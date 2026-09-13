/*
 * hci_rpmsg.c - HCI transport over IPC (derived from zephyr samples/bluetooth/hci_rpmsg).
 */
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>

#include <zephyr/ipc/ipc_service.h>

#include <zephyr/net/buf.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/l2cap.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/buf.h>
#include <zephyr/bluetooth/hci_raw.h>
#include <zephyr/bluetooth/hci_vs.h>

#include <zephyr/logging/log_ctrl.h>
#include <zephyr/logging/log.h>

#include <hal/nrf_gpio.h>

#include "net_common.h"

LOG_MODULE_REGISTER(hci_rpmsg, CONFIG_BT_LOG_LEVEL);

static struct ipc_ept hci_ept;

static K_THREAD_STACK_DEFINE(tx_thread_stack, CONFIG_BT_HCI_TX_STACK_SIZE);
static struct k_thread tx_thread_data;
static K_THREAD_STACK_DEFINE(rx_thread_stack, 2048);
static struct k_thread rx_thread_data;
static K_FIFO_DEFINE(tx_queue);
static K_FIFO_DEFINE(rx_queue);
static K_SEM_DEFINE(ipc_bound_sem, 0, 1);

#define HCI_RPMSG_CMD 0x01
#define HCI_RPMSG_ACL 0x02
#define HCI_RPMSG_SCO 0x03
#define HCI_RPMSG_EVT 0x04
#define HCI_RPMSG_ISO 0x05

#define DBG_PIN BIT(30)

static struct net_buf *hci_rpmsg_cmd_recv(uint8_t *data, size_t remaining)
{
	struct bt_hci_cmd_hdr *hdr = (void *)data;
	struct net_buf *buf;

	if (remaining < sizeof(*hdr)) {
		NET_ERR("wrong command header len\n");
		return NULL;
	}

	buf = bt_buf_get_tx(BT_BUF_CMD, K_NO_WAIT, hdr, sizeof(*hdr));
	if (buf) {
		data += sizeof(*hdr);
		remaining -= sizeof(*hdr);
	} else {
		NET_ERR("No available command buffers\n");
		return NULL;
	}

	if (remaining != hdr->param_len) {
		NET_ERR("Wrong Command payload lenh\n");
		net_buf_unref(buf);
		return NULL;
	}

	if (remaining > net_buf_tailroom(buf)) {
		NET_ERR("no enough space\n");
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, data, remaining);

	return buf;
}

static struct net_buf *hci_rpmsg_acl_recv(uint8_t *data, size_t remaining)
{
	struct bt_hci_acl_hdr *hdr = (void *)data;
	struct net_buf *buf;

	if (remaining < sizeof(*hdr)) {
		NET_ERR("wrong ACL header len\n");
		return NULL;
	}

	buf = bt_buf_get_tx(BT_BUF_ACL_OUT, K_NO_WAIT, hdr, sizeof(*hdr));
	if (buf) {
		data += sizeof(*hdr);
		remaining -= sizeof(*hdr);
	} else {
		NET_ERR("No available ACL buffers\n");
		return NULL;
	}

	if (remaining != sys_le16_to_cpu(hdr->len)) {
		NET_ERR("wrong ACL payload leng\n");
		net_buf_unref(buf);
		return NULL;
	}

	if (remaining > net_buf_tailroom(buf)) {
		NET_ERR("no enough space\n");
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, data, remaining);

	return buf;
}

static struct net_buf *hci_rpmsg_iso_recv(uint8_t *data, size_t remaining)
{
	struct bt_hci_iso_hdr *hdr = (void *)data;
	struct net_buf *buf;

	if (remaining < sizeof(*hdr)) {
		NET_ERR("wrong ISO header len\n");
		return NULL;
	}

	buf = bt_buf_get_tx(BT_BUF_ISO_OUT, K_NO_WAIT, hdr, sizeof(*hdr));
	if (buf) {
		data += sizeof(*hdr);
		remaining -= sizeof(*hdr);
	} else {
		NET_ERR("No available ISO buffers\n");
		return NULL;
	}

	if (remaining != bt_iso_hdr_len(sys_le16_to_cpu(hdr->len))) {
		NET_ERR("wrong ISO payload leng\n");
		net_buf_unref(buf);
		return NULL;
	}

	if (remaining > net_buf_tailroom(buf)) {
		NET_ERR("no enough space\n");
		net_buf_unref(buf);
		return NULL;
	}

	net_buf_add_mem(buf, data, remaining);

	return buf;
}

static void hci_rpmsg_rx(uint8_t *data, size_t len)
{
	uint8_t pkt_indicator;
	struct net_buf *buf = NULL;
	size_t remaining = len;

	pkt_indicator = *data++;
	remaining -= sizeof(pkt_indicator);

	switch (pkt_indicator) {
	case HCI_RPMSG_CMD:
		buf = hci_rpmsg_cmd_recv(data, remaining);
		break;

	case HCI_RPMSG_ACL:
		buf = hci_rpmsg_acl_recv(data, remaining);
		break;

	case HCI_RPMSG_ISO:
		buf = hci_rpmsg_iso_recv(data, remaining);
		break;

	default:
		NET_ERR("Unknown HCI type %u\n", pkt_indicator);
		return;
	}

	if (buf) {
		net_buf_put(&tx_queue, buf);
	}
}

static void tx_thread(void *p1, void *p2, void *p3)
{
	while (1) {
		struct net_buf *buf;
		int err;

		/* Wait until a buffer is available */
		buf = net_buf_get(&tx_queue, K_FOREVER);
		/* Pass buffer to the stack */
		err = bt_send(buf);
		if (err) {
			NET_ERR("Unable to send, err %d\n", err);
			net_buf_unref(buf);
		}

		k_yield();
	}
}

static void hci_rpmsg_send(struct net_buf *buf)
{
	uint8_t pkt_indicator;
	uint8_t retries = 0;
	int ret;

	switch (bt_buf_get_type(buf)) {
	case BT_BUF_ACL_IN:
		pkt_indicator = HCI_RPMSG_ACL;
		break;
	case BT_BUF_EVT:
		pkt_indicator = HCI_RPMSG_EVT;
		break;
	case BT_BUF_ISO_IN:
		pkt_indicator = HCI_RPMSG_ISO;
		break;
	default:
		NET_ERR("Unknown type %u\n", bt_buf_get_type(buf));
		net_buf_unref(buf);
		return;
	}
	net_buf_push_u8(buf, pkt_indicator);

	do {
		ret = ipc_service_send(&hci_ept, buf->data, buf->len);
		if (ret < 0) {
			retries++;
			if (retries > 10) {
				/* Default backend (rpmsg_virtio) has a timeout of 150ms. */
				NET_INF("IPC send blocked 1.5 seconds\n");
				retries = 0;
			}
			k_yield();
		}
	} while (ret < 0);

	net_buf_unref(buf);
}

#if defined(CONFIG_BT_CTLR_ASSERT_HANDLER)
void bt_ctlr_assert_handle(char *file, uint32_t line)
{
	/* Disable interrupts, this is unrecoverable */
	(void)irq_lock();

	NET_ERR("Controller assert in: %s at %d\n", file, line);

	while (true) {
	};
}
#endif /* CONFIG_BT_CTLR_ASSERT_HANDLER */

static void hci_ept_bound(void *priv)
{
	k_sem_give(&ipc_bound_sem);
}

static void rx_thread(void *p1, void *p2, void *p3)
{
	k_sem_take(&ipc_bound_sem, K_FOREVER);

	while (1) {
		struct net_buf *buf;

		buf = net_buf_get(&rx_queue, K_FOREVER);
		NRF_P0->OUTSET = DBG_PIN;
		hci_rpmsg_send(buf);
		NRF_P0->OUTCLR = DBG_PIN;
	}
}

static void hci_ept_recv(const void *data, size_t len, void *priv)
{
	hci_rpmsg_rx((uint8_t *) data, len);
}

static struct ipc_ept_cfg hci_ept_cfg = {
	.name = "nrf_bt_hci",
	.cb = {
		.bound    = hci_ept_bound,
		.received = hci_ept_recv,
	},
};

int hci_rpmsg_init(void)
{
	int err;
	const struct device *hci_ipc_instance =
		DEVICE_DT_GET(DT_CHOSEN(zephyr_bt_hci_rpmsg_ipc));

	/* Enable the raw interface, this will in turn open the HCI driver */
	bt_enable_raw(&rx_queue);

	k_thread_create(&tx_thread_data, tx_thread_stack,
			K_THREAD_STACK_SIZEOF(tx_thread_stack), tx_thread,
			NULL, NULL, NULL, K_PRIO_COOP(7), 0, K_NO_WAIT);
	k_thread_name_set(&tx_thread_data, "HCI rpmsg TX");

	k_thread_create(&rx_thread_data, rx_thread_stack,
			K_THREAD_STACK_SIZEOF(rx_thread_stack), rx_thread,
			NULL, NULL, NULL, K_PRIO_COOP(7), 0, K_NO_WAIT);
	k_thread_name_set(&rx_thread_data, "HCI rpmsg RX");

	/* Initialize IPC service instance and register endpoint. */
	err = ipc_service_open_instance(hci_ipc_instance);
	if (err < 0 && err != -EALREADY) {
		NET_ERR("IPC service init failed %d\n\n", err);
	}

	err = ipc_service_register_endpoint(hci_ipc_instance, &hci_ept, &hci_ept_cfg);
	if (err) {
		NET_ERR("IPC reg endpoint failed %d\n", err);
	}

	return 0;
}

/* Read the random static address from FICR (cf. hci_vendor_read_static_addr). */
int hci_rpmsg_get_static_addr(uint8_t *addr)
{
	struct bt_hci_vs_static_addr addrs[1];
	char str[18];

	if (((NRF_FICR->DEVICEADDR[0] != UINT32_MAX) ||
	     ((NRF_FICR->DEVICEADDR[1] & UINT16_MAX) != UINT16_MAX)) &&
	    (NRF_FICR->DEVICEADDRTYPE & 0x01)) {
		sys_put_le32(NRF_FICR->DEVICEADDR[0], &addrs[0].bdaddr.val[0]);
		sys_put_le16(NRF_FICR->DEVICEADDR[1], &addrs[0].bdaddr.val[4]);
		BT_ADDR_SET_STATIC(&addrs[0].bdaddr);

		if ((NRF_FICR->IR[0] != UINT32_MAX) &&
		    (NRF_FICR->IR[1] != UINT32_MAX) &&
		    (NRF_FICR->IR[2] != UINT32_MAX) &&
		    (NRF_FICR->IR[3] != UINT32_MAX)) {
			sys_put_le32(NRF_FICR->IR[0], &addrs[0].ir[0]);
			sys_put_le32(NRF_FICR->IR[1], &addrs[0].ir[4]);
			sys_put_le32(NRF_FICR->IR[2], &addrs[0].ir[8]);
			sys_put_le32(NRF_FICR->IR[3], &addrs[0].ir[12]);
		} else {
			(void)memset(addrs[0].ir, 0x00, sizeof(addrs[0].ir));
		}

		memcpy(addr, addrs[0].bdaddr.val, 6);
		snprintf(str, sizeof(str), "%02X:%02X:%02X:%02X:%02X:%02X",
			 addr[5], addr[4], addr[3], addr[2], addr[1], addr[0]);
		printk("BT addr: %s\n", str);
		return 1;
	}

	return 0;
}

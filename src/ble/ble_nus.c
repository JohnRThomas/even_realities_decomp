#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <bluetooth/services/nus.h>
#include "g1_log.h"
#include "ble_ancs.h"
#include "ble_proto.h"
#include "../production_test/production_test.h"
#include "../threads/threads.h"

/* the logs print __LINE__: line numbers below follow the vendor file */
#line 10
K_MSGQ_DEFINE(nus_data_msgq, sizeof(struct bt_data_msg), BT_DATA_MSGQ_MAX, 4); /* name sorts between display_msgq and proxy_msgq (__LINE__ is used below) */
static struct ble_context *ble_ctx;
static struct k_mutex nus_mutex;

static void bt_send_enabled(enum bt_nus_send_status status)
{
	G1_LOG_INF("status:%d\n\n", status);
	if (status == BT_NUS_SEND_STATUS_ENABLED) {
		ble_ctx->send_enabled = true;
	} else {
		ble_ctx->send_enabled = false;
	}
}

int ble_write_thread(const uint8_t *data, uint16_t len)
{
	bool connected = get_current_conn();
	int err;

	if (!get_pt_test_mode()) {
		if (!connected || get_dashboard_state()->ble_context.security_pending ||
		    k_sem_count_get(&get_dashboard_state()->ble_context.tx_sem) == 0) {
			return -1;
		}
	}
	k_mutex_lock(&nus_mutex, K_FOREVER);
	err = bt_nus_send(NULL, data, len);
	k_mutex_unlock(&nus_mutex);
	if (err) {
		printk("Failed to send data over BLE connection: ret %d len %d \n", err, len);
		return -1;
	}
	return 0;
}

int enqueue_bt_data(void *data, uint8_t len)
{
	struct bt_data_msg msg;
	int err;

	memset(&msg, 0, sizeof(msg));
	if (k_msgq_num_used_get(&nus_data_msgq) == BT_DATA_MSGQ_MAX) {
		k_msgq_get(&nus_data_msgq, &msg, K_NO_WAIT);
		BLE_PRINTK("enqueue_bt_data drop package! \n");
	}
	msg.len = len;
	memcpy(msg.data, data, sizeof(msg.data));
	err = k_msgq_put(&nus_data_msgq, &msg, K_NO_WAIT);
	if (err) {
		BLE_PRINTK("enqueue_bt_data failed !\n");
	}
	return err;
}

static void bt_receive_cb(struct bt_conn *conn, const uint8_t *const data, uint16_t len)
{
	char addr[BT_ADDR_LE_STR_LEN] = {0};
	struct bt_data_msg msg;
	struct ble_context *ctx;

	memset(&msg, 0, sizeof(msg));
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, ARRAY_SIZE(addr));
	G1_LOG_ERR("**Received data from: %s, len=%d,cmd 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x,"
		   "receiver_thd_is_running is %d\n",
		   addr, len, data[0], data[1], data[2], data[3], data[4], data[5],
		   ble_ctx->receiver_thd_is_running);

	ctx = ble_ctx;
	ctx->last_rx_time = k_uptime_get();

	if (ble_ctx->receiver_thd_is_running || k_sem_count_get(&ble_ctx->rx_sem) != 0) {
		uint8_t resp[20] = {0};

		if (data[0] == 0x18) {
			resp[1] = 0xc9;
			ble_ctx->write(resp, sizeof(resp));
			if (get_dashboard_state()->is_master == 2 &&
			    get_dashboard_state()->dashboard_mode == 6) {
				k_msleep(50);
			}
			exit_running_task(get_dashboard_state(), 0);
			return;
		}
		if (len > sizeof(msg.data)) {
			BLE_PRINTK("[%s-%d]len is %d, too large ! \n", __FUNCTION__, __LINE__, len);
			return;
		}
		msg.len = len;
		memset(msg.data, 0, sizeof(msg.data));
		memcpy(msg.data, data, len);
		enqueue_bt_data(msg.data, len);
		G1_LOG_ERR("enqueue because busy\n");
		return;
	}

	/* receiver idle: hand the packet over directly
	 * (short packets go to small_buf) */
	ctx = ble_ctx;
	if (len > 20) {
		/* long packet */
		if (len > sizeof(ctx->rx_data)) {
			BLE_PRINTK("[%s-%d]len is %d, too large ! \n", __FUNCTION__, __LINE__, len);
			return;
		}
		memcpy(ctx->rx_data, data, len);
		ctx->rx_len = len;
	} else {
		/* short packet */
		memcpy(ctx->small_buf, data, len);
		memset(ctx->small_buf + len, 0, 20 - len);
		ctx->rx_len = 0;
		ctx->small_len = len;
	}
	ctx->rx_pending = 1;
	k_sem_give(&ctx->rx_sem);
}

int dequeue_bt_data(struct bt_data_msg *out)
{
	struct bt_data_msg msg;
	int err;

	memset(&msg, 0, sizeof(msg));
	err = k_msgq_get(&nus_data_msgq, &msg, K_NO_WAIT);
	if (!err) {
		memcpy(out, &msg, sizeof(msg));
	}
	return err;
}

static struct bt_nus_cb nus_cb = {
	.received = bt_receive_cb,
	.send_enabled = bt_send_enabled,
};

int init_nus(void)
{
	return bt_nus_init(&nus_cb);
}

struct ble_context *get_ble_context(void)
{
	return ble_ctx;
}

void ble_context_init(struct ble_context *ctx)
{
	/* vendor layout: the two large rx buffers lie past the end of ble_context
	 * (gs + 0xb10 and gs + 0x1050) */
	ctx->large_buf_0 = (uint8_t *)ctx + 0x394;
	ctx->init_cb = start_ble_work_thread;
	k_mutex_init(&nus_mutex);
	ctx->write = ble_write_thread;
	k_sem_init(&ctx->rx_sem, 0, 1);
	k_sem_init(&ctx->tx_sem, 0, 2);
	ctx->large_buf_1 = (uint8_t *)ctx + 0x8d4;
	ctx->connected = 0;
	ctx->send_enabled = 0;
	ctx->restart_adv = 0;
	ble_ctx = ctx;
	ctx->small_buf = malloc(21);
	memset(ctx->small_buf, 0, 21);
}

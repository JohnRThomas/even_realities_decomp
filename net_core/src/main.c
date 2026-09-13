/*
 * Even Realities G1 network core - main.c (reconstruction of v1.63).
 *
 * Global context, "cpunet-hw-id" endpoint (configuration from the app core),
 * ESB event bookkeeping/statistics and the main supervision loop.
 */
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/reboot.h>
#include <esb.h>
#include <zephyr/drivers/timer/nrf_rtc_timer.h>

#include "net_common.h"

#define NET_BUILD_TIME "2025-06-28 17:32:14"

/* Event passed by the ESB/timeslot layer to the handler given to app_esb_init. */
struct app_esb_evt {
	uint8_t id;             /* 0 = TX success, 1 = TX failed, 2 = RX received */
	uint8_t *data;          /* +4 */
	uint32_t len;           /* +8 */
	uint8_t rssi;           /* +0xc */
};

/* ipc.c / hci_rpmsg.c */
extern int ipc_init(void);
extern int ipc_ops_init(struct ipc_ops *ops);
extern int hci_rpmsg_init(void);
extern int hci_rpmsg_get_static_addr(uint8_t *addr);
/* app_esb.c */
extern void esb_ops_init(struct esb_ops *ops);
extern uint8_t addr_prefix[2];         /* ESB address prefixes */
extern uint8_t base_addr_1[4];         /* ESB base address 1 */
extern uint8_t base_addr_0[4];         /* ESB base address 0 */
/* timeslot.c */
extern int app_esb_init(int role, void (*handler)(struct app_esb_evt *evt));
extern void esb_link_set_high(void);
extern void esb_link_set_low(void);
extern void esb_link_set_paused(void);
extern int esb_link_state_get(void);
extern void timeslot_handler_stop(void);

int net_log_level = 2;
static int sync_offset = -EBUSY;
static uint8_t first_cfg_log = 1;

static struct net_ctx *net_ctx;
static uint32_t esb_tx_ok_cnt;
static uint32_t esb_tx_fail_cnt;
static uint32_t esb_rx_cnt;
static size_t tx_len;
static struct k_msgq esb_msgq;

int64_t now_ticks;                      /* signed: matches k_uptime_ticks(); keeps the ticks
                                         * low word in r0 for the umull (no extra mov) */
static uint64_t now_ms;
uint64_t esb_rx_ms;
static uint64_t last_report_ms;

uint8_t esb_evt_active;
static uint8_t esb_rssi;
static uint8_t last_rssi;
uint8_t esb_tx_done;
uint8_t esb_tx_state;
uint8_t esb_tx_kind;
uint8_t esb_tx_buf[0xfc];
uint8_t esb_channel;
static uint8_t rx_repeat;
static uint8_t last_seq;

static int hwid_received(struct net_ctx *ctx, const uint8_t *data, size_t len)
{
	uint8_t buf[16] = {0};

	switch (data[0]) {
	case 0:
		ctx->role = data[1];
		ctx->mode = data[2];
		ctx->channel = data[3];
		if (data[4] != 0xff && data[5] != 0 && data[5] != 0xff && data[4] != 0) {
			base_addr_0[0] = data[4];
			base_addr_0[1] = data[4];
			base_addr_0[2] = data[4];
			base_addr_0[3] = data[4];
			addr_prefix[0] = data[4];
			addr_prefix[1] = data[5];
			base_addr_1[0] = data[5];
			base_addr_1[1] = data[5];
			base_addr_1[2] = data[5];
			base_addr_1[3] = data[5];
		}
		buf[0] = 1;
		buf[1] = 1;
		ctx->ipc.send(buf, sizeof(buf));
		if (first_cfg_log) {
			first_cfg_log = 0;
			NET_INF("L %d, R %d, M %d C %d\n", len, ctx->role, ctx->mode, ctx->channel);
		}
		break;
	case 8:
		net_ctx->mode = 1;
		timeslot_handler_stop();
		NET_INF("M %d\n", net_ctx->mode);
		break;
	case 10:
		esb_link_set_high();
		NET_INF("H\n");
		break;
	case 11:
		esb_link_set_low();
		NET_INF("L\n");
		break;
	case 12:
		esb_link_set_paused();
		NET_INF("P\n");
		break;
	default:
		break;
	}

	return 0;
}

/*
 * The shipped code has no return statement here (the caller in main() tests the
 * garbage r0 left by the last ipc send); reproduced as-is (-Wreturn-type).
 * int, not uint8_t: the caller truncates the result itself (uxtb after the call).
 */
int send_esb_stats(void)
{
	uint8_t buf[32] = {0};
	uint8_t retry = 10;

	buf[0] = 1;
	buf[1] = 7;
	memcpy(&buf[2], &esb_tx_ok_cnt, 4);
	memcpy(&buf[6], &esb_tx_fail_cnt, 4);
	memcpy(&buf[10], &esb_rx_cnt, 4);
	buf[14] = esb_rssi;

	do {
		if (net_ctx->ipc.send(buf, sizeof(buf)) > 0) {
			break;
		}
		retry--;
		if (retry == 0) {
			break;
		}
		k_msleep(10);
	} while (1);
}

void ipc_send_esb_status(uint8_t val)
{
	uint8_t buf[8] = {0};
	uint8_t retry = 10;

	buf[0] = 1;
	buf[1] = 0xd;
	buf[2] = val;

	do {
		if (net_ctx->ipc.send(buf, sizeof(buf)) > 0) {
			break;
		}
		retry--;
		if (retry == 0) {
			break;
		}
		k_msleep(10);
	} while (1);
}

int esb_tx_buf_set(const uint8_t *data, size_t len)
{
	memcpy(esb_tx_buf, data, len);
	tx_len = len;
	return 0;
}

size_t esb_tx_buf_len_get(void)
{
	return tx_len;
}

void esb_tx_buf_clear(void)
{
	memset(esb_tx_buf, 0, sizeof(esb_tx_buf));
	tx_len = 0;
	esb_tx_state = 0;
}

int net_mode_get(void)
{
	return net_ctx->mode;
}

int net_role_get(void)
{
	return net_ctx->role;
}

void esb_thread_wake(void)
{
	if (k_sem_count_get(&net_ctx->sem1) == 0) {
		k_sem_give(&net_ctx->sem1);
	}
}

/* app_esb.c (align-2 0x1039dfc); defined outside this file, otherwise GCC
 * emits app_esb_event_handler after esb_rx_msgq_put instead of after esb_thread_wake. */
int esb_rx_enqueue(const uint8_t *data, size_t len);

static void app_esb_event_handler(struct app_esb_evt *evt)
{
	esb_evt_active = 1;

	switch (evt->id) {
	case 0:
		esb_tx_ok_cnt++;
		break;
	case 1:
		esb_tx_fail_cnt++;
		break;
	case 2:
		esb_rx_cnt++;
		if (net_ctx->mode == 1) {
			break;
		}
		if (net_ctx->role == 2) {
			if (esb_tx_kind == 1 && esb_tx_state == 2) {
				if (++rx_repeat > 1) {
					rx_repeat = 0;
					esb_tx_state = 0;
					esb_tx_kind = 0;
					esb_tx_done = 2;
					esb_thread_wake();
				}
			}
		} else if (esb_tx_kind != 0) {
			if (esb_tx_kind == 2) {
				esb_tx_kind = 0;
			} else if (esb_tx_kind == 1 && esb_tx_state == 2) {
				esb_tx_kind = 0;
				esb_tx_done = 2;
				esb_thread_wake();
			}
		}
		esb_rssi = evt->rssi;
		if (evt->data[0] == 0x10 || evt->data[0] == 0x11) {
			break;
		}
		if (net_ctx->role == 2 && evt->len > 15) {
			if (last_seq == evt->data[0x11]) {
				break;
			}
			last_seq = evt->data[0x11];
		}
		esb_rx_enqueue(evt->data, evt->len);
		esb_rx_ms = k_ticks_to_ms_ceil64(k_uptime_ticks());
		break;
	default:
		NET_ERR("UN ESB!\n");
		break;
	}

	esb_evt_active = 0;
}

/* non-static: shipped order puts it after app_esb_event_handler */
int rtc_sync_check(void)
{
	int offset;

	if (sync_offset != -EBUSY) {
		return 0;
	}
	offset = z_nrf_rtc_timer_nrf53net_offset_get();
	if (offset == -EBUSY) {
		return 1;
	}
	sync_offset = offset;
	*(volatile uint32_t *)0x20070000 = 0xa5a5a5a5;
	NET_INF("SYNC, offset %d\n", sync_offset);

	return 0;
}

int esb_rx_msgq_init(void)
{
	int err = k_msgq_alloc_init(&esb_msgq, 0xfb, 4);

	if (err) {
		NET_ERR("k_msgq alloc failed\n");
	}

	return err;
}

int esb_rx_msgq_put(const uint8_t *data)
{
	uint8_t buf[252];
	int err;

	if (esb_msgq.max_msgs == 0) {
		return 1;
	}

	memcpy(buf, data, 0xfb);
	err = k_msgq_put(&esb_msgq, buf, K_NO_WAIT);
	if (err) {
		NET_ERR("en ESB F\n");
	}

	return err;
}

int esb_rx_msgq_get(uint8_t *data)
{
	/* The shipped zero block sits in main.c's plain .rodata (align 1, placed after
	 * the align-4 .rodata of the later objects, before all .rodata.*); GCC puts an
	 * anonymous constant there (e.g. a 251-byte "\0..." literal), a named static
	 * goes to .rodata.empty.N.  An uninitialised const keeps the memcpy. */
	static const uint8_t empty[0xfb] __attribute__((section(".rodata")));
	uint8_t buf[252];
	int err;

	memcpy(buf, empty, 0xfb);
	if (esb_msgq.max_msgs == 0) {
		return 1;
	}

	err = k_msgq_get(&esb_msgq, buf, K_NO_WAIT);
	if (err == 0) {
		memcpy(data, buf, 0xfb);
	}

	return err;
}

/*
 * App-core handshake sends with retry.  Both loops are written as
 * `while (xxx_send() < 0) { sleep; if (--i == 0) break; }` on purpose: a
 * `for`/`do` body-first loop lays the send block out before the latch, and
 * then IRA (whose tie-break is the allocno number, i.e. reverse block order)
 * gives the retry counter the lower register.  With the send in the loop
 * condition the latch precedes it in block order and the send result is
 * coloured first (result r4, counter r7 / r7, r8), exactly as shipped.
 * The helpers are inlined (static, called once) and emit no code of their own.
 */
static int mac_send(void)
{
	uint8_t buf[16] = {0};
	int ret;

	buf[0] = 1;
	buf[1] = 3;
	if (net_ctx->role == 1) {
		memcpy(&buf[2], net_ctx->mac0, 6);
	} else {
		memcpy(&buf[2], net_ctx->mac1, 6);
	}
	ret = net_ctx->ipc.send(buf, sizeof(buf));
	NET_INF("mac\n");
	return ret;
}

static int bt_send(void)
{
	uint8_t buf[32] = {0};
	int ret;

	buf[0] = 1;
	buf[1] = 6;
	strcpy((char *)&buf[2], NET_BUILD_TIME);
	ret = net_ctx->ipc.send(buf, sizeof(buf));
	NET_INF("bt\n");
	return ret;
}

int main(void)
{
	struct net_ctx *ctx;
	int cnt;
	uint8_t err;
	int ret;
	int i;

	NET_INF("net %s\n", NET_BUILD_TIME);
	ipc_init();
	NET_INF("global init\n");

	ctx = k_malloc(sizeof(*ctx));
	memset(ctx, 0, sizeof(*ctx));
	memset(ctx->mac0, 0xff, sizeof(ctx->mac0));
	memset(ctx->mac1, 0xff, sizeof(ctx->mac1));
	k_sem_init(&ctx->sem0, 0, 1);
	k_sem_init(&ctx->sem1, 0, 1);
	ctx->channel = 0xff;
	ipc_ops_init(&ctx->ipc);
	ctx->hwid_ep.id = 1;
	ctx->hwid_ep.name = "cpunet-hw-id";
	ctx->hwid_ep.cb = hwid_received;
	ctx->ipc.reg(&ctx->hwid_ep);
	NET_INF("done\n");

	net_ctx = ctx;

	/* Wait (up to 20 x 300 ms) for the app core to answer the role request;
	 * the role is kept in a local so the print after the loop reuses it. */
	i = 20;
	while ((ret = net_ctx->role) == 0) {
		rtc_sync_check();
		{
			uint8_t buf[8] = {0};

			buf[0] = 1;
			buf[1] = 2;
			net_ctx->ipc.send(buf, sizeof(buf));
		}
		NET_INF("resend\n");
		if (net_ctx->role == 0) {
			k_msleep(300);
		}
		if (--i == 0) {
			sys_reboot(SYS_REBOOT_COLD);
		}
	}
	NET_INF("role %d mode %d\n", ret, net_ctx->mode);

	if (net_ctx->role == 1) {
		hci_rpmsg_get_static_addr(net_ctx->mac0);
		NET_INF("M\n");
	} else if (net_ctx->role == 2) {
		hci_rpmsg_get_static_addr(net_ctx->mac1);
		NET_INF("S\n");
	}

	i = 20;
	while (mac_send() < 0) {
		k_msleep(50);
		if (--i == 0) {
			break;
		}
	}

	for (i = 20; i && rtc_sync_check(); i--) {
		k_msleep(50);
	}

	esb_msgq.max_msgs = 0;

	if (net_ctx->channel != 0xff) {
		esb_set_rf_channel(net_ctx->channel);
		esb_channel = net_ctx->channel;
	} else {
		esb_set_rf_channel(0);
	}

	NET_INF("addr 0 0x%02X-0x%02X-0x%02X-0x%02X\n", base_addr_0[0], base_addr_0[1],
		base_addr_0[2], base_addr_0[3]);
	NET_INF("addr 1 0x%02X-0x%02X-0x%02X-0x%02X\n", base_addr_1[0], base_addr_1[1],
		base_addr_1[2], base_addr_1[3]);

	/* two tests with identical bodies (cross-jumped): `role == 1 || role == 2`
	 * folds into a range test and blocks the threading to the PRX init below */
	if (net_ctx->role == 1) {
		esb_ops_init(&net_ctx->esb);
		hci_rpmsg_init();
		k_msleep(1000);
		net_ctx->esb.start();
	} else if (net_ctx->role == 2) {
		esb_ops_init(&net_ctx->esb);
		hci_rpmsg_init();
		k_msleep(1000);
		net_ctx->esb.start();
	}

	if (net_ctx->role == 1) {
		err = app_esb_init(ESB_MODE_PTX, app_esb_event_handler);
	} else {
		err = app_esb_init(ESB_MODE_PRX, app_esb_event_handler);
	}
	if (err) {
		NET_ERR("esb init failed %d\n", err);
		return 0;
	}

	i = 20;
	while (bt_send() < 0) {
		k_msleep(100);
		if (--i == 0) {
			break;
		}
	}

	rtc_sync_check();

	cnt = 0;
	while (1) {
		/* early continue: the shipped layout has the sleep block right after the
		 * tests (tail-merged with the one at the end of the body) */
		if (esb_link_state_get() == 3 || net_ctx->mode == 1) {
			k_msleep(1000);
			continue;
		}
		{
			now_ticks = k_uptime_ticks();
			now_ms = k_ticks_to_ms_ceil64(now_ticks);

			if (last_rssi > 50) {
				if (esb_rssi >= 1 && esb_rssi <= 39) {
					cnt++;
				} else {
					cnt = 0;
				}
			} else if (last_rssi <= 39) {
				cnt = (esb_rssi > 50) ? 3 : 0;
			}

			if (now_ms - last_report_ms >= 10000) {
				last_report_ms = now_ms;
				send_esb_stats();
			} else if (((esb_rssi <= 39 && last_rssi > 50) ||
				    (esb_rssi > 50 && last_rssi <= 39)) && cnt > 2) {
				uint8_t sent = send_esb_stats();

				if (sent) {
					last_report_ms = now_ms;
					last_rssi = esb_rssi;
					cnt = 0;
				}
			}
		}
		k_msleep(1000);
	}

	return 0;
}

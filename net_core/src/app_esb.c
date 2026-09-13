/*
 * Even Realities G1 network core - ESB link between the two glasses
 * (reconstruction of v1.63; derived from nrf/samples/esb/esb_ptx|esb_prx).
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/nrf_clock_control.h>
#include <esb.h>
#include <nrf.h>

#include "net_common.h"

LOG_MODULE_REGISTER(app_esb);

/* Event passed to the user callback (0x21004618). */
struct app_esb_evt {
	uint8_t type;
	uint8_t *data;
	uint32_t len;
	int8_t rssi;
};

typedef void (*app_esb_cb_t)(struct app_esb_evt *evt);

/* main.c */
extern int net_mode_get(void);                  /* mode */
extern int esb_tx_buf_len_get(void);                  /* pending tx length */
extern int esb_tx_buf_set(const uint8_t *data, size_t len); /* store pending tx */
extern void esb_tx_buf_clear(void);                 /* clear pending tx */
extern void ipc_send_esb_status(uint8_t state);        /* report state to the app core */
extern int esb_rx_msgq_init(void);                  /* rx msgq init */
extern int esb_rx_msgq_get(uint8_t *buf);          /* rx msgq get */
extern uint8_t esb_tx_buf[];                  /* pending tx data */
extern uint8_t esb_channel;                    /* esb channel */
extern uint8_t esb_tx_kind;
extern uint8_t esb_tx_state;
extern uint8_t esb_tx_done;
extern uint8_t esb_evt_active;

int on_timeslot_start_stop(int op);

/* timeslot.c */
extern void timeslot_handler_init(int (*cb)(int op));    /* timeslot start */
extern uint8_t timeslot_radio_is_on(void);              /* timeslot radio enabled */

/* .data, 1-byte aligned group */
uint8_t base_addr_0[4] = {0xC9, 0xC9, 0xC9, 0xC9};
uint8_t base_addr_1[4] = {0xA3, 0xA3, 0xA3, 0xA3};
uint8_t addr_prefix[2] = {0xE9, 0xD3};

/* .data */
int esb_link_state = 1;

static app_esb_cb_t app_evt_cb;
static struct app_esb_evt app_evt;
static int tx_count;
static struct esb_ops *g_esb_ops;

static uint8_t tx_busy;
static uint8_t esb_prx;
static uint8_t radio_active;
static struct esb_payload ack_payload;
static struct esb_payload rx_payload;
static struct esb_payload tx_payload;

K_THREAD_STACK_DEFINE(esb_thread_stack, 0x600);
static struct k_thread esb_thread_data;

static int esb_ipc_recv(struct net_ctx *ctx, const uint8_t *data, size_t len)
{
	uint8_t buf[252] = {0};

	memcpy(buf, data, len);

	if (net_mode_get() == 1) {
		return 0;
	}

	if (len > CONFIG_ESB_MAX_PAYLOAD_LENGTH) {
		NET_ERR("data len exceed:%d %d\n", len, CONFIG_ESB_MAX_PAYLOAD_LENGTH);
		return -1;
	}

	if (esb_tx_buf_len_get() != 0) {
		return -1;
	}

	esb_tx_buf_set(buf, len);
	esb_tx_state = 1;
	return 0;
}

static void esb_thread(void)
{
	struct esb_ops *ops = g_esb_ops;
	struct net_ctx *ctx = CONTAINER_OF(ops, struct net_ctx, esb);
	uint8_t buf[252] = {0};
	uint8_t retry;

	buf[0] = (ctx->role == 1) ? 6 : 4;

	esb_rx_msgq_init();

	while (1) {
		if (net_mode_get() == 1) {
			k_sleep(K_MSEC(5000));
			continue;
		}

		if (esb_tx_done == 2 && esb_evt_active == 0) {
			esb_tx_buf_clear();
			ipc_send_esb_status(2);
			esb_tx_done = 0;
		}

		if (esb_rx_msgq_get(&buf[1]) == 0) {
			retry = 10;
			while (1) {
				if (ctx->ipc.send(buf, sizeof(buf)) > 0) {
					break;
				}
				retry--;
				if (retry == 0) {
					break;
				}
				k_sleep(K_MSEC(10));
			}
		}

		k_sem_take(&ctx->sem1, K_FOREVER);
	}
}

static void esb_thread_start(void)
{
	k_thread_create(&esb_thread_data, esb_thread_stack, 0x600,
			(k_thread_entry_t)esb_thread, NULL, NULL, NULL,
			K_PRIO_COOP(5), 0, K_NO_WAIT);
}

void esb_ops_init(struct esb_ops *ops)
{
	struct net_ctx *ctx = CONTAINER_OF(ops, struct net_ctx, esb);
	uint8_t *buf;

	ops->buf = k_malloc(0x100);
	memset(ops->buf, 0, 0x100);
	buf = ops->buf;
	buf[0] = 0xfb;
	memcpy(&buf[0x11], ctx->mac1, 6);

	ops->start = esb_thread_start;
	if (ctx->role == 1) {
		ops->ep.id = 2;
		ops->ep.name = "cpunet-esbm";
	} else {
		ops->ep.id = 4;
		ops->ep.name = "cpunet-esbs";
	}
	ops->ep.cb = esb_ipc_recv;
	ctx->ipc.reg(&ops->ep);
	g_esb_ops = ops;
}

static void event_handler(struct esb_evt const *event);

int esb_initialize(uint8_t prx)
{
	int err;
	struct esb_config config = ESB_DEFAULT_CONFIG;

	config.protocol = ESB_PROTOCOL_ESB_DPL;
	config.retransmit_delay = 300;
	config.retransmit_count = 5;
	config.bitrate = ESB_BITRATE_2MBPS;
	config.event_handler = event_handler;
	config.mode = prx ? ESB_MODE_PRX : ESB_MODE_PTX;
	config.tx_mode = ESB_TXMODE_MANUAL_START;
	config.payload_length = CONFIG_ESB_MAX_PAYLOAD_LENGTH;
	config.selective_auto_ack = true;
	config.use_fast_ramp_up = true;

	err = esb_init(&config);
	if (err) {
		return err;
	}

	esb_set_tx_power(3);

	if (esb_link_state == 2) {
		uint8_t channel = esb_channel / 5 + 80;

		esb_set_rf_channel(channel);
	}

	err = esb_set_base_address_0(base_addr_0);
	if (err) {
		return err;
	}

	err = esb_set_base_address_1(base_addr_1);
	if (err) {
		return err;
	}

	err = esb_set_prefixes(addr_prefix, ARRAY_SIZE(addr_prefix));
	if (err) {
		return err;
	}

	err = esb_enable_pipes(3);
	if (err) {
		return err;
	}

	NVIC_SetPriority(RADIO_IRQn, 0);

	if (prx == 1) {
		err = esb_start_rx();
		if (err) {
			NET_ERR("esb_start_rx fail\n");
			return err;
		}
	}

	return err;
}

/* non-static: keeps the shipped function order (esb_initialize, esb_send) */
void esb_send(uint8_t load)
{
	uint8_t tmp[CONFIG_ESB_MAX_PAYLOAD_LENGTH] = {0};
	int len;

	if (load) {
		tx_payload.length = 0;
		len = esb_tx_buf_len_get();
		if (len) {
			tx_payload.pipe = 0;
			tx_payload.noack = 0;
			memcpy(tx_payload.data, esb_tx_buf, len);
			tx_payload.length = len;
		} else {
			tx_payload.pipe = 0;
			tx_payload.noack = 0;
			tmp[0] = esb_prx == 0 ? 0x11 : 0x10;
			memcpy(tx_payload.data, tmp, sizeof(tmp));
			tx_payload.length = 32;
		}

		if (esb_write_payload(&tx_payload)) {
			return;
		}

		if (esb_prx == 1 && !esb_tx_full()) {
			esb_write_payload(&tx_payload);
		}

		if (len) {
			esb_tx_kind = 1;
		} else {
			esb_tx_kind = 2;
		}
	}

	if (esb_prx == 0) {
		if (esb_start_tx() == 0) {
			tx_count++;
		}
	}
}

void esb_send_idle(void)
{
	uint8_t tmp[CONFIG_ESB_MAX_PAYLOAD_LENGTH] = {0};

	ack_payload.pipe = 0;
	ack_payload.noack = 0;
	tmp[0] = 0x11;
	memcpy(ack_payload.data, tmp, sizeof(tmp));
	ack_payload.length = CONFIG_ESB_MAX_PAYLOAD_LENGTH;

	if (esb_write_payload(&ack_payload)) {
		NET_ERR("esb_write_payload failed\n");
	}

	if (esb_start_tx()) {
		NET_ERR("esb_start_tx failed\n");
	}
}

static void event_handler(struct esb_evt const *event)
{
	enum esb_evt_id id = event->evt_id;

	switch (id) {
	case ESB_EVENT_TX_SUCCESS:
		tx_busy = 0;
		app_evt.type = id;
		app_evt_cb(&app_evt);
		break;
	case ESB_EVENT_TX_FAILED:
		esb_send(0);
		if (radio_active && timeslot_radio_is_on()) {
			app_evt.type = id;
			app_evt_cb(&app_evt);
		}
		break;
	case ESB_EVENT_RX_RECEIVED:
		tx_busy = 0;
		if (esb_prx == 1) {
			esb_send(1);
		}
		while (esb_read_rx_payload(&rx_payload) == 0) {
			if (esb_prx == 0 && rx_payload.data[0] == 0x11) {
				tx_busy = 1;
				esb_send_idle();
				continue;
			}
			esb_tx_state = 2;
			app_evt.type = 2;
			app_evt.data = rx_payload.data;
			app_evt.len = rx_payload.length;
			app_evt.rssi = rx_payload.rssi;
			app_evt_cb(&app_evt);
		}
		break;
	}
}

static int clocks_start(void)
{
	int err;
	int res;
	struct onoff_manager *clk_mgr;
	struct onoff_client clk_cli;

	clk_mgr = z_nrf_clock_control_get_onoff(CLOCK_CONTROL_NRF_SUBSYS_HF);
	if (!clk_mgr) {
		NET_ERR("Unable get Clock\n");
		return -ENXIO;
	}

	sys_notify_init_spinwait(&clk_cli.notify);

	err = onoff_request(clk_mgr, &clk_cli);
	if (err < 0) {
		NET_ERR("Clock request failed: %d\n", err);
		return err;
	}

	do {
		err = sys_notify_fetch_result(&clk_cli.notify, &res);
		if (!err && res) {
			NET_ERR("Clock can not starte %d\n", res);
			return res;
		}
	} while (err);

	return 0;
}

int app_esb_init(uint8_t prx, app_esb_cb_t cb)
{
	int err;

	app_evt_cb = cb;
	esb_prx = prx;

	NRF_P0->DIRSET = 0xF0000010;
	NRF_P0->OUTCLR = 0xF0000000;

	err = clocks_start();
	if (err < 0) {
		return err;
	}

	timeslot_handler_init(on_timeslot_start_stop);
	return 0;
}

int app_esb_suspend(void)
{
	radio_active = 0;
	NRF_P0->OUTSET = BIT(29);

	if (esb_prx == 0) {
		unsigned int key = irq_lock();

		irq_disable(RADIO_IRQn);
		NVIC_DisableIRQ(RADIO_IRQn);

		NRF_RADIO->SHORTS = 0;
		NRF_RADIO->EVENTS_DISABLED = 0;
		NRF_RADIO->TASKS_DISABLE = 1;
		while (NRF_RADIO->EVENTS_DISABLED == 0) {
		}
		NRF_TIMER2->TASKS_STOP = 1;
		NRF_RADIO->INTENCLR = 0xFFFFFFFF;

		esb_disable();

		NVIC_ClearPendingIRQ(RADIO_IRQn);
		irq_unlock(key);
	} else if (esb_prx == 1) {
		esb_stop_rx();
	}

	NRF_P0->OUTCLR = BIT(29);
	NRF_VREQCTRL->VREGRADIO.VREQH = 1;
	return 0;
}

/* Shape of the demo's app_esb_resume() of the same name (if PTX {...} else {...}); the two
 * branches became identical and GCC cross-jumps them, which is what keeps
 * &radio_active/&tx_busy in r8/r7 in the shipped code. */
int app_esb_resume(void)
{
	NRF_P0->OUTSET = BIT(29);
	if (esb_prx == 0) {
		int err = esb_initialize(esb_prx);
		radio_active = 1;
		tx_busy = 1;
		esb_send(1);
		NRF_P0->OUTCLR = BIT(29);
		return err;
	} else {
		int err = esb_initialize(esb_prx);
		radio_active = 1;
		tx_busy = 1;
		esb_send(1);
		NRF_P0->OUTCLR = BIT(29);
		return err;
	}
}

int on_timeslot_start_stop(int op)
{
	switch (op) {
	case 0:
		if (esb_link_state != 3) {
			NRF_P0->OUTSET = BIT(31);
			return app_esb_resume();
		}
		break;
	case 1:
		if (radio_active) {
			NRF_P0->OUTCLR = BIT(31);
			return app_esb_suspend();
		}
		break;
	}
	return op;
}

void esb_link_set_high(void)
{
	esb_link_state = 2;
}

void esb_link_set_low(void)
{
	esb_link_state = 1;
}

void esb_link_set_paused(void)
{
	esb_link_state = 3;
}

int esb_link_state_get(void)
{
	return esb_link_state;
}

int esb_tx_busy_get(void)
{
	return tx_busy;
}

/* ESB rx data -> rx msgq + notify (0x1039dfc, align-2 region; no literal pool).
 * Lives outside main.c (see note there); placed here. */
extern int esb_rx_msgq_put(const uint8_t *data);
extern void esb_thread_wake(void);

int esb_rx_enqueue(const uint8_t *data, size_t len)
{
	uint8_t buf[252] = {0};

	memcpy(buf, data, len);
	esb_rx_msgq_put(buf);
	esb_thread_wake();

	return 0;
}

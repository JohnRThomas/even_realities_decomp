/*
 * Even Realities G1 network core - MPSL timeslot handling for the ESB link
 * (reconstruction of v1.63; derived from nrf/samples/mpsl/timeslot).
 */
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/logging/log.h>
#include <mpsl_timeslot.h>
#include <mpsl.h>
#include <hal/nrf_timer.h>
#include <nrf.h>

#include "net_common.h"

LOG_MODULE_REGISTER(timeslot);


/* MPSL API calls that can be requested for the non-preemptible thread */
enum mpsl_timeslot_call {
	REQ_OPEN_SESSION,
	REQ_MAKE_REQUEST,
	REQ_MAKE_REQUEST_NORMAL,
	REQ_CLOSE_SESSION,
};

/* main.c */
extern int net_mode_get(void);                  /* mode */
extern int net_role_get(void);                  /* role */
/* app_esb.c */
extern int esb_tx_busy_get(void);                  /* ESB tx busy */
extern int on_timeslot_start_stop(int op);               /* radio on/off */
/* esb.c (CONFIG_ESB_DYNAMIC_INTERRUPTS) */
extern void RADIO_IRQHandler(void);

/* Timeslot requests */
static mpsl_timeslot_request_t timeslot_request_earliest = {
	.request_type = MPSL_TIMESLOT_REQ_TYPE_EARLIEST,
	.params.earliest.hfclk = MPSL_TIMESLOT_HFCLK_CFG_NO_GUARANTEE,
	.params.earliest.priority = MPSL_TIMESLOT_PRIORITY_HIGH,
	.params.earliest.length_us = 5000,
	.params.earliest.timeout_us = 1000000
};

static mpsl_timeslot_request_t timeslot_request_normal_m = {
	.request_type = MPSL_TIMESLOT_REQ_TYPE_NORMAL,
	.params.normal.hfclk = MPSL_TIMESLOT_HFCLK_CFG_NO_GUARANTEE,
	.params.normal.priority = MPSL_TIMESLOT_PRIORITY_HIGH,
	.params.normal.distance_us = 50000,
	.params.normal.length_us = 5000
};

static mpsl_timeslot_request_t timeslot_request_normal = {
	.request_type = MPSL_TIMESLOT_REQ_TYPE_NORMAL,
	.params.normal.hfclk = MPSL_TIMESLOT_HFCLK_CFG_NO_GUARANTEE,
	.params.normal.priority = MPSL_TIMESLOT_PRIORITY_HIGH,
	.params.normal.distance_us = 50000,
	.params.normal.length_us = 5000
};

static int (*radio_ctrl_cb)(int op);
static volatile int blocked_count;
static mpsl_timeslot_signal_return_param_t signal_callback_return_param;
static int timer0_extend_count;

static volatile uint8_t timeslot_radio_on;
static uint8_t timeslot_stopped;
static uint8_t timeslot_extension_failed;

/* Message queue for requesting MPSL API calls to non-preemptible thread */
K_MSGQ_DEFINE(mpsl_api_msgq, sizeof(enum mpsl_timeslot_call), 4, 4);

static void set_timeslot_active_status(bool on)
{
	if (timeslot_stopped) {
		return;
	}

	if (on) {
		if (!timeslot_radio_on) {
			radio_ctrl_cb(0);	/* == timeslot_radio_on (0) */
			timeslot_radio_on = 1;
		}
	} else if (timeslot_radio_on) {
		radio_ctrl_cb(1);
		timeslot_radio_on = on;
	}
}

static mpsl_timeslot_signal_return_param_t *mpsl_timeslot_callback(
	mpsl_timeslot_session_id_t session_id,
	uint32_t signal_type);

/* To ensure thread safe operation, call all MPSL APIs from a non-preemptible
 * thread.  Static like set_timeslot_active_status (as in the demo's
 * timeslot_handler.c): GCC then emits set_timeslot_active_status first, the
 * shipped order.  K_THREAD_DEFINE at the end of the file: the thread name
 * string sits between this file's log strings and "timeslot" in the image.
 */
static void mpsl_nonpreemptible_thread(void)
{
	int err;
	enum mpsl_timeslot_call api_call = 0;
	/* Initialize to invalid session id */
	mpsl_timeslot_session_id_t session_id = 0xFFu;

	while (1) {
		if (k_msgq_get(&mpsl_api_msgq, &api_call, K_FOREVER) == 0) {
			switch (api_call) {
			case REQ_OPEN_SESSION:
				err = mpsl_timeslot_session_open(
					mpsl_timeslot_callback,
					&session_id);
				if (err) {
					NET_ERR("Timeslot open error: %d\n", err);
					k_oops();
				}
				break;
			case REQ_MAKE_REQUEST:
				err = mpsl_timeslot_request(
					session_id,
					&timeslot_request_earliest);
				if (err) {
					NET_ERR("Timeslot request error %d\n", err);
					k_oops();
				}
				break;
			case REQ_MAKE_REQUEST_NORMAL:
				if (blocked_count) {
					timeslot_request_normal.params.normal.distance_us = 50000 + 5000 * blocked_count;
					err = mpsl_timeslot_request(session_id, &timeslot_request_normal);
				} else {
					err = mpsl_timeslot_request(session_id, &timeslot_request_normal);
				}
				if (err) {
					NET_ERR("Timeslot request error %d\n", err);
					k_oops();
				}
				break;
			case REQ_CLOSE_SESSION:
				err = mpsl_timeslot_session_close(session_id);
				if (err) {
					NET_ERR("Timeslot close error %d\n", err);
					k_oops();
				}
				break;
			default:
				NET_ERR("Wrong timeslot call\n");
				k_oops();
				break;
			}
		}
	}
}

void schedule_request(enum mpsl_timeslot_call api_call)
{
	int err;

	err = k_msgq_put(&mpsl_api_msgq, &api_call, K_NO_WAIT);
	if (err) {
		NET_ERR("Message sent error %d\n", err);
		k_oops();
	}
}

static mpsl_timeslot_signal_return_param_t *mpsl_timeslot_callback(
	mpsl_timeslot_session_id_t session_id,
	uint32_t signal_type)
{
	mpsl_timeslot_signal_return_param_t *p_ret_val = NULL;
	uint8_t busy;

	NRF_P0->OUTSET = BIT(28);

	switch (signal_type) {
	case MPSL_TIMESLOT_SIGNAL_START:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		signal_callback_return_param.params.request.p_next =
			(net_role_get() == 1) ? &timeslot_request_normal_m
					      : &timeslot_request_normal;
		timeslot_extension_failed = 0;
		blocked_count = 0;

		NVIC_ClearPendingIRQ(RADIO_IRQn);
		NRF_RADIO->POWER = 0;
		NRF_RADIO->POWER = 1;
		NVIC_ClearPendingIRQ(RADIO_IRQn);

		nrf_timer_bit_width_set(NRF_TIMER0, NRF_TIMER_BIT_WIDTH_32);
		nrf_timer_cc_set(NRF_TIMER0, NRF_TIMER_CC_CHANNEL0, 3913);
		nrf_timer_int_enable(NRF_TIMER0, NRF_TIMER_INT_COMPARE0_MASK);
		nrf_timer_cc_set(NRF_TIMER0, NRF_TIMER_CC_CHANNEL1, 4813);
		nrf_timer_int_enable(NRF_TIMER0, NRF_TIMER_INT_COMPARE1_MASK);

		set_timeslot_active_status(true);
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_TIMER0:
		busy = esb_tx_busy_get();
		if (nrf_timer_event_check(NRF_TIMER0, NRF_TIMER_EVENT_COMPARE0)) {
			nrf_timer_int_disable(NRF_TIMER0, NRF_TIMER_INT_COMPARE0_MASK);
			nrf_timer_event_clear(NRF_TIMER0, NRF_TIMER_EVENT_COMPARE0);

			if (net_role_get() == 1) {
				if (!busy) {
					signal_callback_return_param.callback_action =
						MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
					timeslot_request_normal_m.params.normal.distance_us =
						50000 + 5000 * timer0_extend_count;
					timer0_extend_count = 0;
					set_timeslot_active_status(false);
				} else {
					timer0_extend_count++;
					signal_callback_return_param.callback_action =
						MPSL_TIMESLOT_SIGNAL_ACTION_EXTEND;
					signal_callback_return_param.params.extend.length_us = 5000;
				}
			} else {
				if (!busy) {
					signal_callback_return_param.callback_action =
						MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
					timeslot_request_normal.params.normal.distance_us =
						50000 + 5000 * timer0_extend_count;
					timer0_extend_count = 0;
					set_timeslot_active_status(false);
				} else {
					timer0_extend_count++;
					signal_callback_return_param.callback_action =
						MPSL_TIMESLOT_SIGNAL_ACTION_EXTEND;
					signal_callback_return_param.params.extend.length_us = 5000;
				}
			}
		} else if (nrf_timer_event_check(NRF_TIMER0, NRF_TIMER_EVENT_COMPARE1)) {
			nrf_timer_int_disable(NRF_TIMER0, NRF_TIMER_INT_COMPARE1_MASK);
			nrf_timer_event_clear(NRF_TIMER0, NRF_TIMER_EVENT_COMPARE1);

			signal_callback_return_param.params.request.p_next =
				(net_role_get() == 1) ? &timeslot_request_normal_m
						      : &timeslot_request_normal;
			if (timeslot_extension_failed) {
				signal_callback_return_param.callback_action = MPSL_TIMESLOT_SIGNAL_ACTION_REQUEST;
				signal_callback_return_param.params.request.p_next = &timeslot_request_earliest;
			} else {
				signal_callback_return_param.callback_action = MPSL_TIMESLOT_SIGNAL_ACTION_REQUEST;
			}
		}
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_EXTEND_SUCCEEDED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		{
			uint32_t cc = nrf_timer_cc_get(NRF_TIMER0, NRF_TIMER_CC_CHANNEL0);

			nrf_timer_bit_width_set(NRF_TIMER0, NRF_TIMER_BIT_WIDTH_32);
			nrf_timer_cc_set(NRF_TIMER0, NRF_TIMER_CC_CHANNEL0, cc + 5000);
			nrf_timer_int_enable(NRF_TIMER0, NRF_TIMER_INT_COMPARE0_MASK);

			cc = nrf_timer_cc_get(NRF_TIMER0, NRF_TIMER_CC_CHANNEL1);
			nrf_timer_bit_width_set(NRF_TIMER0, NRF_TIMER_BIT_WIDTH_32);
			nrf_timer_cc_set(NRF_TIMER0, NRF_TIMER_CC_CHANNEL1, cc + 5000);
			nrf_timer_int_enable(NRF_TIMER0, NRF_TIMER_INT_COMPARE1_MASK);
		}
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_EXTEND_FAILED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		timeslot_extension_failed = 1;
		timer0_extend_count = 0;
		set_timeslot_active_status(false);
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_RADIO:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		if (timeslot_radio_on) {
			RADIO_IRQHandler();
		} else {
			NVIC_ClearPendingIRQ(RADIO_IRQn);
			NVIC_DisableIRQ(RADIO_IRQn);
		}
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_INVALID_RETURN:
	case MPSL_TIMESLOT_SIGNAL_OVERSTAYED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_END;
		set_timeslot_active_status(false);
		schedule_request(REQ_MAKE_REQUEST);
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_CANCELLED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		set_timeslot_active_status(false);
		schedule_request(REQ_MAKE_REQUEST);
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_BLOCKED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		set_timeslot_active_status(false);
		if (net_mode_get() != 1) {
			if (net_role_get() == 1) {
				schedule_request(REQ_MAKE_REQUEST);
			} else {
				blocked_count++;
				schedule_request(REQ_MAKE_REQUEST_NORMAL);
			}
		}
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_SESSION_IDLE:
		schedule_request(REQ_MAKE_REQUEST);
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		set_timeslot_active_status(false);
		p_ret_val = &signal_callback_return_param;
		break;

	case MPSL_TIMESLOT_SIGNAL_SESSION_CLOSED:
		signal_callback_return_param.callback_action =
			MPSL_TIMESLOT_SIGNAL_ACTION_NONE;
		set_timeslot_active_status(false);
		p_ret_val = &signal_callback_return_param;
		break;

	default:
		k_oops();
		break;
	}

	NRF_P0->OUTCLR = BIT(28);
	return p_ret_val;
}

void timeslot_handler_init(int (*cb)(int op))
{
	radio_ctrl_cb = cb;
	schedule_request(REQ_OPEN_SESSION);
	schedule_request(REQ_MAKE_REQUEST);
}

void timeslot_handler_stop(void)
{
	timeslot_stopped = 1;
	on_timeslot_start_stop(1);
	schedule_request(REQ_CLOSE_SESSION);
}

uint8_t timeslot_radio_is_on(void)
{
	return timeslot_radio_on;
}

K_THREAD_DEFINE(mpsl_nonpreemptible_thread_id, CONFIG_MAIN_STACK_SIZE,
		mpsl_nonpreemptible_thread, NULL, NULL, NULL,
		K_PRIO_COOP(0), 0, 0);

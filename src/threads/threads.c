/*
 * Vendor worker threads: low speed peripheral / BLE message / display
 * dispatch, master<->slave sync, key and touch events, NFC, init_threads.
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/toolchain.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include <nrfx.h>
#include <vendor_drivers.h>	/* bt_hci_cmd_send_sync_timeout() on a stock tree */
#include "g1_log.h"
#include "threads.h"
#include "../aw9320x/aw9320x.h"
#include "../ble/ble_ancs.h"
#include "../button/button.h"
#include "../dashboard/dashboard.h"
#include "../display/display_thread.h"
#include "../display/proxy_thread.h"
#include "../fonts/font_bitmap.h"
#include "../gui/gui.h"
#include "../main.h"
#include "../nfc/nfc_wlc.h"
#include "../notify/demo_image.h"
#include "../notify/notify.h"
#include "../panel_display/panel.h"
#include "../production_test/production_test.h"
#include "../sensors_audio/sensors_audio.h"
#include "../storage/storage.h"
#include "../ui/ui.h"
#include "../utils/burial_point.h"

/* unaligned int64 inside a packed task block */

#define CHARGER_DEV DEVICE_DT_GET(DT_NODELABEL(pmic_charger))
uint8_t deferred_text_ack_cmd;   /* 0x20019a69: 0x0d / 0x0f / 0x4e whose last-packet ack waits for the display refresh */
uint8_t deferred_text_ack_total; /* 0x20019a68 */
uint8_t deferred_text_ack_idx;   /* 0x20019a67 */
uint8_t push_msg_syncing;
uint8_t display_suspend_received;                         /* 0x20019a65 (only written) */
uint8_t screen_switch_busy;                         /* 0x20019a64, also used by imu_fusion_thread */
uint8_t long_press_active;                         /* 0x20019a63 long press active (only written) */
uint8_t can_enter_low_power;                  /* 0x20019a62 */
uint8_t is_wearing;                           /* 0x20019a61: wear detection state (check_work_mode) */
static uint8_t wear_cnt;                      /* 0x20019a60 */
uint8_t ble_conn_hold_count;

/* .bss */
uint8_t fuel_gauge_stuck;
static uint8_t esb_sending;                   /* 0x20019a5d */
uint8_t msg_array_busy;                         /* 0x20019a5c g_arrMsgContent busy (main, notification) */
uint8_t new_msg_signal_received;                         /* 0x20019a5b (message_task) */
static uint8_t esb_tx_busy;                   /* 0x20019a5a */
static uint8_t normal_mode;                   /* 0x20019a59 */
static uint8_t key_event_sem_ready;           /* 0x20019a58 */
static uint8_t lp_timeout_handled;            /* 0x20019a57 */
uint8_t nfc_sem_ready;                        /* 0x20019a56 */
static uint8_t unwear_cnt;                    /* 0x20019a55 */
static uint8_t chipid_check_cnt;              /* 0x20019a54 */
static uint8_t box_status_cnt;                /* 0x20019a53 */
static uint8_t charging_cnt;                  /* 0x20019a52 */
static uint8_t bind_count;                    /* 0x20019a51 */
static uint8_t note_retry;                    /* 0x20019a50 */
static uint8_t low_power_entered;             /* 0x20019a4f */
static struct esb_pkt last_status_pkt;        /* 0x20019a39 */
static uint8_t esb_tx_buf[252];               /* 0x2001993d */
static uint8_t last_msg_screen;               /* 0x2001993d (1.66) */
static uint8_t hci_fail_cnt;                  /* 0x2001993c (1.66): consecutive HCI sync command failures */
static uint16_t last_sync_wait;               /* 0x200100d4 */
/* 0x200084d0.. (reverse definition order) */
struct k_mutex screen_payload_mutex;              /* 0x2000851c */
atomic_t dashboard_flags;                        /* 0x20008518 */
atomic_t close_app_flags;                        /* 0x20008514 */
static struct k_sem key_event_sem;            /* 0x200084fc */
static int key_event_type;                    /* 0x200084f8 */
struct k_sem nfc_msg_sem;                     /* 0x200084e0 */
static uint32_t date_ts;                      /* 0x200084dc */
static int date_idx;                          /* 0x200084d8 */
static int date_cnt;                          /* 0x200084d4 */
static int sw0_low_count;                     /* 0x200084d0 */

/* .data (reverse definition order: 0x20003051 down to 0x20003048) */
uint8_t last_ble_cmd = 0xff;                  /* 0x20003051 */
uint8_t wear_state_event = 0xff;              /* 0x20003050: last wear/case event sent (6/7/8/0x0b), GET 0x2B state code */
uint8_t watchdog_enabled = 1;
static uint8_t esb_last_cmd = 0x13;           /* 0x2000304e */
static uint8_t last_bind_state = 0xff;        /* 0x2000304d */
static uint8_t last_box_soc = 0xff;           /* 0x2000304c */
static uint8_t last_box_status = 0xff;        /* 0x2000304b */
static uint8_t last_battery = 0xff;           /* 0x2000304a */
static uint8_t last_charging = 0xff;          /* 0x20003049 */
static uint8_t last_brightness = 0xff;        /* 0x20003048 */

K_THREAD_STACK_DEFINE(low_speed_stack, 0xc00);       /* 0x200277e0 */
K_THREAD_STACK_DEFINE(display_dispatch_stack, 0x800); /* 0x20026fe0 */
K_THREAD_STACK_DEFINE(ble_msg_dispatch_stack, 0x800); /* 0x200267e0 */
K_THREAD_STACK_DEFINE(slave_display_stack, 0x600);   /* 0x200261e0 */
K_THREAD_STACK_DEFINE(touch_key_stack, 0x400);       /* 0x20025de0 */
K_THREAD_STACK_DEFINE(key_event_stack, 0x400);       /* 0x200259e0 */
K_THREAD_STACK_DEFINE(msg_sync_stack, 0x400);        /* 0x200255e0 */
K_THREAD_STACK_DEFINE(nfc_stack, 0xc00);             /* 0x200249e0 */

static struct k_thread low_speed_thread_data;        /* 0x20004858 */
static struct k_thread display_dispatch_thread_data; /* 0x20004780 */
static struct k_thread ble_msg_dispatch_thread_data; /* 0x200046a8 */
static struct k_thread slave_display_thread_data;    /* 0x200045d0 */
static struct k_thread touch_key_thread_data;        /* 0x200044f8 */
static struct k_thread key_event_thread_data;        /* 0x20004420 */
static struct k_thread msg_sync_thread_data;         /* 0x20004348 */
static struct k_thread nfc_thread_data;              /* 0x20004270 */
static int64_t nfc_deadline;                         /* 0x20004268 */
static uint64_t last_activity_ms;             /* 0x20004260: set by update_activity_time, 5 min low-power window */

/* align-2 (no literal pool) */
void check_not_disturb_sync(void)
{
	if (get_dashboard_state()->is_master == 1 && get_dashboard_state()->bitmap_info->sync_pending && is_idle()) {
		sync_not_disturb_bitmap(get_dashboard_state()->bitmap_info->mode);
	} else if (get_dashboard_state()->is_master == 2 && get_dashboard_state()->bitmap_info->sync_pending) {
		sync_not_disturb_bitmap(get_dashboard_state()->bitmap_info->mode);
	}
}

void exit_running_task(struct GlassesState *state, int notify)
{
	uint8_t changed = 0;

	if (!is_task_running(state)) {
		return;
	}
	if (get_dashboard_state()->stay_time_left_s) {
		get_dashboard_state()->stay_time_left_s = 0;
	}
	if (state->translate_src->data[0] || state->translate_dst->data[0]) {
		dmic_stream_stop();
		memset(state->translate_dst->data, 0, 0x1e0);
		memset(state->translate_src->data, 0, 0x1e0);
		changed = true;
	}
	if (state->nav->running) {
		state->nav->running = 0;
		changed = true;
	}
	if (state->teleprompter->ready) {
		dmic_stream_stop();
		state->teleprompter->ready = 0;
		changed = true;
	}
	if (state->quicknote_show_info->enable) {
		dmic_stream_stop();
		state->quicknote_show_info->enable = 0;
		changed = true;
	}
	if (state->dashboard_mode == 6) {
		dmic_stream_stop();
		state->dashboard_ts->dashboard_on = 0;
		changed = true;
	}
	if (state->dashboard_ts->exit_pending == 1) {
		state->dashboard_ts->exit_pending = 2;
	}
	if (state->dashboard_mode == 4) {
		changed = true;
	}
	if (state->onboarding->active) {
		state->onboarding->active = 0;
		changed = true;
	}
	if (state->raster_height_cfg[0]) {
		state->raster_height_cfg[0] = 0;
		changed = true;
	}
	if (state->dash_buf->data[0]) {
		dmic_stream_stop();
		reset_dash_buf(1);
		changed = true;
	}
	if (state->evenai_buf->state == 1) {
		dmic_stream_stop();
		state->evenai_buf->state = 0;
		changed = true;
	} else if (state->evenai_buf->state == 2) {
		state->evenai_buf->state = 3;
	}
	if (state->horiz_pitch_cfg[0]) {
		state->horiz_pitch_cfg[0] = 0;
		changed = true;
	}
	if (state->ts_info->enable) {
		state->ts_info->enable = 0;
		changed = true;
	}
	if (state->transcribe_buf->running) {
		dmic_stream_stop();
		state->transcribe_buf->running = 0;
		changed = true;
	}
	if (!changed) {
		return;
	}
	if (notify) {
		report_event_to_phone(0);
	}
	update_persist_task_status_to_idle(state);
	if (get_dashboard_state()->sync_seq == 6) {
		return;
	}
	memset(state->ui.buf, 0, sizeof(state->ui.buf));
}

static void unlock_screen_payload_mutex(void)
{
	k_mutex_unlock(&screen_payload_mutex);
}

static void ble_msg_dispatch_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	void *msg_ctx = &state->imu;

	G1_LOG_WRN("enter\n");
	memset(state->task_status, 0, sizeof(*state->task_status));
	memset(state->teleprompter, 0, 0x217);
	memset(state->nav, 0, 0xf5);
	memset(state->translate_src, 0, 0x1e8);
	memset(state->translate_dst, 0, 0x1e8);
	memset(state->dash_buf, 0, 0x1e9);
	memset(state->schedule_notif, 0, 0xaf);
	while (1) {
		if (!(state->module_mask & BIT(7))) {
			k_msleep(1000);
			continue;
		}
		screen_task_dispatch(state, msg_ctx);
		while (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}
		k_msleep(25);
	}
}

static void low_speed_peripheral_dispatch_thread_for_test(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	int dfu_count = 0;

	G1_LOG_WRN("#enter\n");
	state->battery_info[0] = 0;
	state->battery_info[1] = 0;
	state->battery_voltage = 0;
	state->battery_current = 0x80;
	while (1) {
		while (state->work_mode == 1) {
			watchdog_disable();
			set_aging_mode(0);
			dmic_stream_stop();
			if (dfu_count > 34) {
				G1_LOG_ERR("reboot because dfu exceed time\r\n\n");
				k_msleep(500);
				sys_reboot(SYS_REBOOT_COLD);
			}
			dfu_count++;
			k_sleep(K_MSEC(5000));
		}
		nfc_wlc_process();
		if (watchdog_enabled) {
			if (!fuel_gauge_stuck) {
				watchdog_feed();
			}
		} else {
			watchdog_disable();
		}
		fuel_gauge_update(CHARGER_DEV, 0);
		aging_charge_check();
		k_sleep(K_MSEC(1000));
	}
}

uint8_t get_wearing_state(void)
{
	return is_wearing;
}

uint8_t get_wear_state_event(void)
{
	return wear_state_event;
}

void check_work_mode(int in_box, int lid_closed, uint8_t report)
{
	uint8_t mode = get_work_mode();
	uint8_t limit;
	uint8_t val;
	uint8_t evt;
	bool wearing;

	if (mode == 0 || mode == 8) {
		return;
	}
	if (report && mode == 1) {
		if (last_bind_state == 0xff ||
		    get_dashboard_state()->ble_context.tx_sem.count == 2) {
			if (get_dashboard_state()->ble_context.tx_sem.count == 2) {
				k_sem_take(&get_dashboard_state()->ble_context.tx_sem, K_FOREVER);
			}
			G1_LOG_ERR("EVENT_GLASS_HAS_FINISH_BIND\n");
			report_event_to_phone(0x11);
			last_bind_state = 0xfe;
		}
		return;
	}
	if (k_uptime_get() < 10000) {
		return;
	}
	if (get_dashboard_state()->battery_voltage <= 0x82 &&
	    get_dashboard_state()->battery_voltage > 0x50 &&
	    get_dashboard_state()->battery_current_ma > 0 &&
	    get_dashboard_state()->battery_info[0] < 2 && !in_box) {
		if (get_dashboard_state()->is_master == 1) {
			sync_to_slave(get_dashboard_state(), 3, NULL, 0);
		} else {
			sync_to_master(get_dashboard_state(), 5, NULL, 0);
		}
		exit_running_task(get_dashboard_state(), 1);
		change_work_mode(7);
		return;
	}

	if (esb_signal > 50) {
		is_wearing = 1;
		if ((unsigned int)(mode - 2) > 1) {
			exit_running_task(get_dashboard_state(), 0);
			change_work_mode(3);
			G1_LOG_ERR("MODE_NORMAL_STANBY_ID\n");
		} else if (is_task_running(get_dashboard_state())) {
			change_work_mode(2);
			G1_LOG_ERR("MODE_NORMAL_RUN_ID\n");
		}
		unwear_cnt = 0;
		val = wear_cnt + 1;
		if (val >= 2) {
			wear_cnt = 2;
			val = chipid_check_cnt + 1;
			if (val < 10) {
				chipid_check_cnt = val;
			} else {
				chipid_check_cnt = 0;
				if (aw9320x_read_chipid()) {
					aw93203_init();
				}
			}
		} else {
			wear_cnt = val;
		}
		wearing = true;
		if (!in_box) {
			enter_wear_burial_point();
			goto check_report;
		}
	} else {
		wearing = false;
		if (esb_signal < 40) {
			chipid_check_cnt = 0;
			if (is_task_running(get_dashboard_state())) {
				limit = get_dashboard_state()->onboarding->active ? 10 : 60;
			} else {
				limit = 3;
			}
			if ((uint8_t)(unwear_cnt + 1) < limit) {
				unwear_cnt++;
			} else {
				unwear_cnt = limit;
				is_wearing = 0;
				wear_cnt = 0;
				if (get_dashboard_state()->double_tap_dashboard_on) {
					get_dashboard_state()->double_tap_dashboard_on = 0;
				}
				if (in_box && lid_closed) {
					exit_running_task(get_dashboard_state(), 1);
					change_work_mode(6);
					G1_LOG_ERR("MODE_CHARGING_LOW_POWER_ID\n");
				} else if (in_box) {
					exit_running_task(get_dashboard_state(), 1);
					change_work_mode(5);
					G1_LOG_ERR("MODE_CHARGING_RUN_ID\n");
				} else if (mode != 4) {
					exit_running_task(get_dashboard_state(), 1);
					change_work_mode(4);
					G1_LOG_ERR("MODE_NORMAL_LOW_POWER_ID\n");
				}
			}
		}
	}
	exit_wear_burial_point();
check_report:

	if (report) {
		if (last_bind_state == 0xff ||
		    get_dashboard_state()->ble_context.tx_sem.count == 2) {
				if (get_dashboard_state()->ble_context.tx_sem.count == 2) {
				k_sem_take(&get_dashboard_state()->ble_context.tx_sem, K_FOREVER);
			}
			G1_LOG_ERR("EVENT_GLASS_HAS_FINISH_BIND\n");
			report_event_to_phone(0x11);
			last_bind_state = 0xfe;
			return;
		}

		if (in_box) {
			if (lid_closed) {
				evt = 0xb;
				G1_LOG_ERR("EVENT_PUT_IN_GLASS_BOX_CLOSE\n");
			} else {
				evt = 8;
				G1_LOG_ERR("EVENT_PUT_IN_GLASS_BOX_OPEN\n");
			}
		} else {
			if (wearing) {
				evt = 6;
				G1_LOG_ERR("EVENT_ENTER_WARED\n");
			} else {
				evt = 7;
				G1_LOG_ERR("EVENT_UNWARED_OUTBOX\n");
			}
			last_box_soc = 0xff;
			last_box_status = 0xff;
			box_status_cnt = 4;
			charging_cnt = 4;
		}
		if (wear_state_event != evt) {
			report_event_to_phone(evt);
			wear_state_event = evt;
			return;
		}

		val = get_dashboard_state()->battery_info[0];
		if (last_battery != val && val <= 100) {
			last_battery = val;
			G1_LOG_ERR("EVENT_STATE_BATTERY_PERCENT %d\n", val);
			report_event_to_phone(10);
			return;
		}

		if (in_box) {
			val = is_box_charging();
			if (val) {
				charging_cnt = 4;
			}
		} else {
			val = 0;
		}
		if (last_charging != val) {
			if (++charging_cnt > 4) {
				charging_cnt = 0;
				get_dashboard_state()->ble_context.charging = val;
				last_charging = val;
				report_event_to_phone(9);
				G1_LOG_ERR("EVENT_STATE_CHARGING %d\n", val);
			}
			return;
		}
		charging_cnt = 0;
		if (in_box) {
			val = get_pt_level_flag();
			if (last_box_status != val) {
				if (++box_status_cnt > 4) {
					box_status_cnt = 0;
					last_box_status = val;
					G1_LOG_ERR("EVENT_GLASS_BOX_STATUS %d\n", val);
					report_event_to_phone(0xe);
				}
				G1_LOG_ERR("last_box_charging_status is %d, box_charging_status is %d\n",
					   last_box_status, val);
				return;
			}
			box_status_cnt = 0;
			val = get_pt_level();
			if (last_box_soc != val && val <= 100) {
				last_box_soc = val;
				G1_LOG_ERR("EVENT_GLASS_BOX_SOC %d\n", val);
				report_event_to_phone(0xf);
				return;
			}
			G1_LOG_ERR("last_box_soc is %d, box_soc is %d\n", last_box_soc, val);
		}

		if (get_dashboard_state()->is_master != 1) {
			return;
		}
		if (!get_dashboard_state()->opt3007_context.ready) {
			return;
		}
		if (opt3007_get_brightness_level(&get_dashboard_state()->opt3007_context) == 0xff) {
			return;
		}
		if (get_dashboard_state()->panel.panel_brightness_level == last_brightness) {
			return;
		}
		last_brightness = get_dashboard_state()->panel.panel_brightness_level;
		report_event_to_phone(0x12);
	} else {
		last_bind_state = 0xff;
		last_box_soc = 0xff;
		last_box_status = 0xff;
		last_battery = 0xff;
		last_charging = 0xff;
		last_brightness = 0xff;
		box_status_cnt = 4;
		charging_cnt = 4;
	}
}

void check_disp_onboarding(int force)
{
	uint8_t data[3];
	int64_t ts;

	if (force != 0 || !is_wearing ||
	    (is_ble_device_bound() && !get_dashboard_state()->onboarding->action)) {
		if (get_dashboard_state()->is_master == 1) {
			onboarding_deactivate();
		}
	} else {
		if (is_wearing && get_dashboard_state()->task_status->task == 0 &&
		    get_dashboard_state()->dashboard_mode == 0 &&
		    get_dashboard_state()->is_master == 1) {
			if (!is_ble_device_bound() || get_dashboard_state()->onboarding->in_progress) {
				if (!is_ble_device_bound()) {
					G1_LOG_WRN("ble device unbound,prepare to show binding tip\n");
					get_dashboard_state()->onboarding->action = 0;
				}
				get_dashboard_state()->onboarding->sub_step = 0;
				onboarding_shown_sub_step = get_dashboard_state()->onboarding->sub_step;
				data[0] = get_dashboard_state()->onboarding->action;
				data[1] = onboarding_shown_sub_step;
				data[2] = 1;
				if (onboarding_sync_data(data, 3) == 0) {
					G1_LOG_ERR("ready to show onboarding...\n");
					onboarding_request_redraw();
					get_dashboard_state()->onboarding->active = 1;
					update_persist_task_status(get_dashboard_state(), 0xe, 2);
					get_dashboard_state()->onboarding->saved_brightness =
						get_dashboard_state()->panel.panel_brightness_level;
					get_dashboard_state()->panel.panel_brightness_level = 42;
					ts = k_uptime_get();
					get_dashboard_state()->onboarding->ts = ts;
					get_dashboard_state()->esb_down_id = get_dashboard_state()->onboarding->sub_step;
				}
			}
		}
	}
}

void check_disp_quicknote(void)
{
	if (get_dashboard_state()->is_master == 1) {
		uint8_t data[2];
		int i;

		if (get_dashboard_state()->quicknote_show_info->longpress_req == 1) {
			get_dashboard_state()->quicknote_show_info->longpress_req = 0;
			if (get_dashboard_state()->dashboard_mode == 12) {
				G1_LOG_ERR("quicknote is running, exit this time\n");
				return;
			}
			data[0] = 1;
			data[1] = 1;
			if (sync_to_slave(get_dashboard_state(), 6, data, 2) >= 5000) {
				G1_LOG_WRN("SYNC TO Slave failed...,don't exec quick note start function.\n");
			} else {
				exit_temp_task(get_dashboard_state(), 0);
				get_dashboard_state()->esb_screen_id = 12;
				get_dashboard_state()->quicknote_show_info->enable = 1;
				get_dashboard_state()->quicknote_show_info->started_by_app = 0;
				get_dashboard_state()->quicknote_show_info->action = 7;
				memset(get_dashboard_state()->quicknote_show_info->data, 0, 0x14a);
				update_persist_task_status(get_dashboard_state(), 12, 2);
			}
		} else if (get_dashboard_state()->quicknote_show_info->longpress_req == 2) {
			get_dashboard_state()->quicknote_show_info->longpress_req = 0;
			data[0] = 1;
			data[1] = 0;
			for (i = 1; i < 4; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, data, 2) >= 5000) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec quick note start function.\n", i);
				} else {
					display_DelayClose(10000);
					k_yield();
					return;
				}
			}
		}
	} else {
		uint8_t data[2];

		if (get_dashboard_state()->quicknote_show_info->longpress_req == 1) {
			get_dashboard_state()->quicknote_show_info->longpress_req = 0;
			if (get_dashboard_state()->dashboard_mode == 12) {
				G1_LOG_ERR("quicknote is running, exit this time\n");
				return;
			}
			data[0] = 1;
			data[1] = 0;
			sync_to_master(get_dashboard_state(), 6, data, 2);
		} else if (get_dashboard_state()->quicknote_show_info->longpress_req == 2) {
			get_dashboard_state()->quicknote_show_info->longpress_req = 0;
			data[0] = 0;
			data[1] = 0;
			sync_to_master(get_dashboard_state(), 6, data, 2);
		}
	}
}

void check_bind_status(struct GlassesState *state, int touched, int bonded)
{
	if (touched) {
		if (bonded) {
			state->force_bind = 0;
		} else if (!state->force_bind) {
			state->force_bind = 1;
			G1_LOG_ERR("enable allow bind mode\n");
		}
		bind_count = 3;
	} else {
		if (bind_count > 0) {
			bind_count--;
		}
		if (bind_count == 0 && state->force_bind == 1) {
			state->force_bind = 0;
			G1_LOG_ERR("disable allow bind mode\n");
		}
	}
}

uint8_t get_glasses_ble_status(void)
{
	struct GlassesState *s1 = get_dashboard_state();
	struct GlassesState *s2 = get_dashboard_state();
	uint8_t connected = (uintptr_t)get_current_conn();   /* vendor stored the conn pointer in a u8 */

	if (ble_conn_hold_count == 15 && connected) {
		if (get_dashboard_state()->is_master == 1) {
			if (s2->esb_pkt.flags & 1) {
				s1->sync_flags |= 3;
			}
		} else {
			s2->esb_pkt.flags |= 1;
		}
	}
	return (s1->sync_flags & 3) == 3;
}

const struct device *get_charger_device(void)
{
	return CHARGER_DEV;
}

void try_enter_low_power_mode(void)
{
	uint16_t wait = 0;
	uint16_t i;
	uint8_t n;

	if (chargerGetVdcRect() >= 5000 || get_dashboard_state()->battery_info[0] < 98 ||
	    !can_enter_low_power) {
		return;
	}
	while (1) {
		G1_LOG_ERR("try to sleep chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n",
			   chargerGetVdcRect(), get_dashboard_state()->battery_info[0], can_enter_low_power);
		for (i = 0; i < 10; i++) {
			if (watchdog_enabled && !fuel_gauge_stuck) {
				watchdog_feed();
			}
			k_msleep(1000);
			nfc_wlc_process();
			fuel_gauge_update(CHARGER_DEV, 0);
			if (chargerGetVdcRect() < 1000) {
				break;
			}
		}
		if (!can_enter_low_power) {
			if (is_box_lid_closed() == 1) {
				G1_LOG_ERR("glass box is close, wait enter low power mode again.\n");
				continue;
			}
			G1_LOG_ERR("force reboot becase can not enter low power mode %d\n", chargerGetVdcRect());
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
		}
		if (chargerGetVdcRect() > 1000 || is_box_lid_closed() != 1) {
			if (i != 10) {
				G1_LOG_ERR("force exit low power mode becase can not enter low power mode %d\n",
					   chargerGetVdcRect());
				change_work_mode(9);
			}
			continue;
		}
		can_enter_low_power = 2;
		while (!low_power_entered && k_uptime_get() - last_activity_ms < 300000) {
			if (watchdog_enabled && !fuel_gauge_stuck) {
				watchdog_feed();
			}
			if (!can_enter_low_power) {
				return;
			}
			k_msleep(1000);
		}
		change_work_mode(8);
		NRF_RESET_S->NETWORK.FORCEOFF = RESET_NETWORK_FORCEOFF_FORCEOFF_Hold;
		low_power_entered = 1;
		G1_LOG_ERR("enter low power mode\n");
		while (get_dashboard_state()->battery_info[0] > 94 && can_enter_low_power) {
			if (wait % 20 == 0 && watchdog_enabled && !fuel_gauge_stuck) {
				watchdog_feed();
			}
			wait++;
			k_msleep(50);
			if (wait >= 1200) {
				fuel_gauge_update(CHARGER_DEV, 0);
				wait = 0;
			}
		}
		change_work_mode(9);
		G1_LOG_ERR("wakeup chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n",
			   chargerGetVdcRect(), get_dashboard_state()->battery_info[0], can_enter_low_power);
		for (n = 0; n < 40 && !can_enter_low_power; n++) {
			if (watchdog_enabled && n % 10 == 0 && !fuel_gauge_stuck) {
				watchdog_feed();
			}
			k_msleep(100);
			nfc_wlc_process();
			fuel_gauge_update(CHARGER_DEV, 0);
		}
		if (is_box_lid_closed() != 1 && chargerGetVdcRect() <= 1000) {
			G1_LOG_ERR("force reboot becase can not get vac %d\n", chargerGetVdcRect());
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
		}
		k_msleep(6000);
	}
}

/* 1.66: reboot through the watchdog instead of sys_reboot(): stop feeding it and arm a
 * short timeout.  Defined here so GCC emits it right after try_enter_low_power_mode. */
void system_reboot_delayed(void)
{
	fuel_gauge_stuck = 1;
	config_watchdog_wait_reset();
}

int sync_to_slave(struct GlassesState *state, int cmd, void *data, size_t len)
{
	uint8_t buf[0xfc] = {0};
	uint32_t date = state->dashboard_ts->ts;
	uint32_t old_date;
	uint16_t wait = 0;
	uint16_t timeout;
	uint16_t n;
	uint16_t busy;
	uint8_t seq;
	uint8_t st;
	uint8_t m;
	uint8_t ms;
	int64_t now;
	int skip = 0;
	int same = 0;
	int ign = 0;

	if (get_work_mode() != 1 && get_dashboard_state()->work_mode != 8 && get_pt_test_mode() != 1 &&
	    state->is_master != 2) {
		now = k_uptime_get();
		n = 501;
		if (state->last_sync_ts == 0 || now - state->last_sync_ts > 5000) {
			timeout = 500;
		} else {
			timeout = 5000;
			if (cmd) {
				timeout = 3000;
			}
		}
		while (task_status_lock && --n) {
			k_msleep(1);
		}
		busy = 0;
		while (esb_sending) {
			k_msleep(1);
			busy++;
		}
		if (busy && esb_last_cmd == cmd) {
			if (cmd) {
				G1_LOG_ERR("ESB send same type cmd %d, exit\n", cmd);
				esb_last_cmd = 0;
				skip = 1;
			}
		} else if (esb_last_cmd == 1) {
			if (cmd != 0) {
				if (cmd == 1 && last_sync_wait < 500) {
					same = 1;
				}
			} else {
				G1_LOG_ERR("ESB send data after suspend cmd, ignore it.\n");
				esb_last_cmd = 0;
				skip = 1;
			}
		} else if (cmd && esb_last_cmd == cmd && cmd != 7 && (cmd < 12 || cmd > 16) && last_sync_wait < 500) {
			same = 1;
		}
		if (same) {
			G1_LOG_ERR("ESB send same cmd, ignore it %d.\n", cmd);
			esb_last_cmd = 0;
			skip = 1;
		}
		if (!skip) {
			esb_sending = 1;
			if (cmd < 3) {
				esb_last_cmd = cmd;
			}
			seq = state->sync_seq;
			if (state->dashboard_mode == 10) {
				st = state->nav->imu_action_status;
			} else {
				st = state->imu.mode;
			}
			state->sync_seq = seq + 1;
			m = st & 3;
			*(uint8_t *)&state->sync_hdr = (m << 6) | (cmd & 0x3f); /* byte write like the vendor */
			state->esb_hdr.dir = 1;
			state->sync_canvas_x = state->canvas_x;
			state->sync_canvas_y = state->panel.current_column + state->canvas_y;
			buf[0] = 2;
			old_date = state->date_ts;
			state->date_ts = date;
			if (data && len) {
				if (len > 4) {
					memcpy(state->sync_data, data, 4);
				} else {
					memcpy(state->sync_data, data, len);
				}
			} else {
				memset(state->sync_data, 0, 4);
			}
			memcpy(&buf[1], &state->esb_hdr, 11);
			memcpy(&buf[12], &state->sync, 21);
			state->sync_ack = 1;
			if (state->esb_screen_id != 6 && state->esb_screen_id != 0 && cmd == 0) {
				ms = state->imu.mode;
				if (state->esb_dir != ms) {
					state->sync_seq = seq;
					G1_LOG_ERR("ESB send imu status is changed, ignore it.\n");
					skip = 1;
				}
				if (skip) {
				} else if (state->dashboard_mode == 16) {
					if (state->esb_up_seq != state->esb_up_id || state->esb_up_recving) {
						state->sync_seq = seq;
						G1_LOG_ERR("ESB send even ai is changed or receiving, ignore it.\n");
						skip = 1;
					}
				} else if (state->esb_dir == 2 && state->esb_up_seq != state->esb_up_id) {
					state->sync_seq = seq;
					G1_LOG_ERR("ESB send up package is changed, ignore it.\n");
					skip = 1;
				}
				if (skip) {
				} else if (state->imu.mode != 2) {
					if (state->imu.mode == 1 && state->esb_down_seq != state->esb_down_id) {
						state->sync_seq = seq;
						G1_LOG_ERR("ESB send down package is changed, ignore it.\n");
						skip = 1;
					}
				} else if (state->esb_up_recving) {
					state->sync_seq = seq;
					G1_LOG_ERR("ESB send up package is receiving, ignore it.\n");
					skip = 1;
				}
				if (!skip && state->imu.mode == 1 && state->esb_down_recving) {
					state->sync_seq = seq;
					G1_LOG_ERR("ESB send down package is receiving, ignore it.\n");
					skip = 1;
				}
				if (!skip && state->esb_screen_id != state->dashboard_mode && state->dashboard_mode > 6 && state->esb_screen_id > 6) {
					state->sync_seq = seq;
					G1_LOG_ERR("ESB send package id is changed, ignore it.\n");
					skip = 1;
				}
			}
		}
		if (skip) {
			wait = 5000;
		} else {
			state->ipc_ctx.send(buf, 0x21);
			for (wait = 0; state->sync_ack != 2; ) {
				if (++wait >= timeout) {
					G1_LOG_ERR("sync to slave failed!!!!!! wait_count %d\n", wait);
					break;
				}
				k_msleep(1);
			}
			if (state->sync_ack == 2) {
				set_date(date);
			} else {
				set_date(old_date);
			}
			if (wait < timeout) {
				state->last_sync_ts = now;
			}
		}
	}
	last_sync_wait = wait;
	esb_sending = 0;
	return wait;
}

unsigned int sync_to_master(struct GlassesState *state, int cmd, void *data, size_t len)
{
	uint16_t wait = 0;
	int skip = 0;
	struct fw_ver *ver = &state->fw_ver;

	if (get_pt_test_mode() == 1) {
		esb_tx_busy = 0;
		return wait;
	}
	while (esb_tx_busy) {
		if (++wait == 2000) {
			esb_tx_busy = 0;
			return wait;
		}
		k_msleep(1);
	}
	esb_tx_busy = 1;
	state->esb_pkt.seq++;
	state->esb_pkt.cmd = (cmd & 0x3f) | 0x80;
	state->esb_pkt.ver.major = ver->major;
	state->esb_pkt.ver.minor = ver->minor;
	state->esb_pkt.ver.patch = ver->patch;
	memcpy(state->esb_pkt.mac, state->slave_mac, sizeof(state->esb_pkt.mac));
	state->esb_pkt.battery = state->battery_info[0];
	if (cmd == 12 || cmd == 13) {
		esb_tx_buf[0] = 4;
		memcpy(&esb_tx_buf[1], &state->esb_pkt, sizeof(state->esb_pkt));
		memcpy(&esb_tx_buf[2], data, len);
		state->sync_ack = 1;
		state->ipc_ctx.send(esb_tx_buf, 0xdc);
	} else {
		if (data && len) {
			memcpy(state->esb_pkt.data, data, MIN(len, 2));
		}
		if (cmd != 1) {
			esb_tx_buf[0] = 4;
			memcpy(&esb_tx_buf[1], &state->esb_pkt, sizeof(state->esb_pkt));
		} else {
			last_status_pkt.seq = state->esb_pkt.seq;
			if (memcmp(&last_status_pkt, &state->esb_pkt, sizeof(last_status_pkt)) == 0) {
				skip = 1;
			} else {
				esb_tx_buf[0] = 4;
				memcpy(&esb_tx_buf[1], &state->esb_pkt, sizeof(state->esb_pkt));
			}
		}
		if (!skip) {
			state->sync_ack = 1;
			state->ipc_ctx.send(esb_tx_buf, 0x21);
		}
	}
	if (!skip) {
		while (state->sync_ack != 2) {
			if (++wait != 2000) {
				k_msleep(1);
				continue;
			}
			if (cmd == 1) {
				memset(&last_status_pkt, 0, sizeof(last_status_pkt));
			}
			break;
		}
		if (cmd == 1 && state->sync_ack == 2) {
			memcpy(&last_status_pkt, &state->esb_pkt, sizeof(last_status_pkt));
		}
	}
	esb_tx_busy = 0;
	return wait;
}

void sync_push_message(void)
{
	struct notif_msg *item;
	uint8_t flag;

	if (get_dashboard_state()->sync_flags & BIT(2)) {
		return;
	}
	flag = get_dashboard_state()->esb_pkt.flags & BIT(2);
	if (flag) {
		return;
	}
	item = get_push_message_copy();
	if (!item) {
		return;
	}
	if (get_dashboard_state()->is_master == 1) {
		switch (item->sync_state) {
		case 1:
			push_msg_syncing = item->sync_state;
			if (sync_to_slave(get_dashboard_state(), 10, &item->uid, 4) < 3000) {
				set_msg_sync_state(item->pos, 2);
			}
			break;
		case 3:
			if (sync_to_slave(get_dashboard_state(), 11, &item->uid, 4) < 3000) {
				set_msg_sync_state(item->pos, 4);
				confirm_message(item->uid);
				push_msg_syncing = flag;
			}
			break;
		}
	} else if (!msg_busy) {
		switch (item->sync_state) {
		case 0:
			push_msg_syncing = 1;
			sync_to_master(get_dashboard_state(), 12, item, 0xda);
			note_retry = 0;
			break;
		case 2:
			if (++note_retry >= 10) {
				note_retry = 0;
				set_msg_sync_state(item->pos, 0);
				push_msg_syncing = 0;
			} else {
				sync_to_master(get_dashboard_state(), 13, (uint8_t *)item + NOTIF_MSG_HALF, 0xda);
			}
			break;
		}
	}
}

void report_event_to_phone(int cmd)
{
	struct ble_context *ctx = get_ble_context();

	if ((unsigned int)(cmd - 0xf0) <= 2 && last_ble_cmd != 0xff) {
		return;
	}
	last_ble_cmd = cmd;
	if (ctx->receiver_thd_is_running || k_sem_count_get(&ctx->rx_sem)) {
		uint8_t buf[3];

		buf[0] = 0xf5;
		buf[2] = 0xcb;
		buf[1] = cmd;
		enqueue_bt_data(buf, 3);
		last_ble_cmd = 0xff;
	} else if (!ctx->receiver_thd_is_running) {
		k_sem_give(&ctx->rx_sem);
		k_msleep(1);
	}
}

/*
 * Defined here, between check_disp_quicknote and slave_display_thread: with this definition order
 * GCC emits check_work_mode, check_disp_quicknote, slave_display_thread, msg_sync_thread and
 * exit_running_task_keep_status / exit_temp_task (align-2) in target order (exit_temp_task is the root whose callers
 * pull in check_disp_quicknote, slave_display_thread and msg_sync_thread).
 */
void exit_running_task_keep_status(struct GlassesState *state, int notify)
{
	uint8_t changed = 0;

	if (!is_task_running(state)) {
		return;
	}
	if (get_dashboard_state()->stay_time_left_s) {
		get_dashboard_state()->stay_time_left_s = 0;
	}
	if (state->translate_src->data[0] || state->translate_dst->data[0]) {
		dmic_stream_stop();
		memset(state->translate_dst->data, 0, 0x1e0);
		memset(state->translate_src->data, 0, 0x1e0);
		changed = true;
	}
	if (state->nav->running) {
		changed = true;
		state->nav->running = 0;
	}
	if (state->teleprompter->ready) {
		dmic_stream_stop();
		changed = true;
		state->teleprompter->ready = 0;
	}
	if (state->quicknote_show_info->enable) {
		dmic_stream_stop();
		changed = true;
		state->quicknote_show_info->enable = 0;
	}
	if (state->dashboard_mode == 6) {
		dmic_stream_stop();
		state->dashboard_ts->dashboard_on = 0;
	}
	if (state->dashboard_ts->exit_pending == 1) {
		state->dashboard_ts->exit_pending = 2;
	}
	if (state->bitmap_info->enable) {
		changed = true;
		state->bitmap_info->enable = 0;
	}
	if (state->onboarding->active) {
		changed = true;
		state->onboarding->active = 0;
	}
	if (state->dash_buf->data[0]) {
		dmic_stream_stop();
		reset_dash_buf(1);
		changed = true;
	}
	if (state->evenai_buf->state == 1) {
		dmic_stream_stop();
		state->evenai_buf->state = 0;
		changed = true;
	} else if (state->evenai_buf->state == 2) {
		state->evenai_buf->state = 3;
	}
	if (state->raster_height_cfg[0]) {
		changed = true;
		state->raster_height_cfg[0] = 0;
	}
	if (state->horiz_pitch_cfg[0]) {
		changed = true;
		state->horiz_pitch_cfg[0] = 0;
	}
	if (state->ts_info->enable) {
		state->ts_info->enable = 0;
		changed = true;
	}
	if (state->transcribe_buf->running) {
		dmic_stream_stop();
		state->transcribe_buf->running = 0;
		changed = true;
	}
	if (!changed) {
		return;
	}
	if (notify) {
		report_event_to_phone(0);
	}
	memset(state->ui.buf, 0, sizeof(state->ui.buf));
}

void exit_temp_task(struct GlassesState *state, int flag)
{
	if (!is_task_running(state)) {
		return;
	}
	if (state->dashboard_mode != 6) {
		if (state->dashboard_mode != 4) {
			return;
		}
	} else {
		dmic_stream_stop();
		state->dashboard_ts->dashboard_on = 0;
		(void)state->dashboard_mode;
	}
	if (flag) {
		report_event_to_phone(0);
	}
	update_persist_task_status_to_idle(state);
	memset(state->ui.buf, 0, sizeof(state->ui.buf));
}

static void slave_display_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;

	state->panel_on = 1;
	state->dashboard_mode = 0;
	G1_LOG_WRN("enter\n");
	if (state->display_mode == 11) {
		change_work_mode(2);
	}
	for (;;) {
		if (state->display_mode != 11) {
			k_sem_take(&state->sem_1, K_FOREVER);
		} else {
			state->sync_hdr.cmd = 0;
			if (!get_pt_test_mode()) {
				state->dashboard_mode = 6;
			} else {
				state->dashboard_mode = 3;
			}
			k_sleep(K_MSEC(1000));
		}
		while (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}
		if (state->esb_arg2 != state->panel.applied_brightness || state->panel.panel_brightness_level != state->esb_arg2) {
			if (get_pt_test_mode() == 1) {
				set_brightness_to_panel_reg_in_running(state->panel.panel_brightness_level);
				state->esb_arg2 = state->panel.panel_brightness_level;
				state->panel.applied_brightness = state->panel.panel_brightness_level;
			} else {
				state->panel.applied_brightness = state->esb_arg2;
				state->panel.panel_brightness_level = state->esb_arg2;
				set_brightness_to_panel_reg_in_running(state->esb_arg2);
			}
		}

		switch (state->sync_hdr.cmd) {
		case 0:
			if (state->suspend_state == 1) {
				if (state->dashboard_mode != 6 && !is_task_running(state)) {
					G1_LOG_ERR("Ignore data...\n");
					break;
				}
				change_work_mode(2);
				if (state->dashboard_mode == 6 && state->imu.mode != 2) {
					state->imu.mode = 2;
				}
			}
			k_sem_give(&state->sem_2);
			break;
		case 1:
			display_suspend_received = 1;
			screen_switch_busy = 1;
			if (state->suspend_state == 0) {
				exit_running_task(state, 0);
				state->imu.mode = 1;
				state->task_status->task = 0;
				trigger_screen_state_change("goto idle2", state, 0);
				k_sem_give(&state->sem_2);
			} else {
				k_sleep(K_MSEC(80));
			}
			break;
		case 2:
			if (state->sync_data[0] == 11) {
				G1_LOG_WRN("slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
					   state->sync_data[1], state->sync_data[2]);
				if (state->sync_data[1] < 10 && state->sync_data[2] < 9) {
					get_dashboard_state()->panel.canvas_distance_gear = state->sync_data[1];
					get_dashboard_state()->panel.raster_height_offset = state->sync_data[2];
					cal_panel_canvas_coord(&get_dashboard_state()->panel.y_offset,
							       (int *)&get_dashboard_state()->panel.current_column);
				}
			}
			screen_switch_busy = 1;
			if (state->dashboard_mode == 9 || state->dashboard_mode == 12 ||
			    state->dashboard_mode == 10 || state->dashboard_mode == 11 ||
			    state->dashboard_mode == 6 || state->dashboard_mode == 7 ||
			    state->dashboard_mode == 14 || state->dashboard_mode == 15 ||
			    state->dashboard_mode == 16 || state->dashboard_mode == 20 ||
			    state->dashboard_mode == 17 || state->dashboard_mode == 18 ||
			    state->dashboard_mode == 19 || state->dashboard_mode == 0) {
				state->imu.mode = 2;
			}
			change_work_mode(2);
			if (state->dashboard_mode != 9 || state->dashboard_mode != 10 ||
			    state->dashboard_mode != 11 || state->dashboard_mode != 16 ||
			    state->dashboard_mode != 20) {
				k_sem_give(&state->sem_2);
			}
			screen_switch_busy = 0;
			break;
		case 3:
			exit_running_task(state, 1);
			change_work_mode(7);
			break;
		case 6:
			if (state->sync_data[0] == 9) {
				upgradeDashboardStartupModeInfoToFlash(state->sync_data[1]);
				break;
			}
			switch (state->sync_data[0]) {
			case 10:
				atomic_or(&dashboard_flags, 2);
				if (state->sync_data[1] == 1) {
					if (get_dashboard_state()->double_tap_customize == 4) {
						state->double_tap_dashboard_on = 1;
					}
				} else if (state->sync_data[1] == 2) {
					state->double_tap_dashboard_on = 0;
					state->dashboard_ts->dashboard_hold = 0;
				}
				break;
			case 1:
				if (state->dashboard_mode == 12) {
					if (state->sync_data[1] == 0) {
						display_DelayClose(10000);
						k_yield();
					}
				} else if (state->sync_data[1] == 1) {
					exit_temp_task(state, 0);
					state->esb_screen_id = 12;
					state->quicknote_show_info->enable = 1;
					state->quicknote_show_info->started_by_app = 0;
					state->quicknote_show_info->action = 7;
					memset(get_dashboard_state()->quicknote_show_info->data, 0, 0x14a);
					update_persist_task_status(state, 12, 2);
					k_sem_give(&state->sem_2);
				}
				break;
			case 2: {
				uint8_t v = state->sync_data[1];
				uint8_t key = v & 0xf;
				uint8_t idx;

				if (key == 1 && state->dashboard_mode == 6) {
					setNotesIndex(v >> 4);
					display_inputEvent(0, 1);
					k_yield();
				} else if (key == 2) {
					setNotesIndex(v >> 4);
				} else if (key == 3 && state->dashboard_mode == 6) {
					setStocksIndex(v >> 4);
					display_inputEvent(0, 1);
					k_yield();
				} else if (key == 4) {
					setStocksIndex(v >> 4);
				} else if (key == 5 && state->dashboard_mode == 6) {
					setNewsIndex(v >> 4);
					display_inputEvent(0, 1);
					k_yield();
				} else if (key == 6) {
					setNewsIndex(v >> 4);
				} else if (key == 7 && state->dashboard_mode == 6) {
					idx = v >> 4;
					setCalenadrIndex(idx);
					display_inputEvent(0, 1);
					k_yield();
					G1_LOG_ERR("received master send touch si gle click command,timestamp = %d,exec key function %d\n",
						   get_date(), idx);
				} else if (key == 8) {
					idx = v >> 4;
					setCalenadrIndex(idx);
					G1_LOG_ERR("received master send calendar index sync commmand ,timestamp = %d,exec index update %d\n",
						   get_date(), idx);
				} else {
					if (v == 9) {
						state->dashboard_ts->exit_pending = 2;
					} else {
						G1_LOG_WRN("received key press event ,slave screen id = %d,drop it ...\n",
							   state->dashboard_mode);
					}
				}
				break;
			}
			case 3:
				if (state->dashboard_mode == 9) {
					if (state->sync_data[1] == 1) {
						display_MasterSendClose();
						k_yield();
					} else {
						G1_LOG_ERR("slave received unknown command,drop it\n");
					}
				} else {
					G1_LOG_ERR("The master Send the teleprompter command, but the slave's current ScreenID is not teleprompter.drop this command..\n");
				}
				break;
			case 6:
				if (state->dashboard_mode == 10) {
					if (state->sync_data[1] == 1) {
						display_MasterSendClose();
						k_yield();
					} else {
						G1_LOG_ERR("slave received unknown command,drop it\n");
					}
				} else {
					G1_LOG_ERR("The master Send the navigation command, but the slave's current ScreenID is not navigation.drop this command..\n");
				}
				break;
			case 7:
				if (state->dashboard_mode == 6) {
					display_powerEvent(state->sync_data[1]);
					k_yield();
				} else {
					G1_LOG_ERR("The master Send the power notify command, but the slave's current ScreenID is not dashboard.drop this command..\n");
				}
				break;
			case 8: {
				uint8_t lang = state->sync_data[1];

				if (CURRENT_LANGUAGE.magic != lang) {
					G1_LOG_WRN("The information sent by the host is different from that of the APP\n");
				}
				upgradeAppLanguageInfoToFlash(lang);
				break;
			}
			case 4: {
				uint8_t show;
				int64_t ts;

				state->esb_down_id = state->onboarding->sub_step;
				state->onboarding->action = state->sync_data[1];
				state->onboarding->sub_step = state->sync_data[2];
				onboarding_check_step_finished();
				onboarding_shown_sub_step = state->sync_data[2];
				show = state->sync_data[3];
				gui_dynamic_bitmap_reset_thunk();
				onboarding_request_redraw();
				ts = k_uptime_get();
				state->onboarding->ts = ts;
				if (state->task_status->task != 14 &&
				    (!is_ble_device_bound() || state->onboarding->in_progress)) {
					if (!is_ble_device_bound()) {
						G1_LOG_WRN("ble device unbound,prepare to show binding tip\n");
					}
					if (show == 1) {
						state->onboarding->active = 1;
						update_persist_task_status(state, 14, 2);
						state->onboarding->saved_brightness = state->panel.panel_brightness_level;
						state->panel.panel_brightness_level = 0x2a;
					}
				} else if (state->onboarding->action == 3) {
					if (onboarding_shown_sub_step == 0x12) {
						state->onboarding->sync_arg = show;
						state->onboarding->calib_state_a = 3;
						state->onboarding->calib_state_b = 3;
					}
				} else if (state->onboarding->action == 11) {
					get_dashboard_state()->onboarding->active = 0;
					get_dashboard_state()->onboarding->in_progress = 0;
				}
				trigger_screen_state_change("IMU:wakeup:onboarding", state, 1);
				k_sem_give(&state->sem_2);
				break;
			}
			case 5:
				show_not_disturb_bitmap(state->sync_data[1]);
				trigger_screen_state_change("TOUCH:wakeup:not_disturb", state, 1);
				k_sem_give(&state->sem_2);
				break;
			case 12:
				upgradeDoubleTapCustomizeToFlash(state->sync_data[1]);
				break;
			case 13:
				upgradeLongpressTapCustomizeToFlash(state->sync_data[1]);
				break;
			case 14:
				if (state->sync_data[1] == 6) {
					exit_temp_task(get_dashboard_state(), 0);
					if (get_dashboard_state()->task_status->task == 0x14 &&
					    get_dashboard_state()->evenai_buf->state == 1 &&
					    get_dashboard_state()->evenai_buf->sub == 4 &&
					    get_dashboard_state()->evenai_buf->action_status == 0x13) {
						G1_LOG_WRN("evenai_v2 need to show network_err tip\n");
						get_dashboard_state()->task_status->status = 2;
						break;
					}
					if (get_dashboard_state()->task_status->task != 0x14) {
						get_dashboard_state()->evenai_buf->state = 1;
						memset(get_dashboard_state()->evenai_buf->data, 0, 0x200);
						update_persist_task_status(get_dashboard_state(), 0x14, 2);
					}
					get_dashboard_state()->evenai_buf->sub = 7;
					get_dashboard_state()->evenai_buf->action_status = state->sync_data[2];
				}
				k_sem_give(&state->sem_2);
				break;
			}
			break;
		case 4:
			exit_running_task(state, 1);
			state->display_mode = 12;
			state->dashboard_cmd = 3;
			k_sem_give(&state->dashboard_position_sem);
			break;
		case 5:
			state->display_mode = 10;
			state->dashboard_cmd = 3;
			k_sem_give(&state->dashboard_position_sem);
			show_not_disturb_bitmap(1);
			break;
		case 7:
			switch (state->sync_data[0]) {
			case 0:
				update_temp_task_status(state, 5, 2);
				trigger_screen_state_change("BLE:wakeup:new-unread_msg", state, 1);
				break;
			case 1:
				msg_busy = 1;
				clear_timeout_message(0);
				set_msg_timeout_flag();
				mark_cur_message_read();
				update_temp_task_status(state, 4, 2);
				trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
				break;
			case 2: {
				g_arrMsgContent_count();
				if (get_dashboard_state()->unread_msg_num) {
					set_msg_show_state(6);
				} else {
					set_msg_show_state(0);
				}
				break;
			}
			case 3:
				new_msg_signal_received = 1;
				if (get_dashboard_state()->message_mode && count_unread_messages() &&
				    get_dashboard_state()->dashboard_mode != 4) {
					update_temp_task_status(get_dashboard_state(), 4, 2);
					trigger_screen_state_change("IMU:wakeup:new-notification",
								    get_dashboard_state(), 1);
					set_msg_timeout_flag();
				}
				handle_msg_touch_key();
				k_sem_give(&get_dashboard_state()->sem_2);
				set_cur_message_state();
				break;
			}
			k_sem_give(&state->sem_2);
			break;
		}
		(void)state->dashboard_mode;
	}
}

static void msg_sync_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	uint8_t data[4];
	int64_t now;

	for (;;) {
		if (get_dashboard_state()->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
			continue;
		}
		if (get_dashboard_state()->is_master == 1) {
			switch (get_dashboard_state()->dash_buf->type) {
			case 1:
				if (sync_to_slave(get_dashboard_state(), 0xd, NULL, 0) < 500) {
					exit_temp_task(state, 0);
					reset_dash_buf(0);
					if (dmic_get_stop_state()) {
						get_dashboard_state()->dash_buf->type = 2;
					} else {
						get_dashboard_state()->dash_buf->type = 3;
					}
					if (get_dashboard_state()->task_status->task != 0x10) {
						update_persist_task_status(get_dashboard_state(), 0x10, 2);
					}
				}
				break;
			case 3:
				if (sync_to_slave(get_dashboard_state(), 0xe, NULL, 0) < 500) {
					get_dashboard_state()->dash_buf->type = 4;
				}
				break;
			case 5:
				if (sync_to_slave(get_dashboard_state(), 0xf, NULL, 0) < 500) {
					dmic_stream_stop();
					report_event_to_phone(0x18);
					get_dashboard_state()->dash_buf->type = 6;
				}
				break;
			case 10:
				if (sync_to_slave(get_dashboard_state(), 0x10, NULL, 0) < 500) {
					get_dashboard_state()->dash_buf->type = 0xb;
					get_dashboard_state()->stay_time_left_s = 8;
				}
				break;
			case 13:
				if (sync_to_slave(get_dashboard_state(), 0x11, NULL, 0) < 500) {
					get_dashboard_state()->dash_buf->type = 0xe;
				}
				break;
			case 15:
				if (sync_to_slave(get_dashboard_state(), 0x12, NULL, 0) < 500) {
					get_dashboard_state()->dash_buf->type = 0x10;
				}
				break;
			}
			if (get_dashboard_state()->evenai_buf->sub == 6 &&
			    get_dashboard_state()->evenai_buf->action_status < 3) {
				data[0] = 0xe;
				data[1] = get_dashboard_state()->evenai_buf->sub;
				data[2] = get_dashboard_state()->evenai_buf->action_status;
				data[3] = 0;
				if (sync_to_slave(get_dashboard_state(), 6, data, 4) < 500) {
					exit_temp_task(get_dashboard_state(), 0);
					if (get_dashboard_state()->task_status->task == 0x14 &&
					    get_dashboard_state()->evenai_buf->state == 1 &&
					    get_dashboard_state()->evenai_buf->sub == 4 &&
					    get_dashboard_state()->evenai_buf->action_status == 0x13) {
						G1_LOG_WRN("evenai_v2 need to show network_err tip\n");
						get_dashboard_state()->task_status->status = 2;
					} else {
						if (get_dashboard_state()->task_status->task != 0x14) {
							get_dashboard_state()->evenai_buf->state = 1;
							memset(get_dashboard_state()->evenai_buf->data, 0, 0x200);
							update_persist_task_status(get_dashboard_state(), 0x14, 2);
						}
						get_dashboard_state()->evenai_buf->sub = 7;
						now = k_uptime_get();
						get_dashboard_state()->evenai_buf->ts = now;
					}
				}
			}
		} else {
			switch (get_dashboard_state()->dash_buf->type) {
			case 1:
				sync_to_master(get_dashboard_state(), 0xf, NULL, 0);
				exit_temp_task(state, 0);
				break;
			case 5:
				sync_to_master(get_dashboard_state(), 0x10, NULL, 0);
				break;
			}
			if (get_dashboard_state()->evenai_buf->sub == 6) {
				data[0] = get_dashboard_state()->evenai_buf->sub;
				data[1] = get_dashboard_state()->evenai_buf->action_status;
				sync_to_master(get_dashboard_state(), 0x11, data, 2);
			}
		}
		sync_push_message();
		if (get_dashboard_state()->is_master == 1 && slave_msg_key_pending) {
			sync_message_signal_to_slave(3);
			if (get_dashboard_state()->message_mode && count_unread_messages() &&
			    get_dashboard_state()->dashboard_mode != 4) {
				update_temp_task_status(get_dashboard_state(), 4, 2);
				trigger_screen_state_change("IMU:wakeup:new-notification",
							    get_dashboard_state(), 1);
				set_msg_timeout_flag();
			}
			slave_msg_key_pending = 0;
			handle_msg_touch_key();
			set_cur_message_state();
		}
		k_msleep(200);
	}
}

void on_double_click(void)
{
	G1_PRINTK("#############################on_double_click################################\n");
	set_aging_mode(2);
}

void exit_silent_mode(void)
{
	if (demo_mode) {
		demo_mode = 0;
	}
	change_work_mode(2);
	global_system_resume(get_dashboard_state());
	get_dashboard_state()->imu.mode = 2;
	get_dashboard_state()->dashboard_mode = 3;
	display_reflash_screen(get_dashboard_state()->dashboard_mode);
	normal_mode = 1;
}

void on_triple_click(void)
{
	G1_PRINTK("#############################on_triple_click################################\n");
	if (!normal_mode) {
		exit_silent_mode();
	} else {
		enter_silent_mode();
	}
}

void enter_silent_mode(void)
{
	get_dashboard_state()->imu.mode = 1;
	display_close_screen(3);
	get_dashboard_state()->dashboard_mode = 0;
	free_demo_line_buf();
	global_system_suspend(get_dashboard_state());
	normal_mode = 0;
}

static void product_test_touch_key_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	uint32_t press_t = 0;
	uint32_t release_t = 0;
	uint32_t now, t1, t2;
	int clicks = 0;
	int mic_on = 0;
	int dur;

	for (;;) {
		k_sem_take(&state->touch_sem, K_MSEC(500));
		if (state->work_mode == 1 || state->work_mode == 8) {
			k_msleep(5000);
			continue;
		}
		if (!(state->module_mask & BIT(0))) {
			continue;
		}
		if (touch_irq_pending) {
			sys_clock_tick_get_32();
			aw9320x_get_irq_stat();
			sys_clock_tick_get_32();
			touch_irq_pending = 0;
		}
		switch (aw9320x_wearing) {
		case IN_EAR:
			now = sys_clock_tick_get_32();
			aw9320x_diff_get(&state->aw_diff);
			if ((int)(now - press_t) > 30000) {
				clicks = 0;
				release_t = 0;
			}
			press_t = now;
			clicks++;
			aw9320x_wearing = UNKNOWN;
			break;
		case OUT_EAR:
			release_t = sys_clock_tick_get_32();
			aw9320x_wearing = UNKNOWN;
			break;
		default:
			break;
		}
		t1 = sys_clock_tick_get_32();
		t2 = sys_clock_tick_get_32();
		if (clicks == 1) {
			if (!mic_on) {
				if (release_t == 0 && (int)(t1 - press_t) > 30000) {
					printk("########################turn on the mic and start to speak! holdtime %d\n",
					       t1 - press_t);
					mic_on = 1;
				}
			} else {
				mic_on = 1;
			}
		}
		if (clicks == 0) {
			continue;
		}
		if ((int)press_t >= (int)release_t || (int)(t2 - release_t) <= 10000) {
			continue;
		}
		if (get_aging_mode() != 1) {
			dur = release_t - press_t;
			if (dur > 150000) {
				printk("#############################long press################################\n");
				aw9320x_diff_get(&state->aw_diff);
				printk("aw9320x_diff_get: %d\n", state->aw_diff);
			} else if (dur > 90000) {
				printk("#############################short press################################\n");
			} else {
				switch (clicks) {
				case 1:
					if (mic_on) {
						printk("turn off mic now\n");
					} else {
						printk("#############################single click################################\n");
						printk("aw9320x_diff_get: %d\n", state->aw_diff);
					}
					break;
				case 2:
					on_double_click();
					break;
				case 3:
					on_triple_click();
					break;
				case 4:
					G1_LOG_ERR("sys reboot because touch event, %d click, reboot now\n\n", 4);
					k_msleep(500);
					sys_reboot(SYS_REBOOT_COLD);
				case 5:
					enter_aging_mode();
					break;
				case 10:
					reset_all_usr_data(state, 1);
					break;
				}
			}
		} else if (get_aging_phase() == 2 && get_dashboard_state()->aging_touch_count < 0xfa) {
			get_dashboard_state()->aging_touch_count++;
		}
		mic_on = 0;
		clicks = 0;
	}
}

static void display_dispatch_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	int last_attitude = 1;
	int bright_cnt = 0;
	uint8_t changed = 0;
	uint8_t *data = NULL;
	int wait;
	size_t len = 0;
	uint8_t prev_changed;
	uint8_t screen;
	struct translate_buf *b1;

	G1_LOG_WRN("enter\n");
	state->panel.f_360 = 0x12;
	state->screen_on = 0;
	G1_LOG_ERR("raster_height_gear:%d, canvas_distance_gear:%d\n",
		   state->panel.raster_height_offset, state->panel.canvas_distance_gear);
	state->panel.current_row = 0;
	cal_panel_canvas_coord(&get_dashboard_state()->panel.y_offset, (int *)&get_dashboard_state()->panel.current_column);
	state->sync_canvas_x = state->panel.current_row + state->canvas_x;
	state->sync_canvas_y = state->panel.current_column + state->canvas_y;
	state->imu.on = 0;
	state->panel_on = 1;
	state->dashboard_mode = 0;
	if (state->display_mode == 11) {
		change_work_mode(2);
		if (get_pt_test_mode() == 1) {
			enter_silent_mode();
		}
	}

	for (;;) {
		while (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}
		if (!state->screen_on && !is_task_running(state)) {
			G1_LOG_WRN("master sync display suspend.\n");
			state->esb_arg2 = state->panel.panel_brightness_level;
			if (get_work_mode() != 3) {
				sync_to_slave(state, 1, NULL, 0);
				change_work_mode(3);
			}
			if (state->is_master == 2) {
				while (k_sem_count_get(&state->sem_2)) {
					k_sem_take(&state->sem_2, K_FOREVER);
				}
				while (k_sem_count_get(&state->screen_on_sem)) {
					k_sem_take(&state->screen_on_sem, K_FOREVER);
				}
			}
			if (!state->screen_on && !is_task_running(state)) {
				G1_LOG_WRN("thread goto sleep.\n");
				screen_switch_busy = 0;
				k_sem_take(&state->screen_on_sem, K_FOREVER);
				if (state->is_master == 2) {
					while (k_sem_count_get(&state->sem_2)) {
						k_sem_take(&state->sem_2, K_FOREVER);
					}
				}
				bright_cnt = 4;
			} else {
				while (k_sem_count_get(&state->screen_on_sem)) {
					k_sem_take(&state->screen_on_sem, K_FOREVER);
				}
			}
			G1_LOG_WRN("thread wakeup!.\n");
			G1_LOG_WRN("sync display resume.\n");
			state->esb_arg2 = state->panel.panel_brightness_level;
			change_work_mode(2);
			changed = 1;
		}
		if (!state->panel_on) {
			goto skip;
		}
		if (state->is_master == 1 && ++bright_cnt == 5) {
			if (state->opt3007_context.auto_brightness && state->opt3007_context.ready && state->panel.init_done) {
				uint8_t target = opt3007_get_brightness_level(&state->opt3007_context);

				if (target == 0xff) {
					bright_cnt = 0;
				} else {
					if (state->panel.panel_brightness_level < target) {
						state->panel.panel_brightness_level++;
					} else if (state->panel.panel_brightness_level > target) {
						state->panel.panel_brightness_level--;
					}
					bright_cnt = (state->panel.panel_brightness_level != target) ? 4 : 0;
				}
			} else {
				bright_cnt = 4;
			}
			if (state->panel.last_synced_brightness != state->panel.panel_brightness_level) {
				state->panel.last_synced_brightness = state->panel.panel_brightness_level;
				if ((state->dashboard_mode == 6 && state->dashboard_ts->area) ||
				    state->dashboard_mode == 10 || state->dashboard_mode == 4) {
					changed = 0;
				} else {
					changed = state->dashboard_mode != 20;
				}
			}
		}
		state->sync_status.task = state->task_status->task;
		state->sync_status.status = state->task_status->status;
		if (state->is_master == 1) {
			state->esb_up_seq = state->esb_up_id;
			state->esb_down_seq = state->esb_down_id;
			state->esb_dir = state->imu.mode;
			state->esb_screen_id = state->dashboard_mode;
		} else {
			int64_t t0;

			if (state->suspend_state == 1 || state->suspend_state == 2 ||
			    state->suspend_state == 4) {
				k_msleep(50);
				continue;
			}
			t0 = k_uptime_get();
			k_sem_take(&state->sem_2, K_MSEC(500));
			if (k_uptime_get() - t0 >= 500) {
				goto skip;
			}
		}
		if (state->display_mode == 12 && state->dashboard_mode != 7) {
			goto skip;
		}
		wait = is_task_running(state);
		if (!wait) {
			if (LOG_LEVEL <= 0) {
				goto next;
			}
			if (*(unsigned int *)&BLE_DEBUG) {
				ble_printk("%s(): no running task, goto next trun\n", __func__);
				goto next;
			}
			printk("%s(): no running task, goto next trun\n", __func__);
			goto skip;
		}
		k_mutex_lock(&screen_payload_mutex, K_FOREVER);
		screen = state->dashboard_mode;
		switch (state->dashboard_mode) {
		case 4: {
			uint8_t retry = 0x33;

			while (state->esb_screen_id != state->dashboard_mode && --retry) {
				k_msleep(10);
			}
			data = (uint8_t *)get_message_by_index(get_cur_show_msg_idx());
			if (take_msg_timeout_flag() || get_dashboard_state()->unread_msg_num != last_msg_screen) {
				last_msg_screen = get_dashboard_state()->unread_msg_num;
			} else if (!changed) {
				unlock_screen_payload_mutex();
				len = 0x1b4;
				goto skip;
			}
			len = 0x1b4;
			changed = 1;
			break;
		}
		case 2:
			countdown_tick(state, state->countdown_ts);
			len = 7;
			data = (uint8_t *)state->countdown_ts;
			break;
		case 9:
			len = 0x217;
			data = (uint8_t *)state->teleprompter;
			break;
		case 12:
			len = 0x152;
			data = (uint8_t *)state->quicknote_show_info;
			break;
		case 10: {
			uint8_t att = state->imu.mode;

			if (att == 2) {
				if (last_attitude != 2 || state->nav->imu_action_status != 2) {
					changed = 1;
					state->nav->imu_action_status = att;
				}
			} else if (att != last_attitude || state->nav->imu_action_status != 1) {
				changed = 1;
				state->nav->imu_action_status = 1;
			}
			len = 0xf5;
			data = (uint8_t *)state->nav;
			break;
		}
		case 11: {
			b1 = state->translate_dst;
			struct translate_buf *b0;
			uint8_t att;

			if ((uint8_t)(b1->screen_status - 5) < 2) {
				data = (uint8_t *)state->esb_up_snapshot;
				if (state->is_master != 2)
					goto use_translate_dst;
				if (state->esb_up_id == state->esb_up_seq)
					goto use_translate_dst;
				if (state->esb_up_snapshot[0x200] != state->esb_up_seq)
					goto use_translate_dst;
			} else if (b0 = state->translate_src, (uint8_t)(b0->screen_status - 5) < 2) {
				if (state->is_master != 2 || state->esb_down_id == state->esb_down_seq ||
				    state->esb_down_snapshot[0x200] != state->esb_down_seq) {
					data = (uint8_t *)b0;
				} else {
					data = (uint8_t *)state->esb_down_snapshot;
				}
			} else if (att = state->imu.mode, att != 2 ? b1->original_type == b1->translation_type : (last_attitude != 2 || b1->original_type == b1->translation_type)) {
				b1->screen_status = 2;
				goto t1038;
			} else if (att == 2) {
t1038:
				if (state->is_master == 2 && state->esb_up_id != state->esb_up_seq &&
				    state->esb_up_snapshot[0x200] == state->esb_up_seq) {
					data = (uint8_t *)state->esb_up_snapshot;
				} else {
					data = (uint8_t *)state->translate_dst;
				}
			} else {
				if (att != last_attitude) {
					b0->screen_status = 4;
				}
				if (state->is_master == 2 && state->esb_down_id != state->esb_down_seq &&
				    state->esb_down_snapshot[0x200] == state->esb_down_seq) {
					data = (uint8_t *)state->esb_down_snapshot;
				} else {
					data = (uint8_t *)state->translate_src;
				}
			}
c11_len:
			len = 0x1e8;
			break;
		}
		case 8:
			len = 0x16a;
			data = (uint8_t *)state->user_sched_info;
			break;
		case 7:
			len = 0xb;
			data = (uint8_t *)state->bitmap_info;
			break;
		case 14:
			get_dashboard_state()->panel.panel_brightness_level = 0x2a;
			len = 0x21;
			data = (uint8_t *)state->onboarding;
			break;
		case 5:
		case 6:
		case 15:
			len = 0x75;
			data = (uint8_t *)state->dashboard_ts;
			break;
		case 16: {
			struct dash_data_buf *blk = state->dash_buf;

			if (blk->type > 11 && (blk->type & 0xfd) == 13) {
				unlock_screen_payload_mutex();
				goto skip;
			}
			if (state->is_master == 2 && state->esb_up_id != state->esb_up_seq &&
			    state->esb_up_seq == state->esb_up_snapshot[0x200]) {
				data = (uint8_t *)state->esb_up_snapshot;
				blk->seq = state->esb_up_snapshot[0x200];
			} else {
				state->dash_buf->seq = get_dashboard_state()->esb_up_id;
				data = (uint8_t *)blk;
			}
			if (state->dash_buf->type == 7) {
				state->dash_buf->screen_status = 3;
				len = 0x1e9;
				break;
			}
			len = 0x1e9;
			break;
		}
		case 20:
			len = 0x210;
			data = (uint8_t *)state->evenai_buf;
			break;
		case 17:
			len = 2;
			data = (uint8_t *)state->horiz_pitch_cfg;
			break;
		case 18:
			len = 10;
			data = (uint8_t *)state->ts_info;
			break;
		case 19:
			len = 0x208;
			data = (uint8_t *)state->transcribe_buf;
			break;
		case 3: {
			uint32_t now = k_uptime_get();

			if (!date_ts) {
				date_ts = now;
			} else if (now - date_ts > 9999) {
				date_idx = (date_idx + 1) % 7;
				date_ts = 0;
			}
			if (0) {
				/*
				 * case 11, first branch: task_1038 not usable -> task_100c.
				 * The difference of the two reads of state->translate_dst is 0;
				 * the compiler only folds it after RTL CSE, which keeps this
				 * block as one shared "mov r5, r3" target of all three tests
				 * (as in the vendor build) instead of if-converting the last one.
				 */
use_translate_dst:
				data = (uint8_t *)b1 +
				       (*(uintptr_t *)((uintptr_t)state + offsetof(struct GlassesState, translate_dst)) -
					*(uintptr_t *)((uintptr_t)&state->nav +
						       (offsetof(struct GlassesState, translate_dst) -
							offsetof(struct GlassesState, nav))));
				goto c11_len;
			}
			date_cnt++;
			state->sync_data[0] = date_idx;
			state->sync_data[1] = date_cnt;
			break;
		}
		}
		if (data) {
			if (memcmp(state->ui.buf, data, len) == 0 && !changed &&
			    state->dashboard_mode == last_ui_screen_id) {
				unlock_screen_payload_mutex();
				goto skip;
			}
			memcpy(state->ui.buf, data, len);
		}
		memset((uint8_t *)state + (offsetof(struct GlassesState, ui.buf) + len), 0, 0x5dc - len);
		state->buf_len.v = len;
		prev_changed = changed;
		unlock_screen_payload_mutex();
		if (state->suspend_state != 0 && state->suspend_state != 5) {
			goto skip;
		}
		if (state->is_master == 1) {
			if (state->esb_arg2 != state->panel.panel_brightness_level) {
				set_brightness_to_panel_reg_in_running(state->panel.panel_brightness_level);
				state->esb_arg2 = state->panel.panel_brightness_level;
			}
			wait = sync_to_slave(state, 0, NULL, 0);
			changed = 1;
			if (wait >= 5000) {
				G1_LOG_ERR("sync to slave exceed MAX_WAIT_COUNT, wait_time %d\n", wait);
				goto skip;
			}
			if (wait >= 3000) {
				G1_LOG_ERR("sync to slave exceed CMD_WAIT_COUNT, wait_time %d\n", wait);
				goto next;
			}
			if (wait >= 500) {
				G1_LOG_ERR("sync to slave exceed LOW_WAIT_COUNT, wait_time %d\n", wait);
				goto next;
			}
			if (state->esb_screen_id != state->dashboard_mode && state->dashboard_mode > 6 &&
			    state->esb_screen_id > 6) {
				G1_LOG_ERR("screen id was changed, g->master_sync_pkg.new_screen_id %d pkg->screen_id %d\n",
					   state->esb_screen_id, state->dashboard_mode);
				wait = 70;
				goto next;
			}
		} else {
			wait = 0;
		}
		if (!is_task_running(state)) {
			G1_LOG_ERR("task was closed!!!\n");
			changed = 1;
			goto next;
		} else if (state->dashboard_mode != screen) {
			G1_LOG_ERR("screen is closed\n");
			changed = 1;
			goto next;
		} else if (!state->screen_on) {
			G1_LOG_ERR("trigger_on_screen is closed\n");
			changed = 1;
			goto next;
		} else {
			uint8_t att = state->imu.mode;

			if (state->dashboard_mode == 10 && last_attitude != att && prev_changed != 1) {
				G1_LOG_WRN("imu->attitude changed ....\n");
			} else {
				last_attitude = att;
			}
			display_reflash_screen(state->dashboard_mode);
			G1_LOG_ERR("display_reflash_screen %d done\n", state->dashboard_mode);
			if (state->esb_screen_id == 6 || state->esb_screen_id == 0 || state->imu.mode == 2 ||
			    state->dashboard_mode == 20) {
				changed = 0;
				goto next;
			}
			changed = 0;
		}
		goto next;
skip:
		wait = 0;
next:
		if (state->is_master == 1) {
			switch (deferred_text_ack_cmd) {
			case 0x0d:
				report_event_to_phone(0xf0);
				break;
			case 0x0f:
				report_event_to_phone(0xf1);
				break;
			case 0x4e:
				report_event_to_phone(0xf2);
				break;
			}
			deferred_text_ack_cmd = 0;
		}
		if (state->is_master == 1) {
			if (wait < 70) {
				k_sleep(K_MSEC(70 - wait));
			}
		} else if (state->suspend_state != 0 && state->suspend_state != 5) {
			k_sleep(K_MSEC(10));
		}
	}
}

static void key_event_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	uint8_t data[2];
	uint8_t mode;
	uint8_t n;
	int i;
	int type;

	init_key_event_sem();
	for (;;) {
		if (get_dashboard_state()->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
			continue;
		}
		if (k_sem_take(&key_event_sem, K_FOREVER) == 0) {
			G1_LOG_ERR("key event trigger, type %d\n\n", key_event_type);
			type = key_event_type;
			if (type == 1) {

				if (state->dashboard_ts->dashboard_hold == 1) {
					continue;
				}
				if (state->onboarding->active) {
					report_event_to_phone(type);
					if (state->onboarding->action == 5) {
						if (get_dashboard_state()->is_master != 2) {
							continue;
						}
						data[0] = 0x13;
						if (onboarding_sync_data(data, type) == 0) {
							state->onboarding->action = 0x13;
						}
					} else if (state->onboarding->action == 0x13) {
						if (get_dashboard_state()->is_master != 2) {
							continue;
						}
						data[0] = 0x14;
						if (onboarding_sync_data(data, type) == 0) {
							state->onboarding->action = 0x14;
						}
					} else {
						if (state->onboarding->action == 0x14 && get_dashboard_state()->is_master == 1) {
							state->onboarding->action = 0x15;
						}
					}
					continue;
				}
				if ((uint8_t)(state->dash_buf->type - 7) <= 4 || state->horiz_pitch_cfg[0] ||
				    (state->evenai_buf->state == 1 && state->evenai_buf->sub == 3)) {
					report_event_to_phone(type);
					continue;
				}
				if (state->teleprompter->ready) {
					report_event_to_phone(type);
				}
				if (state->is_master == 1) {
					if (state->dashboard_mode == 6) {
						mode = get_pane_mode();
						data[0] = 2;
						data[1] = 1;
						if (mode == 0) {
							data[1] |= getNotesIndex() << 4;
						} else if (mode == 1) {
							data[1] = 3;
							data[1] |= getStocksIndex() << 4;
						} else if (mode == 2) {
							data[1] = 5;
							data[1] |= getNewsIndex() << 4;
						} else if (mode == 3) {
							data[1] = 7;
							G1_LOG_ERR("master send calendar key single click ,timestamp = %d\n",
								   state->dashboard_ts->ts);
							data[1] |= getCalenadrIndex() << 4;
						}
						if (sync_to_slave(state, 6, data, 2) >= 5000) {
							G1_LOG_WRN("SYNC TO Slave failed...,don't exec key function.\n");
						} else {
							display_inputEvent(0, 1);
							k_yield();
						}
					}
				} else if (state->is_master == 2 && count_messages()) {
					if ((state->dashboard_mode == 6 && get_dashboard_state()->imu.mode == 2) ||
					    state->dashboard_mode == 4) {
						while (send_msg_key_to_master() < 0) {
						}
					}
				}
			} else switch (type) {
			case 2:
				if (state->onboarding->active) {
					report_event_to_phone(0x19);
					continue;
				}
				if (state->dashboard_mode == 7) {
					continue;
				}
				if (state->task_status->task == 0 && state->dashboard_mode == 0 && state->display_mode != 12) {
					if (state->double_tap_customize == 4) {
						if (state->is_master == 1) {
							data[0] = 0x0a;
							data[1] = 1;
							for (i = 1; i != 4; i++) {
								if (sync_to_slave(state, 6, data, 2) >= 3000) {
									G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n", i);
								} else {
									G1_LOG_ERR("SEND double click event to slave.\n");
									atomic_or(&dashboard_flags, BIT(1));
									state->double_tap_dashboard_on = 1;
									break;
								}
							}
						} else {
							for (i = 1; i != 4; i++) {
								if (sync_to_master(state, 7, NULL, 0) >= 2000) {
									G1_LOG_ERR("SYNC dashborad startup command to start Slave failed %d times\n", i);
								} else {
									G1_LOG_ERR("sync dashborad startup command success,wait for starting\n");
									break;
								}
							}
						}
					} else if (state->double_tap_customize != 0) {
						report_event_to_phone(0x20);
						for (n = 100; n != 0; n--) {
							k_msleep(20);
						}
					}
					continue;
				}
				if (state->dashboard_mode == 6 &&
				    (state->double_tap_customize == 4 || state->dashboard_ts->dashboard_hold != 0)) {
					report_event_to_phone(0);
					if (state->is_master == 1) {
						data[0] = 0x0a;
						data[1] = 2;
						for (i = 1; i != 4; i++) {
							if (sync_to_slave(state, 6, data, 2) >= 3000) {
								G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n", i);
							} else {
								G1_LOG_ERR("SEND double click event to slave.\n");
								state->double_tap_dashboard_on = 0;
								atomic_or(&dashboard_flags, BIT(1));
								state->dashboard_ts->dashboard_hold = 0;
								break;
							}
						}
					} else {
						for (i = 1; i != 4; i++) {
							if (sync_to_master(state, 7, NULL, 0) >= 2000) {
								G1_LOG_ERR("SYNC dashborad startup command to close dashboard Slave failed %d times\n", i);
							} else {
								G1_LOG_ERR("sync dashborad startup command success,close dashboard function\n");
								break;
							}
						}
					}
					continue;
				}
				n = 101;
				while (state->suspend_state > 1 && --n) {
					k_msleep(10);
				}
				if (state->dashboard_mode != 12 ||
				    (state->dashboard_mode == 12 && state->quicknote_show_info->action == 10)) {
					report_event_to_phone(0);
					if (state->is_master == 1) {
						if (state->dashboard_mode == 4) {
							expire_cur_message();
							if (get_dashboard_state()->unread_msg_num) { set_msg_show_state(6); } else { set_msg_show_state(0); }
						}
						data[0] = 1;
						data[1] = 0;
						if (state->dashboard_mode != 6) {
							atomic_or(&close_app_flags, BIT(1));
							for (i = 1; i != 4; i++) {
								if (sync_to_slave(state, 8, data, 2) >= 3000) {
									G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click close app function.\n", i);
								} else {
									G1_LOG_ERR("SEND double click event to slave.\n");
									exit_running_task(state, 0);
									break;
								}
							}
						} else if (state->dashboard_mode == 6) {
							sync_to_slave(state, 8, data, 2);
							exit_running_task(state, 0);
							update_persist_task_status_to_idle(state);
						}
					} else if (state->dashboard_mode != 6) {
						sync_to_master(state, 4, NULL, 0);
						if (get_dashboard_state()->dashboard_mode == 4) {
							expire_cur_message();
							if (get_dashboard_state()->unread_msg_num) { set_msg_show_state(6); } else { set_msg_show_state(0); }
						}
						exit_running_task(state, 0);
					} else if (state->dashboard_mode == 6) {
						sync_to_master(state, 4, NULL, 0);
						if (get_dashboard_state()->dashboard_mode == 4) {
							expire_cur_message();
							if (get_dashboard_state()->unread_msg_num) { set_msg_show_state(6); } else { set_msg_show_state(0); }
						}
						exit_running_task(state, 0);
						update_persist_task_status_to_idle(state);
					}
					break;
				}
				data[0] = 1;
				data[1] = 0;
				for (i = 1; i != 4; i++) {
					if (sync_to_slave(state, 6, data, 2) >= 3000) {
						G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec quick note start function.\n", i);
					} else {
						display_DelayClose(10000);
						k_yield();
						break;
					}
				}
				G1_LOG_WRN("Click event does not respond, close Quicknote to prevent exceptions\n");
				break;
			case 3:
				if (state->onboarding->active || state->dashboard_ts->dashboard_hold == 1) {
					continue;
				}
				if (state->display_mode == 12) {
					report_event_to_phone(5);
					if (state->is_master == 1) {
						if (sync_to_slave(state, 5, NULL, 0) < 3000) {
							show_not_disturb_bitmap(1);
						}
					} else if (sync_to_master(state, 9, NULL, 0) < 2000) {
						show_not_disturb_bitmap(1);
					}
					state->display_mode = 10;
					G1_LOG_ERR("#############################exit not disturb################################\n\n");
				} else {
					report_event_to_phone(4);
					if (state->is_master == 1) {
						sync_to_slave(state, 4, NULL, 0);
						exit_running_task(state, 0);
					} else {
						sync_to_master(state, 8, NULL, 0);
					}
					state->display_mode = 12;
					exit_running_task(state, 1);
					request_not_disturb_bitmap(0);
					G1_LOG_ERR("#############################enter not disturb################################\n\n");
				}
				state->dashboard_cmd = 3;
				k_sem_give(&state->dashboard_position_sem);
				break;
			case 4:
				if (state->onboarding->active || state->dashboard_ts->dashboard_hold == 1) {
					G1_LOG_ERR("[onboarding/set_lum_coeffic] is running, exit this time\n");
					continue;
				}
				long_press_active = 1;
				if (state->display_mode != 12 &&
				    (is_idle() || state->dashboard_mode == 6 || state->dashboard_mode == 1)) {
					if (state->is_master == 2) {
						uint8_t ok = get_glasses_ble_status();

						if (ok == 1) {
							state->evenai_buf->sub = 6;
							state->evenai_buf->action_status = 2;
							report_event_to_phone(0x17);
						} else {
							state->evenai_buf->sub = 6;
							state->evenai_buf->action_status = 1;
						}
					} else {
						state->quicknote_show_info->longpress_req = 1;
						check_disp_quicknote();
					}
				} else {
					G1_LOG_WRN("longpress task cannot be started because screen_id %d, %d, %d\n",
						   state->dashboard_mode, is_idle(), state->display_mode);
				}
				break;
			case 6:
				long_press_active = 0;
				if (state->is_master == 2) {
					if (state->dashboard_mode == 0x10) {
						if (state->dash_buf->type == 4) {
							state->dash_buf->type = 5;
						}
					} else if (state->dashboard_mode == 0x14 && get_glasses_ble_status() == 1 &&
						   state->evenai_buf->sub == 7 && state->evenai_buf->action_status == 2) {
						report_event_to_phone(0x18);
					}
				} else if (!lp_timeout_handled && state->dashboard_mode == 12) {
					lp_timeout_handled = 1;
					state->quicknote_show_info->longpress_req = 2;
					check_disp_quicknote();
				}
				break;
			case 5:
				long_press_active = 0;
				if (state->is_master == 2) {
					if (state->dashboard_mode == 0x10) {
						if (state->dash_buf->type == 4) {
							state->dash_buf->type = 5;
						}
					} else if (state->dashboard_mode == 0x14 && get_glasses_ble_status() == 1 &&
						   state->evenai_buf->sub == 7 && state->evenai_buf->action_status == 2) {
						report_event_to_phone(0x18);
					}
				} else if (state->dashboard_mode == 12) {
					state->quicknote_show_info->longpress_req = 2;
					check_disp_quicknote();
				}
				break;
			default:
				break;
			}
		}
		key_event_type = 0;
	}
}

static void touch_key_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	uint32_t now, t1;
	int press_t = 0;
	int release_t = 0;
	int clicks = 0;
	int lp_timeout = 0;
	int long_press = 0;
	int hold, since_release, press_dur;
	uint8_t n;

	for (;;) {
		k_sem_take(&state->touch_sem, K_MSEC(250));
		if (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_msleep(5000);
			continue;
		}
		if (touch_irq_pending) {
			aw9320x_get_irq_stat();
			touch_irq_pending = 0;
		}
		if (!(state->module_mask & BIT(0))) {
			continue;
		}
		switch (aw9320x_wearing) {
		case IN_EAR:
			now = sys_clock_tick_get_32();
			aw9320x_diff_get(&state->aw_diff);
			if ((int)(now - press_t) > 10000) {
				clicks = 0;
				release_t = 0;
			}
			clicks++;
			aw9320x_wearing = UNKNOWN;
			press_t = now;
			break;
		case OUT_EAR:
			release_t = sys_clock_tick_get_32();
			aw9320x_wearing = UNKNOWN;
			lp_timeout_handled = 0;
			break;
		default:
			break;
		}
		t1 = sys_clock_tick_get_32();
		since_release = sys_clock_tick_get_32() - release_t;
		press_dur = release_t - press_t;
		/*
		 * The release check (released after the press, 10 s debounce, press length) is
		 * written out once per press state, as the vendor did: the target has one copy
		 * each for "released, no long press", "still pressed, short", "long press
		 * running" (rel == 0, both entries) and "long press, released".
		 */
		if (clicks == 1) {
			int times;

			hold = t1 - press_t;
			if (*(uint8_t *)&long_press == 0) {
				if (release_t != 0) {
					if (press_t >= release_t) {
						continue;
					}
					goto e_since;
				}
				aw9320x_diff_get(&state->aw_diff);
				/* upper bound read through the raw field address: keeps two compares like the vendor build */
				{
					int32_t *diff = (int32_t *)((uintptr_t)state + offsetof(struct GlassesState, aw_diff));

					if (state->aw_diff <= -20000 || *diff >= 20000) {
						if (hold <= 15000) {
							if (press_t >= release_t) {
								long_press = 0;
								/* leave through the end of the loop body (not `continue`): the vendor build
								 * emits this edge's copy block before the aw-in-range one at the function end */
								goto x_end;
							}
							goto e_since;
						}
						G1_LOG_ERR("########################turn on the mic and start to speak! holdtime %d\n\n", hold);
						key_event_type = 4;
						trigger_key_event();
						long_press = 1;
						goto lp_check;
					}
					clicks = 0;
					continue;
				}
			} else {
				if (!long_press) {
					continue;
				}
				if (release_t == 0) {
					goto lp_check;
				}
				if (press_t >= release_t) {
					goto c3;
				}
				if (since_release <= 10000) {
					continue;
				}
				if (press_dur > 15000) {
					goto press_end;
				}
				goto single;
			}
lp_check:
				if (lp_timeout) {
					times = 3;
				} else {
					times = 35;
				}
				if (hold <= times * 30000) {
					if (press_t >= 0 || since_release <= 10000) {
						continue;
					}
					if (press_dur > 15000) {
						goto press_end;
					}
					goto single;
				}
				G1_LOG_ERR("#############################Long press timeout %d################################\n\n", lp_timeout);
				key_event_type = 6;
				/* release_t is 0 on both paths into lp_check; copying it (instead of a literal 0) reproduces the vendor's timeout block */
				lp_timeout = release_t;
				long_press = 0;
				clicks = 0;
				trigger_key_event();
		} else {
			if (clicks == 0 || press_t >= release_t) {
				continue;
			}
e_since:
			if (since_release > 10000) {
			if (press_dur > 15000) {
press_end:
				if (press_dur > 36000) {
					/*
					 * G1_LOG_ERR expanded by hand; the printk arm is written twice
					 * behind a test on lp_timeout (both arms print the same; the
					 * test is merged away by the compiler, it only gives
					 * lp_timeout the register-allocation weight of the vendor build).
					 */
					if (LOG_LEVEL > 0) {
						if (BLE_DEBUG) {
							ble_printk("%s(): #############################Long press end################################\n\n", __func__);
						} else if (lp_timeout) {
							printk("%s(): #############################Long press end################################\n\n", __func__);
						} else {
							printk("%s(): #############################Long press end################################\n\n", &__func__[0]);
						}
					}
					key_event_type = 5;
					trigger_key_event();
					if (0) {
single_trig:
						key_event_type = 1;
						trigger_key_event();
					}
					long_press = 0;
					clicks = 0;
				} else {
					G1_LOG_ERR("#############################Short press end################################\n\n");
					lp_timeout = 1;
					release_t = 0;
				}
			} else {
				switch (clicks) {
				case 1:
single:
			G1_LOG_ERR("#############################single click %d################################\n\n", state->aw_diff);
			/* wait up to 3 x 100 ms; the key event itself is sent from the key-5 block below */
			n = 4;
			goto lchk;
			do {
				k_msleep(100);
lchk:
				if (!even_ai_scrolling) {
					goto single_trig;
				}
			} while (--n);
			goto single_trig;
				case 2:
					G1_LOG_ERR("#############################double click################################\n\n");
					key_event_type = 2;
			trigger_key_event();
					break;
				case 3:
					G1_LOG_ERR("#############################triple click################################\n\n");
					key_event_type = 3;
			trigger_key_event();
					break;
				case 6:
					bt_unpair(BT_ID_DEFAULT, NULL);
					state->force_bind = 2;
					G1_LOG_ERR("#############################%d click force bind#############################\n\n", 6);
					break;
				case 15:
					set_band_for_ESB(10);
					G1_LOG_ERR("%d click, use high band for ESB\n\n", 15);
					break;
				case 5:
					if (state->onboarding->active) {
						break;
					}
					G1_LOG_ERR("%d click, reboot now\n\n", 5);
					reset_pmic_on();
					G1_LOG_ERR("reset_pmic_on\n\n");
					reset_pmic_off();
					G1_LOG_ERR("reset_pmic_off\n\n");
					G1_LOG_ERR("sys reboot because touch event, %d click, reboot now\n\n", 5);
					k_msleep(500);
					system_reboot_delayed();
					break;
				case 10:
					reset_all_usr_data(state, 1);
					break;
				case 11:
					reset_all_usr_data(state, 0);
					break;
				default:
					break;
				}
				long_press = 0;
				clicks = 0;
			}
			if (0) {
c3:
				continue;
			}
			}
		}
x_end:
		;
	}
}

static ALWAYS_INLINE bool nfc_timeout(uint32_t ms)
{
	uint64_t elapsed = k_uptime_get() - nfc_deadline;

	return (uint64_t)nfc_deadline < (uint64_t)k_uptime_get() && elapsed > ms;
}

static void nfc_related(void *p1, void *p2, void *p3)
{
	uint8_t it_status;
	uint8_t ret;
	int retry = 0;

	if (k_sem_init(&nfc_msg_sem, 0, 10) == 0) {
		nfc_sem_ready = 1;
	}
	printk("[csh_debug_nfc] g_nfcMsgSemInitOk is %d \n", nfc_sem_ready);
	for (;;) {
		if (get_dashboard_state()->work_mode == 8) {
			nfc_deadline_set(10000);
			set_pt_deadline();
			k_sleep(K_MSEC(50));
		} else if (get_dashboard_state()->work_mode == 1) {
			k_sleep(K_MSEC(5000));
		} else {
			ret = get_pt_test_mode();
			if (ret == 1) {
				if (init_nfc_comm() == 0) {
					set_box_status(BOX_IN_BOX, ret);
					nfc_deadline_set(0);
				} else {
					if (nfc_timeout(5000)) {
						set_box_status(BOX_IN_BOX, 0);
					}
				}
				if (get_dashboard_state()->comflag == 1) {
					init_serial_comm();
				}
				k_sleep(K_MSEC(150));
			} else {
				/* retry loop with a single exit at the bottom: the timeout path stays inside
				 * the loop, so it is not predicted as a cold loop exit and loop2_invariant
				 * hoists &nfc_deadline for it as well (as in the target) */
				bool again;

				do {
					again = false;
					if (k_sem_take(&nfc_msg_sem, K_MSEC(3000)) == 0) {
						it_status = 0;
						if ((uint64_t)nfc_deadline < (uint64_t)k_uptime_get()) {
							nfc_deadline_set(0);
						}
						nfc_read_it_status(&it_status);
						if (it_status & BIT(5)) {
							init_nfc_comm();
						} else if (++retry <= 9) {
							again = true;
							continue;
						}
						set_box_status(BOX_IN_BOX, 1);
						retry = 0;
					} else if (!can_enter_low_power && get_dashboard_state()->work_mode != 8) {
						if (nfc_timeout(3000)) {
							set_box_status(BOX_IN_BOX, 0);
							set_box_status(BOX_LID_CLOSED, 0);
							can_enter_low_power = 0;
						}
					}
				} while (again);
			}
		}
	}
}

void init_key_event_sem(void)
{
	if (k_sem_init(&key_event_sem, 0, 5) == 0) {
		key_event_sem_ready = 1;
	}
}

void trigger_key_event(void)
{
	if (key_event_sem_ready) {
		k_sem_give(&key_event_sem);
	}
}

void trigger_nfc_event(void)
{
	if (nfc_sem_ready) {
		k_sem_give(&nfc_msg_sem);
	}
}

/* returns the new deadline (the shipped code leaves it in r0:r1) */
int64_t nfc_deadline_set(uint32_t ms)
{
	nfc_deadline = k_uptime_get() + ms;
	return nfc_deadline;
}

void update_activity_time(void)
{
	last_activity_ms = k_uptime_get();
}

static void low_speed_peripheral_dispatch_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	struct bt_conn *conn;
	int8_t sec_retry = 0;
	uint8_t cnt = 0;
	int in_box, lid_closed;
	uint8_t connected;
	int err;

	change_work_mode(3);
	update_persist_task_status_to_idle(state);
	G1_LOG_WRN("#enter\n");
	state->battery_voltage = 0;
	state->battery_info[0] = 0;
	state->battery_info[1] = 0;
	state->battery_current = 0x80;
	if (state->is_master == 1 && state->display_mode == 12) {
		sync_to_slave(state, 4, NULL, 0);
	}
	for (;;) {
		cnt++;
		if (cnt % 5 == 0) {
			if (get_dashboard_state()->work_mode != 1) {
				err = bt_hci_cmd_send_sync_timeout(BT_HCI_OP_READ_LOCAL_VERSION_INFO, NULL, NULL,
								   2000, false);
				if (err) {
					if (++hci_fail_cnt > 2 || err == -ETIMEDOUT) {
						hci_fail_cnt = 0;
						G1_LOG_ERR("watch dog reset becase bt hci cmd send sync failed\n");
						system_reboot_delayed();
					}
				} else {
					hci_fail_cnt = 0;
				}
			}
			conn = get_current_conn();
			if (conn && state->ble_context.send_enabled && state->ble_context.security_pending &&
			    k_sem_count_get(&state->ble_context.tx_sem)) {
				if (++sec_retry > 4) {
					bt_conn_set_security(conn, BT_SECURITY_L2);
					sec_retry = -5;
				}
			} else {
				sec_retry = 0;
			}
			state->battery_min = MIN(state->battery_info[0], state->battery_info[1]);
			fuel_gauge_update(CHARGER_DEV, 0);
			in_box = is_in_box();
			lid_closed = is_box_lid_closed();
			connected = conn && !state->ble_context.security_pending && k_sem_count_get(&state->ble_context.tx_sem);
			check_bind_status(state, in_box, lid_closed);
			if (state->is_master == 1) {
				runtime_info_sync(state);
				if (connected && (state->esb_pkt.flags & BIT(0))) {
					state->sync_flags |= 3;
					ble_conn_hold_count = 15;
				} else if (ble_conn_hold_count) {
					ble_conn_hold_count--;
				} else {
					state->sync_flags &= ~3;
				}
				if (sync_to_slave(state, 0xc, NULL, 0) < 500 && (state->sync_flags & BIT(2))) {
					clear_all_messages();
					state->sync_flags &= ~BIT(2);
				}
			} else {
				if (connected) {
					ble_conn_hold_count = 15;
					state->esb_pkt.flags |= BIT(0);
				} else if (ble_conn_hold_count) {
					ble_conn_hold_count--;
				} else {
					state->esb_pkt.flags &= ~BIT(0);
				}
				if ((state->sync_flags ^ state->esb_pkt.flags) & BIT(0)) {
					state->esb_pkt.data[0]++;
				}
				if (sync_to_master(state, 1, NULL, 0) < 500 && (state->esb_pkt.flags & BIT(2))) {
					clear_all_messages();
					state->esb_pkt.flags &= ~BIT(2);
					state->sync_flags &= ~BIT(2);
				}
			}
			nfc_wlc_process();
			while (state->work_mode == 1) {
				if (k_uptime_get() - state->last_sync_ts >= 600000) {
					G1_LOG_ERR("reboot because dfu exceed time\n");
					system_reboot_delayed();
					k_msleep(500);
					continue;
				}
				watchdog_disable();
				if (state->is_master == 1) {
					update_dashboard_clock(state, (uint32_t *)state->dashboard_ts);
				}
				G1_LOG_ERR("********************DFU MODE********************\n");
				check_work_mode(in_box, lid_closed, connected);
				k_sleep(K_MSEC(1000));
			}
			if (watchdog_enabled) {
				if (!fuel_gauge_stuck) {
					watchdog_feed();
				}
			} else {
				watchdog_disable();
			}
			if (state->is_master == 1) {
				update_dashboard_clock(state, (uint32_t *)state->dashboard_ts);
			}
			if (getEraseDFU() && k_uptime_get() >= 60000) {
				erase_dfu_flash();
				setEraseDFU(false);
			}
			G1_LOG_WRN("Global Working Mode: %d get_glasses_ble_status %d ble_is_connected %d\n",
				   state->display_mode, get_glasses_ble_status(), connected);
			try_enter_low_power_mode();
			check_work_mode(in_box, lid_closed, connected);
			check_disp_onboarding(in_box);
			if (conn && !state->phone_is_ios &&
			    (uint32_t)(k_uptime_get() - state->ble_context.last_rx_time) > 30000 && state->work_mode != 1) {
				state->ble_context.last_rx_time = k_uptime_get();
				bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			}
			if (state->user_data_reset_pending) {
				state->user_data_reset_pending = 0;
				exit_running_task(get_dashboard_state(), 0);
				reset_all_usr_data(state, 1);
			}
			check_sw0_status();
			cnt = 0;
		}
		check_not_disturb_sync();
		if (!fuel_gauge_stuck) {
			watchdog_feed();
		}
		k_sleep(K_MSEC(200));
	}
}

void init_threads(struct GlassesState *state)
{
	k_mutex_init(&screen_payload_mutex);
	start_flash_storage_threads(state);
	init_watchdog();
	if (!get_pt_test_mode()) {
		k_thread_create(&low_speed_thread_data, low_speed_stack, K_THREAD_STACK_SIZEOF(low_speed_stack),
				low_speed_peripheral_dispatch_thread, state, NULL, NULL, -10, 0, K_NO_WAIT);
		k_thread_create(&msg_sync_thread_data, msg_sync_stack, K_THREAD_STACK_SIZEOF(msg_sync_stack),
				msg_sync_thread, state, NULL, NULL, -10, 0, K_NO_WAIT);
	} else {
		k_thread_create(&low_speed_thread_data, low_speed_stack, K_THREAD_STACK_SIZEOF(low_speed_stack),
				low_speed_peripheral_dispatch_thread_for_test, state, NULL, NULL, -10, 0, K_NO_WAIT);
		start_aging_mode_thread();
		start_mic_transm_thread();
	}
	k_thread_create(&nfc_thread_data, nfc_stack, K_THREAD_STACK_SIZEOF(nfc_stack),
			nfc_related, NULL, NULL, NULL, -9, 0, K_NO_WAIT);
	if (state->is_master == 1) {
		k_thread_create(&display_dispatch_thread_data, display_dispatch_stack,
				K_THREAD_STACK_SIZEOF(display_dispatch_stack),
				display_dispatch_thread, state, NULL, NULL, -13, 0, K_NO_WAIT);
		k_thread_create(&ble_msg_dispatch_thread_data, ble_msg_dispatch_stack,
				K_THREAD_STACK_SIZEOF(ble_msg_dispatch_stack),
				ble_msg_dispatch_thread, state, NULL, NULL, -12, 0, K_NO_WAIT);
		start_proxy_thread_handler(state);
		start_display_thread_handler(state);
	} else if (state->is_master == 2) {
		k_thread_create(&display_dispatch_thread_data, display_dispatch_stack,
				K_THREAD_STACK_SIZEOF(display_dispatch_stack),
				display_dispatch_thread, state, NULL, NULL, -13, 0, K_NO_WAIT);
		k_thread_create(&ble_msg_dispatch_thread_data, ble_msg_dispatch_stack,
				K_THREAD_STACK_SIZEOF(ble_msg_dispatch_stack),
				ble_msg_dispatch_thread, state, NULL, NULL, -12, 0, K_NO_WAIT);
		k_thread_create(&slave_display_thread_data, slave_display_stack,
				K_THREAD_STACK_SIZEOF(slave_display_stack),
				slave_display_thread, state, NULL, NULL, -11, 0, K_NO_WAIT);
		start_display_thread_handler(state);
	}
	if (get_pt_test_mode() == 1) {
		k_thread_create(&touch_key_thread_data, touch_key_stack, K_THREAD_STACK_SIZEOF(touch_key_stack),
				product_test_touch_key_thread, state, NULL, NULL, -14, 0, K_NO_WAIT);
	} else {
		k_thread_create(&touch_key_thread_data, touch_key_stack, K_THREAD_STACK_SIZEOF(touch_key_stack),
				touch_key_thread, state, NULL, NULL, -14, 0, K_NO_WAIT);
	}
	k_thread_create(&key_event_thread_data, key_event_stack, K_THREAD_STACK_SIZEOF(key_event_stack),
			key_event_thread, state, NULL, NULL, -13, 0, K_NO_WAIT);
}

void check_sw0_status(void)
{
	if (!get_sw0_irq_level()) {
		G1_LOG_WRN("interrupt line low!!!\n");
		if (++sw0_low_count > 3) {
			G1_LOG_WRN("interrupt line abnormal, now reset\n");
			aw93203_init();
		}
	} else {
		sw0_low_count = 0;
	}
}


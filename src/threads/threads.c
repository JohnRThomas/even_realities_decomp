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
#include <nrfx.h>
#include "g1_log.h"
#include "threads.h"

/* declared differently in message_task.c, hence not in threads.h */
uint8_t is_in_box(void);
uint8_t FUN_000352f4(void);

/* unaligned int64 inside a packed task block */
#define BLK_TS_SET(blk, off, v) UNALIGNED_PUT((v), (int64_t *)((uint8_t *)(blk) + (off)))

#define CHARGER_DEV DEVICE_DT_GET(DT_NODELABEL(pmic_charger))
uint8_t deferred_text_ack_cmd;   /* 0x20019a69: 0x0d / 0x0f / 0x4e whose last-packet ack waits for the display refresh */
uint8_t deferred_text_ack_total; /* 0x20019a68 */
uint8_t deferred_text_ack_idx;   /* 0x20019a67 */
uint8_t DAT_20019a66;
uint8_t DAT_20019a65;                         /* 0x20019a65 (only written) */
uint8_t DAT_20019a64;                         /* 0x20019a64, also used by imu_fusion_thread */
uint8_t long_press_active;                         /* 0x20019a63 long press active (only written) */
uint8_t can_enter_low_power;                  /* 0x20019a62 */
uint8_t is_wearing;                           /* 0x20019a61: wear detection state (check_work_mode) */
static uint8_t wear_cnt;                      /* 0x20019a60 */
uint8_t DAT_20019a5f;

/* .bss */
uint8_t DAT_20019a5e;
static uint8_t esb_sending;                   /* 0x20019a5d */
volatile uint8_t DAT_20019a5c;                /* 0x20019a5c g_arrMsgContent busy (main, notification) */
uint8_t DAT_20019a5b;                         /* 0x20019a5b (message_task) */
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
static uint8_t last_msg_screen;               /* 0x2001993c */
static uint16_t last_sync_wait;               /* 0x200100d4 */
/* 0x200084d0.. (reverse definition order) */
struct k_mutex k_mutex_2000851c;              /* 0x2000851c */
atomic_t DAT_20008518;                        /* 0x20008518 */
atomic_t DAT_20008514;                        /* 0x20008514 */
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
uint8_t DAT_2000304f = 1;
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
void FUN_0007ff16(void)
{
	if (get_dashboard_state()->is_master == 1 && get_dashboard_state()->task_1018->f_01 && is_idle()) {
		FUN_00080806(get_dashboard_state()->task_1018->f_02);
	} else if (get_dashboard_state()->is_master == 2 && get_dashboard_state()->task_1018->f_01) {
		FUN_00080806(get_dashboard_state()->task_1018->f_02);
	}
}

void FUN_0007ff66(struct GlassesState *state, int notify)
{
	uint8_t changed = 0;

	if (!FUN_0002da10(state)) {
		return;
	}
	if (get_dashboard_state()->f_0db) {
		get_dashboard_state()->f_0db = 0;
	}
	if (state->task_1008->f_06 || state->task_100c->f_06) {
		FUN_00030458();
		memset(&state->task_100c->f_06, 0, 0x1e0);
		memset(&state->task_1008->f_06, 0, 0x1e0);
		changed = true;
	}
	if (state->task_1004->f_00) {
		state->task_1004->f_00 = 0;
		changed = true;
	}
	if (state->task_1000->f_01) {
		FUN_00030458();
		state->task_1000->f_01 = 0;
		changed = true;
	}
	if (state->task_1034->f_01) {
		FUN_00030458();
		state->task_1034->f_01 = 0;
		changed = true;
	}
	if (state->dashboard_mode == 6) {
		FUN_00030458();
		state->dashboard_ts->f_73 = 0;
		changed = true;
	}
	if (state->dashboard_ts->f_74 == 1) {
		state->dashboard_ts->f_74 = 2;
	}
	if (state->dashboard_mode == 4) {
		changed = true;
	}
	if (state->onboarding->active) {
		state->onboarding->active = 0;
		changed = true;
	}
	if (state->task_1020->f_00) {
		state->task_1020->f_00 = 0;
		changed = true;
	}
	if (state->task_1010->f_07) {
		FUN_00030458();
		FUN_00080338(1);
		changed = true;
	}
	if (state->task_1014->f_00 == 1) {
		FUN_00030458();
		state->task_1014->f_00 = 0;
		changed = true;
	} else if (state->task_1014->f_00 == 2) {
		state->task_1014->f_00 = 3;
	}
	if (state->task_1024->f_00) {
		state->task_1024->f_00 = 0;
		changed = true;
	}
	if (state->task_1028->f_00) {
		state->task_1028->f_00 = 0;
		changed = true;
	}
	if (state->task_102c->f_00) {
		FUN_00030458();
		state->task_102c->f_00 = 0;
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
	memset(state->buf_0ef, 0, sizeof(state->buf_0ef));
}

static void unlock_mutext_2000851c(void)
{
	k_mutex_unlock(&k_mutex_2000851c);
}

static void ble_msg_dispatch_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	void *msg_ctx = &state->msg_ctx;

	G1_LOG_WRN("enter\n");
	memset(state->f_1068, 0, sizeof(*state->f_1068));
	memset(state->task_1000, 0, 0x217);
	memset(state->task_1004, 0, 0xf5);
	memset(state->task_1008, 0, 0x1e8);
	memset(state->task_100c, 0, 0x1e8);
	memset(state->task_1010, 0, 0x1e9);
	memset(state->task_ffc, 0, 0xaf);
	while (1) {
		if (!(state->module_mask & BIT(7))) {
			k_msleep(1000);
			continue;
		}
		process_for_new_message_come_on(state, msg_ctx);
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
			FUN_00033e2c(0);
			FUN_00030458();
			if (dfu_count > 34) {
				G1_LOG_ERR("reboot because dfu exceed time\r\n\n");
				k_msleep(500);
				sys_reboot(SYS_REBOOT_COLD);
			}
			dfu_count++;
			k_sleep(K_MSEC(5000));
		}
		FUN_00027744();
		if (DAT_2000304f) {
			if (!DAT_20019a5e) {
				watchdog_feed();
			}
		} else {
			watchdog_disable();
		}
		fuel_gauge_update(CHARGER_DEV, 0);
		FUN_000344c8();
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
	uint8_t mode = FUN_000169b4();
	uint8_t limit;
	uint8_t val;
	uint8_t evt;
	bool wearing;

	if (mode == 0 || mode == 8) {
		return;
	}
	if (report && mode == 1) {
		if (last_bind_state == 0xff ||
		    get_dashboard_state()->ble_context.sem_230.count == 2) {
			if (get_dashboard_state()->ble_context.sem_230.count == 2) {
				k_sem_take(&get_dashboard_state()->ble_context.sem_230, K_FOREVER);
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
	    get_dashboard_state()->f_fcc > 0 &&
	    get_dashboard_state()->battery_info[0] < 2 && !in_box) {
		if (get_dashboard_state()->is_master == 1) {
			sync_to_slave(get_dashboard_state(), 3, NULL, 0);
		} else {
			sync_to_master(get_dashboard_state(), 5, NULL, 0);
		}
		FUN_0007ff66(get_dashboard_state(), 1);
		change_work_mode(7);
		return;
	}

	if (DAT_20006bc8 > 50) {
		is_wearing = 1;
		if ((unsigned int)(mode - 2) > 1) {
			FUN_0007ff66(get_dashboard_state(), 0);
			change_work_mode(3);
			G1_LOG_ERR("MODE_NORMAL_STANBY_ID\n");
		} else if (FUN_0002da10(get_dashboard_state())) {
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
		if (DAT_20006bc8 < 40) {
			chipid_check_cnt = 0;
			if (FUN_0002da10(get_dashboard_state())) {
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
				if (get_dashboard_state()->f_1245) {
					get_dashboard_state()->f_1245 = 0;
				}
				if (in_box && lid_closed) {
					FUN_0007ff66(get_dashboard_state(), 1);
					change_work_mode(6);
					G1_LOG_ERR("MODE_CHARGING_LOW_POWER_ID\n");
				} else if (in_box) {
					FUN_0007ff66(get_dashboard_state(), 1);
					change_work_mode(5);
					G1_LOG_ERR("MODE_CHARGING_RUN_ID\n");
				} else if (mode != 4) {
					FUN_0007ff66(get_dashboard_state(), 1);
					change_work_mode(4);
					G1_LOG_ERR("MODE_NORMAL_LOW_POWER_ID\n");
				}
			}
		}
	}
	FUN_00081230();
check_report:

	if (report) {
		if (last_bind_state == 0xff ||
		    get_dashboard_state()->ble_context.sem_230.count == 2) {
				if (get_dashboard_state()->ble_context.sem_230.count == 2) {
				k_sem_take(&get_dashboard_state()->ble_context.sem_230, K_FOREVER);
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
			val = FUN_00033754();
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
			val = FUN_00033760();
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
		if (!get_dashboard_state()->f_f94) {
			return;
		}
		if (FUN_00010848(get_dashboard_state()->opt3007_ctx) == 0xff) {
			return;
		}
		if (get_dashboard_state()->panel_brightness == last_brightness) {
			return;
		}
		last_brightness = get_dashboard_state()->panel_brightness;
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
	    (FUN_0007f3da() && !get_dashboard_state()->onboarding->f_02)) {
		if (get_dashboard_state()->is_master == 1) {
			FUN_00080992();
		}
	} else {
		if (is_wearing && get_dashboard_state()->f_1068->task == 0 &&
		    get_dashboard_state()->dashboard_mode == 0 &&
		    get_dashboard_state()->is_master == 1) {
			if (!FUN_0007f3da() || get_dashboard_state()->onboarding->f_01) {
				if (!FUN_0007f3da()) {
					G1_LOG_WRN("ble device unbound,prepare to show binding tip\n");
					get_dashboard_state()->onboarding->f_02 = 0;
				}
				get_dashboard_state()->onboarding->f_03 = 0;
				DAT_2001db40 = get_dashboard_state()->onboarding->f_03;
				data[0] = get_dashboard_state()->onboarding->f_02;
				data[1] = DAT_2001db40;
				data[2] = 1;
				if (onboarding_sync_data(data, 3) == 0) {
					G1_LOG_ERR("ready to show onboarding...\n");
					FUN_00042830();
					get_dashboard_state()->onboarding->active = 1;
					update_persist_task_status(get_dashboard_state(), 0xe, 2);
					get_dashboard_state()->onboarding->saved_brightness =
						get_dashboard_state()->panel_brightness;
					get_dashboard_state()->panel_brightness = 42;
					ts = k_uptime_get();
					get_dashboard_state()->onboarding->ts = ts;
					get_dashboard_state()->f_0cd = get_dashboard_state()->onboarding->f_03;
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

		if (get_dashboard_state()->task_1034->f_00 == 1) {
			get_dashboard_state()->task_1034->f_00 = 0;
			if (get_dashboard_state()->dashboard_mode == 12) {
				G1_LOG_ERR("quicknote is running, exit this time\n");
				return;
			}
			data[0] = 1;
			data[1] = 1;
			if (sync_to_slave(get_dashboard_state(), 6, data, 2) >= 5000) {
				G1_LOG_WRN("SYNC TO Slave failed...,don't exec quick note start function.\n");
			} else {
				FUN_00080224(get_dashboard_state(), 0);
				get_dashboard_state()->f_0ec = 12;
				get_dashboard_state()->task_1034->f_01 = 1;
				get_dashboard_state()->task_1034->f_02 = 0;
				get_dashboard_state()->task_1034->f_03 = 7;
				memset(get_dashboard_state()->task_1034->data, 0, 0x14a);
				update_persist_task_status(get_dashboard_state(), 12, 2);
			}
		} else if (get_dashboard_state()->task_1034->f_00 == 2) {
			get_dashboard_state()->task_1034->f_00 = 0;
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

		if (get_dashboard_state()->task_1034->f_00 == 1) {
			get_dashboard_state()->task_1034->f_00 = 0;
			if (get_dashboard_state()->dashboard_mode == 12) {
				G1_LOG_ERR("quicknote is running, exit this time\n");
				return;
			}
			data[0] = 1;
			data[1] = 0;
			sync_to_master(get_dashboard_state(), 6, data, 2);
		} else if (get_dashboard_state()->task_1034->f_00 == 2) {
			get_dashboard_state()->task_1034->f_00 = 0;
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
	uint8_t connected = (uintptr_t)FUN_00019cec();   /* vendor stored the conn pointer in a u8 */

	if (DAT_20019a5f == 15 && connected) {
		if (get_dashboard_state()->is_master == 1) {
			if (s2->esb_pkt.flags & 1) {
				s1->f_0e4 |= 3;
			}
		} else {
			s2->esb_pkt.flags |= 1;
		}
	}
	return (s1->f_0e4 & 3) == 3;
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

	if (FUN_00027664() >= 5000 || get_dashboard_state()->battery_info[0] < 98 ||
	    !can_enter_low_power) {
		return;
	}
	watchdog_disable();
	while (1) {
		G1_LOG_ERR("try to sleep chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n",
			   FUN_00027664(), get_dashboard_state()->battery_info[0], can_enter_low_power);
		for (i = 0; i < 10; i++) {
			k_msleep(1000);
			FUN_00027744();
			fuel_gauge_update(CHARGER_DEV, 0);
			if (FUN_00027664() < 1000) {
				break;
			}
		}
		if (!can_enter_low_power) {
			if (is_box_lid_closed() == 1) {
				G1_LOG_ERR("glass box is close, wait enter low power mode again.\n");
				continue;
			}
			G1_LOG_ERR("force reboot becase can not enter low power mode %d\n", FUN_00027664());
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
		}
		if (FUN_00027664() > 1000 || is_box_lid_closed() != 1) {
			if (i != 10) {
				G1_LOG_ERR("force exit low power mode becase can not enter low power mode %d\n",
					   FUN_00027664());
				change_work_mode(9);
			}
			continue;
		}
		can_enter_low_power = 2;
		while (!low_power_entered && k_uptime_get() - last_activity_ms < 300000) {
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
			wait++;
			k_msleep(50);
			if (wait >= 1200) {
				fuel_gauge_update(CHARGER_DEV, 0);
				wait = 0;
			}
		}
		change_work_mode(9);
		G1_LOG_ERR("wakeup chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n",
			   FUN_00027664(), get_dashboard_state()->battery_info[0], can_enter_low_power);
		for (n = 40; n > 0 && !can_enter_low_power; n--) {
			k_msleep(100);
			FUN_00027744();
			fuel_gauge_update(CHARGER_DEV, 0);
		}
		if (is_box_lid_closed() != 1 && FUN_00027664() <= 1000) {
			G1_LOG_ERR("force reboot becase can not get vac %d\n", FUN_00027664());
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
		}
		k_msleep(6000);
	}
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

	if (FUN_000169b4() == 1 || get_dashboard_state()->work_mode == 8 || FUN_00033d5c() == 1 ||
	    state->is_master == 2) {
		goto out;
	}
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
ignore:
			esb_last_cmd = 0;
skip:
			wait = 5000;
			goto out;
		}
	} else if (esb_last_cmd == 1) {
		if (cmd != 0) {
			if (cmd == 1 && last_sync_wait < 500) {
				goto same_cmd;
			}
			goto send;
		}
		G1_LOG_ERR("ESB send data after suspend cmd, ignore it.\n");
		goto ignore;
	} else if (cmd && esb_last_cmd == cmd && cmd != 7 && (cmd < 12 || cmd > 16) && last_sync_wait < 500) {
same_cmd:
		G1_LOG_ERR("ESB send same cmd, ignore it %d.\n", cmd);
		goto ignore;
	}
send:
	esb_sending = 1;
	if (cmd < 3) {
		esb_last_cmd = cmd;
	}
	seq = state->sync_seq;
	if (state->dashboard_mode == 10) {
		st = state->task_1004->f_07;
	} else {
		st = state->msg_ctx.state;
	}
	state->sync_seq = seq + 1;
	m = st & 3;
	state->sync_cmd = (m << 6) | (cmd & 0x3f);
	state->sync_flag_bits.mode = 1;
	state->sync_d6 = state->f_108a;
	state->sync_d8 = state->f_eb8 + state->f_108c;
	buf[0] = 2;
	old_date = state->sync_date;
	state->sync_date = date;
	if (data && len) {
		if (len > 4) {
			memcpy(state->sync_data, data, 4);
		} else {
			memcpy(state->sync_data, data, len);
		}
	} else {
		memset(state->sync_data, 0, 4);
	}
	memcpy(&buf[1], &state->sync_flags, 11);
	memcpy(&buf[12], &state->sync_cmd, 21);
	state->sync_ack = 1;
	if (state->f_0ec != 6 && state->f_0ec != 0 && cmd == 0) {
		ms = state->msg_ctx.state;
		if (state->f_0eb != ms) {
			state->sync_seq = seq;
			G1_LOG_ERR("ESB send imu status is changed, ignore it.\n");
			goto skip;
		}
		if (state->dashboard_mode == 16) {
			if (state->f_0e9 != state->f_0cc || state->f_0ce) {
				state->sync_seq = seq;
				G1_LOG_ERR("ESB send even ai is changed or receiving, ignore it.\n");
				goto skip;
			}
		} else if (state->f_0eb == 2 && state->f_0e9 != state->f_0cc) {
			state->sync_seq = seq;
			G1_LOG_ERR("ESB send up package is changed, ignore it.\n");
			goto skip;
		}
		if (state->msg_ctx.state != 2) {
			if (state->msg_ctx.state == 1 && state->f_0ea != state->f_0cd) {
				state->sync_seq = seq;
				G1_LOG_ERR("ESB send down package is changed, ignore it.\n");
				goto skip;
			}
		} else if (state->f_0ce) {
			state->sync_seq = seq;
			G1_LOG_ERR("ESB send up package is receiving, ignore it.\n");
			goto skip;
		}
		if (state->msg_ctx.state == 1 && state->f_0cf) {
			state->sync_seq = seq;
			G1_LOG_ERR("ESB send down package is receiving, ignore it.\n");
			goto skip;
		}
		if (state->f_0ec != state->dashboard_mode && state->dashboard_mode > 6 && state->f_0ec > 6) {
			state->sync_seq = seq;
			G1_LOG_ERR("ESB send package id is changed, ignore it.\n");
			goto skip;
		}
	}
	state->esb_send(buf, 0x21);
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
out:
	last_sync_wait = wait;
	esb_sending = 0;
	return wait;
}

unsigned int sync_to_master(struct GlassesState *state, int cmd, void *data, size_t len)
{
	uint16_t wait = 0;
	struct fw_ver *ver = &state->fw_ver;

	if (FUN_00033d5c() == 1) {
		goto out;
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
		state->esb_send(esb_tx_buf, 0xdc);
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
				goto out;
			}
			esb_tx_buf[0] = 4;
			memcpy(&esb_tx_buf[1], &state->esb_pkt, sizeof(state->esb_pkt));
		}
		state->sync_ack = 1;
		state->esb_send(esb_tx_buf, 0x21);
	}
	while (state->sync_ack != 2) {
		if (++wait != 2000) {
			k_msleep(1);
			continue;
		}
		if (cmd == 1) {
			memset(&last_status_pkt, 0, sizeof(last_status_pkt));
		}
		goto out;
	}
	if (cmd == 1) {
		memcpy(&last_status_pkt, &state->esb_pkt, sizeof(last_status_pkt));
	}
out:
	esb_tx_busy = 0;
	return wait;
}

void FUN_00029684(void)
{
	struct note_item *item;
	uint8_t flag;

	if (get_dashboard_state()->f_0e4 & BIT(2)) {
		return;
	}
	flag = get_dashboard_state()->esb_pkt.flags & BIT(2);
	if (flag) {
		return;
	}
	item = FUN_0003519c();
	if (!item) {
		return;
	}
	if (get_dashboard_state()->is_master == 1) {
		switch (item->state) {
		case 1:
			DAT_20019a66 = item->state;
			if (sync_to_slave(get_dashboard_state(), 10, &item->id, 4) < 3000) {
				FUN_00035204(item->idx, 2);
			}
			break;
		case 3:
			if (sync_to_slave(get_dashboard_state(), 11, &item->id, 4) < 3000) {
				FUN_00035204(item->idx, 4);
				confirm_message(item->id);
				DAT_20019a66 = flag;
			}
			break;
		}
	} else if (!msg_busy) {
		switch (item->state) {
		case 0:
			DAT_20019a66 = 1;
			sync_to_master(get_dashboard_state(), 12, item, 0xda);
			note_retry = 0;
			break;
		case 2:
			if (++note_retry >= 10) {
				note_retry = 0;
				FUN_00035204(item->idx, 0);
				DAT_20019a66 = 0;
			} else {
				sync_to_master(get_dashboard_state(), 13, &item->data2, 0xda);
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
 * FUN_000800ca / FUN_00080224 (align-2) in target order (FUN_00080224 is the root whose callers
 * pull in check_disp_quicknote, slave_display_thread and msg_sync_thread).
 */
void FUN_000800ca(struct GlassesState *state, int notify)
{
	uint8_t changed = 0;

	if (!FUN_0002da10(state)) {
		return;
	}
	if (get_dashboard_state()->f_0db) {
		get_dashboard_state()->f_0db = 0;
	}
	if (state->task_1008->f_06 || state->task_100c->f_06) {
		FUN_00030458();
		memset(&state->task_100c->f_06, 0, 0x1e0);
		memset(&state->task_1008->f_06, 0, 0x1e0);
		changed = true;
	}
	if (state->task_1004->f_00) {
		changed = true;
		state->task_1004->f_00 = 0;
	}
	if (state->task_1000->f_01) {
		FUN_00030458();
		changed = true;
		state->task_1000->f_01 = 0;
	}
	if (state->task_1034->f_01) {
		FUN_00030458();
		changed = true;
		state->task_1034->f_01 = 0;
	}
	if (state->dashboard_mode == 6) {
		FUN_00030458();
		state->dashboard_ts->f_73 = 0;
	}
	if (state->dashboard_ts->f_74 == 1) {
		state->dashboard_ts->f_74 = 2;
	}
	if (state->task_1018->f_00) {
		changed = true;
		state->task_1018->f_00 = 0;
	}
	if (state->onboarding->active) {
		changed = true;
		state->onboarding->active = 0;
	}
	if (state->task_1010->f_07) {
		FUN_00030458();
		FUN_00080338(1);
		changed = true;
	}
	if (state->task_1014->f_00 == 1) {
		FUN_00030458();
		state->task_1014->f_00 = 0;
		changed = true;
	} else if (state->task_1014->f_00 == 2) {
		state->task_1014->f_00 = 3;
	}
	if (state->task_1020->f_00) {
		changed = true;
		state->task_1020->f_00 = 0;
	}
	if (state->task_1024->f_00) {
		changed = true;
		state->task_1024->f_00 = 0;
	}
	if (state->task_1028->f_00) {
		state->task_1028->f_00 = 0;
		changed = true;
	}
	if (state->task_102c->f_00) {
		FUN_00030458();
		state->task_102c->f_00 = 0;
		changed = true;
	}
	if (!changed) {
		return;
	}
	if (notify) {
		report_event_to_phone(0);
	}
	memset(state->buf_0ef, 0, sizeof(state->buf_0ef));
}

void FUN_00080224(struct GlassesState *state, int flag)
{
	if (!FUN_0002da10(state)) {
		return;
	}
	if (state->dashboard_mode != 6) {
		if (state->dashboard_mode != 4) {
			return;
		}
	} else {
		FUN_00030458();
		state->dashboard_ts->f_73 = 0;
		(void)state->dashboard_mode;
	}
	if (flag) {
		report_event_to_phone(0);
	}
	update_persist_task_status_to_idle(state);
	memset(state->buf_0ef, 0, sizeof(state->buf_0ef));
}

static void slave_display_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;

	state->f_feb = 1;
	state->dashboard_mode = 0;
	G1_LOG_WRN("enter\n");
	if (state->f_fee == 11) {
		change_work_mode(2);
	}
	for (;;) {
		if (state->f_fee != 11) {
			k_sem_take(&state->sem_1, K_FOREVER);
		} else {
			state->sync_hdr.cmd = 0;
			if (!FUN_00033d5c()) {
				state->dashboard_mode = 6;
			} else {
				state->dashboard_mode = 3;
			}
			k_sleep(K_MSEC(1000));
		}
		while (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}
		if (state->f_0cb != state->f_ed7 || state->panel_brightness != state->f_0cb) {
			if (FUN_00033d5c() == 1) {
				set_brightness_to_panel_reg_in_running(state->panel_brightness);
				state->f_0cb = state->panel_brightness;
				state->f_ed7 = state->panel_brightness;
			} else {
				state->f_ed7 = state->f_0cb;
				state->panel_brightness = state->f_0cb;
				set_brightness_to_panel_reg_in_running(state->f_0cb);
			}
		}

		switch (state->sync_hdr.cmd) {
		case 0:
			if (state->suspend_state == 1) {
				if (state->dashboard_mode != 6 && !FUN_0002da10(state)) {
					G1_LOG_ERR("Ignore data...\n");
					break;
				}
				change_work_mode(2);
				if (state->dashboard_mode == 6 && state->msg_ctx.state != 2) {
					state->msg_ctx.state = 2;
				}
			}
			k_sem_give(&state->sem_2);
			break;
		case 1:
			DAT_20019a65 = 1;
			DAT_20019a64 = 1;
			if (state->suspend_state == 0) {
				FUN_0007ff66(state, 0);
				state->msg_ctx.state = 1;
				state->f_1068->task = 0;
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
					get_dashboard_state()->panel_canvas_distance_gear = state->sync_data[1];
					get_dashboard_state()->panel_raster_height_offset = state->sync_data[2];
					cal_panel_canvas_coord(&get_dashboard_state()->panel_ec4,
							       (int *)&get_dashboard_state()->f_eb8);
				}
			}
			DAT_20019a64 = 1;
			if (state->dashboard_mode == 9 || state->dashboard_mode == 12 ||
			    state->dashboard_mode == 10 || state->dashboard_mode == 11 ||
			    state->dashboard_mode == 6 || state->dashboard_mode == 7 ||
			    state->dashboard_mode == 14 || state->dashboard_mode == 15 ||
			    state->dashboard_mode == 16 || state->dashboard_mode == 20 ||
			    state->dashboard_mode == 17 || state->dashboard_mode == 18 ||
			    state->dashboard_mode == 19 || state->dashboard_mode == 0) {
				state->msg_ctx.state = 2;
			}
			change_work_mode(2);
			if (state->dashboard_mode != 9 || state->dashboard_mode != 10 ||
			    state->dashboard_mode != 11 || state->dashboard_mode != 16 ||
			    state->dashboard_mode != 20) {
				k_sem_give(&state->sem_2);
			}
			DAT_20019a64 = 0;
			break;
		case 3:
			FUN_0007ff66(state, 1);
			change_work_mode(7);
			break;
		case 6:
			if (state->sync_data[0] == 9) {
				upgradeDashboardStartupModeInfoToFlash(state->sync_data[1]);
				break;
			}
			switch (state->sync_data[0]) {
			case 10:
				atomic_or(&DAT_20008518, 2);
				if (state->sync_data[1] == 1) {
					if (get_dashboard_state()->f_1244 == 4) {
						state->f_1245 = 1;
					}
				} else if (state->sync_data[1] == 2) {
					state->f_1245 = 0;
					state->dashboard_ts->f_72 = 0;
				}
				break;
			case 1:
				if (state->dashboard_mode == 12) {
					if (state->sync_data[1] == 0) {
						display_DelayClose(10000);
						k_yield();
					}
				} else if (state->sync_data[1] == 1) {
					FUN_00080224(state, 0);
					state->f_0ec = 12;
					state->task_1034->f_01 = 1;
					state->task_1034->f_02 = 0;
					state->task_1034->f_03 = 7;
					memset(get_dashboard_state()->task_1034->data, 0, 0x14a);
					update_persist_task_status(state, 12, 2);
					k_sem_give(&state->sem_2);
				}
				break;
			case 2: {
				uint8_t v = state->sync_data[1];
				uint8_t key = v & 0xf;
				uint8_t idx;

				if (key == 1 && state->dashboard_mode == 6) {
					FUN_00038ae4(v >> 4);
					display_inputEvent(0, 1);
					k_yield();
				} else if (key == 2) {
					FUN_00038ae4(v >> 4);
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
						   FUN_00080732(), idx);
				} else if (key == 8) {
					idx = v >> 4;
					setCalenadrIndex(idx);
					G1_LOG_ERR("received master send calendar index sync commmand ,timestamp = %d,exec index update %d\n",
						   FUN_00080732(), idx);
				} else {
					if (v == 9) {
						state->dashboard_ts->f_74 = 2;
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

				if (CURRENT_LANGUAGE != lang) {
					G1_LOG_WRN("The information sent by the host is different from that of the APP\n");
				}
				upgradeAppLanguageInfoToFlash(lang);
				break;
			}
			case 4: {
				uint8_t show;
				int64_t ts;

				state->f_0cd = state->onboarding->f_03;
				state->onboarding->f_02 = state->sync_data[1];
				state->onboarding->f_03 = state->sync_data[2];
				FUN_00044b24();
				DAT_2001db40 = state->sync_data[2];
				show = state->sync_data[3];
				thunk_FUN_00045444();
				FUN_00042830();
				ts = k_uptime_get();
				state->onboarding->ts = ts;
				if (state->f_1068->task != 14 &&
				    (!FUN_0007f3da() || state->onboarding->f_01)) {
					if (!FUN_0007f3da()) {
						G1_LOG_WRN("ble device unbound,prepare to show binding tip\n");
					}
					if (show == 1) {
						state->onboarding->active = 1;
						update_persist_task_status(state, 14, 2);
						state->onboarding->saved_brightness = state->panel_brightness;
						state->panel_brightness = 0x2a;
					}
				} else if (state->onboarding->f_02 == 3) {
					if (DAT_2001db40 == 0x12) {
						state->onboarding->f_0c = show;
						state->onboarding->f_0d = 3;
						state->onboarding->f_0e = 3;
					}
				} else if (state->onboarding->f_02 == 11) {
					get_dashboard_state()->onboarding->active = 0;
					get_dashboard_state()->onboarding->f_01 = 0;
				}
				trigger_screen_state_change("IMU:wakeup:onboarding", state, 1);
				k_sem_give(&state->sem_2);
				break;
			}
			case 5:
				FUN_0003f1bc(state->sync_data[1]);
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
					FUN_00080224(get_dashboard_state(), 0);
					if (get_dashboard_state()->f_1068->task == 0x14 &&
					    get_dashboard_state()->task_1014->f_00 == 1 &&
					    get_dashboard_state()->task_1014->f_01 == 4 &&
					    get_dashboard_state()->task_1014->f_03 == 0x13) {
						G1_LOG_WRN("evenai_v2 need to show network_err tip\n");
						get_dashboard_state()->f_1068->status = 2;
						break;
					}
					if (get_dashboard_state()->f_1068->task != 0x14) {
						get_dashboard_state()->task_1014->f_00 = 1;
						memset(get_dashboard_state()->task_1014->data + 8, 0, 0x200);
						update_persist_task_status(get_dashboard_state(), 0x14, 2);
					}
					get_dashboard_state()->task_1014->f_01 = 7;
					get_dashboard_state()->task_1014->f_03 = state->sync_data[2];
				}
				k_sem_give(&state->sem_2);
				break;
			}
			break;
		case 4:
			FUN_0007ff66(state, 1);
			state->f_fee = 12;
			state->dashboard_cmd = 3;
			k_sem_give(&state->dashboard_position_sem);
			break;
		case 5:
			state->f_fee = 10;
			state->dashboard_cmd = 3;
			k_sem_give(&state->dashboard_position_sem);
			FUN_0003f1bc(1);
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
				FUN_0002dd98();
				FUN_000359fc();
				update_temp_task_status(state, 4, 2);
				trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
				break;
			case 2: {
				g_arrMsgContent_count();
				if (get_dashboard_state()->f_0dd) {
					FUN_00035abc(6);
				} else {
					FUN_00035abc(0);
				}
				break;
			}
			case 3:
				DAT_20019a5b = 1;
				if (get_dashboard_state()->message_mode && FUN_00035310() &&
				    get_dashboard_state()->dashboard_mode != 4) {
					update_temp_task_status(get_dashboard_state(), 4, 2);
					trigger_screen_state_change("IMU:wakeup:new-notification",
								    get_dashboard_state(), 1);
					FUN_0002dd98();
				}
				FUN_0002df6c();
				k_sem_give(&get_dashboard_state()->sem_2);
				FUN_000359d8();
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
			switch (get_dashboard_state()->task_1010->f_00) {
			case 1:
				if (sync_to_slave(get_dashboard_state(), 0xd, NULL, 0) < 500) {
					FUN_00080224(state, 0);
					FUN_00080338(0);
					if (FUN_00030440()) {
						get_dashboard_state()->task_1010->f_00 = 2;
					} else {
						get_dashboard_state()->task_1010->f_00 = 3;
					}
					if (get_dashboard_state()->f_1068->task != 0x10) {
						update_persist_task_status(get_dashboard_state(), 0x10, 2);
					}
				}
				break;
			case 3:
				if (sync_to_slave(get_dashboard_state(), 0xe, NULL, 0) < 500) {
					get_dashboard_state()->task_1010->f_00 = 4;
				}
				break;
			case 5:
				if (sync_to_slave(get_dashboard_state(), 0xf, NULL, 0) < 500) {
					FUN_00030458();
					report_event_to_phone(0x18);
					get_dashboard_state()->task_1010->f_00 = 6;
				}
				break;
			case 10:
				if (sync_to_slave(get_dashboard_state(), 0x10, NULL, 0) < 500) {
					get_dashboard_state()->task_1010->f_00 = 0xb;
					get_dashboard_state()->f_0db = 8;
				}
				break;
			case 13:
				if (sync_to_slave(get_dashboard_state(), 0x11, NULL, 0) < 500) {
					get_dashboard_state()->task_1010->f_00 = 0xe;
				}
				break;
			case 15:
				if (sync_to_slave(get_dashboard_state(), 0x12, NULL, 0) < 500) {
					get_dashboard_state()->task_1010->f_00 = 0x10;
				}
				break;
			}
			if (get_dashboard_state()->task_1014->f_01 == 6 &&
			    get_dashboard_state()->task_1014->f_03 < 3) {
				data[0] = 0xe;
				data[1] = get_dashboard_state()->task_1014->f_01;
				data[2] = get_dashboard_state()->task_1014->f_03;
				data[3] = 0;
				if (sync_to_slave(get_dashboard_state(), 6, data, 4) < 500) {
					FUN_00080224(get_dashboard_state(), 0);
					if (get_dashboard_state()->f_1068->task == 0x14 &&
					    get_dashboard_state()->task_1014->f_00 == 1 &&
					    get_dashboard_state()->task_1014->f_01 == 4 &&
					    get_dashboard_state()->task_1014->f_03 == 0x13) {
						G1_LOG_WRN("evenai_v2 need to show network_err tip\n");
						get_dashboard_state()->f_1068->status = 2;
					} else {
						if (get_dashboard_state()->f_1068->task != 0x14) {
							get_dashboard_state()->task_1014->f_00 = 1;
							memset((uint8_t *)get_dashboard_state()->task_1014 + 0x10, 0, 0x200);
							update_persist_task_status(get_dashboard_state(), 0x14, 2);
						}
						get_dashboard_state()->task_1014->f_01 = 7;
						now = k_uptime_get();
						BLK_TS_SET(get_dashboard_state()->task_1014, 6, now);
					}
				}
			}
		} else {
			switch (get_dashboard_state()->task_1010->f_00) {
			case 1:
				sync_to_master(get_dashboard_state(), 0xf, NULL, 0);
				FUN_00080224(state, 0);
				break;
			case 5:
				sync_to_master(get_dashboard_state(), 0x10, NULL, 0);
				break;
			}
			if (get_dashboard_state()->task_1014->f_01 == 6) {
				data[0] = get_dashboard_state()->task_1014->f_01;
				data[1] = get_dashboard_state()->task_1014->f_03;
				sync_to_master(get_dashboard_state(), 0x11, data, 2);
			}
		}
		FUN_00029684();
		if (get_dashboard_state()->is_master == 1 && DAT_2001093b) {
			sync_message_signal_to_slave(3);
			if (get_dashboard_state()->message_mode && FUN_00035310() &&
			    get_dashboard_state()->dashboard_mode != 4) {
				update_temp_task_status(get_dashboard_state(), 4, 2);
				trigger_screen_state_change("IMU:wakeup:new-notification",
							    get_dashboard_state(), 1);
				FUN_0002dd98();
			}
			DAT_2001093b = 0;
			FUN_0002df6c();
			FUN_000359d8();
		}
		k_msleep(200);
	}
}

void on_double_click(void)
{
	G1_PRINTK("#############################on_double_click################################\n");
	FUN_00033e2c(2);
}

void exit_silent_mode(void)
{
	if (demo_mode) {
		demo_mode = 0;
	}
	change_work_mode(2);
	global_system_resume(get_dashboard_state());
	get_dashboard_state()->msg_ctx.state = 2;
	get_dashboard_state()->dashboard_mode = 3;
	FUN_00080fca(get_dashboard_state()->dashboard_mode);
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
	get_dashboard_state()->msg_ctx.state = 1;
	display_close_screen(3);
	get_dashboard_state()->dashboard_mode = 0;
	FUN_0004b340();
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
		if (DAT_20006be0) {
			sys_clock_tick_get_32();
			aw9320x_get_irq_stat();
			sys_clock_tick_get_32();
			DAT_20006be0 = 0;
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
		if (FUN_00033e38() != 1) {
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
					FUN_00033e44();
					break;
				case 10:
					reset_all_usr_data(state, 1);
					break;
				}
			}
		} else if (FUN_00033e20() == 2 && get_dashboard_state()->f_10c8 < 0xfa) {
			get_dashboard_state()->f_10c8++;
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
	struct task_blk *b1;

	G1_LOG_WRN("enter\n");
	state->f_ecc = 0x12;
	state->screen_on = 0;
	G1_LOG_ERR("raster_height_gear:%d, canvas_distance_gear:%d\n",
		   state->panel_raster_height_offset, state->panel_canvas_distance_gear);
	state->f_eb4 = 0;
	cal_panel_canvas_coord(&get_dashboard_state()->panel_ec4, (int *)&get_dashboard_state()->f_eb8);
	state->sync_d6 = state->f_eb4 + state->f_108a;
	state->sync_d8 = state->f_eb8 + state->f_108c;
	state->imu_on = 0;
	state->f_feb = 1;
	state->dashboard_mode = 0;
	if (state->f_fee == 11) {
		change_work_mode(2);
		if (FUN_00033d5c() == 1) {
			enter_silent_mode();
		}
	}

	for (;;) {
		while (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}
		if (!state->screen_on && !FUN_0002da10(state)) {
			G1_LOG_WRN("master sync display suspend.\n");
			state->f_0cb = state->panel_brightness;
			if (FUN_000169b4() != 3) {
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
			if (!state->screen_on && !FUN_0002da10(state)) {
				G1_LOG_WRN("thread goto sleep.\n");
				DAT_20019a64 = 0;
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
			state->f_0cb = state->panel_brightness;
			change_work_mode(2);
			changed = 1;
		}
		if (!state->f_feb) {
			goto skip;
		}
		if (state->is_master == 1 && ++bright_cnt == 5) {
			if (state->f_f9c && state->f_f94 && state->f_ec8) {
				uint8_t target = FUN_00010848(state->opt3007_ctx);

				if (target == 0xff) {
					bright_cnt = 0;
				} else {
					if (state->panel_brightness < target) {
						state->panel_brightness++;
					} else if (state->panel_brightness > target) {
						state->panel_brightness--;
					}
					bright_cnt = (state->panel_brightness != target) ? 4 : 0;
				}
			} else {
				bright_cnt = 4;
			}
			if (state->f_ed6 != state->panel_brightness) {
				state->f_ed6 = state->panel_brightness;
				if ((state->dashboard_mode == 6 && state->dashboard_ts->f_66) ||
				    state->dashboard_mode == 10 || state->dashboard_mode == 4) {
					changed = 0;
				} else {
					changed = state->dashboard_mode != 20;
				}
			}
		}
		state->sync_status.task = state->f_1068->task;
		state->sync_status.status = state->f_1068->status;
		if (state->is_master == 1) {
			state->f_0e9 = state->f_0cc;
			state->f_0ea = state->f_0cd;
			state->f_0eb = state->msg_ctx.state;
			state->f_0ec = state->dashboard_mode;
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
		if (state->f_fee == 12 && state->dashboard_mode != 7) {
			goto skip;
		}
		wait = FUN_0002da10(state);
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
		k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
		screen = state->dashboard_mode;
		switch (state->dashboard_mode) {
		case 4: {
			uint8_t retry = 0x33;

			while (state->f_0ec != state->dashboard_mode && --retry) {
				k_msleep(10);
			}
			data = (uint8_t *)FUN_00035260(FUN_000359cc());
			if (FUN_0002ddb0() || get_dashboard_state()->f_0dd != last_msg_screen) {
				last_msg_screen = get_dashboard_state()->f_0dd;
			} else if (!changed) {
				unlock_mutext_2000851c();
				len = 0x1b4;
				goto skip;
			}
			len = 0x1b4;
			changed = 1;
			break;
		}
		case 2:
			FUN_00037af4(state, state->ptr_ff4);
			len = 7;
			data = state->ptr_ff4;
			break;
		case 9:
			len = 0x217;
			data = (uint8_t *)state->task_1000;
			break;
		case 12:
			len = 0x152;
			data = (uint8_t *)state->task_1034;
			break;
		case 10: {
			uint8_t att = state->msg_ctx.state;
			struct task_blk *blk = state->task_1004;

			if (att == 2) {
				if (last_attitude != 2 || blk->f_07 != 2) {
					changed = 1;
					blk->f_07 = att;
				}
			} else if (att != last_attitude || blk->f_07 != 1) {
				changed = 1;
				blk->f_07 = 1;
			}
			len = 0xf5;
			data = (uint8_t *)state->task_1004;
			break;
		}
		case 11: {
			b1 = state->task_100c;
			struct task_blk *b0;
			uint8_t att;

			if ((uint8_t)(b1->f_03 - 5) < 2) {
				data = (uint8_t *)state->task_1038;
				if (state->is_master != 2)
					goto c11_b1;
				if (state->f_0cc == state->f_0e9)
					goto c11_b1;
				if (state->task_1038->data[0x200 - 8] != state->f_0e9)
					goto c11_b1;
			} else if (b0 = state->task_1008, (uint8_t)(b0->f_03 - 5) < 2) {
				if (state->is_master != 2 || state->f_0cd == state->f_0ea ||
				    state->task_103c->data[0x200 - 8] != state->f_0ea) {
					data = (uint8_t *)b0;
				} else {
					data = (uint8_t *)state->task_103c;
				}
			} else if (att = state->msg_ctx.state, att != 2 ? b1->f_01 == b1->f_00 : (last_attitude != 2 || b1->f_01 == b1->f_00)) {
				b1->f_03 = 2;
				goto t1038;
			} else if (att == 2) {
t1038:
				if (state->is_master == 2 && state->f_0cc != state->f_0e9 &&
				    state->task_1038->data[0x200 - 8] == state->f_0e9) {
					data = (uint8_t *)state->task_1038;
				} else {
					data = (uint8_t *)state->task_100c;
				}
			} else {
				if (att != last_attitude) {
					b0->f_03 = 4;
				}
				if (state->is_master == 2 && state->f_0cd != state->f_0ea &&
				    state->task_103c->data[0x200 - 8] == state->f_0ea) {
					data = (uint8_t *)state->task_103c;
				} else {
					data = (uint8_t *)state->task_1008;
				}
			}
c11_len:
			len = 0x1e8;
			break;
		}
		case 8:
			len = 0x16a;
			data = state->ptr_ff8;
			break;
		case 7:
			len = 0xb;
			data = (uint8_t *)state->task_1018;
			break;
		case 14:
			get_dashboard_state()->panel_brightness = 0x2a;
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
			struct task_blk *blk = state->task_1010;

			if (blk->f_00 > 11 && (blk->f_00 & 0xfd) == 13) {
				unlock_mutext_2000851c();
				goto skip;
			}
			if (state->is_master == 2 && state->f_0cc != state->f_0e9 &&
			    state->f_0e9 == state->task_1038->data[0x200 - 8]) {
				data = (uint8_t *)state->task_1038;
				blk->f_06 = state->task_1038->data[0x200 - 8];
			} else {
				state->task_1010->f_06 = get_dashboard_state()->f_0cc;
				data = (uint8_t *)blk;
			}
			if (state->task_1010->f_00 == 7) {
				state->task_1010->f_01 = 3;
				len = 0x1e9;
				break;
			}
			len = 0x1e9;
			break;
		}
		case 20:
			len = 0x210;
			data = (uint8_t *)state->task_1014;
			break;
		case 17:
			len = 2;
			data = (uint8_t *)state->task_1024;
			break;
		case 18:
			len = 10;
			data = (uint8_t *)state->task_1028;
			break;
		case 19:
			len = 0x208;
			data = (uint8_t *)state->task_102c;
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
				 * The difference of the two reads of state->task_100c is 0;
				 * the compiler only folds it after RTL CSE, which keeps this
				 * block as one shared "mov r5, r3" target of all three tests
				 * (as in the vendor build) instead of if-converting the last one.
				 */
c11_b1:
				data = (uint8_t *)b1 +
				       (*(uintptr_t *)((uintptr_t)state + offsetof(struct GlassesState, task_100c)) -
					*(uintptr_t *)((uintptr_t)&state->task_1004 +
						       (offsetof(struct GlassesState, task_100c) -
							offsetof(struct GlassesState, task_1004))));
				goto c11_len;
			}
			date_cnt++;
			state->sync_data[0] = date_idx;
			state->sync_data[1] = date_cnt;
			break;
		}
		}
		if (data) {
			if (memcmp(state->buf_0ef, data, len) == 0 && !changed &&
			    state->dashboard_mode == DAT_2000aa78) {
				unlock_mutext_2000851c();
				goto skip;
			}
			memcpy(state->buf_0ef, data, len);
		}
		memset((uint8_t *)state + (offsetof(struct GlassesState, buf_0ef) + len), 0, 0x5dc - len);
		state->buf_len.v = len;
		prev_changed = changed;
		unlock_mutext_2000851c();
		if (state->suspend_state != 0 && state->suspend_state != 5) {
			goto skip;
		}
		if (state->is_master == 1) {
			if (state->f_0cb != state->panel_brightness) {
				set_brightness_to_panel_reg_in_running(state->panel_brightness);
				state->f_0cb = state->panel_brightness;
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
			if (state->f_0ec != state->dashboard_mode && state->dashboard_mode > 6 &&
			    state->f_0ec > 6) {
				G1_LOG_ERR("screen id was changed, g->master_sync_pkg.new_screen_id %d pkg->screen_id %d\n",
					   state->f_0ec, state->dashboard_mode);
				wait = 70;
				goto next;
			}
		} else {
			wait = 0;
		}
		if (!FUN_0002da10(state)) {
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
			uint8_t att = state->msg_ctx.state;

			if (state->dashboard_mode == 10 && last_attitude != att && prev_changed != 1) {
				G1_LOG_WRN("imu->attitude changed ....\n");
			} else {
				last_attitude = att;
			}
			FUN_00080fca(state->dashboard_mode);
			G1_LOG_ERR("display_reflash_screen %d done\n", state->dashboard_mode);
			if (state->f_0ec == 6 || state->f_0ec == 0 || state->msg_ctx.state == 2 ||
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
		if (k_sem_take(&key_event_sem, K_FOREVER) != 0) {
			goto done;
		}
		G1_LOG_ERR("key event trigger, type %d\n\n", key_event_type);
		type = key_event_type;
		if (type == 1) {

			if (state->dashboard_ts->f_72 == 1) {
				continue;
			}
			if (state->onboarding->active) {
				report_event_to_phone(type);
				if (state->onboarding->f_02 == 5) {
					if (get_dashboard_state()->is_master != 2) {
						continue;
					}
					data[0] = 0x13;
					if (onboarding_sync_data(data, type) == 0) {
						state->onboarding->f_02 = 0x13;
					}
				} else if (state->onboarding->f_02 == 0x13) {
					if (get_dashboard_state()->is_master != 2) {
						continue;
					}
					data[0] = 0x14;
					if (onboarding_sync_data(data, type) == 0) {
						state->onboarding->f_02 = 0x14;
					}
				} else {
					if (state->onboarding->f_02 == 0x14 && get_dashboard_state()->is_master == 1) {
						state->onboarding->f_02 = 0x15;
					}
				}
				continue;
			}
			if ((uint8_t)(state->task_1010->f_00 - 7) <= 4 || state->task_1024->f_00 ||
			    (state->task_1014->f_00 == 1 && state->task_1014->f_01 == 3)) {
				report_event_to_phone(type);
				continue;
			}
			if (state->task_1000->f_01) {
				report_event_to_phone(type);
			}
			if (state->is_master == 1) {
				if (state->dashboard_mode != 6) {
					goto done;
				}
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
			} else if (state->is_master == 2 && FUN_000352f4()) {
				if ((state->dashboard_mode == 6 && get_dashboard_state()->msg_ctx.state == 2) ||
				    state->dashboard_mode == 4) {
					while (FUN_0002dea8() < 0) {
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
			if (state->f_1068->task == 0 && state->dashboard_mode == 0 && state->f_fee != 12) {
				if (state->f_1244 == 4) {
					if (state->is_master == 1) {
						data[0] = 0x0a;
						data[1] = 1;
						for (i = 1; i != 4; i++) {
							if (sync_to_slave(state, 6, data, 2) >= 3000) {
								G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n", i);
							} else {
								G1_LOG_ERR("SEND double click event to slave.\n");
								atomic_or(&DAT_20008518, BIT(1));
								state->f_1245 = 1;
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
				} else if (state->f_1244 != 0) {
					report_event_to_phone(0x20);
					for (n = 100; n != 0; n--) {
						k_msleep(20);
					}
				}
				continue;
			}
			if (state->dashboard_mode == 6 &&
			    (state->f_1244 == 4 || state->dashboard_ts->f_72 != 0)) {
				report_event_to_phone(0);
				if (state->is_master == 1) {
					data[0] = 0x0a;
					data[1] = 2;
					for (i = 1; i != 4; i++) {
						if (sync_to_slave(state, 6, data, 2) >= 3000) {
							G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n", i);
						} else {
							G1_LOG_ERR("SEND double click event to slave.\n");
							state->f_1245 = 0;
							atomic_or(&DAT_20008518, BIT(1));
							state->dashboard_ts->f_72 = 0;
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
			    (state->dashboard_mode == 12 && state->task_1034->f_03 == 10)) {
				report_event_to_phone(0);
				if (state->is_master == 1) {
					if (state->dashboard_mode == 4) {
						FUN_00035a84();
						if (get_dashboard_state()->f_0dd) { FUN_00035abc(6); } else { FUN_00035abc(0); }
					}
					data[0] = 1;
					data[1] = 0;
					if (state->dashboard_mode != 6) {
						atomic_or(&DAT_20008514, BIT(1));
						for (i = 1; i != 4; i++) {
							if (sync_to_slave(state, 8, data, 2) >= 3000) {
								G1_LOG_ERR("SYNC TO Slave failed %d times,don't exec double click close app function.\n", i);
							} else {
								G1_LOG_ERR("SEND double click event to slave.\n");
								FUN_0007ff66(state, 0);
								break;
							}
						}
					} else if (state->dashboard_mode == 6) {
						sync_to_slave(state, 8, data, 2);
						FUN_0007ff66(state, 0);
						update_persist_task_status_to_idle(state);
					}
				} else if (state->dashboard_mode != 6) {
					sync_to_master(state, 4, NULL, 0);
					if (get_dashboard_state()->dashboard_mode == 4) {
						FUN_00035a84();
						if (get_dashboard_state()->f_0dd) { FUN_00035abc(6); } else { FUN_00035abc(0); }
					}
					FUN_0007ff66(state, 0);
				} else if (state->dashboard_mode == 6) {
					sync_to_master(state, 4, NULL, 0);
					if (get_dashboard_state()->dashboard_mode == 4) {
						FUN_00035a84();
						if (get_dashboard_state()->f_0dd) { FUN_00035abc(6); } else { FUN_00035abc(0); }
					}
					FUN_0007ff66(state, 0);
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
			if (state->onboarding->active || state->dashboard_ts->f_72 == 1) {
				continue;
			}
			if (state->f_fee == 12) {
				report_event_to_phone(5);
				if (state->is_master == 1) {
					if (sync_to_slave(state, 5, NULL, 0) < 3000) {
						FUN_0003f1bc(1);
					}
				} else if (sync_to_master(state, 9, NULL, 0) < 2000) {
					FUN_0003f1bc(1);
				}
				state->f_fee = 10;
				G1_LOG_ERR("#############################exit not disturb################################\n\n");
			} else {
				report_event_to_phone(4);
				if (state->is_master == 1) {
					sync_to_slave(state, 4, NULL, 0);
					FUN_0007ff66(state, 0);
				} else {
					sync_to_master(state, 8, NULL, 0);
				}
				state->f_fee = 12;
				FUN_0007ff66(state, 1);
				FUN_00080852(0);
				G1_LOG_ERR("#############################enter not disturb################################\n\n");
			}
			state->dashboard_cmd = 3;
			k_sem_give(&state->dashboard_position_sem);
			break;
		case 4:
			if (state->onboarding->active || state->dashboard_ts->f_72 == 1) {
				G1_LOG_ERR("[onboarding/set_lum_coeffic] is running, exit this time\n");
				continue;
			}
			long_press_active = 1;
			if (state->f_fee != 12 &&
			    (is_idle() || state->dashboard_mode == 6 || state->dashboard_mode == 1)) {
				if (state->is_master == 2) {
					uint8_t ok = get_glasses_ble_status();

					if (ok == 1) {
						state->task_1014->f_01 = 6;
						state->task_1014->f_03 = 2;
						report_event_to_phone(0x17);
					} else {
						state->task_1014->f_01 = 6;
						state->task_1014->f_03 = 1;
					}
				} else {
					state->task_1034->f_00 = 1;
					check_disp_quicknote();
				}
			} else {
				G1_LOG_WRN("longpress task cannot be started because screen_id %d, %d, %d\n",
					   state->dashboard_mode, is_idle(), state->f_fee);
			}
			break;
		case 6:
			long_press_active = 0;
			if (state->is_master == 2) {
				if (state->dashboard_mode == 0x10) {
					if (state->task_1010->f_00 == 4) {
						state->task_1010->f_00 = 5;
					}
				} else if (state->dashboard_mode == 0x14 && get_glasses_ble_status() == 1 &&
					   state->task_1014->f_01 == 7 && state->task_1014->f_03 == 2) {
					report_event_to_phone(0x18);
				}
			} else if (!lp_timeout_handled && state->dashboard_mode == 12) {
				lp_timeout_handled = 1;
quicknote_end:
				state->task_1034->f_00 = 2;
				check_disp_quicknote();
			}
			break;
		case 5:
			long_press_active = 0;
			if (state->is_master == 2) {
				if (state->dashboard_mode == 0x10) {
					if (state->task_1010->f_00 == 4) {
						state->task_1010->f_00 = 5;
					}
				} else if (state->dashboard_mode == 0x14 && get_glasses_ble_status() == 1 &&
					   state->task_1014->f_01 == 7 && state->task_1014->f_03 == 2) {
					report_event_to_phone(0x18);
				}
			} else if (state->dashboard_mode == 12) {
				goto quicknote_end;
			}
			break;
		default:
			break;
		}
done:
		key_event_type = 0;
	}
}

static void touch_key_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	uint32_t now, t1;
	int press_t = 0;
	int release_t = 0;
	unsigned int clicks = 0;
	int lp_timeout = 0;
	unsigned int long_press = 0;
	int hold, since_release, press_dur;
	uint8_t n;

	for (;;) {
		k_sem_take(&state->touch_sem, K_MSEC(250));
		if (state->work_mode == 1 || get_dashboard_state()->work_mode == 8) {
			k_msleep(5000);
			continue;
		}
		if (DAT_20006be0) {
			aw9320x_get_irq_stat();
			DAT_20006be0 = 0;
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
			if (!long_press) {
				if (release_t != 0) {
					if (press_t >= release_t || since_release <= 10000) {
						continue;
					}
					if (press_dur > 15000) {
						goto press_end;
					}
					goto single;
				}
				aw9320x_diff_get(&state->aw_diff);
				/* upper bound read through the raw field address: keeps two compares like the vendor build */
				if (state->aw_diff > -20000) {
					int32_t *diff = (int32_t *)((uintptr_t)state + offsetof(struct GlassesState, aw_diff));

					if (*diff < 20000) {
						clicks = 0;
						continue;
					}
				}
				if (hold <= 15000) {
					if (press_t >= release_t || since_release <= 10000) {
						continue;
					}
					if (press_dur > 15000) {
						goto press_end;
					}
					goto single;
				}
				G1_LOG_ERR("########################turn on the mic and start to speak! holdtime %d\n\n", hold);
				key_event_type = 4;
				trigger_key_event();
				long_press = 1;
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
				lp_timeout = 0;
				long_press = 0;
				clicks = 0;
				trigger_key_event();
				continue;
			}
			if (release_t == 0) {
				goto lp_check;
			}
			if (press_t >= release_t || since_release <= 10000) {
				continue;
			}
			if (press_dur > 15000) {
				goto press_end;
			}
single:
			G1_LOG_ERR("#############################single click %d################################\n\n", state->aw_diff);
			/* wait up to 3 x 100 ms; the key event itself is sent from the key-5 block below */
			n = 4;
			goto lchk;
			do {
				k_msleep(100);
lchk:
				if (!DAT_2001c4e8) {
					goto single_trig;
				}
			} while (--n);
			goto single_trig;
		} else {
			if (clicks == 0 || press_t >= release_t || since_release <= 10000) {
				continue;
			}
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
				} else {
					G1_LOG_ERR("#############################Short press end################################\n\n");
					lp_timeout = 1;
					release_t = 0;
					continue;
				}
			} else {
				switch (clicks) {
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
					goto reset;
				case 15:
					set_band_for_ESB(10);
					G1_LOG_ERR("%d click, use high band for ESB\n\n", 15);
					goto reset;
				case 5:
					if (state->onboarding->active) {
						goto reset;
					}
					G1_LOG_ERR("%d click, reboot now\n\n", 5);
					reset_pmic_on();
					G1_LOG_ERR("reset_pmic_on\n\n");
					reset_pmic_off();
					G1_LOG_ERR("reset_pmic_off\n\n");
					G1_LOG_ERR("sys reboot because touch event, %d click, reboot now\n\n", 5);
					k_msleep(500);
					sys_reboot(SYS_REBOOT_COLD);
				case 10:
					reset_all_usr_data(state, 1);
					goto reset;
				case 11:
					reset_all_usr_data(state, 0);
					goto reset;
				default:
					goto reset;
				}
			}
		}
reset:
		long_press = 0;
		clicks = 0;
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
			FUN_00033b18();
			k_sleep(K_MSEC(50));
		} else if (get_dashboard_state()->work_mode == 1) {
			k_sleep(K_MSEC(5000));
		} else {
			ret = FUN_00033d5c();
			if (ret == 1) {
				if (init_nfc_comm() == 0) {
					set_box_status(BOX_IN_BOX, ret);
					nfc_deadline_set(0);
				} else {
					if (nfc_timeout(5000)) {
						set_box_status(BOX_IN_BOX, 0);
					}
				}
				if (get_dashboard_state()->f_10a0 == 1) {
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
						FUN_00027848(&it_status);
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

/* old Ghidra names, kept as aliases until the callers in other modules are renamed */
extern __typeof__(report_event_to_phone) FUN_00029774 __attribute__((alias("report_event_to_phone")));
extern __typeof__(nfc_deadline_set) FUN_0002c6f4 __attribute__((alias("nfc_deadline_set")));
extern __typeof__(update_activity_time) FUN_0002c8a4 __attribute__((alias("update_activity_time")));
extern __typeof__(get_glasses_ble_status) FUN_00028d2c __attribute__((alias("get_glasses_ble_status")));
extern __typeof__(sync_to_master) FUN_000294d0 __attribute__((alias("sync_to_master")));


static void low_speed_peripheral_dispatch_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *state = p1;
	struct bt_conn *conn;
	int8_t sec_retry = 0;
	uint8_t cnt = 0;
	int in_box, lid_closed;
	uint8_t connected;

	change_work_mode(3);
	update_persist_task_status_to_idle(state);
	G1_LOG_WRN("#enter\n");
	state->battery_voltage = 0;
	state->battery_info[0] = 0;
	state->battery_info[1] = 0;
	state->battery_current = 0x80;
	if (state->is_master == 1 && state->f_fee == 12) {
		sync_to_slave(state, 4, NULL, 0);
	}
	for (;;) {
		cnt++;
		if (cnt % 5 == 0) {
			conn = FUN_00019cec();
			if (conn && state->f_ae2 && state->f_ae3 &&
			    k_sem_count_get(&state->ble_context.sem_230)) {
				if (++sec_retry > 4) {
					bt_conn_set_security(conn, BT_SECURITY_L2);
					sec_retry = -5;
				}
			} else {
				sec_retry = 0;
			}
			state->f_0de = MIN(state->battery_info[0], state->battery_info[1]);
			fuel_gauge_update(CHARGER_DEV, 0);
			in_box = is_in_box();
			lid_closed = is_box_lid_closed();
			connected = conn && !state->f_ae3 && k_sem_count_get(&state->ble_context.sem_230);
			check_bind_status(state, in_box, lid_closed);
			if (state->is_master == 1) {
				runtime_info_sync(state);
				if (connected && (state->esb_pkt.flags & BIT(0))) {
					state->f_0e4 |= 3;
					DAT_20019a5f = 15;
				} else if (DAT_20019a5f) {
					DAT_20019a5f--;
				} else {
					state->f_0e4 &= ~3;
				}
				if (sync_to_slave(state, 0xc, NULL, 0) < 500 && (state->f_0e4 & BIT(2))) {
					FUN_00035270();
					state->f_0e4 &= ~BIT(2);
				}
			} else {
				if (connected) {
					DAT_20019a5f = 15;
					state->esb_pkt.flags |= BIT(0);
				} else if (DAT_20019a5f) {
					DAT_20019a5f--;
				} else {
					state->esb_pkt.flags &= ~BIT(0);
				}
				if ((state->f_0e4 ^ state->esb_pkt.flags) & BIT(0)) {
					state->esb_pkt.data[0]++;
				}
				if (sync_to_master(state, 1, NULL, 0) < 500 && (state->esb_pkt.flags & BIT(2))) {
					FUN_00035270();
					state->esb_pkt.flags &= ~BIT(2);
					state->f_0e4 &= ~BIT(2);
				}
			}
			FUN_00027744();
			while (state->work_mode == 1) {
				watchdog_disable();
				if (state->is_master == 1) {
					FUN_000806e4(state, state->dashboard_ts);
				}
				if (k_uptime_get() - state->last_sync_ts >= 600000) {
					G1_LOG_ERR("reboot because dfu exceed time\n");
					k_msleep(500);
					sys_reboot(SYS_REBOOT_COLD);
				}
				G1_LOG_ERR("********************DFU MODE********************\n");
				check_work_mode(in_box, lid_closed, connected);
				k_sleep(K_MSEC(1000));
			}
			if (DAT_2000304f) {
				if (!DAT_20019a5e) {
					watchdog_feed();
				}
			} else {
				watchdog_disable();
			}
			if (state->is_master == 1) {
				FUN_000806e4(state, state->dashboard_ts);
			}
			if (getEraseDFU() && k_uptime_get() >= 60000) {
				erase_dfu_flash();
				setEraseDFU(false);
			}
			G1_LOG_WRN("Global Working Mode: %d get_glasses_ble_status %d ble_is_connected %d\n",
				   state->f_fee, get_glasses_ble_status(), connected);
			try_enter_low_power_mode();
			check_work_mode(in_box, lid_closed, connected);
			check_disp_onboarding(in_box);
			if (conn && !state->f_1080 &&
			    (uint32_t)(k_uptime_get() - state->f_ae4) > 30000 && state->work_mode != 1) {
				state->f_ae4 = k_uptime_get();
				bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			}
			if (state->f_10d5) {
				state->f_10d5 = 0;
				FUN_0007ff66(get_dashboard_state(), 0);
				reset_all_usr_data(state, 1);
			}
			check_sw0_status();
			cnt = 0;
		}
		FUN_0007ff16();
		if (!DAT_20019a5e) {
			watchdog_feed();
		}
		k_sleep(K_MSEC(200));
	}
}

void init_threads(struct GlassesState *state)
{
	k_mutex_init(&k_mutex_2000851c);
	start_flash_storage_threads(state);
	init_watchdog();
	if (!FUN_00033d5c()) {
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
	if (FUN_00033d5c() == 1) {
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
	if (!FUN_00017f30()) {
		G1_LOG_WRN("interrupt line low!!!\n");
		if (++sw0_low_count > 3) {
			G1_LOG_WRN("interrupt line abnormal, now reset\n");
			aw93203_init();
		}
	} else {
		sw0_low_count = 0;
	}
}


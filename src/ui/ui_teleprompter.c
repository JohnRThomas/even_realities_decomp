/*
 * Teleprompter screen task: count down, scrolling text page with elapsed
 * time / progress bar, suspend handling and app-disconnect detection.
 */
#include <stdio.h>

#include "ui_a.h"

#define TELEPROMPTER_DISPLAY_IDLE          0
#define TELEPROMPTER_DISPLAY_COUNTDOWN     1
#define TELEPROMPTER_TEXT_DISPLAY          2
#define TELEPROMPTER_DISPLAY_ABNORMAL_EXIT 3

/* _tpm_thread_prv_data (0x20004b40, 0x230 bytes) */
struct tpm_thread_prv_data {
	volatile uint8_t state;          /* 0x00 */
	volatile int8_t sync_cnt;        /* 0x01 */
	uint8_t pad_02[6];
	volatile int64_t last_sync_ts;   /* 0x08 */
	volatile int64_t start_ts;       /* 0x10 */
	volatile uint32_t elapsed_ms;    /* 0x18 */
	volatile uint8_t suspend_applied; /* 0x1c */
	volatile uint8_t suspended;      /* 0x1d */
	uint8_t pad_1e[2];
	volatile uint32_t display_ms;    /* 0x20 */
	volatile uint8_t work_mode;      /* 0x24 */
	volatile int8_t countdown;       /* 0x25 */
	uint8_t pad_26[2];
	volatile int64_t countdown_end;  /* 0x28 */
	char text[0x200];                /* 0x30 */
};
BUILD_ASSERT(sizeof(struct tpm_thread_prv_data) == 0x230);

/* elapsed time shown on the page (reverse definition order) */
static int tp_hour;                          /* 0x2000a9d0 */
static int tp_min;                           /* 0x2000a9cc */
static int tp_sec;                           /* 0x2000a9c8 */
static int tp_last_hour;                     /* 0x2000a9c4 */
static int tp_last_min;                      /* 0x2000a9c0 */
static int tp_last_sec;                      /* 0x2000a9bc */

struct tpm_thread_prv_data _tpm_thread_prv_data;

void FUN_0003f23c(void)
{
	memset(&_tpm_thread_prv_data, 0, sizeof(_tpm_thread_prv_data));
}

int ui_teleprompter_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct ui_gs *gs = UI_GS();
	struct tpm_thread_prv_data *tp = &_tpm_thread_prv_data;
	uint8_t **fb = panel->panel_buffer;

	set_frame_buffer(fb);
	set_showing_notification_on_gui();

	switch (tp->state) {
	case TELEPROMPTER_DISPLAY_IDLE:
		G1_LOG_INF("running  TELEPROMPTER_DISPLAY_IDLE STATUS.\n");
		if (event == UI_EVT_EXIT) {
			gui_screen_clear();
			memset(tp, 0, sizeof(*tp));
			break;
		}
		G1_LOG_INF("GLOBAL->temeprompter_info->enable = %d\n", UI_GS()->tp_info->enable);
		if (event == UI_EVT_ENTER && UI_GS()->tp_info->enable == 1 && gs->ui.tp.cmd == 1) {
			uint8_t percent;
			uint16_t dark_lines;
			bool is_24h;

			G1_LOG_INF("setp1: received teleprompter command.\n");
			if (UI_GS()->is_master == 1) {
				send_response_data_to_ble();
			}
			G1_LOG_INF("received teleprompter counter down timer start event..\n");
			gui_screen_clear();
			memset(tp, 0, sizeof(*tp));
			tp->state = TELEPROMPTER_DISPLAY_COUNTDOWN;
			tp->last_sync_ts = k_uptime_get();
			tp->start_ts = k_uptime_get();
			tp->elapsed_ms = 0;
			tp->sync_cnt = 10;
			tp->countdown = gs->ui.tp.countdown;
			tp_hour = 0;
			tp_min = 0;
			tp_sec = 0;
			tp_last_hour = 0;
			tp_last_min = 0;
			tp_last_sec = 0;
			memset(tp->text, 0, sizeof(tp->text));
			k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
			memcpy(tp->text, gs->ui.tp.text, sizeof(tp->text));
			percent = gs->ui.tp.percent;
			dark_lines = gs->ui.tp.dark_lines;
			tp->work_mode = gs->ui.tp.work_mode;
			tp->countdown = gs->ui.tp.countdown;
			k_mutex_unlock(&k_mutex_2000851c);
			tp->countdown_end = k_uptime_get() + gs->ui.tp.countdown * 1000 - 350;
			G1_LOG_INF("teleprompter work mode = %d\n", tp->work_mode);
			clear_showing_notification_on_gui();
			for (int i = 0; i < 4; i++) {
				gui_utf_draw(0, tp->text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset() + 1,
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, dark_lines,
					     0, NULL, 0);
				is_24h = UI_GS()->dashboard_ts->time_disp_mode != 1;
				gui_clock_draw(FUN_00080732(), gui_screen_x_offset(), gui_screen_y_offset() + 2,
					       gui_screen_x_offset() + 0x3f, gui_screen_y_offset() + 0x1d, 3, is_24h);
				gui_verticalLine_process_bar(gui_screen_x_offset() + 0x23c, gui_screen_y_offset(),
							     gui_screen_x_offset() + 0x23c, gui_screen_y_offset() + 0x88,
							     1, percent, 0);
				gui_bmp_bitmap_draw(0x18, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0);
				for (int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = {1, 3, 5, 7, 7, 7, 7, 7};
						uint8_t pix = fb[row][col];

						if (pix != 0) {
							fb[row][col] = pix & gui_fade_mask[row % 26]
											  [steps[i]][col];
						}
					}
				}
				_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
							UI_GS()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
			k_msleep(150);
			gui_dynamic_bitmap_reset();
		}
		break;

	case TELEPROMPTER_DISPLAY_COUNTDOWN:
		if (event == UI_EVT_EXIT) {
			gui_screen_clear();
			memset(tp, 0, sizeof(*tp));
			break;
		}
		if (event == UI_EVT_ENTER) {
			G1_LOG_INF("counter down break,received sync message...\n");
			if (gs->ui.tp.status == 2 || gs->ui.tp.status == 3) {
				tp->last_sync_ts = k_uptime_get();
				tp->state = TELEPROMPTER_TEXT_DISPLAY;
				tp->start_ts = k_uptime_get();
				_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
					       gui_screen_x_offset() + 0x24, gui_screen_y_offset() + 0x52);
				if (tp->work_mode == 1) {
					gui_bmp_bitmap_draw(0x1a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				} else if (tp->work_mode == 0) {
					gui_bmp_bitmap_draw(0x19, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				}
			}
			if (UI_GS()->is_master == 1) {
				send_response_data_to_ble();
			}
		} else if (event == UI_EVT_REFRESH) {
			int64_t now;

			G1_LOG_INF("na sync arar reflash,update counter down timer\n");
			now = k_uptime_get();
			if (now < tp->countdown_end) {
				int64_t remain = (tp->countdown_end - now) / 1000;

				if (remain > tp->countdown) {
					remain = tp->countdown;
				}
				if (remain == 0) {
					G1_LOG_INF("remain time end ,switch text display ...\n");
					tp->start_ts = k_uptime_get();
					tp->last_sync_ts = k_uptime_get();
					tp->state = TELEPROMPTER_TEXT_DISPLAY;
					_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
						       gui_screen_x_offset() + 0x24, gui_screen_y_offset() + 0x52);
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column,
								gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
								gui_screen_x_offset() + 0x24,
								gui_screen_y_offset() + 0x52);
					if (tp->work_mode == 1) {
						gui_bmp_bitmap_draw(0x1a, gui_screen_x_offset(),
								    gui_screen_y_offset() + 0x36, 0, 0, 0);
					} else if (tp->work_mode == 0) {
						gui_bmp_bitmap_draw(0x19, gui_screen_x_offset(),
								    gui_screen_y_offset() + 0x36, 0, 0, 0);
					}
				} else {
					char cnt[3];

					memset(cnt, 0, sizeof(cnt));

					snprintf(cnt, sizeof(cnt), "%d", (int)remain);
					G1_LOG_INF("upgrade counterdown timer = %s\n", cnt);
					gui_utf_draw(0, cnt, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
						     gui_screen_x_offset() + 0x1e, gui_screen_y_offset() + 0x50, 1, 0, 0,
						     NULL, 0);
				}
			} else {
				G1_LOG_INF("counter down timeout . exit counter down status ,switch TEXT DISPLAY \n");
				tp->start_ts = k_uptime_get();
				tp->state = TELEPROMPTER_TEXT_DISPLAY;
				tp->last_sync_ts = k_uptime_get();
				_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
					       gui_screen_x_offset() + 0x1e, gui_screen_y_offset() + 0x50);
				_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
							UI_GS()->panel.current_column, gui_screen_x_offset(),
							gui_screen_y_offset() + 0x36, gui_screen_x_offset() + 0x1e,
							gui_screen_y_offset() + 0x50);
				if (tp->work_mode == 1) {
					gui_bmp_bitmap_draw(0x1a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				} else if (tp->work_mode == 0) {
					gui_bmp_bitmap_draw(0x19, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				}
			}
		}
		break;

	case TELEPROMPTER_TEXT_DISPLAY: {
		bool is_24h;
		uint8_t suspended;

		G1_LOG_INF("running TELEPROMPTER_TEXT_DISPLAY STATUS.\n");
		if (event == UI_EVT_EXIT) {
			G1_LOG_INF("received exit command,clear screen...\n");
exit_text:
			gui_screen_fade_out();
			memset(tp, 0, sizeof(*tp));
stop_mic:
			if (UI_GS()->is_master == 1 && tp->work_mode == 2) {
				FUN_00030458();
			}
			break;
		}
		suspended = tp->suspended;
		if (suspended == 1) {
			if (!tp->suspend_applied) {
				uint32_t now = k_uptime_get();

				tp->elapsed_ms += now - (uint32_t)tp->start_ts;
				tp->suspend_applied = suspended;
			}
			tp->display_ms = tp->elapsed_ms;
		} else if (!tp->suspend_applied) {
			tp->display_ms = (uint32_t)k_uptime_get() - (uint32_t)tp->start_ts;
			tp->display_ms += tp->elapsed_ms;
		} else {
			tp->start_ts = (uint32_t)k_uptime_get();
			tp->display_ms = tp->elapsed_ms;
			tp->suspend_applied = 0;
		}
		is_24h = UI_GS()->dashboard_ts->time_disp_mode != 1;
		gui_clock_draw(FUN_00080732(), gui_screen_x_offset(), gui_screen_y_offset() + 2, gui_screen_x_offset() + 0x3f,
			       gui_screen_y_offset() + 0x1d, 3, is_24h);
		if (event == UI_EVT_ENTER) {
			uint8_t percent;
			uint8_t suspend;
			uint16_t dark_lines;
			int32_t suspend_time;

			if (UI_GS()->is_master == 1) {
				G1_LOG_INF("received sync area command ,send store cache data to app\n");
				send_response_data_to_ble();
				if (tp->sync_cnt < 20) {
					tp->sync_cnt = 19;
				}
			}
			memset(tp->text, 0, sizeof(tp->text));
			k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
			memcpy(tp->text, gs->ui.tp.text, sizeof(tp->text));
			percent = gs->ui.tp.percent;
			suspend = gs->ui.tp.suspend;
			dark_lines = gs->ui.tp.dark_lines;
			/* memcpy, not a plain load: the extra copy decides an IRA spill tie (keeps suspend_time in r8) */
			memcpy(&suspend_time, &gs->ui.tp.suspend_time, sizeof(suspend_time));
			k_mutex_unlock(&k_mutex_2000851c);
			if (DAT_20010f05 == 1) {
				DAT_20010f05 = 0;
				gui_utf_draw_scroll_line(0, tp->text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset() + 1,
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5,
					     dark_lines);
			} else {
				gui_utf_draw(0, tp->text, 0, gui_screen_x_offset() + 0x58, gui_screen_y_offset() + 1,
					     gui_screen_x_offset() + 0x230, gui_screen_y_offset() + 0x88, 5, dark_lines,
					     0, NULL, 0);
			}
			gui_verticalLine_process_bar(gui_screen_x_offset() + 0x23c, gui_screen_y_offset(),
						     gui_screen_x_offset() + 0x23c, gui_screen_y_offset() + 0x88, 1,
						     percent, 0);
			if (suspend == 1) {
				if (atomic_test_bit(&gui_flags, 1)) {
					_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
						       gui_screen_x_offset() + 0x24, gui_screen_y_offset() + 0x52);
				}
				if (atomic_test_bit(&gui_flags, 1)) {
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column,
								gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
								gui_screen_x_offset() + 0x24,
								gui_screen_y_offset() + 0x52);
				}
				gui_bmp_bitmap_draw(0x1b, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0);
				tp->suspended = 1;
				tp->elapsed_ms = suspend_time * 1000;
				tp->start_ts = (uint32_t)k_uptime_get();
				G1_LOG_INF("suspend enable...\n");
			} else {
				tp->suspended = 0;
				if (atomic_test_bit(&gui_flags, 1)) {
					_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
						       gui_screen_x_offset() + 0x24, gui_screen_y_offset() + 0x52);
				}
				if (atomic_test_bit(&gui_flags, 1)) {
					_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
								UI_GS()->panel.current_column,
								gui_screen_x_offset(), gui_screen_y_offset() + 0x36,
								gui_screen_x_offset() + 0x24,
								gui_screen_y_offset() + 0x52);
				}
				if (tp->work_mode == 1) {
					gui_bmp_bitmap_draw(0x1a, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				} else if (tp->work_mode == 0) {
					gui_bmp_bitmap_draw(0x19, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
				}
				G1_LOG_INF("suspend cancel...\n");
			}
		}
		if (tp->work_mode == 2 && tp->suspended == 0) {
			gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0, 0, 0, 0);
		}
		tp->display_ms = tp->display_ms / 1000;
		if (tp->display_ms < 60) {
			tp_sec = tp->display_ms % 60;
		} else if (tp->display_ms < 3600) {
			tp_sec = tp->display_ms % 60;
			tp_min = tp->display_ms / 60;
		} else if (tp->display_ms < 360000) {
			uint32_t rem;

			tp_hour = tp->display_ms / 3600;
			rem = tp->display_ms % 3600;
			tp_sec = rem % 60;
			tp_min = rem / 60;
		} else {
			tp_hour = 99;
			tp_min = 59;
			tp_sec = 59;
		}
		char buf[64] = "";

		if (tp_hour > 9) {
			snprintf(buf, sizeof(buf), "%02d:%02d:%02d", tp_hour, tp_min, tp_sec);
		} else {
			snprintf(buf, sizeof(buf), "%d:%02d:%02d", tp_hour, tp_min, tp_sec);
		}
		if (tp_hour != tp_last_hour || tp_min != tp_last_min || tp_sec != tp_last_sec) {
			gui_utf_draw(0, buf, 0, gui_screen_x_offset(), gui_screen_y_offset() + 0x6e,
				     gui_screen_x_offset() + 0x50, gui_screen_y_offset() + 0x88, 1, 0, 0, NULL, 0);
			tp_last_hour = tp_hour;
			tp_last_min = tp_min;
			tp_last_sec = tp_sec;
		}
		if (UI_GS()->is_master == 1) {
			uint8_t stop_cmd[2];

			if (DAT_20007f44 > 0) {
				DAT_20007f44 = 0;
				if (tp->sync_cnt < 20) {
					tp->sync_cnt = 19;
				}
			}
			if (abs_diff_u64(k_uptime_get(), tp->last_sync_ts) <= 1000) {
				break;
			}
			tp->last_sync_ts = k_uptime_get();
			tp->sync_cnt--;
			G1_LOG_INF("DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
				   tp->sync_cnt);
			if (tp->sync_cnt > 0) {
				break;
			}
			G1_LOG_WRN("There is a disconnection between the AR Glasses and the Bluetooth application!\n");
			G1_LOG_INF("bluetooth connect is break,Send Stop Teleprompter command to slave.\n");
			stop_cmd[0] = 0x03;
			stop_cmd[1] = 0x01;
			if (sync_to_slave(get_dashboard_state(), 6, stop_cmd, 2) > 4999) {
				G1_LOG_ERR("SYNC TO Slave failed...,don't exec teleprompter exit action,master auto exit...\n");
				break;
			}
			tp->state = TELEPROMPTER_DISPLAY_ABNORMAL_EXIT;
			tp->last_sync_ts = k_uptime_get();
			gui_screen_clear();
			gui_bmp_bitmap_draw(0x3f, gui_screen_x_offset(), gui_screen_y_offset() + 0x3a, 0, 0, 0);
			if (get_current_language() != LANGUAGE_GERMAN) {
				gui_utf_draw(0, "Teleprompt stopped due to app disconnection", 0,
					     gui_screen_x_offset() + 0x4e, gui_screen_y_offset() + 0x37,
					     gui_screen_x_offset() + 0x23a, gui_screen_y_offset() + 0x88, 1, 0, 0,
					     NULL, 0);
			} else {
				gui_utf_draw(0, "Teleprompter aufgrund einer", 0, gui_screen_x_offset() + 0xa0,
					     gui_screen_y_offset() + 0x37, gui_screen_x_offset() + 0x23a,
					     gui_screen_y_offset() + 0x52, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, "App-Trennung gestoppt.", 0, gui_screen_x_offset() + 0xb4,
					     gui_screen_y_offset() + 0x52, gui_screen_x_offset() + 0x23a,
					     gui_screen_y_offset() + 0x6d, 1, 0, 0, NULL, 0);
			}
			goto stop_mic;
		} else if (event == UI_EVT_MASTER_CLOSE) {
			G1_LOG_INF("Received exit command from master, exit teleprompter mode\n");
			tp->state = TELEPROMPTER_DISPLAY_ABNORMAL_EXIT;
			tp->last_sync_ts = k_uptime_get();
			gui_screen_clear();
			gui_bmp_bitmap_draw(0x3f, gui_screen_x_offset(), gui_screen_y_offset() + 0x3a, 0, 0, 0);
			if (get_current_language() != LANGUAGE_GERMAN) {
				gui_utf_draw(0, "Teleprompt stopped due to app disconnection", 0,
					     gui_screen_x_offset() + 0x4e, gui_screen_y_offset() + 0x37,
					     gui_screen_x_offset() + 0x23a, gui_screen_y_offset() + 0x88, 1, 0, 0,
					     NULL, 0);
			} else {
				gui_utf_draw(0, "Teleprompter aufgrund einer", 0, gui_screen_x_offset() + 0xa0,
					     gui_screen_y_offset() + 0x37, gui_screen_x_offset() + 0x23a,
					     gui_screen_y_offset() + 0x52, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, "App-Trennung gestoppt.", 0, gui_screen_x_offset() + 0xb4,
					     gui_screen_y_offset() + 0x52, gui_screen_x_offset() + 0x23a,
					     gui_screen_y_offset() + 0x6d, 1, 0, 0, NULL, 0);
			}
		}
		break;
	}

	case TELEPROMPTER_DISPLAY_ABNORMAL_EXIT:
		G1_LOG_WRN("running TELEPROMPTER_DISPLAY_ABNORMAL_EXIT STATUS.\n");
		if (abs_diff_u64(k_uptime_get(), tp->last_sync_ts) > 8000) {
			G1_LOG_WRN("The teleprompter automatically shuts down due to disconnection.\n");
			memset(UI_GS()->tp_info, 0, 0x217);
			gui_screen_fade_out();
			UI_GS()->tp_info->enable = 0;
			memset(tp, 0, sizeof(*tp));
		}
		if (event == UI_EVT_EXIT) {
			/* G1_LOG_INF() spelled out: &__func__[0] keeps GIMPLE tail merge off these arms */
			if (LOG_LEVEL > 2) {
				if (BLE_DEBUG) {
					ble_printk("%s(): received exit command,clear screen...\n", &__func__[0]);
				} else {
					printk("%s(): received exit command,clear screen...\n", &__func__[0]);
				}
			}
			goto exit_text;
		}
		break;

	default:
		break;
	}
	return 0;
}

/* ui_task_table pre-callback of the teleprompter screen (id 9, 0x200024b8) */
int FUN_000808b0(void)
{
	return 0;
}

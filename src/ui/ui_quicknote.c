/*
 * Quick note (voice memo) screen task and the DMIC record start/stop
 * helpers it uses.
 */
#include "ui_a.h"

/* quick note page private state (0x20004b20, 0x20 bytes) */
struct quicknote_prv_data {
	uint8_t state;            /* 0x00 0 init, 1 running, 2 exiting (logo) */
	uint8_t pad_01[3];
	int32_t exit_delay;       /* 0x04 */
	int64_t ts;               /* 0x08 */
	uint8_t last_status;      /* 0x10 */
	uint8_t recording;        /* 0x11 */
	uint8_t f_12;             /* 0x12 */
	uint8_t pad_13[0x0d];
};
BUILD_ASSERT(sizeof(struct quicknote_prv_data) == 0x20);

int exit_display_ms = 4000;                  /* 0x200024ec */
struct quicknote_prv_data quicknote_prv;
uint8_t quicknote_result_shown;                        /* "result" page drawn */

void dmic_record_start(void)
{
	UI_GS()->pending = 4;
	G1_LOG_INF("received open dmic command\n");
	FUN_00030b28();
	startAudioStreamRecord();
	atomic_set(&DAT_20008558, 1);
	UI_GS()->dashboard_cmd = 0x1d;
	k_sem_give(&UI_GS()->main_sem);
}

void quicknote_stop_record(void)
{
	atomic_set(&DAT_20008558, 0);
	stopAudioStreamRecord();
	FUN_00030458();
}

void FUN_0003d7b4(void)
{
	quicknote_prv.f_12 = 0;
}

int ui_QuickNote_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct ui_gs *gs = UI_GS();
	uint8_t lang = get_current_language();
	struct quicknote_prv_data *qn = &quicknote_prv;

	set_frame_buffer(panel->panel_buffer);
	set_showing_notification_on_gui();

	switch (qn->state) {
	case 0:
		G1_LOG_INF("QUICK NOTE INIT.....\n");
		memset(qn, 0, sizeof(*qn));
		G1_LOG_INF("GLOBAL->quicknote_show_info->enable = %d\n",
			   UI_GS()->quicknote_show_info->enable);
		if (event == UI_EVT_ENTER) {
			if (UI_GS()->quicknote_show_info->enable != 1) {
				break;
			}
			G1_LOG_INF("quick note function start ...\n");
			gui_screen_clear();
			qn->state = 1;
			qn->last_status = gs->ui.qn.status;
			qn->recording = 0;
			quicknote_result_shown = 0;
			gui_dynamic_bitmap_reset();
			clear_showing_notification_on_gui();
			for (int i = 0; i < 4; i++) {
				if (gs->ui.qn.status == 10) {
					quicknote_result_shown = 1;
					qn->ts = k_uptime_get();
					if (gs->ui.qn.mode == 2) {
						uint32_t x;

						/*
						 * compiler_barrier() emits no code.  It makes the block of the first
						 * compare (lang == GERMAN) "not side-effect free", so GCC 12's
						 * if-to-switch pass leaves that compare out.  The remaining 3 cases
						 * are below the table threshold, so the chain stays a compare chain
						 * as in the target.  Without it, GCC builds a CSWTCH table (-28 B).
						 * Vendor-like alternatives that do not work:
						 * - int/uint8/uint32 lang, a switch, ternaries, x = 0xcc first,
						 *   nested else, or a helper: all give the table.
						 * - The chain placed before the mode test, after the qn->ts store:
						 *   the store also blocks the pass, but GCC then does not sink the
						 *   chain below the mode test as the target has it (2376 B).
						 * The vendor's real construct is unknown.
						 */
						compiler_barrier();
						if (lang == LANGUAGE_GERMAN) {
							x = 0xc6;
						} else if (lang == LANGUAGE_FRENCH) {
							x = 0xcc;
						} else if (lang == LANGUAGE_SPANISH) {
							x = 0xd6;
						} else if (lang == LANGUAGE_ITALIAN) {
							x = 0xd0;
						} else {
							x = 0xcc;
						}

						gui_bmp_bitmap_draw(0x4a, gui_screen_x_offset() + x,
								    gui_screen_y_offset() + 0x3a, 0, 0, 0);
						gui_utf_draw(0, get_string(0x52), 0,
							     gui_screen_x_offset() + (int)x + 0x2c,
							     gui_screen_y_offset() + 0x36,
							     gui_screen_x_offset() + 0x240,
							     gui_screen_y_offset() + 0x88, 1, 0, 0, NULL, 0);
					}
				} else {
					gui_utf_draw_middle(0, get_string(0x44), 0, gui_screen_x_offset(),
							    gui_screen_y_offset() + 0x36,
							    gui_screen_x_offset() + 0x240,
							    gui_screen_y_offset() + 0x51, 1, 0, 0, NULL, 0);
					if (gs->ui.qn.page == 0) {
						gui_utf_draw_middle(0, get_string(0x45), 0,
								    gui_screen_x_offset(),
								    gui_screen_y_offset() + 0x6c,
								    gui_screen_x_offset() + 0x240,
								    gui_screen_y_offset() + 0x87, 1, 0, 0,
								    NULL, 0);
					}
				}
				for (int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = {1, 3, 5, 7, 7, 7, 7, 7};
						uint8_t pix = panel->panel_buffer[row][col];

						if (pix != 0) {
							panel->panel_buffer[row][col] =
								pix & gui_fade_mask[row % 26][steps[i]]
										   [col];
						}
					}
				}
				_reflash_fb_data_to_lcd(UI_GS()->panel.current_row,
							UI_GS()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
			if (UI_GS()->is_master == 1) {
				if (qn->recording == 1) {
					if (FUN_00030440() == 1) {
						FUN_0008040c();
					}
				} else if (atomic_get(&DAT_20008558) != 1 || FUN_00030440() == 1) {
					dmic_record_start();
				}
			}
		} else if (event == UI_EVT_EXIT) {
			G1_LOG_ERR("quick init,exec function exit ...\n");
			if (UI_GS()->is_master == 1) {
				if (qn->recording == 1) {
					FUN_00030458();
				} else {
					quicknote_stop_record();
				}
			}
			gui_screen_clear();
			UI_GS()->quicknote_show_info->enable = 0;
			memset(qn, 0, sizeof(*qn));
			quicknote_result_shown = 0;
		}
		break;

	case 1:
		G1_LOG_INF("QUICK NOTE RUNING.....\n");
		if (UI_GS()->quicknote_show_info->enable == 1) {
			if (event == UI_EVT_ENTER) {
				uint8_t status = gs->ui.qn.status;

				if (status == 8) {
					if (qn->last_status != 8) {
						qn->last_status = status;
						_clean_fb_data(panel->panel_buffer, 0,
							       gui_screen_x_offset() + 0x14, gui_screen_y_offset(),
							       gui_screen_x_offset() + 0x240,
							       gui_screen_y_offset() + 0x88);
					}
					if (gs->ui.qn.mode == 0) {
						const char *text = gs->ui.qn.text;

						if (gs->ui.qn.f_05 == 1) {
							gui_utf_draw_scroll_line(0, text, 0, gui_screen_x_offset() + 100,
								     gui_screen_y_offset(),
								     gui_screen_x_offset() + 0x1dc,
								     gui_screen_y_offset() + 0x88, 5, 0);
						} else {
							gui_utf_draw(0, text, 0, gui_screen_x_offset() + 100,
								     gui_screen_y_offset(),
								     gui_screen_x_offset() + 0x1dc,
								     gui_screen_y_offset() + 0x88, 5, 0, 0, NULL,
								     0);
						}
					}
				} else if (status == 10 && quicknote_result_shown == 0) {
					quicknote_result_shown = 1;
					gui_screen_clear();
					qn->ts = k_uptime_get();
					switch (gs->ui.qn.mode) {
					case 1:
						gui_utf_draw_middle(0, get_string(0x60), 0, gui_screen_x_offset(),
								    gui_screen_y_offset() + 0x36,
								    gui_screen_x_offset() + 0x240,
								    gui_screen_y_offset() + 0x88, 3, 0, 0, NULL, 0);
						break;
					case 2: {
						uint32_t x;

						compiler_barrier(); /* see the first language chain */
						if (lang == LANGUAGE_GERMAN) {
							x = 0xc6;
						} else if (lang == LANGUAGE_FRENCH) {
							x = 0xcc;
						} else if (lang == LANGUAGE_SPANISH) {
							x = 0xd6;
						} else if (lang == LANGUAGE_ITALIAN) {
							x = 0xd0;
						} else {
							x = 0xcc;
						}

						gui_bmp_bitmap_draw(0x4a, gui_screen_x_offset() + x,
								    gui_screen_y_offset() + 0x3a, 0, 0, 0);
						gui_utf_draw(0, get_string(0x52), 0,
							     gui_screen_x_offset() + (int)x + 0x2c,
							     gui_screen_y_offset() + 0x36,
							     gui_screen_x_offset() + 0x240,
							     gui_screen_y_offset() + 0x88, 1, 0, 0, NULL, 0);
						break;
					}
					}
				}
			}
			if ((event == UI_EVT_ENTER || event == UI_EVT_REFRESH) &&
			    (gs->ui.qn.status == 7 || gs->ui.qn.status == 8)) {
				gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0, 0);
			}
		}
		if (quicknote_result_shown != 0) {
			if (qn->ts + 3999 < k_uptime_get()) {
				UI_GS()->quicknote_show_info->enable = 0;
			}
		}
		if (event == UI_EVT_EXIT) {
			G1_LOG_INF("quick note function exit ...\n");
			if (UI_GS()->is_master == 1) {
				if (qn->recording == 1) {
					FUN_00030458();
				} else {
					quicknote_stop_record();
				}
			}
			gui_screen_fade_out();
			UI_GS()->quicknote_show_info->enable = 0;
			memset(qn, 0, sizeof(*qn));
			quicknote_result_shown = 0;
		} else if (event == UI_EVT_DELAY_CLOSE) {
			G1_LOG_INF("quick note function delay exit ...\n");
			if (UI_GS()->is_master == 1) {
				if (qn->recording == 1) {
					FUN_00030458();
				} else {
					quicknote_stop_record();
				}
			}
			qn->exit_delay = get_display_delay_close_ms();
			qn->ts = k_uptime_get();
			gui_screen_clear();
			qn->state = 2;
			quicknote_result_shown = 0;
			gui_dynamic_bitmap_reset();
			G1_LOG_INF("exec even logo reflash....\n");
		}
		break;

	case 2:
		G1_LOG_INF("quick note process exec.....\n");
		if (event == UI_EVT_EXIT) {
			G1_LOG_INF("quick note function exit ...\n");
			if (UI_GS()->is_master == 1) {
				if (qn->recording == 1) {
					FUN_00030458();
				} else {
					quicknote_stop_record();
				}
			}
			gui_screen_fade_out();
			UI_GS()->quicknote_show_info->enable = 0;
			memset(qn, 0, sizeof(*qn));
			quicknote_result_shown = 0;
		} else {
			int64_t now = k_uptime_get();

			if (qn->ts + qn->exit_delay < now) {
				G1_LOG_INF("quick note function exit -164 ...\n");
				gui_screen_fade_out();
				UI_GS()->quicknote_show_info->enable = 0;
				memset(qn, 0, sizeof(*qn));
				quicknote_result_shown = 0;
			} else if (qn->ts + qn->exit_delay - exit_display_ms < now) {
				if (quicknote_result_shown == 0) {
					G1_LOG_INF("exec quick note exit display...\n");
					gui_screen_clear();
					gui_bmp_bitmap_draw(0x3b, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0);
					gui_utf_draw_middle(0, get_string(0x46), 0, gui_screen_x_offset() + 0x24,
							    gui_screen_y_offset() + 0x36,
							    gui_screen_x_offset() + 0x21c,
							    gui_screen_y_offset() + 0x6c, 2, 0, 0, NULL, 0);
					quicknote_result_shown = 1;
				}
			} else if (quicknote_result_shown == 0) {
				gui_bmp_dynamic_bitmap_draw(9, gui_screen_x_offset(), gui_screen_y_offset() + 0x36, 0,
							    0, 0, 0);
				gui_utf_draw_darkword_by_lines(0, gs->ui.qn.text, 0,
							       gui_screen_x_offset() + 100, gui_screen_y_offset(),
							       gui_screen_x_offset() + 0x1dc,
							       gui_screen_y_offset() + 0x88, 5, 5, 0, NULL, 0);
			}
		}
		break;

	default:
		break;
	}
	return 0;
}

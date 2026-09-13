/*
 * UI page: Even AI (v2) information.
 */
#include <string.h>
#include <zephyr/kernel.h>

#include "gui.h"

static struct {
	uint8_t state;
	uint8_t entered;
	uint8_t timeout_cnt;
	int64_t ts;
	uint8_t last_action;
	uint8_t last_status;
} even_ai_v2_ui;

/* reset the page's idle-timeout counter (ble_proto calls it on each new packet) */
void even_ai_v2_info_timeout_reset(void)
{
	even_ai_v2_ui.timeout_cnt = 0;
}
extern __typeof__(even_ai_v2_info_timeout_reset) FUN_00049a24 __attribute__((alias("even_ai_v2_info_timeout_reset")));

/* other modules */
uint8_t FUN_00028d2c(void);
uint8_t FUN_00030440(void);
void FUN_0008040c(void);
void gui_utf_draw_scroll_line(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		  uint32_t max_lines, uint32_t dark_cnt);
int gui_horizontal_percentage_bar(int x0, int y0, int x1, int y1, uint8_t segments, uint8_t gap,
				  uint8_t percent);

/* even_ai_v2 actions (GlassesState + 0xf0) */
enum {
	EVEN_AI_V2_WAKEUP = 1,
	EVEN_AI_V2_LISTEN = 2,
	EVEN_AI_V2_ANSWER = 3,
	EVEN_AI_V2_COMMAND = 4,
	EVEN_AI_V2_ERROR = 7,
};

/*
 * Redraw the Even AI v2 page for GlassesState+0xf0 (action) / +0xf2 (status).
 * force == 1: also redraw the static text.  Screen positions are relative to
 * gui_screen_x_offset() (x) / gui_screen_y_offset() (y); icon x offsets depend on the UI
 * language (5, 6, 7, 14 have their own layout; switch/if-chains -> CSWTCH tables
 * 0xdb2ec..0xdb382 / 0x9c49c..0x9c4d8 in the target).
 */
int even_ai_v2_info_reflash(uint8_t **fb, int force)
{
	struct gui_glasses_state *gs = GUI_STATE();
	uint8_t lang = get_current_language();
	int x_off = 0;
	int text_w = 576;
	int x, y;

	ARG_UNUSED(fb);

	if (GUI_STATE()->f_1247 == 1 &&
	    (gs->ui_action == 2 ? gs->ui_status == 1 :
	     (gs->ui_action >= 3 && gs->ui_action <= 6 && gs->ui_action != 5))) {
		FUN_00030458();
	} else if (GUI_STATE()->is_master == 1 && FUN_00028d2c() == 1 &&
		   *GUI_STATE()->even_ai_state == 1 && FUN_00030440() == 1) {
		FUN_0008040c();
	}

	if (even_ai_v2_ui.last_action != gs->ui_action ||
	    (gs->ui_action != EVEN_AI_V2_ANSWER && even_ai_v2_ui.last_status != gs->ui_status)) {
		G1_LOG_WRN("even_ai_v2 action change, id:%d,status:%d, clear screen\n",
			   gs->ui_action, gs->ui_status);
		even_ai_v2_ui.last_action = gs->ui_action;
		even_ai_v2_ui.last_status = gs->ui_status;
		gui_screen_clear();
		gui_dynamic_bitmap_reset();
	}

	/* animated icon */
	switch (gs->ui_action) {
	case EVEN_AI_V2_ERROR:
		if (gs->ui_status == 2) {
			gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		}
		break;
	case EVEN_AI_V2_WAKEUP:
		gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		break;
	case EVEN_AI_V2_LISTEN:
		if (gs->ui_status == 0) {
			gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		} else {
			gui_bmp_dynamic_bitmap_draw(9, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		}
		break;
	case EVEN_AI_V2_ANSWER:
		if (gs->ui_status == 0) {
			gui_bmp_dynamic_bitmap_draw(4, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		}
		break;
	default:
		break;
	}

	if (force != 1) {
		return 0;
	}

	switch (gs->ui_action) {
	case EVEN_AI_V2_ERROR: {
		int off;

		if (gs->ui_status == 1) {
			switch (lang) {
			case 5:
				off = 164;
				break;
			case 6:
				off = 142;
				break;
			case 7:
				off = 148;
				break;
			case 14:
				off = 158;
				break;
			default:
				off = 154;
				break;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x3e, x + off, y + 54, 0, 0, 0);
			gui_utf_draw(0, get_string(0x5f), 0, gui_screen_x_offset() + off + 52,
				     gui_screen_y_offset() + 54, gui_screen_x_offset() + 576,
				     gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
		} else if (gs->ui_status == 2) {
			gui_utf_draw_middle(0, get_string(0x56), 0, gui_screen_x_offset(),
					    gui_screen_y_offset() + 54, gui_screen_x_offset() + 576,
					    gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
			gui_utf_draw_middle(0, get_string(0x45), 0, gui_screen_x_offset(),
					    gui_screen_y_offset() + 108, gui_screen_x_offset() + 576,
					    gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
		}
		break;
	}
	case EVEN_AI_V2_WAKEUP: {
		uint8_t id;

		gui_utf_draw_middle(0, get_string(0x56), 0, gui_screen_x_offset(), gui_screen_y_offset() + 54,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
		if (gs->ui_status >= 1 && gs->ui_status <= 7) {
			id = gs->ui_status + 0x57;
		} else {
			id = 0x57;
		}
		gui_utf_draw_middle(0, get_string(id), 0, gui_screen_x_offset(), gui_screen_y_offset() + 108,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
		break;
	}
	case EVEN_AI_V2_LISTEN:
		if (gs->ui_status == 0) {
			if (gs->page_flags == 1) {
				gui_utf_draw_scroll_line(0, gs->ai_text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
					     gui_screen_x_offset() + 560, gui_screen_y_offset() + 136, 5, 0);
			} else {
				gui_utf_draw(0, gs->ai_text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
					     gui_screen_x_offset() + 560, gui_screen_y_offset() + 136, 5, 0, 0, NULL, 0);
			}
		} else {
			gui_utf_draw_darkword_by_lines(0, gs->ai_text, 0, gui_screen_x_offset() + 88,
						       gui_screen_y_offset(), gui_screen_x_offset() + 560,
						       gui_screen_y_offset() + 136, 5, 5, 0, NULL, 0);
		}
		break;
	case EVEN_AI_V2_ANSWER:
		if (gs->ui_status == 0) {
			if (gs->page_flags == 1) {
				gui_utf_draw_scroll_line(0, gs->ai_text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
					     gui_screen_x_offset() + 560, gui_screen_y_offset() + 136, 5, 0);
			} else {
				gui_utf_draw(0, gs->ai_text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
					     gui_screen_x_offset() + 560, gui_screen_y_offset() + 136, 5, 0, 0, NULL, 0);
			}
		} else {
			gui_area_clear(gui_screen_x_offset(), gui_screen_y_offset() + 58, gui_screen_x_offset() + 40,
				       gui_screen_y_offset() + 98);
			gui_utf_draw(0, gs->ai_text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
				     gui_screen_x_offset() + 560, gui_screen_y_offset() + 136, 5, 0, 0, NULL, 0);
			if (gs->dark_cnt <= 100) {
				gui_verticalLine_process_bar(gui_screen_x_offset() + 572, gui_screen_y_offset(),
							     gui_screen_x_offset() + 572,
							     gui_screen_y_offset() + 136, 1, gs->dark_cnt,
							     0);
			}
		}
		break;
	case EVEN_AI_V2_COMMAND:
		switch (gs->ui_status) {
		case 1:
			if (lang == 6) {
				x_off = 16;
			} else if (lang == 5) {
				x_off = 14;
			} else if (lang == 7) {
				x_off = 68;
			} else if (lang == 14) {
				x_off = 48;
			} else {
				x_off = 98;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4d, x + x_off, y + 58, 0, 0, 0);
			break;
		case 2:
			if (lang == 6) {
				x_off = 154;
			} else if (lang == 5) {
				x_off = 118;
			} else if (lang == 7) {
				x_off = 140;
			} else if (lang == 14) {
				x_off = 136;
			} else {
				x_off = 162;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4a, x + x_off, y + 58, 0, 0, 0);
			break;
		case 3:
			if (lang == 6) {
				x_off = 142;
			} else if (lang == 5) {
				x_off = 120;
			} else if (lang == 7) {
				x_off = 148;
			} else if (lang == 14) {
				x_off = 124;
			} else {
				x_off = 174;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4b, x + x_off, y + 58, 0, 0, 0);
			break;
		case 4:
			if (lang == 6) {
				x_off = 138;
			} else if (lang == 5) {
				x_off = 104;
			} else if (lang == 7) {
				x_off = 130;
			} else if (lang == 14) {
				x_off = 110;
			} else {
				x_off = 170;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4b, x + x_off, y + 58, 0, 0, 0);
			break;
		case 5:
			gui_bmp_bitmap_draw(0x4c, gui_screen_x_offset() + 144, gui_screen_y_offset() + 58, 0, 0, 0);
			gui_horizontal_percentage_bar(gui_screen_x_offset() + 188, gui_screen_y_offset() + 66,
						      gui_screen_x_offset() + 388, gui_screen_y_offset() + 70, 1, 0,
						      GUI_STATE()->level_0cb * 100 / 42);
			x_off = 144;
			break;
		case 6:
			gui_bmp_bitmap_draw(0x4f, gui_screen_x_offset() + 136, gui_screen_y_offset() + 58, 0, 0, 0);
			gui_horizontal_percentage_bar(gui_screen_x_offset() + 180, gui_screen_y_offset() + 66,
						      gui_screen_x_offset() + 396, gui_screen_y_offset() + 70, 5, 4,
						      (GUI_STATE()->panel.brightness + 1) * 10);
			x_off = 136;
			break;
		case 7:
			gui_bmp_bitmap_draw(0x50, gui_screen_x_offset() + 136, gui_screen_y_offset() + 58, 0, 0, 0);
			gui_horizontal_percentage_bar(
				gui_screen_x_offset() + 180, gui_screen_y_offset() + 66, gui_screen_x_offset() + 394,
				gui_screen_y_offset() + 70, 9, 2,
				(GUI_STATE()->panel.raster_height_offset + 1) * 100 / 9);
			x_off = 136;
			break;
		case 8:
			if (lang == 6) {
				x_off = 196;
			} else if (lang == 5) {
				x_off = 160;
			} else if (lang == 7) {
				x_off = 164;
			} else if (lang == 14) {
				x_off = 172;
			} else {
				x_off = 196;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4e, x + x_off, y + 58, 0, 0, 0);
			break;
		case 9:
			if (lang == 6) {
				x_off = 194;
			} else if (lang == 5) {
				x_off = 144;
			} else if (lang == 7) {
				x_off = 148;
			} else if (lang == 14) {
				x_off = 158;
			} else {
				x_off = 194;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4e, x + x_off, y + 58, 0, 0, 0);
			break;
		case 10:
			if (lang == 6) {
				x_off = 170;
			} else if (lang == 5) {
				x_off = 166;
			} else if (lang == 7) {
				x_off = 154;
			} else if (lang == 14) {
				x_off = 186;
			} else {
				x_off = 198;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x3c, x + x_off, y + 54, 0, 0, 0);
			break;
		case 11:
			if (lang == 6) {
				x_off = 166;
			} else if (lang == 5) {
				x_off = 150;
			} else if (lang == 7) {
				x_off = 136;
			} else if (lang == 14) {
				x_off = 174;
			} else {
				x_off = 194;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x3c, x + x_off, y + 54, 0, 0, 0);
			break;
		case 12:
			if (lang == 6) {
				x_off = 160;
			} else if (lang == 5) {
				x_off = 144;
			} else if (lang == 7) {
				x_off = 168;
			} else if (lang == 14) {
				x_off = 178;
			} else {
				x_off = 192;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x3b, x + x_off, y + 54, 0, 0, 0);
			break;
		case 13:
			if (lang == 6) {
				x_off = 48;
			} else if (lang == 5) {
				x_off = 52;
			} else if (lang == 7) {
				x_off = 84;
			} else if (lang == 14) {
				x_off = 76;
			} else {
				x_off = 74;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x54, x + x_off, y + 58, 0, 0, 0);
			break;
		case 14:
			if (lang == 6) {
				x_off = 34;
			} else if (lang == 5) {
				x_off = 42;
			} else if (lang == 7) {
				x_off = 72;
			} else if (lang == 14) {
				x_off = 70;
			} else {
				x_off = 66;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x53, x + x_off, y + 58, 0, 0, 0);
			break;
		case 15:
			if (lang == 6) {
				text_w = 410;
				x_off = 62;
			} else if (lang == 5) {
				text_w = 390;
				x_off = 72;
			} else if (lang == 7) {
				x_off = 46;
			} else if (lang == 14) {
				x_off = 130;
			} else {
				x_off = 78;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x52, x + x_off, y + 58, 0, 0, 0);
			break;
		case 16:
			if (lang == 6) {
				x_off = 68;
			} else if (lang == 5) {
				text_w = 336;
				x_off = 100;
			} else if (lang == 7) {
				x_off = 80;
			} else if (lang == 14) {
				x_off = 88;
			} else {
				x_off = 92;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x51, x + x_off, y + 58, 0, 0, 0);
			break;
		case 17:
			if (lang == 6) {
				x_off = 70;
			} else if (lang == 5) {
				text_w = 370;
				x_off = 84;
			} else if (lang == 7) {
				x_off = 68;
			} else if (lang == 14) {
				x_off = 82;
			} else {
				x_off = 88;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x51, x + x_off, y + 58, 0, 0, 0);
			break;
		case 18:
			gui_utf_draw_middle(0, gs->ai_text, 0, gui_screen_x_offset(), gui_screen_y_offset() + 54,
					    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 3, 0, 0, NULL,
					    0);
			break;
		case 19:
			if (lang == 6) {
				x_off = 198;
			} else if (lang == 5) {
				x_off = 204;
			} else if (lang == 7) {
				x_off = 214;
			} else if (lang == 14) {
				x_off = 208;
			} else {
				x_off = 204;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x4a, x + x_off, y + 58, 0, 0, 0);
			break;
		case 20:
			if (lang == 6) {
				text_w = 424;
				x_off = 54;
			} else if (lang == 5) {
				text_w = 412;
				x_off = 60;
			} else if (lang == 7) {
				text_w = 414;
				x_off = 58;
			} else if (lang == 14) {
				text_w = 312;
				x_off = 110;
			} else {
				x_off = 24;
			}
			x = gui_screen_x_offset();
			y = gui_screen_y_offset();
			gui_bmp_bitmap_draw(0x51, x + x_off, y + 58, 0, 0, 0);
			break;
		default:
			break;
		}

		/* command text next to the icon */
		if (gs->ui_status > 20) {
			break;
		}
		if (gs->ui_status >= 5 && gs->ui_status <= 7) {
			gui_utf_draw_middle(0, gs->ai_text, 0, gui_screen_x_offset(), gui_screen_y_offset() + 108,
					    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 1, 0, 0, NULL,
					    0);
		} else if ((gs->ui_status == 15 && (lang == 5 || lang == 6)) ||
			   (gs->ui_status == 16 && lang == 5) || (gs->ui_status == 17 && lang == 5) ||
			   (gs->ui_status == 20 &&
			    (lang == 5 || lang == 6 || lang == 7 || lang == 14))) {
			gui_utf_draw_middle(0, gs->ai_text, 0, gui_screen_x_offset() + x_off + 44,
					    gui_screen_y_offset() + 54,
					    gui_screen_x_offset() + x_off + 44 + text_w,
					    gui_screen_y_offset() + 136, 3, 0, 0, NULL, 0);
		} else if (gs->ui_status != 18) {
			gui_utf_draw(0, gs->ai_text, 0, gui_screen_x_offset() + x_off + 44,
				     gui_screen_y_offset() + 54, gui_screen_x_offset() + 576,
				     gui_screen_y_offset() + 136, 1, 0, 0, NULL, 0);
		}
		break;
	default:
		break;
	}
	return 0;
}

int ui_even_ai_v2_info_task(struct jbd_panel_context *ctx, void *arg, int event)
{
	struct gui_glasses_state *gs = GUI_STATE();

	set_frame_buffer(ctx->panel_buffer);
	set_showing_notification_on_gui();

	switch (even_ai_v2_ui.state) {
	case 0:
		if (event == 1) {
			if (gs->ui_action == 0 || even_ai_v2_ui.entered) {
				return 0;
			}
			gui_utf_adv_draw_reset();
			gui_screen_clear();
			gui_text_state_reset();
			memset(&even_ai_v2_ui, 0, sizeof(even_ai_v2_ui));
			gui_dynamic_bitmap_reset();
			clear_showing_notification_on_gui();

			/* fade in */
			for (int i = 0; i < 8; i++) {
				even_ai_v2_info_reflash(ctx->panel_buffer, 1);
				for (int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = { 1, 2, 3, 4, 5, 6, 7, 7 };

						if (ctx->panel_buffer[row][col] != 0) {
							ctx->panel_buffer[row][col] &=
								gui_fade_mask[row % 26][steps[i]][col];
						}
					}
				}
				_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
							GUI_STATE()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
			even_ai_v2_ui.state = 1;
			even_ai_v2_ui.entered = 1;
			even_ai_v2_ui.ts = k_uptime_get();
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_clear();
			gui_utf_adv_draw_reset();
			memset(&even_ai_v2_ui, 0, sizeof(even_ai_v2_ui));
			FUN_00030458();
		}
		break;
	case 1:
		if (event == 1) {
			even_ai_v2_info_reflash(ctx->panel_buffer, event);
		} else if (event == 0) {
			even_ai_v2_info_reflash(ctx->panel_buffer, event);
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_fade_out();
			gui_utf_adv_draw_reset();
			memset(&even_ai_v2_ui, 0, sizeof(even_ai_v2_ui));
			FUN_00030458();
		}
		if (GUI_STATE()->is_master == 1 &&
		    abs_diff_u64(k_uptime_get(), even_ai_v2_ui.ts) > 1000) {
			even_ai_v2_ui.timeout_cnt++;
			even_ai_v2_ui.ts = k_uptime_get();
			if (even_ai_v2_ui.timeout_cnt >= 20) {
				*GUI_STATE()->even_ai_state = 0;
				FUN_00030458();
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

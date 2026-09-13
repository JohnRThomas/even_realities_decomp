/*
 * UI page: real-time translation (language pair, clock, translated text).
 */
#include "ui_b.h"

#define TRANS_LANG_NUM 25

const char *trans_lang_name[TRANS_LANG_NUM] = {
	"CN", "EN", "JP", "KR", "FR", "DE", "ES", "RU", "NL", "NO", "DK", "SV", "FI",
	"IT", "AR", "HI", "BN", "HK", "PL", "CZ", "TR", "PT", "UK", "EL", "HU",
};

static struct {
	uint8_t state;                   /* 0x00 */
	uint8_t entered;                 /* 0x01 */
	uint8_t suspend_en;              /* 0x02 */
	uint8_t pad_03[7];
	uint16_t hour;                   /* 0x0a last drawn clock */
	uint16_t minute;                 /* 0x0c */
	uint8_t pad_0e[2];
	uint8_t translation_type;        /* 0x10 last drawn language pair */
	uint8_t original_type;           /* 0x11 */
} trans_ui;                              /* 0x200100da */

static char trans_text[0x1e0];           /* 0x2001d960 */
static uint8_t trans_mode;               /* 0x2001d95f */

int draw_template_translate_screen(struct jbd_panel_context *panel)
{
	struct GlassesState *gs = get_dashboard_state();
	struct trans_info *ti = TRANS_INFO(gs);

	set_frame_buffer(panel->panel_buffer);

	if (ti->original_type >= 9 || ti->translation_type == 0 || ti->translation_type >= 9 ||
	    ti->original_type == 0) {
		G1_LOG_ERR("translate language type error! trans_info->original_type %d "
			   "trans_info->translation_type %d\n",
			   ti->original_type, ti->translation_type);
	} else {
		char pair[10] = { 0 };

		snprintf(pair, sizeof(pair), "%s>%s", trans_lang_name[ti->original_type - 1],
			 trans_lang_name[ti->translation_type - 1]);
		gui_utf_draw(0, pair, 3, X0, Y0 + 0x6e, X0 + 0x50, Y0 + 0x89, 1, 0, 0, NULL, 0);
	}

	gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x50, Y0 + 0x1d, 3, true);
	if (ti->suspend_en == 1) {
		gui_bmp_bitmap_draw(0x1b, X0, Y0 + 0x36, 0, 0, 0);
	} else {
		gui_bmp_bitmap_draw(0x33, X0, Y0 + 0x36, 0, 0, 0);
	}
	gui_utf_draw(0, ti->text, 0, X0 + 0x58, Y0 + 1, X0 + 0x240, Y0 + 0x88, 5, 0, 0, NULL, 0);
	return 0;
}

void translate_draw_hint_page(int which)
{
	uint8_t lang = get_current_language();
	uint32_t x;

	gui_screen_clear();
	if (which == 0) {
		switch (lang) {
		case 5:
			x = 0x7a;
			break;
		case 6:
			x = 0x6e;
			break;
		case 7:
		case 14:
			x = 0x7e;
			break;
		default:
			x = 0x70;
			break;
		}
		gui_bmp_bitmap_draw(0x40, X0 + x, Y0 + 0x3a, 0, 0, 0);
		gui_utf_draw(0, get_string(0x54), 0, X0 + (int)x + 0x2c, Y0 + 0x36, X0 + 0x240,
			     Y0 + 0x88, 3, 0, 0, NULL, 0);
	} else if (which == 1) {
		switch (lang) {
		case 5:
			x = 0x38;
			break;
		case 6:
			x = 0x28;
			break;
		case 7:
			x = 0x32;
			break;
		case 14:
			x = 0x20;
			break;
		default:
			x = 0x5c;
			break;
		}
		gui_bmp_bitmap_draw(0x40, X0 + x, Y0 + 0x3a, 0, 0, 0);
		gui_utf_draw(0, get_string(0x55), 0, X0 + (int)x + 0x2c, Y0 + 0x36, X0 + 0x240,
			     Y0 + 0x88, 3, 0, 0, NULL, 0);
	}
}

int ui_translate_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct GlassesState *gs = get_dashboard_state();
	struct trans_info *ti = TRANS_INFO(gs);
	set_frame_buffer(panel->panel_buffer);
	set_showing_notification_on_gui();

	switch (trans_ui.state) {
	case 0:
		if (event == UI_EVT_ENTER) {
			if (trans_ui.entered) {
				return 0;
			}
			G1_LOG_INF("SYNC_AREA_REFALSH Upgrade ....\n");
			gui_utf_adv_draw_reset();
			gui_screen_clear();
			gui_text_state_reset();
			memset(&trans_ui.suspend_en, 0, 0x10);
			text_anim.f_1c = 0x80;
			text_anim.f_08 = 0;
			text_anim.f_0c = 0;
			text_anim.text = text_anim_buf;
			text_anim.f_14 = 0;
			text_anim.f_18 = 0;
			text_anim.f_04 = 0;
			text_anim.f_10 = 0;
			trans_ui.state = 1;
			trans_ui.entered = 1;
			gui_dynamic_bitmap_reset();
			clear_showing_notification_on_gui();

			/* fade in */
			for (int i = 0; i < 4; i++) {
				if (ti->original_type >= 26 || ti->translation_type == 0 || ti->translation_type >= 26 ||
	    ti->original_type == 0) {
					G1_LOG_ERR("translate language type error! "
						   "trans_info->original_type %d "
						   "trans_info->translation_type %d\n",
						   ti->original_type, ti->translation_type);
				} else {
					char pair[10];

					memset(pair, 0, sizeof(pair));
					snprintf(pair, sizeof(pair), "%s>%s",
						 trans_lang_name[ti->original_type - 1],
						 trans_lang_name[ti->translation_type - 1]);
					gui_utf_draw(0, pair, 3, X0, Y0 + 0x6e, X0 + 0x50, Y0 + 0x89, 1,
						     0, 0, NULL, 0);
					trans_ui.original_type = ti->original_type;
					trans_ui.translation_type = ti->translation_type;
				}
				bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

				gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x50, Y0 + 0x1d, 3,
					       is_24h);
				for (unsigned int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = { 1, 3, 5, 7, 7, 7, 7, 7 };

						if (panel->panel_buffer[row][col] != 0) {
							panel->panel_buffer[row][col] &=
								gui_fade_mask[row % 26][steps[i]][col];
						}
					}
				}
				_reflash_fb_data_to_lcd(UI_PANEL(get_dashboard_state())->current_row,
							UI_PANEL(get_dashboard_state())->current_column,
							0, 0, GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
			return 0;
		}
		if (event != UI_EVT_EXIT) {
			return 0;
		}
		G1_LOG_INF("translate process received exit packet ...\n");
		gui_screen_clear();
		goto exit;
	case 1:
		break;
	default:
		return 0;
	}

	uint8_t mode = ti->mode;

	if (mode == 5) {
		if (event == UI_EVT_ENTER) {
			if (trans_mode == 5) {
				return 0;
			}
			trans_mode = mode;
			translate_draw_hint_page(0);
			return 0;
		}
	} else if (mode == 6) {
		if (event == UI_EVT_ENTER) {
			if (trans_mode == 6) {
				return 0;
			}
			trans_mode = mode;
			translate_draw_hint_page(1);
			return 0;
		}
	} else if ((unsigned int)event <= UI_EVT_ENTER) {
		if (trans_mode == 5 || trans_mode == 6) {
			trans_mode = mode;
			gui_screen_clear();
		}
		if (event == UI_EVT_ENTER) {
			memset(trans_text, 0, sizeof(trans_text));
			k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
			trans_ui.suspend_en = ti->suspend_en;
			trans_mode = ti->mode;
			memcpy(trans_text, ti->text, sizeof(trans_text));
			k_mutex_unlock(&k_mutex_2000851c);

			if (trans_ui.suspend_en == 1) {
				G1_LOG_INF("suspend_en is 1, reflash suspend icon\n");
				gui_bmp_bitmap_draw(0x1b, X0, Y0 + 0x36, 0, 0, 0);
			}

			if (ti->original_type >= 26 || ti->translation_type == 0 || ti->translation_type >= 26 ||
	    ti->original_type == 0) {
				G1_LOG_ERR("translate language type error! "
					   "trans_info->original_type %d "
					   "trans_info->translation_type %d\n",
					   ti->original_type, ti->translation_type);
			} else {
				if (trans_ui.original_type != ti->original_type ||
				    trans_ui.translation_type != ti->translation_type) {
					char pair[10] = { 0 };

					snprintf(pair, sizeof(pair), "%s>%s",
						 trans_lang_name[ti->original_type - 1],
						 trans_lang_name[ti->translation_type - 1]);
					G1_LOG_DBG("draw translate type content\n");
					gui_utf_draw(0, pair, 3, X0, Y0 + 0x6e, X0 + 0x50, Y0 + 0x89, 1,
						     0, 0, NULL, 0);
					trans_ui.original_type = ti->original_type;
					trans_ui.translation_type = ti->translation_type;
				}
			}

			if (trans_mode == 3 || trans_mode == 4) {
				gs = get_dashboard_state();
				uint8_t **fb = UI_PANEL(gs)->panel_buffer;

				/* fade the old text out */
				for (int step = 5; step >= 4; step--) {
					for (int row = Y0; row <= Y0 + 0x87; row++) {
						for (int col = X0 + 0x58; col < (X0 + 0x240) / 2;
						     col++) {
							if (fb[row][col] != 0) {
								fb[row][col] &=
									gui_fade_mask[row % 26][step][col];
							}
						}
					}
					_reflash_fb_data_to_lcd(
						UI_PANEL(get_dashboard_state())->current_row,
						UI_PANEL(get_dashboard_state())->current_column,
						X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88);
				}
				_clean_fb_data(fb, 0, X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88);
				if (!trans_ui.suspend_en) {
					gui_bmp_dynamic_bitmap_draw(1, X0, Y0 + 0x36, 0, 0, 0, 0);
				}
				clear_showing_notification_on_gui();

				/* and the new one in */
				for (int i = 2; i < 4; i++) {
					gui_utf_draw(0, trans_text, 0, X0 + 0x58, Y0, X0 + 0x240,
						     Y0 + 0x88, 5, 0, 0, NULL, 0);

					int x0 = X0 + 0x58;
					int x1 = X0 + 0x240;
					int y0 = Y0;
					int y1 = Y0 + 0x88;
					int xs = x0 / 2;

					for (int r = 0; r < y1 - y0; r++) {
						for (int c = 0; c < (x1 - x0) / 2; c++) {
							const uint8_t steps[8] = { 1, 3, 5, 7,
										   7, 7, 7, 7 };
							uint8_t *line = fb[y0 + r] + xs;

							if (line[c] != 0) {
								line[c] &=
									gui_fade_mask[r % 26][steps[i]][c];
							}
						}
					}
					_reflash_fb_data_to_lcd(
						UI_PANEL(get_dashboard_state())->current_row,
						UI_PANEL(get_dashboard_state())->current_column, x0, y0,
						x1, y1);
				}
				set_showing_notification_on_gui();
			} else {
				gui_utf_draw(0, trans_text, 0, X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88, 5,
					     0, 0, NULL, 0);
			}
		}

		if (!trans_ui.suspend_en) {
			gui_bmp_dynamic_bitmap_draw(1, X0, Y0 + 0x36, 0, 0, 0, 0);
		}

		struct bp_date date = { 0 };

		init_burial_point_date(FUN_00080732(), &date);
		if (trans_ui.minute == date.minute && trans_ui.hour == date.hour) {
			return 0;
		}
		trans_ui.minute = date.minute;
		trans_ui.hour = date.hour;
		bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

		gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x50, Y0 + 0x1d, 3, is_24h);
		return 0;
	}

	if (event != UI_EVT_EXIT) {
		return 0;
	}
	G1_LOG_INF("translate process received exit packet ...\n");
	gui_screen_fade_out();
exit:
	gui_utf_adv_draw_reset();
	text_anim.f_08 = 0;
	text_anim.f_0c = 0;
	text_anim.f_14 = 0;
	text_anim.f_18 = 0;
	text_anim.f_04 = 0;
	text_anim.f_10 = 0;
	memset(&trans_ui, 0, sizeof(trans_ui));
	return 0;
}

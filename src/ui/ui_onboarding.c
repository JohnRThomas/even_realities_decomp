/*
 * UI page: onboarding (first-use tutorial, driven by the phone app).
 */
#include "ui_b.h"

static uint8_t page_redraw;             /* page needs a redraw */
static uint8_t anim_drawn;             /* animated part already drawn */
static uint8_t step_finished;             /* step finished */
static uint8_t headup_hint_count;             /* repeat counter of the head-up hint */
uint8_t DAT_2001db41;
uint8_t DAT_2001db40;                    /* sub step on screen */

static int8_t last_action = -1;          /* 0x20003697 */
uint8_t onboarding_languages[5] = { 2, 6, 5, 7, 14 }; /* onboarding languages */

static struct {
	volatile uint8_t timeout_cnt;    /* 0x00 */
	volatile int64_t ts;             /* 0x08 */
	uint8_t imu_mode;                /* 0x10 */
} onboarding_prv;                        /* 0x20004da8 */

static int fade_step;                    /* 0x2000a9d4 */

int FUN_0004280c(void)
{
	memset(get_dashboard_state()->ptr_101c, 0, sizeof(struct onboarding_ctx));
	page_redraw = 1;
	return 0;
}

void FUN_00042830(void)
{
	if (last_action != ONB()->action ||
	    (ONB()->action != 5 && ONB()->action != 0x13 && ONB()->action != 0x14 &&
	     ONB()->action != 0x15)) {
		anim_drawn = 0;
		step_finished = 0;
	}
	page_redraw = 1;
	last_action = ONB()->action;
}

/* fade the whole frame buffer in (one step per call, see fade_step) */
#define ONB_FADE_FRAME(gs)                                                                 \
	do {                                                                               \
		for (unsigned int row = 0; row < 199; row++) {                             \
			for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {                 \
				const uint8_t steps[8] = { 1, 3, 5, 7, 7, 7, 7, 7 };       \
				uint8_t *line = UI_PANEL(gs)->panel_buffer[row];           \
                                                                                           \
				if (line[col] != 0) {                                      \
					line[col] &= gui_fade_mask[row % 26][steps[fade_step]][col]; \
				}                                                          \
			}                                                                  \
		}                                                                          \
	} while (0)

#define ONB_REFLASH_FULL()                                                                 \
	_reflash_fb_data_to_lcd(UI_PANEL(get_dashboard_state())->current_row,              \
				UI_PANEL(get_dashboard_state())->current_column, 0, 0,     \
				GUI_SCREEN_WIDTH, 199)

void onboarding_draw_static_page(int event)
{
	struct GlassesState *gs = get_dashboard_state();

	if (!page_redraw) {
		return;
	}
	page_redraw = 0;
	gui_screen_clear();

	if (ONB()->action != 0 && ONB()->action != 10 && ONB()->action != 11 &&
	    ONB()->action != 5 && ONB()->action != 6 && ONB()->action != 0x13 &&
	    ONB()->action != 0x14 && ONB()->action != 0x15 && ONB()->action != 0xe &&
	    ONB()->action != 0xf && ONB()->action != 0x10 && ONB()->action != 0x11 &&
	    (ONB()->action != 3 || DAT_2001db40 != 2)) {
		gui_utf_draw(0, ONB()->step_str, 3, X0, Y0 + 0x37, X0 + 0x28, Y0 + 0x52, 4, 0, 0,
			     NULL, 0);
	}

	switch (ONB()->action) {
	case 0:
		clear_showing_notification_on_gui();
		for (fade_step = 0; fade_step < 8;) {
			gui_bmp_bitmap_draw(0x16, X0, Y0 + 0x38, 0, 0, 0);
			gui_utf_draw_middle(0,
					    get_string_in_language(
						    onboarding_languages[DAT_2001db40], 1),
					    0, X0 + 0x24, Y0 + 0x37, X0 + 0x21c, Y0 + 0x88, 4, 0, 0,
					    NULL, 0);
			ONB_FADE_FRAME(gs);
			fade_step++;
			ONB_REFLASH_FULL();
		}
		set_showing_notification_on_gui();
		break;
	case 1:
		gui_utf_draw(0, get_string(6), 0, X0 + 0x8c, Y0 + 0x37, X0 + 0x240, Y0 + 0x88, 4,
			     0, 0, NULL, 0);
		break;
	case 2:
		gui_utf_draw(0, get_string(0x20), 0, X0 + 0x80, Y0 + 0x37, X0 + 0x240, Y0 + 0x88,
			     4, 0, 0, NULL, 0);
		break;
	case 4:
		gui_utf_draw(0, get_string(7), 0, X0 + 0xd2, Y0 + 0x37, X0 + 0x240, Y0 + 0x52, 1,
			     0, 0, NULL, 0);
		gui_utf_draw(0, get_string(0x1f), 0, X0 + 0xae, Y0 + 0x6d, X0 + 0x240, Y0 + 0x88,
			     1, 0, 0, NULL, 0);
		break;
	case 3:
	case 5:
	case 0x14:
	case 0x15:
		if (DAT_2001db40 == 1) {
			if (ONB()->action == 3) {
				headup_hint_count = 0;
				gui_utf_draw(0, get_string(8), 0, X0 + 0x8c, Y0 + 0x37,
					     X0 + 0x240, Y0 + 0x88, 4, 0, 0, NULL, 0);
			} else if (ONB()->action == 0x15) {
				headup_hint_count = 0;
				if ((ONB()->flags & 3) == 1) {
					FUN_00029774(0x14);
					ONB()->flags |= 2;
					ONB()->action = 0x17;
				}
			}
		} else if (DAT_2001db40 == 2) {
			if (ONB()->action == 0x15 && !(ONB()->flags & 1)) {
				FUN_00029774(0x13);
				ONB()->flags |= 1;
			}
			if (step_finished) {
				anim_drawn = 0;
				break;
			}
			if (ONB()->action != 0x15 || onboarding_prv.imu_mode == 1) {
				clear_showing_notification_on_gui();
			}
			for (fade_step = 0; fade_step < 8;) {
				gui_utf_draw(0, get_string(0x14), 3, X0, Y0, X0 + 0x76, Y0 + 0x1b, 1,
					     0, 0, NULL, 0);
				gui_utf_draw(0, "12:47", 1, X0, Y0 + 0x1b, X0 + 0x68, Y0 + 0x42, 1,
					     0, 0, NULL, 0);
				gui_bmp_bitmap_draw(0x29, X0 + 0xa6, Y0 + 4, 0, 0, 0);
				gui_utf_draw(0, "25", 3, X0 + 0xc2, Y0 + 3, X0 + 0xea, Y0 + 0x1e, 1,
					     0, 0, NULL, 0);
				gui_utf_draw(0, "*", 3, X0 + 0xde, Y0 + 3, X0 + 0xec, Y0 + 0x1e, 1,
					     0, 0, NULL, 0);
				gui_bmp_bitmap_draw(0x3c, X0 + 0xa6, Y0 + 0x23, 0, 0, 0);

				const char *cnt;

				if (ONB()->action == 5) {
					cnt = "1";
				} else if (ONB()->action == 3) {
					cnt = "3";
				} else {
					cnt = "0";
				}
				gui_utf_draw(0, cnt, 3, X0 + 0xc2, Y0 + 0x23, X0 + 0xd6, Y0 + 0x3e, 1,
					     0, 0, NULL, 0);
				gui_bmp_bitmap_draw(0x39, X0, Y0 + 0x51, 0, 0, 0);
				gui_utf_draw(0, get_string(0x16), 0, X0 + 0x1c, Y0 + 0x51, X0 + 0xf2,
					     Y0 + 0x6c, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, get_string(0x15), 0, X0, Y0 + 0x6d, X0 + 0xf2,
					     Y0 + 0x88, 1, 0, 0, NULL, 0);
				gui_bmp_bitmap_draw(0x3b, X0 + 0x108, Y0 + 1, 0, 0, 0);
				gui_utf_draw(0, get_string(0x17), 0, X0 + 0x126, Y0, X0 + 0x202,
					     Y0 + 0x1b, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, ONB()->action == 0x15 ? "2/2" : "1/2", 3, X0 + 0x210,
					     Y0 + 1, X0 + 0x234, Y0 + 0x1c, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, get_string(ONB()->action == 0x15 ? 0xe : 0x18), 0,
					     X0 + 0x108, Y0 + 0x1b, X0 + 0x232, Y0 + 0x87, 4, 0, 0,
					     NULL, 0);
				gui_bmp_bitmap_draw(0x59, X0 + 0xfc, Y0, 0, 0, 0);
				gui_bmp_bitmap_draw(0x5a, X0 + 0x23e, Y0, 0, 0, 0);
				if (ONB()->action == 0x15 && onboarding_prv.imu_mode != 1) {
					break;
				}
				ONB_FADE_FRAME(gs);
				fade_step++;
				ONB_REFLASH_FULL();
			}
			set_showing_notification_on_gui();
		}
		break;
	case 6:
	case 0x13:
		if (DAT_2001db40 == 1) {
			if (ONB()->action == 6) {
				gui_bmp_bitmap_draw(0x38, X0, Y0 + 0x37, 0, 0, 0);
				if ((ONB()->flags & 0xc) == 4) {
					FUN_00029774(0x16);
					ONB()->flags |= 8;
					ONB()->action = 5;
				}
			} else if (ONB()->action == 0x13) {
				gui_utf_draw(0, get_string(0x22), 0, X0 + 0xa6, Y0 + 0x6d,
					     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
			}
		} else if (DAT_2001db40 == 2) {
			if (ONB()->action == 6) {
				if (!(ONB()->flags & 4)) {
					FUN_00029774(0x15);
					ONB()->flags |= 4;
				}
			} else if (ONB()->action == 0x13 && step_finished) {
				anim_drawn = 0;
				break;
			}
			clear_showing_notification_on_gui();
			for (fade_step = 0; fade_step < 8;) {
				gui_bmp_bitmap_draw(0x3c, X0 + 0x212, Y0 + 4, 0, 0, 0);
				gui_utf_draw(0, ONB()->action == 6 ? "1" : "0", 3, X0 + 0x22e, Y0 + 3,
					     X0 + 0x23e, Y0 + 0x1e, 1, 0, 0, NULL, 0);
				gui_bmp_bitmap_draw(0x38, X0, Y0 + 4, 0, 0, 0);
				gui_utf_draw(0, get_string(0x1a), 0, X0 + 0x24, Y0 + 3, X0 + 0x150,
					     Y0 + 0x1e, 1, 0, 0, NULL, 0);
				gui_utf_draw(0, get_string(ONB()->action == 6 ? 0x1c : 0xc), 0, X0,
					     Y0 + 0x37, X0 + 0x240, Y0 + 0x6d, 2, 0, 0, NULL, 0);
				ONB_FADE_FRAME(gs);
				fade_step++;
				ONB_REFLASH_FULL();
			}
			set_showing_notification_on_gui();
		}
		break;
	case 0x16:
		gui_utf_draw(0, get_string(0x11), 0, X0 + 0x6a, Y0 + 0x37, X0 + 0x240, Y0 + 0x88,
			     4, 0, 0, NULL, 0);
		break;
	case 0x17:
		if (get_current_language() == 6) {
			gui_utf_draw(0, get_string(0x12), 0, X0 + 0x48, Y0 + 0x37, X0 + 0x240,
				     Y0 + 0x88, 4, 0, 0, NULL, 0);
		} else {
			gui_utf_draw(0, get_string(0x12), 0, X0 + 0x88, Y0 + 0x37, X0 + 0x240,
				     Y0 + 0x88, 4, 0, 0, NULL, 0);
		}
		break;

	case 8:
		if (get_current_language() == 6) {
			gui_utf_draw(0, get_string(7), 0, X0 + 0xc6, Y0 + 0x37, X0 + 0x240,
				     Y0 + 0x52, 1, 0, 0, NULL, 0);
			gui_utf_draw(0, get_string(0x1f), 0, X0 + 0xac, Y0 + 0x6d, X0 + 0x240,
				     Y0 + 0x88, 1, 0, 0, NULL, 0);
		} else {
			gui_utf_draw(0, get_string(7), 0, X0 + 0xd2, Y0 + 0x37, X0 + 0x240,
				     Y0 + 0x52, 1, 0, 0, NULL, 0);
			gui_utf_draw(0, get_string(0x1f), 0, X0 + 0x8a, Y0 + 0x6d, X0 + 0x240,
				     Y0 + 0x88, 1, 0, 0, NULL, 0);
		}
		break;
	case 7:
	case 9:
	case 0xc:
	case 0xd:
		gui_utf_draw(0, get_string(0x21), 0, X0 + 0x72, Y0 + 0x37, X0 + 0x240, Y0 + 0x88,
			     4, 0, 0, NULL, 0);
		break;
	case 0xe:
	case 0xf:
		gui_bmp_bitmap_draw(0x36, X0, Y0 + 0x37, 0, 0, 0);
		if (ONB()->action != 0xf || DAT_2001db40 != 1) {
			gui_utf_draw_middle(0, get_string(0x23), 0, X0, Y0 + 0x37, X0 + 0x240,
					    Y0 + 0x88, 4, 0, 0, NULL, 0);
		}
		break;
	case 0x10:
	case 0x11:
		if (ONB()->action != 0x11 || DAT_2001db40 != 1) {
			gui_bmp_bitmap_draw(0x3c, X0 + 0x212, Y0 + 4, 0, 0, 0);
			gui_utf_draw(0, "1", 3, X0 + 0x22e, Y0 + 3, X0 + 0x23e, Y0 + 0x1e, 1, 1, 0,
				     NULL, 0);
			gui_bmp_bitmap_draw(0x38, X0, Y0 + 4, 0, 0, 0);
			gui_utf_draw(0, get_string(0x1a), 0, X0 + 0x24, Y0 + 3, X0 + 0x150,
				     Y0 + 0x1e, 1, 0, 0, NULL, 0);
			gui_utf_draw(0, get_string(0x1c), 0, X0, Y0 + 0x37, X0 + 0x240, Y0 + 0x6d,
				     2, 0, 0, NULL, 0);
		} else {
			gui_bmp_bitmap_draw(0x38, X0, Y0 + 0x37, 0, 0, 0);
		}
		break;
	default:
		break;
	}
	onboarding_prv.imu_mode = get_dashboard_state()->imu.mode;
}


void onboarding_draw_animated_page(int event)
{
	uint8_t buf[0x400] = { 0 };
	uint8_t shown;

	switch (ONB()->action) {
	case 0:
		if (k_uptime_get() - ONB()->ts > 4000) {
			ONB()->sub_step++;
			if (ONB()->sub_step >= 5) {
				ONB()->sub_step = 0;
			}
		}
		break;
	case 3:
		ONB()->sub_step = get_dashboard_state()->imu.mode;
		if (headup_hint_count > 5) {
			break;
		}
		if (headup_hint_count == 0 || k_uptime_get() - ONB()->ts > 1000) {
			headup_hint_count++;
			FUN_00029774(0x10);
			ONB()->ts = k_uptime_get();
		}
		break;
	default:
		break;
	case 4:
		gui_bmp_dynamic_bitmap_draw(0xc, X0 + 0x8a, Y0 + 0x70, 0, 0, 0, 0);
		break;
	case 5:
	case 0x14:
	case 0x15:
		ONB()->sub_step = get_dashboard_state()->imu.mode;
		if (DAT_2001db40 == 1) {
			if (ONB()->action == 5 && !step_finished &&
			    k_uptime_get() - ONB()->ts < 500) {
				break;
			}
			if (get_current_language() == 6) {
				gui_bmp_dynamic_bitmap_draw(2, X0 + 0x42, Y0 + 0x70, 0, 0, 0, 0);
				gui_utf_draw(0, get_string(0x13), 0, X0 + 0x66, Y0 + 0x6d, X0 + 0x240,
					     Y0 + 0x88, 1, 0, 0, NULL, 0);
			} else {
				gui_bmp_dynamic_bitmap_draw(2, X0 + 0x82, Y0 + 0x70, 0, 0, 0, 0);
				gui_utf_draw(0, get_string(0x13), 0, X0 + 0xa6, Y0 + 0x6d, X0 + 0x240,
					     Y0 + 0x88, 1, 0, 0, NULL, 0);
			}
			break;
		}
		if (DAT_2001db40 != 2) {
			break;
		}
		if (k_uptime_get() - ONB()->ts > 2000 || step_finished) {
			if (!anim_drawn) {
				anim_drawn = 1;
				gui_utf_draw(0, get_string(0x14), 3, X0, Y0, X0 + 0x76, Y0 + 0x1b, 1,
					     strlen(get_string(0x14)), 0, NULL, 0);
				gui_utf_draw(0, "12:47", 1, X0, Y0 + 0x1b, X0 + 0x68, Y0 + 0x42, 1, 5,
					     0, NULL, 0);
				gui_bmp_bitmap_draw_ex(0x29, X0 + 0xa6, Y0 + 4, buf, 0x55);
				gui_utf_draw(0, "25", 3, X0 + 0xc2, Y0 + 3, X0 + 0xea, Y0 + 0x1e, 1, 2,
					     0, NULL, 0);
				gui_utf_draw(0, "*", 3, X0 + 0xde, Y0 + 3, X0 + 0xec, Y0 + 0x1e, 1, 1,
					     0, NULL, 0);

				if (ONB()->action == 5) {
					gui_bmp_bitmap_draw(0x3c, X0 + 0xa6, Y0 + 0x23, 0, 0, 0);
					gui_utf_draw(0, "1", 3, X0 + 0xc2, Y0 + 0x23, X0 + 0xd6,
						     Y0 + 0x3e, 1, 0, 0, NULL, 0);
				} else {
					gui_bmp_bitmap_draw_ex(0x3c, X0 + 0xa6, Y0 + 0x23, buf, 0x55);
					gui_utf_draw(0, "0", 3, X0 + 0xc2, Y0 + 0x23, X0 + 0xd6,
						     Y0 + 0x3e, 1, 1, 0, NULL, 0);
				}
				gui_bmp_bitmap_draw_ex(0x39, X0, Y0 + 0x51, buf, 0x55);
				gui_utf_draw(0, get_string(0x16), 0, X0 + 0x1c, Y0 + 0x51, X0 + 0xf2,
					     Y0 + 0x6c, 1, strlen(get_string(0x16)), 0, NULL, 0);
				gui_utf_draw(0, get_string(0x15), 0, X0, Y0 + 0x6d, X0 + 0xf2,
					     Y0 + 0x88, 1, strlen(get_string(0x15)), 0, NULL, 0);
				if (ONB()->action == 0x14) {
					gui_bmp_bitmap_draw(0x3b, X0 + 0x108, Y0 + 1, 0, 0, 0);
					gui_utf_draw(0, get_string(0x17), 0, X0 + 0x126, Y0,
						     X0 + 0x202, Y0 + 0x1b, 1, 0, 0, NULL, 0);
					gui_utf_draw(0, "1/2", 3, X0 + 0x210, Y0 + 1, X0 + 0x234,
						     Y0 + 0x1c, 1, 0, 0, NULL, 0);
				} else {
					gui_bmp_bitmap_draw_ex(0x3b, X0 + 0x108, Y0 + 1, buf, 0x55);
					gui_utf_draw(0, get_string(0x17), 0, X0 + 0x126, Y0,
						     X0 + 0x202, Y0 + 0x1b, 1,
						     strlen(get_string(0x17)), 0, NULL, 0);
					gui_utf_draw(0, ONB()->action == 0x15 ? "2/2" : "1/2", 3,
						     X0 + 0x210, Y0 + 1, X0 + 0x234, Y0 + 0x1c, 1, 3,
						     0, NULL, 0);
				}
				gui_utf_draw(0, get_string(ONB()->action == 0x15 ? 0xe : 0x18), 0,
					     X0 + 0x108, Y0 + 0x1b, X0 + 0x232, Y0 + 0x87, 4,
					     strlen(get_string(ONB()->action == 0x15 ? 0xe : 0x18)), 0,
					     NULL, 0);
				gui_bmp_bitmap_draw_ex(0x59, X0 + 0xfc, Y0, buf, 0x55);
				gui_bmp_bitmap_draw_ex(0x5a, X0 + 0x23e, Y0, buf, 0x55);
				gui_utf_draw(0, " ", 0, X0, Y0 + 0x6d, X0 + 0x240, Y0 + 0x88, 1, 0, 0,
					     NULL, 0);
				if (ONB()->action == 5) {
					if (get_current_language() == 6) {
						gui_utf_draw(0, get_string(9), 0, X0 + 0x5c, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
						gui_bmp_bitmap_draw(0x85, X0 + 0xae, Y0 + 0x87, 0, 0, 0);
					} else {
						gui_utf_draw(0, get_string(9), 0, X0 + 0x6a, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
						gui_bmp_bitmap_draw(0x85, X0 + 0xca, Y0 + 0x87, 0, 0, 0);
					}
				} else if (ONB()->action == 0x14) {
					gui_utf_draw(0, get_string(0xb), 0, X0 + 0x54, Y0 + 0x6d,
						     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
					if (get_current_language() == 6) {
						gui_bmp_bitmap_draw(0x86, X0 + 0xaa, Y0 + 0x87, 0, 0, 0);
					} else {
						gui_bmp_bitmap_draw(0x86, X0 + 0xb2, Y0 + 0x87, 0, 0, 0);
					}
				} else if (ONB()->action == 0x15) {
					if (get_current_language() == 6) {
						gui_utf_draw(0, get_string(0xf), 0, X0 + 100, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
					} else {
						gui_utf_draw(0, get_string(0xf), 0, X0 + 0x92, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
					}
				}
			}
			if (ONB()->action == 5) {
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(0xb, X0 + 0x38, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(0xb, X0 + 0x46, Y0 + 0x70, 0, 0, 0, 0);
				}
			} else if (ONB()->action == 0x14) {
				gui_bmp_dynamic_bitmap_draw(0xb, X0 + 0x30, Y0 + 0x70, 0, 0, 0, 0);
			} else if (ONB()->action == 0x15) {
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(3, X0 + 0x40, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(3, X0 + 0x6e, Y0 + 0x70, 0, 0, 0, 0);
				}
			}
		}
		if (ONB()->sub_step == 1) {
			step_finished = 1;
		}
		break;
	case 6:
	case 0x13:
		ONB()->sub_step = get_dashboard_state()->imu.mode;
		shown = DAT_2001db40;
		if (shown == 1) {
			if (ONB()->action == 6) {
				if (k_uptime_get() - ONB()->ts <= 2000) {
					break;
				}
				if (!anim_drawn) {
					anim_drawn = shown;
					gui_dynamic_bitmap_reset();
					gui_bmp_bitmap_draw_ex(0x38, X0, Y0 + 0x37, buf, 0x55);
					if (get_current_language() == 6) {
						gui_utf_draw(0, get_string(0x19), 0, X0 + 0x34,
							     Y0 + 0x6d, X0 + 0x240, Y0 + 0x88, 1, 0, 0,
							     NULL, 0);
					} else {
						gui_utf_draw(0, get_string(0x19), 0, X0 + 0x8c,
							     Y0 + 0x6d, X0 + 0x240, Y0 + 0x88, 1, 0, 0,
							     NULL, 0);
					}
				}
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(2, X0 + 0x10, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(2, X0 + 0x68, Y0 + 0x70, 0, 0, 0, 0);
				}
			} else if (ONB()->action == 0x13) {
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(2, X0 + 0x74, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(2, X0 + 0x82, Y0 + 0x70, 0, 0, 0, 0);
				}
			}
			break;
		}
		if (shown != 2) {
			break;
		}
		if (k_uptime_get() - ONB()->ts > 2000 || step_finished) {
			if (!anim_drawn) {
				anim_drawn = 1;
				if (!(ONB()->flags & 4)) {
					FUN_00029774(0x15);
					ONB()->flags |= 4;
				}
				if (ONB()->action == 6) {
					gui_bmp_bitmap_draw_ex(0x3c, X0 + 0x212, Y0 + 4, buf, 0x55);
					gui_utf_draw(0, "1", 3, X0 + 0x22e, Y0 + 3, X0 + 0x23e,
						     Y0 + 0x1e, 1, 1, 0, NULL, 0);
				} else if (ONB()->action == 0x13) {
					gui_bmp_bitmap_draw(0x3c, X0 + 0x212, Y0 + 4, 0, 0, 0);
					gui_utf_draw(0, "0", 3, X0 + 0x22e, Y0 + 3, X0 + 0x23e,
						     Y0 + 0x1e, 1, 0, 0, NULL, 0);
				}
				gui_bmp_bitmap_draw_ex(0x38, X0, Y0 + 4, buf, 0x55);
				gui_utf_draw(0, get_string(0x1a), 0, X0 + 0x24, Y0 + 3, X0 + 0x150,
					     Y0 + 0x1e, 1, strlen(get_string(0x1a)), 0, NULL, 0);
				if (ONB()->action == 6) {
					gui_utf_draw(0, get_string(0x1c), 0, X0, Y0 + 0x37, X0 + 0x240,
						     Y0 + 0x6d, 2, strlen(get_string(0x1c)), 0, NULL,
						     0);
				} else if (ONB()->action == 0x13) {
					gui_utf_draw(0, get_string(0xc), 0, X0, Y0 + 0x37, X0 + 0x240,
						     Y0 + 0x6d, 2, strlen(get_string(0xc)), 0, NULL, 0);
				}
				if (ONB()->action == 6) {
					if (get_current_language() == 6) {
						gui_utf_draw(0, get_string(0x10), 0, X0 + 0x34,
							     Y0 + 0x6d, X0 + 0x240, Y0 + 0x88, 1, 0, 0,
							     NULL, 0);
					} else {
						gui_utf_draw(0, get_string(0x10), 0, X0 + 0x72,
							     Y0 + 0x6d, X0 + 0x240, Y0 + 0x88, 1, 0, 0,
							     NULL, 0);
					}
				} else if (ONB()->action == 0x13) {
					if (get_current_language() == 6) {
						gui_utf_draw(0, get_string(10), 0, X0 + 0x8a, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
						gui_bmp_bitmap_draw(0x85, X0 + 0xdc, Y0 + 0x87, 0, 0, 0);
					} else {
						gui_utf_draw(0, get_string(10), 0, X0 + 0x94, Y0 + 0x6d,
							     X0 + 0x240, Y0 + 0x88, 1, 0, 0, NULL, 0);
						gui_bmp_bitmap_draw(0x85, X0 + 0xf4, Y0 + 0x87, 0, 0, 0);
					}
				}
			}
			if (ONB()->action == 6) {
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(3, X0 + 0x10, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(3, X0 + 0x4e, Y0 + 0x70, 0, 0, 0, 0);
				}
			} else if (ONB()->action == 0x13) {
				if (get_current_language() == 6) {
					gui_bmp_dynamic_bitmap_draw(0xb, X0 + 0x66, Y0 + 0x70, 0, 0, 0, 0);
				} else {
					gui_bmp_dynamic_bitmap_draw(0xb, X0 + 0x70, Y0 + 0x70, 0, 0, 0, 0);
				}
			}
		}
		if (ONB()->sub_step == 1) {
			step_finished = 1;
		}
		break;
	case 0x16:
		if (k_uptime_get() - ONB()->ts > 4000) {
			ONB()->action = 5;
		}
		break;
	case 0x17:
		if (headup_hint_count > 5) {
			break;
		}
		if (headup_hint_count == 0 || k_uptime_get() - ONB()->ts > 1000) {
			headup_hint_count++;
			FUN_00029774(0x14);
			ONB()->ts = k_uptime_get();
		}
		break;
	case 8:
		if (get_current_language() == 6) {
			gui_bmp_dynamic_bitmap_draw(0xc, X0 + 0x88, Y0 + 0x70, 0, 0, 0, 0);
		} else {
			gui_bmp_dynamic_bitmap_draw(0xc, X0 + 0x66, Y0 + 0x70, 0, 0, 0, 0);
		}
		break;
	case 0xf:
	case 0x11:
		ONB()->sub_step = get_dashboard_state()->imu.mode;
		break;
	}
}


void FUN_00044b24(void)
{
	if ((ONB()->action == 5 || ONB()->action == 0x13 || ONB()->action == 0x14 ||
	     ONB()->action == 0x15) &&
	    DAT_2001db40 == 2 && ONB()->sub_step == 1) {
		step_finished = 1;
	}
}

int ui_onboarding_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct GlassesState *gs = get_dashboard_state();

	set_frame_buffer(panel->panel_buffer);
	set_showing_notification_on_gui();

	if (event == UI_EVT_EXIT || gs->buf_0ef[2] > 0x17) {
		ONB()->active = 0;
		UI_PANEL_BRIGHTNESS(get_dashboard_state()) = ONB()->saved_brightness;
		gui_screen_clear();
		return 0;
	}

	if (event == UI_EVT_ENTER && get_dashboard_state()->is_master == 1) {
		send_response_data_to_ble();
	}

	if (get_dashboard_state()->is_master == 1 && ONB()->action != 0 &&
	    abs_diff_u64(k_uptime_get(), onboarding_prv.ts) > 1000) {
		onboarding_prv.timeout_cnt++;
		onboarding_prv.ts = k_uptime_get();
		if (onboarding_prv.timeout_cnt >= 20) {
			G1_LOG_WRN("onboarding: disconnection between the AR Glasses and the Bluetooth application!\n");
			onboarding_prv.timeout_cnt = 20;
			ONB()->action = 0xb;

			uint8_t data[3] = { ONB()->action, 0, 0 };

			if (onboarding_sync_data(data, 3) == 0) {
				ONB()->active = 0;
				ONB()->f_01 = 0;
			}
			return 0;
		}
	}

	if (ONB()->action != last_action || ONB()->sub_step != DAT_2001db40) {
		if (get_dashboard_state()->is_master == 1) {
			FUN_00044b24();
			DAT_2001db40 = ONB()->sub_step;

			uint8_t data[3] = { ONB()->action, DAT_2001db40, ONB()->f_0c };

			if (ONB()->action != 10 && ONB()->action != 11) {
				G1_LOG_INF("SYNC onboarding action_cmd %d and sub_step %d to slave\n",
					   ONB()->action, ONB()->sub_step);
				onboarding_sync_data(data, 3);
			}
			thunk_FUN_00045444();
			FUN_00042830();
			ONB()->ts = k_uptime_get();
			get_dashboard_state()->esb_down_id = ONB()->sub_step;
		}
	} else {
		onboarding_draw_static_page(event);
		onboarding_draw_animated_page(event);
	}
	return 0;
}

int onboarding_ble_process(struct GlassesState *gs, const struct ui_ble_req_hdr *hdr,
			   const uint8_t *req, uint8_t *rsp)
{
	int rsp_len;

	if (req[1] > 0x17) {
		G1_LOG_ERR("ble rcv unknown onboarding action:%d\n", req[1]);
		memcpy(rsp, req, 2);
		rsp[2] = 0xca;
		return 3;
	}

	onboarding_prv.timeout_cnt = 0;
	onboarding_prv.ts = k_uptime_get();

	if (req[1] != 0x12) {
		FUN_00042830();
		ONB_CTX(gs)->active = 1;
		ONB_CTX(gs)->ts = k_uptime_get();
		ONB_CTX(gs)->action = req[1];
		G1_LOG_INF("ble rcv onboarding action:%d\n", ONB_CTX(gs)->action);

		switch (ONB_CTX(gs)->action) {
		case 1:
			ONB_CTX(gs)->f_01 = 1;
			memcpy(ONB_CTX(gs)->step_str, "1/6", 4);
			break;
		case 2:
			memcpy(ONB_CTX(gs)->step_str, "6/6", 4);
			break;
		case 3:
			memcpy(ONB_CTX(gs)->step_str, "4/6", 4);
			DAT_2001db41 = 0;
			DAT_2001db40 = 0;
			ONB_CTX(gs)->sub_step = 0;
			ONB_CTX(gs)->f_0d = 0;
			ONB_CTX(gs)->f_0e = 0;
			ONB_CTX(gs)->f_0f = 0;
			ONB_CTX(gs)->f_13 = 0;
			ONB_CTX(gs)->f_17 = 0;
			ONB_CTX(gs)->f_0c = 0;
			break;
		case 4:
		case 5:
		case 6:
			memcpy(ONB_CTX(gs)->step_str, "3/6", 4);
			anim_drawn = 0;
			DAT_2001db40 = 0;
			ONB_CTX(gs)->sub_step = get_dashboard_state()->imu.mode;
			if (ONB_CTX(gs)->action == 6) {
				ONB_CTX(gs)->flags = 0;
			}
			break;
		case 7:
			memcpy(ONB_CTX(gs)->step_str, "5/6", 4);
			break;
		case 8:
		case 9:
			memcpy(ONB_CTX(gs)->step_str, "3/6", 4);
			break;
		case 10:
		case 11:
			ONB_CTX(gs)->active = 0;
			ONB_CTX(gs)->f_01 = 0;
			break;
		case 12:
			ONB_CTX(gs)->f_01 = 1;
			memcpy(ONB_CTX(gs)->step_str, "2/6", 4);
			break;
		case 15:
		case 17:
			ONB()->sub_step = get_dashboard_state()->imu.mode;
			break;
		default:
			break;
		}
		thunk_FUN_00045444();
	}

	if (hdr->len == 2) {
		memcpy(rsp, req, 2);
		rsp[2] = 0xc9;
		rsp_len = 3;
	} else if (hdr->len == 3) {
		memcpy(rsp, req, 2);
		rsp[2] = 0xc9;
		rsp[3] = req[2];
		if (ONB_CTX(gs)->active) {
			gs->esb_down_id = rsp[3];
			rsp_len = 4;
		} else {
			rsp_len = 4;
		}
	} else {
		rsp_len = 0;
	}

	if (req[1] != 0x12 && get_dashboard_state()->glasses_state->state != 0xe && !is_in_box()) {
		update_persist_task_status(get_dashboard_state(), 0xe, 2);
		ONB()->saved_brightness = UI_PANEL_BRIGHTNESS(get_dashboard_state());
		UI_PANEL_BRIGHTNESS(get_dashboard_state()) = 0x2a;
	}
	return rsp_len;
}

int onboarding_sync_data(const uint8_t *data, uint32_t len)
{
	if (data == NULL) {
		return -1;
	}
	if (get_dashboard_state()->is_master == 1) {
		uint8_t buf[4] = {4};

		if (len > 3) {
			len = 3;
		}
		if (len) {
			memcpy(&buf[1], data, len);
		}
		if (sync_to_slave(get_dashboard_state(), 6, buf, (uint8_t)(len + 1)) >= 5000) {
			G1_LOG_ERR("onboarding sync to Slave failed...\n");
			return -1;
		}
	} else {
		uint8_t buf[2] = {4};

		if (len) {
			len = 1;
			buf[1] = data[0];
		}
		if ((unsigned int)FUN_000294d0(get_dashboard_state(), 0xe, buf, (uint8_t)(len + 1)) >=
		    2000) {
			G1_LOG_ERR("onboarding sync to master failed...\n");
			return -1;
		}
	}
	return 0;
}

void FUN_00080992(void)
{
	if (ONB()->active) {
		ONB()->active = 0;
	}
}

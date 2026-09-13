/*
 * UI page: transcribe information (clock, animated icon, transcribed text).
 */
#include <string.h>
#include <zephyr/kernel.h>

#include "gui.h"

static struct {
	uint8_t state;
	uint8_t entered;
	uint8_t timeout_cnt;
	int64_t ts;
} transcribe_ui;

/* reset the page's idle-timeout counter (ble_proto calls it on each new packet) */
void transcribe_info_timeout_reset(void)
{
	transcribe_ui.timeout_cnt = 0;
}
extern __typeof__(transcribe_info_timeout_reset) FUN_000496a4 __attribute__((alias("transcribe_info_timeout_reset")));

int transcribe_info_reflash(uint8_t **fb, int force)
{
	struct gui_glasses_state *gs = GUI_STATE();

	if (gs->show_clock == 1) {
		gui_clock_draw(FUN_00080732(), gui_screen_x_offset(), gui_screen_y_offset() + 2, gui_screen_x_offset() + 80,
			       gui_screen_y_offset() + 29, 3, GUI_STATE()->dashboard_ts->time_disp_mode != 1);
		if (gs->page_flags & 1) {
			gui_bmp_dynamic_bitmap_draw(1, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0, 0);
		} else {
			gui_dynamic_bitmap_reset();
			_clean_fb_data(fb, 0, gui_screen_x_offset(), gui_screen_y_offset() + 58, gui_screen_x_offset() + 20,
				       gui_screen_y_offset() + 84);
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, gui_screen_x_offset(),
						gui_screen_y_offset() + 58, gui_screen_x_offset() + 20,
						gui_screen_y_offset() + 84);
		}
	}
	if (transcribe_ui.state == 0 || force == 1) {
		gui_utf_draw_darkword_by_lines(0, gs->text, 0, gui_screen_x_offset() + 88, gui_screen_y_offset(),
					       gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 5,
					       gs->dark_cnt, 0, NULL, 0);
	}
	return 0;
}

int ui_transcribe_info_task(struct jbd_panel_context *ctx, void *arg, int event)
{
	get_dashboard_state();
	set_frame_buffer(ctx->panel_buffer);
	set_showing_notification_on_gui();

	switch (transcribe_ui.state) {
	case 0:
		if (event == 1) {
			if (transcribe_ui.entered) {
				return 0;
			}
			gui_utf_adv_draw_reset();
			gui_screen_clear();
			gui_text_state_reset();
			memset(&transcribe_ui, 0, sizeof(transcribe_ui));
			gui_dynamic_bitmap_reset();
			clear_showing_notification_on_gui();

			/* fade in */
			for (int i = 0; i < 8; i++) {
				transcribe_info_reflash(ctx->panel_buffer, 1);
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
			transcribe_ui.state = 1;
			transcribe_ui.entered = 1;
			transcribe_ui.ts = k_uptime_get();
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_clear();
			gui_utf_adv_draw_reset();
			memset(&transcribe_ui, 0, sizeof(transcribe_ui));
			FUN_00030458();
		}
		break;
	case 1:
		if (event == 1) {
			transcribe_info_reflash(ctx->panel_buffer, event);
		} else if (event == 0) {
			transcribe_info_reflash(ctx->panel_buffer, event);
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_fade_out();
			gui_utf_adv_draw_reset();
			memset(&transcribe_ui, 0, sizeof(transcribe_ui));
			FUN_00030458();
		}
		if (GUI_STATE()->is_master == 1 &&
		    abs_diff_u64(k_uptime_get(), transcribe_ui.ts) > 1000) {
			transcribe_ui.timeout_cnt++;
			transcribe_ui.ts = k_uptime_get();
			if (transcribe_ui.timeout_cnt >= 30) {
				*GUI_STATE()->multi_packet_buf = 0;
				FUN_00030458();
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

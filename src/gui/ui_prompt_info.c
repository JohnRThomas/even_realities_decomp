/*
 * UI page: prompt information.
 */
#include <string.h>
#include <zephyr/kernel.h>

#include "gui.h"

#define PROMPT_ACTION_MAX 2

static struct {
	uint8_t state;
	uint8_t entered;
} prompt_ui;

int prompt_info_reflash(void)
{
	uint8_t action = GUI_STATE()->ui_action;

	if (action > PROMPT_ACTION_MAX) {
		G1_LOG_ERR("prompt_info->action_cmd over E_PROMPT_ACTION_MAX\n");
		return -1;
	}

	switch (action) {
	case 1:
		gui_utf_draw_middle(0, get_string(0x42), 0, gui_screen_x_offset(), gui_screen_y_offset() + 55,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 3, 0, 0, NULL, 0);
		break;
	case 2:
		gui_utf_draw_middle(0, get_string(0x43), 0, gui_screen_x_offset(), gui_screen_y_offset() + 55,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 136, 3, 0, 0, NULL, 0);
		break;
	default:
		break;
	}
	return 0;
}

int ui_prompt_info_task(struct jbd_panel_context *ctx, void *arg, int event)
{
	get_dashboard_state();
	set_frame_buffer(ctx->panel_buffer);
	set_showing_notification_on_gui();

	switch (prompt_ui.state) {
	case 0:
		if (event == 1) {
			if (prompt_ui.entered) {
				return 0;
			}
			gui_utf_adv_draw_reset();
			gui_screen_clear();
			gui_text_state_reset();
			prompt_ui.state = 0;
			prompt_ui.entered = 1;
			int64_t now = k_uptime_get();

			GUI_STATE()->ts_info->enter_ts = now;
			gui_dynamic_bitmap_reset();
			prompt_ui.state = 1;
			clear_showing_notification_on_gui();

			/* fade in */
			for (int i = 0; i < 8; i++) {
				prompt_info_reflash();
				for (int row = 0; row < 199; row++) {
					for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
						const uint8_t steps[8] = { 1, 2, 3, 4, 5, 6, 7, 7 };
						uint8_t pix = ctx->panel_buffer[row][col];

						if (pix != 0) {
							ctx->panel_buffer[row][col] =
								pix & gui_fade_mask[row % 26][steps[i]][col];
						}
					}
				}
				_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
							GUI_STATE()->panel.current_column, 0, 0,
							GUI_SCREEN_WIDTH, 199);
			}
			set_showing_notification_on_gui();
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_clear();
			gui_utf_adv_draw_reset();
			memset(&prompt_ui, 0, sizeof(prompt_ui));
		}
		break;
	case 1:
		if (event == 1) {
			prompt_info_reflash();
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_fade_out();
			gui_utf_adv_draw_reset();
			memset(&prompt_ui, 0, sizeof(prompt_ui));
		}
		break;
	default:
		break;
	}
	return 0;
}

/*
 * UI page: IMU pitch (head-up angle) calibration.
 */
#include <string.h>
#include <zephyr/kernel.h>

#include "gui.h"

#define IMU_PITCH_STEP_MAX 2

static struct {
	uint8_t state;
	uint8_t entered;
	uint8_t last_step;
} imu_pitch_ui;

int set_imu_pitch_reflash(void)
{
	struct gui_glasses_state *gs = GUI_STATE();

	if (gs->ui_action >= IMU_PITCH_STEP_MAX) {
		G1_LOG_ERR("set_imu_pitch:horiz_step over E_IMU_PITCH_STEP_MAX\n");
		return -1;
	}

	if (imu_pitch_ui.last_step != gs->ui_action) {
		gui_screen_clear();
		imu_pitch_ui.last_step = gs->ui_action;
	}

	if (gs->ui_action != 1) {
		gui_bmp_bitmap_draw(0x87, gui_screen_x_offset() + 82, gui_screen_y_offset() + 101, 0, 0, 0);
		gui_utf_draw_middle(0, get_string(2), 0, gui_screen_x_offset(), gui_screen_y_offset() + 60,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 87, 1, 0, 0, NULL, 0);
		gui_utf_draw_middle(0, get_string(3), 0, gui_screen_x_offset(), gui_screen_y_offset() + 113,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 140, 1, 0, 0, NULL, 0);
	} else {
		gui_bmp_bitmap_draw(0x87, gui_screen_x_offset() + 82, gui_screen_y_offset() + 101, 0, 0, 0);
		gui_utf_draw_middle(0, get_string(4), 0, gui_screen_x_offset(), gui_screen_y_offset() + 60,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 87, 1, 0, 0, NULL, 0);
		gui_utf_draw_middle(0, get_string(5), 0, gui_screen_x_offset(), gui_screen_y_offset() + 113,
				    gui_screen_x_offset() + 576, gui_screen_y_offset() + 140, 1, 0, 0, NULL, 0);
	}
	return 0;
}

int ui_set_imu_pitch_task(struct jbd_panel_context *ctx, void *arg, int event)
{
	get_dashboard_state();
	set_frame_buffer(ctx->panel_buffer);
	set_showing_notification_on_gui();

	switch (imu_pitch_ui.state) {
	case 0:
		if (event == 1) {
			if (imu_pitch_ui.entered) {
				return 0;
			}
			gui_utf_adv_draw_reset();
			gui_screen_clear();
			gui_text_state_reset();
			memset(&imu_pitch_ui, 0, sizeof(imu_pitch_ui));
			imu_pitch_ui.entered = 1;
			gui_dynamic_bitmap_reset();
			imu_pitch_ui.state = 1;
			clear_showing_notification_on_gui();

			/* fade in */
			for (int i = 0; i < 8; i++) {
				set_imu_pitch_reflash();
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
			memset(&imu_pitch_ui, 0, sizeof(imu_pitch_ui));
		}
		break;
	case 1:
		if (event == 1) {
			set_imu_pitch_reflash();
		} else if (event == 2) {
			G1_LOG_INF("set_imu_pitch process received exit packet ...\n");
			gui_screen_fade_out();
			gui_utf_adv_draw_reset();
			memset(&imu_pitch_ui, 0, sizeof(imu_pitch_ui));
		}
		break;
	default:
		break;
	}
	return 0;
}

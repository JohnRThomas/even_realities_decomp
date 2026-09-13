/*
 * "Do not disturb" bitmap page (ui_bitmap_task) and the do-not-disturb
 * master/slave synchronisation.
 */
#include "ui_a.h"

uint8_t dnd_bitmap_mode;                        /* do-not-disturb page mode */
/* 0x2001c6cb; non-static: as a static GCC reorders the exit stores of ui_bitmap_task */
uint8_t bitmap_state;

/* not inlined into FUN_0003f1bc in the shipped image */
__noinline void bitmap_state_reset(void)
{
	bitmap_state = 0;
}

int ui_bitmap_task(struct jbd_panel_context *panel, void *arg, int event)
{
	set_frame_buffer(panel->panel_buffer);
	set_showing_notification_on_gui();

	if (event == UI_EVT_EXIT) {
		gui_screen_clear();
		UI_GS()->bitmap_info->enable = 0;
		bitmap_state = 0;
		return 0;
	}
	switch (bitmap_state) {
	case 0: {
		int64_t now;

		gui_screen_clear();
		gui_dynamic_bitmap_reset();
		bitmap_state = 1;
		now = k_uptime_get();
		UI_GS()->bitmap_info->deadline = now;
		switch (dnd_bitmap_mode) {
		case 0:
			gui_bmp_dynamic_bitmap_draw(6, gui_screen_x_offset() + 0xc8, gui_screen_y_offset() + 0x3a, 0, 0,
						    0, 1);
			gui_utf_draw(0, get_string(0x25), 0, gui_screen_x_offset() + 0xf4,
				     gui_screen_y_offset() + 0x37, gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88,
				     2, 0, 0, NULL, 0);
			break;
		case 2:
			gui_bmp_bitmap_draw(0x49, gui_screen_x_offset(), gui_screen_y_offset() + 0x3a, 0, 0, 0);
			gui_utf_draw(0, get_string(0x26), 0, gui_screen_x_offset() + 0x58,
				     gui_screen_y_offset() + 0x37, gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88,
				     2, 0, 0, NULL, 0);
			break;
		case 1:
			gui_bmp_dynamic_bitmap_draw(7, gui_screen_x_offset() + 0xd8, gui_screen_y_offset() + 0x3a, 0, 0,
						    0, 1);
			gui_utf_draw(0, get_string(0x27), 0, gui_screen_x_offset() + 0x104,
				     gui_screen_y_offset() + 0x37, gui_screen_x_offset() + 0x240, gui_screen_y_offset() + 0x88,
				     2, 0, 0, NULL, 0);
			break;
		default:
			break;
		}
		break;
	}
	case 1:
		switch (dnd_bitmap_mode) {
		case 0:
			gui_bmp_dynamic_bitmap_draw(6, gui_screen_x_offset() + 0xc8, gui_screen_y_offset() + 0x3a, 0, 0,
						    0, 1);
			break;
		case 1:
			gui_bmp_dynamic_bitmap_draw(7, gui_screen_x_offset() + 0xd8, gui_screen_y_offset() + 0x3a, 0, 0,
						    0, 1);
			break;
		case 2:
			break;
		default:
			UI_GS()->bitmap_info->enable = 0;
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

int not_disturb_sync_data(const uint8_t *data, uint8_t len)
{
	if (data == NULL) {
		return -1;
	}
	if (UI_GS()->is_master == 1) {
		uint8_t buf[4] = {5};

		if (len > 3) {
			len = 3;
		}
		if (len) {
			memcpy(&buf[1], data, len);
		}
		if (sync_to_slave(get_dashboard_state(), 6, buf, (uint8_t)(len + 1)) > 2999) {
			G1_LOG_ERR("not_disturb SYNC TO Slave failed...\n");
			return -1;
		}
	} else {
		uint8_t buf[2] = {5};

		if (len) {
			len = 1;
			buf[1] = data[0];
		}
		if ((unsigned int)FUN_000294d0(get_dashboard_state(), 0xe, buf, (uint8_t)(len + 1)) >=
		    2000) {
			G1_LOG_ERR("not_disturb SYNC TO master failed...\n");
			return -1;
		}
	}
	return 0;
}

void FUN_0003f1bc(uint8_t mode)
{
	bitmap_state_reset();
	dnd_bitmap_mode = mode;
	UI_GS()->bitmap_info->mode = mode;
	UI_GS()->esb_down_id = dnd_bitmap_mode;
	UI_GS()->bitmap_info->enable = 1;
	UI_GS()->bitmap_info->deadline = k_uptime_get() + 10000;
	update_persist_task_status(get_dashboard_state(), 7, 2);
}

int FUN_00080806(uint8_t mode)
{
	int ret;

	if (UI_GS()->bitmap_info->sync_pending) {
		ret = not_disturb_sync_data(&mode, 1);
		if (ret) {
			return ret;
		}
		UI_GS()->bitmap_info->sync_pending = ret;
		if (UI_GS()->is_master == 1) {
			FUN_0003f1bc(mode);
		}
	}
	return 0;
}

/* request a new do-not-disturb bitmap mode (0..2); synced to the app later */
void FUN_00080852(uint8_t mode)
{
	if (mode < 3 && (UI_GS()->bitmap_info->mode != mode || UI_GS()->dashboard_mode != 7)) {
		UI_GS()->bitmap_info->mode = mode;
		UI_GS()->bitmap_info->sync_pending = 1;
	}
}

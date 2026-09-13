/*
 * UI page: raster height / canvas distance adjustment.
 */
#include "ui_b.h"

int CURRENT_HORIZONTAL_OFFSET = -1;
int CURRENT_VERTICAL_OFFSET = -1;

void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset)
{
	if (horizontal_offset != NULL) {
		int old = *horizontal_offset;

		switch (get_dashboard_state()->panel_canvas_distance_gear) {
		case 1:
			*horizontal_offset = 22;
			break;
		case 2:
			*horizontal_offset = 8;
			break;
		default:
			*horizontal_offset = 0;
			break;
		case 4:
			*horizontal_offset = -4;
			break;
		case 5:
			*horizontal_offset = -8;
			break;
		case 6:
			*horizontal_offset = -10;
			break;
		case 7:
			*horizontal_offset = -12;
			break;
		case 8:
			*horizontal_offset = -14;
			break;
		case 9:
			*horizontal_offset = -16;
			break;
		}
		if (get_dashboard_state()->is_master == 1) {
			*horizontal_offset = -*horizontal_offset;
		}
		if (*horizontal_offset != old) {
			G1_LOG_WRN("canvas_distance_gear:%d, pos_x:%d\n",
				   get_dashboard_state()->panel_canvas_distance_gear,
				   *horizontal_offset);
		}
	}
	if (vertical_offset != NULL) {
		int old = *vertical_offset;

		*vertical_offset = (8 - get_dashboard_state()->panel_raster_height_offset) * 35;
		if (*vertical_offset != old) {
			G1_LOG_WRN("raster_height_gear:%d, pos_y:%d\n",
				   get_dashboard_state()->panel_raster_height_offset,
				   *vertical_offset);
		}
	}
}

int ui_raster_height_task(struct jbd_panel_context *panel, void *arg, int event)
{
	int horizontal_offset = -1;
	int vertical_offset = -1;

	if (event == UI_EVT_EXIT) {
		G1_LOG_INF("ui_raster_height_task exit...\n");
		ui_DashBoard_task(panel, arg, UI_EVT_EXIT);
		CURRENT_HORIZONTAL_OFFSET = -1;
		CURRENT_VERTICAL_OFFSET = -1;
	} else {
		cal_panel_canvas_coord(&horizontal_offset, &vertical_offset);
		if (horizontal_offset != CURRENT_HORIZONTAL_OFFSET ||
		    vertical_offset != CURRENT_VERTICAL_OFFSET) {
			G1_LOG_INF("ui_raster_height_task reflash...\n");
			gui_screen_clear();
			set_screen_cleared();
			CURRENT_HORIZONTAL_OFFSET = horizontal_offset;
			CURRENT_VERTICAL_OFFSET = vertical_offset;
			get_dashboard_state()->panel_ec4 = horizontal_offset;
			get_dashboard_state()->panel_eb8 = vertical_offset;
			UI_DASH_TS(get_dashboard_state())->refresh_73 = 1;
			ui_DashBoard_task(panel, arg, UI_EVT_ENTER);
			get_dashboard_state()->dashboard_cmd = 0x26;
			k_sem_give(&get_dashboard_state()->dashboard_position_sem);
		}
	}
	return 0;
}

/*
 * UI page: navigation (map part): direction arrow, overview map page and
 * panoramic map page.
 *
 * One original file: the map pages (ui_a) followed by the navigation task
 * and its align-2 helpers (written by the ui_b module, merged here).  They
 * share the private data, the map bitmaps, one k_uptime_get copy (0x808b4)
 * and one k_mutex_lock/unlock copy (0x808d0/0x808d4).
 */
#include "ui_b.h"

/* navigation page data at GlassesState + 0xef (written by ble_process_put_req) */
struct nav_info {
	uint8_t f_00;
	uint8_t direction;               /* 0x01 */
	uint8_t pad_02[6];
	uint16_t pos_x;                  /* 0x08 position on the panoramic map */
	uint16_t pos_y;                  /* 0x0a */
	uint8_t pad_0c;
	char total_time[0x18];           /* 0x0d */
	char total_distance[0x18];       /* 0x25 */
	char road[0x40];                 /* 0x3d */
	char distance[0x18];             /* 0x7d */
	char speed[0x1c];                /* 0x95 */
	uint32_t map_size;               /* 0xb1 overview map size (0x1210 = raw) */
} __packed;
BUILD_ASSERT(offsetof(struct nav_info, map_size) == 0xb1);

#define NAV_MAP_RAW_SIZE 0x1210

extern struct k_mutex k_mutex_20007f54;  /* ble_proto: navigation data lock */
extern uint8_t DAT_20016b1f[];           /* ble_proto: overview map as received */
extern uint8_t DAT_20012a4f[];           /* ble_proto: panoramic map */
extern uint8_t DAT_20014ab7[];           /* ble_proto: panoramic map mask */
extern volatile uint8_t DAT_20010dbc;             /* ble_proto: panoramic map updated */
extern volatile uint8_t DAT_20010dbd;             /* ble_proto: position updated */
extern uint8_t DAT_20010dbe;             /* ble_proto: overview map updated */
extern uint8_t DAT_20010dbf;             /* ble_proto: text info updated */
int rle_decode(const uint8_t *src, uint32_t len, uint8_t *dst);  /* RLE decode */

uint8_t nav_map_bitmaps[2][0x908];          /* overview map bitmap / mask */
uint8_t nav_overview_decoded;                    /* overview map decoded */
volatile uint8_t nav_panoramic_drawn;                    /* panoramic map drawn */
char nav_summary_line[0x80];                 /* "total time total distance" line */
struct nav_prv_data nav_prv;

#define NAV_PANEL() UI_PANEL(get_dashboard_state())

#define NAV_DRAW_CLOCK()                                                                  \
	do {                                                                              \
		bool is_24h = UI_DASH_TS(get_dashboard_state())->time_disp_mode != 1;    \
                                                                                          \
		gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x4c, Y0 + 0x1d, 3, is_24h); \
	} while (0)

int nav_prv_reset(void)
{
	memset(&nav_prv, 0, sizeof(nav_prv));
	return 0;
}

void navigation_direction_img_display(int direction)
{
	if (direction < 1 || direction > 0x23) {
		G1_LOG_WRN("navigation direction parampter error\n");
		return;
	}
	gui_bmp_bitmap_draw(direction + 0x60, X0, Y0 + 0x39, 0, 0, 0);
}

#define nav_load_overview_map(info) \
	do { \
	if (info->map_size == NAV_MAP_RAW_SIZE) { \
		G1_LOG_INF("Data is in raw format.\n"); \
		memset(nav_map_bitmaps, 0, NAV_MAP_RAW_SIZE); \
		k_mutex_lock(&k_mutex_20007f54, K_FOREVER); \
		memcpy(nav_map_bitmaps, DAT_20016b1f, NAV_MAP_RAW_SIZE); \
	} else { \
		G1_LOG_INF("Data is in rle compress raw format.\n"); \
		memset(nav_map_bitmaps, 0, NAV_MAP_RAW_SIZE); \
		k_mutex_lock(&k_mutex_20007f54, K_FOREVER); \
		rle_decode(DAT_20016b1f, info->map_size, nav_map_bitmaps[0]); \
	} \
	nav_overview_decoded = 1; \
	k_mutex_unlock(&k_mutex_20007f54); \
	} while (0)

void navigation_overview_map_display(struct GlassesState *gs, uint8_t *nav)
{
	const struct nav_info *info = (const struct nav_info *)nav;

	if (nav_prv.overview_shown == 0) {
		uint8_t **fb;

		G1_LOG_INF("reflash overview map && text\n");
		fb = NAV_PANEL()->panel_buffer;
		/* fade out */
		for (int k = 5; k > 3; k--) {
			for (int row = 0; row < 199; row++) {
				for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
					uint8_t pix = fb[row][col];

					if (pix != 0) {
						fb[row][col] = pix & gui_fade_mask[row % 26][k][col];
					}
				}
			}
			_reflash_fb_data_to_lcd(NAV_PANEL()->current_row, NAV_PANEL()->current_column, 0,
						0, GUI_SCREEN_WIDTH, 199);
		}
		if (DAT_20010dc1 == 1 && nav_overview_decoded == 0) {
			nav_load_overview_map(info);
		}
		clear_showing_notification_on_gui();
		for (int i = 1; i < 4; i++) {
			_clean_fb_data(fb, 0, 0, 0, GUI_SCREEN_WIDTH, 199);
			gui_bitmps_merge_draw(X0 + 0x1b6, Y0, X0 + 0x240, Y0 + 0x88, nav_map_bitmaps[0],
					      nav_map_bitmaps[1], 2, 0xf);
			memset(nav_summary_line, 0, sizeof(nav_summary_line));
			snprintf(nav_summary_line, sizeof(nav_summary_line), "%s %s", info->total_time,
				 info->total_distance);
			gui_utf_draw(0, nav_summary_line, 0, X0 + 0xe8, Y0, X0 + 0x1ae, Y0 + 0x1b, 1, 0, 0,
				     NULL, 0);
			gui_utf_draw(0, info->distance, 0, X0, Y0 + 0x6c, X0 + 200, Y0 + 0x87, 1, 0, 0,
				     NULL, 0);
			gui_utf_draw(0, info->road, 0, X0, Y0 + 0x1d, X0 + 0x1ae, Y0 + 0x38, 1, 0, 0,
				     NULL, 0);
			NAV_DRAW_CLOCK();
			navigation_direction_img_display(info->direction);
			for (int row = 0; row < 199; row++) {
				for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
					const uint8_t steps[8] = {1, 3, 5, 7, 7, 7, 7, 7};
					uint8_t pix = fb[row][col];

					if (pix != 0) {
						fb[row][col] =
							pix & gui_fade_mask[row % 26][steps[i]][col];
					}
				}
			}
			_reflash_fb_data_to_lcd(NAV_PANEL()->current_row, NAV_PANEL()->current_column, 0,
						0, GUI_SCREEN_WIDTH, 199);
		}
		set_showing_notification_on_gui();
		gui_utf_draw(0, nav_summary_line, 0, X0 + 0xe8, Y0, X0 + 0x1ae, Y0 + 0x1b, 1, 0, 0, NULL,
			     0);
		gui_utf_draw(0, info->distance, 0, X0, Y0 + 0x6c, X0 + 200, Y0 + 0x87, 1, 0, 0, NULL,
			     0);
		gui_utf_draw(0, info->road, 0, X0, Y0 + 0x1d, X0 + 0x1ae, Y0 + 0x38, 1, 0, 0, NULL, 0);
		NAV_DRAW_CLOCK();
	}
	if (DAT_20010dbe == 1) {
		if (DAT_20010dc1 == 1) {
			G1_LOG_INF("reflash overview map ....\n");
			nav_load_overview_map(info);
			gui_bitmps_merge_draw(X0 + 0x1b6, Y0, X0 + 0x240, Y0 + 0x88, nav_map_bitmaps[0],
					      nav_map_bitmaps[1], 2, 0xf);
		} else if (nav_overview_decoded == 1) {
			gui_bitmps_merge_draw(X0 + 0x1b6, Y0, X0 + 0x240, Y0 + 0x88, nav_map_bitmaps[0],
					      nav_map_bitmaps[1], 2, 0xf);
		}
		DAT_20010dbe = 0;
	}
	if (DAT_20010dbf == 1) {
		G1_LOG_INF("reflash text info ....\n");
		memset(nav_summary_line, 0, sizeof(nav_summary_line));
		snprintf(nav_summary_line, sizeof(nav_summary_line), "%s %s", info->total_time,
			 info->total_distance);
		gui_utf_draw(0, nav_summary_line, 0, X0 + 0xe8, Y0, X0 + 0x1ae, Y0 + 0x1b, 1, 0, 0, NULL,
			     0);
		gui_utf_draw(0, info->road, 0, X0, Y0 + 0x1d, X0 + 0x1ae, Y0 + 0x38, 1, 0, 0, NULL, 0);
		gui_utf_draw(0, info->distance, 0, X0, Y0 + 0x6c, X0 + 200, Y0 + 0x87, 1, 0, 0, NULL,
			     0);
		NAV_DRAW_CLOCK();
		navigation_direction_img_display(info->direction);
		DAT_20010dbf = 0;
	}
	nav_prv.panoramic_shown = 0;
	nav_prv.overview_shown = 1;
	nav_prv.arrived_cleared = 0;
}

#define nav_draw_position(info) \
	do { \
	if (info->pos_x <= 0x1e8 && info->pos_y <= 0x88) { \
		gui_4bit_bitmap_override(0x5f, info->pos_x + X0 + 0x52, info->pos_y - 6 + Y0); \
	} else { \
		G1_LOG_ERR("APP send navigation offset overstep ,stop draw....\n"); \
	} \
	} while (0)

#define nav_draw_panoramic_text(info) \
	do { \
	gui_utf_draw(0, info->speed, 0, X0, Y0 + 0x37, X0 + 0x4c, Y0 + 0x52, 1, 0, 0, NULL, 0); \
	gui_utf_draw(0, info->total_time, 0, X0, Y0 + 0x52, X0 + 0x4c, Y0 + 0x6d, 1, 0, 0, NULL, 0); \
	gui_utf_draw(0, info->total_distance, 0, X0, Y0 + 0x6d, X0 + 0x4c, Y0 + 0x88, 1, 0, 0, NULL, \
		     0); \
	} while (0)

void navigation_panoramic_map_display(struct GlassesState *gs, uint8_t *nav)
{
	const struct nav_info *info = (const struct nav_info *)nav;

	if (nav_prv.panoramic_shown == 0) {
		uint8_t **fb;

		G1_LOG_INF("reflash panoramic map to lcd\n");
		fb = NAV_PANEL()->panel_buffer;
		/* fade out */
		for (int k = 5; k > 3; k--) {
			for (int row = 0; row < 199; row++) {
				for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
					uint8_t pix = fb[row][col];

					if (pix != 0) {
						fb[row][col] = pix & gui_fade_mask[row % 26][k][col];
					}
				}
			}
			_reflash_fb_data_to_lcd(NAV_PANEL()->current_row, NAV_PANEL()->current_column, 0,
						0, GUI_SCREEN_WIDTH, 199);
		}
		clear_showing_notification_on_gui();
		for (int i = 1; i < 4; i++) {
			_clean_fb_data(fb, 0, 0, 0, GUI_SCREEN_WIDTH, 199);
			if (DAT_20010dc0 == 1) {
				gui_bitmps_merge_draw(X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88, DAT_20012a4f,
						      DAT_20014ab7, 2, 0xf);
				nav_draw_position(info);
				nav_draw_panoramic_text(info);
				nav_panoramic_drawn = 1;
			} else {
				gui_utf_draw(0, get_string(0x48), 0, X0, Y0 + 0x37, X0 + 0x240, Y0 + 0x88,
					     3, 0, 0, NULL, 0);
				nav_panoramic_drawn = 0;
			}
			NAV_DRAW_CLOCK();
			for (int row = 0; row < 199; row++) {
				for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
					const uint8_t steps[8] = {1, 3, 5, 7, 7, 7, 7, 7};
					uint8_t pix = fb[row][col];

					if (pix != 0) {
						fb[row][col] =
							pix & gui_fade_mask[row % 26][steps[i]][col];
					}
				}
			}
			_reflash_fb_data_to_lcd(NAV_PANEL()->current_row, NAV_PANEL()->current_column, 0,
						0, GUI_SCREEN_WIDTH, 199);
		}
		set_showing_notification_on_gui();
		if (DAT_20010dc0 == 1) {
			nav_draw_panoramic_text(info);
		}
		NAV_DRAW_CLOCK();
	}
	if (DAT_20010dbd == 1 || DAT_20010dbc == 1) {
		if (DAT_20010dbd == 1) {
			DAT_20010dbd = 0;
		}
		if (DAT_20010dbc == 1) {
			DAT_20010dbc = 0;
		}
		if (DAT_20010dc0 == 1) {
			gui_bitmps_merge_draw(X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88, DAT_20012a4f,
					      DAT_20014ab7, 2, 0xf);
			nav_draw_position(info);
			if (nav_panoramic_drawn == 0) {
				nav_draw_panoramic_text(info);
			}
		} else {
			_clean_fb_data(NAV_PANEL()->panel_buffer, 0, X0 + 0x58, Y0, X0 + 0x240,
				       Y0 + 0x88);
			_reflash_fb_data_to_lcd(NAV_PANEL()->current_row, NAV_PANEL()->current_column,
						X0 + 0x58, Y0, X0 + 0x240, Y0 + 0x88);
			gui_utf_draw(0, get_string(0x48), 0, X0, Y0 + 0x37, X0 + 0x240, Y0 + 0x88, 3, 0,
				     0, NULL, 0);
		}
	}
	if (DAT_20010dbf == 1) {
		DAT_20010dbf = 0;
		if (DAT_20010dc0 == 1) {
			nav_draw_panoramic_text(info);
		}
		NAV_DRAW_CLOCK();
	}
	if (DAT_20010dbe == 1) {
		DAT_20010dbe = 0;
		if (info->map_size == NAV_MAP_RAW_SIZE) {
			G1_LOG_INF("Data is in raw format.\n");
			memset(nav_map_bitmaps, 0, NAV_MAP_RAW_SIZE);
			k_mutex_lock(&k_mutex_20007f54, K_FOREVER);
			memcpy(nav_map_bitmaps, DAT_20016b1f, NAV_MAP_RAW_SIZE);
			nav_overview_decoded = 1;
			k_mutex_unlock(&k_mutex_20007f54);
		} else {
			G1_LOG_INF("Data is in rle compress raw format.\n");
			memset(nav_map_bitmaps, 0, NAV_MAP_RAW_SIZE);
			k_mutex_lock(&k_mutex_20007f54, K_FOREVER);
			rle_decode(DAT_20016b1f, info->map_size, nav_map_bitmaps[0]);
			nav_overview_decoded = 1;
			k_mutex_unlock(&k_mutex_20007f54);
		}
	}
	nav_prv.panoramic_shown = 1;
	nav_prv.overview_shown = 0;
	nav_prv.arrived_cleared = 0;
}


/* ---- navigation task (was ui_navigation_task.c, ui_b module) ---- */

int FUN_000808d8(void)
{
	return 0;
}

void nav_draw_service_lost(void)
{
	gui_utf_draw_middle(0, get_string(0x49), 0, X0, Y0 + 0x37, X0 + 0x240, Y0 + 0x88, 1, 0,
			    0, NULL, 0);
}

void nav_draw_route_generating(void)
{
	gui_utf_draw(0, get_string(0x47), 0, X0 + 0x24, Y0 + 0x37, X0 + 0x21c, Y0 + 0x6d, 2, 0, 0,
		     NULL, 0);
}

/*
 * G1_LOG() copy for the two log lines that appear in both case 0 and case 1 of
 * ui_navigation_task.  compiler_barrier() emits no code.  It is a statement
 * that GIMPLE tail merging (pass_tail_merge in PRE) cannot compare, so the
 * case-0 and case-1 printk blocks stay separate there.  RTL cross-jumping
 * merges them later and keeps the case-1 printk stubs where the target has
 * them.  With plain G1_LOG, GCC merges the blocks in GIMPLE and the stubs end
 * up with case 0 (2352 B vs 2356 B).  -fno-tree-tail-merge does not help
 * either (it is worse).  Alternatives tried, none of which match:
 * - printk branch first (if (!BLE_DEBUG)): 2352 B.
 * - __FUNCTION__ in the printk call: 2368 B.
 * - a volatile read of BLE_DEBUG: 2352 B.
 * The barrier is needed in all four uses.
 */
#define NAV_LOG(lvl, fmt)                                                           \
	do {                                                                        \
		if (LOG_LEVEL > (lvl)) {                                            \
			if (BLE_DEBUG) {                                            \
				ble_printk("%s(): " fmt, __func__);                 \
			} else {                                                    \
				printk("%s(): " fmt, __func__);                     \
				compiler_barrier();                                 \
			}                                                           \
		}                                                                   \
	} while (0)

int ui_navigation_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct GlassesState *gs = get_dashboard_state();
	uint8_t *nav = NAV_INFO(gs);

	set_frame_buffer(panel->panel_buffer);
	set_showing_notification_on_gui();

	switch (nav_prv.state) {
	case 0:
		G1_LOG_INF("ENTER NAVIGATION INIT status ....\n");
		if (event == UI_EVT_EXIT) {
			G1_LOG_INF("running exit command..\n");
			gui_screen_clear();
clear:
			memset(&nav_prv, 0, sizeof(nav_prv));
			memset(nav_map_bitmaps, 0, sizeof(nav_map_bitmaps));
			nav_overview_decoded = 0;
			return 0;
		}
		if (event == UI_EVT_REFRESH && nav_prv.synced == 1) {
			G1_LOG_INF("dynamic image reflash\n");
			gui_bmp_dynamic_bitmap_draw(8, X0, Y0 + 0x3a, 0, 0, 0, 0);
		} else if (event == UI_EVT_ENTER) {
			if (get_dashboard_state()->is_master == 1) {
				send_response_data_to_ble();
			}
			if (!nav_prv.synced && *NAV_FLAGS(get_dashboard_state()) == 1) {
				G1_LOG_INF("INIT STATUS  SYNC ACTION ENTER\n");
				nav_prv_reset();
				nav_prv.synced = 1;
				nav_prv.ts = k_uptime_get();
				nav_prv.sync_cnt = 10;
				gui_screen_clear();
				gui_dynamic_bitmap_reset();
				nav_draw_route_generating();
			}
			if (nav_prv.synced == 1 && DAT_20010dc1 == 1) {
				uint8_t running = DAT_20010dc0;

				if (running == 1) {
					nav_prv.state = running;
					nav_panoramic_drawn = 0;
					G1_LOG_INF("switch NAVIGATION_RUNNING_STATUS .....\n");
					gui_screen_clear();
					nav_overview_decoded = 0;
					nav_prv.sync_cnt = 10;
					nav_prv.ts = k_uptime_get();
					navigation_overview_map_display(gs, nav);
				}
			}
		}
		if (get_dashboard_state()->is_master == 1 && nav_prv.synced == 1) {
			if (DAT_20007f48 > 0) {
				DAT_20007f48 = 0;
				if (nav_prv.sync_cnt < 20) {
					nav_prv.sync_cnt = 19;
				}
			}
			if (abs_diff_u64(k_uptime_get(), nav_prv.ts) <= 1000) {
				return 0;
			}
			nav_prv.ts = k_uptime_get();
			nav_prv.sync_cnt--;
			G1_LOG_INF("DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
				   nav_prv.sync_cnt);
			if (nav_prv.sync_cnt != 0) {
				return 0;
			}
			G1_LOG_WRN("There is a disconnection between the AR Glasses and the Bluetooth "
				   "application!\n");
			G1_LOG_INF("bluetooth connect is break,Send Stop Navigation command to slave.\n");
			{
				uint8_t cmd[2] = { 6, 1 };

				if (sync_to_slave(get_dashboard_state(), 6, cmd, 2) < 5000) {
					goto abnormal;
				}
			}
			NAV_LOG(0, "SYNC TO Slave failed...,don't exec Navigation exit action,master auto "
				   "exit...\n");
			return 0;
		}
		if (event != UI_EVT_MASTER_CLOSE) {
			return 0;
		}
		NAV_LOG(2, "Received exit command from master, exit teleprompter mode\n");
		goto abnormal;

	case 1:
		if (event == UI_EVT_EXIT) {
			gui_screen_fade_out();
			goto clear;
		}
		if (event == UI_EVT_ENTER) {
			if (get_dashboard_state()->is_master == 1) {
				send_response_data_to_ble();
				if (NAV_FLAGS(get_dashboard_state())[6] == 1) {
					if (nav_prv.sync_cnt < 20) {
						nav_prv.sync_cnt = 19;
					}
					NAV_FLAGS(get_dashboard_state())[6] = 0;
				}
			}
			k_mutex_lock(&k_mutex_2000851c, K_FOREVER);
			nav_prv.arrived = NAV_ARRIVED_STATUS(gs);
			nav_prv.imu_action = NAV_IMU_ACTION_STATUS(gs);
			k_mutex_unlock(&k_mutex_2000851c);
			G1_LOG_INF("arrived status = %d,  nav->imu_action_status = %d\n",
				   nav_prv.arrived, NAV_IMU_ACTION_STATUS(gs));

			if (nav_prv.arrived == 2) {
				G1_LOG_INF("received arrived complte command\n");
				nav_prv.state = 3;
				gui_screen_clear();

				uint32_t x = get_current_language() == 6 ? 0xaa : 0xc4;

				gui_utf_draw(0, NAV_ARRIVED_TEXT(gs), 0, X0 + x, Y0 + 0x3c, X0 + 0x23f,
					     Y0 + 0x57, 2, 0, 0, NULL, 0);

				bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

				gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x4c, Y0 + 0x1d, 3,
					       is_24h);
				nav_prv.arrived_ts = k_uptime_get();
				nav_prv.timeout = 5000;
			} else if (nav_prv.arrived == 1) {
				G1_LOG_INF("received arrived command,draw arrived page\n");
				if (nav_prv.imu_action == 2) {
					G1_LOG_INF("navigation arrived 2 rst reflash, "
						   "navigation_panoramic_map_display reflash\n");
					navigation_panoramic_map_display(gs, nav);
				} else {
					G1_LOG_INF("navigation arrived 1 rst reflash\n");
					if (!nav_prv.arrived_cleared) {
						gui_screen_clear();
						nav_prv.arrived_cleared = 1;
					}
					gui_bitmps_merge_draw(X0 + 0x1b6, Y0, X0 + 0x240, Y0 + 0x88,
							      nav_map_bitmaps[0], nav_map_bitmaps[1], 2, 0xf);

					uint32_t x = get_current_language() == 6 ? 0xe8 : 0xc4;

					gui_utf_draw(0, NAV_ARRIVED_TEXT(gs), 0, X0 + x, Y0 + 0x3c,
						     X0 + 0x1e4, Y0 + 0x57, 2, 0, 0, NULL, 0);
					nav_prv.panoramic_shown = 0;
					nav_prv.overview_shown = 1;

					bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

					gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x4c, Y0 + 0x1d, 3,
						       is_24h);
				}
			} else if (nav_prv.imu_action == 2) {
				G1_LOG_INF("navigation_panoramic_map_display reflash\n");
				navigation_panoramic_map_display(gs, nav);
			} else {
				G1_LOG_INF("navigation_overview_map_display reflash\n");
				navigation_overview_map_display(gs, nav);
			}
		} else if (event == UI_EVT_REFRESH) {
			struct bp_date date = { 0 };

			init_burial_point_date(FUN_00080732(), &date);
			if (nav_prv.minute != date.minute || date.hour != nav_prv.hour) {
				nav_prv.minute = date.minute;
				nav_prv.hour = date.hour;
				bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

				gui_clock_draw(FUN_00080732(), X0, Y0 + 2, X0 + 0x4c, Y0 + 0x1d, 3,
					       is_24h);
			}
		}
		if (get_dashboard_state()->is_master == 1) {
			if (DAT_20007f48 > 0) {
				DAT_20007f48 = 0;
				if (nav_prv.sync_cnt < 20) {
					nav_prv.sync_cnt = 19;
				}
			}
			if (abs_diff_u64(k_uptime_get(), nav_prv.ts) <= 1000) {
				return 0;
			}
			nav_prv.ts = k_uptime_get();
			nav_prv.sync_cnt--;
			G1_LOG_INF("DECETED TIMEOUT ...... _tpm_thread_prv_data.sync_cnt = %d\n",
				   nav_prv.sync_cnt);
			if (nav_prv.sync_cnt != 0) {
				return 0;
			}
			G1_LOG_WRN("There is a disconnection between the AR Glasses and the Bluetooth "
				   "application!\n");
			G1_LOG_INF("bluetooth connect is break,Send Stop Navigation command to slave.\n");
			{
				uint8_t cmd[2] = { 6, 1 };

				if (sync_to_slave(get_dashboard_state(), 6, cmd, 2) < 5000) {
					goto abnormal;
				}
			}
			NAV_LOG(0, "SYNC TO Slave failed...,don't exec Navigation exit action,master auto "
				   "exit...\n");
			return 0;
		}
		if (event != UI_EVT_MASTER_CLOSE) {
			return 0;
		}
		NAV_LOG(2, "Received exit command from master, exit teleprompter mode\n");
		goto abnormal;

	case 2:
		G1_LOG_WRN("running navigation DISPLAY ABNORMAL EXIT STATUS.\n");
		if (abs_diff_u64(k_uptime_get(), nav_prv.ts) > 8000) {
			G1_LOG_WRN("The navigation automatically shuts down due to disconnection.\n");
			gui_screen_fade_out();
			memset(&nav_prv, 0, sizeof(nav_prv));
			memset(nav_map_bitmaps, 0, sizeof(nav_map_bitmaps));
			nav_overview_decoded = 0;
			*NAV_FLAGS(get_dashboard_state()) = 0;
		}
		if (event != UI_EVT_EXIT) {
			return 0;
		}
		G1_LOG_INF("received exit command,clear screen...\n");
		break;

	case 3:
		if (event != UI_EVT_EXIT) {
			if (event == UI_EVT_ENTER && get_dashboard_state()->is_master == 1) {
				send_response_data_to_ble();
			}
			if (k_uptime_get() > nav_prv.timeout + nav_prv.arrived_ts) {
				G1_LOG_INF("exec navigation auto exit ...\n");
				*NAV_FLAGS(get_dashboard_state()) = 0;
				gui_screen_fade_out();
				memset(&nav_prv, 0, sizeof(nav_prv));
			}
			return 0;
		}
		break;

	default:
		return 0;
	}
	gui_screen_fade_out();
	goto clear;

abnormal:
	nav_prv.state = 2;
	nav_prv.ts = k_uptime_get();
	gui_screen_clear();
	gui_bmp_bitmap_draw(0x3f, X0, Y0 + 0x3a, 0, 0, 0);
	nav_draw_service_lost();
	return 0;

}

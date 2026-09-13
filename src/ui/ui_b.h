/*
 * UI screen tasks (navigation, translate, onboarding, raster height):
 * module-private declarations, reconstructed from the v1.63 app core.
 */
#ifndef G1_UI_B_H_
#define G1_UI_B_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <zephyr/kernel.h>
#include <g1_log.h>

#include "../main.h"
#define GUI_C_INTERNAL /* gui_screen_x_offset() returns int in these pages */
#include "../gui/gui.h"

/* the panel context lives at GlassesState + 0xb6c */
#define UI_PANEL(gs) ((struct jbd_panel_context *)&(gs)->panel_init)

/* partial view of struct dashboard_ts_context (bytes main.h leaves as padding) */
struct ui_dashboard_ts {
	uint8_t pad_00[0x5e];
	uint8_t time_disp_mode;          /* 0x5e: 1 = 12h */
	uint8_t pad_5f[0x73 - 0x5f];
	uint8_t refresh_73;              /* 0x73 */
} __packed;
#define UI_DASH_TS(gs) ((struct ui_dashboard_ts *)(gs)->dashboard_ts)

/* canvas origin (depends on the panel position settings) */
#define X0 gui_screen_x_offset()
#define Y0 gui_screen_y_offset()

/* UI process events passed to the ui_*_task() handlers */
enum ui_event {
	UI_EVT_REFRESH = 0,
	UI_EVT_ENTER = 1,
	UI_EVT_EXIT = 2,
	UI_EVT_DELAY_CLOSE = 3,
	UI_EVT_INPUT = 4,
	UI_EVT_MASTER_CLOSE = 5,
};

/* GlassesState + 0x101c: onboarding context (0x21 bytes, cleared by FUN_0004280c) */
struct onboarding_ctx {
	uint8_t active;                  /* 0x00 */
	uint8_t f_01;                    /* 0x01 */
	uint8_t action;                  /* 0x02 action_cmd */
	uint8_t sub_step;                /* 0x03 */
	uint64_t ts;                     /* 0x04 k_uptime_get() of the last step change */
	uint8_t f_0c;                    /* 0x0c */
	uint8_t f_0d;                    /* 0x0d */
	uint8_t f_0e;                    /* 0x0e */
	uint32_t f_0f;                   /* 0x0f */
	uint32_t f_13;                   /* 0x13 */
	uint32_t f_17;                   /* 0x17 */
	char step_str[4];                /* 0x1b "n/6" */
	uint8_t flags;                   /* 0x1f */
	uint8_t saved_brightness;        /* 0x20 */
} __packed;
BUILD_ASSERT(sizeof(struct onboarding_ctx) == 0x21);
#define ONB_CTX(gs) ((struct onboarding_ctx *)(gs)->ptr_101c)
#define ONB() ONB_CTX(get_dashboard_state())

/* panel brightness level byte (GlassesState + 0xed5 = panel + 0x369) */
#define UI_PANEL_BRIGHTNESS(gs) (((uint8_t *)(gs))[0xed5])

/* header of a BLE request handed to the *_ble_process() handlers */
struct ui_ble_req_hdr {
	uint16_t f_00;
	uint16_t len;                    /* 0x02 */
};

/* GlassesState + 0xef: translate page data (written by the BLE handler) */
struct trans_info {
	uint8_t translation_type;        /* 0x00 (GS + 0xef) 1-based language index */
	uint8_t original_type;           /* 0x01 */
	uint8_t suspend_en;              /* 0x02 */
	uint8_t mode;                    /* 0x03 */
	uint8_t pad_04[2];
	char text[0x1e0];                /* 0x06 (GS + 0xf5) */
} __packed;
#define TRANS_INFO(gs) ((struct trans_info *)&(gs)->buf_0ef[0])

/* text_anim / text_anim_buf (text animation): see gui.h */
extern struct k_mutex k_mutex_2000851c;

/*
 * Navigation private data (0x20004d70, 0x38 bytes).  Shared with the
 * navigation_*_display() functions of the same original file (ui_a).
 */
struct nav_prv_data {
	uint32_t state;                  /* 0x00 0 init, 1 running, 2 abnormal exit, 3 arrived */
	volatile uint8_t panoramic_shown; /* 0x04 panoramic page shown (volatile: stores not merged) */
	volatile uint8_t overview_shown;  /* 0x05 overview page shown */
	uint8_t synced;                  /* 0x06 init sync with the phone done */
	uint8_t pad_07[7];
	volatile uint16_t hour;          /* 0x0e last drawn clock (volatile: ldrh+uxth) */
	volatile uint16_t minute;        /* 0x10 */
	uint8_t pad_12[2];
	volatile uint8_t arrived;        /* 0x14 arrived status (1 arriving, 2 arrived) */
	volatile uint8_t arrived_cleared; /* 0x15 */
	uint8_t pad_16[2];
	volatile int64_t timeout;        /* 0x18 auto exit delay after arrival */
	volatile int64_t arrived_ts;     /* 0x20 */
	uint8_t imu_action;              /* 0x28 2 = panoramic map */
	uint8_t pad_29[4];
	volatile uint8_t sync_cnt;       /* 0x2d heart beat counter (volatile: re-read for the log) */
	uint8_t pad_2e[2];
	volatile int64_t ts;             /* 0x30 */
};
BUILD_ASSERT(sizeof(struct nav_prv_data) == 0x38);
extern struct nav_prv_data nav_prv;
extern volatile uint8_t nav_panoramic_drawn;    /* volatile (ui_a: ldrb + and #0xff re-reads) */
extern uint8_t nav_overview_decoded;
extern uint8_t nav_map_bitmaps[2][0x908];   /* navigation bitmaps (overview / arrow) */
extern volatile uint8_t DAT_20010dc0;    /* written by ble_process_put_req (volatile, ui_a) */
extern uint8_t DAT_20010dc1;
extern int DAT_20007f48;                 /* ble_proto: phone heart beat seen */

/* navigation page data at GlassesState + 0xef */
#define NAV_INFO(gs) (&(gs)->buf_0ef[0])
#define NAV_FLAGS(gs) ((uint8_t *)(gs)->ptr_1004)   /* [0] navigation active, [6] phone alive */
#define NAV_IMU_ACTION_STATUS(gs) ((gs)->buf_0ef[0xf6 - 0xef])
#define NAV_ARRIVED_STATUS(gs) ((gs)->buf_0ef[0x19d - 0xef])
#define NAV_ARRIVED_TEXT(gs) ((const char *)&(gs)->buf_0ef[0x1a4 - 0xef])

int nav_prv_reset(void);
void navigation_direction_img_display(int direction);
void navigation_overview_map_display(struct GlassesState *gs, uint8_t *nav);
void navigation_panoramic_map_display(struct GlassesState *gs, uint8_t *nav);

/* ---- other modules ---- */
uint8_t is_in_box(void);
int update_persist_task_status(struct GlassesState *state, int task, int status);
void FUN_00029774(int cmd);
int sync_to_slave(struct GlassesState *state, int cmd, void *data, size_t len);
unsigned int FUN_000294d0(struct GlassesState *state, int cmd, void *data, size_t len);
int send_response_data_to_ble(void);
int ui_DashBoard_task(struct jbd_panel_context *panel, void *arg, int event);
void set_screen_cleared(void);

/* gui.c (not yet in gui.h) */
int gui_bitmps_merge_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp1, const uint8_t *bmp2,
			  uint8_t color1, uint8_t color2);
int gui_4bit_bitmap_override(int id, uint32_t x, uint32_t y);
int gui_1bit_bitmap_override(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color);
int gui_bitmap_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color);
int gui_bmp_bitmap_draw_ex(int id, int x, int y, uint8_t *buf, uint8_t level);
int gui_utf_draw_dark_light_split(int arg, const char *str, int font, int x0, int y0, int x1,
				  int y1, uint32_t max_lines, uint32_t dark_cnt, int effect,
				  gui_effect_cb_t cb, int no_draw);
int gui_string_draw(int font, const char *str, int x0, int y0, int x1, int y1, int *out_w);

/* ---- ui_navigation_map.c (navigation task part, merged from ui_navigation_task.c) ---- */
int FUN_000808b0(void);
int FUN_000808d8(void);
void nav_draw_service_lost(void);
void nav_draw_route_generating(void);

/* ---- ui_translate.c ---- */
int draw_template_translate_screen(struct jbd_panel_context *panel);
void translate_draw_hint_page(int which);
int ui_translate_task(struct jbd_panel_context *panel, void *arg, int event);

/* ---- ui_onboarding.c ---- */
extern uint8_t DAT_2001db40;             /* onboarding sub-step shown (slave_display_thread) */
int FUN_0004280c(void);
void FUN_00042830(void);
void onboarding_draw_static_page(int event);
void onboarding_draw_animated_page(int event);
void FUN_00044b24(void);
int onboarding_ble_process(struct GlassesState *gs, const struct ui_ble_req_hdr *hdr,
			   const uint8_t *req, uint8_t *rsp);
int onboarding_sync_data(const uint8_t *data, uint32_t len);
int ui_onboarding_task(struct jbd_panel_context *panel, void *arg, int event);
void FUN_00080992(void);

/* ---- ui_raster_height.c ---- */
void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset);
int ui_raster_height_task(struct jbd_panel_context *panel, void *arg, int event);

#endif /* G1_UI_B_H_ */

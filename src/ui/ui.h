/*
 * UI screen tasks (quick note, Even AI, bitmap, teleprompter, navigation,
 * translate, onboarding, raster height) - module private declarations.
 * Partial views of vendor structures, reconstructed from the v1.63 app core.
 *
 * gui_screen_x_offset() returns int in some pages and uint16_t in others
 * (call sites differ): pages that want the int prototype define
 * GUI_C_INTERNAL before including this header.
 */
#ifndef G1_UI_H_
#define G1_UI_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "../main.h"
#include "../gui/gui.h"

/* events passed to the ui_*_task() handlers (display_thread.h) */
#define UI_EVT_REFRESH     0
#define UI_EVT_ENTER       1
#define UI_EVT_EXIT        2
#define UI_EVT_DELAY_CLOSE 3
#define UI_EVT_INPUT       4
#define UI_EVT_MASTER_CLOSE 5
#define UI_EVT_LOW_POWER   6
#define UI_EVT_POWER_RESUME 7

#define LANGUAGE_FRENCH  5
#define LANGUAGE_GERMAN  6
#define LANGUAGE_SPANISH 7
#define LANGUAGE_ITALIAN 14

/* canvas origin (depends on the panel position settings) */
#define X0 gui_screen_x_offset()
#define Y0 gui_screen_y_offset()

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

/* ui_quicknote.c */
extern uint8_t quicknote_result_shown;
void dmic_record_start(void);
void quicknote_stop_record(void);
void quicknote_timeout_reset(void);
int ui_QuickNote_task(struct jbd_panel_context *panel, void *arg, int event);
int day_of_week(int year, int month, int day); /* day of week (Zeller) */
void draw_countdown_running_status(uint8_t **fb, void *arg, int a, int b, int c);
int draw_template_bitmap_page(struct jbd_panel_context *panel, void *arg);

/* ui_even_ai.c */
extern uint8_t even_ai_scrolling;
int ui_even_ai_task(struct jbd_panel_context *panel, void *arg, int event);

/* ui_bitmap.c */
int ui_bitmap_task(struct jbd_panel_context *panel, void *arg, int event);
void show_not_disturb_bitmap(uint8_t mode);
int sync_not_disturb_bitmap(uint8_t mode);
void request_not_disturb_bitmap(uint8_t mode);

/* ui_teleprompter.c */
void teleprompter_state_reset(void);
int ui_teleprompter_task(struct jbd_panel_context *panel, void *arg, int event);
int draw_template_teleprompter_page(struct jbd_panel_context *panel, void *arg);

/* ui_navigation_map.c (navigation task part, merged from ui_navigation_task.c) */
extern struct nav_prv_data nav_prv;
extern volatile uint8_t nav_panoramic_drawn;    /* volatile (ui_a: ldrb + and #0xff re-reads) */
extern uint8_t nav_overview_decoded;
extern uint8_t nav_map_bitmaps[2][0x908];   /* navigation bitmaps (overview / arrow) */
int nav_prv_reset(void);
void navigation_direction_img_display(int direction);
void navigation_overview_map_display(struct GlassesState *gs, uint8_t *nav);
void navigation_panoramic_map_display(struct GlassesState *gs, uint8_t *nav);
int draw_template_navigation_page(struct jbd_panel_context *panel, void *arg);
void nav_draw_service_lost(void);
void nav_draw_route_generating(void);
int ui_navigation_task(struct jbd_panel_context *panel, void *arg, int event);

/* ui_translate.c */
int draw_template_translate_screen(struct jbd_panel_context *panel, void *arg);
void translate_draw_hint_page(int which);
int ui_translate_task(struct jbd_panel_context *panel, void *arg, int event);

/* ui_onboarding.c */
extern uint8_t onboarding_shown_sub_step;             /* onboarding sub-step shown (slave_display_thread) */
int init_onboarding_info(void);
void onboarding_request_redraw(void);
void onboarding_draw_static_page(int event);
void onboarding_draw_animated_page(int event);
void onboarding_check_step_finished(void);
int ui_onboarding_task(struct jbd_panel_context *panel, void *arg, int event);
struct ble_req_hdr;
int onboarding_ble_process(struct GlassesState *gs, const struct ble_req_hdr *hdr,
			   const uint8_t *req, uint8_t *rsp);
int onboarding_sync_data(const uint8_t *data, uint32_t len);
void onboarding_deactivate(void);

/* ui_raster_height.c */
void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset);
int ui_raster_height_task(struct jbd_panel_context *panel, void *arg, int event);

#endif /* G1_UI_H_ */

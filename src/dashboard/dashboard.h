/*
 * Dashboard screen (DashBoard_Reflash) - module private declarations.
 * Partial views of shared vendor structures, reconstructed from the v1.63
 * app core.
 */
#ifndef G1_DASHBOARD_H_
#define G1_DASHBOARD_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include <g1_log.h>
#include <g1_date.h>
#include <glasses_state.h>

/* events passed to the ui_*_task() handlers (display_thread.h) */
#define UI_EVT_REFRESH      0
#define UI_EVT_ENTER        1
#define UI_EVT_EXIT         2
#define UI_EVT_DELAY_CLOSE  3
#define UI_EVT_INPUT        4
#define UI_EVT_MASTER_CLOSE 5
#define UI_EVT_LOW_POWER    6
#define UI_EVT_POWER_RESUME 7

#define GUI_SCREEN_WIDTH 640
#define GUI_FB_ROW_BYTES 320

/*
 * Dashboard page private state (_dashboard_prv_data, .bss 0x20004af8,
 * 0x28 bytes, 8-byte aligned), defined in dashboard.c.
 */
struct dashboard_prv_data {
	uint8_t state;               /* 0x00: 0 init, 1 running */
	uint8_t notes_index;         /* 0x01 */
	uint8_t notes_count;         /* 0x02 */
	uint8_t stocks_index;        /* 0x03 */
	uint8_t stocks_count;        /* 0x04 */
	uint8_t news_index;          /* 0x05 */
	uint8_t news_count;          /* 0x06 */
	uint8_t calendar_last_index; /* 0x07 */
	uint8_t calendar_index;      /* 0x08 */
	uint8_t calendar_count;      /* 0x09 (calendar pages) */
	uint8_t notes_shown;         /* 0x0a */
	uint8_t news_shown;          /* 0x0b */
	uint8_t init_done;           /* 0x0c */
	uint8_t pad_0d;
	uint8_t power_info_sent;     /* 0x0e */
	uint8_t pad_0f;
	int64_t enter_ts;            /* 0x10 */
	uint8_t language;            /* 0x18 */
	uint8_t display_mode;        /* 0x19 */
	uint8_t pane_mode;           /* 0x1a _CurrentCustomAreaType (Ghidra PANE_MODE) */
	uint8_t pad_1b;
	uint32_t ble_connected;      /* 0x1c */
	uint8_t calendar_disp_mode;  /* 0x20 (schedule_disp_status) */
	uint8_t stocks_disp_mode;    /* 0x21 */
	uint8_t news_disp_mode;      /* 0x22 */
	uint8_t citywalk_disp_mode;  /* 0x23 */
	uint8_t screen_cleared;      /* 0x24 (cleared by set_screen_cleared()) */
	uint8_t msg_count;           /* 0x25 */
	uint8_t pad_26[2];
};
BUILD_ASSERT(sizeof(struct dashboard_prv_data) == 0x28);
extern struct dashboard_prv_data _dashboard_prv_data;

/*
 * Screen origin helpers (align-2, owned by the gui file):
 * gui_screen_x_offset() = panel x offset (GS+0xec4) + GS->x_shift_108a (reset to 0x20
 * when out of range), gui_screen_y_offset() = GS->y_shift_108c (clamped to 4..0x40).
 * Every dashboard coordinate is written relative to them.
 */
#define DB_X(n) (gui_screen_x_offset() + (n))
#define DB_Y(n) (gui_screen_y_offset() + (n))

/* dashboard.c */
extern uint8_t notes_index;
extern uint8_t stocks_index;
extern uint8_t news_index;
extern uint8_t calendar_index;
int ui_new_message_come_on_task(struct jbd_panel_context *panel, void *arg, int event);
void dashboard_draw_add_note_hint(void);
void dashboard_draw_add_note_hint_wide(void);
void init_dashboard_info(struct dashboard_ts_context *ts);
uint8_t getNotesIndex(void);
int setNotesIndex(int idx);
void cleanNotesIndex(void);
uint8_t get_pane_mode(void);
/* align-2 helpers (0x806e4..0x80802) */
void update_dashboard_clock(struct GlassesState *gs, uint32_t *total_s);
uint32_t get_dashboard_tx_ctx(void);
int draw_template_dashboard_page(struct jbd_panel_context *panel, void *arg);
int draw_template_schedule_page(struct jbd_panel_context *panel, void *arg);
int power_info_battery_ok(void);
void DashBoard_Reflash(struct db_info *db, struct GlassesState *gs, int refresh,
		       uint8_t display_mode);
uint8_t getStocksIndex(void);
int setStocksIndex(int idx);
void cleanStocksIndex(void);
uint8_t getNewsIndex(void);
int setNewsIndex(int idx);
void cleanNewsIndex(void);
uint8_t getCalenadrIndex(void);
int setCalenadrIndex(int idx);
void cleanCalenadrIndex(void);
void set_screen_cleared(void);
int send_message_count_to_app(void);
int sync_dashboard_key_event_to_app(void);
int ui_DashBoard_task(struct jbd_panel_context *panel, void *arg, int event);

#endif /* G1_DASHBOARD_H_ */

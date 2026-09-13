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

/* print without the LOG_LEVEL check / "%s(): " prefix */
#define BLE_PRINTK(fmt, ...)                                                   \
	do {                                                                   \
		if (BLE_DEBUG) {                                               \
			ble_printk(fmt, ##__VA_ARGS__);                        \
		} else {                                                       \
			printk(fmt, ##__VA_ARGS__);                            \
		}                                                              \
	} while (0)

/* JBD panel context (GlassesState + 0xb6c), partial */
struct jbd_panel_context {
	void *cb[9];                /* 0x000 */
	uint8_t *panel_buffer[200]; /* 0x024 frame buffer row pointers */
	uint8_t *current_buffer;    /* 0x344 */
	uint32_t current_row;       /* 0x348 */
	uint32_t current_column;    /* 0x34c */
};

/* GlassesState->dashboard_ts (0xff0), partial */
struct db_ts_context {
	uint32_t ts;            /* 0x00 */
	uint8_t f_04;           /* 0x04 */
	uint8_t f_05;           /* 0x05 */
	uint64_t f_06;          /* 0x06 uptime ms base */
	uint8_t pad_0e[0x5d - 0x0e];
	uint8_t temp_unit;      /* 0x5d: 0 = Celsius, else Fahrenheit */
	uint8_t time_disp_mode; /* 0x5e: 1 = 12h */
	uint8_t pad_5f;
	uint8_t low_power;      /* 0x60 */
	uint8_t pad_61[0x65 - 0x61];
	uint8_t f_65;           /* 0x65 */
	uint8_t f_66;           /* 0x66 */
	uint8_t pad_67[0x71 - 0x67];
	uint8_t f_71;           /* 0x71 */
	uint8_t pad_72;
	uint8_t dashboard_on;   /* 0x73 */
	uint8_t f_74;           /* 0x74 */
} __packed;

/*
 * Dashboard info block (GlassesState + 0xef, packed), filled from the
 * phone's dashboard packets.
 */
struct db_info {
	uint8_t pad_00[4];
	uint8_t weather_icon; /* 0x04: 0 / 0xff = none */
	int8_t temperature;   /* 0x05: Celsius */
	uint8_t pad_06;
	uint8_t new_msg_count; /* 0x07 (GS + 0xf6, "new message" page) */
	uint8_t pad_08[0x5f - 0x08];
	uint8_t date_format; /* 0x5f: 0 = mm/dd, 1 = dd-mm, else dd/mm */
	uint8_t f_60;        /* 0x60: 1 = show the 0x42 icon */
	uint8_t pad_61[0x65 - 0x61];
	uint8_t display_mode;       /* 0x65 */
	uint8_t pane_mode;          /* 0x66 */
	uint8_t calendar_disp_mode; /* 0x67 */
	uint8_t pad_68;
	uint8_t stocks_disp_mode;   /* 0x69 */
	uint8_t news_disp_mode;     /* 0x6a */
	uint8_t citywalk_disp_mode; /* 0x6b */
	uint8_t pad_6c;
	uint16_t citywalk_x;   /* 0x6d */
	uint16_t citywalk_y;   /* 0x6f */
	uint8_t citywalk_f_71; /* 0x71 */
	uint8_t pad_72;
	uint8_t f_73;          /* 0x73 (GS + 0x162) */
} __packed;

/* quick note entry (GlassesState->ptr_1030[4]) */
struct db_quick_note {
	uint8_t pad_00[3];
	uint8_t valid;           /* 0x03 */
	char title[0x29];        /* 0x04 */
	char text[0x143 - 0x2d]; /* 0x2d */
};

/* GlassesState->user_sched_info (0xff8), partial */
struct db_user_sched {
	uint8_t pad_000[0x164];
	uint32_t ts; /* 0x164: time stamp from the phone (0 = none) */
};

/* Partial view of the global vendor state (struct GlassesState, 0x1248 B) */
struct GlassesState {
	uint8_t is_master; /* 0x000 */
	uint8_t pad_001[0x0d0 - 0x001];
	uint32_t date_ts; /* 0x0d0 (FUN_00080732) */
	uint8_t pad_0d4[0x0dd - 0x0d4];
	uint8_t unread_msg_num; /* 0x0dd master_sync_pkg.panel_data_pkg */
	uint8_t pad_0de[0x0ef - 0x0de];
	struct db_info db_info; /* 0x0ef */
	uint8_t pad_161[0xb6c - 0x0ef - sizeof(struct db_info)];
	struct jbd_panel_context panel; /* 0xb6c */
	uint8_t pad_ebc[0xec4 - 0xb6c - sizeof(struct jbd_panel_context)];
	int x_offset; /* 0xec4 */
	uint8_t pad_ec8[0xfc4 - 0xec8];
	uint8_t battery_left;  /* 0xfc4 */
	uint8_t battery_right; /* 0xfc5 */
	uint8_t pad_fc6[0xff0 - 0xfc6];
	struct db_ts_context *dashboard_ts; /* 0xff0 */
	uint8_t pad_ff4[0xff8 - 0xff4];
	struct db_user_sched *user_sched_info; /* 0xff8 */
	uint8_t pad_ffc[0x1030 - 0xffc];
	struct db_quick_note (*quick_notes)[4]; /* 0x1030: the 4 quick notes */
	uint8_t pad_1034[0x108a - 0x1034];
	uint16_t x_shift_108a; /* 0x108a */
	uint16_t y_shift_108c; /* 0x108c */
	uint8_t pad_108e[0x1247 - 0x108e];
	uint8_t f_1247; /* 0x1247 */
};

BUILD_ASSERT(offsetof(struct GlassesState, date_ts) == 0xd0);
BUILD_ASSERT(offsetof(struct GlassesState, db_info) == 0xef);
BUILD_ASSERT(offsetof(struct GlassesState, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct GlassesState, panel.panel_buffer) == 0xb90);
BUILD_ASSERT(offsetof(struct GlassesState, panel.current_row) == 0xeb4);
BUILD_ASSERT(offsetof(struct GlassesState, x_offset) == 0xec4);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, quick_notes) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, x_shift_108a) == 0x108a);
BUILD_ASSERT(offsetof(struct GlassesState, f_1247) == 0x1247);
BUILD_ASSERT(offsetof(struct GlassesState, unread_msg_num) == 0xdd);
BUILD_ASSERT(offsetof(struct GlassesState, db_info.new_msg_count) == 0xf6);
BUILD_ASSERT(offsetof(struct GlassesState, db_info.f_73) == 0x162);
BUILD_ASSERT(offsetof(struct GlassesState, battery_left) == 0xfc4);
BUILD_ASSERT(offsetof(struct db_ts_context, low_power) == 0x60);
BUILD_ASSERT(offsetof(struct db_ts_context, dashboard_on) == 0x73);

struct GlassesState *get_dashboard_state(void);

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

/* phone data buffers (filled by ble_process_put_req) */
struct db_stock {
	uint8_t valid; /* 0x000 */
	uint8_t trend; /* 0x001: 0 / 1 / 2 */
	uint8_t pad_002[2];
	char name[0x20];             /* 0x004 */
	char full_name[0x40];        /* 0x024 */
	char price[0x10];            /* 0x064 */
	char change[0x10];           /* 0x074 */
	char percent[0x10];          /* 0x084 */
	uint8_t chart[0x7f2 - 0x94]; /* 0x094 */
} __packed;

struct db_news {
	uint8_t valid;           /* 0x000 */
	char title[0x40];        /* 0x001 */
	char body[0x159 - 0x41]; /* 0x041 */
} __packed;

struct db_calendar {
	uint8_t valid;       /* 0x00 */
	char title[0x41];    /* 0x01 */
	char time[0x21];     /* 0x42 */
	char location[0x41]; /* 0x63 */
} __packed;

extern struct db_stock DAT_2000e104[4];
extern struct db_news DAT_20011281[4];
extern struct db_calendar DAT_2001252f[8];
extern volatile uint8_t DAT_2001111d; /* citywalk map valid */
extern uint8_t DAT_200143cf[];        /* citywalk map bitmap */
extern uint8_t DAT_20015cc7[];        /* citywalk arrow (narrow layout) */
extern uint8_t DAT_20015777[];        /* citywalk arrow (wide layout) */

extern atomic_t gui_flags; /* 0x2000aa10, bit 1: notification showing */

/*
 * Screen origin helpers (align-2, owned by the gui file):
 * gui_screen_x_offset() = panel x offset (GS+0xec4) + GS->x_shift_108a (reset to 0x20
 * when out of range), gui_screen_y_offset() = GS->y_shift_108c (clamped to 4..0x40).
 * Every dashboard coordinate is written relative to them.
 */
int gui_screen_x_offset(void);
uint16_t gui_screen_y_offset(void);
#define DB_X(n) (gui_screen_x_offset() + (n))
#define DB_Y(n) (gui_screen_y_offset() + (n))

/* this file, align-2 helpers (0x806e4..0x80802) */
void FUN_000806e4(struct GlassesState *gs, uint32_t *total_s);
struct db_ts_context;
uint32_t get_dashboard_tx_ctx(void);
void FUN_00016614(uint32_t ts);
void FUN_0004d494(uint32_t *total_s, int idx, int restart);
int day_of_week(int year, int month, int day); /* day of week (Zeller) */


typedef int (*gui_effect_cb_t)(int arg, const char *str, int font, int x, int y);
int gui_screen_clear(void);
int gui_area_clear(int x_start, int y_start, int x_end, int y_end);
int _clean_fb_data(uint8_t **fb, int val, int x_start, int y_start, int x_end, int y_end);
int _reflash_fb_data_to_lcd(uint32_t row, uint32_t column, int x_start, int y_start, int x_end,
			    int y_end);
int gui_clock_draw(uint32_t ts, int x0, int y0, int x1, int y1, int mode, bool is_24h);
int gui_bmp_bitmap_draw(int id, int x, int y, int effect, gui_effect_cb_t cb, int no_draw);
int gui_bitmap_draw(int x0, int y0, int x1, int y1, const uint8_t *data, uint8_t color);
int gui_1bit_bitmap_override(int x0, int y0, int x1, int y1, const uint8_t *data, uint8_t color);
int gui_string_draw(int font, const char *str, int x0, int y0, int x1, int y1, int *width);
int gui_utf_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		 uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
		 int no_draw);
int gui_utf_draw_middle(int arg, const char *str, int font, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
			uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			int no_draw);
int gui_utf_draw_align_right(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			     uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			     int no_draw);
int gui_utf_draw_dark_light_split(int arg, const char *str, int font, int x0, int y0, int x1,
				  int y1, uint32_t max_lines, uint16_t color, int effect,
				  gui_effect_cb_t cb, int no_draw);
uint8_t get_current_language(void);
const char *get_string(uint8_t string_id);

int weather_icon_to_bitmap(int weather_icon); /* weather icon -> bitmap id */
int FUN_00035310(void);             /* unread message count (vendor: implicit declaration) */
uint8_t FUN_00028d2c(void);         /* BLE connected (1) */
uint8_t FUN_00030440(void);
void FUN_00030458(void);
void FUN_0008040c(void);
void FUN_00038b00(void);
void dashboard_draw_add_note_hint(void);
void dashboard_draw_add_note_hint_wide(void);
void cleanStocksIndex(void);
void cleanNewsIndex(void);
void cleanCalenadrIndex(void);

/* notification / gui / app sync (other modules) */
extern const uint8_t gui_fade_mask[26][8][GUI_FB_ROW_BYTES];
extern atomic_t DAT_20007f4c; /* dashboard lock bits (ble_proto) */
extern atomic_t DAT_20007f50;
extern atomic_t DAT_20008480; /* imu/dashboard lock bits */
int set_frame_buffer(uint8_t **fb);
int set_showing_notification_on_gui(void);
int clear_showing_notification_on_gui(void);
int gui_screen_fade_out(void);
uint8_t FUN_00035a78(void);
uint8_t parse_message_type(int idx);
int is_ncs_mem_initialized(void);
void FUN_000166f8(void);
void FUN_000167cc(uint8_t idx);
void FUN_0004d4dc(uint64_t ms);
int getQuickNoteDataFromFlash(uint32_t idx, void *title, int title_len, void *text,
			      int text_len);
int sync_to_slave(struct GlassesState *gs, int cmd, void *data, size_t len);
int send_response_data_to_msgqueue(const void *data, uint32_t len);
int send_response_data_to_ble(void);
void FUN_00029774(int arg);
void enter_dashboard_burial_point(void);
void exit_dashboard_burial_point(void);
int set_display_wait_ms(int ms);
int SendPowerInfoToSlave(uint8_t on);

/* this file */
extern uint8_t notes_index;
extern uint8_t stocks_index;
extern uint8_t news_index;
extern uint8_t calendar_index;
uint8_t getNotesIndex(void);
uint8_t getStocksIndex(void);
uint8_t getNewsIndex(void);
uint8_t getCalenadrIndex(void);
void set_screen_cleared(void);
int send_message_count_to_app(void);
int sync_dashboard_key_event_to_app(void);
int power_info_battery_ok(void);

void DashBoard_Reflash(struct db_info *db, struct GlassesState *gs, int refresh,
		       uint8_t display_mode);

#endif /* G1_DASHBOARD_H_ */

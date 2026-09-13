/*
 * UI screen tasks (dashboard task, quick note, Even AI, bitmap,
 * teleprompter, navigation maps) - module private declarations.
 * Partial views of vendor structures, reconstructed from the v1.63 app core.
 */
#ifndef G1_UI_A_H_
#define G1_UI_A_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
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

/* GlassesState->dashboard_ts (0xff0), partial */
struct ui_dash_ts {
	uint8_t pad_00[0x5e];
	uint8_t time_disp_mode;          /* 0x5e */
	uint8_t pad_5f;
	uint8_t low_power;               /* 0x60 */
	uint8_t pad_61[4];
	uint8_t f_65;                    /* 0x65 */
	uint8_t f_66;                    /* 0x66 */
	uint8_t pad_67[0x73 - 0x67];
	uint8_t dashboard_on;            /* 0x73 */
};

/* dashboard info sent by the phone (GlassesState + 0xef) */
struct ui_db_info {
	uint8_t pad_00[0x65];
	uint8_t current_index;           /* 0x65 (GS + 0x154) */
	uint8_t pad_66;
	uint8_t schedule_disp_status;    /* 0x67 (GS + 0x156) */
	uint8_t pad_68;
	uint8_t stocks_disp_mode;        /* 0x69 (GS + 0x158) */
	uint8_t news_disp_mode;          /* 0x6a (GS + 0x159) */
	uint8_t citywalk_disp_mode;      /* 0x6b (GS + 0x15a) */
	uint8_t pad_6c[0x73 - 0x6c];
	uint8_t f_73;                    /* 0x73 (GS + 0x162) */
};

/* GlassesState->quicknote_show_info (0x1034) */
struct quicknote_show_info {
	uint8_t f_0;
	uint8_t enable;                  /* 0x01 */
};

/* GlassesState->temeprompter_info (0x1000), 0x217 bytes */
struct teleprompter_info {
	uint8_t f_0;
	uint8_t enable;                  /* 0x01 */
};

/* GlassesState->bitmap_info (0x1018), packed */
struct bitmap_show_info {
	uint8_t enable;                  /* 0x00 */
	uint8_t sync_pending;            /* 0x01 */
	uint8_t mode;                    /* 0x02 */
	int64_t deadline;                /* 0x03 */
} __packed;

/* Partial view of the global vendor state (struct GlassesState, main.h) */
struct ui_gs {
	uint8_t is_master;               /* 0x000 1 master (left), 2 slave */
	uint8_t pad_001[0x68 - 0x001];
	struct k_sem main_sem;           /* 0x068 */
	uint8_t pad_080[0xcd - 0x080];
	uint8_t esb_down_id;             /* 0x0cd */
	uint8_t pad_0ce[0xd0 - 0xce];
	uint32_t now;                    /* 0x0d0 */
	uint8_t pad_0d4;
	uint8_t dashboard_mode;          /* 0x0d5 (7: do-not-disturb page) */
	uint8_t pad_0d6[0xef - 0xd6];
	union {
		uint8_t buf[0x5dc];      /* 0x0ef screen payload */
		struct ui_db_info db;
		struct {
			uint8_t f_00;
			uint8_t sub_mode;        /* 0x0f0 */
			uint8_t page;            /* 0x0f1 */
			uint8_t status;          /* 0x0f2 */
			uint8_t mode;            /* 0x0f3 */
			uint8_t f_05;            /* 0x0f4 */
			uint8_t pad_06[2];
			char text[0x5dc - 8];    /* 0x0f7 */
		} __packed qn;
		struct {
			uint8_t status;          /* 0x0ef */
			uint8_t sub_status;      /* 0x0f0 (read under k_mutex_2000851c) */
			uint8_t pad_02[2];
			uint8_t percent;         /* 0x0f3 */
			uint8_t hide_bar;        /* 0x0f4 */
			uint8_t page;            /* 0x0f5 */
			char text[0x1e0];        /* 0x0f6 */
			uint16_t text_len;       /* 0x2d6 */
		} __packed ai;
		struct {
			uint8_t work_mode;       /* 0x0ef */
			uint8_t cmd;             /* 0x0f0 */
			uint8_t pad_02[8];
			uint8_t status;          /* 0x0f9 */
			uint8_t pad_0b;
			int8_t countdown;        /* 0x0fb */
			uint8_t percent;         /* 0x0fc */
			uint16_t dark_lines;     /* 0x0fd */
			uint8_t suspend;         /* 0x0ff */
			int32_t suspend_time;    /* 0x100 */
			uint8_t pad_15[2];
			char text[0x200];        /* 0x106 */
		} __packed tp;
	} ui;
	uint8_t pad_6cb[0xb6c - 0x6cb];
	struct jbd_panel_context panel;  /* 0xb6c */
	uint8_t pad_ecc[0xfc4 - 0xb6c - sizeof(struct jbd_panel_context)];
	uint8_t battery_left;            /* 0xfc4 */
	uint8_t battery_right;           /* 0xfc5 */
	uint8_t pad_fc6[0xff0 - 0xfc6];
	struct ui_dash_ts *dashboard_ts; /* 0xff0 */
	uint8_t pad_ff4[0x1000 - 0xff4];
	struct teleprompter_info *tp_info; /* 0x1000 */
	uint8_t pad_1004[0x1018 - 0x1004];
	struct bitmap_show_info *bitmap_info; /* 0x1018 */
	uint8_t pad_101c[0x1034 - 0x101c];
	struct quicknote_show_info *quicknote_show_info; /* 0x1034 */
	uint8_t pad_1038[0x1060 - 0x1038];
	uint32_t dashboard_cmd;          /* 0x1060 */
	uint8_t pad_1064[0x106d - 0x1064];
	uint8_t pending;                 /* 0x106d */
	uint8_t pad_106e[0x1247 - 0x106e];
	uint8_t f_1247;                  /* 0x1247 */
};

BUILD_ASSERT(offsetof(struct ui_gs, main_sem) == 0x68);
BUILD_ASSERT(offsetof(struct ui_gs, esb_down_id) == 0xcd);
BUILD_ASSERT(offsetof(struct ui_gs, now) == 0xd0);
BUILD_ASSERT(offsetof(struct ui_gs, ui) == 0xef);
BUILD_ASSERT(offsetof(struct ui_gs, ui.db.current_index) == 0x154);
BUILD_ASSERT(offsetof(struct ui_gs, ui.db.f_73) == 0x162);
BUILD_ASSERT(offsetof(struct ui_gs, ui.qn.status) == 0xf2);
BUILD_ASSERT(offsetof(struct ui_gs, ui.qn.text) == 0xf7);
BUILD_ASSERT(offsetof(struct ui_gs, ui.ai.text_len) == 0x2d6);
BUILD_ASSERT(offsetof(struct ui_gs, ui.tp.text) == 0x106);
BUILD_ASSERT(offsetof(struct ui_gs, tp_info) == 0x1000);
BUILD_ASSERT(offsetof(struct ui_gs, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct ui_gs, panel.current_row) == 0xeb4);
BUILD_ASSERT(offsetof(struct ui_gs, battery_left) == 0xfc4);
BUILD_ASSERT(offsetof(struct ui_gs, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct ui_gs, bitmap_info) == 0x1018);
BUILD_ASSERT(offsetof(struct ui_gs, quicknote_show_info) == 0x1034);
BUILD_ASSERT(offsetof(struct ui_gs, dashboard_cmd) == 0x1060);
BUILD_ASSERT(offsetof(struct ui_gs, pending) == 0x106d);
BUILD_ASSERT(offsetof(struct ui_gs, f_1247) == 0x1247);

#define UI_GS() ((struct ui_gs *)get_dashboard_state())

/* dashboard/dashboard.c (owns struct dashboard_prv_data _dashboard_prv_data, see dashboard.h) */
void DashBoard_Reflash(struct ui_db_info *db, struct GlassesState *gs, int refresh,
		       uint8_t display_mode);
uint8_t getNotesIndex(void);
uint8_t getStocksIndex(void);
uint8_t getNewsIndex(void);
uint8_t getCalenadrIndex(void);
extern uint8_t notes_index;
extern uint8_t stocks_index;
extern uint8_t news_index;
extern uint8_t calendar_index;

/* other modules */
extern atomic_t DAT_20007f4c;     /* dashboard lock bits (ble_proto) */
extern atomic_t DAT_20007f50;
extern atomic_t DAT_20008480;     /* imu/dashboard lock bits */
extern atomic_t DAT_20008558;     /* audio stream record running */
extern struct k_mutex k_mutex_2000851c;
uint8_t FUN_00035310(void);       /* unread message count */
int sync_to_slave(struct GlassesState *gs, int cmd, void *data, size_t len);
int FUN_000294d0(struct GlassesState *gs, int cmd, void *data, size_t len);
int send_response_data_to_msgqueue(const void *data, uint32_t len);
int send_response_data_to_ble(void);
void FUN_00029774(int arg);
void FUN_000167cc(uint8_t idx);
void enter_dashboard_burial_point(void);
void exit_dashboard_burial_point(void);
int set_display_wait_ms(int ms);
int get_display_delay_close_ms(void);
uint8_t FUN_00028d2c(void);
uint8_t FUN_00030440(void);
void FUN_00030458(void);
void FUN_0008040c(void);
int SendPowerInfoToSlave(uint8_t on);
/* FUN_00080732 (uint32_t now) is declared in gui.h with a pointer return type */
int FUN_00030b28(void);
int startAudioStreamRecord(void);
int stopAudioStreamRecord(void);
void update_persist_task_status(struct GlassesState *gs, int task, int status);

/* gui (gui.c) prototypes not in gui.h */
int gui_bitmps_merge_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp1, const uint8_t *bmp2,
			  uint8_t color1, uint8_t color2);
int gui_4bit_bitmap_override(int id, uint32_t x, uint32_t y);
/* int return like the vendor prototype (the body never returns a value; the int call_value
 * pattern changes IRA costs in ui_even_ai_task, see agent_notes/ui_even_ai_task.md) */
int gui_utf_draw_scroll_line(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		  uint32_t max_lines, uint32_t dark_cnt);

/* ui_bitmap.c */
void FUN_00080852(uint8_t mode);

/* dashboard/dashboard.c */
void set_screen_cleared(void);
int send_message_count_to_app(void);
int sync_dashboard_key_event_to_app(void);
int power_info_battery_ok(void);

/* text_anim / text_anim_buf (text animation): see gui.h */

extern int DAT_20007f44;          /* ble_proto: app sync request seen */
extern uint8_t DAT_20010f05;      /* ble_proto: teleprompter text scrolled */

/* ui_quicknote.c */
extern uint8_t quicknote_result_shown;
void dmic_record_start(void);
void quicknote_stop_record(void);
void FUN_0003d7b4(void);

#endif /* G1_UI_A_H_ */

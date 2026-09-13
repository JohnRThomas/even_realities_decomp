/*
 * Display thread (UI framework dispatcher): private declarations.
 * Partial views of vendor structures, reconstructed from the v1.63 app core.
 */
#ifndef G1_DISPLAY_THREAD_H_
#define G1_DISPLAY_THREAD_H_

#include <stdint.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>

struct GlassesState;
struct jbd_panel_context;

/* message posted to display_msgq (24 bytes) */
enum disp_msg_type {
	DISP_MSG_OPEN = 2,         /* display_reflash() */
	DISP_MSG_CLOSE = 3,        /* display_close() */
	DISP_MSG_DELAY_CLOSE = 4,  /* display_DelayClose() */
	DISP_MSG_INPUT = 5,        /* display_inputEvent() */
	DISP_MSG_MASTER_CLOSE = 6, /* display_MasterSendClose() */
	DISP_MSG_POWER_ON = 7,     /* display_powerEvent(1) */
	DISP_MSG_POWER_OFF = 8,    /* display_powerEvent(!1) */
};

struct disp_msg {
	uint8_t type;      /* 0x00 enum disp_msg_type */
	uint8_t pad_01;
	uint16_t len;      /* 0x02 payload length */
	uint8_t data[20];  /* 0x04 payload: [0] = 1 valid, [1] = screen id */
};

/* UI process (event) passed to the ui_*_task() handlers */
enum disp_ui_event {
	DISP_UI_REFRESH = 0,
	DISP_UI_ENTER = 1,
	DISP_UI_EXIT = 2,
	DISP_UI_DELAY_CLOSE = 3,
	DISP_UI_INPUT = 4,
	DISP_UI_MASTER_CLOSE = 5,
	DISP_UI_POWER_ON = 6,
	DISP_UI_POWER_OFF = 7,
};

/* display thread state machine */
struct disp_state {
	uint8_t state;      /* 0 idle, 1 running, 2 closing */
	uint8_t screen_id;  /* screen id of the running UI application */
};

/* Head of struct jbd_panel_context (GlassesState + 0xb6c) */
struct disp_panel {
	void *cb[5];                                           /* 0x00 */
	int (*default_task)(struct disp_panel *panel, int screen_id, void *ctx); /* 0x14 */
	void *cb2[3];                                          /* 0x18 */
	uint8_t *panel_buffer[1];                              /* 0x24 */
};

/* Partial view of the global vendor state (struct GlassesState) */
struct disp_gs {
	uint8_t is_master;                /* 0x000 */
	uint8_t esb_state;                /* 0x001 (1 and 8 = ESB busy) */
	uint8_t pad_002[0x0d4 - 0x002];
	uint8_t sync_cmd;                 /* 0x0d4 last sync package (ctx of the UI tasks) */
	volatile uint8_t screen_id;       /* 0x0d5 */
	uint8_t pad_0d6[0x0ef - 0x0d6];
	uint8_t buf_0ef[0x5dc];           /* 0x0ef */
	uint8_t pad_6cb[0xb6c - 0x6cb];
	struct disp_panel panel;          /* 0xb6c jbd_panel_context */
	uint8_t pad_b94[0x1010 - 0xb6c - sizeof(struct disp_panel)];
	uint8_t *even_ai_state;           /* 0x1010 */
} __aligned(8);

BUILD_ASSERT(offsetof(struct disp_gs, screen_id) == 0x0d5);
BUILD_ASSERT(offsetof(struct disp_gs, buf_0ef) == 0x0ef);
BUILD_ASSERT(offsetof(struct disp_gs, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct disp_gs, panel.default_task) == 0xb80);
BUILD_ASSERT(offsetof(struct disp_gs, panel.panel_buffer) == 0xb90);
BUILD_ASSERT(offsetof(struct disp_gs, even_ai_state) == 0x1010);

struct GlassesState *get_dashboard_state(void);
#define DISP_GS() ((struct disp_gs *)get_dashboard_state())

/* other modules */
uint8_t FUN_00033d5c(void);   /* test (production) mode */
int set_frame_buffer(uint8_t **fb);
void jbd_clear_cache_sync(int val);   /* clear panel cache + sync */
void FUN_00037824(void);
int FUN_00038270(struct jbd_panel_context *panel, void *arg, int event);

int ui_ancs_notificaton_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_new_message_come_on_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_DashBoard_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_bitmap_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_teleprompter_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_navigation_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_translate_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_QuickNote_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_onboarding_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_raster_height_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_even_ai_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_set_imu_pitch_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_prompt_info_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_transcribe_info_task(struct jbd_panel_context *panel, void *arg, int event);
int ui_even_ai_v2_info_task(struct jbd_panel_context *panel, void *arg, int event);

/* this file */
extern int DAT_2000aa78;      /* screen id of the last ui_task_handler() call */
int set_display_wait_ms(int ms);
int ui_task_handler(struct disp_gs *gs, int screen_id, void *ctx, int event);
int display_reflash_handler(struct disp_gs *gs, int screen_id, void *ctx, int event);
void display_timer_stop(void);
int get_display_delay_close_ms(void);
void display_thread_boost_priority(void);
void display_thread_restore_priority(void);
void display_thread_handler(struct disp_gs *gs);
int start_display_thread_handler(struct disp_gs *gs);
int display_reflash(const void *data, uint32_t len);
int display_close(const void *data, uint32_t len);
int display_close_screen(int screen_id);
int display_DelayClose(int ms);
int display_inputEvent(uint8_t a, uint8_t b);
int display_MasterSendClose(void);
int display_powerEvent(int on);
int FUN_00080fca(uint8_t screen_id);

#endif /* G1_DISPLAY_THREAD_H_ */

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
#include <glasses_state.h>

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

/* display_thread.c */
extern int last_ui_screen_id;      /* screen id of the last ui_task_handler() call */
int set_display_wait_ms(int ms);
int ui_task_handler(struct GlassesState *gs, int screen_id, void *ctx, int event);
int display_reflash_handler(struct GlassesState *gs, int screen_id, void *ctx, int event);
void display_timer_stop(void);
int get_display_delay_close_ms(void);
void display_thread_boost_priority(void);
void display_thread_restore_priority(void);
void display_thread_handler(struct GlassesState *gs);
int start_display_thread_handler(struct GlassesState *gs);
int display_reflash(const void *data, uint32_t len);
int display_close(const void *data, uint32_t len);
int display_close_screen(int screen_id);
int display_DelayClose(int ms);
int display_inputEvent(uint8_t a, uint8_t b);
int display_MasterSendClose(void);
int display_powerEvent(int on);
int display_reflash_screen(uint8_t screen_id);

#endif /* G1_DISPLAY_THREAD_H_ */

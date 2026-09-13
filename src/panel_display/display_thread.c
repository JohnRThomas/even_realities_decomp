/*
 * Display thread: the UI framework dispatcher.  Other threads post
 * open / close / input / power messages to display_msgq; the display thread
 * keeps track of the running UI application (screen id) and calls the
 * matching ui_*_task() handler.
 * Reconstructed from the v1.63 firmware image.
 */
#include <errno.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "display_thread.h"

#define DISPLAY_MSG_MAX_LEN 10

K_MSGQ_DEFINE(display_msgq, sizeof(struct disp_msg), 30, 4);

static K_THREAD_STACK_DEFINE(display_stack, 0x1400);
static struct k_thread display_thread;
static struct k_timer display_timer;

static k_tid_t display_tid;
int DAT_2000aa78;
static int display_delay_close_ms;

static int display_wait_ms = 0x42;

static struct disp_state disp_state;
static uint8_t display_prio_boosted;

int set_display_wait_ms(int ms)
{
	ms = MIN(ms, 0x7d);
	ms = MAX(ms, 0x21);
	display_wait_ms = ms;
	return 0;
}

int ui_task_handler(struct disp_gs *gs, int screen_id, void *ctx, int event)
{
	struct jbd_panel_context *panel;

	if (FUN_00033d5c() == 1) {
		if (screen_id == 3) {
			FUN_00038270((struct jbd_panel_context *)&gs->panel, ctx, event);
		}
		return 0;
	}

	panel = (struct jbd_panel_context *)&gs->panel;
	DAT_2000aa78 = screen_id;

	switch (screen_id) {
	case 7:
		return ui_bitmap_task(panel, ctx, event);
	case 9:
		return ui_teleprompter_task(panel, ctx, event);
	case 6:
		return ui_DashBoard_task(panel, ctx, event);
	case 12:
		return ui_QuickNote_task(panel, ctx, event);
	case 11:
		return ui_translate_task(panel, ctx, event);
	case 16:
		return ui_even_ai_task(panel, ctx, event);
	case 20:
		return ui_even_ai_v2_info_task(panel, ctx, event);
	case 10:
		return ui_navigation_task(panel, ctx, event);
	case 4:
		return ui_ancs_notificaton_task(panel, ctx, event);
	case 5:
		return ui_new_message_come_on_task(panel, ctx, event);
	case 14:
		return ui_onboarding_task(panel, ctx, event);
	case 15:
		return ui_raster_height_task(panel, ctx, event);
	case 17:
		return ui_set_imu_pitch_task(panel, ctx, event);
	case 18:
		return ui_prompt_info_task(panel, ctx, event);
	case 19:
		return ui_transcribe_info_task(panel, ctx, event);
	default:
		return gs->panel.default_task(&gs->panel, gs->screen_id, &gs->sync_cmd);
	}
}

int display_reflash_handler(struct disp_gs *gs, int screen_id, void *ctx, int event)
{
	if (event == DISP_UI_EXIT) {
		if (screen_id != disp_state.screen_id && disp_state.screen_id != 0) {
			G1_LOG_ERR("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			G1_LOG_ERR("The wrong screen ID has appeared, and the exception handling is "
				   "closed,The message ID at startup is %d. The current message ID is%d\n",
				   disp_state.screen_id, screen_id);
			G1_LOG_ERR("To perform exception handling, close the previous SCREEN ID = %d UI "
				   "application first\n",
				   disp_state.screen_id);
			ui_task_handler(gs, screen_id, ctx, DISP_UI_EXIT);
			return -1;
		}
	} else if (event == DISP_UI_ENTER) {
		if (screen_id != disp_state.screen_id && disp_state.screen_id != 0) {
			G1_LOG_ERR("------------------------------------------------------------------"
				   "----------------------\n");
			G1_LOG_ERR("There is a screen ID error. The previous screen iD was %d, the "
				   "current screen ID is %d, and the UI process to be performed is %d\n",
				   disp_state.screen_id, screen_id, DISP_UI_ENTER);
			G1_LOG_ERR("The UI framework closes the opened UI application first, and the "
				   "closed application ScreenID is %d\n",
				   disp_state.screen_id);
			ui_task_handler(gs, disp_state.screen_id, ctx, DISP_UI_EXIT);
			G1_LOG_ERR("Because ScreenID has changed, close the old screenID application "
				   "first and update the backup value of screenID to %d\n",
				   screen_id);
			disp_state.screen_id = screen_id;
		}
	} else if (screen_id != disp_state.screen_id) {
		G1_LOG_ERR("******************************************************************"
			   "*******************************\n");
		G1_LOG_ERR("There is a screen ID error. The previous screen iD was %d, the "
			   "current screen ID is %d, and the UI process to be performed is %d\n",
			   disp_state.screen_id, screen_id, event);
	}

	ui_task_handler(gs, screen_id, ctx, event);
	return 0;
}

void display_timer_stop(void)
{
	k_timer_stop(&display_timer);
}

int get_display_delay_close_ms(void)
{
	return display_delay_close_ms;
}

void display_thread_boost_priority(void)
{
	k_thread_priority_set(display_tid, -16);
	display_prio_boosted = 1;
}

void display_thread_restore_priority(void)
{
	if (display_prio_boosted == 1) {
		k_thread_priority_set(display_tid, -14);
		display_prio_boosted = 0;
	}
}

static void display_timer_expiry(struct k_timer *timer)
{
	display_reflash(NULL, 0);
}

void display_thread_handler(struct disp_gs *gs)
{
	struct disp_msg msg;
	volatile uint8_t received;
	void *ctx = &gs->sync_cmd;
	int ret;

	memset(&msg, 0, sizeof(msg));
	received = 0;
	k_timer_init(&display_timer, display_timer_expiry, NULL);
	set_frame_buffer(gs->panel.panel_buffer);
	memset(&disp_state, 0, sizeof(disp_state));

	for (;;) {
		if (gs->esb_state == 1 || gs->esb_state == 8) {
			k_sleep(K_MSEC(5000));
			continue;
		}
		memset(&msg, 0, sizeof(msg));
		received = 0;
		ret = k_msgq_get(&display_msgq, &msg, K_MSEC(display_wait_ms));
		if (ret == 0) {
			received = 1;
		} else if (ret == -ENOMSG || ret == -EAGAIN) {
			received = 0;
		}

		switch (disp_state.state) {
		case 0:
			if (received != 1) {
				break;
			}
			received = 0;
			if (msg.type == DISP_MSG_OPEN) {
				if (gs->screen_id == 16 && *DISP_GS()->even_ai_state < 12) {
					jbd_clear_cache_sync(0);
				}
				if (msg.len == 0) {
					disp_state.screen_id = gs->screen_id;
					display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_ENTER);
					disp_state.state = 1;
				} else if (msg.len == 2) {
					if (msg.data[0] == 1) {
						disp_state.screen_id = msg.data[1];
						display_reflash_handler(gs, msg.data[1], ctx,
									DISP_UI_ENTER);
						disp_state.state = 1;
					} else {
						G1_LOG_ERR("---screen ID message parampter error!\n");
					}
				}
				display_thread_restore_priority();
			} else if (msg.type == DISP_MSG_CLOSE) {
				memset(&disp_state, 0, sizeof(disp_state));
				if (msg.len == 0) {
					display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_EXIT);
				} else if (msg.len == 2) {
					if (msg.data[0] == 1) {
						display_reflash_handler(gs, msg.data[1], ctx,
									DISP_UI_EXIT);
					} else {
						G1_LOG_ERR("exit .screen ID message parampter error!\n");
						display_reflash_handler(gs, gs->screen_id, ctx,
									DISP_UI_EXIT);
					}
				}
				display_thread_restore_priority();
			}
			break;
		case 1:
			if (received == 1) {
				received = 0;
				if (msg.type == DISP_MSG_OPEN) {
					if (msg.len == 0) {
						display_reflash_handler(gs, gs->screen_id, ctx,
									DISP_UI_ENTER);
					} else if (msg.len == 2) {
						if (msg.data[0] == 1) {
							display_reflash_handler(gs, msg.data[1], ctx,
										DISP_UI_ENTER);
						} else {
							G1_LOG_ERR("screen ID message parampter error!\n");
						}
					}
					break;
				}
				switch (msg.type) {
				case DISP_MSG_CLOSE:
					disp_state.state = 2;
					if (msg.len == 0) {
						display_reflash_handler(gs, gs->screen_id, ctx,
									DISP_UI_EXIT);
					} else if (msg.len == 2) {
						if (msg.data[0] == 1) {
							display_reflash_handler(gs, msg.data[1], ctx,
										DISP_UI_EXIT);
						} else {
							G1_LOG_ERR("screen ID message parampter error!\n");
							display_reflash_handler(gs, gs->screen_id, ctx,
										DISP_UI_EXIT);
						}
					}
					display_timer_stop();
					goto close;
				case DISP_MSG_DELAY_CLOSE:
					display_delay_close_ms = *(int *)msg.data;
					display_reflash_handler(gs, gs->screen_id, ctx,
								DISP_UI_DELAY_CLOSE);
					break;
				case DISP_MSG_INPUT:
					display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_INPUT);
					break;
				case DISP_MSG_MASTER_CLOSE:
					display_reflash_handler(gs, gs->screen_id, ctx,
								DISP_UI_MASTER_CLOSE);
					break;
				case DISP_MSG_POWER_ON:
					display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_POWER_ON);
					break;
				case DISP_MSG_POWER_OFF:
					display_reflash_handler(gs, gs->screen_id, ctx,
								DISP_UI_POWER_OFF);
					break;
				default:
					break;
				}
			} else if (gs->screen_id != 0) {
				display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_REFRESH);
			} else if (gs->screen_id == 0) {
				G1_LOG_ERR("When the UI exit command is not received in IDLE state, the UI "
					   "exit is performed by itself\n");
				jbd_clear_cache_sync(0);
				display_timer_stop();
				memset(&disp_state, 0, sizeof(disp_state));
			}
			break;
		case 2:
close:
			jbd_clear_cache_sync(0);
			display_timer_stop();
			memset(&disp_state, 0, sizeof(disp_state));
			display_thread_restore_priority();
			break;
		default:
			G1_LOG_ERR("unknow display thread state\n");
			display_reflash_handler(gs, gs->screen_id, ctx, DISP_UI_EXIT);
			goto close;
		}
	}
}

int start_display_thread_handler(struct disp_gs *gs)
{
	display_tid = k_thread_create(&display_thread, display_stack,
				      K_THREAD_STACK_SIZEOF(display_stack),
				      (k_thread_entry_t)display_thread_handler, gs, NULL, NULL, -14,
				      0, K_NO_WAIT);
	return 0;
}

int display_reflash(const void *data, uint32_t len)
{
	struct disp_msg msg;

	memset(&msg, 0, sizeof(msg));
	if (len > DISPLAY_MSG_MAX_LEN) {
		G1_LOG_ERR("send data length more than %d,can't load it,exit ...\n",
			   DISPLAY_MSG_MAX_LEN);
		return -1;
	}
	k_uptime_get();
	msg = (struct disp_msg){.type = DISP_MSG_OPEN};
	if (data) {
		memcpy(msg.data, data, len);
		msg.len = len;
	}
	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	k_uptime_get();
	display_thread_boost_priority();
	return 0;
}

int display_close(const void *data, uint32_t len)
{
	struct disp_msg msg;

	memset(&msg, 0, sizeof(msg));
	if (len > DISPLAY_MSG_MAX_LEN) {
		G1_LOG_ERR("send data length more than %d,can't load it,exit ...\n",
			   DISPLAY_MSG_MAX_LEN);
		return -1;
	}
	msg.type = DISP_MSG_CLOSE;
	if (data) {
		memcpy(msg.data, data, len);
		msg.len = len;
	}
	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	G1_LOG_ERR("send display close command.......\n");
	return 0;
}

int display_close_screen(int screen_id)
{
	uint8_t data[2] = {1};

	data[1] = screen_id;
	if (screen_id != 0) {
		G1_LOG_ERR("display_close_screen %d\n", screen_id);
		if (screen_id == 4) {
			FUN_00037824();
		}
		display_thread_boost_priority();
		display_close(data, sizeof(data));
		k_yield();
		memset(DISP_GS()->buf_0ef, 0, sizeof(DISP_GS()->buf_0ef));
	}
	return 0;
}

int display_DelayClose(int ms)
{
	struct disp_msg msg = {.type = DISP_MSG_DELAY_CLOSE, .len = 4};

	*(int *)msg.data = ms;
	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int display_inputEvent(uint8_t a, uint8_t b)
{
	struct disp_msg msg = {.type = DISP_MSG_INPUT, .len = 2, .data = {a, b}};

	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int display_MasterSendClose(void)
{
	struct disp_msg msg = {.type = DISP_MSG_MASTER_CLOSE};

	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int display_powerEvent(int on)
{
	struct disp_msg msg;

	memset(&msg, 0, sizeof(msg));
	if (on == 1) {
		msg.type = DISP_MSG_POWER_ON;
	} else {
		msg.type = DISP_MSG_POWER_OFF;
	}
	if (k_msgq_put(&display_msgq, &msg, K_NO_WAIT) != 0) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int FUN_00080fca(uint8_t screen_id)
{
	uint8_t data[2] = {1};

	data[1] = screen_id;

	display_reflash(data, sizeof(data));
	k_yield();
	return 0;
}

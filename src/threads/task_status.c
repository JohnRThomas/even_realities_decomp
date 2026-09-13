/*
 * Persist / temporary task status.  The screen on/off and suspend/resume
 * part is in system_state.c, the screen / message state machine in
 * message_task.c.
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "threads.h"
#include "../display/display_thread.h"

#define TASK_RUNNING 2
#define TASK_PAUSE   3

/* .bss */
static uint8_t saved_auto_brightness;                     /* 0x20019a6b */
uint8_t task_status_lock;                     /* 0x20019a6a */

uint8_t is_persist_task_active(struct GlassesState *state, int mode)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	return state->task_status->status > 1;
}

int is_task_running(struct GlassesState *state)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	return state->dashboard_mode > 1;
}

int update_persist_task_status(struct GlassesState *state, int task, int status)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if (state->task_status->task == task &&
	    (state->task_status->status == 1 || state->task_status->status == status)) {
		task_status_lock = 0;
		return status;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		if (!state->dashboard_ts->exit_pending || state->dashboard_mode != 6) {
			if (status == TASK_RUNNING) {
				switch (task) {
				case 4:
				case 6:
				case 7:
				case 16:
				case 20:
					break;
				default:
					task_status_lock = 0;
					return status;
				}
				display_close_screen(state->dashboard_mode);
				state->dashboard_mode = task;
			} else {
				display_close_screen(state->dashboard_mode);
				state->dashboard_mode = task;
			}
		}
	} else {
		state->dashboard_mode = task;
	}
	if (status == TASK_RUNNING) {
		G1_LOG_ERR("persist task [running]: %d\n", task);
		if (task == 16) {
			saved_auto_brightness = state->opt3007_context.auto_brightness;
			if (state->opt3007_context.auto_brightness == 1) {
				state->opt3007_context.auto_brightness = 0;
			}
		}
		if (state->evenai_buf->state > 1) {
			state->evenai_buf->state = 0;
		}
	} else if (status == TASK_PAUSE) {
		G1_LOG_ERR("persist task [pause]: %d\n", task);
	} else {
		G1_LOG_ERR("persist task [stop]: %d\n", task);
	}
	state->task_status->task = task;
	state->task_status->status = status;
	task_status_lock = 0;
	return status;
}

int update_temp_task_status(struct GlassesState *state, int task, int status)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if ((state->task_status->task == task &&
	     (state->task_status->status == 1 || state->task_status->status == status)) ||
	    state->dashboard_mode == task) {
		task_status_lock = 0;
		return status;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		if (status == TASK_RUNNING) {
			if (task != 4) {
				if (task != 6) {
					task_status_lock = 0;
					return status;
				}
				display_close_screen(state->dashboard_mode);
			} else {
				display_close_screen(state->dashboard_mode);
			}
		} else {
			display_close_screen(state->dashboard_mode);
		}
	}
	if (status == TASK_RUNNING) {
		G1_LOG_ERR("persist task [running]: %d\n", task);
	} else if (status == TASK_PAUSE) {
		G1_LOG_ERR("persist task [pause]: %d\n", task);
	} else {
		G1_LOG_ERR("persist task [stop]: %d\n", task);
	}
	state->dashboard_mode = task;
	state->task_status->task = 0;
	state->task_status->status = 1;
	task_status_lock = 0;
	return status;
}

int update_persist_task_status_to_idle(struct GlassesState *state)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if (state->dashboard_mode == 0 && state->task_status->status == 1) {
		task_status_lock = 0;
		return 0;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		display_close_screen(state->dashboard_mode);
	}
	if (state->dashboard_mode == 16) {
		state->opt3007_context.auto_brightness = saved_auto_brightness;
	}
	G1_LOG_ERR("persist task [stop]: %d\n", 0);
	state->dashboard_mode = 0;
	state->task_status->status = 1;
	task_status_lock = 0;
	return 0;
}

int update_persist_task_status_to_wait_blow_head(struct GlassesState *state)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		display_close_screen(state->dashboard_mode);
	}
	G1_LOG_ERR("persist task [stop]: %d\n", 1);
	state->dashboard_mode = 1;
	state->task_status->task = 1;
	state->task_status->status = 1;
	task_status_lock = 0;
	return 0;
}

bool task_uses_mic(int task)
{
	switch (task) {
	case 9:
	case 11:
	case 12:
	case 16:
	case 19:
	case 20:
		return true;
	default:
		return false;
	}
}

bool is_idle(void)
{
	if (get_dashboard_state()->task_status->task != 0) {
		return false;
	}
	if (get_dashboard_state()->task_status->status != 1) {
		return false;
	}
	if (get_dashboard_state()->dashboard_mode != 0) {
		return false;
	}
	return get_dashboard_state()->suspend_state == 1;
}

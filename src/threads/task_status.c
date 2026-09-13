/*
 * Persist / temporary task status (0x2d9e8..0x2dd97, align-2 0x802b0..0x802f7;
 * the screen on/off and suspend/resume part before it is system_state.c, the
 * screen / message state machine that follows is message_task.c.)
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "threads.h"

#define TASK_RUNNING 2
#define TASK_PAUSE   3

/* .bss */
static uint8_t saved_f9c;                     /* 0x20019a6b */
uint8_t task_status_lock;                     /* 0x20019a6a */

uint8_t FUN_0002d9e8(struct GlassesState *state, int mode)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	return state->f_1068->status > 1;
}

int FUN_0002da10(struct GlassesState *state)
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
	if (state->f_1068->task == task &&
	    (state->f_1068->status == 1 || state->f_1068->status == status)) {
		goto out;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		if (!state->dashboard_ts->f_74 || state->dashboard_mode != 6) {
			if (status == TASK_RUNNING) {
				switch (task) {
				case 4:
				case 6:
				case 7:
				case 16:
				case 20:
					break;
				default:
					goto out;
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
			saved_f9c = state->f_f9c;
			if (state->f_f9c == 1) {
				state->f_f9c = 0;
			}
		}
		if (state->task_1014->f_00 > 1) {
			state->task_1014->f_00 = 0;
		}
	} else if (status == TASK_PAUSE) {
		G1_LOG_ERR("persist task [pause]: %d\n", task);
	} else {
		G1_LOG_ERR("persist task [stop]: %d\n", task);
	}
	state->f_1068->task = task;
	state->f_1068->status = status;
out:
	task_status_lock = 0;
	return status;
}

int update_temp_task_status(struct GlassesState *state, int task, int status)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if ((state->f_1068->task == task &&
	     (state->f_1068->status == 1 || state->f_1068->status == status)) ||
	    state->dashboard_mode == task) {
		goto out;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		if (status == TASK_RUNNING) {
			if (task != 4) {
				if (task != 6) {
					goto out;
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
	state->f_1068->task = 0;
	state->f_1068->status = 1;
out:
	task_status_lock = 0;
	return status;
}

int update_persist_task_status_to_idle(struct GlassesState *state)
{
	while (task_status_lock) {
		k_msleep(1);
	}
	task_status_lock = 1;
	if (state->dashboard_mode == 0 && state->f_1068->status == 1) {
		goto out;
	}
	if (state->dashboard_mode != 0 && state->dashboard_mode != 1) {
		display_close_screen(state->dashboard_mode);
	}
	if (state->dashboard_mode == 16) {
		state->f_f9c = saved_f9c;
	}
	G1_LOG_ERR("persist task [stop]: %d\n", 0);
	state->dashboard_mode = 0;
	state->f_1068->status = 1;
out:
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
	state->f_1068->task = 1;
	state->f_1068->status = 1;
	task_status_lock = 0;
	return 0;
}

bool FUN_0002dd80(int task)
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
	if (get_dashboard_state()->f_1068->task != 0) {
		return false;
	}
	if (get_dashboard_state()->f_1068->status != 1) {
		return false;
	}
	if (get_dashboard_state()->dashboard_mode != 0) {
		return false;
	}
	return get_dashboard_state()->suspend_state == 1;
}

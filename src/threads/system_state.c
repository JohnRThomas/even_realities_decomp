/*
 * Screen on/off state, IMU on/off hooks and global suspend/resume
 * (0x2d838..0x2d9e7, align-2 FUN_0008027a).  A translation unit of its own: in the
 * target its __func__ objects (global_system_resume, global_system_suspend,
 * trigger_screen_state_change) sit between its strings and update_persist_task_status's
 * strings, and FUN_0008027a precedes task_status.c's k_msleep copy in align-2.
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "threads.h"

int trigger_screen_state_change(const char *who, struct GlassesState *state, uint8_t on)
{
	int ret = on;

	if (state->screen_on == on) {
		G1_LOG_WRN("%s: ignore:%d.\n", who, state->screen_on);
		ret = -1;
		return ret;
	}
	if (on) {
		state->screen_on = 1;
		k_sem_give(&state->screen_on_sem);
	} else {
		state->screen_on = 0;
	}
	G1_LOG_WRN("%s: trigger_on_screen -> %d\n", who, state->screen_on);
	return ret;
}

int FUN_0008027a(void *dev, struct GlassesState *state, uint32_t on)
{
	if (state->imu_on != on) {
		state->imu_on = on;
		if (state->f_fee == 10 && on && !state->f_b0c) {
			state->f_fed = 1;
			k_sem_give(&state->imu_sem);
		}
		return 0;
	}
	return -1;
}

int FUN_0002d8c8(void *dev, struct GlassesState *state, bool on)
{
	if (!on) {
		FUN_0008027a(dev, state, on);
		trigger_screen_state_change("imu-off", state, on);
	} else {
		FUN_0008027a(dev, state, true);
		trigger_screen_state_change("imu-on", state, true);
	}
	return 0;
}

int global_system_suspend(struct GlassesState *state)
{
	if ((state->suspend_state & ~4) == 0) {
		state->suspend_state = 2;
		G1_LOG_WRN("begin.\n");
		k_sleep(K_MSEC(300));
		state->pm.suspend(&state->pm);
		G1_LOG_WRN("end.\n");
		state->suspend_state = 1;
	}
	return 0;
}

int global_system_resume(struct GlassesState *state)
{
	if ((state->suspend_state & 0xfb) == 1) {
		state->suspend_state = 3;
		G1_LOG_WRN("begin.\n");
		state->pm.resume(&state->pm);
		G1_LOG_WRN("end.\n");
		state->suspend_state = 0;
	}
	return 0;
}

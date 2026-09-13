/*
 * Message timeout / sync state and the screen state machine run by
 * ble_msg_dispatch_thread (screen_task_dispatch and the
 * process_for_* screens inlined into it).
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include "g1_log.h"
#include "threads.h"
#include "../ble/ble_ancs.h"
#include "../display/display_thread.h"
#include "../main.h"
#include "../notify/notify.h"
#include "../production_test/production_test.h"
#include "../sensors_audio/sensors_audio.h"
#include "../storage/storage.h"
#include "../ui/ui.h"

/* .bss */
uint8_t msg_busy;                             /* 0x20019a6d */
static uint8_t msg_timeout_flag;              /* 0x20019a6c */

void set_msg_timeout_flag(void)
{
	int64_t now = k_uptime_get();

	ARG_UNUSED(now);
	if (count_unread_messages()) {
		msg_timeout_flag = 1;
	}
}

uint8_t take_msg_timeout_flag(void)
{
	uint8_t ret = msg_timeout_flag;

	if (ret) {
		msg_timeout_flag = 0;
	}
	return ret;
}

int sync_message_signal_to_slave(uint8_t signal)
{
	int64_t start = k_uptime_get();
	uint8_t data[2] = {0};
	int ret;

	data[0] = signal;
	ret = sync_to_slave(get_dashboard_state(), 7, data, 1);
	if (get_dashboard_state()->sync_ack != 2) {
		G1_PRINTK("%s failed !", __func__);
	} else {
		G1_PRINTK("%s successfully !", __func__);
	}
	if (start + 3000 < k_uptime_get()) {
		G1_PRINTK("retry sync_to_slave failed !");
	}
	return ret;
}

void check_showing_message(void)
{
	for (;;) {
		if (get_msg_show_state() != 5 || cur_message_show_state() != 2) {
			break;
		}
		G1_PRINTK("[csh_debug_msg] check showing msg timeout \n");
		if (sync_message_signal_to_slave(2) >= 3000) {
			continue;
		}
		g_arrMsgContent_count();
		if (get_dashboard_state()->unread_msg_num) {
			set_msg_show_state(6);
		} else {
			set_msg_show_state(0);
			return;
		}
	}
}

int send_msg_key_to_master(void)
{
	uint16_t retry = 1000;
	uint64_t i;  /* 64-bit: the shipped code counts this loop up (permuter) */
	int ret;
	struct notif_msg *msg;

	msg_busy = 1;
	do {
		msg = get_message_by_index(10);
		if (!msg->app_identifier[0] || !msg->pos) {
			break;
		}
		k_sleep(K_MSEC(1));
	} while (--retry);

	if (sync_to_master(get_dashboard_state(), 10, NULL, 0) < 2000 &&
	    get_dashboard_state()->sync_ack == 2) {
		for (i = 0; i < 10; i++) {
			if (new_msg_signal_received) {
				break;
			}
			k_sleep(K_MSEC(100));
		}
		if (new_msg_signal_received) {
			new_msg_signal_received = 0;
			get_dashboard_state()->unread_msg_num = count_unread_messages();
			ret = 0;
		} else {
			ret = -1;
		}
	} else {
		G1_PRINTK("#########timeout,should retry !");
		ret = -1;
	}
	msg_busy = 0;
	return ret;
}

uint32_t get_msg_stay_time(int type, uint32_t def)
{
	switch (type) {
	case 11:
		return 31536000;
	case 12:
		return 1;
	default:
		return def;
	}
}

void handle_msg_touch_key(void)
{
	int64_t now = k_uptime_get();

	ARG_UNUSED(now);
	G1_PRINTK("[csh_debug_msg] set touch key flag get_msg_show_state() %d\n", get_msg_show_state());
	if (get_msg_show_state() == 2 || get_msg_show_state() == 4) {
		g_arrMsgContent_count();
		get_dashboard_state()->stay_time_left_s = get_msg_stay_time(get_dashboard_state()->display_mode,
							     get_dashboard_state()->message_stay_time);
	}
	get_dashboard_state()->unread_msg_num = count_unread_messages();
	if (get_dashboard_state()->unread_msg_num) {
		clear_timeout_message(1);
		mark_cur_message_read();
		msg_timeout_flag = 1;
	} else {
		set_msg_show_state(0);
		if (get_dashboard_state()->dashboard_mode != 1 && get_dashboard_state()->imu.mode == 2) {
			trigger_screen_state_change("IMU:wakeup:dashboard", get_dashboard_state(), 1);
		}
		if (get_dashboard_state()->is_master == 1) {
			get_dashboard_state()->stay_time_left_s = 0;
		}
	}
}

/*
 * Screen / task state machine run by ble_msg_dispatch_thread
 * (state->dashboard_mode is the current screen id).
 */
#define SCREEN_CHANGED 0xb      /* the screen id changed: dispatch again */
#define TASK_EXITED    (-1)     /* the task finished: back to idle */



static ALWAYS_INLINE void notify_msg_ctx(struct imu_ctx *ctx, int code)
{
	CONTAINER_OF(ctx, struct GlassesState, imu)->imu.set_cb(ctx, code);
}

static ALWAYS_INLINE void msg_led_update(void)
{
	uint8_t v;

	if (cur_message_show_state() != 1) {
		v = get_dashboard_state()->unread_msg_num;
		if (v) {
			set_msg_show_state(6);
		} else {
			set_msg_show_state(v);
		}
	} else {
		set_msg_show_state(5);
	}
}

static ALWAYS_INLINE void clear_dashboard_flag(void)
{
	if (atomic_test_bit(&dashboard_flags, 1)) {
		atomic_clear_bit(&dashboard_flags, 1);
	}
}

/* leave the current screen: the caller goes back to the idle screen */
#define TASK_EXIT(why) do { *reason = (why); return TASK_EXITED; } while (0)

/* DFU in progress (local or reported by the box). A macro, not an inline function: an
 * inlined helper keeps its own branch probabilities, the task loops then look cold and RTL
 * loop-invariant motion no longer hoists state + 0x1000 (target does). */
#define IS_DFU(state) ((state)->work_mode == 1 || get_dashboard_state()->work_mode == 8)

/* stop the task on both sides */
static ALWAYS_INLINE void task_stop(struct GlassesState *state, struct imu_ctx *ctx)
{
	sync_to_slave(state, 8, NULL, 0);
	if (ctx->mode == 2) {
		update_persist_task_status_to_wait_blow_head(state);
	} else {
		update_persist_task_status_to_idle(state);
	}
}

/*
 * Send the canvas distance / raster height gears to the slave.  A macro, not a
 * function: the log carries the __func__ of the screen handler that expands it
 * (the target has process_for_message_show's name for the second copy).
 */
#define sync_canvas_to_slave(state)                                                       \
	do {                                                                              \
		uint8_t data[3];                                                          \
                                                                                          \
		G1_LOG_WRN("master sync canvas_distance_gear:%d,raster_height_gear:%d\n",  \
			   (state)->panel.canvas_distance_gear,                           \
			   (state)->panel.raster_height_offset);                          \
		data[0] = 0xb;                                                            \
		data[1] = (state)->panel.canvas_distance_gear;                            \
		data[2] = (state)->panel.raster_height_offset;                            \
		sync_to_slave((state), 0xc, data, 3);                                     \
		cal_panel_canvas_coord(&(state)->panel.y_offset, (int *)&(state)->panel.current_column);       \
	} while (0)

/*
 * The screen handlers are plain static functions (each called once): the IPA inliner merges them
 * into screen_task_dispatch, and its order shows in the target's exit-reason strings
 * (teleprompter, dashboard, quicknote, ...); ALWAYS_INLINE (early inlining) gave switch order.
 */
static int process_for_IDLE(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	struct msg_status *persist = state->task_status;
	int cnt;
	int i;
	uint8_t v;
	bool next_msg;
	int show;

	clear_dashboard_flag();
	reset_dash_buf(1);
	if (!is_persist_task_active(state, state->dashboard_mode)) {
		if (ctx->mode != 2) {
			trigger_screen_state_change("goto idle1", state, 0);
			if (get_dashboard_state()->is_master == 2 &&
			    k_sem_count_get(&get_dashboard_state()->sem_2) == 0) {
				k_sem_give(&get_dashboard_state()->sem_2);
			}
		}
		state->dashboard_mode = 0;
		state->task_status->task = 0;
		state->task_status->status = 1;
		msg_led_update();
		take_msg_timeout_flag();
		if (ctx->mode != 2) {
			i = 100;
			while (state->suspend_state != 1) {
				k_msleep(10);
				if (!--i) {
					break;
				}
			}
		}
		G1_LOG_WRN("Now, I will goto run IDLE ^v^ g->persist_task->screen_id %d, persist->status %d pkg->screen_id %d\n",
			   state->task_status->task, persist->status, state->dashboard_mode);
	}
	cnt = 0;
	msg_busy = 0;
	while (1) {
		if (IS_DFU(state)) {
			break;
		}
		next_msg = false;
		if (!(uint8_t)is_in_box() &&
		    !(state->display_mode == 12 && (persist->task != 7 || state->dashboard_mode != 7))) {
			if (is_persist_task_active(state, state->dashboard_mode) == 1) {
				state->dashboard_mode = persist->task;
				if (state->dashboard_ts->exit_pending) {
					state->dashboard_ts->exit_pending = 0;
				}
				if (state->evenai_buf->state > 1) {
					state->evenai_buf->state = 0;
				}
				trigger_screen_state_change("BLE:wakeup:persist_task", state, 1);
				break;
			}
			if (get_pt_test_mode() != 1) {
				if (state->onboarding->in_progress || !is_ble_device_bound() || get_dashboard_state()->bitmap_info->sync_pending) {
					cnt++;
					if ((cnt & 0x1f) == 0) {
						G1_LOG_ERR("There is an unfinished task,skip the local tasks:%d,%d,%d\n",
							   state->onboarding->in_progress, is_ble_device_bound(),
							   get_dashboard_state()->bitmap_info->sync_pending);
					}
				} else {
				v = state->dashboard_ts->exit_pending;
				if (v) {
					cnt++;
					k_msleep(50);
					if (cnt >= 80) {
						state->dashboard_ts->exit_pending = 0;
					} else if (cnt % 40 == 0) {
						G1_LOG_WRN("dashboard wait for starting other task\n");
					}
					continue;
				}
				if (state->evenai_buf->state > 1) {
					cnt++;
					k_msleep(50);
					if (cnt >= 100) {
						state->evenai_buf->state = v;
					} else if (cnt % 40 == 0) {
						G1_LOG_WRN("evenai v2 wait for starting other task\n");
					}
					continue;
				}
				if (ctx->mode == 2) {
					if (get_dashboard_state()->suspend_state != 5 && is_message_showing()) {
						set_particle_pending();
						if (state->is_master == 1) {
							sync_message_signal_to_slave(1);
							clear_timeout_message(0);
							set_msg_timeout_flag();
							mark_cur_message_read();
							update_temp_task_status(state, 4, 2);
							trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
						} else if (state->dashboard_mode != 4) {
							goto wait;
						}
						G1_LOG_ERR("goto message show task !\n");
						return SCREEN_CHANGED;
					}
					if (state->dashboard_ts->exit_pending) {
						show = 0;
					} else if (ctx->mode == 2 && get_dashboard_state()->suspend_state != 5 && !get_dashboard_startup_mode()) {
						show = 1;
					} else if (state->double_tap_dashboard_on) {
						show = 1;
					} else {
						show = 2;
					}
				} else if (state->double_tap_dashboard_on) {
					show = 1;
				} else {
					show = 2;
				}
				if (show == 2) {
					show = state->dashboard_ts->dashboard_hold != 0;
				}
				if (show) {
					clear_dashboard_flag();
					if (state->is_master == 1) {
						sync_canvas_to_slave(state);
						if (is_persist_task_active(state, state->dashboard_mode) == 1) {
							continue;
						}
						if (get_dashboard_state()->is_master == 1 && get_glasses_ble_status() == 1 &&
						    !get_dashboard_state()->head_up_mic_disabled && dmic_get_stop_state() == 1) {
							request_dmic_stream_start();
						}
					} else if (/* same test written in both arms, see the double_tap_dashboard_on test above */
						   get_dashboard_state()->is_master == 1 && get_glasses_ble_status() == 1 &&
					    !get_dashboard_state()->head_up_mic_disabled && dmic_get_stop_state() == 1) {
						request_dmic_stream_start();
					}
					get_dashboard_state()->dashboard_ts->dashboard_on = 1;
					update_temp_task_status(state, 6, 2);
					trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
					return SCREEN_CHANGED;
				}
				if (state->message_mode) {
					if ((ctx->mode == 1 && !get_dashboard_startup_mode()) || get_dashboard_startup_mode()) {
						if (cur_message_show_state() == 1 || get_msg_show_state() == 1) {
							set_particle_pending();
							if (state->is_master == 1) {
								sync_message_signal_to_slave(1);
								clear_timeout_message(0);
								set_msg_timeout_flag();
							mark_cur_message_read();
								update_temp_task_status(state, 4, 2);
								trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
								return SCREEN_CHANGED;
							}
							if (state->dashboard_mode == 4) {
								G1_PRINTK("goto message show task !");
								return SCREEN_CHANGED;
							}
							next_msg = true;
						}
					}
					if (!next_msg && state->message_mode) {
						next_msg = true;
					}
				}
				if (!next_msg) {
					if (get_msg_show_state() == 1) {
						if (state->is_master == 1) {
							sync_message_signal_to_slave(0);
							update_temp_task_status(state, 5, 2);
							trigger_screen_state_change("BLE:wakeup:new-unread_msg", state, 1);
							G1_LOG_ERR("goto new message come on task master!\r\n\n");
							return SCREEN_CHANGED;
						}
						if (state->dashboard_mode == 5) {
							G1_LOG_ERR("goto new message come on task slave!\r\n\n");
							return SCREEN_CHANGED;
						}
					}
				}
				if (state->message_mode && state->dashboard_mode == 4 &&
				    ((ctx->mode == 1 && !get_dashboard_startup_mode()) || get_dashboard_startup_mode())) {
					trigger_screen_state_change("BLE:wakeup:next-unread_msg", state, 1);
					break;
				}
				}
			}
		}
wait:
		cnt++;
		if (state->is_master == 1) {
			notify_msg_ctx(ctx, 0x50);
		}
		k_sleep(K_MSEC(50));
	}
	if (state->is_master == 1) {
		notify_msg_ctx(ctx, 0x26);
	}
	return 0;
}

static int process_for_wait_blow_head(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	trigger_screen_state_change("WAIT_BLOW_HEAD", state, 0);
	while (1) {
		if (ctx->mode == 1 || get_dashboard_state()->double_tap_customize == 4) {
			state->dashboard_mode = 0;
			return SCREEN_CHANGED;
		}
		if (state->task_status->status == 2 && state->task_status->task == 16) {
			state->dashboard_mode = 16;
			trigger_screen_state_change("BLE:wakeup:persist_task", state, 1);
			return 0;
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_countdown(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	struct countdown_ts_context *cd;

	/* exit test at the loop top: the task_stop blocks get lower positions than the body */
	while (1) {
		if (!state->countdown_ts->enabled || state->display_mode != 10) {
			task_stop(state, ctx);
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			TASK_EXIT("countdown:trigger-off-imm");
		}
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("countdown:imu-trigger-off-imm");
		}
		cd = state->countdown_ts;
		if (cd->seconds == 0) {
			cd->enabled = 0;
			update_persist_task_status(state, state->task_status->task, 1);
			TASK_EXIT("countdown:ts is over");
		}
		if (ctx->mode == 2) {
			if (state->unread_msg_num) {
				update_temp_task_status(state, 4, 2);
				set_msg_timeout_flag();
			} else {
				get_dashboard_state()->dashboard_ts->dashboard_on = 1;
				update_temp_task_status(state, 6, 2);
			}
			update_persist_task_status(state, state->task_status->task, 3);
			return SCREEN_CHANGED;
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_message_show(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	uint16_t wait = 1000;
	int cnt;

	while (get_dashboard_state()->unread_msg_num &&
	       get_msg_sync_state(get_dashboard_state()->unread_msg_num - 1) != 4) {
		wait--;
		k_sleep(K_MSEC(1));
		if (!wait) {
			break;
		}
	}
	cnt = 0;
	state->unknown_task_count = 0;
	set_msg_show_state(4);
	state->stay_time_left_s = get_msg_stay_time(state->display_mode, get_dashboard_state()->message_stay_time);
	while (1) {
		if ((!state->message_mode ? ctx->mode == 1 || !state->stay_time_left_s : cur_message_show_state() == 2 || !state->stay_time_left_s) &&
		    state->display_mode == 10) {
			if (state->dashboard_mode == 6 ||
			    (state->dashboard_mode != 6 &&
			     ((!get_dashboard_startup_mode() && ctx->mode == 2) ||
			      (state->double_tap_customize == 4 && state->double_tap_dashboard_on == 1)))) {
				if (get_dashboard_state()->message_mode && get_dashboard_state()->is_master == 1) {
					get_dashboard_state()->last_sync_ts -= 1000;
				}
				if (state->is_master == 1) {
					sync_canvas_to_slave(state);
					if (state->dashboard_ts->exit_pending) {
						state->dashboard_ts->exit_pending = 0;
					}
				}
				k_sleep(K_MSEC(500));
				get_dashboard_state()->dashboard_ts->dashboard_on = 1;
				update_temp_task_status(get_dashboard_state(), 6, 2);
				return SCREEN_CHANGED;
			}
			sync_to_slave(state, 8, NULL, 0);
			if (state->is_master == 1) {
				update_persist_task_status_to_idle(state);
			} else if (state->dashboard_mode == 4) {
				k_sleep(K_MSEC(50));
				continue;
			}
			set_msg_show_state(5);
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			if (get_msg_show_state() == 4) {
				continue;
			}
			TASK_EXIT("imu-trigger-off-imm");
		}
		if (IS_DFU(state) || get_dashboard_state()->display_mode == 12) {
			update_persist_task_status_to_idle(state);
			set_msg_show_state(5);
			TASK_EXIT("imu-trigger-off-imm");
		}
		if (state->dashboard_mode != 4) {
			int r = SCREEN_CHANGED;
			if (state->dashboard_mode == 0) {
				*reason = "imu-trigger-off-imm";
				r = TASK_EXITED;
			}
			return r;
		}
		cnt++;
		if (state->message_mode && state->is_master == 1 &&
		    ((ctx->mode == 1 && !get_dashboard_startup_mode()) || get_dashboard_startup_mode())) {
			if (cnt % 20 == 0 && state->stay_time_left_s < 30) {
				state->stay_time_left_s--;
			}
		}
		k_sleep(K_MSEC(50));
	}
}

static ALWAYS_INLINE int dashboard_goto_persist_task(struct GlassesState *state)
{
	if (!task_uses_mic(state->task_status->task)) {
		dmic_stream_stop();
	}
	state->dashboard_mode = state->task_status->task;
	return SCREEN_CHANGED;
}

static int process_for_DASHBOARD_show(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	uint8_t closing = 0;
	uint8_t d[2];
	bool do_close;

	state->unknown_task_count = 0;
	clear_dashboard_flag();
	while (1) {
		if (state->work_mode == 1) {
dfu:
			update_persist_task_status_to_idle(state);
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		if (get_dashboard_state()->work_mode == 8) {
			goto dfu;
		}
		closing |= state->dashboard_ts->dashboard_hold;
		if (!closing) {
			do_close = (ctx->mode == 1 && !get_dashboard_startup_mode()) ||
				   (!get_dashboard_state()->double_tap_dashboard_on && get_dashboard_state()->double_tap_customize == 4);
		} else {
			do_close = !state->dashboard_ts->dashboard_hold;
			if (!do_close) {
				closing = 1;
			}
		}
		if (do_close) {
			clear_dashboard_flag();
			if (is_persist_task_active(state, state->dashboard_mode) == 1 && !state->dashboard_ts->exit_pending) {
				return dashboard_goto_persist_task(state);
			}
			dmic_stream_stop();
			sync_to_slave(state, 8, NULL, 0);
			goto dfu;
		}
		if (!state->dashboard_ts->exit_pending) {
			if (is_persist_task_active(state, state->dashboard_mode) == 1) {
				if (!task_uses_mic(state->task_status->task)) {
					dmic_stream_stop();
				}
				if (state->sync_status.task == 11) {
					state->dashboard_mode = 11;
					return SCREEN_CHANGED;
				}
				switch (state->sync_status.task) {
				case 9:
					state->dashboard_mode = 9;
					return SCREEN_CHANGED;
				case 8:
					state->dashboard_mode = 8;
					return SCREEN_CHANGED;
				case 10:
					state->dashboard_mode = 10;
					return SCREEN_CHANGED;
				case 12:
					state->dashboard_mode = 12;
					return SCREEN_CHANGED;
				case 7:
					state->dashboard_mode = 7;
					return SCREEN_CHANGED;
				case 14:
					state->dashboard_mode = 14;
					return SCREEN_CHANGED;
				case 15:
					state->dashboard_mode = 15;
					return SCREEN_CHANGED;
				case 16:
					state->dashboard_mode = 16;
					return SCREEN_CHANGED;
				case 20:
					state->dashboard_mode = 20;
					return SCREEN_CHANGED;
				case 17:
					state->dashboard_mode = 17;
					return SCREEN_CHANGED;
				case 18:
					state->dashboard_mode = 18;
					return SCREEN_CHANGED;
				case 19:
					state->dashboard_mode = 19;
					return SCREEN_CHANGED;
				default:
					state->unknown_task_count++;
					break;
				}
			}
			if (state->dashboard_mode == 1) {
				TASK_EXIT("dashboard:imu-trigger-off-imm");
			}
		}
		if (is_master() == 1 && state->dashboard_ts->exit_pending == 1) {
			state->dashboard_ts->exit_pending = 2;
		}
		if (state->dashboard_ts->exit_pending == 2 && is_persist_task_active(state, state->dashboard_mode) == 1) {
			d[0] = 2;
			d[1] = 9;
			if (sync_to_slave(state, 6, d, 2) < 3000) {
				G1_LOG_WRN("sync close dashboard!\n");
				display_close_screen(6);
				while (state->dashboard_ts->dashboard_on == 1) {
					k_sleep(K_MSEC(50));
				}
				state->dashboard_ts->exit_pending = 0;
				return dashboard_goto_persist_task(state);
			}
			G1_LOG_ERR("sync exit dashboard fail!\n");
		}
		if (state->dashboard_mode == 4) {
			dmic_stream_stop();
			if (state->is_master == 2) {
				k_msleep(150);
			}
			G1_PRINTK("goto message show task becasse screen id is E_ID_SCREEN_ANCS_NOTIFICATION!");
			return SCREEN_CHANGED;
		}
		if (state->suspend_state == 1) {
			k_sleep(K_MSEC(50));
			return 0;
		}
		if (msg_timeout_flag && count_messages()) {
			dmic_stream_stop();
			set_particle_pending();
			set_msg_show_state(6);
			update_temp_task_status(state, 4, 2);
			trigger_screen_state_change("display msg by touch", state, 1);
			return SCREEN_CHANGED;
		}
		get_dashboard_state();
		k_sleep(K_MSEC(50));
	}
}

static int process_for_unread_msg(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	state->schedule_notif_pending = 0;
	get_dashboard_state()->unread_msg_num = count_unread_messages();
	while (1) {
		if (ctx->mode == 1 && state->display_mode == 10) {
			sync_to_slave(state, 8, NULL, 0);
			update_persist_task_status_to_idle(state);
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			TASK_EXIT("imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_teleprompter(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	struct teleprompter_info *blk = state->teleprompter;

	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("teleprompter:imu-trigger-off-imm");
		}
		if (!blk->ready) {
			dmic_stream_stop();
			if (ctx->mode == 2) {
				trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
				teleprompter_state_reset();
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
				k_sleep(K_MSEC(300));
			} else {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				teleprompter_state_reset();
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
			}
			TASK_EXIT("temeprompter:self exit");
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_navigation(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	struct nav_info *blk = state->nav;

	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("navigation:imu-trigger-off-imm");
		}
		if (!blk->running) {
			if (ctx->mode == 2) {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
				k_sleep(K_MSEC(300));
			} else {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
			}
			TASK_EXIT("navigation:self exit");
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_translate(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("translate:self exit");
		}
		if (!state->translate_src->data[0] && !state->translate_dst->data[0]) {
			if (ctx->mode == 2) {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
				k_sleep(K_MSEC(300));
			} else {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
			}
			TASK_EXIT("translate:self exit");
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_quicknote(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("quicknote:imu-trigger-off-imm");
		}
		if (!state->quicknote_show_info->enable) {
			if (ctx->mode == 2) {
				task_stop(state, ctx);
				trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
			} else {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
			}
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			TASK_EXIT("quicknote:self exit");
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_not_disturb(struct GlassesState *state, const char **reason)
{
	state->bitmap_info->sync_pending = 0;
	while (1) {
		if (state->bitmap_info->enable && k_uptime_get() - state->bitmap_info->deadline > 1500) {
			state->bitmap_info->enable = 0;
		}
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("not_disturb:dfu");
		}
		if (!state->bitmap_info->enable) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("not_disturb:self exit");
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("not_disturb:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

/*
 * The handlers below that take ctx do not need it: each one tests ctx and then does the same
 * thing on both paths.  RTL cross-jumping merges the two copies after register allocation and
 * the ctx test disappears (no code), but ctx stays live inside the task loop, as in the shipped
 * code (state + 0x1000 and the log pointers then avoid r5).
 */
/* simple tasks: run until the task flag drops */
#define SIMPLE_TASK(name, flag, sleep_ms)                                              \
	while (1) {                                                                    \
		if (IS_DFU(state)) {                                                   \
			update_persist_task_status_to_idle(state);                     \
			TASK_EXIT(name ":dfu");                          \
		}                                                                      \
		if (!(flag)) {                                                         \
			sync_to_slave(state, 8, NULL, 0);                              \
			update_persist_task_status_to_idle(state);                     \
			if (state->is_master == 1) {                                   \
				k_sleep(K_MSEC(sleep_ms));                             \
			}                                                              \
			TASK_EXIT(name ":self exit");                    \
		}                                                                      \
		if (ctx) {                                                             \
			if (state->dashboard_mode == 1) {                              \
				TASK_EXIT(name ":imu-trigger-off-imm");                \
			}                                                              \
		} else if (state->dashboard_mode == 1) {                               \
			TASK_EXIT(name ":imu-trigger-off-imm");                        \
		}                                                                      \
		k_sleep(K_MSEC(50));                                                   \
	}

static int process_for_onboarding(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("onboarding", state->onboarding->active, 100)
}

static int process_for_raster_height(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("raster_height", state->raster_height_cfg[0], 500)
}

static int process_for_set_imu_pitch(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("set_imu_pitch", state->horiz_pitch_cfg[0], 500)
}

static int process_for_transcribe(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("transcribe", state->transcribe_buf->running, 500)
}

static int process_for_prompt(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("prompt:dfu");
		}
		if (state->is_master == 1 && state->ts_info->enable &&
		    k_uptime_get() - state->ts_info->ts > 4000) {
			state->ts_info->enable = 0;
		}
		if (!state->ts_info->enable) {
			sync_to_slave(state, 8, NULL, 0);
			update_persist_task_status_to_idle(state);
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			TASK_EXIT("prompt:self exit");
		}
		if (ctx) {
			if (state->dashboard_mode == 1) {
				TASK_EXIT("prompt:imu-trigger-off-imm");
			}
		} else if (state->dashboard_mode == 1) {
			TASK_EXIT("prompt:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_evenai(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	struct dash_data_buf *ai;
	int cnt = 0;
	uint8_t st;

	while (1) {
		if (state->display_mode == 12) {
			task_stop(state, ctx);
			reset_dash_buf(1);
			TASK_EXIT("evenai:self exit");
		}
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			reset_dash_buf(1);
			TASK_EXIT("evenai:self exit");
		}
		if (!get_glasses_ble_status() && get_dashboard_state()->dash_buf->type > 1 &&
		    get_dashboard_state()->dash_buf->type < 10) {
			get_dashboard_state()->dash_buf->type = 10;
		}
		ai = state->dash_buf;
		if (!ai->data[0] || !get_dashboard_state()->dash_buf->type ||
		    (((st = state->dash_buf->type) == 8 || st == 11) && !state->stay_time_left_s)) {
			if (state->is_master == 1) {
				report_event_to_phone(0);
			}
			sync_to_slave(state, 8, NULL, 0);
			update_persist_task_status_to_idle(state);
			reset_dash_buf(1);
			TASK_EXIT("evenai:self exit");
		}
		if (state->dashboard_mode == 1) {
			reset_dash_buf(1);
			TASK_EXIT("evenai:imu-trigger-off-imm");
		}
		cnt++;
		if (state->is_master == 1 && (st == 7 || st == 8 || st == 11) && cnt % 20 == 0) {
			state->stay_time_left_s--;
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_even_ai_v2_show(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	int64_t now;

	if (get_dashboard_state()->is_master == 2 &&
	    k_sem_count_get(&get_dashboard_state()->sem_2) == 0) {
		k_sem_give(&get_dashboard_state()->sem_2);
	}
	now = k_uptime_get();
	/* plain memcpy, not UNALIGNED_PUT: Zephyr's UNALIGNED_PUT ends in a compiler barrier and the
	 * shipped code schedules across this store */
	memcpy(&state->evenai_buf->ts, &now, sizeof(now));
	state->dashboard_ts->exit_pending = 0;
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("evenai_v2:dfu");
		}
		if (state->is_master == 1 && state->evenai_buf->state == 1) {
			if ((k_uptime_get() - state->evenai_buf->ts > 5000 &&
			     ((state->evenai_buf->sub == 7 && state->evenai_buf->action_status == 1) ||
			      (state->evenai_buf->sub == 4 && state->evenai_buf->action_status == 0x13))) ||
			    (k_uptime_get() - state->evenai_buf->ts > 15000 &&
			     state->evenai_buf->sub == 2)) {
				state->evenai_buf->state = 0;
			}
		}
		if (is_master() == 1 && state->evenai_buf->state == 2) {
			state->evenai_buf->state = 3;
		}
		if (state->evenai_buf->state == 0 || state->evenai_buf->state == 3) {
			if (ctx->mode == 2) {
				if (sync_to_slave(state, 8, NULL, 0) < 3000) {
					update_persist_task_status_to_idle(state);
					TASK_EXIT("evenai_v2:self exit");
				}
				G1_LOG_ERR("sync exit evenai_v2 fail!\n");
			} else {
				if (sync_to_slave(state, 8, NULL, 0) < 3000) {
					update_persist_task_status_to_idle(state);
					TASK_EXIT("evenai_v2:self exit");
				}
				G1_LOG_ERR("sync exit evenai_v2 fail!\n");
			}
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("evenai_v2:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static void dec_nz(uint8_t *v)
{
	if (*v) {
		(*v)--;
	}
}

/* screen 5: a new notification came in; show it until it times out or the user acts.
 * The local DFU check and the box DFU / quicknote check are separate exits with the same
 * body: as one combined condition the exit string lands in another place of .rodata. */
static int process_for_new_message_come_on(struct GlassesState *state, struct imu_ctx *ctx, const char **reason)
{
	int cnt;
	uint32_t msg_id;
	uint32_t id;

	state->stay_time_left_s = get_msg_stay_time(state->display_mode, get_dashboard_state()->message_stay_time);
	set_msg_show_state(2);
	cnt = 0;
	msg_id = *(uint32_t *)get_message_by_index(get_dashboard_state()->unread_msg_num - 1);
	while (1) {
		if (state->work_mode == 1) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("message:imu-trigger-off-imm");
		}
		if (get_dashboard_state()->work_mode == 8 || get_dashboard_state()->display_mode == 12) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("message:imu-trigger-off-imm");
		}
		if (state->is_master == 1) {
			id = *(uint32_t *)get_message_by_index(get_dashboard_state()->unread_msg_num - 1);
			if (msg_id != id) {
				state->stay_time_left_s = get_msg_stay_time(state->display_mode,
							    get_dashboard_state()->message_stay_time);
				msg_id = id;
			}
		}
		if (state->dashboard_mode != 5) {
			G1_LOG_ERR("goto next screen, new screen %d !\r\n\n", state->dashboard_mode);
			return SCREEN_CHANGED;
		}
		if (ctx->mode == 2 || state->display_mode == 11) {
			set_particle_pending();
			if (state->schedule_notif_pending == 1) {
				update_temp_task_status(state, 8, 2);
				set_msg_show_state(4);
				return SCREEN_CHANGED;
			}
			if (state->dashboard_mode == 5 && state->is_master == 1) {
				sync_message_signal_to_slave(1);
				clear_timeout_message(0);
				set_msg_timeout_flag();
				mark_cur_message_read();
				update_temp_task_status(state, 4, 2);
				trigger_screen_state_change("IMU:wakeup:new-notification", state, 1);
				G1_LOG_ERR("goto new message come on task master!\r\n\n");
				return SCREEN_CHANGED;
			}
		}
		if (!state->stay_time_left_s) {
			task_stop(state, ctx);
			set_msg_show_state(6);
			TASK_EXIT("new-msg-timeout-goto-idle");
		}
		k_sleep(K_MSEC(50));
		cnt++;
		if (state->is_master == 1 && cnt % 20 == 0) {
			dec_nz(&state->stay_time_left_s);
		}
		if (!state->stay_time_left_s) {
			state->schedule_notif_pending = 0;
			task_stop(state, ctx);
			set_msg_show_state(6);
			/* &"..."[0]: the two timeout exits differ for GIMPLE tail-merge,
			 * RTL crossjump still shares them (target keeps this copy's else arm) */
			TASK_EXIT(&"new-msg-timeout-goto-idle"[0]);
		}
	}
}

/* Screen state machine of ble_msg_dispatch_thread: run the handler of the current
 * screen until a handler ends its task; a changed screen id dispatches again. */
int screen_task_dispatch(struct GlassesState *state, struct imu_ctx *ctx)
{
	int ret = 0;
	const char *reason;

	do {
		memset(state->ui.buf, 0, sizeof(state->ui.buf));
		clear_timeout_message(0);
		if (state->is_master == 1) {
			check_showing_message();
		}
		if (state->dashboard_mode != 4) {
			msg_busy = 0;
		}
		if (!state->screen_on && is_task_running(state) == 1) {
			trigger_screen_state_change("BLE:wakeup:running_task", state, 1);
		}
		switch (state->dashboard_mode) {
		case 5:
			ret = process_for_new_message_come_on(state, ctx, &reason);
			break;
		case 4:
			ret = process_for_message_show(state, ctx, &reason);
			break;
		case 6:
			ret = process_for_DASHBOARD_show(state, ctx, &reason);
			break;
		case 2:
			ret = process_for_countdown(state, ctx, &reason);
			break;
		case 9:
			ret = process_for_teleprompter(state, ctx, &reason);
			break;
		case 12:
			ret = process_for_quicknote(state, ctx, &reason);
			break;
		case 10:
			ret = process_for_navigation(state, ctx, &reason);
			break;
		case 11:
			ret = process_for_translate(state, ctx, &reason);
			break;
		case 8:
			ret = process_for_unread_msg(state, ctx, &reason);
			break;
		case 7:
			ret = process_for_not_disturb(state, &reason);
			break;
		case 14:
			ret = process_for_onboarding(state, ctx, &reason);
			break;
		case 15:
			ret = process_for_raster_height(state, ctx, &reason);
			break;
		case 16:
			ret = process_for_evenai(state, ctx, &reason);
			break;
		case 20:
			ret = process_for_even_ai_v2_show(state, ctx, &reason);
			break;
		case 17:
			ret = process_for_set_imu_pitch(state, ctx, &reason);
			break;
		case 18:
			ret = process_for_prompt(state, ctx, &reason);
			break;
		case 19:
			ret = process_for_transcribe(state, ctx, &reason);
			break;
		case 0:
			ret = process_for_IDLE(state, ctx, &reason);
			break;
		case 1:
			ret = process_for_wait_blow_head(state, ctx, &reason);
			break;
		default:
			k_sleep(K_MSEC(1000));
			break;
		}
		if (ret == TASK_EXITED) {
			break;
		}
	} while (ret == SCREEN_CHANGED);
	if (ret == TASK_EXITED) {
		trigger_screen_state_change(reason, state, 0);
		k_msleep(150);
		if (get_msg_show_state() == 1) {
			msg_led_update();
		}
	}
	return 0;
}

/* align-2 */

void reset_dash_buf(int clear)
{
	get_dashboard_state()->esb_up_seq = 0;
	get_dashboard_state()->esb_down_seq = 0;
	get_dashboard_state()->esb_up_id = 0;
	get_dashboard_state()->esb_down_id = 0;
	get_dashboard_state()->esb_up_recving = 0;
	get_dashboard_state()->esb_down_recving = 0;
	if (clear) {
		get_dashboard_state()->dash_buf->data[0] = 0;
		get_dashboard_state()->dash_buf->type = 0;
	} else {
		get_dashboard_state()->dash_buf->data[0] = 13;
	}
	memset(&get_dashboard_state()->dash_buf->data[1], 0, 0x1df);
}

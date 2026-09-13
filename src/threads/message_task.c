/*
 * Message timeout / sync state and the screen state machine run by
 * ble_msg_dispatch_thread (process_for_new_message_come_on and the
 * process_for_* screens inlined into it).  Separate object after
 * task_status.c: it has its own k_uptime_get / k_sleep / k_msleep copies
 * (0x802f8, 0x80314, 0x80318), while task_status.c only has the
 * k_msleep(1) constprop copy and inlines its single k_sleep.
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include "g1_log.h"
#include "threads.h"

/* .bss */
uint8_t msg_busy;                             /* 0x20019a6d */
static uint8_t msg_timeout_flag;              /* 0x20019a6c */

extern atomic_t DAT_20008518;

/* other modules */
uint8_t FUN_00030440(void);

void FUN_0002dd98(void)
{
	int64_t now = k_uptime_get();

	ARG_UNUSED(now);
	if (FUN_00035310()) {
		msg_timeout_flag = 1;
	}
}

uint8_t FUN_0002ddb0(void)
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
		if (FUN_00035a78() != 5 || FUN_00035acc() != 2) {
			break;
		}
		G1_PRINTK("[csh_debug_msg] check showing msg timeout \n");
		if (sync_message_signal_to_slave(2) >= 3000) {
			continue;
		}
		g_arrMsgContent_count();
		if (get_dashboard_state()->f_0dd) {
			FUN_00035abc(6);
		} else {
			FUN_00035abc(0);
			return;
		}
	}
}

int FUN_0002dea8(void)
{
	uint16_t retry = 1000;
	uint64_t i;  /* 64-bit: the shipped code counts this loop up (permuter) */
	int ret;
	struct msg_content *msg;

	msg_busy = 1;
	do {
		msg = FUN_00035260(10);
		if (!msg->f_10 || !msg->f_0c) {
			break;
		}
		k_sleep(K_MSEC(1));
	} while (--retry);

	if (sync_to_master(get_dashboard_state(), 10, NULL, 0) < 2000 &&
	    get_dashboard_state()->sync_ack == 2) {
		for (i = 0; i < 10; i++) {
			if (DAT_20019a5b) {
				break;
			}
			k_sleep(K_MSEC(100));
		}
		if (DAT_20019a5b) {
			DAT_20019a5b = 0;
			get_dashboard_state()->f_0dd = FUN_00035310();
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

uint32_t FUN_0002df54(int type, uint32_t def)
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

void FUN_0002df6c(void)
{
	int64_t now = k_uptime_get();

	ARG_UNUSED(now);
	G1_PRINTK("[csh_debug_msg] set touch key flag get_msg_show_state() %d\n", FUN_00035a78());
	if (FUN_00035a78() == 2 || FUN_00035a78() == 4) {
		g_arrMsgContent_count();
		get_dashboard_state()->f_0db = FUN_0002df54(get_dashboard_state()->f_fee,
							     get_dashboard_state()->message_stay_time);
	}
	get_dashboard_state()->f_0dd = FUN_00035310();
	if (get_dashboard_state()->f_0dd) {
		FUN_000359fc(clear_timeout_message(1));
		msg_timeout_flag = 1;
	} else {
		FUN_00035abc(0);
		if (get_dashboard_state()->dashboard_mode != 1 && get_dashboard_state()->msg_ctx.state == 2) {
			trigger_screen_state_change("IMU:wakeup:dashboard", get_dashboard_state(), 1);
		}
		if (get_dashboard_state()->is_master == 1) {
			get_dashboard_state()->f_0db = 0;
		}
	}
}

/*
 * Screen / task state machine run by ble_msg_dispatch_thread
 * (state->dashboard_mode is the current screen id).
 */
#define SCREEN_CHANGED 0xb      /* the screen id changed: dispatch again */
#define TASK_EXITED    (-1)     /* the task finished: back to idle */

int is_in_box(void);
uint8_t FUN_000260dc(void);
bool FUN_00035ea4(void);
void FUN_00037830(void);
void FUN_0003f23c(void);
void FUN_0008040c(void);
int FUN_00035218(int idx);
uint8_t FUN_000352f4(void);
uint8_t is_master(void);
void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset);

#define BLK_TS(blk, off)          UNALIGNED_GET((int64_t *)((uint8_t *)(blk) + (off)))
#define BLK_TS_SET(blk, off, v)   UNALIGNED_PUT((v), (int64_t *)((uint8_t *)(blk) + (off)))

static ALWAYS_INLINE void notify_msg_ctx(struct message_ctx *ctx, int code)
{
	CONTAINER_OF(ctx, struct GlassesState, msg_ctx)->msg_notify(ctx, code);
}

static ALWAYS_INLINE void msg_led_update(void)
{
	uint8_t v;

	if (FUN_00035acc() != 1) {
		v = get_dashboard_state()->f_0dd;
		if (v) {
			FUN_00035abc(6);
		} else {
			FUN_00035abc(v);
		}
	} else {
		FUN_00035abc(5);
	}
}

static ALWAYS_INLINE void clear_dashboard_flag(void)
{
	if (atomic_test_bit(&DAT_20008518, 1)) {
		atomic_clear_bit(&DAT_20008518, 1);
	}
}

/* leave the current screen: the caller goes back to the idle screen */
#define TASK_EXIT(why) do { *reason = (why); return TASK_EXITED; } while (0)

/* DFU in progress (local or reported by the box). A macro, not an inline function: an
 * inlined helper keeps its own branch probabilities, the task loops then look cold and RTL
 * loop-invariant motion no longer hoists state + 0x1000 (target does). */
#define IS_DFU(state) ((state)->work_mode == 1 || get_dashboard_state()->work_mode == 8)

/* stop the task on both sides */
static ALWAYS_INLINE void task_stop(struct GlassesState *state, struct message_ctx *ctx)
{
	sync_to_slave(state, 8, NULL, 0);
	if (ctx->state == 2) {
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
			   (state)->panel_canvas_distance_gear,                           \
			   (state)->panel_raster_height_offset);                          \
		data[0] = 0xb;                                                            \
		data[1] = (state)->panel_canvas_distance_gear;                            \
		data[2] = (state)->panel_raster_height_offset;                            \
		sync_to_slave((state), 0xc, data, 3);                                     \
		cal_panel_canvas_coord(&(state)->panel_ec4, (int *)&(state)->f_eb8);       \
	} while (0)

/*
 * The screen handlers are plain static functions (each called once): the IPA inliner merges them
 * into process_for_new_message_come_on, and its order shows in the target's exit-reason strings
 * (teleprompter, dashboard, quicknote, ...); ALWAYS_INLINE (early inlining) gave switch order.
 */
static int process_for_IDLE(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	struct msg_status *persist = state->f_1068;
	int cnt;
	int i;
	uint8_t v;

	clear_dashboard_flag();
	FUN_00080338(1);
	if (!FUN_0002d9e8(state, state->dashboard_mode)) {
		if (ctx->state != 2) {
			trigger_screen_state_change("goto idle1", state, 0);
			if (get_dashboard_state()->is_master == 2 &&
			    k_sem_count_get(&get_dashboard_state()->sem_2) == 0) {
				k_sem_give(&get_dashboard_state()->sem_2);
			}
		}
		state->dashboard_mode = 0;
		state->f_1068->task = 0;
		state->f_1068->status = 1;
		msg_led_update();
		FUN_0002ddb0();
		if (ctx->state != 2) {
			i = 100;
			while (state->suspend_state != 1) {
				k_msleep(10);
				if (!--i) {
					break;
				}
			}
		}
		G1_LOG_WRN("Now, I will goto run IDLE ^v^ g->persist_task->screen_id %d, persist->status %d pkg->screen_id %d\n",
			   state->f_1068->task, persist->status, state->dashboard_mode);
	}
	cnt = 0;
	msg_busy = 0;
	while (1) {
		if (IS_DFU(state)) {
			break;
		}
		if ((uint8_t)is_in_box()) {
			goto wait;
		}
		if (state->f_fee == 12 && (persist->task != 7 || state->dashboard_mode != 7)) {
			goto wait;
		}
		if (FUN_0002d9e8(state, state->dashboard_mode) == 1) {
			state->dashboard_mode = persist->task;
			if (state->dashboard_ts->f_74) {
				state->dashboard_ts->f_74 = 0;
			}
			if (state->task_1014->f_00 > 1) {
				state->task_1014->f_00 = 0;
			}
			trigger_screen_state_change("BLE:wakeup:persist_task", state, 1);
			break;
		}
		if (FUN_00033d5c() == 1) {
			goto wait;
		}
		if (state->onboarding->f_01 || !FUN_0007f3da() || get_dashboard_state()->task_1018->f_01) {
			cnt++;
			if ((cnt & 0x1f) == 0) {
				G1_LOG_ERR("There is an unfinished task,skip the local tasks:%d,%d,%d\n",
					   state->onboarding->f_01, FUN_0007f3da(),
					   get_dashboard_state()->task_1018->f_01);
			}
			goto wait;
		}
		v = state->dashboard_ts->f_74;
		if (v) {
			cnt++;
			k_msleep(50);
			if (cnt >= 80) {
				state->dashboard_ts->f_74 = 0;
			} else if (cnt % 40 == 0) {
				G1_LOG_WRN("dashboard wait for starting other task\n");
			}
			continue;
		}
		if (state->task_1014->f_00 > 1) {
			cnt++;
			k_msleep(50);
			if (cnt >= 100) {
				state->task_1014->f_00 = v;
			} else if (cnt % 40 == 0) {
				G1_LOG_WRN("evenai v2 wait for starting other task\n");
			}
			continue;
		}
		if (ctx->state == 2) {
			if (get_dashboard_state()->suspend_state != 5 && FUN_00035ea4()) {
				FUN_00037830();
				if (state->is_master == 1) {
					sync_message_signal_to_slave(1);
					clear_timeout_message(0);
					FUN_0002dd98();
					FUN_000359fc();
					update_temp_task_status(state, 4, 2);
					trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
				} else if (state->dashboard_mode != 4) {
					goto wait;
				}
				G1_LOG_ERR("goto message show task !\n");
				return SCREEN_CHANGED;
			}
			if (state->dashboard_ts->f_74) {
				goto check_msg;
			}
			if (ctx->state == 2 && get_dashboard_state()->suspend_state != 5 && !FUN_000260dc()) {
				goto show_dashboard;
			}
			/* the f_1245 test is written once per path (GIMPLE tail-merge would otherwise
			 * merge the split-edge forwarders into the one after the first ctx test and
			 * move the flag tests before the ctx == 2 body); crossjump shares the copies */
			if (state->f_1245) {
				goto show_dashboard;
			}
			goto test72;
		}
		if (state->f_1245) {
			goto show_dashboard;
		}
test72:
		if (!state->dashboard_ts->f_72) {
			goto check_msg;
		}
		{
show_dashboard:
			clear_dashboard_flag();
			if (state->is_master == 1) {
				sync_canvas_to_slave(state);
				if (FUN_0002d9e8(state, state->dashboard_mode) == 1) {
					continue;
				}
				if (get_dashboard_state()->is_master == 1 && get_glasses_ble_status() == 1 &&
				    !get_dashboard_state()->f_1247 && FUN_00030440() == 1) {
					FUN_0008040c();
				}
			} else if (/* same test written in both arms, see the f_1245 test above */
				   get_dashboard_state()->is_master == 1 && get_glasses_ble_status() == 1 &&
			    !get_dashboard_state()->f_1247 && FUN_00030440() == 1) {
				FUN_0008040c();
			}
			get_dashboard_state()->dashboard_ts->f_73 = 1;
			update_temp_task_status(state, 6, 2);
			trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
			return SCREEN_CHANGED;
		}
check_msg:
		if (state->message_mode) {
			if ((ctx->state == 1 && !FUN_000260dc()) || FUN_000260dc()) {
				if (FUN_00035acc() == 1 || FUN_00035a78() == 1) {
					FUN_00037830();
					if (state->is_master == 1) {
						sync_message_signal_to_slave(1);
						clear_timeout_message(0);
						FUN_0002dd98();
					FUN_000359fc();
						update_temp_task_status(state, 4, 2);
						trigger_screen_state_change("IMU:wakeup:uncomplete msg", state, 1);
						return SCREEN_CHANGED;
					}
					if (state->dashboard_mode == 4) {
						G1_PRINTK("goto message show task !");
						return SCREEN_CHANGED;
					}
					goto next_msg;
				}
			}
			if (state->message_mode) {
				goto next_msg;
			}
		}
		if (FUN_00035a78() == 1) {
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
next_msg:
		if (state->message_mode && state->dashboard_mode == 4 &&
		    ((ctx->state == 1 && !FUN_000260dc()) || FUN_000260dc())) {
			trigger_screen_state_change("BLE:wakeup:next-unread_msg", state, 1);
			break;
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

static int process_for_wait_blow_head(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	trigger_screen_state_change("WAIT_BLOW_HEAD", state, 0);
	while (1) {
		if (ctx->state == 1 || get_dashboard_state()->f_1244 == 4) {
			state->dashboard_mode = 0;
			return SCREEN_CHANGED;
		}
		if (state->f_1068->status == 2 && state->f_1068->task == 16) {
			state->dashboard_mode = 16;
			trigger_screen_state_change("BLE:wakeup:persist_task", state, 1);
			return 0;
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_countdown(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	struct ff4_ctx *cd;

	/* exit test at the loop top: the task_stop blocks get lower positions than the body */
	while (1) {
		if (!((struct ff4_ctx *)state->ptr_ff4)->f_05 || state->f_fee != 10) {
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
		cd = state->ptr_ff4;
		if (cd->ts == 0) {
			cd->f_05 = 0;
			update_persist_task_status(state, state->f_1068->task, 1);
			TASK_EXIT("countdown:ts is over");
		}
		if (ctx->state == 2) {
			if (state->f_0dd) {
				update_temp_task_status(state, 4, 2);
				FUN_0002dd98();
			} else {
				get_dashboard_state()->dashboard_ts->f_73 = 1;
				update_temp_task_status(state, 6, 2);
			}
			update_persist_task_status(state, state->f_1068->task, 3);
			return SCREEN_CHANGED;
		}
		if (state->dashboard_mode == 1) {
			TASK_EXIT("dashboard:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_message_show(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	uint16_t wait = 1000;
	int cnt;

	while (get_dashboard_state()->f_0dd &&
	       FUN_00035218(get_dashboard_state()->f_0dd - 1) != 4) {
		wait--;
		k_sleep(K_MSEC(1));
		if (!wait) {
			break;
		}
	}
	cnt = 0;
	state->f_0dc = 0;
	FUN_00035abc(4);
	state->f_0db = FUN_0002df54(state->f_fee, get_dashboard_state()->message_stay_time);
	while (1) {
		if ((!state->message_mode ? ctx->state == 1 || !state->f_0db : FUN_00035acc() == 2 || !state->f_0db) &&
		    state->f_fee == 10) {
			if (state->dashboard_mode == 6 ||
			    (state->dashboard_mode != 6 &&
			     ((!FUN_000260dc() && ctx->state == 2) ||
			      (state->f_1244 == 4 && state->f_1245 == 1)))) {
				if (get_dashboard_state()->message_mode && get_dashboard_state()->is_master == 1) {
					get_dashboard_state()->last_sync_ts -= 1000;
				}
				if (state->is_master == 1) {
					sync_canvas_to_slave(state);
					if (state->dashboard_ts->f_74) {
						state->dashboard_ts->f_74 = 0;
					}
				}
				k_sleep(K_MSEC(500));
				get_dashboard_state()->dashboard_ts->f_73 = 1;
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
			FUN_00035abc(5);
			if (state->is_master == 1) {
				k_sleep(K_MSEC(500));
			}
			if (FUN_00035a78() == 4) {
				continue;
			}
			TASK_EXIT("imu-trigger-off-imm");
		}
		if (IS_DFU(state) || get_dashboard_state()->f_fee == 12) {
			update_persist_task_status_to_idle(state);
			FUN_00035abc(5);
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
		    ((ctx->state == 1 && !FUN_000260dc()) || FUN_000260dc())) {
			if (cnt % 20 == 0 && state->f_0db < 30) {
				state->f_0db--;
			}
		}
		k_sleep(K_MSEC(50));
	}
}

static ALWAYS_INLINE int dashboard_goto_persist_task(struct GlassesState *state)
{
	if (!FUN_0002dd80(state->f_1068->task)) {
		FUN_00030458();
	}
	state->dashboard_mode = state->f_1068->task;
	return SCREEN_CHANGED;
}

static int process_for_DASHBOARD_show(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	uint8_t closing = 0;
	uint8_t d[2];

	state->f_0dc = 0;
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
		closing |= state->dashboard_ts->f_72;
		if (!closing) {
			if ((ctx->state == 1 && !FUN_000260dc()) ||
			    (!get_dashboard_state()->f_1245 && get_dashboard_state()->f_1244 == 4)) {
				goto close;
			}
		} else if (!state->dashboard_ts->f_72) {
close:
			clear_dashboard_flag();
			if (FUN_0002d9e8(state, state->dashboard_mode) == 1 && !state->dashboard_ts->f_74) {
				return dashboard_goto_persist_task(state);
			}
			FUN_00030458();
			sync_to_slave(state, 8, NULL, 0);
			goto dfu;
		} else {
			closing = 1;
		}
		if (!state->dashboard_ts->f_74) {
			if (FUN_0002d9e8(state, state->dashboard_mode) == 1) {
				if (!FUN_0002dd80(state->f_1068->task)) {
					FUN_00030458();
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
					state->f_0dc++;
					break;
				}
			}
			if (state->dashboard_mode == 1) {
				TASK_EXIT("dashboard:imu-trigger-off-imm");
			}
		}
		if (is_master() == 1 && state->dashboard_ts->f_74 == 1) {
			state->dashboard_ts->f_74 = 2;
		}
		if (state->dashboard_ts->f_74 == 2 && FUN_0002d9e8(state, state->dashboard_mode) == 1) {
			d[0] = 2;
			d[1] = 9;
			if (sync_to_slave(state, 6, d, 2) < 3000) {
				G1_LOG_WRN("sync close dashboard!\n");
				display_close_screen(6);
				while (state->dashboard_ts->f_73 == 1) {
					k_sleep(K_MSEC(50));
				}
				state->dashboard_ts->f_74 = 0;
				return dashboard_goto_persist_task(state);
			}
			G1_LOG_ERR("sync exit dashboard fail!\n");
		}
		if (state->dashboard_mode == 4) {
			FUN_00030458();
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
		if (msg_timeout_flag && FUN_000352f4()) {
			FUN_00030458();
			FUN_00037830();
			FUN_00035abc(6);
			update_temp_task_status(state, 4, 2);
			trigger_screen_state_change("display msg by touch", state, 1);
			return SCREEN_CHANGED;
		}
		get_dashboard_state();
		k_sleep(K_MSEC(50));
	}
}

static int process_for_unread_msg(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	state->f_b0d = 0;
	get_dashboard_state()->f_0dd = FUN_00035310();
	while (1) {
		if (ctx->state == 1 && state->f_fee == 10) {
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

static int process_for_teleprompter(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	struct task_blk *blk = state->task_1000;

	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("teleprompter:imu-trigger-off-imm");
		}
		if (!blk->f_01) {
			FUN_00030458();
			if (ctx->state == 2) {
				trigger_screen_state_change("IMU:wakeup:dashboard", state, 1);
				FUN_0003f23c();
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				if (state->is_master == 1) {
					k_sleep(K_MSEC(500));
				}
				k_sleep(K_MSEC(300));
			} else {
				sync_to_slave(state, 8, NULL, 0);
				update_persist_task_status_to_idle(state);
				FUN_0003f23c();
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

static int process_for_navigation(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	struct task_blk *blk = state->task_1004;

	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("navigation:imu-trigger-off-imm");
		}
		if (!blk->f_00) {
			if (ctx->state == 2) {
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

static int process_for_translate(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("translate:self exit");
		}
		if (!state->task_1008->f_06 && !state->task_100c->f_06) {
			if (ctx->state == 2) {
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

static int process_for_quicknote(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("quicknote:imu-trigger-off-imm");
		}
		if (!state->task_1034->f_01) {
			if (ctx->state == 2) {
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
	state->task_1018->f_01 = 0;
	while (1) {
		if (state->task_1018->f_00 && k_uptime_get() - BLK_TS(state->task_1018, 3) > 1500) {
			state->task_1018->f_00 = 0;
		}
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("not_disturb:dfu");
		}
		if (!state->task_1018->f_00) {
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
 * thing on both paths, the second copy written so that GIMPLE does not see the two copies as
 * equal.  RTL cross-jumping merges the copies after register allocation and the ctx test
 * disappears (no code), but ctx stays live inside the task loop, as in the shipped code
 * (state + 0x1000 and the log pointers then avoid r5).
 */
/* state->dashboard_mode read through its raw address (same load, different GIMPLE) */
#define DASHBOARD_MODE_RAW(state) \
	(*(uint8_t *)((uintptr_t)(state) + offsetof(struct GlassesState, dashboard_mode)))

/* G1_LOG with the BLE_DEBUG test inverted (same code, different GIMPLE) */
#define G1_LOG_ERR_SWAPPED(fmt, ...)                                                \
	do {                                                                        \
		if (LOG_LEVEL > 0) {                                                \
			if (!BLE_DEBUG) {                                           \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);      \
			} else {                                                    \
				ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);  \
			}                                                           \
		}                                                                   \
	} while (0)

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
		} else if (DASHBOARD_MODE_RAW(state) == 1) {                           \
			TASK_EXIT(name ":imu-trigger-off-imm");                        \
		}                                                                      \
		k_sleep(K_MSEC(50));                                                   \
	}

static int process_for_onboarding(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("onboarding", state->onboarding->active, 100)
}

static int process_for_raster_height(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("raster_height", state->task_1020->f_00, 500)
}

static int process_for_set_imu_pitch(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("set_imu_pitch", state->task_1024->f_00, 500)
}

static int process_for_transcribe(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	SIMPLE_TASK("transcribe", state->task_102c->f_00, 500)
}

static int process_for_prompt(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("prompt:dfu");
		}
		if (state->is_master == 1 && state->task_1028->f_00 &&
		    k_uptime_get() - BLK_TS(state->task_1028, 2) > 4000) {
			state->task_1028->f_00 = 0;
		}
		if (!state->task_1028->f_00) {
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
		} else if (DASHBOARD_MODE_RAW(state) == 1) {
			TASK_EXIT("prompt:imu-trigger-off-imm");
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_evenai(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	struct task_blk *ai;
	int cnt = 0;
	uint8_t st;

	while (1) {
		if (state->f_fee == 12) {
			task_stop(state, ctx);
			FUN_00080338(1);
			TASK_EXIT("evenai:self exit");
		}
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			FUN_00080338(1);
			TASK_EXIT("evenai:self exit");
		}
		if (!get_glasses_ble_status() && get_dashboard_state()->task_1010->f_00 > 1 &&
		    get_dashboard_state()->task_1010->f_00 < 10) {
			get_dashboard_state()->task_1010->f_00 = 10;
		}
		ai = state->task_1010;
		if (!ai->f_07 || !get_dashboard_state()->task_1010->f_00) {
			goto exit;
		}
		st = state->task_1010->f_00;
		if ((st == 8 || st == 11) && !state->f_0db) {
exit:
			if (state->is_master == 1) {
				report_event_to_phone(0);
			}
			sync_to_slave(state, 8, NULL, 0);
			update_persist_task_status_to_idle(state);
			FUN_00080338(1);
			TASK_EXIT("evenai:self exit");
		}
		if (state->dashboard_mode == 1) {
			FUN_00080338(1);
			TASK_EXIT("evenai:imu-trigger-off-imm");
		}
		cnt++;
		if (state->is_master == 1 && (st == 7 || st == 8 || st == 11) && cnt % 20 == 0) {
			state->f_0db--;
		}
		k_sleep(K_MSEC(50));
	}
}

static int process_for_even_ai_v2_show(struct GlassesState *state, struct message_ctx *ctx, const char **reason)
{
	int64_t now;

	if (get_dashboard_state()->is_master == 2 &&
	    k_sem_count_get(&get_dashboard_state()->sem_2) == 0) {
		k_sem_give(&get_dashboard_state()->sem_2);
	}
	now = k_uptime_get();
	/* packed store without UNALIGNED_PUT's compiler barrier (the shipped code schedules
	 * across it) */
	((struct __packed { int64_t v; } *)((uint8_t *)state->task_1014 + 6))->v = now;
	state->dashboard_ts->f_74 = 0;
	while (1) {
		if (IS_DFU(state)) {
			update_persist_task_status_to_idle(state);
			TASK_EXIT("evenai_v2:dfu");
		}
		if (state->is_master == 1 && state->task_1014->f_00 == 1) {
			if ((k_uptime_get() - BLK_TS(state->task_1014, 6) > 5000 &&
			     ((state->task_1014->f_01 == 7 && state->task_1014->f_03 == 1) ||
			      (state->task_1014->f_01 == 4 && state->task_1014->f_03 == 0x13))) ||
			    (k_uptime_get() - BLK_TS(state->task_1014, 6) > 10000 &&
			     state->task_1014->f_01 == 2)) {
				state->task_1014->f_00 = 0;
			}
		}
		if (is_master() == 1 && state->task_1014->f_00 == 2) {
			state->task_1014->f_00 = 3;
		}
		if (state->task_1014->f_00 == 0 || state->task_1014->f_00 == 3) {
			if (ctx->state == 2) {
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
				G1_LOG_ERR_SWAPPED("sync exit evenai_v2 fail!\n");
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

static inline bool u32_differs(const uint32_t *a, uint32_t b)
{
	return *a != b;
}

int process_for_new_message_come_on(struct GlassesState *state, struct message_ctx *ctx)
{
	int ret = 0;
	const char *reason;
	int cnt;
	uint32_t msg_id;
	uint32_t id;

	do {
		memset(state->buf_0ef, 0, sizeof(state->buf_0ef));
		clear_timeout_message(0);
		if (state->is_master == 1) {
			check_showing_message();
		}
		if (state->dashboard_mode != 4) {
			msg_busy = 0;
		}
		if (!state->screen_on && FUN_0002da10(state) == 1) {
			trigger_screen_state_change("BLE:wakeup:running_task", state, 1);
		}
		switch (state->dashboard_mode) {
		case 5:
			state->f_0db = FUN_0002df54(state->f_fee, get_dashboard_state()->message_stay_time);
			FUN_00035abc(2);
			cnt = 0;
			msg_id = *(uint32_t *)FUN_00035260(get_dashboard_state()->f_0dd - 1);
			while (1) {
				if (IS_DFU(state) || get_dashboard_state()->f_fee == 12) {
					update_persist_task_status_to_idle(state);
					reason = "message:imu-trigger-off-imm";
					ret = TASK_EXITED;
					break;
				}
				if (state->is_master == 1) {
					id = *(uint32_t *)FUN_00035260(get_dashboard_state()->f_0dd - 1);
					if (u32_differs(&msg_id, id)) {
						state->f_0db = FUN_0002df54(state->f_fee,
									    get_dashboard_state()->message_stay_time);
					}
					msg_id = id;
				}
				if (state->dashboard_mode != 5) {
					G1_LOG_ERR("goto next screen, new screen %d !\r\n\n", state->dashboard_mode);
					ret = SCREEN_CHANGED;
					break;
				}
				if (ctx->state == 2 || state->f_fee == 11) {
					FUN_00037830();
					if (state->f_b0d == 1) {
						update_temp_task_status(state, 8, 2);
						FUN_00035abc(4);
						ret = SCREEN_CHANGED;
						break;
					}
					if (state->dashboard_mode == 5 && state->is_master == 1) {
						sync_message_signal_to_slave(1);
						clear_timeout_message(0);
						FUN_0002dd98();
					FUN_000359fc();
						update_temp_task_status(state, 4, 2);
						trigger_screen_state_change("IMU:wakeup:new-notification", state, 1);
						G1_LOG_ERR("goto new message come on task master!\r\n\n");
						ret = SCREEN_CHANGED;
						break;
					}
				}
				if (!state->f_0db) {
					task_stop(state, ctx);
					FUN_00035abc(6);
					reason = "new-msg-timeout-goto-idle";
					ret = TASK_EXITED;
					break;
				}
				k_sleep(K_MSEC(50));
				cnt++;
				if (state->is_master == 1 && cnt % 20 == 0) {
					dec_nz(&state->f_0db);
				}
				if (!state->f_0db) {
					state->f_b0d = 0;
					task_stop(state, ctx);
					FUN_00035abc(6);
					/* &"..."[0]: the two timeout exits differ for GIMPLE tail-merge,
					 * RTL crossjump still shares them (target keeps this copy's else arm) */
					reason = &"new-msg-timeout-goto-idle"[0];
					ret = TASK_EXITED;
					break;
				}
			}
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
			trigger_screen_state_change(reason, state, 0);
			k_msleep(150);
			if (FUN_00035a78() == 1) {
				msg_led_update();
			}
			return 0;
		}
	} while (ret == SCREEN_CHANGED);
	return 0;
}

/* align-2 */

void FUN_00080338(int clear)
{
	get_dashboard_state()->f_0e9 = 0;
	get_dashboard_state()->f_0ea = 0;
	get_dashboard_state()->f_0cc = 0;
	get_dashboard_state()->f_0cd = 0;
	get_dashboard_state()->f_0ce = 0;
	get_dashboard_state()->f_0cf = 0;
	if (clear) {
		get_dashboard_state()->task_1010->f_07 = 0;
		get_dashboard_state()->task_1010->f_00 = 0;
	} else {
		get_dashboard_state()->task_1010->f_07 = 13;
	}
	memset(get_dashboard_state()->task_1010->data, 0, 0x1df);
}

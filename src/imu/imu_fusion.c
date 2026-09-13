/*
 * IMU (LSM6DSO) fusion context: sensor setup, mode switching, the
 * head-angle threshold calculation and the fusion thread (head-up /
 * bow-head gesture detection, motion/still detection).
 */
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/atomic.h>

#include <g1_log.h>

#include "imu_fusion.h"
#include "../ble/ble_proto.h"
#include "../display/proxy_thread.h"
#include "../main.h"
#include "../notify/notify.h"
#include "../production_test/production_test.h"
#include "../storage/storage.h"
#include "../threads/threads.h"

/*
 * Partial view of the GlassesState (src/main.h) as used here; main.h cannot be
 * included because it has its own partial struct imu_ctx.
 */

/* ESB block at GlassesState + 0xc8, the three tx fields used here */
struct imu_esb {
	uint8_t pad_00[0x25];
	uint8_t tx_cmd;				/* 0x25 (gs 0x0ed) */
	uint8_t tx_arg;				/* 0x26 (gs 0x0ee) */
	uint8_t tx_buf[12];			/* 0x27 (gs 0x0ef) yaw/pitch/roll (float) */
};
BUILD_ASSERT(offsetof(struct GlassesState, esb_block) + offsetof(struct imu_esb, tx_cmd) == offsetof(struct GlassesState, tx_cmd));






#define IMU_FUSION_STACK_SIZE	0x700
#define IMU_FUSION_PRIORITY	(-11)

K_THREAD_STACK_DEFINE(imu_fusion_stack, IMU_FUSION_STACK_SIZE);	/* 0x200242e0 */
static struct k_thread imu_fusion_thread_data;			/* 0x20004188 */

void imu_fusion_thread(void *p1, void *p2, void *p3);
int imu_fusion_init(struct imu_ctx *c);

/* motion / still detection state (0x20008490) */
struct imu_motion {
	uint8_t warmed_up;		/* 0x00 */
	uint8_t state;			/* 0x01: 0 idle, 1 moving, 2 settled */
	uint8_t pad_02[2];
	uint32_t samples;		/* 0x04 */
	int move_cnt;			/* 0x08 */
	int still_cnt;			/* 0x0c */
	int sign[3];			/* 0x10 */
	float prev[3];			/* 0x1c */
	float start[3];			/* 0x28 */
	float accum[3];			/* 0x34 */
};

/* forward declarations (definition order follows GCC's emission order) */
static int imu_fusion_deinit(struct imu_ctx *c);

static const float imu_motion_thr[3] = { 0.2f, 0.15f, 0.15f };	/* 0x8c1f4 */

static int imu_last_div = 300;
static int imu_angle_threshold = 150;
static uint8_t imu_last_wear = 3;

static struct imu_motion imu_motion;
uint32_t imu_pitch_x100;			/* pitch * 100 */
uint32_t imu_yaw_x100;			/* yaw * 100 */
uint32_t imu_roll_x100;			/* roll * 100 */
atomic_t dashboard_head_up_opened;
static int imu_last_ref;
static int imu_last_base;
static uint32_t imu_last_ms;
static int imu_last_pitch;
static int imu_trigger_count;
static int imu_level_pitch;
static uint8_t imu_last_level;

/*
 * 6-byte "look up" notification for the app (cmd 0x0650).  The vendor fills
 * the first word with the lock state before writing cmd (word store + halfword
 * store in the target), hence the union.
 */
union imu_lookup_msg {
	uint32_t word;
	struct {
		uint16_t cmd;
		uint16_t f2;
		uint8_t action;
		uint8_t status;
	} s;
};

void send_dashboard_lock_info(void)
{
	union imu_lookup_msg msg;
	bool locked;

	if (atomic_test_bit(&dashboard_lock_requested, 1) && !atomic_test_bit(&dashboard_head_up_opened, 1)) {
		locked = atomic_test_bit(&dashboard_lock_reported, 1);
		if (!locked && atomic_test_bit(&dashboard_lock_requested, 1)) {
			msg.word = locked;
			msg.s.cmd = 0x0650;
			msg.s.action = 1;
			msg.s.status = 1;
			send_response_data_to_msgqueue(&msg, 6);
			send_response_data_to_ble();
			atomic_set_bit(&dashboard_lock_reported, 1);
		}
	}
}

int update_head_up_thresholds(struct imu_ctx *c)
{
	int offset;
	int scaled;
	int t;
	int base_hi;

	if (c->ref != imu_last_ref || c->level != imu_last_level || c->wear != imu_last_wear ||
	    c->div != imu_last_div || c->base != imu_last_base) {
		imu_last_ref = c->ref;
		imu_last_level = c->level;
		imu_last_wear = c->wear;
		imu_last_div = c->div;
		imu_last_base = c->base;

		if (c->wear == 0) {
			offset = -350;
		} else {
			offset = (c->wear != 2) ? 0 : 700;
		}

		/* angle threshold: level scaled by 1900 in mode 2, else by 4000 */
		if (c->mode == 2) {
			scaled = c->level * 1900;
		} else {
			scaled = c->level * 4000;
		}
		imu_angle_threshold = scaled / c->div;
		is_master();

		base_hi = c->base - 4500;
		t = 50 * c->level + offset;
		if (c->base) {
			c->thr_low = c->base - t;
			c->thr_high = base_hi - t;
		} else if (c->ref) {
			c->thr_low = c->ref - t;
			c->thr_high = c->ref - 4500 - t;
		} else {
			c->thr_low = t - 6300;
			c->thr_high = t - 9300;
		}
	}

	return imu_angle_threshold;
}

/*
 * Head-up ("look up") / bow-head gesture detection.  Inlined into the thread; it
 * has to be a separate function (with its own `sync` pointer) for the target's
 * compare operand order and c-relative screen_id addressing.
 */
static void imu_fusion_set(struct imu_ctx *c, uint32_t val)
{
	if (c->sample_period_ms != val) {
		c->sample_period_ms = val;
	}
}


int update_imu_mode(struct imu_ctx *c, uint8_t mode)
{
	int retry;
	int ret;

	if (is_master() != 1) {
		return 0;
	}

	if (c->inited) {
		G1_LOG_WRN("imu_fusion: algo is existed\n\n");
		return -1;
	}

	is_master();
	c->dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));

	switch (mode) {
	case 1:
		c->odr.val1 = 12;
		c->odr.val2 = 0;
		break;
	case 2:
		c->odr.val1 = 26;
		c->odr.val2 = 0;
		break;
	case 0:
		c->odr.val1 = 0;
		c->odr.val2 = 0;
		break;
	}

	for (retry = 1;;) {
		ret = sensor_attr_set(c->dev, SENSOR_CHAN_ACCEL_XYZ,
				      SENSOR_ATTR_SAMPLING_FREQUENCY, &c->odr);
		if (ret >= 0) {
			break;
		}
		G1_LOG_WRN("c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d "
			   "retry_time %d.\n\n", ret, retry);
		if (++retry <= 20) {
			k_sleep(K_MSEC(5));
		} else {
			return -3;
		}
	}

	if (mode <= 2) {
		c->odr.val1 = 0;
		c->odr.val2 = 0;
	}

	for (retry = 1;;) {
		ret = sensor_attr_set(c->dev, SENSOR_CHAN_GYRO_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY,
				      &c->odr);
		if (ret >= 0) {
			break;
		}
		G1_LOG_WRN("c->imu_fusion: Cannot set sampling frequency for gyro %d.\n\n", retry);
		if (++retry <= 20) {
			k_sleep(K_MSEC(5));
		} else {
			return -4;
		}
	}

	G1_LOG_WRN("imu sensor update to mode %d\n", mode);

	return 0;
}


static int imu_fusion_deinit(struct imu_ctx *c)
{
	return 0;
}

static int imu_fusion_get(struct imu_ctx *c)
{
	return 0;
}


int register_imu_funsion_context(struct imu_ctx *c)
{
	c->init_cb = imu_fusion_init;
	c->deinit_cb = imu_fusion_deinit;
	c->get_cb = imu_fusion_get;
	c->set_cb = imu_fusion_set;
	G1_LOG_WRN("exit\n\n");

	return 0;
}

int imu_fusion_init(struct imu_ctx *c)
{
	int ret;

	if (c->inited) {
		G1_LOG_WRN("imu_fusion: algo is existed\n\n");
		return -1;
	}

	is_master();
	c->dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
	G1_LOG_WRN("imu_fusion: sensor device is ready:\n\n");

	c->odr.val1 = (is_master() != 1) ? 0 : 52;
	c->odr.val2 = 0;
	ret = sensor_attr_set(c->dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY,
			      &c->odr);
	if (ret < 0) {
		G1_LOG_WRN("c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d.\n\n",
			   ret);
		return -3;
	}

	is_master();
	c->odr.val1 = 0;
	c->odr.val2 = 0;
	ret = sensor_attr_set(c->dev, SENSOR_CHAN_GYRO_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY,
			      &c->odr);
	if (ret < 0) {
		G1_LOG_WRN("c->imu_fusion: Cannot set sampling frequency for gyro.\n\n");
		return -4;
	}

	c->sample_period_ms = 0;
	G1_LOG_WRN("sensor_fusion_init:\n\n");
	Mahony_init(&c->fusion);
	c->inited = 0;
	c->thread_running = 1;
	update_head_up_thresholds(c);

	k_thread_create(&imu_fusion_thread_data, imu_fusion_stack, IMU_FUSION_STACK_SIZE, imu_fusion_thread, c,
			NULL, NULL, IMU_FUSION_PRIORITY, 0, K_NO_WAIT);

	return 0;
}


static void imu_head_gesture(struct imu_ctx *c, int pitch, int yaw, int roll, float *angles)
{
	struct GlassesState *gs = CONTAINER_OF(c, struct GlassesState, imu);
	struct esb_sync_pkt *sync = &gs->sync;
	int retry;

	if (sync->screen_id == 0) {
		/*
		 * |pitch - last| < 50, written per sign with the lock block in both
		 * arms (as the vendor did: the copies are cross-jumped after reload
		 * and the abs becomes cmp/ite/sub/sub).
		 */
		if (pitch >= imu_last_pitch) {
			if (pitch - imu_last_pitch < 50) {
				imu_last_pitch = pitch;
				imu_trigger_count = 0;
				send_dashboard_lock_info();
				goto level_check;
			}
		} else {
			if (imu_last_pitch - pitch < 50) {
				imu_last_pitch = pitch;
				imu_trigger_count = 0;
				send_dashboard_lock_info();
				goto level_check;
			}
		}
	}

	imu_last_pitch = pitch;
	if (sync->screen_id == 13) {
		/* the vendor addresses the ESB block (gs + 0xc8) through one pointer */
		struct imu_esb *esb = (struct imu_esb *)&gs->esb_block;

		esb->tx_cmd = 12;
		esb->tx_arg = 0;
		memcpy(esb->tx_buf, angles, 3 * sizeof(float));
	}

	imu_pitch_x100 = pitch;
	imu_yaw_x100 = yaw;
	imu_roll_x100 = roll;

	if (c->mode != 2) {
		if (pitch <= c->thr_low && pitch >= c->thr_high) {
			/* head is up: look up */
			k_uptime_ticks();
			if (get_dashboard_state()->suspend_state != 0 && get_dashboard_state()->suspend_state != 1) {
				goto level_check;
			}
			imu_trigger_count++;
			if (BLE_DEBUG) {
				ble_printk("trigger_count %d", imu_trigger_count);
			} else {
				printk("trigger_count %d", imu_trigger_count);
			}
			if (imu_trigger_count > 1) {
				int level_pitch;
				uint8_t level;

				imu_trigger_count = -3;
				level_pitch = imu_level_pitch;
				level = c->level;
				if (sync->screen_id != 0 || pitch < level_pitch) {
					screen_switch_busy = 1;
					if (BLE_DEBUG) {
						ble_printk("look up################################################,screen_id is %d, pitch_y is %d, pitch_threshold_bow_head is %d, pitch_threshold_level is %d\n",
							   sync->screen_id, pitch, c->thr_low, level);
					} else {
						printk("look up################################################,screen_id is %d, pitch_y is %d, pitch_threshold_bow_head is %d, pitch_threshold_level is %d\n",
						       sync->screen_id, pitch, c->thr_low, level);
					}
					retry = 101;
					while (!get_dashboard_state()->message_mode && push_msg_syncing && --retry) {
						k_sleep(K_MSEC(10));
					}
					report_event_to_phone(2);
					if (sync->screen_id == 9 || sync->screen_id == 12 ||
					    sync->screen_id == 10 || sync->screen_id == 11 ||
					    sync->screen_id == 5 || sync->screen_id == 4 ||
					    sync->screen_id == 7 || sync->screen_id == 14 ||
					    sync->screen_id == 15 || sync->screen_id == 16 ||
					    sync->screen_id == 20 || sync->screen_id == 17 ||
					    sync->screen_id == 18 || sync->screen_id == 19) {
						c->mode = 2;
						screen_switch_busy = 0;
						return;
					}
					if (!get_dashboard_startup_mode()) {
						if (atomic_test_bit(&dashboard_lock_requested, 1)) {
							if (!atomic_test_bit(&dashboard_head_up_opened, 1)) {
								union imu_lookup_msg msg;
								bool locked;

								locked = atomic_test_bit(&dashboard_lock_reported, 1);
								if (!locked &&
								    atomic_test_bit(&dashboard_lock_requested, 1)) {
									msg.word = locked;
									msg.s.cmd = 0x0650;
									msg.s.action = 1;
									msg.s.status = 1;
									send_response_data_to_msgqueue(&msg, 6);
									send_response_data_to_ble();
									atomic_set_bit(&dashboard_lock_reported, 1);
								}
							}
						} else {
							c->mode = 2;
							if (!atomic_test_bit(&dashboard_head_up_opened, 1)) {
								atomic_set_bit(&dashboard_head_up_opened, 1);
							}
						}
					} else {
						c->mode = 2;
					}
					screen_switch_busy = 0;
				}
			}
			goto level_check;
		}
	} else if (pitch > c->thr_low + 100 || pitch < c->thr_high) {
		/* head went down: bow head */
		if (++imu_trigger_count < 2) {
			goto level_check;
		}
		imu_trigger_count = -3;
		screen_switch_busy = 1;
		if (BLE_DEBUG) {
			ble_printk("bow head################################################\n");
		} else {
			printk("bow head################################################\n");
		}
		report_event_to_phone(3);
		c->mode = 1;
		if (sync->screen_id == 9 || sync->screen_id == 12 || sync->screen_id == 10 ||
		    sync->screen_id == 11 || sync->screen_id == 7 || sync->screen_id == 14 ||
		    sync->screen_id == 15 || sync->screen_id == 16 || sync->screen_id == 20 ||
		    sync->screen_id == 17 || sync->screen_id == 18 || sync->screen_id == 19 ||
		    sync->screen_id == 4 || is_persist_task_active(gs, sync->screen_id)) {
			screen_switch_busy = 0;
			return;
		}
		gs->esb_arg2 = gs->panel.panel_brightness_level;
		if (sync->screen_id == 1) {
			sync_to_slave(gs, 8, NULL, 0);
		} else if ((!gs->message_mode || cur_message_show_state() != 1) && !get_dashboard_startup_mode() &&
			   !gs->dashboard_ts->dashboard_hold) {
			sync_to_slave(gs, 1, NULL, 0);
		}
		if (!gs->message_mode && !get_dashboard_startup_mode() && !gs->dashboard_ts->dashboard_hold) {
			exit_temp_task(gs, 0);
		}
		screen_switch_busy = 0;
		goto level_check;
	}

	if (imu_trigger_count < 0) {
		imu_trigger_count++;
	} else {
		imu_trigger_count = 0;
	}
	return;

level_check:
	if (c->mode == 1 && imu_trigger_count <= 0) {
		k_uptime_ticks();
		imu_level_pitch = pitch;
	}
}

/* Motion / still detection on the yaw/pitch/roll angles (inlined into the thread). */
static void imu_motion_detect(struct imu_ctx *c, float *angles)
{
	struct GlassesState *gs = CONTAINER_OF(c, struct GlassesState, imu);
	struct esb_sync_pkt *sync = &gs->sync;
	float diff[3];
	float out[3];
	int moved;
	int i;

	for (i = 0; i < 3; i++) {
		diff[i] = angles[i] - imu_motion.prev[i];
	}
	memset(out, 0, sizeof(out));

	switch (imu_motion.state) {
	case 0:
		moved = 0;
		for (i = 0; i < 3; i++) {
			if (fabsf(diff[i]) > imu_motion_thr[i]) {
				int s = (diff[i] > 0) ? 1 : -1;

				if (imu_motion.sign[i] == s) {
					moved++;
				}
				imu_motion.sign[i] = s;
			}
		}
		if (moved) {
			if (imu_motion.move_cnt == 0) {
				memcpy(imu_motion.start, angles, 3 * sizeof(float));
				imu_motion.move_cnt = 1;
			} else if (++imu_motion.move_cnt > 4) {
				imu_motion.state = 1;
			}
		}
		break;
	case 1: {
		float delta[3];

		for (i = 0; i < 3; i++) {
			delta[i] = angles[i] - imu_motion.start[i];
			if (fabsf(delta[i]) > 180.0f) {
				if (delta[i] > 0) {
					delta[i] -= 360.0f;
				} else {
					delta[i] += 360.0f;
				}
			}
			out[i] = imu_motion.accum[i] + delta[i];
		}
		(void)sync->screen_id;	/* unused volatile read in the vendor code */
		if (fabsf(diff[0]) > 0.1f || fabsf(diff[1]) > 0.1f || fabsf(diff[2]) > 0.1f) {
			imu_motion.still_cnt = 0;
		} else if (++imu_motion.still_cnt > 4) {
			imu_motion.state = 2;
			memcpy(imu_motion.accum, out, sizeof(out));
		}
		break;
	}
	case 2:
		imu_motion.move_cnt = 0;
		imu_motion.still_cnt = 0;
		memset(imu_motion.sign, 0, sizeof(imu_motion.sign));
		imu_motion.state = 0;
		break;
	}

	memcpy(imu_motion.prev, angles, 3 * sizeof(float));
}

void imu_fusion_thread(void *p1, void *p2, void *p3)
{
	struct imu_ctx *c = p1;
	struct GlassesState *gs;
	float angles[3] = { 0 };
	struct sensor_value accel[3];
	struct sensor_value gyro[3];
	float ax, ay, az, gx, gy, gz, dt;
	uint32_t now;
	int yaw, pitch, roll;

	memset(accel, 0, sizeof(accel));
	memset(gyro, 0, sizeof(gyro));

	if (c->inited) {
		G1_LOG_WRN("error\n\n");
		return;
	}

	G1_LOG_WRN("start imu looper\n\n");
	c->mode = 1;
	gs = CONTAINER_OF(c, struct GlassesState, imu);
	now = 0;

	while (c->thread_running) {
		while (gs->work_mode == 1 || gs->work_mode == 8) {
			k_sleep(K_MSEC(5000));
		}

		if (get_pt_test_mode() == 0) {
			if (gs->display_mode == 11) {
				c->mode = 2;
				k_sleep(K_MSEC(1000));
				continue;
			}
			if (gs->display_mode == 12) {
				c->mode = 1;
				if (gs->sync.screen_id != 7) {
					sync_to_slave(gs, 1, NULL, 0);
					if (get_work_mode() == 2) {
						change_work_mode(3);
					}
					exit_running_task(gs, 1);
				}
				k_sleep(K_MSEC(1000));
				continue;
			}
			if (!(gs->module_mask & BIT(5))) {
				c->mode = 1;
				k_sleep(K_MSEC(100));
				continue;
			}
			now = k_uptime_get();
			if (now - imu_last_ms > 1000) {
				Mahony_init(&c->fusion);
			}
		}

		if (sensor_sample_fetch(c->dev) < 0) {
			k_sleep(K_MSEC(20));
			continue;
		}
		sensor_channel_get(c->dev, SENSOR_CHAN_ACCEL_XYZ, accel);
		sensor_channel_get(c->dev, SENSOR_CHAN_GYRO_XYZ, gyro);

		ax = sensor_value_to_double(&accel[0]) * 10;
		ay = sensor_value_to_double(&accel[1]) * 10;
		az = sensor_value_to_double(&accel[2]) * 10;
		gx = sensor_value_to_double(&gyro[0]);
		gy = sensor_value_to_double(&gyro[1]);
		gz = sensor_value_to_double(&gyro[2]);

		gs->accel[0] = ax;
		gs->accel[1] = ay;
		gs->accel[2] = az;

		gx = gx - 0.0585;
		gy = gy + 0.0325;
		gz = gz - 0.01;

		dt = Mahony_deltatUpdate(&c->fusion);
		Mahony_updateIMU(gx, gy, gz, ax, ay, az, dt, &c->fusion);
		angles[0] = Mahony_getYaw(&c->fusion);
		angles[1] = Mahony_getPitch(&c->fusion);
		angles[2] = Mahony_getRoll(&c->fusion);

		pitch = angles[1] * 100;
		yaw = angles[0] * 100;
		roll = angles[2] * 100;
		imu_pitch_x100 = pitch;
		imu_yaw_x100 = yaw;
		imu_roll_x100 = roll;

		if (get_pt_test_mode() == 1 && gs->display_mode == 11) {
			c->mode = 2;
			k_sleep(K_MSEC(10));
			continue;
		}

		imu_last_ms = now;
		imu_motion.samples++;
		if (!imu_motion.warmed_up) {
			if (imu_motion.samples <= 200) {
				k_sleep(K_MSEC(10));
				continue;
			}
			imu_motion.warmed_up = 1;
			memcpy(imu_motion.prev, angles, sizeof(angles));
		}

		update_head_up_thresholds(c);
		imu_head_gesture(c, pitch, yaw, roll, angles);

		imu_motion_detect(c, angles);

		if (c->mode == 2) {
			k_sleep(K_MSEC(38));
		} else {
			k_sleep(K_MSEC(80));
		}
	}
}

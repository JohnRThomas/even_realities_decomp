/* IMU fusion context (GlassesState imu, partial) and the attitude filter */
#ifndef G1_IMU_FUSION_H_
#define G1_IMU_FUSION_H_

#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/atomic.h>

#include "../ahrs/ahrs.h"
#include <glasses_state.h>

/* imu_fusion.c */
extern atomic_t dashboard_head_up_opened; /* imu/dashboard lock bits */
extern uint32_t imu_roll_x100;
extern uint32_t imu_yaw_x100;
extern uint32_t imu_pitch_x100; /* imu pitch base */
int update_imu_mode(struct imu_ctx *c, uint8_t mode);
int register_imu_funsion_context(struct imu_ctx *c);

#endif /* G1_IMU_FUSION_H_ */

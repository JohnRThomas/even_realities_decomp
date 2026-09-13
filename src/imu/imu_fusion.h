/* IMU fusion context (GlassesState imu, partial) and the attitude filter */
#ifndef G1_IMU_FUSION_H_
#define G1_IMU_FUSION_H_

#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

/*
 * attitude filter state (0x44 bytes): the members of the Arduino Mahony class
 * (referenced_examples/mahony_ahrs/src/MahonyAHRS.h) in vendor order, with
 * Madgwick's beta added in front, invSampleFreq replaced by a measured period
 * and anglesComputed moved before the angles.
 */
struct ahrs {
	float beta;		/* 0x00: 0.1 (unused by the Mahony update) */
	float twoKp;		/* 0x04: 2 * proportional gain (Kp) */
	float twoKi;		/* 0x08: 2 * integral gain (Ki) */
	float q0, q1, q2, q3;	/* 0x0c: quaternion of sensor frame relative to auxiliary frame */
	float integralFBx, integralFBy, integralFBz;	/* 0x1c: integral error terms scaled by Ki */
	char anglesComputed;	/* 0x28 */
	uint8_t pad_29[3];
	float roll;		/* 0x2c (rad) */
	float pitch;		/* 0x30 */
	float yaw;		/* 0x34 */
	uint32_t Now;		/* 0x38: ms */
	uint32_t lastUpdate;	/* 0x3c: ms */
	float deltat;		/* 0x40: s */
};

struct imu_ctx {
	uint8_t mode;			/* 0x00 */
	uint8_t pad_01[7];
	int thr_low;			/* 0x08 */
	int thr_high;			/* 0x0c */
	uint8_t level;			/* 0x10 */
	uint8_t wear;			/* 0x11 */
	uint8_t pad_12[2];
	uint8_t inited;			/* 0x14 */
	uint8_t f15;			/* 0x15 */
	uint8_t pad_16[2];
	uint32_t f18;			/* 0x18 */
	const struct device *dev;	/* 0x1c */
	struct sensor_value odr;	/* 0x20 */
	struct ahrs fusion;		/* 0x28 */
	uint8_t pad_6c[0x14];
	int ref;			/* 0x80 */
	int base;			/* 0x84 */
	int div;			/* 0x88 */
	int (*init_cb)(struct imu_ctx *c);		/* 0x8c */
	int (*deinit_cb)(struct imu_ctx *c);		/* 0x90 */
	int (*get_cb)(struct imu_ctx *c);		/* 0x94 */
	void (*set_cb)(struct imu_ctx *c, uint32_t val);	/* 0x98 */
};

/* ahrs.c (MahonyAHRS) */
void Mahony_init(struct ahrs *a);
float Mahony_invSqrt(float x);
void Mahony_updateIMU(float gx, float gy, float gz, float ax, float ay, float az, float dt,
		      struct ahrs *a);
float Mahony_deltatUpdate(struct ahrs *a);
float Mahony_getRoll(struct ahrs *a);
float Mahony_getPitch(struct ahrs *a);
float Mahony_getYaw(struct ahrs *a);
void Mahony_computeAngles(struct ahrs *a);

#endif /* G1_IMU_FUSION_H_ */

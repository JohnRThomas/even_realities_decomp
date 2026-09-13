/* Mahony AHRS attitude filter (C port of the Arduino MahonyAHRS library) */
#ifndef G1_AHRS_H_
#define G1_AHRS_H_

#include <stdint.h>

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

void Mahony_init(struct ahrs *a);
float Mahony_invSqrt(float x);
void Mahony_updateIMU(float gx, float gy, float gz, float ax, float ay, float az, float dt,
		      struct ahrs *a);
float Mahony_deltatUpdate(struct ahrs *a);
float Mahony_getRoll(struct ahrs *a);
float Mahony_getPitch(struct ahrs *a);
float Mahony_getYaw(struct ahrs *a);
void Mahony_computeAngles(struct ahrs *a);

#endif /* G1_AHRS_H_ */

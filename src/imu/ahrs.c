/*
 * Attitude filter: Mahony AHRS, a C port of the Arduino MahonyAHRS library
 * (referenced_examples/mahony_ahrs/src/MahonyAHRS.cpp, Madgwick's
 * implementation of Mahony's algorithm): Mahony() -> Mahony_init,
 * invSqrt, updateIMU, computeAngles, getRoll/getPitch/getYaw.  The class
 * members live in struct ahrs (imu_fusion.h).
 *
 * Vendor changes against the reference:
 *   - gains: twoKp = 4.0 (reference 2 * 0.5), plus a Madgwick-style
 *     beta = 0.1 member that the update never reads;
 *   - updateIMU takes the sample period dt instead of invSampleFreq and does
 *     not convert the gyro rates from deg/s (callers pass rad/s);
 *   - the period is measured by Mahony_deltatUpdate (Now / lastUpdate / deltat,
 *     the kriswiner MPU9250 sketch idiom, in ms from k_uptime_get());
 *   - getters use 57.295f instead of 57.29578f;
 *   - invSqrt uses a pointer cast instead of the union.
 *
 * Original file name unknown.  Link order: after spim.c
 * (align-4 0x28694..0x2892b, align-2 0x7fe2e..0x7fea5).
 */
#include <math.h>
#include <zephyr/kernel.h>

#include "imu_fusion.h"

void Mahony_init(struct ahrs *a)
{
	a->beta = 0.1f;
	a->twoKp = 4.0f;	/* 2 * proportional gain (Kp) */
	a->twoKi = 0.0f;	/* 2 * integral gain (Ki) */
	a->q0 = 1.0f;
	a->q1 = 0.0f;
	a->q2 = 0.0f;
	a->q3 = 0.0f;
	a->integralFBx = 0.0f;
	a->integralFBy = 0.0f;
	a->integralFBz = 0.0f;
	a->Now = 0;
	a->lastUpdate = 0;
	a->anglesComputed = 0;
}

/* Fast inverse square-root */
float Mahony_invSqrt(float x)
{
	float halfx = 0.5f * x;
	float y = x;
	int32_t i = *(int32_t *)&y;

	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5f - (halfx * y * y));
	y = y * (1.5f - (halfx * y * y));

	return y;
}

void Mahony_updateIMU(float gx, float gy, float gz, float ax, float ay, float az, float dt,
		      struct ahrs *a)
{
	float recipNorm;
	float halfvx, halfvy, halfvz;
	float halfex, halfey, halfez;
	float qa, qb, qc;

	/* Compute feedback only if accelerometer measurement valid
	 * (avoids NaN in accelerometer normalisation)
	 */
	if (!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {
		/* Normalise accelerometer measurement */
		recipNorm = Mahony_invSqrt(ax * ax + ay * ay + az * az);
		ax *= recipNorm;
		ay *= recipNorm;
		az *= recipNorm;

		/* Estimated direction of gravity */
		halfvx = a->q1 * a->q3 - a->q0 * a->q2;
		halfvy = a->q0 * a->q1 + a->q2 * a->q3;
		halfvz = a->q0 * a->q0 - 0.5f + a->q3 * a->q3;

		/* Error is sum of cross product between estimated
		 * and measured direction of gravity
		 */
		halfex = (ay * halfvz - az * halfvy);
		halfey = (az * halfvx - ax * halfvz);
		halfez = (ax * halfvy - ay * halfvx);

		/* Compute and apply integral feedback if enabled */
		if (a->twoKi > 0.0f) {
			/* integral error scaled by Ki */
			a->integralFBx += a->twoKi * halfex * dt;
			a->integralFBy += a->twoKi * halfey * dt;
			a->integralFBz += a->twoKi * halfez * dt;
			gx += a->integralFBx;	/* apply integral feedback */
			gy += a->integralFBy;
			gz += a->integralFBz;
		} else {
			a->integralFBx = 0.0f;	/* prevent integral windup */
			a->integralFBy = 0.0f;
			a->integralFBz = 0.0f;
		}

		/* Apply proportional feedback */
		gx += a->twoKp * halfex;
		gy += a->twoKp * halfey;
		gz += a->twoKp * halfez;
	}

	/* Integrate rate of change of quaternion */
	gx *= (0.5f * dt);	/* pre-multiply common factors */
	gy *= (0.5f * dt);
	gz *= (0.5f * dt);
	qa = a->q0;
	qb = a->q1;
	qc = a->q2;
	a->q0 += (-qb * gx - qc * gy - a->q3 * gz);
	a->q1 += (qa * gx + qc * gz - a->q3 * gy);
	a->q2 += (qa * gy - qb * gz + a->q3 * gx);
	a->q3 += (qa * gz + qb * gy - qc * gx);

	/* Normalise quaternion */
	recipNorm = Mahony_invSqrt(a->q0 * a->q0 + a->q1 * a->q1 + a->q2 * a->q2 + a->q3 * a->q3);
	a->q0 *= recipNorm;
	a->q1 *= recipNorm;
	a->q2 *= recipNorm;
	a->q3 *= recipNorm;
	a->anglesComputed = 0;
}

/* vendor: measure the sample period (no counterpart in the reference) */
float Mahony_deltatUpdate(struct ahrs *a)
{
	a->Now = k_uptime_get();
	a->deltat = (float)(a->Now - a->lastUpdate) / 1000.0f;
	a->lastUpdate = a->Now;

	return a->deltat;
}

float Mahony_getRoll(struct ahrs *a)
{
	if (!a->anglesComputed) {
		Mahony_computeAngles(a);
	}

	return a->roll * 57.295f;
}

float Mahony_getPitch(struct ahrs *a)
{
	if (!a->anglesComputed) {
		Mahony_computeAngles(a);
	}

	return a->pitch * 57.295f;
}

float Mahony_getYaw(struct ahrs *a)
{
	if (!a->anglesComputed) {
		Mahony_computeAngles(a);
	}

	return a->yaw * 57.295f + 180.0f;
}

void Mahony_computeAngles(struct ahrs *a)
{
	a->roll = atan2f(a->q0 * a->q1 + a->q2 * a->q3, 0.5f - a->q1 * a->q1 - a->q2 * a->q2);
	a->pitch = asinf(-2.0f * (a->q1 * a->q3 - a->q0 * a->q2));
	a->yaw = atan2f(a->q1 * a->q2 + a->q0 * a->q3, 0.5f - a->q2 * a->q2 - a->q3 * a->q3);
	a->anglesComputed = 1;
}

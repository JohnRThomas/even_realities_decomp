/*
 * "Burial point" (usage statistics): per-day wear / dashboard / notification
 * counters and durations in a 7-day ring, kept in GlassesState + 0x1128.
 * Reconstructed from the v1.63 app core (original file name unknown).
 */
#include <stdint.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "burial_point.h"

int update_burial_point_day_index(void)
{
	uint32_t ts = get_dashboard_tx_ctx();
	struct bp_date date = { 0 };
	uint8_t i;

	init_burial_point_date(ts, &date);
	if (date.year < 2024 || (date.year == 2024 && date.month < 8)) {
		G1_LOG_WRN("burial point date was not init!\n");
		return -1;
	}

	if (BP_GS()->bp.day_index > 6) {
		BP_GS()->bp.day_index = 0;
	}

	if (BP_GS()->bp.wear_day[BP_GS()->bp.day_index].year == date.year &&
	    BP_GS()->bp.wear_day[BP_GS()->bp.day_index].month == date.month &&
	    BP_GS()->bp.wear_day[BP_GS()->bp.day_index].day == date.day) {
		/*
		 * Both paths return 0; the extra test is kept because the shipped
		 * code has the block structure it produces (found by the permuter).
		 */
		if (date.month == 0) {
			return 0;
		}
		return 0;
	}

	for (i = 0; i < 7; i++) {
		if (BP_GS()->bp.day_index != i && BP_GS()->bp.wear_day[i].year == date.year &&
		    BP_GS()->bp.wear_day[i].month == date.month &&
		    BP_GS()->bp.wear_day[i].day == date.day) {
			BP_GS()->bp.day_index = i;
			break;
		}
	}
	if (i == 7) {
		BP_GS()->bp.day_index++;
		if (BP_GS()->bp.day_index > 6) {
			BP_GS()->bp.day_index = 0;
		}
	}

	BP_GS()->bp.wear_day[BP_GS()->bp.day_index].year = date.year;
	BP_GS()->bp.wear_day[BP_GS()->bp.day_index].month = date.month;
	BP_GS()->bp.wear_day[BP_GS()->bp.day_index].day = date.day;
	BP_GS()->bp.wear_day[BP_GS()->bp.day_index].sum_time = 0;
	BP_GS()->bp.wear_day[BP_GS()->bp.day_index].count = 0;
	BP_GS()->bp.dashboard_day[BP_GS()->bp.day_index].year = date.year;
	BP_GS()->bp.dashboard_day[BP_GS()->bp.day_index].month = date.month;
	BP_GS()->bp.dashboard_day[BP_GS()->bp.day_index].day = date.day;
	BP_GS()->bp.dashboard_day[BP_GS()->bp.day_index].sum_time = 0;
	BP_GS()->bp.dashboard_day[BP_GS()->bp.day_index].count = 0;
	BP_GS()->bp.notification_day[BP_GS()->bp.day_index].year = date.year;
	BP_GS()->bp.notification_day[BP_GS()->bp.day_index].month = date.month;
	BP_GS()->bp.notification_day[BP_GS()->bp.day_index].day = date.day;
	BP_GS()->bp.notification_day[BP_GS()->bp.day_index].sum_time = 0;
	BP_GS()->bp.notification_day[BP_GS()->bp.day_index].count = 0;

	return 0;
}

/* index of today's slot, 7 if the date is not known */
uint8_t FUN_00081216(void)
{
	if (update_burial_point_day_index() != 0) {
		return 7;
	}

	return BP_GS()->bp.day_index;
}

void FUN_00081230(void)
{
	if (BP_GS()->wear.active && FUN_00081216() < 7) {
		BP_GS()->wear.active = 0;
	}
}

void FUN_00081258(int64_t ms)
{
	uint8_t idx = FUN_00081216();

	if (idx < 7) {
		BP_GS()->bp.wear_day[idx].sum_time += ms / 1000;
		BP_GS()->bp.wear_sum_time += ms / 1000;
	}
}

void enter_wear_burial_point(void)
{
	uint8_t idx;

	if (FUN_00033d5c() == 1 || BP_GS()->wear.active == 1) {
		return;
	}

	idx = FUN_00081216();
	if (idx >= 7) {
		return;
	}

	BP_GS()->wear.active = 1;
	BP_GS()->wear.day_index = idx;
	BP_GS()->wear.start_time = k_uptime_get();
	BP_GS()->bp.wear_day[idx].count++;
	BP_GS()->bp.wear_count++;

	G1_LOG_WRN("[enter_wear_burial_point] start_time is %d\n", BP_GS()->wear.start_time);
}

int64_t get_dashboard_sum_time(void)
{
	int64_t t;

	if (k_uptime_get() > BP_GS()->dashboard.start_time) {
		t = k_uptime_get() - BP_GS()->dashboard.start_time;
	} else {
		t = BP_GS()->dashboard.start_time - k_uptime_get();
	}

	G1_LOG_WRN("get_dashboard_sum_time is %d\n", t);

	return t;
}

void add_dashboard_burial_time(int64_t ms)
{
	uint8_t idx = FUN_00081216();

	if (idx < 7) {
		BP_GS()->bp.dashboard_day[idx].sum_time += ms / 1000;
		BP_GS()->bp.dashboard_sum_time += ms / 1000;
	}
}

void enter_dashboard_burial_point(void)
{
	uint8_t idx;

	if (FUN_00033d5c() == 1 || BP_GS()->dashboard.active == 1) {
		return;
	}

	idx = FUN_00081216();
	if (idx >= 7) {
		return;
	}

	BP_GS()->dashboard.active = 1;
	BP_GS()->dashboard.day_index = idx;
	BP_GS()->dashboard.start_time = k_uptime_get();
	BP_GS()->bp.dashboard_day[idx].count++;
	BP_GS()->bp.dashboard_count++;

	G1_LOG_WRN("[enter_dashboard_burial_point] start_time is %d\n",
		   BP_GS()->dashboard.start_time);
}

void exit_dashboard_burial_point(void)
{
	int64_t t;

	if (BP_GS()->dashboard.active && FUN_00081216() < 7) {
		BP_GS()->dashboard.active = 0;
		t = get_dashboard_sum_time();
		add_dashboard_burial_time(t);
		G1_LOG_WRN("[exit_dashboard_burial_point] sum_time is %d ms,dashboard_sum_time is %d s\n",
			   t, BP_GS()->bp.dashboard_sum_time);
	}
}

int64_t get_notification_sum_time(void)
{
	int64_t t;

	if (k_uptime_get() > BP_GS()->notification.start_time) {
		t = k_uptime_get() - BP_GS()->notification.start_time;
	} else {
		t = BP_GS()->notification.start_time - k_uptime_get();
	}

	G1_LOG_WRN("get_notification_sum_time is %d\n", t);

	return t;
}

void add_notification_burial_time(int64_t ms)
{
	uint8_t idx = FUN_00081216();

	if (idx < 7) {
		BP_GS()->bp.notification_day[idx].sum_time += ms / 1000;
		BP_GS()->bp.notification_sum_time += ms / 1000;
	}
}

void enter_notification_burial_point(void)
{
	uint8_t idx;

	if (FUN_00033d5c() == 1 || BP_GS()->notification.active == 1) {
		return;
	}

	idx = FUN_00081216();
	if (idx >= 7) {
		return;
	}

	BP_GS()->notification.active = 1;
	BP_GS()->notification.day_index = idx;
	BP_GS()->notification.start_time = k_uptime_get();
	BP_GS()->bp.notification_day[idx].count++;
	BP_GS()->bp.notification_count++;

	G1_LOG_WRN("[enter_notification_burial_point] start_time is %d\n",
		   BP_GS()->notification.start_time);
}

void exit_notification_burial_point(void)
{
	int64_t t;

	if (BP_GS()->notification.active && FUN_00081216() < 7) {
		BP_GS()->notification.active = 0;
		t = get_notification_sum_time();
		add_notification_burial_time(t);
		G1_LOG_WRN("[exit_notification_burial_point] sum_time is %d ms,notification_sum_time is %d s\n",
			   t, BP_GS()->bp.notification_sum_time);
	}
}

void burial_point_record_info_init(void)
{
	G1_LOG_INF("burial_point_record_info_init\n");

	memset(&BP_GS()->dashboard, 0, sizeof(struct bp_session));
	memset(&BP_GS()->wear, 0, sizeof(struct bp_session));
	memset(&BP_GS()->notification, 0, sizeof(struct bp_session));
}

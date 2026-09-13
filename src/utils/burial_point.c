/*
 * "Burial point" (usage statistics): per-day wear / dashboard / notification
 * counters and durations in a 7-day ring, kept in GlassesState + 0x1128.
 * Reconstructed from the v1.63 app core.
 */
#include <stdint.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "burial_point.h"
#include "../dashboard/dashboard.h"
#include "../production_test/production_test.h"

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

	if (get_dashboard_state()->bp.day_index > 6) {
		get_dashboard_state()->bp.day_index = 0;
	}

	if (get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].year == date.year &&
	    get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].month == date.month &&
	    get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].day == date.day) {
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
		if (get_dashboard_state()->bp.day_index != i && get_dashboard_state()->bp.wear_day[i].year == date.year &&
		    get_dashboard_state()->bp.wear_day[i].month == date.month &&
		    get_dashboard_state()->bp.wear_day[i].day == date.day) {
			get_dashboard_state()->bp.day_index = i;
			break;
		}
	}
	if (i == 7) {
		get_dashboard_state()->bp.day_index++;
		if (get_dashboard_state()->bp.day_index > 6) {
			get_dashboard_state()->bp.day_index = 0;
		}
	}

	get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].year = date.year;
	get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].month = date.month;
	get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].day = date.day;
	get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].sum_time = 0;
	get_dashboard_state()->bp.wear_day[get_dashboard_state()->bp.day_index].count = 0;
	get_dashboard_state()->bp.dashboard_day[get_dashboard_state()->bp.day_index].year = date.year;
	get_dashboard_state()->bp.dashboard_day[get_dashboard_state()->bp.day_index].month = date.month;
	get_dashboard_state()->bp.dashboard_day[get_dashboard_state()->bp.day_index].day = date.day;
	get_dashboard_state()->bp.dashboard_day[get_dashboard_state()->bp.day_index].sum_time = 0;
	get_dashboard_state()->bp.dashboard_day[get_dashboard_state()->bp.day_index].count = 0;
	get_dashboard_state()->bp.notification_day[get_dashboard_state()->bp.day_index].year = date.year;
	get_dashboard_state()->bp.notification_day[get_dashboard_state()->bp.day_index].month = date.month;
	get_dashboard_state()->bp.notification_day[get_dashboard_state()->bp.day_index].day = date.day;
	get_dashboard_state()->bp.notification_day[get_dashboard_state()->bp.day_index].sum_time = 0;
	get_dashboard_state()->bp.notification_day[get_dashboard_state()->bp.day_index].count = 0;

	return 0;
}

/* index of today's slot, 7 if the date is not known */
uint8_t get_burial_point_day_index(void)
{
	if (update_burial_point_day_index() != 0) {
		return 7;
	}

	return get_dashboard_state()->bp.day_index;
}

void exit_wear_burial_point(void)
{
	if (get_dashboard_state()->bp_wear.active && get_burial_point_day_index() < 7) {
		get_dashboard_state()->bp_wear.active = 0;
	}
}

void add_wear_burial_time(int64_t ms)
{
	uint8_t idx = get_burial_point_day_index();

	if (idx < 7) {
		get_dashboard_state()->bp.wear_day[idx].sum_time += ms / 1000;
		get_dashboard_state()->bp.wear_sum_time += ms / 1000;
	}
}

void enter_wear_burial_point(void)
{
	uint8_t idx;

	if (get_pt_test_mode() == 1 || get_dashboard_state()->bp_wear.active == 1) {
		return;
	}

	idx = get_burial_point_day_index();
	if (idx >= 7) {
		return;
	}

	get_dashboard_state()->bp_wear.active = 1;
	get_dashboard_state()->bp_wear.day_index = idx;
	get_dashboard_state()->bp_wear.start_time = k_uptime_get();
	get_dashboard_state()->bp.wear_day[idx].count++;
	get_dashboard_state()->bp.wear_count++;

	G1_LOG_WRN("[enter_wear_burial_point] start_time is %d\n", get_dashboard_state()->bp_wear.start_time);
}

int64_t get_dashboard_sum_time(void)
{
	int64_t t;

	if (k_uptime_get() > get_dashboard_state()->bp_dashboard.start_time) {
		t = k_uptime_get() - get_dashboard_state()->bp_dashboard.start_time;
	} else {
		t = get_dashboard_state()->bp_dashboard.start_time - k_uptime_get();
	}

	G1_LOG_WRN("get_dashboard_sum_time is %d\n", t);

	return t;
}

void add_dashboard_burial_time(int64_t ms)
{
	uint8_t idx = get_burial_point_day_index();

	if (idx < 7) {
		get_dashboard_state()->bp.dashboard_day[idx].sum_time += ms / 1000;
		get_dashboard_state()->bp.dashboard_sum_time += ms / 1000;
	}
}

void enter_dashboard_burial_point(void)
{
	uint8_t idx;

	if (get_pt_test_mode() == 1 || get_dashboard_state()->bp_dashboard.active == 1) {
		return;
	}

	idx = get_burial_point_day_index();
	if (idx >= 7) {
		return;
	}

	get_dashboard_state()->bp_dashboard.active = 1;
	get_dashboard_state()->bp_dashboard.day_index = idx;
	get_dashboard_state()->bp_dashboard.start_time = k_uptime_get();
	get_dashboard_state()->bp.dashboard_day[idx].count++;
	get_dashboard_state()->bp.dashboard_count++;

	G1_LOG_WRN("[enter_dashboard_burial_point] start_time is %d\n",
		   get_dashboard_state()->bp_dashboard.start_time);
}

void exit_dashboard_burial_point(void)
{
	int64_t t;

	if (get_dashboard_state()->bp_dashboard.active && get_burial_point_day_index() < 7) {
		get_dashboard_state()->bp_dashboard.active = 0;
		t = get_dashboard_sum_time();
		add_dashboard_burial_time(t);
		G1_LOG_WRN("[exit_dashboard_burial_point] sum_time is %d ms,dashboard_sum_time is %d s\n",
			   t, get_dashboard_state()->bp.dashboard_sum_time);
	}
}

int64_t get_notification_sum_time(void)
{
	int64_t t;

	if (k_uptime_get() > get_dashboard_state()->bp_notification.start_time) {
		t = k_uptime_get() - get_dashboard_state()->bp_notification.start_time;
	} else {
		t = get_dashboard_state()->bp_notification.start_time - k_uptime_get();
	}

	G1_LOG_WRN("get_notification_sum_time is %d\n", t);

	return t;
}

void add_notification_burial_time(int64_t ms)
{
	uint8_t idx = get_burial_point_day_index();

	if (idx < 7) {
		get_dashboard_state()->bp.notification_day[idx].sum_time += ms / 1000;
		get_dashboard_state()->bp.notification_sum_time += ms / 1000;
	}
}

void enter_notification_burial_point(void)
{
	uint8_t idx;

	if (get_pt_test_mode() == 1 || get_dashboard_state()->bp_notification.active == 1) {
		return;
	}

	idx = get_burial_point_day_index();
	if (idx >= 7) {
		return;
	}

	get_dashboard_state()->bp_notification.active = 1;
	get_dashboard_state()->bp_notification.day_index = idx;
	get_dashboard_state()->bp_notification.start_time = k_uptime_get();
	get_dashboard_state()->bp.notification_day[idx].count++;
	get_dashboard_state()->bp.notification_count++;

	G1_LOG_WRN("[enter_notification_burial_point] start_time is %d\n",
		   get_dashboard_state()->bp_notification.start_time);
}

void exit_notification_burial_point(void)
{
	int64_t t;

	if (get_dashboard_state()->bp_notification.active && get_burial_point_day_index() < 7) {
		get_dashboard_state()->bp_notification.active = 0;
		t = get_notification_sum_time();
		add_notification_burial_time(t);
		G1_LOG_WRN("[exit_notification_burial_point] sum_time is %d ms,notification_sum_time is %d s\n",
			   t, get_dashboard_state()->bp.notification_sum_time);
	}
}

void burial_point_record_info_init(void)
{
	G1_LOG_INF("burial_point_record_info_init\n");

	memset(&get_dashboard_state()->bp_dashboard, 0, sizeof(struct bp_session));
	memset(&get_dashboard_state()->bp_wear, 0, sizeof(struct bp_session));
	memset(&get_dashboard_state()->bp_notification, 0, sizeof(struct bp_session));
}

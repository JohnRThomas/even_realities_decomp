/*
 * Template gyro page of the page dispatcher (ui_task_table in
 * ui_notification.c): screen id 13, YPR read-out.  A separate file in the
 * vendor build: the table takes their address in ui_notification.c, yet they
 * are emitted after the notification page in the target, and the target
 * .rodata has this file's strings followed by its own __func__ object
 * ("dump_template_gyro_info") before the countdown page's strings
 * (ui_countdown.c).  align-4 0x379bc..0x37af3.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

void dump_template_gyro_info(void *arg)
{
	struct GlassesState *state = get_dashboard_state();
	float *ypr = (float *)&state->ui.ypr;
	double yaw = ypr[0];
	double pitch = ypr[1];
	double roll = ypr[2];

	G1_LOG_INF("screen_id: %d, ypr: %.2f, %.2f, %.2f\n", ((uint8_t *)arg)[1], yaw, pitch,
		   roll);
}

int draw_template_gyro_page(struct jbd_panel_context *panel, void *arg)
{
	uint8_t **fb = panel->panel_buffer;
	uint16_t count;
	char buf[10] = {0};
	uint16_t *codes;
	struct GlassesState *state;
	float ypr[3];
	int n;
	int y;

	codes = FUN_0004b160("陀螺仪姿态解算:YPR", &count);
	for (int i = 0; i < count; i++) {
		FUN_00080bc0(fb, find_chinese_bitmap_by_unicode(codes[i], 12, 36), 12, 36,
			     i * 12 + 6, 0);
	}
	state = get_dashboard_state();
	memcpy(ypr, &state->ui.ypr, sizeof(ypr));
	float *p = ypr;

	y = 0;
	do {
		n = FUN_0004d328(*p++, buf);
		y += 30;
		for (int i = 0; i < n; i++) {
			FUN_00080bc0(fb, find_chinese_bitmap_by_unicode(buf[i], 12, 36), 12, 36,
				     i * 12 + 6, y);
		}
	} while (y != 90);
	return 0;
}

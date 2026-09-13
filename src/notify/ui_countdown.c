/*
 * Template countdown timer page of the page dispatcher (ui_task_table in
 * ui_notification.c, screen id 2) and its helpers.  Split from
 * ui_template.c at the .rodata TU boundary (see there).
 * align-4 0x37af4..0x37daf, align-2 0x806c2..0x806d5.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

/* countdown of the template timer page */
struct ui_countdown {
	uint32_t seconds;
	uint8_t f_4;
	uint8_t f_5;
	uint8_t reset;
} __packed;

static uint32_t countdown_last_ms;

void countdown_tick(void *unused, struct ui_countdown *cd)
{
	uint32_t now;

	if (cd->reset == 1) {
		countdown_last_ms = 0;
		cd->reset = 0;
	}
	now = k_uptime_get_32();
	if (countdown_last_ms == 0) {
		countdown_last_ms = now;
		return;
	}
	if (now - countdown_last_ms >= 1000) {
		uint32_t *sec = &cd->seconds;

		*sec = *sec - (now - countdown_last_ms) / 1000;
		countdown_last_ms = now;
	}
}

int draw_template_countdown_page(struct jbd_panel_context *panel, void *arg)
{
	uint8_t **fb = panel->panel_buffer;
	struct GlassesState *state = get_dashboard_state();
	struct ui_timer_payload *timer = &state->ui.timer;
	uint32_t hours = timer->seconds / 3600 % 24;
	uint32_t remain = timer->seconds % 3600;
	uint32_t secs = remain % 60;
	bool done = false;
	uint16_t count = 0;
	uint16_t *codes;
	uint32_t mins;
	int x;

	if (remain < 60) {
		done = (hours | secs) == 0;
	}
	FUN_00080bc0(fb, FUN_0004b2d4(done ? 4 : 9, 288), 12, 24, 12, 12);
	if (done) {
		codes = FUN_0004b160("时间到!", &count);
		for (int i = 0; i < count; i++) {
			FUN_00080bc0(fb, find_chinese_bitmap_by_unicode(codes[i], 12, 36), 12, 36,
				     i * 12 + 32, 8);
		}
	} else {
		x = 12;
		if (hours) {
			FUN_00080bc0(fb, FUN_00080fa2(hours / 10, 15, 36, 0), 15, 36, 32, 12);
			FUN_00080bc0(fb, FUN_00080fa2(hours % 10, 15, 36, 0), 15, 36, 47, 12);
			FUN_00080bc0(fb, FUN_00080fa2(10, 15, 36, 0), 15, 36, 62, 12);
			x = 57;
		}
		mins = remain / 60;
		FUN_00080bc0(fb, FUN_00080fa2(mins / 10, 15, 36, 0), 15, 36, x + 20, 12);
		FUN_00080bc0(fb, FUN_00080fa2(mins % 10, 15, 36, 0), 15, 36, x + 35, 12);
		FUN_00080bc0(fb, FUN_00080fa2(10, 15, 36, 0), 15, 36, x + 50, 12);
		FUN_00080bc0(fb, FUN_00080fa2(secs / 10, 15, 36, 0), 15, 36, x + 65, 12);
		FUN_00080bc0(fb, FUN_00080fa2(secs % 10, 15, 36, 0), 15, 36, x + 80, 12);
	}
	if (timer->state >= 2) {
		FUN_00080bc0(fb, FUN_0004b2d4(12, 288), 12, 24, 226, 20);
		codes = FUN_0004b160("结束中..", &count);
		x = 244;
		for (int i = 0; i < count; i++) {
			FUN_00080bc0(fb, find_chinese_bitmap_by_unicode(codes[i], 12, 32), 12, 32, x, 8);
			x += 12;
		}
	} else {
		FUN_00080800(fb, arg, 0, 0, 0);
	}
	return 0;
}

int draw_template_notification_page(struct jbd_panel_context *panel, void *arg)
{
	return 0;
}

void countdown_reset(struct ui_countdown *cd)
{
	cd->seconds = 60;
	cd->f_4 = 0;
}

/* Old placeholder names, still used by other modules (renamed 2026-10-21, byte-neutral). */
extern __typeof__(countdown_tick) FUN_00037af4 __attribute__((alias("countdown_tick")));
extern __typeof__(countdown_reset) FUN_000806c6 __attribute__((alias("countdown_reset")));

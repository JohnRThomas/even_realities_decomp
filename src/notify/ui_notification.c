/*
 * Notification UI: the "new notification" page (message, time since
 * received, unread counter), the page dispatcher table and two
 * template/test pages.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

#define LANGUAGE_FRENCH  5
#define LANGUAGE_GERMAN  6
#define LANGUAGE_SPANISH 7
#define LANGUAGE_ITALIAN 14

#define SECONDS_PER_MIN  60
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_DAY  86400

typedef int (*ui_task_fn)(struct jbd_panel_context *panel, void *arg);
typedef void (*ui_pre_fn)(void *arg);

struct ui_task {
	uint32_t id;
	uint32_t has_pre;
	ui_task_fn task;
	ui_pre_fn pre;
};

/* countdown of the template timer page */
struct ui_countdown {
	uint32_t seconds;
	uint8_t f_4;
	uint8_t f_5;
	uint8_t reset;
} __packed;

int draw_template_gyro_page(struct jbd_panel_context *panel, void *arg);
void dump_template_gyro_info(void *arg);
int draw_template_countdown_page(struct jbd_panel_context *panel, void *arg);
int FUN_0008074e(struct jbd_panel_context *panel, void *arg);
int FUN_00080752(struct jbd_panel_context *panel, void *arg);
int FUN_00080802(struct jbd_panel_context *panel, void *arg);
int FUN_000808b0(struct jbd_panel_context *panel, void *arg);
int FUN_000808d8(struct jbd_panel_context *panel, void *arg);
int draw_template_translate_screen(struct jbd_panel_context *panel, void *arg);
int draw_template_notification_page(struct jbd_panel_context *panel, void *arg);
int draw_template_new_message_page(struct jbd_panel_context *panel, void *arg);

static int last_uid = -1;
struct ui_task ui_task_table[] = {
	{13, 0, draw_template_gyro_page, (ui_pre_fn)dump_template_gyro_info},
	{2, 0, draw_template_countdown_page, NULL},
	{3, 0, FUN_0008074e, NULL},
	{4, 0, draw_template_notification_page, NULL},
	{5, 0, draw_template_new_message_page, NULL},
	{6, 0, FUN_0008074e, NULL},
	{7, 0, FUN_00080802, NULL},
	{8, 0, FUN_00080752, NULL},
	{9, 0, FUN_000808b0, NULL},
	{10, 0, FUN_000808d8, NULL},
	{11, 0, draw_template_translate_screen, NULL},
};

static uint8_t last_idx = 0xff;
static uint8_t last_num = 0xff;


static uint8_t hide_icon_on_exit;
static uint8_t particle_pending;

int panel_related(struct jbd_panel_context *panel, int idx, void *arg)
{
	struct ui_task *t;

	if (!panel->panel_on) {
		return -1;
	}
	panel->current_row = 0;
	panel->current_column = 176;
	if (idx != 7) {
		panel->clear_cb();
	}
	if (idx == 7 || (unsigned int)(idx - 1) < 20) {
		t = ui_task_table + idx - 1;
		if (t->has_pre && t->pre) {
			t->pre(arg);
		}
		t->task(panel, arg);
	}
	if (panel->init_done) {
		panel->draw_cb(panel);
	}
	return 0;
}

void draw_time(char *buf, uint32_t recv_time)
{
	uint8_t **fb = get_dashboard_state()->panel.panel_buffer;
	uint32_t now = FUN_00080732();
	uint32_t diff = now - recv_time;
	uint32_t elapsed;
	uint8_t lang;

	memset(buf, 0, 32);
	elapsed = (int)diff < 0 ? 0 : diff;
	BLE_PRINTK("currentTime is %d,recvTime is %d,unReadTime is %d \n", now, recv_time, elapsed);
	lang = get_current_language();
	if (lang == LANGUAGE_GERMAN) {
		struct bp_date date;

		if ((int)diff < 0 || diff < SECONDS_PER_MIN) {
			sprintf(buf, "Jetzt");
		} else if (elapsed >= SECONDS_PER_MIN && elapsed < SECONDS_PER_HOUR) {
			sprintf(buf, "Vor %d Min.", elapsed / SECONDS_PER_MIN);
		} else if (elapsed >= SECONDS_PER_HOUR && elapsed < 3 * SECONDS_PER_HOUR) {
			sprintf(buf, "Vor %d Std.", elapsed / SECONDS_PER_HOUR);
		} else if (elapsed >= 3 * SECONDS_PER_HOUR && elapsed < SECONDS_PER_DAY) {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d:%02d", date.hour, date.minute);
		} else if (elapsed >= SECONDS_PER_DAY && elapsed < 2 * SECONDS_PER_DAY) {
			sprintf(buf, "Gestern");
		} else if (elapsed >= 2 * SECONDS_PER_DAY && elapsed < 7 * SECONDS_PER_DAY) {
			strcpy(buf, FUN_0004d2cc(recv_time));
		} else {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d/%02d", date.day, date.month);
		}
	} else if (lang == LANGUAGE_FRENCH) {
		struct bp_date date;

		if ((int)diff < 0 || diff < SECONDS_PER_MIN) {
			sprintf(buf, "Maintenant");
		} else if (elapsed >= SECONDS_PER_MIN && elapsed < SECONDS_PER_HOUR) {
			sprintf(buf, "%d min", elapsed / SECONDS_PER_MIN);
		} else if (elapsed >= SECONDS_PER_HOUR && elapsed < 3 * SECONDS_PER_HOUR) {
			sprintf(buf, "%d h", elapsed / SECONDS_PER_HOUR);
		} else if (elapsed >= 3 * SECONDS_PER_HOUR && elapsed < SECONDS_PER_DAY) {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			BLE_PRINTK("date: %u: %04d/%02d/%02d-%02d:%02d:%02d", recv_time, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			BLE_PRINTK("time_disp_mode is %d \n",
				   get_dashboard_state()->dashboard_ts->time_disp_mode);
			if (!get_dashboard_state()->dashboard_ts->time_disp_mode) {
				sprintf(buf, "%02d:%02d", date.hour, date.minute);
			} else {
				if (date.hour > 12) {
					date.hour -= 12;
					sprintf(buf, "%02d:%02dpm", date.hour, date.minute);
				} else if (date.hour == 0) {
					date.hour = 12;
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				} else {
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				}
			}
		} else if (elapsed >= SECONDS_PER_DAY && elapsed < 2 * SECONDS_PER_DAY) {
			sprintf(buf, "Hier");
		} else if (elapsed >= 2 * SECONDS_PER_DAY && elapsed < 7 * SECONDS_PER_DAY) {
			strcpy(buf, FUN_0004d2cc(recv_time));
		} else {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d/%02d", date.month, date.day);
		}
	} else if (lang == LANGUAGE_SPANISH) {
		struct bp_date date;

		if ((int)diff < 0 || diff < SECONDS_PER_MIN) {
			sprintf(buf, "Ahora");
		} else if (elapsed >= SECONDS_PER_MIN && elapsed < SECONDS_PER_HOUR) {
			sprintf(buf, "hace %d'", elapsed / SECONDS_PER_MIN);
		} else if (elapsed >= SECONDS_PER_HOUR && elapsed < 3 * SECONDS_PER_HOUR) {
			sprintf(buf, "hace %d h", elapsed / SECONDS_PER_HOUR);
		} else if (elapsed >= 3 * SECONDS_PER_HOUR && elapsed < SECONDS_PER_DAY) {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			BLE_PRINTK("date: %u: %04d/%02d/%02d-%02d:%02d:%02d", recv_time, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			BLE_PRINTK("time_disp_mode is %d \n",
				   get_dashboard_state()->dashboard_ts->time_disp_mode);
			if (!get_dashboard_state()->dashboard_ts->time_disp_mode) {
				sprintf(buf, "%02d:%02d", date.hour, date.minute);
			} else {
				if (date.hour > 12) {
					date.hour -= 12;
					sprintf(buf, "%02d:%02dpm", date.hour, date.minute);
				} else if (date.hour == 0) {
					date.hour = 12;
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				} else {
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				}
			}
		} else if (elapsed >= SECONDS_PER_DAY && elapsed < 2 * SECONDS_PER_DAY) {
			sprintf(buf, "Ayer");
		} else if (elapsed >= 2 * SECONDS_PER_DAY && elapsed < 7 * SECONDS_PER_DAY) {
			strcpy(buf, FUN_0004d2cc(recv_time));
		} else {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d/%02d", date.month, date.day);
		}
	} else if (lang == LANGUAGE_ITALIAN) {
		struct bp_date date;

		if ((int)diff < 0 || diff < SECONDS_PER_MIN) {
			sprintf(buf, "Adesso");
		} else if (elapsed >= SECONDS_PER_MIN && elapsed < SECONDS_PER_HOUR) {
			sprintf(buf, "%d min fa", elapsed / SECONDS_PER_MIN);
		} else if (elapsed >= SECONDS_PER_HOUR && elapsed < 3 * SECONDS_PER_HOUR) {
			sprintf(buf, "%d ore fa", elapsed / SECONDS_PER_HOUR);
		} else if (elapsed >= 3 * SECONDS_PER_HOUR && elapsed < SECONDS_PER_DAY) {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			BLE_PRINTK("date: %u: %04d/%02d/%02d-%02d:%02d:%02d", recv_time, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			BLE_PRINTK("time_disp_mode is %d \n",
				   get_dashboard_state()->dashboard_ts->time_disp_mode);
			if (!get_dashboard_state()->dashboard_ts->time_disp_mode) {
				sprintf(buf, "%02d:%02d", date.hour, date.minute);
			} else {
				if (date.hour > 12) {
					date.hour -= 12;
					sprintf(buf, "%02d:%02dpm", date.hour, date.minute);
				} else if (date.hour == 0) {
					date.hour = 12;
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				} else {
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				}
			}
		} else if (elapsed >= SECONDS_PER_DAY && elapsed < 2 * SECONDS_PER_DAY) {
			sprintf(buf, "Ieri");
		} else if (elapsed >= 2 * SECONDS_PER_DAY && elapsed < 7 * SECONDS_PER_DAY) {
			strcpy(buf, FUN_0004d2cc(recv_time));
		} else {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d/%02d", date.month, date.day);
		}
	} else {
		struct bp_date date;

		if ((int)diff < 0 || diff < SECONDS_PER_MIN) {
			sprintf(buf, "Now");
		} else if (elapsed >= SECONDS_PER_MIN && elapsed < SECONDS_PER_HOUR) {
			sprintf(buf, "%dm ago", elapsed / SECONDS_PER_MIN);
		} else if (elapsed >= SECONDS_PER_HOUR && elapsed < 3 * SECONDS_PER_HOUR) {
			sprintf(buf, "%dh ago", elapsed / SECONDS_PER_HOUR);
		} else if (elapsed >= 3 * SECONDS_PER_HOUR && elapsed < SECONDS_PER_DAY) {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			BLE_PRINTK("date: %u: %04d/%02d/%02d-%02d:%02d:%02d", recv_time, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			BLE_PRINTK("time_disp_mode is %d \n",
				   get_dashboard_state()->dashboard_ts->time_disp_mode);
			if (!get_dashboard_state()->dashboard_ts->time_disp_mode) {
				sprintf(buf, "%02d:%02d", date.hour, date.minute);
			} else {
				if (date.hour > 12) {
					date.hour -= 12;
					sprintf(buf, "%02d:%02dpm", date.hour, date.minute);
				} else if (date.hour == 0) {
					date.hour = 12;
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				} else {
					sprintf(buf, "%02d:%02dam", date.hour, date.minute);
				}
			}
		} else if (elapsed >= SECONDS_PER_DAY && elapsed < 2 * SECONDS_PER_DAY) {
			sprintf(buf, "Yesterday");
		} else if (elapsed >= 2 * SECONDS_PER_DAY && elapsed < 7 * SECONDS_PER_DAY) {
			strcpy(buf, FUN_0004d2cc(recv_time));
		} else {
			memset(&date, 0, sizeof(date));
			init_burial_point_date(recv_time, &date);
			sprintf(buf, "%02d/%02d", date.month, date.day);
		}
	}
	_clean_fb_data(fb, 0, FUN_000809e2() + 406, FUN_00080a3a(),
		       FUN_000809e2() + 512, FUN_00080a3a() + 27);
	gui_utf_draw_align_right(0, buf, 0, FUN_000809e2() + 406, FUN_00080a3a(),
				 FUN_000809e2() + 512, FUN_00080a3a() + 27, 1, 0, 0, NULL, 0);
	BLE_PRINTK("gui_getScreenoffset_x=%d,timeDiffBuf is %s \n", FUN_000809e2(), buf);
}

#line 394
void draw_message(uint8_t unread, struct notif_msg *msg)
{
	char title[72] = {0};
	char time_str[32] = {0};
	char count[8] = {0};
	char body[291] = {0};
	uint8_t type;

	if (msg == NULL) {
		BLE_PRINTK("[%s-%d]curMsg is NULL !\n", __func__, __LINE__);
		return;
	}
	type = parse_message_type(get_cur_show_msg_idx());
	BLE_PRINTK("show msgType is %d unReadCount %d\n", type, unread);
	switch (type) {
	case 2:
		memset(title, 0, sizeof(title));
		snprintf(title, sizeof(title), "%s", msg->message);
		gui_utf_draw_middle(0, title, 0, FUN_000809e2(), FUN_00080a3a() + 54,
				    FUN_000809e2() + 576, FUN_00080a3a() + 81, 1, 0, 0, NULL, 0);
		gui_bmp_bitmap_draw(0x36, FUN_000809e2(), FUN_00080a3a() + 58, 0, 0, 0);
		memset(body, 0, sizeof(body));
		snprintf(body, sizeof(body), "%s", msg->title);
		if (body[0] == 0) {
			return;
		}
		gui_utf_draw_middle(0, body, 0, FUN_000809e2(), FUN_00080a3a() + 81,
				    FUN_000809e2() + 576, FUN_00080a3a() + 81, 1, 0, 0, NULL, 0);
		return;
	case 1:
		gui_bmp_bitmap_draw(0x37, FUN_000809e2(), FUN_00080a3a() + 4, 0, 0, 0);
		memset(title, 0, sizeof(title));
		snprintf(title, sizeof(title), "%s", msg->message);
		break;
	case 3:
		gui_bmp_bitmap_draw(0x3a, FUN_000809e2(), FUN_00080a3a() + 4, 0, 0, 0);
		memset(title, 0, sizeof(title));
		snprintf(title, sizeof(title), "%s | %s", msg->display_name, msg->subtitle);
		break;
	case 4:
		gui_bmp_bitmap_draw(0x39, FUN_000809e2(), FUN_00080a3a() + 4, 0, 0, 0);
		memset(title, 0, sizeof(title));
		snprintf(title, sizeof(title), "%s", msg->display_name);
		break;
	case 0:
		gui_bmp_bitmap_draw(0x38, FUN_000809e2(), FUN_00080a3a() + 4, 0, 0, 0);
		memset(title, 0, sizeof(title));
		snprintf(title, sizeof(title), "%s", msg->display_name);
		break;
	default:
		gui_bmp_bitmap_draw(0x38, FUN_000809e2(), FUN_00080a3a() + 4, 0, 0, 0);
		memset(title, 0, sizeof(title));
		if (msg->subtitle[0]) {
			snprintf(title, sizeof(title), "%s | %s", msg->display_name, msg->subtitle);
		} else {
			snprintf(title, sizeof(title), "%s", msg->display_name);
		}
		break;
	}
	gui_utf_draw_truncate(0, title, 0, FUN_000809e2() + 36, FUN_00080a3a(),
			      FUN_000809e2() + 390, FUN_00080a3a() + 27, 1, 0, 0, NULL, 0);
	BLE_PRINTK("recvTime is %u,curMsg->message %s\n", msg->recv_time, msg->message);
	draw_time(time_str, msg->recv_time);
	gui_bmp_bitmap_draw(0x3c, FUN_000809e2() + 528, FUN_00080a3a(), 0, 0, 0);
	memset(count, 0, sizeof(count));
	sprintf(count, "%u", unread);
	gui_utf_draw(0, count, 0, FUN_000809e2() + 556, FUN_00080a3a(), FUN_000809e2() + 580,
		     FUN_00080a3a() + 27, 1, 0, 0, NULL, 0);
	memset(body, 0, sizeof(body));
	if (type == 1) {
		snprintf(body, sizeof(body), "%s", msg->title);
		if (body[0] == 0) {
			return;
		}
		gui_utf_Wordwrap_draw(0, body, 0, FUN_000809e2(), FUN_00080a3a() + 54,
				      FUN_000809e2() + 576, FUN_00080a3a() + 135, 3, 0, 0, NULL, 0);
	} else if (type == 4) {
		snprintf(body, sizeof(body), "%s\n%s", msg->title, msg->message);
		if (body[0] == 0) {
			return;
		}
		gui_utf_Wordwrap_draw(0, body, 0, FUN_000809e2(), FUN_00080a3a() + 54,
				      FUN_000809e2() + 576, FUN_00080a3a() + 135, 3, 0, 0, NULL, 0);
	} else {
		if (msg->title[0] == 0) {
			snprintf(body, sizeof(body), "%s", msg->message);
		} else {
			snprintf(body, sizeof(body), "%s - %s", msg->title, msg->message);
		}
		if (body[0] == 0) {
			return;
		}
		gui_utf_Wordwrap_draw(0, body, 0, FUN_000809e2(), FUN_00080a3a() + 54,
				      FUN_000809e2() + 576, FUN_00080a3a() + 135, 3, 0, 0, NULL, 0);
	}
}

#line 519
void draw_particle_effects(uint8_t **fb, uint8_t unread, struct notif_msg *msg)
{
	if (msg == NULL) {
		BLE_PRINTK("[%s-%d]curMsg is NULL !\n", __func__, __LINE__);
		return;
	}

	if (fb == NULL) {
		BLE_PRINTK("[%s-%d]fb is NULL !\n", __func__, __LINE__);
		return;
	}
	clear_showing_notification_on_gui();
	for (int step = 0; step < 8; step++) {
		draw_message(unread, msg);
		for (int y = 0; y < 199; y++) {
			for (int x = 0; x < 320; x++) {
				uint8_t level[8] = {1, 3, 5, 7, 7, 7, 7, 7};

				if (fb[y][x]) {
					fb[y][x] &= gui_fade_mask[y % 26][level[step]][x];
				}
			}
		}
		k_sleep(K_MSEC(5));
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column, 0, 0, 640, 199);
	}
	set_showing_notification_on_gui();
}

void set_hide_icon_on_exit(void)
{
	hide_icon_on_exit = 1;
}

void set_particle_pending(void)
{
	particle_pending = 1;
}

int ui_ancs_notificaton_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct notif_msg *msg = NULL;
	uint8_t idx;
	uint8_t num;

	if (event == 2) {
		BLE_PRINTK("ui_ancs_notificaton_task exit !");
		last_idx = 0xff;
		last_num = 0xff;
		last_uid = -1;
		if (hide_icon_on_exit) {
			hide_icon_notification_on_gui();
			hide_icon_on_exit = 0;
		} else {
			gui_screen_clear();
		}
		msg_busy = 0;
		exit_notification_burial_point();
		return 0;
	}
	if (event == 0) {
		return 0;
	}
	idx = get_cur_show_msg_idx();
	num = count_unread_messages();
	/* note: msg is still NULL here (vendor bug) */
	if (last_idx == idx && last_num == num && msg->uid == last_uid) {
		return 0;
	}
	if (pull_message(&msg) >= MSG_NORMAL_NUM) {
		BLE_PRINTK("pull message error !\r\n");
		last_idx = 0xff;
		last_num = 0xff;
		last_uid = -1;
		return 0;
	}
	if (!msg->read) {
		last_idx = 0xff;
		last_num = 0xff;
		last_uid = -1;
		BLE_PRINTK("message has not set to show!\r\n");
		return 0;
	}
	if (msg->f_0e == 0) {
		last_idx = 0xff;
		last_num = 0xff;
		last_uid = -1;
		BLE_PRINTK("message has not confirm!\r\n");
		return 0;
	}
	uint8_t **fb = panel->panel_buffer;

	if (last_idx == 0xff) {
		set_frame_buffer(fb);
		set_showing_notification_on_gui();
		gui_screen_clear();
		enter_notification_burial_point();
	}
	if (particle_pending) {
		draw_particle_effects(fb, num, msg);
		particle_pending = 0;
	}
	draw_message(num, msg);
	last_idx = idx;
	last_num = num;
	last_uid = msg->uid;
	msg_busy = 0;
	return 0;
}

/* Old placeholder names, still used by other modules (renamed 2026-10-21, byte-neutral). */
extern __typeof__(set_hide_icon_on_exit) FUN_00037824 __attribute__((alias("set_hide_icon_on_exit")));
extern __typeof__(set_particle_pending) FUN_00037830 __attribute__((alias("set_particle_pending")));

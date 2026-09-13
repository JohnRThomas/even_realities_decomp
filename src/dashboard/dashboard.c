/*
 * Dashboard UI file: "new message" page, dashboard info init (quick notes),
 * the notes/stocks/news/calendar page index helpers (0x384c4..),
 * the dashboard renderer DashBoard_Reflash (0x38dc4..) and the dashboard
 * screen task ui_DashBoard_task with its app sync helpers (0x3cc54..).
 *
 * One translation unit in the shipped image: they share _dashboard_prv_data
 * (_dashboard_prv_data) and the out-of-line atomic_get() copy at 0x806de.
 * (Merged from notify/dashboard_info.c, dashboard/dashboard_reflash.c and
 * ui/ui_dashboard_task.c.)
 */
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/printk.h>
#include "dashboard.h"

#define QUICKNOTE_NUM        4
#define QUICKNOTE_TITLE_LEN  0x29
#define QUICKNOTE_TEXT_LEN   0x119

uint8_t notes_index;
uint8_t stocks_index;
uint8_t news_index;
uint8_t calendar_index;

static uint8_t new_msg_drawn;
static uint8_t new_msg_entered;

int ui_new_message_come_on_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct GlassesState *state = get_dashboard_state();
	uint8_t type;

	if (FUN_00035a78() == 4) {
		return 0;
	}
	if (event == 2) {
		BLE_PRINTK("ui_new_message_come_on_task exit !");
		gui_screen_clear();
		new_msg_drawn = 0;
		new_msg_entered = 0;
		return 0;
	}
	if (event == 0) {
		return 0;
	}
	if (new_msg_drawn == 0) {
		new_msg_drawn = 1;
		set_frame_buffer(panel->panel_buffer);
		set_showing_notification_on_gui();
		gui_screen_clear();
		new_msg_entered = 0;
	}
	if (state->db_info.new_msg_count < 2) {
		new_msg_entered = 0;
		gui_screen_clear();
		return 0;
	}
	type = parse_message_type((uint8_t)(get_dashboard_state()->unread_msg_num - 1));
	BLE_PRINTK("new msgType is %d \n", type);
	if (new_msg_entered) {
		return 0;
	}
	clear_showing_notification_on_gui();
	for (int step = 0; step < 8; step++) {
		switch (type) {
		case 1:
			gui_bmp_bitmap_draw(0x37, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0);
			break;
		case 2:
			gui_bmp_bitmap_draw(0x36, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0);
			break;
		case 3:
			gui_bmp_bitmap_draw(0x3a, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0);
			break;
		case 4:
			gui_bmp_bitmap_draw(0x39, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0);
			break;
		default:
			gui_bmp_bitmap_draw(0x38, gui_screen_x_offset(), gui_screen_y_offset() + 58, 0, 0, 0);
			break;
		}
		for (int y = 0; y < 199; y++) {
			for (int x = 0; x < 320; x++) {
				uint8_t level[8] = {1, 2, 3, 4, 5, 6, 7, 7};

				if (panel->panel_buffer[y][x]) {
					panel->panel_buffer[y][x] &= gui_fade_mask[y % 26][level[step]][x];
				}
			}
		}
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column, 0, 0, 640, 199);
	}
	set_showing_notification_on_gui();
	new_msg_entered = 1;
	return 0;
}

void dashboard_draw_add_note_hint(void)
{
	uint8_t flag = FUN_00028d2c();
	uint8_t lang = get_current_language();
	const char *str;

	if (flag == 1) {
		if (_dashboard_prv_data.language != lang) {
			_dashboard_prv_data.language = lang;
			_clean_fb_data(get_dashboard_state()->panel.panel_buffer, 0, gui_screen_x_offset() + 266,
			       gui_screen_y_offset() + 28, gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column,
					gui_screen_x_offset() + 266, gui_screen_y_offset() + 28,
					gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
		}
		str = get_string(0x53);
		gui_utf_draw_middle(0, str, 0, gui_screen_x_offset() + 266, gui_screen_y_offset() + 40,
				    gui_screen_x_offset() + 564, gui_screen_y_offset() + 94, 2, 0, 0, NULL, 0);
	} else {
		if (_dashboard_prv_data.language != lang) {
			_dashboard_prv_data.language = lang;
			_clean_fb_data(get_dashboard_state()->panel.panel_buffer, 0, gui_screen_x_offset() + 266,
			       gui_screen_y_offset() + 28, gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column,
					gui_screen_x_offset() + 266, gui_screen_y_offset() + 28,
					gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
		}
		str = get_string(0x53);
		gui_utf_draw_middle(0, str, 0, gui_screen_x_offset() + 224, gui_screen_y_offset() + 40,
				    gui_screen_x_offset() + 522, gui_screen_y_offset() + 94, 2, 0, 0, NULL, 0);
	}
}

void dashboard_draw_add_note_hint_wide(void)
{
	uint8_t lang = get_current_language();

	if (_dashboard_prv_data.language != lang) {
		_dashboard_prv_data.language = lang;
		_clean_fb_data(get_dashboard_state()->panel.panel_buffer, 0, gui_screen_x_offset() + 210,
			       gui_screen_y_offset() + 28, gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column,
					gui_screen_x_offset() + 210, gui_screen_y_offset() + 28,
					gui_screen_x_offset() + 564, gui_screen_y_offset() + 136);
	}
	gui_utf_draw_middle(0, get_string(0x53), 0, gui_screen_x_offset() + 184, gui_screen_y_offset() + 40,
			    gui_screen_x_offset() + 564, gui_screen_y_offset() + 94, 2, 0, 0, NULL, 0);
}

void init_dashboard_info(void)
{
	int ret;

	if (is_ncs_mem_initialized() == 0) {
		G1_LOG_INF("system startup ,NCS memory is vaild\n");
		FUN_000166f8();
	} else {
		G1_LOG_INF("system startup ,NCS memory is invaild\n");
		get_dashboard_state()->dashboard_ts->ts = 1704067200;          /* 2024-01-01 */
		get_dashboard_state()->dashboard_ts->f_06 = 1704067200000ULL;
		FUN_0004d4dc(get_dashboard_state()->dashboard_ts->f_06);
	}
	for (uint8_t i = 0; i < QUICKNOTE_NUM; i++) {
		/* byte-offset form (unsigned i * sizeof) gives the target's induction variable */
		ret = getQuickNoteDataFromFlash(
			i,
			(uint8_t *)get_dashboard_state()->quick_notes + i * sizeof(struct db_quick_note) +
				offsetof(struct db_quick_note, title),
			QUICKNOTE_TITLE_LEN,
			(uint8_t *)get_dashboard_state()->quick_notes + i * sizeof(struct db_quick_note) +
				offsetof(struct db_quick_note, text),
			QUICKNOTE_TEXT_LEN);
		if (ret == -1) {
			(*get_dashboard_state()->quick_notes)[i].valid = 0;
			G1_LOG_INF("QuickNote %d is invaild,don't export\n", i);
		} else if (ret == 0) {
			(*get_dashboard_state()->quick_notes)[i].valid = 1;
			G1_LOG_INF("success export quicknote text from flash,quicknote index = %d\n", i);
		} else {
			G1_LOG_ERR("!!!! getQuickNoteDataFromFlash return unknown value.\n");
		}
	}
}

uint8_t getNotesIndex(void)
{
	_dashboard_prv_data.notes_index = notes_index;
	FUN_000167cc(notes_index);
	return _dashboard_prv_data.notes_index;
}

int FUN_00038ae4(int idx)
{
	_dashboard_prv_data.notes_index = idx;
	notes_index = idx;
	FUN_000167cc(idx);
	return 0;
}

void FUN_00038b00(void)
{
	_dashboard_prv_data.notes_index = 0;
	notes_index = 0;
	FUN_000167cc(0);
}

uint8_t get_pane_mode(void)
{
	return _dashboard_prv_data.pane_mode;
}

/* restart the burial-point timer, keeping the phone's schedule time stamp in sync */
void FUN_000806e4(struct GlassesState *gs, uint32_t *total_s)
{
	if (gs->user_sched_info->ts != 0) {
		gs->dashboard_ts->ts = gs->user_sched_info->ts;
	}
	FUN_0004d494(total_s, 0, 0);
	if (gs->user_sched_info->ts != 0) {
		gs->user_sched_info->ts = gs->dashboard_ts->ts;
	}
	FUN_00016614(gs->dashboard_ts->ts);
}

uint32_t get_dashboard_tx_ctx(void)
{
	return get_dashboard_state()->dashboard_ts->ts;
}

uint32_t FUN_00080732(void)
{
	return get_dashboard_state()->date_ts;
}

uint32_t set_date(uint32_t ts)
{
	get_dashboard_state()->date_ts = ts;
	return ts;
}

/* ui_task_table pre-callbacks (notify/ui_notification.c) */
int FUN_0008074e(struct jbd_panel_context *panel, void *arg)
{
	return 0;
}

int FUN_00080752(struct jbd_panel_context *panel, void *arg)
{
	return 0;
}

/* 0 = battery ok for "power info" (left > 20 % or right in 3..20 %) */
int power_info_battery_ok(void)
{
	if (get_dashboard_state()->battery_left <= 20) {
		return 0;
	}
	if (get_dashboard_state()->battery_right > 20) {
		return -1;
	}
	return get_dashboard_state()->battery_right > 2 ? 0 : -1;
}

/* day of the week (0 = Sunday), Zeller-like congruence */
int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		month += 12;
		year--;
	}
	return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 +
		1) % 7;
}

void FUN_00080800(uint8_t **fb, void *arg, int a, int b, int c)
{
}

int FUN_00080802(struct jbd_panel_context *panel, void *arg)
{
	return 0;
}

/* dashboard UI state (indices, last drawn modes), see dashboard.h */
struct dashboard_prv_data _dashboard_prv_data;

/* x shift of the weather / message group of the compact layout (mode 2) */
static uint16_t weather_x_shift = 0x16;

#define DB_CLEAN_FB(x0, y0, x1, y1)                                                                \
	_clean_fb_data(get_dashboard_state()->panel.panel_buffer, 0, DB_X(x0), DB_Y(y0), DB_X(x1), \
		       DB_Y(y1))
#define DB_REFLASH_FB(x0, y0, x1, y1)                                                              \
	_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,                          \
				get_dashboard_state()->panel.current_column, DB_X(x0), DB_Y(y0),   \
				DB_X(x1), DB_Y(y1))

#define DB_TEXT(fn, str, font, x0, y0, x1, y1, lines)                                              \
	fn(0, str, font, DB_X(x0), DB_Y(y0), DB_X(x1), DB_Y(y1), lines, 0, 0, NULL, 0)

static ALWAYS_INLINE bool db_notification_showing(void)
{
	return atomic_test_bit(&gui_flags, 1);
}

static ALWAYS_INLINE void db_draw_clock(int x0, int y0, int x1, int y1)
{
	bool is_24h = get_dashboard_state()->dashboard_ts->time_disp_mode != 1;

	gui_clock_draw(FUN_00080732(), DB_X(x0), DB_Y(y0), DB_X(x1), DB_Y(y1), 1, is_24h);
}

void DashBoard_Reflash(struct db_info *db, struct GlassesState *gs, int refresh,
		       uint8_t display_mode)
{
	struct dashboard_prv_data *ctx = &_dashboard_prv_data;
	uint32_t connected;
	const char *s;
	int count;
	int i;
	int idx;

	G1_LOG_INF("display_mode = %d\n", display_mode);
	connected = FUN_00028d2c();
	G1_LOG_INF("BLE Connect status : %s\n", connected == 1 ? "connect" : "disconnect");

	if (get_dashboard_state()->is_master == 1) {
		if (connected == 1 && get_dashboard_state()->f_1247 == 0 &&
		    get_dashboard_state()->dashboard_ts->dashboard_on == 1 &&
		    get_dashboard_state()->dashboard_ts->f_74 == 0) {
			if (FUN_00030440() == 1) {
				FUN_0008040c();
			}
		} else if (FUN_00030440() != 1) {
			FUN_00030458();
		}
	}

	switch (display_mode) {
	case 0: {
		if (ctx->ble_connected != connected || ctx->display_mode != 0 ||
		    ctx->pane_mode != db->pane_mode) {
			gui_screen_clear();
			ctx->pane_mode = db->pane_mode;
			ctx->ble_connected = connected;
			ctx->display_mode = db->display_mode;
			G1_LOG_INF("display_mode = %d ,exec screen clear\n", ctx->display_mode);
		}

		struct bp_date date = {0};

		if (connected == 1) {
			init_burial_point_date(FUN_00080732(), &date);
			const char *week =
				get_string(day_of_week(date.year, date.month, date.day) + 40);
			char date_str[20] = "";

			if (db->date_format == 0) {
				sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
			} else if (db->date_format == 1) {
				sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
			} else {
				sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
			}
			DB_TEXT(gui_utf_draw, date_str, 3, 0, 2, 0x8c, 0x1d, 1);
			db_draw_clock(0, 0x22, 0x96, 0x43);
			if (refresh != 1) {
				if (refresh != 4) {
					return;
				}
			} else {
				char str[8];

				gui_bmp_bitmap_draw(0x5a, DB_X(0x23e), DB_Y(4), 0, 0, 0);
				gui_bmp_bitmap_draw(0x59, DB_X(0xfe), DB_Y(4), 0, 0, 0);
				G1_LOG_INF("weather icon num = %d\n", db->weather_icon);
				memset(str, 0, sizeof(str));
				if (db->weather_icon != 0 && db->weather_icon != 0xff) {
					struct GlassesState *state;
					int temp;
					int width;

					gui_bmp_bitmap_draw(weather_icon_to_bitmap(db->weather_icon),
							    DB_X(0xa0), DB_Y(1), 0, 0, 0);
					state = get_dashboard_state();
					temp = db->temperature;
					if (state->dashboard_ts->temp_unit == 0) {
						memset(str, 0, sizeof(str));
						G1_LOG_INF("temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(3, str, DB_X(0xbc), DB_Y(1),
								DB_X(0xf8), DB_Y(0x1c), &width);
						memset(str, 0, sizeof(str));
						str[0] = '*';
						/* unit glyph: '*' = Celsius, '#' = Fahrenheit (drawn in each arm) */
						gui_string_draw(3, str, DB_X(0xbc) + width, DB_Y(1),
								DB_X(0xbc) + width + 0xf, DB_Y(0x1c), NULL);
					} else {
						temp = temp * 9 / 5 + 32;
						memset(str, 0, sizeof(str));
						G1_LOG_INF("fahrenheit_temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(3, str, DB_X(0xbc), DB_Y(1),
								DB_X(0xf8), DB_Y(0x1c), &width);
						memset(str, 0, sizeof(str));
						str[0] = '#';
						gui_string_draw(3, str, DB_X(0xbc) + width, DB_Y(1),
								DB_X(0xbc) + width + 0xf, DB_Y(0x1c), NULL);
					}
				}
				gui_bmp_bitmap_draw(0x3c, DB_X(0xa0), DB_Y(0x25), 0, 0, 0);
				count = FUN_00035310();
				memset(str, 0, sizeof(str));
				if (count > 10) {
					snprintf(str, sizeof(str), "%d+", 10);
				} else {
					snprintf(str, sizeof(str), "%d", count);
				}
				gui_string_draw(3, str, DB_X(0xbc), DB_Y(0x25), DB_X(0xe8),
						DB_Y(0x40), NULL);
				if (db->f_60 == 1) {
					gui_bmp_bitmap_draw(0x42, DB_X(0xdc), DB_Y(0x25), 0, 0, 0);
				} else {
					DB_CLEAN_FB(0xdc, 0x25, 0xf4, 0x40);
					DB_REFLASH_FB(0xdc, 0x25, 0xf4, 0x40);
				}
				gui_bmp_bitmap_draw(0x39, DB_X(0), DB_Y(0x56), 0, 0, 0);
				if (ctx->calendar_disp_mode != db->calendar_disp_mode) {
					ctx->calendar_disp_mode = db->calendar_disp_mode;
					gui_area_clear(DB_X(0x1c), DB_Y(0x51), DB_X(0xf2),
						       DB_Y(0x6c));
					gui_area_clear(DB_X(0), DB_Y(0x6c), DB_X(0xf2), DB_Y(0x87));
				}
				if (ctx->calendar_disp_mode == 0) {
					gui_area_clear(DB_X(0x1c), DB_Y(0x51), DB_X(0xf2),
						       DB_Y(0x6c));
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw, s, 0, 0, 0x6c, 0xf2, 0x89, 1);
				} else if (ctx->calendar_disp_mode == 1) {
					gui_area_clear(DB_X(0x1c), DB_Y(0x51), DB_X(0xf2),
						       DB_Y(0x6c));
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw, s, 0, 0, 0x6e, 0xf2, 0x89, 1);
				} else if (ctx->calendar_disp_mode == 2) {
					gui_area_clear(DB_X(0x1c), DB_Y(0x51), DB_X(0xf2),
						       DB_Y(0x6c));
					s = get_string(0x4a);
					DB_TEXT(gui_utf_draw, s, 0, 0, 0x6e, 0xf2, 0x89, 1);
				} else if (ctx->calendar_disp_mode == 3) {
					DB_TEXT(gui_utf_draw, DAT_2001252f[0].title, 0, 0x1c, 0x51,
						0xf2, 0x6c, 1);

					char line[0x58] = "";
					size_t len;

					memcpy(line, DAT_2001252f[0].time,
					       strlen(DAT_2001252f[0].time));
					len = strlen(DAT_2001252f[0].time);
					line[len] = ' ';
					memcpy(&line[len + 1], DAT_2001252f[0].location,
					       strlen(DAT_2001252f[0].location));
					DB_TEXT(gui_utf_draw, line, 0, 0, 0x6c, 0xf2, 0x87, 1);
				}
			}

			if (ctx->pane_mode == 0) {
				char buf[32] = "";

				count = 0;
				for (i = 0; i < 4; i++) {
					if ((*gs->quick_notes)[i].valid == 1) {
						G1_LOG_INF("quick note num.%d is vaild\n", i);
						count++;
					}
				}
				G1_LOG_INF("total quick note num = %d\n", count);
				ctx->notes_count = count;
				gui_bmp_bitmap_draw(0x3b, DB_X(0x10a), DB_Y(2), 0, 0, 0);
				if (count == 0) {
					if (db_notification_showing() && ctx->notes_shown == 1) {
						ctx->notes_shown = 0;
						DB_CLEAN_FB(0x128, 1, 0x23a, 0x1c);
						DB_REFLASH_FB(0x128, 1, 0x23a, 0x1c);
						DB_CLEAN_FB(0x10a, 0x1c, 0x232, 0x88);
						DB_REFLASH_FB(0x10a, 0x1c, 0x232, 0x88);
					}
					FUN_00038b00();
					dashboard_draw_add_note_hint();
					return;
				}
				ctx->notes_shown = 1;
				memset(buf, 0, sizeof(buf));
				snprintf(buf, sizeof(buf), "%d/%d", ctx->notes_index + 1, count);
				idx = ctx->notes_index;
				DB_TEXT(gui_utf_draw, (*gs->quick_notes)[idx].title, 0, 0x128, 1,
					0x212, 0x1c, 1);
				if (count != 1) {
					DB_TEXT(gui_utf_draw, buf, 0, 0x218, 1, 0x23a, 0x1c, 1);
				} else {
					DB_TEXT(gui_utf_draw, " ", 0, 0x218, 1, 0x23a, 0x1c, 1);
				}
				gui_utf_draw_dark_light_split(0, (*gs->quick_notes)[idx].text, 0,
							      DB_X(0x10a), DB_Y(0x1c), DB_X(0x238),
							      DB_Y(0x88), 4, 0x200b, 0, NULL, 0);
			} else if (ctx->pane_mode == 1) {
				uint8_t mode;

				count = 0;
				for (i = 0; i < 4; i++) {
					if (DAT_2000e104[i].valid == 1) {
						count++;
					}
				}
				mode = db->stocks_disp_mode;
				if (mode == 0) {
					G1_LOG_INF("db_info->stocks_disp_mode = %d\n",
						   db->stocks_disp_mode);
					if (ctx->stocks_disp_mode != db->stocks_disp_mode) {
						ctx->stocks_disp_mode = db->stocks_disp_mode;
						gui_area_clear(DB_X(0x100), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanStocksIndex();
					}
					gui_bmp_bitmap_draw(0x43, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->stocks_disp_mode != 1) {
						ctx->stocks_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					G1_LOG_INF("db_info->stocks_disp_mode = %d\n",
						   db->stocks_disp_mode);
					if (count == 0) {
						cleanStocksIndex();
					}
					gui_bmp_bitmap_draw(0x43, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x2a, 0x234, 0x45,
						1);
					s = get_string(0x4c);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x45, 0x234, 0x60,
						1);
				} else if (mode == 2) {
					if (ctx->stocks_disp_mode != 2) {
						ctx->stocks_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					count = 0;
					for (i = 0; i < 4; i++) {
						if (DAT_2000e104[i].valid == 1) {
							count++;
						}
					}
					ctx->stocks_count = count;
					idx = ctx->stocks_index;
					if (DAT_2000e104[idx].trend == 0) {
						gui_bmp_bitmap_draw(0x46, DB_X(0x10a), DB_Y(2), 0,
								    0, 0);
					} else if (DAT_2000e104[idx].trend == 1) {
						gui_bmp_bitmap_draw(0x44, DB_X(0x10a), DB_Y(2), 0,
								    0, 0);
					} else if (DAT_2000e104[idx].trend == 2) {
						gui_bmp_bitmap_draw(0x45, DB_X(0x10a), DB_Y(2), 0,
								    0, 0);
					}
					if (count != 0) {
						char buf[32] = "";

						snprintf(buf, sizeof(buf), "%d/%d", idx + 1, count);
						DB_TEXT(gui_utf_draw, buf, 0, 0x218, 1, 0x23a, 0x1c,
							1);
					} else {
						gui_area_clear(DB_X(0x218), DB_Y(1), DB_X(0x23a),
							       DB_Y(0x1c));
					}
					DB_TEXT(gui_utf_draw, DAT_2000e104[idx].name, 0, 0x126, 0,
						0x200, 0x1b, 1);
					DB_TEXT(gui_utf_draw, DAT_2000e104[idx].full_name, 0, 0x10a,
						0x1b, 0x232, 0x36, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].price,
						0, 0x1d2, 0x36, 0x232, 0x51, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].change,
						0, 0x1d2, 0x51, 0x232, 0x6c, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].percent,
						0, 0x1d2, 0x6c, 0x232, 0x87, 1);
					gui_bitmap_draw(DB_X(0x10a), DB_Y(0x36), DB_X(0x1c2),
							DB_Y(0x88), DAT_2000e104[idx].chart, 0xf);
				}
			} else if (ctx->pane_mode == 2) {
				char buf[32] = "";
				uint8_t mode;

				count = 0;
				for (i = 0; i < 4; i++) {
					if (DAT_20011281[i].valid == 1) {
						G1_LOG_INF("news num.%d is vaild\n", i);
						count++;
					}
				}
				mode = db->news_disp_mode;
				if (mode == 0) {
					if (ctx->news_disp_mode != 0) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->news_disp_mode != 1) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x2a, 0x234, 0x45,
						1);
					s = get_string(0x4c);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x45, 0x234, 0x60,
						1);
				} else if (mode == 4) {
					if (ctx->news_disp_mode != 4) {
						ctx->news_disp_mode = 4;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x51);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x36, 0x234, 0x6c,
						2);
				} else if (mode == 2) {
					if (ctx->news_disp_mode != 2) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					G1_LOG_INF("total news num = %d\n", count);
					ctx->news_count = count;
					gui_bmp_bitmap_draw(0x47, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					if (count == 0) {
						if (db_notification_showing() &&
						    ctx->news_shown == 1) {
							ctx->news_shown = 0;
							DB_CLEAN_FB(0x128, 1, 0x23a, 0x1c);
							DB_REFLASH_FB(0x128, 1, 0x23a, 0x1c);
							DB_CLEAN_FB(0x10a, 0x1c, 0x232, 0x88);
							DB_REFLASH_FB(0x10a, 0x1c, 0x232, 0x88);
						}
						cleanNewsIndex();
						return;
					}
					ctx->news_shown = 1;
					memset(buf, 0, sizeof(buf));
					snprintf(buf, sizeof(buf), "%d/%d", ctx->news_index + 1,
						 count);
					idx = ctx->news_index;
					DB_TEXT(gui_utf_draw, DAT_20011281[idx].title, 0, 0x128, 1,
						0x212, 0x1c, 1);
					if (count != 1) {
						DB_TEXT(gui_utf_draw, buf, 0, 0x218, 1, 0x23a, 0x1c,
							1);
					} else {
						DB_TEXT(gui_utf_draw, " ", 0, 0x218, 1, 0x23a, 0x1c,
							1);
					}
					gui_utf_draw_dark_light_split(0, DAT_20011281[idx].body, 0,
								      DB_X(0x10a), DB_Y(0x1c),
								      DB_X(0x238), DB_Y(0x88), 4,
								      0x200b, 0, NULL, 0);
				}
			} else if (ctx->pane_mode == 4) {
				uint8_t mode = db->citywalk_disp_mode;

				if (mode == 0 || (ctx->screen_cleared == 0 && DAT_2001111d == 0)) {
					if (ctx->citywalk_disp_mode != mode) {
						ctx->citywalk_disp_mode = mode;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bmp_bitmap_draw(0x48, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->citywalk_disp_mode != 1) {
						ctx->citywalk_disp_mode = 1;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bmp_bitmap_draw(0x48, DB_X(0x10a), DB_Y(2), 0, 0, 0);
					s = get_string(0x50);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0x10a, 0x2a, 0x234, 0x60,
						2);
				} else if (mode == 3 && DAT_2001111d == 1 &&
					   (ctx->screen_cleared == 0 || db->citywalk_f_71 == 3) &&
					   db->citywalk_x <= 0x108 && db->citywalk_y <= 0x68) {
					if (ctx->screen_cleared) {
						db->citywalk_f_71 = 0;
						get_dashboard_state()->dashboard_ts->f_71 = 0;
					}
					if (ctx->citywalk_disp_mode != db->citywalk_disp_mode) {
						ctx->citywalk_disp_mode = db->citywalk_disp_mode;
						gui_area_clear(DB_X(0x100), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bitmap_draw(DB_X(0x10a), DB_Y(0), DB_X(0x232),
							DB_Y(0x88), DAT_200143cf, 2);
					gui_1bit_bitmap_override(
						DB_X(0x10a) + db->citywalk_x,
						DB_Y(0) + db->citywalk_y,
						DB_X(0x10a) + db->citywalk_x + 0x20,
						DB_Y(0) + db->citywalk_y + 0x20, DAT_20015777, 0xf);
				}
			}
		} else {
			init_burial_point_date(FUN_00080732(), &date);
			const char *week =
				get_string(day_of_week(date.year, date.month, date.day) + 40);
			char date_str[20] = "";

			if (db->date_format == 0) {
				sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
			} else if (db->date_format == 1) {
				sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
			} else {
				sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
			}
			DB_TEXT(gui_utf_draw, date_str, 3, 0x2e, 0, 0xb9, 0x1b, 1);
			db_draw_clock(0x2e, 0x34, 0xc3, 0x55);
			if (refresh != 1) {
				if (refresh != 4) {
					return;
				}
			} else {
				gui_bmp_bitmap_draw(0x3e, DB_X(0x2e), DB_Y(0x6d), 0, 0, 0);
				if (db->f_60 == 1) {
					gui_bmp_bitmap_draw(0x42, DB_X(0x8e), DB_Y(0x6d), 0, 0, 0);
				} else {
					DB_CLEAN_FB(0x8e, 0x6d, 0xa6, 0x88);
					DB_REFLASH_FB(0x8e, 0x6d, 0xa6, 0x88);
				}
				gui_bmp_bitmap_draw(0x5a, DB_X(0x214), DB_Y(4), 0, 0, 0);
				gui_bmp_bitmap_draw(0x59, DB_X(0xd4), DB_Y(4), 0, 0, 0);
			}
			if (ctx->pane_mode == 0) {
				char buf[32] = "";

				count = 0;
				for (i = 0; i < 4; i++) {
					if ((*gs->quick_notes)[i].valid == 1) {
						G1_LOG_INF("quick note num.%d is vaild\n", i);
						count++;
					}
				}
				G1_LOG_INF("total quick note num = %d\n", count);
				ctx->notes_count = count;
				gui_bmp_bitmap_draw(0x3b, DB_X(0xe0), DB_Y(2), 0, 0, 0);
				if (count == 0) {
					if (db_notification_showing() && ctx->notes_shown == 1) {
						ctx->notes_shown = 0;
						DB_CLEAN_FB(0x128, 1, 0x208, 0x1c);
						DB_REFLASH_FB(0x128, 1, 0x23a, 0x1c);
						DB_CLEAN_FB(0x10a, 0x1c, 0x208, 0x88);
						DB_REFLASH_FB(0x10a, 0x1c, 0x208, 0x88);
					}
					FUN_00038b00();
					dashboard_draw_add_note_hint();
					return;
				}
				ctx->notes_shown = 1;
				memset(buf, 0, sizeof(buf));
				snprintf(buf, sizeof(buf), "%d/%d", ctx->notes_index + 1, count);
				idx = ctx->notes_index;
				DB_TEXT(gui_utf_draw, (*gs->quick_notes)[idx].title, 0, 0xfc, 1, 0x1d6,
					0x1c, 1);
				if (count != 1) {
					DB_TEXT(gui_utf_draw, buf, 0, 0x1e4, 1, 0x212, 0x1c, 1);
				} else {
					DB_TEXT(gui_utf_draw, " ", 0, 0x1e4, 1, 0x212, 0x1c, 1);
				}
				gui_utf_draw_dark_light_split(0, (*gs->quick_notes)[idx].text, 0,
							      DB_X(0xe0), DB_Y(0x1c), DB_X(0x208),
							      DB_Y(0x88), 4, 0x200b, 0, NULL, 0);
				return;
			}
			if (ctx->pane_mode == 1) {
				gui_bmp_bitmap_draw(0x43, DB_X(0xe0), DB_Y(2), 0, 0, 0);
			} else if (ctx->pane_mode == 2) {
				gui_bmp_bitmap_draw(0x47, DB_X(0xe0), DB_Y(2), 0, 0, 0);
			} else if (ctx->pane_mode == 4) {
				gui_bmp_bitmap_draw(0x48, DB_X(0xe0), DB_Y(2), 0, 0, 0);
			}
			s = get_string(0x4f);
			DB_TEXT(gui_utf_draw_middle, s, 0, 0xe0, 0x36, 0x20a, 0x6c, 2);
		}
		break;
	}
	case 1: {
		if (ctx->ble_connected != connected || ctx->display_mode != 1 ||
		    ctx->pane_mode != db->pane_mode) {
			gui_screen_clear();
			ctx->pane_mode = db->pane_mode;
			ctx->ble_connected = connected;
			ctx->display_mode = db->display_mode;
			G1_LOG_INF("display_mode = %d ,exec screen clear\n", ctx->display_mode);
		}

		struct bp_date date = {0};

		if (connected == 1) {
			init_burial_point_date(FUN_00080732(), &date);
			const char *week =
				get_string(day_of_week(date.year, date.month, date.day) + 40);
			char date_str[20] = "";

			if (db->date_format == 0) {
				sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
			} else if (db->date_format == 1) {
				sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
			} else {
				sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
			}
			DB_TEXT(gui_utf_draw, date_str, 3, 0, 2, 0x8c, 0x1d, 1);
			db_draw_clock(0, 0x34, 0x96, 0x55);
			if (refresh != 1) {
				if (refresh != 4) {
					return;
				}
			} else {
				char str[8];

				gui_bmp_bitmap_draw(0x5a, DB_X(0x23e), DB_Y(4), 0, 0, 0);
				gui_bmp_bitmap_draw(0x59, DB_X(0xac), DB_Y(4), 0, 0, 0);
				G1_LOG_INF("weather icon num = %d\n", db->weather_icon);
				memset(str, 0, sizeof(str));
				if (db->weather_icon != 0 && db->weather_icon != 0xff) {
					struct GlassesState *state;
					int temp;
					int width;

					gui_bmp_bitmap_draw(weather_icon_to_bitmap(db->weather_icon), DB_X(0),
							    DB_Y(0x6d), 0, 0, 0);
					state = get_dashboard_state();
					temp = db->temperature;
					if (state->dashboard_ts->temp_unit == 0) {
						memset(str, 0, sizeof(str));
						G1_LOG_INF("temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(3, str, DB_X(0x1c), DB_Y(0x6d),
								DB_X(0x58), DB_Y(0x88), &width);
						memset(str, 0, sizeof(str));
						str[0] = '*';
						gui_string_draw(3, str, DB_X(0x1c) + width, DB_Y(0x6d),
								DB_X(0x1c) + width + 0x4b, DB_Y(0x88),
								NULL);
					} else {
						memset(str, 0, sizeof(str));
						temp = temp * 9 / 5 + 32;
						G1_LOG_INF("fahrenheit_temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(3, str, DB_X(0x1c), DB_Y(0x6d),
								DB_X(0x58), DB_Y(0x88), &width);
						memset(str, 0, sizeof(str));
						str[0] = '#';
						gui_string_draw(3, str, DB_X(0x1c) + width, DB_Y(0x6d),
								DB_X(0x1c) + width + 0x4b, DB_Y(0x88),
								NULL);
					}
				}
				gui_bmp_bitmap_draw(0x3c, DB_X(0x60), DB_Y(0x6d), 0, 0, 0);
				count = FUN_00035310();
				memset(str, 0, sizeof(str));
				if (count > 10) {
					snprintf(str, sizeof(str), "%d+", 10);
				} else {
					snprintf(str, sizeof(str), "%d", count);
				}
				gui_string_draw(3, str, DB_X(0x7c), DB_Y(0x6d), DB_X(0x9a),
						DB_Y(0x88), NULL);
				if (db->f_60 == 1) {
					gui_bmp_bitmap_draw(0x42, DB_X(0x8c), DB_Y(1), 0, 0, 0);
				} else {
					DB_CLEAN_FB(0x8c, 1, 0xa4, 0x1c);
					DB_REFLASH_FB(0x8c, 1, 0xa4, 0x1c);
				}
			}

			if (ctx->pane_mode == 0) {
				char buf[32] = "";

				count = 0;
				for (i = 0; i < 4; i++) {
					if ((*gs->quick_notes)[i].valid == 1) {
						G1_LOG_INF("quick note num.%d is vaild\n", i);
						count++;
					}
				}
				G1_LOG_INF("total quick note num = %d\n", count);
				ctx->notes_count = count;
				gui_bmp_bitmap_draw(0x3b, DB_X(0xba), DB_Y(1), 0, 0, 0);
				if (count == 0) {
					if (db_notification_showing() && ctx->notes_shown == 1) {
						ctx->notes_shown = 0;
						DB_CLEAN_FB(0xd6, 1, 0x22e, 0x1c);
						DB_REFLASH_FB(0xd6, 1, 0x22e, 0x1c);
						DB_CLEAN_FB(0xba, 0x1c, 0x238, 0x88);
						DB_REFLASH_FB(0xba, 0x1c, 0x238, 0x88);
					}
					FUN_00038b00();
					dashboard_draw_add_note_hint_wide();
					return;
				}
				ctx->notes_shown = 1;
				memset(buf, 0, sizeof(buf));
				snprintf(buf, sizeof(buf), "%d/%d", ctx->notes_index + 1, count);
				idx = ctx->notes_index;
				DB_TEXT(gui_utf_draw, (*gs->quick_notes)[idx].title, 0, 0xd6, 1, 0x22e,
					0x1c, 1);
				if (count != 1) {
					DB_TEXT(gui_utf_draw, buf, 0, 0x20e, 1, 0x23a, 0x1c, 1);
				} else {
					DB_TEXT(gui_utf_draw, " ", 0, 0x20e, 1, 0x23a, 0x1c, 1);
				}
				gui_utf_draw_dark_light_split(0, (*gs->quick_notes)[idx].text, 0,
							      DB_X(0xba), DB_Y(0x1c), DB_X(0x238),
							      DB_Y(0x88), 4, 0x200b, 0, NULL, 0);
				return;
			}
			switch (ctx->pane_mode) {
			case 1: {
				uint8_t mode;

				count = 0;
				for (i = 0; i < 4; i++) {
					if (DAT_2000e104[i].valid == 1) {
						count++;
					}
				}
				mode = db->stocks_disp_mode;
				if (mode == 0) {
					if (ctx->stocks_disp_mode != 0) {
						ctx->stocks_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanStocksIndex();
					}
					G1_LOG_INF("db_info->stocks_disp_mode = %d\n",
						   db->stocks_disp_mode);
					gui_bmp_bitmap_draw(0x43, DB_X(0xba), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->stocks_disp_mode != 1) {
						ctx->stocks_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanStocksIndex();
					}
					G1_LOG_INF("db_info->stocks_disp_mode = %d\n",
						   db->stocks_disp_mode);
					gui_bmp_bitmap_draw(0x43, DB_X(0xba), DB_Y(2), 0, 0, 0);
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x2a, 0x234, 0x45,
						1);
					s = get_string(0x4c);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x45, 0x234, 0x60,
						1);
				} else if (mode == 2) {
					if (ctx->stocks_disp_mode != 2) {
						ctx->stocks_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					count = 0;
					for (i = 0; i < 4; i++) {
						if (DAT_2000e104[i].valid == 1) {
							count++;
						}
					}
					idx = ctx->stocks_index;
					ctx->stocks_count = count;
					if (DAT_2000e104[idx].trend == 0) {
						gui_bmp_bitmap_draw(0x46, DB_X(0xba), DB_Y(2), 0, 0,
								    0);
					} else if (DAT_2000e104[idx].trend == 1) {
						gui_bmp_bitmap_draw(0x44, DB_X(0xba), DB_Y(2), 0, 0,
								    0);
					} else if (DAT_2000e104[idx].trend == 2) {
						gui_bmp_bitmap_draw(0x45, DB_X(0xba), DB_Y(2), 0, 0,
								    0);
					}
					if (count != 0) {
						char buf[32] = "";

						snprintf(buf, sizeof(buf), "%d/%d", idx + 1, count);
						DB_TEXT(gui_utf_draw, buf, 0, 0x20e, 1, 0x23a, 0x1c,
							1);
					} else {
						gui_area_clear(DB_X(0x20e), DB_Y(1), DB_X(0x23a),
							       DB_Y(0x1c));
					}
					DB_TEXT(gui_utf_draw, DAT_2000e104[idx].name, 0, 0xd6, 0,
						0x202, 0x1b, 1);
					DB_TEXT(gui_utf_draw, DAT_2000e104[idx].full_name, 0, 0xba,
						0x1b, 0x234, 0x36, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].price,
						0, 0x182, 0x36, 0x234, 0x51, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].change,
						0, 0x182, 0x51, 0x234, 0x6c, 1);
					DB_TEXT(gui_utf_draw_align_right, DAT_2000e104[idx].percent,
						0, 0x182, 0x6c, 0x234, 0x87, 1);
					gui_bitmap_draw(DB_X(0xba), DB_Y(0x36), DB_X(0x172),
							DB_Y(0x88), DAT_2000e104[idx].chart, 0xf);
				}
				return;
			}
			case 2: {
				char buf[32] = "";
				uint8_t mode;

				count = 0;
				for (i = 0; i < 4; i++) {
					if (DAT_20011281[i].valid == 1) {
						G1_LOG_INF("news num.%d is vaild\n", i);
						count++;
					}
				}
				mode = db->news_disp_mode;
				if (mode == 0) {
					if (ctx->news_disp_mode != 0) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0xba), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->news_disp_mode != 1) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0xba), DB_Y(2), 0, 0, 0);
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x2a, 0x234, 0x45,
						1);
					s = get_string(0x4c);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x45, 0x234, 0x60,
						1);
				} else if (mode == 4) {
					if (ctx->news_disp_mode != 4) {
						ctx->news_disp_mode = 4;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					if (count == 0) {
						cleanNewsIndex();
					}
					gui_bmp_bitmap_draw(0x47, DB_X(0xba), DB_Y(2), 0, 0, 0);
					s = get_string(0x51);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x6c,
						2);
				} else if (mode == 2) {
					if (ctx->news_disp_mode != 2) {
						ctx->news_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(4), DB_X(0x23c),
							       DB_Y(0x88));
					}
					G1_LOG_INF("total news num = %d\n", count);
					ctx->news_count = count;
					gui_bmp_bitmap_draw(0x47, DB_X(0xba), DB_Y(2), 0, 0, 0);
					if (count == 0) {
						if (db_notification_showing() &&
						    ctx->news_shown == 1) {
							ctx->news_shown = 0;
							DB_CLEAN_FB(0xd4, 1, 0x23c, 0x1c);
							DB_REFLASH_FB(0xd4, 1, 0x23c, 0x1c);
							DB_CLEAN_FB(0xba, 0x1c, 0x234, 0x88);
							DB_REFLASH_FB(0xba, 0x1c, 0x234, 0x88);
						}
						cleanNewsIndex();
						return;
					}
					ctx->news_shown = 1;
					memset(buf, 0, sizeof(buf));
					snprintf(buf, sizeof(buf), "%d/%d", ctx->news_index + 1,
						 count);
					idx = ctx->news_index;
					DB_TEXT(gui_utf_draw, DAT_20011281[idx].title, 0, 0xd6, 1,
						0x200, 0x1c, 1);
					if (count != 1) {
						DB_TEXT(gui_utf_draw, buf, 0, 0x216, 1, 0x23a, 0x1c,
							1);
					} else {
						DB_TEXT(gui_utf_draw, " ", 0, 0x216, 1, 0x23a, 0x1c,
							1);
					}
					gui_utf_draw_dark_light_split(0, DAT_20011281[idx].body, 0,
								      DB_X(0xba), DB_Y(0x1c),
								      DB_X(0x236), DB_Y(0x88), 4,
								      0x200b, 0, NULL, 0);
				}
				return;
			}
			case 3: {

				if (ctx->calendar_disp_mode != db->calendar_disp_mode ||
				    ctx->calendar_last_index != ctx->calendar_index) {
					ctx->calendar_disp_mode = db->calendar_disp_mode;
					ctx->calendar_last_index = ctx->calendar_index;
					gui_area_clear(DB_X(0x20e), DB_Y(2), DB_X(0x234),
						       DB_Y(0x1d));
					gui_area_clear(DB_X(0xb8), DB_Y(0x3b), DB_X(0x23e),
						       DB_Y(0x88));
				}
				count = 0;
				for (i = 0; i < 8; i++) {
					if (DAT_2001252f[i].valid == 1) {
						G1_LOG_INF("news num.%d is vaild\n", i);
						count++;
					}
				}
				G1_LOG_INF("total calendar num = %d\n", count);
				ctx->calendar_count = count / 2 + count % 2;
				if (ctx->calendar_disp_mode == 0) {
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x51,
						1);
				} else if (ctx->calendar_disp_mode == 1) {
					s = get_string(0x4b);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x2a, 0x234, 0x45,
						1);
					s = get_string(0x4c);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x45, 0x234, 0x60,
						1);
				} else if (ctx->calendar_disp_mode == 2) {
					gui_bmp_bitmap_draw(0x39, DB_X(0xba), DB_Y(1), 0, 0, 0);
					s = get_string(0x4e);
					DB_TEXT(gui_utf_draw, s, 0, 0xd6, 0, 0x13a, 0x1b, 1);
					s = get_string(0x4a);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x51,
						1);
				} else if (ctx->calendar_disp_mode == 3) {
					gui_bmp_bitmap_draw(0x39, DB_X(0xba), DB_Y(1), 0, 0, 0);
					s = get_string(0x4e);
					DB_TEXT(gui_utf_draw, s, 0, 0xd6, 0, 0x13a, 0x1b, 1);
					if (ctx->calendar_count == 0) {
						return;
					}
					char buf[32] = "";

					snprintf(buf, sizeof(buf), "%d/%d", ctx->calendar_index + 1,
						 ctx->calendar_count);
					DB_TEXT(gui_utf_draw, buf, 0, 0x216, 1, 0x23a, 0x1c, 1);
					DB_TEXT(gui_utf_draw,
						DAT_2001252f[ctx->calendar_index * 2].title, 0,
						0xba, 0x1b, 0x236, 0x36, 1);
					DB_TEXT(gui_utf_draw,
						DAT_2001252f[ctx->calendar_index * 2].time, 0, 0xba,
						0x36, 0x15e, 0x51, 1);
					DB_TEXT(gui_utf_draw_align_right,
						DAT_2001252f[ctx->calendar_index * 2].location, 0,
						0x162, 0x36, 0x234, 0x51, 1);
					if (DAT_2001252f[ctx->calendar_index * 2 + 1].valid != 1) {
						return;
					}
					DB_TEXT(gui_utf_draw,
						DAT_2001252f[ctx->calendar_index * 2 + 1].title, 0,
						0xba, 0x51, 0x236, 0x6c, 1);
					DB_TEXT(gui_utf_draw,
						DAT_2001252f[ctx->calendar_index * 2 + 1].time, 0,
						0xba, 0x6c, 0x15e, 0x87, 1);
					DB_TEXT(gui_utf_draw_align_right,
						DAT_2001252f[ctx->calendar_index * 2 + 1].location,
						0, 0x162, 0x6c, 0x234, 0x87, 1);
					return;
				} else {
					return;
				}
				cleanCalenadrIndex();
				return;
			}
			case 4: {
				uint8_t mode = db->citywalk_disp_mode;

				if (mode == 0 || (ctx->screen_cleared == 0 && DAT_2001111d == 0)) {
					if (ctx->citywalk_disp_mode != mode) {
						ctx->citywalk_disp_mode = mode;
						gui_area_clear(DB_X(0xae), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bmp_bitmap_draw(0x48, DB_X(0xb8), DB_Y(2), 0, 0, 0);
					s = get_string(0x4d);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x51,
						1);
				} else if (mode == 1) {
					if (ctx->citywalk_disp_mode != 1) {
						ctx->citywalk_disp_mode = 1;
						gui_area_clear(DB_X(0xae), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bmp_bitmap_draw(0x48, DB_X(0xb8), DB_Y(2), 0, 0, 0);
					s = get_string(0x50);
					DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x2a, 0x234, 0x60,
						2);
				} else if (mode == 3 && DAT_2001111d == 1 &&
					   (ctx->screen_cleared == 0 || db->citywalk_f_71 == 3) &&
					   db->citywalk_x <= 0x158 && db->citywalk_y <= 0x68) {
					if (ctx->screen_cleared == 1) {
						db->citywalk_f_71 = 0;
						get_dashboard_state()->dashboard_ts->f_71 = 0;
					}
					if (ctx->citywalk_disp_mode != db->citywalk_disp_mode) {
						ctx->citywalk_disp_mode = db->citywalk_disp_mode;
						gui_area_clear(DB_X(0xae), DB_Y(0), DB_X(0x23c),
							       DB_Y(0x88));
					}
					gui_bitmap_draw(DB_X(0xb8), DB_Y(0), DB_X(0x230),
							DB_Y(0x88), DAT_200143cf, 2);
					gui_1bit_bitmap_override(DB_X(0xb8) + db->citywalk_x,
								 DB_Y(0) + db->citywalk_y,
								 DB_X(0xb8) + db->citywalk_x + 0x20,
								 DB_Y(0) + db->citywalk_y + 0x20,
								 DAT_20015cc7, 0xf);
				}
				return;
			}
			default:
				return;
			}
		}

		init_burial_point_date(FUN_00080732(), &date);
		const char *week = get_string(day_of_week(date.year, date.month, date.day) + 40);
		char date_str[20] = "";

		if (db->date_format == 0) {
			sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
		} else if (db->date_format == 1) {
			sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
		} else {
			sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
		}
		DB_TEXT(gui_utf_draw, date_str, 3, 0, 0, 0x8c, 0x1b, 1);
		db_draw_clock(0, 0x34, 0x96, 0x55);
		if (refresh != 1) {
			if (refresh != 4) {
				return;
			}
		} else {
			gui_bmp_bitmap_draw(0x3e, DB_X(0), DB_Y(0x6d), 0, 0, 0);
			if (db->f_60 == 1) {
				gui_bmp_bitmap_draw(0x42, DB_X(0x60), DB_Y(0x6d), 0, 0, 0);
			} else {
				DB_CLEAN_FB(0x60, 0x6d, 0x78, 0x88);
				DB_REFLASH_FB(0x60, 0x6d, 0x78, 0x88);
			}
			gui_bmp_bitmap_draw(0x5a, DB_X(0x23e), DB_Y(4), 0, 0, 0);
			gui_bmp_bitmap_draw(0x59, DB_X(0xac), DB_Y(4), 0, 0, 0);
		}
		if (ctx->pane_mode == 0) {
			char buf[32] = "";

			count = 0;
			for (i = 0; i < 4; i++) {
				if ((*gs->quick_notes)[i].valid == 1) {
					G1_LOG_INF("quick note num.%d is vaild\n", i);
					count++;
				}
			}
			G1_LOG_INF("total quick note num = %d\n", count);
			ctx->notes_count = count;
			gui_bmp_bitmap_draw(0x3b, DB_X(0xba), DB_Y(1), 0, 0, 0);
			if (count == 0) {
				if (db_notification_showing() && ctx->notes_shown == 1) {
					ctx->notes_shown = 0;
					DB_CLEAN_FB(0xd6, 1, 0x22e, 0x1c);
					DB_REFLASH_FB(0xd6, 1, 0x22e, 0x1c);
					DB_CLEAN_FB(0xba, 0x1c, 0x238, 0x88);
					DB_REFLASH_FB(0xba, 0x1c, 0x238, 0x88);
				}
				FUN_00038b00();
				dashboard_draw_add_note_hint_wide();
				return;
			}
			ctx->notes_shown = 1;
			memset(buf, 0, sizeof(buf));
			snprintf(buf, sizeof(buf), "%d/%d", ctx->notes_index + 1, count);
			idx = ctx->notes_index;
			DB_TEXT(gui_utf_draw, (*gs->quick_notes)[idx].title, 0, 0xd6, 1, 0x22e, 0x1c,
				1);
			if (count != 1) {
				DB_TEXT(gui_utf_draw, buf, 0, 0x20e, 1, 0x23a, 0x1c, 1);
			} else {
				DB_TEXT(gui_utf_draw, " ", 0, 0x20e, 1, 0x23a, 0x1c, 1);
			}
			gui_utf_draw_dark_light_split(0, (*gs->quick_notes)[idx].text, 0, DB_X(0xba),
						      DB_Y(0x1c), DB_X(0x238), DB_Y(0x88), 4,
						      0x200b, 0, NULL, 0);
			return;
		}
		switch (ctx->pane_mode) {
		case 1:
			gui_bmp_bitmap_draw(0x43, DB_X(0xba), DB_Y(2), 0, 0, 0);
			break;
		case 2:
			gui_bmp_bitmap_draw(0x47, DB_X(0xba), DB_Y(2), 0, 0, 0);
			break;
		case 3:
			gui_bmp_bitmap_draw(0x39, DB_X(0xba), DB_Y(2), 0, 0, 0);
			break;
		case 4:
			gui_bmp_bitmap_draw(0x48, DB_X(0xba), DB_Y(2), 0, 0, 0);
			break;
		}
		get_current_language();
		s = get_string(0x4f);
		DB_TEXT(gui_utf_draw_middle, s, 0, 0xb8, 0x36, 0x234, 0x6c, 2);
		return;
	}
	case 2: {
		if (ctx->ble_connected != connected || ctx->display_mode != 2 ||
		    ctx->pane_mode != db->pane_mode) {
			gui_screen_clear();
			ctx->pane_mode = db->pane_mode;
			ctx->ble_connected = connected;
			ctx->display_mode = db->display_mode;
			G1_LOG_INF("display_mode = %d ,exec screen clear\n", ctx->display_mode);
		}

		if (connected == 1) {
			if (refresh == 1) {
				char str[8];

				if (db->f_60 == 1) {
					if (weather_x_shift != 0) {
						weather_x_shift = 0;
						DB_CLEAN_FB(0, 0x1c, 0x240, 0x37);
						DB_REFLASH_FB(0, 0x1c, 0x240, 0x37);
					}
					gui_bmp_bitmap_draw(0x42, DB_X(0x1b8), DB_Y(0x1c), 0, 0, 0);
				} else if (weather_x_shift != 0x16) {
					weather_x_shift = 0x16;
					DB_CLEAN_FB(0, 0x1c, 0x240, 0x37);
					DB_REFLASH_FB(0, 0x1c, 0x240, 0x37);
				}
				G1_LOG_INF("weather icon num = %d\n", db->weather_icon);
				memset(str, 0, sizeof(str));
				if (db->weather_icon != 0 && db->weather_icon != 0xff) {
					struct GlassesState *state;
					int temp;
					int width;

					gui_bmp_bitmap_draw(weather_icon_to_bitmap(db->weather_icon),
							    gui_screen_x_offset() + weather_x_shift +
								    0x100,
							    DB_Y(0x1c), 0, 0, 0);
					state = get_dashboard_state();
					temp = db->temperature;
					if (state->dashboard_ts->temp_unit == 0) {
						memset(str, 0, sizeof(str));
						G1_LOG_INF("temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(
							3, str,
							gui_screen_x_offset() + weather_x_shift + 0x11c,
							DB_Y(0x1c),
							gui_screen_x_offset() + weather_x_shift + 0x144,
							DB_Y(0x37), &width);
						memset(str, 0, sizeof(str));
						str[0] = '*';
						gui_string_draw(
							3, str,
							gui_screen_x_offset() + weather_x_shift + 0x11c + width,
							DB_Y(0x1c),
							gui_screen_x_offset() + weather_x_shift + width + 0x12b,
							DB_Y(0x37), NULL);
					} else {
						temp = temp * 9 / 5 + 32;
						memset(str, 0, sizeof(str));
						G1_LOG_INF("fahrenheit_temperature = %d\n", temp);
						snprintf(str, sizeof(str), "%d", temp);
						width = 0;
						gui_string_draw(
							3, str,
							gui_screen_x_offset() + weather_x_shift + 0x11c,
							DB_Y(0x1c),
							gui_screen_x_offset() + weather_x_shift + 0x144,
							DB_Y(0x37), &width);
						memset(str, 0, sizeof(str));
						str[0] = '#';
						gui_string_draw(
							3, str,
							gui_screen_x_offset() + weather_x_shift + 0x11c + width,
							DB_Y(0x1c),
							gui_screen_x_offset() + weather_x_shift + width + 0x12b,
							DB_Y(0x37), NULL);
					}
				}
				gui_bmp_bitmap_draw(0x3c, DB_X(0x16e) + weather_x_shift, DB_Y(0x1c),
						    0, 0, 0);
				count = FUN_00035310();
				memset(str, 0, sizeof(str));
				if (count > 10) {
					snprintf(str, sizeof(str), "%d+", 10);
				} else {
					snprintf(str, sizeof(str), "%d", count);
				}
				gui_string_draw(3, str, gui_screen_x_offset() + weather_x_shift + 0x18a,
						DB_Y(0x1c),
						gui_screen_x_offset() + weather_x_shift + 0x1a4,
						DB_Y(0x37), NULL);
			}
			struct bp_date date = {0};

			init_burial_point_date(FUN_00080732(), &date);
			const char *week =
				get_string(day_of_week(date.year, date.month, date.day) + 40);
			char date_str[20] = "";

			if (db->date_format == 0) {
				sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
			} else if (db->date_format == 1) {
				sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
			} else {
				sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
			}
			gui_utf_draw_align_right(
				0, date_str, 3, gui_screen_x_offset() + weather_x_shift + 0x54, DB_Y(0x1c),
				gui_screen_x_offset() + weather_x_shift + 0xe0, DB_Y(0x37), 1, 0, 0, NULL,
				0);
			db_draw_clock(0xea, 0x4c, 0x180, 0x6d);
		} else {
			if (refresh == 1) {
				if (db->f_60 == 1) {
					if (weather_x_shift != 0) {
						weather_x_shift = 0;
						DB_CLEAN_FB(0, 0x1c, 0x240, 0x37);
						DB_REFLASH_FB(0, 0x1c, 0x240, 0x37);
					}
					gui_bmp_bitmap_draw(0x42, DB_X(0x178), DB_Y(0x1c), 0, 0, 0);
				} else if (weather_x_shift != 0x16) {
					weather_x_shift = 0x16;
					DB_CLEAN_FB(0, 0x1c, 0x240, 0x37);
					DB_REFLASH_FB(0, 0x1c, 0x240, 0x37);
				}
				gui_bmp_bitmap_draw(0x3e, gui_screen_x_offset() + weather_x_shift + 0x144,
						    DB_Y(0x1c), 0, 0, 0);
			}
			struct bp_date date = {0};

			init_burial_point_date(FUN_00080732(), &date);
			const char *week =
				get_string(day_of_week(date.year, date.month, date.day) + 40);
			char date_str[20] = "";

			if (db->date_format == 0) {
				sprintf(date_str, "%s, %02d/%02d", week, date.month, date.day);
			} else if (db->date_format == 1) {
				sprintf(date_str, "%s, %02d-%02d", week, date.day, date.month);
			} else {
				sprintf(date_str, "%s, %02d/%02d", week, date.day, date.month);
			}
			gui_utf_draw_align_right(
				0, date_str, 3, gui_screen_x_offset() + weather_x_shift + 0x98, DB_Y(0x1c),
				gui_screen_x_offset() + weather_x_shift + 0x124, DB_Y(0x37), 1, 0, 0, NULL,
				0);
			db_draw_clock(0xea, 0x4c, 0x180, 0x6d);
		}
		break;
	}
	default:
		break;
	}
}

/* fade-in step counter (a static global in the vendor code) */
static int dashboard_fade_step;

uint8_t getStocksIndex(void)
{
	_dashboard_prv_data.stocks_index = stocks_index;
	G1_LOG_INF(" %s index = %d\n", __func__, stocks_index);
	return _dashboard_prv_data.stocks_index;
}

int setStocksIndex(int idx)
{
	_dashboard_prv_data.stocks_index = idx;
	stocks_index = idx;
	G1_LOG_INF(" %s index = %d\n", __func__, (uint8_t)idx);
	return 0;
}

void cleanStocksIndex(void)
{
	_dashboard_prv_data.stocks_index = 0;
	stocks_index = 0;
	G1_LOG_INF(" %s index = %d\n", __func__, 0);
}

uint8_t getNewsIndex(void)
{
	_dashboard_prv_data.news_index = news_index;
	G1_LOG_INF(" %s index = %d\n", __func__, news_index);
	return _dashboard_prv_data.news_index;
}

int setNewsIndex(int idx)
{
	_dashboard_prv_data.news_index = idx;
	news_index = idx;
	G1_LOG_INF(" %s index = %d\n", __func__, (uint8_t)idx);
	return 0;
}

void cleanNewsIndex(void)
{
	_dashboard_prv_data.news_index = 0;
	news_index = 0;
	G1_LOG_INF(" %s index = %d\n", __func__, 0);
}

uint8_t getCalenadrIndex(void)
{
	_dashboard_prv_data.calendar_index = calendar_index;
	G1_LOG_INF(" calendar %s index = %d\n", __func__, calendar_index);
	return _dashboard_prv_data.calendar_index;
}

int setCalenadrIndex(int idx)
{
	_dashboard_prv_data.calendar_index = idx;
	calendar_index = idx;
	G1_LOG_INF("calendar %s index = %d\n", __func__, (uint8_t)idx);
	return 0;
}

void cleanCalenadrIndex(void)
{
	_dashboard_prv_data.calendar_index = 0;
	calendar_index = 0;
	G1_LOG_INF(" %s index = %d\n", __func__, 0);
}


void set_screen_cleared(void)
{
	_dashboard_prv_data.screen_cleared = 0;
}

int send_message_count_to_app(void)
{
	if (get_dashboard_state()->is_master == 2) {
		return 0;
	}
	uint8_t data[16] = {0};

	data[0] = 0x22;
	data[1] = 0x0a;
	data[4] = 0x01;
	data[5] = FUN_00035310();
	data[6] = get_dashboard_state()->dashboard_ts->low_power;
	data[7] = get_dashboard_state()->dashboard_ts->f_65;
	data[8] = get_dashboard_state()->dashboard_ts->f_66;
	if (_dashboard_prv_data.pane_mode == 0) {
		data[9] = getNotesIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 1) {
		data[9] = getStocksIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 2) {
		data[9] = getNewsIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 3) {
		data[9] = getCalenadrIndex() + 1;
	}
	send_response_data_to_msgqueue(data, 10);
	return send_response_data_to_ble();
}

int sync_dashboard_key_event_to_app(void)
{
	if (get_dashboard_state()->is_master == 2) {
		return 0;
	}
	uint8_t data[16] = {0};

	data[0] = 0x22;
	data[1] = 0x08;
	data[4] = 0x02;
	data[5] = get_dashboard_state()->dashboard_ts->f_65;
	data[6] = _dashboard_prv_data.pane_mode;
	if (_dashboard_prv_data.pane_mode == 0) {
		data[7] = getNotesIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 1) {
		data[7] = getStocksIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 2) {
		data[7] = getNewsIndex() + 1;
	} else if (_dashboard_prv_data.pane_mode == 3) {
		data[7] = getCalenadrIndex() + 1;
		G1_LOG_ERR("calendar index = %d\n", data[7]);
	}
	send_response_data_to_msgqueue(data, 8);
	return send_response_data_to_ble();
}

#define SEND_DASHBOARD_LOCK_INFO()                                                    \
	do {                                                                          \
		uint8_t lock[6] = {0};                                                \
		lock[0] = 0x50;                                                       \
		lock[1] = 0x06;                                                       \
		lock[4] = 0x01;                                                       \
		lock[5] = 0x02;                                                       \
                                                                                      \
		G1_LOG_INF("send dashboard lock info to app ,status = %d \n", 2);   \
		send_response_data_to_msgqueue(lock, 6);                              \
		send_response_data_to_ble();                                          \
		atomic_or(&DAT_20007f4c, BIT(1));                                     \
	} while (0)

int ui_DashBoard_task(struct jbd_panel_context *panel, void *arg, int event)
{
	struct GlassesState *gs = get_dashboard_state();
	struct db_info *db = &gs->db_info;
	struct dashboard_prv_data *prv = &_dashboard_prv_data;

	set_frame_buffer(panel->panel_buffer);

	switch (prv->state) {
	case 0:
		G1_LOG_INF("Enter DASHBOARD_INIT_STATUS task....\n");
		enter_dashboard_burial_point();
		if (event == UI_EVT_EXIT) {
			G1_LOG_INF("dashboard function exit ...\n");
			get_dashboard_state()->dashboard_ts->dashboard_on = 0;
			FUN_00029774(0x1f);
			gui_screen_clear();
			goto exit;
		}
		if (event == UI_EVT_ENTER && get_dashboard_state()->dashboard_ts->dashboard_on == 1 &&
		    gs->db_info.f_73 == 1) {
			if (!prv->init_done) {
				G1_LOG_INF("DASHBOARD INIT .......\n");
				FUN_00029774(0x1e);
				memset(prv, 0, sizeof(*prv));
				gui_screen_clear();
				/* statement order decides the register allocation of the whole
				 * function (LRA spills the frame buffer pointer otherwise) */
				prv->notes_index = notes_index;
				prv->stocks_index = stocks_index;
				prv->news_index = news_index;
				prv->calendar_index = calendar_index;
				prv->init_done = 1;
				prv->calendar_disp_mode = gs->db_info.calendar_disp_mode;
				G1_LOG_INF("quicknote index = %d,stocks index = %d,news index = %d,calendar = %d\n",
					   notes_index, stocks_index, news_index, calendar_index);
				G1_LOG_INF("db_info->schedule_disp_status = %d\n",
					   gs->db_info.calendar_disp_mode);
				G1_LOG_INF("db_info->stocks_disp_mode = %d\n", gs->db_info.stocks_disp_mode);
				G1_LOG_INF("db_info->news_disp_mode = %d\n", gs->db_info.news_disp_mode);
				G1_LOG_INF("db_info->schedule_disp_status = %d\n",
					   gs->db_info.calendar_disp_mode);
				G1_LOG_INF("db_info->citywalk_disp_mode = %d\n",
					   gs->db_info.citywalk_disp_mode);
				clear_showing_notification_on_gui();
				dashboard_fade_step = 0;
				while (dashboard_fade_step < 4) {
					DashBoard_Reflash(db, get_dashboard_state(), 1,
							  gs->db_info.display_mode);
					for (int row = 0; row < 199; row++) {
						for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
							const uint8_t steps[8] = {1, 3, 5, 7, 7, 7, 7, 7};
							uint8_t pix = panel->panel_buffer[row][col];

							if (pix != 0) {
								panel->panel_buffer[row][col] =
									pix & gui_fade_mask[row % 26]
											   [steps[dashboard_fade_step]]
											   [col];
							}
						}
					}
					dashboard_fade_step++;
					_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
								get_dashboard_state()->panel.current_column, 0, 0,
								GUI_SCREEN_WIDTH, 199);
				}
				set_showing_notification_on_gui();
				if (get_dashboard_state()->is_master == 1) {
					uint8_t sync[2];
					int8_t idx; /* signed: keeps the target's `and #0xf0` */
					int val;
					int ret;

					sync[0] = 0x02;
					sync[1] = 0x02;
					if (prv->pane_mode == 0) {
						idx = getNotesIndex();
						val = sync[1] | ((idx << 4) & 0xf0);
						sync[1] = val;
						G1_LOG_INF("master sync quicknote index to slave ,index = %d\n", val);
					} else if (prv->pane_mode == 1) {
						sync[1] = 0x04;
						idx = getStocksIndex();
						val = sync[1] | ((idx << 4) & 0xf0);
						sync[1] = val;
						G1_LOG_INF("master sync stocks index to slave,index = %d\n", val);
					} else if (prv->pane_mode == 2) {
						sync[1] = 0x06;
						idx = getNewsIndex();
						val = sync[1] | ((idx << 4) & 0xf0);
						sync[1] = val;
						G1_LOG_INF("master sync news index to slave,index = %d\n", val);
					} else if (prv->pane_mode == 3) {
						sync[1] = 0x08;
						idx = getCalenadrIndex();
						val = sync[1] | ((idx << 4) & 0xf0);
						sync[1] = val;
						G1_LOG_INF("master sync news index to slave,index = %d\n", val);
					}
					ret = sync_to_slave(get_dashboard_state(), 6, sync, 2);
					if (ret >= 5000) {
						G1_LOG_WRN("SYNC TO Slave failed...,don't exec key function.\n");
					} else {
						G1_LOG_INF("sync to slave return value = %d,exec key function. ts = %d\n",
							   ret, (uint32_t)FUN_00080732());
					}
				}
				prv->enter_ts = k_uptime_get();
				prv->state = 1;
				prv->screen_cleared = 1;
				set_display_wait_ms(0x42);
				send_message_count_to_app();
			}
			if (get_dashboard_state()->is_master == 1) {
				if (FUN_00028d2c() == 1) {
					if (FUN_00030440() == 1 && get_dashboard_state()->f_1247 == 0) {
						FUN_0008040c();
					}
				} else if (FUN_00030440() != 1) {
					FUN_00030458();
				}
			}
		}
		if (!atomic_test_bit(&DAT_20007f50, 1)) {
			return 0;
		}
		if (atomic_test_bit(&DAT_20007f4c, 1)) {
			return 0;
		}
		SEND_DASHBOARD_LOCK_INFO();
		return 0;

	case 1:

	if (atomic_test_bit(&DAT_20007f50, 1) && !atomic_test_bit(&DAT_20007f4c, 1)) {
		SEND_DASHBOARD_LOCK_INFO();
	}
	if (FUN_00035310() != prv->msg_count) {
		prv->msg_count = FUN_00035310();
		G1_LOG_INF("notify message count has changed,send message count to app. unread messgae count = %d\n",
			   prv->msg_count);
		send_message_count_to_app();
	}
	set_showing_notification_on_gui();
	G1_LOG_INF("Enter DASHBOARD_RUNING_STATUS task....\n");

	if (event == UI_EVT_EXIT) {
		G1_LOG_INF("dashboard function exit ...\n");
		get_dashboard_state()->dashboard_ts->dashboard_on = 0;
		FUN_00029774(0x1f);
		gui_screen_fade_out();
		atomic_clear_bit(&DAT_20008480, 1);
		exit_dashboard_burial_point();
		memset(prv, 0, sizeof(*prv));
		return 0;
	}
	if (event == UI_EVT_ENTER) {
		DashBoard_Reflash(db, get_dashboard_state(), event, gs->db_info.display_mode);
		return 0;
	}
	if (event == UI_EVT_REFRESH) {
		G1_LOG_INF("current index = %d\n", gs->db_info.display_mode);
		DashBoard_Reflash(db, get_dashboard_state(), 0, gs->db_info.display_mode);
	}
	if (event == UI_EVT_INPUT) {
		uint8_t mode;

		G1_LOG_ERR("received key press event,_dashboard_prv_data.display_mode = %d\n",
			   prv->display_mode);
		mode = prv->pane_mode;
		G1_LOG_ERR("_CurrentCustomAreaType = %d\n", mode);
		if (mode == 0) {
			if (prv->notes_count > 1) {
				notes_index = prv->notes_index =
					(uint8_t)(prv->notes_index + 1) % prv->notes_count;
				FUN_000167cc(notes_index);
				G1_LOG_INF("current quicknote index = %d\n", prv->notes_index);
			}
		}
		if (mode == 1) {
			if (prv->stocks_count > 1) {
				stocks_index = prv->stocks_index =
					(uint8_t)(prv->stocks_index + 1) % prv->stocks_count;
				G1_LOG_INF("current stocks index = %d\n", prv->stocks_index);
			}
		}
		if (mode == 2) {
			if (prv->news_count > 1 && prv->news_index != 3) {
				news_index = prv->news_index =
					(uint8_t)(prv->news_index + 1) % prv->news_count;
				G1_LOG_INF("current news index = %d\n", prv->news_index);
			}
		}
		if (mode == 3) {
			if (prv->calendar_count != 0) {
				calendar_index = prv->calendar_index =
					(uint8_t)(prv->calendar_index + 1) % prv->calendar_count;
				G1_LOG_ERR("current calendar index = %d\n", prv->calendar_index);
			}
		}
		if (mode == 4) {
			goto power;
		}
		DashBoard_Reflash(db, get_dashboard_state(), 4, gs->db_info.display_mode);
		sync_dashboard_key_event_to_app();
	}
	if (event == UI_EVT_LOW_POWER) {
		G1_LOG_INF("received system low power event.\n");
		get_dashboard_state()->dashboard_ts->low_power = 1;
		send_message_count_to_app();
	}
	if (event == UI_EVT_POWER_RESUME) {
		G1_LOG_INF("received system  power resume event.\n");
		get_dashboard_state()->dashboard_ts->low_power = 0;
		send_message_count_to_app();
	}

power:
	if (get_dashboard_state()->is_master == 1) {
		int low = power_info_battery_ok();
		int64_t now = k_uptime_get();

		if (low == 0) {
			if (get_dashboard_state()->dashboard_ts->low_power != 0) {
				if (prv->power_info_sent) {
					return 0;
				}
				if (now - prv->enter_ts <= 1500) {
					return 0;
				}
			}
			SendPowerInfoToSlave(1);
		} else {
			if (get_dashboard_state()->dashboard_ts->low_power != 1) {
				if (prv->power_info_sent) {
					return 0;
				}
				if (now - prv->enter_ts <= 1500) {
					return 0;
				}
			}
			SendPowerInfoToSlave(0);
		}
		prv->power_info_sent = 1;
	}
		break;
	default:
		break;
	}
	return 0;

exit:
	atomic_clear_bit(&DAT_20008480, 1);
	exit_dashboard_burial_point();
	memset(prv, 0, sizeof(*prv));
	return 0;
}

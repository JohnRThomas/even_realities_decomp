/*
 * GUI drawing layer: frame buffer handling, bitmap drawing, UTF-8 text.
 */
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>

#define GUI_C_INTERNAL
#include "gui.h"
#include "gui_fade_mask.h"

int gui_font_kerning(uint16_t cur, uint16_t next);
int gui_utf_draw_scroll_line(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		  uint32_t max_lines, uint32_t dark_cnt);

struct gui_text_anim text_anim;
uint8_t text_anim_buf[0x80];
/* text grey level used by the gui_utf_draw* family */
volatile uint8_t text_grey_level = 0x55;

static uint8_t **frame_buffer;
atomic_t gui_flags;

/* scroll/line state reset by gui_text_state_reset() (write-only in this image; non-static,
 * otherwise GCC would drop the stores) */
int gui_aa0c;
int gui_aa08;
int gui_aa04;
int gui_aa00;
int gui_a9fc;
int gui_a9f8;

/* advanced UTF draw state, see gui_utf_adv_draw_configure() */
int adv_param1;   /* 0x2000a9f4 */
int adv_param2;   /* 0x2000a9f0 */
int adv_step;     /* 0x2000a9ec */
int adv_mode;     /* 0x2000a9e8 */
int adv_e4;       /* 0x2000a9e4 */
int adv_e0;       /* 0x2000a9e0 */
int adv_enable;   /* 0x2000a9dc */
int adv_d8;       /* 0x2000a9d8 */

uint8_t adv_db48;
uint8_t adv_db47;
static uint8_t dark_light_flag;

/* frame counters of gui_bmp_dynamic_bitmap_draw() */
static uint16_t dyn_frame_cnt;
static uint16_t dyn_frame_idx;
static uint16_t dyn_loop_cnt;

atomic_val_t gui_flags_get(void)
{
	return atomic_get(&gui_flags);
}

int set_frame_buffer(uint8_t **fb)
{
	frame_buffer = fb;
	return 0;
}

int gui_screen_clear(void)
{
	G1_LOG_INF("exec screen clear command....\n");

	if (!get_jdb_panel_context()->init_done) {
		G1_LOG_ERR("c->init_done = 0,init failed, can't write data!\n");
		return -1;
	}

	jbd_clear_cache_sync(0);
	return 0;
}

int gui_area_clear(int x_start, int y_start, int x_end, int y_end)
{
	G1_LOG_INF("exec area clear command....\n");

	if (!get_jdb_panel_context()->init_done) {
		G1_LOG_ERR("c->init_done = 0,init failed, can't write data!\n");
		return -1;
	}

	_clean_fb_data(GUI_STATE()->panel.panel_buffer, 0, x_start, y_start, x_end, y_end);
	_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row, GUI_STATE()->panel.current_column,
				x_start, y_start, x_end, y_end);
	return 0;
}

int set_showing_notification_on_gui(void)
{
	atomic_or(&gui_flags, GUI_FLAG_NOTIFICATION_SHOWING);
	return 0;
}

int clear_showing_notification_on_gui(void)
{
	atomic_and(&gui_flags, ~GUI_FLAG_NOTIFICATION_SHOWING);
	return 0;
}

int gui_dynamic_bitmap_reset(void)
{
	dyn_frame_cnt = 0;
	dyn_frame_idx = 0;
	dyn_loop_cnt = 0;
	return 0;
}

int gui_icon_area_clear(int x, int y)
{
	_clean_fb_data(frame_buffer, 0, x, y, x + 40, y + 40);
	return 0;
}

int gui_bmp_dynamic_bitmap_draw(int id, int x, int y, int a, int b, int c, uint8_t loop)
{
	int w = 0, h = 0;
	const uint8_t *data = NULL;
	uint8_t frames;

	if (resource_manger_get(5, id, &w, &h, &data, &frames) < 0) {
		G1_LOG_WRN("can't find resource,please check resource name !\n");
		return -1;
	}

	dyn_frame_cnt = frames;
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x, y, x + w, y + h);
	}
	copy_to_frame_buffer(frame_buffer, data + h * ((w * dyn_frame_idx) / 2), w / 2, h, x, y);
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x, y, x + w, y + h);
	}

	if (dyn_frame_idx < dyn_frame_cnt - 1) {
		dyn_frame_idx++;
	} else if (loop == 0 || loop - 1 > dyn_loop_cnt) {
		dyn_frame_idx++;
	}
	if (dyn_frame_idx >= dyn_frame_cnt) {
		dyn_frame_idx = 0;
		dyn_loop_cnt++;
	}
	return 0;
}

int gui_bmp_bitmap_draw(int id, int x, int y, int effect, gui_effect_cb_t cb, int no_draw)
{
	const uint8_t *data;

	if (effect == 0 && cb == NULL) {
		int w, h;

		if (no_draw == 0) {
			w = 0;
			h = 0;
			if (id < 0x16 || id > 0x87) {
				if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
					_clean_fb_data(frame_buffer, 0, x, y, x + 24, y + 24);
				}
				data = FUN_0004b2d4((uint8_t)id, 0x120);
				copy_to_frame_buffer(frame_buffer, data, 12, 24, x, y);
				if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
					_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
								GUI_STATE()->panel.current_column, x, y,
								x + 24, y + 24);
				}
			} else {
				if (resource_manger_get(4, id, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can't find resource,please check resource name !\n");
					return -1;
				}
				if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
					_clean_fb_data(frame_buffer, 0, x, y, w + 2 + x, y + h);
				}
				copy_to_frame_buffer(frame_buffer, data, w / 2, h, x, y);
				if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
					_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
								GUI_STATE()->panel.current_column, x, y,
								w + 2 + x, y + h);
				}
			}
		}
	}
	return 0;
}

int gui_bmp_bitmap_draw_ex(int id, int x, int y, uint8_t *buf, uint8_t level)
{
	int w, h;
	const uint8_t *data;
	size_t size;

	if (level == 0) {
		G1_LOG_WRN("dark light value parampter error,exit!\n");
		return -1;
	}

	if (resource_manger_get(4, id, &w, &h, &data, NULL) < 0) {
		G1_LOG_WRN("can't find resource,please check resource name !\n");
		return -1;
	}

	size = w / 2 * h;
	memcpy(buf, data, size);
	for (int i = 0; i < (int)size; i++) {
		if (buf[i] != 0) {
			buf[i] &= level;
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x, y, w + 2 + x, y + h);
	}
	copy_to_frame_buffer(frame_buffer, buf, w / 2, h, x, y);
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x, y, w + 2 + x, y + h);
	}
	return 0;
}

int gui_text_state_reset(void)
{
	gui_aa0c = 0;
	gui_aa08 = 0;
	gui_aa04 = 0;
	gui_aa00 = 0;
	gui_a9fc = 0;
	gui_a9f8 = 0;
	return 0;
}

/* index is passed by address on purpose: it keeps the vendor compare order (dark_cnt > i) */
static inline int gui_char_is_dark(const uint32_t *idx, uint32_t dark_cnt)
{
	return *idx < dark_cnt;
}

/* G1_LOG_WRN with &__func__[0]: identical code, but GIMPLE does not tail-merge it with G1_LOG_WRN */
#define GUI_DW_CB_LOG()                                                                       \
	do {                                                                                  \
		if (LOG_LEVEL > 1) {                                                          \
			if (BLE_DEBUG) {                                                      \
				ble_printk("%s(): exex process effect callback function\n",  \
					   &__func__[0]);                                     \
			} else {                                                              \
				printk("%s(): exex process effect callback function\n",      \
				       &__func__[0]);                                         \
			}                                                                     \
		}                                                                             \
	} while (0)

int gui_utf_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		 uint32_t max_lines, uint32_t dark_cnt, volatile int effect, gui_effect_cb_t cb,
		 int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;
	uint32_t i;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		int x_off = 0, y_off = 0, line_w = 0, lines = 0;
		uint32_t y_max;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}

		for (i = 0; (int)i < count; i++) {
			uint8_t glyph[676];
			uint16_t c = *code++;
			int ret = check_printable_code(c);

			if (ret == 0) {
				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
					continue;
				}
				memcpy(glyph, data, h * (w / 2));
				if (dark_cnt != 0 && gui_char_is_dark(&i, dark_cnt)) {
					for (int k = 0; k < h * (w / 2); k++) {
						glyph[k] &= text_grey_level;
					}
				}
				line_w += w + gui_font_kerning(code[-1], code[0]);
				if (line_w > (uint32_t)(x1 - x0)) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
					lines++;
					if (lines >= max_lines) {
						break;
					}
					y_max = y1 - y0;
					if (y_off >= y_max) {
						break;
					}
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0, y0 + y_off);
					x_off = w + gui_font_kerning(code[-1], code[0]);
					line_w = x_off;
				} else {
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0 + x_off,
							     y0 + y_off);
					x_off += gui_font_kerning(code[-1], code[0]) + w;
				}
			} else if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines) {
					break;
				}
				y_max = y1 - y0;
				if (y_off >= y_max) {
					break;
				}
				line_w = 0;
				x_off = 0;
			}
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		/* Same log in every arm (see agent_notes/gui_utf_draw_darkword_by_lines.md):
		 * the no_draw tests only add IRA references; post-reload crossjump merges
		 * the identical arms and deletes them.
		 */
		if (no_draw == 1) {
			G1_LOG_WRN("exex process effect callback function\n");
		} else if (no_draw == 2) {
			GUI_DW_CB_LOG();
		} else if (no_draw == 3) {
			GUI_DW_CB_LOG();
		} else {
			GUI_DW_CB_LOG();
		}
		return cb(0, str, font, x0, y0);
	}
	return 0;
}

int gui_utf_draw_dark_light_split(int arg, const char *str, int font, int x0, int y0, int x1,
				  int y1, uint32_t max_lines, uint16_t split_code, int effect,
				  gui_effect_cb_t cb, int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		int x_off = 0, y_off = 0, line_w = 0, lines = 0;
		uint32_t y_max;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}

		for (uint32_t i = 0; (int)i < count; i++) {
			uint8_t glyph[676];
			uint16_t c = *code++;
			int ret = check_printable_code(c);

			if (ret == 0) {
				if (c == split_code) {
					if (dark_light_flag == 0) {
						dark_light_flag = 1;
						G1_LOG_WRN("dark_light_flag 1 code = 0x%x\n", split_code);
					} else {
						dark_light_flag = 0;
						G1_LOG_WRN("dark_light_flag 0 code = 0x%x\n", split_code);
					}
					continue;
				}
				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
					continue;
				}
				memcpy(glyph, data, h * (w / 2));
				if (dark_light_flag == 1) {
					for (int k = 0; k < h * (w / 2); k++) {
						glyph[k] &= text_grey_level;
					}
				}
				line_w += w + gui_font_kerning(code[-1], code[0]);
				if (line_w > (uint32_t)(x1 - x0)) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
					lines++;
					if (lines >= max_lines) {
						break;
					}
					y_max = y1 - y0;
					if (y_off >= y_max) {
						break;
					}
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0, y0 + y_off);
					x_off = gui_font_kerning(code[-1], code[0]) + w;
					line_w = x_off;
				} else {
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0 + x_off,
							     y0 + y_off);
					x_off += gui_font_kerning(code[-1], code[0]) + w;
				}
			} else if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines) {
					break;
				}
				y_max = y1 - y0;
				if (y_off >= y_max) {
					break;
				}
				line_w = 0;
				x_off = 0;
			}
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		G1_LOG_WRN("exex process effect callback function\n");
		return cb(0, str, font, x0, y0);
	}
	dark_light_flag = 0;
	return 0;
}


/* second operand read through a pointer on purpose: keeps the vendor compare operand order */
static inline int gui_u32_ge(uint32_t a, const uint32_t *b)
{
	return a >= *b;
}

int gui_utf_draw_truncate(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		uint8_t glyph[676];
		int x_off = 0;
		int y_off = 0;
		int line_w = 0;
		int i = 0;
		int lines = 0;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}
		int width = x1 - x0;
		uint32_t y_max;

		for (; (int)i < count; i++, code++) {
			uint16_t c = *code;
			int ret = check_printable_code(c);

			if (ret == 0) {
				int gw, gh, bw;

				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
					continue;
				}
				gw = w;
				bw = gw / 2;
				gh = h;
				memcpy(glyph, data, gh * bw);
				if (!gui_u32_ge(i, &dark_cnt)) {
					for (int k = 0; k < gh * bw; k++) {
						glyph[k] &= text_grey_level;
					}
				}
				int kern = gui_font_kerning(code[0], code[1]);

				line_w += gw + kern;
				if (width < (uint32_t)line_w) {
					lines++;
					y_max = y1 - y0;
					if (lines >= max_lines || y_off >= y_max) {
						/* last line is full: make room for an ellipsis */
						uint16_t *p = code;
						uint32_t k = i;
						_Alignas(4) unsigned short ch = c;

						while (k != 0) {
							if ((uint32_t)(width - x_off) > 3) {
								goto ellipsis;
							}
							ch = p[-1];
							k--;
							if (resource_manger_get(font, ch, &w, &h, &data,
										NULL) < 0) {
								/* G1_LOG_WRN expanded by hand: the printk arm is written
								 * twice (identical calls; &__func__[0] keeps GIMPLE from
								 * merging them, RTL crossjump does). The ch test only
								 * adds IRA references and is deleted with the merge.
								 */
								if (LOG_LEVEL > 1) {
									if (BLE_DEBUG) {
										ble_printk("%s(): truncate can not find [%d]0x%x font resource\n",
											   __func__, k, ch);
									} else if (ch & 1) {
										printk("%s(): truncate can not find [%d]0x%x font resource\n",
										       __func__, k, ch);
									} else {
										printk("%s(): truncate can not find [%d]0x%x font resource\n",
										       &__func__[0], k, ch);
									}
								}
							} else {
								int kern = gui_font_kerning(p[-1], p[0]);

								x_off = x_off - w - kern;
								_clean_fb_data(frame_buffer, 0, x0 + x_off,
									       y0 + (int)y_off, x0 + x_off + w,
									       y0 + (int)y_off + h);
							}
							p--;
						}
						x_off = 0;
ellipsis:
						G1_LOG_WRN("end line x0=%d\n", x_off);
						if (resource_manger_get(font, 0x2026, &w, &h, &data, NULL) <
						    0) {
							G1_LOG_WRN("can not find 0x%x font resource\n", ch);
							continue;
						}
						bw = w / 2;
						gh = h;
						unsigned int size = gh * bw;

						/* identical arms (see agent_notes/gui_utf_draw_truncate.md):
						 * the test keeps p live across the size multiply for IRA,
						 * crossjump merges the two calls and deletes it.
						 */
						if ((uintptr_t)p & 1) {
							memcpy(glyph, data, size);
						} else {
							memcpy(&glyph[0], data, size);
						}
						if (i < dark_cnt) {
							for (int n = 0; n < gh * bw; n++) {
								glyph[n] &= text_grey_level;
							}
						}
						copy_to_frame_buffer(frame_buffer, glyph, bw, gh, x0 + x_off,
								     y0 + (int)y_off);
						break;
					}
					uint32_t ny = y_off + gh;

					if (font == 0) {
						ny++;
					}
					copy_to_frame_buffer(frame_buffer, glyph, bw, gh, x0, y0 + (int)ny);
					y_off = ny;
					x_off = w + gui_font_kerning(code[0], code[1]);
					line_w = x_off;
				} else {
					copy_to_frame_buffer(frame_buffer, glyph, bw, gh, x0 + x_off,
							     y0 + (int)y_off);
					x_off += gui_font_kerning(code[0], code[1]) + w;
				}
			}
			if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines || gui_u32_ge(y_off, &(uint32_t){y1 - y0})) {
					break;
				}
				x_off = 0;
				line_w = 0;
				continue;
			}
		}
		/* shared return inside glyph's scope: gives the vendor block layout */
		if (0) {
ret0:
			return 0;
		}
	} else if (cb != NULL) {
		G1_LOG_WRN("exex process effect callback function\n");
		return cb(0, str, font, x0, y0);
	} else {
		goto ret0;
	}
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0, y0, x1, y1);
	}
	goto ret0;
}

/* `volatile int effect` (top-level qualifier, only in the definition; the prototype stays
 * compatible) keeps effect in its stack slot during register allocation, like the vendor build. */
int gui_utf_draw_darkword_by_lines(int arg, const char *str, int font, int x0, int y0, int x1,
				   int y1, uint32_t max_lines, uint8_t dark_lines, volatile int effect,
				   gui_effect_cb_t cb, int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		int x_off = 0, y_off = 0, line_w = 0, lines = 0;
		uint32_t y_max;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}

		for (uint32_t i = 0; (int)i < count; i++) {
			uint8_t glyph[676];
			uint16_t c = *code++;
			int ret = check_printable_code(c);

			if (ret == 0) {
				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
					continue;
				}
				memcpy(glyph, data, h * (w / 2));
				if (dark_lines != 0 && (int)lines < dark_lines) {
					for (int k = 0; k < h * (w / 2); k++) {
						glyph[k] &= text_grey_level;
					}
				}
				line_w += w + gui_font_kerning(code[-1], code[0]);
				if (line_w > (uint32_t)(x1 - x0)) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
					lines++;
					if (lines >= max_lines) {
						break;
					}
					y_max = y1 - y0;
					if (y_off >= y_max) {
						break;
					}
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0, y0 + y_off);
					x_off = w + gui_font_kerning(code[-1], code[0]);
					line_w = x_off;
				} else {
					copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0 + x_off,
							     y0 + y_off);
					x_off += gui_font_kerning(code[-1], code[0]) + w;
				}
			} else if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines) {
					break;
				}
				y_max = y1 - y0;
				if (y_off >= y_max) {
					break;
				}
				line_w = 0;
				x_off = 0;
			}
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		/* Same log in every arm (see agent_notes/gui_utf_draw_darkword_by_lines.md):
		 * the no_draw tests only add IRA references; post-reload crossjump merges
		 * the identical arms and deletes them.
		 */
		if (no_draw == 1) {
			G1_LOG_WRN("exex process effect callback function\n");
		} else if (no_draw == 2) {
			GUI_DW_CB_LOG();
		} else if (no_draw == 3) {
			GUI_DW_CB_LOG();
		} else {
			GUI_DW_CB_LOG();
		}
		return cb(0, str, font, x0, y0);
	}
	return 0;
}

/* read through a pointer so new_line is renamed into SSA after early inlining:
 * this orders its loop PHI after i's (see agent_notes/gui_utf_draw_middle.md) */
static inline bool gui_bool_get(const bool *b)
{
	return *b;
}

int gui_utf_draw_middle(int arg, const char *str, int font, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
		  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
		  int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		uint32_t i;
		int x_start = x0;
		uint32_t x_off = 0;
		uint32_t y_off = 0;
		uint32_t line_w = 0;
		int lines = 0;
		bool new_line = true;
		uint32_t y_max;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}

		for (i = 0; (int)i < count; i++) {
			uint8_t glyph[676];
			uint16_t c;
			int ret;

			if (gui_bool_get(&new_line)) {
				/* measure the line up to the next CR/LF */
				int lw = 0;
				uint16_t *p = code;

				for (uint32_t j = i; (int)j < count; j++, p++) {
					uint16_t ch = *p;

					if (ch == '\r' || ch == '\n') {
						break;
					}
					if (check_printable_code(ch) == 0) {
						if (resource_manger_get(font, ch, &w, &h, &data, NULL) < 0) {
							G1_LOG_WRN("can not find 0x%x font resource\n", ch);
						} else {
							lw += gui_font_kerning(p[0], p[1]) + w;
						}
					}
				}
				x_start = x0 + ((x1 - x0 - lw) >> 1);
			}

			c = *code++;
			ret = check_printable_code(c);
			if (ret == 0) {
				int gw, gh, bw;

				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
				} else {
					gw = w;
					bw = gw / 2;
					gh = h;
					memcpy(glyph, data, gh * bw);
					if (gui_char_is_dark(&i, dark_cnt)) {
						for (int k = 0; k < gh * bw; k++) {
							glyph[k] &= text_grey_level;
						}
					}
					line_w += gui_font_kerning(code[-1], code[0]) + gw;
					if (line_w > x1 - x0) {
						y_off += gh;
						if (font == 0) {
							y_off++;
						}
						lines++;
						if (lines >= max_lines) {
							break;
						}
						y_max = y1 - y0;
						if (y_off >= y_max) {
							break;
						}
						copy_to_frame_buffer(frame_buffer, glyph, bw, gh, x_start,
								     y0 + y_off);
						x_off = gui_font_kerning(code[-1], code[0]) + w;
						line_w = x_off;
					} else {
						copy_to_frame_buffer(frame_buffer, glyph, bw, gh,
								     x_start + x_off, y0 + y_off);
						x_off += gui_font_kerning(code[-1], code[0]) + w;
					}
				}
				new_line = false;
			} else if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines) {
					break;
				}
				if (y_off >= y1 - y0) {
					break;
				}
				new_line = true;
				x_off = 0;
				line_w = 0;
			} else {
				new_line = false;
			}
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		G1_LOG_WRN("exex process effect callback function\n");
		return cb(0, str, font, x0, y0);
	}
	return 0;
}

int gui_utf_draw_align_right(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		       uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
		       int no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *code = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		uint32_t x_off = 0;
		uint32_t y_off = 0;
		uint32_t line_w = 0;
		int i;
		int lines = 0;
		int x_start = x0;
		bool new_line = true;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}

		for (i = 0; i < count; i++) {
			uint8_t glyph[676];
			uint16_t c;
			int ret;

			if (new_line) {
				/* measure the line up to the next CR/LF (16-bit width kept in an int) */
				int lw = 0;
				uint16_t *p = code;

				for (int j = i; j < count; j++, p++) {
					uint16_t ch = *p;

					if (ch == '\r' || ch == '\n') {
						break;
					}
					if (check_printable_code(ch) == 0) {
						if (resource_manger_get(font, ch, &w, &h, &data, NULL) < 0) {
							G1_LOG_WRN("can not find 0x%x font resource\n", ch);
						} else {
							lw = (uint16_t)(lw + w);
							lw = (uint16_t)(lw + gui_font_kerning(p[0], p[1]));
						}
					}
				}
				{
					uint32_t span = x1 - x0;
					x_start = lw <= span ? x1 - lw : x0;
				}
				x_start &= ~1;
			}

			c = *code++;
			ret = check_printable_code(c);
			if (ret == 0) {
				int gw, gh, bw;

				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					G1_LOG_WRN("can not find 0x%x font resource\n", c);
				} else {
					gw = w;
					bw = gw / 2;
					gh = h;
					memcpy(glyph, data, gh * bw);
					if ((uint32_t)i < dark_cnt) {
						for (int k = 0; k < gh * bw; k++) {
							glyph[k] &= text_grey_level;
						}
					}
					line_w += gui_font_kerning(code[-1], code[0]) + gw;
					if (line_w > (uint32_t)(x1 - x0)) {
						y_off += gh;
						if (font == 0) {
							y_off++;
						}
						lines++;
						if (lines >= max_lines) {
							break;
						}
						if (y_off >= (uint32_t)(y1 - y0)) {
							break;
						}
						copy_to_frame_buffer(frame_buffer, glyph, bw, gh, x_start,
								     y0 + (int)y_off);
						x_off = gui_font_kerning(code[-1], code[0]) + w;
						line_w = x_off;
					} else {
						copy_to_frame_buffer(frame_buffer, glyph, bw, gh,
								     x_start + x_off, y0 + (int)y_off);
						x_off += gui_font_kerning(code[-1], code[0]) + w;
					}
				}
				new_line = false;
			} else if (ret == -1 && (c == '\r' || c == '\n')) {
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines) {
					break;
				}
				if (y_off >= (uint32_t)(y1 - y0)) {
					break;
				}
				new_line = true;
				x_off = 0;
				line_w = 0;
			} else {
				new_line = false;
			}
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		G1_LOG_WRN("exex process effect callback function\n");
		return cb(0, str, font, x0, y0);
	}
	return 0;
}


/*
 * G1_LOG_WRN variants for gui_utf_Wordwrap_draw: the printk (and for GUI_WW_LOG2 also the ble_printk) call is
 * written twice behind a test, once with __func__ and once with &__func__[0].  Both arms print the same line;
 * GIMPLE keeps them apart, post-reload cross-jumping merges them and deletes the test.  The tests only add
 * register-allocation references (they keep the vendor register / stack-slot assignment).
 */
#define GUI_WW_LOG(cond, fmt, ...)                                                            \
	do {                                                                                  \
		if (LOG_LEVEL > 1) {                                                          \
			if (BLE_DEBUG) {                                                      \
				ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);            \
			} else if (cond) {                                                    \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);                \
			} else {                                                              \
				printk("%s(): " fmt, &__func__[0], ##__VA_ARGS__);            \
			}                                                                     \
		}                                                                             \
	} while (0)

#define GUI_WW_LOG2(cond, ble_cond, fmt, ...)                                                 \
	do {                                                                                  \
		if (LOG_LEVEL > 1) {                                                          \
			if (BLE_DEBUG) {                                                      \
				if (ble_cond) {                                               \
					ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);    \
				} else {                                                      \
					ble_printk("%s(): " fmt, &__func__[0], ##__VA_ARGS__); \
				}                                                             \
			} else if (cond) {                                                    \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);                \
			} else {                                                              \
				printk("%s(): " fmt, &__func__[0], ##__VA_ARGS__);            \
			}                                                                     \
		}                                                                             \
	} while (0)

/* read through a pointer on purpose: the variable is rewritten into SSA only after inlining (late SSA version),
 * which gives the vendor compare operand order (gui_u32_get) and pseudo order / register choice (gui_code_get,
 * gui_int_get: lines gets its loop PHI last, so the zero-init copies come out in the vendor order) */
static inline uint32_t gui_u32_get(const uint32_t *p)
{
	return *p;
}

static inline int gui_int_get(const int *p)
{
	return *p;
}

static inline uint16_t gui_code_get(uint16_t *const *p)
{
	return **p;
}

/* no_draw is unsigned: the zero-init PHI arguments of the unsigned counters (i, line_w) are un-propagated to the
 * no_draw parameter and the int ones (y_off, x_off, lines) to effect, which gives the vendor init/reset copies. */
int gui_utf_Wordwrap_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  uint32_t no_draw)
{
	uint16_t count = 0;
	const uint8_t *data = NULL;
	uint16_t *codes = FUN_0004b160(str, &count);
	int w = 0, h = 0;

	if (effect == 0 && cb == NULL && no_draw == 0) {
		int x_off = 0;
		int y_off = 0;
		uint32_t line_w = 0;
		uint32_t i = 0;
		int lines = 0;
		uint16_t *code = codes;

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}
		int width = x1 - x0;

		for (; (int)i < count; i++, code++) {
			uint8_t glyph[676];
			uint16_t c = gui_code_get(&code);
			int ret = check_printable_code(c);

			if (ret == 0) {
				if (resource_manger_get(font, c, &w, &h, &data, NULL) < 0) {
					GUI_WW_LOG2(line_w & 1, (uint32_t)width > (uint32_t)width / 2, "can not find 0x%x font resource\n", c);
				} else {
					memcpy(glyph, data, h * (w / 2));
					if (dark_cnt != 0 && gui_char_is_dark(&i, dark_cnt)) {
						for (int k = 0; k < h * (w / 2); k++) {
							glyph[k] &= text_grey_level;
						}
					}

					if (line_w > (uint32_t)width / 2 && lines < max_lines - 1) {
						const int total = count;
						const uint16_t split_chars[5] = { ' ', ',', '.', '?', '!' };
						int k;

						for (k = 0; k < 5; k++) {
							if (split_chars[k] == c) {
								break;
							}
						}
						if (k < 5 && c != 0) {
							const uint16_t end_chars[7] = { ' ', ',', '.', '?', '!',
											'\r', '\n' };
							uint32_t start = i + 1;
							uint32_t end;

							/* find the end of the next word */
							int found = 0;
							for (end = start; (int)end < total; end++) {
								for (k = 0; k < 7; k++) {
									if (codes[end] == end_chars[k]) {
										if (codes[end] != 0) {
											found = 1;
										}
										break;
									}
								}
								if (found) {
									break;
								}
							}
							if (found) {
								if ((int)(end - i) > 40) {
									GUI_WW_LOG(x_off & 1, "The word is too long and will not be processed\n");
								} else {
									int wide = 0;

									for (uint32_t n = start; (int)n < (int)end; n++) {
										if (codes[n] > 0x25cc) {
											wide++;
										}
									}
									if (gui_u32_get(&end) == i) {
										GUI_WW_LOG(font & 1, "!!! end_split_character_index == start_split_character_index\n");
									} else if (wide == 0 ||
										   (float)wide / (float)(int)(end - i) < 0.5f) {
										int gw = 0, gh = 0;
										const uint8_t *gdata;
										uint16_t *p = code;
										int len = line_w;

										for (uint32_t n = i; (int)n <= (int)end; n++, p++) {
											if (resource_manger_get(font, *p, &gw, &gh,
														&gdata, NULL) == 0) {
												len += gui_font_kerning(p[0], p[1]) + gw;
											}
											if ((uint32_t)len > (uint32_t)width) {
												ret = 1;
												break;
											}
										}
									}
								}
							}
						}
					}

					line_w += gui_font_kerning(code[0], code[1]) + w;
					if (line_w > (uint32_t)width) {
						y_off += h;
						if (font == 0) {
							y_off++;
						}
						lines++;
						if (gui_int_get(&lines) >= max_lines) {
							break;
						}
						uint32_t y_max = y1 - y0;
						if (y_off >= y_max) {
							break;
						}
						copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0, y0 + y_off);
						x_off = gui_font_kerning(code[0], code[1]) + w;
						line_w = x_off;
					} else {
						copy_to_frame_buffer(frame_buffer, glyph, w / 2, h, x0 + x_off,
								     y0 + y_off);
						x_off += gui_font_kerning(code[0], code[1]) + w;
					}
				}
				if (ret != 1) {
					continue;
				}
			} else if (ret != -1 || (c != '\n' && c != '\r')) {
				continue;
			}
				if (h != 0) {
					y_off += h;
					if (font == 0) {
						y_off++;
					}
				} else {
					if (font != 0) {
						y_off += 26;
					} else {
						y_off += 27;
					}
				}
				lines++;
				if (lines >= max_lines || y_off >= (uint32_t)(y1 - y0)) {
					break;
				}
				line_w = 0;
				x_off = 0;
		}

		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
	} else if (cb != NULL) {
		G1_LOG_WRN("exex process effect callback function\n");
		return cb(0, str, font, x0, y0);
	}
	return 0;
}

int gui_utf_adv_draw_configure(struct gui_utf_adv_cfg cfg)
{
	switch (cfg.cmd) {
	case 8:
		adv_param1 = 0;
		adv_param2 = 0;
		adv_step = 0;
		adv_mode = 0;
		adv_db48 = 0;
		adv_e4 = 0;
		adv_e0 = 0;
		adv_enable = 0;
		adv_d8 = 0;
		adv_db47 = 0;
		break;
	case 4:
		adv_param1 = cfg.param1;
		adv_param2 = cfg.param2;
		adv_step = 0;
		adv_mode = 4;
		adv_db48 = 0;
		adv_e4 = 0;
		adv_e0 = 0;
		adv_enable = 1;
		break;
	case 5:
		adv_param1 = 0;
		adv_param2 = 0;
		adv_step = 3;
		adv_mode = 5;
		adv_db48 = 0;
		adv_e4 = 0;
		adv_d8 = 0;
		adv_e0 = 0;
		adv_enable = 1;
		break;
	case 6:
		adv_step = 2;
		adv_mode = 6;
		adv_db48 = 0;
		adv_e4 = 0;
		adv_d8 = 0;
		adv_e0 = 0;
		adv_enable = 1;
		break;
	default:
		G1_LOG_ERR("unkonown adv command\n");
		break;
	}
	return -1;
}

/* ---------------------------------------------------------------------------
 * small helpers (align-2 region)
 */
int thunk_FUN_00045444(void)
{
	return gui_dynamic_bitmap_reset();
}

int64_t abs_diff_u64(int64_t a, int64_t b)
{
	if (a >= b) {
		return a - b;
	}
	return b - a;
}

int gui_utf_adv_draw_reset(void)
{
	struct gui_utf_adv_cfg cfg;

	cfg.cmd = 8;
	return gui_utf_adv_draw_configure(cfg);
}

/* horizontal text origin: the stored x shift (display depth setting, 22..42) plus the panel's per-eye offset */
int gui_screen_x_offset(void)
{
	if ((GUI_STATE()->text_y_108a == 0 && GUI_STATE()->font_size_108c == 0) ||
	    GUI_STATE()->text_y_108a > 64) {
		GUI_STATE()->text_y_108a = 32;
	}
	return GUI_STATE()->text_y_108a + GUI_STATE()->panel.y_offset;
}

/* vertical text origin (display height setting, clamped to 4..64) */
int gui_screen_y_offset(void)
{
	if ((GUI_STATE()->text_y_108a == 0 && GUI_STATE()->font_size_108c == 0) ||
	    GUI_STATE()->font_size_108c > 64) {
		GUI_STATE()->font_size_108c = 32;
	}
	if (GUI_STATE()->font_size_108c < 4) {
		GUI_STATE()->font_size_108c = 4;
	}
	return GUI_STATE()->font_size_108c;
}
/* old names, still used by notify (ui_notification.c) */
extern __typeof__(gui_screen_x_offset) FUN_000809e2 __attribute__((alias("gui_screen_x_offset")));
extern __typeof__(gui_screen_y_offset) FUN_00080a3a __attribute__((alias("gui_screen_y_offset")));

int gui_utf_draw_scroll_line(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		  uint32_t max_lines, uint32_t dark_cnt)
{
	if (gui_screen_y_offset() <= 32) {
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0 + 27, x1, y1 + 27);
		}
		clear_showing_notification_on_gui();
		gui_utf_draw(0, str, 0, x0, y0 + 27, x1, y1 + 27, max_lines, dark_cnt, 0, NULL, 0);
		set_showing_notification_on_gui();
		for (int i = 0; i < 9; i++) {
			const int offs[9] = { 3, 6, 9, 12, 15, 18, 21, 24, 27 };

			_reflash_fb_data_to_lcd_ex(GUI_STATE()->panel.current_row,
						   GUI_STATE()->panel.current_column, x0, y0, x1, y1,
						   offs[i]);
		}
		copy_frame_buffer_rows((int)frame_buffer, x0, y0, x0, y0 + 27, 27, x1 - x0);
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y1, x1, y1 + 27);
		}
	} else if (gui_screen_y_offset() > 32) {
		copy_frame_buffer_rows((int)frame_buffer, x0, y0 - 27, x0, y0, 27, x1 - x0);
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}
		clear_showing_notification_on_gui();
		gui_utf_draw(0, str, 0, x0, y0, x1, y1, max_lines, dark_cnt, 0, NULL, 0);
		set_showing_notification_on_gui();
		for (int i = 0; i < 9; i++) {
			const int offs[9] = { -27, -21, -18, -15, -12, -9, -6, -3, 0 };

			_reflash_fb_data_to_lcd_ex(GUI_STATE()->panel.current_row,
						   GUI_STATE()->panel.current_column, x0, y0, x1, y1,
						   offs[i]);
		}
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0 - 27, x1, y0);
		}
	}
}

int gui_clock_draw(uint32_t ts, int x0, int y0, int x1, int y1, int mode,
		   bool is_24h)
{
	struct bp_date date = { 0 };
	size_t len;
	const uint8_t *data;
	int w, h;
	int x;

	init_burial_point_date(ts, &date);
	char buf[16] = { 0 };

	if (is_24h) {
		sprintf(buf, "%d%d%s%d%d", date.hour / 10, date.hour % 10, ":", date.minute / 10,
			date.minute % 10);
	} else {
		if (date.hour > 12) {
			date.hour -= 12;
		} else if (date.hour == 0) {
			date.hour = 12;
		}
		sprintf(buf, "%d%d%s%d%d", date.hour / 10, date.hour % 10, ":", date.minute / 10,
			date.minute % 10);
	}
	len = strlen(buf);

	switch (mode) {
	case 0:
		gui_utf_draw(0, buf, 0, x0, y0, x1, y1, 1, 0, 0, NULL, 0);
		break;
	case 3:
		gui_utf_draw(0, buf, 3, x0, y0, x1, y1, 1, 0, 0, NULL, 0);
		break;
	case 1:
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}
		x = x0;
		for (int i = 0; i < len; i++) {
			/*
			 * A compile-time constant condition in the vendor source (probably a
			 * config switch): a plain block gives different block layout.
			 */
			if (1) {
				data = NULL;
				if (resource_manger_get(1, (uint8_t)buf[i], &w, &h, &data, NULL) != 0 ||
				    data == NULL) {
					G1_LOG_WRN("The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n",
						   (uint8_t)buf[i], "EVEN_DASHBOARD_CLOCK_32x_TTF");
				} else {
					copy_to_frame_buffer(frame_buffer, data, w / 2, h, x, y0);
					x += w + 6;
				}
			}
		}
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
		break;
	case 2:
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
		}
		x = x0;
		for (int i = 0; i < len; i++) {
			data = NULL;
			if (resource_manger_get(2, (uint8_t)buf[i], &w, &h, &data, NULL) != 0 ||
			    data == NULL) {
				G1_LOG_WRN("The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n",
					   (uint8_t)buf[i], "EVEN_DASHBOARD_CLOCK_32x_TTF");
			} else {
				copy_to_frame_buffer(frame_buffer, data, w / 2, h, x, y0);
				if (buf[i + 1] != ':') {
					x += w + 2;
				} else {
					x += w + 7;
				}
				if (buf[i] == ':') {
					x += 7;
				}
			}
		}
		if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
			_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
						GUI_STATE()->panel.current_column, x0, y0, x1, y1);
		}
		break;
	default:
		break;
	}
	return 0;
}

int gui_screen_fade_out(void)
{
	for (int step = 0; step < 8; step++) {
		for (int row = 0; row < 199; row++) {
			for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
				if (frame_buffer[row][col] != 0) {
					frame_buffer[row][col] &= gui_fade_mask[row % 26][7 - step][col];
				}
			}
		}
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, 0, 0, GUI_SCREEN_WIDTH, 199);
		k_busy_wait(5000);
	}
	gui_screen_clear();
	return 0;
}

int hide_icon_notification_on_gui(void)
{
	for (int step = 0; step < 8; step++) {
		for (int row = 0; row < 199; row++) {
			for (int col = 0; col < GUI_FB_ROW_BYTES; col++) {
				if (frame_buffer[row][col] != 0) {
					frame_buffer[row][col] &= gui_fade_mask[row % 26][7 - step][col];
				}
			}
		}
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, 0, 0, GUI_SCREEN_WIDTH, 199);
	}
	gui_screen_clear();
	return 0;
}

int gui_verticalLine_process_bar(int x0, int y0, int x1, int y1, int reserved, uint8_t percent,
				 int unused)
{
	uint8_t color;
	uint32_t pct;
	int col;
	uint8_t **fb;

	if (x0 != x1 || y0 > y1) {
		G1_LOG_WRN("input param error,please check postion content\n");
		return -1;
	}

	color = (x0 & 1) ? 0x0f : 0xf0;
	pct = percent;
	if (pct > 100) {
		pct = 100;
	}
	col = x0 / 2;

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x0 - 6, y0, x0 + 6, y1);
	}
	fb = frame_buffer;
	for (int i = 0; i < y1 - y0; i++) {
		fb[y0 + i][col] = color;
	}
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0 - 6, y0, x1 + 6, y1);
	}
	gui_bmp_bitmap_draw(0x17, x0 - 4, (int)(pct * (y1 - y0 - 13)) / 100 + y0, 0, 0, 0);
	return 0;
}

/* pix is read through its address on purpose: it keeps the vendor register allocation */
static inline uint8_t gui_bar_px(const uint8_t *p)
{
	return *p;
}

int gui_horizontal_percentage_bar(int x0, int y0, int x1, int y1, uint8_t segments, uint8_t gap,
				  uint8_t percent)
{
	int width, bar_width, fill;
	uint32_t seg_num, pct;
	uint8_t pix;
	int x;
	int seg_len, seg, seg_w, col0;
	int col;
	uintptr_t fbi;

	if (x0 > x1 || y0 > y1) {
		G1_LOG_WRN("input param error,please check postion content\n");
		return -1;
	}

	seg_num = segments;
	pct = percent;
	if (seg_num == 0) {
		seg_num = 1;
	}
	if (pct > 100) {
		pct = 100;
	}
	bar_width = x1 - x0 - gap * (int)(seg_num - 1);
	width = x1 - x0;
	seg_w = bar_width / (int)seg_num;
	fill = (int)(bar_width * pct) / 100;
	col0 = x0 / 2;

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
	}

	pix = 0;
	seg = 0;
	seg_len = 0;
	for (x = 0; x < width; x++, seg_len++) {
		if (seg_len >= seg_w) {
			seg++;
			if (seg >= (int)seg_num) {
				break;
			}
			x += gap;
			if (x > width) {
				break;
			}
			seg_len = 0;
		}
		/* column and row base are named per column (col via an unsigned sum, the row base as an
		 * integer): this keeps the vendor spill-slot order (col [sp,#12], row base [sp,#16]) */
		col = (int)((unsigned int)col0 + (x >> 1));
		fbi = (uintptr_t)(frame_buffer + y0);
		if (fill != 0) {
			for (int r = 0; r < y1 - y0; r++) {
				if ((x & 1) == 0) {
					pix = 0xf0;
				} else {
					pix |= 0x0f;
				}
				if (((x + 1) & 1) == 0) {
					((uint8_t **)fbi)[r][col] = gui_bar_px(&pix);
				}
			}
		} else {
			for (int r = 0; r < y1 - y0; r++) {
				if ((x & 1) == 0) {
					pix = text_grey_level & 0xf0;
				} else {
					pix |= text_grey_level & 0x0f;
				}
				if (((x + 1) & 1) == 0) {
					((uint8_t **)fbi)[r][col] = gui_bar_px(&pix);
				}
			}
		}
		if (fill > 0) {
			fill--;
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0, y0, x1, y1);
	}
	return 0;
}


int gui_bitmap_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color)
{
	uint8_t **fb;
	uint32_t n;

	if (x0 > x1 || y0 > y1 || color > 0x0f) {
		G1_LOG_WRN("input param error,please check postion content\n");
		return -1;
	}
	if (x0 & 1) {
		G1_LOG_WRN("Scenarios where the starting point of x is an even number are not currently supported.\n");
		return -1;
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x0 - 2, y0, x1 + 2, y1);
	}

	int x_byte = x0 / 2;

	fb = frame_buffer;
	/* bytes per bitmap row; the unsigned difference hides x0 <= x1 from VRP, so GCC keeps the
	 * row step as max(n, 0) like the target (bic fp, fp, asr #31) */
	n = (int)((uint32_t)x1 - (uint32_t)x0) >> 3;
	int k = 0;
	for (int r = 0; r < y1 - y0; r++) {
		for (int i = 0; i < (int)n; i++) {
			uint8_t bits = bmp[k++];
			uint32_t pix = 0;
			uint8_t out[4] = { 0 };

			for (int b = 0; b < 8; b++) {
				if ((bits >> b) & 1) {
					if (b & 1) {
						pix |= color;
					} else {
						pix |= (uint8_t)(color << 4);
					}
				}
				if (((b + 1) & 1) == 0) {
					out[b >> 1] = pix;
					pix = 0;
				}
			}
			*(uint32_t *)&fb[y0 + r][x_byte + i * 4] = *(uint32_t *)out;
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0 - 2, y0, x1 + 2, y1);
	}
	return 0;
}

int gui_bitmps_merge_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp1, const uint8_t *bmp2,
			  uint8_t color1, uint8_t color2)
{
	uint8_t **fb;
	uint32_t n;

	if (x0 > x1 || y0 > y1 || (color1 | color2) > 0x0f) {
		G1_LOG_WRN("input param error,please check postion content\n");
		return -1;
	}
	if (x0 & 1) {
		G1_LOG_WRN("Scenarios where the starting point of x is an even number are not currently supported.\n");
		return -1;
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
	}

	int x_byte = x0 / 2;

	fb = frame_buffer;
	n = (int)((uint32_t)x1 - (uint32_t)x0) >> 3;
	int k = 0;
	for (int r = 0; r < y1 - y0; r++) {
		for (int i = 0; i < (int)n; i++) {
			uint8_t bits1 = bmp1[k];
			uint8_t bits2 = bmp2[k];
			k++;
			uint8_t pix = 0;
			uint8_t out[4] = { 0 };

			for (int b = 0; b < 8; b++) {
				if ((bits1 >> b) & 1) {
					if (b & 1) {
						pix |= color1;
					} else {
						pix |= (uint8_t)(color1 << 4);
					}
				}
				if ((bits2 >> b) & 1) {
					if (b & 1) {
						pix |= color2;
					} else {
						pix |= (uint8_t)(color2 << 4);
					}
				}
				if (((b + 1) & 1) == 0) {
					out[b >> 1] = pix;
					pix = 0;
				}
			}
			*(uint32_t *)&fb[y0 + r][x_byte + i * 4] = *(uint32_t *)out;
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0, y0, x1, y1);
	}
	return 0;
}

int gui_1bit_bitmap_override(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color)
{
	uint8_t **fb;
	uint32_t n;

	if (x0 > x1 || y0 > y1 || color > 0x0f) {
		G1_LOG_WRN("input param error,please check postion content\n");
		return -1;
	}
	if (x0 & 1) {
		G1_LOG_WRN("Scenarios where the starting point of x is an even number are not currently supported.\n");
		return -1;
	}

	int x_byte = x0 / 2;

	fb = frame_buffer;
	n = (int)((uint32_t)x1 - (uint32_t)x0) >> 3;
	int k = 0;
	for (int r = 0; r < y1 - y0; r++) {
		for (int i = 0; i < (int)n; i++) {
			uint8_t bits = bmp[k++];
			uint8_t pix = 0;
			uint8_t out[4] = { 0 };

			for (int b = 0; b < 8; b++) {
				if ((bits >> b) & 1) {
					if (b & 1) {
						pix |= color;
					} else {
						pix |= (uint8_t)(color << 4);
					}
				}
				if (((b + 1) & 1) == 0) {
					out[b >> 1] = pix;
					pix = 0;
				}
			}
			for (int j = 0; j < 4; j++) {
				fb[y0 + r][x_byte + i * 4 + j] |= out[j];
			}
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0 - 2, y0, x1 + 2, y1);
	}
	return 0;
}

int gui_4bit_bitmap_override(int id, uint32_t x, uint32_t y)
{
	int w = 0, h = 0;
	const uint8_t *data = NULL;

	if (x > 640 || y > 480) {
		G1_LOG_ERR("gui_4bit_bitmap_override parampter overstep!!! stop draw bitmap !!! x= %d,y= %d\n",
			   x, y);
		return -1;
	}
	if (resource_manger_get(4, id, &w, &h, &data, NULL) < 0) {
		G1_LOG_WRN("can't find resource,please check resource name !\n");
		return -1;
	}

	or_to_frame_buffer((int)frame_buffer, (int)data, w, h, x, y);
	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x, y, w + x, h + y);
	}
	return 0;
}

int gui_font_kerning(uint16_t cur, uint16_t next)
{
	int n = 0;

	for (int i = 0; i < font26_glyph_count; i++) {
		if (font26_index[i].code == cur) {
			n++;
		}
		if (font26_index[i].code == next) {
			n++;
		}
	}
	if (n >= 2) {
		n = 2;
	}
	return n;
}

int gui_string_draw(int font, const char *str, int x0, int y0, int x1, int y1, int *out_w)
{
	int w = 0, h = 0;
	const uint8_t *data = NULL;
	size_t len = strlen(str);
	int x;

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_clean_fb_data(frame_buffer, 0, x0, y0, x1, y1);
	}

	x = x0;
	for (size_t i = 0; i < len; i++) {
		if ((uint8_t)str[0] >= 0x20) {
			int ret = resource_manger_get(font, (uint8_t)str[i], &w, &h, &data, NULL);

			if (data == NULL || ret != 0) {
				G1_LOG_WRN("find ascii postion failed\n");
			} else {
				copy_to_frame_buffer(frame_buffer, data, w / 2, h, x, y0);
				if ((uint8_t)str[i] - 0x20U < 0x5f && font == 3) {
					x = x + w + 3;
				} else {
					x += w;
					x += gui_font_kerning((uint8_t)str[i], (uint8_t)str[i + 1]);
				}
			}
		} else {
			G1_LOG_ERR("non-ascii characters\n");
		}
	}

	if (gui_flags_get() & GUI_FLAG_NOTIFICATION_SHOWING) {
		_reflash_fb_data_to_lcd(GUI_STATE()->panel.current_row,
					GUI_STATE()->panel.current_column, x0, y0, x1, y1);
	}
	if (out_w != NULL) {
		*out_w = x - x0;
	}
	return 0;
}

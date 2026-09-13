/*
 * GUI drawing layer (frame buffer, bitmaps, UTF-8 text) - module private header.
 */
#ifndef G1_GUI_H_
#define G1_GUI_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/atomic.h>
#include <g1_log.h>
#include <g1_date.h>
#include <glasses_state.h>

#define GUI_SCREEN_WIDTH   640
#define GUI_SCREEN_HEIGHT  200
#define GUI_FB_ROWS        200          /* 4 bpp, 320 bytes per row */
#define GUI_FB_ROW_BYTES   320

typedef int (*gui_effect_cb_t)(int arg, const char *str, int font, int x, int y);

/* gui_flags bits */
#define GUI_FLAG_NOTIFICATION_SHOWING BIT(1)

/*
 * Text animation state of the Even AI / translate pages (.bss 0x2000aa18,
 * 0x20 bytes) and its 0x80 byte text buffer (0x2001db49).  Only
 * ui_even_ai.c / ui_translate.c use them; defined in gui.c (first variables
 * of the file: highest addresses of gui.c's .bss groups).
 */
struct gui_text_anim {
	const uint8_t *text;             /* 0x00 */
	uint32_t f_04;
	uint32_t f_08;
	uint32_t f_0c;
	uint32_t f_10;
	uint32_t f_14;
	uint32_t f_18;
	uint32_t buf_size;
};

struct gui_utf_adv_cfg {
	int cmd;
	int param1;
	int param2;
};

/* gui.c (frame_buffer is static there) */
extern struct gui_text_anim text_anim;
extern uint8_t text_anim_buf[0x80];
extern volatile uint8_t text_grey_level;   /* text grey level (.data 0x20003698 = 0x55) */
extern atomic_t gui_flags;               /* 0x2000aa10, GUI_FLAG_* */
extern const uint8_t gui_fade_mask[26][8][GUI_FB_ROW_BYTES]; /* gui_fade_mask.h */
atomic_val_t gui_flags_get(void);
int set_frame_buffer(uint8_t **fb);
int gui_screen_clear(void);
int gui_area_clear(int x_start, int y_start, int x_end, int y_end);
int set_showing_notification_on_gui(void);
int clear_showing_notification_on_gui(void);
int gui_dynamic_bitmap_reset(void);
int gui_icon_area_clear(int x, int y);
int gui_bmp_dynamic_bitmap_draw(int id, int x, int y, int a, int b, int c, uint8_t loop);
int gui_bmp_bitmap_draw(int id, int x, int y, int effect, gui_effect_cb_t cb, int no_draw);
int gui_bmp_bitmap_draw_ex(int id, int x, int y, uint8_t *buf, uint8_t level);
int gui_text_state_reset(void);
int gui_utf_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		 uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb, int no_draw);
int gui_utf_draw_dark_light_split(int arg, const char *str, int font, int x0, int y0, int x1,
				  int y1, uint32_t max_lines, uint16_t split_code, int effect,
				  gui_effect_cb_t cb, int no_draw);
int gui_utf_draw_truncate(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  int no_draw);
int gui_utf_draw_darkword_by_lines(int arg, const char *str, int font, int x0, int y0, int x1,
				   int y1, uint32_t max_lines, uint8_t dark_lines, int effect,
				   gui_effect_cb_t cb, int no_draw);
int gui_utf_draw_middle(int arg, const char *str, int font, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
			uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			int no_draw);
int gui_utf_draw_align_right(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			     uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			     int no_draw);
int gui_utf_Wordwrap_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  uint32_t no_draw);
int gui_utf_adv_draw_configure(struct gui_utf_adv_cfg cfg);
int gui_dynamic_bitmap_reset_thunk(void);
int64_t abs_diff_u64(int64_t a, int64_t b);
int gui_utf_adv_draw_reset(void);
#ifdef GUI_C_INTERNAL
int gui_screen_x_offset(void);          /* gui.c: the definition returns int */
#else
uint16_t gui_screen_x_offset(void);     /* the vendor prototype says uint16_t (call sites differ) */
#endif
int gui_screen_y_offset(void);
int gui_utf_draw_scroll_line(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			     uint32_t max_lines, uint32_t dark_cnt);
int gui_clock_draw(uint32_t ts, int x0, int y0, int x1, int y1, int mode,
		   bool is_24h);
int gui_screen_fade_out(void);
int hide_icon_notification_on_gui(void);
/* callers pass a 7th argument (0), so the definition takes it too */
int gui_verticalLine_process_bar(int x0, int y0, int x1, int y1, int reserved, uint8_t percent,
				 int unused);
int gui_horizontal_percentage_bar(int x0, int y0, int x1, int y1, uint8_t segments, uint8_t gap,
				  uint8_t percent);
int gui_bitmap_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color);
int gui_bitmps_merge_draw(int x0, int y0, int x1, int y1, const uint8_t *bmp1, const uint8_t *bmp2,
			  uint8_t color1, uint8_t color2);
int gui_1bit_bitmap_override(int x0, int y0, int x1, int y1, const uint8_t *bmp, uint8_t color);
int gui_4bit_bitmap_override(int id, uint32_t x, uint32_t y);
int gui_string_draw(int font, const char *str, int x0, int y0, int x1, int y1, int *out_w);

/* gui_strings.c */
const char *get_string_in_language(int language, uint32_t string_id);
const char *get_string(uint8_t string_id);

/* resource_manager.c */
const uint8_t *font39_lookup(uint16_t code, int *w, int *h);
const uint8_t *font_c_lookup(uint16_t code, int *w, int *h);
const uint8_t *font_b_lookup(uint16_t code, int *w, int *h);
const uint8_t *font26_lookup(uint16_t code, int *w, int *h);
int resource_manger_get(int type, int id, int *w, int *h, const uint8_t **data, uint8_t *frames);
int weather_icon_to_bitmap(int weather); /* weather icon -> bitmap id */

/* ui_set_imu_pitch.c */
int ui_set_imu_pitch_task(struct jbd_panel_context *ctx, void *arg, int event);

/* ui_prompt_info.c */
int ui_prompt_info_task(struct jbd_panel_context *ctx, void *arg, int event);

/* ui_transcribe_info.c */
void transcribe_info_timeout_reset(void);
int ui_transcribe_info_task(struct jbd_panel_context *ctx, void *arg, int event);

/* ui_even_ai_v2_info.c */
void even_ai_v2_info_timeout_reset(void);
int ui_even_ai_v2_info_task(struct jbd_panel_context *ctx, void *arg, int event);

/* fonts/gui_fonts.c */
struct font_glyph_idx {
	uint16_t code;
	uint8_t width;      /* in bytes (2 pixels per byte) */
	uint8_t pad;
};
extern const int font26_glyph_count;            /* 0x8e7b8 */
extern const int font_b_glyph_count;            /* 0x8e7bc */
extern const int font_c_glyph_count;            /* 0x8e7c0 */
extern const int font39_glyph_count;            /* 0x8e7c4 */
extern const struct font_glyph_idx font26_index[];   /* 0x9c4ec */
extern const struct font_glyph_idx font_b_index[];   /* 0x9cbe0 */
extern const struct font_glyph_idx font_c_index[];   /* 0x9cd64 */
extern const struct font_glyph_idx font39_index[];   /* 0x9cd90 */
extern const uint8_t font26_bitmap[];           /* 0xe092e */
extern const uint8_t font_b_bitmap[];           /* 0xdc124 */
extern const uint8_t font_c_bitmap[];           /* 0xdedd4 */
extern const uint8_t font39_bitmap[];           /* 0xdfc14 */

#endif /* G1_GUI_H_ */

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

#define GUI_SCREEN_WIDTH   640
#define GUI_SCREEN_HEIGHT  200
#define GUI_FB_ROWS        200          /* 4 bpp, 320 bytes per row */
#define GUI_FB_ROW_BYTES   320

typedef int (*gui_effect_cb_t)(int arg, const char *str, int font, int x, int y);

/* gui_flags bits */
#define GUI_FLAG_NOTIFICATION_SHOWING BIT(1)

/*
 * Partial view of the JBD panel context (owned by the panel driver;
 * GlassesState + 0xb6c).  Offsets established from the code.
 */
struct jbd_panel_context {
	void *cb[9];                     /* 0x000 init/suspend/resume/off/on/?/draw/clear/brightness */
	uint8_t *panel_buffer[GUI_FB_ROWS]; /* 0x024 frame buffer row pointers */
	uint8_t *current_buffer;         /* 0x344 */
	uint32_t current_row;            /* 0x348 */
	uint32_t current_column;         /* 0x34c */
	uint32_t current_buffer_size;    /* 0x350 */
	uint8_t raster_height_offset;    /* 0x354 */
	uint8_t brightness;              /* 0x355 brightness level 0..9 */
	uint8_t pad_356[0x358 - 0x356];
	uint32_t y_offset;               /* 0x358 (GlassesState + 0xec4) */
	uint32_t init_done;              /* 0x35c */
};

/* partial view of struct dashboard_ts_context (dashboard module) */
struct gui_dashboard_ts {
	uint8_t pad_00[0x5e];
	uint8_t time_disp_mode;          /* 0x5e: 1 = 12h */
};

/* GlassesState + 0x1028 points to this (packed) block */
struct gui_ts_info {
	uint16_t f0;
	int64_t enter_ts;                /* 0x02 k_uptime_get() when a page was entered */
} __packed;

/* Partial view of the global vendor state (struct GlassesState, main.h). */
struct gui_glasses_state {
	uint8_t is_master;               /* 0x000 */
	uint8_t pad_001[0xcb - 1];
	uint8_t level_0cb;               /* 0x0cb (esb_arg2): even-AI v2 volume level, 0..42 */
	uint8_t pad_0cc[0xf0 - 0xcc];
	uint8_t ui_action;               /* 0x0f0 page action / step */
	uint8_t show_clock;              /* 0x0f1 */
	uint8_t ui_status;               /* 0x0f2 page sub-state (even_ai_v2) */
	uint8_t page_flags;              /* 0x0f3 bit0: show the animated icon */
	uint8_t dark_cnt;                /* 0x0f4 */
	uint8_t pad_0f5[2];
	char text[1];                    /* 0x0f7 page text (length unknown) */
	uint8_t pad_0f8[0xff - 0xf8];
	char ai_text[1];                 /* 0x0ff even_ai_v2 page text (length unknown) */
	uint8_t pad_100[0xb6c - 0x100];
	struct jbd_panel_context panel;  /* 0xb6c */
	uint8_t pad_ecc[0xff0 - 0xb6c - sizeof(struct jbd_panel_context)];
	struct gui_dashboard_ts *dashboard_ts; /* 0xff0 */
	uint8_t pad_ff4[0x1014 - 0xff4];
	uint8_t *even_ai_state;          /* 0x1014 */
	uint8_t pad_1018[0x1028 - 0x1018];
	struct gui_ts_info *ts_info;     /* 0x1028 */
	uint8_t *multi_packet_buf;       /* 0x102c */
	uint8_t pad_1030[0x1044 - 0x1030];
	int (*flash_read)(void *gs, uint32_t addr, void *buf, uint32_t len); /* 0x1044 */
	uint8_t pad_1048[0x108a - 0x1048];
	uint16_t text_y_108a;            /* 0x108a */
	uint16_t font_size_108c;         /* 0x108c */
	uint8_t pad_108e[0x1247 - 0x108e];
	uint8_t f_1247;                  /* 0x1247 */
} __aligned(8);

struct GlassesState;
struct GlassesState *get_dashboard_state(void);
#define GUI_STATE() ((struct gui_glasses_state *)get_dashboard_state())

/* panel driver */
struct jbd_panel_context *get_jdb_panel_context(void);
int _clean_fb_data(uint8_t **fb, int val, int x_start, int y_start, int x_end, int y_end);
int _reflash_fb_data_to_lcd(uint32_t row, uint32_t column, int x_start, int y_start,
			    int x_end, int y_end);
int _reflash_fb_data_to_lcd_ex(uint32_t row, uint32_t column, int x_start, int y_start,
			       int x_end, int y_end, int offset);
int copy_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w_bytes, int h, int x, int y);
void jbd_clear_cache_sync(int val);
void or_to_frame_buffer(int a, int b, int c, int d, int e, int f);
void copy_frame_buffer_rows(int a, int b, int c, int d, int e, int f, int g);
const uint8_t *FUN_0004b2d4(int glyph, int size);
uint16_t *FUN_0004b160(const char *utf8, uint16_t *count);
int check_printable_code(uint32_t code);

extern volatile uint8_t text_grey_level;   /* text grey level (.data 0x20003698 = 0x55, gui.c) */
extern atomic_t gui_flags;               /* 0x2000aa10, GUI_FLAG_* (gui.c) */

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
	uint32_t f_1c;
};
extern struct gui_text_anim text_anim;
extern uint8_t text_anim_buf[0x80];

/* fonts (gui_fonts.c) */
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

void FUN_00030458(void);
int gui_clock_draw(uint32_t ts, int x0, int y0, int x1, int y1, int mode,
		   bool is_24h);
int gui_bmp_dynamic_bitmap_draw(int id, int x, int y, int a, int b, int c, uint8_t loop);
int gui_bmp_bitmap_draw(int id, int x, int y, int effect, gui_effect_cb_t cb, int no_draw);
int gui_utf_draw_darkword_by_lines(int arg, const char *str, int font, int x0, int y0, int x1,
				   int y1, uint32_t max_lines, uint8_t dark_lines, int effect,
				   gui_effect_cb_t cb, int no_draw);



/* gui.c */
/* callers pass a 7th argument (0), so the definition takes it too */
int gui_verticalLine_process_bar(int x0, int y0, int x1, int y1, int reserved, uint8_t percent,
				 int unused);
/* frame_buffer is static in gui.c */
extern const uint8_t gui_fade_mask[26][8][GUI_FB_ROW_BYTES];
int gui_screen_fade_out(void);
int gui_utf_draw_middle(int arg, const char *str, int font, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
			uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			int no_draw);
atomic_val_t gui_flags_get(void);
int set_frame_buffer(uint8_t **fb);
int gui_screen_clear(void);
int gui_area_clear(int x_start, int y_start, int x_end, int y_end);
int set_showing_notification_on_gui(void);
int clear_showing_notification_on_gui(void);
int gui_dynamic_bitmap_reset(void);
int gui_icon_area_clear(int x, int y);

struct gui_utf_adv_cfg {
	int cmd;
	int param1;
	int param2;
};
int gui_utf_adv_draw_configure(struct gui_utf_adv_cfg cfg);
int gui_text_state_reset(void);

int gui_screen_y_offset(void);
#ifdef GUI_C_INTERNAL
int gui_screen_x_offset(void);          /* gui.c: the definition returns int */
#else
uint16_t gui_screen_x_offset(void);     /* UI pages: the vendor prototype says uint16_t (call sites differ) */
#endif
int gui_utf_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		 uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb, int no_draw);

uint8_t get_current_language(void);
const char *get_string_in_language(int language, uint32_t string_id);
const char *get_string(uint8_t string_id);
int64_t abs_diff_u64(int64_t a, int64_t b);
int gui_utf_adv_draw_reset(void);
int thunk_FUN_00045444(void);

const uint8_t *font_c_lookup(uint16_t code, int *w, int *h);
const uint8_t *font39_lookup(uint16_t code, int *w, int *h);
const uint8_t *font_b_lookup(uint16_t code, int *w, int *h);
const uint8_t *font26_lookup(uint16_t code, int *w, int *h);
int resource_manger_get(int type, int id, int *w, int *h, const uint8_t **data, uint8_t *frames);

#endif /* G1_GUI_H_ */

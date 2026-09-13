/* Private declarations of font_bitmap.c (panel_display module) */
#ifndef PD_FONT_BITMAP_H_
#define PD_FONT_BITMAP_H_

#include <stdint.h>
#include <glasses_state.h>


uint16_t utf8_decode_char(const uint8_t *s, int len);
int utf8_to_unicode(const char *utf8, int len, uint16_t *out, int max);
uint16_t *utf8_to_unicode_buf(const char *utf8, uint16_t *count);
void expand_1bpp_to_4bpp(const uint8_t *src, int len, uint8_t *dst);
const uint8_t *get_small_glyph_bitmap(int glyph, int size);
const uint8_t *get_demo_picture(int id, int *w, int *h);
void free_demo_line_buf(void);
const uint8_t *find_chinese_bitmap_by_unicode(int code, int w, int h);
const uint8_t *font_ascii_lookup(uint8_t c, int size);
const uint8_t *font_ascii_get_glyph(uint16_t digit, int w, int h, int arg);
int check_printable_code(uint32_t code);

/* font_bitmap_data.inc: 6x5 pixel markers of the demo position page (4 bpp) */
extern const uint8_t demo_mark_left[15];
extern const uint8_t demo_mark_right[15];

#endif

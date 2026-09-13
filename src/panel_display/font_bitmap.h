/* Private declarations of font_bitmap.c (panel_display module) */
#ifndef PD_FONT_BITMAP_H_
#define PD_FONT_BITMAP_H_

#include <stdint.h>

struct GlassesState;
struct GlassesState *get_dashboard_state(void);

/* partial view of GlassesState */
struct font_gs {
	uint8_t pad_000[0x1044];
	int (*flash_read)(struct GlassesState *gs, uint32_t addr, void *buf, uint32_t len); /* 0x1044 */
} __attribute__((aligned(8)));
#define FONT_GS() ((struct font_gs *)get_dashboard_state())

uint16_t utf8_decode_char(const uint8_t *s, int len);
int utf8_to_unicode(const char *utf8, int len, uint16_t *out, int max);
uint16_t *FUN_0004b160(const char *utf8, uint16_t *count);
void expand_1bpp_to_4bpp(const uint8_t *src, int len, uint8_t *dst);
const uint8_t *FUN_0004b2d4(int glyph, int size);
const uint8_t *FUN_0004b30c(int id, int *w, int *h);
void FUN_0004b340(void);
const uint8_t *find_chinese_bitmap_by_unicode(int code, int w, int h);
const uint8_t *font_ascii_lookup(uint8_t c, int size);
const uint8_t *FUN_00080fa2(uint16_t digit, int w, int h, int arg);
int check_printable_code(uint32_t code);

extern uint8_t demo_mode;
extern uint8_t *line_buf;

#endif

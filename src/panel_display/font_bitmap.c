/*
 * Font bitmap helpers: UTF-8 string -> unicode buffer, 1 bpp -> 4 bpp glyph
 * expansion, CJK glyph lookup in the external flash font area.
 * Reconstructed from the v1.63 app core.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "font_bitmap.h"

/* glyph index entry in the external flash (0x140000 + (code - 0xa4) * 4) */
struct cjk_glyph_index {
	uint16_t unicode;
	uint16_t offset;
};

/* every source byte (8 pixels, 1 bpp) maps to 4 bytes (8 pixels, 4 bpp) */
#include "font_bitmap_data.inc"
#include "font_1bpp_to_4bpp.inc"

/* 0x8e7b0: picture table of FUN_0004b30c */
static const uint8_t *const font_picture_table[2] = {demo_mark_right, NULL};

static uint8_t small_glyph_buf[0x120];        /* 0x2001deb6 */
static uint8_t cjk_glyph_buf[0x1b0];          /* 0x2001dd06 */
static uint16_t unicode_buf[0x400];           /* 0x200100f2 */

/* decode one 2 or 3 byte UTF-8 sequence into a unicode code point */
uint16_t utf8_decode_char(const uint8_t *s, int len)
{
	uint8_t c = s[0];
	uint8_t hi, lo;
	uint8_t top2, top4;

	if ((c & 0xf0) == 0xe0) {
		if (len < 3) {
			return 0;
		}
		top2 = s[1] & 0x03;
		top4 = c & 0x0f;
		lo = (((s[2] >> 4) & 0x03) << 4) | (top2 << 6) | (s[2] & 0x0f);
		hi = ((s[1] >> 2) & 0x0f) | (top4 << 4);
	} else if ((c & 0xe0) == 0xc0) {
		if (len < 2) {
			printf("length error!\n");
			return 0;
		}
		top2 = c & 0x03;
		lo = (s[1] & 0x3f) | (top2 << 6);
		hi = (c & 0x1f) >> 2;
	} else {
		printf("maybe [%x] not unicode ?\n", c);
		return 0;
	}
	return lo | (hi << 8);
}

/* UTF-8 string -> unicode array (ASCII, CR/LF, 2 and 3 byte sequences) */
int utf8_to_unicode(const char *utf8, int len, uint16_t *out, int max)
{
	int k = 0;
	int i = 0;

	while (i < len) {
		uint16_t *o = &out[k];
		uint8_t c = utf8[i];
		uint16_t u;

		if (c == 0) {
			break;
		}
		if (c == '\r' || c == '\n') {
			u = c;
			i++;
		} else if (c >= 0x20 && c < 0x80) {
			u = c;
			i++;
		} else if ((c & 0xf0) == 0xe0) {
			u = utf8_decode_char((const uint8_t *)&utf8[i], 3);
			i += 3;
		} else if ((c & 0xe0) == 0xc0) {
			u = utf8_decode_char((const uint8_t *)&utf8[i], 2);
			i += 2;
		} else {
			i++;
			continue;
		}
		*o = u;
		if (k == max - 1) {
			printf("maybe array overflow!(k=%d)\n", k);
			break;
		}
		k++;
	}
	out[k] = 0;
	return k;
}

uint16_t *FUN_0004b160(const char *utf8, uint16_t *count)
{
	memset(unicode_buf, 0, sizeof(unicode_buf));
	*count = utf8_to_unicode(utf8, strlen(utf8), unicode_buf, 0x400);
	return unicode_buf;
}

void expand_1bpp_to_4bpp(const uint8_t *src, int len, uint8_t *dst)
{
	for (int i = 0; i < len; i++) {
		((uint32_t *)dst)[i] = ((const uint32_t *)font_1bpp_to_4bpp)[src[i]];
	}
}

const uint8_t *find_chinese_bitmap_by_unicode(int code, int w, int h)
{
	uint16_t size = w * h;
	uint8_t buf[size];
	uint8_t *bitmap = buf;
	const uint8_t *ret;
	struct cjk_glyph_index idx;
	uint32_t addr;
	int err;

	if ((unsigned int)(code - 0x20) < 0x60) {
		ret = font_ascii_lookup(code, size);
	} else {
		if (FONT_GS()->flash_read == NULL) {
			bitmap = NULL;
		} else {
			if (FONT_GS()->flash_read(get_dashboard_state(), ((code - 0xa4) << 2) + 0x140000,
						  &idx, sizeof(idx))) {
				G1_LOG_ERR("read flash fail\n\n");
				return NULL;
			}
			printk("unicode=%x, offset=%d\n", idx.unicode, idx.offset);
			addr = (size / 4) * idx.offset;
			if (size == 0x1b0) {
				addr += 0xcf120;
			}
			memset(buf, 0, size);
			err = FONT_GS()->flash_read(get_dashboard_state(), addr + 0x200000, buf, size / 4);
			if (err) {
				G1_LOG_ERR("read flash fail: %d\n\n", err);
			}
		}
		expand_1bpp_to_4bpp(bitmap, size, cjk_glyph_buf);
		ret = cjk_glyph_buf;
	}
	return ret;
}

const uint8_t *FUN_0004b2d4(int glyph, int size)
{
	if (glyph == 4) {
		memcpy(small_glyph_buf, font_glyph4_4bpp, sizeof(small_glyph_buf));
	} else {
		int n = size / 4;

		expand_1bpp_to_4bpp(&font_small_glyphs[n * glyph], n, small_glyph_buf);
	}
	return small_glyph_buf;
}

const uint8_t *FUN_0004b30c(int id, int *w, int *h)
{
	*h = 200;
	if (demo_mode) {
		*w = 0x27e;
		*h = 199;
		return NULL;
	}
	*w = 0x240;
	*h = 0x88;
	return font_picture_table[id];
}

void FUN_0004b340(void)
{
	if (line_buf) {
		free(line_buf);
		line_buf = NULL;
	}
}

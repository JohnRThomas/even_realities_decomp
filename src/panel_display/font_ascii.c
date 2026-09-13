/*
 * ASCII glyph helpers of the font code (only align-2 leaf functions).
 * Kept in a separate file: find_chinese_bitmap_by_unicode() calls
 * font_ascii_lookup() out of line.
 * Reconstructed from the v1.63 app core.
 */
#include <stdint.h>
#include <stddef.h>

#include "font_bitmap.h"

/* ASCII glyphs are drawn elsewhere */
const uint8_t *font_ascii_lookup(uint8_t c, int size)
{
	return NULL;
}

/*
 * ASCII glyph of a w x h font: there is no ASCII table in this build, so the
 * result is the glyph offset from a NULL base (callers pass arg = 0, unused).
 */
const uint8_t *FUN_00080fa2(uint16_t digit, int w, int h, int arg)
{
	(void)arg;
	if ((uint16_t)(digit - 0x20) < 0x60) {
		return (const uint8_t *)((digit - 0x20) * (w * h));
	}
	return NULL;
}

int check_printable_code(uint32_t code)
{
	return code > 0x1f ? 0 : -1;
}

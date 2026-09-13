/*
 * Minimal 8x8 monospace bitmap font for the ARMemul demo.
 *
 * ORIGINAL WORK: the glyphs are a hand-drawn 5x7 design created for this
 * project (no external font assets were copied); same license as the
 * repository. Coverage: space, % + , - . / 0-9 : = A-Z (lowercase input is
 * folded to uppercase); anything else renders as a hollow box.
 */
#ifndef DEMO_FONT8X8_H_
#define DEMO_FONT8X8_H_

#include <stdint.h>

/* Returns 8 bytes, one per row (top first); bit 7 = leftmost pixel. */
const uint8_t *font8x8_glyph(char c);

#endif /* DEMO_FONT8X8_H_ */

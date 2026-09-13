/*
 * JBD 640x200 4-bpp microdisplay driver for the ARMemul demo.
 *
 * The one custom driver of the demo app (everything else uses the pinned
 * in-tree drivers). Protocol per models/JBD_Display.cs:
 *   - 0x9F: identification, responds with ID 0x4010 (0x40 then 0x10)
 *   - 0x02: pixel window write:
 *       byte0   = 0x02
 *       byte1-3 = coord = (x & 0x3FF) | ((y << 10) & 0x7FC00),
 *                 little-endian (model default CoordBigEndian=false)
 *       byte4   = 0xFF marker
 *       byte5.. = packed 4-bpp pixels, high nibble = left pixel
 *                 (model default FirstPixelInLowNibble=false)
 *       last    = one trailing dummy byte
 * Every command must be a single SPI transaction (the SPIM model frames
 * commands at transaction end), so the full-frame update is sent as one
 * contiguous buffer.
 */
#ifndef DEMO_JBD_DISPLAY_H_
#define DEMO_JBD_DISPLAY_H_

#include <stdint.h>

#define JBD_WIDTH		640
#define JBD_HEIGHT		200
#define JBD_BYTES_PER_ROW	(JBD_WIDTH / 2)
#define JBD_FRAME_BYTES		(JBD_BYTES_PER_ROW * JBD_HEIGHT)
#define JBD_EXPECTED_ID		0x4010

#define JBD_TEXT_COLS		(JBD_WIDTH / 8)
#define JBD_TEXT_ROWS		(JBD_HEIGHT / 8)

/* Reads the ID via 0x9F. Returns the 16-bit ID or -errno. */
int jbd_read_id(void);

/* Clears the local framebuffer (does not touch the panel). */
void jbd_clear(void);

/* Draws str at text cell (col, row) into the local framebuffer;
 * 8x8 cells, intensity 0..15.
 */
void jbd_draw_text(int col, int row, const char *str, uint8_t intensity);

/* Sends the whole framebuffer as one 0x02 pixel-window transaction. */
int jbd_flush(void);

#endif /* DEMO_JBD_DISPLAY_H_ */

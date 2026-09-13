/*
 * JBD display driver — see jbd_display.h for the protocol description.
 *
 * Uses the pinned Zephyr SPI API (spi_nrfx_spim) directly; SPI mode 3 per
 * docs/board-map.md.
 */
#include <zephyr/kernel.h>
#include <zephyr/drivers/spi.h>
#include <string.h>

#include "jbd_display.h"
#include "font8x8.h"

#define JBD_NODE DT_NODELABEL(jbd0)

#define JBD_SPI_OP (SPI_OP_MODE_MASTER | SPI_WORD_SET(8) | SPI_TRANSFER_MSB | \
		    SPI_MODE_CPOL | SPI_MODE_CPHA)

static const struct spi_dt_spec jbd_spi = SPI_DT_SPEC_GET(JBD_NODE, JBD_SPI_OP, 0);

#define JBD_HDR_BYTES 5

/* [0x02][coord0][coord1][coord2][0xFF][64000 pixel bytes][dummy] */
static uint8_t frame_tx[JBD_HDR_BYTES + JBD_FRAME_BYTES + 1];
#define FRAMEBUF (&frame_tx[JBD_HDR_BYTES])

int jbd_read_id(void)
{
	uint8_t tx[3] = { 0x9F, 0x00, 0x00 };
	uint8_t rx[3] = { 0 };
	const struct spi_buf txb = { .buf = tx, .len = sizeof(tx) };
	const struct spi_buf rxb = { .buf = rx, .len = sizeof(rx) };
	const struct spi_buf_set txs = { .buffers = &txb, .count = 1 };
	const struct spi_buf_set rxs = { .buffers = &rxb, .count = 1 };
	int err;

	if (!spi_is_ready_dt(&jbd_spi)) {
		return -ENODEV;
	}
	err = spi_transceive_dt(&jbd_spi, &txs, &rxs);
	if (err < 0) {
		return err;
	}
	return (rx[1] << 8) | rx[2];
}

void jbd_clear(void)
{
	memset(FRAMEBUF, 0, JBD_FRAME_BYTES);
}

void jbd_draw_text(int col, int row, const char *str, uint8_t intensity)
{
	uint8_t left = (uint8_t)((intensity & 0xF) << 4);
	uint8_t right = (uint8_t)(intensity & 0xF);

	for (; *str != '\0'; str++, col++) {
		if (col < 0 || col >= JBD_TEXT_COLS ||
		    row < 0 || row >= JBD_TEXT_ROWS) {
			continue;
		}
		const uint8_t *glyph = font8x8_glyph(*str);

		for (int gy = 0; gy < 8; gy++) {
			uint8_t bits = glyph[gy];
			uint8_t *dst = FRAMEBUF +
				(row * 8 + gy) * JBD_BYTES_PER_ROW + col * 4;

			for (int bx = 0; bx < 4; bx++) {
				uint8_t v = 0;

				if (bits & (0x80 >> (2 * bx))) {
					v |= left;
				}
				if (bits & (0x40 >> (2 * bx))) {
					v |= right;
				}
				dst[bx] = v;
			}
		}
	}
}

int jbd_flush(void)
{
	const struct spi_buf txb = { .buf = frame_tx, .len = sizeof(frame_tx) };
	const struct spi_buf_set txs = { .buffers = &txb, .count = 1 };

	if (!spi_is_ready_dt(&jbd_spi)) {
		return -ENODEV;
	}

	frame_tx[0] = 0x02;
	/* window origin (0, 0): coord word 0, little-endian */
	frame_tx[1] = 0x00;
	frame_tx[2] = 0x00;
	frame_tx[3] = 0x00;
	frame_tx[4] = 0xFF;
	frame_tx[sizeof(frame_tx) - 1] = 0x00; /* trailing dummy */

	return spi_write_dt(&jbd_spi, &txs);
}

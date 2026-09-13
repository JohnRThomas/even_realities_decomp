/*
 * JBD013VGA SPI transport, derived from the JBD reference code
 * (referenced_examples/jdb013vga/hal_driver.c), on top of the vendor
 * spi_interface_t of the panel context.  Reconstructed from the v1.63
 * firmware image.
 */
#include <string.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "panel.h"

/* write the frame buffer to the panel cache at column col / row row */
void spi_wr_buffer(uint16_t col, uint16_t row, uint8_t *buf, uint32_t len)
{
	uint8_t rx[1] = {0};
	struct jbd_panel_context *c = get_jdb_panel_context();
	uint8_t *p = c->current_buffer;
	uint32_t addr = ((row << 10) & 0x7fc00) | (col & 0x3ff);

	p[-5] = SPI_WR_BUFFER;
	p[-4] = addr >> 16;
	p[-3] = addr >> 8;
	p[-2] = addr;
	p[-1] = 0xff;
	lock_lcd_mutex(K_FOREVER);
	c->spi_callbacks->rx_tx(c->spi_callbacks, p - 5, len + 6, rx, 1);
	unlock_lcd_mutex();
}

uint16_t spi_read_id(void)
{
	uint32_t tx;
	uint8_t rx[4] = {0};
	struct jbd_panel_context *c = get_jdb_panel_context();

	tx = SPI_RD_ID;

	lock_lcd_mutex(K_FOREVER);
	c->spi_callbacks->rx_tx(c->spi_callbacks, (uint8_t *)&tx, 4, rx, 4);
	unlock_lcd_mutex();
	G1_LOG_INF("jbd panel devicve id: %02x, %02x, %02x, %02x\n", rx[0], rx[1], rx[2], rx[3]);
	return sys_get_be16(&rx[2]);
}

/* ---- align-2 part ---- */

void delay_ms(uint32_t ms)
{
	k_busy_wait(ms * 1000);
}

void spi_send_cmd(uint8_t cmd)
{
	uint8_t rx[1] = {0};
	struct jbd_panel_context *c = get_jdb_panel_context();

	lock_lcd_mutex(K_FOREVER);
	c->spi_callbacks->rx_tx(c->spi_callbacks, &cmd, 1, rx, 1);
	unlock_lcd_mutex();
}

#define SPI_TX_CHUNK 0xf000

int spi_tx_data(const uint8_t *buf, uint32_t len)
{
	struct jbd_panel_context *c = get_jdb_panel_context();
	uint8_t rx[1] = {0};
	uint32_t whole = len / SPI_TX_CHUNK * SPI_TX_CHUNK;
	uint32_t rem = len - whole;
	const uint8_t *end = buf + whole;

	for (; buf != end; buf += SPI_TX_CHUNK) {
		lock_lcd_mutex(K_FOREVER);
		c->spi_callbacks->rx_tx(c->spi_callbacks, buf, SPI_TX_CHUNK, rx, 1);
		unlock_lcd_mutex();
	}
	lock_lcd_mutex(K_FOREVER);
	c->spi_callbacks->rx_tx(c->spi_callbacks, buf, rem, rx, 1);
	return unlock_lcd_mutex();
}

/* send one command frame: cmd followed by len parameter bytes */
void spi_tx_frame(uint8_t cmd, const uint8_t *param, uint32_t len)
{
	uint8_t buf[6];

	buf[0] = cmd;
	memcpy(&buf[1], param, len);
	spi_tx_data(buf, len + 1);
}

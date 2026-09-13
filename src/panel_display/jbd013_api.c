/*
 * JBD013VGA panel command API, derived from the JBD reference code
 * (referenced_examples/jdb013vga/jbd013_api.c).  Reconstructed from the
 * v1.63 firmware image.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/byteorder.h>

#include "panel.h"

/* send a JBD013VGA SPI command to the panel */
void send_cmd(uint8_t cmd)
{
	spi_send_cmd(cmd);
}

/* write status register regAddr */
void wr_status_reg(uint8_t reg, uint8_t data)
{
	spi_tx_frame(reg, &data, 1);
}

/* write offset register, row offset (0~31), column offset (0~31) */
void wr_offset_reg(uint8_t row, uint8_t col)
{
	uint8_t buf[2];

	buf[0] = row;
	buf[1] = col;
	spi_tx_frame(SPI_WR_OFFSET_REG, buf, 2);
	send_cmd(SPI_SYNC);
	delay_ms(1);
}

/* write current register (0~63) */
void wr_cur_reg(uint8_t param)
{
	spi_tx_frame(SPI_WR_CURRENT_REG, &param, 1);
}

/* write luminance register */
void wr_lum_reg(uint16_t param)
{
	uint8_t buf[2];

	sys_put_be16(param, buf);
	spi_tx_frame(SPI_WR_LUM_REG, buf, 2);
}

/* clear the panel cache */
void clr_cache(uint8_t val)
{
	uint8_t *buf = get_jdb_panel_context()->panel_buffer[0];

	memset(buf, val, PANEL_FB_SIZE);
	spi_wr_buffer(0, 0, buf, 0xf000);
	spi_wr_buffer(0, 192, buf, 0xf000);
	spi_wr_buffer(0, 384, buf, 0x7800);
}

void jbd_clear_cache_sync(uint8_t val)
{
	clr_cache(val);
	send_cmd(SPI_SYNC);
	delay_ms(1);
}

/* display an image */
void display_image(uint32_t col, uint32_t row, uint8_t *buf, int len)
{
	uint16_t y = row;
	uint16_t x = col;

	for (;;) {
		uint16_t next = y + 192;

		if (len <= 0xf000) {
			spi_wr_buffer(x, y, buf, len);
			send_cmd(SPI_SYNC);
			delay_ms(1);
			return;
		}
		spi_wr_buffer(x, y, buf, 0xf000);
		len -= 0xf000;
		y = next;
	}
}

/* reset the panel */
void panel_rst(void)
{
	delay_ms(1);
	send_cmd(SPI_RST_EN);
	delay_ms(1);
	send_cmd(SPI_RST);
	delay_ms(10);
}

/* initialise the panel */
void panel_init(void)
{
	panel_rst();
	send_cmd(SPI_WR_ENABLE);
	wr_status_reg(SPI_WR_STATUS_REG1, 0x10);
	clr_cache(0);
	wr_offset_reg(0, 0);
	wr_offset_reg(0, 20);
	wr_offset_reg(24, 0);
	wr_offset_reg(24, 20);
	wr_offset_reg(12, 10);
	send_cmd(SPI_DISPLAY_DEFAULT_MODE);
	send_cmd(SPI_SYNC);
	delay_ms(1);
	send_cmd(SPI_DISPLAY_RL);
	send_cmd(SPI_SYNC);
	delay_ms(1);
	wr_cur_reg(15);
	wr_status_reg(SPI_WR_STATUS_REG2, 0x04);
	send_cmd(SPI_DISPLAY_ENABLE);
	send_cmd(SPI_SYNC);
	delay_ms(1);
}

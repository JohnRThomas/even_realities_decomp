/*
 * JBD panel frame buffer flush (_reflash_fb_data_to_lcd / _ex), deep power
 * down / resume and the LCD mutex: align-4 0x4abd0..0x4af6b.
 *
 * A file of its own: in the target .rodata its strings follow _clean_fb_data's
 * __func__, and its __func__ objects (jbd_panel_resume, jbd_panel_suspend,
 * _reflash_fb_data_to_lcd_ex, _reflash_fb_data_to_lcd: reverse definition
 * order) come after all of its strings.  Reconstructed from the v1.63 image.
 */
#include <stdbool.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "panel.h"

/*
 * Deep power down / resume and the LCD mutex: align-4 0x4aea8..0x4af6b.
 * panel_suspend()/panel_resume() (jbd_panel.c) are emitted
 * *before* these callees, which GCC never does for callees in the same file,
 * so they live here (lcd_mutex 0x2000aa40 follows jbd_panel.c's .bss too).
 */
uint32_t JDB_PANEL_ID;            /* 0x2000aa54 (defined first: highest address) */
struct k_mutex lcd_mutex;         /* 0x2000aa40 */

int _reflash_fb_data_to_lcd(uint32_t row, uint32_t column, int x_start, int y_start,
			    int x_end, int y_end)
{
	uint8_t rx[1] = {0};
	struct jbd_panel_context *c = get_jdb_panel_context();
	int ret;

	if (!c->init_done) {
		G1_LOG_ERR("c->init_done = 0,init failed, can't write data!\n");
		return -1;
	}
	if (y_end >= PANEL_FB_ROWS) {
		y_end = PANEL_FB_ROWS;
	}
	if (x_end >= PANEL_WIDTH) {
		x_end = PANEL_WIDTH;
	}
	for (; y_start <= y_end; y_start++) {
		volatile uint8_t *p = c->current_buffer + y_start * PANEL_FB_STRIDE + x_start / 2 - 5;
		int len = x_end / 2 - x_start / 2 + 5;
		uint8_t backup[5];
		volatile uint32_t addr;
		uint8_t tail;

		memcpy(backup, (uint8_t *)p, sizeof(backup));
		addr = (((column + y_start) << 10) & 0x7fc00) | ((x_start + row) & 0x3ff);
		p[0] = SPI_WR_BUFFER;
		p[1] = (addr >> 16) & 0xff;
		p[2] = (addr >> 8) & 0xff;
		p[3] = addr & 0xff;
		p[4] = 0xff;
		tail = p[len];
		p[len] = 0;
		k_mutex_lock(&lcd_mutex, K_FOREVER);
		ret = c->spi_callbacks->rx_tx(c->spi_callbacks, (uint8_t *)p, len, rx, 1);
		k_mutex_unlock(&lcd_mutex);
		if (ret) {
			G1_LOG_ERR("spi transfer error....\n");
		}
		p[len] = tail;
		memcpy((uint8_t *)p, backup, sizeof(backup));
	}
	spi_send_cmd(SPI_SYNC);
	delay_ms(1);
	return 0;
}

int _reflash_fb_data_to_lcd_ex(uint32_t row, uint32_t column, int x_start, int y_start,
			       int x_end, int y_end, int offset)
{
	uint8_t rx[1] = {0};
	struct jbd_panel_context *c = get_jdb_panel_context();
	int ret;

	if (!c->init_done) {
		G1_LOG_ERR("c->init_done = 0,init failed, can't write data!\n");
		return -1;
	}
	if (y_end >= PANEL_FB_ROWS) {
		y_end = PANEL_FB_ROWS;
	}
	if (x_end >= PANEL_WIDTH) {
		x_end = PANEL_WIDTH;
	}
	for (; y_start <= y_end; y_start++) {
		volatile uint8_t *p = c->current_buffer + (y_start + offset) * PANEL_FB_STRIDE +
				      x_start / 2 - 5;
		int len = x_end / 2 - x_start / 2 + 5;
		uint8_t backup[5];
		volatile uint32_t addr;
		uint8_t tail;

		memcpy(backup, (uint8_t *)p, sizeof(backup));
		addr = (((column + y_start) << 10) & 0x7fc00) | ((x_start + row) & 0x3ff);
		p[0] = SPI_WR_BUFFER;
		p[1] = (addr >> 16) & 0xff;
		p[2] = (addr >> 8) & 0xff;
		p[3] = addr & 0xff;
		p[4] = 0xff;
		tail = p[len];
		p[len] = 0;
		k_mutex_lock(&lcd_mutex, K_FOREVER);
		ret = c->spi_callbacks->rx_tx(c->spi_callbacks, (uint8_t *)p, len, rx, 1);
		k_mutex_unlock(&lcd_mutex);
		if (ret) {
			G1_LOG_ERR("spi transfer error....\n");
		}
		p[len] = tail;
		memcpy((uint8_t *)p, backup, sizeof(backup));
	}
	spi_send_cmd(SPI_SYNC);
	delay_ms(1);
	return 0;
}

/* 0x2000aa40 */

int jbd_panel_suspend(void)
{
	uint8_t param;

	G1_LOG_INF("SPI_DEEP_POWER_DOWN\n");
	param = 0xff;
	spi_tx_frame(SPI_DEEP_POWER_DOWN, &param, 1);
	return 0;
}

int jbd_panel_resume(struct jbd_panel_context *c)
{
	G1_LOG_INF("release from deep power down\n");
	panel_init();
	set_brightness_to_panel_reg(c->panel_brightness_level);
	G1_LOG_INF("resume completed\n");
	return 0;
}

void lock_lcd_mutex(k_timeout_t timeout)
{
	k_mutex_lock(&lcd_mutex, timeout);
}

int unlock_lcd_mutex(void)
{
	return k_mutex_unlock(&lcd_mutex);
}

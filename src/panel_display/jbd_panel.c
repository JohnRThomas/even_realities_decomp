/*
 * JBD013VGA micro-LED panel layer: panel context callbacks and brightness
 * (the frame buffer clear is in panel_fb.c, the flush in jbd_panel_flush.c).
 * Function definition order follows the target's __func__ order (reverse
 * definition order in .rodata), not the code order.
 * Reconstructed from the v1.63 firmware image.
 */
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "panel.h"

int getDeviceRole(void);
int power_for_panel(void);
int power_down_panel(void);
struct opt3007_context;
int opt3007_chip_init(struct opt3007_context *ctx);
void opt3007_chip_deinit(void);
int panel_related(struct jbd_panel_context *panel, int idx, void *arg);

extern uint32_t JDB_PANEL_ID;     /* jbd_panel_flush.c */
extern struct k_mutex lcd_mutex; /* jbd_panel_flush.c */
static int JBD_LUM_REG_VAL;
static int JBD_CUR_REG_VAL;

/* the SPI interface sits 0x5c bytes in front of the panel context in GlassesState */
#define PANEL_SPI(c) ((struct spi_interface *)((uint8_t *)(c) - 0x5c))

int panel_set_brightness_level(struct jbd_panel_context *c, uint8_t level)
{
	if (c->panel_brightness_level != level) {
		c->panel_brightness_level = level;
		G1_LOG_INF("new: %d\n", level);
	}
	return level;
}

void set_brightness_to_panel_reg(uint8_t level)
{
	G1_LOG_INF("set brightness level = %d\n", level);
	{
		uint16_t lum;
		uint8_t cur;

		update_brightness_level_for_jdb_panel(level, &lum, &cur);
		send_cmd(SPI_WR_ENABLE);
		send_cmd(SPI_DISPLAY_DISABLE);
		wr_lum_reg(lum);
		wr_cur_reg(cur);
	}
	wr_status_reg(SPI_WR_STATUS_REG2, 0x04);
	send_cmd(SPI_DISPLAY_ENABLE);
	send_cmd(SPI_SYNC);
	delay_ms(1);
}

void wr_lum_and_cur_reg(uint16_t lum_value, uint8_t cur_value)
{
	if (lum_value != JBD_LUM_REG_VAL) {
		wr_lum_reg(lum_value);
		JBD_LUM_REG_VAL = lum_value;
	}
	if (cur_value != JBD_CUR_REG_VAL) {
		wr_cur_reg(cur_value);
		JBD_CUR_REG_VAL = cur_value;
	}
}

void set_brightness_to_panel_reg_in_running(uint8_t level)
{
	G1_LOG_INF("set brightness level = %d\n", level);
	if (!PANEL_GS()->panel.init_done) {
		return;
	}
	{
		uint16_t lum;
		uint8_t cur;

		update_brightness_level_for_jdb_panel(level, &lum, &cur);
		send_cmd(SPI_WR_ENABLE);
		send_cmd(SPI_DISPLAY_DISABLE);
		wr_lum_and_cur_reg(lum, cur);
	}
	wr_status_reg(SPI_WR_STATUS_REG2, 0x04);
	send_cmd(SPI_DISPLAY_ENABLE);
	send_cmd(SPI_SYNC);
	delay_ms(1);
}

int panel_suspend(struct jbd_panel_context *c)
{
	c->spi_callbacks = PANEL_SPI(c);
	G1_LOG_INF("panel_suspend enter!\n");
	jbd_panel_suspend();
	panel_off(c);
	c->init_done = 0;
	return 0;
}

int panel_off(struct jbd_panel_context *c)
{
	c->spi_callbacks = PANEL_SPI(c);
	if (PANEL_SPI(c)->is_initialized) {
		c->init_done = 0;
		G1_LOG_INF("panel_suspend enter!\n");
		if (getDeviceRole() == 0) {
			opt3007_chip_deinit();
		}
		PANEL_SPI(c)->deinit(c->spi_callbacks);
		power_down_panel();
	}
	return 0;
}

int panel_resume(struct jbd_panel_context *c)
{
	uint32_t ret;

	c->spi_callbacks = PANEL_SPI(c);
	if (!(CONTAINER_OF(c, struct panel_gs, panel)->module_mask & LP_JBD_BIT)) {
		G1_LOG_ERR("panel_resume exit due to LP_JBD_BIT\n");
		ret = -1;
	} else {
		G1_LOG_INF("panel_resume enter!\n");
		ret = c->init_done;
		if (ret) {
			G1_LOG_ERR("panel_resume exit due to init_done\n");
			ret = -1;
		} else if (c->spi_callbacks->is_initialized) {
			jbd_panel_resume(c);
			if (spi_read_id() != JBD_PANEL_DEVICE_ID) {
				G1_LOG_ERR("JBD PANEL init failure!\n");
			}
			c->init_done = 1;
		} else {
			panel_on(c);
			set_brightness_to_panel_reg(c->panel_brightness_level);
		}
	}
	/* constant-true block (permuter find): the extra CFG node keeps one shared exit block
	 * (`mov r0, r5; pop`) instead of a copy in the error path, as in the target */
	if (1) {
		return ret;
	}
}

int panel_on(struct jbd_panel_context *c)
{
	c->spi_callbacks = PANEL_SPI(c);
	if (!PANEL_SPI(c)->is_initialized) {
		G1_LOG_INF("panel_on enter!\n");
		power_for_panel();
		PANEL_SPI(c)->init_cb(c->spi_callbacks);
		panel_init();
		c->init_done = 1;
		if (getDeviceRole() == 0) {
			opt3007_chip_init(NULL);
		}
	}
	return 0;
}

int jdb_panel_init(struct jbd_panel_context *c)
{
	c->spi_callbacks = PANEL_SPI(c);
	panel_init();
	set_brightness_to_panel_reg(c->panel_brightness_level);
	JDB_PANEL_ID = spi_read_id();
	if (JDB_PANEL_ID != JBD_PANEL_DEVICE_ID) {
		G1_LOG_ERR("JBD PANEL init failure!, device id: 0x%x\n", JDB_PANEL_ID);
		return -1;
	}
	G1_LOG_ERR("JBD PANEL init ok!, device id: 0x%x\n", JDB_PANEL_ID);
	c->init_done = 1;
	return 0;
}

void register_jdb_panel_context(struct jbd_panel_context *c)
{
	uint8_t *buf;
	int i;

	k_mutex_init(&lcd_mutex);
	c->init_cb = jdb_panel_init;
	c->suspend_cb = panel_suspend;
	c->resume_cb = panel_resume;
	c->off_cb = panel_off;
	c->on_cb = panel_on;
	c->panel_cb_14 = panel_related;
	c->draw_image_cb = panel_draw_cb;
	c->clear_cb = clear_panel;
	c->set_brightness_cb = panel_set_brightness_level;
	/* 5 bytes command header in front of the frame buffer, 3 behind */
	buf = malloc(PANEL_FB_SIZE + 8);
	c->current_buffer = buf + 5;
	for (i = 0; i < PANEL_FB_ROWS; i++) {
		c->panel_buffer[i] = buf + 5 + i * PANEL_FB_STRIDE;
	}
	c->current_buffer_size = PANEL_FB_SIZE;
}

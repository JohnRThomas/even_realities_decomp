/*
 * Panel frame buffer helpers (brightness curve, draw/clear callbacks, frame
 * buffer copies).  These have no literal pools and all live in the align-2
 * text region right after gui; since get_jdb_panel_context() is not inlined
 * into jbd_panel.c / jbd_panel_flush.c, they are in a file of their own.
 * _clean_fb_data() (align-4 0x4ab3c) is this file's only align-4 function: its
 * strings and __func__ sit between jbd_panel.c's __func__ block and the
 * strings of jbd_panel_flush.c in the target .rodata.
 * Reconstructed from the v1.63 firmware image.
 */
#include <stdbool.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "panel.h"

int _clean_fb_data(uint8_t **fb, int val, int x_start, int y_start, int x_end, int y_end)
{
	int y;

	if (x_end >= PANEL_WIDTH) {
		x_end = PANEL_WIDTH;
	}
	if (y_end >= PANEL_FB_ROWS) {
		y_end = PANEL_FB_ROWS;
	}
	if (x_start > x_end || y_start > y_end) {
		G1_LOG_ERR("clean frame buffer parameter error!!!\n");
		return -1;
	}
	for (y = y_start; y <= y_end; y++) {
		memset(fb[y] + x_start / 2, val, x_end / 2 - x_start / 2 + 1);
	}
	return x_end / 2 - x_start / 2 + 1;
}

void update_brightness_level_for_jdb_panel(uint8_t level, uint16_t *lum, uint8_t *cur)
{
	if (level <= 5) {
		int base = PANEL_GS()->panel.brightness_max * 2 / 9;

		if (base == 0 || PANEL_GS()->panel.brightness_max <= 5) {
			*lum = (level * 111 / 6 + 1) * (PANEL_GS()->panel.brightness_max + 1);
		} else {
			*lum = (base + level * (PANEL_GS()->panel.brightness_max - base) / 6) * 111;
		}
		*cur = 0;
	} else {
		*lum = (PANEL_GS()->panel.brightness_max + 1) * 111;
		*cur = level - 6;
	}
	if ((PANEL_GS()->panel.brightness_percent > 69) &
	    (PANEL_GS()->panel.brightness_percent < 100)) {
		*lum = *lum * PANEL_GS()->panel.brightness_percent / 100;
	}
	if (*lum == 0) {
		*lum = 1;
	}
}

void *clear_panel(struct jbd_panel_context *c)
{
	return memset(c->panel_buffer[0], 0, c->current_buffer_size);
}

void panel_draw_cb(struct jbd_panel_context *c)
{
	if (c->init_done) {
		display_image(c->current_row, c->current_column, c->panel_buffer[0],
			      c->current_buffer_size);
	}
}

struct jbd_panel_context *get_jdb_panel_context(void)
{
	return &PANEL_GS()->panel;
}

int FUN_00080bc0(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y)
{
	int i;

	for (i = 0; i < h; i++) {
		memcpy(fb[y + i] + x % PANEL_FB_STRIDE, src + i * w, w);
	}
	return y;
}

int copy_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y)
{
	int i;

	if (y >= PANEL_FB_ROWS) {
		y = PANEL_FB_ROWS;
	}
	if (x >= PANEL_WIDTH) {
		x = PANEL_WIDTH;
	}
	for (i = 0; i < h; i++) {
		memcpy(fb[y + i] + x / 2, src + i * w, w);
	}
	return y;
}

int or_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y)
{
	int k = 0;
	int i, j;
	int x_byte;

	if (y >= PANEL_FB_ROWS) {
		y = PANEL_FB_ROWS;
	}
	if (x >= PANEL_WIDTH) {
		x = PANEL_WIDTH;
	}
	x_byte = x / 2;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w / 2; j++) {
			fb[y + i][x_byte + j] |= src[k++];
		}
	}
	return y;
}

void copy_frame_buffer_rows(uint8_t **fb, int dst_x, int dst_y, int src_x, int src_y, int h, int w)
{
	int i;

	for (i = 0; i < h; i++) {
		memcpy(fb[dst_y + i] + dst_x / 2, fb[src_y + i] + src_x / 2, w / 2);
	}
}

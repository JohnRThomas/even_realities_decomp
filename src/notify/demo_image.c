/*
 * Demo / calibration pictures: 1 bpp BMP files in the external flash are
 * converted to the 4 bpp panel format, plus the 9-point position page.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

#define DEMO_IMAGE_FLASH_ADDR  0x180000
#define DEMO_IMAGE_SIZE        0x3ebe
#define DEMO_IMAGE_NUM         5
#define FLASH_IMAGE_ADDR       0x1c0000
#define LINE_BYTES             320

struct bmp_file_header {
	char type[2];
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t off_bits;
} __packed;

struct bmp_info_header {
	uint32_t size;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bit_count;
	uint32_t compression;
	uint32_t size_image;
	int32_t x_ppm;
	int32_t y_ppm;
	uint32_t clr_used;
	uint32_t clr_important;
};

uint8_t demo_mode;
static uint8_t demo_idx;

uint8_t *line_buf;
int line_idx;
int line_x;
static uint8_t demo_shown = 0xff;

static int demo_x = -1;
static int demo_y = -1;
/* 6x5 pixel markers of the position page (4 bpp); the data lives in
 * panel_display/font_bitmap.c (.rodata 0xdbb66 / 0xdbb75, after font_1bpp_to_4bpp) */
extern const uint8_t demo_mark_left[15];
extern const uint8_t demo_mark_right[15];

#line 35
void pixelto4bithex_for_flash(uint8_t pix, int width, uint16_t row)
{
	if (line_buf == NULL) {
		line_buf = malloc(LINE_BYTES);
		if (line_buf == NULL) {
			printk("[%s-%d]malloc error \n", __func__, __LINE__);
			return;
		}
		memset(line_buf, 0, LINE_BYTES);
	}
	for (int shift = 0; shift < 8; shift += 2) {
		uint8_t v;

		if (line_x >= width) {
			return;
		}
		line_x += 2;
		v = (pix << shift) & 0xc0;
		if (v == 0xc0) {
			line_buf[line_idx] = 0xff;
		} else if (v == 0x80) {
			line_buf[line_idx] = 0xf0;
		} else if (v == 0x40) {
			line_buf[line_idx] = 0x0f;
		} else if (v == 0) {
			line_buf[line_idx] = 0;
		} else {
			line_buf[line_idx] = 0x99;
		}
		line_idx++;
	}
}

__noinline uint32_t bmp_read_u32(const void *p)
{
	return *(const uint32_t *)p;
}

#line 74
void get_demo_image_source_from_flash(void)
{
	struct bmp_file_header fh;
	struct bmp_info_header ih;
	uint8_t *buf;
	uint32_t addr = FLASH_IMAGE_ADDR;
	int width, off, height, bytes, stride;

	buf = malloc(0x50);
	if (buf == NULL) {
		printk("[%s-%d]malloc error \n", __func__, __LINE__);
		return;
	}
	memset(buf, 0, 0x50);
	if (get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, 0x50)) {
		printk("[%s-%d] read pic from flash failed !\n", __func__, 90);
		goto out;
	}
	memcpy(&fh, buf, sizeof(fh));
	if (strncmp(fh.type, "BM", 2)) {
		printk("File is not BMP format \n");
		goto out;
	}
	memcpy(&ih, buf + sizeof(fh), sizeof(ih));
	off = bmp_read_u32(&fh.off_bits);
	width = bmp_read_u32(&ih.width);
	height = bmp_read_u32(&ih.height);
	if (ih.bit_count != 1) {
		printf("Unsupported bit depth - %d\r\n", ih.bit_count);
		goto out;
	}
	bytes = (width + 7) / 8;
	stride = (width + 31) / 32 * 4;
	line_x = 0;
	line_idx = 0;
	for (int y = 0; y < height; y++) {
		line_x = 0;
		memset(buf, 0, 0x50);
		addr = FLASH_IMAGE_ADDR + off + (height - 1 - y) * stride;
		if (get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, bytes)) {
			printk("[%s-%d] read pic from flash failed !\n", __func__, 126);
			goto out;
		}
		for (int i = 0; i < bytes; i++) {
			pixelto4bithex_for_flash(~buf[i], width, y);
		}
		if (line_buf) {
			line_idx = 0;
			memcpy(get_dashboard_state()->panel.panel_buffer[y], line_buf, LINE_BYTES);
		}
	}
out:
	free(buf);
}

#line 162
void pixelto4bithex(uint8_t pix, int width, uint16_t row)
{
	if (line_buf == NULL) {
		line_buf = malloc(LINE_BYTES);
		if (line_buf == NULL) {
			printk("[%s-%d]malloc error \n", __func__, __LINE__);
			return;
		}
		memset(line_buf, 0, LINE_BYTES);
	}
	for (int shift = 0; shift < 8; shift += 2) {
		uint8_t v;

		if (line_x >= width) {
			return;
		}
		line_x += 2;
		v = (pix << shift) & 0xc0;
		if (v == 0xc0) {
			line_buf[line_idx] = 0;
		} else if (v == 0x80) {
			line_buf[line_idx] = 0x0f;
		} else if (v == 0x40) {
			line_buf[line_idx] = 0xf0;
		} else if (v == 0) {
			line_buf[line_idx] = 0xff;
		} else {
			line_buf[line_idx] = 0x99;
		}
		line_idx++;
	}
}

#line 201
void get_demo_image_source(uint32_t idx)
{
	struct bmp_file_header fh;
	struct bmp_info_header ih;
	uint8_t *buf;
	uint32_t addr;
	int off, width, height, bytes, stride;

	buf = malloc(0x50);
	if (buf == NULL) {
		printk("[%s-%d]malloc error \n", __func__, __LINE__);
		return;
	}
	memset(buf, 0, 0x50);
	if (idx >= DEMO_IMAGE_NUM) {
		printk("error imgIdx is %d,reset as zero !\n", idx);
		idx = 0;
	}
	if (get_dashboard_state()->flash_read(get_dashboard_state(),
					      idx * DEMO_IMAGE_SIZE + DEMO_IMAGE_FLASH_ADDR,
					      buf, 0x50)) {
		printk("[%s-%d] read pic from flash failed !\n", __func__, 223);
		goto out;
	}
	memcpy(&fh, buf, sizeof(fh));
	if (strncmp(fh.type, "BM", 2)) {
		printk("File is not BMP format \n");
		goto out;
	}
	memcpy(&ih, buf + sizeof(fh), sizeof(ih));
	off = bmp_read_u32(&fh.off_bits);
	width = bmp_read_u32(&ih.width);
	height = bmp_read_u32(&ih.height);
	if (ih.bit_count != 1) {
		printf("Unsupported bit depth - %d\r\n", ih.bit_count);
		goto out;
	}
	bytes = (width + 7) / 8;
	stride = (width + 31) / 32 * 4;
	line_x = 0;
	line_idx = 0;
	for (int y = 0; y < height; y++) {
		line_x = 0;
		memset(buf, 0, 0x50);
		addr = idx * DEMO_IMAGE_SIZE + DEMO_IMAGE_FLASH_ADDR + off + (height - 1 - y) * stride;
		if (get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, bytes)) {
			printk("[%s-%d] read pic from flash failed !\n", __func__, 259);
			goto out;
		}
		for (int i = 0; i < bytes; i++) {
			pixelto4bithex(~buf[i], width, y);
		}
		if (line_buf) {
			line_idx = 0;
			memcpy(get_dashboard_state()->panel.panel_buffer[y], line_buf, LINE_BYTES);
		}
	}
out:
	free(buf);
}

void demo_image_select(uint8_t idx)
{
	if (idx >= DEMO_IMAGE_NUM) {
		idx = 0;
	}
	demo_mode = 1;
	demo_idx = idx;
}

void demo_image_next(void)
{
	demo_mode = 1;
	demo_idx++;
	if (demo_idx >= DEMO_IMAGE_NUM) {
		demo_idx = 0;
	}
}

int ui_demo_image_task(struct jbd_panel_context *panel, void *arg, int event)
{
	int w, h;

	if (event == 2) {
		gui_screen_clear();
		demo_x = -1;
		demo_y = -1;
		demo_shown = 0xff;
		return 0;
	}
	if (demo_mode == 0) {
		if (get_dashboard_state()->text_x != demo_x ||
		    get_dashboard_state()->text_y != demo_y) {
			gui_screen_clear();
			w = 6;
			h = 5;
			for (uint8_t i = 0; i < 9; i++) {
				const uint8_t *mark;

				switch (i) {
				default:
					demo_x = get_dashboard_state()->text_x + 8;
					demo_y = get_dashboard_state()->text_y + 8;
					mark = demo_mark_left;
					break;
				case 1:
					demo_x = get_dashboard_state()->text_x + 8;
					demo_y = get_dashboard_state()->text_y + 66;
					mark = demo_mark_left;
					break;
				case 2:
					demo_x = get_dashboard_state()->text_x + 8;
					demo_y = get_dashboard_state()->text_y + 123;
					mark = demo_mark_left;
					break;
				case 3:
					demo_x = get_dashboard_state()->text_x + 286;
					demo_y = get_dashboard_state()->text_y + 8;
					mark = demo_mark_left;
					break;
				case 4:
					demo_x = get_dashboard_state()->text_x + 286;
					demo_y = get_dashboard_state()->text_y + 66;
					mark = demo_mark_left;
					break;
				case 5:
					demo_x = get_dashboard_state()->text_x + 286;
					demo_y = get_dashboard_state()->text_y + 123;
					mark = demo_mark_left;
					break;
				case 6:
					demo_x = get_dashboard_state()->text_x + 562;
					demo_y = get_dashboard_state()->text_y + 8;
					mark = demo_mark_right;
					break;
				case 7:
					demo_x = get_dashboard_state()->text_x + 562;
					demo_y = get_dashboard_state()->text_y + 66;
					mark = demo_mark_right;
					break;
				case 8:
					demo_x = get_dashboard_state()->text_x + 562;
					demo_y = get_dashboard_state()->text_y + 123;
					mark = demo_mark_right;
					break;
				}
				copy_to_frame_buffer(panel->panel_buffer, mark, w / 2, h, demo_x, demo_y);
				_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
							get_dashboard_state()->panel.current_column,
							demo_x, demo_y, w + demo_x, h + demo_y);
			}
		}
	} else if (demo_shown != demo_idx) {
		demo_shown = demo_idx;
		gui_screen_clear();
		demo_x = 0;
		demo_y = 0;
		FUN_0004b30c(0, &w, &h);
		get_demo_image_source(demo_idx);
		_reflash_fb_data_to_lcd(get_dashboard_state()->panel.current_row,
					get_dashboard_state()->panel.current_column, demo_x, demo_y,
					w + demo_x, h + demo_y);
	}
	return 0;
}

int draw_template_new_message_page(struct jbd_panel_context *panel, void *arg)
{
	return 0;
}

/* Old placeholder names, still used by other modules (renamed 2026-10-21, byte-neutral). */
extern __typeof__(ui_demo_image_task) FUN_00038270 __attribute__((alias("ui_demo_image_task")));

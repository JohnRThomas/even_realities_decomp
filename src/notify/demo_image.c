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
#include "demo_image.h"
#include "../fonts/font_bitmap.h"
#include "../gui/gui.h"
#include "../panel_display/panel.h"

#define DEMO_IMAGE_FLASH_ADDR  0x180000
#define DEMO_IMAGE_SIZE        0x3ebe
#define DEMO_IMAGE_NUM         5
#define FLASH_IMAGE_ADDR       0x1c0000
#define LINE_BYTES             320

uint8_t demo_mode;
static uint8_t demo_idx;

uint8_t *line_buf;
int line_idx;
int line_x;
static uint8_t demo_shown = 0xff;

static int demo_x = -1;
static int demo_y = -1;

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

uint32_t bmp_read_u32(const void *p)
{
	return ((const uint8_t *)p)[0] | ((const uint8_t *)p)[1] << 8 |
	       ((const uint8_t *)p)[2] << 16 | (uint32_t)((const uint8_t *)p)[3] << 24;
}

void get_demo_image_source_from_flash(void)
{
	struct bmp_file_header fh;
	struct bmp_info_header ih;
	uint8_t *buf;
	uint32_t addr = FLASH_IMAGE_ADDR;
	int width, off, height, bytes, stride, ret;

	buf = malloc(0x50);
	if (buf == NULL) {
		printk("[%s-%d]malloc error \n", __func__, __LINE__);
		return;
	}
	memset(buf, 0, 0x50);
	ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, 0x50);
	if (ret) {
		printk("[%s-%d] read pic from flash failed !\n", __func__, __LINE__);
	} else {
		memcpy(&fh, buf, sizeof(fh));
		if (strncmp(fh.type, "BM", 2)) {
			printk("File is not BMP format \n");
		} else {
			memcpy(&ih, buf + sizeof(fh), sizeof(ih));
			off = bmp_read_u32(&fh.off_bits);
			width = bmp_read_u32(&ih.width);
			height = bmp_read_u32(&ih.height);
			if (ih.bit_count != 1) {
				printf("Unsupported bit depth - %d\r\n", ih.bit_count);
			} else {



				/*
				 * Convert the picture row by row.  BMP stores the rows bottom-up and
				 * pads each one to a multiple of 4 bytes (stride); only the first
				 * (width + 7) / 8 bytes of a row hold pixels.  The panel shows the
				 * inverse of the file: every byte is inverted before
				 * pixelto4bithex_for_flash() expands it, two 1 bpp pixels into one
				 * 4 bpp panel byte.  line_buf collects one panel row and is copied
				 * to the frame buffer when the row is complete.
				 */

				bytes = (width + 7) / 8;
				stride = (width + 31) / 32 * 4;
				line_x = 0;
				line_idx = 0;
				for (int y = 0; y < height; y++) {
					line_x = 0;
					memset(buf, 0, 0x50);
					addr = FLASH_IMAGE_ADDR + off + (height - 1 - y) * stride;
					ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, bytes);
					if (ret) {
						printk("[%s-%d] read pic from flash failed !\n", __func__, __LINE__);
						break;
					}
					for (int i = 0; i < bytes; i++) {
						pixelto4bithex_for_flash(~buf[i], width, y);
					}
					if (line_buf) {
						line_idx = 0;
						memcpy(get_dashboard_state()->panel.panel_buffer[y], line_buf, LINE_BYTES);
					}
				}
			}
		}
	}
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
	int off, width, height, bytes, stride, ret;

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
	ret = get_dashboard_state()->flash_read(get_dashboard_state(),
						  idx * DEMO_IMAGE_SIZE + DEMO_IMAGE_FLASH_ADDR,
						  buf, 0x50);
	if (ret) {
		printk("[%s-%d] read pic from flash failed !\n", __func__, __LINE__);
	} else {
		memcpy(&fh, buf, sizeof(fh));
		if (strncmp(fh.type, "BM", 2)) {
			printk("File is not BMP format \n");
		} else {
			memcpy(&ih, buf + sizeof(fh), sizeof(ih));
			off = bmp_read_u32(&fh.off_bits);
			width = bmp_read_u32(&ih.width);
			height = bmp_read_u32(&ih.height);
			if (ih.bit_count != 1) {
				printf("Unsupported bit depth - %d\r\n", ih.bit_count);
			} else {



				/*
				 * Same conversion as get_demo_image_source_from_flash(), for picture
				 * idx of the DEMO_IMAGE_NUM demo pictures.  They are stored back to
				 * back, DEMO_IMAGE_SIZE bytes each, from DEMO_IMAGE_FLASH_ADDR on.
				 * The rows go through pixelto4bithex(), which also allocates
				 * line_buf on first use.  An index out of range was reset to the
				 * first picture above, so the caller always gets a picture on the
				 * panel.
				 */

				bytes = (width + 7) / 8;
				stride = (width + 31) / 32 * 4;
				line_x = 0;
				line_idx = 0;
				for (int y = 0; y < height; y++) {
					line_x = 0;
					memset(buf, 0, 0x50);
					addr = idx * DEMO_IMAGE_SIZE + DEMO_IMAGE_FLASH_ADDR + off + (height - 1 - y) * stride;
					ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, bytes);
					if (ret) {
						printk("[%s-%d] read pic from flash failed !\n", __func__, __LINE__);
						break;
					}
					for (int i = 0; i < bytes; i++) {
						pixelto4bithex(~buf[i], width, y);
					}
					if (line_buf) {
						line_idx = 0;
						memcpy(get_dashboard_state()->panel.panel_buffer[y], line_buf, LINE_BYTES);
					}
				}
			}
		}
	}
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
		if (get_dashboard_state()->canvas_x != demo_x ||
		    get_dashboard_state()->canvas_y != demo_y) {
			gui_screen_clear();
			w = 6;
			h = 5;
			for (uint8_t i = 0; i < 9; i++) {
				const uint8_t *mark;

				switch (i) {
				default:
					demo_x = get_dashboard_state()->canvas_x + 8;
					demo_y = get_dashboard_state()->canvas_y + 8;
					mark = demo_mark_left;
					break;
				case 1:
					demo_x = get_dashboard_state()->canvas_x + 8;
					demo_y = get_dashboard_state()->canvas_y + 66;
					mark = demo_mark_left;
					break;
				case 2:
					demo_x = get_dashboard_state()->canvas_x + 8;
					demo_y = get_dashboard_state()->canvas_y + 123;
					mark = demo_mark_left;
					break;
				case 3:
					demo_x = get_dashboard_state()->canvas_x + 286;
					demo_y = get_dashboard_state()->canvas_y + 8;
					mark = demo_mark_left;
					break;
				case 4:
					demo_x = get_dashboard_state()->canvas_x + 286;
					demo_y = get_dashboard_state()->canvas_y + 66;
					mark = demo_mark_left;
					break;
				case 5:
					demo_x = get_dashboard_state()->canvas_x + 286;
					demo_y = get_dashboard_state()->canvas_y + 123;
					mark = demo_mark_left;
					break;
				case 6:
					demo_x = get_dashboard_state()->canvas_x + 562;
					demo_y = get_dashboard_state()->canvas_y + 8;
					mark = demo_mark_right;
					break;
				case 7:
					demo_x = get_dashboard_state()->canvas_x + 562;
					demo_y = get_dashboard_state()->canvas_y + 66;
					mark = demo_mark_right;
					break;
				case 8:
					demo_x = get_dashboard_state()->canvas_x + 562;
					demo_y = get_dashboard_state()->canvas_y + 123;
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
		get_demo_picture(0, &w, &h);
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

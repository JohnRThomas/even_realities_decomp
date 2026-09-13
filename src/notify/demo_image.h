/* Demo / calibration pictures (demo_image.c) and their BMP file / info headers */
#ifndef G1_DEMO_IMAGE_H_
#define G1_DEMO_IMAGE_H_

#include <stdint.h>
#include <zephyr/toolchain.h>
#include <glasses_state.h>

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

/* demo_image.c */
extern uint8_t demo_mode;
extern uint8_t *line_buf; /* heap line buffer */
void get_demo_image_source_from_flash(void);
void demo_image_select(uint8_t idx);
void demo_image_next(void);
int ui_demo_image_task(struct jbd_panel_context *panel, void *arg, int event);
int draw_template_new_message_page(struct jbd_panel_context *panel, void *arg);

#endif /* G1_DEMO_IMAGE_H_ */

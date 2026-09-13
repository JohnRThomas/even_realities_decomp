/*
 * JBD013VGA micro-LED panel layer (jbd_panel.c, jbd013_api.c, hal_driver.c).
 * Partial views of the vendor structures, reconstructed from the v1.63 app core.
 */
#ifndef G1_PANEL_H_
#define G1_PANEL_H_

#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>

/* JBD013VGA SPI commands (jbd013_api.h) */
#define SPI_WR_ENABLE            0x06
#define SPI_WR_STATUS_REG1       0x01
#define SPI_WR_STATUS_REG2       0x31
#define SPI_WR_CURRENT_REG       0x46
#define SPI_WR_LUM_REG           0x36
#define SPI_WR_OFFSET_REG        0xc0
#define SPI_RD_ID                0x9f
#define SPI_SYNC                 0x97
#define SPI_RST_EN               0x66
#define SPI_RST                  0x99
#define SPI_DISPLAY_ENABLE       0xa3
#define SPI_DISPLAY_DISABLE      0xa9
#define SPI_DISPLAY_DEFAULT_MODE 0x71
#define SPI_DISPLAY_RL           0x73
#define SPI_DEEP_POWER_DOWN      0xb9
#define SPI_WR_BUFFER            0x02

#define JBD_PANEL_DEVICE_ID      0x4010

#define PANEL_WIDTH              640
#define PANEL_FB_ROWS            200
#define PANEL_FB_STRIDE          (PANEL_WIDTH / 2)          /* 4 bpp */
#define PANEL_FB_SIZE            (PANEL_FB_ROWS * PANEL_FB_STRIDE)

/* GLOBAL_STATE->spi (0xb10): spi_interface_t */
struct spi_interface {
	int (*init_cb)(struct spi_interface *spi);                     /* 0x00 */
	int (*deinit)(struct spi_interface *spi);                      /* 0x04 */
	int (*rx_tx)(struct spi_interface *spi, const uint8_t *tx, size_t tx_len,
		     uint8_t *rx, size_t rx_len);                     /* 0x08 */
	uint8_t pad_0c[0x14 - 0x0c];
	uint32_t is_initialized;                                       /* 0x14 */
	uint8_t pad_18[0x20 - 0x18];
};

struct jbd_panel_context;
typedef int (*panel_cb_t)(struct jbd_panel_context *c);

/* GLOBAL_STATE->jdb_panel_context (0xb6c), 0x37c bytes */
struct jbd_panel_context {
	panel_cb_t init_cb;                      /* 0x000 */
	panel_cb_t suspend_cb;                   /* 0x004 */
	panel_cb_t resume_cb;                    /* 0x008 */
	panel_cb_t off_cb;                       /* 0x00c */
	panel_cb_t on_cb;                        /* 0x010 */
	void *panel_cb_14;                       /* 0x014 (0x36e11, gui) */
	void (*draw_image_cb)(struct jbd_panel_context *c);           /* 0x018 */
	void *(*clear_cb)(struct jbd_panel_context *c);               /* 0x01c */
	int (*set_brightness_cb)(struct jbd_panel_context *c, uint8_t level); /* 0x020 */
	uint8_t *panel_buffer[PANEL_FB_ROWS];    /* 0x024 frame buffer row pointers */
	uint8_t *current_buffer;                 /* 0x344 */
	uint32_t current_row;                    /* 0x348 */
	uint32_t current_column;                 /* 0x34c */
	uint32_t current_buffer_size;            /* 0x350 */
	uint8_t raster_height_offset;            /* 0x354 */
	uint8_t pad_355[0x358 - 0x355];
	uint32_t y_offset;                       /* 0x358 */
	uint32_t init_done;                      /* 0x35c */
	uint8_t pad_360[0x369 - 0x360];
	uint8_t panel_brightness_level;          /* 0x369 */
	uint8_t pad_36a[2];
	uint16_t brightness_max;                 /* 0x36c (gs + 0xed8) */
	uint8_t pad_36e[0x374 - 0x36e];
	uint8_t brightness_percent;              /* 0x374 (gs + 0xee0) */
	uint8_t pad_375[3];
	struct spi_interface *spi_callbacks;     /* 0x378 */
};
BUILD_ASSERT(offsetof(struct jbd_panel_context, current_buffer) == 0x344);
BUILD_ASSERT(offsetof(struct jbd_panel_context, init_done) == 0x35c);
BUILD_ASSERT(offsetof(struct jbd_panel_context, spi_callbacks) == 0x378);
BUILD_ASSERT(sizeof(struct jbd_panel_context) == 0x37c);

/* Partial view of the global vendor state (struct GlassesState) */
struct panel_gs {
	uint8_t pad_000[0xb10];
	struct spi_interface spi;                /* 0xb10 */
	uint8_t pad_b30[0xb6c - 0xb30];
	struct jbd_panel_context panel;          /* 0xb6c */
	uint8_t pad_ee8[0x1070 - 0xee8];
	uint16_t module_mask;                    /* 0x1070 */
} __aligned(8);
BUILD_ASSERT(offsetof(struct panel_gs, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct panel_gs, module_mask) == 0x1070);

#define LP_JBD_BIT BIT(8)

struct GlassesState;
struct GlassesState *get_dashboard_state(void);
#define PANEL_GS() ((struct panel_gs *)get_dashboard_state())

/* jbd_panel.c */
extern uint32_t JDB_PANEL_ID;
void lock_lcd_mutex(k_timeout_t timeout);
int unlock_lcd_mutex(void);
void set_brightness_to_panel_reg(uint8_t level);
void set_brightness_to_panel_reg_in_running(uint8_t level);
void wr_lum_and_cur_reg(uint16_t lum_value, uint8_t cur_value);
int jbd_panel_suspend(void);
int jbd_panel_resume(struct jbd_panel_context *c);

/* panel_fb.c */
void update_brightness_level_for_jdb_panel(uint8_t level, uint16_t *lum, uint8_t *cur);
void *clear_panel(struct jbd_panel_context *c);
void panel_draw_cb(struct jbd_panel_context *c);
struct jbd_panel_context *get_jdb_panel_context(void);

/* jbd013_api.c */
void send_cmd(uint8_t cmd);
void wr_status_reg(uint8_t reg, uint8_t data);
void wr_offset_reg(uint8_t row, uint8_t col);
void wr_cur_reg(uint8_t param);
void wr_lum_reg(uint16_t param);
void clr_cache(uint8_t val);
void display_image(uint32_t row, uint32_t col, uint8_t *buf, int len);
void panel_rst(void);
void panel_init(void);

/* hal_driver.c */
void delay_ms(uint32_t ms);
void spi_send_cmd(uint8_t cmd);
int spi_tx_data(const uint8_t *buf, uint32_t len);
void spi_tx_frame(uint8_t cmd, const uint8_t *param, uint32_t len);
void spi_wr_buffer(uint16_t col, uint16_t row, uint8_t *buf, uint32_t len);
uint16_t spi_read_id(void);

#endif /* G1_PANEL_H_ */

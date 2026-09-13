/*
 * JBD013VGA micro-LED panel layer (jbd_panel.c, panel_fb.c, jbd_panel_flush.c,
 * jbd013_api.c, hal_driver.c).
 * Partial views of the vendor structures, reconstructed from the v1.63 app core.
 */
#ifndef G1_PANEL_H_
#define G1_PANEL_H_

#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <glasses_state.h>

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
#define PANEL_FB_STRIDE          (PANEL_WIDTH / 2)          /* 4 bpp */
#define PANEL_FB_SIZE            (PANEL_FB_ROWS * PANEL_FB_STRIDE)

#define LP_JBD_BIT BIT(8)

/* jbd_panel.c */
void set_brightness_to_panel_reg(uint8_t level);
void wr_lum_and_cur_reg(uint16_t lum_value, uint8_t cur_value);
void set_brightness_to_panel_reg_in_running(uint8_t level);
void register_jdb_panel_context(struct jbd_panel_context *c);

/* panel_fb.c */
int _clean_fb_data(uint8_t **fb, int val, int x_start, int y_start, int x_end, int y_end);
void update_brightness_level_for_jdb_panel(uint8_t level, uint16_t *lum, uint8_t *cur);
void *clear_panel(struct jbd_panel_context *c);
void panel_draw_cb(struct jbd_panel_context *c);
struct jbd_panel_context *get_jdb_panel_context(void);
int copy_to_frame_buffer_raw(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y);
int copy_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y);
int or_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w, int h, int x, int y);
void copy_frame_buffer_rows(uint8_t **fb, int dst_x, int dst_y, int src_x, int src_y, int h, int w);

/* jbd_panel_flush.c */
extern uint32_t JDB_PANEL_ID;
extern struct k_mutex lcd_mutex;
int _reflash_fb_data_to_lcd(uint32_t row, uint32_t column, int x_start, int y_start,
			    int x_end, int y_end);
int _reflash_fb_data_to_lcd_ex(uint32_t row, uint32_t column, int x_start, int y_start,
			       int x_end, int y_end, int offset);
int jbd_panel_suspend(void);
int jbd_panel_resume(struct jbd_panel_context *c);
void lock_lcd_mutex(k_timeout_t timeout);
int unlock_lcd_mutex(void);

/* jbd013_api.c */
void send_cmd(uint8_t cmd);
void wr_status_reg(uint8_t reg, uint8_t data);
void wr_offset_reg(uint8_t row, uint8_t col);
void wr_cur_reg(uint8_t param);
void wr_lum_reg(uint16_t param);
void clr_cache(uint8_t val);
void jbd_clear_cache_sync(uint8_t val); /* clear panel cache + sync */
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

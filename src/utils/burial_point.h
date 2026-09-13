/*
 * Module-private declarations for common_utils.c and burial_point.c
 * (part of the panel_display module).  Reconstructed from the v1.63 app core.
 */
#ifndef PANEL_DISPLAY_BURIAL_POINT_H_
#define PANEL_DISPLAY_BURIAL_POINT_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/toolchain.h>
#include <glasses_state.h>

#include <g1_date.h> /* struct bp_date, init_burial_point_date() */

/* common_utils.c */
const char *get_weekday_name(uint32_t ts);
int format_float_2dp(float val, char *buf);
void dump_ancs(const char *tag, struct notif_msg *n);
void dump_hex(const char *tag, const uint8_t *data, int len);
void accumulate_elapsed_seconds(uint32_t *total_s, int idx, int restart);
void set_wall_clock_ms(int64_t ts);
void get_wall_clock_ms(int64_t *ts);
void init_boot_seconds(void);
int get_boot_seconds(void);
int uint32_to_little_endian(uint8_t *buf, uint32_t val);
uint16_t crc16_generic(uint16_t crc, uint16_t poly, uint16_t xorout, int refin, bool refout,
		      const uint8_t *data, int len);
uint16_t crc16_usb(uint16_t crc, const uint8_t *buf, int len);
int rle_decode(const uint8_t *src, uint32_t len, uint8_t *dst);

/* burial_point.c */
int update_burial_point_day_index(void);
uint8_t get_burial_point_day_index(void);
void exit_wear_burial_point(void);
void add_wear_burial_time(int64_t ms);
void enter_wear_burial_point(void);
int64_t get_dashboard_sum_time(void);
void add_dashboard_burial_time(int64_t ms);
void enter_dashboard_burial_point(void);
void exit_dashboard_burial_point(void);
int64_t get_notification_sum_time(void);
void add_notification_burial_time(int64_t ms);
void enter_notification_burial_point(void);
void exit_notification_burial_point(void);
void burial_point_record_info_init(void);

#endif

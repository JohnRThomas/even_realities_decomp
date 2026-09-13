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

#include <g1_date.h> /* struct bp_date, init_burial_point_date() */

struct ancs_notif_data;

/* common_utils.c */
const char *FUN_0004d2cc(uint32_t ts);
int FUN_0004d328(float val, char *buf);
void dump_ancs(const char *tag, struct ancs_notif_data *data);
void dump_hex(const char *tag, const uint8_t *data, int len);
void FUN_0004d494(uint32_t *total_s, int idx, int restart);
void FUN_0004d4dc(int64_t ts);
void FUN_0004d4f8(int64_t *ts);
void FUN_0004d528(void);
int get_boot_seconds(void);
int uint32_to_little_endian(uint8_t *buf, uint32_t val);
uint16_t crc16_generic(uint16_t crc, uint16_t poly, uint16_t xorout, int refin, bool refout,
		      const uint8_t *data, int len);
uint16_t FUN_000811a0(uint16_t crc, const uint8_t *buf, int len);
int rle_decode(const uint8_t *src, uint32_t len, uint8_t *dst);

/* one day of statistics (7-day ring in struct bp_context) */
struct bp_day {
	uint16_t year;      /* 0x0 */
	uint8_t month;      /* 0x2 */
	uint8_t day;        /* 0x3 */
	uint32_t sum_time;  /* 0x4 seconds */
	uint32_t count;     /* 0x8 */
};

/* GlassesState + 0x1128 (0x11c bytes, saved to flash 0x135000 = storage's struct burial_point) */
struct bp_context {
	uint32_t id;                         /* 0x00 */
	uint32_t wear_sum_time;              /* 0x04 */
	uint32_t wear_count;                 /* 0x08 */
	uint32_t dashboard_sum_time;         /* 0x0c */
	uint32_t dashboard_count;            /* 0x10 */
	uint8_t version;                     /* 0x14 */
	uint8_t day_index;                   /* 0x15 */
	uint8_t valid;                       /* 0x16 */
	uint8_t pad_17;
	struct bp_day wear_day[7];           /* 0x18 */
	struct bp_day dashboard_day[7];      /* 0x6c */
	uint32_t notification_sum_time;      /* 0xc0 */
	uint32_t notification_count;         /* 0xc4 */
	struct bp_day notification_day[7];   /* 0xc8 */
};

/* running session, 0x1a bytes (cleared by burial_point_record_info_init) */
struct bp_session {
	uint8_t active;        /* 0x00 */
	uint8_t day_index;     /* 0x01 */
	int64_t start_time;    /* 0x02 k_uptime_get() */
	uint8_t pad_0a[0x10];
} __packed;

/*
 * partial view of struct GlassesState.  The real struct is 8-byte aligned (it has
 * int64 members): with only 4-byte alignment GCC addresses gs+0x1110 differently.
 */
struct bp_gs {
	uint8_t pad_000[0x10da];
	struct bp_session dashboard;     /* 0x10da */
	struct bp_session wear;          /* 0x10f4 */
	struct bp_session notification;  /* 0x110e */
	struct bp_context bp;            /* 0x1128 */
} __aligned(8);

BUILD_ASSERT(sizeof(struct bp_context) == 0x11c);
BUILD_ASSERT(offsetof(struct bp_gs, wear) == 0x10f4);
BUILD_ASSERT(offsetof(struct bp_gs, bp) == 0x1128);

#define BP_GS() ((struct bp_gs *)get_dashboard_state())

/* burial_point.c */
int update_burial_point_day_index(void);
uint8_t FUN_00081216(void);
void FUN_00081230(void);
void FUN_00081258(int64_t ms);
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

/* external */
uint32_t get_dashboard_tx_ctx(void);
uint8_t FUN_00033d5c(void);
struct GlassesState;
struct GlassesState *get_dashboard_state(void);
int day_of_week(uint16_t year, uint16_t month, uint16_t day);
const char *get_string(uint8_t string_id);

#endif

/*
 * Small vendor helpers: UTC -> date conversion, weekday name, float
 * formatting, ANCS / hex dumps, uptime based timekeeping, generic CRC16 and a
 * run-length decoder.  Reconstructed from the v1.63 app core (original file
 * name unknown).
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "burial_point.h"

/* NB: not parenthesised in the vendor code ("i == 1 && IS_LEAP_YEAR(y)"). */
#define IS_LEAP_YEAR(y) ((y) % 4 == 0 && (y) % 100 != 0) || (y) % 400 == 0

#define SECONDS_PER_DAY 86400

/* partial view of struct ancs_notif_data (ble_ancs.h) */
struct bp_ancs_notif {
	uint32_t msg_id;            /* 0x000 */
	uint32_t f_004;             /* 0x004 */
	uint32_t uid;               /* 0x008 */
	uint8_t pad_00c[4];
	char app_identifier[32];    /* 0x010 */
	char display_name[32];      /* 0x030 */
	char title[32];             /* 0x050 */
	char subtitle[32];          /* 0x070 */
	char message[256];          /* 0x090 */
	char date[32];              /* 0x190 */
};

static const uint16_t days_of_month[12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

static uint32_t boot_uptime_s;          /* 0x2000aa90 */
static uint32_t duration_ref_ms[4];     /* 0x2000aa80 */
static int64_t time_base_uptime;        /* 0x20004fd8 */
static int64_t time_base;               /* 0x20004fd0 */

int init_burial_point_date(uint32_t timestamp, struct bp_date *date)
{
	uint32_t days = timestamp / SECONDS_PER_DAY;
	uint32_t secs = timestamp % SECONDS_PER_DAY;
	uint16_t year = 1970;
	uint16_t month;
	uint16_t n;

	while (1) {
		n = IS_LEAP_YEAR(year) ? 366 : 365;
		if (days < n) {
			break;
		}
		days -= n;
		year++;
	}
	date->year = year;

	for (month = 0; month < 12; month++) {
		n = days_of_month[month];
		if (month == 1 && IS_LEAP_YEAR(year)) {
			n = 29;
		}
		if (days < n) {
			break;
		}
		days -= n;
	}

	date->month = month + 1;
	date->day = days + 1;
	date->hour = secs / 3600;
	secs %= 3600;
	date->minute = secs / 60;
	date->second = secs % 60;

	return 0;
}

/* weekday name of a UTC timestamp */
const char *FUN_0004d2cc(uint32_t ts)
{
	struct bp_date date = { 0 };

	init_burial_point_date(ts, &date);
	printk("date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n", ts, date.year, date.month, date.day,
	       date.hour, date.minute, date.second);

	return get_string((uint8_t)(day_of_week(date.year, date.month, date.day) + 0x3b));
}

/* formats val with two decimals and a sign ("+1.23", "-0.05"); returns the length */
int FUN_0004d328(float val, char *buf)
{
	int v = (int)(val * 100);
	uint32_t a = abs(v);
	char tmp[12] = { 0 };
	char *p = buf;
	int mode;
	int n = 0;
	int i;

	if (a < 10) {
		mode = 2;
	} else if (a < 100) {
		mode = 1;
	} else {
		mode = 0;
	}

	while (a) {
		uintptr_t dst;

		if (n == 2 && mode == 0) {
			tmp[2] = '.';
			n = 3;
		}
		dst = (uintptr_t)tmp;
		dst += n++;
		*(char *)dst = a % 10 + '0';
		a /= 10;
	}

	if (mode == 2) {
		tmp[n++] = '0';
	}
	*p = (v <= 0) ? '-' : '+';

	if (mode != 0) {
		p[1] = '0';
		p[2] = '.';
		p += 2;
		for (i = n - 1; i >= 0; i--) {
			*++p = tmp[i];
		}
		return n + 3;
	}

	for (i = 0; i < n; i++) {
		p[1 + i] = tmp[n - 1 - i];
	}
	p[n + 1] = '\0';
	return n + 1;
}

/*
 * Full ANCS notification dump.  Nothing calls it (--gc-sections drops the code), but GCC emits
 * its strings first, so dump_ancs' strings share its .rodata string section: that is where the
 * target's unused "dump begin" / subtitle / date / display_name strings come from.
 */
void dump_ancs_detail(const char *tag, struct ancs_notif_data *data)
{
	struct bp_ancs_notif *n = (struct bp_ancs_notif *)data;

	printk("##############(dump begin:%s)###############\n", tag);
	printk("app_identifier:(%s)\n", n->app_identifier);
	printk("subtitle:(%s)\n", n->subtitle);
	printk("message:(%s)\n", n->message);
	printk("message_size:(%s)\n", n->title);   /* argument unknown (code is never linked) */
	printk("date:(%s)\n", n->date);
	printk("display_name:(%s)\n", n->display_name);
	printk("uid :(%d)\n", n->uid);
}

void dump_ancs(const char *tag, struct ancs_notif_data *data)
{
	struct bp_ancs_notif *n = (struct bp_ancs_notif *)data;

	if (BLE_DEBUG) {
		ble_printk("app_identifier:(%s)\n", n->app_identifier);
	} else {
		printk("app_identifier:(%s)\n", n->app_identifier);
	}
	if (BLE_DEBUG) {
		ble_printk("message:(%s)\n", n->message);
	} else {
		printk("message:(%s)\n", n->message);
	}
	if (BLE_DEBUG) {
		ble_printk("uid :(%d)\n", n->uid);
	} else {
		printk("uid :(%d)\n", n->uid);
	}
}

void dump_hex(const char *tag, const uint8_t *data, int len)
{
	printk("dump_hex(%s):", tag);
	for (int i = 0; i < len; i++) {
		if ((i & 7) == 0) {
			printk("\n");
		}
		printk("0x%02x,", data[i]);
	}
	printk("\n");
}

/* accumulates whole seconds elapsed since the last call into *total_s */
void FUN_0004d494(uint32_t *total_s, int idx, int restart)
{
	uint32_t now, d;

	if (restart) {
		duration_ref_ms[idx] = k_uptime_get();
	} else {
		now = k_uptime_get();
		if (duration_ref_ms[idx] == 0) {
			duration_ref_ms[idx] = now;
		} else {
			d = now - duration_ref_ms[idx];
			if (d >= 1000) {
				d /= 1000;
				*total_s += d;
				duration_ref_ms[idx] += d * 1000;
			}
		}
	}
}

/* sets the wall clock */
void FUN_0004d4dc(int64_t ts)
{
	time_base = ts;
	time_base_uptime = k_uptime_get();
}

/* current wall clock */
void FUN_0004d4f8(int64_t *ts)
{
	*ts = k_uptime_get() - time_base_uptime + time_base;
}

void FUN_0004d528(void)
{
	boot_uptime_s = k_uptime_get() / 1000;
}

int get_boot_seconds(void)
{
	int s = k_uptime_get() / 1000 - boot_uptime_s;

	G1_LOG_INF("[csh_debug] bootSeconds is %d\n", s);

	return s;
}

int uint32_to_little_endian(uint8_t *buf, uint32_t val)
{
	if (buf == NULL) {
		G1_LOG_WRN("buf is NULL !\n");
		return 0;
	}

	buf[0] = val;
	buf[1] = val >> 8;
	buf[2] = val >> 16;
	buf[3] = val >> 24;

	return 1;
}

/* generic CRC-16 (init, poly, xorout, reflect in / out) */
uint16_t crc16_generic(uint16_t crc, uint16_t poly, uint16_t xorout, int refin, bool refout,
		      const uint8_t *data, int len)
{
	uint16_t out;
	uint8_t b, r;
	int i, j;

	if (data == NULL) {
		return 0;
	}
	if (len <= 0) {
		return 0;
	}

	for (i = 0; i < len; i++) {
		b = data[i];
		if (refin) {
			r = 0;
			for (j = 7; j >= 0; j--) {
				if (b & 1) {
					r |= 1 << j;
				}
				b >>= 1;
			}
			b = r;
		}
		crc ^= b << 8;
		for (j = 0; j < 8; j++) {
			if (crc & 0x8000) {
				crc = (crc << 1) ^ poly;
			} else {
				crc <<= 1;
			}
		}
	}

	if (refout) {
		out = 0;
		for (j = 15; j >= 0; j--) {
			if (crc & 1) {
				out |= 1 << j;
			}
			crc >>= 1;
		}
		crc = out;
	}

	return xorout ^ crc;
}

uint16_t FUN_000811a0(uint16_t crc, const uint8_t *buf, int len)
{
	if (buf == NULL || len <= 0) {
		return 0;
	}

	return crc16_generic(crc, 0x8005, 0xffff, 1, 1, buf, len);
}

/* (count, value) pair run-length decoder; returns the decoded length */
int rle_decode(const uint8_t *src, uint32_t len, uint8_t *dst)
{
	int out = 0;

	for (uint32_t i = 0; i < len; i += 2) {
		uint8_t cnt = src[i];

		memset(dst + out, src[i + 1], cnt);
		out += cnt;
	}

	return out;
}

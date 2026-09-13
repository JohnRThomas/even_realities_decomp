/*
 * Date helpers shared by several modules.
 *
 * init_burial_point_date() (panel_display/common_utils.c) splits a UTC time
 * stamp into six uint16_t fields; FUN_00080732() / set_date()
 * (dashboard/dashboard.c) read / write the current time stamp
 * (GlassesState + 0xd0).
 */
#ifndef G1_DATE_H_
#define G1_DATE_H_

#include <stdint.h>

struct bp_date {
	uint16_t year;   /* 0x0 */
	uint16_t month;  /* 0x2 1..12 */
	uint16_t day;    /* 0x4 1..31 */
	uint16_t hour;   /* 0x6 */
	uint16_t minute; /* 0x8 */
	uint16_t second; /* 0xa */
};

int init_burial_point_date(uint32_t timestamp, struct bp_date *date);
uint32_t FUN_00080732(void);
uint32_t set_date(uint32_t ts);

#endif /* G1_DATE_H_ */

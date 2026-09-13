/*
 * Production-test (PT) protocol: command handlers and frame processing.
 *
 * Original file name unknown (src/production_test/<?>.c, > 3100 lines,
 * judging by the __LINE__ values).  The vendor file is longer and ordered
 * differently: the handlers whose logs print __LINE__ start with a #line
 * directive giving their line in the vendor file.  Several handlers carry a copy-pasted
 * name in their error message (three "get_mac_info", two "set_restart_mode",
 * two "get_keyboard_info"); the duplicates got a numeric suffix here.
 */
#define DMIC_STREAM_STOP_VOID_PROTOTYPE /* dmic_stream_stop() returns void here (sensors_audio.h) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "production_test.h"
#include "../aw9320x/aw9320x.h"
#include "../imu/imu_fusion.h"
#include "../main.h"
#include "../nfc/nfc_wlc.h"
#include "../notify/demo_image.h"
#include "../panel_display/panel.h"
#include "../sensors_audio/sensors_audio.h"
#include "../storage/storage.h"
#include "../threads/threads.h"

#define MIC_DATA_CHUNK 240
#define MIC_TRANSM_CHUNK 200
#define MIC_TRANSM_FRAME (6 + MIC_TRANSM_CHUNK)

/* bytes of the serial number / glasses SN the factory tool sends and reads back */
#define PT_SN_LEN         14
#define PT_GLASSES_SN_LEN 11

/* "[%s-%d]" style messages: BLE_DEBUG only, no LOG_LEVEL gate */
#define PT_PRINT(fmt, ...)                                                          \
	do {                                                                        \
		if (BLE_DEBUG) {                                                    \
			ble_printk(fmt, ##__VA_ARGS__);                             \
		} else {                                                            \
			printk(fmt, ##__VA_ARGS__);                                 \
		}                                                                   \
	} while (0)

/* ------------------------------------------------------------------ */
/* module data                                                         */
/* ------------------------------------------------------------------ */
/*
 * Defined in reverse address order (GCC emits a file's variables in reverse
 * definition order inside each alignment group).
 */

/* .bss, 8-byte aligned */
int64_t pt_timeout_ms;                   /* uptime (get_mac_info_2) or uptime + 10 s (set_pt_deadline); no reader in this image */
static struct k_thread aging_thread;     /* aging_test_thread */
struct k_thread mic_transm_thread_data;            /* mic_transm_thread (start_mic_transm_thread) */
static int64_t discharge_test_start_ms;             /* discharge test start (ms) */

/* .bss, 4-byte aligned */
static uint32_t charger_retry_last_ms;            /* enable_charger_retry rate limit (ms) */
static int mic_retransmit_count;                 /* mic read: retransmit counter */
struct k_sem mic_transm_sem;        /* mic_transm_thread trigger */
static uint32_t battery_info_last_ms;            /* get_battery_info rate limit (ms) */

/* .bss, 2-byte aligned */
static uint16_t mic_chunk_index;            /* mic read: chunk index */
static uint16_t lux_calibrated_mask;            /* set_lux_base: calibrated points mask */

/* .bss, 1-byte aligned */
uint8_t pt_uart_frame[256];               /* UART frame scratch (process_pt_protocol) */
static union {
	uint8_t raw;
	struct {
		uint8_t level : 7;
		uint8_t flag : 1;
	} bits;
} pt_level_flags;
uint8_t pt_test_mode;                    /* production test mode */
static uint8_t aging_phase;             /* aging: 1 = charging, 2 = discharging */
static uint8_t aging_mode;             /* aging mode */
static uint8_t aging_thread_started;             /* aging thread started */
static uint8_t charger_retry_fail_count;
static bool battery_full_flag;
static uint8_t battery_high_v_count;
static uint8_t battery_full_count;
static uint8_t mic_chunk_buf[MIC_DATA_CHUNK];
static uint8_t flash_info_cache[0x4e];

/* .data */
static uint32_t mic_flash_addr = 0x400000; /* mic data base address in ext flash */
static bool charger_enable_ok = true;

/* .noinit */
static K_THREAD_STACK_DEFINE(aging_thread_stack, 1024); /* reverse definition order */
K_THREAD_STACK_DEFINE(mic_transm_thread_stack, 1024);        /* mic_transm_thread stack */

int get_mac_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_mac_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x07;
	p[1] = 1;
	p[2] = 2;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;
	set_box_status(1, false);
	can_enter_low_power = 0;

	return 0;
}

int get_mac_info_2(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			  uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_mac_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x08;
	p[1] = 1;
	p[2] = 2;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;
	set_box_status(1, true);
	nfc_deadline_set(10000);
	pt_timeout_ms = k_uptime_get();

	return 0;
}

int get_keyboard_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			     uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_keyboard_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x2f;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	get_dashboard_state()->aw_diff = 0;
	p[4] = get_dashboard_state()->aw_diff != 0;
	*resp_len = 5;

	return 0;
}

int set_battery_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			    uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	int16_t v;

	if (resp == NULL || resp_len == NULL) {
		printk("set_battery_info para is NULL\n");
		return -1;
	}

	get_charger_device();
	p = *resp;
	p[0] = 0x11;
	p[1] = 1;
	p[2] = 3;
	p[3] = 7;
	p[4] = get_dashboard_state()->battery_left;
	p[5] = get_dashboard_state()->battery_voltage;
	p[6] = get_dashboard_state()->battery_current_ma <= 0;
	p[7] = abs(get_dashboard_state()->battery_current_ma);
	p[8] = get_dashboard_state()->battery_temp_x100 > 0;
	v = abs(get_dashboard_state()->battery_temp_x100);
	p[9] = (uint16_t)v >> 8;
	p[10] = v;
	*resp_len = 0x0b;

	return 0;
}

int set_imu_base(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	uint8_t retry;
	uint32_t base;

	if (resp == NULL || resp_len == NULL) {
		printk("set_imu_base para is NULL\n");
		return -1;
	}
	if (get_pt_test_mode() != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x2d;
	p[1] = 1;
	p[2] = 3;
	p[3] = 5;

	char buf[20] = {0};

	if (imu_yaw_x100 == 0 && imu_pitch_x100 == 0 && imu_roll_x100 == 0 &&
	    get_dashboard_state()->accel[0] == 0 && get_dashboard_state()->accel[1] == 0 &&
	    get_dashboard_state()->accel[2] == 0) {
		p[4] = 1;
	} else {
		/* uint32_t -> int store: fetch the state first so the load stays after the call */
		struct GlassesState *gs = get_dashboard_state();

		gs->imu.ref = imu_pitch_x100;
		p[4] = 0;
	}
	sprintf(buf, "base: %d", imu_pitch_x100);
	*(uint32_t *)(p + 5) = get_dashboard_state()->imu.ref;
	save_sys_settings(get_dashboard_state(), 0);

	base = get_dashboard_state()->imu.ref;
	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0 && settings.imu_base == base) {
			break;
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 2;
	}
	*resp_len = 9;

	return 0;
}

int set_charge_limit(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			    uint8_t *resp_len, void *arg)
{
	struct usr_settings settings;
	uint8_t *p;
	uint8_t upper, lower;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL) {
		printk("set_charge_limit para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x40;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	upper = req[4];
	lower = req[5];
	if (upper >= 100) {
		upper = 100;
	}
	if (lower >= 100) {
		lower = 100;
	}
	if (req[4] == 0) {
		enable_charger();
	}
	get_dashboard_state()->charge_limit_upper = upper;
	get_dashboard_state()->charge_limit_lower = lower;
	save_usr_settings(get_dashboard_state(), 0);

	for (retry = 0; retry < 5; retry++) {
		if (read_usr_settting_from_flash(&settings) == 0 &&
		    settings.charge_limit_upper == upper &&
		    settings.charge_limit_lower == lower) {
			break;
		}
		k_msleep(100);
	}
	p[4] = (retry == 5);
	*resp_len = 5;

	return 0;
}

int get_query_sn_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			     uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL) {
		printk("get_query_sn_info para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	const uint8_t *sn = req + 4;
	p = *resp;
	save_serial_number(sn);
	printf("The string is: %s\n", sn);
	save_sys_settings(get_dashboard_state(), 0);
	p[0] = 0x1c;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;

	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0 &&
		    memcmp(req + 4, settings.sn, PT_SN_LEN) == 0) {
			break;
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 1;
	}

	return 0;
}

int set_brightness(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			  uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint8_t level;
	uint8_t ret = 1;

	if (resp == NULL || resp_len == NULL) {
		printk("set_brightness para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x33;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	level = req[4];
	if (get_dashboard_state()->panel.panel_brightness_level != level) {
		get_dashboard_state()->panel.set_brightness_cb(&get_dashboard_state()->panel,
							 level);
		ret = 0;
	}
	p[4] = ret;
	*resp_len = 5;

	return 0;
}

int get_keyboard_info_2(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_keyboard_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x18;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	if ((uint32_t)get_dashboard_state()->aw_diff > 255000) {
		p[4] = 0xff;
		printk("before aw9320x_diff_get: %d\n", get_dashboard_state()->aw_diff);
	} else {
		p[4] = (uint32_t)get_dashboard_state()->aw_diff / 1000;
		printk("before aw9320x_diff_get: %d\n", get_dashboard_state()->aw_diff);
	}
	aw9320x_diff_get(&get_dashboard_state()->aw_diff);
	printk("after aw9320x_diff_get: %d\n", get_dashboard_state()->aw_diff);
	*resp_len = 5;

	return 0;
}

int set_restart_mode(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			    uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("set_restart_mode para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x0b;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int set_restart_mode_2(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			      uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("set_restart_mode para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0xe1;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;
	get_dashboard_state()->force_bind = 2;

	return 0;
}

int get_mic_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_mic_info para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x19;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;
	request_dmic_stream_start();
	mic_chunk_index = 0;
	mic_retransmit_count = 0;
	mic_flash_addr = 0x400000;

	return 0;
}

int set_panel_voltage(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			     uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint8_t val;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 5) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}

	p = *resp;
	p[0] = 0x3c;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	val = req[4];
	if (val > 1) {
		p[4] = 3;
	} else if (get_dashboard_state()->panel.voltage == val) {
		p[4] = 4;
	} else {
		struct sys_settings settings;

		get_dashboard_state()->panel.voltage = val;
		save_sys_settings(get_dashboard_state(), 0);
		for (retry = 0; retry < 5; retry++) {
			if (read_sys_settting_from_flash(&settings) == 0 &&
			    settings.panel_voltage == val) {
				break;
			}
			k_msleep(100);
		}
		p[4] = (retry == 5);
	}
	*resp_len = 5;

	return 0;
}

int get_flash_info_2(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			  uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint16_t size;

	if (resp == NULL || resp_len == NULL) {
		printk("get_flash_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x16;
	p[1] = 1;
	p[2] = 3;
	p[3] = 0x0b;
	p[4] = get_dashboard_state()->ext_flash_ok != 0;
	size = get_dashboard_state()->flash_page_count * 4;
	p[5] = size;
	p[6] = size >> 8;
	*(uint32_t *)(p + 7) = 0;
	p[11] = 0;
	*(int *)(p + 12) = opt3007_read(0);
	*resp_len = 0x10;

	return 0;
}

int exit_mic_mode(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			 uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("exit_mic_mode para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x1a;
	p[1] = 1;
	p[4] = 0;
	p[2] = 3;
	p[3] = 1;
	*resp_len = 5;
	dmic_stream_stop();
	k_sem_give(&get_dashboard_state()->main_sem);

	return 0;
}

int get_sn_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		       uint8_t *resp_len, void *arg)
{
	char buf[32] = {0};
	uint8_t *p;
	size_t len;

	if (resp == NULL || resp_len == NULL) {
		printk("get_sn_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x22;
	p[1] = req[1];
	p[2] = 3;
	sprintf(buf, "%s", get_serial_number());
	len = strlen(buf);
	p[3] = len;
	memcpy(p + 4, buf, len);
	*resp_len = len + 4;

	return 0;
}

int set_mic_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(mx25r64));
	uint8_t *p;
	uint32_t addr;
	uint32_t sum;
	int err;
	int cnt;
	int i;

	if (resp == NULL || resp_len == NULL) {
		printk("get_mic_info para is NULL\n");
		return -1;
	}

	p = *resp;
	if (req[4] == 0) {
		mic_chunk_index++;
	} else {
		mic_retransmit_count++;
	}

	if (!device_is_ready(flash_dev)) {
		G1_LOG_ERR(" [%s] device not ready.\n", flash_dev->name);
		p[0] = 0x1b;
		p[1] = 1;
		p[2] = 3;
		p[3] = 1;
		p[4] = 1;
		*resp_len = 5;
		return 0;
	}

	if (get_dashboard_state()->flash_read != 0) {
		addr = mic_chunk_index * MIC_DATA_CHUNK + mic_flash_addr;
		printk("Flash read addr 0x%x  \n", addr);
		err = flash_read(flash_dev, addr, mic_chunk_buf, MIC_DATA_CHUNK);
		if (err) {
			printk("Flash read failed! %d\n", err);
			p[0] = 0x1b;
			p[1] = 1;
			p[2] = 3;
			p[3] = 1;
			p[4] = 2;
			*resp_len = 5;
			return 0;
		}

		printk("flash read ok\n");
		p[0] = 0x1b;
		p[1] = 1;
		p[2] = 3;
		p[3] = 0xf5;
		memcpy(p + 9, mic_chunk_buf, MIC_DATA_CHUNK);
		cnt = 0;
		for (i = 10; i < 20; i++) {
			if (p[i] == 0xff) {
				cnt++;
			}
		}
		p[8] = 0;
		if (cnt == 10 || mic_retransmit_count == 3 || addr > 0x410000) {
			p[8] = 1;
			mic_chunk_index = 0;
			mic_retransmit_count = 0;
			mic_flash_addr = 0x400000;
			printk("***********************************************************************************\n");
		}
	} else {
		p[0] = 0x1b;
		p[1] = 1;
		p[2] = 3;
		p[3] = 1;
		p[4] = 3;
		*resp_len = 5;
		return 0;
	}

	/* checksum over the response, skipping the checksum field p[4..7] */
	sum = 0;
	for (i = 0; i < 250; i++) {
		if (i < 4 || i > 7) {
			sum += p[i];
		}
	}
	p[4] = sum >> 24;
	p[5] = sum >> 16;
	p[6] = sum >> 8;
	p[7] = sum;
	*resp_len = 0xf9;

	return 0;
}

int get_assign_channel_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
				   uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL) {
		G1_LOG_ERR("get_assign_channel_info para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	get_dashboard_state()->esb_channel = req[4];
	get_dashboard_state()->esb_master_addr = req[5];
	get_dashboard_state()->esb_slave_addr = req[6];
	save_sys_settings(get_dashboard_state(), 0);
	p[0] = 0x1d;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;

	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0 &&
		    req[4] == settings.esb_channel &&
		    req[5] == settings.esb_master_addr &&
		    req[6] == settings.esb_slave_addr) {
			break;
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 1;
	}
	*resp_len = 5;

	return 0;
}

int resume_panel(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		            uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("resume_panel para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x25;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	exit_silent_mode();
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int get_imu_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_imu_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x17;
	p[1] = 1;
	p[2] = 3;
	p[3] = 0x1c;
	*(uint32_t *)(p + 4) = imu_yaw_x100;
	*(uint32_t *)(p + 8) = imu_pitch_x100;
	*(uint32_t *)(p + 12) = imu_roll_x100;
	*(uint32_t *)(p + 16) = get_dashboard_state()->accel[0];
	*(uint32_t *)(p + 20) = get_dashboard_state()->accel[1];
	*(uint32_t *)(p + 24) = get_dashboard_state()->accel[2];
	*(uint32_t *)(p + 28) = get_dashboard_state()->imu.ref;
	*resp_len = 0x20;

	return 0;
}

int set_glasses_sn_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL) {
		printk("set_glasses_sn_info para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	const uint8_t *sn = req + 4;
	p = *resp;
	dump_serial_number(sn);
	printf("The string is: %s\n", sn);
	save_sys_settings(get_dashboard_state(), 0);
	p[0] = 0x29;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;

	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0 &&
		    memcmp(req + 4, settings.name, PT_GLASSES_SN_LEN) == 0) {
			break;
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 1;
	}

	return 0;
}

int get_flash_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			  uint8_t *resp_len, void *arg)
{
	const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(mx25r64));
	uint8_t *p;
	int err;

	if (resp == NULL || resp_len == NULL) {
		printk("get_flash_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x1e;
	p[1] = req[1];
	p[2] = 3;
	p[3] = 4;
	if (!device_is_ready(flash_dev)) {
		G1_LOG_ERR(" [%s] device not ready.\n", flash_dev->name);
		p[0] = 0x1e;
		p[1] = req[1];
		p[2] = 3;
		p[3] = 1;
		p[4] = 1;
		*resp_len = 5;
		return 0;
	}

	if (get_dashboard_state()->flash_read != 0) {
		err = flash_read(flash_dev, 0x2612d2, flash_info_cache, sizeof(flash_info_cache));
		if (err) {
			printk("Flash read failed! %d\n", err);
			p[0] = 0x1e;
			p[1] = req[1];
			p[2] = 3;
			p[3] = 1;
			p[4] = 2;
			*resp_len = 5;
			return 0;
		}
		printk("flash read ok\n");
	}
	memcpy(p + 4, flash_info_cache, sizeof(flash_info_cache));
	*resp_len = 0x52;

	return 0;
}

int suspend_panel(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		             uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("suspend_panel para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x26;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	enter_silent_mode();
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int get_flash_burn_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_flash_burn_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x35;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = is_ext_flash_burned();
	*resp_len = 5;

	return 0;
}

int set_lux_base(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	int lux;
	uint8_t idx;
	uint8_t retry;
	uint32_t stored;

	if (resp == NULL || resp_len == NULL) {
		printk("set_lux_base para is NULL\n");
		return -1;
	}
	if (get_pt_test_mode() != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x2e;
	p[1] = 1;
	p[2] = 3;
	p[3] = 6;
	lux = opt3007_read(0);
	idx = req[4];
	switch (idx) {
	case 1:
		if (lux >= 50 && lux < 200) {
			p[4] = 0;
		} else if (lux > 0) {
			p[4] = 1;
		} else {
			p[4] = 2;
			lux = 80000;
		}
		get_dashboard_state()->lux_base[0] = lux;
		lux_calibrated_mask |= 1;
		break;
	case 2:
		if (lux >= 200 && lux < 1000) {
			p[4] = 0;
		} else if (lux > 0) {
			p[4] = 1;
		} else {
			p[4] = 2;
			lux = 80000;
		}
		get_dashboard_state()->lux_base[1] = lux;
		lux_calibrated_mask |= 2;
		break;
	case 3:
		if (lux >= 1000 && lux < 10000) {
			p[4] = 0;
		} else if (lux > 0) {
			p[4] = 1;
		} else {
			p[4] = 2;
			lux = 80000;
		}
		get_dashboard_state()->lux_base[2] = lux;
		lux_calibrated_mask |= 4;
		break;
	case 4:
		if (lux >= 80000) {
			p[4] = 0;
		} else if (lux > 0) {
			p[4] = 1;
		} else {
			p[4] = 2;
			lux = 80000;
		}
		get_dashboard_state()->opt3007_context.lux_base_max = lux;
		lux_calibrated_mask |= 0x8000;
		break;
	default:
		break;
	}

	if (lux_calibrated_mask > 0x8000) {
		get_dashboard_state()->lux_k_max = 22156.0 / get_dashboard_state()->opt3007_context.lux_base_max;
		get_dashboard_state()->lux_k_min = 4210.7 / get_dashboard_state()->lux_base[0];
		get_dashboard_state()->luminance_curve =
			(get_dashboard_state()->lux_k_max + get_dashboard_state()->lux_k_min) / 2 *
			1000000;
	}
	save_sys_settings(get_dashboard_state(), 0);

	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0) {
			if (idx == 1) {
				stored = settings.lux_base[1];
			}
			if (idx == 2) {
				stored = settings.lux_base[0];
			}
			if (idx == 3) {
				stored = settings.lux_base[2];
			}
			if (idx == 4) {
				stored = settings.lux_base_max;
			}
			if (idx >= 1 && idx <= 4 && lux == stored) {
				break;
			}
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 3;
	}
	p[5] = idx;
	*(int *)(p + 6) = lux;
	*resp_len = 10;

	return 0;
}

int set_brightness_lum_base(const uint8_t *req, uint32_t req_len, uint8_t **resp,
				   uint8_t *resp_len, void *arg)
{
	struct sys_settings settings;
	uint8_t *p;
	uint16_t val;
	uint16_t lum;		/* raw request value (unaligned in the request) */
	uint8_t idx;
	uint8_t retry;

	if (resp == NULL || resp_len == NULL) {
		printk("set_brightness_lum_base para is NULL\n");
		return -1;
	}
	if (get_pt_test_mode() != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x36;
	p[1] = 1;
	p[2] = 3;
	p[3] = 2;
	idx = req[4];
	memcpy(&lum, req + 5, sizeof(lum));
	if (lum <= 0x3f) {
		val = lum;
		p[4] = 0;
	} else {
		val = 0x3f;
		p[4] = 1;
	}

	switch (idx) {
	case 0:
		get_dashboard_state()->panel.brightness_lum[1] = val;
		break;
	case 1:
		get_dashboard_state()->panel.brightness_lum[2] = val;
		break;
	case 2:
		get_dashboard_state()->panel.brightness_lum[3] = val;
		break;
	default:
		break;
	}
	get_dashboard_state()->panel.brightness_lum[0] = val;
	save_sys_settings(get_dashboard_state(), 0);

	for (retry = 0; retry < 5; retry++) {
		if (read_sys_settting_from_flash(&settings) == 0) {
			if ((idx == 0 && settings.lum_base[0] == val) ||
			    (idx == 1 && settings.lum_base[1] == val) ||
			    (idx == 2 && settings.lum_base[2] == val)) {
				break;
			}
		}
		k_msleep(100);
	}
	if (retry == 5) {
		p[4] = 2;
	}
	p[5] = idx;
	*resp_len = 6;

	return 0;
}

int get_esb_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_esb_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x23;
	p[1] = 0;
	p[2] = 3;
	p[3] = 0x0b;
	p[4] = get_dashboard_state()->esb_channel;
	p[5] = get_dashboard_state()->esb_master_addr;
	p[6] = get_dashboard_state()->esb_slave_addr;
	*(uint32_t *)(p + 7) = esb_signal;
	*resp_len = 0x0f;

	return 0;
}

int get_brightness_lum_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
				   uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_brightness_lum_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x37;
	p[1] = 1;
	p[2] = 3;
	p[3] = 8;
	*(uint16_t *)(p + 4) = get_dashboard_state()->panel.brightness_lum[0];
	*(uint16_t *)(p + 6) = get_dashboard_state()->panel.brightness_lum[1];
	*(uint16_t *)(p + 8) = get_dashboard_state()->panel.brightness_lum[2];
	*(uint16_t *)(p + 10) = get_dashboard_state()->panel.brightness_lum[3];
	*resp_len = 0x0c;

	return 0;
}

int chnange_test_image(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		                  uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("chnange_test_image para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x28;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	demo_image_select(req[4]);
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int get_role_info_right(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		                   uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_role_info_right para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x2b;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	if (is_master() == 1) {
		p[4] = 1;
	} else if (is_master() == 2) {
		p[4] = 0;
	}
	*resp_len = 5;

	return 0;
}

int get_battery_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			    uint8_t *resp_len, void *arg)
{
	uint8_t *p = *resp;
	uint32_t now = k_uptime_get();
	uint32_t voltage;

	if (resp_len == NULL) {
		printk("get_battery_info para is NULL\n");
		return -1;
	}

	if (req_len > 4) {
		pt_level_flags.raw = req[4];
		set_ncs_mem_pt_level(pt_level_flags.bits.level);
		if (req_len != 5) {
			switch (req[5]) {
			case 6:
				can_enter_low_power = 1;
				set_box_status(1, true);
				break;
			case 7:
				set_box_status(1, false);
				can_enter_low_power = 0;
				break;
			case 8:
				set_box_status(1, true);
				update_activity_time();
				break;
			default:
				break;
			}
		}
	}

	p[0] = 0x13;
	p[1] = 1;
	p[2] = 2;
	p[3] = 6;
	p[4] = 0;
	voltage = nfc_get_field_mv();
	if (voltage > 5499 && get_dashboard_state()->battery_current_ma >= 0 && battery_full_flag == 0) {
		if (battery_high_v_count < 5) {
			battery_high_v_count++;
		}
	} else {
		battery_high_v_count = 0;
		battery_full_count = 0;
	}
	if (get_dashboard_state()->battery_temp_x100 > 5999) {
		p[4] = 2;
	} else if (get_dashboard_state()->battery_temp_x100 > 4999 && get_dashboard_state()->battery_voltage > 0xd1) {
		p[4] = 2;
	}

	if (get_dashboard_state()->battery_left >= get_aging_charge_limit() - 1) {
		if (get_dashboard_state()->battery_left >= get_aging_charge_limit()) {
			battery_full_flag = 1;
		}
		if (battery_full_flag != 0) {
			p[4] = 1;
			battery_high_v_count = 0;
		}
	} else {
		battery_full_flag = 0;
	}
	if (p[4] == 0 && charger_enable_ok == 0 && battery_full_flag == 0) {
		if (++battery_full_count >= 40) {
			p[4] = 4;
		}
	} else {
		battery_full_count = 0;
	}
	if (p[4] == 0 && voltage - 1 < 7799 && battery_full_flag == 0 && battery_high_v_count > 39 &&
	    get_dashboard_state()->battery_current_ma >= 0) {
		p[4] = 4;
	}

	p[5] = voltage >> 8;
	p[6] = voltage;
	p[7] = get_dashboard_state()->battery_left;
	if (get_dashboard_state()->battery_current_ma < 0) {
		p[8] = 1;
		battery_high_v_count = 0;
		battery_full_count = 0;
	} else {
		p[8] = 0;
	}
	if (voltage - 1 < 4999 && get_dashboard_state()->battery_current_ma >= 0 && battery_full_flag == 0) {
		if (battery_high_v_count > 39 && get_dashboard_state()->battery_current_ma >= 0) {
			p[9] = 100;
			p[4] = 4;
		}
	} else {
		p[9] = abs(get_dashboard_state()->battery_current_ma);
	}
	*resp_len = 10;

	if (is_box_lid_closed() != 1) {
		can_enter_low_power = 0;
	}
	if (p[4] == 0 && battery_full_flag != 0) {
		battery_high_v_count = 0;
		battery_full_count = 0;
		p[4] = 1;
	}
	if (p[4] != 0) {
		set_box_status(2, false);
	} else {
		set_box_status(2, true);
	}
	if ((battery_high_v_count | battery_full_count) > 3 && get_dashboard_state()->battery_left > 2 &&
	    get_dashboard_state()->battery_left < 100 && now - battery_info_last_ms > 10000) {
		battery_info_last_ms = now;
		p[9] = 0x80;
	}

	return 0;
}

int power_on_opt3007(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		                uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("power_on_opt3007 para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x30;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	enable_power_for_panel();
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int power_off_opt3007(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		                 uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("power_off_opt3007 para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x31;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	disable_power_for_panel();
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

void enable_charger_retry(void)
{
	uint8_t i;
	uint32_t now;

	for (i = 0; i < 10; i++) {
		if (set_charger_status() == 0) {
			break;
		}
		enable_charger();
		k_sleep(K_MSEC(20));
	}

	now = k_uptime_get();
	if (now - charger_retry_last_ms >= 1000) {
		charger_retry_last_ms = now;
		if (i != 10) {
			charger_retry_fail_count = 0;
			charger_enable_ok = 1;
		} else if (++charger_retry_fail_count > 3) {
			charger_enable_ok = 0;
			charger_retry_fail_count = 3;
		} else {
			charger_enable_ok = 1;
		}
	}
}

uint8_t get_pt_level_flag(void)
{
	return pt_level_flags.bits.flag;
}

uint8_t get_pt_level(void)
{
	return pt_level_flags.bits.level;
}

uint8_t set_pt_level(uint8_t level)
{
	pt_level_flags.bits.level = level;
	return pt_level_flags.bits.level;
}

uint8_t get_aging_charge_limit(void)
{
	if (aging_mode == 1 && aging_phase != 1) {
		return (aging_phase == 2) ? 70 : 85;
	}

	return 100;
}

int set_comflag(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("set_comflag para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x32;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = req[4];
	if (get_dashboard_state()->comflag == 0 && req[4] == 1) {
		serial_rx_clear();
	}
	get_dashboard_state()->comflag = req[4];
	*resp_len = 5;

	return 0;
}

int into_long_trip_mode(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	printk("join in into_long_trip_mode\n");
	if (resp == NULL || resp_len == NULL) {
		printk("into_long_trip_mode para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x06;
	p[1] = 1;
	if (req[2] == 2) {
		can_enter_low_power = 1;
		set_box_status(1, true);
		nfc_deadline_set(10000);
		p[2] = 2;
	} else {
		p[2] = 3;
	}
	p[3] = 1;
	p[4] = 0;
	*resp_len = 5;

	return 0;
}

int pt_resp_checksum(uint8_t **resp, uint8_t *resp_len)
{
	uint8_t *p;
	uint8_t len;
	int sum = 0;
	int i;

	if (resp == NULL || resp_len == NULL) {
		return -1;
	}

	p = *resp;
	len = *resp_len;
	for (i = 0; i < len; i++) {
		sum += p[i];
	}
	p[len] = sum;
	*resp_len = len + 1;

	return 0;
}

int process_pt_protocol(int type, const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t hdr[12];
	uint8_t *p;
	int i;
	int ret = 0;

	if (req == NULL || req_len == 0 || resp == NULL || resp_len == NULL ||
	    type == PT_COMM_NONE) {
		printk("process_pt_protocol para is error\n");
		return -1;
	}

	for (i = 0; i < ARRAY_SIZE(pt_cmd_table); i++) {
		if (pt_cmd_table[i].cmd == req[0] && pt_cmd_table[i].handler != NULL) {
			pt_cmd_table[i].handler(req, req_len, resp, resp_len, arg);
			break;
		}
	}
	if (i == ARRAY_SIZE(pt_cmd_table)) {
		p = *resp;
		p[0] = req[0];
		p[1] = 1;
		p[2] = 3;
		p[3] = 1;
		p[4] = 2;
		*resp_len = 5;
	}

	if (type == PT_COMM_NFC) {
		ret = pt_resp_checksum(resp, resp_len);
	} else if (type == PT_COMM_UART) {
		uint8_t len = *resp_len;

		hdr[0] = 0x5a;
		hdr[1] = 0xa5;
		hdr[2] = 0xff;
		hdr[3] = len;
		p = *resp;
		for (i = 0; i < *resp_len; i++) {
			pt_uart_frame[i] = p[i];
		}
		memcpy(p, hdr, 4);
		for (i = 0; i < *resp_len; i++) {
			p[4 + i] = pt_uart_frame[i];
		}
		*resp_len += 4;
		ret = pt_resp_checksum(resp, resp_len);
	}
	if (ret != 0) {
		return -4;
	}

	return 0;
}

int64_t set_pt_deadline(void)
{
	int64_t deadline = k_uptime_get() + 10000;

	pt_timeout_ms = deadline;
	return deadline;
}

int get_canvas_pos_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_canvas_pos_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x39;
	p[1] = 1;
	p[2] = 3;
	p[3] = 4;
	*(uint16_t *)(p + 4) = get_dashboard_state()->canvas_x;
	*(uint16_t *)(p + 6) = get_dashboard_state()->canvas_y;
	*resp_len = 8;

	return 0;
}

int get_mac_info_3(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			  uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_mac_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x05;
	p[1] = 1;
	p[2] = 3;
	p[3] = 6;
	if (req[2] == 1) {
		memcpy(p + 4, get_dashboard_state()->master_mac, 6);
	} else if (req[2] == 0) {
		memcpy(p + 4, get_dashboard_state()->slave_mac, 6);
	}
	*resp_len = 10;

	return 0;
}

int get_version(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_version para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x24;
	p[1] = 1;
	p[2] = 3;
	p[3] = 3;
	p[4] = (pt_test_mode == 1) ? 0x5b : 1;
	p[5] = 6;
	p[6] = 6;
	*resp_len = 7;

	return 0;
}

int is_ext_flash_burned(void)
{
	/*
	 * The never-taken retry == 7 test makes its block a one-block inner
	 * loop, so GCC's thread2/threadfull2 reject the step PHI ("crosses
	 * loop") instead of threading every passed step into the next case;
	 * only VRP2 (ranger: retry never reaches 6..7) proves it dead and
	 * deletes it after the threaders.  crc lives in the retry loop body, so
	 * the mismatch exit (outside its scope) and the in-scope returns reach
	 * the return block through separate PHIs and phiopt cannot turn the
	 * last compare into a cstore.  The one-case switch escapes the "opcode
	 * nonequal" branch prediction (an `if (crc == X)` gives the equal edge
	 * 34 %, this gives 50 %), so the conditional jump stays on the return-0
	 * edge and return 1 falls through, as in the vendor layout.
	 */
	int step = 0;
	uint8_t retry = 0;

	while (1) {
		uint16_t crc = 0xffff;

		while (1) {
			if (retry == 7) {
				retry = 0;
				continue;
			}
			crc = 0xffff;
			switch (step) {
			case 0:
				if (calc_flash_crc(&crc, 0x140000, 16) || calc_flash_crc(&crc, 0x17fcf8, 16)) {
					goto fail;
				}
				if (crc != 0x0d59) {
					goto mismatch;
				}
				step = 1;
				retry = 0;
				break;
			case 1:
				if (calc_flash_crc(&crc, 0x200000, 16) || calc_flash_crc(&crc, 0x3f8c98, 16)) {
					goto fail;
				}
				if (crc != 0xdab9) {
					goto mismatch;
				}
				step = 2;
				retry = 0;
				break;
			case 2:
				if (calc_flash_crc(&crc, 0x500000, 16) || calc_flash_crc(&crc, 0x515768, 16)) {
					goto fail;
				}
				if (crc != 0x1265) {
					goto mismatch;
				}
				step = 3;
				retry = 0;
				break;
			case 3:
				if (calc_flash_crc(&crc, 0x520000, 16) || calc_flash_crc(&crc, 0x97c44f, 16)) {
					goto fail;
				}
				if (crc != 0xdab9) {
					goto mismatch;
				}
				step = 4;
				retry = 0;
				break;
			case 4:
				if (calc_flash_crc(&crc, 0xa20000, 16) || calc_flash_crc(&crc, 0xa2b77f, 16)) {
					goto fail;
				}
				if (crc != 0xd412) {
					goto mismatch;
				}
				step = 5;
				retry = 0;
				break;
			case 5:
				if (calc_flash_crc(&crc, 0xa40000, 16) || calc_flash_crc(&crc, 0xdbedcf, 16)) {
					goto fail;
				}
				if (crc != 0xdab9) {
					goto mismatch;
				}
				step = 6;
				retry = 0;
				break;
			case 6:
				if (calc_flash_crc(&crc, 0x180000, 16) || calc_flash_crc(&crc, 0x1af0d8, 16)) {
					goto fail;
				}
				switch (crc) {
				case 0x2632:
					return 0;
				default:
					goto mismatch;
				}
			}
		}
fail:
		if (retry == 5) {
			return 2;
		}
		k_msleep(100);
		retry++;
		G1_LOG_ERR("flash read fail, retry again, retry time %d\n", retry);
	}
mismatch:
	return 1;
}

uint8_t get_pt_test_mode(void)
{
	return pt_test_mode;
}

void set_test_mode(uint8_t mode)
{
	PT_PRINT("set testmode is %d \n", mode);
	pt_test_mode = mode;
}

#line 2645
int enter_into_testmode(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint8_t val;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 5) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}

	p = *resp;
	p[0] = 0x01;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	val = req[4];
	if (val > 1) {
		PT_PRINT("[%s-%d]invalid vaule\n", __func__, __LINE__);
		p[4] = 3;
	} else if (pt_test_mode == val) {
		p[4] = 4;
	} else {
		p[4] = 0;
		set_test_mode(req[4]);
		save_usr_settings(get_dashboard_state(), 0);
	}
	*resp_len = 5;

	return 0;
}

uint8_t get_aging_phase(void)
{
	return aging_phase;
}

int get_firmware_mode(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			     uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 4) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}

	p = *resp;
	p[0] = 0x04;
	p[1] = 1;
	p[2] = 3;
	p[3] = get_pt_test_mode();
	*resp_len = 4;

	return 0;
}

void set_aging_mode(uint8_t v)
{
	aging_mode = v;
}

#line 2705
int set_mic_nocompress(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			      uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint8_t val;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 5) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x3a;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	val = req[4];
	if (val > 1) {
		PT_PRINT("[%s-%d]invalid vaule \n", __func__, __LINE__);
		p[4] = 3;
	} else if (get_dashboard_state()->mic_nocompress == val) {
		p[4] = 4;
	} else {
		p[4] = 0;
		get_dashboard_state()->mic_nocompress = req[4];
	}
	*resp_len = 5;

	return 0;
}

int get_brightness_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 4) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}

	p = *resp;
	p[0] = 0x3b;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	p[4] = get_dashboard_state()->panel.panel_brightness_level;
	*resp_len = 5;

	return 0;
}

uint8_t get_aging_mode(void)
{
	return aging_mode;
}

int get_glasses_sn_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	char buf[32] = {0};
	uint8_t *p;
	size_t len;

	if (resp == NULL || resp_len == NULL) {
		printk("get_glasses_sn_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x2a;
	p[1] = req[1];
	p[2] = 3;
	sprintf(buf, "%s", get_glasses_name());
	len = strlen(buf);
	p[3] = len;
	memcpy(p + 4, buf, len);
	*resp_len = len + 4;

	return 0;
}

int get_charge_test_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
				uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint16_t *q;
	int i;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 4) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}

	p = *resp;
	p[0] = 0x3d;
	p[1] = 1;
	p[2] = 3;
	p[3] = 0x1a;
	p[4] = get_dashboard_state()->aging_test_count;
	p[5] = get_dashboard_state()->aging_start_soc;
	*(uint32_t *)(p + 6) = get_dashboard_state()->aging_elapsed_s;
	*(uint32_t *)(p + 10) = get_dashboard_state()->aging_charge_time_s;
	*(uint32_t *)(p + 14) = get_dashboard_state()->aging_discharge_time_s;
	q = (uint16_t *)(p + 18);
	for (i = 0; i < 6; i++) {
		*q++ = get_dashboard_state()->aging_discharge_step_s[i];
	}
	p[30] = get_dashboard_state()->aging_touch_count;
	p[31] = get_dashboard_state()->aging_charge_check_result;
	*resp_len = 0x20;

	return 0;
}

void enter_aging_mode(void)
{
	exit_silent_mode();
	aging_mode = 1;
	aging_phase = 1;
	get_dashboard_state()->panel.panel_brightness_level = 1;
	set_brightness_to_panel_reg_in_running(get_dashboard_state()->panel.panel_brightness_level);
	get_dashboard_state()->aging_test_count++;
	get_dashboard_state()->aging_start_soc = get_dashboard_state()->battery_left;
	get_dashboard_state()->aging_start_uptime_s = k_uptime_get() / 1000;
	get_dashboard_state()->aging_charge_time_s = 0;
	get_dashboard_state()->aging_discharge_time_s = 0;
	memset(get_dashboard_state()->aging_discharge_step_s, 0, sizeof(get_dashboard_state()->aging_discharge_step_s));
	get_dashboard_state()->aging_touch_count = 0;
	get_dashboard_state()->aging_charge_check_count = 0;
	get_dashboard_state()->aging_charge_check_result = 0;
	get_dashboard_state()->aging_no_charge_count = 0;
	save_sys_settings(get_dashboard_state(), 0);
}

#line 2822
int set_aging_test_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint8_t val;

	if (resp == NULL || resp_len == NULL || req == NULL || req_len < 5) {
		printk("%s para is NULL\n", __func__);
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x3e;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	val = req[4];
	if (val > 1) {
		PT_PRINT("[%s-%d]invalid vaule \n", __func__, __LINE__);
		p[4] = 3;
	} else if (aging_mode == val) {
		p[4] = 4;
	} else {
		p[4] = 0;
		if (req[4] == 0) {
			exit_aging_mode();
		} else if (req[4] == 1) {
			enter_aging_mode();
		}
	}
	*resp_len = 5;

	return 0;
}

void exit_aging_mode(void)
{
	enter_silent_mode();
	aging_mode = 0;
	aging_phase = 0;
	get_dashboard_state()->panel.panel_brightness_level = 0x15;
	set_brightness_to_panel_reg_in_running(get_dashboard_state()->panel.panel_brightness_level);
}

void aging_charge_test(int interval)
{
	bool need_save;
	int t;
	int i;

	if (aging_mode != 1) {
		return;
	}

	get_dashboard_state()->aging_elapsed_s = k_uptime_get() / 1000 - get_dashboard_state()->aging_start_uptime_s;
	if (get_dashboard_state()->aging_elapsed_s <= 900) {
		need_save = get_dashboard_state()->aging_elapsed_s % 60 < interval;
	} else {
		need_save = get_dashboard_state()->aging_elapsed_s % 900 < interval;
	}

	if (aging_phase == 1) {
		if (get_dashboard_state()->aging_elapsed_s >= 300 &&
		    (get_dashboard_state()->panel.init_done == 1 || get_dashboard_state()->dashboard_mode == 3 ||
		     get_dashboard_state()->suspend_state == 0 || line_buf != 0)) {
			enter_silent_mode();
		}
		if (get_dashboard_state()->battery_left > 96) {
			aging_phase = 2;
			get_dashboard_state()->panel.panel_brightness_level = 0x15;
			set_brightness_to_panel_reg_in_running(
				get_dashboard_state()->panel.panel_brightness_level);
			discharge_test_start_ms = k_uptime_get();
			get_dashboard_state()->aging_charge_time_s =
				k_uptime_get() / 1000 - get_dashboard_state()->aging_start_uptime_s;
			need_save = true;
		}
	} else if (aging_phase == 2) {
		if (get_dashboard_state()->panel.init_done != 1 || get_dashboard_state()->dashboard_mode != 3 ||
		    get_dashboard_state()->suspend_state == 1 || line_buf == 0) {
			exit_silent_mode();
		}
		if (get_dashboard_state()->battery_left <= 70) {
			t = (k_uptime_get() - discharge_test_start_ms) / 1000;
			for (i = 0; i < 5; i++) {
				t -= get_dashboard_state()->aging_discharge_step_s[i];
			}
			get_dashboard_state()->aging_discharge_step_s[5] = t;
			if (discharge_test_start_ms < k_uptime_get()) {
				get_dashboard_state()->aging_discharge_time_s = (k_uptime_get() - discharge_test_start_ms) / 1000;
			} else {
				G1_LOG_ERR("Err:current time is smaller than the discharge test start time!\n");
			}
			aging_phase = 0;
			need_save = true;
		} else if (get_dashboard_state()->battery_left <= 75 && get_dashboard_state()->aging_discharge_step_s[4] == 0) {
			t = (k_uptime_get() - discharge_test_start_ms) / 1000;
			for (i = 0; i < 4; i++) {
				t -= get_dashboard_state()->aging_discharge_step_s[i];
			}
			get_dashboard_state()->aging_discharge_step_s[4] = t;
			need_save = true;
		} else if (get_dashboard_state()->battery_left <= 80 && get_dashboard_state()->aging_discharge_step_s[3] == 0) {
			t = (k_uptime_get() - discharge_test_start_ms) / 1000;
			for (i = 0; i < 3; i++) {
				t -= get_dashboard_state()->aging_discharge_step_s[i];
			}
			get_dashboard_state()->aging_discharge_step_s[3] = t;
			need_save = true;
		} else if (get_dashboard_state()->battery_left <= 85 && get_dashboard_state()->aging_discharge_step_s[2] == 0) {
			t = (k_uptime_get() - discharge_test_start_ms) / 1000;
			for (i = 0; i < 2; i++) {
				t -= get_dashboard_state()->aging_discharge_step_s[i];
			}
			get_dashboard_state()->aging_discharge_step_s[2] = t;
			need_save = true;
		} else if (get_dashboard_state()->battery_left <= 90 && get_dashboard_state()->aging_discharge_step_s[1] == 0) {
			t = (k_uptime_get() - discharge_test_start_ms) / 1000;
			t -= get_dashboard_state()->aging_discharge_step_s[0];
			get_dashboard_state()->aging_discharge_step_s[1] = t;
			need_save = true;
		} else if (get_dashboard_state()->battery_left <= 95 && get_dashboard_state()->aging_discharge_step_s[0] == 0) {
			get_dashboard_state()->aging_discharge_step_s[0] = (k_uptime_get() - discharge_test_start_ms) / 1000;
			need_save = true;
		}
	} else {
		if (get_dashboard_state()->panel.init_done != 1 || get_dashboard_state()->dashboard_mode != 3 ||
		    get_dashboard_state()->suspend_state == 1 || line_buf == 0) {
			exit_silent_mode();
		}
	}

	if (need_save) {
		save_sys_settings(get_dashboard_state(), 0);
	}
}

static void aging_test_thread(void *p1, void *p2, void *p3)
{
	while (1) {
		if (aging_mode == 1) {
			G1_LOG_WRN("$$$$$$$$$$$$$$$$$$$$$enter agemode!$$$$$$$$$$$$$$$$$$$$$\n");
			int64_t start = k_uptime_get();   /* unused in the shipped code */
			while (aging_mode == 1) {
				demo_image_select(0);
				k_msleep(3000);
				demo_image_select(2);
				k_msleep(1000);
				aging_charge_test(4);
			}
		} else if (aging_mode == 2) {
			demo_image_next();
			aging_mode = 0;
		}
		check_sw0_status();
		k_msleep(100);
	}
}

void aging_charge_check(void)
{
	bool need_save = false;

	if (aging_mode != 1 || aging_phase != 1) {
		return;
	}
	if (get_dashboard_state()->aging_elapsed_s >= 300) {
		return;
	}
	if (get_box_status_by_type(0) != 1) {
		return;
	}
	if (get_dashboard_state()->battery_left > 94) {
		return;
	}

	get_dashboard_state()->aging_charge_check_count++;
	if (get_dashboard_state()->battery_current_ma >= 0) {
		if (get_dashboard_state()->aging_no_charge_count <= 20) {
			get_dashboard_state()->aging_no_charge_count++;
		}
	} else {
		if (get_dashboard_state()->aging_charge_check_result != 2) {
			get_dashboard_state()->aging_no_charge_count = 0;
		}
	}

	if (get_dashboard_state()->aging_charge_check_count > 60 && get_dashboard_state()->aging_charge_check_result == 0) {
		get_dashboard_state()->aging_charge_check_result = 1;
		need_save = true;
	}
	if (get_dashboard_state()->aging_no_charge_count > 20 && get_dashboard_state()->aging_charge_check_result != 2) {
		get_dashboard_state()->aging_charge_check_result = 2;
		need_save = true;
	}
	if (need_save) {
		save_sys_settings(get_dashboard_state(), 0);
	}
}

#line 3102
void start_aging_mode_thread(void)
{
	if (aging_thread_started) {
		printk("[%s-%d], thread has started !\n", __func__, __LINE__);
		return;
	}

	if (k_thread_create(&aging_thread, aging_thread_stack, K_THREAD_STACK_SIZEOF(aging_thread_stack),
			    aging_test_thread, NULL, NULL, NULL, -12, 0, K_NO_WAIT) == NULL) {
		aging_thread_started = 1;
	}
}

int pt_flash_read(const struct device *dev, off_t offset, void *data, size_t len)
{
	if (!device_is_ready(dev)) {
		return -ENODEV;
	}
	return flash_read(dev, offset, data, len);
}

int get_lux_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint32_t lux;
	float curve;

	if (resp == NULL || resp_len == NULL) {
		printk("get_lux_info para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x20;
	p[1] = 1;
	p[2] = 3;
	p[3] = 0x20;
	lux = opt3007_read(0);
	*(uint32_t *)(p + 4) = lux;
	*(uint32_t *)(p + 8) = get_dashboard_state()->lux_base[0];
	*(uint32_t *)(p + 12) = get_dashboard_state()->lux_base[1];
	*(uint32_t *)(p + 16) = get_dashboard_state()->lux_base[2];
	*(uint32_t *)(p + 20) = get_dashboard_state()->opt3007_context.lux_base_max;
	*(int *)(p + 24) = get_dashboard_state()->luminance_curve;
	*(int *)(p + 28) = get_dashboard_state()->luminance_curve_a1;
	curve = get_dashboard_state()->luminance_curve;
	*(uint32_t *)(p + 32) = curve / 1000000.0 * lux;
	*resp_len = 0x24;

	return 0;
}


uint8_t get_pt_version_major(void)
{
	return 0x5b;
}

int set_canvas_pos_info(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			       uint8_t *resp_len, void *arg)
{
	uint8_t *p;
	uint32_t x, y;
	uint8_t ret;

	if (resp == NULL || resp_len == NULL) {
		printk("set_canvas_pos_info para is NULL\n");
		return -1;
	}
	if (pt_test_mode != 1) {
		printk("warning: not test mode,disable setting\n");
		return -2;
	}

	p = *resp;
	p[0] = 0x38;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	ret = 1;
	x = *(const uint16_t *)(req + 5);
	if (x <= 0x40) {
		y = *(const uint16_t *)(req + 7);
		if (y <= 0x40) {
			if (x % 2 == 0) {
				get_dashboard_state()->canvas_x = x;
			} else {
				get_dashboard_state()->canvas_x = x - 1;
			}
			get_dashboard_state()->canvas_y = y;
			demo_mode = 0;
			ret = 0;
		}
	}
	p[4] = ret;
	if (req[4]) {
		save_sys_settings(get_dashboard_state(), 0);
	}
	*resp_len = 5;

	return 0;
}

void mic_transm_thread(void *p1, void *p2, void *p3)
{
	const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(mx25r64));
	uint8_t buf[MIC_TRANSM_FRAME] = {0};
	uint8_t fail = 0;
	uint16_t seq;
	uint32_t addr;
	int err;
	int cnt;
	int i;

	k_sem_init(&mic_transm_sem, 0, 1);

	while (1) {
		k_sem_take(&mic_transm_sem, K_FOREVER);
		buf[0] = 0x5a;
		buf[1] = 0xa5;
		buf[2] = 0xf1;
		buf[3] = 0x01;

		if (!device_is_ready(flash_dev)) {
			G1_LOG_ERR(" [%s] device not ready.\n", flash_dev->name);
			buf[4] = 0;
			buf[5] = 0xca;
			get_dashboard_state()->ble_context.write(buf, 10);
		} else if (get_dashboard_state()->flash_read != 0) {
			seq = 0;
			while (1) {
				addr = mic_flash_addr + seq * MIC_TRANSM_CHUNK;
				printk("start send mic data,flash address:0x%x,seq:%d\n", addr, seq);
				err = flash_read(flash_dev, addr, buf + 6, MIC_TRANSM_CHUNK);
				if (err) {
					printk("Flash read failed! %d\n", err);
					buf[4] = seq;
					buf[5] = 0xca;
					get_dashboard_state()->ble_context.write(buf, 10);
					break;
				}
				buf[4] = seq;
				buf[5] = 0;
				cnt = 0;
				for (i = 6; i < 26; i++) {
					if (buf[i] == 0xff) {
						cnt++;
					}
				}
				if (cnt == 20 || addr > 0x410000) {
					buf[4] = 0;
					buf[5] = 1;
					get_dashboard_state()->ble_context.write(buf, 10);
					break;
				}
				if (get_dashboard_state()->ble_context.write(buf, MIC_TRANSM_FRAME) < 0) {
					fail++;
					if (fail >= 10) {
						G1_LOG_ERR("BLE send failed for %d times\n", fail);
						goto reset;
					}
				} else {
					seq++;
				}
				k_msleep(20);
			}
		}
		if (0) {
			/* the fail counter is cleared at a join in front of the memset
			 * (a plain "fail = 0; break;" gets that block tail-duplicated) */
reset:
			fail = 0;
		}
		memset(buf, 0, sizeof(buf));
	}
}

int get_role_info_left(const uint8_t *req, uint32_t req_len, uint8_t **resp,
		                  uint8_t *resp_len, void *arg)
{
	uint8_t *p;

	if (resp == NULL || resp_len == NULL) {
		printk("get_role_info_left para is NULL\n");
		return -1;
	}

	p = *resp;
	p[0] = 0x2c;
	p[1] = 1;
	p[2] = 3;
	p[3] = 1;
	if (is_master() == 1) {
		p[4] = 1;
	} else if (is_master() == 2) {
		p[4] = 0;
	}
	*resp_len = 5;

	return 0;
}

void start_mic_transm_thread(void)
{
	k_thread_create(&mic_transm_thread_data, mic_transm_thread_stack, K_THREAD_STACK_SIZEOF(mic_transm_thread_stack),
			mic_transm_thread, NULL, NULL, NULL, -12, 0, K_NO_WAIT);
}

const struct pt_cmd pt_cmd_table[48] = {
	{0x22, get_sn_info},
	{0x24, get_version},
	{0x06, into_long_trip_mode},
	{0x11, set_battery_info},
	{0x13, get_battery_info},
	{0x05, get_mac_info_3},
	{0x07, get_mac_info},
	{0x08, get_mac_info_2},
	{0x0b, set_restart_mode},
	{0x3c, set_panel_voltage},
	{0x40, set_charge_limit},
	{0x01, enter_into_testmode},
	{0x04, get_firmware_mode},
	{0x16, get_flash_info_2},
	{0x17, get_imu_info},
	{0x18, get_keyboard_info_2},
	{0x19, get_mic_info},
	{0x1a, exit_mic_mode},
	{0x1b, set_mic_info},
	{0x1c, get_query_sn_info},
	{0x1d, get_assign_channel_info},
	{0x1e, get_flash_info},
	{0x20, get_lux_info},
	{0x23, get_esb_info},
	{0x25, resume_panel},
	{0x26, suspend_panel},
	{0x28, chnange_test_image},
	{0x29, set_glasses_sn_info},
	{0x2a, get_glasses_sn_info},
	{0x2b, get_role_info_right},
	{0x2c, get_role_info_left},
	{0x2d, set_imu_base},
	{0x2e, set_lux_base},
	{0x2f, get_keyboard_info},
	{0x30, power_on_opt3007},
	{0x31, power_off_opt3007},
	{0x32, set_comflag},
	{0x33, set_brightness},
	{0x35, get_flash_burn_info},
	{0x36, set_brightness_lum_base},
	{0x37, get_brightness_lum_info},
	{0x38, set_canvas_pos_info},
	{0x39, get_canvas_pos_info},
	{0xe1, set_restart_mode_2},
	{0x3a, set_mic_nocompress},
	{0x3b, get_brightness_info},
	{0x3d, get_charge_test_info},
	{0x3e, set_aging_test_info},
};

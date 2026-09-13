/*
 * Zephyr settings glue: "ar_glass_userdata_settings" subtree and the local
 * store backend used through GLOBAL_STATE->store, followed by the raw external-flash
 * helpers (flash_settings_read, flash_settings_write_and_verify, write_font, ...): their
 * __func__ strings sit between the two groups in the target .rodata, so it is one file.
 * Original file name unknown.
 */
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/settings/settings.h>
#include "g1_log.h"
#include "storage.h"

#define SETT_ROOT "ar_glass_userdata_settings"

void local_store_delete(const char *key)
{
	char path[128] = SETT_ROOT "/";

	strcat(path, key);
	settings_delete(path);
}

int local_store_write(const char *key, const void *val, size_t len)
{
	char path[128] = SETT_ROOT "/";
	int err;

	strcat(path, key);
	err = settings_save_one(path, val, len);
	if (err) {
		G1_LOG_ERR("failed to store key: %s --- %d\n", key, len);
	} else {
		G1_LOG_INF("save success:[%s], len=%d\n", key, len);
	}
	return 0;
}

static int sett_handler(const char *key, size_t len, settings_read_cb read_cb,
			void *cb_arg)
{
	int rc;

	if (!strcmp(key, "ble_whitelist_app")) {
		rc = read_cb(cb_arg, FUN_00036268(), 0x15e2);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		return 0;
	}
	if (!strcmp(key, "dashboard_ts")) {
		if (get_dashboard_state()->dashboard_ts == NULL) {
			return 0;
		}
		rc = read_cb(cb_arg, get_dashboard_state()->dashboard_ts, 0x75);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, *(int *)get_dashboard_state()->dashboard_ts);
		return 0;
	}
	if (!strcmp(key, "countdown_ts")) {
		if (get_dashboard_state()->countdown_ts == NULL) {
			return 0;
		}
		rc = read_cb(cb_arg, get_dashboard_state()->countdown_ts, 7);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, *(int *)get_dashboard_state()->countdown_ts);
		return 0;
	}
	if (!strcmp(key, "first_enter_flag")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->first_enter_flag, 4);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->first_enter_flag);
		return 0;
	}
	if (!strcmp(key, "brightness_level")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->brightness_level, 1);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->brightness_level);
		return 0;
	}
	if (!strcmp(key, "3dof_enable")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->dof3_enable, 1);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->dof3_enable);
		return 0;
	}
	if (!strcmp(key, "display_mode")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->display_mode, 1);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->display_mode);
		return 0;
	}
	if (!strcmp(key, "runtime_mode")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->work_mode, 1);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->work_mode);
		return 0;
	}
	if (!strcmp(key, "user_sched_info")) {
		if (get_dashboard_state()->user_sched_info == NULL) {
			return 0;
		}
		rc = read_cb(cb_arg, get_dashboard_state()->user_sched_info, 0x16a);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		return 0;
	}
	if (!strcmp(key, "wakeup_angle")) {
		rc = read_cb(cb_arg, &get_dashboard_state()->wakeup_angle, 1);
		if (rc < 0) {
			G1_LOG_WRN("Failed to read %s, error: %d\n", key, rc);
			return rc;
		}
		G1_LOG_INF("key:%s, val=%d\n", key, get_dashboard_state()->wakeup_angle);
		return 0;
	}
	return 0;
}

static struct settings_handler sett_conf = {
	.name = SETT_ROOT,
	.h_set = sett_handler,
};

static int local_store_load(void)
{
	return 0;
}

void sett_init(struct local_store *st)
{
	int err;

	err = settings_subsys_init();
	if (err) {
		G1_LOG_WRN("Failed to initialize settings subsystem, error: %d\n", err);
	} else {
		err = settings_register(&sett_conf);
		if (err) {
			G1_LOG_WRN("Cannot register settings handler %d\n", err);
		} else {
			G1_LOG_WRN("init ok\n");
		}
	}
	st->status = err ? err : 1;
	st->write = local_store_write;
	st->load = local_store_load;
	st->del = local_store_delete;
}

int flash_settings_read(uint32_t addr, void *buf, size_t len)
{
	int retry = 0;
	int ret;

	while (1) {
		if (!device_is_ready(FLASH_DEV)) {
			printk(" [%s] device not ready.\n", FLASH_DEV->name);
			ret = -1;
		} else {
			ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, len);
			if (ret == 0) {
				break;
			}
			printk("Flash read failed! %d\n", ret);
		}
		if (retry == 10) {
			break;
		}
		k_sleep(K_MSEC(100));
		retry++;
		G1_LOG_ERR("flash read fail, retry again, retry time %d\n", retry);
	}
	return ret;
}

int flash_settings_write_and_verify(uint32_t addr, const void *data, size_t len)
{
	uint8_t *buf;
	int ret;

	buf = malloc(4096);
	if (buf == NULL) {
		G1_PRINT("[%s-%d]error, have no memory ! \n", __func__, __LINE__);
		return -1;
	}
	if (!device_is_ready(FLASH_DEV)) {
		printk(" [%s] device not ready.\n", FLASH_DEV->name);
		ret = -1;
		goto out;
	}
	memset(buf, 0, 4096);
	ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, 4096);
	if (ret) {
		printk("Flash read failed! %d\n", ret);
		goto out;
	}
	if (memcmp(data, buf, len) == 0) {
		printk("write data and read data is same, exit\n");
		goto out;
	}
	ret = get_dashboard_state()->flash_erase(get_dashboard_state(), addr, 4096);
	if (ret) {
		printk("Flash erase failed! %d\n", ret);
		goto out;
	}
	memset(buf, 0, 4096);
	memcpy(buf, data, len);
	ret = get_dashboard_state()->flash_write(get_dashboard_state(), addr, buf, 4096);
	if (ret) {
		printk("Flash write failed! %d addr %08X size %d\n", ret, addr, len);
		goto out;
	}
	ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, 4096);
	if (ret) {
		printk("Flash read failed! %d\n", ret);
		goto out;
	}
	if (memcmp(data, buf, len) == 0) {
		printk("flash verify success!\n");
	} else {
		printk("flash verify failed\n");
		ret = 1;
	}
out:
	free(buf);
	return ret;
}

int write_whitelist_to_flash(uint32_t addr, const uint8_t *data, uint32_t size)
{
	int ret = 0;
	uint8_t pages;
	int16_t last;
	uint8_t i;

	G1_PRINT("size is %d\n", size);
	pages = (size >> 12) + 1;
	last = size - (pages - 1) * 4096;
	for (i = 0; i < pages; i++) {
		ret += flash_settings_write_and_verify(addr + i * 4096, data + i * 4096,
						       i < pages - 1 ? 4096 : last);
	}
	return ret;
}

int write_font(uint32_t addr, const void *data, size_t len)
{
	uint8_t buf[4096] = {0};
	int retry = 0;
	int ret;
	uint32_t err;

	while (1) {
		if (!device_is_ready(FLASH_DEV)) {
			printk(" [%s] device not ready.\n", FLASH_DEV->name);
			ret = -1;
			retry++;
		} else {
			ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, 4096);
			if (ret) {
				printk("Flash read font failed! %d\n", ret);
				err = ret;
			} else if (memcmp(data, buf, len) == 0) {
				printk("write font data and read data is same, exit\n");
				return ret;
			} else {
				err = get_dashboard_state()->flash_erase(get_dashboard_state(), addr, 4096);
				if (err) {
					printk("Flash erase font failed! %d\n", err);
				} else {
					err = get_dashboard_state()->flash_write(get_dashboard_state(),
										 addr, data, len);
					if (err) {
						printk("Flash write font failed! %d\n", err);
					} else {
						err = get_dashboard_state()->flash_read(
							get_dashboard_state(), addr, buf, 4096);
						if (err) {
							printk("Flash read font failed! %d\n", err);
						} else if (memcmp(data, buf, len) == 0) {
							return ret;
						} else {
							printk("flash verify font failed\n");
							ret = 1;
							retry++;
							goto next;
						}
					}
				}
			}
			ret = err;
			retry++;
			goto next;	/* explicit (falls through anyway): the extra edge keeps the target's string-register choice (permuter) */
		}
next:
		if (retry == 10) {
			return ret;
		}
		k_sleep(K_MSEC(100));
	}
}

int calc_flash_crc(uint16_t *crc, int addr, uint32_t size)
{
	uint16_t pages;
	int pos;
	int len;
	int ret;
	uint8_t i;

	G1_LOG_INF("join in calc_flash_crc\n\n");
	if (crc == NULL || size == 0) {
		G1_LOG_INF("calc_flash_crc para is NULL\n\n");
		return -1;
	}
	pages = size / 1024;
	if (size % 1024) {
		pages++;
	}
	uint8_t buf[1024] = {0xff};

	if (!device_is_ready(FLASH_DEV)) {
		printk(" [%s] device not ready.\n", FLASH_DEV->name);
		return -1;
	}
	for (uint16_t page = 0; page < pages; page++) {
		pos = addr + page * 1024;
		len = size + addr - pos;
		if (len >= 1024) {
			len = 1024;
		}
		ret = get_dashboard_state()->flash_read(get_dashboard_state(), pos, buf, len);
		if (ret) {
			printk("Flash read 0x%x failed: %d\n", pos, ret);
			return -1;
		}
		for (i = 0; i < len; i++) {
			G1_LOG_INF("0x%x \n", buf[i]);
		}
		G1_LOG_INF("\n\n");
		*crc = FUN_000811a0(*crc, buf, len);
	}
	if (DAT_2000304f && !DAT_20019a5e) {
		watchdog_feed();
	}
	return 0;
}

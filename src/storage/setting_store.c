/*
 * App language / dashboard startup mode / tap customisation persistence.
 * The record lives in the first bytes of the 0x13e000 flash sector and is
 * written by the flash ops thread (SettingStoreHandler).
 * Original file name unknown.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "storage.h"

#define SETTING_FLASH_ADDR  0x13e000
#define SETTING_MAGIC       0xaa
#define SETTING_QUEUE_DEPTH 5

enum {
	SETTING_CMD_LANGUAGE = 1,
	SETTING_CMD_LANGUAGE_CLEAN = 2,
	SETTING_CMD_STARTUP_MODE = 3,
	SETTING_CMD_STARTUP_MODE_CLEAN = 4,
};

struct setting_msg {
	uint8_t cmd;
	uint8_t f1;
	uint16_t f2;
	uint8_t value;
	uint8_t f5;
};

K_MSGQ_DEFINE(setting_msgq, sizeof(struct setting_msg), SETTING_QUEUE_DEPTH, 4);

volatile struct app_setting CURRENT_LANGUAGE;

/*
 * Flush the setting queue.  The shipped code takes the message count from
 * the local message buffer instead of the queue (vendor bug, reproduced).
 */
int clearSettingStorageQueue(void)
{
	struct setting_msg msg;
	int ret = 0;
	int n;

	for (n = k_msgq_num_used_get((struct k_msgq *)&msg); n > 0; n--) {
		ret = k_msgq_get(&setting_msgq, &msg, K_NO_WAIT);
	}
	return ret;
}

int upgradeAppLanguageInfoToFlash(uint8_t language)
{
	struct setting_msg msg = {
		.cmd = SETTING_CMD_LANGUAGE,
		.f2 = 1,
		.value = language,
	};

	if (k_msgq_put(&setting_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("setting flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("send app language store Command, language = %d\n", language);
	k_sem_give(&flash_ops_sem);
	return 0;
}

int cleanAppLanguageInfo(void)
{
	struct setting_msg msg = {
		.cmd = SETTING_CMD_LANGUAGE_CLEAN,
	};

	if (k_msgq_put(&setting_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("setting flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("SEND APP Language Command...\n");
	k_sem_give(&flash_ops_sem);
	return 0;
}

int upgradeDashboardStartupModeInfoToFlash(uint8_t mode)
{
	struct setting_msg msg = {
		.cmd = SETTING_CMD_STARTUP_MODE,
		.f2 = 1,
		.value = mode,
	};

	if (k_msgq_put(&setting_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("setting flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("send startup mode store Command, mode = %d\n", mode);
	k_sem_give(&flash_ops_sem);
	return 0;
}

int cleanDashBoardStartUpModeInfo(void)
{
	struct setting_msg msg = {
		.cmd = SETTING_CMD_STARTUP_MODE_CLEAN,
	};

	if (k_msgq_put(&setting_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("setting flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("SEND APP Language Command...\n");
	k_sem_give(&flash_ops_sem);
	return 0;
}

int upgradeDoubleTapCustomizeToFlash(uint32_t mode)
{
	if (mode > 5) {
		G1_LOG_ERR("Err:double_tap_customize is out of range!\n");
		return -1;
	}
	if (get_dashboard_state()->f_1244 != mode) {
		get_dashboard_state()->f_1244 = mode;
		get_dashboard_state()->f_1245 = 0;
		storage_commit_request(0, 0);
		if (get_dashboard_state()->f_1244 == 4) {
			if (CURRENT_LANGUAGE.startup_mode != 2) {
				upgradeDashboardStartupModeInfoToFlash(2);
			}
		} else {
			get_dashboard_state()->f_1245 = 0;
		}
	}
	return 0;
}

int upgradeLongpressTapCustomizeToFlash(uint32_t mode)
{
	if (mode > 1) {
		G1_LOG_ERR("Err:longpress_tap_customize is out of range!\n");
		return -1;
	}
	if (get_dashboard_state()->f_1246.a != mode) {
		get_dashboard_state()->f_1246.a = mode;
		storage_commit_request(0, 0);
	}
	return 0;
}

uint8_t getAppLanguageInfofromFlash(void)
{
	struct app_setting rec;

	G1_LOG_INF("read setting flash data to ram...\r\n\n");
	if (!device_is_ready(FLASH_DEV)) {
		G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
		return 0xff;
	}
	memset(&rec, 0, sizeof(rec));
	if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR, &rec,
					      sizeof(rec))) {
		G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
		return 0;
	}
	if (rec.magic == SETTING_MAGIC) {
		CURRENT_LANGUAGE.language = rec.language;
	} else {
		CURRENT_LANGUAGE.language = 2;
	}
	return CURRENT_LANGUAGE.language;
}

uint8_t getDashboardStartUpModeInfofromFlash(void)
{
	struct app_setting rec;

	G1_LOG_INF("read setting flash data to ram...\r\n\n");
	if (!device_is_ready(FLASH_DEV)) {
		G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
		return 0xff;
	}
	memset(&rec, 0, sizeof(rec));
	if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR, &rec,
					      sizeof(rec))) {
		G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
		return 0;
	}
	/*
	 * Each branch logs on its own (as the vendor source evidently did): GIMPLE
	 * hoisting then lifts the LOG_LEVEL load to the head of the success path,
	 * jump2 head-merges it with the error path's load above the branch on the
	 * flash_read result, and crossjumping folds the log copies back together.
	 */
	if (rec.magic == SETTING_MAGIC) {
		if (rec.startup_mode == 0xff) {
			CURRENT_LANGUAGE.startup_mode = 0;
			G1_LOG_ERR("dashboard startup mode = %d\n", CURRENT_LANGUAGE.startup_mode);
		} else {
			CURRENT_LANGUAGE.startup_mode = rec.startup_mode;
			G1_LOG_ERR("dashboard startup mode = %d\n", CURRENT_LANGUAGE.startup_mode);
		}
	} else {
		CURRENT_LANGUAGE.startup_mode = 0;
		G1_LOG_ERR("dashboard startup mode = %d\n", CURRENT_LANGUAGE.startup_mode);
	}
	return CURRENT_LANGUAGE.startup_mode;
}

uint8_t get_current_language(void)
{
	return CURRENT_LANGUAGE.language;
}

uint8_t get_dashboard_startup_mode(void)
{
	return CURRENT_LANGUAGE.startup_mode;
}

int getSettingStorageQueueNum(void)
{
	return k_msgq_num_used_get(&setting_msgq);
}

static int getSettingStorageQueueCacheData(struct setting_msg *msg)
{
	int ret;

	ret = k_msgq_get(&setting_msgq, msg, K_NO_WAIT);
	if (ret) {
		G1_LOG_ERR("setting storage queue get failed\r\n\n");
	}
	return ret;
}

/*
 * Flash ops thread handler for one queued setting command.  Single exit through
 * `ret`; each case has its own `rec` (vendor layout): the end-of-scope clobbers
 * keep every case's success path on its own edge into the return PHI, so uncprop
 * returns the final flash_read result (r4) instead of a shared constant 0.
 */
int SettingStoreHandler(void)
{
	struct setting_msg msg;
	uint8_t value;
	int ret;

	ret = getSettingStorageQueueCacheData(&msg);
	if (ret) {
		G1_LOG_ERR("setting storage get queue data failed\n");
		return -1;
	}
	G1_LOG_INF("received setting command .\n");
	switch (msg.cmd) {
	case SETTING_CMD_LANGUAGE: {
		struct app_setting rec;

		value = msg.value;
		G1_LOG_INF("start setting  parameter check. language type = %d\n", value);
		if (value < 1 || value > 25) {
			G1_LOG_ERR("Setting Task received error language parameters.\n");
			ret = -1;
			break;
		}
		if (CURRENT_LANGUAGE.language == value) {
			G1_LOG_INF("Setting Task received same language parameters.drop it ..\n");
			ret = -1;
			break;
		}
		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			ret = -1;
			break;
		}
		memset(&rec, 0, sizeof(rec));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
						      &rec, sizeof(rec))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		rec.magic = SETTING_MAGIC;
		rec.language = value;
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(), SETTING_FLASH_ADDR,
							 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			break;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(), SETTING_FLASH_ADDR,
							 &rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			break;
		}
		memset(&rec, 0, sizeof(rec));
		ret = get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
							&rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		CURRENT_LANGUAGE.language = rec.language;
		G1_LOG_INF("language infomation  %d store sucess\n", CURRENT_LANGUAGE.language);
		break;
	}
	case SETTING_CMD_LANGUAGE_CLEAN: {
		struct app_setting rec;

		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			ret = -1;
			break;
		}
		memset(&rec, 0, sizeof(rec));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
						      &rec, sizeof(rec))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		rec.magic = SETTING_MAGIC;
		rec.language = 2;
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(), SETTING_FLASH_ADDR,
							 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			break;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(), SETTING_FLASH_ADDR,
							 &rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			break;
		}
		memset(&rec, 0, sizeof(rec));
		ret = get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
							&rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		G1_LOG_INF("App language clean success.\n");
		CURRENT_LANGUAGE.language = 2;
		break;
	}
	case SETTING_CMD_STARTUP_MODE: {
		struct app_setting rec;

		value = msg.value;
		G1_LOG_INF("start setting  parameter check. startup_mode type = %d\n", value);
		if (CURRENT_LANGUAGE.startup_mode == value) {
			G1_LOG_ERR("Setting Task received same language parameters.drop it ..\n");
			ret = -1;
			break;
		}
		if (value > 2) {
			G1_LOG_ERR("dashboard startup mode value error,exit...\n");
			ret = -1;
			break;
		}
		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			ret = -1;
			break;
		}
		memset(&rec, 0, sizeof(rec));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
						      &rec, sizeof(rec))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		rec.magic = SETTING_MAGIC;
		rec.startup_mode = value;
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(), SETTING_FLASH_ADDR,
							 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			break;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(), SETTING_FLASH_ADDR,
							 &rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			break;
		}
		memset(&rec, 0, sizeof(rec));
		ret = get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
							&rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		CURRENT_LANGUAGE.startup_mode = rec.startup_mode;
		G1_LOG_INF("startup mode  infomation  %d store sucess\n", CURRENT_LANGUAGE.startup_mode);
		value = CURRENT_LANGUAGE.startup_mode;
		if (value == 0 && get_dashboard_state()->f_1244 == 4) {
			upgradeDoubleTapCustomizeToFlash(value);
		}
		break;
	}
	case SETTING_CMD_STARTUP_MODE_CLEAN: {
		struct app_setting rec;

		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			ret = -1;
			break;
		}
		memset(&rec, 0, sizeof(rec));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
						      &rec, sizeof(rec))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		rec.magic = SETTING_MAGIC;
		rec.startup_mode = 0;
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(), SETTING_FLASH_ADDR,
							 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			break;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(), SETTING_FLASH_ADDR,
							 &rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			break;
		}
		memset(&rec, 0, sizeof(rec));
		ret = get_dashboard_state()->flash_read(get_dashboard_state(), SETTING_FLASH_ADDR,
							&rec, sizeof(rec));
		if (ret) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n", SETTING_FLASH_ADDR);
			ret = -1;
			break;
		}
		G1_LOG_INF("App language clean success.\n");
		CURRENT_LANGUAGE.startup_mode = 0;
		break;
	}
	default:
		break;
	}
	return ret;
}

/* old Ghidra names, kept as aliases until the callers in other modules are renamed */
extern __typeof__(get_dashboard_startup_mode) FUN_000260dc __attribute__((alias("get_dashboard_startup_mode")));
extern __typeof__(clearSettingStorageQueue) FUN_00025bd0 __attribute__((alias("clearSettingStorageQueue")));

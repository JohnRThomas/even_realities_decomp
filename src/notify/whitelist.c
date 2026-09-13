/*
 * Notification white list (which phone apps may raise notifications):
 * flash storage, JSON exchange with the phone app and look-up.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

#define WHITELIST_FLASH_ADDR    0x131000
#define MAX_WHITE_LIST_APP_NUM  100
#define MAX_WHITE_LIST_BUF_LEN  (sizeof(struct app_whitelist) + 1)

extern int flash_settings_read(uint32_t addr, void *buf, size_t len);
extern int write_whitelist_to_flash(uint32_t addr, const void *buf, size_t len);
extern int parse_receiver_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);

struct app_info {
	char id[40];
	char name[16];
};

struct app_whitelist {
	uint8_t call_enable : 1;
	uint8_t msg_enable : 1;
	uint8_t ios_mail_enable : 1;
	uint8_t calendar_enable : 1;
	uint8_t app_enable : 1;
	uint8_t app_count;
	struct app_info list[MAX_WHITE_LIST_APP_NUM];
};

BUILD_ASSERT(sizeof(struct app_whitelist) == 0x15e2);

static char *whitelist_buf;
struct app_whitelist g_appWhiteListInfo;

#line 19
void dump_whitelist(void);

int store_whitelist(void)
{
	int ret;
	uint8_t retry = 3;

	do {
		ret = write_whitelist_to_flash(WHITELIST_FLASH_ADDR, &g_appWhiteListInfo,
					       sizeof(g_appWhiteListInfo));
		if (ret == 0) {
			dump_whitelist();
			break;
		}
		k_sleep(K_MSEC(5));
		BLE_PRINTK("write to flash failed, should retry ! \n");
	} while (--retry);
	BLE_PRINTK("[%s-%d] flash_settings_write_and_verify ret is %d \n", __func__, __LINE__, ret);
	return ret;
}

#line 40
int load_whitelist(void)
{
	struct app_whitelist tmp;
	int ret;

	memset(&tmp, 0, sizeof(tmp));
	ret = flash_settings_read(WHITELIST_FLASH_ADDR, &tmp, sizeof(tmp));
	if (ret) {
		BLE_PRINTK("[%s-%d] flash_settings_read error,ret is %d \n", __func__, __LINE__, ret);
		return -1;
	}

	/* the app list must fit */
	if (tmp.app_count > MAX_WHITE_LIST_APP_NUM) {
		BLE_PRINTK("[%s-%d] error,appCounts is %d \n", __func__, __LINE__, tmp.app_count);
		return -1;
	}
	memcpy(&g_appWhiteListInfo, &tmp, sizeof(tmp));
	return 0;
}

uint8_t *get_app_whitelist_info(void)
{
	return (uint8_t *)&g_appWhiteListInfo;
}

#line 67
uint8_t is_on_whitelist_by_identifier(const char *pkg_name)
{
	if (pkg_name == NULL) {
		BLE_PRINTK("[%s-%d] pkg_name is NULL !\n", __func__, __LINE__);
		return 0;
	}
	if (strlen(pkg_name) >= 40) {
		BLE_PRINTK("[%s-%d] pkg_name length is too long !\n", __func__, __LINE__);
		return 0;
	}
	BLE_PRINTK("pkg_name is %s \n", pkg_name);
	if (strncmp("com.apple.mobilephone", pkg_name, 21) == 0 ||
	    strncmp("com.apple.mobilephone_missed", pkg_name, 28) == 0 ||
	    strncmp("com.android.phone_incall", pkg_name, 24) == 0 ||
	    strncmp("com.android.phone_missed", pkg_name, 24) == 0) {
		if (g_appWhiteListInfo.call_enable) {
			BLE_PRINTK("whitelist type call is enable ! \n");
			return 2;
		}
		BLE_PRINTK("whitelist type call is disable ! \n");
		return 1;
	}
	if (strncmp("com.apple.MobileSMS", pkg_name, 19) == 0 ||
	    strncmp("com.android.even_sms", pkg_name, 20) == 0) {
		if (g_appWhiteListInfo.msg_enable) {
			BLE_PRINTK("whitelist type message is enable ! \n");
			return 2;
		}
		BLE_PRINTK("whitelist type message is disable ! \n");
		return 1;
	}
	if (strncmp("com.apple.mobilecal", pkg_name, 19) == 0 ||
	    strncmp("com.android.even_calendar", pkg_name, 25) == 0) {
		if (g_appWhiteListInfo.calendar_enable) {
			BLE_PRINTK("whitelist type calendar is enable ! \n");
			return 2;
		}
		BLE_PRINTK("whitelist type calendar is disable ! \n");
		return 1;
	}
	if (strncmp("com.apple.mobilemail", pkg_name, 20) == 0) {
		if (g_appWhiteListInfo.ios_mail_enable) {
			BLE_PRINTK("whitelist type mail is enable ! \n");
			return 2;
		}
		BLE_PRINTK("whitelist type mail is disable ! \n");
		return 1;
	}
	BLE_PRINTK("appcounts is %d \n", g_appWhiteListInfo.app_count);
	if (g_appWhiteListInfo.app_enable && g_appWhiteListInfo.app_count) {
		for (uint8_t i = 0; i < g_appWhiteListInfo.app_count; i++) {
			const char *id = g_appWhiteListInfo.list[i].id;

			BLE_PRINTK("g_appWhiteListInfo.listAppInfo[%d].id is %s \n", i, id);
			if (strncmp(id, pkg_name, strlen(id)) == 0) {
				return 2;
			}
		}
	}
	if (strstr("com.apple.mobilecal", pkg_name)) {
		return 3;
	}
	return 1;
}

#line 452
void put_whitelist_app_from_app(struct ble_context *ctx, uint8_t *hdr, const uint8_t *data,
				uint16_t len, uint8_t *rsp)
{
	if (whitelist_buf == NULL) {
		whitelist_buf = malloc(0x1800);
		if (whitelist_buf == NULL) {
			BLE_PRINTK("[%s-%d] malloc failed !!\n", __func__, __LINE__);
		} else {
			memset(whitelist_buf, 0, 0x1800);
		}
	}
	if (whitelist_buf != NULL) {
		int ret = parse_receiver_pack_pkcs7((uint8_t *)whitelist_buf, data, len);

		rsp[1] = ret;
		if (ret == PKCS7_PACK_DONE) {
			if (!is_the_same_whitelist_app(whitelist_buf)) {
				if (parse_app_white_list_json(whitelist_buf)) {
					if (store_whitelist()) {
						BLE_PRINTK("store_write#whitelist_app: FAIL");
						rsp[1] = 0xca;
					}
				} else {
					BLE_PRINTK("invalid whilte list json ! \n");
					rsp[1] = 0xca;
				}
			}
			free(whitelist_buf);
			whitelist_buf = NULL;
		}
	}
	ctx->write(rsp, 2);
}

#line 132
int parse_app_white_list_json(const char *json)
{
	cJSON *root;
	cJSON *item;
	cJSON *app;
	cJSON *list;
	cJSON *single;
	cJSON *id;
	cJSON *name;
	uint8_t i;
	uint8_t n = 0;
	uint8_t count;

	root = cJSON_Parse(json);
	if (root == NULL) {
		BLE_PRINTK("error root JSON NODE,json_buffer is %s\n", json);
		return 0;
	}
	memset(&g_appWhiteListInfo, 0, sizeof(g_appWhiteListInfo));
	item = cJSON_GetObjectItem(root, "call_enable");
	if (item == NULL) {
		BLE_PRINTK("callEnable is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	g_appWhiteListInfo.call_enable = item->type == cJSON_True;
	item = cJSON_GetObjectItem(root, "msg_enable");
	if (item == NULL) {
		BLE_PRINTK("msgEnable is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	g_appWhiteListInfo.msg_enable = item->type == cJSON_True;
	item = cJSON_GetObjectItem(root, "calendar_enable");
	if (item == NULL) {
		BLE_PRINTK("jsonCaledarEnable is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	g_appWhiteListInfo.calendar_enable = item->type == cJSON_True;
	item = cJSON_GetObjectItem(root, "ios_mail_enable");
	if (item == NULL) {
		BLE_PRINTK("jsonIosMailEnable is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	g_appWhiteListInfo.ios_mail_enable = item->type == cJSON_True;
	app = cJSON_GetObjectItem(root, "app");
	if (app == NULL) {
		BLE_PRINTK("appJson is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	item = cJSON_GetObjectItem(app, "enable");
	if (item == NULL) {
		BLE_PRINTK("appEnableJson is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	g_appWhiteListInfo.app_enable = item->type == cJSON_True;
	list = cJSON_GetObjectItem(app, "list");
	if (list == NULL) {
		BLE_PRINTK("appListJson is NULL !\n");
		cJSON_Delete(root);
		return 0;
	}
	if (cJSON_IsArray(list)) {
		count = cJSON_GetArraySize(list);
		if (count > MAX_WHITE_LIST_APP_NUM - 1) {
			count = MAX_WHITE_LIST_APP_NUM;
		}
		g_appWhiteListInfo.app_count = count;
		for (i = 0; i < g_appWhiteListInfo.app_count; i++) {
			single = cJSON_GetArrayItem(list, i);
			if (single == NULL) {
				BLE_PRINTK("singleAppJson is NULL !\n");
				continue;
			}
			id = cJSON_GetObjectItem(single, "id");
			if (id == NULL) {
				BLE_PRINTK("appIdJson is NULL !\n");
				continue;
			}
			name = cJSON_GetObjectItem(single, "name");
			if (name == NULL) {
				BLE_PRINTK("appNameJson is NULL !\n");
				continue;
			}
			memset(g_appWhiteListInfo.list[n].id, 0, sizeof(g_appWhiteListInfo.list[n].id));
			memset(g_appWhiteListInfo.list[n].name, 0,
			       sizeof(g_appWhiteListInfo.list[n].name));
			strncpy(g_appWhiteListInfo.list[n].id, id->valuestring,
				sizeof(g_appWhiteListInfo.list[n].id) - 1);
			strncpy(g_appWhiteListInfo.list[n].name, name->valuestring,
				sizeof(g_appWhiteListInfo.list[n].name) - 1);
			n++;
		}
	}
	cJSON_Delete(root);
	return 1;
}

int is_app_name_same(const char *id, const char *name)
{
	if (id == NULL || name == NULL) {
		BLE_PRINTK("invalid param ! \n");
		return 0;
	}
	for (uint8_t i = 0; i < g_appWhiteListInfo.app_count; i++) {
		if (strncmp(g_appWhiteListInfo.list[i].id, id, 40) == 0 &&
		    strncmp(g_appWhiteListInfo.list[i].name, name, 16) == 0) {
			return 1;
		}
	}
	return 0;
}

int is_the_same_whitelist_app(const char *json)
{
	cJSON *root;
	cJSON *item;
	cJSON *app;
	cJSON *list;
	cJSON *single;
	cJSON *id;
	cJSON *name;
	char app_name[16];
	char app_id[40];
	uint8_t i;
	uint8_t count;
	uint8_t same;
	int ret = 0;

	root = cJSON_Parse(json);
	if (root == NULL) {
		BLE_PRINTK("error root JSON NODE !\n");
		return 0;
	}
	do {
		item = cJSON_GetObjectItem(root, "call_enable");
		if (item == NULL) {
			BLE_PRINTK("callEnable is NULL !\n");
			goto out;
		}
		if (0) {
fail:
			goto out;
		}
		if (0) {
out:
			cJSON_Delete(root);
			if (!BLE_DEBUG) {
				break;
			}
			ble_printk("is_the_same_whitelist_app ret is %d\n", ret);
			return ret;
		}
		if (g_appWhiteListInfo.call_enable != (item->type == cJSON_True)) {
			BLE_PRINTK("callEnable is not the same !\n");
			goto out;
		}
		item = cJSON_GetObjectItem(root, "msg_enable");
		if (item == NULL) {
			BLE_PRINTK("msgEnable is NULL !\n");
			goto out;
		}
		if (g_appWhiteListInfo.msg_enable != (item->type == cJSON_True)) {
			BLE_PRINTK("msgEnable is not the same !\n");
			goto out;
		}
		item = cJSON_GetObjectItem(root, "calendar_enable");
		if (item == NULL) {
			BLE_PRINTK("jsonCalendarEnable is NULL !\n");
			goto out;
		}
		if (g_appWhiteListInfo.calendar_enable != (item->type == cJSON_True)) {
			BLE_PRINTK("calendarEnable is not the same !\n");
			goto out;
		}
		item = cJSON_GetObjectItem(root, "ios_mail_enable");
		if (item == NULL) {
			BLE_PRINTK("iosMailEnableJson is NULL !\n");
			goto out;
		}
		if (g_appWhiteListInfo.ios_mail_enable != (item->type == cJSON_True)) {
			BLE_PRINTK("iosMailEnable is not the same !\n");
			goto out;
		}
		app = cJSON_GetObjectItem(root, "app");
		if (app == NULL) {
			BLE_PRINTK("appJson is NULL !\n");
			goto out;
		}
		item = cJSON_GetObjectItem(app, "enable");
		if (item == NULL) {
			BLE_PRINTK("appEnableJson is NULL !\n");
			goto out;
		}
		if (g_appWhiteListInfo.app_enable != (item->type == cJSON_True)) {
			BLE_PRINTK("appEnable is not the same !\n");
			goto out;
		}
		list = cJSON_GetObjectItem(app, "list");
		if (list == NULL) {
			BLE_PRINTK("appListJson is NULL !\n");
			goto out;
		}
		if (!cJSON_IsArray(list)) {
			goto fail;
		}
		count = cJSON_GetArraySize(list);
		if (g_appWhiteListInfo.app_count != count) {
			BLE_PRINTK("appCounts is not the same !\n");
			goto out;
		}
		same = 0;
		/* i is the low byte of the int index (little-endian) */
		for (int idx = 0; (i = *(uint8_t *)&idx) < count; idx++) {
			single = cJSON_GetArrayItem(list, idx);
			if (single == NULL) {
				BLE_PRINTK("singleAppJson is NULL !\n");
				continue;
			}
			id = cJSON_GetObjectItem(single, "id");
			if (id == NULL) {
				BLE_PRINTK("appIdJson is NULL !\n");
				continue;
			}
			name = cJSON_GetObjectItem(single, "name");
			if (name == NULL) {
				BLE_PRINTK("appNameJson is NULL !\n");
				continue;
			}
			app_id[39] = 0;
			app_name[15] = 0;
			strncpy(app_id, id->valuestring, 39);
			strncpy(app_name, name->valuestring, 15);
			if (!is_app_name_same(app_id, app_name)) {
				break;
			}
			same++;
		}
		if (same == count) {
			BLE_PRINTK("the same whitelist ! \n");
			ret = 1;
		}
		goto out;
	} while (0);
	printk("is_the_same_whitelist_app ret is %d\n", ret);
	return ret;
}

uint16_t convert_app_whitelist_to_json(char *buf)
{
	cJSON *root;
	cJSON *app;
	cJSON *list;
	cJSON *item;
	char *str;
	size_t len;

	if (buf == NULL) {
#line 497
		BLE_PRINTK("[%s-%d]buf is null \n", __func__, __LINE__);
		return 0;
	}
	root = cJSON_CreateObject();
	if (root == NULL) {




		BLE_PRINTK("[%s-%d]jsonRoot is null \n", __func__, __LINE__);
		return 0;
	}
	cJSON_AddBoolToObject(root, "call_enable", g_appWhiteListInfo.call_enable);
	cJSON_AddBoolToObject(root, "msg_enable", g_appWhiteListInfo.msg_enable);
	cJSON_AddBoolToObject(root, "ios_mail_enable", g_appWhiteListInfo.ios_mail_enable);
	cJSON_AddBoolToObject(root, "calendar_enable", g_appWhiteListInfo.calendar_enable);
	app = cJSON_CreateObject();
	if (app == NULL) {



		BLE_PRINTK("[%s-%d]appJson is null \n", __func__, __LINE__);
		goto err;
	}
	cJSON_AddBoolToObject(app, "enable", g_appWhiteListInfo.app_enable);
	list = cJSON_CreateArray();
	if (list == NULL) {


		BLE_PRINTK("[%s-%d]appListInfoJson is null \n", __func__, __LINE__);
		goto err;
	}
	for (uint8_t i = 0; i < g_appWhiteListInfo.app_count; i++) {
		item = cJSON_CreateObject();
		if (item == NULL) {





			BLE_PRINTK("[%s-%d]appItem is null \n", __func__, __LINE__);
			goto err;
		}
		cJSON_AddStringToObject(item, "id", g_appWhiteListInfo.list[i].id);
		cJSON_AddStringToObject(item, "name", g_appWhiteListInfo.list[i].name);
		cJSON_AddItemToArray(list, item);
	}
	cJSON_AddItemToObject(app, "list", list);
	cJSON_AddItemToObject(root, "app", app);
	str = cJSON_PrintUnformatted(root);
	BLE_PRINTK("cJsonStr is %s \n", str);
	strcpy(buf, str);
	len = strlen(str);
	free(str);
	cJSON_Delete(root);
	return len;
err:
	cJSON_Delete(root);
	return 0;
}

#line 556
void get_whitelist_app_from_device(struct ble_context *ctx, uint8_t *rsp)
{
	char *buf;
	char *src;
	int len;
	int rem;
	uint8_t pad;
	int i, n, total;

	buf = malloc(MAX_WHITE_LIST_BUF_LEN);
	if (buf == NULL) {
		BLE_PRINTK("[%s-%d] buf is NULL \n", __func__, __LINE__);
		return;
	}
	rsp[1] = 0x6a;
	memset(buf, 0, MAX_WHITE_LIST_BUF_LEN);
	len = convert_app_whitelist_to_json(buf);
	if (len == 0) {
		BLE_PRINTK("[%s-%d] total_len is %d \n", __func__, __LINE__ + 1, len);
		return;
	}
	rem = len % 17;
	pad = 17 - rem;
	n = len / 17;		/* full 17-byte chunks */
	total = n + 1;		/* plus the (possibly empty) last packet */
	rsp[1] = total;
	src = buf;
	for (i = 0; i < n; i++) {
		rsp[2] = i;
		memcpy(&rsp[3], src, 17);
		src += 17;
		ctx->write(rsp, 0x14);
	}
	rsp[2] = i;
	if (rem == 0) {
		memset(&rsp[3], 0, pad);
		ctx->write(rsp, 3);
	} else {
		memcpy(&rsp[3], src, rem);
		memset(&rsp[3 + rem], 0, pad);
		ctx->write(rsp, rem + 3);
	}
	free(buf);
}

#line 626
void dump_whitelist(void)
{
	char *buf = malloc(0x1800);

	if (buf == NULL) {
		BLE_PRINTK("[%s-%d] malloc failed !!\n", __func__, __LINE__);
		return;
	}
	memset(buf, 0, MAX_WHITE_LIST_BUF_LEN);
	convert_app_whitelist_to_json(buf);
	free(buf);
}

void load_app_white_list_from_flash(void)
{
	memset(&g_appWhiteListInfo, 0, sizeof(g_appWhiteListInfo));
	printk("MAX_WHITE_LIST_BUF_LEN is %d \n", MAX_WHITE_LIST_BUF_LEN);
	if (load_whitelist() == 0) {
		dump_whitelist();
	}
}

/* Old placeholder names, still used by other modules (renamed 2026-10-21, byte-neutral). */
extern __typeof__(get_app_whitelist_info) FUN_00036268 __attribute__((alias("get_app_whitelist_info")));

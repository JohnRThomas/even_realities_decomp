/*
 * BLE application protocol: debug channel, pkcs7 packet reassembly, request
 * handlers / dispatch and the BLE work thread.
 * Reconstructed from the G1 v1.63 app core (original file name unknown).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#if __has_include(<cJSON.h>)
#include <cJSON.h>
#else
/* cJSON include path is missing until CONFIG_CJSON_LIB=y is set in prj.conf */
typedef struct cJSON cJSON;
typedef int cJSON_bool;
cJSON *cJSON_CreateObject(void);
cJSON *cJSON_AddNumberToObject(cJSON *const object, const char *const name, const double number);
cJSON *cJSON_AddStringToObject(cJSON *const object, const char *const name,
			       const char *const string);
cJSON_bool cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);
char *cJSON_Print(const cJSON *item);
void cJSON_Delete(cJSON *item);
#endif

#include "g1_log.h"
#include "ble_proto.h"



BUILD_ASSERT(sizeof(struct schedule_item) == 0xa4);
BUILD_ASSERT(sizeof(struct stock_item) == 0x7f2);
BUILD_ASSERT(sizeof(struct news_item) == 0x159);
BUILD_ASSERT(sizeof(struct teleprompter_info) == 0x217);
BUILD_ASSERT(sizeof(struct nav_info) == 0xf5);
BUILD_ASSERT(sizeof(struct translate_buf) == 0x1e8);
BUILD_ASSERT(sizeof(struct quicknote_item) == 0x143);
BUILD_ASSERT(offsetof(struct dashboard_ts_view, disp_mode) == 0x65);
BUILD_ASSERT(offsetof(struct dashboard_ts_view, f_72) == 0x72);
BUILD_ASSERT(offsetof(struct GlassesState, f_0dd) == 0xdd);
BUILD_ASSERT(offsetof(struct GlassesState, lum_cur) == 0xed8);
BUILD_ASSERT(offsetof(struct GlassesState, lum_gear) == 0xede);
BUILD_ASSERT(offsetof(struct GlassesState, user_horiz_pitch) == 0xf6c);
BUILD_ASSERT(offsetof(struct GlassesState, f_fea) == 0xfea);
BUILD_ASSERT(offsetof(struct GlassesState, teleprompter) == 0x1000);
BUILD_ASSERT(offsetof(struct GlassesState, translate_dst) == 0x100c);
BUILD_ASSERT(offsetof(struct GlassesState, horiz_pitch_cfg) == 0x1024);
BUILD_ASSERT(offsetof(struct GlassesState, quicknote) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, qn_show) == 0x1034);
BUILD_ASSERT(offsetof(struct GlassesState, file_ts) == 0x1078);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d5) == 0x10d5);
uint8_t DAT_20016b1f[0x1210];               /* navigation overview map */
uint8_t DAT_20012a4f[PANORAMIC_MAP_SIZE];   /* panoramic map / citywalk data */


/* .bss, 2-byte aligned */
static volatile uint16_t sched_cnt;       /* 0x200100d0 */
static volatile uint16_t sched_total;     /* 0x200100ce */
static volatile uint16_t sched_len;       /* 0x200100cc */
struct stock_item DAT_2000e104[4];
static volatile uint16_t stock_cnt;       /* 0x2000e102 */
static volatile uint16_t stock_total;     /* 0x2000e100 */
static volatile uint16_t stock_len;       /* 0x2000e0fe */
static volatile uint16_t news_cnt;        /* 0x2000e0fc */
static volatile uint16_t news_total;      /* 0x2000e0fa */
static volatile uint16_t news_len;        /* 0x2000e0f8 */
static volatile uint16_t citywalk_len;    /* 0x2000e0f6 */
volatile uint16_t DAT_2000e0f4;
volatile uint16_t DAT_2000e0f2;
volatile uint16_t DAT_2000e0f0;
static volatile uint16_t tp_len;          /* 0x2000e0ee */
static volatile uint16_t pano_len;        /* 0x2000e0ec */
static volatile uint16_t pano_cnt;        /* 0x2000e0ea */
static volatile uint16_t pano_total;      /* 0x2000e0e8 */
static volatile uint16_t qn_len;          /* 0x2000e0e6 */
static volatile uint16_t qn_cnt;          /* 0x2000e0e4 */
static volatile uint16_t qn_total;        /* 0x2000e0e2 */
static volatile uint16_t nav_last_x;      /* 0x2000e0e0 */
static volatile uint16_t nav_last_y;      /* 0x2000e0de */
static uint16_t pack_offset;     /* 0x2000e0dc */
static uint16_t msg_pack_offset; /* 0x2000e0da */
static uint16_t msg_pack_id;     /* 0x2000e0d8 */

/*
 * .bss, 4-byte aligned (reverse definition order in the image):
 * 0x20007ef4 DAT_20007ef4 ... 0x20007f54 k_mutex_20007f54
 */
struct k_mutex k_mutex_20007f54;
atomic_t DAT_20007f50;
atomic_t DAT_20007f4c;
uint32_t DAT_20007f48;
uint32_t DAT_20007f44;
static int dmic_send_count;      /* 0x20007f40 */
static int dmic_pkt_count;       /* 0x20007f3c */
static int send_fail_count;      /* 0x20007f38 */
static int send_fail_count_06;   /* 0x20007f34 */
int BLE_DEBUG;
int debug_pending;               /* 0x20007f2c (not static: the shipped code keeps its store after the rx_bufs[2] stores) */
static struct k_msgq debug_msgq; /* 0x20007ef8 */

/* .data (put_req) */
static volatile uint8_t citywalk_reload = 1; /* 0x20003005 */
uint8_t BIT_MAP_CHUNK_ID = 0xff;    /* 0x20003004 */
/* citywalk bitmaps inside DAT_20012a4f, referenced by name from DashBoard_Reflash */
__asm__(".global DAT_200143cf\n.set DAT_200143cf, DAT_20012a4f + 0x1980\n"
	".global DAT_20015777\n.set DAT_20015777, DAT_20012a4f + 0x2d28\n"
	".global DAT_20015cc7\n.set DAT_20015cc7, DAT_20012a4f + 0x3278\n"
	".global DAT_20014ab7\n.set DAT_20014ab7, DAT_20012a4f + 0x2068\n");
struct schedule_item DAT_2001252f[8];
static uint8_t sched_buf[0x538];            /* 0x20011ff7 */
static uint8_t stock_buf[0x812];            /* 0x200117e5 */
struct news_item DAT_20011281[4];
static uint8_t news_buf[0x161];             /* 0x20011120 */
static volatile uint8_t DAT_2001111f;
static volatile uint8_t DAT_2001111e;
volatile uint8_t DAT_2001111d;          /* citywalk map valid (read by DashBoard_Reflash) */
static struct teleprompter_info tp_buf;     /* 0x20010f06 */
uint8_t DAT_20010f05;
static struct qn_title qn_title_buf;        /* 0x20010edc */
static uint8_t qn_text_buf[0x119];          /* 0x20010dc3 */
static volatile uint8_t qn_num;             /* 0x20010dc2 */
uint8_t DAT_20010dc1;
uint8_t DAT_20010dc0;
uint8_t DAT_20010dbf;
uint8_t DAT_20010dbe;
uint8_t DAT_20010dbd;
uint8_t DAT_20010dbc;
static uint8_t dmic_seq;         /* 0x20010dbb */
static uint8_t pack_cmd;         /* 0x20010dba */
static uint8_t msg_pack_cmd;     /* 0x20010db9 */
static uint8_t debug_buf[DEBUG_MSG_SIZE]; /* 0x20010cf1 */
static uint8_t DAT_20010b99[0x158];         /* translate / quick note packet buffer */

void lock_k_mutex_20007f54(k_timeout_t timeout)
{
	k_mutex_lock(&k_mutex_20007f54, timeout);
}

void unlock_k_mutex_20007f54(void)
{
	k_mutex_unlock(&k_mutex_20007f54);
}

int spim_transfer(struct ble_context *ctx, uint8_t *buf, uint32_t len)
{
	struct GlassesState *state = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	int ret;

	if (LOG_LEVEL == 5) {
		printk("spim tx(len=%d): %02x,%02x,%02x,%02x, %02x,%02x,%02x,%02x\n", ctx->tx_len,
		       ctx->tx_buf[0], ctx->tx_buf[1], ctx->tx_buf[2], ctx->tx_buf[3],
		       ctx->tx_buf[0], ctx->tx_buf[1], ctx->tx_buf[2], ctx->tx_buf[3]);
	}
	ret = master_process_put_req(state, ctx->tx_buf, buf, len);
	if (LOG_LEVEL == 5) {
		printk("spim ret(len=%d): %02x,%02x,%02x,%02x, %02x,%02x,%02x,%02x\n", len,
		       buf[0], buf[1], buf[2], buf[3], buf[0], buf[1], buf[2], buf[3]);
	}
	return ret;
}

int debug_init(void)
{
	int ret;

	ret = k_msgq_alloc_init(&debug_msgq, DEBUG_MSG_SIZE, DEBUG_MSGQ_MAX);
	if (ret) {
		printk("debug init failed\r\n");
	} else {
		printk("debug init success\r\n");
	}
	return ret;
}

int enqueue_debug(void *msg)
{
	int ret;

	if (debug_msgq.used_msgs == DEBUG_MSGQ_MAX) {
		/* drop the oldest message */
		k_msgq_get(&debug_msgq, debug_buf, K_NO_WAIT);
	}
	memcpy(debug_buf, msg, DEBUG_MSG_SIZE);
	ret = k_msgq_put(&debug_msgq, debug_buf, K_NO_WAIT);
	if (ret) {
		printk("enqueue_debug failed\r\n");
	}
	return ret;
}

int dequeue_debug(void *msg)
{
	uint8_t buf[DEBUG_MSG_SIZE];
	int ret;

	ret = k_msgq_get(&debug_msgq, buf, K_NO_WAIT);
	if (ret == 0) {
		memcpy(msg, buf, DEBUG_MSG_SIZE);
	}
	return ret;
}

/*
 * Test commands typed into the phone app's debug console (plain strings
 * instead of protocol packets).  Returns non-zero if the data is not a test
 * command and must be handled as a normal request.
 */
int spec_ble_command_hook(uint8_t *data, uint32_t len)
{
	struct ble_context *ctx = get_ble_context();
	struct GlassesState *state = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	char buf[256] = {0};
	char *pos;
	int val;

	memcpy(buf, data, len);

	if (strcmp(buf, "#c") == 0) {
		G1_LOG_INF("test:BLE_REQ_POST_BT_UNPAIR\n\n");
		buf[0] = 0x47;
		FUN_0007f50c((uint8_t *)buf, 1);
		return 0;
	}

	pos = strstr(buf, "#1@");
	if (pos) {
		char title[32] = {0};
		char message[128] = {0};
		char *p;

		pos += 3;
		for (p = pos; *p != '@'; p++) {
		}
		memcpy(title, pos, p - pos);
		strcpy(message, p + 1);
		G1_LOG_INF("模拟接收到新通知 title:%s, message:%s\n", title, message);
		return mobile_send_notification_to_ble_device_test(title, message, FUN_0007f50c);
	}

	pos = strstr(buf, "#2@");
	if (pos) {
		pos += 3;
		val = atoi(pos);
		G1_LOG_INF("模拟抬头/低头触发:pos:%s, val=%d\n\n", pos, val);
		buf[0] = 5;
		buf[1] = 1;
		buf[2] = val != 0;
		FUN_0007f50c((uint8_t *)buf, 3);
		return 0;
	}

	pos = strstr(buf, "#3@");
	if (pos) {
		pos += 3;
		val = atoi(pos);
		G1_LOG_INF("pos:%s, new screen_id=%d\n\n", pos, val);
		buf[0] = 5;
		buf[1] = 3;
		buf[2] = val;
		FUN_0007f50c((uint8_t *)buf, 3);
		return 0;
	}

	pos = strstr(buf, "#4@");
	if (pos) {
		pos += 3;
		val = atoi(pos);
		if (val > 2) {
			BLE_PRINTK("%s(): pos:%s, new log_level_set=%d\n\n", __func__, pos, val);
		}
		buf[0] = 5;
		buf[1] = 2;
		buf[2] = val;
		FUN_0007f50c((uint8_t *)buf, 3);
		return 0;
	}

	pos = strstr(buf, "#5@");
	if (pos) {
		char str[16] = {0};
		char *p, *q;
		int sec, enable;

		memcpy(str, pos + 3, 4);
		G1_LOG_INF("buf:%s\n\n", str);
		p = str;
		while (*p != '\0') {
			if (*++p == '@') {
				break;
			}
		}
		char cmd[4] = {0};

		memcpy(cmd, str, p - str);
		G1_LOG_INF("cmd:%s\n\n", cmd);
		p++;
		char en[4] = {0};

		for (q = p; *q != '\0'; q++) {
		}
		memcpy(en, p, q - p);
		G1_LOG_INF("en:%s\n\n", en);
		sec = atoi(cmd) * 60 + 3610;
		buf[0] = 7;
		memcpy(&buf[1], &sec, sizeof(sec));
		enable = atoi(en);
		buf[5] = enable;
		G1_LOG_INF("enable: %d, sec:%d\n\n", enable, sec);
		FUN_0007f50c((uint8_t *)buf, 6);
		return 0;
	}

	pos = strstr(buf, "#cmd@");
	if (pos) {
		char *p;
		int n, cmd;

		pos += 5;
		G1_LOG_INF("pos=%s, tx_data_len=%d\n\n", pos, len);
		char cmd_type[4] = {0};
		char value[128] = {0};

		dump_hex("ble", (uint8_t *)pos, 8);
		for (p = pos; *p != '@'; p++) {
		}
		n = p - pos;
		G1_LOG_INF("11 len=%d\n", n);
		memcpy(cmd_type, pos, n);
		cmd = atoi(cmd_type);
		G1_LOG_INF("cmd=%d\n", cmd);
		if (cmd == 4) {
			G1_LOG_INF("BLE_REQ_PUT_NOTIFI_WHIHTLIST_APP需要单独处理.\n\n");
			char json[256] = {0};

			strcpy(json, "{\"whitelist_app\":\"com.apple.MobileSMS:com.tencent.xin:com.tencent.mqq\"}");
			n = strlen(json);
			G1_LOG_INF("cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n", cmd_type,
				   value, 0, n, json);
			subcontracing_send_data_pkcs7((uint8_t *)json, n, 4, FUN_0007f50c);
			return 0;
		}
		if (cmd == 9) {
			cJSON *info, *root;
			char *str;

			G1_LOG_INF("simulator->BLE_REQ_PUT_TELEPROMPTER_INFO.\n\n");
			info = cJSON_CreateObject();
			cJSON_AddNumberToObject(info, "enable", 1);
			cJSON_AddStringToObject(info, "text",
				"提词器功能很简单,我们只需要把文档或者TXT文件上传到手机APP中,眼镜上就显示相应的文字，我们可以用手机当遥控器翻...");
			root = cJSON_CreateObject();
			cJSON_AddItemToObject(root, "teleprompter_info", info);
			str = cJSON_Print(root);
			n = strlen(str);
			G1_LOG_INF("cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n", cmd_type,
				   value, 0, n, str);
			subcontracing_send_data_pkcs7((uint8_t *)str, n, 9, FUN_0007f50c);
			cJSON_Delete(root);
			return 0;
		}
		if (cmd == 10) {
			cJSON *info, *root;
			char *str;

			G1_LOG_INF("simulator->BLE_REQ_PUT_NAVIGATION_INFO.\n\n");
			info = cJSON_CreateObject();
			cJSON_AddNumberToObject(info, "enable", 1);
			cJSON_AddNumberToObject(info, "direction", 2);
			cJSON_AddStringToObject(info, "info", "前面100米路口左拐进入留仙大道辅道.");
			root = cJSON_CreateObject();
			cJSON_AddItemToObject(root, "navigation_info", info);
			str = cJSON_Print(root);
			n = strlen(str);
			G1_LOG_INF("cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n", cmd_type,
				   value, 0, n, str);
			subcontracing_send_data_pkcs7((uint8_t *)str, n, 10, FUN_0007f50c);
			cJSON_Delete(root);
			return 0;
		}
		if (cmd == 0x58) {
			G1_LOG_INF("simulator:SCHEDULE 触发.\n\n");
			simulator_ancs_calendar_schedule_trigger();
			return 0;
		}
		if (cmd == 0x4b) {
			char title[32];
			char msg[128];
			char *q;

			p++;
			for (q = p; *q != '\0'; q++) {
			}
			n = q - p;
			G1_LOG_INF("22 len=%d\n", n);
			memcpy(value, p, n);
			for (q = value; *q != '#'; q++) {
			}
			memcpy(title, value, q - value);
			strcpy(msg, q + 1);
			G1_LOG_INF("#cmd_type:%s, title=%s, msg=%s\n\n", cmd_type, title, msg);
			return mobile_send_notification_to_ble_device_test(title, msg, FUN_0007f50c);
		}
		buf[0] = cmd;
		buf[1] = atoi(value);
		G1_LOG_INF("**cmd_type:%s, value=%s, tx_len=%d\n\n", cmd_type, value, 2);
		FUN_0007f50c((uint8_t *)buf, 2);
		return 0;
	}

	if (strncmp(buf, "#a", 2) == 0) {
		printk("\n*****test callback audio data*****\n");
		char req[20] = {0};

		req[0] = 0x6e;
		while (ctx->write(req, sizeof(req)) != 0) {
			k_sleep(K_MSEC(10));
			if (!ctx->f_365 || !ctx->send_enabled) {
				G1_LOG_ERR("unable to change MTU for audio transfer, due to no connected or "
					   "notification disabled\n");
				return 0;
			}
		}
		{
			uint8_t pkt[0x6b];
			uint16_t err_cnt = 0;
			int64_t t0;
			int i;

			k_sem_take(&ctx->tx_sem, K_FOREVER);
			printk("\n*****start upload audio*****\n");
			char audio[1024] = {0};
			/* kept as an integer address, not a char *: an (unsigned int)&audio
			 * conversion is no GIMPLE invariant, so p survives as a real pseudo (r6)
			 * that the fill loop and the send loop both start from */
			uintptr_t p = (uintptr_t)audio;

			for (i = 0; i < sizeof(audio); i++) {
				audio[i] = (i & 0xf) + '0';
			}
			t0 = k_uptime_get();
			for (i = 0; i < 9; i++) {
				pkt[0] = 0xf1;
				pkt[1] = 0x0a;
				pkt[2] = i;
				memcpy(&pkt[3], (void *)p, 0x68);
				while (ctx->write(pkt, sizeof(pkt)) != 0) {
					err_cnt++;
					k_sleep(K_MSEC(10));
					if (!ctx->f_365 || !ctx->send_enabled) {
						G1_LOG_ERR("unable to audio transfer, due to no "
							   "connected or notification disabled\n");
						return 0;
					}
				}
				p += 0x68;
			}
			printk("t0 = %d error count = %d \n", (int)(k_uptime_get() - t0),
			       err_cnt);
		}
		return 0;
	}

	if (strncmp(buf, "#b", 2) == 0) {
		val = atoi(&buf[2]);
		state->esb_channel = val;
		printk("\n*****test set esb channel***** %d\n", (uint8_t)val);
		state->dashboard_cmd = 0;
		sys_settings_dirty = 1;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#d", 2) == 0) {
		val = atoi(&buf[2]);
		state->f_fee = val;
		printk("\n*****display mode***** %d\n", (uint8_t)val);
		if (state->f_fee == 11) {
			state->f_ee8 = 2;
			change_work_mode(2);
			if (state->is_master == 2) {
				k_sem_give(&state->sem_020);
			}
		} else {
			state->f_ee8 = 1;
			change_work_mode(3);
		}
		state->dashboard_cmd = 0;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#e", 2) == 0) {
		if (buf[2] == '0') {
			FUN_00030458();
		} else {
			state->f_106d |= 4;
		}
		k_sem_give(&state->sem_068);
		return 0;
	}

	if (strncmp(buf, "#f", 2) == 0) {
		state->f_106d |= 8;
		k_sem_give(&state->sem_068);
		return 0;
	}

	if (strncmp(buf, "#g", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "TX:%d,fail:%d,RX:%d,Signal:%d", DAT_20006bd4, DAT_20006bd0,
			DAT_20006bcc, DAT_20006bc8);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#r", 2) == 0) {
		G1_LOG_ERR("sys reboot because reboot cmd\n");
		k_msleep(500);
		sys_reboot(SYS_REBOOT_COLD);
	}

	if (strncmp(buf, "#l", 2) == 0) {
		if (atoi(&buf[2]) == 1) {
			BLE_DEBUG = 0;
		} else {
			BLE_DEBUG = 1;
		}
		return 0;
	}

	if (strncmp(buf, "#o", 2) == 0) {
		char out[20] = {0};

		state->f_f68 = DAT_2000848c;
		sprintf(out, "base: %d", DAT_2000848c);
		ctx->write(out, sizeof(out));
		state->dashboard_cmd = 0;
		sys_settings_dirty = 1;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#i", 2) == 0) {
		char out[20] = {0};
		uint32_t lux = opt3007_get_max_lux();

		if (buf[2] != '\0') {
			if (atoi(&buf[2]) < 2U) {
				state->f_f9c = atoi(&buf[2]);
			} else {
				state->f_f9c = 0;
				state->f_ed5 = atoi(&buf[2]);
			}
		}
		if (lux == 0xffffffff) {
			sprintf(out, "base: %d", 80000);
		} else {
			sprintf(out, "base: %d", lux);
		}
		ctx->write(out, sizeof(out));
		state->dashboard_cmd = 0;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#y", 2) == 0) {
		char out[20] = {0};

		sprintf(out, "level: %d", state->f_ed5);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#u", 2) == 0) {
		char out[20] = {0};

		val = atoi(&buf[2]);
		state->f_ef8 = val;
		sprintf(out, "level: %d", (uint8_t)val);
		ctx->write(out, sizeof(out));
		state->dashboard_cmd = 0;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#p", 2) == 0) {
		char out[20] = {0};

		sprintf(out, "pitch: %d", DAT_2000848c);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#t", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "net build time: %s, app build time %s, ver %d.%d.%d, JBD DeviceID %x\n\r",
			DAT_2001093c, "2025-06-28 17:28:42", 1, 6, 3, JDB_PANEL_ID);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#v", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "B:%d, V:%d, A:%d, T:%d", state->f_fc4, state->f_fc8 + 200,
			state->f_fc9 - 128, state->f_fca);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#k", 2) == 0) {
		char out[64] = {0};

		sprintf(out, "VADC:%d TMR:%d", FUN_00027664(), 0);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#j", 2) == 0) {
		char out[20] = {0};

		if (atoi(&buf[2]) == 1) {
			state->ops_b10.fn(&state->ops_b10);
			state->ops_b30.fn(&state->ops_b30);
			strcpy(out, "init flash");
		} else {
			state->ops_b10.fn(&state->ops_b10);
			state->ops_b30.fn(&state->ops_b30);
			strcpy(out, "deinit flash");
		}
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#s", 2) == 0) {
		char out[20] = {0};

		change_work_mode(buf[2] != '\0' ? atoi(&buf[2]) : 7);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#h", 2) == 0) {
		char out[64] = {0};

		switch (atoi(&buf[2])) {
		case 1:
			state->dashboard_cmd = 0x19;
			sys_settings_dirty = 1;
			k_sem_give(&state->dashboard_position_sem);
			break;
		case 2:
			memset(state->master_mac, 0xff, sizeof(state->master_mac));
			memset(state->slave_mac, 0xff, sizeof(state->slave_mac));
			state->dashboard_cmd = 0x1a;
			sys_settings_dirty = 1;
			k_sem_give(&state->dashboard_position_sem);
			break;
		default:
			sprintf(out, "master mac: %02X:%02X:%02X:%02X:%02X:%02X, slave mac: "
				     "%02X:%02X:%02X:%02X:%02X:%02X",
				state->master_mac[0], state->master_mac[1], state->master_mac[2],
				state->master_mac[3], state->master_mac[4], state->master_mac[5],
				state->slave_mac[0], state->slave_mac[1], state->slave_mac[2],
				state->slave_mac[3], state->slave_mac[4], state->slave_mac[5]);
			break;
		}
		ctx->write(out, sizeof(out));
		return 0;
	}

	return -1;
}

#line 174
int parse_receiver_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len)
{
	uint8_t cmd, total, idx;

	if (req == NULL) {
		BLE_PRINTK("[%s-%d]error, req is NULL ! \n", __func__, __LINE__);
		return PKCS7_PACK_ERR;
	}

	if (origin_data == NULL) {
		BLE_PRINTK("[%s-%d]error, origin_data is NULL ! \n", __func__, __LINE__);
		return PKCS7_PACK_ERR;
	}


	if (req_len < 3) {
		BLE_PRINTK("[%s-%d]error, req_len is %d, too short ! \n", __func__, __LINE__, req_len);
		return PKCS7_PACK_ERR;
	}

	cmd = req[0];
	total = req[1];
	idx = req[2];
	if (idx == 0) {
		pack_offset = 0;
		pack_cmd = cmd;
	}

	/*
	 * (vendor file: the chunk header and bookkeeping comments stood here;
	 *  the line numbers in the logs below are the original ones, kept by the
	 *  #line at the top of each function)
	 *
	 *
	 */

	if (pack_cmd != cmd) {
		BLE_PRINTK("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n", __func__, __LINE__,
			   cmd, pack_cmd);
		return PKCS7_PACK_ERR;
	}
	memcpy(origin_data + pack_offset, req + 3, req_len - 3);
	pack_offset += (uint16_t)req_len - 3;
	if (idx == total - 1) {
		return PKCS7_PACK_DONE;
	}
	return PKCS7_PACK_MORE;
}

#line 226
int parse_receiver_msg_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len)
{
	uint8_t cmd, msg_id, total, idx;

	if (req == NULL) {
		BLE_PRINTK("[%s-%d]error, req is NULL ! \n", __func__, __LINE__);
		return PKCS7_PACK_ERR;
	}

	if (origin_data == NULL) {
		BLE_PRINTK("[%s-%d]error, origin_data is NULL ! \n", __func__, __LINE__);
		return PKCS7_PACK_ERR;
	}


	if (req_len < 4) {
		BLE_PRINTK("[%s-%d]error, req_len is %d, too short ! \n", __func__, __LINE__, req_len);
		return PKCS7_PACK_ERR;
	}

	cmd = req[0];
	msg_id = req[1];
	total = req[2];
	idx = req[3];
	if (idx == 0) {
		msg_pack_offset = 0;
		msg_pack_id = msg_id;
		msg_pack_cmd = cmd;
	}

	/*
	 * (vendor file: comment block of the message-chunk bookkeeping stood here;
	 *  see the note in parse_receiver_pack_pkcs7)
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	if (msg_pack_cmd != cmd) {
		BLE_PRINTK("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n", __func__, __LINE__,
			   cmd, msg_pack_cmd);
		return PKCS7_PACK_ERR;
	}

	if (msg_pack_id != msg_id) {
		BLE_PRINTK("[%s-%d]error, curMsgId is %d, but parseMsgId is %d ! \n", __func__, __LINE__, msg_id, msg_pack_id);
		return PKCS7_PACK_ERR;
	}
	memcpy(origin_data + msg_pack_offset, req + 4, req_len - 4);
	msg_pack_offset += req_len - 4;
	if (idx != total - 1) {
		return PKCS7_PACK_MORE;
	}
	BLE_PRINTK("origin_data is %s \n", origin_data);
	return PKCS7_PACK_DONE;
}

int send_dmic_msg(struct ble_context *ctx)
{
	uint8_t buf[203] = {0};
	int ret;

	buf[0] = 0xf1;
	do {
		buf[1] = dmic_seq;
		if (get_dmic_num_messages() == 0) {
			return 0;
		}
		ret = dequeue_dmic(&buf[2]);
		if (ret) {
			return ret;
		}
		ret = ctx->write(buf, 0xca);
		if (ret < 0) {
			if (get_dashboard_state()->f_0d5 == 6) {
				if (send_fail_count_06 < 100) {
					send_fail_count_06++;
				}
				send_fail_count = 0;
			} else {
				send_fail_count++;
				send_fail_count_06 = 0;
			}
			if (send_fail_count >= 10) {
				G1_LOG_ERR("BLE send failed for %d times\n", send_fail_count);
				send_fail_count = 0;
				FUN_0007ff66(get_dashboard_state(), 1);
				return ret;
			}
		} else if (send_fail_count > 0) {
			send_fail_count--;
		}
		if (++dmic_pkt_count >= 10) {
			dmic_pkt_count = 0;
			int64_t now = k_uptime_ticks();

			dmic_send_count++;
			G1_LOG_ERR("time %d dmic_send_count %d send_fail_count %d\n",
				   (uint32_t)k_ticks_to_ms_ceil64(now), dmic_send_count * 10,
				   get_dashboard_state()->f_0d5 == 6 ? send_fail_count_06
								    : send_fail_count);
		}
		dmic_seq++;
	} while (dmic_seq & 3);
	return 0;
}

void DashboardLockTimerExpiry_callback(struct k_timer *timer)
{
	G1_LOG_INF("dashboard lock timeout,release .\n");
	atomic_clear_bit(&DAT_20007f50, DASHBOARD_LOCK_BIT);
	atomic_clear_bit(&DAT_20007f4c, DASHBOARD_LOCK_BIT);
	atomic_clear_bit(&DAT_20008480, DASHBOARD_LOCK_BIT);
}

void ble_process_get_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	struct GlassesState *globle = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	uint8_t resp[21] = {0};
	uint8_t rx[0x11c];

	memcpy(ctx->tx_buf, hdr, sizeof(*hdr));
	ctx->tx_len = hdr->len;
	resp[0] = hdr->cmd;

	switch (hdr->cmd) {
	case BLE_CMD_NOTIFI_WHITELIST_GET:
		get_whitelist_app_from_device(ctx, resp);
		return;
	case BLE_CMD_BRIGHTNESS_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x65;
		resp[2] = rx[0];
		resp[3] = rx[1];
		G1_LOG_INF("BLE_REQ_GET_BRIGHTNESS: 0x%02x,0x%02x,0x%02x,0x%02x,\n", resp[0], resp[1],
			   resp[2], resp[3]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_DEVICE_INFO_GET:
		if (data[1] == 1) {
			globle->phone_is_ios = 0;
		} else if (data[1] == 2) {
			globle->phone_is_ios = 1;
		}
		G1_LOG_INF("%s mobile phone is connected,raw_data[1] = %d\n",
			   globle->phone_is_ios ? "IOS" : "Android", data[1]);
		spim_transfer(ctx, rx, 0x18);
		resp[1] = 0x66;
		resp[2] = rx[0];
		resp[3] = rx[1];
		resp[4] = rx[2];
		resp[5] = rx[3];
		resp[6] = rx[4];
		resp[7] = rx[5];
		resp[8] = rx[6];
		resp[9] = rx[7];
		resp[10] = rx[8];
		resp[11] = rx[9];
		resp[12] = rx[10];
		resp[13] = rx[11];
		resp[14] = rx[12];
		resp[15] = rx[13];
		resp[16] = rx[14];
		resp[17] = rx[15];
		resp[18] = rx[16];
		G1_LOG_INF("BLE_REQ_GET_DEVICE_INFO: CHG:0x%02x,0x%02x,0x%02x,0x%02x,0x%02x "
			   "M_SW_VER:v%d.%d.%d S_SW_VER:v%d.%d.%d BLE_SW_VER:v%d.%d\n",
			   rx[0], rx[1], rx[2], rx[3], rx[4], rx[5], rx[6], rx[7], rx[8], rx[9],
			   rx[10], rx[15], rx[16]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_MAC_GET:
		spim_transfer(ctx, rx, 12);
		resp[1] = 0x67;
		dump_hex("get_mn_mac", rx, 12);
		memcpy(&resp[2], &rx[0], 6);
		memcpy(&resp[8], &rx[6], 6);
		G1_LOG_INF("BLE_REQ_GET_M_N_S_MAC: 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, "
			   "0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
			   resp[0], resp[1], resp[2], resp[3], resp[4], resp[5], resp[6], resp[7],
			   resp[8], resp[9], resp[10], resp[11]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_SILENT_MODE_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x69;
		resp[2] = rx[0];
		resp[3] = rx[1];
		G1_LOG_INF("BLE_REQ_GET_DISPLAY_MODE: 0x%02x,0x%02x,\n", resp[0], resp[1]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_ANTI_SHAKE_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x68;
		resp[2] = rx[0];
		G1_LOG_INF("BLE_REQ_GET_ANTI_SHAKE_ENABLE: 0x%02x,0x%02x,\n", resp[0], resp[1]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_HEAD_UP_ANGLE_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x6d;
		resp[2] = rx[0];
		resp[3] = rx[1];
		G1_LOG_INF("BLE_REQ_GET_WAKEUP_ANGLE: 0x%02x,0x%02x,0x%02x,0x%02x,\n", rx[0], rx[1],
			   rx[2], rx[3]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_DEVICE_SN_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x34;
		memcpy(&resp[2], rx, 16);
		G1_LOG_INF("BLE_REQ_GET_DEVICE_SN: %s\n", rx);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_GLASSES_SN_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x33;
		memcpy(&resp[2], rx, 16);
		G1_LOG_INF("BLE_REQ_GET_GLASSES_SN: %s\n", rx);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_ESB_CHANNEL_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = rx[0];
		G1_LOG_INF("BLE_REQ_GET_ESB_CHANNEL: %d\n", resp[2]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_TIME_SINCE_BOOT_GET:
		spim_transfer(ctx, rx, 1);
		resp[1] = 0x37;
		memcpy(&resp[2], rx, 5);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_ANCS_ENABLE_GET:
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = globle->bonded;
		G1_LOG_ERR("globle->enable_ancs %d\n", resp[2]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_NOTIF_COUNT_GET:
		get_notification_counts_cmd_process(ctx, rx, resp);
		return;
	case BLE_CMD_WEAR_DETECTION_GET:
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = globle->check_mode;
		G1_LOG_ERR("globle->check_mode %d\n", resp[2]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_RUNNING_APP_GET:
		if (*(uint16_t *)&data[1] != hdr->len) {
			G1_LOG_ERR("get device  information packet length error,input data length = "
				   "%d,packet data length = %d\n",
				   hdr->len, *(uint16_t *)&data[1]);
			memset(&resp[6], 0, 15);
			memcpy(resp, data, 5);
			resp[5] = 0xff;
		} else {
			memset(&resp[5], 0, 16);
			memcpy(resp, data, 5);
			if (is_idle()) {
				resp[5] = 0;
				G1_LOG_INF("return system status to app,current running app is "
					   "E_ID_SCREEN_IDLE\n");
			} else {
				resp[5] = 0;
				resp[5] = globle->f_0d5 ? globle->f_0d5 : 0;
				G1_LOG_INF("return system status to app,current running app is %d\n",
					   globle->f_0d5);
			}
		}
		ctx->write(resp, 6);
		return;
	case BLE_CMD_RASTER_CONFIG_GET:
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = globle->raster_height_gear;
		resp[3] = globle->canvas_distance_gear;
		G1_LOG_INF("BLE_GET_RASTER_CONFIG:raster_height_gear:%d,canvas_distance_gear:%d\n",
			   resp[2], resp[3]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_NOTIF_AUTO_DISPLAY_GET:
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = globle->message_mode;
		resp[3] = globle->message_stay_time;
		G1_LOG_ERR("globle->message_mode %d globle->message_stay_time %d\n", resp[2],
			   resp[3]);
		ctx->write(resp, 20);
		return;
	case BLE_CMD_LANGUAGE_SET: {
		uint16_t data_len = *(uint16_t *)&data[1];
		uint8_t lang;
		uint8_t master;

		uint16_t pkt_len = hdr->len;

		if (data_len != pkt_len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = "
				   "%d\n",
				   pkt_len, data_len);
			return;
		}
		lang = data[5];
		memset(resp, 0, sizeof(resp));
		memcpy(resp, data, data_len);
		master = is_master();
		CURRENT_LANGUAGE = lang;
		if (master == 1) {
			SendSystemLanguageInfoToSlave(lang);
		}
		ctx->write(resp, data_len);
		return;
	}
	case BLE_CMD_BURIAL_POINT_GET: {
		const int buf_len = sizeof(globle->burial_point_ctx) + 2;

		G1_LOG_ERR("BLE_GET_BURIAL_POINT_DATA\n\n");
		uint8_t buf[buf_len];
		{
			memcpy(rx, get_dashboard_state()->burial_point_ctx,
			       sizeof(globle->burial_point_ctx));
			buf[0] = hdr->cmd;
			buf[1] = PKCS7_PACK_DONE;
			memcpy(&buf[2], rx, sizeof(globle->burial_point_ctx));
			ctx->write(buf, buf_len);
		}
		return;
	}
	case BLE_CMD_HARDWARE_GET:
		resp[1] = data[1];
		resp[2] = PKCS7_PACK_DONE;
		switch (data[1]) {
		case HW_SUB_DOUBLE_TAP_ACTION:
			resp[3] = globle->f_1244;
			break;
		case HW_SUB_LUM_COEFFICIENT:
			resp[3] = globle->f_ee0;
			break;
		case HW_SUB_LONG_PRESS_ENABLE:
			resp[3] = globle->f_1246;
			break;
		case HW_SUB_MIC_ON_HEAD_UP:
			resp[3] = globle->f_1247;
			break;
		default:
			resp[2] = PKCS7_PACK_ERR;
			break;
		}
		ctx->write(resp, 20);
		return;
	default:
		G1_LOG_WRN("#tx error get req_type: %d\n", hdr->cmd);
		resp[1] = PKCS7_PACK_ERR;
		resp[2] = 20u;
		strcpy((char *)&resp[2], "error get req.");
		ctx->write(resp, 20u);
		return;
	}
}

/*
 * ===== ble_process_put_req (0x1a9b4) =====
 * BLE "PUT" requests from the phone: dashboard (time, schedule, stocks,
 * news, citywalk), countdown, teleprompter, navigation, translate,
 * microphone, quick notes / audio, file transfer, onboarding, settings.
 */

/* dashboard packet header (cmd 6 and most multi-packet commands) */
struct put_pkt_hdr {
	uint8_t cmd;       /* 0 */
	uint16_t len;      /* 1 */
	uint8_t sync_id;   /* 3 */
	uint8_t sub;       /* 4 */
	uint16_t total;    /* 5 */
	uint16_t idx;      /* 7 (1-based) */
} __packed;

/* response helpers: copy the first n bytes of the request, set the status */
#define PUT_RSP(n, status)                                                     \
	do {                                                                   \
		memset(resp, 0, sizeof(resp));                                 \
		memcpy(resp, data, n);                                         \
		resp[n] = (status);                                            \
	} while (0)

/* same without clearing the rest of resp first */
#define PUT_RSP_NC(n, status)                                                  \
	do {                                                                   \
		memcpy(resp, data, n);                                         \
		resp[n] = (status);                                            \
	} while (0)

/* quick note list entry (re-read through globle->quicknote on every access) */
#define QN_ITEM(n) (globle->quicknote->items[n])

#define POST_TO_HOST(n)                                                        \
	do {                                                                   \
		ret = ctx->write(resp, n);                                     \
		if (ret < 0) {                                                 \
			G1_LOG_ERR("post_to_host failed ret = %d\n", ret);     \
		}                                                              \
	} while (0)

/* little endian helpers (open coded, the target has no out-of-line copies) */
#define GET_LE32(p)                                                            \
	((uint32_t)(p)[0] | ((uint32_t)(p)[1] << 8) | ((uint32_t)(p)[2] << 16) |    \
	 ((uint32_t)(p)[3] << 24))
#define GET_LE64(p)                                                            \
	((uint64_t)(p)[0] | ((uint64_t)(p)[1] << 8) | ((uint64_t)(p)[2] << 16) |    \
	 ((uint64_t)(p)[3] << 24) | ((uint64_t)(p)[4] << 32) |                       \
	 ((uint64_t)(p)[5] << 40) | ((uint64_t)(p)[6] << 48) | ((uint64_t)(p)[7] << 56))

static void FUN_0007f41e(uint8_t a, uint8_t b);

void ble_process_put_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	struct GlassesState *globle = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	uint8_t *tx = ctx->tx_buf;
	uint8_t *msg;
	uint8_t resp[20] = {0};
	uint8_t rx[0x100];
	int ret;
	uint32_t data_len;
	uint32_t total, idx;
	uint8_t i, num, sub;

	memcpy(tx, hdr, sizeof(*hdr));
	msg = tx + sizeof(*hdr);
	ctx->tx_len = hdr->len + 4;
	resp[0] = hdr->cmd;

	switch (hdr->cmd) {
	case BLE_CMD_BRIGHTNESS_SET:
	case BLE_CMD_ANTI_SHAKE_SET:
	case BLE_CMD_SILENT_MODE_SET:
	case BLE_CMD_DEBUG_CONTROL:
	case BLE_CMD_HEAD_UP_ANGLE_SET:
	case BLE_CMD_NOTIFY_EN:
		memcpy(msg, &data[1], hdr->len - 1);
		G1_LOG_INF("msg_data:%02x, %02x, %02x, %02x\n", msg[0], msg[1], msg[2], msg[3]);
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_HEAD_UP_CALIBRATION:
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == *(uint16_t *)&data[1] && data[4] <= 2) {
			switch (data[4]) {
			case 1:
				if (get_dashboard_state()->user_horiz_pitch != 0) {
					G1_LOG_WRN("ble clear user horiz pitch\n");
					get_dashboard_state()->user_horiz_pitch = 0;
					get_dashboard_state()->dashboard_cmd = 0;
					k_sem_give(&get_dashboard_state()->dashboard_position_sem);
				}
				break;
			case 2:
				if (data[5] == 1) {
					get_dashboard_state()->horiz_pitch_cfg[0] = 1;
					get_dashboard_state()->horiz_pitch_cfg[1] = data[6];
					if (get_dashboard_state()->horiz_pitch_cfg[1] == 1) {
						G1_LOG_WRN("ble set user horiz pitch:%d\n", DAT_2000848c);
						{
							struct GlassesState *gs = get_dashboard_state();

							gs->user_horiz_pitch = DAT_2000848c;
						}
						get_dashboard_state()->dashboard_cmd = 0;
						k_sem_give(&get_dashboard_state()->dashboard_position_sem);
					}
					globle->f_0cd = data[3];
					update_persist_task_status(get_dashboard_state(), 0x11, 2);
				} else {
					get_dashboard_state()->horiz_pitch_cfg[0] = 0;
				}
				break;
			}
			resp[5] = PKCS7_PACK_DONE;
		} else {
			resp[5] = PKCS7_PACK_ERR;
		}
		ctx->write(resp, 20);
		break;
	case BLE_CMD_NOTIFI_WHITELIST_SET:
		put_whitelist_app_from_app(ctx, msg, data, (uint8_t)hdr->len, resp);
		break;
	case BLE_CMD_HEAD_UP_ACTION_SET:
		data_len = *(uint16_t *)&data[1];
		if (data_len != hdr->len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = "
				   "%d\n",
				   hdr->len, data_len);
			break;
		}
		sub = data[4];
		G1_LOG_INF("received dashboard details packet\n");
		switch (sub) {
		case 4:
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, data_len);
			resp[5] = FUN_000260dc();
			ctx->write(resp, data_len);
			break;
		case 3:
			if (data[5] > 2) {
				G1_LOG_ERR("dashboard details packet error,invalid data\n");
				break;
			}
			if (is_master() == 1) {
				SendDashBoardStartupModeInfoToSlave(data[5]);
			}
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, data_len);
			ctx->write(resp, data_len);
			break;
		}
		break;
	case BLE_CMD_COUNTDOWN_TIMER:
		G1_LOG_INF("#BLE_REQ_PUT_COUNTDOWN_TIMER:\n");
		*(uint32_t *)&msg[0] = *(uint32_t *)&data[1];
		msg[4] = data[5];
		((struct ble_req_hdr *)tx)->len = 5;
		ctx->tx_len = 9;
		G1_LOG_INF("countdown expect_ts:%d, enable:%d\n", *(uint32_t *)&msg[0], msg[4]);
		G1_LOG_INF("msg_data: %02x,%02x,%02x,%02x,%02x\n", msg[0], msg[1], msg[2], msg[3],
			   msg[4]);
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_DASHBOARD_SET: {
		struct put_pkt_hdr *ph = (struct put_pkt_hdr *)data;

		data_len = ph->len;
		if (data_len != hdr->len) {
			G1_LOG_ERR("dashboard information packet length error,input data length = "
				   "%d,packet data length = %d\n",
				   hdr->len, data_len);
			PUT_RSP(5, 1);
			ctx->write(resp, 20);
			return;
		}
		G1_LOG_INF("received sync id = %d\n", data[3]);
		switch (data[4]) {
		case DASHBOARD_SUB_TIME_WEATHER: {
			int64_t ms_ts = ((struct put_time_sync *)data)->ms_ts;
			uint32_t sec_ts;
			struct bp_date date;

			FUN_0004d4dc(ms_ts);
			sec_ts = ((struct put_time_sync *)data)->sec_ts;
			G1_LOG_INF("origin ms timestamp = %lld,origin second timestamp = %d\n", ms_ts,
				   sec_ts);
			globle->dashboard_ts->f_04 = data[0x11];
			globle->dashboard_ts->f_05 = data[0x12];
			globle->dashboard_ts->ts = sec_ts;
			globle->dashboard_ts->ms_ts = ms_ts;
			memset(&date, 0, sizeof(date));
			init_burial_point_date(sec_ts, &date);
			G1_LOG_INF("date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n", sec_ts, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			FUN_0004d494((uint32_t *)(void *)globle->dashboard_ts, 0, 1);
			globle->dashboard_ts->f_5d = data[0x13];
			globle->dashboard_ts->time_fmt = data[0x14];
			if (data_len > 0x15 && globle->dashboard_ts->f_5f != data[0x15]) {
				globle->dashboard_ts->f_5f = data[0x15];
				FUN_00025b28(0, 0);
			}
			G1_LOG_INF("time display format :%s hours, temperature display format %s \n",
				   globle->dashboard_ts->time_fmt ? "12" : "24",
				   globle->dashboard_ts->time_fmt ? "Fahrenheit" : "centigrade degree");
			FUN_0001666c();
			set_ncs_mem_initialized();
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 5);
			ctx->write(resp, 6);
			break;
		}
		case DASHBOARD_SUB_WEATHER:
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 5);
			ctx->write(resp, 6);
			break;
		case DASHBOARD_SUB_PANE_MODE:
			globle->dashboard_ts->disp_mode = data[5];
			globle->dashboard_ts->area = data[6];
			if (globle->dashboard_ts->area == 4 &&
			    globle->dashboard_ts->disp_mode != DAT_2001111f) {
				DAT_2001111f = globle->dashboard_ts->disp_mode;
				get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
				citywalk_reload = 1;
				DAT_2001111e = 0;
			}
			G1_LOG_INF("Dashboard display mode :%d custom display Area value : %d\n",
				   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
			FUN_0001666c();
			set_ncs_mem_initialized();
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 5);
			ctx->write(resp, 6);
			break;
		case DASHBOARD_SUB_PANE_CALENDAR: /* schedule */
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (total == 1) {
				const uint8_t *p;

				get_dashboard_state()->dashboard_ts->disp_mode = data[9];
				get_dashboard_state()->dashboard_ts->area = data[10];
				get_dashboard_state()->dashboard_ts->sched_mode = data[0xb];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("schedule display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->sched_mode);
				if (get_dashboard_state()->dashboard_ts->sched_mode == 3) {
					struct schedule_item *item;

					num = data[0xc];
					G1_LOG_INF("schedule total record num = %d\n", num);
					p = &data[0xd];
					if (num > 8) {
sched_oversize:
						G1_LOG_ERR("schedule data oversize!!!!\n");
						break;
					}
					memset(DAT_2001252f, 0, sizeof(DAT_2001252f));
					item = DAT_2001252f;
					for (i = 0; i != num; i++, item++) {
						if (p[0] == 1) {
								if (p[1] > 0x40) {
									G1_LOG_WRN("schedule title data format error!!!\n");
								}
								memset(item, 0, sizeof(*item));
								memcpy(item->title, &p[2], MIN(p[1], 0x40));
								p += p[1] + 2;
						} else {
							G1_LOG_ERR("schedule title data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
								if (p[1] > 0x20) {
									G1_LOG_WRN("schedule time data format error!!!\n");
								}
								memcpy(item->time, &p[2], MIN(p[1], 0x20));
								p += p[1] + 2;
						} else {
							G1_LOG_ERR("schedule time data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 3) {
							if (p[1] > 0x40) {
								G1_LOG_WRN("schedule location data format error!!!\n");
							}
							item->valid = 1;
							memcpy(item->location, &p[2], MIN(p[1], 0x40));
							p += p[1] + 2;
							G1_LOG_INF("schedule title : %s , time :%s , location : %s \n",
								   item->title, item->time, item->location);
						} else {
							G1_LOG_ERR("schedule time data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
					}
					if (get_dashboard_state()->dashboard_ts->sched_num != i) {
						cleanCalenadrIndex();
					}
					get_dashboard_state()->dashboard_ts->sched_num = i;
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
					return;
				}
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
				return;
			} else if (idx == 1) {
				G1_LOG_INF("Action ID = 1,Received schedule multiple initialization "
					   "packets, currently the first packet of data\n");
				sched_cnt = 0;
				sched_total = 0;
				sched_len = 0;
				memset(sched_buf, 0, sizeof(sched_buf));
				memcpy(sched_buf, &data[9], data_len - 9);
				sched_len += data_len - 9;
				sched_cnt++;
				sched_total = total;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
				return;
			} else if (idx < total) {
				if (sched_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order = "
						   "%d, expected packet order =%d\n",
						   idx, sched_cnt + 1);
					sched_total = 0;
					sched_cnt = 0;
					memset(sched_buf, 0, sizeof(sched_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&sched_buf[sched_len], &data[9], data_len - 9);
				sched_len += data_len - 9;
				sched_cnt++;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
				return;
			} else if (idx == total) {
				const uint8_t *p;

				if (sched_cnt != idx - 1 || sched_total != idx) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, sched_cnt + 1);
					sched_total = 0;
					sched_cnt = 0;
					memset(sched_buf, 0, sizeof(sched_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&sched_buf[sched_len], &data[9], data_len - 9);
				sched_len += data_len - 9;
				sched_cnt++;
				get_dashboard_state()->dashboard_ts->disp_mode = sched_buf[0];
				get_dashboard_state()->dashboard_ts->area = sched_buf[1];
				get_dashboard_state()->dashboard_ts->sched_mode = sched_buf[2];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("schedule display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->sched_mode);
				if (get_dashboard_state()->dashboard_ts->sched_mode == 3) {
					struct schedule_item *item;

					num = *(volatile uint8_t *)&sched_buf[3];
					G1_LOG_INF("schedule record num = %d\n", num);
					if (num > 8) {
						goto sched_oversize;
					}
					memset(DAT_2001252f, 0, sizeof(DAT_2001252f));
					p = &sched_buf[4];
					char *loc = DAT_2001252f[0].location;
					for (i = 0; i != num; i++, loc += sizeof(*item)) {

						if (p[0] == 1) {
								if (p[1] > 0x41) {
									G1_LOG_WRN("schedule title data format error!!!\n");
								}
								item = (struct schedule_item *)(loc - offsetof(struct schedule_item, location));
								memset(item, 0, sizeof(*item));
								memcpy(item->title, &p[2], MIN(p[1], 0x41));
								p += p[1] + 2;
						} else {
							G1_LOG_ERR("schedule title data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
								if (p[1] > 0x21) {
									G1_LOG_WRN("schedule time data format error!!!\n");
								}
								memcpy(item->time, &p[2], MIN(p[1], 0x21));
								p += p[1] + 2;
						} else {
							G1_LOG_ERR("schedule time data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 3) {
							if (p[1] > 0x41) {
								G1_LOG_WRN("schedule time data format error!!!\n");
							}
							item->valid = 1;
							memcpy(item->location, &p[2], MIN(p[1], 0x41));
							p += p[1] + 2;
							G1_LOG_INF("schedule title : %s , time :%s , location : %s , "
								   "schedule_validity :%d\n",
								   item->title, item->time, item->location, 1);
						} else {
							G1_LOG_ERR("schedule time data struct error, error type = %d\n", p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
					}
					if (get_dashboard_state()->dashboard_ts->sched_num != i) {
						cleanCalenadrIndex();
					}
					get_dashboard_state()->dashboard_ts->sched_num = i;
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
					return;
				}
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
				return;
			} else {
				return;
			}
		case DASHBOARD_SUB_PANE_STOCK: /* stocks */
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (total == 1) {
				get_dashboard_state()->dashboard_ts->disp_mode = data[9];
				get_dashboard_state()->dashboard_ts->area = data[10];
				get_dashboard_state()->dashboard_ts->stocks_mode = data[0xb];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("stocks display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->stocks_mode);
				if (get_dashboard_state()->dashboard_ts->stocks_mode == 2) {
					num = data[0xc];
					if (num >= 5) {
						G1_LOG_ERR("stocks data oversize!!!!\n");
						PUT_RSP(9, 1);
						POST_TO_HOST(10);
						break;
					}
					G1_LOG_INF("current stocks index num = %d\n", num);
					if (data[0xd] == 2) {
						G1_LOG_INF("delete stocks index num = %d\n", num);
						memset(&DAT_2000e104[num - 1], 0, sizeof(DAT_2000e104[0]));
						cleanStocksIndex();
					} else {
						struct stock_item *st;
						const uint8_t *p;
						uint16_t img_len;

						if (data[0xe] == 1) {
							if (data[0xf] > 0x20) {
								G1_LOG_WRN("stocks code oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							st = &DAT_2000e104[num - 1];
							if (memcmp(st->code, &data[0x10], MIN(data[0xf], 0x20))) {
								memset(st->code, 0, sizeof(st->code));
								cleanStocksIndex();
							}
							memcpy(st->code, &data[0x10], MIN(data[0xf], 0x20));
							G1_LOG_INF("stock code name : %s\n", st->code);
							p = &data[data[0xf] + 0x10];
						} else {
							G1_LOG_ERR("stock code data struct error, error type = "
								   "%d\n",
								   data[0xe]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
							if (p[1] > 0x40) {
								G1_LOG_WRN("stocks share price oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							if (memcmp(st->company, &p[2], MIN(p[1], 0x40))) {
								memset(st->company, 0, sizeof(st->company));
								cleanStocksIndex();
							}
							memcpy(st->company, &p[2], MIN(p[1], 0x40));
							p += p[1] + 2;
							G1_LOG_INF("stock company name : %s\n", st->company);
						} else {
							G1_LOG_ERR("stocks company name data struct error, "
								   "error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 3) {
							if (p[1] > 0x10) {
								G1_LOG_WRN("stocks share price oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							memset(st->price, 0, sizeof(st->price));
							memcpy(st->price, &p[2], MIN(p[1], 0x10));
							p += p[1] + 2;
							G1_LOG_INF("stock price  : %s\n", st->price);
						} else {
							G1_LOG_ERR("stocks share price data struct error, error "
								   "type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 4) {
							if (p[1] > 0x10) {
								G1_LOG_WRN("stocks price change oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							memset(st->price_change, 0, sizeof(st->price_change));
							memcpy(st->price_change, &p[2], MIN(p[1], 0x10));
							p += p[1] + 2;
							G1_LOG_INF("stock price change  : %s\n", st->price_change);
						} else {
							G1_LOG_ERR("stocks price change data struct error, error "
								   "type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 5) {
							if (p[1] > 0x10) {
								G1_LOG_WRN("stocks price change oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							memset(st->change_rate, 0, sizeof(st->change_rate));
							memcpy(st->change_rate, &p[2], MIN(p[1], 0x10));
							p += p[1] + 2;
							G1_LOG_INF("stock change rate : %s\n", st->change_rate);
						} else {
							G1_LOG_ERR("stocks change rate data struct error, error "
								   "type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 6) {
							if (p[1] != 1) {
								G1_LOG_ERR("stocks change status sformat error !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
								return;
							}
							st->change_status = p[2];
							p += p[1] + 2;
							G1_LOG_INF("stock change status : %d\n", st->change_status);
						} else {
							G1_LOG_ERR("stocks change rate data struct error, error "
								   "type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 7) {
							img_len = *(uint16_t *)&p[1];
							if (img_len > sizeof(st->image)) {
								G1_LOG_ERR("stocks image format oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
								return;
							}
							st->image_len = img_len;
							memset(st->image, 0, sizeof(st->image));
							memcpy(st->image, &p[3], img_len);
							st->valid = 1;
							G1_LOG_INF("We received %d byte of data from the "
								   "App\n",
								   st->image_len);
						} else {
							G1_LOG_ERR("stocks change rate data struct error, error "
								   "type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
					}
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				} else {
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				}
			} else if (idx == 1) {
				G1_LOG_INF("Action ID = 1,Received schedule multiple initialization "
					   "packets, currently the first packet of data\n");
				stock_cnt = 0;
				stock_total = 0;
				stock_len = 0;
				memset(stock_buf, 0, sizeof(stock_buf));
				memcpy(stock_buf, &data[9], data_len - 9);
				stock_len += data_len - 9;
				stock_cnt++;
				stock_total = total;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (stock_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, sched_cnt + 1);
					stock_total = 0;
					stock_cnt = 0;
					memset(stock_buf, 0, sizeof(stock_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&stock_buf[stock_len], &data[9], data_len - 9);
				stock_len += data_len - 9;
				stock_cnt++;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
			} else if (idx == total) {
				if (stock_cnt != idx - 1 || stock_total != idx) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, stock_cnt + 1);
					stock_total = 0;
					stock_cnt = 0;
					memset(stock_buf, 0, sizeof(stock_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&stock_buf[stock_len], &data[9], data_len - 9);
				stock_len += data_len - 9;
				stock_cnt++;
				get_dashboard_state()->dashboard_ts->disp_mode = stock_buf[0];
				get_dashboard_state()->dashboard_ts->area = stock_buf[1];
				get_dashboard_state()->dashboard_ts->stocks_mode = stock_buf[2];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("stocks display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->stocks_mode);
				if (get_dashboard_state()->dashboard_ts->stocks_mode == 2) {
					num = *(volatile uint8_t *)&stock_buf[3];
					if (num >= 5) {
						G1_LOG_ERR("stocks data oversize!!!!\n");
						PUT_RSP(9, 1);
						POST_TO_HOST(10);
						return;
					}
					G1_LOG_INF("current stocks index num = %d\n", num);
					if (stock_buf[4] == 2) {
						G1_LOG_INF("delete stocks index num = %d\n", num);
						cleanStocksIndex();
						memset(&DAT_2000e104[num - 1], 0, sizeof(DAT_2000e104[0]));
						PUT_RSP(9, 0);
						POST_TO_HOST(10);
					} else {
						const uint8_t *p = &stock_buf[5];
						struct stock_item *st;
						uint8_t n;
						uint16_t img_len;

						if (p[0] == 1) {
							if (p[1] > 0x20) {
								G1_LOG_WRN("stocks code oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							st = &DAT_2000e104[num - 1];
							if (memcmp(st->code, &p[2], MIN(p[1], 0x20))) {
								memset(st->code, 0, sizeof(st->code));
								cleanStocksIndex();
							}
							memcpy(st->code, &p[2], MIN(p[1], 0x20));
							G1_LOG_INF("stock code name : %s\n", st->code);
							p += p[1] + 2;
						} else {
							G1_LOG_ERR("stock code data struct error, error type = "
								   "%d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
							if (p[1] > 0x40) {
								G1_LOG_WRN("stocks share price oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							if (memcmp(st->company, &p[2], MIN(p[1], 0x40))) {
								memset(st->company, 0, sizeof(st->company));
								cleanStocksIndex();
							}
									n = p[1];
									memcpy(st->company, &p[2], MIN(n, 0x40));
									p += n + 2;
									G1_LOG_INF("stock company name : %s\n", st->company);
						} else {
							G1_LOG_ERR("stocks company name data struct error, "
								   "error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
								if (p[0] == 3) {
									if (p[1] > 0x10) {
										G1_LOG_WRN("stocks share price oversize !!!\n");
										PUT_RSP(9, 1);
										POST_TO_HOST(10);
									}
									memset(st->price, 0, sizeof(st->price));
									n = p[1];
									memcpy(st->price, &p[2], MIN(n, 0x10));
									p += n + 2;
									G1_LOG_INF("stock price  : %s\n", st->price);
								} else {
									G1_LOG_ERR("stocks share price data struct error, error "
										   "type = %d\n",
										   p[0]);
									PUT_RSP(9, 1);
									POST_TO_HOST(10);
									return;
								}
								if (p[0] == 4) {
									if (p[1] > 0x10) {
										G1_LOG_WRN("stocks price change oversize !!!\n");
										PUT_RSP(9, 1);
										POST_TO_HOST(10);
									}
									memset(st->price_change, 0, sizeof(st->price_change));
									n = p[1];
									memcpy(st->price_change, &p[2], MIN(n, 0x10));
									p += n + 2;
									G1_LOG_INF("stock price change  : %s\n", st->price_change);
								} else {
									G1_LOG_ERR("stocks price change data struct error, error "
										   "type = %d\n",
										   p[0]);
									PUT_RSP(9, 1);
									POST_TO_HOST(10);
									return;
								}
								if (p[0] == 5) {
									if (p[1] > 0x10) {
										G1_LOG_WRN("stocks price change oversize !!!\n");
										PUT_RSP(9, 1);
										POST_TO_HOST(10);
									}
									memset(st->change_rate, 0, sizeof(st->change_rate));
									n = p[1];
									memcpy(st->change_rate, &p[2], MIN(n, 0x10));
									p += n + 2;
									G1_LOG_INF("stock change rate : %s\n", st->change_rate);
								} else {
									G1_LOG_ERR("stocks change rate data struct error, error "
										   "type = %d\n",
										   p[0]);
									PUT_RSP(9, 1);
									POST_TO_HOST(10);
									return;
								}
								if (p[0] == 6) {
									if (p[1] != 1) {
										G1_LOG_ERR("stocks change status sformat error !!!\n");
										PUT_RSP(9, 1);
										POST_TO_HOST(10);
										return;
									}
									st->change_status = p[2];
									p += p[1] + 2;
									G1_LOG_INF("stock change status : %d\n", st->change_status);
								} else {
									G1_LOG_ERR("stocks change rate data struct error, error "
										   "type = %d\n",
										   p[0]);
									PUT_RSP(9, 1);
									POST_TO_HOST(10);
									return;
								}
								if (p[0] == 7) {
									img_len = *(uint16_t *)&p[1];
									if (img_len > sizeof(st->image)) {
										G1_LOG_ERR("stocks image format oversize !!!\n");
										PUT_RSP(9, 1);
										POST_TO_HOST(10);
										return;
									}
									st->image_len = img_len;
									memset(st->image, 0, sizeof(st->image));
									memcpy(st->image, &p[3], img_len);
									st->valid = 1;
									G1_LOG_INF("We received %d byte of data from the App\n", st->image_len);
									stock_total = 0;
									stock_cnt = 0;
									PUT_RSP(9, 0);
								} else {
									G1_LOG_ERR("stocks change rate data struct error, error "
										   "type = %d\n",
										   p[0]);
									PUT_RSP(9, 1);
									POST_TO_HOST(10);
									return;
								}
								POST_TO_HOST(10);
					}
				} else {
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				}
			}
			break;
		case DASHBOARD_SUB_PANE_NEWS: /* news */
			total = *(uint16_t *)&data[5];
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				get_dashboard_state()->dashboard_ts->disp_mode = data[9];
				get_dashboard_state()->dashboard_ts->area = data[10];
				get_dashboard_state()->dashboard_ts->news_mode = data[0xb];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("news display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->news_mode);
				if (get_dashboard_state()->dashboard_ts->news_mode == 2) {
					num = data[0xc];
					if (num >= 5) {
						G1_LOG_ERR("news index num  oversize!!!!\n");
						PUT_RSP(9, 1);
						POST_TO_HOST(10);
						break;
					}
					G1_LOG_INF("current news index num = %d\n", num);
					if (data[0xd] == 2) {
						G1_LOG_INF("delete news index num = %d\n", num);
						memset(&DAT_20011281[num - 1], 0, sizeof(DAT_20011281[0]));
						cleanNewsIndex();
					} else {
						const uint8_t *p = &data[0xe];
						struct news_item *nw;
						uint16_t txt_len;
						uint8_t n8;

						if (p[0] == 1) {
							if (p[1] > 0x40) {
								G1_LOG_WRN("news source oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							nw = &DAT_20011281[num - 1];
							if (memcmp(nw->source, &p[2], MIN(p[1], 0x40))) {
								memset(nw->source, 0, sizeof(nw->source));
								cleanNewsIndex();
							}
							memcpy(nw->source, &p[2], MIN(p[1], 0x40));
							G1_LOG_INF("news source : %s\n", nw->source);
							p += p[1] + 2;
						} else {
							G1_LOG_ERR("news data struct error, error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
							txt_len = *(uint16_t *)&p[1];
							n8 = p[1];
							if (txt_len > sizeof(nw->text)) {
								G1_LOG_ERR("news txt format oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
								return;
							}
							if (memcmp(nw->text, &p[2], n8)) {
								memset(nw->text, 0, sizeof(nw->text));
								cleanNewsIndex();
							}
							memcpy(nw->text, &p[3], txt_len);
							nw->valid = 1;
							G1_LOG_INF("We received %d byte of data from the News App\n",
								   txt_len);
						} else {
							G1_LOG_ERR("news change rate data struct error, "
								   "error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
					}
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				} else {
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				}
			} else if (idx == 1) {
				G1_LOG_INF("Action ID = 1,Received schedule multiple initialization "
					   "packets, currently the first packet of data\n");
				news_cnt = 0;
				news_total = 0;
				news_len = 0;
				memset(news_buf, 0, sizeof(news_buf));
				memcpy(news_buf, &data[9], data_len - 9);
				news_len += data_len - 9;
				news_cnt++;
				news_total = total;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (news_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, news_cnt + 1);
					news_total = 0;
					news_cnt = 0;
					memset(news_buf, 0, sizeof(news_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&news_buf[news_len], &data[9], data_len - 9);
				news_len += data_len - 9;
				news_cnt++;
				PUT_RSP(9, 0);
				POST_TO_HOST(10);
			} else if (total == idx) {
				if (news_cnt != total - 1 || news_total != total) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, news_cnt + 1);
					news_total = 0;
					news_cnt = 0;
					memset(news_buf, 0, sizeof(news_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy(&news_buf[news_len], &data[9], data_len - 9);
				news_len += data_len - 9;
				news_cnt++;
				get_dashboard_state()->dashboard_ts->disp_mode = news_buf[0];
				get_dashboard_state()->dashboard_ts->area = news_buf[1];
				get_dashboard_state()->dashboard_ts->news_mode = news_buf[2];
				G1_LOG_INF("Dashboard display mode :%d  custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("news display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->news_mode);
				if (get_dashboard_state()->dashboard_ts->news_mode == 2) {
					num = *(volatile uint8_t *)&news_buf[3];
					if (num >= 5) {
						G1_LOG_ERR("stocks data oversize!!!!\n");
						PUT_RSP(9, 1);
						POST_TO_HOST(10);
						return;
					}
					G1_LOG_INF("current news index num = %d\n", num);
					if (news_buf[4] == 2) {
						G1_LOG_INF("delete news index num = %d\n", num);
						memset(&DAT_20011281[num - 1], 0, sizeof(DAT_20011281[0]));
						PUT_RSP(9, 0);
						POST_TO_HOST(10);
					} else {
						const uint8_t *p = &news_buf[5];
						struct news_item *nw;
						uint16_t txt_len;
						uint8_t n8;

						if (p[0] == 1) {
							if (p[1] > 0x40) {
								G1_LOG_WRN("news source oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
							}
							nw = &DAT_20011281[num - 1];
							if (memcmp(nw->source, &p[2], MIN(p[1], 0x40))) {
								memset(nw->source, 0, sizeof(nw->source));
								cleanNewsIndex();
							}
							memcpy(nw->source, &p[2], MIN(p[1], 0x40));
							G1_LOG_INF("stock code name : %s\n", nw->source);
							p += p[1] + 2;
						} else {
							G1_LOG_ERR("news data struct error, error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						if (p[0] == 2) {
							txt_len = *(uint16_t *)&p[1];
							n8 = p[1];
							if (txt_len > sizeof(nw->text)) {
								G1_LOG_ERR("news txt format oversize !!!\n");
								PUT_RSP(9, 1);
								POST_TO_HOST(10);
								return;
							}
							if (memcmp(nw->text, &p[2], n8)) {
								memset(nw->text, 0, sizeof(nw->text));
								cleanNewsIndex();
							}
							memcpy(nw->text, &p[3], txt_len);
							nw->valid = 1;
							G1_LOG_INF("We received %d byte of data from the News App\n",
								   txt_len);
							news_total = 0;
							news_cnt = 0;
							PUT_RSP(9, 0);
						} else {
							G1_LOG_ERR("news change rate data struct error, "
								   "error type = %d\n",
								   p[0]);
							PUT_RSP(9, 1);
							POST_TO_HOST(10);
							return;
						}
						POST_TO_HOST(10);
					}
				} else {
					PUT_RSP(9, 0);
					POST_TO_HOST(10);
				}
			}
			break;
		case DASHBOARD_SUB_PANE_CANVAS: /* citywalk */
			memcpy(resp, data, 9);
			resp[9] = 0;
			total = *(uint16_t *)&data[5];
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				get_dashboard_state()->dashboard_ts->disp_mode = data[9];
				get_dashboard_state()->dashboard_ts->area = data[10];
				get_dashboard_state()->dashboard_ts->citywalk_mode = data[0xb];
				G1_LOG_INF("Dashboard display mode :%d custom display Area value : %d\n",
					   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
				G1_LOG_INF("CityWalk display mode = %d\n",
					   get_dashboard_state()->dashboard_ts->citywalk_mode);
				if (get_dashboard_state()->dashboard_ts->area != 4) {
					return;
				}
				if (get_dashboard_state()->dashboard_ts->citywalk_mode == 2) {
					return;
				}
				if (get_dashboard_state()->dashboard_ts->citywalk_mode == 3) {
					uint8_t *dst;
					uint16_t v;

					v = *(uint16_t *)&data[0xc];
					get_dashboard_state()->dashboard_ts->arrow_x = v;
					if (get_dashboard_state()->dashboard_ts->arrow_x & 1) {
						get_dashboard_state()->dashboard_ts->arrow_x--;
					}
					v = *(uint16_t *)&data[0xe];
					get_dashboard_state()->dashboard_ts->arrow_y = v;
					if (get_dashboard_state()->dashboard_ts->disp_mode == 0) {
						if (get_dashboard_state()->dashboard_ts->arrow_x > 0x108 ||
						    get_dashboard_state()->dashboard_ts->arrow_y > 0x68) {
							G1_LOG_ERR("citywalk arrow offset too long!\n");
							return;
						}
						dst = &DAT_20012a4f[0x13ac];
						memcpy(dst, &data[0x10], data_len - 0x10);
					} else if (get_dashboard_state()->dashboard_ts->disp_mode == 1) {
						if (get_dashboard_state()->dashboard_ts->arrow_x > 0x158 ||
						    get_dashboard_state()->dashboard_ts->arrow_y > 0x68) {
							G1_LOG_ERR("citywalk arrow offset too long!\n");
							return;
						}
						dst = &DAT_20012a4f[0x18fc];
						memcpy(dst, &data[0x10], data_len - 0x10);
					}
					if (get_dashboard_state()->dashboard_ts->disp_mode !=
					    DAT_2001111f) {
						DAT_2001111f =
							get_dashboard_state()->dashboard_ts->disp_mode;
						get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
						citywalk_reload = 1;
						DAT_2001111e = 0;
					} else if (DAT_2001111e == 1) {
						citywalk_reload = 0;
						if (get_dashboard_state()
							    ->dashboard_ts->citywalk_state == 2) {
							memcpy(&DAT_20012a4f[0x197c],
							       DAT_20012a4f, 0x197c);
						} else if (get_dashboard_state()
								   ->dashboard_ts->disp_mode ==
							   0) {
							memcpy(&DAT_20012a4f[0x197c + 0x13ac],
							       &DAT_20012a4f[0x13ac],
							       data_len - 0x10);
						} else if (get_dashboard_state()
								   ->dashboard_ts->disp_mode ==
							   1) {
							memcpy(&DAT_20012a4f[0x197c + 0x18fc],
							       &DAT_20012a4f[0x18fc],
							       data_len - 0x10);
						}
						get_dashboard_state()->dashboard_ts->citywalk_state =
							3;
						DAT_2001111d = 1;
					}
					if (citywalk_reload == 1) {
						get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
					}
				}
			} else if (idx == 1) {
				G1_LOG_INF("Received citywalk multiple packets, currently the first "
					   "packet of data\n");
				if (data[10] != 4) {
					return;
				}
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 1;
				if (data[0xb] == 2) {
					DAT_2001111e = 0;
					get_dashboard_state()->dashboard_ts->citywalk_state = 1;
					memset(DAT_20012a4f, 0, 0x197c);
					memcpy(DAT_20012a4f, &data[9], data_len - 9);
					citywalk_len = data_len - 9;
				}
			} else if (idx < total) {
				if (get_dashboard_state()->dashboard_ts->citywalk_state == 1) {
					DAT_2001111e = 0;
					if (DAT_2000e0f2 != idx - 1) {
						G1_LOG_WRN("There is a packet order error, current packet "
							   "order = %d, expected packet order = %d\n",
							   idx, DAT_2000e0f2 + 1);
						DAT_2000e0f0 = total;
						DAT_2000e0f2 = 0;
						citywalk_len = 0;
						memset(DAT_20012a4f, 0, 0x197c);
						return;
					}
					if (citywalk_len - 9 + data_len > 0x197c) {
						G1_LOG_ERR("citywalk data is too long, the current data "
							   "length %d,wait write data length = %d\n",
							   citywalk_len, data_len - 9);
						return;
					}
					memcpy(&DAT_20012a4f[citywalk_len], &data[9], data_len - 9);
					citywalk_len += data_len - 9;
					G1_LOG_INF("Successfully received the subpackage content, the "
						   "packet sequence is %d\n",
						   idx);
					DAT_2000e0f2++;
				}
			} else if (total == idx) {
				if (get_dashboard_state()->dashboard_ts->citywalk_state == 1) {
					if (DAT_2000e0f2 != total - 1 || DAT_2000e0f0 != total) {
						G1_LOG_WRN("There is a packet order error, current packet "
							   "order = %d, expected packet order = %d\n",
							   idx, DAT_2000e0f2 + 1);
						DAT_2000e0f0 = total;
						DAT_2000e0f2 = 0;
						citywalk_len = 0;
						DAT_2001111e = 0;
						memset(DAT_20012a4f, 0, 0x197c);
						return;
					}
					if (citywalk_len - 9 + data_len > 0x197c) {
						G1_LOG_ERR("citywalk data is too long, the current data "
							   "length %d,wait write data length = %d\n",
							   citywalk_len, data_len - 9);
						DAT_2001111e = 0;
						return;
					}
					G1_LOG_ERR("Successfully assembled multiple packages of data, and "
						   "updated the complete content to the UI thread for "
						   "data update.\n");
					memcpy(&DAT_20012a4f[citywalk_len], &data[9], data_len - 9);
					citywalk_len += data_len - 9;
					get_dashboard_state()->dashboard_ts->disp_mode = DAT_20012a4f[0];
					get_dashboard_state()->dashboard_ts->area = DAT_20012a4f[1];
					if (citywalk_reload == 1) {
						get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
					}
					get_dashboard_state()->dashboard_ts->f_6c = DAT_20012a4f[3];
					DAT_2001111e = 1;
					get_dashboard_state()->dashboard_ts->citywalk_state = 2;
					if ((get_dashboard_state()->dashboard_ts->disp_mode == 0 &&
					     citywalk_len != 0x13ac) ||
					    (get_dashboard_state()->dashboard_ts->disp_mode == 1 &&
					     citywalk_len != 0x18fc)) {
						citywalk_reload = 1;
						DAT_2001111e = 0;
						get_dashboard_state()->dashboard_ts->citywalk_state = 0;
					}
				}
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				citywalk_len = 0;
			}
			ctx->write(resp, 10);
			break;
		}
		break;
	}
	case BLE_CMD_STATUS:
		if (*(uint16_t *)&data[1] != hdr->len) {
			G1_LOG_ERR("dashboard information packet length error,input data length = "
				   "%d,packet data length = %d\n",
				   hdr->len, *(uint16_t *)&data[1]);
			break;
		}
		G1_LOG_INF("received sync id = %d\n", data[3]);
		if (data[4] == 1) {
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 8);
			resp[5] = globle->f_0dd;
			resp[6] = getNotesIndex() + 1;
			resp[7] = globle->dashboard_ts->f_60;
			ctx->write(resp, 8);
		}
		break;
	case BLE_CMD_TELEPROMPTER_INFO: { /* teleprompter */
		struct put_pkt_hdr *ph = (struct put_pkt_hdr *)data;
		struct teleprompter_info *tp;
		volatile struct teleprompter_info *tpv = &tp_buf;

		data_len = ph->len;
		if (data_len != hdr->len) {
			G1_LOG_ERR("teleprompter packet length error,input data length = %d,packet "
				   "data length = %d\n",
				   hdr->len, data_len);
			return;
		}
		sub = data[4];
		switch (sub) {
		case 1:
			G1_LOG_INF("received teleprompter init  packet ....\n");
			memset(msg, 0, sizeof(struct teleprompter_info));
			total = *(uint16_t *)&data[5];
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				int64_t now;

				G1_LOG_INF("received teleprompter init packet,total packet = 1\n");
				tp = (struct teleprompter_info *)msg;
				globle->f_0cd = data[3];
				FUN_0007f4a4(data[3], 0, 0);
				tp->action = 1;
				tp->ready = 1;
				tp->mode = data[10] & 0xf;
				tp->f_0b = data[10] & 0x80;
				tp->f_0c = data[9];
				tp->f_0d = data[0xb];
				tp->mark_pos = 0;
				tp->suspend = 0;
				memcpy(tp->text, &data[0xc], data_len - 0x14);
				tp->len = data_len - 0x14;
				tp->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				FUN_0004d4f8(&now);
				G1_LOG_ERR("*******************------ received app send timestamp = "
					   "%lld,current system timestamp = %lld\n",
					   tp->ts, now);
				((struct ble_req_hdr *)tx)->len = hdr->len;
				ctx->tx_len = hdr->len + 4;
				spim_transfer(ctx, rx, 8);
				PUT_RSP(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else if (idx == 1) {
				G1_LOG_INF("Action ID = 1,Received multiple initialization packets, "
					   "currently the first packet of data\n");
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				tp_len = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				tpv->action = 1;
				tpv->ready = 0;
				tpv->mode = data[10] & 0xf;
				tpv->f_0b = data[10] & ~0x7f;
				tpv->f_0c = data[9];
				tpv->f_0d = data[0xb];
				tpv->mark_pos = 0;
				tpv->ts = 0;
				memcpy((void *)tp_buf.text, &data[0xc], data_len - 0xc);
				tp_len = data_len - 0xc;
				DAT_2000e0f2++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (DAT_2000e0f2 != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy((void *)&tp_buf.text[tp_len], &data[0xc], data_len - 0xc);
				tp_len += data_len - 0xc;
				G1_LOG_INF("ACTION ID = 1,Successfully received the subpackage "
					   "content, the packet sequence is %d\n",
					   idx);
				DAT_2000e0f2++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx == total) {
				int64_t now;

				if (DAT_2000e0f2 != idx - 1 || DAT_2000e0f0 != idx) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				globle->f_0cd = data[3];
				FUN_0007f4a4(data[3], 0, 0);
				memcpy((void *)(tp_buf.text + tp_len), &data[0xc], data_len - 0x14);
				tp_len += data_len - 0x14;
				tpv->len = tp_len;
				tp_buf.ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				FUN_0004d4f8(&now);
				G1_LOG_INF("*******************------ received app send timestamp "
					   "= %lld,current system timestamp = %lld\n",
					   tp_buf.ts, now);
				DAT_2000e0f2++;
				tp_buf.ready = 1;
				memcpy(get_dashboard_state()->teleprompter, (const void *)&tp_buf,
				       sizeof(tp_buf));
				if (tp_buf.ready) {
					update_persist_task_status(globle, 9, 2);
				}
				G1_LOG_INF("ACTION ID = 1,Successfully assembled multiple packages "
					   "of data, and updated the complete content to the UI "
					   "thread for data update.\n");
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_ERR("A serious packet order error occurred!\n");
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				PUT_RSP_NC(9, 1);
				POST_TO_HOST(10);
			}
			break;
		case 2:
			globle->f_0cd = data[3];
			FUN_0007f4a4(data[3], 0, 0);
			ctx->tx_len = ((struct ble_req_hdr *)tx)->len + 4;
			globle->teleprompter->mark_pos = *(uint16_t *)&data[6];
			globle->teleprompter->f_0d = data[5];
			globle->teleprompter->action = 2;
			globle->teleprompter->ts = GET_LE64(&data[data_len - 8]);
			G1_LOG_INF("MARK POSITION = %d\n", globle->teleprompter->mark_pos);
			PUT_RSP(5, 0);
			if (is_master() == 1) {
				send_response_data_to_msgqueue(resp, 6);
			} else {
				POST_TO_HOST(6);
			}
			break;
		case 3:
		case 7:
			G1_LOG_INF("received teleprompter text upgrade packet ....\n");
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (total == 1) {
				int64_t now;

				G1_LOG_INF("received TEXT UPGRADE Single PACKET ...\n");
				globle->f_0cd = data[3];
				FUN_0007f4a4(data[3], 0, 0);
				globle->teleprompter->action = 3;
				globle->teleprompter->ready = 1;
				globle->teleprompter->f_0d = data[9];
				globle->teleprompter->mark_pos = *(uint16_t *)&data[10];
				memset(globle->teleprompter->text, 0, sizeof(globle->teleprompter->text));
				memcpy(globle->teleprompter->text, &data[0xc], data_len - 0x14);
				globle->teleprompter->len = data_len - 0x14;
				globle->teleprompter->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				FUN_0004d4f8(&now);
				G1_LOG_INF("*******************------ received app send timestamp = "
					   "%lld,current system timestamp = %lld\n",
					   globle->teleprompter->ts, now);
				if (sub == 7) {
					DAT_20010f05 = 1;
				}
				((struct ble_req_hdr *)tx)->len = hdr->len;
				ctx->tx_len = hdr->len + 4;
				PUT_RSP(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else if (idx == 1) {
				G1_LOG_INF("ACTION ID = 3,Received multiple initialization packets, "
					   "currently the first packet of data\n");
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				memcpy((void *)&tp_buf, &data[0xc], data_len - 0xc);
				DAT_2000e0f4 = data_len - 0xc;
				DAT_2000e0f2++;
				globle->teleprompter->ts = 0;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (DAT_2000e0f2 != idx - 1) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = 0;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy((uint8_t *)(void *)&tp_buf + DAT_2000e0f4, &data[0xc],
				       data_len - 0xc);
				DAT_2000e0f4 += data_len - 0xc;
				G1_LOG_INF("ACTION ID = 3,Successfully received the subpackage "
					   "content, the packet sequence is %d\n",
					   idx);
				DAT_2000e0f2++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx == total) {
				int64_t now;

				if (DAT_2000e0f2 != idx - 1 || DAT_2000e0f0 != idx) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				globle->f_0cd = data[3];
				FUN_0007f4a4(data[3], 0, 0);
				memcpy((uint8_t *)(void *)&tp_buf + DAT_2000e0f4, &data[0xc],
				       data_len - 0x14);
				DAT_2000e0f4 += data_len - 0x14;
				DAT_2000e0f2++;
				memset(globle->teleprompter->text, 0,
				       sizeof(globle->teleprompter->text));
				memcpy(globle->teleprompter->text, (const void *)&tp_buf, DAT_2000e0f4);
				globle->teleprompter->len = DAT_2000e0f4;
				globle->teleprompter->action = 3;
				globle->teleprompter->f_0d = data[9];
				globle->teleprompter->mark_pos = *(uint16_t *)&data[10];
				G1_LOG_INF("ACTIION ID = 3,Successfully assembled multiple packages "
					   "of data, and updated the complete content to the UI "
					   "thread for data update.\n");
				globle->teleprompter->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				FUN_0004d4f8(&now);
				G1_LOG_INF("*******************------ received app send timestamp "
					   "= %lld,current system timestamp = %lld\n",
					   globle->teleprompter->ts, now);
				if (sub == 7) {
					DAT_20010f05 = 1;
				}
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_ERR("ACTION ID = 3,A serious packet order error occurred!\n");
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				PUT_RSP_NC(9, 1);
				POST_TO_HOST(10);
			}
			break;
		case 5:
			G1_LOG_INF("received teleprompter func exit packet ....\n");
			if (is_master() == 1) {
				globle->f_0cd = data[3];
				FUN_0007f4a4(data[3], 0, 0);
				memset(msg, 0, sizeof(struct teleprompter_info));
				ctx->tx_len = ((struct ble_req_hdr *)tx)->len + 4;
				spim_transfer(ctx, rx, 8);
			}
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 6);
			POST_TO_HOST(6);
			break;
		}
		break;
	}
	case BLE_CMD_TELEPROMPTER_SUSPEND: {
		struct teleprompter_info *tp;

		data_len = *(uint16_t *)&data[1];
		if (data_len != hdr->len) {
			G1_LOG_ERR("teleprompter packet length error,input data length = %d,packet "
				   "data length = %d\n",
				   hdr->len, data_len);
			return;
		}
		if (data[4] != 6) {
			return;
		}
		G1_LOG_INF("received teleprompter suspend packet ....\n");
		globle->f_0cd = data[3];
		FUN_0007f4a4(data[3], 0, 0);
		if (data[5] == 1) {
			globle->teleprompter->suspend = 1;
		} else {
			globle->teleprompter->suspend = 0;
		}
		globle->teleprompter->ts = GET_LE64(&data[data_len - 0xc]);
		globle->teleprompter->counter = GET_LE32(&data[data_len - 4]);
		G1_LOG_INF("SUSPEND status ,app send counter time = %d\n",
			   globle->teleprompter->counter);
		ctx->tx_len = ((struct ble_req_hdr *)tx)->len + 4;
		memset(resp, 0, sizeof(resp));
		memcpy(resp, data, 6);
		if (is_master() == 1) {
			send_response_data_to_msgqueue(resp, 6);
		} else {
			POST_TO_HOST(6);
		}
		break;
	}
	case BLE_CMD_TELEPROMPTER_POSITION_SET:
		if (*(uint16_t *)&data[1] != hdr->len) {
			G1_LOG_ERR("teleprompter packet length error,input data length = %d,packet "
				   "data length = %d\n",
				   hdr->len, *(uint16_t *)&data[1]);
			break;
		}
		if (data[4] == 4) {
			G1_LOG_INF("received app send sync packet ....\n");
			DAT_20007f44++;
			ctx->tx_len = ((struct ble_req_hdr *)tx)->len + 4;
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 6);
			POST_TO_HOST(6);
		}
		break;
	case BLE_CMD_QUICK_NOTE_CONTROL: { /* quick note / audio */
		struct put_pkt_hdr *ph = (struct put_pkt_hdr *)data;

		data_len = ph->len;
		if (data_len != hdr->len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = "
				   "%d\n",
				   hdr->len, data_len);
			break;
		}
		switch (data[4]) {
		case 1:
			if (is_master() == 1 && data_len == 6 && data[5] == 1) {
				requestAudioInfoToApp(0);
			}
			break;
		case 2:
			if (is_master() == 1) {
				if (data_len == 6) {
					G1_LOG_INF("received request voice data commmand\n");
					sendAudioStreamFileToApp(0, data[5]);
				} else if (data_len == 0xb) {
					if (data[10] == 0) {
						G1_LOG_INF("received request voice data next data\n");
					} else if (data[10] == 0xaa) {
						G1_LOG_INF("APP success received audio data ,delete voice "
							   "block num %d\n",
							   data[9]);
						if (is_master() == 1) {
							if ((uint8_t)(data[9] - 1) < 4) {
								delAudioStreamRecord(data[9]);
							} else {
								G1_LOG_WRN("APP delete voice block num "
									   "error %d\n",
									   data[9]);
							}
						}
					} else {
						G1_LOG_ERR("app return error response information\n");
					}
				}
			}
			break;
		case 3:
			total = *(uint16_t *)&data[5];
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				int num = data[9] & 0xf;
				uint8_t flag = data[10];
				int n = num - 1;

				memset(QN_ITEM(n).title.str, 0, sizeof(QN_ITEM(n).title));
				memset(QN_ITEM(n).text, 0, sizeof(QN_ITEM(n).text));
				if (flag == 0) {
					QN_ITEM(n).valid = 0;
					G1_LOG_INF("received empty quick note data ,delete quick note "
						   "num.%d\n",
						   num);
					PUT_RSP_NC(9, 0);
					ctx->write(resp, 10);
					deleteQuickNoteData(n);
				} else {
					uint8_t tl = data[0xb];
					uint16_t xl;

					memcpy(QN_ITEM(n).title.str, &data[0xc],
					       MIN(tl, sizeof(QN_ITEM(n).title)));
					xl = data[tl + 0xc] | (data[tl + 0xd] << 8);
					memcpy(QN_ITEM(n).text, &data[tl + 0xe],
					       MIN(xl, sizeof(QN_ITEM(n).text)));
					G1_LOG_INF("title length = %d,text length = %d\n", tl, xl);
					QN_ITEM(n).valid = 1;
					G1_LOG_INF("Quick Note Title = %s,TXET = %s\n",
						   QN_ITEM(n).title.str, QN_ITEM(n).text);
					upgradeQuickNoteDataToFlash(n);
					PUT_RSP_NC(9, 0);
					ctx->write(resp, 10);
				}
			} else if (idx == 1) {
				memset(qn_text_buf, 0, sizeof(qn_text_buf));
				memset(&qn_title_buf, 0, sizeof(qn_title_buf));
				qn_len = 0;
				qn_cnt = 0;
				qn_total = total;
				qn_num = data[9];
				QN_ITEM(qn_num - 1).valid = 0;
				if (qn_num > 4 || qn_num == 0) {
					G1_LOG_ERR("app send parameter error,qucik note num = %d\n",
						   qn_num);
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
				} else {
					uint8_t tl = data[0xb];
					uint16_t xl;

					memcpy(qn_title_buf.str, &data[0xc], MIN(tl, sizeof(qn_title_buf)));
					xl = data_len - 0xe - tl;
					memcpy(&qn_text_buf[qn_len], &data[tl + 0xe],
					       MIN(xl, sizeof(qn_text_buf)));
					qn_len = xl;
					qn_cnt++;
					PUT_RSP_NC(9, 0);
					ctx->write(resp, 10);
				}
			} else if (idx < total) {
				if (qn_cnt != idx - 1) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					qn_total = 0;
					qn_cnt = 0;
					qn_len = 0;
					memset(qn_text_buf, 0, sizeof(qn_text_buf));
					memset(&qn_title_buf, 0, sizeof(qn_title_buf));
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				memcpy(&qn_text_buf[qn_len], &data[9], data_len - 9);
				qn_len += data_len - 9;
				qn_cnt++;
				PUT_RSP_NC(9, 0);
				ctx->write(resp, 10);
			} else if (idx == total) {
				if (qn_cnt != total - 1 || qn_total != total) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					memset(qn_text_buf, 0, sizeof(qn_text_buf));
					memset(&qn_title_buf, 0, sizeof(qn_title_buf));
					qn_len = 0;
					qn_cnt = 0;
					qn_total = 0;
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				memcpy(&qn_text_buf[qn_len], &data[9], data_len - 9);
				qn_len += data_len - 9;
				memset(&QN_ITEM(qn_num - 1).title, 0, sizeof(QN_ITEM(0).title));
				QN_ITEM(qn_num - 1).title = qn_title_buf;
				memset(QN_ITEM(qn_num - 1).text, 0, sizeof(QN_ITEM(0).text));
				memcpy(QN_ITEM(qn_num - 1).text, qn_text_buf, sizeof(qn_text_buf));
				QN_ITEM(qn_num - 1).valid = 1;
				G1_LOG_INF("Quick Note Title =%s,QuickNote TXET =%s\n",
					   QN_ITEM(qn_num - 1).title.str, QN_ITEM(qn_num - 1).text);
				upgradeQuickNoteDataToFlash(qn_num - 1);
				PUT_RSP_NC(9, 0);
				ctx->write(resp, 10);
				qn_len = 0;
				qn_cnt = 0;
				qn_total = 0;
			}
			break;
		case 4:
			if (data[5] < 5) {
				G1_LOG_INF("delete audio record num = %d\n", data[5] - 1);
				if (is_master() == 1) {
					delAudioStreamRecord(data[5]);
				}
				memcpy(resp, data, 5);
				resp[5] = 0;
				ctx->write(resp, 6);
			} else {
				G1_LOG_INF("received delete all quick note audio file command .\n");
				if (is_master() == 1) {
					delAudioStreamRecord(0xff);
				}
				memcpy(resp, data, 5);
				resp[5] = 0;
				ctx->write(resp, 6);
			}
			break;
		case 5:
			G1_LOG_INF("received clean audio voice command\n");
			if (is_master() == 1) {
				delAudioStreamRecord(0xff);
				memcpy(resp, data, 5);
				resp[5] = 0;
				ctx->write(resp, 6);
			}
			break;
		case 7:
			memcpy(resp, data, 5);
			resp[5] = 0;
			FUN_0003d7b4();
			if (data[5] == 1) {
				globle->qn_show->f_1 = 1;
				globle->qn_show->f_2 = 1;
				globle->qn_show->action = 7;
				memset(globle->qn_show->data, 0, sizeof(globle->qn_show->data));
				update_persist_task_status(globle, 0xc, 2);
				FUN_0007f4a4(data[3], 0, 0);
			} else {
				resp[5] = 1;
			}
			ctx->write(resp, 6);
			break;
		case 8: {
			struct put_pkt_hdr *rh = (struct put_pkt_hdr *)resp;

			FUN_0003d7b4();
			memcpy(resp, data, 9);
			rh->len = 10;
			resp[9] = 0;
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (total == 1) {
				G1_LOG_INF("received quick note packet,total packet = 1\n");
				data_len -= 0xb;
				if (data_len > 0x14a) {
					G1_LOG_ERR("quick note data is too long, the current data length "
						   "0,wait write data length = %d\n",
						   data_len);
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				globle->qn_show->action = 8;
				get_dashboard_state()->qn_show->f_4 = data[9];
				get_dashboard_state()->qn_show->f_5 = data[10];
				if (get_dashboard_state()->qn_show->f_4 == 0) {
					memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
					memset(get_dashboard_state()->qn_show->data, 0,
					       sizeof(get_dashboard_state()->qn_show->data));
					get_dashboard_state()->qn_show->len = data_len;
					memcpy(get_dashboard_state()->qn_show->data, &data[0xb],
					       get_dashboard_state()->qn_show->len);
				} else {
					display_DelayClose(10000);
				}
				FUN_0007f4a4(data[3], 0, 0);
			} else if (idx == 1) {
				G1_LOG_INF("Received quick note multiple packets, currently the first "
					   "packet of data\n");
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 1;
				memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
				memcpy(DAT_20010b99, &data[0xb], data_len - 0xb);
				DAT_2000e0f4 = data_len - 0xb;
			} else if (idx < total) {
				if (DAT_2000e0f2 != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order = %d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				if (DAT_2000e0f4 - 0xb + data_len > 0x14a) {
					G1_LOG_ERR("quick note data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, data_len - 0xb);
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				memcpy(&DAT_20010b99[DAT_2000e0f4], &data[0xb], data_len - 0xb);
				DAT_2000e0f4 += data_len - 0xb;
				G1_LOG_INF("Successfully received the subpackage content, the packet "
					   "sequence is %d\n",
					   idx);
				DAT_2000e0f2++;
			} else if (idx == total) {
				if (DAT_2000e0f2 != idx - 1 || idx != DAT_2000e0f0) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order = %d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				if (DAT_2000e0f4 - 0xb + data_len > 0x14a) {
					G1_LOG_ERR("quick note data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, data_len - 0xb);
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				G1_LOG_INF("Successfully assembled multiple packages of data, and "
					   "updated the complete content to the UI thread for data "
					   "update.\n");
				globle->qn_show->action = 8;
				get_dashboard_state()->qn_show->f_4 = data[9];
				get_dashboard_state()->qn_show->f_5 = data[10];
				if (get_dashboard_state()->qn_show->f_4 == 0) {
					memcpy(&DAT_20010b99[DAT_2000e0f4], &data[0xb], data_len - 0xb);
					DAT_2000e0f4 += data_len - 0xb;
					memset(get_dashboard_state()->qn_show->data, 0,
					       sizeof(get_dashboard_state()->qn_show->data));
					memcpy(get_dashboard_state()->qn_show->data, DAT_20010b99,
					       DAT_2000e0f4);
					get_dashboard_state()->qn_show->len = DAT_2000e0f4;
				} else {
					display_DelayClose(10000);
				}
				FUN_0007f4a4(data[3], 0, 0);
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
			}
			ctx->write(resp, rh->len);
			break;
		}
		case 9:
			FUN_0003d7b4();
			memcpy(resp, data, 5);
			resp[5] = globle->qn_show->f_1 != 1;
			resp[6] = data[5];
			ctx->write(resp, 7);
			break;
		case 10:
			memcpy(resp, data, 5);
			resp[5] = 0;
			if (data[5] <= 2) {
				FUN_0003d7b4();
				if (globle->f_0d5 != 12) {
					globle->qn_show->f_1 = 1;
					globle->qn_show->f_2 = 1;
					memset(get_dashboard_state()->qn_show->data, 0,
					       sizeof(get_dashboard_state()->qn_show->data));
					update_persist_task_status(globle, 0xc, 2);
				}
				globle->qn_show->action = 10;
				globle->qn_show->f_4 = data[5];
				FUN_0007f4a4(data[3], 0, 0);
			} else {
				resp[5] = 1;
			}
			ctx->write(resp, 6);
			break;
		}
		break;
	}
	case BLE_CMD_NAVIGATION_INFO: { /* navigation */
		struct put_pkt_hdr *ph = (struct put_pkt_hdr *)data;
		struct nav_info *nav;

		data_len = ph->len;
		if (data_len != hdr->len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = "
				   "%d\n",
				   hdr->len, data_len);
			return;
		}
		switch (data[4]) {
		case 0:
			G1_LOG_INF("received navigation func startup  packet ....\n");
			nav = get_dashboard_state()->nav;
			globle->f_0cd = data[3];
			memset(nav, 0, sizeof(*nav));
			memset(get_dashboard_state()->nav, 0, sizeof(*nav));
			nav->type = 0;
			nav->running = 1;
			nav->sync_id = data[3];
			DAT_20010dc1 = 0;
			DAT_20010dc0 = 0;
			update_persist_task_status(get_dashboard_state(), 10, 2);
			memset(resp, 0, sizeof(resp)); memcpy(resp, data, 6); resp[5] = 0;
			if (is_master() == 1) {
				send_response_data_to_msgqueue(resp, 6);
			} else {
				POST_TO_HOST(6);
			}
			break;
		case 1: {
			uint32_t n;
			uint32_t pos, end;
			uint32_t left;

			nav = get_dashboard_state()->nav;
			get_dashboard_state()->f_0cd = data[3];
			nav->direction = data[5];
			nav->x = *(uint16_t *)&data[6];
			nav->y = *(uint16_t *)&data[8];
			if (nav->x != nav_last_x || nav->y != nav_last_y) {
				nav_last_x = nav->x;
				nav_last_y = nav->y;
				DAT_20010dbc = 1;
			}
			if (nav->x > 0x1e8 || nav->y > 0x88) {
				G1_LOG_ERR("app send x/y parameter overstep!!! x= %d,y= %d\n", nav->x,
					   nav->y);
			}
			/* time remaining */
			for (n = 0;;) {
				left = data_len - 10;
				if (n >= left) {
time_oversize:
					G1_LOG_ERR("TIME_REMAINNING_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
				if (data[10 + n++] == '\0')
					break;
			}
			if ((int)n > (int)sizeof(nav->time_remaining))
				goto time_oversize;
			memset(nav->time_remaining, 0, sizeof(nav->time_remaining));
			memcpy(nav->time_remaining, &data[10], n);
			pos = 10 + n - 1;
			end = data_len - 1;
			/* remaining kilometers */
			n = 0;
			goto km_oversize_chk;
			for (;;) {
				if (data[pos + 1 + n++] == '\0')
					break;
km_oversize_chk:
				left = end - pos;
				if (n >= left) {
km_oversize:
					G1_LOG_ERR("KILOMETER_REMAINNING_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)n > (int)sizeof(nav->km_remaining))
				goto km_oversize;
			memset(nav->km_remaining, 0, sizeof(nav->km_remaining));
			memcpy(nav->km_remaining, &data[pos + 1], n);
			pos += n;
			/* road name */
			n = 0;
			goto road_oversize_chk;
			for (;;) {
				if (data[pos + 1 + n++] == '\0')
					break;
road_oversize_chk:
				left = end - pos;
				if (n >= left) {
road_oversize:
					G1_LOG_ERR("ROAD_NAME_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)n > (int)sizeof(nav->road_name))
				goto road_oversize;
			memset(nav->road_name, 0, sizeof(nav->road_name));
			memcpy(nav->road_name, &data[pos + 1], n);
			pos += n;
			/* remaining distance */
			for (n = 0;;) {
				left = end - pos;
				if (n >= left) {
dist_oversize:
					G1_LOG_ERR("REMAINING_DISTANCE_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
				if (data[pos + 1 + n++] == '\0')
					break;
			}
			if ((int)n > (int)sizeof(nav->remaining_distance))
				goto dist_oversize;
			memset(nav->remaining_distance, 0, sizeof(nav->remaining_distance));
			memcpy(nav->remaining_distance, &data[pos + 1], n);
			pos += n;
			/* current speed */
			n = 0;
			goto speed_oversize_chk;
			for (;;) {
				if (data[pos + 1 + n++] == '\0')
					break;
speed_oversize_chk:
				left = end - pos;
				if (n >= left) {
speed_oversize:
					G1_LOG_ERR("CURRENT_SPEED_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)n > (int)sizeof(nav->speed))
				goto speed_oversize;
			memset(nav->speed, 0, sizeof(nav->speed));
			memcpy(nav->speed, &data[pos + 1], n);
			G1_LOG_INF("direction = %d,x = %d,y = %d,time_remaining = "
				   "%s,remainning_kilometers = %s,road_name_info = %s,                "
				   "            remaining_distance_info= %s,current speed = %s\n",
				   nav->direction, nav->x, nav->y, nav->time_remaining,
				   nav->km_remaining, nav->road_name, nav->remaining_distance,
				   nav->speed);
			nav->updated = 1;
			nav->type = 1;
			nav->sync_id = data[3];
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 5);
			DAT_20010dbf = 1;
			if (is_master() == 1) {
				send_response_data_to_msgqueue(resp, 6);
			} else {
				POST_TO_HOST(6);
			}
			break;
		}
		case 2: /* overview map */
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (idx == 1) {
				G1_LOG_INF("Received multiple initialization packets, currently the "
					   "first packet of data,total packet = %d\n",
					   total);
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				nav = get_dashboard_state()->nav;
				DAT_20010dc1 = 0;
				lock_k_mutex_20007f54(K_FOREVER);
				memset(DAT_20016b1f, 0, sizeof(DAT_20016b1f));
				memcpy(DAT_20016b1f, &data[9], data_len - 9);
				unlock_k_mutex_20007f54();
				DAT_2000e0f4 = data_len - 9;
				DAT_2000e0f2++;
				if (total == 1) {
					nav->updated = total;
					DAT_20010dbe = total;
					DAT_20010dc1 = total;
					nav->type = 2;
					nav->sync_id = data[3];
					nav->map_size = DAT_2000e0f4;
					G1_LOG_INF("Successfully received navigation data .Maps are "
						   "compressed to only one pack!!!\n");
					DAT_2000e0f0 = 0;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
				}
				PUT_RSP_NC(9, 0);
				ctx->write(resp, 10);
			} else if (idx < total) {
				if (DAT_2000e0f2 != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					lock_k_mutex_20007f54(K_FOREVER);
					memset(DAT_20016b1f, 0, sizeof(DAT_20016b1f));
					unlock_k_mutex_20007f54();
					get_dashboard_state();
					DAT_20010dc1 = 0;
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				if (DAT_2000e0f4 - 9 + data_len >= sizeof(DAT_20016b1f)) {
					G1_LOG_ERR("overview map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, DAT_2000e0f4 - 9 + data_len);
					return;
				}
				get_dashboard_state();
				lock_k_mutex_20007f54(K_FOREVER);
				memcpy(&DAT_20016b1f[DAT_2000e0f4], &data[9], data_len - 9);
				unlock_k_mutex_20007f54();
				DAT_20010dc1 = 0;
				DAT_2000e0f4 += data_len - 9;
				G1_LOG_INF("Successfully received the subpackage content, "
					   "the packet sequence is %d,total size = %d\n",
					   idx, DAT_2000e0f4);
				DAT_2000e0f2++;
			} else if (idx == total) {
				if (DAT_2000e0f2 != idx - 1 || idx != DAT_2000e0f0) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					lock_k_mutex_20007f54(K_FOREVER);
					memset(DAT_20016b1f, 0, sizeof(DAT_20016b1f));
					unlock_k_mutex_20007f54();
					get_dashboard_state();
					DAT_20010dc1 = 0;
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				if (DAT_2000e0f4 - 9 + data_len > sizeof(DAT_20016b1f)) {
					G1_LOG_ERR("overview map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, DAT_2000e0f4 - 9 + data_len);
					return;
				}
				globle->f_0cd = data[3];
				nav = get_dashboard_state()->nav;
				lock_k_mutex_20007f54(K_FOREVER);
				memcpy(&DAT_20016b1f[DAT_2000e0f4], &data[9], data_len - 9);
				unlock_k_mutex_20007f54();
				DAT_2000e0f4 += data_len - 9;
				G1_LOG_INF("Successfully received the last packet,packet "
					   "length = %d,total packet size = %d\n",
					   idx, DAT_2000e0f4);
				nav->updated = 1;
				DAT_20010dc1 = 1;
				DAT_20010dbe = 1;
				nav->type = 2;
				nav->sync_id = data[3];
				nav->map_size = DAT_2000e0f4;
				DAT_2000e0f2++;
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_WRN("There is a packet order error, current packet order = %d, "
					   "expected packet order =%d\n",
					   idx, DAT_2000e0f2 + 1);
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
				lock_k_mutex_20007f54(K_FOREVER);
				memset(DAT_20016b1f, 0, sizeof(DAT_20016b1f));
				unlock_k_mutex_20007f54();
				PUT_RSP_NC(9, 1);
				ctx->write(resp, 10);
			}
			break;
		case 3: /* panoramic map */
			G1_LOG_INF("received navigation panoramic map data packet ....\n");
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (idx == 1) {
				uint32_t n = data_len - 10;

				pano_total = total;
				pano_cnt = 0;
				pano_len = 0;
				nav = get_dashboard_state()->nav;
				DAT_20010dc0 = 0;
				DAT_2001111d = 0;
				nav->panoramic = data[9];
				memset(DAT_20012a4f, 0, PANORAMIC_MAP_SIZE);
				memcpy(DAT_20012a4f, &data[10], n);
				pano_len = n;
				G1_LOG_INF("Successfully received multiple initialization packets, "
					   "currently the first packet of data,received data size = "
					   "%d,total packet len = %d\n",
					   pano_len, pano_total);
				pano_cnt++;
				PUT_RSP_NC(10, 0);
				ctx->write(resp, 11);
			} else if (idx < total) {
				get_dashboard_state();
				if (pano_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, pano_cnt + 1);
					pano_total = total;
					pano_cnt = 0;
					pano_len = 0;
					memset(DAT_20012a4f, 0, PANORAMIC_MAP_SIZE);
					DAT_20010dc0 = 0;
					PUT_RSP_NC(10, 1);
					ctx->write(resp, 11);
					return;
				}
				if (pano_len - 10 + data_len >= PANORAMIC_MAP_SIZE) {
					G1_LOG_ERR("Panoramic map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   pano_len, pano_len - 10 + data_len);
					return;
				}
				DAT_20010dc0 = 0;
				memcpy(&DAT_20012a4f[pano_len], &data[10], data_len - 10);
				pano_len += data_len - 10;
				G1_LOG_INF("Successfully received the subpackage content, "
					   "the packet sequence is %d,total received size "
					   "= %d\n",
					   idx, pano_len);
				pano_cnt++;
			} else if (idx == total) {
				nav = get_dashboard_state()->nav;
				if (pano_cnt != idx - 1 || idx != pano_total) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, pano_cnt + 1);
					pano_total = total;
					pano_cnt = 0;
					pano_len = 0;
					memset(DAT_20012a4f, 0, PANORAMIC_MAP_SIZE);
					DAT_20010dc0 = 0;
					PUT_RSP_NC(10, 1);
					ctx->write(resp, 11);
					return;
				}
				if (pano_len - 10 + data_len > PANORAMIC_MAP_SIZE) {
					G1_LOG_ERR("Panoramic map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   pano_len, pano_len - 10 + data_len);
					return;
				}
				globle->f_0cd = data[3];
				memcpy(&DAT_20012a4f[pano_len], &data[10], data_len - 10);
				pano_len += data_len - 10;
				G1_LOG_INF("Successfully received panoramic map  last "
					   "packet,Packet id = %d,total received size = "
					   "%d\n",
					   idx, pano_len);
				pano_cnt++;
				DAT_20010dc0 = 1;
				DAT_20010dbd = 1;
				nav->updated = 1;
				nav->type = 3;
				nav->sync_id = data[3];
				pano_total = 0;
				pano_cnt = 0;
				pano_len = 0;
				PUT_RSP_NC(10, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 11);
				} else {
					POST_TO_HOST(11);
				}
			} else {
				get_dashboard_state();
				G1_LOG_WRN("There is a packet order error, current packet order = %d, "
					   "expected packet order =%d\n",
					   idx, pano_cnt + 1);
				pano_total = total;
				pano_cnt = 0;
				pano_len = 0;
				memset(DAT_20012a4f, 0, PANORAMIC_MAP_SIZE);
				DAT_20010dc0 = 0;
				PUT_RSP_NC(10, 1);
				ctx->write(resp, 11);
			}
			break;
		case 4:
			G1_LOG_INF("received app send sync packet ....\n");
			nav = get_dashboard_state()->nav;
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 6);
			if (nav->running == 0) {
				resp[5] = 0;
				G1_LOG_WRN("navigation don't startup, sync packet return\n");
			} else {
				DAT_20007f48++;
			}
			ctx->write(resp, 6);
			break;
		case 5:
			G1_LOG_INF("received navigation func exit packet ....\n");
			nav = get_dashboard_state()->nav;
			globle->f_0cd = data[3];
			memset((uint8_t *)nav + 1, 0, sizeof(*nav) - 1);
			nav->running = 0;
			PUT_RSP(5, 1);
			ctx->write(resp, 6);
			break;
		case 6: {
			uint8_t status;

			nav = get_dashboard_state()->nav;
			globle->f_0cd = data[3];
			status = data[5];
			nav->updated = 1;
			nav->arrived = status;
			nav->type = 6;
			nav->sync_id = data[3];
			memset(resp, 0, sizeof(resp));
			memcpy(resp, data, 6);
			memset(nav->prompt, 0, sizeof(nav->prompt));
			if (data_len - 6 >= sizeof(nav->prompt)) {
				G1_LOG_ERR("app send prompt word oversize,drop it...\n");
				resp[5] = 1;
			} else {
				memcpy(nav->prompt, &data[6], data_len - 6);
				G1_LOG_INF("received arrived status packet. arrived status = %d "
					   ",arrived prompt word = %s\n",
					   status, nav->prompt);
				resp[5] = 0;
			}
			if (is_master() == 1) {
				send_response_data_to_msgqueue(resp, 6);
			} else {
				POST_TO_HOST(6);
			}
			break;
		}
		}
		break;
	}
	case BLE_CMD_TRANSLATE_SRC_TEXT: { /* translate: original text */
		struct translate_buf *tb;

		if (hdr->len != 0) {
			memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				FUN_0007f472(globle->translate_src, sizeof(struct translate_buf),
					     globle->f_0cd, 0);
				FUN_0007f4a4(data[1], 1, 0);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(DAT_20010b99, &data[7], hdr->len - 7);
		}
		if (data[3] == 0) {
			memset(globle->translate_src->data, 0, sizeof(globle->translate_src->data));
			tb = globle->translate_src;
			tb->len = 0;
			globle->translate_src->f_3 = data[4];
			globle->translate_src->f_4 = data[6] + data[5] * 256;
		}
		memcpy((uint8_t *)globle->translate_src + globle->translate_src->len + 6, DAT_20010b99,
		       hdr->len - 7);
		globle->translate_src->len += hdr->len - 7;
		((struct ble_req_hdr *)tx)->len = hdr->len;
		ctx->tx_len = hdr->len + 4;
		if (data[3] == data[2] - 1) {
			spim_transfer(ctx, rx, 8);
		}
		resp[2] = data[1];
		resp[3] = data[2];
		resp[4] = data[3];
		if (is_master() == 1) {
			if (data[3] == data[2] - 1) {
				deferred_text_ack_cmd = BLE_CMD_TRANSLATE_SRC_TEXT;
				deferred_text_ack_idx = data[3];
				deferred_text_ack_total = data[2];
				FUN_0007f4a4(data[1], 0, 0);
			} else {
				ctx->write(resp, 20);
			}
		} else {
			if (data[3] == data[2] - 1) {
				FUN_0007f4a4(data[1], 0, 0);
			}
			ctx->write(resp, 20);
		}
		break;
	}
	case BLE_CMD_TRANSLATE_DST_TEXT: { /* translate: translated text */
		struct translate_buf *tb;

		if (hdr->len != 0) {
			memset(DAT_20010b99, 0, sizeof(DAT_20010b99));
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				FUN_0007f472(globle->translate_dst, sizeof(struct translate_buf),
					     globle->f_0cc, 1);
				FUN_0007f41e(data[1], 1);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(DAT_20010b99, &data[7], hdr->len - 7);
		}
		if (data[3] == 0) {
			memset(globle->translate_dst->data, 0, sizeof(globle->translate_dst->data));
			tb = globle->translate_dst;
			tb->len = 0;
			globle->translate_dst->f_3 = data[4];
			globle->translate_dst->f_4 = data[6] + data[5] * 256;
		}
		memcpy((uint8_t *)globle->translate_dst + globle->translate_dst->len + 6, DAT_20010b99,
		       hdr->len - 7);
		globle->translate_dst->len += hdr->len - 7;
		((struct ble_req_hdr *)tx)->len = hdr->len;
		ctx->tx_len = hdr->len + 4;
		if (data[3] == data[2] - 1) {
			spim_transfer(ctx, rx, 8);
		}
		resp[2] = data[1];
		resp[3] = data[2];
		resp[4] = data[3];
		if (is_master() == 1) {
			if (data[3] == data[2] - 1) {
				deferred_text_ack_cmd = BLE_CMD_TRANSLATE_DST_TEXT;
				deferred_text_ack_idx = data[3];
				deferred_text_ack_total = data[2];
				FUN_0007f41e(data[1], 0);
			} else {
				ctx->write(resp, 20);
			}
		} else {
			if (data[3] == data[2] - 1) {
				FUN_0007f41e(data[1], 0);
			}
			ctx->write(resp, 20);
		}
		break;
	}
	case BLE_CMD_MICROPHONE_SET: /* microphone */
		if (data[1] == 1) {
			if (is_idle() || *get_dashboard_state()->task_status == 9 ||
			    *get_dashboard_state()->task_status == 0x10 ||
			    *get_dashboard_state()->task_status == 0xb ||
			    *get_dashboard_state()->task_status == 0x13 ||
			    *get_dashboard_state()->task_status == 0x14 ||
			    *get_dashboard_state()->task_status == 0xc ||
			    (get_dashboard_state()->f_0d5 == 0 && get_dashboard_state()->f_fea == 0)) {
				if (*get_dashboard_state()->task_status == 0x10 &&
				    get_dashboard_state()->dash_buf->type == 2) {
					get_dashboard_state()->dash_buf->type = 3;
				}
				G1_LOG_INF("received open dmic command\n");
				FUN_0008040c();
				resp[1] = PKCS7_PACK_DONE;
			} else {
				resp[1] = PKCS7_PACK_ERR;
				goto mic_tail;
			}
		} else {
			G1_LOG_INF("received close dmic command\n");
			FUN_00030458();
			resp[1] = PKCS7_PACK_DONE;
		}
mic_tail:
		resp[2] = data[1];
		ctx->write(resp, 20);
		break;
	case BLE_CMD_TRANSLATE_CONTROL:
		if (data[2] != 0 && data[3] != 0) {
			globle->translate_src->f_0 = data[3];
			globle->translate_src->f_1 = data[2];
			globle->translate_dst->f_0 = data[3];
			globle->translate_dst->f_1 = data[2];
		}
		globle->translate_src->suspend = data[1];
		globle->translate_dst->suspend = data[1];
		FUN_00030484(data[1]);
		G1_LOG_INF("received start/Pause command,origin language type = %d,translate origin "
			   "language type = %d,Suspend status = %d\n",
			   globle->translate_dst->f_1, globle->translate_dst->f_0,
			   globle->translate_src->suspend);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_FILE_UPLOAD:
		BIT_MAP_CHUNK_ID++;
		if (data[1] != BIT_MAP_CHUNK_ID) {
			resp[1] = BIT_MAP_CHUNK_ID;
			resp[2] = PKCS7_PACK_ERR;
			ctx->write(resp, 20);
			BIT_MAP_CHUNK_ID--;
			G1_LOG_ERR("wrong package id %d\n", BIT_MAP_CHUNK_ID);
		} else {
			enqueue_file(&data[1], (uint8_t)(hdr->len - 1));
			globle->dashboard_cmd = 0x15;
			k_sem_give(&globle->dashboard_position_sem);
		}
		globle->file_ts = k_uptime_get();
		break;
	case BLE_CMD_FILE_UPLOAD_COMPLETE:
		if (hdr->len < 0x15 && data[1] == 0xd && data[2] == 0xe) {
			enqueue_file(&data[1], (uint8_t)(hdr->len - 1));
			globle->dashboard_cmd = 0x20;
			k_sem_give(&globle->dashboard_position_sem);
			G1_LOG_ERR("recv upgrade font success\n");
			resp[1] = PKCS7_PACK_DONE;
			ctx->write(resp, 20);
		} else {
			resp[1] = PKCS7_PACK_ERR;
			ctx->write(resp, 20);
			G1_LOG_ERR("recv upgrade font failed\n");
		}
		BIT_MAP_CHUNK_ID = 0xff;
		break;
	case BLE_CMD_WEAR_DETECTION_SET:
		globle->check_mode = data[1];
		globle->dashboard_cmd = 0x27;
		k_sem_give(&globle->dashboard_position_sem);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_BITMAP_SHOW:
		rx[3] = data[1];
		rx[2] = data[2];
		rx[1] = data[3];
		rx[0] = data[4];
		resp[1] = data[1];
		resp[2] = data[2];
		resp[3] = data[3];
		resp[4] = data[4];
		if (*(uint32_t *)rx != LAST_FILE_CRC) {
			resp[5] = PKCS7_PACK_ERR;
		} else {
			resp[5] = PKCS7_PACK_DONE;
		}
		ctx->write(resp, 20);
		globle->dashboard_cmd = hdr->cmd;
		k_sem_give(&globle->dashboard_position_sem);
		break;
	case BLE_CMD_UPGRADE_CONTROL:
		setEraseDFU(true);
		globle->file_ts = k_uptime_get();
		globle->dashboard_cmd = hdr->cmd;
		k_sem_give(&globle->dashboard_position_sem);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_BITMAP_HIDE:
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		if (get_dashboard_state()->f_0d5 == 0xb || get_dashboard_state()->f_0d5 == 0x10) {
			FUN_000800ca(globle, 0);
		} else {
			if (get_dashboard_state()->is_master == 2 &&
			    get_dashboard_state()->f_0d5 == 6) {
				k_msleep(50);
			}
			FUN_0007ff66(globle, 0);
		}
		break;
	case BLE_CMD_TUTORIAL_CONTROL: {
		int n;

		G1_LOG_INF("received onboarding init packet ....\n");
		n = onboarding_ble_process(globle, hdr, data, resp);
		if (n > 0) {
			memcpy(msg, data, hdr->len);
			ret = ctx->write(resp, (uint16_t)n);
			if (ret < 0) {
				G1_LOG_ERR("onboarding post_to_host failed ret = %d\n", ret);
			}
		}
		break;
	}
	case BLE_CMD_HARDWARE_SET:
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == *(uint16_t *)&data[1] && data[4] < 9) {
			uint8_t v;

			resp[5] = PKCS7_PACK_DONE;
			switch (data[4]) {
			case HW_SUB_USER_DATA_RESET:
				globle->f_10d5 = 1;
				break;
			case HW_SUB_HEIGHT_DEPTH:
				if (data[6] > 8 || data[7] > 9) {
					goto setting_err;
				}
				globle->f_0cd = data[3];
				memcpy(msg, data, hdr->len);
				spim_transfer(ctx, rx, 8);
				break;
			case HW_SUB_GIVE_MIC_TRANSM_SEM:
				if (FUN_00033d5c() == 1) {
					G1_LOG_INF("give mic_transm_sem\n");
					k_sem_give(&DAT_200085b4);
				}
				break;
			case HW_SUB_LUM_GEAR:
				v = data[5];
				G1_LOG_WRN("ble set lum gear:%d\n", v);
				if (v > 0x3f) {
					goto setting_err;
				}
				if (globle->lum_gear != v) {
					globle->lum_gear = v;
					globle->lum_cur = v;
					globle->dashboard_cmd = hdr->cmd;
					sys_settings_dirty = 1;
					k_sem_give(&globle->dashboard_position_sem);
				}
				break;
			case HW_SUB_DOUBLE_TAP_ACTION:
				v = data[5];
				if (v > 5) {
					goto setting_err;
				}
				if (globle->f_1244 != v) {
					SendDoubleTapCustomizeToSlave(v);
				}
				break;
			case HW_SUB_LUM_COEFFICIENT:
				v = data[5];
				switch (v) {
				case 1:
					globle->dashboard_ts->f_72 = v;
					break;
				case 0:
					globle->dashboard_ts->f_72 = v;
					break;
				case 2:
					v = data[6];
					G1_LOG_WRN("ble set lum coeffic:%d\n", v);
					if (globle->dashboard_ts->f_72 != 1 || v < 70 || v > 100) {
						goto setting_err;
					}
					if (globle->f_ee0 != v) {
						globle->f_ee0 = v;
						set_brightness_to_panel_reg_in_running(globle->f_ed5);
						FUN_00025b28(0, 0);
					}
					break;
				default:
setting_err:
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				break;
			case HW_SUB_LONG_PRESS_ENABLE:
				v = data[5];
				if (v > 1) {
					goto setting_err;
				}
				if (globle->f_1246 != v) {
					SendLongpressTapCustomizeToSlave(v);
				}
				break;
			case HW_SUB_MIC_ON_HEAD_UP:
				if (data[5] == 1) {
					globle->f_1247 = 1;
				} else {
					globle->f_1247 = 0;
				}
				break;
			default:
				goto setting_err;
			}
		} else {
			goto setting_err;
		}
		ctx->write(resp, 20);
		break;
	default:
		G1_LOG_WRN("@tx error put req_type: %d\n", hdr->cmd);
		resp[1] = PKCS7_PACK_ERR;
		resp[2] = 0x15;
		strcpy((char *)&resp[2], "error put req.");
		ctx->write(resp, 20);
		break;
	}
}

/* ===== 0x22448 - 0x23d37 ===== */

int deal_event_to_phone(struct ble_context *ctx, uint8_t *evt)
{
	struct GlassesState *state = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	uint8_t buf[21] = {0};

	switch (evt[1]) {
	case 0xf0:
		buf[0] = 0x0d;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->f_0cd;
		buf[3] = deferred_text_ack_total;
		buf[4] = deferred_text_ack_idx;
		deferred_text_ack_total = 0;
		deferred_text_ack_idx = 0;
		break;
	case 0xf1:
		buf[0] = 0x0f;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->f_0cc;
		buf[3] = deferred_text_ack_total;
		buf[4] = deferred_text_ack_idx;
		deferred_text_ack_total = 0;
		deferred_text_ack_idx = 0;
		break;
	case 0xf2:
		buf[0] = 0x4e;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->f_0cc;
		buf[3] = deferred_text_ack_total;
		buf[4] = deferred_text_ack_idx;
		deferred_text_ack_total = 0;
		deferred_text_ack_idx = 0;
		break;
	case 9:
		memcpy(buf, evt, 3);
		break;
	case 0x0e:
		buf[0] = 0xf5;
		buf[1] = 0x0e;
		buf[2] = FUN_00033754();
		break;
	case 0x0f:
		buf[0] = 0xf5;
		buf[1] = 0x0f;
		buf[2] = FUN_00033760();
		break;
	case 10:
		buf[0] = 0xf5;
		buf[1] = 10;
		if (state->f_fc4 == 0x5d) {
			buf[2] = state->f_fc6 ? 0x5f : 0x5e;
		} else if (state->f_fc4 == 0x5e) {
			buf[2] = state->f_fc6 ? 0x61 : 0x60;
		} else {
			switch (state->f_fc4) {
			case 0x5f:
				buf[2] = 0x62;
				break;
			case 0x60:
				buf[2] = 0x63;
				break;
			default:
				buf[2] = state->f_fc4 > 0x60 ? 0x64 : state->f_fc4;
				break;
			}
		}
		break;
	case 0x12:
		buf[0] = 0xf5;
		buf[1] = 0x12;
		buf[2] = state->f_ed5;
		break;
	case 0x1e:
		G1_LOG_WRN("send dashboard start...\n");
		__fallthrough;
	default:
		buf[0] = 0xf5;
		buf[1] = evt[1];
		break;
	}
	ctx->write(buf, sizeof(buf));
	return 0;
}

/* response of a post request: cmd, u16 length, seq, sub command, status, ... */
#define POST_RESP_LEN(r) (*(uint16_t *)&(r)[1])

static int ble_process_post_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	uint8_t *tx = ctx->tx_buf;
	uint8_t *payload = tx + 4;
	uint8_t resp[20] = {0};
	uint8_t rx[128];
	/* data[4] read before the length checks; the four length-error paths share len_err */
	uint8_t op;
	/* sized view of the reassembly buffer: the vendor build saw its size here (__memcpy_chk) */
	extern uint8_t DAT_20010995[MULTI_PACKET_BUF_SIZE];

	memcpy(tx, hdr, sizeof(*hdr));
	ctx->tx_len = hdr->len + 4;
	resp[0] = hdr->cmd;

	switch (hdr->cmd) {
	case BLE_CMD_NOTIFICATION_SEND:
		post_notification_cmd_process(ctx, hdr, data);
		return 0;
	case BLE_CMD_SYNC_DISPLAY:
		memcpy(ctx->tx_buf, hdr, sizeof(*hdr));
		memcpy(payload, data + 1, hdr->len - 1);
		ctx->tx_len = hdr->len + 4;
		goto send_to_master;
	case BLE_CMD_BT_UNPAIR: {
		struct bt_conn *conn;
		int err;

		G1_LOG_WRN("*****will unbond current bt connection*****\n\n");
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, sizeof(resp));
		err = bt_unpair(BT_ID_DEFAULT, NULL);
		if (err) {
			G1_LOG_WRN("bt_unpair fail: %d\n\n", err);
		}
		conn = FUN_00019cec();
		if (conn == NULL) {
			return 0;
		}
		G1_LOG_ERR("bt_conn_disconnect because recv unpair\n");
		bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
		return 0;
	}
	case BLE_CMD_TEXT_SET: {
		struct dash_data_buf *dash;
		uint8_t t;

		if (hdr->len != 0) {
			memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				FUN_0007f472(get_dashboard_state()->dash_buf,
					     sizeof(struct dash_data_buf),
					     get_dashboard_state()->f_0cc, 1);
				FUN_0007f41e(data[1], 1);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(DAT_20010995, data + 9, hdr->len - 9);
		}
		if (data[3] == 0) {
			memset(get_dashboard_state()->dash_buf->data, 0,
			       sizeof(get_dashboard_state()->dash_buf->data));
			dash = get_dashboard_state()->dash_buf;
			((uint8_t *)&dash->len)[0] = 0;
			((uint8_t *)&dash->len)[1] = 0;
			get_dashboard_state()->dash_buf->f_1 = data[4];
			get_dashboard_state()->dash_buf->f_2 = data[5] * 256 + data[6];
			get_dashboard_state()->dash_buf->f_4 = data[7];
			get_dashboard_state()->dash_buf->f_5 = data[8];
		}
		dash = get_dashboard_state()->dash_buf;
		memcpy(&dash->data[get_dashboard_state()->dash_buf->len], DAT_20010995,
		       hdr->len - 9);
		get_dashboard_state()->dash_buf->len += hdr->len - 9;
		((struct ble_req_hdr *)tx)->len = hdr->len;
		ctx->tx_len = hdr->len + 4;
		if (data[3] == data[2] - 1) {
			spim_transfer(ctx, rx, 8);
			if ((data[4] & 0xf0) == 0x60) {
				FUN_00030458();
				get_dashboard_state()->dash_buf->type = 10;
			} else if ((data[4] & 0xf0) == 0x70) {
				dash = get_dashboard_state()->dash_buf;
				t = 15;
				goto dash_f0;
			} else if (get_dashboard_state()->dash_buf->type != 6) {
				if ((data[4] & 0xf0) == 0x30) {
					goto dash_7;
				} else if ((data[4] & 0xf0) == 0x40) {
					goto dash_8;
				} else if (get_dashboard_state()->dash_buf->type > 6) {
					if ((data[4] & 0xf0) != 0x40) {
						if ((data[4] & 0xf0) == 0x50) {
							dash = get_dashboard_state()->dash_buf;
							t = 9;
							goto dash_f0;
						}
					} else {
						get_dashboard_state()->dash_buf->type = 8;
						get_dashboard_state()->f_0db = 8;
					}
				}
			} else if ((data[4] & 0xf0) == 0x40) {
			dash_8:
				get_dashboard_state()->dash_buf->type = 8;
				get_dashboard_state()->f_0db = 8;
			} else {
			dash_7:
				get_dashboard_state()->dash_buf->type = 7;
				get_dashboard_state()->f_0db = 0x10;
			}
			if (0) {
			dash_f0:
				dash->type = t;
				get_dashboard_state()->f_0db = 0;
			}
		}
		resp[2] = data[1];
		resp[3] = data[2];
		resp[4] = data[3];
		if (is_master() == 1) {
			if (data[3] == data[2] - 1) {
				deferred_text_ack_cmd = BLE_CMD_TEXT_SET;
				deferred_text_ack_total = data[2];
				deferred_text_ack_idx = data[3];
				FUN_0007f41e(data[1], 0);
				return 0;
			}
		} else if (data[3] == data[2] - 1) {
			FUN_0007f41e(data[1], 0);
			/* per-site write copies (&resp[0] keeps them apart in GIMPLE; RTL merges them) */
			ctx->write(&resp[0], sizeof(resp));
			return 0;
		}
		ctx->write(&resp[0], sizeof(resp));
		return 0;
	}
	case BLE_CMD_POST_49:
	case BLE_CMD_MTU_SET:
	send_to_master:
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		break;
	case BLE_CMD_NOTIFICATION_CLEAR:
		G1_LOG_INF("ble_process_post_req BLE_REQ_POST_DELETE_NOTIFICATION_MSG\n");
		memcpy(payload, data + 1, hdr->len - 1);
		goto send_to_master;
	case BLE_CMD_NOTIF_AUTO_DISPLAY_SET:
		memcpy(ctx->tx_buf, hdr, sizeof(*hdr));
		memcpy(payload, data + 1, hdr->len - 1);
		spim_transfer(ctx, rx, 8);
		resp[1] = rx[0];
		resp[2] = rx[1];
		resp[3] = rx[2];
		ctx->write(&resp[0], sizeof(resp));
		return 0;
	case BLE_CMD_DASHBOARD_LOCK_SET:
		if (*(uint16_t *)&data[1] != hdr->len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = %d\n",
				   hdr->len, *(uint16_t *)&data[1]);
			return 0;
		}
		G1_LOG_INF("received Dashboard lock command.\n");
		{
		uint8_t action = data[4];
		if (get_dashboard_state()->is_master == 1) {
			if (action == 1) {
				if (atomic_test_bit(&DAT_20007f50, DASHBOARD_LOCK_BIT)) {
					return 0;
				}
				G1_LOG_INF("master exec dashboard lock process.\n");
				atomic_set_bit(&DAT_20007f50, DASHBOARD_LOCK_BIT);
				atomic_clear_bit(&DAT_20007f4c, DASHBOARD_LOCK_BIT);
				k_timer_start(&DashboardLockTimer, K_SECONDS(1), K_NO_WAIT);
				return 0;
			}
			G1_LOG_ERR("received error dashboard lock action command.\n");
			return 0;
		}
		G1_LOG_ERR("slave received error dashboard lock command! can't exec\n");
		return 0;
		}
	case BLE_CMD_QUICK_NOTE_UPDATE_TASK: {
		uint16_t data_len = *(uint16_t *)&data[1];
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == data_len && data[4] <= 2) {
			if (data[5] == 1) {
				get_dashboard_state()->buf_1028->enable = 1;
				get_dashboard_state()->buf_1028->f_1 = data[4];
				get_dashboard_state()->buf_1028->timeout = k_uptime_get() + 5000;
				get_dashboard_state()->f_0cd = data[3];
				update_persist_task_status(get_dashboard_state(), 0x12, 2);
			} else {
				get_dashboard_state()->buf_1028->enable = 0;
			}
			resp[5] = PKCS7_PACK_DONE;
		} else {
			resp[5] = PKCS7_PACK_ERR;
		}
		break;
	}
	case BLE_CMD_TRANSCRIBE_CONTROL: {
		uint16_t data_len = *(uint16_t *)&data[1];
		op = data[4];
		uint16_t total, idx;

		if (hdr->len == data_len && op <= 3) {
		transcribe_info_timeout_reset();
		switch (data[4]) {
		case 1: {
				uint8_t mode = data[5];

				resp[1] = 7;
				resp[2] = 0;
				resp[3] = data[3];
				resp[4] = 1;
				resp[5] = PKCS7_PACK_DONE;
				resp[6] = mode;
				if (mode == 0) {
					get_dashboard_state()->transcribe_buf->running = mode;
					FUN_00030458();
				} else if (mode == 1 || mode == 2) {
					memset(get_dashboard_state()->transcribe_buf, 0,
					       sizeof(struct transcribe_buf));
					get_dashboard_state()->transcribe_buf->running = true;
					get_dashboard_state()->transcribe_buf->mode = resp[6];
					if (get_dashboard_state()->transcribe_buf->mode == 2) {
						get_dashboard_state()->transcribe_buf->flags = 0;
					} else {
						get_dashboard_state()->transcribe_buf->flags = 0xff;
					}
					get_dashboard_state()->f_0cd = data[3];
					update_persist_task_status(get_dashboard_state(), 0x13, 2);
				} else if (mode == 3) {
					FUN_00030484(1);
					get_dashboard_state()->transcribe_buf->flags &= ~1;
				} else if (mode == 4) {
					FUN_00030484(0);
					if (get_dashboard_state()->transcribe_buf->mode != 2) {
						get_dashboard_state()->transcribe_buf->flags |= 1;
					}
				}
			break;
		}
		case 2:
				memcpy(resp, data, 9);
				resp[1] = 10;
				resp[2] = 0;
				resp[9] = PKCS7_PACK_DONE;
				total = *(uint16_t *)&data[5];
				idx = *(uint16_t *)&data[7];
				if (total == 1) {
					G1_LOG_INF("received transcribe packet,total packet = 1\n");
					get_dashboard_state()->transcribe_buf->f_3 = data[9];
					if (data[10] == 1 || get_dashboard_state()->transcribe_buf->mode == 2) {
						get_dashboard_state()->transcribe_buf->flags &= ~1;
					} else {
						get_dashboard_state()->transcribe_buf->flags |= 1;
					}
					get_dashboard_state()->transcribe_buf->f_5 = data[11];
					memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
					memset(get_dashboard_state()->transcribe_buf->data, 0,
					       sizeof(get_dashboard_state()->transcribe_buf->data));
					get_dashboard_state()->transcribe_buf->len = data_len - 12;
					memcpy(get_dashboard_state()->transcribe_buf->data, data + 12,
					       get_dashboard_state()->transcribe_buf->len);
					FUN_0007f4a4(data[3], 0, 0);
				} else if (idx == 1) {
					G1_LOG_INF("Received transcribe multiple packets, currently the first "
						   "packet of data\n");
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 1;
					memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
					memcpy(DAT_20010995, data + 12, data_len - 12);
					DAT_2000e0f4 = data_len - 12;
				} else if (idx < total) {
					if (DAT_2000e0f2 != idx - 1) {
						G1_LOG_WRN("There is a packet order error, current packet order = "
							   "%d, expected packet order = %d\n",
							   idx, DAT_2000e0f2 + 1);
						DAT_2000e0f0 = total;
						DAT_2000e0f2 = 0;
						DAT_2000e0f4 = 0;
						memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
						resp[9] = PKCS7_PACK_ERR;
						break;
					}
					if (DAT_2000e0f4 + data_len > 0x20c) {
						G1_LOG_ERR("transcribe data is too long, the current data length "
							   "%d,wait write data length = %d\n",
							   DAT_2000e0f4, data_len - 12);
						resp[9] = PKCS7_PACK_ERR;
						break;
					}
					memcpy(DAT_20010995 + DAT_2000e0f4, data + 12, data_len - 12);
					DAT_2000e0f4 = DAT_2000e0f4 - 12 + data_len;
					G1_LOG_INF("Successfully received the subpackage content, the packet "
						   "sequence is %d\n",
						   idx);
					DAT_2000e0f2++;
				} else if (idx == total) {
					if (DAT_2000e0f2 != total - 1 || DAT_2000e0f0 != total) {
						G1_LOG_WRN("There is a packet order error, current packet order = "
							   "%d, expected packet order = %d\n",
							   idx, DAT_2000e0f2 + 1);
						DAT_2000e0f0 = total;
						DAT_2000e0f2 = 0;
						memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
						resp[9] = PKCS7_PACK_ERR;
						break;
					}
					if (DAT_2000e0f4 + data_len > 0x20c) {
						G1_LOG_ERR("transcribe data is too long, the current data length "
							   "%d,wait write data length = %d\n",
							   DAT_2000e0f4, data_len - 12);
						resp[9] = PKCS7_PACK_ERR;
						break;
					}
					G1_LOG_INF("Successfully assembled multiple packages of data, and "
						   "updated the complete content to the UI thread for data "
						   "update.\n");
					get_dashboard_state()->transcribe_buf->f_3 = data[9];
					if (data[10] == 1 || get_dashboard_state()->transcribe_buf->mode == 2) {
						get_dashboard_state()->transcribe_buf->flags &= ~1;
					} else {
						get_dashboard_state()->transcribe_buf->flags |= 1;
					}
					get_dashboard_state()->transcribe_buf->f_5 = data[11];
					memcpy(DAT_20010995 + DAT_2000e0f4, data + 12, data_len - 12);
					DAT_2000e0f4 = DAT_2000e0f4 - 12 + data_len;
					memset(get_dashboard_state()->transcribe_buf->data, 0,
					       sizeof(get_dashboard_state()->transcribe_buf->data));
					memcpy(get_dashboard_state()->transcribe_buf->data, DAT_20010995,
					       DAT_2000e0f4);
					get_dashboard_state()->transcribe_buf->len = DAT_2000e0f4;
					FUN_0007f4a4(data[3], 0, 0);
					DAT_2000e0f0 = 0;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
				}
			break;
		case 3:
				resp[1] = 7;
				resp[2] = 0;
				resp[3] = data[3];
				goto transcribe_status;
		default:
				resp[1] = 6;
				resp[2] = 0;
				resp[3] = data[3];
				resp[4] = data[4];
				resp[5] = PKCS7_PACK_ERR;
			break;
		}
		} else {
			goto len_err;
		}
		goto post_resp;
	}
	case BLE_CMD_TRANSCRIBE_STATUS: {
		if (hdr->len == *(uint16_t *)&data[1]) {
		op = data[4];
		if (op <= 3) {
			transcribe_info_timeout_reset();
			if (data[4] == 3) {
				resp[1] = 7;
				resp[2] = 0;
				(&resp[1])[2] = data[3];
			transcribe_status:
				resp[4] = 3;
				resp[5] = PKCS7_PACK_DONE;
				resp[5] = get_dashboard_state()->transcribe_buf->running ? PKCS7_PACK_DONE
											 : PKCS7_PACK_ERR;
				resp[6] = data[5];
			} else {
				resp[1] = 6;
				resp[2] = 0;
				resp[3] = data[3];
				resp[4] = data[4];
				resp[5] = PKCS7_PACK_ERR;
			}
		} else {
			goto len_err;
		}
		} else {
			op = *(uint8_t *)((uintptr_t)data + 4);
			goto len_err;
		}
		goto post_resp;
	}
	case BLE_CMD_EVENAI: {
		uint16_t data_len = *(uint16_t *)&data[1];
		uint8_t sub;

		if (hdr->len == data_len) {
		op = data[4];
		if (op <= 7) {
		even_ai_v2_info_timeout_reset();
		sub = data[4];
		switch (sub) {
		case 1: {
			uint8_t mode = data[5];

			resp[1] = 7;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = 1;
			resp[5] = PKCS7_PACK_DONE;
			resp[6] = mode;
			if (mode == 1) {
				get_dashboard_state()->evenai_buf->state = mode;
				get_dashboard_state()->evenai_buf->sub = mode;
				get_dashboard_state()->evenai_buf->f_2 = data[6];
				get_dashboard_state()->evenai_buf->f_3 = data[7];
				memset(get_dashboard_state()->evenai_buf->data, 0,
				       sizeof(get_dashboard_state()->evenai_buf->data));
			} else if (mode == 2) {
				get_dashboard_state()->evenai_buf->state = mode;
				FUN_00030458();
				goto post_resp;
			} else if (mode == 3) {
				get_dashboard_state()->evenai_buf->state = 1;
				get_dashboard_state()->evenai_buf->sub = 0;
			} else {
				if (is_master() == 1) {
					get_dashboard_state()->evenai_buf->state = 0;
				}
				FUN_00030458();
				goto post_resp;
			}
			if (*get_dashboard_state()->task_status != 0x14) {
				update_persist_task_status(get_dashboard_state(), 0x14, 2);
			}
			FUN_0007f4a4(data[3], 0, 0);
			break;
		}
		case 2:
		case 3:
		case 4: {
			int hlen;
			uint16_t total, idx;

			memcpy(resp, data, 9);
			resp[1] = 10;
			resp[2] = 0;
			resp[9] = PKCS7_PACK_DONE;
			if (sub == 2) {
				hlen = 11;
			} else if (sub == 3) {
				hlen = 12;
			} else {
				hlen = 10;
			}
			idx = *(uint16_t *)&data[7];
			total = *(uint16_t *)&data[5];
			if (total == 1) {
				int n;
				uint8_t *payload;

				G1_LOG_INF("received evenai_v2 packet,total packet = 1\n");
				n = data_len - hlen;
				if (n > 0x200) {
					G1_LOG_ERR("evenai_v2 data is too long, the current data length "
						   "0,wait write data length = %d\n",
						   n);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				payload = data + hlen;
				get_dashboard_state()->evenai_buf->sub = sub;
				get_dashboard_state()->evenai_buf->f_3 = data[9];
				if (sub != 4) {
					get_dashboard_state()->evenai_buf->f_4 = data[10];
					if (sub == 2) {
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					} else {
						get_dashboard_state()->evenai_buf->f_5 = data[11];
					}
				} else {
					if (get_dashboard_state()->evenai_buf->f_3 == 1) {
						get_dashboard_state()->dashboard_ts->f_72 = 2;
					} else if (get_dashboard_state()->evenai_buf->f_3 == 0x13) {
						if (*get_dashboard_state()->task_status != 0x14) {
							if (get_dashboard_state()->f_0d5 == 6 &&
							    get_dashboard_state()->dashboard_ts->f_74 == 0) {
								get_dashboard_state()->dashboard_ts->f_74 = 1;
							}
							get_dashboard_state()->evenai_buf->state = 1;
							update_persist_task_status(get_dashboard_state(),
										   0x14, 2);
						}
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					}
				}
				if (sub != 2 || get_dashboard_state()->evenai_buf->f_3 != 1 || payload[0] != 0) {
					memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
					memset(get_dashboard_state()->evenai_buf->data, 0,
					       sizeof(get_dashboard_state()->evenai_buf->data));
					get_dashboard_state()->evenai_buf->len = n;
					memcpy(get_dashboard_state()->evenai_buf->data, payload,
					       get_dashboard_state()->evenai_buf->len);
				}
				FUN_0007f4a4(data[3], 0, 0);
			} else if (idx == 1) {
				G1_LOG_INF("Received evenai_v2 multiple packets, currently the first "
					   "packet of data\n");
				DAT_2000e0f0 = total;
				DAT_2000e0f2 = 1;
				memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
				memcpy(DAT_20010995, data + hlen, data_len - hlen);
				DAT_2000e0f4 = data_len - hlen;
			} else if (idx < total) {
				if (DAT_2000e0f2 != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order = "
						   "%d, expected packet order = %d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					DAT_2000e0f4 = 0;
					memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				if (DAT_2000e0f4 + data_len - hlen > 0x200) {
					G1_LOG_ERR("evenai_v2 data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, data_len - hlen);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				memcpy(DAT_20010995 + DAT_2000e0f4, data + hlen, data_len - hlen);
				DAT_2000e0f4 = DAT_2000e0f4 + data_len - hlen;
				G1_LOG_INF("Successfully received the subpackage content, the packet "
					   "sequence is %d\n",
					   idx);
				DAT_2000e0f2++;
			} else if (idx == total) {
				if (DAT_2000e0f2 != idx - 1 || idx != DAT_2000e0f0) {
					G1_LOG_WRN("There is a packet order error, current packet order = "
						   "%d, expected packet order = %d\n",
						   idx, DAT_2000e0f2 + 1);
					DAT_2000e0f0 = total;
					DAT_2000e0f2 = 0;
					memset(DAT_20010995, 0, MULTI_PACKET_BUF_SIZE);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				if (DAT_2000e0f4 + data_len - hlen > 0x200) {
					G1_LOG_ERR("evenai_v2 data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   DAT_2000e0f4, data_len - hlen);
					(&resp[1])[8] = PKCS7_PACK_ERR; /* = resp[9]; this form keeps the copy out of tree tail-merge */
					goto post_resp;
				}
				G1_LOG_INF("Successfully assembled multiple packages of data, and "
					   "updated the complete content to the UI thread for data "
					   "update.\n");
				get_dashboard_state()->evenai_buf->sub = sub;
				get_dashboard_state()->evenai_buf->f_3 = data[9];
				if (sub != 4) {
					get_dashboard_state()->evenai_buf->f_4 = data[10];
					if (sub == 2) {
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					} else {
						get_dashboard_state()->evenai_buf->f_5 = data[11];
					}
				} else {
					if (get_dashboard_state()->evenai_buf->f_3 == 1) {
						get_dashboard_state()->dashboard_ts->f_72 = 2;
					} else if (get_dashboard_state()->evenai_buf->f_3 == 0x13) {
						if (*get_dashboard_state()->task_status != 0x14) {
							if (get_dashboard_state()->f_0d5 == 6 &&
							    get_dashboard_state()->dashboard_ts->f_74 == 0) {
								get_dashboard_state()->dashboard_ts->f_74 = 1;
							}
							get_dashboard_state()->evenai_buf->state = 1;
							update_persist_task_status(get_dashboard_state(),
										   0x14, 2);
						}
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					}
				}
				memcpy(DAT_20010995 + DAT_2000e0f4, data + hlen, data_len - hlen);
				DAT_2000e0f4 = DAT_2000e0f4 + data_len - hlen;
				if (sub != 2 || get_dashboard_state()->evenai_buf->f_3 != 1 ||
				    data[hlen] != 0) {
					memset(get_dashboard_state()->evenai_buf->data, 0,
					       sizeof(get_dashboard_state()->evenai_buf->data));
					memcpy(get_dashboard_state()->evenai_buf->data, DAT_20010995,
					       DAT_2000e0f4);
					get_dashboard_state()->evenai_buf->len = DAT_2000e0f4;
				}
				FUN_0007f4a4(data[3], 0, 0);
				DAT_2000e0f0 = 0;
				DAT_2000e0f2 = 0;
				DAT_2000e0f4 = 0;
			}
			break;
		}
		case 5:
			resp[1] = 7;
			resp[2] = 0;
			resp[3] = data[3];
			goto evenai_status;
		default:
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = sub;
			resp[5] = PKCS7_PACK_ERR;
			break;
		}
		goto post_resp;
		}
		} else {
			op = *(uint8_t *)((uintptr_t)data + 4);
		}
		{
		len_err:
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = op;
			resp[5] = PKCS7_PACK_ERR;
		}
		goto post_resp;
	}
	case BLE_CMD_EVENAI_STATUS: {
		if (*(uint16_t *)&data[1] == hdr->len) {
			op = data[4];
			if (op > 7)
				goto len_err;
		} else {
			op = *(uint8_t *)((uintptr_t)data + 4);
			goto len_err;
		}
		even_ai_v2_info_timeout_reset();
		if (data[4] == 5) {
			resp[1] = 7;
			resp[2] = 0;
			(&resp[1])[2] = data[3];
		evenai_status:
			resp[4] = 5;
			resp[5] = PKCS7_PACK_DONE;
			if (get_dashboard_state()->evenai_buf->state == 0) {
				resp[5] = PKCS7_PACK_ERR;
			} else if (get_dashboard_state()->evenai_buf->state > 1) {
				resp[5] = PKCS7_PACK_ERR;
			} else {
				resp[5] = PKCS7_PACK_DONE;
			}
			resp[6] = data[5];
		} else {
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = data[4];
			resp[5] = PKCS7_PACK_ERR;
		}
		goto post_resp;
	}
	case BLE_CMD_EVENAI_EXIT:
		if (*(uint16_t *)&data[1] == hdr->len) {
			even_ai_v2_info_timeout_reset();
			{
			uint8_t sub = data[4];
			uint8_t seq = data[3];
			uint8_t flag = data[5];
			if (sub == 8) {
				resp[1] = 7;
				resp[2] = 0;
				resp[3] = seq;
				resp[4] = 8;
				resp[5] = 0;
				resp[6] = flag;
				if (flag == 0) {
					if (get_dashboard_state()->dashboard_ts->f_74 == 0) {
						get_dashboard_state()->dashboard_ts->f_74 = 1;
					}
					FUN_00030458();
				}
			} else {
				resp[1] = 7;
				resp[2] = 0;
				resp[3] = seq;
				resp[4] = sub;
				resp[5] = 1;
				resp[6] = flag;
			}
			}
		} else {
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = data[4];
			resp[5] = 1;
		}
		goto post_resp;
	default:
		G1_LOG_WRN("@tx error post req_type: %d\n", hdr->cmd);
		resp[1] = PKCS7_PACK_ERR;
		resp[2] = 0x15;
		strcpy((char *)&resp[2], "error post req.");
		goto post_write;
	}
	goto post_write;
post_resp:
	ctx->write(resp, POST_RESP_LEN(resp));
	return 0;
post_write:
	ctx->write(resp, sizeof(resp));
	return 0;
}

static int ble_process_report_response(struct ble_context *ctx, struct ble_req_hdr *hdr,
				       uint8_t *data)
{
	uint8_t cmd = hdr->cmd;
	uint8_t resp[21] = {0};

	switch (cmd) {
	case BLE_CMD_AUDIO:
		if (data[2] == PKCS7_PACK_DONE || data[2] == PKCS7_PACK_MORE) {
			return 0;
		}
		if (data[2] == 0xcc) {
			send_dmic_msg(ctx);
			return 0;
		}
		G1_LOG_WRN("@tx error post req_type: %d\n", cmd);
		resp[1] = PKCS7_PACK_ERR;
		resp[2] = 0x15;
		strcpy((char *)&resp[2], "error post req.");
		ctx->write(resp, 20);
		return 0;
	case BLE_CMD_DEBUG:
		FUN_0007f4d2(ctx);
		return 0;
	case BLE_CMD_EVENT:
		deal_event_to_phone(ctx, data);
		return 0;
	}
	G1_LOG_WRN("@tx error post req_type: %d\n", cmd);
	resp[1] = PKCS7_PACK_ERR;
	resp[2] = 0x15;
	strcpy((char *)&resp[2], "error post req.");
	ctx->write(resp, 20);
	return 0;
}

int ble_process_req_dispatch(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	uint8_t cmd = hdr->cmd;

	if (cmd >= 0x01 && cmd <= 0x27) {
		ble_process_put_req(ctx, hdr, data);
		return 0;
	}
	if (cmd >= 0x29 && cmd <= 0x45) {
		ble_process_get_req(ctx, hdr, data);
		return 0;
	}
	if (cmd >= 0x47 && cmd <= 0x56) {
		return ble_process_post_req(ctx, hdr, data);
	}
	if (cmd >= 0xf1 && cmd <= 0xf6) {
		return ble_process_report_response(ctx, hdr, data);
	}
	G1_LOG_ERR("tx error req_type. %d\n", cmd);
	ctx->write("NN", 3);
	return 0;
}

int mobile_send_notification_to_ble_device_test(const char *title, const char *message,
						 ble_send_fn_t send)
{
	cJSON *notif = cJSON_CreateObject();
	cJSON *root;
	char *str;

	cJSON_AddStringToObject(notif, "app_identifier", "com.tencent.xin");
	cJSON_AddStringToObject(notif, "title", title);
	cJSON_AddStringToObject(notif, "subtitle", "aaa");
	cJSON_AddStringToObject(notif, "message", message);
	cJSON_AddStringToObject(notif, "date", "08-04 09:50");
	cJSON_AddStringToObject(notif, "display_name", "微信");
	root = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "ncs_notification", notif);
	str = cJSON_Print(root);
	G1_LOG_INF("%s\n", str);
	subcontracing_send_data_pkcs7((uint8_t *)str, strlen(str), 0x4b, send);
	cJSON_Delete(root);
	return 0;
}


void FUN_00023d38(uint8_t *data, uint32_t len, int dump)
{
	if (dump) {
		dump_hex("BLE-rec", data, len);
	}
	if (spec_ble_command_hook(data, len)) {
		FUN_0007f50c(data, len);
	}
}

void ble_work_thread(void *p1, void *p2, void *p3)
{
	struct ble_context *ctx = p1;
	struct bt_data_msg msg;
	int err;

	G1_LOG_INF("start\n\n");
	err = ancs_main(ctx);
	debug_init();
	if (err) {
		G1_LOG_INF("err:%d\n\n", err);
	}
	ctx->tx_buf = malloc(BLE_TX_BUF_SIZE);
	G1_LOG_INF("tx_size:%d\n\n", BLE_TX_BUF_SIZE);

	while (1) {
		if (!(get_dashboard_state()->module_mask & BIT(7))) {
			k_msleep(1000);
			continue;
		}
		if (dequeue_bt_data(&msg) == 0) {
			if (msg.len > BLE_SMALL_PKT_MAX) {
				memcpy(ctx->rx_data, msg.data, msg.len);
				ctx->rx_len = msg.len;
			} else {
				memcpy(ctx->rx_bufs[2], msg.data, msg.len);
				ctx->rx_pending = 1;
				ctx->small_len = msg.len;
				ctx->rx_len = 0;
			}
		} else {
			ctx->receiver_thd_is_running = 0;
			k_sem_take(&ctx->rx_sem, K_FOREVER);
			ctx->receiver_thd_is_running = 1;
			if (ctx->rx_pending == 0 && ctx->rx_len == 0) {
				if (last_ble_cmd != 0xff) {
					ctx->rx_pending = 1;
					ctx->rx_bufs[2][0] = 0xf5;
					ctx->rx_bufs[2][1] = last_ble_cmd;
					last_ble_cmd = 0xff;
					ctx->rx_bufs[2][2] = PKCS7_PACK_MORE;
					ctx->rx_len = 0;
					ctx->small_len = 3;
					if (ctx->rx_bufs[2][1] == 9 || ctx->rx_bufs[2][1] == 10) {
						ctx->rx_bufs[2][2] = ctx->f_018;
					}
				} else if (DAT_20019a77) {
					ctx->rx_pending = 1;
					ctx->rx_bufs[2][0] = 0xf1;
					DAT_20019a77 = 0;
					ctx->rx_bufs[2][1] = 0;
					ctx->rx_bufs[2][2] = 0xcc;
					ctx->rx_len = 0;
				} else if (debug_pending) {
					ctx->rx_pending = 1;
					ctx->rx_bufs[2][0] = 0xf4;
					ctx->rx_bufs[2][1] = 0;
					ctx->rx_bufs[2][2] = PKCS7_PACK_MORE;
					debug_pending = 0;
					ctx->rx_len = 0;
				} else {
					continue;
				}
			}
		}

		if (ctx->restart_adv) {
			err = stop_ble_advertising();
			if (err) {
				G1_LOG_WRN("bt_le_adv_stop failed!!! err=%d\n\n", err);
			} else {
				G1_LOG_INF("charge plug off, call bt_start. \n\n");
				err = bt_start();
				if (err) {
					printk("Advertising failed to start (err %d)\n", err);
				}
			}
			ctx->restart_adv = 0;
			continue;
		}
		if (ctx->rx_len) {
			FUN_00023d38(ctx->rx_data, ctx->rx_len, 0);
			memset(ctx->rx_data, 0, sizeof(ctx->rx_data));
		} else {
			FUN_00023d38(ctx->rx_bufs[ctx->rx_pending + 1], ctx->small_len, 0);
		}
		ctx->rx_len = 0;
		ctx->rx_pending = 0;
	}
}

static K_THREAD_STACK_DEFINE(ble_work_thread_stack, BLE_WORK_THREAD_STACK_SIZE);
static struct k_thread ble_work_thread_data;
struct k_timer DashboardLockTimer;

/* ===== align-2 helpers ===== */

static void FUN_0007f41e(uint8_t a, uint8_t b)
{
	get_dashboard_state()->f_0ce = b;
	get_dashboard_state()->f_0cc = a;
}

int FUN_0007f472(const void *data, size_t len, uint8_t arg, int sel)
{
	uint8_t *buf;

	if (sel) {
		buf = get_dashboard_state()->buf_1038;
	} else {
		buf = get_dashboard_state()->buf_103c;
	}
	memcpy(buf, data, len);
	buf[0x200] = arg;
	return 0;
}

/* noinline: the shipped code has no partial-inlining clone of this function (see status) */
__attribute__((noinline)) int FUN_0007f4a4(uint8_t a, uint8_t b, int sel)
{
	if (sel) {
		FUN_0007f41e(a, b);
	} else {
		get_dashboard_state()->f_0cf = b;
		get_dashboard_state()->f_0cd = a;
	}
	return 0;
}

void ble_printk(const char *fmt, ...)
{
	struct ble_context *ctx = get_ble_context();
	char buf[DEBUG_MSG_SIZE];
	va_list ap;

	va_start(ap, fmt);
	memset(buf, 0, sizeof(buf));
	vsnprintf(buf, sizeof(buf), fmt, ap);
	enqueue_debug(buf);
	buf[0] = '\0';
	va_end(ap);

	if (!ctx->receiver_thd_is_running && k_sem_count_get(&ctx->rx_sem) == 0) {
		debug_pending = 1;
		k_sem_give(&ctx->rx_sem);
	}
}

int FUN_0007f4c6(struct ble_context *ctx, uint8_t *buf, uint32_t len)
{
	spim_transfer(ctx, buf, len);
	return len;
}

int FUN_0007f4d2(struct ble_context *ctx)
{
	char buf[DEBUG_MSG_SIZE + 4];

	while (1) {
		memset(&buf[1], 0, 0xca);
		buf[0] = 0xf4;
		if (dequeue_debug(&buf[1])) {
			break;
		}
		ctx->write(buf, strlen(buf) + 1);
	}
	return 0;
}

int subcontracing_send_data_pkcs7(const uint8_t *data, int len, uint8_t cmd, ble_send_fn_t send)
{
	/* the vendor build calls send through an int-returning type (result ignored) */
	typedef int (*send_ret_fn_t)(uint8_t *buf, uint32_t len);
	uint8_t buf[20] = {0};
	int integer_num = len / 17;
	int tail_len = len % 17;
	int i;
	int n;

	buf[1] = integer_num + 1;
	buf[0] = cmd;
	G1_LOG_INF("integer_num: %d, tail_len: %d, raw_data_len: %d\n", integer_num + 1, tail_len,
		   len);
	for (i = 0; i < integer_num; i++) {
		buf[2] = i;
		memcpy(&buf[3], data + i * 17, 17);
		G1_LOG_INF("#发送: %d/%d\n", i + 1, integer_num + 1);
		dump_hex("body", buf, sizeof(buf));
		((send_ret_fn_t)send)(buf, sizeof(buf));
	}
	n = i + 1;
	buf[2] = i;
	if (tail_len == 0) {
		/* PKCS#7 padding: a full block of 17 x 0x11 */
		memset(&buf[3], 17, 17);
		G1_LOG_INF("PKCS-7#发送: %d/%d\n", n, integer_num + 1);
		dump_hex("tail", buf, sizeof(buf));
	} else {
		memset(&buf[3] + tail_len, 17 - tail_len, 17 - tail_len);
		memcpy(&buf[3], data + integer_num * 17, tail_len);
		G1_LOG_INF("PKCS-7#发送tail: %d/%d\n", n, integer_num + 1);
		dump_hex("tail", buf, sizeof(buf));
	}
	G1_LOG_INF("total-size:%d\n", len);
	((send_ret_fn_t)send)(buf, sizeof(buf));
	return 0;
}

void simulator_ancs_calendar_schedule_trigger(void)
{
	struct ble_context *ctx = get_ble_context();

	G1_LOG_INF("enter\n");
	memset(&ctx->notif, 0, sizeof(ctx->notif));
	strncpy(ctx->notif.app_identifier, "com.apple.mobilecal", sizeof(ctx->notif.app_identifier));
	strncpy(ctx->notif.title, "日程1", sizeof(ctx->notif.title));
	strncpy(ctx->notif.message, "今天 16:35", sizeof(ctx->notif.message));
	strncpy(ctx->notif.display_name, "日历", sizeof(ctx->notif.display_name));
	dump_ancs("calendar-sched", &ctx->notif);
	k_sem_give(&ctx->ancs_get_attr_data_sem);
}

int start_ble_work_thread(struct ble_context *ctx)
{
	k_mutex_init(&k_mutex_20007f54);
	k_timer_init(&DashboardLockTimer, DashboardLockTimerExpiry_callback, NULL);
	k_thread_create(&ble_work_thread_data, ble_work_thread_stack,
			K_THREAD_STACK_SIZEOF(ble_work_thread_stack), ble_work_thread, ctx, NULL,
			NULL, BLE_WORK_THREAD_PRIORITY, 0, K_NO_WAIT);
	return 0;
}

void FUN_0007f50c(uint8_t *data, uint32_t len)
{
	struct ble_req_hdr hdr;

	struct ble_context *ctx = get_ble_context();

	hdr.cmd = data[0];
	hdr.f_1 = 1;
	hdr.len = len;
	ble_process_req_dispatch(ctx, &hdr, data);
}


/* old Ghidra name, kept as an alias until the callers in other modules are renamed */
extern __typeof__(spim_transfer) FUN_00019d14 __attribute__((alias("spim_transfer")));

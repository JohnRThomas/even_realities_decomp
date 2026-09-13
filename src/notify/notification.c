/*
 * Notification store: messages received from the phone (ANCS / NCS),
 * g_arrMsgContent bookkeeping and the BLE notification commands.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "notify.h"

extern volatile uint8_t DAT_20019a5c; /* g_arrMsgContent busy */

static char ios_mail_list[10][32] = {
	"com.apple.mail",
	"com.google.Gmail",
	"com.microsoft.Office.Outlook",
	"com.yahoo.Aerogram",
	"ch.protonmail.protonmail",
	"com.easilydo.mail",
	"Mailroom.Canary-iOS",
	"com.fastmail.FastMail",
	"com.apple.samsung",
};
static char android_mail_list[10][32] = {
	"com.google.mail",
	"com.google.android.gm",
	"com.microsoft.office.outlook",
	"com.yahoo.mobile.client.android.", /* truncated to 32 */
	"ch.protonmail.android",
	"com.easilydo.mail",
	"io.canarymail.android",
	"com.fastmail.app",
	"com.samsung.android.email.provid", /* truncated to 32 */
};
static char ios_calendar_list[4][32] = {
	"com.apple.mobilecal",
	"com.cron.calendar",
	"com.google.calendar",
};
static char android_calendar_list[5][32] = {
	"com.android.even_calendar",
	"com.google.android.calendar",
	"com.samsung.android.calendar",
	"com.cron.calendar",
};

struct notif_msg g_arrMsgContent[MSG_TOTAL_NUM];
uint8_t cur_message_show_state(void);
static char *ncs_buf;
static struct notif_msg push_msg_copy;

uint8_t g_msg_num_push;
uint8_t g_curShowMsgIdx;
uint8_t msg_show_state;

int send_notifi_app_white_list_app(struct ble_context *ctx, const char *app_id,
				   const char *name)
{
	uint8_t pkt[21] = {0};
	char json[320];
	uint16_t len;
	uint8_t total;
	uint8_t i;
	uint8_t retry;
	uint8_t n;
	uint8_t last;

	memset(json, 0, sizeof(json));
	len = sprintf(json, "{\"whitelist_app_add\": {\"%s\":  \"%s\",\"%s\": \"%s\"}}",
		      "app_identifier", app_id, "display_name", name);
	BLE_PRINTK("[csh_debug]:send_notifi_app_white_list app buf is: %s \n", json);

	total = len / 17;
	if (len % 17) {
		total++;
	}
	last = len - (total - 1) * 17;

	retry = 0;
	i = 0;
	while (i < total) {
		memset(&pkt[3], 0, 18);
		pkt[0] = 0xf6;
		n = (i < total - 1) ? 17 : last;
		pkt[1] = total;
		pkt[2] = i;
		memcpy(&pkt[3], &json[i * 17], n);
		if (ctx->write(pkt, n + 3) == 0) {
			i++;
			retry = 0;
		} else {
			retry++;
			if (retry == 6) {
				BLE_PRINTK("[csh_debug] failed to send whitelist !!\n");
				return 0;
			}
		}
		k_sleep(K_MSEC(5));
	}
	return 0;
}

#line 291
void send_whilelist_app_info_wrapper(struct notif_msg *msg)
{
	if (msg == NULL) {
		return;
	}
	const char *special[] = {
		"com.android.phone_missed",
		"com.android.phone_incall",
		"com.apple.mobilephone",
		"com.apple.mobilephone_missed",
		"com.apple.MobileSMS",
		"com.android.even_sms",
		"com.apple.mobilemail",
		"com.apple.mobilecal",
		"com.android.even_calendar",
	};
	uint8_t i;

	for (i = 0; i < 9; i++) {
		if (strncmp(special[i], msg->app_identifier, strlen(special[i])) == 0) {
			BLE_PRINTK("[%s-%d] special package nane:%s,need not send to app !\n",
				   __func__, __LINE__, msg->app_identifier);
			return;
		}
	}
	send_notifi_app_white_list_app(&get_dashboard_state()->ble_context,
				       msg->app_identifier, msg->display_name);
}

#line 321
int post_notification_cmd_response(struct GlassesState *state, uint8_t *data, volatile uint8_t *src,
				   uint8_t *hdr, uint8_t *arg, uint8_t *out, uint32_t len)
{
	struct notif_msg *msg;

	if (state == NULL || data == NULL || src == NULL || hdr == NULL || arg == NULL ||
	    out == NULL) {
		G1_LOG_WRN("input parm invalid !\n");
		return 0;
	}
	G1_LOG_INF("BLE_REQ_POST_NOTIFICATION_MSG source:%d\n", hdr[1]);
	if (hdr[1] == 4) {
		strncpy(state->schedule_notif->title, (char *)data + 0x54, 16);
		strncpy(state->schedule_notif->desc, (char *)data + 0x94, 0x96);
		state->schedule_notif->ts = 0;
		if (state->dashboard_mode == 0) {
			state->f_b0d = 1;
		}
		G1_LOG_INF("schedule_notif#title:%s, desc:%s, ts:%d, date:%s\n",
			   state->schedule_notif->title, state->schedule_notif->desc,
			   state->schedule_notif->ts, data + 0x194);
	} else {
		if (*(uint16_t *)&hdr[2] != sizeof(struct notif_msg)) {
			G1_LOG_ERR("[%s-%d] invliad  message len, data_len is %d\n\n", __FUNCTION__,
				   __LINE__, *(uint16_t *)&hdr[2]);
			return 0;
		}
		msg = (struct notif_msg *)(data + 4);
		if (msg->action > 1) {
			push_message(msg);
		} else {
			uint8_t ret = is_on_whitelist_by_identifier(msg->app_identifier);

			if (ret == 2 || ret == 3) {
				push_message(msg);
			} else if (ret == 1) {
				send_whilelist_app_info_wrapper(msg);
			}
		}
	}
	if (src[1] == 4) {
		G1_LOG_INF("ble:ANCS通知界面来新消息处理逻辑.\n");
	} else if (src[1] == 6) {
		G1_LOG_INF("ble:dashboard界面来新消息处理逻辑.\n");
	}
	memcpy(out, "Good", 5);
	return 5;
}

#line 386
void post_notification_cmd_process(struct ble_context *ctx, uint8_t *req, uint8_t *data)
{
	uint8_t resp[128];
	uint8_t *tx;
	struct notif_msg *msg;
	int ret;

	if (ctx == NULL || req == NULL || data == NULL) {
		G1_LOG_WRN("input param invalid !\n");
		return;
	}
	tx = ctx->tx_buf;
	msg = (struct notif_msg *)&tx[4];
	uint8_t rsp[20] = {0};

	rsp[0] = req[0];
	tx[0] = req[0];
	tx[1] = req[1];
	ctx->tx_len = *(uint16_t *)&tx[2] + 4;
	if (tx[1] == 2 || tx[1] == 4) {
		*(uint16_t *)&tx[2] = sizeof(struct notif_msg);
		memcpy(msg, data, sizeof(struct notif_msg));
		G1_LOG_INF("ANCS接收完成,封装头和数据,即将发送给master芯片,source:%d\n\n", tx[1]);
		FUN_00019d14(ctx, resp, 8);
		return;
	}
	if (ncs_buf == NULL) {
		ncs_buf = malloc(0x800);
		if (ncs_buf == NULL) {
			BLE_PRINTK("[%s-%d] malloc failed !!\n", __FUNCTION__, __LINE__);
		} else {
			memset(ncs_buf, 0, 0x800);
		}
	}
	if (ncs_buf != NULL) {
		ret = parse_receiver_msg_pack_pkcs7((uint8_t *)ncs_buf, data, tx[2]);
		rsp[1] = ret;
		rsp[2] = data[1];
		if (ret == PKCS7_PACK_DONE) {
			parse_ncs_notification(ncs_buf, msg);
			G1_LOG_INF("ncs data receive okay !\n\n");
			*(uint16_t *)&tx[2] = sizeof(struct notif_msg);
			FUN_00019d14(ctx, resp, 8);
			rsp[1] = PKCS7_PACK_DONE;
			free(ncs_buf);
			ncs_buf = NULL;
		}
	}
	ctx->write(rsp, 0x14);
}

int get_notification_counts_cmd_response(struct GlassesState *state, uint8_t *out)
{
	if (state == NULL || out == NULL) {
		G1_LOG_WRN("input param is error !\n");
		return 0;
	}
	*out = state->unread_msg_num;
	G1_LOG_INF("[csh_debug]unread_msg_num is: %d\n", *out);
	return 1;
}

void get_notification_counts_cmd_process(struct ble_context *ctx, uint8_t *buf, uint8_t *rsp)
{
	FUN_0007f4c6(ctx, buf, 1, 0x1e);
	rsp[1] = 0xc9;
	rsp[2] = *buf;
	G1_LOG_INF("BLE_REQ_GET_ESB_CHANNEL: %d\n", rsp[2]);
	ctx->write(rsp, 0x14);
}

void normal_g_arrMsgContent(void)
{
	for (int i = 0; i < MSG_NORMAL_NUM; i++) {
		BLE_PRINTK("normal g_arrMsgContent[%d].uidTail is %d %d recvTime %d\n", i,
			   g_arrMsgContent[i].uid, g_arrMsgContent[i].start_show_time,
			   g_arrMsgContent[i].recv_time);
	}
}

void push_g_arrMsgContent(void)
{
	for (int i = MSG_NORMAL_NUM; i < MSG_TOTAL_NUM; i++) {
		BLE_PRINTK("PUSH: g_arrMsgContent[%d].uidTail is %d push %d \n", i,
			   g_arrMsgContent[i].uid, g_arrMsgContent[i].recv_time);
	}
}

struct notif_msg *get_push_message_copy(void)
{
	struct notif_msg *m = &g_arrMsgContent[MSG_NORMAL_NUM];

	if (m->app_identifier[0] == 0) {
		return NULL;
	}
	if (m->f_0e != 0) {
		return NULL;
	}
	if (m->f_0d > 3) {
		return NULL;
	}
	m->pos = 10;
	memcpy(&push_msg_copy, m, sizeof(push_msg_copy));
	return &push_msg_copy;
}

struct notif_msg *get_push_message(void)
{
	struct notif_msg *m = &g_arrMsgContent[MSG_NORMAL_NUM];

	if (m->app_identifier[0] == 0) {
		return NULL;
	}
	if (m->f_0e != 0) {
		return NULL;
	}
	if (m->f_0d > 3) {
		return NULL;
	}
	m->pos = 10;
	return m;
}

void FUN_00035204(int idx, uint8_t val)
{
	g_arrMsgContent[idx].f_0d = val;
}

uint8_t FUN_00035218(int idx)
{
	return g_arrMsgContent[idx].f_0d;
}

struct notif_msg *find_push_message_by_uid(uint32_t uid)
{
	for (int i = MSG_NORMAL_NUM; i < MSG_TOTAL_NUM; i++) {
		if (g_arrMsgContent[i].app_identifier[0] && g_arrMsgContent[i].f_0e == 0 &&
		    g_arrMsgContent[i].uid == uid) {
			return &g_arrMsgContent[i];
		}
	}
	return NULL;
}

struct notif_msg *get_message_by_index(int idx)
{
	return &g_arrMsgContent[idx];
}

void clear_all_messages(void)
{
	DAT_20019a5c = 1;
	for (int i = 0; i < MSG_TOTAL_NUM; i++) {
		memset(&g_arrMsgContent[i], 0, sizeof(g_arrMsgContent[i]));
	}
	g_msg_num_push = MSG_NORMAL_NUM;
	g_curShowMsgIdx = 0;
	get_dashboard_state()->unread_msg_num = 0;
	normal_g_arrMsgContent();
	push_g_arrMsgContent();
	DAT_20019a5c = 0;
}

uint8_t find_last_read_message(void)
{
	int i;

	for (i = MSG_NORMAL_NUM - 1; i >= 0; i--) {
		if (!g_arrMsgContent[i].read) {
			continue;
		}
		g_curShowMsgIdx = i;
		return i;
	}
	g_curShowMsgIdx = 0;
	return 0xff;
}

uint8_t count_messages(void)
{
	uint8_t i;

	for (i = 0; i < MSG_NORMAL_NUM; i++) {
		if (g_arrMsgContent[i].app_identifier[0] == 0) {
			break;
		}
	}
	return i;
}

uint8_t count_unread_messages(void)
{
	uint8_t unread = 0;
	bool found = false;
	int i;
	uint8_t last = 0;
	uint8_t count;

	for (i = 0; i < MSG_NORMAL_NUM; i++) {
		count = i;
		if (g_arrMsgContent[i].app_identifier[0] == 0) {
			if (found) {
				g_curShowMsgIdx = last;
			}
			if (unread == 0) {
				goto none;
			}
			return count - unread;
		}
		if (g_arrMsgContent[i].read) {
			unread++;
			found = g_arrMsgContent[i].read;
		}
		if (g_arrMsgContent[i].read) {
			last = count;
		}
	}
	count = i;
	if (found) {
		g_curShowMsgIdx = last;
	}
	if (unread == 0) {
none:
		if (count != 0) {
			g_curShowMsgIdx = 0;
		} else {
			g_curShowMsgIdx = 0xff;
		}
	}
	return count - unread;
}

void clear_timeout_message(int force)
{
	int i = 0;
	int offset = 0;
	int j;
	int has_msg = 0;
	int found = 0;

	DAT_20019a5c = 1;
	while (i < MSG_NORMAL_NUM) {
		struct notif_msg *m = &g_arrMsgContent[i];
		uint32_t recv = m->recv_time;
		uint32_t show = m->start_show_time;

		/*
		 * Every `break` in the inner switch lands in the shared tail after the
		 * `if (0)` block, which recomputes j = offset + i and stops the loop
		 * when j > MSG_NORMAL_NUM - 1 (the early j checks therefore end the
		 * loop exactly as before).  `move` leaves the outer switch with the
		 * destination slot's first app_identifier byte in `found`.
		 */
		switch (0) {
		default:
			switch (0) {
			default:
				if (recv != 0) {
					has_msg = 1;
				}
				if (recv == 0) {
					if (has_msg) {
						if (offset == 0) {
							offset = 1;
						} else if (!m->read) {
							j = i + offset;
							if (j > MSG_NORMAL_NUM - 1) {
								goto tailx;
							}
							goto move;
						} else {
							goto read_arm;
						}
					}
				}
				if (show == 0) {
					if (offset == 0) {
						i++;
						continue;
					}
					goto shift;
				}
				if (m->read) {
read_arm:
					if (force) {
						if (show == 0) {
							goto shift;
						}
						memset(&g_arrMsgContent[i], 0, sizeof(struct notif_msg));
						offset++;
					} else if (show == 0) {
						break;
					} else if (FUN_00080732() > g_arrMsgContent[i].start_show_time + get_dashboard_state()->msg_timeout) {
						memset(&g_arrMsgContent[i], 0, sizeof(struct notif_msg));
						offset++;
					}
				} else if (recv != 0 && FUN_00080732() > g_arrMsgContent[i].start_show_time + 5) {
					memset(&g_arrMsgContent[i], 0, sizeof(struct notif_msg));
					offset++;
				}
				break;
			}
			if (0) {
shift:
				if (offset == 0) {
					i++;
					continue;
				}
				j = i + offset;
				if (j > MSG_NORMAL_NUM - 1) {
					goto tailx;
				}
				if (recv != 0) {
					i++;
					continue;
				}
move:
				found = g_arrMsgContent[j].app_identifier[0];
				break;
			}
tailx:
			j = offset + i;
			if (j > MSG_NORMAL_NUM - 1) {
				i = MSG_NORMAL_NUM;
				continue;
			}
			if (g_arrMsgContent[i].recv_time != 0 || offset == 0) {
				i++;
				continue;
			}
			goto move;
		}
		if (found) {
			memcpy(&g_arrMsgContent[i], &g_arrMsgContent[j], sizeof(struct notif_msg));
			memset(&g_arrMsgContent[j], 0, sizeof(struct notif_msg));
			G1_LOG_ERR("######clear_timeout_message copy data from %d to  i %d\n", j, i);
			i++;
			continue;
		}
		offset++;
		goto next;
next:;
	}
	get_dashboard_state()->unread_msg_num = count_unread_messages();
	DAT_20019a5c = 0;
}
int message_uid_exists(uint32_t num, uint32_t uid)
{
	for (uint8_t i = 0; i < num; i++) {
		if (g_arrMsgContent[i].app_identifier[0] && g_arrMsgContent[i].uid == uid) {
			return 1;
		}
	}
	return 0;
}

#line 1059
void confirm_message(uint32_t uid)
{
	struct notif_msg *pending = &g_arrMsgContent[MSG_NORMAL_NUM];
	uint8_t action = pending->action;
	int count;
	uint8_t i;

	if (pending->app_identifier[0] == 0 || pending->uid != uid || pending->f_0d != 4) {
		return;
	}
	if (get_dashboard_state()->is_master == 1 && action == 0 &&
	    message_uid_exists(MSG_NORMAL_NUM, uid)) {
		G1_LOG_ERR("add found same message, uidtail %d\n", uid);
		memset(pending, 0, sizeof(*pending));
		return;
	}
	DAT_20019a5c = 1;
	if (get_dashboard_state()->dashboard_mode != 4) {
		clear_timeout_message(0);
	}
	if (get_dashboard_state()->f_10d6 && get_dashboard_state()->panel.imu_state != 1) {
		(void)*(volatile uint8_t *)&get_dashboard_state()->dashboard_mode;
	}
	count = count_messages();
	if (pending->action == 0) {
		if (count == MSG_NORMAL_NUM) {
			for (int j = 0; j < MSG_NORMAL_NUM - 1; j++) {
				memcpy(&g_arrMsgContent[j], &g_arrMsgContent[j + 1], sizeof(struct notif_msg));
				g_arrMsgContent[j].pos = j;
			}
			count = MSG_NORMAL_NUM - 1;
		}
		memcpy(&g_arrMsgContent[count], pending, sizeof(struct notif_msg));
		g_arrMsgContent[count].pos = count;
		if (g_arrMsgContent[count].recv_time == 0) {
			g_arrMsgContent[count].recv_time = FUN_00080732();
		}
		g_arrMsgContent[count].f_0e = 1;
		if (g_arrMsgContent[count].start_show_time != 0) {
			g_arrMsgContent[count].start_show_time = FUN_00080732();
		}
	} else if (pending->action == 2) {
		if (count) {
			bool found = false;

			for (i = 0; i < count; i++) {
				if (g_arrMsgContent[i].uid == pending->uid || found) {
					memcpy(&g_arrMsgContent[i], &g_arrMsgContent[i + 1],
					       sizeof(struct notif_msg));
					found = true;
					g_arrMsgContent[i].pos = i;
				}
			}
			if (found) {
				memset(&g_arrMsgContent[count - 1], 0, sizeof(struct notif_msg));
			}
		}
	} else if (pending->action == 1 && count) {
		for (i = 0; i < count; i++) {
			if (g_arrMsgContent[i].uid == pending->uid) {
				memcpy(&g_arrMsgContent[i], pending, sizeof(struct notif_msg));
				break;
			}
		}
	}
	memset(pending, 0, sizeof(*pending));

	for (i = MSG_NORMAL_NUM; i < g_msg_num_push; i++) {
		if (g_arrMsgContent[i + 1].app_identifier[0] == 0) {
			break;
		}
		memcpy(&g_arrMsgContent[i], &g_arrMsgContent[i + 1], sizeof(struct notif_msg));
		g_arrMsgContent[i].pos = i;
		g_arrMsgContent[i].f_0d = 0;
	}
	if (g_msg_num_push > MSG_NORMAL_NUM) {
		g_msg_num_push--;
	}
	memset(&g_arrMsgContent[g_msg_num_push], 0, sizeof(struct notif_msg));

	if (get_dashboard_state()->dashboard_mode != 4) {
		clear_timeout_message(0);
	} else {
		get_dashboard_state()->unread_msg_num = count_unread_messages();
	}
	if (action == 0) {
		uint8_t unread = find_last_read_message();

		if (get_dashboard_state()->dashboard_mode == 4) {
			if (unread != 0xff) {
				FUN_0002dd98();
			}
		} else if (is_in_box() != 1) {
			if (get_dashboard_state()->dashboard_mode == 0 ||
			    (get_dashboard_state()->f_10d6 && get_dashboard_state()->dashboard_mode == 6)) {
				if (cur_message_show_state() != 1) {
					msg_show_state = 1;
				}
			}
		}
	}
	if (!msg_busy) {
		normal_g_arrMsgContent();
		push_g_arrMsgContent();
	}
	DAT_20019a5c = 0;
	if (get_dashboard_state()->f_10d6 && get_dashboard_state()->panel.imu_state != 1) {
		(void)*(volatile uint8_t *)&get_dashboard_state()->dashboard_mode;
	}
}

#line 855
uint8_t push_message(struct notif_msg *msg)
{
	uint8_t pos;

	if (msg == NULL) {
		BLE_PRINTK("[%s-%d] message is NULL \n", __FUNCTION__, __LINE__);
		return 0;
	}
	if (msg->action == 0) {
		if (message_uid_exists(MSG_TOTAL_NUM, msg->uid)) {
			G1_LOG_ERR("slave add found same message, uidtail %d\n", msg->uid);
			return 0;
		}
	} else {
		if (!message_uid_exists(MSG_TOTAL_NUM, msg->uid)) {
			G1_LOG_ERR("can not found same message, uidtail %d\n", msg->uid);
			return 0;
		}
	}
	msg->read = 0;
	pos = g_msg_num_push;
	if (pos < MSG_TOTAL_NUM) {
		msg->f_0e = 0;
		msg->f_0d = 0;
		msg->pos = pos;
		memcpy(&g_arrMsgContent[pos], msg, sizeof(*msg));
		G1_LOG_ERR("update pos to %d, uidtail %d message->startShowTime %d action %d\n", pos, msg->uid, msg->start_show_time, msg->action);
		g_msg_num_push++;
	} else {
		G1_LOG_ERR("update pos to %d, uidtail %d message->startShowTime %d\n", MSG_TOTAL_NUM - 1, msg->uid, msg->start_show_time);
		for (int i = MSG_NORMAL_NUM; i < MSG_TOTAL_NUM - 1; i++) {
			if (g_arrMsgContent[i].f_0d == 0) {
				memcpy(&g_arrMsgContent[i], &g_arrMsgContent[i + 1], sizeof(*msg));
				g_arrMsgContent[i].pos = i;
				if (g_arrMsgContent[i].f_0e == 0) {
					msg->f_0d = 0;
				}
			}
		}
		memcpy(&g_arrMsgContent[MSG_TOTAL_NUM - 1], msg, sizeof(*msg));
		g_arrMsgContent[MSG_TOTAL_NUM - 1].pos = MSG_TOTAL_NUM - 1;
		g_arrMsgContent[MSG_TOTAL_NUM - 1].f_0d = 0;
		g_arrMsgContent[MSG_TOTAL_NUM - 1].f_0e = 0;
		g_msg_num_push = MSG_TOTAL_NUM;
	}
	BLE_PRINTK("[csh_debug_msg]push_message g_msg_num_push is %d \n", g_msg_num_push);
	return g_msg_num_push;
}

#line 370
uint8_t g_arrMsgContent_count(void)
{
	uint8_t num = get_dashboard_state()->unread_msg_num;

	if (num != 0) {
		int idx = num - 1;

		if (g_arrMsgContent[idx].start_show_time != 0) {
			clear_timeout_message(1);
			if (idx == 0) {
				g_curShowMsgIdx = 0;
			} else {
				g_curShowMsgIdx = num - 2;
			}
			BLE_PRINTK("[csh_debug_msg]msg_count_dec unread_msg_num is %d \n", idx);
			get_dashboard_state()->unread_msg_num = count_unread_messages();
		}
	}
	return get_dashboard_state()->unread_msg_num;
}

#line 967
uint8_t pull_message(struct notif_msg **msg)
{
	if (msg == NULL) {
		G1_LOG_ERR("[%s-%d] message is NULL \n\n", __FUNCTION__, __LINE__);
		return MSG_NORMAL_NUM;
	}
	if (get_dashboard_state()->unread_msg_num > MSG_NORMAL_NUM) {
		BLE_PRINTK("exception handle, GLOBAL->master_sync_pkg.panel_data_pkg.unread_msg_num is %d \n",
			   get_dashboard_state()->unread_msg_num);
		return MSG_NORMAL_NUM;
	}
	*msg = &g_arrMsgContent[g_curShowMsgIdx];
	BLE_PRINTK("[csh_debug_msg]g_curShowMsgIdx is %d \n", g_curShowMsgIdx);
	return g_curShowMsgIdx;
}

uint8_t get_cur_show_msg_idx(void)
{
	return g_curShowMsgIdx;
}

void FUN_000359d8(void)
{
	g_arrMsgContent[g_curShowMsgIdx].state = 1;
}

void mark_cur_message_read(void)
{
	struct notif_msg *m = &g_arrMsgContent[g_curShowMsgIdx];

	if (m->recv_time != 0 && !m->read) {
		uint8_t idx;

		get_dashboard_state()->unread_msg_num = count_unread_messages();
		idx = 0;
		if (get_dashboard_state()->unread_msg_num) {
			idx = get_dashboard_state()->unread_msg_num - 1;
		}
		g_curShowMsgIdx = idx;
		g_arrMsgContent[idx].start_show_time = FUN_00080732();
		g_arrMsgContent[g_curShowMsgIdx].read = 1;
		get_dashboard_state()->unread_msg_num = count_unread_messages();
	}
	normal_g_arrMsgContent();
}

uint8_t get_msg_show_state(void)
{
	return msg_show_state;
}

void expire_cur_message(void)
{
	if (g_arrMsgContent[g_curShowMsgIdx].start_show_time != 0) {
		g_arrMsgContent[g_curShowMsgIdx].start_show_time -=
			get_dashboard_state()->msg_timeout;
	}
}

void set_msg_show_state(uint8_t val)
{
	msg_show_state = val;
	if (val == 0) {
		expire_cur_message();
	}
}

uint8_t cur_message_show_state(void)
{
	uint8_t ret;

	if (get_dashboard_state()->f_10d6 && get_dashboard_state()->is_master == 1) {
		set_date(get_dashboard_state()->dashboard_ts->ts);
	}
	ret = g_arrMsgContent[g_curShowMsgIdx].read;
	if (ret) {
		ret = 0;
		if (g_arrMsgContent[g_curShowMsgIdx].start_show_time != 0) {
			if (FUN_00080732() > g_arrMsgContent[g_curShowMsgIdx].start_show_time +
						     get_dashboard_state()->msg_timeout) {
				ret = 2;
			} else {
				ret = 1;
			}
		}
	}
	if (g_arrMsgContent[g_curShowMsgIdx].start_show_time > FUN_00080732()) {
		ret = 3;
	}
	return ret;
}

#line 1170
uint8_t latest_message_show_state(void)
{
	uint8_t ret = 0;

	if (g_arrMsgContent[get_dashboard_state()->unread_msg_num - 1].recv_time != 0) {
		if (FUN_00080732() > g_arrMsgContent[get_dashboard_state()->unread_msg_num - 1].recv_time +
					     get_dashboard_state()->msg_timeout) {
			ret = 2;
		} else {
			ret = 1;
		}
	}
	return ret;
}

bool is_message_showing(void)
{
	if (count_messages() == 0) {
		return false;
	}
	if (msg_show_state == 5 && cur_message_show_state() == 1) {
		return true;
	}
	if (msg_show_state == 3) {
		return latest_message_show_state() == 1;
	}
	return false;
}

uint8_t parse_message_type(int idx)
{
	const char *id = g_arrMsgContent[idx].app_identifier;
	char (*list)[32];
	uint8_t len;

	if (strncmp("com.android.phone_missed", id, 24) == 0 ||
	    strncmp("com.apple.mobilephone_missed", id, 28) == 0) {
		return 1;
	}
	if (strncmp("com.android.phone_incall", id, 24) == 0 ||
	    strncmp("com.apple.mobilephone", id, 21) == 0) {
		return 2;
	}
	if (strncmp("com.apple.MobileSMS", id, 19) == 0 ||
	    strncmp("com.android.even_sms", id, 20) == 0) {
		return 0;
	}
	for (list = get_dashboard_state()->phone_is_ios ? ios_mail_list : android_mail_list;
	     (*list)[0] != 0; list++) {
		len = strlen(*list);
		if (len > 31) {
			len = 31;
		}
		if (strncmp(*list, id, len) == 0) {
			return 3;
		}
	}
	for (list = get_dashboard_state()->phone_is_ios ? ios_calendar_list : android_calendar_list;
	     (*list)[0] != 0; list++) {
		len = strlen(*list);
		if (len > 31) {
			len = 31;
		}
		if (strncmp(*list, id, len) == 0) {
			return 4;
		}
	}
	return 5;
}

void app_list_init(void)
{
	g_msg_num_push = MSG_NORMAL_NUM;
	g_curShowMsgIdx = 0;
	msg_show_state = 0;
	expire_cur_message();
	memset(g_arrMsgContent, 0, sizeof(g_arrMsgContent));
	load_app_white_list_from_flash();
}

/* Old placeholder names, still used by other modules (renamed 2026-10-21, byte-neutral). */
extern __typeof__(get_push_message_copy) FUN_0003519c __attribute__((alias("get_push_message_copy")));
extern __typeof__(get_push_message) FUN_000351d8 __attribute__((alias("get_push_message")));
extern __typeof__(find_push_message_by_uid) FUN_0003522c __attribute__((alias("find_push_message_by_uid")));
extern __typeof__(get_message_by_index) FUN_00035260 __attribute__((alias("get_message_by_index")));
extern __typeof__(clear_all_messages) FUN_00035270 __attribute__((alias("clear_all_messages")));
extern __typeof__(count_messages) FUN_000352f4 __attribute__((alias("count_messages")));
extern __typeof__(count_unread_messages) FUN_00035310 __attribute__((alias("count_unread_messages")));
extern __typeof__(get_cur_show_msg_idx) FUN_000359cc __attribute__((alias("get_cur_show_msg_idx")));
extern __typeof__(mark_cur_message_read) FUN_000359fc __attribute__((alias("mark_cur_message_read")));
extern __typeof__(get_msg_show_state) FUN_00035a78 __attribute__((alias("get_msg_show_state")));
extern __typeof__(expire_cur_message) FUN_00035a84 __attribute__((alias("expire_cur_message")));
extern __typeof__(set_msg_show_state) FUN_00035abc __attribute__((alias("set_msg_show_state")));
extern __typeof__(cur_message_show_state) FUN_00035acc __attribute__((alias("cur_message_show_state")));
extern __typeof__(is_message_showing) FUN_00035ea4 __attribute__((alias("is_message_showing")));

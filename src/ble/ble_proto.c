/*
 * BLE application protocol: debug channel, pkcs7 packet reassembly, request
 * handlers / dispatch and the BLE work thread.
 * Reconstructed from the G1 v1.63 app core (original file name unknown).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>
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
#include "ble_ancs.h"
#include "../dashboard/dashboard.h"
#include "../display/display_thread.h"
#include "../display/proxy_thread.h"
#include "../gui/gui.h"
#include "../imu/imu_fusion.h"
#include "../main.h"
#include "../nfc/nfc_wlc.h"
#include "../notify/notify.h"
#include "../notify/whitelist.h"
#include "../panel_display/panel.h"
#include "../production_test/production_test.h"
#include "../sensors_audio/sensors_audio.h"
#include "../storage/storage.h"
#include "../threads/threads.h"
#include "../ui/ui.h"
#include "../utils/burial_point.h"

BUILD_ASSERT(sizeof(struct schedule_item) == 0xa4);
BUILD_ASSERT(sizeof(struct stock_item) == 0x7f2);
BUILD_ASSERT(sizeof(struct news_item) == 0x159);
BUILD_ASSERT(sizeof(struct teleprompter_info) == 0x217);
BUILD_ASSERT(sizeof(struct nav_info) == 0xf5);
BUILD_ASSERT(sizeof(struct translate_buf) == 0x1e8);
BUILD_ASSERT(sizeof(struct quicknote_item) == 0x143);
BUILD_ASSERT(offsetof(struct dashboard_ts_context, disp_mode) == 0x65);
BUILD_ASSERT(offsetof(struct dashboard_ts_context, dashboard_hold) == 0x72);
uint8_t nav_overview_map_buf[0x1210];               /* navigation overview map */
uint8_t panoramic_map_buf[PANORAMIC_MAP_SIZE];   /* panoramic map / citywalk data */

/* .bss, 2-byte aligned */
static volatile uint16_t sched_cnt;       /* 0x200100d0 */
static volatile uint16_t sched_total;     /* 0x200100ce */
static volatile uint16_t sched_len;       /* 0x200100cc */
struct stock_item stock_items[4];
static volatile uint16_t stock_cnt;       /* 0x2000e102 */
static volatile uint16_t stock_total;     /* 0x2000e100 */
static volatile uint16_t stock_len;       /* 0x2000e0fe */
static volatile uint16_t news_cnt;        /* 0x2000e0fc */
static volatile uint16_t news_total;      /* 0x2000e0fa */
static volatile uint16_t news_len;        /* 0x2000e0f8 */
static volatile uint16_t citywalk_len;    /* 0x2000e0f6 */
volatile uint16_t multi_packet_len;
volatile uint16_t multi_packet_cnt;
volatile uint16_t multi_packet_total;
static volatile uint16_t tp_len;          /* 0x2000e0ee */
static volatile uint16_t pano_len;        /* 0x2000e0ec */
static volatile uint16_t pano_cnt;        /* 0x2000e0ea */
static volatile uint16_t pano_total;      /* 0x2000e0e8 */
static volatile uint16_t qn_len;          /* 0x2000e0e6 */
static volatile uint16_t qn_cnt;          /* 0x2000e0e4 */
static volatile uint16_t qn_total;        /* 0x2000e0e2 */
volatile uint16_t nav_last_x;      /* 0x2000e0e0 */
static volatile uint16_t nav_last_y;      /* 0x2000e0de */
static uint16_t pack_offset;     /* 0x2000e0dc */
static uint16_t msg_pack_offset; /* 0x2000e0da */
static uint16_t msg_pack_id;     /* 0x2000e0d8 */

/*
 * .bss, 4-byte aligned (reverse definition order in the image):
 * 0x20007ef4 current_conn ... 0x20007f54 nav_map_mutex
 */
struct k_mutex nav_map_mutex;
atomic_t dashboard_lock_requested;
atomic_t dashboard_lock_reported;
int nav_app_sync_count;
int tp_app_sync_count;
static int dmic_send_count;      /* 0x20007f40 */
static int dmic_pkt_count;       /* 0x20007f3c */
static int send_fail_count;      /* 0x20007f38 */
static int dashboard_send_fail_count;   /* 0x20007f34 */
int BLE_DEBUG;
int debug_pending;               /* 0x20007f2c (not static: the shipped code keeps its store after the rx_bufs[2] stores) */
static struct k_msgq debug_msgq; /* 0x20007ef8 */

/* .data (put_req) */
static volatile uint8_t citywalk_reload = 1; /* 0x20003005 */
uint8_t BIT_MAP_CHUNK_ID = 0xff;    /* 0x20003004 */
/* citywalk bitmaps inside panoramic_map_buf, referenced by name from DashBoard_Reflash */
__asm__(".global citywalk_canvas_bitmap\n.set citywalk_canvas_bitmap, panoramic_map_buf + 0x1980\n"
	".global citywalk_arrow_full\n.set citywalk_arrow_full, panoramic_map_buf + 0x2d28\n"
	".global citywalk_arrow_dual\n.set citywalk_arrow_dual, panoramic_map_buf + 0x3278\n"
	".global panoramic_map_mask\n.set panoramic_map_mask, panoramic_map_buf + 0x2068\n");
struct schedule_item schedule_items[8];
static uint8_t sched_buf[0x538];            /* 0x20011ff7 */
static int sched_retry;                     /* never set: the single-packet schedule parse runs once */
static uint8_t stock_buf[0x812];            /* 0x200117e5 */
struct news_item news_items[4];
static uint8_t news_buf[0x161];             /* 0x20011120 */
static volatile uint8_t citywalk_last_disp_mode;
static volatile uint8_t citywalk_bg_ready;
volatile uint8_t citywalk_canvas_valid;          /* citywalk map valid (read by DashBoard_Reflash) */
static struct teleprompter_info tp_buf;     /* 0x20010f06 */
uint8_t tp_scroll_pending;
static struct qn_title qn_title_buf;        /* 0x20010edc */
static uint8_t qn_text_buf[0x119];          /* 0x20010dc3 */
static volatile uint8_t qn_num;             /* 0x20010dc2 */
uint8_t nav_overview_map_ready;
volatile uint8_t nav_panoramic_map_ready;
uint8_t nav_text_updated;
uint8_t nav_overview_map_updated;
volatile uint8_t nav_panoramic_map_updated;
volatile uint8_t nav_pos_updated;
static uint8_t dmic_seq;         /* 0x20010dbb */
static uint8_t pack_cmd;         /* 0x20010dba */
static uint8_t msg_pack_cmd;     /* 0x20010db9 */
static uint8_t debug_buf[DEBUG_MSG_SIZE]; /* 0x20010cf1 */
static uint8_t text_packet_buf[0x158];         /* translate / quick note packet buffer */

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
#define QN_ITEM(n) (globle->quicknote->notes[n])

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

/* response of a post request: cmd, u16 length, seq, sub command, status, ... */
#define POST_RESP_LEN(r) (*(uint16_t *)&(r)[1])

static K_THREAD_STACK_DEFINE(ble_work_thread_stack, BLE_WORK_THREAD_STACK_SIZE);
static struct k_thread ble_work_thread_data;
struct k_timer DashboardLockTimer;

/*
 * Definition order, linkage and the forward declarations below are reconstructed from the shipped
 * layout, not from the program logic.  GCC emits the __func__ strings in reverse cgraph analysis order
 * (public functions in definition order, each followed by its not yet analysed static callees) and the
 * functions in reverse ipa_reverse_postorder of the call graph (callees first, edges rebuilt by the
 * early local passes in that same order).  The shipped __func__ order
 *   parse_pack, parse_msg, send_dmic, deal_event, dispatch, put, get, post, report,
 *   subcontracing, mobile_send, simulator, spec_hook, ble_work_thread, DashboardLockTimer
 * needs get/put (reached from dispatch), ble_work_thread and the timer callback (reached from
 * start_ble_work_thread) to be static, and the text order then fixes where everything is defined.
 */
static void DashboardLockTimerExpiry_callback(struct k_timer *timer);
static void ble_process_get_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
static __attribute__((noclone)) void ble_process_put_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data, uint32_t n);
static inline uint16_t ble_get_u16(const uint8_t *p);
static int ble_process_post_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
static int ble_process_report_response(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
static void ble_work_thread(void *p1, void *p2, void *p3);
static int set_esb_up_recv_state(uint8_t a, uint8_t b);

int save_esb_snapshot(const void *data, size_t len, uint8_t arg, int sel)
{
	uint8_t *buf;

	if (sel) {
		buf = get_dashboard_state()->esb_up_snapshot;
	} else {
		buf = get_dashboard_state()->esb_down_snapshot;
	}
	memcpy(buf, data, len);
	buf[0x200] = arg;
	return 0;
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
static __attribute__((noclone)) void ble_process_put_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data, uint32_t n) /* n: never read, reused as the nav time/road scan index; noclone: static, IPA would drop it */
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
	uint16_t dlen, hlen;

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
		dlen = *(uint16_t *)&data[1];
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == dlen && data[4] <= 2) {
			switch (data[4]) {
			case 1:
				if (get_dashboard_state()->imu.base != 0) {
					G1_LOG_WRN("ble clear user horiz pitch\n");
					get_dashboard_state()->imu.base = 0;
					get_dashboard_state()->dashboard_cmd = 0;
					k_sem_give(&get_dashboard_state()->dashboard_position_sem);
				}
				break;
			case 2:
				if (data[5] == 1) {
					get_dashboard_state()->horiz_pitch_cfg[0] = 1;
					get_dashboard_state()->horiz_pitch_cfg[1] = data[6];
					if (get_dashboard_state()->horiz_pitch_cfg[1] == 1) {
						G1_LOG_WRN("ble set user horiz pitch:%d\n", imu_pitch_x100);
						{
							struct GlassesState *gs = get_dashboard_state();

							gs->imu.base = imu_pitch_x100;
						}
						get_dashboard_state()->dashboard_cmd = 0;
						k_sem_give(&get_dashboard_state()->dashboard_position_sem);
					}
					globle->esb_down_id = data[3];
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
			resp[5] = get_dashboard_startup_mode();
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
		uint16_t total, idx;
		case DASHBOARD_SUB_TIME_WEATHER: {
			int64_t ms_ts = ((struct put_time_sync *)data)->ms_ts;
			uint32_t sec_ts;
			struct bp_date date;

			set_wall_clock_ms(ms_ts);
			sec_ts = ((struct put_time_sync *)data)->sec_ts;
			G1_LOG_INF("origin ms timestamp = %lld,origin second timestamp = %d\n", ms_ts,
				   sec_ts);
			globle->dashboard_ts->weather_icon = data[0x11];
			globle->dashboard_ts->temperature = data[0x12];
			globle->dashboard_ts->ts = sec_ts;
			globle->dashboard_ts->ms_ts = ms_ts;
			memset(&date, 0, sizeof(date));
			init_burial_point_date(sec_ts, &date);
			G1_LOG_INF("date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n", sec_ts, date.year,
				   date.month, date.day, date.hour, date.minute, date.second);
			accumulate_elapsed_seconds((uint32_t *)(void *)globle->dashboard_ts, 0, 1);
			globle->dashboard_ts->temp_unit = data[0x13];
			globle->dashboard_ts->time_disp_mode = data[0x14];
			if (data_len > 0x15 && globle->dashboard_ts->date_format != data[0x15]) {
				globle->dashboard_ts->date_format = data[0x15];
				storage_commit_request(0, 0);
			}
			G1_LOG_INF("time display format :%s hours, temperature display format %s \n",
				   globle->dashboard_ts->time_disp_mode ? "12" : "24",
				   globle->dashboard_ts->time_disp_mode ? "Fahrenheit" : "centigrade degree");
			save_dashboard_ts_to_ncs_mem();
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
			    globle->dashboard_ts->disp_mode != citywalk_last_disp_mode) {
				citywalk_last_disp_mode = globle->dashboard_ts->disp_mode;
				get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
				citywalk_reload = 1;
				citywalk_bg_ready = 0;
			}
			G1_LOG_INF("Dashboard display mode :%d custom display Area value : %d\n",
				   globle->dashboard_ts->disp_mode, globle->dashboard_ts->area);
			save_dashboard_ts_to_ncs_mem();
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
					unsigned int num;

					num = data[0xc];
					G1_LOG_INF("schedule total record num = %d\n", num);
					/* Single-pass parse loop (sched_retry is always 0, see
					 * agent_notes/ble_process_put_req.md attempt 12): the oversize
					 * test is then a loop exit, which keeps p computed before it. */
					do {
					p = &data[0xd];
					if (num > 8) {
						G1_LOG_ERR("schedule data oversize!!!!\n");
						return;
					}
					memset(schedule_items, 0, sizeof(schedule_items));
					item = schedule_items;
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
					} while (sched_retry);
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
					unsigned int num;

					num = *(volatile uint8_t *)&sched_buf[3];
					G1_LOG_INF("schedule record num = %d\n", num);
					if (num > 8) {
						G1_LOG_ERR("schedule data oversize!!!!\n");
						return;
					}
					memset(schedule_items, 0, sizeof(schedule_items));
					p = &sched_buf[4];
					char *loc = schedule_items[0].location;
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
						memset(&stock_items[num - 1], 0, sizeof(stock_items[0]));
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
							st = &stock_items[num - 1];
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
						memset(&stock_items[num - 1], 0, sizeof(stock_items[0]));
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
							st = &stock_items[num - 1];
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
						memset(&news_items[num - 1], 0, sizeof(news_items[0]));
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
							nw = &news_items[num - 1];
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
						memset(&news_items[num - 1], 0, sizeof(news_items[0]));
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
							nw = &news_items[num - 1];
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
						dst = &panoramic_map_buf[0x13ac];
						memcpy(dst, &data[0x10], data_len - 0x10);
					} else if (get_dashboard_state()->dashboard_ts->disp_mode == 1) {
						if (get_dashboard_state()->dashboard_ts->arrow_x > 0x158 ||
						    get_dashboard_state()->dashboard_ts->arrow_y > 0x68) {
							G1_LOG_ERR("citywalk arrow offset too long!\n");
							return;
						}
						dst = &panoramic_map_buf[0x18fc];
						memcpy(dst, &data[0x10], data_len - 0x10);
					}
					if (get_dashboard_state()->dashboard_ts->disp_mode !=
					    citywalk_last_disp_mode) {
						citywalk_last_disp_mode =
							get_dashboard_state()->dashboard_ts->disp_mode;
						get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
						citywalk_reload = 1;
						citywalk_bg_ready = 0;
					} else if (citywalk_bg_ready == 1) {
						citywalk_reload = 0;
						if (get_dashboard_state()
							    ->dashboard_ts->citywalk_state == 2) {
							memcpy(&panoramic_map_buf[0x197c],
							       panoramic_map_buf, 0x197c);
						} else if (get_dashboard_state()
								   ->dashboard_ts->disp_mode ==
							   0) {
							memcpy(&panoramic_map_buf[0x197c + 0x13ac],
							       &panoramic_map_buf[0x13ac],
							       data_len - 0x10);
						} else if (get_dashboard_state()
								   ->dashboard_ts->disp_mode ==
							   1) {
							memcpy(&panoramic_map_buf[0x197c + 0x18fc],
							       &panoramic_map_buf[0x18fc],
							       data_len - 0x10);
						}
						get_dashboard_state()->dashboard_ts->citywalk_state =
							3;
						citywalk_canvas_valid = 1;
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
				multi_packet_total = total;
				multi_packet_cnt = 1;
				if (data[0xb] == 2) {
					citywalk_bg_ready = 0;
					get_dashboard_state()->dashboard_ts->citywalk_state = 1;
					memset(panoramic_map_buf, 0, 0x197c);
					memcpy(panoramic_map_buf, &data[9], data_len - 9);
					citywalk_len = data_len - 9;
				}
			} else if (idx < total) {
				if (get_dashboard_state()->dashboard_ts->citywalk_state == 1) {
					citywalk_bg_ready = 0;
					if (multi_packet_cnt != idx - 1) {
						G1_LOG_WRN("There is a packet order error, current packet "
							   "order = %d, expected packet order = %d\n",
							   idx, multi_packet_cnt + 1);
						multi_packet_total = total;
						multi_packet_cnt = 0;
						citywalk_len = 0;
						memset(panoramic_map_buf, 0, 0x197c);
						return;
					}
					if (citywalk_len - 9 + data_len > 0x197c) {
						G1_LOG_ERR("citywalk data is too long, the current data "
							   "length %d,wait write data length = %d\n",
							   citywalk_len, data_len - 9);
						return;
					}
					memcpy(&panoramic_map_buf[citywalk_len], &data[9], data_len - 9);
					citywalk_len += data_len - 9;
					G1_LOG_INF("Successfully received the subpackage content, the "
						   "packet sequence is %d\n",
						   idx);
					multi_packet_cnt++;
				}
			} else if (total == idx) {
				if (get_dashboard_state()->dashboard_ts->citywalk_state == 1) {
					if (multi_packet_cnt != total - 1 || multi_packet_total != total) {
						G1_LOG_WRN("There is a packet order error, current packet "
							   "order = %d, expected packet order = %d\n",
							   idx, multi_packet_cnt + 1);
						multi_packet_total = total;
						multi_packet_cnt = 0;
						citywalk_len = 0;
						citywalk_bg_ready = 0;
						memset(panoramic_map_buf, 0, 0x197c);
						return;
					}
					if (citywalk_len - 9 + data_len > 0x197c) {
						G1_LOG_ERR("citywalk data is too long, the current data "
							   "length %d,wait write data length = %d\n",
							   citywalk_len, data_len - 9);
						citywalk_bg_ready = 0;
						return;
					}
					G1_LOG_ERR("Successfully assembled multiple packages of data, and "
						   "updated the complete content to the UI thread for "
						   "data update.\n");
					memcpy(&panoramic_map_buf[citywalk_len], &data[9], data_len - 9);
					citywalk_len += data_len - 9;
					get_dashboard_state()->dashboard_ts->disp_mode = panoramic_map_buf[0];
					get_dashboard_state()->dashboard_ts->area = panoramic_map_buf[1];
					if (citywalk_reload == 1) {
						get_dashboard_state()->dashboard_ts->citywalk_mode = 0;
					}
					get_dashboard_state()->dashboard_ts->citywalk_bg_param = panoramic_map_buf[3];
					citywalk_bg_ready = 1;
					get_dashboard_state()->dashboard_ts->citywalk_state = 2;
					if ((get_dashboard_state()->dashboard_ts->disp_mode == 0 &&
					     citywalk_len != 0x13ac) ||
					    (get_dashboard_state()->dashboard_ts->disp_mode == 1 &&
					     citywalk_len != 0x18fc)) {
						citywalk_reload = 1;
						citywalk_bg_ready = 0;
						get_dashboard_state()->dashboard_ts->citywalk_state = 0;
					}
				}
				multi_packet_total = 0;
				multi_packet_cnt = 0;
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
			resp[5] = globle->unread_msg_num;
			resp[6] = getNotesIndex() + 1;
			resp[7] = globle->dashboard_ts->low_power;
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
		uint16_t total;
		case 1:
			G1_LOG_INF("received teleprompter init  packet ....\n");
			memset(msg, 0, sizeof(struct teleprompter_info));
			total = data[5] | (data[6] << 8);
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				int64_t now;

				G1_LOG_INF("received teleprompter init packet,total packet = 1\n");
				tp = (struct teleprompter_info *)msg;
				globle->esb_down_id = data[3];
				set_esb_recv_state(data[3], 0, 0);
				tp->action = 1;
				tp->ready = 1;
				tp->mode = data[10] & 0xf;
				tp->mode_flag = data[10] & 0x80;
				tp->countdown_s = data[9];
				tp->scroll_pct = data[0xb];
				tp->mark_pos = 0;
				tp->suspend = 0;
				memcpy(tp->text, &data[0xc], data_len - 0x14);
				tp->len = data_len - 0x14;
				tp->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				get_wall_clock_ms(&now);
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
				multi_packet_total = total;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				tp_len = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				tpv->action = 1;
				tpv->ready = 0;
				tpv->mode = data[10] & 0xf;
				tp_buf.mode_flag = data[10] & ~0x7f;
				atomic_signal_fence(memory_order_seq_cst);
				tpv->countdown_s = data[9];
				tpv->scroll_pct = data[0xb];
				tpv->mark_pos = 0;
				tpv->ts = 0;
				memcpy((void *)tp_buf.text, &data[0xc], data_len - 0xc);
				tp_len = data_len - 0xc;
				multi_packet_cnt++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (multi_packet_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
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
				multi_packet_cnt++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx == total) {
				int64_t now;

				if (multi_packet_cnt != idx - 1 || multi_packet_total != idx) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				globle->esb_down_id = data[3];
				set_esb_recv_state(data[3], 0, 0);
				memcpy((void *)(tp_buf.text + tp_len), &data[0xc], data_len - 0x14);
				tp_len += data_len - 0x14;
				tpv->len = tp_len;
				tp_buf.ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				get_wall_clock_ms(&now);
				G1_LOG_INF("*******************------ received app send timestamp "
					   "= %lld,current system timestamp = %lld\n",
					   tp_buf.ts, now);
				multi_packet_cnt++;
				tp_buf.ready = 1;
				memcpy(get_dashboard_state()->teleprompter, (const void *)&tp_buf,
				       sizeof(tp_buf));
				if (tp_buf.ready) {
					update_persist_task_status(globle, 9, 2);
				}
				G1_LOG_INF("ACTION ID = 1,Successfully assembled multiple packages "
					   "of data, and updated the complete content to the UI "
					   "thread for data update.\n");
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_ERR("A serious packet order error occurred!\n");
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				PUT_RSP_NC(9, 1);
				POST_TO_HOST(10);
			}
			break;
		case 2:
			globle->esb_down_id = data[3];
			set_esb_recv_state(data[3], 0, 0);
			ctx->tx_len = ((struct ble_req_hdr *)tx)->len + 4;
			globle->teleprompter->mark_pos = *(uint16_t *)&data[6];
			globle->teleprompter->scroll_pct = data[5];
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
			total = data[5] | (data[6] << 8);
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				int64_t now;

				G1_LOG_INF("received TEXT UPGRADE Single PACKET ...\n");
				globle->esb_down_id = data[3];
				set_esb_recv_state(data[3], 0, 0);
				globle->teleprompter->action = 3;
				globle->teleprompter->ready = 1;
				globle->teleprompter->scroll_pct = data[9];
				globle->teleprompter->mark_pos = *(uint16_t *)&data[10];
				memset(globle->teleprompter->text, 0, sizeof(globle->teleprompter->text));
				memcpy(globle->teleprompter->text, &data[0xc], data_len - 0x14);
				globle->teleprompter->len = data_len - 0x14;
				globle->teleprompter->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				get_wall_clock_ms(&now);
				G1_LOG_INF("*******************------ received app send timestamp = "
					   "%lld,current system timestamp = %lld\n",
					   globle->teleprompter->ts, now);
				if (sub == 7) {
					tp_scroll_pending = 1;
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
				multi_packet_total = total;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				memcpy((void *)&tp_buf, &data[0xc], data_len - 0xc);
				multi_packet_len = data_len - 0xc;
				multi_packet_cnt++;
				globle->teleprompter->ts = 0;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx < total) {
				if (multi_packet_cnt != idx - 1) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = 0;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				memcpy((uint8_t *)(void *)&tp_buf + multi_packet_len, &data[0xc],
				       data_len - 0xc);
				multi_packet_len += data_len - 0xc;
				G1_LOG_INF("ACTION ID = 3,Successfully received the subpackage "
					   "content, the packet sequence is %d\n",
					   idx);
				multi_packet_cnt++;
				PUT_RSP_NC(9, 0);
				POST_TO_HOST(10);
			} else if (idx == total) {
				int64_t now;

				if (multi_packet_cnt != idx - 1 || multi_packet_total != idx) {
					G1_LOG_WRN("ACTION ID = 3,There is a packet order error, current "
						   "packet order = %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					memset((void *)&tp_buf, 0, sizeof(tp_buf));
					PUT_RSP_NC(9, 1);
					POST_TO_HOST(10);
					return;
				}
				globle->esb_down_id = data[3];
				set_esb_recv_state(data[3], 0, 0);
				memcpy((uint8_t *)(void *)&tp_buf + multi_packet_len, &data[0xc],
				       data_len - 0x14);
				multi_packet_len += data_len - 0x14;
				multi_packet_cnt++;
				memset(globle->teleprompter->text, 0,
				       sizeof(globle->teleprompter->text));
				memcpy(globle->teleprompter->text, (const void *)&tp_buf, multi_packet_len);
				globle->teleprompter->len = multi_packet_len;
				globle->teleprompter->action = 3;
				globle->teleprompter->scroll_pct = data[9];
				globle->teleprompter->mark_pos = *(uint16_t *)&data[10];
				G1_LOG_INF("ACTIION ID = 3,Successfully assembled multiple packages "
					   "of data, and updated the complete content to the UI "
					   "thread for data update.\n");
				globle->teleprompter->ts = GET_LE64(&data[data_len - 8]);
				now = 0;
				get_wall_clock_ms(&now);
				G1_LOG_INF("*******************------ received app send timestamp "
					   "= %lld,current system timestamp = %lld\n",
					   globle->teleprompter->ts, now);
				if (sub == 7) {
					tp_scroll_pending = 1;
				}
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_ERR("ACTION ID = 3,A serious packet order error occurred!\n");
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				memset((void *)&tp_buf, 0, sizeof(tp_buf));
				PUT_RSP_NC(9, 1);
				POST_TO_HOST(10);
			}
			break;
		case 5:
			G1_LOG_INF("received teleprompter func exit packet ....\n");
			if (is_master() == 1) {
				globle->esb_down_id = data[3];
				set_esb_recv_state(data[3], 0, 0);
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
		globle->esb_down_id = data[3];
		set_esb_recv_state(data[3], 0, 0);
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
			tp_app_sync_count++;
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
		case 3: {
			uint16_t total, idx;

			total = *(uint16_t *)&data[5];
			idx = *(uint16_t *)&data[7];
			if (total == 1) {
				int num = data[9] & 0xf;
				uint8_t flag = data[10];
				int n = num - 1;

				memset(QN_ITEM(n).title, 0, sizeof(QN_ITEM(n).title));
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

					memcpy(QN_ITEM(n).title, &data[0xc],
					       MIN(tl, sizeof(QN_ITEM(n).title)));
					xl = data[tl + 0xc] | (data[tl + 0xd] << 8);
					memcpy(QN_ITEM(n).text, &data[tl + 0xe],
					       MIN(xl, sizeof(QN_ITEM(n).text)));
					G1_LOG_INF("title length = %d,text length = %d\n", tl, xl);
					QN_ITEM(n).valid = 1;
					G1_LOG_INF("Quick Note Title = %s,TXET = %s\n",
						   QN_ITEM(n).title, QN_ITEM(n).text);
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
						   idx, multi_packet_cnt + 1);
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
						   idx, multi_packet_cnt + 1);
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
				memcpy(QN_ITEM(qn_num - 1).title, qn_title_buf.str, sizeof(qn_title_buf));
				memset(QN_ITEM(qn_num - 1).text, 0, sizeof(QN_ITEM(0).text));
				memcpy(QN_ITEM(qn_num - 1).text, qn_text_buf, sizeof(qn_text_buf));
				QN_ITEM(qn_num - 1).valid = 1;
				G1_LOG_INF("Quick Note Title =%s,QuickNote TXET =%s\n",
					   QN_ITEM(qn_num - 1).title, QN_ITEM(qn_num - 1).text);
				upgradeQuickNoteDataToFlash(qn_num - 1);
				PUT_RSP_NC(9, 0);
				ctx->write(resp, 10);
				qn_len = 0;
				qn_cnt = 0;
				qn_total = 0;
			}
			break;
		}
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
			quicknote_timeout_reset();
			if (data[5] == 1) {
				globle->quicknote_show_info->enable = 1;
				globle->quicknote_show_info->started_by_app = 1;
				globle->quicknote_show_info->action = 7;
				memset(globle->quicknote_show_info->data, 0, sizeof(globle->quicknote_show_info->data));
				update_persist_task_status(globle, 0xc, 2);
				set_esb_recv_state(data[3], 0, 0);
			} else {
				resp[5] = 1;
			}
			ctx->write(resp, 6);
			break;
		case 8: {
			struct put_pkt_hdr *rh = (struct put_pkt_hdr *)resp;

			quicknote_timeout_reset();
			memcpy(resp, data, 9);
			resp[1] = 10;
			resp[2] = 0;
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
				globle->quicknote_show_info->action = 8;
				get_dashboard_state()->quicknote_show_info->result_code = data[9];
				get_dashboard_state()->quicknote_show_info->scroll_line = data[10];
				if (get_dashboard_state()->quicknote_show_info->result_code == 0) {
					memset(text_packet_buf, 0, sizeof(text_packet_buf));
					memset(get_dashboard_state()->quicknote_show_info->data, 0,
					       sizeof(get_dashboard_state()->quicknote_show_info->data));
					get_dashboard_state()->quicknote_show_info->len = data_len;
					memcpy(get_dashboard_state()->quicknote_show_info->data, &data[0xb],
					       get_dashboard_state()->quicknote_show_info->len);
				} else {
					display_DelayClose(10000);
				}
				set_esb_recv_state(data[3], 0, 0);
			} else if (idx == 1) {
				G1_LOG_INF("Received quick note multiple packets, currently the first "
					   "packet of data\n");
				multi_packet_total = total;
				multi_packet_cnt = 1;
				memset(text_packet_buf, 0, sizeof(text_packet_buf));
				memcpy(text_packet_buf, &data[0xb], data_len - 0xb);
				multi_packet_len = data_len - 0xb;
			} else if (idx < total) {
				if (multi_packet_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order = %d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					memset(text_packet_buf, 0, sizeof(text_packet_buf));
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				if (multi_packet_len - 0xb + data_len > 0x14a) {
					G1_LOG_ERR("quick note data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, data_len - 0xb);
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				memcpy(&text_packet_buf[multi_packet_len], &data[0xb], data_len - 0xb);
				multi_packet_len += data_len - 0xb;
				G1_LOG_INF("Successfully received the subpackage content, the packet "
					   "sequence is %d\n",
					   idx);
				multi_packet_cnt++;
			} else if (idx == total) {
				if (multi_packet_cnt != idx - 1 || idx != multi_packet_total) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order = %d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					memset(text_packet_buf, 0, sizeof(text_packet_buf));
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				if (multi_packet_len - 0xb + data_len > 0x14a) {
					G1_LOG_ERR("quick note data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, data_len - 0xb);
					resp[9] = 1;
					ctx->write(resp, rh->len);
					return;
				}
				G1_LOG_INF("Successfully assembled multiple packages of data, and "
					   "updated the complete content to the UI thread for data "
					   "update.\n");
				globle->quicknote_show_info->action = 8;
				get_dashboard_state()->quicknote_show_info->result_code = data[9];
				get_dashboard_state()->quicknote_show_info->scroll_line = data[10];
				if (get_dashboard_state()->quicknote_show_info->result_code == 0) {
					memcpy(&text_packet_buf[multi_packet_len], &data[0xb], data_len - 0xb);
					multi_packet_len += data_len - 0xb;
					memset(get_dashboard_state()->quicknote_show_info->data, 0,
					       sizeof(get_dashboard_state()->quicknote_show_info->data));
					memcpy(get_dashboard_state()->quicknote_show_info->data, text_packet_buf,
					       multi_packet_len);
					get_dashboard_state()->quicknote_show_info->len = multi_packet_len;
				} else {
					display_DelayClose(10000);
				}
				set_esb_recv_state(data[3], 0, 0);
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
			}
			ctx->write(resp, rh->len);
			break;
		}
		case 9:
			quicknote_timeout_reset();
			memcpy(resp, data, 5);
			resp[5] = globle->quicknote_show_info->enable != 1;
			resp[6] = data[5];
			ctx->write(resp, 7);
			break;
		case 10:
			memcpy(resp, data, 5);
			resp[5] = 0;
			if (data[5] <= 2) {
				quicknote_timeout_reset();
				if (globle->dashboard_mode != 12) {
					globle->quicknote_show_info->enable = 1;
					globle->quicknote_show_info->started_by_app = 1;
					memset(get_dashboard_state()->quicknote_show_info->data, 0,
					       sizeof(get_dashboard_state()->quicknote_show_info->data));
					update_persist_task_status(globle, 0xc, 2);
				}
				globle->quicknote_show_info->action = 10;
				globle->quicknote_show_info->result_code = data[5];
				set_esb_recv_state(data[3], 0, 0);
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
			globle->esb_down_id = data[3];
			memset(nav, 0, sizeof(*nav));
			memset(get_dashboard_state()->nav, 0, sizeof(*nav));
			nav->type = 0;
			nav->running = 1;
			nav->sync_id = data[3];
			nav_overview_map_ready = 0;
			nav_panoramic_map_ready = 0;
			update_persist_task_status(get_dashboard_state(), 10, 2);
			memset(resp, 0, sizeof(resp)); memcpy(resp, data, 6); resp[5] = 0;
			if (is_master() == 1) {
				send_response_data_to_msgqueue(resp, 6);
			} else {
				POST_TO_HOST(6);
			}
			break;
		case 1: {
			uint32_t len; /* km / distance / speed scans; time and road use the parameter n */
			uint32_t pos, end;
			uint32_t left;

			nav = get_dashboard_state()->nav;
			get_dashboard_state()->esb_down_id = data[3];
			nav->direction = data[5];
			memcpy(&nav->x, &data[6], sizeof(nav->x));
			memcpy(&nav->y, &data[8], sizeof(nav->y));
			if (nav->x != nav_last_x || nav->y != nav_last_y) {
				nav_last_x = nav->x;
				nav_last_y = nav->y;
				nav_pos_updated = 1;
			}
			if (nav->x > 0x1e8 || nav->y > 0x88) {
				G1_LOG_ERR("app send x/y parameter overstep!!! x= %d,y= %d\n", nav->x,
					   nav->y);
			}
			/* time remaining */
			{
			int64_t m;
			uint32_t k = 0;
			m = 0;
			goto time_oversize_chk;
			for (;;) {
				m = n + 1;
				if (data[10 + k++] == '\0')
					break;
time_oversize_chk:
				n = *(uint32_t *)&m;
				left = data_len - 10;
				if (n >= left) {
time_oversize:
					G1_LOG_ERR("TIME_REMAINNING_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)m > (int)sizeof(nav->time_remaining))
				goto time_oversize;
			memset(nav->time_remaining, 0, sizeof(nav->time_remaining));
			pos = 10 + n;
			memcpy(nav->time_remaining, &data[10], (int)m);
			}
			end = data_len - 1;
			/* remaining kilometers */
			len = 0;
			goto km_oversize_chk;
			for (;;) {
				if (data[pos + 1 + len++] == '\0')
					break;
km_oversize_chk:
				left = end - pos;
				if (len >= left) {
km_oversize:
					G1_LOG_ERR("KILOMETER_REMAINNING_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					if (pos & 0x80000000)
						ctx->write(resp, 6);
					else
						ctx->write(&resp[0], 6);
					return;
				}
			}
			if ((int)len > (int)sizeof(nav->km_remaining))
				goto km_oversize;
			memset(nav->km_remaining, 0, sizeof(nav->km_remaining));
			memcpy(nav->km_remaining, &data[pos + 1], len);
			pos += len;
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
			{
			uint32_t npos = pos + n;
			memcpy(nav->road_name, &data[pos + 1], n);
			pos = npos;
			}
			/* remaining distance */
			len = 0;
			goto dist_oversize_chk;
			for (;;) {
				if (data[pos + 1 + len++] == '\0')
					break;
dist_oversize_chk:
				left = end - pos;
				if (len >= left) {
dist_oversize:
					G1_LOG_ERR("REMAINING_DISTANCE_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)len > (int)sizeof(nav->remaining_distance))
				goto dist_oversize;
			memset(nav->remaining_distance, 0, sizeof(nav->remaining_distance));
			memcpy(nav->remaining_distance, &data[pos + 1], len);
			pos += len;
			/* current speed */
			len = 0;
			goto speed_oversize_chk;
			for (;;) {
				if (data[pos + 1 + len++] == '\0')
					break;
speed_oversize_chk:
				if (len >= end - pos) {
speed_oversize:
					G1_LOG_ERR("CURRENT_SPEED_STRING_SIZE oversize\n");
					PUT_RSP(5, 1);
					ctx->write(resp, 6);
					return;
				}
			}
			if ((int)len > (int)sizeof(nav->speed))
				goto speed_oversize;
			memset(nav->speed, 0, sizeof(nav->speed));
			memcpy(nav->speed, &data[pos + 1], len);
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
			nav_text_updated = 1;
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
				multi_packet_total = total;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				nav = get_dashboard_state()->nav;
				nav_overview_map_ready = 0;
				lock_nav_map_mutex(K_FOREVER);
				memset(nav_overview_map_buf, 0, sizeof(nav_overview_map_buf));
				memcpy(nav_overview_map_buf, &data[9], data_len - 9);
				unlock_nav_map_mutex();
				multi_packet_len = data_len - 9;
				multi_packet_cnt++;
				if (total == 1) {
					nav_overview_map_updated = total;
					nav_overview_map_ready = total;
					nav->updated = total;
					nav->type = 2;
					nav->sync_id = data[3];
					nav->map_size = multi_packet_len;
					G1_LOG_INF("Successfully received navigation data .Maps are "
						   "compressed to only one pack!!!\n");
					multi_packet_total = 0;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
				}
				PUT_RSP_NC(9, 0);
				ctx->write(resp, 10);
			} else if (idx < total) {
				if (multi_packet_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					lock_nav_map_mutex(K_FOREVER);
					memset(nav_overview_map_buf, 0, sizeof(nav_overview_map_buf));
					unlock_nav_map_mutex();
					get_dashboard_state();
					nav_overview_map_ready = 0;
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				if (multi_packet_len - 9 + data_len >= sizeof(nav_overview_map_buf)) {
					G1_LOG_ERR("overview map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, multi_packet_len - 9 + data_len);
					return;
				}
				get_dashboard_state();
				lock_nav_map_mutex(K_FOREVER);
				memcpy(&nav_overview_map_buf[multi_packet_len], &data[9], data_len - 9);
				unlock_nav_map_mutex();
				nav_overview_map_ready = 0;
				multi_packet_len += data_len - 9;
				G1_LOG_INF("Successfully received the subpackage content, "
					   "the packet sequence is %d,total size = %d\n",
					   idx, multi_packet_len);
				multi_packet_cnt++;
			} else if (idx == total) {
				if (multi_packet_cnt != idx - 1 || idx != multi_packet_total) {
					G1_LOG_WRN("There is a packet order error, current packet order "
						   "= %d, expected packet order =%d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					lock_nav_map_mutex(K_FOREVER);
					memset(nav_overview_map_buf, 0, sizeof(nav_overview_map_buf));
					unlock_nav_map_mutex();
					get_dashboard_state();
					nav_overview_map_ready = 0;
					PUT_RSP_NC(9, 1);
					ctx->write(resp, 10);
					return;
				}
				if (multi_packet_len - 9 + data_len > sizeof(nav_overview_map_buf)) {
					G1_LOG_ERR("overview map : The data length of the current "
						   "packet is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, multi_packet_len - 9 + data_len);
					return;
				}
				globle->esb_down_id = data[3];
				nav = get_dashboard_state()->nav;
				lock_nav_map_mutex(K_FOREVER);
				memcpy(&nav_overview_map_buf[multi_packet_len], &data[9], data_len - 9);
				unlock_nav_map_mutex();
				multi_packet_len += data_len - 9;
				G1_LOG_INF("Successfully received the last packet,packet "
					   "length = %d,total packet size = %d\n",
					   idx, multi_packet_len);
				nav->updated = 1;
				nav_overview_map_ready = 1;
				nav_overview_map_updated = 1;
				nav->type = 2;
				nav->sync_id = data[3];
				nav->map_size = multi_packet_len;
				multi_packet_cnt++;
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				PUT_RSP_NC(9, 0);
				if (is_master() == 1) {
					send_response_data_to_msgqueue(resp, 10);
				} else {
					POST_TO_HOST(10);
				}
			} else {
				G1_LOG_WRN("There is a packet order error, current packet order = %d, "
					   "expected packet order =%d\n",
					   idx, multi_packet_cnt + 1);
				multi_packet_total = total;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
				lock_nav_map_mutex(K_FOREVER);
				memset(nav_overview_map_buf, 0, sizeof(nav_overview_map_buf));
				unlock_nav_map_mutex();
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
				nav_panoramic_map_ready = 0;
				citywalk_canvas_valid = 0;
				nav->panoramic = data[9];
				memset(panoramic_map_buf, 0, PANORAMIC_MAP_SIZE);
				memcpy(panoramic_map_buf, &data[10], n);
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
					memset(panoramic_map_buf, 0, PANORAMIC_MAP_SIZE);
					nav_panoramic_map_ready = 0;
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
				nav_panoramic_map_ready = 0;
				memcpy(&panoramic_map_buf[pano_len], &data[10], data_len - 10);
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
					memset(panoramic_map_buf, 0, PANORAMIC_MAP_SIZE);
					nav_panoramic_map_ready = 0;
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
				globle->esb_down_id = data[3];
				memcpy(&panoramic_map_buf[pano_len], &data[10], data_len - 10);
				pano_len += data_len - 10;
				G1_LOG_INF("Successfully received panoramic map  last "
					   "packet,Packet id = %d,total received size = "
					   "%d\n",
					   idx, pano_len);
				pano_cnt++;
				nav_panoramic_map_ready = 1;
				nav_panoramic_map_updated = 1;
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
				memset(panoramic_map_buf, 0, PANORAMIC_MAP_SIZE);
				nav_panoramic_map_ready = 0;
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
				nav_app_sync_count++;
			}
			ctx->write(resp, 6);
			break;
		case 5:
			G1_LOG_INF("received navigation func exit packet ....\n");
			nav = get_dashboard_state()->nav;
			globle->esb_down_id = data[3];
			memset((uint8_t *)nav + 1, 0, sizeof(*nav) - 1);
			nav->running = 0;
			PUT_RSP(5, 1);
			ctx->write(resp, 6);
			break;
		case 6: {
			uint8_t status;

			nav = get_dashboard_state()->nav;
			globle->esb_down_id = data[3];
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
			memset(text_packet_buf, 0, sizeof(text_packet_buf));
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				save_esb_snapshot(globle->translate_src, sizeof(struct translate_buf),
					     globle->esb_down_id, 0);
				set_esb_recv_state(data[1], 1, 0);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(text_packet_buf, &data[7], hdr->len - 7);
		}
		if (data[3] == 0) {
			memset(globle->translate_src->data, 0, sizeof(globle->translate_src->data));
			tb = globle->translate_src;
			tb->len = 0;
			globle->translate_src->screen_status = data[4];
			globle->translate_src->char_pos = data[6] + data[5] * 256;
		}
		memcpy((uint8_t *)globle->translate_src + globle->translate_src->len + 6, text_packet_buf,
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
				deferred_text_ack_total = data[2];
				deferred_text_ack_idx = data[3];
				set_esb_recv_state(data[1], 0, 0);
			} else {
				ctx->write(resp, 20);
			}
		} else {
			if (data[3] == data[2] - 1) {
				set_esb_recv_state(data[1], 0, 0);
			}
			ctx->write(resp, 20);
		}
		break;
	}
	case BLE_CMD_TRANSLATE_DST_TEXT: { /* translate: translated text */
		struct translate_buf *tb;

		if (hdr->len != 0) {
			memset(text_packet_buf, 0, sizeof(text_packet_buf));
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				save_esb_snapshot(globle->translate_dst, sizeof(struct translate_buf),
					     globle->esb_up_id, 1);
				set_esb_up_recv_state(data[1], 1);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(text_packet_buf, &data[7], hdr->len - 7);
		}
		if (data[3] == 0) {
			memset(globle->translate_dst->data, 0, sizeof(globle->translate_dst->data));
			tb = globle->translate_dst;
			tb->len = 0;
			globle->translate_dst->screen_status = data[4];
			globle->translate_dst->char_pos = data[6] + data[5] * 256;
		}
		memcpy((uint8_t *)globle->translate_dst + globle->translate_dst->len + 6, text_packet_buf,
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
				deferred_text_ack_total = data[2];
				deferred_text_ack_idx = data[3];
				set_esb_up_recv_state(data[1], 0);
			} else {
				ctx->write(resp, 20);
			}
		} else {
			if (data[3] == data[2] - 1) {
				set_esb_up_recv_state(data[1], 0);
			}
			ctx->write(resp, 20);
		}
		break;
	}
	case BLE_CMD_MICROPHONE_SET: /* microphone */
		if (data[1] == 1) {
			if (is_idle() || get_dashboard_state()->task_status->task == 9 ||
			    get_dashboard_state()->task_status->task == 0x10 ||
			    get_dashboard_state()->task_status->task == 0xb ||
			    get_dashboard_state()->task_status->task == 0x13 ||
			    get_dashboard_state()->task_status->task == 0x14 ||
			    get_dashboard_state()->task_status->task == 0xc ||
			    (get_dashboard_state()->dashboard_mode == 0 && get_dashboard_state()->suspend_state == 0)) {
				if (get_dashboard_state()->task_status->task == 0x10 &&
				    get_dashboard_state()->dash_buf->type == 2) {
					get_dashboard_state()->dash_buf->type = 3;
				}
				if (LOG_LEVEL > 2) {
					int dbg = BLE_DEBUG;
					if (dbg != 0) {
						if (dbg > 0)
							ble_printk("%s(): received open dmic command\n", __func__);
						else
							ble_printk("%s(): received open dmic command\n", &__func__[0]);
					} else {
						printk("%s(): received open dmic command\n", __func__);
					}
				}
				request_dmic_stream_start();
				resp[1] = PKCS7_PACK_DONE;
			} else {
				resp[1] = PKCS7_PACK_ERR;
				goto mic_tail;
			}
		} else {
			G1_LOG_INF("received close dmic command\n");
			dmic_stream_stop();
			resp[1] = PKCS7_PACK_DONE;
		}
mic_tail:
		resp[2] = data[1];
		ctx->write(resp, 20);
		break;
	case BLE_CMD_TRANSLATE_CONTROL:
		if (data[2] != 0 && data[3] != 0) {
			globle->translate_src->translation_type = data[3];
			globle->translate_src->original_type = data[2];
			globle->translate_dst->translation_type = data[3];
			globle->translate_dst->original_type = data[2];
		}
		globle->translate_src->suspend = data[1];
		globle->translate_dst->suspend = data[1];
		dmic_stream_pause(data[1]);
		G1_LOG_INF("received start/Pause command,origin language type = %d,translate origin "
			   "language type = %d,Suspend status = %d\n",
			   globle->translate_dst->original_type, globle->translate_dst->translation_type,
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
		globle->last_sync_ts = k_uptime_get();
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
		globle->last_sync_ts = k_uptime_get();
		globle->dashboard_cmd = hdr->cmd;
		k_sem_give(&globle->dashboard_position_sem);
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		break;
	case BLE_CMD_BITMAP_HIDE:
		resp[1] = PKCS7_PACK_DONE;
		ctx->write(resp, 20);
		if (get_dashboard_state()->dashboard_mode == 0xb || get_dashboard_state()->dashboard_mode == 0x10) {
			exit_running_task_keep_status(globle, 0);
		} else {
			if (get_dashboard_state()->is_master == 2 &&
			    get_dashboard_state()->dashboard_mode == 6) {
				k_msleep(50);
			}
			exit_running_task(globle, 0);
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
		dlen = *(uint16_t *)&data[1];
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == dlen && data[4] < 9) {
			uint8_t v;

			resp[5] = PKCS7_PACK_DONE;
			switch (data[4]) {
			case HW_SUB_USER_DATA_RESET:
				globle->user_data_reset_pending = 1;
				break;
			case HW_SUB_HEIGHT_DEPTH:
				if (unlikely(data[6] > 8 || data[7] > 9)) {
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				globle->esb_down_id = data[3];
				memcpy(msg, data, hdr->len);
				spim_transfer(ctx, rx, 8);
				break;
			case HW_SUB_GIVE_MIC_TRANSM_SEM:
				if (get_pt_test_mode() == 1) {
					G1_LOG_INF("give mic_transm_sem\n");
					k_sem_give(&mic_transm_sem);
				}
				break;
			case HW_SUB_LUM_GEAR:
				v = data[5];
				G1_LOG_WRN("ble set lum gear:%d\n", v);
				if (unlikely(v > 0x3f)) {
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				if (globle->panel.lum_gear != v) {
					globle->panel.lum_gear = v;
					globle->panel.brightness_max = v;
					globle->dashboard_cmd = hdr->cmd;
					sys_settings_dirty = 1;
					k_sem_give(&globle->dashboard_position_sem);
				}
				break;
			case HW_SUB_DOUBLE_TAP_ACTION:
				v = data[5];
				if (unlikely(v > 5)) {
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				if (globle->double_tap_customize != v) {
					SendDoubleTapCustomizeToSlave(v);
				}
				break;
			case HW_SUB_LUM_COEFFICIENT:
				v = data[5];
				switch (v) {
				case 1:
					globle->dashboard_ts->dashboard_hold = v;
					break;
				case 0:
					globle->dashboard_ts->dashboard_hold = v;
					break;
				case 2:
					v = data[6];
					G1_LOG_WRN("ble set lum coeffic:%d\n", v);
					if (globle->dashboard_ts->dashboard_hold != 1 || v < 70 || v > 100) {
						resp[5] = PKCS7_PACK_ERR;
						break;
					}
					if (globle->panel.brightness_percent != v) {
						globle->panel.brightness_percent = v;
						set_brightness_to_panel_reg_in_running(globle->panel.panel_brightness_level);
						storage_commit_request(0, 0);
					}
					break;
				default:
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				break;
			case HW_SUB_LONG_PRESS_ENABLE:
				v = data[5];
				if (unlikely(v > 1)) {
					resp[5] = PKCS7_PACK_ERR;
					break;
				}
				if (globle->longpress_tap_customize != v) {
					SendLongpressTapCustomizeToSlave(v);
				}
				break;
			case HW_SUB_MIC_ON_HEAD_UP:
				if (data[5] == 1) {
					globle->head_up_mic_disabled = 1;
				} else {
					globle->head_up_mic_disabled = 0;
				}
				break;
			default:
				resp[5] = PKCS7_PACK_ERR;
				break;
			}
		} else {
			resp[5] = PKCS7_PACK_ERR;
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
static void DashboardLockTimerExpiry_callback(struct k_timer *timer)
{
	G1_LOG_INF("dashboard lock timeout,release .\n");
	atomic_clear_bit(&dashboard_lock_requested, DASHBOARD_LOCK_BIT);
	atomic_clear_bit(&dashboard_lock_reported, DASHBOARD_LOCK_BIT);
	atomic_clear_bit(&dashboard_head_up_opened, DASHBOARD_LOCK_BIT);
}
void lock_nav_map_mutex(k_timeout_t timeout)
{
	k_mutex_lock(&nav_map_mutex, timeout);
}
void unlock_nav_map_mutex(void)
{
	k_mutex_unlock(&nav_map_mutex);
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
	ret = master_process_put_req(state, (struct ble_req *)ctx->tx_buf, buf, len);
	if (LOG_LEVEL == 5) {
		printk("spim ret(len=%d): %02x,%02x,%02x,%02x, %02x,%02x,%02x,%02x\n", len,
		       buf[0], buf[1], buf[2], buf[3], buf[0], buf[1], buf[2], buf[3]);
	}
	return ret;
}
void ble_dispatch_raw_packet(uint8_t *data, uint32_t len)
{
	struct ble_req_hdr hdr;

	struct ble_context *ctx = get_ble_context();

	hdr.cmd = data[0];
	hdr.source = 1;
	hdr.len = len;
	ble_process_req_dispatch(ctx, &hdr, data);
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
			if (get_dashboard_state()->dashboard_mode == 6) {
				if (dashboard_send_fail_count < 100) {
					dashboard_send_fail_count++;
				}
				send_fail_count = 0;
			} else {
				send_fail_count++;
				dashboard_send_fail_count = 0;
			}
			if (send_fail_count >= 10) {
				G1_LOG_ERR("BLE send failed for %d times\n", send_fail_count);
				send_fail_count = 0;
				exit_running_task(get_dashboard_state(), 1);
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
				   get_dashboard_state()->dashboard_mode == 6 ? dashboard_send_fail_count
								    : send_fail_count);
		}
		dmic_seq++;
	} while (dmic_seq & 3);
	return 0;
}
static void ble_process_get_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
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
		spim_transfer_len(ctx, rx, 1); /* inlined spim_transfer; the call edge puts get before put in the text */
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
				resp[5] = globle->dashboard_mode ? globle->dashboard_mode : 0;
				G1_LOG_INF("return system status to app,current running app is %d\n",
					   globle->dashboard_mode);
			}
		}
		ctx->write(resp, 6);
		return;
	case BLE_CMD_RASTER_CONFIG_GET:
		resp[1] = PKCS7_PACK_DONE;
		resp[2] = globle->panel.raster_height_offset;
		resp[3] = globle->panel.canvas_distance_gear;
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
		CURRENT_LANGUAGE.magic = lang;
		if (master == 1) {
			SendSystemLanguageInfoToSlave(lang);
		}
		ctx->write(resp, data_len);
		return;
	}
	case BLE_CMD_BURIAL_POINT_GET: {
		const int buf_len = sizeof(globle->bp) + 2;

		G1_LOG_ERR("BLE_GET_BURIAL_POINT_DATA\n\n");
		uint8_t buf[buf_len];
		{
			memcpy(rx, &get_dashboard_state()->bp,
			       sizeof(globle->bp));
			buf[0] = hdr->cmd;
			buf[1] = PKCS7_PACK_DONE;
			memcpy(&buf[2], rx, sizeof(globle->bp));
			ctx->write(buf, buf_len);
		}
		return;
	}
	case BLE_CMD_HARDWARE_GET:
		resp[1] = data[1];
		resp[2] = PKCS7_PACK_DONE;
		switch (data[1]) {
		case HW_SUB_DOUBLE_TAP_ACTION:
			resp[3] = globle->double_tap_customize;
			break;
		case HW_SUB_LUM_COEFFICIENT:
			resp[3] = globle->panel.brightness_percent;
			break;
		case HW_SUB_LONG_PRESS_ENABLE:
			resp[3] = globle->longpress_tap_customize;
			break;
		case HW_SUB_MIC_ON_HEAD_UP:
			resp[3] = globle->head_up_mic_disabled;
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
static void ble_work_thread(void *p1, void *p2, void *p3)
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
						ctx->rx_bufs[2][2] = ctx->charging;
					}
				} else if (dmic_send_pending) {
					ctx->rx_pending = 1;
					ctx->rx_bufs[2][0] = 0xf1;
					dmic_send_pending = 0;
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
			ble_handle_rx_data(ctx->rx_data, ctx->rx_len, 0);
			memset(ctx->rx_data, 0, sizeof(ctx->rx_data));
		} else {
			ble_handle_rx_data(ctx->rx_bufs[ctx->rx_pending + 1], ctx->small_len, 0);
		}
		ctx->rx_len = 0;
		ctx->rx_pending = 0;
	}
}
/* noinline: the shipped code has no partial-inlining clone of this function (see status) */
__attribute__((noinline)) int set_esb_recv_state(uint8_t a, uint8_t b, int sel)
{
	if (sel) {
		set_esb_up_recv_state(a, b);
	} else {
		get_dashboard_state()->esb_down_recving = b;
		get_dashboard_state()->esb_down_id = a;
	}
	return 0;
}
int spim_transfer_len(struct ble_context *ctx, uint8_t *buf, uint32_t len)
{
	spim_transfer(ctx, buf, len);
	return len;
}
int deal_event_to_phone(struct ble_context *ctx, uint8_t *evt)
{
	struct GlassesState *state = CONTAINER_OF(ctx, struct GlassesState, ble_context);
	uint8_t buf[21] = {0};

	switch (evt[1]) {
	case 0xf0:
		buf[0] = 0x0d;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->esb_down_id;
		buf[3] = deferred_text_ack_total;
		buf[4] = deferred_text_ack_idx;
		deferred_text_ack_total = 0;
		deferred_text_ack_idx = 0;
		break;
	case 0xf1:
		buf[0] = 0x0f;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->esb_up_id;
		buf[3] = deferred_text_ack_total;
		buf[4] = deferred_text_ack_idx;
		deferred_text_ack_total = 0;
		deferred_text_ack_idx = 0;
		break;
	case 0xf2:
		buf[0] = 0x4e;
		buf[1] = PKCS7_PACK_DONE;
		buf[2] = state->esb_up_id;
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
		buf[2] = get_pt_level_flag();
		break;
	case 0x0f:
		buf[0] = 0xf5;
		buf[1] = 0x0f;
		buf[2] = get_pt_level();
		break;
	case 10:
		buf[0] = 0xf5;
		buf[1] = 10;
		if (state->battery_left == 0x5d) {
			buf[2] = state->battery_soc_flag ? 0x5f : 0x5e;
		} else if (state->battery_left == 0x5e) {
			buf[2] = state->battery_soc_flag ? 0x61 : 0x60;
		} else {
			switch (state->battery_left) {
			case 0x5f:
				buf[2] = 0x62;
				break;
			case 0x60:
				buf[2] = 0x63;
				break;
			default:
				buf[2] = state->battery_left > 0x60 ? 0x64 : state->battery_left;
				break;
			}
		}
		break;
	case 0x12:
		buf[0] = 0xf5;
		buf[1] = 0x12;
		buf[2] = state->panel.panel_brightness_level;
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
int ble_process_req_dispatch(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	uint8_t cmd = hdr->cmd;

	if (cmd - 1u <= 0x26) {
		ble_process_put_req(ctx, hdr, data, cmd - 1u); /* PUT command index (unused by the callee) */
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
int send_debug_msg(struct ble_context *ctx)
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
void ble_handle_rx_data(uint8_t *data, uint32_t len, int dump)
{
	if (dump) {
		dump_hex("BLE-rec", data, len);
	}
	if (spec_ble_command_hook(data, len)) {
		ble_dispatch_raw_packet(data, len);
	}
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
/* unaligned little-endian 16-bit field of a request packet */
static inline uint16_t ble_get_u16(const uint8_t *p)
{
	uint16_t v;

	memcpy(&v, p, sizeof(v));
	return v;
}
static ALWAYS_INLINE int post_resp_write(struct ble_context *ctx, uint8_t *resp)
{
	ctx->write(resp, POST_RESP_LEN(resp));
	return 0;
}

static int ble_process_post_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data)
{
	uint8_t *tx = ctx->tx_buf;
	uint8_t *payload = tx + 4;
	uint8_t resp[20] = {0};
	uint8_t rx[128];
	/* data[4] read before the length checks; the four length-error paths share len_err */
	uint8_t op;
	/* sized view of the reassembly buffer: the vendor build saw its size here (__memcpy_chk) */

	memcpy(tx, hdr, sizeof(*hdr));
	ctx->tx_len = hdr->len + 4;
	resp[0] = hdr->cmd;

	switch (hdr->cmd) {
	case BLE_CMD_NOTIFICATION_SEND:
		post_notification_cmd_process(ctx, (uint8_t *)hdr, data);
		return 0;
	case BLE_CMD_SYNC_DISPLAY:
		memcpy(ctx->tx_buf, hdr, sizeof(*hdr));
		memcpy(payload, data + 1, hdr->len - 1);
		ctx->tx_len = hdr->len + 4;
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		break;
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
		conn = get_current_conn();
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
			memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
			if (data[3] == data[2] - 1) {
				resp[1] = PKCS7_PACK_DONE;
			} else {
				save_esb_snapshot(get_dashboard_state()->dash_buf,
					     sizeof(struct dash_data_buf),
					     get_dashboard_state()->esb_up_id, 1);
				set_esb_up_recv_state(data[1], 1);
				resp[1] = PKCS7_PACK_MORE;
			}
			memcpy(multi_packet_buf, data + 9, hdr->len - 9);
		}
		if (data[3] == 0) {
			memset(get_dashboard_state()->dash_buf->data, 0,
			       sizeof(get_dashboard_state()->dash_buf->data));
			dash = get_dashboard_state()->dash_buf;
			((uint8_t *)&dash->len)[0] = 0;
			((uint8_t *)&dash->len)[1] = 0;
			get_dashboard_state()->dash_buf->screen_status = data[4];
			get_dashboard_state()->dash_buf->char_pos = data[5] * 256 + data[6];
			get_dashboard_state()->dash_buf->scroll_pct = data[7];
			get_dashboard_state()->dash_buf->page_count = data[8];
		}
		dash = get_dashboard_state()->dash_buf;
		memcpy(&dash->data[get_dashboard_state()->dash_buf->len], multi_packet_buf,
		       hdr->len - 9);
		get_dashboard_state()->dash_buf->len += hdr->len - 9;
		((struct ble_req_hdr *)tx)->len = hdr->len;
		ctx->tx_len = hdr->len + 4;
		if (data[3] == data[2] - 1) {
			spim_transfer(ctx, rx, 8);
			if ((data[4] & 0xf0) == 0x60) {
				dmic_stream_stop();
				get_dashboard_state()->dash_buf->type = 10;
			} else if ((data[4] & 0xf0) == 0x70) {
				dash = get_dashboard_state()->dash_buf;
				t = 15;
				goto dash_set_type;
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
							goto dash_set_type;
						}
					} else {
						get_dashboard_state()->dash_buf->type = 8;
						get_dashboard_state()->stay_time_left_s = 8;
					}
				}
			} else if ((data[4] & 0xf0) == 0x40) {
			dash_8:
				get_dashboard_state()->dash_buf->type = 8;
				get_dashboard_state()->stay_time_left_s = 8;
			} else {
			dash_7:
				get_dashboard_state()->dash_buf->type = 7;
				get_dashboard_state()->stay_time_left_s = 0x10;
			}
			if (0) {
			dash_set_type:
				dash->type = t;
				get_dashboard_state()->stay_time_left_s = 0;
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
				set_esb_up_recv_state(data[1], 0);
				return 0;
			}
		} else if (data[3] == data[2] - 1) {
			set_esb_up_recv_state(data[1], 0);
			/* per-site write copies (&resp[0] keeps them apart in GIMPLE; RTL merges them) */
			ctx->write(&resp[0], sizeof(resp));
			return 0;
		}
		ctx->write(&resp[0], sizeof(resp));
		return 0;
	}
	case BLE_CMD_POST_49:
	case BLE_CMD_MTU_SET:
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		break;
	case BLE_CMD_NOTIFICATION_CLEAR:
		G1_LOG_INF("ble_process_post_req BLE_REQ_POST_DELETE_NOTIFICATION_MSG\n");
		memcpy(payload, data + 1, hdr->len - 1);
		spim_transfer(ctx, rx, 8);
		resp[1] = PKCS7_PACK_DONE;
		break;
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
		if (ble_get_u16(&data[1]) != hdr->len) {
			G1_LOG_WRN("packet length error,input data length = %d,packet data length = %d\n",
				   hdr->len, ble_get_u16(&data[1]));
			return 0;
		}
		G1_LOG_INF("received Dashboard lock command.\n");
		{
		uint8_t action = data[4];
		if (get_dashboard_state()->is_master == 1) {
			if (action == 1) {
				if (atomic_test_bit(&dashboard_lock_requested, DASHBOARD_LOCK_BIT)) {
					return 0;
				}
				G1_LOG_INF("master exec dashboard lock process.\n");
				atomic_set_bit(&dashboard_lock_requested, DASHBOARD_LOCK_BIT);
				atomic_clear_bit(&dashboard_lock_reported, DASHBOARD_LOCK_BIT);
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
		uint16_t data_len = ble_get_u16(&data[1]);
		resp[1] = 6;
		resp[3] = data[3];
		resp[2] = 0;
		resp[4] = data[4];
		if (hdr->len == data_len && data[4] <= 2) {
			if (data[5] == 1) {
				get_dashboard_state()->ts_info->enable = 1;
				get_dashboard_state()->ts_info->action_cmd = data[4];
				get_dashboard_state()->ts_info->ts = k_uptime_get() + 5000;
				get_dashboard_state()->esb_down_id = data[3];
				update_persist_task_status(get_dashboard_state(), 0x12, 2);
			} else {
				get_dashboard_state()->ts_info->enable = 0;
			}
			resp[5] = PKCS7_PACK_DONE;
		} else {
			resp[5] = PKCS7_PACK_ERR;
		}
		break;
	}
	case BLE_CMD_TRANSCRIBE_CONTROL: {
		uint16_t data_len = ble_get_u16(&data[1]);
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
					dmic_stream_stop();
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
					get_dashboard_state()->esb_down_id = data[3];
					update_persist_task_status(get_dashboard_state(), 0x13, 2);
				} else if (mode == 3) {
					dmic_stream_pause(1);
					get_dashboard_state()->transcribe_buf->flags &= ~1;
				} else if (mode == 4) {
					dmic_stream_pause(0);
					if (get_dashboard_state()->transcribe_buf->mode != 2) {
						get_dashboard_state()->transcribe_buf->flags |= 1;
					}
				}
			break;
		}
		/* The packet-count check of the idx == total path sits at the top of this
		 * loop, before the case 2 loads, and is reached only through the loop
		 * back-edge from that path (break leaves the loop into the assemble code
		 * below, the other paths leave through case2_end). */
		for (;;) {
			if (multi_packet_total == total)
				break;
			goto ord_err;
		case 2:
				memcpy(resp, data, 9);
				resp[1] = 10;
				resp[2] = 0;
				resp[9] = PKCS7_PACK_DONE;
				total = ble_get_u16(&data[5]);
				idx = ble_get_u16(&data[7]);
				if (total == 1) {
					G1_LOG_INF("received transcribe packet,total packet = 1\n");
					get_dashboard_state()->transcribe_buf->status = data[9];
					if (data[10] == 1 || get_dashboard_state()->transcribe_buf->mode == 2) {
						get_dashboard_state()->transcribe_buf->flags &= ~1;
					} else {
						get_dashboard_state()->transcribe_buf->flags |= 1;
					}
					get_dashboard_state()->transcribe_buf->dark_lines = data[11];
					memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
					memset(get_dashboard_state()->transcribe_buf->data, 0,
					       sizeof(get_dashboard_state()->transcribe_buf->data));
					get_dashboard_state()->transcribe_buf->len = data_len - 12;
					memcpy(get_dashboard_state()->transcribe_buf->data, data + 12,
					       get_dashboard_state()->transcribe_buf->len);
					set_esb_recv_state(data[3], 0, 0);
					goto case2_end;
				} else if (idx == 1) {
					G1_LOG_INF("Received transcribe multiple packets, currently the first "
						   "packet of data\n");
					multi_packet_total = total;
					multi_packet_cnt = 1;
					memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
					memcpy(multi_packet_buf, data + 12, data_len - 12);
					multi_packet_len = data_len - 12;
					goto case2_end;
				} else if (idx < total) {
					if (multi_packet_cnt != idx - 1) {
						G1_LOG_WRN("There is a packet order error, current packet order = "
							   "%d, expected packet order = %d\n",
							   idx, multi_packet_cnt + 1);
						multi_packet_total = total;
						multi_packet_cnt = 0;
						multi_packet_len = 0;
						memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
						resp[9] = PKCS7_PACK_ERR;
						goto case2_end;
					}
					if (multi_packet_len + data_len > 0x20c) {
						G1_LOG_ERR("transcribe data is too long, the current data length "
							   "%d,wait write data length = %d\n",
							   multi_packet_len, data_len - 12);
						resp[9] = PKCS7_PACK_ERR;
						goto case2_end;
					}
					memcpy(multi_packet_buf + multi_packet_len, data + 12, data_len - 12);
					multi_packet_len = multi_packet_len - 12 + data_len;
					G1_LOG_INF("Successfully received the subpackage content, the packet "
						   "sequence is %d\n",
						   idx);
					multi_packet_cnt++;
					goto case2_end;
				} else if (idx == total) {
					if (multi_packet_cnt != total - 1)
						goto ord_err;
				} else {
					goto case2_end;
					ord_err:
						G1_LOG_WRN("There is a packet order error, current packet order = "
							   "%d, expected packet order = %d\n",
							   idx, multi_packet_cnt + 1);
						multi_packet_total = total;
						multi_packet_cnt = 0;
						memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
						resp[9] = PKCS7_PACK_ERR;
						goto case2_end;
				}
		}
			if (multi_packet_len + data_len > 0x20c) {
				G1_LOG_ERR("transcribe data is too long, the current data length "
					   "%d,wait write data length = %d\n",
					   multi_packet_len, data_len - 12);
				resp[9] = PKCS7_PACK_ERR;
				break;
			}
			G1_LOG_INF("Successfully assembled multiple packages of data, and "
				   "updated the complete content to the UI thread for data "
				   "update.\n");
			get_dashboard_state()->transcribe_buf->status = data[9];
			if (data[10] == 1 || get_dashboard_state()->transcribe_buf->mode == 2) {
				get_dashboard_state()->transcribe_buf->flags &= ~1;
			} else {
				get_dashboard_state()->transcribe_buf->flags |= 1;
			}
			get_dashboard_state()->transcribe_buf->dark_lines = data[11];
			memcpy(multi_packet_buf + multi_packet_len, data + 12, data_len - 12);
			multi_packet_len = multi_packet_len - 12 + data_len;
			memset(get_dashboard_state()->transcribe_buf->data, 0,
			       sizeof(get_dashboard_state()->transcribe_buf->data));
			memcpy(get_dashboard_state()->transcribe_buf->data, multi_packet_buf,
			       multi_packet_len);
			get_dashboard_state()->transcribe_buf->len = multi_packet_len;
			set_esb_recv_state(data[3], 0, 0);
			multi_packet_total = 0;
			multi_packet_cnt = 0;
			multi_packet_len = 0;
		case2_end:
			break;
		case 3:
				resp[1] = 7;
				resp[2] = 0;
				resp[3] = data[3];
				resp[4] = 3;
				resp[5] = PKCS7_PACK_DONE;
				resp[5] = get_dashboard_state()->transcribe_buf->running ? PKCS7_PACK_DONE
											 : PKCS7_PACK_ERR;
				resp[6] = data[5];
				break;
		default:
				resp[1] = 6;
				resp[2] = 0;
				resp[3] = data[3];
				resp[4] = data[4];
				resp[5] = PKCS7_PACK_ERR;
			break;
		}
		} else {
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = op;
			resp[5] = PKCS7_PACK_ERR;
		}
		goto post_resp;
	}
	case BLE_CMD_TRANSCRIBE_STATUS: {
		if (hdr->len == ble_get_u16(&data[1])) {
		op = data[4];
		if (op <= 3) {
			transcribe_info_timeout_reset();
			if (data[4] == 3) {
				resp[1] = 7;
				resp[2] = 0;
				(&resp[1])[2] = data[3];
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
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = op;
			resp[5] = PKCS7_PACK_ERR;
		}
		} else {
			op = *(uint8_t *)((uintptr_t)data + 4);
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = op;
			resp[5] = PKCS7_PACK_ERR;
		}
		ctx->write(resp, POST_RESP_LEN(resp));
		return 0;
	}
	case BLE_CMD_EVENAI: {
		uint16_t data_len = ble_get_u16(&data[1]);
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
				get_dashboard_state()->evenai_buf->wakeup_arg = data[6];
				get_dashboard_state()->evenai_buf->action_status = data[7];
				memset(get_dashboard_state()->evenai_buf->data, 0,
				       sizeof(get_dashboard_state()->evenai_buf->data));
			} else if (mode == 2) {
				get_dashboard_state()->evenai_buf->state = mode;
				dmic_stream_stop();
				ctx->write(resp, POST_RESP_LEN(resp));
				return 0;
			} else if (mode == 3) {
				get_dashboard_state()->evenai_buf->state = 1;
				get_dashboard_state()->evenai_buf->sub = 0;
			} else {
				if (is_master() == 1) {
					get_dashboard_state()->evenai_buf->state = 0;
				}
				dmic_stream_stop();
				ctx->write(resp, POST_RESP_LEN(resp));
				return 0;
			}
			if (get_dashboard_state()->task_status->task != 0x14) {
				update_persist_task_status(get_dashboard_state(), 0x14, 2);
			}
			set_esb_recv_state(data[3], 0, 0);
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
			idx = ble_get_u16(&data[7]);
			total = ble_get_u16(&data[5]);
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
					ctx->write(resp, POST_RESP_LEN(resp));
					return 0;
				}
				payload = data + hlen;
				get_dashboard_state()->evenai_buf->sub = sub;
				get_dashboard_state()->evenai_buf->action_status = data[9];
				if (sub != 4) {
					get_dashboard_state()->evenai_buf->scroll_line = data[10];
					if (sub == 2) {
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					} else {
						get_dashboard_state()->evenai_buf->scroll_pct = data[11];
					}
				} else {
					if (get_dashboard_state()->evenai_buf->action_status == 1) {
						get_dashboard_state()->dashboard_ts->dashboard_hold = 2;
					} else if (get_dashboard_state()->evenai_buf->action_status == 0x13) {
						if (get_dashboard_state()->task_status->task != 0x14) {
							if (get_dashboard_state()->dashboard_mode == 6 &&
							    get_dashboard_state()->dashboard_ts->exit_pending == 0) {
								get_dashboard_state()->dashboard_ts->exit_pending = 1;
							}
							get_dashboard_state()->evenai_buf->state = 1;
							update_persist_task_status(get_dashboard_state(),
										   0x14, 2);
						}
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					}
				}
				if (sub != 2 || get_dashboard_state()->evenai_buf->action_status != 1 || payload[0] != 0) {
					memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
					memset(get_dashboard_state()->evenai_buf->data, 0,
					       sizeof(get_dashboard_state()->evenai_buf->data));
					get_dashboard_state()->evenai_buf->len = n;
					memcpy(get_dashboard_state()->evenai_buf->data, payload,
					       get_dashboard_state()->evenai_buf->len);
				}
				set_esb_recv_state(data[3], 0, 0);
			} else if (idx == 1) {
				G1_LOG_INF("Received evenai_v2 multiple packets, currently the first "
					   "packet of data\n");
				multi_packet_total = total;
				multi_packet_cnt = 1;
				memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
				memcpy(multi_packet_buf, data + hlen, data_len - hlen);
				multi_packet_len = data_len - hlen;
			} else if (idx < total) {
				if (multi_packet_cnt != idx - 1) {
					G1_LOG_WRN("There is a packet order error, current packet order = "
						   "%d, expected packet order = %d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					multi_packet_len = 0;
					memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
					resp[9] = PKCS7_PACK_ERR;
					ctx->write(resp, POST_RESP_LEN(resp));
					return 0;
				}
				if (multi_packet_len + data_len - hlen > 0x200) {
					G1_LOG_ERR("evenai_v2 data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, data_len - hlen);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				memcpy(multi_packet_buf + multi_packet_len, data + hlen, data_len - hlen);
				multi_packet_len = multi_packet_len + data_len - hlen;
				G1_LOG_INF("Successfully received the subpackage content, the packet "
					   "sequence is %d\n",
					   idx);
				multi_packet_cnt++;
			} else if (idx == total) {
				if (multi_packet_cnt != idx - 1 || idx != multi_packet_total) {
					G1_LOG_WRN("There is a packet order error, current packet order = "
						   "%d, expected packet order = %d\n",
						   idx, multi_packet_cnt + 1);
					multi_packet_total = total;
					multi_packet_cnt = 0;
					memset(multi_packet_buf, 0, MULTI_PACKET_BUF_SIZE);
					resp[9] = PKCS7_PACK_ERR;
					goto post_resp;
				}
				if (multi_packet_len + data_len - hlen > 0x200) {
					G1_LOG_ERR("evenai_v2 data is too long, the current data length "
						   "%d,wait write data length = %d\n",
						   multi_packet_len, data_len - hlen);
					(&resp[1])[8] = PKCS7_PACK_ERR; /* = resp[9]; this form keeps the copy out of tree tail-merge */
					ctx->write(resp, POST_RESP_LEN(resp));
					return 0;
				}
				G1_LOG_INF("Successfully assembled multiple packages of data, and "
					   "updated the complete content to the UI thread for data "
					   "update.\n");
				get_dashboard_state()->evenai_buf->sub = sub;
				get_dashboard_state()->evenai_buf->action_status = data[9];
				if (sub != 4) {
					get_dashboard_state()->evenai_buf->scroll_line = data[10];
					if (sub == 2) {
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					} else {
						get_dashboard_state()->evenai_buf->scroll_pct = data[11];
					}
				} else {
					if (get_dashboard_state()->evenai_buf->action_status == 1) {
						get_dashboard_state()->dashboard_ts->dashboard_hold = 2;
					} else if (get_dashboard_state()->evenai_buf->action_status == 0x13) {
						if (get_dashboard_state()->task_status->task != 0x14) {
							if (get_dashboard_state()->dashboard_mode == 6 &&
							    get_dashboard_state()->dashboard_ts->exit_pending == 0) {
								get_dashboard_state()->dashboard_ts->exit_pending = 1;
							}
							get_dashboard_state()->evenai_buf->state = 1;
							update_persist_task_status(get_dashboard_state(),
										   0x14, 2);
						}
						{ int64_t now = k_uptime_get(); get_dashboard_state()->evenai_buf->ts = now; }
					}
				}
				memcpy(multi_packet_buf + multi_packet_len, data + hlen, data_len - hlen);
				multi_packet_len = multi_packet_len + data_len - hlen;
				if (sub != 2 || get_dashboard_state()->evenai_buf->action_status != 1 ||
				    data[hlen] != 0) {
					memset(get_dashboard_state()->evenai_buf->data, 0,
					       sizeof(get_dashboard_state()->evenai_buf->data));
					memcpy(get_dashboard_state()->evenai_buf->data, multi_packet_buf,
					       multi_packet_len);
					get_dashboard_state()->evenai_buf->len = multi_packet_len;
				}
				set_esb_recv_state(data[3], 0, 0);
				multi_packet_total = 0;
				multi_packet_cnt = 0;
				multi_packet_len = 0;
			}
			break;
		}
		case 5:
			resp[1] = 7;
			resp[2] = 0;
			resp[3] = data[3];
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
			break;
		default:
			resp[1] = 6;
			resp[2] = 0;
			resp[3] = data[3];
			resp[4] = sub;
			resp[5] = PKCS7_PACK_ERR;
			break;
		}
		return post_resp_write(ctx, resp);
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
		if (ble_get_u16(&data[1]) == hdr->len) {
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
		ctx->write(resp, POST_RESP_LEN(resp));
		return 0;
	}
	case BLE_CMD_EVENAI_EXIT:
		if (ble_get_u16(&data[1]) == hdr->len) {
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
					if (get_dashboard_state()->dashboard_ts->exit_pending == 0) {
						get_dashboard_state()->dashboard_ts->exit_pending = 1;
					}
					dmic_stream_stop();
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
		ctx->write(resp, POST_RESP_LEN(resp));
		return 0;
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
/*
 * Returns int like set_esb_recv_state / save_esb_snapshot; no caller uses the result, so IPA-SRA emits
 * the clone set_esb_up_recv_state.isra.0.  Being a clone (created after z_impl_k_sem_give) is what
 * puts it after k_sem_give and before k_uptime_get in the shipped .text order.
 */
static int set_esb_up_recv_state(uint8_t a, uint8_t b)
{
	get_dashboard_state()->esb_up_recving = b;
	get_dashboard_state()->esb_up_id = a;
	return 0;
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
		ble_dispatch_raw_packet((uint8_t *)buf, 1);
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
		strncpy(title, pos, p - pos);
		strcpy(message, p + 1);
		G1_LOG_INF("模拟接收到新通知 title:%s, message:%s\n", title, message);
		return mobile_send_notification_to_ble_device_test(title, message, ble_dispatch_raw_packet);
	}

	pos = strstr(buf, "#2@");
	if (pos) {
		pos += 3;
		val = atoi(pos);
		G1_LOG_INF("模拟抬头/低头触发:pos:%s, val=%d\n\n", pos, val);
		buf[0] = 5;
		buf[1] = 1;
		buf[2] = val != 0;
		ble_dispatch_raw_packet((uint8_t *)buf, 3);
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
		ble_dispatch_raw_packet((uint8_t *)buf, 3);
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
		ble_dispatch_raw_packet((uint8_t *)buf, 3);
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
		ble_dispatch_raw_packet((uint8_t *)buf, 6);
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
			subcontracing_send_data_pkcs7((uint8_t *)json, n, 4, ble_dispatch_raw_packet);
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
			subcontracing_send_data_pkcs7((uint8_t *)str, n, 9, ble_dispatch_raw_packet);
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
			subcontracing_send_data_pkcs7((uint8_t *)str, n, 10, ble_dispatch_raw_packet);
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
			strncpy(title, value, q - value);
			strcpy(msg, q + 1);
			G1_LOG_INF("#cmd_type:%s, title=%s, msg=%s\n\n", cmd_type, title, msg);
			return mobile_send_notification_to_ble_device_test(title, msg, ble_dispatch_raw_packet);
		}
		buf[0] = cmd;
		buf[1] = atoi(value);
		G1_LOG_INF("**cmd_type:%s, value=%s, tx_len=%d\n\n", cmd_type, value, 2);
		ble_dispatch_raw_packet((uint8_t *)buf, 2);
		return 0;
	}

	if (strncmp(buf, "#a", 2) == 0) {
		printk("\n*****test callback audio data*****\n");
		char req[20] = {0};

		req[0] = 0x6e;
		while (ctx->write(req, sizeof(req)) != 0) {
			k_sleep(K_MSEC(10));
			if (!ctx->connected || !ctx->send_enabled) {
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
					k_sleep(K_MSEC(10));
					err_cnt++;
					if (!ctx->connected || !ctx->send_enabled) {
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
		state->display_mode = val;
		printk("\n*****display mode***** %d\n", (uint8_t)val);
		if (state->display_mode == 11) {
			state->imu.mode = 2;
			change_work_mode(2);
			if (state->is_master == 2) {
				k_sem_give(&state->sem_1);
			}
		} else {
			state->imu.mode = 1;
			change_work_mode(3);
		}
		state->dashboard_cmd = 0;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#e", 2) == 0) {
		if (buf[2] == '0') {
			dmic_stream_stop();
		} else {
			state->pending |= 4;
		}
		k_sem_give(&state->main_sem);
		return 0;
	}

	if (strncmp(buf, "#f", 2) == 0) {
		state->pending |= 8;
		k_sem_give(&state->main_sem);
		return 0;
	}

	if (strncmp(buf, "#g", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "TX:%d,fail:%d,RX:%d,Signal:%d", esb_tx_count, esb_tx_fail_count,
			esb_rx_count, esb_signal);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#r", 2) == 0) {
		G1_LOG_ERR("sys reboot because reboot cmd\n");
		system_reboot_delayed();
		return 0;
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

		state->imu.ref = imu_pitch_x100;
		sprintf(out, "base: %d", imu_pitch_x100);
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
				state->opt3007_context.auto_brightness = atoi(&buf[2]);
			} else {
				state->opt3007_context.auto_brightness = 0;
				state->panel.panel_brightness_level = atoi(&buf[2]);
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

		sprintf(out, "level: %d", state->panel.panel_brightness_level);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#u", 2) == 0) {
		char out[20] = {0};

		val = atoi(&buf[2]);
		state->imu.level = val;
		sprintf(out, "level: %d", (uint8_t)val);
		ctx->write(out, sizeof(out));
		state->dashboard_cmd = 0;
		k_sem_give(&state->dashboard_position_sem);
		return 0;
	}

	if (strncmp(buf, "#p", 2) == 0) {
		char out[20] = {0};

		sprintf(out, "pitch: %d", imu_pitch_x100);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#t", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "net build time: %s, app build time %s, ver %d.%d.%d, JBD DeviceID %x\n\r",
			net_build_time, G1_BUILD_TIME, 1, 6, 6, JDB_PANEL_ID);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#v", 2) == 0) {
		char out[200] = {0};

		sprintf(out, "B:%d, V:%d, A:%d, T:%d", state->battery_left, state->battery_voltage + 200,
			state->battery_current - 128, state->battery_temp);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#k", 2) == 0) {
		char out[64] = {0};

		sprintf(out, "VADC:%d TMR:%d", chargerGetVdcRect(), 0);
		ctx->write(out, sizeof(out));
		return 0;
	}

	if (strncmp(buf, "#j", 2) == 0) {
		char out[20] = {0};

		if (atoi(&buf[2]) == 1) {
			state->spi.init_cb(&state->spi);
			state->flash_ops.fn(&state->flash_ops);
			strcpy(out, "init flash");
		} else {
			state->spi.init_cb(&state->spi);
			state->flash_ops.fn(&state->flash_ops);
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
int start_ble_work_thread(struct ble_context *ctx)
{
	k_mutex_init(&nav_map_mutex);
	k_timer_init(&DashboardLockTimer, DashboardLockTimerExpiry_callback, NULL);
	k_thread_create(&ble_work_thread_data, ble_work_thread_stack,
			K_THREAD_STACK_SIZEOF(ble_work_thread_stack), ble_work_thread, ctx, NULL,
			NULL, BLE_WORK_THREAD_PRIORITY, 0, K_NO_WAIT);
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
		send_debug_msg(ctx);
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


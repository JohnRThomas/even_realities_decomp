/*
 * BLE application protocol (phone <-> glasses): request dispatch, get/put
 * request handlers, pkcs7 packet reassembly, BLE debug log channel and the
 * BLE work thread.  Reconstructed from the G1 v1.63 app core.
 *
 * This header is shared by everything in ble_proto.c, including
 * ble_process_put_req() (written separately and dropped into ble_proto.c).
 */
#ifndef G1_BLE_PROTO_H_
#define G1_BLE_PROTO_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <g1_date.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/bluetooth/addr.h>
#include <zephyr/bluetooth/conn.h>

#include "g1_log.h"

/* vendor log line without LOG_LEVEL check and without the "%s(): " prefix */
#define BLE_PRINTK(fmt, ...)                                                   \
	do {                                                                   \
		if (BLE_DEBUG) {                                               \
			ble_printk(fmt, ##__VA_ARGS__);                        \
		} else {                                                       \
			printk(fmt, ##__VA_ARGS__);                            \
		}                                                              \
	} while (0)

#include "ble_cmd.h"

/* pkcs7 packet reassembly results */
#define PKCS7_PACK_DONE  0xc9 /* last packet received */
#define PKCS7_PACK_ERR   0xca
#define PKCS7_PACK_MORE  0xcb /* more packets follow */

/* Debug log message queue (ble_printk -> phone) */
#define DEBUG_MSG_SIZE 200
#define DEBUG_MSGQ_MAX 20

/* dashboard lock bits (DAT_20007f4c / DAT_20007f50 / DAT_20008480) */
#define DASHBOARD_LOCK_BIT 1 /* bit number */

#define BLE_TX_BUF_SIZE 0x2b8
#define BLE_SMALL_PKT_MAX 20

/* One queued NUS packet (same as struct bt_data_msg in src/ble/ble_ancs.h) */
struct bt_data_msg {
	uint8_t len;
	uint8_t data[256];
};

/* request header handed to ble_process_req_dispatch() */
struct ble_req_hdr {
	uint8_t cmd;
	uint8_t f_1;
	uint16_t len;
};

#define BLE_WORK_THREAD_STACK_SIZE 0x3000
#define BLE_WORK_THREAD_PRIORITY (-15)

/* One ANCS notification (0x1b4 bytes; same as src/ble/ble_ancs.h) */
struct ancs_notif_data {
	uint32_t msg_id;                                 /* 0x000 */
	uint32_t f_004;                                  /* 0x004 */
	uint32_t uid;                                    /* 0x008 */
	uint8_t f_00c;                                   /* 0x00c */
	uint8_t f_00d;                                   /* 0x00d */
	uint8_t f_00e;                                   /* 0x00e */
	uint8_t f_00f;                                   /* 0x00f */
	char app_identifier[32];                         /* 0x010 */
	char display_name[32];                           /* 0x030 */
	char title[32];                                  /* 0x050 */
	char subtitle[32];                               /* 0x070 */
	char message[256];                               /* 0x090 */
	char date[32];                                   /* 0x190 */
	uint32_t action;                                 /* 0x1b0 */
};

/* BLE context embedded in GlassesState at 0x77c (partial; same layout as
 * struct ble_context in src/ble/ble_ancs.h)
 */
struct ble_context {
	void (*start_work_thread)(void);                 /* 0x000 */
	uint8_t pad_004[0x00c - 0x004];
	int (*write)(const uint8_t *data, uint16_t len); /* 0x00c */
	uint8_t *tx_buf;                                 /* 0x010 (malloc(0x2b8)) */
	uint32_t tx_len;                                 /* 0x014 */
	uint8_t f_018;                                   /* 0x018 */
	uint8_t pad_019[0x034 - 0x019];
	struct ancs_notif_data notif;                    /* 0x034 */
	struct k_sem ancs_get_attr_data_sem;             /* 0x1e8 */
	struct k_sem ancs_get_attr_req_sem;              /* 0x200 */
	struct k_sem rx_sem;                             /* 0x218 */
	struct k_sem tx_sem;                             /* 0x230 */
	uint8_t receiver_thd_is_running;                 /* 0x248 */
	uint8_t pad_249[3];
	uint8_t *rx_bufs[3];                             /* 0x24c (buf_394, buf_8d4, small_buf) */
	uint8_t rx_data[0x100];                          /* 0x258 */
	uint32_t rx_len;                                 /* 0x358 */
	uint32_t rx_pending;                             /* 0x35c */
	uint32_t small_len;                              /* 0x360 */
	volatile uint8_t restart_adv;                    /* 0x364 */
	uint8_t f_365;                                   /* 0x365 */
	uint8_t send_enabled;                            /* 0x366 */
	uint8_t f_367;                                   /* 0x367 */
};

/* GlassesState->dashboard_ts (partial, packed) */
struct dashboard_ts_view {
	uint32_t ts;                                     /* 0x00 second timestamp */
	uint8_t f_04;                                    /* 0x04 */
	uint8_t f_05;                                    /* 0x05 */
	int64_t ms_ts;                                   /* 0x06 ms timestamp */
	uint8_t pad_0e[0x5d - 0x0e];
	uint8_t f_5d;                                    /* 0x5d */
	uint8_t time_fmt;                                /* 0x5e 12/24 h, F/C */
	uint8_t f_5f;                                    /* 0x5f */
	uint8_t f_60;                                    /* 0x60 */
	uint8_t pad_61[0x65 - 0x61];
	uint8_t disp_mode;                               /* 0x65 dashboard display mode */
	uint8_t area;                                    /* 0x66 custom display area */
	uint8_t sched_mode;                              /* 0x67 schedule display mode */
	uint8_t sched_num;                               /* 0x68 schedule record count */
	uint8_t stocks_mode;                             /* 0x69 */
	uint8_t news_mode;                               /* 0x6a */
	uint8_t citywalk_mode;                           /* 0x6b */
	uint8_t f_6c;                                    /* 0x6c */
	uint16_t arrow_x;                                /* 0x6d citywalk arrow offset */
	uint16_t arrow_y;                                /* 0x6f */
	uint8_t citywalk_state;                          /* 0x71 */
	uint8_t f_72;                                    /* 0x72 */
	uint8_t f_73;
	uint8_t f_74;                                    /* 0x74 */
} __packed;

/* GlassesState->dash_buf: dashboard data received with cmd 0x4e (0x1e9 bytes) */
struct dash_data_buf {
	uint8_t type;                                    /* 0x000 */
	uint8_t f_1;                                     /* 0x001 */
	uint16_t f_2;                                    /* 0x002 (big endian in the packet) */
	uint8_t f_4;                                     /* 0x004 */
	uint8_t f_5;                                     /* 0x005 */
	uint8_t f_6;                                     /* 0x006 */
	uint8_t data[0x1e0];                             /* 0x007 */
	uint16_t len;                                    /* 0x1e7 */
} __packed;

/* GlassesState->evenai_buf (cmd 0x54) */
struct evenai_buf {
	uint8_t state;                                   /* 0x00 */
	uint8_t sub;                                     /* 0x01 */
	uint8_t f_2;                                     /* 0x02 */
	uint8_t f_3;                                     /* 0x03 */
	uint8_t f_4;                                     /* 0x04 */
	uint8_t f_5;                                     /* 0x05 */
	int64_t ts;                                      /* 0x06 */
	uint16_t len;                                    /* 0x0e */
	uint8_t data[0x200];                             /* 0x10 */
} __packed;

/* GlassesState->buf_1028 (cmd 0x51) */
struct buf_1028 {
	uint8_t enable;                                  /* 0x00 */
	uint8_t f_1;                                     /* 0x01 */
	int64_t timeout;                                 /* 0x02 */
} __packed;

/* GlassesState->transcribe_buf (cmd 0x52 / 0x53, 0x208 bytes) */
struct transcribe_buf {
	bool running;                                    /* 0x000 */
	uint8_t f_1;                                     /* 0x001 */
	uint8_t mode;                                    /* 0x002 */
	uint8_t f_3;                                     /* 0x003 */
	uint8_t flags;                                   /* 0x004 */
	uint8_t f_5;                                     /* 0x005 */
	uint16_t len;                                    /* 0x006 */
	uint8_t data[0x200];                             /* 0x008 */
};

struct state_ops_b10 {
	void (*fn)(struct state_ops_b10 *ops);
};

struct state_ops_b30 {
	uint32_t f_0;
	void (*fn)(struct state_ops_b30 *ops);
};

struct teleprompter_info;
struct nav_info;
struct translate_buf;
struct quicknote_list;
struct qn_show_info;

/* Partial view of the global vendor state (get_dashboard_state()) */
struct GlassesState {
	uint8_t is_master;                               /* 0x000 */
	uint8_t work_mode;                               /* 0x001 */
	uint8_t esb_channel;                             /* 0x002 */
	uint8_t pad_003[0x020 - 0x003];
	struct k_sem sem_020;                            /* 0x020 */
	uint8_t pad_038[0x068 - 0x038];
	struct k_sem sem_068;                            /* 0x068 */
	struct k_sem dashboard_position_sem;             /* 0x080 */
	uint8_t pad_098[0x0cc - 0x098];
	uint8_t f_0cc;                                   /* 0x0cc */
	uint8_t f_0cd;                                   /* 0x0cd */
	uint8_t f_0ce;                                   /* 0x0ce */
	uint8_t f_0cf;                                   /* 0x0cf */
	uint8_t pad_0d0[0x0d5 - 0x0d0];
	volatile uint8_t f_0d5;                          /* 0x0d5 current app id (6 = ...) */
	uint8_t pad_0d6[0x0db - 0x0d6];
	uint8_t f_0db;                                   /* 0x0db */
	uint8_t pad_0dc;
	uint8_t f_0dd;                                   /* 0x0dd */
	uint8_t pad_0de[0x77c - 0x0de];
	struct ble_context ble_context;                  /* 0x77c */
	uint8_t pad_ae4[0xb10 - 0x77c - sizeof(struct ble_context)];
	struct state_ops_b10 ops_b10;                    /* 0xb10 */
	uint8_t pad_b14[0xb30 - 0xb14];
	struct state_ops_b30 ops_b30;                    /* 0xb30 */
	uint8_t pad_b38[0xec0 - 0xb38];
	uint8_t raster_height_gear;                      /* 0xec0 */
	uint8_t canvas_distance_gear;                    /* 0xec1 */
	uint8_t pad_ec2[0xed5 - 0xec2];
	uint8_t f_ed5;                                   /* 0xed5 */
	uint8_t pad_ed6[0xed8 - 0xed6];
	uint16_t lum_cur;                                /* 0xed8 */
	uint8_t pad_eda[0xede - 0xeda];
	uint16_t lum_gear;                               /* 0xede */
	uint8_t f_ee0;                                   /* 0xee0 */
	uint8_t pad_ee1[0xee8 - 0xee1];
	uint8_t f_ee8;                                   /* 0xee8 */
	uint8_t pad_ee9[0xef8 - 0xee9];
	uint8_t f_ef8;                                   /* 0xef8 */
	uint8_t pad_ef9[0xf68 - 0xef9];
	uint32_t f_f68;                                  /* 0xf68 */
	int32_t user_horiz_pitch;                        /* 0xf6c */
	uint8_t pad_f70[0xf9c - 0xf70];
	uint8_t f_f9c;                                   /* 0xf9c */
	uint8_t pad_f9d[0xfc4 - 0xf9d];
	uint8_t f_fc4;                                   /* 0xfc4 */
	uint8_t f_fc5;                                   /* 0xfc5 */
	uint8_t f_fc6;                                   /* 0xfc6 */
	uint8_t f_fc7;                                   /* 0xfc7 */
	uint8_t f_fc8;                                   /* 0xfc8 */
	uint8_t f_fc9;                                   /* 0xfc9 */
	uint8_t f_fca;                                   /* 0xfca */
	uint8_t pad_fcb[0xfde - 0xfcb];
	uint8_t master_mac[6];                           /* 0xfde */
	uint8_t slave_mac[6];                            /* 0xfe4 */
	uint8_t f_fea;                                   /* 0xfea */
	uint8_t pad_feb[0xfee - 0xfeb];
	uint8_t f_fee;                                   /* 0xfee (display mode) */
	uint8_t pad_fef;
	struct dashboard_ts_view *dashboard_ts;          /* 0xff0 */
	uint8_t pad_ff4[0x1000 - 0xff4];
	struct teleprompter_info *teleprompter;          /* 0x1000 */
	struct nav_info *nav;                            /* 0x1004 */
	struct translate_buf *translate_src;             /* 0x1008 */
	struct translate_buf *translate_dst;             /* 0x100c */
	struct dash_data_buf *dash_buf;                  /* 0x1010 */
	struct evenai_buf *evenai_buf;                   /* 0x1014 */
	uint8_t pad_1018[0x1024 - 0x1018];
	uint8_t *horiz_pitch_cfg;                        /* 0x1024 */
	struct buf_1028 *buf_1028;                       /* 0x1028 */
	struct transcribe_buf *transcribe_buf;           /* 0x102c */
	struct quicknote_list *quicknote;                /* 0x1030 */
	struct qn_show_info *qn_show;                    /* 0x1034 */
	uint8_t *buf_1038;                               /* 0x1038 */
	uint8_t *buf_103c;                               /* 0x103c */
	uint8_t pad_1040[0x1060 - 0x1040];
	uint32_t dashboard_cmd;                          /* 0x1060 */
	uint8_t pad_1064[0x1068 - 0x1064];
	int *task_status;                                /* 0x1068 (*task_status = current task id) */
	uint8_t bt_state;                                /* 0x106c */
	uint8_t f_106d;                                  /* 0x106d (flags) */
	uint8_t pad_106e[0x1070 - 0x106e];
	uint16_t module_mask;                            /* 0x1070 */
	uint8_t pad_1072[0x1078 - 0x1072];
	int64_t file_ts;                                 /* 0x1078 */
	uint8_t phone_is_ios;                            /* 0x1080 */
	bt_addr_le_t bonded_addr;                        /* 0x1081 */
	uint8_t bonded;                                  /* 0x1088 (globle->enable_ancs) */
	uint8_t pad_1089[0x10d4 - 0x1089];
	uint8_t check_mode;                              /* 0x10d4 */
	uint8_t f_10d5;                                  /* 0x10d5 */
	uint8_t message_mode;                            /* 0x10d6 */
	uint8_t message_stay_time;                       /* 0x10d7 */
	uint8_t pad_10d8[0x1128 - 0x10d8];
	uint8_t burial_point_ctx[0x11c];                 /* 0x1128 */
	uint8_t f_1244;                                  /* 0x1244 */
	uint8_t f_1245;                                  /* 0x1245 */
	uint8_t f_1246;                                  /* 0x1246 */
	uint8_t f_1247;                                  /* 0x1247 */
};

struct GlassesState *get_dashboard_state(void);

/* ---- types used by ble_process_put_req() ---- */

/* cmd 6 / sub 1: time sync */
struct put_time_sync {
	uint8_t hdr[5];
	uint32_t sec_ts;   /* 0x05 */
	int64_t ms_ts;     /* 0x09 */
} __packed;

/* dashboard schedule entry (DAT_2001252f[8], also read by DashBoard_Reflash) */
struct schedule_item {
	uint8_t valid;
	char title[0x41];
	char time[0x21];
	char location[0x41];
};

/* dashboard stock entry (DAT_2000e104[4]) */
struct stock_item {
	uint8_t valid;            /* 0x000 */
	uint8_t change_status;    /* 0x001 */
	uint16_t image_len;       /* 0x002 */
	char code[0x20];          /* 0x004 */
	char company[0x40];       /* 0x024 */
	char price[0x10];         /* 0x064 */
	char price_change[0x10];  /* 0x074 */
	char change_rate[0x10];   /* 0x084 */
	uint8_t image[0x75e];     /* 0x094 */
};

/* dashboard news entry (DAT_20011281[4]) */
struct news_item {
	uint8_t valid;
	char source[0x40];
	char text[0x118];
};

/* teleprompter info (GlassesState->teleprompter, 0x217 bytes) */
struct teleprompter_info {
	uint8_t mode;        /* 0x00 */
	uint8_t ready;       /* 0x01 */
	int64_t ts;          /* 0x02 */
	uint8_t action;      /* 0x0a */
	uint8_t f_0b;        /* 0x0b */
	uint8_t f_0c;        /* 0x0c */
	uint8_t f_0d;        /* 0x0d */
	uint16_t mark_pos;   /* 0x0e */
	uint8_t suspend;     /* 0x10 */
	uint32_t counter;    /* 0x11 */
	uint16_t len;        /* 0x15 */
	uint8_t text[0x200]; /* 0x17 */
} __packed;

/* navigation info (GlassesState->nav, 0xf5 bytes) */
struct nav_info {
	uint8_t running;                 /* 0x00 */
	uint8_t direction;               /* 0x01 */
	uint8_t f_02[4];
	uint8_t updated;                 /* 0x06 */
	uint8_t f_07;
	uint16_t x;                      /* 0x08 */
	uint16_t y;                      /* 0x0a */
	uint8_t f_0c;
	char time_remaining[0x18];       /* 0x0d */
	char km_remaining[0x18];         /* 0x25 */
	char road_name[0x40];            /* 0x3d */
	char remaining_distance[0x18];   /* 0x7d */
	char speed[0x18];                /* 0x95 */
	uint8_t panoramic;               /* 0xad */
	uint8_t arrived;                 /* 0xae */
	uint8_t type;                    /* 0xaf */
	uint8_t sync_id;                 /* 0xb0 */
	uint32_t map_size;               /* 0xb1 */
	char prompt[0x40];               /* 0xb5 */
} __packed;

/* translate buffers (GlassesState->translate_src / translate_dst, 0x1e8 bytes) */
struct translate_buf {
	uint8_t f_0;          /* 0x000 */
	uint8_t f_1;          /* 0x001 */
	uint8_t suspend;      /* 0x002 */
	uint8_t f_3;          /* 0x003 */
	uint16_t f_4;         /* 0x004 */
	uint8_t data[0x1e0];  /* 0x006 */
	uint16_t len;         /* 0x1e6 */
} __packed;

/* quick notes (GlassesState->quicknote) */
struct qn_title {
	char str[0x29];
};

struct quicknote_item {
	uint8_t valid;
	struct qn_title title;
	char text[0x119];
};

struct quicknote_list {
	uint8_t f_0[3];
	struct quicknote_item items[4];
};

/* GlassesState->qn_show (0x1034) */
struct qn_show_info {
	uint8_t f_0;
	uint8_t f_1;          /* 0x01 */
	uint8_t f_2;          /* 0x02 */
	uint8_t action;       /* 0x03 */
	uint8_t f_4;          /* 0x04 */
	uint8_t f_5;          /* 0x05 */
	uint16_t len;         /* 0x06 */
	uint8_t data[0x14a];  /* 0x08 */
};

#define PANORAMIC_MAP_SIZE 0x40d0

/* ---- globals defined in ble_proto.c ---- */
extern struct bt_conn *DAT_20007ef4;   /* current connection */
extern volatile uint16_t DAT_2000e0f0;  /* multi-packet: total packets */
extern volatile uint16_t DAT_2000e0f2;  /* multi-packet: packets received */
extern volatile uint16_t DAT_2000e0f4;  /* multi-packet: bytes received */
#ifndef MULTI_PACKET_BUF_SIZE
#define MULTI_PACKET_BUF_SIZE 0x204
#endif
extern uint8_t DAT_20010995[];          /* multi-packet reassembly buffer (ble_ancs.c) */
/* phone data buffers filled by ble_process_put_req (read by DashBoard_Reflash) */
extern struct stock_item DAT_2000e104[4];      /* 0x7f2 B each */
extern struct news_item DAT_20011281[4];       /* 0x159 B each */
extern struct schedule_item DAT_2001252f[8];   /* 0xa4 B each */
extern volatile uint8_t DAT_2001111d;          /* citywalk map valid */
extern uint8_t DAT_20012a4f[];                 /* map / citywalk buffer (0x40d0) */
extern uint8_t DAT_200143cf[], DAT_20015777[], DAT_20015cc7[]; /* inside DAT_20012a4f */
extern struct k_mutex k_mutex_20007f54;
extern atomic_t DAT_20007f4c;           /* dashboard lock bits */
extern atomic_t DAT_20007f50;           /* dashboard lock bits */
extern struct k_timer DashboardLockTimer;

/* ---- globals defined elsewhere ---- */
extern uint8_t last_ble_cmd;           /* pending 0xf5 event to phone (0xff: none) */
extern uint8_t DAT_20019a77;           /* pending 0xf1 dmic request */
extern uint8_t CURRENT_LANGUAGE;
extern uint32_t DAT_20006bc8;          /* esb signal */
extern uint32_t DAT_20006bcc;          /* esb rx count */
extern uint32_t DAT_20006bd0;          /* esb tx fail count */
extern uint32_t DAT_20006bd4;          /* esb tx count */
extern uint32_t DAT_2000848c;          /* imu pitch base */
extern uint32_t JDB_PANEL_ID;
extern char DAT_2001093c[];            /* net core build time */
extern uint8_t sys_settings_dirty;           /* settings dirty flag */
extern uint8_t deferred_text_ack_idx;
extern uint8_t deferred_text_ack_total;
extern uint8_t deferred_text_ack_cmd;
extern atomic_t DAT_20008480;           /* imu/dashboard lock bits */

/* ---- ble_proto.c ---- */
void lock_k_mutex_20007f54(k_timeout_t timeout);
void unlock_k_mutex_20007f54(void);
int spim_transfer(struct ble_context *ctx, uint8_t *buf, uint32_t len);
int FUN_00019d14(struct ble_context *ctx, uint8_t *buf, uint32_t len); /* old name, alias of spim_transfer */
int debug_init(void);
int enqueue_debug(void *msg);
int dequeue_debug(void *msg);
void ble_printk(const char *fmt, ...);
int parse_receiver_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);
int parse_receiver_msg_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);
int send_dmic_msg(struct ble_context *ctx);
void DashboardLockTimerExpiry_callback(struct k_timer *timer);
void ble_process_get_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
void ble_process_put_req(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
int ble_process_req_dispatch(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
void ble_work_thread(void *p1, void *p2, void *p3);
int start_ble_work_thread(struct ble_context *ctx);
int deal_event_to_phone(struct ble_context *ctx, uint8_t *evt);
typedef void (*ble_send_fn_t)(uint8_t *buf, uint32_t len);
int subcontracing_send_data_pkcs7(const uint8_t *data, int len, uint8_t cmd, ble_send_fn_t send);
int mobile_send_notification_to_ble_device_test(const char *title, const char *message,
						 ble_send_fn_t send);
void simulator_ancs_calendar_schedule_trigger(void);
void FUN_00023d38(uint8_t *data, uint32_t len, int dump);
int spec_ble_command_hook(uint8_t *data, uint32_t len);

/* align-2 helpers (stop_ble_advertising, FUN_0007f3da: ble_ancs.c; the rest: ble_proto.c) */
int stop_ble_advertising(void);
bool FUN_0007f3da(void);
int FUN_0007f472(const void *data, size_t len, uint8_t arg, int sel);
int FUN_0007f4a4(uint8_t a, uint8_t b, int sel);
int FUN_0007f4c6(struct ble_context *ctx, uint8_t *buf, uint32_t len);
int FUN_0007f4d2(struct ble_context *ctx);
void FUN_0007f50c(uint8_t *data, uint32_t len);

/* ---- other modules ---- */
int FUN_00019c80(int enable);           /* ble_ancs.c */
struct bt_conn *FUN_00019cec(void);     /* ble_ancs.c */
void FUN_00018ba8(void);
struct ble_context *get_ble_context(void);
int dequeue_bt_data(void *msg);
void dump_hex(const char *tag, const uint8_t *data, uint32_t len);
int ancs_main(struct ble_context *ctx);
int bt_start(void);
int master_process_put_req(struct GlassesState *s, uint8_t *tx, uint8_t *buf, uint32_t len);
uint32_t get_dmic_num_messages(void);
int dequeue_dmic(void *buf);
void FUN_0007ff66(struct GlassesState *s, int arg);
uint8_t FUN_00033754(void);
uint8_t is_master(void);
void change_work_mode(int mode);
uint32_t opt3007_get_max_lux(void);
int FUN_00027664(void);
void transcribe_info_timeout_reset(void);
void even_ai_v2_info_timeout_reset(void);
int FUN_00030458(void);
int FUN_00030484(int arg);
int update_persist_task_status(struct GlassesState *state, int task, int status);
void post_notification_cmd_process(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
bool is_idle(void);
int SendSystemLanguageInfoToSlave(uint8_t lang);
void get_whitelist_app_from_device(struct ble_context *ctx, uint8_t *resp);
void get_notification_counts_cmd_process(struct ble_context *ctx, uint8_t *buf, uint8_t *resp);
uint8_t FUN_00033760(void);
void dump_ancs(const char *tag, struct ancs_notif_data *data);

/* ---- other modules, used by ble_process_put_req() ---- */
void put_whitelist_app_from_app(struct ble_context *ctx, uint8_t *hdr, const uint8_t *data,
				uint16_t len, uint8_t *rsp);
int SendDashBoardStartupModeInfoToSlave(uint8_t mode);
int SendDoubleTapCustomizeToSlave(uint8_t mode);
int SendLongpressTapCustomizeToSlave(uint8_t mode);
uint8_t FUN_000260dc(void);
void FUN_0004d4dc(int64_t ts);
void FUN_0004d4f8(int64_t *ts);
void FUN_0004d494(uint32_t *total_s, int idx, int restart);
void FUN_00025b28(int cmd, uint8_t sys_dirty);
void FUN_0001666c(void);
void set_ncs_mem_initialized(void);
void cleanCalenadrIndex(void);
void cleanStocksIndex(void);
void cleanNewsIndex(void);
uint8_t getNotesIndex(void);
int send_response_data_to_msgqueue(const void *data, uint32_t len);
int requestAudioInfoToApp(uint8_t cmd);
int sendAudioStreamFileToApp(uint8_t cmd, uint8_t block);
int delAudioStreamRecord(uint8_t num);
int deleteQuickNoteData(int index);
int upgradeQuickNoteDataToFlash(int index);
void FUN_0003d7b4(void);
int display_DelayClose(int ms);
void FUN_0008040c(void);
int enqueue_file(const void *data, size_t len);
void setEraseDFU(bool set);
void FUN_000800ca(struct GlassesState *state, int notify);
int onboarding_ble_process(struct GlassesState *gs, const struct ble_req_hdr *hdr,
			   const uint8_t *req, uint8_t *rsp);
uint8_t FUN_00033d5c(void);
void set_brightness_to_panel_reg_in_running(uint8_t level);
extern uint32_t LAST_FILE_CRC;
extern struct k_sem DAT_200085b4;      /* mic_transm_thread trigger (production_test.c) */

#endif /* G1_BLE_PROTO_H_ */

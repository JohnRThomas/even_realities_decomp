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
#include <glasses_state.h>

#include "g1_log.h"

#include "ble_cmd.h"

/* pkcs7 packet reassembly results */
#define PKCS7_PACK_DONE  0xc9 /* last packet received */
#define PKCS7_PACK_ERR   0xca
#define PKCS7_PACK_MORE  0xcb /* more packets follow */

/* Debug log message queue (ble_printk -> phone) */
#define DEBUG_MSG_SIZE 200
#define DEBUG_MSGQ_MAX 20

/* dashboard lock bits (dashboard_lock_reported / dashboard_lock_requested / dashboard_head_up_opened) */
#define DASHBOARD_LOCK_BIT 1 /* bit number */

#define BLE_TX_BUF_SIZE 0x2b8
#define BLE_SMALL_PKT_MAX 20

/* request header handed to ble_process_req_dispatch() */
struct ble_req_hdr {
	uint8_t cmd;
	uint8_t source;
	uint16_t len;
};

#define BLE_WORK_THREAD_STACK_SIZE 0x3000
#define BLE_WORK_THREAD_PRIORITY (-15)




/* ---- types used by ble_process_put_req() ---- */

/* cmd 6 / sub 1: time sync */
struct put_time_sync {
	uint8_t hdr[5];
	uint32_t sec_ts;   /* 0x05 */
	int64_t ms_ts;     /* 0x09 */
} __packed;

/* dashboard schedule entry (schedule_items[8], also read by DashBoard_Reflash) */
struct schedule_item {
	uint8_t valid;
	char title[0x41];
	char time[0x21];
	char location[0x41];
};

/* dashboard stock entry (stock_items[4]) */
struct stock_item {
	uint8_t valid;            /* 0x000 */
	uint8_t change_status;    /* 0x001: 0 / 1 / 2 (dashboard trend arrow) */
	uint16_t image_len;       /* 0x002 */
	char code[0x20];          /* 0x004 */
	char company[0x40];       /* 0x024 */
	char price[0x10];         /* 0x064 */
	char price_change[0x10];  /* 0x074 */
	char change_rate[0x10];   /* 0x084 */
	uint8_t image[0x75e];     /* 0x094 */
};

/* dashboard news entry (news_items[4]) */
struct news_item {
	uint8_t valid;
	char source[0x40];
	char text[0x118];
};




/* quick notes (GlassesState->quicknote) */
struct qn_title {
	char str[0x29];
};



#define PANORAMIC_MAP_SIZE 0x40d0

/* ---- globals defined in ble_proto.c ---- */
extern int tp_app_sync_count;                /* app sync request seen */
extern int nav_app_sync_count;                /* phone heart beat seen */
extern atomic_t dashboard_lock_reported;           /* dashboard lock bits */
extern atomic_t dashboard_lock_requested;           /* dashboard lock bits */
extern struct k_mutex nav_map_mutex; /* navigation data lock */
extern struct k_timer DashboardLockTimer;
extern volatile uint16_t multi_packet_total;  /* multi-packet: total packets */
extern volatile uint16_t multi_packet_cnt;  /* multi-packet: packets received */
extern volatile uint16_t multi_packet_len;  /* multi-packet: bytes received */
/* navigation (ble_process_put_req -> ui_navigation_map.c) */
extern volatile uint8_t nav_pos_updated;   /* position updated */
extern volatile uint8_t nav_panoramic_map_updated;   /* panoramic map updated */
extern uint8_t nav_overview_map_updated;            /* overview map updated */
extern uint8_t nav_text_updated;            /* text info updated */
extern volatile uint8_t nav_panoramic_map_ready;
extern uint8_t nav_overview_map_ready;
extern uint8_t tp_scroll_pending;            /* teleprompter text scrolled */
extern uint8_t nav_overview_map_buf[0x1210];    /* navigation overview map as received */
/* phone data buffers filled by ble_process_put_req (read by DashBoard_Reflash) */
extern struct stock_item stock_items[4];      /* 0x7f2 B each */
extern struct news_item news_items[4];       /* 0x159 B each */
extern struct schedule_item schedule_items[8];   /* 0xa4 B each */
extern volatile uint8_t citywalk_canvas_valid;          /* citywalk map valid */
extern uint8_t panoramic_map_buf[PANORAMIC_MAP_SIZE]; /* panoramic map / citywalk data */
/* inside panoramic_map_buf: citywalk map bitmap, arrow (wide layout), arrow (narrow layout) */
extern uint8_t citywalk_canvas_bitmap[], citywalk_arrow_full[], citywalk_arrow_dual[];
extern uint8_t panoramic_map_mask[];                 /* inside panoramic_map_buf: panoramic map mask */

/* ---- ble_proto.c ---- */
void lock_nav_map_mutex(k_timeout_t timeout);
void unlock_nav_map_mutex(void);
int spim_transfer(struct ble_context *ctx, uint8_t *buf, uint32_t len);
int debug_init(void);
int enqueue_debug(void *msg);
int dequeue_debug(void *msg);
int parse_receiver_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);
int parse_receiver_msg_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);
int send_dmic_msg(struct ble_context *ctx);
int ble_process_req_dispatch(struct ble_context *ctx, struct ble_req_hdr *hdr, uint8_t *data);
int start_ble_work_thread(struct ble_context *ctx);
int deal_event_to_phone(struct ble_context *ctx, uint8_t *evt);
typedef void (*ble_send_fn_t)(uint8_t *buf, uint32_t len);
int subcontracing_send_data_pkcs7(const uint8_t *data, int len, uint8_t cmd, ble_send_fn_t send);
int mobile_send_notification_to_ble_device_test(const char *title, const char *message,
						 ble_send_fn_t send);
void simulator_ancs_calendar_schedule_trigger(void);
void ble_handle_rx_data(uint8_t *data, uint32_t len, int dump);
int spec_ble_command_hook(uint8_t *data, uint32_t len);

/* align-2 helpers */
int save_esb_snapshot(const void *data, size_t len, uint8_t arg, int sel);
int set_esb_recv_state(uint8_t a, uint8_t b, int sel);
/* unprototyped: get_notification_counts_cmd_process() (notification.c) passes a fourth
 * argument (0x1e) that the definition, (ctx, buf, len), does not take */
int spim_transfer_len();
int send_debug_msg(struct ble_context *ctx);
void ble_dispatch_raw_packet(uint8_t *data, uint32_t len);

#endif /* G1_BLE_PROTO_H_ */

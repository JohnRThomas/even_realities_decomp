/*
 * BLE (NUS + ANCS client) module - private types and prototypes.
 * Reconstructed from the G1 v1.63 app core.
 */
#ifndef G1_BLE_ANCS_H_
#define G1_BLE_ANCS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/addr.h>

#define BT_DATA_MSGQ_MAX 96

/* print without the LOG_LEVEL check / "%s(): " prefix */
#define BLE_PRINTK(fmt, ...) \
	do { if (BLE_DEBUG) ble_printk(fmt, ##__VA_ARGS__); else printk(fmt, ##__VA_ARGS__); } while (0)

/* Multi-packet reassembly buffer size (DAT_20010995, defined in ble_ancs.c) */
#define MULTI_PACKET_BUF_SIZE 0x204

/* One queued NUS packet (enqueue_bt_data / dequeue_bt_data) */
struct bt_data_msg {
	uint8_t len;
	uint8_t data[256];
};

/* One ANCS notification as handed to the dashboard (0x1b4 bytes) */
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

/* BLE context embedded in GlassesState at 0x77c (partial) */
struct ble_context {
	void (*start_work_thread)(void);                 /* 0x000 */
	uint8_t pad_004[0x00c - 0x004];
	int (*write)(const uint8_t *data, uint16_t len); /* 0x00c */
	uint8_t pad_010[0x034 - 0x010];
	struct ancs_notif_data notif;                    /* 0x034 */
	struct k_sem ancs_get_attr_data_sem;             /* 0x1e8 */
	struct k_sem ancs_get_attr_req_sem;              /* 0x200 */
	struct k_sem rx_sem;                             /* 0x218 */
	struct k_sem tx_sem;                             /* 0x230 */
	uint8_t receiver_thd_is_running;                 /* 0x248 */
	uint8_t pad_249[3];
	uint8_t *buf_394;                                /* 0x24c */
	uint8_t *buf_8d4;                                /* 0x250 */
	uint8_t *small_buf;                              /* 0x254 */
	uint8_t rx_data[0x100];                          /* 0x258 */
	uint32_t rx_len;                                 /* 0x358 */
	uint32_t rx_pending;                             /* 0x35c */
	uint32_t small_len;                              /* 0x360 */
	volatile uint8_t f_364;                               /* 0x364 */
	volatile uint8_t f_365;                               /* 0x365 */
	volatile uint8_t send_enabled;                          /* 0x366 */
	uint8_t f_367;                                   /* 0x367 */
	uint32_t last_rx_time;                           /* 0x368 */
	uint32_t connected_time;                         /* 0x36c */
	uint8_t pad_370[0x394 - 0x370];
	uint8_t data_394[0x862 - 0x394];                 /* 0x394 */
	uint8_t mac_r[3];                                /* 0x862 (state 0xfde) */
	uint8_t pad_865[0x868 - 0x865];
	uint8_t mac_l[3];                                /* 0x868 (state 0xfe4) */
	uint8_t pad_86b[0x8d4 - 0x86b];
	uint8_t data_8d4[4];                             /* 0x8d4 */
};

/* Partial view of the global vendor state (see src/main.h) */
struct GlassesState {
	uint8_t is_master;                               /* 0x000 (compared to 2) */
	uint8_t f_001;                                   /* 0x001 (1/8: ESB busy) */
	uint8_t esb_channel;                             /* 0x002 */
	uint8_t pad_003[0x080 - 0x003];
	struct k_sem dashboard_position_sem;             /* 0x080 */
	uint8_t pad_098[0x0d5 - 0x098];
	uint8_t f_d5;                                    /* 0x0d5 */
	uint8_t pad_0d6[0x77c - 0x0d6];
	struct ble_context ble_context;                  /* 0x77c */
	uint8_t pad_1054[0x1060 - 0x1054];
	uint32_t dashboard_cmd;                          /* 0x1060 */
	uint8_t pad_1064[0x106c - 0x1064];
	uint8_t bt_state;                                /* 0x106c */
	uint8_t pad_106d[0x1070 - 0x106d];
	uint16_t module_mask;                            /* 0x1070 */
	uint8_t pad_1072[0x1081 - 0x1072];
	bt_addr_le_t bonded_addr;                        /* 0x1081 */
	uint8_t bonded;                                  /* 0x1088 */
	uint8_t force_bind;                              /* 0x1089 */
};

BUILD_ASSERT(sizeof(struct ancs_notif_data) == 0x1b4);
BUILD_ASSERT(offsetof(struct ble_context, rx_sem) == 0x218);
BUILD_ASSERT(offsetof(struct ble_context, send_enabled) == 0x366);
BUILD_ASSERT(offsetof(struct ble_context, data_8d4) == 0x8d4);
BUILD_ASSERT(offsetof(struct GlassesState, ble_context) == 0x77c);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_cmd) == 0x1060);
BUILD_ASSERT(offsetof(struct GlassesState, bonded_addr) == 0x1081);

struct GlassesState *get_dashboard_state(void);

/* other modules */
struct bt_conn;
struct bt_conn *FUN_00019cec(void); /* current connection (ble_ancs.c) */
int stop_ble_advertising(void);
bool FUN_0007f3da(void);
int FUN_00019c80(int enable);
extern uint8_t FUN_00033d5c(void);
extern void FUN_0007ff66(struct GlassesState *s, int arg);
extern void start_ble_work_thread(void);

/* ble_nus.c */
int ble_write_thread(const uint8_t *data, uint16_t len);
int enqueue_bt_data(void *data, uint8_t len);
int dequeue_bt_data(struct bt_data_msg *msg);
int init_nus(void);
struct ble_context *get_ble_context(void);
struct ble_context *FUN_00018320(void); /* old name, alias of get_ble_context */
void ble_context_init(struct ble_context *ctx);

#endif /* G1_BLE_ANCS_H_ */

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
#include <glasses_state.h>

#define BT_DATA_MSGQ_MAX 96

/* Multi-packet reassembly buffer size (multi_packet_buf, defined in ble_ancs.c) */
#define MULTI_PACKET_BUF_SIZE 0x204

/* One queued NUS packet (enqueue_bt_data / dequeue_bt_data) */
struct bt_data_msg {
	uint8_t len;
	uint8_t data[256];
};

/* ble_nus.c */
int ble_write_thread(const uint8_t *data, uint16_t len);
int enqueue_bt_data(void *data, uint8_t len);
int dequeue_bt_data(struct bt_data_msg *msg);
int init_nus(void);
struct ble_context *get_ble_context(void);
void ble_context_init(struct ble_context *ctx);

/* ble_ancs.c */
struct bt_conn;
extern uint8_t multi_packet_buf[MULTI_PACKET_BUF_SIZE]; /* multi-packet reassembly buffer */
struct bt_conn *get_current_conn(void); /* current connection */
int bt_start(void);
int ancs_main(struct ble_context *ctx);
void ancs_delete_notification(uint32_t uid);
int set_ancs_enable(int enable);
int stop_ble_advertising(void);
bool is_ble_device_bound(void);

#endif /* G1_BLE_ANCS_H_ */

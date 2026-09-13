/*
 * "threads" module (dispatch threads, key events, watchdog, master/slave
 * sync, message state) - private types and prototypes.
 * Reconstructed from the G1 v1.63 app core.
 */
#ifndef G1_THREADS_H_
#define G1_THREADS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/atomic.h>
#include <glasses_state.h>

/* print without the LOG_LEVEL check / "%s(): " prefix */
#define G1_PRINTK(fmt, ...) \
	do { if (BLE_DEBUG) ble_printk(fmt, ##__VA_ARGS__); else printk(fmt, ##__VA_ARGS__); } while (0)

/* threads.c */
extern uint8_t watchdog_enabled;
extern struct k_sem nfc_msg_sem;
extern atomic_t close_app_flags;
extern atomic_t dashboard_flags;
extern struct k_mutex screen_payload_mutex;
extern uint8_t new_msg_signal_received;
extern uint8_t msg_array_busy;          /* g_arrMsgContent busy */
extern uint8_t fuel_gauge_stuck;          /* battery level stuck flag */
extern uint8_t can_enter_low_power;
extern uint8_t screen_switch_busy;          /* head gesture in progress */
extern uint8_t push_msg_syncing;
extern uint8_t wear_state_event;
extern uint8_t last_ble_cmd;          /* pending 0xf5 event to phone (0xff: none) */
extern uint8_t deferred_text_ack_cmd;
extern uint8_t deferred_text_ack_idx;
extern uint8_t deferred_text_ack_total;
void update_activity_time(void);
void check_not_disturb_sync(void);
void exit_running_task(struct GlassesState *state, int notify);
uint8_t get_wearing_state(void);
uint8_t get_wear_state_event(void);
void check_work_mode(int in_box, int lid_closed, uint8_t report);
void check_disp_quicknote(void);
uint8_t get_glasses_ble_status(void);
const struct device *get_charger_device(void);
int sync_to_slave(struct GlassesState *state, int cmd, void *data, size_t len);
unsigned int sync_to_master(struct GlassesState *state, int cmd, void *data, size_t len);
void report_event_to_phone(int cmd);
void exit_running_task_keep_status(struct GlassesState *state, int notify);
void exit_temp_task(struct GlassesState *state, int flag);
void exit_silent_mode(void);
void enter_silent_mode(void);
void trigger_key_event(void);
void trigger_nfc_event(void);
int64_t nfc_deadline_set(uint32_t ms);
void init_threads(struct GlassesState *state);
void check_sw0_status(void);
void system_reboot_delayed(void);

/* watchdog.c */
extern int wdt_0_channel_id;
int init_watchdog(void);
int config_watchdog_wait_reset(void);
int watchdog_feed(void);
int watchdog_disable(void);

/* ble_req.c */
struct ble_req;
int master_process_put_req(struct GlassesState *state, struct ble_req *head, uint8_t *out, uint32_t len);

/* system_state.c */
int trigger_screen_state_change(const char *who, struct GlassesState *state, uint8_t on);
int set_imu_on_state(void *dev, struct GlassesState *state, uint32_t on);
int trigger_imu_state_change(void *dev, struct GlassesState *state, bool on);
int global_system_suspend(struct GlassesState *state);
int global_system_resume(struct GlassesState *state);

/* task_status.c */
extern uint8_t task_status_lock;
uint8_t is_persist_task_active(struct GlassesState *state, int mode);
int is_task_running(struct GlassesState *state);
int update_persist_task_status(struct GlassesState *state, int task, int status);
int update_temp_task_status(struct GlassesState *state, int task, int status);
int update_persist_task_status_to_idle(struct GlassesState *state);
int update_persist_task_status_to_wait_blow_head(struct GlassesState *state);
bool task_uses_mic(int task);
bool is_idle(void);

/* message_task.c */
extern uint8_t msg_busy;
void set_msg_timeout_flag(void);
uint8_t take_msg_timeout_flag(void);
int sync_message_signal_to_slave(uint8_t signal);
int send_msg_key_to_master(void);
uint32_t get_msg_stay_time(int type, uint32_t def);
void handle_msg_touch_key(void);
int screen_task_dispatch(struct GlassesState *state, struct imu_ctx *ctx);
void reset_dash_buf(int clear);

#endif /* G1_THREADS_H_ */

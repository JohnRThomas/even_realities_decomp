/*
 * Module-private declarations for the production-test files
 * (production_test.c, serial_thread.c, serial_port.c).
 * Partial views of shared vendor structures, reconstructed from the v1.63
 * app core.
 */
#ifndef G1_PRODUCTION_TEST_H_
#define G1_PRODUCTION_TEST_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <glasses_state.h>

/* communication channel of the production-test protocol */
enum pt_comm_type {
	PT_COMM_NFC = 0,   /* st25dv mailbox */
	PT_COMM_UART = 1,  /* lpuart */
	PT_COMM_NONE = 2,
};

/* response frame: [cmd][1][3][payload len][payload...] */
typedef int (*pt_cmd_handler_t)(const uint8_t *req, uint32_t req_len, uint8_t **resp,
				uint8_t *resp_len, void *arg);

typedef int pt_cmd_handler_fn(const uint8_t *req, uint32_t req_len, uint8_t **resp,
			      uint8_t *resp_len, void *arg);

struct pt_cmd {
	uint8_t cmd;
	pt_cmd_handler_t handler;
};

/* production_test.c: command handlers of pt_cmd_table */
pt_cmd_handler_fn chnange_test_image, enter_into_testmode, exit_mic_mode, get_assign_channel_info, get_battery_info, get_brightness_info, get_brightness_lum_info, get_canvas_pos_info, get_charge_test_info, get_esb_info, get_firmware_mode, get_flash_burn_info, get_flash_info, get_flash_info_2, get_glasses_sn_info, get_imu_info, get_keyboard_info, get_keyboard_info_2, get_lux_info, get_mac_info, get_mac_info_2, get_mac_info_3, get_mic_info, get_query_sn_info, get_role_info_left, get_role_info_right, get_sn_info, get_version, into_long_trip_mode, power_off_opt3007, power_on_opt3007, resume_panel, set_aging_test_info, set_battery_info, set_brightness, set_brightness_lum_base, set_canvas_pos_info, set_charge_limit, set_comflag, set_glasses_sn_info, set_imu_base, set_lux_base, set_mic_info, set_mic_nocompress, set_panel_voltage, set_restart_mode, set_restart_mode_2, suspend_panel;

/* pt_comm.c */
int comm_write(int type, void *ctx, uint8_t *data, size_t len);
int comm_read(int type, void *ctx, uint8_t **data, uint32_t *len);

/* production_test.c */
extern const struct pt_cmd pt_cmd_table[48];
extern struct k_thread mic_transm_thread_data;
K_THREAD_STACK_DECLARE(mic_transm_thread_stack, 1024);
extern struct k_sem mic_transm_sem;             /* mic_transm_thread trigger */
int process_pt_protocol(int type, const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg);
int64_t set_pt_deadline(void);                   /* pt_timeout_ms = uptime + 10 s */
void mic_transm_thread(void *p1, void *p2, void *p3);
void start_mic_transm_thread(void);
void enable_charger_retry(void);
uint8_t get_pt_level_flag(void);
uint8_t get_pt_level(void);
uint8_t set_pt_level(uint8_t level);
uint8_t get_aging_charge_limit(void);
int is_ext_flash_burned(void);
uint8_t get_pt_test_mode(void);
void set_test_mode(uint8_t mode);
uint8_t get_aging_phase(void);                /* 1 charging, 2 discharging */
void set_aging_mode(uint8_t v);
uint8_t get_aging_mode(void);
void enter_aging_mode(void);
void exit_aging_mode(void);
void aging_charge_test(int interval);
void aging_charge_check(void);
void start_aging_mode_thread(void);
uint8_t get_pt_version_major(void);

/* pt_data.c */
int setUARTDevice(const struct device *dev);
int setNFCDevice(void *nfc);
int lock_sensor_mutex(void);
int unlock_sensor_mutex(void);
int process_pt_data(void *arg);

/* serial_thread.c */
int init_serial_comm(void);

/* serial_port.c */
void serial_rx_clear(void);
int lpuart_async_a(const struct device *dev);
int lpuart_async_b(const struct device *dev, uint8_t *data, size_t len);
int read_serial_data(const struct device *dev, uint8_t **data, uint32_t *len);

#endif /* G1_PRODUCTION_TEST_H_ */

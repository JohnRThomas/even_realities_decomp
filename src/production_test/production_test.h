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

/* communication channel of the production-test protocol */
enum pt_comm_type {
	PT_COMM_NFC = 0,   /* st25dv mailbox */
	PT_COMM_UART = 1,  /* lpuart */
	PT_COMM_NONE = 2,
};

/* Partial view of the global vendor state behind GLOBAL_STATE */
struct GlassesState {
	bool is_master;                          /* 0x000 */
	uint8_t work_mode;                       /* 0x001 */
	uint8_t esb_channel;                     /* 0x002 */
	uint8_t esb_master_addr;                 /* 0x003 */
	uint8_t esb_slave_addr;                  /* 0x004 */
	uint8_t pad_005[0x068 - 0x005];
	struct k_sem sem_68;                     /* 0x068 */
	uint8_t pad_080[0xd5 - 0x068 - sizeof(struct k_sem)];
	uint8_t f_d5;                            /* 0x0d5 */
	uint8_t pad_0d6[0x788 - 0xd6];
	int (*send_data)(uint8_t *data, int len); /* 0x788 */
	uint8_t pad_78c[0xb6c - 0x78c];
	uint8_t jbd_panel_context[0x20];         /* 0xb6c */
	void (*set_brightness_cb)(void *panel, uint8_t level); /* 0xb8c */
	uint8_t pad_b90[0xec8 - 0xb90];
	int panel_init_done;                     /* 0xec8 (jbd panel context) */
	uint8_t pad_ecc[0xed4 - 0xecc];
	uint8_t panel_voltage;                   /* 0xed4 */
	uint8_t panel_brightness_level;          /* 0xed5 */
	uint8_t pad_ed6[2];
	uint16_t brightness_lum[4];              /* 0xed8 */
	uint8_t pad_ee0[0xf68 - 0xee0];
	uint32_t imu_f68;                        /* 0xf68 */
	uint8_t pad_f6c[0xf98 - 0xf6c];
	uint32_t lux_base_max;                   /* 0xf98 (opt3007_context + 0x14) */
	uint8_t pad_f9c[0xfa4 - 0xf9c];
	uint32_t lux_base[3];                    /* 0xfa4 */
	uint8_t pad_fb0[4];
	int luminance_curve;                     /* 0xfb4 */
	int lux_fb8;                             /* 0xfb8 */
	float lux_k_min;                         /* 0xfbc */
	float lux_k_max;                         /* 0xfc0 */
	uint8_t battery_fc4;                     /* 0xfc4 */
	uint8_t pad_fc5[3];
	uint8_t battery_fc8;                     /* 0xfc8 */
	uint8_t pad_fc9[3];
	int8_t battery_fcc;                      /* 0xfcc */
	uint8_t pad_fcd;
	int16_t battery_fce;                     /* 0xfce */
	uint8_t pad_fd0[0xfde - 0xfd0];
	uint8_t master_mac[6];                   /* 0xfde */
	uint8_t slave_mac[6];                    /* 0xfe4 */
	uint8_t f_fea;                           /* 0xfea */
	uint8_t pad_feb[0x1044 - 0xfeb];
	int f_1044;                              /* 0x1044 */
	uint8_t pad_1048[0x1089 - 0x1048];
	uint8_t f_1089;                          /* 0x1089 */
	uint16_t canvas_x;                       /* 0x108a */
	uint16_t canvas_y;                       /* 0x108c */
	uint8_t pad_108e[2];
	uint32_t touch_diff;                     /* 0x1090 */
	uint32_t imu_base[3];                    /* 0x1094 */
	uint8_t comflag;                         /* 0x10a0 */
	uint8_t flash_10a1;                      /* 0x10a1 */
	uint16_t flash_page_count;               /* 0x10a2 */
	uint8_t mic_nocompress;                  /* 0x10a4 */
	uint8_t pad_10a5[3];
	uint8_t charge_10a8;                     /* 0x10a8 */
	uint8_t charge_10a9;                     /* 0x10a9 */
	uint8_t pad_10aa[2];
	uint32_t charge_10ac;                    /* 0x10ac */
	uint32_t charge_10b0;                    /* 0x10b0 */
	uint32_t charge_10b4;                    /* 0x10b4 */
	uint32_t charge_10b8;                    /* 0x10b8 */
	uint16_t charge_10bc[6];                 /* 0x10bc */
	uint8_t charge_10c8;                     /* 0x10c8 */
	uint8_t pad_10c9[3];
	uint32_t charge_10cc;                    /* 0x10cc */
	uint8_t charge_10d0;                     /* 0x10d0 */
	uint8_t charge_10d1;                     /* 0x10d1 */
	uint8_t pad_10d2[0x10d8 - 0x10d2];
	uint8_t charge_limit_upper;              /* 0x10d8 */
	uint8_t charge_limit_lower;              /* 0x10d9 */
};

BUILD_ASSERT(offsetof(struct GlassesState, send_data) == 0x788);
BUILD_ASSERT(offsetof(struct GlassesState, set_brightness_cb) == 0xb8c);
BUILD_ASSERT(offsetof(struct GlassesState, panel_brightness_level) == 0xed5);
BUILD_ASSERT(offsetof(struct GlassesState, imu_f68) == 0xf68);
BUILD_ASSERT(offsetof(struct GlassesState, battery_fce) == 0xfce);
BUILD_ASSERT(offsetof(struct GlassesState, f_1044) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, touch_diff) == 0x1090);
BUILD_ASSERT(offsetof(struct GlassesState, flash_page_count) == 0x10a2);
BUILD_ASSERT(offsetof(struct GlassesState, charge_10b0) == 0x10b0);
BUILD_ASSERT(offsetof(struct GlassesState, charge_10bc) == 0x10bc);
BUILD_ASSERT(offsetof(struct GlassesState, charge_10d0) == 0x10d0);

BUILD_ASSERT(offsetof(struct GlassesState, master_mac) == 0xfde);
BUILD_ASSERT(offsetof(struct GlassesState, f_d5) == 0xd5);
BUILD_ASSERT(offsetof(struct GlassesState, panel_init_done) == 0xec8);
BUILD_ASSERT(offsetof(struct GlassesState, f_fea) == 0xfea);
BUILD_ASSERT(offsetof(struct GlassesState, charge_10ac) == 0x10ac);
BUILD_ASSERT(offsetof(struct GlassesState, lux_base_max) == 0xf98);
BUILD_ASSERT(offsetof(struct GlassesState, lux_k_max) == 0xfc0);
BUILD_ASSERT(offsetof(struct GlassesState, charge_10cc) == 0x10cc);
BUILD_ASSERT(offsetof(struct GlassesState, charge_limit_upper) == 0x10d8);

struct GlassesState *get_dashboard_state(void);

/* system settings record as stored in flash (read_sys_settting_from_flash) */
struct sys_settings {
	uint8_t pad_00[8];
	uint8_t esb_channel;                     /* 0x08 */
	uint8_t pad_09[3];
	uint32_t imu_base;                       /* 0x0c */
	uint32_t lux_base_max;                   /* 0x10 */
	uint8_t panel_voltage;                   /* 0x14 */
	uint8_t serial_number[14];               /* 0x15 */
	uint8_t pad_23[0x35 - 0x23];
	uint8_t glasses_sn[11];                  /* 0x35 */
	uint8_t pad_40[0x55 - 0x40];
	uint8_t esb_master_addr;                 /* 0x55 */
	uint8_t esb_slave_addr;                  /* 0x56 */
	uint8_t pad_57[0x64 - 0x57];
	uint32_t lux_base[3];                    /* 0x64: [0] = GlassesState 0xfa8, [1] = 0xfa4, [2] = 0xfac */
	uint8_t pad_70[4];
	uint16_t lum_base[3];                    /* 0x74 */
	uint8_t pad_7a[0x98 - 0x7a];
};

BUILD_ASSERT(sizeof(struct sys_settings) == 0x98);
BUILD_ASSERT(offsetof(struct sys_settings, lux_base) == 0x64);

/* user settings record (read_usr_settting_from_flash) */
struct usr_settings {
	uint8_t pad_00[0x15];
	uint8_t charge_limit_upper;              /* 0x15 */
	uint8_t charge_limit_lower;              /* 0x16 */
	uint8_t pad_17[0x2c - 0x17];
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

/* production_test.c: command handlers of pt_cmd_table (serial_thread.c) */
pt_cmd_handler_fn chnange_test_image, enter_into_testmode, exit_mic_mode, get_assign_channel_info, get_battery_info, get_brightness_info, get_brightness_lum_info, get_canvas_pos_info, get_charge_test_info, get_esb_info, get_firmware_mode, get_flash_burn_info, get_flash_info, get_flash_info_2, get_glasses_sn_info, get_imu_info, get_keyboard_info, get_keyboard_info_2, get_lux_info, get_mac_info, get_mac_info_2, get_mac_info_3, get_mic_info, get_query_sn_info, get_role_info_left, get_role_info_right, get_sn_info, get_version, into_long_trip_mode, power_off_opt3007, power_on_opt3007, resume_panel, set_aging_test_info, set_battery_info, set_brightness, set_brightness_lum_base, set_canvas_pos_info, set_charge_limit, set_comflag, set_glasses_sn_info, set_imu_base, set_lux_base, set_mic_info, set_mic_nocompress, set_panel_voltage, set_restart_mode, set_restart_mode_2, suspend_panel;

/* serial_thread.c */
extern const struct pt_cmd pt_cmd_table[48];

/* production_test.c */
int comm_write(int type, void *ctx, uint8_t *data, size_t len);
int comm_read(int type, void *ctx, uint8_t **data, uint32_t *len);
int process_pt_protocol(int type, const uint8_t *req, uint32_t req_len, uint8_t **resp,
			uint8_t *resp_len, void *arg);
void mic_transm_thread(void *p1, void *p2, void *p3);
extern struct k_thread mic_transm_thread_data;
K_THREAD_STACK_DECLARE(mic_transm_thread_stack, 1024);

/* serial_port.c */
void serial_rx_clear(void);
int lpuart_async_a(const struct device *dev);
int lpuart_async_b(const struct device *dev, uint8_t *data, size_t len);
int read_serial_data(const struct device *dev, uint8_t **data, uint32_t *len);

/* serial_thread.c */
int setUARTDevice(const struct device *dev);
int process_pt_data(void *arg);

/* aw93203_port.c: PT bus lock flag */
uint8_t FUN_0003214c(void);
void FUN_00032158(void);
void FUN_00032164(void);

/* production_test.c accessors called by other modules (old FUN_ names kept as aliases there) */
void enable_charger_retry(void);              /* FUN_000336ec */
uint8_t get_pt_level_flag(void);              /* FUN_00033754 */
uint8_t get_pt_level(void);                   /* FUN_00033760 */
uint8_t set_pt_level(uint8_t level);          /* FUN_00033770 */
int64_t set_pt_deadline(void);                   /* FUN_00033b18: pt_timeout_ms = uptime + 10 s */
uint8_t get_pt_test_mode(void);               /* FUN_00033d5c */
uint8_t get_aging_phase(void);                /* FUN_00033e20: 1 charging, 2 discharging */
void set_aging_mode(uint8_t v);               /* FUN_00033e2c */
uint8_t get_aging_mode(void);                 /* FUN_00033e38 */

#endif /* G1_PRODUCTION_TEST_H_ */

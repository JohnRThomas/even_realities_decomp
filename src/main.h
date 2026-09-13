/*
 * Declarations of src/main.c (and partial views of shared
 * vendor structures, reconstructed from the v1.63 app core).
 */
#ifndef G1_MAIN_H_
#define G1_MAIN_H_

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/regulator.h>
#include <glasses_state.h>

/* Copy of the private config struct of drivers/regulator/regulator_npm1300.c */
struct regulator_npm1300_config {
	struct regulator_common_config common;
	const struct device *mfd;
	uint8_t source;
	int32_t retention_uv;
	struct gpio_dt_spec enable_gpios;
	struct gpio_dt_spec retention_gpios;
	struct gpio_dt_spec pwm_gpios;
};

extern struct GlassesState *GLOBAL_STATE;

/*
 * Memory block at 0x2007fc00, retained across reboots / shared with the
 * bootloader and the network core.
 */
struct ncs_mem {
	uint32_t ts;              /* 0x00 */
	uint8_t weather_icon;             /* 0x04 */
	uint8_t temperature;             /* 0x05 */
	uint8_t pad_06[2];
	uint64_t ms_ts;            /* 0x08 */
	uint8_t retained_buf_a[0x25];       /* 0x10 */
	uint8_t retained_buf_b[0x2a];       /* 0x35 */
	uint8_t temp_unit;             /* 0x5f */
	uint8_t time_disp_mode;             /* 0x60 */
	uint8_t retained_a;             /* 0x61 */
	uint8_t retained_b;             /* 0x62 */
	bool erase_dfu;           /* 0x63 */
	uint32_t magic;           /* 0x64 */
	uint8_t retained_c;             /* 0x68 */
	uint8_t notes_index;      /* 0x69 */
	uint8_t pad_6a[6];
	uint8_t pt_level;             /* 0x70 */
};

/*
 * The block is a linked object (the code addresses it through a literal
 * that GCC cannot fold, e.g. 0x12345678 is not derived from its address),
 * placed at 0x2007fc00 by the linker.
 */
extern struct ncs_mem ncs_mem;
#define NCS_MEM (&ncs_mem)
#define NCS_MEM_MAGIC 0x12345678

/* main.c */
extern uint8_t slave_msg_key_pending;  /* new message flag */
extern char net_build_time[32]; /* net core build time */
extern int esb_signal;      /* esb signal */
extern int esb_rx_count;      /* esb rx count */
extern int esb_tx_fail_count;      /* esb tx fail count */
extern int esb_tx_count;      /* esb tx count */
int power_for_panel(void);
int power_down_panel(void);
int runtime_info_sync(struct GlassesState *gs);
int getDeviceRole(void);
/* returns uint8_t; ble_ancs.c was built against an int prototype (bt_start's code
 * depends on it) and defines IS_MASTER_INT_PROTOTYPE before including this header */
#ifdef IS_MASTER_INT_PROTOTYPE
int is_master(void);
#else
uint8_t is_master(void);
#endif
void set_ncs_mem_ts(uint32_t ts);
bool getEraseDFU(void);
void setEraseDFU(bool set);
void set_ncs_mem_pt_level(uint8_t val);
void set_ncs_mem_initialized(void);
int is_ncs_mem_initialized(void);
void save_dashboard_ts_to_ncs_mem(void);
void restore_dashboard_ts_from_ncs_mem(void);
void set_ncs_mem_notes_index(uint8_t idx);
void deinit_ncs_memory(void);
int erase_dfu_flash(void);
int set_shipmode(int enable);
void set_band_for_ESB(uint8_t band);
int get_work_mode(void);
int change_work_mode(int mode);
/* power hooks of the flash module (empty in this build) */
void ext_flash_power_up(void);
void ext_flash_power_down(void);

#endif /* G1_MAIN_H_ */

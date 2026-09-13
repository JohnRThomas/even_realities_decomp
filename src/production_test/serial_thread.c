/*
 * Production-test link layer: selects the transport (NFC mailbox or lpuart),
 * reads one request, runs the PT protocol and writes the response back.
 *
 * Original path: src/production_test/serial_thread.c (from the __ASSERT
 * __FILE__ string; the assert in init_serial_port() sits at line 46).
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>

#include "g1_log.h"
#include "production_test.h"

void set_box_status(int status, bool closed);
int64_t nfc_deadline_set(uint32_t ms);  /* defined in threads.c; callers ignore the result */
void change_work_mode(int mode);
void erase_audio_buffer(void);
int enable_charger(void);
void FUN_0007fc18(void *ctx);
void FUN_0007fc2c(void *ctx);

extern uint8_t can_enter_low_power;

/* current production-test transport */
static struct {
	void *nfc;                       /* st25dv context */
	const struct device *uart;       /* lpuart */
	uint8_t type;                    /* enum pt_comm_type */
} PTR_20002424 = {
	.uart = (const struct device *)1,
};

#define PT_COMM_DEV()                                                               \
	(PTR_20002424.type == PT_COMM_NFC ? PTR_20002424.nfc : (void *)PTR_20002424.uart)
static uint8_t lpuart_ready;             /* lpuart initialised */
static uint8_t pt_resp_buf[50];         /* response buffer */

static uint8_t pt_req_buf[256];        /* request buffer */

/*
 * The mic transfer thread is created here, not in production_test.c: in the
 * target mic_transm_thread is laid out among the handlers of production_test.c
 * (0x33498), which GCC only does when its address is not taken in that file,
 * and this function directly precedes setUARTDevice.
 */
void start_mic_transm_thread(void)
{
	k_thread_create(&mic_transm_thread_data, mic_transm_thread_stack, K_THREAD_STACK_SIZEOF(mic_transm_thread_stack),
			mic_transm_thread, NULL, NULL, NULL, -12, 0, K_NO_WAIT);
}

int setUARTDevice(const struct device *dev)
{
	if (dev == NULL) {
		return -1;
	}

	if (PTR_20002424.uart != dev) {
		PTR_20002424.uart = dev;
	}
	PTR_20002424.type = PT_COMM_UART;

	return 0;
}

int FUN_000346b4(void *nfc)
{
	if (nfc == NULL) {
		return -1;
	}

	if (PTR_20002424.nfc != nfc) {
		PTR_20002424.nfc = nfc;
	}
	PTR_20002424.type = PT_COMM_NFC;

	return 0;
}

int lock_sensor_mutex(void)
{
	if (PTR_20002424.nfc) {
		FUN_0007fc18(PTR_20002424.nfc);
	}

	return 0;
}

int unlock_sensor_mutex(void)
{
	if (PTR_20002424.nfc) {
		FUN_0007fc2c(PTR_20002424.nfc);
	}

	return 0;
}

int process_pt_data(void *arg)
{
	uint8_t *p;
	uint8_t cmd;
	int ret;

	if (PTR_20002424.type == PT_COMM_NONE ||
	    (PTR_20002424.type == PT_COMM_NFC && PTR_20002424.nfc == NULL) ||
	    (PTR_20002424.type == PT_COMM_UART && PTR_20002424.uart == NULL)) {
		printk("comm para is error\n");
		return -1;
	}

	uint32_t resp_len = 0;
	uint32_t req_len = 0;
	uint8_t *req = pt_req_buf;
	uint8_t *resp = pt_resp_buf;

	FUN_00032158();
	if (comm_read(PTR_20002424.type,
		      PT_COMM_DEV(),
		      &req, &req_len)) {
		FUN_00032164();
		return -2;
	}

	if (process_pt_protocol(PTR_20002424.type, pt_req_buf, (uint8_t)req_len, &resp,
				(uint8_t *)&resp_len, arg)) {
		printk("process_pt_protocol is failed\n");
		FUN_00032164();
		return -3;
	}

	ret = comm_write(PTR_20002424.type,
			 PT_COMM_DEV(),
			 resp, (uint8_t)resp_len);
	if (ret) {
		printk("comm_write is failed\n");
		FUN_00032164();
		return -4;
	}
	FUN_00032164();

	if (resp[9] == 0x80) {
		k_msleep(1000);
		resp[9] = 0;
		FUN_00032158();
		comm_write(PTR_20002424.type, PTR_20002424.nfc, resp, (uint8_t)resp_len);
		FUN_00032164();
	}

	p = resp;
	if (PTR_20002424.type != PT_COMM_NFC) {
		p += 4;
	}

	cmd = p[0];
	if (cmd == 0x1b) {
		if (p[8]) {
			erase_audio_buffer();
		}
	}
	if (cmd == 0x13) {
		if ((p[4] & ~4) == 0) {
			if (enable_charger()) {
				ret = -5;
			}
		}
	}
	if (cmd == 0x06) {
		if (p[2] == 2) {
			can_enter_low_power = 1;
			set_box_status(1, true);
			nfc_deadline_set(10000);
		} else {
			printk("enter into long trip \n");
			k_msleep(10000);
			change_work_mode(7);
		}
	}
	if (cmd == 0x0b) {
		G1_LOG_ERR("sys reboot because process_pt_data cmd PTP_DEVICE_RESTART\n");
		k_msleep(300);
		sys_reboot(SYS_REBOOT_COLD);
	}
	if (cmd == 0x3c) {
		if (p[4] == 0) {
			G1_LOG_ERR("sys reboot because process_pt_data cmd %d and ACK_SUCC\n", cmd);
			k_msleep(300);
			sys_reboot(SYS_REBOOT_COLD);
		}
	}
	if (cmd == 0x01) {
		if (p[4] == 0) {
			G1_LOG_ERR("sys reboot because process_pt_data cmd ACK_SUCC\n");
			k_msleep(300);
			sys_reboot(SYS_REBOOT_COLD);
		}
	}

	return ret;
}

int init_serial_port(void)
{
	const struct device *lpuart = DEVICE_DT_GET(DT_NODELABEL(uart0));

	if (lpuart_ready) {
		return 0;
	}

#line 46 "../src/production_test/serial_thread.c"
	__ASSERT(device_is_ready(lpuart), "LPUART device not ready");

	if (lpuart_async_a(lpuart)) {
		lpuart_ready = 0;
		printk("init_serial_port is failed\n");
		return -1;
	}
	lpuart_ready = 1;

	return 0;
}

int init_serial_comm(void)
{
	if (init_serial_port()) {
		return -1;
	}

	if (setUARTDevice(DEVICE_DT_GET(DT_NODELABEL(uart0)))) {
		printk("init_serial_comm is failed\n");
		k_sleep(K_MSEC(500));
		return -2;
	}

	return process_pt_data(NULL) ? -3 : 0;
}

/*
 * Command table of process_pt_protocol() (production_test.c, .rodata 0x8d9b8).
 * It is defined here, not next to its handlers: if the table were in
 * production_test.c the handlers would be address-taken there and GCC would
 * emit them before every other function of that file, unlike the target.
 */
const struct pt_cmd pt_cmd_table[48] = {
	{0x22, get_sn_info},
	{0x24, get_version},
	{0x06, into_long_trip_mode},
	{0x11, set_battery_info},
	{0x13, get_battery_info},
	{0x05, get_mac_info_3},
	{0x07, get_mac_info},
	{0x08, get_mac_info_2},
	{0x0b, set_restart_mode},
	{0x3c, set_panel_voltage},
	{0x40, set_charge_limit},
	{0x01, enter_into_testmode},
	{0x04, get_firmware_mode},
	{0x16, get_flash_info_2},
	{0x17, get_imu_info},
	{0x18, get_keyboard_info_2},
	{0x19, get_mic_info},
	{0x1a, exit_mic_mode},
	{0x1b, set_mic_info},
	{0x1c, get_query_sn_info},
	{0x1d, get_assign_channel_info},
	{0x1e, get_flash_info},
	{0x20, get_lux_info},
	{0x23, get_esb_info},
	{0x25, resume_panel},
	{0x26, suspend_panel},
	{0x28, chnange_test_image},
	{0x29, set_glasses_sn_info},
	{0x2a, get_glasses_sn_info},
	{0x2b, get_role_info_right},
	{0x2c, get_role_info_left},
	{0x2d, set_imu_base},
	{0x2e, set_lux_base},
	{0x2f, get_keyboard_info},
	{0x30, power_on_opt3007},
	{0x31, power_off_opt3007},
	{0x32, set_comflag},
	{0x33, set_brightness},
	{0x35, get_flash_burn_info},
	{0x36, set_brightness_lum_base},
	{0x37, get_brightness_lum_info},
	{0x38, set_canvas_pos_info},
	{0x39, get_canvas_pos_info},
	{0xe1, set_restart_mode_2},
	{0x3a, set_mic_nocompress},
	{0x3b, get_brightness_info},
	{0x3d, get_charge_test_info},
	{0x3e, set_aging_test_info},
};

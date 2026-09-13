/*
 * Production-test link layer: selects the transport (NFC mailbox or lpuart),
 * reads one request, runs the PT protocol and writes the response back.
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>

#include "g1_log.h"
#include "production_test.h"
#include "../aw9320x/aw9320x.h"
#include "../main.h"
#include "../nfc/st25dv.h"
#include "../sensors_audio/sensors_audio.h"
#include "../threads/threads.h"



/* current production-test transport */
static struct {
	void *nfc;                       /* st25dv context */
	const struct device *uart;       /* lpuart */
	uint8_t type;                    /* enum pt_comm_type */
} pt_comm = {
	.uart = (const struct device *)1,
};

#define PT_COMM_DEV()                                                               \
	(pt_comm.type == PT_COMM_NFC ? pt_comm.nfc : (void *)pt_comm.uart)
static uint8_t pt_resp_buf[50];         /* response buffer */

static uint8_t pt_req_buf[256];        /* request buffer */

int setUARTDevice(const struct device *dev)
{
	if (dev == NULL) {
		return -1;
	}

	if (pt_comm.uart != dev) {
		pt_comm.uart = dev;
	}
	pt_comm.type = PT_COMM_UART;

	return 0;
}

int setNFCDevice(void *nfc)
{
	if (nfc == NULL) {
		return -1;
	}

	if (pt_comm.nfc != nfc) {
		pt_comm.nfc = nfc;
	}
	pt_comm.type = PT_COMM_NFC;

	return 0;
}

int lock_sensor_mutex(void)
{
	if (pt_comm.nfc) {
		eeprom_st25dv_lock(pt_comm.nfc);
	}

	return 0;
}

int unlock_sensor_mutex(void)
{
	if (pt_comm.nfc) {
		eeprom_st25dv_unlock(pt_comm.nfc);
	}

	return 0;
}

int process_pt_data(void *arg)
{
	uint8_t *p;
	uint8_t cmd;
	int ret;

	if (pt_comm.type == PT_COMM_NONE ||
	    (pt_comm.type == PT_COMM_NFC && pt_comm.nfc == NULL) ||
	    (pt_comm.type == PT_COMM_UART && pt_comm.uart == NULL)) {
		printk("comm para is error\n");
		return -1;
	}

	uint32_t resp_len = 0;
	uint32_t req_len = 0;
	uint8_t *req = pt_req_buf;
	uint8_t *resp = pt_resp_buf;

	pt_comm_busy_set();
	if (comm_read(pt_comm.type,
		      PT_COMM_DEV(),
		      &req, &req_len)) {
		pt_comm_busy_clear();
		return -2;
	}

	if (process_pt_protocol(pt_comm.type, pt_req_buf, (uint8_t)req_len, &resp,
				(uint8_t *)&resp_len, arg)) {
		printk("process_pt_protocol is failed\n");
		pt_comm_busy_clear();
		return -3;
	}

	ret = comm_write(pt_comm.type,
			 PT_COMM_DEV(),
			 resp, (uint8_t)resp_len);
	if (ret) {
		printk("comm_write is failed\n");
		pt_comm_busy_clear();
		return -4;
	}
	pt_comm_busy_clear();

	if (resp[9] == 0x80) {
		k_msleep(1000);
		resp[9] = 0;
		pt_comm_busy_set();
		comm_write(pt_comm.type, pt_comm.nfc, resp, (uint8_t)resp_len);
		pt_comm_busy_clear();
	}

	p = resp;
	if (pt_comm.type != PT_COMM_NFC) {
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

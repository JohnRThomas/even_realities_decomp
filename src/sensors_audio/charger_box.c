/*
 * nPM1300 charger register helpers and the charging-case (NFC box) status flags.
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/regulator.h>
#include <zephyr/drivers/mfd/npm1300.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "sensors_audio.h"

struct regulator_npm1300_config {
	struct regulator_common_config common;
	const struct device *mfd;
	uint8_t source;
	int32_t retention_uv;
	struct gpio_dt_spec enable_gpios;
	struct gpio_dt_spec retention_gpios;
	struct gpio_dt_spec pwm_gpios;
};

#define PMIC_LDO2    DEVICE_DT_GET(DT_NODELABEL(pmic_ldo2))
#define NPM_MFD(dev) (((const struct regulator_npm1300_config *)(dev)->config)->mfd)

#define CHGR_BASE           0x03
#define CHGR_OFFSET_EN_SET  0x04
#define CHGR_OFFSET_VTERM   0x0C
#define CHGR_OFFSET_CHG_STAT 0x34

uint8_t nfc_box_status[3];             /* 0x20019a74 */
static uint8_t in_box_last;            /* 0x20019a73 */
static uint8_t lid_closed_last;        /* 0x20019a72 */
static uint8_t charging_last;          /* 0x20019a71 */

int change_termination_voltage(void)
{
	/* VTERM = 4.20 V */
	if (mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO2), CHGR_BASE, CHGR_OFFSET_VTERM, 8) < 0) {
		printk("Could not change termination voltage to 4.2V\n");
		return -1;
	}
	return 0;
}

int enable_charger(void)
{
	if (mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO2), CHGR_BASE, CHGR_OFFSET_EN_SET, 1) < 0) {
		printk("Could not enable charger\n");
		return -1;
	}
	return 0;
}

/* returns 1 while charging, 0 when charging completed / trickle */
int set_charger_status(void)
{
	uint8_t status = 0;

	if (mfd_npm1300_reg_read(NPM_MFD(PMIC_LDO2), CHGR_BASE, CHGR_OFFSET_CHG_STAT, &status) < 0) {
		printk("Could not get charger status\n");
		return -1;
	}
	int s = status;
	int trickle = (s >> 2) & 1;
	int cc = (s >> 3) & 1;
	int cv = (s >> 4) & 1;

	if (trickle || cc) {
		return 0;
	}
	return !cv;
}

uint8_t get_box_status_by_type(uint8_t type)
{
	if (type > 2) {
		return 0xfe;
	}
	return nfc_box_status[type];
}

void set_box_status(uint8_t type, uint8_t status)
{
	if (type > 2) {
		return;
	}
	if (status) {
		nfc_box_status[type] = 1;
	} else {
		nfc_box_status[type] = 0;
	}
}

int is_in_box(void)
{
	uint8_t status = nfc_box_status[0];

	if (in_box_last != status) {
		if (BLE_DEBUG) {
			ble_printk("[csh_debug_box]isInbox is %d \n", status);
		} else {
			printk("[csh_debug_box]isInbox is %d \n", status);
		}
	}
	in_box_last = status;
	return status;
}

uint8_t is_box_lid_closed(void)
{
	uint8_t status = nfc_box_status[1];

	if (lid_closed_last != status) {
		printk("[csh_debug_box]isLidCLose is %d \n", status);
	}
	lid_closed_last = status;
	return status;
}

uint8_t is_box_charging(void)
{
	uint8_t status = nfc_box_status[2];

	if (charging_last != status) {
		printk("[csh_debug_box] isInCharge is %d \n", status);
	}
	charging_last = status;
	return status;
}

void init_box_status(void)
{
	nfc_box_status[0] = 0;
	nfc_box_status[1] = 0;
	nfc_box_status[2] = 0;
}

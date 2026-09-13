/*
 * nPM1300 fuel gauge / charger helpers and charging-box status, derived from
 * the NCS npm1300_fuel_gauge sample (src/fuel_gauge.c).
 * Reconstructed from the v1.63 firmware image.
 */
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/sensor/npm1300_charger.h>
#include <zephyr/drivers/regulator.h>
#include <zephyr/drivers/mfd/npm1300.h>
#include <zephyr/sys/printk.h>

#include "nrf_fuel_gauge.h"

#include "g1_log.h"
#include "sensors_audio.h"

/* other modules */
extern uint8_t pt_comm_busy_get(void);         /* PT bus lock flag */
extern int lock_sensor_mutex(void);
extern int unlock_sensor_mutex(void);
extern const char *get_glasses_name(void);     /* hardware version string */
extern void report_event_to_phone(int arg);
extern int sync_to_slave(struct GlassesState *gs, int cmd, void *data, size_t len);
extern int FUN_000294d0(struct GlassesState *gs, int cmd, void *data, size_t len);
extern void FUN_0007ff66(struct GlassesState *gs, int arg);
extern uint8_t DAT_20019a5e;               /* battery level stuck flag */

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

#define PMIC_LDO2    DEVICE_DT_GET(DT_NODELABEL(pmic_ldo2))
#define NPM_MFD(dev) (((const struct regulator_npm1300_config *)(dev)->config)->mfd)

#define CHGR_BASE           0x03
#define CHGR_OFFSET_EN_SET  0x04
#define CHGR_OFFSET_VTERM   0x0C
#define CHGR_OFFSET_CHG_STAT 0x34

#define DISPLAY_MODE_ABNORMAL_TEMP 0x0c

static int64_t fuel_gauge_ref_time;               /* 0x20004930 */
static float fg_last_soc;                 /* 0x20008554 */
static uint32_t fg_last_soc_time;         /* 0x20008550 */

static const struct battery_model battery_model = {
#include "battery_model.inc"
};

uint8_t nfc_box_status[3];             /* 0x20019a74 */
static uint8_t in_box_last;            /* 0x20019a73 */
static uint8_t lid_closed_last;        /* 0x20019a72 */
static uint8_t charging_last;          /* 0x20019a71 */
static uint8_t zero_current_count;     /* 0x20019a70 */

int read_sensors(const struct device *charger, float *voltage, float *current, float *temp)
{
	struct sensor_value value;
	int ret;

	ret = sensor_sample_fetch(charger);
	if (ret < 0) {
		return ret;
	}

	sensor_channel_get(charger, SENSOR_CHAN_GAUGE_VOLTAGE, &value);
	*voltage = (float)value.val1 + ((float)value.val2 / 1000000);

	sensor_channel_get(charger, SENSOR_CHAN_GAUGE_TEMP, &value);
	*temp = (float)value.val1 + ((float)value.val2 / 1000000);

	sensor_channel_get(charger, SENSOR_CHAN_GAUGE_AVG_CURRENT, &value);
	*current = (float)value.val1 + ((float)value.val2 / 1000000);

	return 0;
}

int fuel_gauge_init(const struct device *charger)
{
	struct sensor_value value;
	struct nrf_fuel_gauge_init_parameters parameters = { .model = &battery_model };
	int ret;

	ret = read_sensors(charger, &parameters.v0, &parameters.i0, &parameters.t0);
	if (ret < 0) {
		return ret;
	}

	sensor_channel_get(charger, SENSOR_CHAN_GAUGE_DESIRED_CHARGING_CURRENT, &value);

	ret = nrf_fuel_gauge_init(&parameters, NULL);
	if (ret < 0) {
		return ret;
	}

	fuel_gauge_ref_time = k_uptime_get();

	return 0;
}

bool is_old_board(void)
{
	const char *hw = get_glasses_name();

	if (hw[4] == 'E' && hw[5] == 'G' && hw[6] == 'P') {
		if (hw[7] == '0') {
			return true;
		}
		if (hw[7] == '1') {
			return hw[8] >= '0' && hw[8] <= '3';
		}
	}
	return false;
}

int fuel_gauge_update(const struct device *charger)
{
	float voltage;
	float current;
	float temp;
	float soc = 0;
	float new_soc;
	int retry = 11;
	int64_t delta;
	uint32_t now;
	int ret;

	while (1) {
		if (pt_comm_busy_get()) {
			if (soc > 0) {
				goto report;
			}
			return 0;
		}
		lock_sensor_mutex();
		ret = read_sensors(charger, &voltage, &current, &temp);
		unlock_sensor_mutex();
		if (ret < 0) {
			printk("Error: Could not read from charger device\n");
			return ret;
		}

		delta = k_uptime_get() - fuel_gauge_ref_time;
		if (delta >= 1000) {
			soc = nrf_fuel_gauge_process(voltage, current, temp, (float)delta / 1000.f, NULL);
			if (current != 0 || --retry == 0 || !(soc < 100) || !(soc > 0)) {
				break;
			}
			k_sleep(K_MSEC(5));
		} else {
			return -1;
		}
	}
	fuel_gauge_ref_time = k_uptime_get();

report:
	G1_LOG_ERR("V: %.3f, I: %.3f, T: %.2f\n", voltage, current, temp);

	now = k_uptime_get();
	if ((soc != 0 && fg_last_soc != soc) || soc >= 100) {
		fg_last_soc_time = now;
		fg_last_soc = soc;
	} else if (now - fg_last_soc_time >= 120000) {
		DAT_20019a5e = 1;
	}

	if (is_old_board()) {
		new_soc = soc * 1.25f;
	} else {
		new_soc = soc;
	}
	G1_LOG_ERR("Original soc %.2f, New Soc %.2f, %s\n", soc, new_soc, get_glasses_name());

	if (new_soc < 0 || new_soc >= 150) {
		new_soc = 0;
	} else if (new_soc >= 100) {
		new_soc = 100;
	}
	if ((new_soc >= 93.5f && new_soc < 94.0f) || (new_soc >= 94.5f && new_soc < 95.0f)) {
		get_dashboard_state()->battery_soc_flag = 1;
	} else {
		get_dashboard_state()->battery_soc_flag = 0;
	}
	get_dashboard_state()->battery_soc = new_soc;
	get_dashboard_state()->battery_voltage = voltage * 100 - 200;

	if (current != 0) {
		get_dashboard_state()->battery_current = (current + 0.128) * 1000.0;
		get_dashboard_state()->battery_current_ma = current * 1000;
		zero_current_count = 0;
	} else if (++zero_current_count > 5) {
		zero_current_count = 0;
		get_dashboard_state()->battery_current = (current + 0.128) * 1000.0;
		get_dashboard_state()->battery_current_ma = current * 1000;
	}

	get_dashboard_state()->battery_temp = temp;
	get_dashboard_state()->battery_temp_x100 = temp * 100;

	if ((temp >= 60 && temp < 120) || (temp >= -50 && temp <= -20)) {
		if (get_dashboard_state()->display_mode != DISPLAY_MODE_ABNORMAL_TEMP) {
			report_event_to_phone(4);
			if (get_dashboard_state()->is_master == 1) {
				sync_to_slave(get_dashboard_state(), 4, NULL, 0);
				FUN_0007ff66(get_dashboard_state(), 0);
			} else {
				FUN_000294d0(get_dashboard_state(), 8, NULL, 0);
			}
			get_dashboard_state()->display_mode = DISPLAY_MODE_ABNORMAL_TEMP;
			FUN_0007ff66(get_dashboard_state(), 1);
			G1_LOG_ERR("#############################Abnormal "
				   "temperature################################\n\n");
		}
	}
	return 0;
}

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

uint8_t is_in_box(void)
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

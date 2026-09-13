/*
 * TI OPT3007 ambient light sensor (OPT3001 compatible), derived from
 * zephyr/drivers/sensor/opt3001/opt3001.c, plus the panel LDSW1 power switch.
 * Reconstructed from the v1.63 firmware image.
 */
#include <errno.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/regulator.h>
#include <zephyr/drivers/mfd/npm1300.h>

#include "g1_log.h"
#include "sensors_audio.h"

#define OPT3001_I2C_ADDR 0x45

#define OPT3001_REG_RESULT          0x00
#define OPT3001_REG_CONFIG          0x01
#define OPT3001_REG_MANUFACTURER_ID 0x7E
#define OPT3001_REG_DEVICE_ID       0x7F

#define OPT3001_MANUFACTURER_ID_VALUE 0x5449
#define OPT3001_DEVICE_ID_VALUE       0x3001

#define OPT3001_CONVERSION_MODE_MASK       (BIT(10) | BIT(9))
#define OPT3001_CONVERSION_MODE_CONTINUOUS (BIT(10) | BIT(9))

#define OPT3001_SAMPLE_EXPONENT_SHIFT 12
#define OPT3001_MANTISSA_MASK         0xfff

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

#define PMIC_LDO1    DEVICE_DT_GET(DT_NODELABEL(pmic_ldo1))
#define NPM_MFD(dev) (((const struct regulator_npm1300_config *)(dev)->config)->mfd)

/* .data 0x200023fc: bus + address; only .bus is used, the address is a constant */
struct i2c_dt_spec opt3001_i2c_device = {
	.bus = DEVICE_DT_GET(DT_NODELABEL(i2c1)),
	.addr = OPT3001_I2C_ADDR,
};

static struct opt3007_context *opt3007_ctx;  /* 0x2000854c */
static bool opt3007_ready;                   /* 0x20019a6f */
static uint8_t als_level;                    /* 0x20019a6e */

static int opt3001_reg_read(uint8_t reg, uint16_t *val)
{
	uint8_t tx_buf[1];
	uint8_t value[2] = { 0 };

	if (!device_is_ready(opt3001_i2c_device.bus)) {
		G1_LOG_ERR("Bus device is not ready\n");
		return -ENODEV;
	}
	tx_buf[0] = reg;
	if (i2c_write_read(opt3001_i2c_device.bus, OPT3001_I2C_ADDR, tx_buf, 1, value, 2) < 0) {
		G1_LOG_ERR("ERR: opt3007 i2c read addr=0x%x,\n", OPT3001_I2C_ADDR);
		return -ENOENT;
	}
	*val = ((uint16_t)value[0] << 8) + value[1];
	return 0;
}


static int opt3001_reg_write(uint8_t reg, uint16_t val)
{
	uint8_t tx_buf[3] = { reg, val >> 8, val & 0xff };
	int ret;

	if (!device_is_ready(opt3001_i2c_device.bus)) {
		G1_LOG_ERR("Bus device is not ready\n");
		return -ENODEV;
	}
	ret = i2c_write(opt3001_i2c_device.bus, tx_buf, sizeof(tx_buf), OPT3001_I2C_ADDR);
	if (ret < 0) {
		G1_LOG_ERR("opt3007 i2c write err=%d,\n", ret);
		return ret;
	}
	return 0;
}

static int opt3001_reg_update(uint8_t reg, uint16_t mask, uint16_t val)
{
	uint16_t old_val;
	uint16_t new_val;

	if (opt3001_reg_read(reg, &old_val) != 0) {
		return -EIO;
	}

	new_val = old_val & ~mask;
	new_val |= val & mask;

	return opt3001_reg_write(reg, new_val);
}


int opt3007_read(int arg)
{
	uint16_t value;

	if (!opt3007_ready) {
		return -1;
	}
	if (opt3001_reg_read(OPT3001_REG_RESULT, &value) != 0) {
		return -1;
	}
	return (value & OPT3001_MANTISSA_MASK) << (value >> OPT3001_SAMPLE_EXPONENT_SHIFT);
}


static uint8_t als_lux_to_level(int lux)
{
	uint8_t level;

	if (lux < 50) {
		level = lux / 5;
	} else if (lux < 200) {
		level = (lux - 50) / 10 + 10;
	} else if (lux < 1000) {
		level = (lux - 200) / 50 + 25;
	} else if (lux < 10000) {
		level = (lux - 1000) / 1000 + 41;
	} else if (lux < 80000) {
		level = (lux - 10000) / 5000 + 50;
	} else {
		return 42;
	}
	if (level > 41) {
		level = 42;
	}

	return level;
}

/*
 * Ambient light -> brightness level (0..42).  Without a luminance calibration
 * (a0 unset or <= 60000) the raw lux is mapped piecewise; with one, the
 * calibrated lux moves the level between 0/3/6/12/19/26/42 with hysteresis.
 */
uint8_t FUN_00010848(struct opt3007_context *ctx) /* callers pass &gs->opt3007 (0xf84); unused */
{
	int lux;
	uint8_t level;
	float l;

	if (!opt3007_ready) {
		return 0xff;
	}
	lux = opt3007_read(0);
	if (lux == 0 || lux == -1) {
		return 0xff;
	}

	if (get_dashboard_state()->luminance_curve_a0 == 0 ||
	    get_dashboard_state()->luminance_curve_a0 == -1 ||
	    get_dashboard_state()->luminance_curve_a0 <= 60000) {
		return als_lux_to_level(lux);
	}

	l = lux * (get_dashboard_state()->luminance_curve_a0 / 1000000.0);
	level = als_level;
	switch (level) {
	case 0:
		if (l > 2.4) {
			level = 3;
		}
		break;
	case 3:
		if (l > 6.0) {
			level = 6;
		} else if (l < 1.6) {
			level = 0;
		}
		break;
	case 6:
		if (l > 12.0) {
			level = 12;
		} else if (l < 4.0) {
			level = 3;
		}
		break;
	case 12:
		if (l > 120.0) {
			level = 19;
		} else if (l < 8.0) {
			level = 6;
		}
		break;
	case 19:
		if (l > 496.0) {
			level = 26;
		} else if (l < 75.0) {
			level = 12;
		}
		break;
	case 26:
		if (l > 1440.0) {
			level = 42;
		} else if (l < 372.0) {
			level = 19;
		}
		break;
	case 42:
		if (l < 960.0) {
			level = 26;
		}
		break;
	}
	als_level = level;

	return level;
}


int opt3007_get_max_lux(void)
{
	int lux;
	double max_lux;

	if (!opt3007_ready) {
		return -1;
	}
	lux = opt3007_read(0);
	if (lux == 0 || lux == -1) {
		return lux;
	}
	max_lux = (double)((int64_t)lux * get_dashboard_state()->luminance_curve_a0) / 1000000.0;
	G1_LOG_INF("opt3007_get_max_lux %d %f luminance_curve_a0 %d\n", lux, max_lux,
		   get_dashboard_state()->luminance_curve_a0);
	return (int)max_lux;
}


int opt3007_chip_init(struct opt3007_context *ctx)
{
	uint16_t value = 0;

	if (ctx == NULL) {
		ctx = &get_dashboard_state()->opt3007_context;
	}
	opt3007_ctx = ctx;

	G1_LOG_INF("opt3007 init start:\n");

	if (opt3001_reg_read(OPT3001_REG_MANUFACTURER_ID, &value) != 0) {
		G1_LOG_ERR("opt3007 mfg id=0x%x, err\n", value);
		return -EIO;
	}
	G1_LOG_WRN("mfg_id=0x%x,\n", value);
	if (value != OPT3001_MANUFACTURER_ID_VALUE) {
		G1_LOG_ERR("opt3007 Bad manufacturer id 0x%x\n", value);
		return -ENOTSUP;
	}

	if (opt3001_reg_read(OPT3001_REG_DEVICE_ID, &value) != 0) {
		G1_LOG_ERR("opt3007 dev id=0x%x err!\n", value);
		return -EIO;
	}
	G1_LOG_WRN("dev_id=0x%x,\n", value);
	if (value != OPT3001_DEVICE_ID_VALUE) {
		G1_LOG_ERR("opt3007 Bad device id 0x%x\n", value);
		return -ENOTSUP;
	}

	if (opt3001_reg_update(OPT3001_REG_CONFIG, OPT3001_CONVERSION_MODE_MASK,
			       OPT3001_CONVERSION_MODE_CONTINUOUS) != 0) {
		G1_LOG_ERR("opt3007 Failed to set mode to continuous conversion\n");
		return -EIO;
	}

	if (opt3007_ctx != NULL) {
		opt3007_ctx->ready = 1;
	}
	G1_LOG_INF("opt3007 init done!\n");
	opt3007_ready = true;
	return 0;
}


void opt3007_chip_deinit(void)
{
	if (opt3007_ctx != NULL) {
		opt3007_ctx->ready = 0;
	}
	G1_LOG_INF("opt3007_chip_deinit done!\n");
	opt3007_ready = false;
}


void register_opt3007_context(struct opt3007_context *ctx)
{
	ctx->owner = CONTAINER_OF(ctx, struct GlassesState, opt3007_context)->f_b50;
	ctx->init_cb = opt3007_chip_init;
	ctx->read_cb = opt3007_read;
}


int enable_power_for_panel(void)
{
	int ret;

	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO1), 0x08, 0x00, 1);
	if (ret < 0) {
		printk("Could not set ldsw1.\n");
		return 0;
	}
	printk("enable ldsw1 1.8v for panel\n");
	opt3007_chip_init(NULL);
	return 0;
}

int disable_power_for_panel(void)
{
	int ret;

	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO1), 0x08, 0x01, 1);
	if (ret < 0) {
		printk("Could not set ldsw1.\n");
		return 0;
	}
	printk("disable ldsw1 1.8v for panel\n");
	opt3007_chip_deinit();
	return 0;
}

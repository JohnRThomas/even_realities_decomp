/*
 * ARMemul nRF5340 demo application.
 *
 * Exercises every modelled peripheral through the PINNED NCS v2.5.1
 * in-tree drivers (see docs/board-map.md for the wiring):
 *   - LSM6DSO IMU        (zephyr/drivers/sensor/lsm6dso + hal_st, TWIM2)
 *   - OPT3001 light      (zephyr/drivers/sensor/opt3001, TWIM1)
 *   - nPM1300 PMIC       (zephyr/drivers/mfd + sensor/npm1300_charger +
 *                         regulator/regulator_npm1300, TWIM1)
 *   - SAADC AIN3         (zephyr/drivers/adc/adc_nrfx_saadc)
 *   - MX25U QSPI NOR     (zephyr/drivers/flash/nrf_qspi_nor)
 *   - PDM microphone     (zephyr/drivers/audio/dmic_nrfx_pdm)
 *   - buttons            (gpio-keys on GPIO/P1.09+P1.10)
 *   - JBD display        (custom driver, src/jbd_display.c, SPIM4)
 *
 * Behaviour: a ~2 Hz loop reads every sensor, prints one stable
 * machine-parseable "DEMO ..." block per cycle on the UARTE0 console and
 * renders the readings as text pages on the 640x200 4-bpp display.
 * sw0 cycles the display page, sw1 forces a save of the persistent
 * counters kept in one 4 KiB QSPI-flash sector (read+erase+write).
 *
 * All printed values are integers in micro units unless suffixed:
 *   ACC   micro-m/s^2          GYRO  micro-rad/s
 *   LUX   micro-lux            VBAT/BUCK2 micro-volts
 *   IBAT  micro-amps           AIN3  MV= millivolts, RAW= ADC code
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/sensor/npm1300_charger.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/drivers/regulator.h>
#include <zephyr/drivers/mfd/npm1300.h>
#include <zephyr/audio/dmic.h>
#include <hal/nrf_saadc.h>
#include <stdio.h>

#include "jbd_display.h"

/* ------------------------------ devices ------------------------------ */

static const struct device *const lsm6dso_dev =
	DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
static const struct device *const opt3001_dev =
	DEVICE_DT_GET(DT_NODELABEL(opt3001));
static const struct device *const npm1300_mfd_dev =
	DEVICE_DT_GET(DT_NODELABEL(npm1300));
static const struct device *const npm1300_charger_dev =
	DEVICE_DT_GET(DT_NODELABEL(npm1300_charger));
static const struct device *const npm1300_buck2_dev =
	DEVICE_DT_GET(DT_NODELABEL(npm1300_buck2));
static const struct device *const adc_dev =
	DEVICE_DT_GET(DT_NODELABEL(adc));
static const struct device *const flash_dev =
	DEVICE_DT_GET(DT_NODELABEL(mx25r64));
static const struct device *const dmic_dev =
	DEVICE_DT_GET(DT_NODELABEL(pdm0));

static const struct gpio_dt_spec sw0 =
	GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
static const struct gpio_dt_spec sw1 =
	GPIO_DT_SPEC_GET(DT_ALIAS(sw1), gpios);

/* ------------------------- persistent counters ------------------------ */

#define PERSIST_OFFSET		0x00000000
#define PERSIST_SECTOR_SIZE	4096
#define PERSIST_MAGIC		0x41524D45 /* "ARME" */

struct persist_rec {
	uint32_t magic;
	uint32_t boot_count;
	uint32_t save_count;
	uint32_t reserved;
};

static struct persist_rec persist;
static bool flash_ok;

static int persist_write(void)
{
	int err;

	if (!flash_ok) {
		return -ENODEV;
	}
	err = flash_erase(flash_dev, PERSIST_OFFSET, PERSIST_SECTOR_SIZE);
	if (err < 0) {
		printk("DEMO ERR flash_erase=%d\n", err);
		return err;
	}
	err = flash_write(flash_dev, PERSIST_OFFSET, &persist, sizeof(persist));
	if (err < 0) {
		printk("DEMO ERR flash_write=%d\n", err);
	}
	return err;
}

static void persist_boot(void)
{
	struct persist_rec rec;
	int err;

	flash_ok = device_is_ready(flash_dev);
	if (!flash_ok) {
		printk("DEMO ERR flash=not-ready\n");
		return;
	}
	err = flash_read(flash_dev, PERSIST_OFFSET, &rec, sizeof(rec));
	if (err < 0) {
		printk("DEMO ERR flash_read=%d\n", err);
		flash_ok = false;
		return;
	}
	if (rec.magic == PERSIST_MAGIC) {
		persist = rec;
	} else {
		persist.magic = PERSIST_MAGIC;
		persist.boot_count = 0;
		persist.save_count = 0;
		persist.reserved = 0;
	}
	persist.boot_count++;
	(void)persist_write();
	printk("DEMO FLASH BOOT=%u SAVE=%u\n",
	       persist.boot_count, persist.save_count);
}

/* ------------------------------- SAADC ------------------------------- */

#define AIN3_CHANNEL 0

static bool adc_ok;
static int16_t adc_raw_sample;

static void adc_setup(void)
{
	/* Board map: AIN3/P0.07, single-ended, 12-bit, internal ref, gain 1/6 */
	static const struct adc_channel_cfg cfg = {
		.gain = ADC_GAIN_1_6,
		.reference = ADC_REF_INTERNAL,
		.acquisition_time = ADC_ACQ_TIME_DEFAULT,
		.channel_id = AIN3_CHANNEL,
		.input_positive = NRF_SAADC_INPUT_AIN3,
	};

	adc_ok = device_is_ready(adc_dev) &&
		 adc_channel_setup(adc_dev, &cfg) == 0;
	if (!adc_ok) {
		printk("DEMO ERR adc=setup-failed\n");
	}
}

static int adc_sample(int32_t *millivolts, int16_t *raw)
{
	struct adc_sequence sequence = {
		.channels = BIT(AIN3_CHANNEL),
		.buffer = &adc_raw_sample,
		.buffer_size = sizeof(adc_raw_sample),
		.resolution = 12,
	};
	int err;

	if (!adc_ok) {
		return -ENODEV;
	}
	err = adc_read(adc_dev, &sequence);
	if (err < 0) {
		return err;
	}
	*raw = adc_raw_sample;
	*millivolts = adc_raw_sample;
	err = adc_raw_to_millivolts(adc_ref_internal(adc_dev), ADC_GAIN_1_6,
				    sequence.resolution, millivolts);
	return err;
}

/* -------------------------------- PDM -------------------------------- */

#define PDM_RATE_HZ	16000
#define PDM_SAMPLES	1600 /* 100 ms of mono 16-bit PCM */
#define PDM_BLOCK_BYTES	(PDM_SAMPLES * 2)

K_MEM_SLAB_DEFINE(pdm_slab, PDM_BLOCK_BYTES, 4, 4);

static bool pdm_ok;

static void pdm_setup(void)
{
	static struct pcm_stream_cfg stream = {
		.pcm_rate = PDM_RATE_HZ,
		.pcm_width = 16,
		.block_size = PDM_BLOCK_BYTES,
		.mem_slab = &pdm_slab,
	};
	struct dmic_cfg cfg = {
		.io = {
			.min_pdm_clk_freq = 1000000,
			.max_pdm_clk_freq = 3500000,
			.min_pdm_clk_dc = 40,
			.max_pdm_clk_dc = 60,
		},
		.streams = &stream,
		.channel = {
			.req_num_streams = 1,
			.req_num_chan = 1,
		},
	};
	int err;

	if (!device_is_ready(dmic_dev)) {
		printk("DEMO ERR pdm=not-ready\n");
		return;
	}
	cfg.channel.req_chan_map_lo =
		dmic_build_channel_map(0, 0, PDM_CHAN_LEFT);
	err = dmic_configure(dmic_dev, &cfg);
	if (err < 0) {
		printk("DEMO ERR pdm_configure=%d\n", err);
		return;
	}
	pdm_ok = true;
}

static uint32_t isqrt64(uint64_t v)
{
	uint64_t x = v;
	uint64_t y = (x + 1) / 2;

	if (v < 2) {
		return (uint32_t)v;
	}
	while (y < x) {
		x = y;
		y = (x + v / x) / 2;
	}
	return (uint32_t)x;
}

/* Captures one PDM buffer and returns its RMS level (or -errno). */
static int pdm_capture_rms(uint32_t *rms, uint32_t *samples)
{
	void *buffer = NULL;
	uint32_t size = 0;
	int err;

	if (!pdm_ok) {
		return -ENODEV;
	}
	err = dmic_trigger(dmic_dev, DMIC_TRIGGER_START);
	if (err < 0) {
		return err;
	}
	err = dmic_read(dmic_dev, 0, &buffer, &size, 1000);
	(void)dmic_trigger(dmic_dev, DMIC_TRIGGER_STOP);
	if (err < 0) {
		return err;
	}

	const int16_t *pcm = buffer;
	uint32_t count = size / 2;
	uint64_t sum_sq = 0;

	for (uint32_t i = 0; i < count; i++) {
		sum_sq += (int64_t)pcm[i] * pcm[i];
	}
	*rms = count > 0 ? isqrt64(sum_sq / count) : 0;
	*samples = count;
	k_mem_slab_free(&pdm_slab, buffer);

	/* Drain buffers queued between our read and the stop. */
	while (dmic_read(dmic_dev, 0, &buffer, &size, 0) == 0) {
		k_mem_slab_free(&pdm_slab, buffer);
	}
	return 0;
}

/* ------------------------------ helpers ------------------------------- */

static int64_t sv_to_micro(const struct sensor_value *v)
{
	return (int64_t)v->val1 * 1000000LL + v->val2;
}

/* ------------------------------ display ------------------------------- */

#define PAGE_COUNT 3

struct readings {
	int64_t acc[3];
	int64_t gyro[3];
	int64_t lux;
	int64_t vbat_uv;
	int64_t ibat_ua;
	int chg_status;
	int chg_error;
	int vbus_present;
	int32_t buck2_uv;
	int32_t ain3_mv;
	int16_t ain3_raw;
	uint32_t pdm_rms;
	uint32_t pdm_samples;
	int sw0_state;
	int sw1_state;
};

static uint32_t frame_count;

static void render_page(int page, const struct readings *r)
{
	char line[JBD_TEXT_COLS + 1];

	jbd_clear();
	snprintf(line, sizeof(line), "ARMEMUL DEMO   PAGE %d/%d", page + 1,
		 PAGE_COUNT);
	jbd_draw_text(0, 0, line, 15);

	switch (page) {
	case 0:
		jbd_draw_text(0, 2, "SENSORS", 12);
		snprintf(line, sizeof(line), "ACC X %lld", (long long)r->acc[0]);
		jbd_draw_text(0, 4, line, 15);
		snprintf(line, sizeof(line), "ACC Y %lld", (long long)r->acc[1]);
		jbd_draw_text(0, 5, line, 15);
		snprintf(line, sizeof(line), "ACC Z %lld", (long long)r->acc[2]);
		jbd_draw_text(0, 6, line, 15);
		snprintf(line, sizeof(line), "GYR X %lld", (long long)r->gyro[0]);
		jbd_draw_text(0, 8, line, 15);
		snprintf(line, sizeof(line), "GYR Y %lld", (long long)r->gyro[1]);
		jbd_draw_text(0, 9, line, 15);
		snprintf(line, sizeof(line), "GYR Z %lld", (long long)r->gyro[2]);
		jbd_draw_text(0, 10, line, 15);
		snprintf(line, sizeof(line), "LUX   %lld", (long long)r->lux);
		jbd_draw_text(0, 12, line, 15);
		break;
	case 1:
		jbd_draw_text(0, 2, "POWER", 12);
		snprintf(line, sizeof(line), "VBAT UV %lld",
			 (long long)r->vbat_uv);
		jbd_draw_text(0, 4, line, 15);
		snprintf(line, sizeof(line), "IBAT UA %lld",
			 (long long)r->ibat_ua);
		jbd_draw_text(0, 5, line, 15);
		snprintf(line, sizeof(line), "CHG %02X ERR %02X VBUS %d",
			 r->chg_status, r->chg_error, r->vbus_present);
		jbd_draw_text(0, 6, line, 15);
		snprintf(line, sizeof(line), "BUCK2 UV %d", r->buck2_uv);
		jbd_draw_text(0, 8, line, 15);
		snprintf(line, sizeof(line), "AIN3 %d MV RAW %d", r->ain3_mv,
			 r->ain3_raw);
		jbd_draw_text(0, 10, line, 15);
		break;
	default:
		jbd_draw_text(0, 2, "SYSTEM", 12);
		snprintf(line, sizeof(line), "BOOT %u SAVE %u",
			 persist.boot_count, persist.save_count);
		jbd_draw_text(0, 4, line, 15);
		snprintf(line, sizeof(line), "PDM RMS %u N %u", r->pdm_rms,
			 r->pdm_samples);
		jbd_draw_text(0, 6, line, 15);
		snprintf(line, sizeof(line), "BTN %d %d", r->sw0_state,
			 r->sw1_state);
		jbd_draw_text(0, 8, line, 15);
		snprintf(line, sizeof(line), "FRAME %u", frame_count);
		jbd_draw_text(0, 10, line, 15);
		snprintf(line, sizeof(line), "UPTIME MS %lld",
			 (long long)k_uptime_get());
		jbd_draw_text(0, 12, line, 15);
		break;
	}

	if (jbd_flush() == 0) {
		frame_count++;
	}
}

/* -------------------------------- main -------------------------------- */

int main(void)
{
	struct readings r;
	int page = 0;
	int prev_sw0 = 0, prev_sw1 = 0;
	bool imu_ok, light_ok, charger_ok, mfd_ok, buck2_ok;
	int err;

	printk("DEMO START build=%s\n", __DATE__);

	/* JBD display: verify the ID before anything else. */
	err = jbd_read_id();
	if (err < 0) {
		printk("DEMO ERR jbd_id=%d\n", err);
	} else {
		printk("DEMO JBD ID=0x%04X %s\n", err,
		       err == JBD_EXPECTED_ID ? "OK" : "MISMATCH");
	}

	persist_boot();

	imu_ok = device_is_ready(lsm6dso_dev);
	if (!imu_ok) {
		printk("DEMO ERR lsm6dso=not-ready\n");
	}
	light_ok = device_is_ready(opt3001_dev);
	if (!light_ok) {
		printk("DEMO ERR opt3001=not-ready\n");
	}
	charger_ok = device_is_ready(npm1300_charger_dev);
	if (!charger_ok) {
		printk("DEMO ERR npm1300_charger=not-ready\n");
	}
	mfd_ok = device_is_ready(npm1300_mfd_dev);
	if (!mfd_ok) {
		printk("DEMO ERR npm1300_mfd=not-ready\n");
	}
	buck2_ok = device_is_ready(npm1300_buck2_dev);
	if (!buck2_ok) {
		printk("DEMO ERR npm1300_buck2=not-ready\n");
	}

	adc_setup();
	pdm_setup();

	if (gpio_pin_configure_dt(&sw0, GPIO_INPUT) < 0 ||
	    gpio_pin_configure_dt(&sw1, GPIO_INPUT) < 0) {
		printk("DEMO ERR buttons=config-failed\n");
	}

	printk("DEMO READY\n");

	while (1) {
		struct sensor_value v[3];

		memset(&r, 0, sizeof(r));

		/* IMU: accel + gyro (polling, pinned lsm6dso driver) */
		if (imu_ok && sensor_sample_fetch(lsm6dso_dev) == 0) {
			if (sensor_channel_get(lsm6dso_dev,
					       SENSOR_CHAN_ACCEL_XYZ, v) == 0) {
				r.acc[0] = sv_to_micro(&v[0]);
				r.acc[1] = sv_to_micro(&v[1]);
				r.acc[2] = sv_to_micro(&v[2]);
			}
			if (sensor_channel_get(lsm6dso_dev,
					       SENSOR_CHAN_GYRO_XYZ, v) == 0) {
				r.gyro[0] = sv_to_micro(&v[0]);
				r.gyro[1] = sv_to_micro(&v[1]);
				r.gyro[2] = sv_to_micro(&v[2]);
			}
		}

		/* Ambient light (pinned opt3001 driver) */
		if (light_ok && sensor_sample_fetch(opt3001_dev) == 0 &&
		    sensor_channel_get(opt3001_dev, SENSOR_CHAN_LIGHT, v) == 0) {
			r.lux = sv_to_micro(&v[0]);
		}

		/* PMIC: charger sensor + mfd + regulator (pinned drivers) */
		if (charger_ok && sensor_sample_fetch(npm1300_charger_dev) == 0) {
			if (sensor_channel_get(npm1300_charger_dev,
					       SENSOR_CHAN_GAUGE_VOLTAGE, v) == 0) {
				r.vbat_uv = sv_to_micro(&v[0]);
			}
			if (sensor_channel_get(npm1300_charger_dev,
					       SENSOR_CHAN_GAUGE_AVG_CURRENT, v) == 0) {
				r.ibat_ua = sv_to_micro(&v[0]);
			}
			if (sensor_channel_get(npm1300_charger_dev,
					       (enum sensor_channel)SENSOR_CHAN_NPM1300_CHARGER_STATUS,
					       v) == 0) {
				r.chg_status = v[0].val1;
			}
			if (sensor_channel_get(npm1300_charger_dev,
					       (enum sensor_channel)SENSOR_CHAN_NPM1300_CHARGER_ERROR,
					       v) == 0) {
				r.chg_error = v[0].val1;
			}
		}
		if (mfd_ok) {
			uint8_t vbus_status = 0;

			/* VBUSIN.VBUSINSTATUS bit0 = VBUSINPRESENT */
			if (mfd_npm1300_reg_read(npm1300_mfd_dev, 0x02U, 0x07U,
						 &vbus_status) == 0) {
				r.vbus_present = vbus_status & 0x01;
			}
		}
		if (buck2_ok &&
		    regulator_get_voltage(npm1300_buck2_dev, &r.buck2_uv) != 0) {
			r.buck2_uv = -1;
		}

		/* SAADC AIN3 (pinned adc_nrfx_saadc driver) */
		if (adc_sample(&r.ain3_mv, &r.ain3_raw) < 0) {
			r.ain3_mv = -1;
			r.ain3_raw = -1;
		}

		/* PDM capture (pinned dmic_nrfx_pdm driver) */
		err = pdm_capture_rms(&r.pdm_rms, &r.pdm_samples);
		if (err < 0 && pdm_ok) {
			printk("DEMO ERR pdm_read=%d\n", err);
		}

		/* Buttons (active-low gpio-keys; 1 = pressed) */
		r.sw0_state = gpio_pin_get_dt(&sw0);
		r.sw1_state = gpio_pin_get_dt(&sw1);

		if (r.sw0_state == 1 && prev_sw0 == 0) {
			page = (page + 1) % PAGE_COUNT;
		}
		if (r.sw1_state == 1 && prev_sw1 == 0) {
			persist.save_count++;
			if (persist_write() == 0) {
				printk("DEMO FLASH SAVED BOOT=%u SAVE=%u\n",
				       persist.boot_count, persist.save_count);
			}
		}
		prev_sw0 = r.sw0_state == 1;
		prev_sw1 = r.sw1_state == 1;

		/* Stable machine-parseable console block */
		printk("DEMO ACC=%lld,%lld,%lld GYRO=%lld,%lld,%lld\n",
		       (long long)r.acc[0], (long long)r.acc[1],
		       (long long)r.acc[2], (long long)r.gyro[0],
		       (long long)r.gyro[1], (long long)r.gyro[2]);
		printk("DEMO LUX=%lld\n", (long long)r.lux);
		printk("DEMO PMIC VBAT=%lld IBAT=%lld CHG=0x%02X ERR=0x%02X VBUS=%d BUCK2=%d\n",
		       (long long)r.vbat_uv, (long long)r.ibat_ua,
		       r.chg_status, r.chg_error, r.vbus_present, r.buck2_uv);
		printk("DEMO AIN3 MV=%d RAW=%d\n", r.ain3_mv, r.ain3_raw);
		printk("DEMO PDM RMS=%u N=%u\n", r.pdm_rms, r.pdm_samples);
		printk("DEMO BTN=%d,%d PAGE=%d BOOT=%u SAVE=%u FRAME=%u\n",
		       r.sw0_state, r.sw1_state, page, persist.boot_count,
		       persist.save_count, frame_count);

		render_page(page, &r);

		k_sleep(K_MSEC(500));
	}
	return 0;
}

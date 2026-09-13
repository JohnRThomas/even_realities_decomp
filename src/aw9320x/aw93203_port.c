/*
 * AW93203 capacitive touch / wear sensor: Zephyr port layer for the Awinic
 * aw9320x driver (I2C, delay and irq hooks) plus the init entry point.
 *
 * The original file name is unknown; this file follows aw9320x.c in link
 * order (align-4 0x320c4..0x3216c, align-2 0x805ca..0x805f1).
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>

#include "aw9320x.h"

/* set once aw9320x_init() succeeded; polled by the button interrupt path */
int DAT_200085ac;

/* bus lock flag used by the production-test protocol (fuel_gauge_update, process_pt_data) */
uint8_t pt_comm_busy;

/*
 * I2C spec of the bus (.data 0x20002418, 8 bytes: i2c2 device + 0x6b, i.e. the
 * lsm6dso node on the same bus; the driver addresses the AW93203 with its own
 * AW9320X_I2C_DEV_ADDR and only uses .bus).
 */
struct i2c_dt_spec aw_i2c_dev = I2C_DT_SPEC_GET(DT_NODELABEL(lsm6dso));

static int32_t aw93203_i2c_read(uint8_t *addr, uint8_t addr_len, uint8_t *r_data, uint32_t r_len)
{
	if (i2c_write_read(aw_i2c_dev.bus, AW9320X_I2C_DEV_ADDR, addr, addr_len, r_data, r_len)) {
		return -1;
	}

	return 0;
}

static int32_t aw93203_i2c_write(uint8_t *buf, uint32_t len)
{
	if (i2c_write(aw_i2c_dev.bus, buf, len, AW9320X_I2C_DEV_ADDR)) {
		return -1;
	}

	return 0;
}

static void aw93203_irq_init(void (*irq_cb)(void))
{
}

static void aw93203_delay(uint32_t ms)
{
	k_msleep(ms);
}

static struct aw9320x_func aw9320x_func = {
	.i2c_func = {
		.i2c_r = aw93203_i2c_read,
		.i2c_w = aw93203_i2c_write,
	},
	.irq_init = aw93203_irq_init,
	.delay = aw93203_delay,
};

void aw93203_init(void)
{
	if (aw9320x_init(&aw9320x_func) >= 0) {
		DAT_200085ac = 1;
	}
}

uint8_t pt_comm_busy_get(void)
{
	return pt_comm_busy;
}

void pt_comm_busy_set(void)
{
	pt_comm_busy = 1;
}

void pt_comm_busy_clear(void)
{
	pt_comm_busy = 0;
}

/* old Ghidra names, kept as aliases until the callers in production_test/serial_thread.c are renamed */
extern __typeof__(pt_comm_busy_get) FUN_0003214c __attribute__((alias("pt_comm_busy_get")));
extern __typeof__(pt_comm_busy_set) FUN_00032158 __attribute__((alias("pt_comm_busy_set")));
extern __typeof__(pt_comm_busy_clear) FUN_00032164 __attribute__((alias("pt_comm_busy_clear")));

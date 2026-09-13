/*
 * AW93203 capacitive touch / wear sensor: Zephyr port layer for the Awinic
 * aw9320x driver (I2C, delay and irq hooks) plus the init entry point.
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>

#include "aw9320x.h"

/* set once aw9320x_init() succeeded; polled by the button interrupt path */
int aw93203_ready;

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
		aw93203_ready = 1;
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

/*
 * ST25DV as a Zephyr EEPROM: I2C transfers, retry/lock wrappers, the
 * mailbox helpers and the hand-made device instance.
 *
 * Original file name unknown.  Link order: after nfc.c
 * (align-4 0x27818..0x27c53, align-2 0x7fbc6..0x7fc37).
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/eeprom.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/printk.h>

#include "st25dv.h"

#define ST25DV_RETRIES	20

/* production-test protocol back end */
int FUN_000346b4(const struct device *dev);
int process_pt_data(void);
static struct k_mutex st25dv_mutex;

struct device global_st25dv_context;
const struct device *global_st25dv_context_ptr;

static struct eeprom_st25dv_config st25dv_device = {
	.bus = DEVICE_DT_GET(DT_NODELABEL(i2c1)),
	.bus_addr = ST25DV_ADDR_DATA_I2C,
};

int init_nfc_comm(void)
{
	if (FUN_000346b4(global_st25dv_context_ptr)) {
		printk("init_nfc_comm is failed\n");
		return -1;
	}

	return process_pt_data() ? -2 : 0;
}

int FUN_00027848(uint8_t *it_status)
{
	int ret;
	int retries = 10;

	if (!it_status || !global_st25dv_context_ptr) {
		printk("input param valid \n");
		return -1;
	}

	do {
		ret = st25dv_read_itsts_dyn(global_st25dv_context_ptr, it_status);
		if (!ret) {
			break;
		}
	} while (--retries);

	return ret;
}

void i2c_delay(void)
{
	k_sleep(K_MSEC(1));
}

static int st25dv_write(const struct eeprom_st25dv_config *config, uint16_t addr, off_t offset,
			const uint8_t *buf, size_t len)
{
	uint8_t block[len + 2];
	struct i2c_msg msg;
	int ret;

	block[0] = offset >> 8;
	block[1] = offset;
	memcpy(&block[2], buf, len);

	msg.buf = block;
	msg.len = len + 2;
	msg.flags = I2C_MSG_WRITE | I2C_MSG_STOP;

	ret = i2c_transfer(config->bus, &msg, 1, addr);
	i2c_delay();
	if (ret < 0) {
		printk("_st25dv_write  ret %d \n", ret);
	}

	return ret;
}

int eeprom_st25dv_write(const struct device *dev, off_t offset, const void *buf, size_t len)
{
	const struct eeprom_st25dv_config *config = dev->config;
	struct k_mutex *lock = dev->data;
	int retries = ST25DV_RETRIES;
	int ret;

	if (!len) {
		return 0;
	}

	while (1) {
		k_mutex_lock(lock, K_FOREVER);
		ret = st25dv_write(config, config->addr, offset, buf, len);
		k_mutex_unlock(lock);
		if (!ret || !--retries) {
			break;
		}
		i2c_delay();
	}

	if (ret) {
		printk("eeprom_st25dv_write addr %04X offset %04X failed %d\r\n",
		       config->addr, (uint32_t)offset, ret);
	}

	return ret;
}

static int st25dv_read(const struct device *bus, uint16_t addr, off_t offset, uint8_t *buf,
		       size_t len)
{
	uint8_t wr_addr[2];
	struct i2c_msg msgs[2];
	int ret;

	sys_put_be16(offset, wr_addr);

	msgs[0].buf = wr_addr;
	msgs[0].len = 2;
	msgs[0].flags = I2C_MSG_WRITE;

	msgs[1].buf = buf;
	msgs[1].len = len;
	msgs[1].flags = I2C_MSG_RESTART | I2C_MSG_READ | I2C_MSG_STOP;

	ret = i2c_transfer(bus, msgs, 2, addr);
	i2c_delay();
	if (ret < 0) {
		printk("_st25dv_read  ret %d \n", ret);
	}

	return ret;
}

int eeprom_st25dv_read(const struct device *dev, off_t offset, void *buf, size_t len)
{
	const struct eeprom_st25dv_config *config = dev->config;
	struct k_mutex *lock = dev->data;
	int retries = ST25DV_RETRIES;
	int ret;

	if (!len) {
		return 0;
	}

	while (1) {
		k_mutex_lock(lock, K_FOREVER);
		ret = st25dv_read(config->bus, config->addr, offset, buf, len);
		k_mutex_unlock(lock);
		if (!ret || !--retries) {
			break;
		}
		i2c_delay();
	}

	if (ret) {
		printk("eeprom_st25dv_read addr %04X offset %04X failed %d\r\n",
		       config->addr, (uint32_t)offset, ret);
	}

	return ret;
}

int st25dv_write_sys(const struct eeprom_st25dv_config *config, off_t offset,
			    const void *buf, size_t len)
{
	return st25dv_write(config, config->addr | ST25DV_ADDR_SYST_I2C_BIT, offset, buf, len);
}

int st25dv_read_sys(const struct eeprom_st25dv_config *config, off_t offset, void *buf,
			   size_t len)
{
	return st25dv_read(config->bus, config->addr | ST25DV_ADDR_SYST_I2C_BIT, offset, buf, len);
}

int eeprom_st25dv_read_sys(const struct device *dev, off_t offset, void *buf, size_t len)
{
	const struct eeprom_st25dv_config *config = dev->config;
	struct k_mutex *lock = dev->data;
	int retries = ST25DV_RETRIES;
	int ret;

	if (!len) {
		return 0;
	}

	while (1) {
		k_mutex_lock(lock, K_FOREVER);
		ret = st25dv_read_sys(config, offset, buf, len);
		k_mutex_unlock(lock);
		if (!ret || !--retries) {
			break;
		}
		i2c_delay();
	}

	if (ret) {
		printk("eeprom_st25dv_read_sys addr %04X offset %04X failed %d\r\n",
		       config->addr | ST25DV_ADDR_SYST_I2C_BIT, (uint32_t)offset, ret);
	}

	return ret;
}

int eeprom_st25dv_write_sys(const struct device *dev, off_t offset, const void *buf, size_t len)
{
	const struct eeprom_st25dv_config *config = dev->config;
	struct k_mutex *lock = dev->data;
	int retries = ST25DV_RETRIES;
	int ret;

	if (!len) {
		return 0;
	}

	while (1) {
		k_mutex_lock(lock, K_FOREVER);
		ret = st25dv_write_sys(config, offset, buf, len);
		k_mutex_unlock(lock);
		if (!ret || !--retries) {
			break;
		}
		i2c_delay();
	}

	if (ret) {
		printk("eeprom_st25dv_write_sys addr %04X offset %04X failed %d\r\n",
		       config->addr | ST25DV_ADDR_SYST_I2C_BIT, (uint32_t)offset, ret);
	}

	return ret;
}

/* read the RF->host mailbox message: *buf receives the data, *len the length - 1 */
int FUN_00027ac0(const struct device *dev, uint8_t **buf, uint32_t *len)
{
	uint8_t mb_ctrl;
	uint32_t mb_len;

	if (!dev || !buf || !len) {
		return -1;
	}

	mb_ctrl = 0;
	if (eeprom_st25dv_read(dev, ST25DV_MB_CTRL_DYN_REG, &mb_ctrl, 1)) {
		printk("eeprom_st25dv_read ST25DV_REG_MB_CTRL_DYN is failed\n");
		return -2;
	}

	/* MB_EN and RF_PUT_MSG */
	if ((mb_ctrl & 0x05) != 0x05) {
		return -3;
	}

	mb_len = 0;
	if (eeprom_st25dv_read(dev, ST25DV_MB_LEN_DYN_REG, &mb_len, 1)) {
		printk("eeprom_st25dv_read ST25DV_REG_MB_LEN_DYN is failed\n");
		return -4;
	}
	*len = mb_len;

	if (eeprom_st25dv_read(dev, ST25DV_MAILBOX_RAM_REG, *buf, 0xff)) {
		printk("eeprom_st25dv_read ST25DV_REG_MAILBOX_DYN is failed\n");
		return -5;
	}

	return 0;
}

int eeprom_st25dv_write_i2c_mb_mailbox_ram(const struct device *dev, const void *buf, size_t len)
{
	uint8_t mb_ctrl;

	if (!dev || !buf || !len) {
		return -1;
	}

	mb_ctrl = 0;
	if (eeprom_st25dv_read(dev, ST25DV_MB_CTRL_DYN_REG, &mb_ctrl, 1)) {
		goto ctrl_fail;
	}

	/* HOST_PUT_MSG or RF_PUT_MSG still pending */
	if (mb_ctrl & 0x06) {
		printk("eeprom_st25dv_write_i2c_mb_mailbox_ram no write\n");
		return -3;
	}

	if (eeprom_st25dv_write(dev, ST25DV_MAILBOX_RAM_REG, buf, len)) {
		printk("eeprom_st25dv_write ST25DV_REG_MAILBOX_DYN failed\n");
		return -3;
	}

	if (eeprom_st25dv_read(dev, ST25DV_MB_CTRL_DYN_REG, &mb_ctrl, 1)) {
		goto ctrl_fail;
	}

	return 0;

ctrl_fail:
	printk("eeprom_st25dv_read ST25DV_REG_MB_CTRL_DYN is failed\n");
	return -2;
}

static size_t eeprom_st25dv_size(const struct device *dev)
{
	const struct eeprom_st25dv_config *config = dev->config;

	return config->size;
}

static const struct eeprom_driver_api st25dv_callbacks = {
	.read = eeprom_st25dv_read,
	.write = eeprom_st25dv_write,
	.size = eeprom_st25dv_size,
};

const struct device *eeprom_st25dv_init(void)
{
	global_st25dv_context.api = &st25dv_callbacks;
	st25dv_device.bus_addr = ST25DV_ADDR_DATA_I2C;
	st25dv_device.addr = ST25DV_ADDR_DATA_I2C;
	st25dv_device.size = 0x1000;
	global_st25dv_context.data = &st25dv_mutex;
	global_st25dv_context.config = &st25dv_device;
	k_mutex_init(&st25dv_mutex);

	if (!device_is_ready(st25dv_device.bus)) {
		printk("parent bus device not ready\r\n");
	} else {
		printk("eeprom_st25dv_init ready\r\n");
	}

	if (!device_is_ready(st25dv_device.bus)) {
		printk("\nError: Device \"%s\" is not ready; "
		       "check the driver initialization logs for errors.\n",
		       st25dv_device.bus->name);
		return NULL;
	}

	printk("update_eeprom_interface\r\n");
	return &global_st25dv_context;
}

/*
 * Not present in the image (no callers, removed by --gc-sections).  They are
 * kept because the shipped code needs a third i2c_transfer() caller (or GCC
 * inlines z_impl_i2c_transfer) and a non-constant k_mutex_lock() timeout (or
 * GCC const-propagates K_FOREVER into the out-of-line k_mutex_lock copy).
 */
int st25dv_transfer(const struct device *dev, struct i2c_msg *msgs, uint8_t num_msgs)
{
	const struct eeprom_st25dv_config *config = dev->config;

	return i2c_transfer(config->bus, msgs, num_msgs, config->addr);
}

int eeprom_st25dv_lock_timeout(const struct device *dev, k_timeout_t timeout)
{
	return k_mutex_lock(dev->data, timeout);
}

/*
 * Lock / unlock with dev->data.  The vendor declared a return value but never
 * returns one (falling off the end); that is what keeps the call from being a
 * sibcall (bl + pop in the target).
 */
uint8_t FUN_0007fc18(const struct device *dev)
{
	if (dev) {
		k_mutex_lock(dev->data, K_FOREVER);
	}
}

uint8_t FUN_0007fc2c(const struct device *dev)
{
	if (dev) {
		k_mutex_unlock(dev->data);
	}
}

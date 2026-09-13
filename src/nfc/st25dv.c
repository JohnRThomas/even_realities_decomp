/*
 * ST25DV register helpers, derived from ST's st25dv.c (stm32-st25dv)
 * and rewritten on top of the eeprom_st25dv device.
 *
 * Original file name unknown.  Only align-2 code: 0x7fc38..0x7fdb5.
 */
#include <errno.h>
#include <string.h>
#include <zephyr/device.h>

#include "st25dv.h"

int st25dv_configure_gpo(const struct device *dev, uint8_t it_conf)
{
	return eeprom_st25dv_write_sys(dev, ST25DV_GPO_REG, &it_conf, 1);
}

int st25dv_read_it_pulse(const struct device *dev, uint8_t *it_time)
{
	if (!it_time) {
		return -EINVAL;
	}

	return eeprom_st25dv_read_sys(dev, ST25DV_ITTIME_REG, it_time, 1);
}

int st25dv_write_it_pulse(const struct device *dev, uint8_t it_time)
{
	uint8_t reg;
	int ret;

	ret = eeprom_st25dv_read_sys(dev, ST25DV_ITTIME_REG, &reg, 1);
	if (ret) {
		return ret;
	}

	reg = (reg & ~0x1f) | (it_time & 0x1f);

	return eeprom_st25dv_write_sys(dev, ST25DV_ITTIME_REG, &reg, 1);
}

int ST25DV_GetUID(const struct device *dev, uint8_t *uid)
{
	if (!uid) {
		return -EINVAL;
	}

	return eeprom_st25dv_read_sys(dev, ST25DV_UID_REG, uid, 8);
}

int st25dv_read_ic_rev(const struct device *dev, uint8_t *ic_rev)
{
	if (!ic_rev) {
		return -EINVAL;
	}

	return eeprom_st25dv_read_sys(dev, ST25DV_ICREV_REG, ic_rev, 1);
}

int st25dv_read_id(const struct device *dev, uint8_t *ic_ref)
{
	if (!ic_ref) {
		return -EINVAL;
	}

	return eeprom_st25dv_read_sys(dev, ST25DV_ICREF_REG, ic_ref, 1);
}

int st25dv_read_mem_size(const struct device *dev, struct st25dv_mem_size *size)
{
	uint8_t reg[2] = {0};
	int ret;

	if (!size) {
		return -EINVAL;
	}

	ret = eeprom_st25dv_read_sys(dev, ST25DV_MEM_SIZE_REG, reg, 2);
	if (ret) {
		return ret;
	}
	memcpy(&size->mem_size, reg, 2);

	return eeprom_st25dv_read_sys(dev, ST25DV_BLK_SIZE_REG, &size->blk_size, 1);
}

int st25dv_present_i2c_password(const struct device *dev, const struct st25dv_passwd *pwd)
{
	uint8_t msg[17] = {0};
	uint32_t msb = pwd->msb;
	uint32_t lsb = pwd->lsb;
	int i;

	/* password, validation code 0x09, password */
	msg[8] = 0x09;
	for (i = 0; i < 4; i++) {
		msg[i] = msb >> ((3 - i) * 8);
		msg[i + 4] = lsb >> ((3 - i) * 8);
		msg[i + 9] = msg[i];
		msg[i + 13] = msg[i + 4];
	}

	return eeprom_st25dv_write_sys(dev, ST25DV_I2CPASSWD_REG, msg, sizeof(msg));
}

int st25dv_read_eh_ctrl_dyn(const struct device *dev, uint8_t *eh_ctrl)
{
	return eeprom_st25dv_read(dev, ST25DV_EH_CTRL_DYN_REG, eh_ctrl, 1);
}

int st25dv_write_eh_ctrl_dyn(const struct device *dev, uint8_t eh_ctrl)
{
	return eeprom_st25dv_write(dev, ST25DV_EH_CTRL_DYN_REG, &eh_ctrl, 1);
}

int st25dv_read_itsts_dyn(const struct device *dev, uint8_t *it_status)
{
	return eeprom_st25dv_read(dev, ST25DV_ITSTS_DYN_REG, it_status, 1);
}

int st25dv_read_i2c_security_session_dyn(const struct device *dev, uint8_t *session)
{
	uint8_t reg;
	int ret;

	*session = 0;
	ret = eeprom_st25dv_read(dev, ST25DV_I2C_SSO_DYN_REG, &reg, 1);
	if (ret == 0) {
		if (reg) {
			*session = 1;
		} else {
			*session = 0;
		}
	}

	return ret;
}

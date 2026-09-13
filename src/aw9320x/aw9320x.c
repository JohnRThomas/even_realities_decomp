/*
* aw9320x.c
*
* Copyright ©2022 Shanghai Awinic Technology Co., Ltd. All Rights Reserved
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* G1 variant: derived from AW9320X_Driver_MCU_V1.11.0, reduced to the
* firmware (protocol) update path, the parameter download and the wear
* interrupt handling.  No SPP / OS hooks, debug output compiled out.
*/


#include "aw9320x.h"
#include "aw9320x_fw_info.h"

#define AW9320X_I2C_NAME		"aw9320x_cap"
#define AW9320X_DRIVER_VERSION		"v1.11.0"

static int32_t old_mode = 0;
static uint32_t hostirqen = 0;
static uint8_t prot_update_fw_flag = 0;
static struct aw9320x_func *g_aw9320x_func = NULL;
//Interrupt mode is mutually exclusive to polling mode
volatile static uint8_t g_is_need_irq = 1;

aw9320x_WEARING aw9320x_wearing;

static void aw9320x_Global_var_rst_def_val(void)
{
	old_mode = 0;
	hostirqen = 0;
	prot_update_fw_flag = 0;
	g_is_need_irq = AW_TRUE;
}

static void AW_DELAY(uint32_t ms)
{
	g_aw9320x_func->delay(ms);
}

static int32_t i2c_write_seq(uint8_t *buf, uint16_t len)
{
	return g_aw9320x_func->i2c_func.i2c_w(buf, (uint32_t)len);
}

static int32_t i2c_read_seq(uint8_t *addr, uint8_t addr_len, uint8_t *r_data, uint16_t r_len)
{
	return g_aw9320x_func->i2c_func.i2c_r(addr, addr_len, r_data, r_len);
}

static int8_t aw9320x_i2c_read(uint16_t reg_addr, uint32_t *reg_data)
{
	uint8_t cnt = 0;
	int32_t status = 0;
	uint8_t addr_buf[2] = { 0 };
	uint8_t reg_val[4] = { 0 };

	addr_buf[0] = (reg_addr >> OFFSET_BIT_8) & 0xff;
	addr_buf[1] = reg_addr & 0xff;

	while (cnt < AW9320X_I2C_RETRIES) {
		status = i2c_read_seq(addr_buf, AW_REG_ADDR_LEN, reg_val, AW_REG_DATA_LEN);
		if (status == AW_OK) {
			*reg_data = ((uint32_t)reg_val[0] << OFFSET_BIT_24) | ((uint32_t)reg_val[1] << OFFSET_BIT_16) |
				((uint32_t)reg_val[2] << OFFSET_BIT_8) | ((uint32_t)reg_val[3]);
			return AW_OK;
		} else {
			AWLOGE("error = %d, cnt = %d", status, cnt);
			AW_DELAY(1);
			cnt++;
		}
	}

		return -AW_ERR;
}

static int8_t aw9320x_i2c_write(uint16_t reg_addr, uint32_t reg_data)
{
	uint8_t cnt = 0;
	int32_t status = 0;
	uint8_t tx_buf[AW_TX_BUF_LEN] = { 0 };

	tx_buf[0] = (reg_addr >> OFFSET_BIT_8) & 0xff;
	tx_buf[1] = reg_addr & 0xff;
	tx_buf[2] = (reg_data >> OFFSET_BIT_24) & 0xff;
	tx_buf[3] = (reg_data >> OFFSET_BIT_16) & 0xff;
	tx_buf[4] = (reg_data >> OFFSET_BIT_8) & 0xff;
	tx_buf[5] = reg_data  & 0xff;

	while (cnt < AW9320X_I2C_RETRIES) {
		status = i2c_write_seq(tx_buf, AW_TX_BUF_LEN);
		if (status == AW_OK) {
			return AW_OK;
		} else {
			AWLOGE("error = %d, cnt = %d", status, cnt);
			AW_DELAY(1);
			cnt++;
		}
	}

	return -AW_ERR;
}

static int32_t aw9320x_i2c_write_bits(uint16_t reg_addr16, uint32_t mask, uint32_t reg_data32)
{
	uint32_t reg_val;

	aw9320x_i2c_read(reg_addr16, &reg_val);
	reg_val &= mask;
	reg_val |= (reg_data32 & (~mask));
	aw9320x_i2c_write(reg_addr16, reg_val);

	return 0;
}

void aw9320x_mode_operation_set(enum AW9320X_OPERAION_MODE mode)
{
	if ((mode == AW9320X_ACTIVE_MODE) && (old_mode != AW9320X_ACTIVE_MODE)) {
		if (old_mode == AW9320X_DEEPSLEEP_MODE)
			aw9320x_i2c_write(REG_HOSTCTRL1, REG_HOSTCTRL_EN);
		aw9320x_i2c_write(REG_CMD, AW9320X_ACTIVE_MODE);
	} else if ((mode == AW9320X_SLEEP_MODE) && (old_mode != AW9320X_SLEEP_MODE)) {
		if (old_mode == AW9320X_DEEPSLEEP_MODE)
			aw9320x_i2c_write(REG_HOSTCTRL1, REG_HOSTCTRL_EN);
		aw9320x_i2c_write(REG_CMD, AW9320X_SLEEP_MODE);
	} else if ((mode == AW9320X_DEEPSLEEP_MODE) && (old_mode != AW9320X_DEEPSLEEP_MODE))
		aw9320x_i2c_write(REG_CMD, AW9320X_DEEPSLEEP_MODE);
	else
		AWLOGD("failed to operation mode!");

	AW_DELAY(AW_MAX_SCAN_PERRIOD);
	old_mode = mode;
}

enum AW9320X_OPERAION_MODE aw9320x_mode_operation_get(void)
{
	uint32_t data = 0;

	aw9320x_i2c_read(REG_WST, &data);
	AWLOGD("data = 0x%x", data);
	if (data == AW_GET_REG_ACTIVE_VAL)
		return AW9320X_ACTIVE_MODE;
	else if (data == AW_GET_REG_SLEEP_VAL)
		return AW9320X_SLEEP_MODE;
	else if (data == AW_GET_REG_DEEPSLEEP_VAL)
		return AW9320X_DEEPSLEEP_MODE;

	return AW9320X_MODE_ERR;
}

void aw9320x_diff_get(int32_t *p_diff)
{
	aw9320x_i2c_read(REG_DIFF_CH0, (uint32_t *)p_diff);
	*p_diff = *p_diff >> AW_REMOVE_DECIMAL_BITS;
}

int32_t aw9320x_read_chipid(void)
{
	int32_t ret = -AW_ERR;
	uint32_t reg_val = 0;

	AWLOGD("enter");

	ret = aw9320x_i2c_read(REG_CHIPID, &reg_val);
	if (ret < 0) {
		AWLOGE("read CHIP ID failed: %d", ret);
		return -AW_ERR;
	}

	switch (reg_val) {
	case AW93203CSR_CHIP_ID:
		AWLOGD("AW93203CSR CHIP ID : 0x%x", reg_val);
		break;
	case AW93205DNR_CHIP_ID:
		AWLOGD("AW93205DNR CHIP ID : 0x%x", reg_val);
		break;
	case AW93208CSR_CHIP_ID:
		AWLOGD("AW93208CSR CHIP ID : 0x%x", reg_val);
		break;
	default:
		AWLOGD("no chipid,need update root and frimware,CHIP ID : 0x%08x", reg_val);
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_soft_reset(void)
{
	int32_t ret = -AW_ERR;

	AWLOGD("enter");

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret < 0) {
		AWLOGE("read REG_APB_ACCESS_EN err: %d", ret);
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(AW_REG_FLASH_WAKE_UP, AW_REG_FLASH_WAKE_UP_ON);
	if (ret < 0) {
		AWLOGE("read REG_APB_ACCESS_EN err: %d", ret);
		return -AW_ERR;
	}
	AW_DELAY(1);

	ret = aw9320x_i2c_write(REG_MCFG, REG_SET_MCFG00);
	if (ret != AW_OK) {
		AWLOGD("REG_MCFG err");
		return ret;
	}
	AW_DELAY(REG_MCFG_DELAY_MS);

	ret = aw9320x_i2c_write(REG_RSTNALL, REG_RSTNALL_VAL);
	if (ret < 0) {
		AWLOGE("read soft_reset err: %d", ret);
		return -AW_ERR;
	}

	AW_DELAY(AW_POWER_ON_DELAY_MS);

	ret = aw9320x_i2c_write(AW_REG_FLASH_WAKE_UP, AW_REG_FLASH_WAKE_UP_OFF);
	if (ret < 0) {
		AWLOGE("read REG_APB_ACCESS_EN err: %d", ret);
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_init_irq_handle(void)
{
	int32_t ret = -AW_ERR;
	uint32_t irq_stat = 0;
	int8_t cnt = AW_IRQ_DELAY_MS;

	AWLOGD("enter");

	do {
		ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
		if (ret < 0) {
			AWLOGE("read init irq reg err: %d cnt: %d", ret, cnt);
			return -AW_ERR;
		}
		if ((irq_stat & INIT_OVER_IRQ) == INIT_OVER_IRQ_OK) {
			AWLOGD("init over irq ok cnt: %d", cnt);
			return AW_OK;
		} else {
			AWLOGE("init over irq no ok cnt: %d", cnt);
		}
		AW_DELAY(1);
	} while (cnt--);

	if (cnt < 0) {
		AWLOGE("init over irq err! irq_stat:%d", irq_stat);
	}

	return -AW_ERR_IRQ_INIT;
}

static int32_t aw9320x_en_active(void)
{
	int32_t ret = 0;

	AWLOGD("enter");

	ret = aw9320x_i2c_write(REG_CMD, AW9320X_ACTIVE_MODE);
	if (ret != AW_OK) {
		AWLOGE("write REG_CMD err");
		return -AW_ERR;
	} else {
		old_mode = AW9320X_ACTIVE_MODE;
		AWLOGD("addr: 0x%x data: 0x%x", REG_CMD, 1);
	}

	ret = aw9320x_i2c_write(REG_IRQEN, hostirqen);
	if (ret != AW_OK) {
		AWLOGD("addr: 0x%x data: 0x%x",
					REG_IRQEN, hostirqen);
		return -AW_ERR;
	} else {
		AWLOGD("addr: 0x%x data: 0x%x", REG_IRQEN, hostirqen);
	}

	return AW_OK;
}

static int32_t aw9320x_para_loaded(void)
{
	int32_t i = 0;
	int32_t len = sizeof(aw9320x_reg_default)/sizeof(uint32_t);

	AWLOGD("start to download para!");

	for (i = 0; i < len; i = i + 2) {
		if (aw9320x_reg_default[i] == REG_IRQEN) {
			hostirqen = aw9320x_reg_default[i + 1];
			continue;
		}
		aw9320x_i2c_write((uint16_t)aw9320x_reg_default[i], aw9320x_reg_default[i+1]);
		AWLOGD("reg_addr = 0x%04x, reg_data = 0x%08x",
						aw9320x_reg_default[i],
						aw9320x_reg_default[i+1]);
	}
	AWLOGD("para writen completely");

	return aw9320x_en_active();
}

static int32_t aw9320x_check_sum(const uint8_t *para_data,  uint32_t arr_len)
{
	uint32_t i = 0;
	uint32_t arr_data_sum = 0;
	uint32_t check_sum = AW_GET_32_DATA(para_data[3], para_data[2],para_data[1], para_data[0]);

	AWLOGD("enter");

	for (i = 4; i < arr_len; i++)
		arr_data_sum += para_data[i];
	AWLOGD("check_sum = 0x%x, arr_data_sum = 0x%x arr_len = %d", check_sum, arr_data_sum, arr_len);
	if (check_sum != arr_data_sum) {
		AWLOGD("check_sum != arr_data_sum err");
		return -AW_ERR;
	}

	return AW_OK;
}

/********aw9320x_reg_mode_update start********/
static int32_t aw9320x_check_isp_go_reg(void)
{
	int32_t delay_cnt = 100;
	uint32_t r_isp_go_reg = 0;
	int32_t ret = 0;

	do {
		ret = aw9320x_i2c_read(REG_ISPGO, &r_isp_go_reg);
		if (ret != AW_OK) {
			AWLOGE("write 0xff20 err");
			return ret;
		}
		if (r_isp_go_reg == 0)
			break;
		AW_DELAY(1);
	} while (delay_cnt--);

	if (delay_cnt < 0) {
		AWLOGE("check_isp_go_reg err!");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_close_write_flash_protect(uint32_t flash_addr_flag)
{
	int32_t ret = 0;

	//Open host read / write FMC protection
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	//Configure PMC_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//Turn on flash write protection
	if (flash_addr_flag == BOOT_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
	}

	return AW_OK;
}

static int32_t aw9320x_reg_write_to_flash_once(uint16_t addr, uint32_t w_data)
{
	int32_t ret = 0;

	//Write access address
	ret = aw9320x_i2c_write(REG_ISPADR, addr);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	//Write data
	ret = aw9320x_i2c_write(REG_ISPWDATA, w_data);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	//Configure ISP_CMD reg
	ret = aw9320x_i2c_write(REG_ISPCMD, REG_ISP_CMD_CONFIG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	//Configure ISP_GO reg
	ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	ret = aw9320x_check_isp_go_reg();
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	return AW_OK;
}

static uint32_t aw9320x_get_bin_checksum(const uint8_t *w_bin_offset,
					uint32_t update_data_len, uint32_t check_len)
{
	uint32_t i = 0;
	uint32_t check_sum = 0;
	uint32_t tmp = 0;
	uint32_t index = 0;

	for (i = 0; i < check_len; i += WORD_LEN) {
		if (i < update_data_len) {
			tmp = AW_GET_32_DATA(w_bin_offset[index + 0],
				w_bin_offset[index + 1],
				w_bin_offset[index + 2],
				w_bin_offset[index + 3]);
			index  += WORD_LEN;
		} else {
			tmp = AW_FLASH_DEFAULT_VAL;
		}
		check_sum += tmp;
	}
	check_sum = ~check_sum + 1;

	return check_sum;
}

static int32_t aw9320x_reg_write_val_to_flash(uint16_t addr,
						uint32_t val, struct aw_update_common *update_info)
{
	int32_t ret = 0;

	ret = aw9320x_close_write_flash_protect(update_info->update_flag);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	ret = aw9320x_reg_write_to_flash_once(addr, val);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//Configure PMU_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_reg_read_val(uint32_t *read_data, uint16_t start_addr)
{
	int32_t ret = 0;

	//3.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_ISPADR, start_addr);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//4.config ISP_CMD reg
	ret = aw9320x_i2c_write(REG_ISPCMD, REG_ISP_CMD_MAIN_ARR);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//5.config ISP_GO reg
	ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//6.check isp_go reg
	ret = aw9320x_check_isp_go_reg();
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//7 read data
	ret = aw9320x_i2c_read(REG_ISPRDATA, read_data);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_rd_or_wi_cmp(struct aw_update_common *update_info,
				const uint8_t *w_bin_offset, uint32_t update_data_len)
{
	int32_t ret = 0;
	uint32_t i = 0;
	uint32_t r_data = 0;
	uint32_t w_data = 0;
	uint32_t read_cnt = update_info->update_data_len;

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	for (i = 0; i < read_cnt; i += WORD_LEN) {
		ret = aw9320x_reg_read_val(&r_data,
					update_info->flash_tr_start_addr + i);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		w_data = AW_GET_32_DATA(w_bin_offset[i + 0],
					w_bin_offset[i + 1],
					w_bin_offset[i + 2],
					w_bin_offset[i + 3]);
		if (w_data != r_data) {
			AWLOGE("i= %d, addr= 0x%08x, W_DATA= 0x%08x, R_DATA= 0x%08x",
			i, update_info->flash_tr_start_addr + i, w_data, r_data);
			return -AW_ERR;
		}
	}

	return AW_OK;
}

static int32_t aw9320x_reg_write_bin_to_flash(struct aw_update_common *update_info)
{
	int32_t ret = 0;
	uint32_t i = 0;
	uint32_t w_data = 0;
	uint32_t index = 0;
	const uint8_t *p_data = update_info->w_bin_offset;
	uint32_t len = update_info->update_data_len;
	uint16_t flash_addr = update_info->flash_tr_start_addr;

	ret = aw9320x_close_write_flash_protect(update_info->update_flag);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	for (i = 0; i < len; i += WORD_LEN, index += WORD_LEN) {
		w_data = AW_GET_32_DATA(p_data[index + 0], p_data[index + 1],
				p_data[index + 2], p_data[index + 3]);
		ret = aw9320x_reg_write_to_flash_once(flash_addr + i, w_data);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
	}

	//Configure PMU_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_erase_sector(struct aw_update_common *update_info)
{
	int32_t ret = 0;
	uint32_t i = 0;
	uint32_t erase_len = update_info->check_info->check_len;
	uint32_t temp = (erase_len % SOCTOR_SIZE > 0) ? 1 : 0;
	uint32_t erase_cnt = erase_len / SOCTOR_SIZE + temp;

	//1.close write protect
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		return ret;
	}

	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		return ret;
	}

	if (update_info->update_flag == BOOT_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			return ret;
		}
	}

	for (i = 0; i < erase_cnt; i++)	{
		//2.0x3800~0x3FFF Erase one sector at a time
		ret = aw9320x_i2c_write(REG_ISPADR,
				update_info->check_info->flash_check_start_addr + i * SOCTOR_SIZE);
		if (ret != AW_OK) {
			return ret;
		}

		ret = aw9320x_i2c_write(REG_ISPCMD, REG_ACCESS_MAIN_ARR);
		if (ret != AW_OK) {
			return ret;
		}

		ret = aw9320x_i2c_write(REG_T_RCV, REG_SET_T_RCV);
		if (ret != AW_OK) {
			return ret;
		}

		ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
		if (ret != AW_OK) {
			return ret;
		}

		ret = aw9320x_check_isp_go_reg();
		if (ret != AW_OK) {
			return ret;
		}
	}

	ret = aw9320x_i2c_write(REG_T_RCV, REG_SET_T_RCV_EN);
	if (ret != AW_OK) {
		return ret;
	}

	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		return ret;
	}

	return AW_OK;
}

int32_t aw9320x_flash_update(struct aw_update_common *update_info)
{
	int32_t ret = 0;
	uint32_t check_sum = 0;

	//1.open register access enable
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_REG_ACCESS_EN);
	if (ret != AW_OK) {
		return ret;
	}

	ret = aw9320x_i2c_write(REG_MCFG, REG_OPEN_MCFG_EN);
	if (ret != AW_OK) {
		return ret;
	}

	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		return ret;
	}

	if (update_info->update_flag == FRIMWARE_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			return ret;
		}
	}

	//2.Erase sector (0x3800~0x37ff)
	ret = aw9320x_erase_sector(update_info);
	if (ret != AW_OK) {
		return ret;
	}

	//3.write boot
	ret = aw9320x_reg_write_bin_to_flash(update_info);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//4.read data check
	ret = aw9320x_rd_or_wi_cmp(update_info,
				   update_info->w_bin_offset,
				   update_info->update_data_len);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//5.write checksum en
	ret = aw9320x_reg_write_val_to_flash(update_info->check_info->w_check_en_addr,
					AW_CHECK_EN_VAL, update_info);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//6.write checksum data
	check_sum = aw9320x_get_bin_checksum(update_info->w_bin_offset,
						update_info->update_data_len,
						update_info->check_info->check_len);
	ret = aw9320x_reg_write_val_to_flash(update_info->check_info->w_check_code_addr,
					check_sum, update_info);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	//7.open flash protect
	if (update_info->update_flag == FRIMWARE_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_ENSET_BTROM_EW_EN);
		if (ret != AW_OK) {
			return ret;
		}
	}

	return AW_OK;
}

int32_t aw9320x_update_fw_to_flash(void)
{
	uint32_t arr_len = sizeof(fw_para_data) / sizeof(fw_para_data[0]);
	int32_t ret = 0;

	ret = aw9320x_check_sum(fw_para_data, arr_len);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	struct check_info fw_check_info = {
		.check_len = AW_FW_CHECK_LEN,
		.flash_check_start_addr = AW_FW_CHECK_START_ADDR,
		.w_check_en_addr = AW_FW_CHECK_EN_ADDR,
		.w_check_code_addr = AW_FW_CHECK_CODE_ADDR,
	};

	struct aw_update_common fw_update = {
		.update_flag = FRIMWARE_UPDATE,
		.w_bin_offset = &fw_para_data[72],
		.update_data_len = AW_GET_32_DATA(fw_para_data[71], fw_para_data[70], fw_para_data[69], fw_para_data[68]),
		.flash_tr_start_addr = AW_FW_TR_START_ADDR,
		.check_info = &fw_check_info,
	};

	return aw9320x_flash_update(&fw_update);
}
/*********************reg mode update boot/frimware end*********************/

/*********************protocol update frimware start****************** *****/

static uint32_t get_pack_checksum(uint8_t *data, uint16_t length, uint8_t module, uint8_t command)
{
	uint32_t i = 0;
	uint32_t check_sum = 0;

	check_sum = module + command + length;
	for (i = 0; i < length; i += 4)
		check_sum += AW_GET_32_DATA(data[i + 0], data[i + 1], data[i + 2], data[i + 3]);

	return (~check_sum + 1);
}

static int32_t dri_to_soc_pack_send(uint8_t module, uint8_t command, uint16_t length, uint8_t *data)
{
	int8_t cnt = AW_RETRIES;
	int32_t ret = -1;
	uint32_t checksum = 0;
	uint8_t *prot_pack_w = (uint8_t *)malloc(AW_PACK_FIXED_SIZE + length + SEND_ADDR_LEN);

	if (prot_pack_w == NULL) {
		AWLOGE("malloc err!");
		return -1;
	}

	prot_pack_w[0] = ((uint16_t)PROT_SEND_ADDR & GET_BITS_15_8) >> OFFSET_BIT_8;
	prot_pack_w[1] = (uint16_t)PROT_SEND_ADDR & GET_BITS_7_0;

	//header
	prot_pack_w[2] = ((uint16_t)AW_HEADER_VAL & GET_BITS_15_8) >> OFFSET_BIT_8;
	prot_pack_w[3] = (uint16_t)AW_HEADER_VAL & GET_BITS_7_0;

	//size
	prot_pack_w[4] = ((uint16_t)(AW_PACK_FIXED_SIZE + length) & GET_BITS_15_8) >> OFFSET_BIT_8;
	prot_pack_w[5] = (uint16_t)(AW_PACK_FIXED_SIZE + length) & GET_BITS_7_0;

	//checksum
	checksum = get_pack_checksum(data, length, module, command);
	prot_pack_w[6] = ((uint32_t)checksum & GET_BITS_31_25) >> OFFSET_BIT_24;
	prot_pack_w[7] = ((uint32_t)checksum & GET_BITS_24_16) >> OFFSET_BIT_16;
	prot_pack_w[8] = ((uint32_t)checksum & GET_BITS_15_8) >> OFFSET_BIT_8;
	prot_pack_w[9] = (uint32_t)checksum & GET_BITS_7_0;

	//module
	prot_pack_w[10] = module;

	//command
	prot_pack_w[11] = command;

	//length
	prot_pack_w[12] = ((uint16_t)length & 0xff00) >> OFFSET_BIT_8;
	prot_pack_w[13] = (uint16_t)length & 0x00ff;

	//value
	if (length != 0 && data != NULL)
		memcpy(prot_pack_w + AW_PACK_FIXED_SIZE + SEND_ADDR_LEN, data, length);

	do {
		ret = i2c_write_seq(prot_pack_w, AW_PACK_FIXED_SIZE + AW_ADDR_SIZE + length);
		if (ret < 0)
			AWLOGE("dri_to_soc_pack_send err cnt = %d", cnt);
		else
			break;
	} while (cnt--);

	free(prot_pack_w);

	if (cnt < 0) {
		AWLOGE("dri_to_soc_pack_send err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t
soc_to_dri_pack_recv(struct aw_soc_protocol *prot_pack, uint32_t pack_len, uint8_t *addr)
{
	int8_t cnt = AW_RETRIES;
	int32_t ret = -1;

	if (prot_pack == NULL || pack_len == 0)
		return -1;

	do {
		ret = i2c_read_seq(addr, 2, (uint8_t *)prot_pack, pack_len);
		if (ret < 0)
			AWLOGE("soc_to_dri_pack_recv err cnt = %d", cnt);
		else
			break;
	} while (cnt--);

	if (cnt < 0) {
		AWLOGE("soc_to_dri_pack_recv err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t soc_to_dri_pack_parse(uint32_t length, uint8_t module, uint8_t command)
{
	int32_t ret = -1;
	uint32_t pack_len = AW_PACK_FIXED_SIZE + length;
	uint8_t ack_addr[2] = { 0 };
	uint32_t cmd_status = 0;

	struct aw_soc_protocol *prot_pack_r = (struct aw_soc_protocol *)malloc(pack_len);
	if (prot_pack_r == NULL) {
		AWLOGE("malloc err!");
		return -1;
	}

	ack_addr[0] = (uint8_t)(AW_ACK_ADDR >> OFFSET_BIT_8);
	ack_addr[1] = (uint8_t)AW_ACK_ADDR;

	ret = soc_to_dri_pack_recv(prot_pack_r, pack_len, ack_addr);
	if (ret != AW_OK) {
		AWLOGE("soc_to_dri_pack_recv err!");
		goto err_pack_parse;
	}

	prot_pack_r->header = AW_REVERSEBYTERS_U16(prot_pack_r->header);
	prot_pack_r->size = AW_REVERSEBYTERS_U16(prot_pack_r->size);
	prot_pack_r->length = AW_REVERSEBYTERS_U16(prot_pack_r->length);
	prot_pack_r->checksum = AW_REVERSEBYTERS_U32(prot_pack_r->checksum);

	cmd_status = AW_GET_32_DATA(prot_pack_r->value[3], prot_pack_r->value[2],
				    prot_pack_r->value[1], prot_pack_r->value[0]);

	if ((module == prot_pack_r->module) && (command == prot_pack_r->command) && (cmd_status == 0)) {
	} else {
		AWLOGE("soc_to_dri_pack_parse err");
		return -AW_ERR;
	}

	free(prot_pack_r);

	return AW_OK;

err_pack_parse:
	free(prot_pack_r);
	return -AW_ERR;
}

static int32_t aw9320x_fw_version_cmp(int8_t *cmp_val, uint32_t app_version)
{
	uint32_t firmware_version = 0;
	int32_t ret = -AW_ERR;

	ret = aw9320x_i2c_read(REG_FIRMWARE, &firmware_version);
	if (ret < 0) {
		AWLOGE("read firmware version err");
		return -AW_ERR;
	}

	AWLOGD("REG_FIRMWARE :0x%08x bin_fwver :0x%08x!",
			firmware_version, app_version);

	if (app_version != firmware_version) {
		*cmp_val = AW9320X_VER_NOT_EQUAL;
	} else {
		*cmp_val = AW9320X_VER_EQUAL;
	}

	return AW_OK;
}

static int32_t aw9320x_read_ack_irq(void)
{
	uint32_t irq_stat = 0;
	int32_t cnt = AW_WAIT_IRQ_CYCLES;
	int32_t ret = 0;

	if (prot_update_fw_flag == SEND_UPDATE_FW_CMD) {
		cnt = AW_PROT_STOP_WAIT_IRQ_CYCLES;
	}

	do {
		ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
		if (ret != AW_OK) {
			AWLOGE("read REG_HOSTIRQSRC err");
			return -AW_ERR;
		}
		if (((irq_stat >> 29) & 0x01) == 1) {
			break;
		}
		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGE("read_ack_irq err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_read_init_comp_irq(void)
{
	uint32_t irq_stat = 0;
	int32_t cnt = 10;
	int32_t ret = 0;

	do {
		ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
		if (ret != AW_OK) {
			AWLOGE("read REG_HOSTIRQSRC err");
			return -AW_ERR;
		}

		if ((irq_stat & 0x01) == INIT_OVER_IRQ_OK) {
			break;
		}

		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGE("read_init_comp_irq err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t
aw9320x_send_once_cmd(uint8_t module, uint8_t command, uint8_t *send_value, uint16_t send_val_len)
{
	int32_t ret = -AW_ERR;
	uint8_t recv_len = 0;
	uint32_t delay_ms_cnt = 0;

	//1.send cmd
	ret = dri_to_soc_pack_send(module, command,
				send_val_len, send_value);
	if (ret != AW_OK) {
		AWLOGE("dri_to_soc_pack_send err");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(AW_BT_PROT_CMD_PACK_ADDR, AW_SRAM_FIRST_DETECT);
	if (ret != AW_OK) {
		AWLOGE("aw9320x_i2c_write err");
		return -AW_ERR;
	}

	//2.send trig
	ret = aw9320x_i2c_write(REG_CMD, REG_H2C_TRIG_PARSE_CMD);
	if (ret != AW_OK) {
		AWLOGE("aw9320x_i2c_write err");
		return -AW_ERR;
	}

	switch (prot_update_fw_flag) {
	case SEND_START_CMD:
		recv_len = SEND_START_CMD_RECV_LEN;
		delay_ms_cnt = SEND_START_CMD_DELAY_MS;
		break;
	case SEND_ERASE_SECTOR_CMD:
		recv_len = SEND_ERASE_CHIP_CMD_RECV_LEN;
		delay_ms_cnt = SEND_ERASE_SECTOR_CMD_DELAY_MS;
		break;
	case SEND_UPDATE_FW_CMD:
		recv_len = SEND_UPDATE_FW_CMD_RECV_LEN;
		delay_ms_cnt = 0;
		break;
	case SEND_UPDATE_CHECK_CODE_CMD:
		recv_len = SEND_UPDATE_CHECK_CODE_CMD_RECV_LEN;
		delay_ms_cnt = SEND_UPDATE_CHECK_CODE_CMD_DELAY_MS;
		break;
	case SEND_RESTORE_CMD:
		recv_len = SEND_RESTORE_CMD_RECV_LEN;
		delay_ms_cnt = SEND_RESTORE_CMD_DELAY_MS;
		break;
	default:
		recv_len = 0;
		delay_ms_cnt = 0;
		break;
	}

	AW_DELAY(delay_ms_cnt);

	//3.Read interrupt information, wait 100ms
	ret = aw9320x_read_ack_irq();
	if (ret != AW_OK) {
		AWLOGE("aw9320x_read_ack_irq err");
		return -AW_ERR;
	}

	//4.read start ack and pare pack
	ret = soc_to_dri_pack_parse(recv_len, module, command);
	if (ret != AW_OK) {
		AWLOGE("soc_to_dri_pack_parse err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_send_stop_cmd(void)
{
	int32_t ret = -AW_ERR;

	aw9320x_i2c_write(AW_REG_MCFG, AW_CPU_HALT);
	aw9320x_i2c_write(AW_REG_ACESS_EN, AW_ACC_PERI);
	aw9320x_i2c_write_bits(REG_UPDATA_DIS, AW_REG_UPDATA_DIS_MASK, 0);
	aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
	aw9320x_i2c_write(AW_REG_MCFG, AW_CPU_RUN);

	AW_DELAY(SEND_STOP_CMD_DELAY_MS);

	ret = aw9320x_read_init_comp_irq();
	if (ret != AW_OK) {
		AWLOGE("read_init_comp_irq err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_cycle_write_firmware(
					    const uint8_t *fw_data, uint32_t firmware_len,
					    uint32_t flash_addr)
{
	uint8_t value_head_len = TRANSFER_SEQ_LEN + TRANSFER_DTS_ADDR_LEN;
	uint32_t seq = 1;
	int32_t ret = -AW_ERR;
	uint32_t i = 0;
	uint32_t start_addr = 0;
	uint32_t word_comp_len = 0;
	uint32_t cycle_cnt = 0;
	uint32_t cycle_cnt_last_len = 0;
	uint32_t send_all_len = 0;
	uint8_t *firmware_info = NULL;
	uint16_t half_cache_len = AW_CACHE_LEN / 16; //max.4058

	if (firmware_len % WORD_LEN != 0) {
		word_comp_len = WORD_LEN - firmware_len % WORD_LEN;
	}
	firmware_len = firmware_len + word_comp_len;

	cycle_cnt = firmware_len / half_cache_len;
	cycle_cnt_last_len = firmware_len % half_cache_len;
	send_all_len = firmware_len + value_head_len;

	AWLOGD("firmware_len=%dcycle_cnt=%d last_len =%dall_len=%d",
			firmware_len, cycle_cnt, cycle_cnt_last_len, send_all_len);

	for (i = 0; i < cycle_cnt; i++) {
		firmware_info = (uint8_t *)malloc(half_cache_len + value_head_len);
		if (firmware_info == NULL) {
			AWLOGE("malloc err");
			return -AW_ERR;
		}
		memset(firmware_info, 1, half_cache_len + value_head_len);

		firmware_info[0] = (uint8_t)(seq >> OFFSET_BIT_24);
		firmware_info[1] = (uint8_t)(seq >> OFFSET_BIT_16);
		firmware_info[2] = (uint8_t)(seq >> OFFSET_BIT_8);
		firmware_info[3] = (uint8_t)(seq);
		firmware_info[4] = (uint8_t)(flash_addr >> OFFSET_BIT_24);
		firmware_info[5] = (uint8_t)(flash_addr >> OFFSET_BIT_16);
		firmware_info[6] = (uint8_t)(flash_addr >> OFFSET_BIT_8);
		firmware_info[7] = (uint8_t)(flash_addr);

		memcpy(firmware_info + value_head_len,
				&(fw_data[start_addr + half_cache_len * i]), half_cache_len);


		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
					firmware_info, half_cache_len + value_head_len);
		if (ret != AW_OK) {
			AWLOGE("cnt%d dri_to_soc_pack_send err", i);
			goto err_hand;
		}
		if (firmware_info != NULL) {
			free(firmware_info);
			firmware_info = NULL;
		}
		flash_addr += half_cache_len;
		seq++;
	}

	if (cycle_cnt_last_len != 0) {
		firmware_info = (uint8_t *)malloc(cycle_cnt_last_len + value_head_len);
		if (firmware_info == NULL) {
			AWLOGE("malloc err");
			goto err_hand;
		}
		memset(firmware_info, 1, cycle_cnt_last_len + value_head_len);

		firmware_info[0] = (uint8_t)(seq >> OFFSET_BIT_24);
		firmware_info[1] = (uint8_t)(seq >> OFFSET_BIT_16);
		firmware_info[2] = (uint8_t)(seq >> OFFSET_BIT_8);
		firmware_info[3] = (uint8_t)(seq);
		firmware_info[4] = (uint8_t)(flash_addr >> OFFSET_BIT_24);
		firmware_info[5] = (uint8_t)(flash_addr >> OFFSET_BIT_16);
		firmware_info[6] = (uint8_t)(flash_addr >> OFFSET_BIT_8);
		firmware_info[7] = (uint8_t)(flash_addr);

		memcpy(firmware_info + value_head_len,
				&(fw_data[start_addr + cycle_cnt * half_cache_len]),
				cycle_cnt_last_len);

		if (flash_addr + cycle_cnt_last_len >= AW_NVR_ADDR) {
			AWLOGE("flash addr write err, addr=0x%08X, len=0x%04X",
					flash_addr, cycle_cnt_last_len);
			goto err_hand;
		}

		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
					firmware_info, cycle_cnt_last_len + value_head_len);
		if (ret != AW_OK) {
			AWLOGE("last dri_to_soc_pack_send err");
			goto err_hand;
		}
		if (firmware_info != NULL) {
			free(firmware_info);
			firmware_info = NULL;
		}
	}

	return AW_OK;

err_hand:
	if (firmware_info != NULL) {
		free(firmware_info);
		firmware_info = NULL;
	}

	return -AW_ERR;
}

static int32_t aw9320x_write_firmware_checksum(uint8_t *p_checksum)
{
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t transfer_value_w[AW_EN_TR_CHECK_VALUE_LEN] = { 0 };
	int32_t ret = 0;
	uint32_t r_check_en = 0;
	uint32_t r_checksum = 0;
	uint32_t w_checksum = 0;

	for (i = 0; i < 4; i++) {
		transfer_value_w[i] = (uint8_t)(0 >> ((3 - i) * 8));
	}
	for (i = 4; i < 8; i++) {
		transfer_value_w[i] = (uint8_t)(AW_FW_CHECKSUM_EN_ADDR >> ((3 - j) * 8));
		j++;
	}
	j = 0;
	for (i = 8; i < 12; i++) {
		transfer_value_w[i] = (uint8_t)(AW_CHECK_EN_VAL >> ((3 - j) * 8));
		j++;
	}
	j = 0;
	for (i = 12; i < 16; i++) {
		transfer_value_w[i] = p_checksum[j];
		j++;
	}

	ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
						transfer_value_w, AW_EN_TR_CHECK_VALUE_LEN);
	if (ret != AW_OK) {
		AWLOGE("send checksum err");
		return -AW_ERR;
	}

	ret = aw9320x_reg_read_val(&r_check_en, AW_FW_CHECK_EN_ADDR);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	ret = aw9320x_reg_read_val(&r_checksum, AW_FW_CHECK_CODE_ADDR);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	w_checksum = AW_GET_32_DATA(p_checksum[0], p_checksum[1], p_checksum[2], p_checksum[3]);

	if ((r_check_en == AW_CHECK_EN_VAL) && (r_checksum == w_checksum)) {
		return AW_OK;
	} else {
		return -AW_ERR;
	}
}

static int32_t aw9320x_get_fw_and_bt_info(
				const uint8_t *fw_data, uint32_t fw_len,
				uint8_t *p_fw_check_sum)
{
	uint32_t fw_checksum = 0;
	int32_t ret = 0;
	uint32_t bt_version = 0;
	uint32_t bt_date = 0;
	uint32_t bt_checksum = 0;

	ret = aw9320x_i2c_read(AW_BT_VER_INF_VERSION, &bt_version);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	ret = aw9320x_i2c_read(AW_BT_VER_INF_DATE, &bt_date);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		return -AW_ERR;
	}
	ret = aw9320x_reg_read_val(&bt_checksum, AW_BT_CHECK_SUM_ADDR);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	AWLOGD("boot version:0x%08x, date:0x%08x, checksum 0x%08x",
			bt_version, bt_date, bt_checksum);

	fw_checksum = aw9320x_get_bin_checksum(fw_data, fw_len, AW_FW_CHECK_LEN);

	p_fw_check_sum[0] = (uint8_t)(fw_checksum >> 24);
	p_fw_check_sum[1] = (uint8_t)(fw_checksum >> 16);
	p_fw_check_sum[2] = (uint8_t)(fw_checksum >> 8);
	p_fw_check_sum[3] = (uint8_t)(fw_checksum >> 0);

	return AW_OK;
}

static int32_t aw9320x_flash_erase_sector(void)
{
	uint8_t i = 0;
	uint32_t erase_addr = AW_FLASH_ERASE_SECTOR_START_ADDR;
	uint8_t addr_buf[4] = { 0 };
	int32_t ret = 0;

	for (i = 0; i < AW_ERASE_SECTOR_CNT; i++) {
		addr_buf[0] = (uint8_t)(erase_addr >> OFFSET_BIT_24);
		addr_buf[1] = (uint8_t)(erase_addr >> OFFSET_BIT_16);
		addr_buf[2] = (uint8_t)(erase_addr >> OFFSET_BIT_8);
		addr_buf[3] = (uint8_t)(erase_addr);
		prot_update_fw_flag = SEND_ERASE_SECTOR_CMD;
		ret = aw9320x_send_once_cmd(FLASH_MODULE, FLASH_ERASE_SECTOR_CMD,
					addr_buf, sizeof(addr_buf));
		if (ret != AW_OK) {
			AWLOGE("erase sector err");
			break;
		}
		erase_addr += AW_SECTOR_SIZE;
	}

	return ret;
}

static int32_t aw9320x_flash_erase_last_sector(void)
{
	uint32_t erase_addr = AW_FLASH_ERASE_SECTOR_START_ADDR + AW_SECTOR_SIZE * AW_ERASE_SECTOR_CNT;
	uint8_t addr_buf[4] = { 0 };
	int32_t ret = 0;

	addr_buf[0] = (uint8_t)(erase_addr >> OFFSET_BIT_24);
	addr_buf[1] = (uint8_t)(erase_addr >> OFFSET_BIT_16);
	addr_buf[2] = (uint8_t)(erase_addr >> OFFSET_BIT_8);
	addr_buf[3] = (uint8_t)(erase_addr);
	prot_update_fw_flag = SEND_ERASE_SECTOR_CMD;
	ret = aw9320x_send_once_cmd(FLASH_MODULE, FLASH_ERASE_SECTOR_CMD,
				addr_buf, sizeof(addr_buf));
	if (ret != AW_OK) {
		AWLOGE("erase last sector err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_send_online_cmd(void)
{
	int32_t ret = 0;
	int32_t cnt = 200;
	uint32_t irq_stat = 0;

	ret = aw9320x_i2c_write(AW_BT_HOST2CPU_TRIG, AW_BT_HOST2CPU_TRIG_ONLINE_UPGRADE_CMD);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	AW_DELAY(1);

	do {
		ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		if (((irq_stat >> 29) & 0x01) == 1)
			break;
		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGE("send online cmd err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_send_all_update_cmd(
					const uint8_t *fw_data,
					uint32_t fw_len,
					uint8_t load_fw_mode)
{
	int8_t update_flag = AW_TRUE;
	int32_t ret = -AW_ERR;
	uint32_t data_tmp = 0;
	uint8_t fw_check_sum[4] = { 0 };
	uint32_t reg_boot_loader_active_val = 0;

	do {
		ret = aw9320x_send_online_cmd();
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		ret = aw9320x_get_fw_and_bt_info(fw_data, fw_len, fw_check_sum);
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		prot_update_fw_flag = SEND_START_CMD;
		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_START_CMD,
				P_AW_START_CMD_SEND_VALUE, AW_START_CMD_SEND_VALUE_LEN);
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		ret = aw9320x_flash_erase_last_sector();
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		prot_update_fw_flag = SEND_UPDATE_CHECK_CODE_CMD;
		ret = aw9320x_write_firmware_checksum(fw_check_sum);
		if (ret != AW_OK) {
				update_flag = AW_FALSE;
				break;
		}

		ret = aw9320x_flash_erase_sector();
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		prot_update_fw_flag = SEND_UPDATE_FW_CMD;
		ret = aw9320x_cycle_write_firmware(fw_data, fw_len, AW_FLASH_HEAD_ADDR);
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}

		prot_update_fw_flag = SEND_STOP_CMD;
		ret = aw9320x_send_stop_cmd();
		if (ret != AW_OK) {
			update_flag = AW_FALSE;
			break;
		}
	} while (0);

	if (update_flag == AW_FALSE) {
		ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_OPEN);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		ret = aw9320x_i2c_read(REG_BOOT_LOADER_ACTIVE, &reg_boot_loader_active_val);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		if (reg_boot_loader_active_val != 0) {
			ret = aw9320x_i2c_write(REG_BOOT_LOADER_ACTIVE, 0);
				if (ret != AW_OK) {
				return -AW_ERR;
			}
		}
		ret = aw9320x_i2c_read(REG_UPDATA_DIS, &data_tmp);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		if (((data_tmp >> 24) & 0xff) != 0) {
			ret = aw9320x_i2c_write(REG_UPDATA_DIS, data_tmp & AW_REG_UPDATA_DIS_MASK);
			if (ret != AW_OK) {
				return -AW_ERR;
			}
		}
		ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
		if (ret != AW_OK) {
			return -AW_ERR;
		}
		if (load_fw_mode == AW_DIRECT_LOAD) {
			return -AW_ERR;
		}
		return -AW_PROT_UPDATE_ERR;
	}

	return AW_OK;
}

int32_t aw9320x_fw_update(uint8_t load_fw_mode)
{
	int8_t cmp_val = 0;
	int32_t ret = 0;
	uint32_t arr_len = sizeof(fw_para_data) / sizeof(fw_para_data[0]);

	ret = aw9320x_check_sum(fw_para_data, arr_len);
	if (ret != AW_OK) {
		return -AW_ERR;
	}

	struct aw_fw_load_info fw_load_info = {
		.fw_len = AW_GET_32_DATA(fw_para_data[71], fw_para_data[70], fw_para_data[69], fw_para_data[68]),
		.p_fw_data = &fw_para_data[72],
		.app_version = AW_GET_32_DATA(fw_para_data[63], fw_para_data[62], fw_para_data[61], fw_para_data[60]),
		.load_fw_mode = load_fw_mode,
	};

	if (fw_load_info.load_fw_mode == AW_COMPARE_VERSION_LOAD) {
		aw9320x_fw_version_cmp(&cmp_val, fw_load_info.app_version);
		if (cmp_val == AW9320X_VER_EQUAL) {
	 		return AW_OK;
		}
	}

	return aw9320x_send_all_update_cmd(fw_load_info.p_fw_data, fw_load_info.fw_len, load_fw_mode);
}

static int32_t aw9320x_get_err_info(void)
{
	uint32_t err_code = 0;
	uint32_t boot_mode = 0;
	uint32_t jump_info = 0;

	aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_OPEN);
	//Get error check code,(0x09: Firmware verification failed.0x7:boot verification failed)
	aw9320x_i2c_read(AW9320X_SRAM_ERROR_CODE, &err_code);
	//The bit[31:24] must be 0, otherwise the boot cannot be jumped out actively
	aw9320x_i2c_read(REG_UPDATA_DIS, &jump_info);
	//bit8 0:Boot from ROM, 1: Boot from RAM
	aw9320x_i2c_read(REG_MCFG, &boot_mode);
	AWLOGE("0x1c00:0x%x, 0x4744:0x%x, 0x4444:0x%x", err_code, jump_info, boot_mode);
	aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);

	return AW_OK;
}

static int32_t aw9320x_update_err_handle(void)
{
	int32_t ret = -1;

	ret = aw9320x_update_fw_to_flash();
	if (ret != AW_OK) {
		AWLOGE("update_fw_to_flash failed :%d", ret);
		return -AW_ERR;
	}

	ret = aw9320x_soft_reset();
	if (ret != AW_OK) {
		AWLOGE("soft_reset err");
		return -AW_ERR;
	}

	ret = aw9320x_read_chipid();
	if (ret != AW_OK) {
		AWLOGE("read_chipid err");
		return -AW_ERR;
	}

	ret = aw9320x_init_irq_handle();
	if (ret != AW_OK) {
		AWLOGE("init_over_irq err");
		return -AW_ERR;
	}

	return AW_OK;
}

void aw9320x_get_irq_stat(struct cap_event_status *p_irq_stat_data, uint32_t *irq_status)
{
	int32_t ret = 0;
	uint32_t irq_stat = 0;

	ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
	if (ret < 0) {
		AWLOGE("i2c IO error");
		return;
	}

	/*
	 * Awinic reference: flag records whether any interrupt source was handled;
	 * the "no valid interrupt" branch (irq_trigger = AW_FALSE) was emptied by
	 * the vendor.  The leftover test with its return keeps the target's block
	 * layout (wearing stores out of line, no IT blocks).
	 */
	uint8_t flag = AW_FALSE;

	if ((irq_stat >> REG_IRQSRC_EXIT_PROX_BIT) & 0x01) {
		aw9320x_wearing = OUT_EAR;
		flag = AW_TRUE;
	}
	if ((irq_stat >> REG_IRQSRC_PROX_BIT) & 0x01) {
		aw9320x_wearing = IN_EAR;
		flag = AW_TRUE;
	}
	if ((irq_stat >> REG_IRQSRC_INIT_BIT) & 0x01) {
		aw9320x_para_loaded();
		flag = AW_TRUE;
	}
	if (flag != AW_TRUE) {
		return;
	}
}

int32_t aw9320x_init(struct aw9320x_func *hw_fun)
{
	int32_t ret = -AW_ERR;
	uint8_t load_fw_mode = AW_COMPARE_VERSION_LOAD;

	AWLOGD("enter");
	AWLOGD("chip type:%s", AW9320X_I2C_NAME);
	AWLOGD("version:%s", AW9320X_DRIVER_VERSION);

	if ((hw_fun == NULL) || (hw_fun->i2c_func.i2c_r == NULL) || (hw_fun->i2c_func.i2c_w == NULL) ||
		(hw_fun->irq_init == NULL) || (hw_fun->delay == NULL)) {
		   AWLOGE("err! para is NULL");
		   return ret;
	}

	g_aw9320x_func = hw_fun;

	aw9320x_Global_var_rst_def_val();

	ret = aw9320x_read_chipid();
	if (ret == -AW_ERR) {
		return ret;
	}

	ret = aw9320x_soft_reset();
	if (ret != AW_OK) {
		AWLOGE("version_init failed :%d", ret);
		return -AW_ERR;
	}

	ret = aw9320x_init_irq_handle();
	if (ret == -AW_ERR) {
		AWLOGE("init irq_handle failed");
		return -AW_ERR;
	} else if (ret == -AW_ERR_IRQ_INIT) {
		AWLOGE("read_init_over_irq, ret=%d", ret);
		ret = aw9320x_get_err_info();
		load_fw_mode = AW_DIRECT_LOAD;
		AWLOGE("Firmware abnormal reload");
	} else {
		AWLOGD("read_init_over_irq ok!");
	}

	ret = aw9320x_fw_update(load_fw_mode);
	if (ret != AW_OK) {
		ret = aw9320x_update_err_handle();
		if (ret != AW_OK) {
			return -AW_ERR;
		}
	}

	ret = aw9320x_para_loaded();
	if (ret != AW_OK) {
		AWLOGE("aw9320x_para_loaded failed :%d", ret);
		return -AW_ERR;
	}

	AWLOGD("aw9320x init ok!");

	return 0;
}

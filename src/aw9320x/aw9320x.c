/*
* aw9320x.c
*
* Copyright ©2022 Shanghai Awinic Technology Co., Ltd. All Rights Reserved
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*/


#include "aw9320x.h"
#include "aw9320x_fw_info.h"
#include "aw9320x_bt_info.h"

#define AW9320X_I2C_NAME		"aw9320x_cap"
#define AW9320X_DRIVER_VERSION		"v1.11.0"

static int32_t old_mode = 0;
static uint32_t hostirqen = 0;
static uint8_t prot_update_fw_flag = 0;
static struct aw9320x_func *g_aw9320x_func = NULL;
//Interrupt mode is mutually exclusive to polling mode
volatile static uint8_t g_is_need_irq = 1;

AW_U8 g_air_send_buf[2 * sizeof(AW_S32) * AW_CHANNEL_NUM_MAX] = { 0 };
AW_U8 g_approach_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + 2] = { 0 };

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

//aot: Auto-Offset-Tuning
void aw9320x_aot_set(uint8_t cali_flag)
{
	if (cali_flag == AW_TRUE) {
		aw9320x_i2c_write_bits(REG_SCANCTRL0,
					AW_SCANCTR_AOTEN_MASK, AW_SCANCTR_AOTEN_EN);
	} else {
		AWLOGE("fail to set aot cali");
	}
}

void aw9320x_diff_get(int32_t *p_diff)
{
	int8_t i = 0;

	for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(REG_DIFF_CH0 + (i * AW_REG_STEP), (uint32_t *)&p_diff[i]);
		AWLOGD("diff: ch%d = %d", i, p_diff[i] >> AW_REMOVE_DECIMAL_BITS);
	}
}

#if defined(AW_SPP_USED) && defined(AW_OS_USED)
static int32_t aw9320x_app_data_unpack(uint8_t *in, uint8_t in_len, aw_app_prf_t *out)
{
	uint32_t valid_dat_len = 0;
	uint64_t sum_r = 0;
	uint64_t sum_v = 0;

	if (in[0] != APK_HEADER) {
		AWLOGD("%s : awinic frame header error.", __func__);
		return AW_ERR;
	}

	if (in[in_len - 2] != APK_END0 || in[in_len - 1] != APK_END1) {
		AWLOGD("%s : awinic frame end error.", __func__);
		return AW_ERR;
	}

	valid_dat_len = ((uint32_t)in[3] << 8) | in[2];
	AWLOGD("%s : aw valid_dat_len = %d.", __func__, valid_dat_len);

	for (int i = 0; i < valid_dat_len; i++) {
		sum_v += (long)in[i + 4];
	}
	sum_r = (uint64_t)(((uint64_t)in[APK_VALID_DATA_HEADER_V1 + valid_dat_len]) |
			((uint64_t)in[APK_VALID_DATA_HEADER_V1 + valid_dat_len + 1]) << AW_BIT8 |
			((uint64_t)in[APK_VALID_DATA_HEADER_V1 + valid_dat_len + 2]) << AW_BIT16 |
			((uint64_t)in[APK_VALID_DATA_HEADER_V1 + valid_dat_len + 3]) << AW_BIT24 |
			((uint64_t)in[APK_VALID_DATA_HEADER_V1 + valid_dat_len + 4]) << AW_BIT32 );
	if (sum_r != sum_v) {
		AWLOGD("%s : aw sum_r = 0x%lld  sum_v = 0x%lld.", __func__, sum_r, sum_v);
		return AW_ERR;
	}
	out->cmd = in[1];
	out->len = valid_dat_len;
	memcpy((void *)out->dat, (void *)&in[APK_VALID_DATA_HEADER_V1], valid_dat_len);

	return AW_OK;
}
static void aw9320x_app_data_send(uint8_t cmd, uint8_t *buf, uint32_t length)
{
	uint64_t sum = 0;
	uint8_t send_total_buf[800] = { 0 };

	send_total_buf[0] = APK_HEADER;
	send_total_buf[1] = cmd;
	send_total_buf[2] = (byte)(length & 0xff);
	send_total_buf[3] = (byte)(length >> 8) & 0Xff;

	for (int i = 0; i < length; i++) {
		sum += buf[i];
		send_total_buf[APK_VALID_DATA_HEADER_V1 + i] = buf[i];
	}

	send_total_buf[APK_VALID_DATA_HEADER_V1 + length] = (byte)(sum & AW_ONE_BYTE_1);
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 1] = (byte)((sum >> AW_BIT8) & AW_ONE_BYTE_1);
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 2] = (byte)((sum >> AW_BIT16) & AW_ONE_BYTE_1);
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 3] = (byte)((sum >> AW_BIT24) & AW_ONE_BYTE_1);
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 4] = (byte)((sum >> AW_BIT32) & AW_ONE_BYTE_1);
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 5] = APK_END0;
	send_total_buf[APK_VALID_DATA_HEADER_V1 + length + 6] = APK_END1;

	length += AW_SPP_PACK_END_LEN_V1;
	g_aw9320x_func->spp_func.spp_write(send_total_buf, (uint16_t)length);
}


static void aw9320x_data_pack_v1(AW_U8 cmd, AW_U8 *in, AW_U16 in_len, AW_U8 *out, AW_U16 *out_len)
{
	AW_U64 sum = 0;

	out[0] = APK_HEADER;
	out[1] = cmd;
	out[2] = (AW_U8)(in_len & 0xff);
	out[3] = (AW_U8)(in_len >> 8) & 0Xff;

	for (AW_U16 i = 0; i < in_len; i++) {
		sum += in[i];
		out[APK_VALID_DATA_HEADER_V1 + i] = in[i];
	}

	out[APK_VALID_DATA_HEADER_V1 + in_len] = (byte)(sum & AW_ONE_BYTE_1);
	out[APK_VALID_DATA_HEADER_V1 + in_len + 1] = (byte)((sum >> AW_BIT8) & AW_ONE_BYTE_1);
	out[APK_VALID_DATA_HEADER_V1 + in_len + 2] = (byte)((sum >> AW_BIT16) & AW_ONE_BYTE_1);
	out[APK_VALID_DATA_HEADER_V1 + in_len + 3] = (byte)((sum >> AW_BIT24) & AW_ONE_BYTE_1);
	out[APK_VALID_DATA_HEADER_V1 + in_len + 4] = (byte)((sum >> AW_BIT32) & AW_ONE_BYTE_1);
	out[APK_VALID_DATA_HEADER_V1 + in_len + 5] = APK_END0;
	out[APK_VALID_DATA_HEADER_V1 + in_len + 6] = APK_END1;

	*out_len = in_len + AW9320X_REDUNDANCY_DATA_LEN_V1;

}

static void aw9320x_app_data_send_v1(AW_U8 cmd, AW_U8 *buf, AW_U32 length)
{
	AW_U16 send_len = 0;
	AW_U8 send_total_buf[800] = { 0 };
	//AW_U16 i = 0;

	aw9320x_data_pack_v1(cmd, buf, length, send_total_buf, &send_len);

	//for(i=0;i<send_len;i++)
	//	printf("aw9320x_app_data_send_v1-----send_total_buf[%d]=0x%x\n",i,(AW_U8)send_total_buf[i]);
	g_aw9320x_func->spp_func.spp_write(send_total_buf, (AW_U16)(send_len));
}

static void aw9320x_app_get_reg(aw_app_prf_t app_data)
{
	uint16_t addr = 0;
	uint8_t sbuf[AW_SPP_REG_MAX_NUM * SAR_REG_DATA_LEN] = { 0 };
	uint8_t addr_arr[2] = { 0 };

	memcpy(&addr, app_data.dat, sizeof(uint16_t));
	if (app_data.dat[2] > AW_SPP_REG_MAX_NUM)
		app_data.dat[2] = AW_SPP_REG_MAX_NUM;

	addr_arr[0] = (addr >> OFFSET_BIT_8) & 0xff;
	addr_arr[1] = addr & 0xff;
	AWLOGD(" app_data.dat = %d, addr = 0x%x", app_data.dat[2], addr);
	i2c_read_seq(addr_arr, 2, sbuf, app_data.dat[2] * SAR_REG_DATA_LEN);
	for (int32_t i = 0; i < app_data.dat[2]; i++) {
		uint8_t tmp = sbuf[(i * SAR_REG_DATA_LEN) + 3];
		uint8_t tmp1 = sbuf[(i * SAR_REG_DATA_LEN) + 2];
		sbuf[(i * SAR_REG_DATA_LEN) + 3] = sbuf[(i * SAR_REG_DATA_LEN)];
		sbuf[(i * SAR_REG_DATA_LEN) + 2] = sbuf[(i * SAR_REG_DATA_LEN) + 1];
		sbuf[(i * SAR_REG_DATA_LEN) + 1] = tmp1;
		sbuf[(i * SAR_REG_DATA_LEN)] = tmp;
	}

	aw9320x_app_data_send(AW_APP_CMD_READ_REG, sbuf, app_data.dat[2] * SAR_REG_DATA_LEN);
}

static void aw9320x_app_set_reg(aw_app_prf_t app_data)
{
	uint16_t addr = 0;
	uint32_t data = 0;
	uint8_t sbuf = 0;

	memcpy(&addr, app_data.dat, sizeof(uint16_t));
	memcpy(&data, &app_data.dat[2], sizeof(uint32_t));
	AWLOGD("awinic addr = 0x%x, data = 0x%x", addr, data);
	aw9320x_i2c_write(addr, data);

	aw9320x_app_data_send(AW_APP_CMD_WRITE_REG, &sbuf, sizeof(uint8_t));
}

static void aw9320x_app_send_dev_info(void)
{
	uint8_t buf[6];

	buf[0] = AW_CHIP_CAP;
	buf[1] = AW_SAR_REG_LEN;
	buf[2] = AW_SAR_DATA_LEN;
	buf[3] = AW_COMM_CYCLE;
	buf[4] = PACKS_IN_ONE_COMM;
	buf[5] = AW_CURVE_DATA_LEN;
	aw9320x_app_data_send(AW_APP_CMD_GET_DEVICE_INFO, buf, sizeof(buf));
}

/**
 * @brief this func pack and wirte approach data to flash.
 *
 * @param in data need to write.
 * @param len data len
 */
static AW_U32 aw9320x_factory_cali_diff_write(AW_U8 *in, AW_U32 len)
{
	AW_U8 out[DATA_MAX_LEN] = { 0 };
	AW_U16 out_len = 0;

	aw9320x_data_pack_v1(AW_APP_CMD_SET_DIFF_TH, in, len, out, &out_len);

	return AW_OK;
}

/**
 * @brief this func detect if any channel connected to vdd or gnd.
 *
 *@param gnd_stat Pin short circuited to GND
 *@param vcc_stat Pin short circuited to VCC
 *return If 0, it is normal, otherwise it is abnormal
 */
AW_S8 aw9320x_short_circuit_detect_get_stat(AW_U32 *p_gnd_stat, AW_U32 *p_vcc_stat)
{
	AW_U32 stat = 0;

	aw9320x_mode_operation_set(AW9320X_SLEEP_MODE);

	aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_GPIO_ACCESS_EN);

	aw9320x_i2c_write(REG_GPIOMFP, 0x555);
	aw9320x_i2c_write(REG_GPIODIR, 0);
	aw9320x_i2c_write(REG_GPIOIBE, AW9320X_GPIO_DIRIN_EN);

	aw9320x_i2c_write(REG_GPIOPU, AW9320X_GPIO_PU_EN);
	aw9320x_i2c_write(REG_GPIOPD, AW9320X_GPIO_PD_DIS);
	aw9320x_i2c_read(REG_GPIORDATA, &stat);
	*p_gnd_stat = stat;
	if (stat != 0x3F) {
		for (AW_U32 i = 0; i < AW_CHANNEL_FOR_GPIO; i++) {
			if (((stat >> i) & 0x01) == 0) {
				AWLOGD("aw9320x channel %d connect the ground.", i);
				AWLOGD("stat: 0x%02X.", stat);
				return -1;
			}
		}
	}

	aw9320x_i2c_write(REG_GPIOPU, AW9320X_GPIO_PU_DIS);
	aw9320x_i2c_write(REG_GPIOPD, AW9320X_GPIO_PD_EN);
	aw9320x_i2c_read(REG_GPIORDATA, &stat);
	*p_vcc_stat = stat;
	if (stat != 0) {
		for (AW_U32 i = 0; i < AW_CHANNEL_FOR_GPIO; i++) {
			if (((stat >> i) & 0x01) == 1) {
				AWLOGD("aw9320x channel %d connect the power supply.", i);
				return -1;
			}
		}
	}

	// reset reg to pre-state.
	aw9320x_i2c_write(REG_GPIOPU, 0x0);
	aw9320x_i2c_write(REG_GPIOPD, 0x0);
	aw9320x_i2c_write(REG_GPIOMFP, 0x0);
	// aw9320x_i2c_write(REG_IEB,  0x40);

	aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);

	aw9320x_mode_operation_set(AW9320X_ACTIVE_MODE);

	return 0;
}

static void aw9320x_short_circuit_state_send(AW_U32 gnd, AW_U32 vcc)
{
#ifdef AW_SPP_USED
	AW_U8 sbuf[8] = {0};

	AWLOGD("short circuit detect gnd=[0x%08X], vcc=[0x%08X]", gnd, vcc);
	sbuf[0] = (uint8_t)gnd;
	sbuf[1] = (uint8_t)(gnd >> AW_BIT8);
	sbuf[2] = (uint8_t)(gnd >> AW_BIT16);
	sbuf[3] = (uint8_t)(gnd >> AW_BIT24);
	sbuf[4] = (uint8_t)vcc;
	sbuf[5] = (uint8_t)(vcc >> AW_BIT8);
	sbuf[6] = (uint8_t)(vcc >> AW_BIT16);
	sbuf[7] = (uint8_t)(vcc >> AW_BIT24);
	aw9320x_app_data_send_v1(AW_APP_CMD_SHORT_CIRCUIT, sbuf, sizeof(sbuf));
#endif
}

/**
 * @brief this func detect if any channel connected to vdd or gnd.
 *
 */
static void aw9320x_spp_short_circuit_detect(void)
{
	AW_U32 gnd_stat = 0;
	AW_U32 vcc_stat = 0;

	aw9320x_short_circuit_detect_get_stat(&gnd_stat, &vcc_stat);
	aw9320x_short_circuit_state_send(gnd_stat, vcc_stat);
}

/**
 * @brief send diff-prox data.
 *
 * @param diff_avg diff avg in prox state
 * @param avg_state diff avg in prox state
 * @param snr_state
 */
static void aw9320x_diff_approach_send(AW_S32 *diff_avg, AW_U8 avg_state, AW_U8 snr_state)
{
#ifdef AW_SPP_USED
	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		g_approach_send_buf[i * sizeof(AW_S32) + 0] = (uint8_t)diff_avg[i];
		g_approach_send_buf[i * sizeof(AW_S32) + 1] = (uint8_t)(diff_avg[i] >> AW_BIT8);
		g_approach_send_buf[i * sizeof(AW_S32) + 2] = (uint8_t)(diff_avg[i] >> AW_BIT16);
		g_approach_send_buf[i * sizeof(AW_S32) + 3] = (uint8_t)(diff_avg[i] >> AW_BIT24);
	}
	g_approach_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX] = avg_state;
	g_approach_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + 1] = snr_state;
#endif
}

/**
 * @brief this func sample diff data for 1s with press and calculate average value.
 *
 */
void aw9320x_diff_approach(void)
{
	AW_U8 diff_avg_save[AW_CHANNEL_NUM_MAX * sizeof(AW_S32)];
	AW_U32 ret = 0;
	AW_U32 sample_cnt = 100;
	AW_S32 diff[AW_CHANNEL_NUM_MAX];
	AW_S32 diff_avg[AW_CHANNEL_NUM_MAX];
	AW_S64 diff_sum[AW_CHANNEL_NUM_MAX];

	memset(diff_avg_save, 0, sizeof(diff_avg_save));
	memset(diff_avg, 0, sizeof(diff_avg));
	memset(diff_sum, 0, sizeof(diff_sum));
	memset(diff, 0, sizeof(diff));

	while (1) {
		sample_cnt--;
		if (sample_cnt <= 0) {
			sample_cnt = 100;
			break;
		}
		aw9320x_diff_get(diff);
		for (int i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
			diff[i] >>= 10;
			diff_sum[i] += diff[i];
		}
		AW_DELAY(10);
	}

	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		diff_avg[i] = diff_sum[i] / sample_cnt;
		AWLOGD("aw9320x diff_avg[%d] = 0x%x", i, diff_avg[i]);
		if (diff_avg[i] < AW9320X_DIFF_PROX_MIN || diff_avg[i] > AW9320X_DIFF_PROX_MAX)
			AWLOGD("aw9320x diff_avg[%d] = 0x%x", i, diff_avg[i]);
		diff_avg_save[i * 4] = (AW_U8)(diff_avg[i] & AW_ONE_BYTE_1);
		diff_avg_save[i * 4 + 1] = (AW_U8)(diff_avg[i] >> AW_BIT8 & AW_ONE_BYTE_1);
		diff_avg_save[i * 4 + 2] = (AW_U8)(diff_avg[i] >> AW_BIT16 & AW_ONE_BYTE_1);
		diff_avg_save[i * 4 + 3] = (AW_U8)(diff_avg[i] >> AW_BIT24 & AW_ONE_BYTE_1);
	}
	ret = aw9320x_factory_cali_diff_write(diff_avg_save, sizeof(diff_avg_save));
	if (ret)
		AWLOGD("aw9320x data write error");
	aw9320x_diff_approach_send(diff_avg, 0, 0);
}


static void aw9320x_diff_to_air_send(AW_S32 *diff_max, AW_S32 *diff_min)
{
#ifdef AW_SPP_USED
	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		g_air_send_buf[i * sizeof(AW_S32) + 0] = (uint8_t)diff_max[i];
		g_air_send_buf[i * sizeof(AW_S32) + 1] = (uint8_t)(diff_max[i] >> AW_BIT8);
		g_air_send_buf[i * sizeof(AW_S32) + 2] = (uint8_t)(diff_max[i] >> AW_BIT16);
		g_air_send_buf[i * sizeof(AW_S32) + 3] = (uint8_t)(diff_max[i] >> AW_BIT24);
	}
	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		g_air_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 0] =
			(uint8_t)diff_min[i];
		g_air_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 1] =
			(uint8_t)(diff_min[i] >> AW_BIT8);
		g_air_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 2] =
			(uint8_t)(diff_min[i] >> AW_BIT16);
		g_air_send_buf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 3] =
			(uint8_t)(diff_min[i] >> AW_BIT24);
	}
#endif
}

/**
 * @brief this func sample diff data for 5s without press and peak to peak value.
 *
 */
void aw9320x_diff_to_air(void)
{
	AW_U32 sample_cnt = 500;
	AW_S32 diff[AW_CHANNEL_NUM_MAX];
	AW_S32 diff_max[AW_CHANNEL_NUM_MAX];
	AW_S32 diff_min[AW_CHANNEL_NUM_MAX];
	AW_S32 diff_to_air_vpp[AW_CHANNEL_NUM_MAX];

	memset(diff, 0, sizeof(diff));
	memset(diff_max, 0, sizeof(diff_max));
	memset(diff_min, 0, sizeof(diff_min));
	memset(diff_to_air_vpp, 0, sizeof(diff_to_air_vpp));

	aw9320x_diff_get(diff);
	for (int i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		diff[i] >>= 10;
		diff_max[i] = diff[i];
		diff_min[i] = diff[i];
	}

	while (1) {
		sample_cnt--;
		if (sample_cnt <= 0) {
			break;
		}
		aw9320x_diff_get(diff);
		for (int i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
			diff[i] >>= 10;
			if (diff_max[i] < diff[i])
				diff_max[i] = diff[i];
			if (diff_min[i] > diff[i])
				diff_min[i] = diff[i];
		}
		AW_DELAY(10);
	}
	for (int i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		diff_to_air_vpp[i] = diff_max[i] - diff_min[i];
		AWLOGD("aw9320x diff_to_air_vpp[%d] = 0x%x", i, diff_to_air_vpp[i]);
		AWLOGD("aw9320x diff_max[%d] = 0x%x", i, diff_max[i]);
		AWLOGD("aw9320x diff_min[%d] = 0x%x", i, diff_min[i]);
	}
	aw9320x_diff_to_air_send(diff_max, diff_min);
	AWLOGD("leave");
}

void aw9320x_offset_cali_send(AW_U32 *offset, AW_U32 *init, AW_U8 offset_state, AW_U8 init_state)
{
#ifdef AW_SPP_USED
	AW_U8 sbuf[2 * sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + 2] = { 0 };

	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		sbuf[i * sizeof(AW_S32) + 0] = (uint8_t)offset[i];
		sbuf[i * sizeof(AW_S32) + 1] = (uint8_t)(offset[i] >> AW_BIT8);
		sbuf[i * sizeof(AW_S32) + 2] = (uint8_t)(offset[i] >> AW_BIT16);
		sbuf[i * sizeof(AW_S32) + 3] = (uint8_t)(offset[i] >> AW_BIT24);
	}
	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		sbuf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 0] = (uint8_t)init[i];
		sbuf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 1] = (uint8_t)(init[i] >> AW_BIT8);
		sbuf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 2] = (uint8_t)(init[i] >> AW_BIT16);
		sbuf[sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + i * sizeof(AW_S32) + 3] = (uint8_t)(init[i] >> AW_BIT24);
	}
	sbuf[2 * sizeof(AW_S32) * AW_CHANNEL_NUM_MAX] = offset_state;
	sbuf[2 * sizeof(AW_S32) * AW_CHANNEL_NUM_MAX + 1] = init_state;
	AWLOGD("aw9320x_offset_cali_send[%d]",sizeof(sbuf));
	aw9320x_app_data_send_v1(AW_APP_CMD_OFFSET_CALI, sbuf, sizeof(sbuf));
#endif
}

/**
 * @brief this func is used for parasitic capacitance calibration.
 *
 */
void aw9320x_offset_cali(void)
{
	AW_U8 offset_state = 0;
	AW_U8 init_state = 0;
	AW_U32 crange[AW_CHANNEL_NUM_MAX];
	AW_U32 offset[AW_CHANNEL_NUM_MAX];
	AW_S32 initial_data_after_cali[AW_CHANNEL_NUM_MAX];
	AW_U32 reg_afe_cfg1[] = {REG_AFECFG1_CH0, REG_AFECFG1_CH1, REG_AFECFG1_CH2,
		REG_AFECFG1_CH3, REG_AFECFG1_CH4, REG_AFECFG1_CH5,
		REG_AFECFG1_CH6, REG_AFECFG1_CH7,};
	AW_U32 reg_afe_cfg0[] = {REG_AFECFG0_CH0, REG_AFECFG0_CH1, REG_AFECFG0_CH2,
		REG_AFECFG0_CH3, REG_AFECFG0_CH4, REG_AFECFG0_CH5,
		REG_AFECFG0_CH6, REG_AFECFG0_CH7,};
	float cap[AW_CHANNEL_NUM_MAX];
	float aw9320x_cap_map[16][2] = { {0, 1.1}, {1, 2.2}, {2, 3.3}, {3, 4.4}, {4, 6.6}, {5, 7.7}, {6, 8.8}, {7, 9.9},
					{8, 11}, {9, 12.1}, {10, 13.2}, {11, 14.3}, {12, 16.5}, {13, 17.6}, {14, 18.7}, {15, 19.8} };

	//step 1: Parasitic capacitance calibration
	aw9320x_i2c_write(REG_SCANCTRL0, 0x0000ffff);

	//step 2: Waiting 500 ms for aot
	AW_DELAY(500);

	//step 3: Read offset data and restore
	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(reg_afe_cfg1[i], &offset[i]);
		offset[i] &= 0x0000ffff;
		AWLOGD("aw9320x reg = 0x%x  data = 0x%x", reg_afe_cfg1[i], offset[i]);
	}

	//step 4: Read the initial data after calibration and restore
	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(REG_INITVAL_CH0 + i * AW_REG_STEP, (AW_U32 *)&initial_data_after_cali[i]);
		AWLOGD("aw9320x reg = 0x%x, initial_data_after_cali[%d] = 0x%x", reg_afe_cfg0[i], i, initial_data_after_cali[i]);
	}

	//step 5: Judge whether the offset meets the expectation
	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		if ((offset[i] > AW9320X_OFFSET_MAX) || (offset[i] < AW9320X_OFFSET_MIN)) {
			offset_state &= ~(1 << i);
			AWLOGD("offset doesn't meets the expectation, offset[%d] = 0x%x", i, offset[i]);
		} else {
			offset_state |= 1 << i;
			AWLOGD("aw9320x offset[%d] = 0x%x", i, offset[i]);
		}
	}

	//step 6: Judge whether the initial data meets the expectation
	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(reg_afe_cfg0[i], &crange[i]);
		crange[i] >>= AW_BIT16;
		crange[i] &= 0x0000000f;
		AWLOGD("aw9320x crange[%d] = 0x%2x", i, crange[i]);
		for (AW_U32 j = 0; j < 16; j++) {
			if (crange[i] == aw9320x_cap_map[j][0]) {
				cap[i] = aw9320x_cap_map[j][1];
				AWLOGD("aw9320x cap[%d] = %d / 1000", i, (AW_U32)(cap[i] * 1000));
				break;
			}
		}
	}
	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		AWLOGD("aw9320x initial_data_after_cali[%d] = 0x%x", i, (AW_U32)(initial_data_after_cali[i]));
		AW_S32 result = (AW_S32)((initial_data_after_cali[i] >> 21) * cap[i]);
		if ((result < AW9320X_CAP_MIN) || (result > AW9320X_CAP_MAX)) {
			init_state &= ~(1 << i);
			AWLOGD("aw9320x initial data doesn't meet the expection, result[%d] = (%d / 1000)", i, (AW_U32)(result * 1000));
		} else {
			init_state |= 1 << i;
			AWLOGD("aw9320x result[%d] = (%d / 1000)", i, (AW_U32)(result * 1000));
		}
	}
	aw9320x_offset_cali_send(offset, (AW_U32 *)initial_data_after_cali, offset_state, init_state);
}

void aw9320x_spp_cmd_handler(uint8_t *dat, uint16_t len)
{
	aw_app_prf_t app_data;

	if (aw9320x_app_data_unpack(dat, len, &app_data) != AW_OK) {
		AWLOGD("_app_data_unpack err!");
		return;
	}

	switch (app_data.cmd) {
	case AW_APP_CMD_GET_DEVICE_INFO:
		AWLOGD("awinic get dev info");
		aw9320x_app_send_dev_info();
		break;
	case AW_APP_CMD_GET_CURVE_DATA:
		AWLOGD("awinic get curve info");
			g_is_need_irq = AW_FALSE;
			g_aw9320x_func->work_thread_func.set_signal(AW9320X_SPP_CURVE_RUN);
		break;
	case AW_APP_CMD_READ_REG:
		AWLOGD("awinic get reg");
		aw9320x_app_get_reg(app_data);
		break;
	case AW_APP_CMD_WRITE_REG:
		AWLOGD("awinic get curve info");
		aw9320x_app_set_reg(app_data);
		break;
	case AW_APP_CMD_GET_ALGO_PARA:
		AWLOGD("awinic get param info");
		break;
	case AW_APP_CMD_SET_ALGO_PARA:
		AWLOGD("awinic set param info");
		break;
	case AW_APP_CMD_OFFSET_CALI:
		AWLOGD("AW_APP_CMD_OFFSET_CALI");
		aw9320x_offset_cali();
		break;
	case AW_APP_CMD_DIFF_TO_AIR:
		AWLOGD("AW_APP_CMD_DIFF_TO_AIR");
		aw9320x_diff_to_air();
		aw9320x_app_data_send_v1(AW_APP_CMD_DIFF_TO_AIR,
				g_air_send_buf, sizeof(g_air_send_buf));
		break;
	case AW_APP_CMD_DIFF_APPROACH:
		AWLOGD("AW_APP_CMD_DIFF_APPROACH");
		aw9320x_diff_approach();
		aw9320x_app_data_send_v1(AW_APP_CMD_DIFF_APPROACH,
				g_approach_send_buf, sizeof(g_approach_send_buf));
		break;
	case AW_APP_CMD_SHORT_CIRCUIT:
		AWLOGD("AW_APP_CMD_SHORT_CIRCUIT");
		aw9320x_spp_short_circuit_detect();
		break;
	case AW_APP_CMD_SET_DIFF_TH:
		AWLOGD("AW_APP_CMD_SET_DIFF_TH");
		aw9320x_factory_cali_diff_write(app_data.dat, app_data.len);
		break;
	default:
		AWLOGD("no such commnd.");
		break;
	}
}
#endif

static int32_t aw9320x_read_chipid(void)
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
	case AW93208_CHIP_ID:
		AWLOGD("AW93208 CHIP ID : 0x%x", reg_val);
		break;
	default:
		AWLOGD("no chipid,need update root and frimware,CHIP ID : 0x%08x", reg_val);
		return -AW_ERR_CHIPID;
	}

	return AW_OK;
}

static int32_t aw9320x_recover_fun(uint8_t recover_flag)
{
	int32_t ret = 0;
	uint32_t reg_data = 0;
	uint32_t new_reg_data = 0;

	AWLOGE("enter");
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_REG_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	ret = aw9320x_i2c_read(REG_UPDATA_DIS, &reg_data);
	if (ret != AW_OK) {
		AWLOGE("read REG_UPDATA_DIS err: %d", ret);
		return ret;
	}

	AWLOGD("trim  reg_data:0x%08X", reg_data);

	if (recover_flag == REG_UPDATE_RECOVER) {
		new_reg_data = reg_data & 0x00ffffff;
	} else {
		if ((reg_data & 0xff000000) == 0xff000000) {
			new_reg_data = reg_data & 0x00ffffff;
		} else {
			new_reg_data = reg_data;
		}
	}

	AWLOGD("trim new_reg_data:0x%08X", new_reg_data);

	if (new_reg_data != reg_data) {
		AWLOGD("trim reg_data error, need update");
		ret = aw9320x_i2c_write(REG_UPDATA_DIS, new_reg_data);
		if (ret != AW_OK){
			AWLOGE("write REG_UPDATA_DIS err");
		}
	} else {
		AWLOGD("trim reg_data ok, no need update");
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err: %d", ret);
		return -AW_ERR;
	}

	return ret;
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

	ret = aw9320x_i2c_write(AW_BT_HOST2CPU_TRIG, AW_BT_HOST2CPU_TRIG_ONLINE_CLEAR_CMD);
	if (ret != AW_OK) {
		AWLOGE("write AW_BT_HOST2CPU_TRIG failed");
		return -AW_ERR;
	}

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

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
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
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	//Configure PMC_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	//Turn on flash write protection
	if (flash_addr_flag == BOOT_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			AWLOGE("write 0xff20 err");
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
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	//Write data
	ret = aw9320x_i2c_write(REG_ISPWDATA, w_data);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	//Configure ISP_CMD reg
	ret = aw9320x_i2c_write(REG_ISPCMD, REG_ISP_CMD_CONFIG);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	//Configure ISP_GO reg
	ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}

	ret = aw9320x_check_isp_go_reg();
	if (ret != AW_OK) {
		AWLOGE("check_isp_go_reg err");
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

	AWLOGD("enter");

	ret = aw9320x_close_write_flash_protect(update_info->update_flag);
	if (ret != AW_OK) {
		AWLOGE("close_write_flash_protect err");
		return -AW_ERR;
	}

	ret = aw9320x_reg_write_to_flash_once(addr, val);
	if (ret != AW_OK) {
		AWLOGE("write aw9320x_reg_write_bin_once err");
		return -AW_ERR;
	}

	//Configure PMU_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("write 0x4820 err");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	return AW_OK;
}

static int32_t aw9320x_reg_read_val(uint32_t *read_data, uint16_t start_addr)
{
	int32_t ret = 0;
	uint32_t isp_cmd_val;

	//3.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_ISPADR, start_addr);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG regerr");
		return -AW_ERR;
	}

	if (start_addr >= 0x4000)
		isp_cmd_val = REG_ISP_CMD_NVR;
	else
		isp_cmd_val = REG_ISP_CMD_MAIN_ARR;
	//4.config ISP_CMD reg
	ret = aw9320x_i2c_write(REG_ISPCMD, isp_cmd_val);
	if (ret != AW_OK) {
		AWLOGE("config ISP_CMD reg err");
		return -AW_ERR;
	}
	//5.config ISP_GO reg
	ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
	if (ret != AW_OK) {
		AWLOGE("config ISP_CMD reg err");
		return -AW_ERR;
	}
	//6.check isp_go reg
	ret = aw9320x_check_isp_go_reg();
	if (ret != AW_OK) {
		AWLOGE("config check_isp_go_reg err");
		return -AW_ERR;
	}
	//7 read data
	ret = aw9320x_i2c_read(REG_ISPRDATA, read_data);
	if (ret != AW_OK) {
		AWLOGE("config ISP_CMD reg err");
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

	AWLOGD("enter");

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}
	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG reg err");
		return -AW_ERR;
	}

	AWLOGE("read_cnt = %d", read_cnt);
	for (i = 0; i < read_cnt; i += WORD_LEN) {
		ret = aw9320x_reg_read_val(&r_data,
					update_info->flash_tr_start_addr + i);
		if (ret != AW_OK) {
			AWLOGE("reg_read_bin err");
			return -AW_ERR;
		}
		w_data = AW_GET_32_DATA(w_bin_offset[i + 0],
					w_bin_offset[i + 1],
					w_bin_offset[i + 2],
					w_bin_offset[i + 3]);
//		AWLOGD("i= %d, addr= 0x%08x, W_DATA= 0x%08x, R_DATA= 0x%08x",
//			i, update_info->flash_tr_start_addr + i, w_data, r_data);
		if (w_data != r_data) {
			AWLOGE("w_data != r_data err!");
			AWLOGE("i= %d, addr= 0x%08x, W_DATA= 0x%08x, R_DATA= 0x%08x",
			i, update_info->flash_tr_start_addr + i, w_data, r_data);
			return -AW_ERR;
		}
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}
	AWLOGD("END");

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

	AWLOGD("enter");

	ret = aw9320x_close_write_flash_protect(update_info->update_flag);
	if (ret != AW_OK) {
		AWLOGE("close_write_flash_protect err");
		return -AW_ERR;

	}
	for (i = 0; i < len; i += WORD_LEN, index += WORD_LEN) {
		w_data = AW_GET_32_DATA(p_data[index + 0], p_data[index + 1],
				p_data[index + 2], p_data[index + 3]);
		// AWLOGD("w_data :0x%08x", w_data);
		ret = aw9320x_reg_write_to_flash_once(flash_addr + i, w_data);
		if (ret != AW_OK) {
			AWLOGD("write aw9320x_reg_write_bin_once err");
			return -AW_ERR;
		}
	}

	//Configure PMU_ CFG register
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("write 0x4820 err");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
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

	AWLOGD("enter temp = %d erase_cnt = %d", temp, erase_cnt);

	//1.close write protect
	AWLOGD("1.open host write FMC protect");
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	if (update_info->update_flag == BOOT_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			AWLOGD("write 0x4794 err");
			return ret;
		}
	}

	for (i = 0; i < erase_cnt; i++)	{
		//2.0x3800~0x3FFF Erase one sector at a time
		ret = aw9320x_i2c_write(REG_ISPADR,
				update_info->check_info->flash_check_start_addr + i * SOCTOR_SIZE);
		if (ret != AW_OK) {
			AWLOGE("write 0x4794 err");
			return ret;
		}

		ret = aw9320x_i2c_write(REG_ISPCMD, REG_ACCESS_MAIN_ARR);
		if (ret != AW_OK) {
			AWLOGE("write 0x4710 err");
			return ret;
		}

		ret = aw9320x_i2c_write(REG_T_RCV, REG_SET_T_RCV);
		if (ret != AW_OK) {
			AWLOGE("write 0x472c err");
			return ret;
		}

		ret = aw9320x_i2c_write(REG_ISPGO, REG_SET_ISP_GO);
		if (ret != AW_OK) {
			AWLOGE("write 0x4714 err");
			return ret;
		}

		ret = aw9320x_check_isp_go_reg();
		if (ret != AW_OK) {
			AWLOGE("check_isp_go_reg err");
			return ret;
		}
	}
	ret = aw9320x_i2c_write(REG_T_RCV, REG_SET_T_RCV_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0x472c err");
		return ret;
	}

	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("write 0x4820 err");
		return ret;
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	return AW_OK;
}

int32_t aw9320x_flash_update(struct aw_update_common *update_info)
{
	int32_t ret = 0;
	uint32_t check_sum = 0;

	AWLOGD("enter read_len = %d", update_info->update_data_len);

	//1.open register access enable
	AWLOGE("1.opne register access enable");
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_REG_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}
	ret = aw9320x_i2c_write(REG_MCFG, REG_OPEN_MCFG_EN);
	if (ret != AW_OK) {
		AWLOGE("0x4444 write 0x10000 err");
		return ret;
	}
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_SET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("0x4820 write 0x6 err");
		return ret;
	}
	if (update_info->update_flag == FRIMWARE_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_SET_BTROM_EW_EN);
		if (ret != AW_OK) {
			AWLOGE("write 0x4794 err");
			return ret;
		}
	}
	//2.Erase sector (0x3800~0x37ff)
	AWLOGD("2.Erase sector (0x3800~0x37ff)");
	ret = aw9320x_erase_sector(update_info);
	if (ret != AW_OK) {
		AWLOGE("erase_sector_main err");
		return ret;
	}

	//3.write checksum en
	AWLOGD("3.write checksum en");
	ret = aw9320x_reg_write_val_to_flash(update_info->check_info->w_check_en_addr,
					AW_CHECK_EN_VAL, update_info);
	if (ret != AW_OK) {
		AWLOGE("write checksum en err");
		return -AW_ERR;
	} else {
		AWLOGD("write checksum en ok");
	}

	//4.write boot
	AWLOGD("4.write boot");
	ret = aw9320x_reg_write_bin_to_flash(update_info);
	if (ret != AW_OK) {
		AWLOGE("erase_sector_main err");
		return ret;
	}

	//5.read data check
	AWLOGD("5.read data check");
	ret = aw9320x_rd_or_wi_cmp(update_info,
				   update_info->w_bin_offset,
				   update_info->update_data_len);
	if (ret != AW_OK) {
		AWLOGE("reg_read_bin err");
		return -AW_ERR;
	}

	//6.write checksum data
	AWLOGD("6.write checksum data");
	check_sum = aw9320x_get_bin_checksum(update_info->w_bin_offset,
						update_info->update_data_len,
						update_info->check_info->check_len);
	AWLOGD("check_sum = 0x%x", check_sum);
	ret = aw9320x_reg_write_val_to_flash(update_info->check_info->w_check_code_addr,
					check_sum, update_info);
	if (ret != AW_OK) {
		AWLOGE("5.write checksum err");
		return -AW_ERR;
	} else
		AWLOGD("5.write checksum ok");

	//7.open flash protect
	AWLOGD("7.open flash protect");
	if (update_info->update_flag == FRIMWARE_UPDATE) {
		ret = aw9320x_i2c_write(REG_ARRAY2_EW_EN, REG_ENSET_BTROM_EW_EN);
		if (ret != AW_OK) {
			AWLOGE("6.open flash protect err");
			return ret;
		}
	}

	AWLOGD("%s update success!!!", ((update_info->update_flag == BOOT_UPDATE) ? "bt":"fw"));

	return AW_OK;
}

int32_t aw9320x_update_bt_to_flash(void)
{
	uint32_t arr_len = sizeof(bt_para_data) / sizeof(bt_para_data[0]);
	int32_t ret = 0;

	struct check_info bt_check_info = {
		.check_len = AW_BT_CHECK_LEN,
		.flash_check_start_addr = AW_BT_CHECK_START_ADDR,
		.w_check_en_addr = AW_BT_CHECK_EN_ADDR,
		.w_check_code_addr = AW_BT_CHECK_CODE_ADDR,
	};

	ret = aw9320x_check_sum(bt_para_data, arr_len);
	if (ret != AW_OK) {
		AWLOGD("check_um err!");
		return -AW_ERR;
	}

	struct aw_update_common bt_update = {
		.update_flag = BOOT_UPDATE,
		.w_bin_offset = &bt_para_data[72],
		.update_data_len = AW_GET_32_DATA(bt_para_data[71], bt_para_data[70], bt_para_data[69], bt_para_data[68]),
		.flash_tr_start_addr = AW_BT_TR_START_ADDR,
		.check_info = &bt_check_info,
	};

	AWLOGD("update_data_len = %d", bt_update.update_data_len);

	return aw9320x_flash_update(&bt_update);
}

int32_t aw9320x_update_fw_to_flash(void)
{
	uint32_t arr_len = sizeof(fw_para_data) / sizeof(fw_para_data[0]);
	int32_t ret = 0;

	ret = aw9320x_check_sum(fw_para_data, arr_len);
	if (ret != AW_OK) {
		AWLOGD("check_um err!");
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
	AWLOGD("update_data_len = %d", fw_update.update_data_len);

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
	//AWLOGD("length = %d", length);

	if (length != 0 && data != NULL)
		memcpy(prot_pack_w + AW_PACK_FIXED_SIZE + SEND_ADDR_LEN, data, length);
	/*
	AWLOGD("aw9320x addr: 0x%02x 0x%02x", prot_pack_w[0], prot_pack_w[1]);
	for (i = 2; i < AW_PACK_FIXED_SIZE + length + AW_ADDR_SIZE; i += 4) {
		AWLOGD("aw9320x prot_pack_w i = %d, 0x%02x 0x%02x 0x%02x 0x%02x",
			i, prot_pack_w[i + 0], prot_pack_w[i + 1],
			prot_pack_w[i + 2], prot_pack_w[i + 3]);
	}
	*/
	do {
		ret = i2c_write_seq(prot_pack_w, AW_PACK_FIXED_SIZE + AW_ADDR_SIZE + length);
		if (ret < 0)
			AWLOGE("aw9320x i2c write cmd err cnt = %d ret = %d", cnt, ret);
		else
			break;
		//usleep_range(2000, 3000);
	} while (cnt--);

	free(prot_pack_w);

	if (cnt < 0) {
		AWLOGD("i2c write cmd err!!! ret = %d", ret);
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t
soc_to_dri_pack_recv(struct aw_soc_protocol *prot_pack, uint32_t pack_len, uint8_t *addr)
{
	int8_t cnt = AW_RETRIES;
	int32_t ret = -1;

	//AWLOGD("enter");

	if (prot_pack == NULL || pack_len == 0)
		return -1;

	do {
		ret = i2c_read_seq(addr, 2, (uint8_t *)prot_pack, pack_len);
		if (ret < 0)
			AWLOGE("aw9320x i2c read cmd err cnt = %d ret = %d", cnt, ret);
		else
			break;
		//usleep_range(2000, 3000);
	} while (cnt--);

	if (cnt < 0) {
		AWLOGE("aw9320x i2c read cmd err!!! ret = %d", ret);
		return -AW_ERR;
	}

	return AW_OK;
}

/**
  * @brief flash init
  * @param parse pack value
  * @retval err code
  */
static int32_t soc_to_dri_pack_parse(uint32_t length, uint8_t module, uint8_t command)
{
	int32_t ret = -1;
	uint32_t pack_len = AW_PACK_FIXED_SIZE + length;
	uint8_t ack_addr[2] = { 0 };
	uint32_t cmd_status = 0;

	struct aw_soc_protocol *prot_pack_r = (struct aw_soc_protocol *)malloc(pack_len);
	if (prot_pack_r == NULL) {
		AWLOGE("kzalloc_ err!");
		return -1;
	}

	//AWLOGD("enter");

	ack_addr[0] = (uint8_t)(AW_ACK_ADDR >> OFFSET_BIT_8);
	ack_addr[1] = (uint8_t)AW_ACK_ADDR;

	ret = soc_to_dri_pack_recv(prot_pack_r, pack_len, ack_addr);
	if (ret != AW_OK) {
		AWLOGE("pack parse err");
		goto err_pack_parse;
	}

	prot_pack_r->header = AW_REVERSEBYTERS_U16(prot_pack_r->header);
	prot_pack_r->size = AW_REVERSEBYTERS_U16(prot_pack_r->size);
	prot_pack_r->length = AW_REVERSEBYTERS_U16(prot_pack_r->length);
	prot_pack_r->checksum = AW_REVERSEBYTERS_U32(prot_pack_r->checksum);

	cmd_status = AW_GET_32_DATA(prot_pack_r->value[3], prot_pack_r->value[2],
				    prot_pack_r->value[1], prot_pack_r->value[0]);

//	AWLOGD("header= 0x%x, size= 0x%x, length= 0x%x, checksum= 0x%x,",
//			prot_pack_r->header, prot_pack_r->size,
//			prot_pack_r->length, prot_pack_r->checksum);
//	AWLOGD("module= 0x%x, command= 0x%x, length=0x%x, cmd_status = %d",
//			prot_pack_r->module, prot_pack_r->command,
//			prot_pack_r->length, cmd_status);

	if ((module == prot_pack_r->module) && (command == prot_pack_r->command) && (cmd_status == 0)) {
//		AWLOGD("soc_to_dri_pack_parse ok");
	} else {
		AWLOGE("soc_to_dri_pack_parse err!!!");
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

	AWLOGD("enter");

	ret = aw9320x_i2c_read(REG_FIRMWARE, &firmware_version);
	if (ret < 0) {
		AWLOGD("read firmware version err");
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
			AWLOGD("read REG_HOSTIRQSRC err");
			return -AW_ERR;
		}
		if (((irq_stat >> 29) & 0x01) == 1) {
			//AWLOGD("irq_stat bit29 = 1  cmd send success!");
			break;
		}
		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGD("irq_stat != 0 cmd send err!");
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
//		AWLOGD("REG_HOSTIRQSRC :0x%x", irq_stat);
		if (ret != AW_OK) {
			AWLOGD("read REG_HOSTIRQSRC err");
			return -AW_ERR;
		}

		if ((irq_stat & 0x01) == INIT_OVER_IRQ_OK) {
//			AWLOGD("stop_flag irq_stat = 1 cmd send success!");
			break;
		} else {
			AWLOGE("REG_HOSTIRQSRC val: 0x%x cnt: %d", irq_stat, cnt);
		}

		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGD("irq_stat != 0 cmd send err!");
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
		AWLOGE("UPDATE_START_CMD err");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(AW_BT_PROT_CMD_PACK_ADDR, AW_SRAM_FIRST_DETECT);
	if (ret != AW_OK) {
		AWLOGE("REG_CMD_SEND_TIRG err");
		return -AW_ERR;
	}

	//2.send trig
	ret = aw9320x_i2c_write(REG_CMD, REG_H2C_TRIG_PARSE_CMD);
	if (ret != AW_OK) {
		AWLOGE("REG_CMD_SEND_TIRG err");
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

	//AWLOGD("delay_ms_cnt = %d", delay_ms_cnt);

	AW_DELAY(delay_ms_cnt);

	//3.Read interrupt information, wait 100ms
	ret = aw9320x_read_ack_irq();
	if (ret != AW_OK) {
		AWLOGE("read_ack_irq err");
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

	AWLOGD("enter");

	aw9320x_i2c_write(AW_REG_MCFG, AW_CPU_HALT);
	aw9320x_i2c_write(AW_REG_ACESS_EN, AW_ACC_PERI);
	aw9320x_i2c_write_bits(REG_UPDATA_DIS, AW_REG_UPDATA_DIS_MASK, 0);
	aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
	aw9320x_i2c_write(AW_REG_MCFG, AW_CPU_RUN);

	AW_DELAY(SEND_STOP_CMD_DELAY_MS);

	//Read interrupt information, wait 10ms
	ret = aw9320x_read_init_comp_irq();
	if (ret != AW_OK) {
		AWLOGE("stop read_ack_irq err");
		return -AW_ERR;
	}

	return AW_OK;
}

static int32_t aw9320x_reg_read_all_val(
					uint32_t *read_data,
					uint32_t read_len,
					uint8_t flash_addr_flag,
					uint16_t start_addr)
{
	int32_t ret = 0;

	AWLOGD("enter");

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}
	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG reg err");
		return -AW_ERR;
	}

	ret = aw9320x_reg_read_val(read_data, start_addr);
	if (ret != AW_OK) {
			AWLOGD("reg_read_bin err");
			return -AW_ERR;
	}
	AWLOGD("addr = 0x%04x read data = 0x%08x", start_addr, *read_data);

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
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
	uint32_t j = 0;
	uint32_t start_addr = 0;
	uint32_t word_comp_len = 0;
	uint32_t cycle_cnt = 0;
	uint32_t cycle_cnt_last_len = 0;
	uint32_t send_all_len = 0;
	uint8_t *firmware_info = NULL;
	uint16_t half_cache_len = AW_CACHE_LEN / 16; //max.4058

	AWLOGD("enter half_cache_len = %d", half_cache_len);

	if (firmware_len % WORD_LEN != 0) {
		word_comp_len = WORD_LEN - firmware_len % WORD_LEN;
		AWLOGE("word_comp_len = %d", word_comp_len);
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
			AWLOGE("devm_kzalloc err");
			return -AW_ERR;
		}

		//Insufficient word makes up for 0xff
		memset(firmware_info, 1, half_cache_len + value_head_len);

		firmware_info[0] = (uint8_t)(seq >> OFFSET_BIT_24);
		firmware_info[1] = (uint8_t)(seq >> OFFSET_BIT_16);
		firmware_info[2] = (uint8_t)(seq >> OFFSET_BIT_8);
		firmware_info[3] = (uint8_t)(seq);

		firmware_info[4] = (uint8_t)(flash_addr >> OFFSET_BIT_24);
		firmware_info[5] = (uint8_t)(flash_addr >> OFFSET_BIT_16);
		firmware_info[6] = (uint8_t)(flash_addr >> OFFSET_BIT_8);
		firmware_info[7] = (uint8_t)(flash_addr);

		for (j = 0; j < value_head_len; j += 4) {
			AWLOGD("cnt = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x",
				i, firmware_info[j + 0], firmware_info[j + 1],
				firmware_info[j + 2], firmware_info[j + 3]);
		}

		AWLOGD("half_cache_len = %d", half_cache_len);
		memcpy(firmware_info + value_head_len,
				&(fw_data[start_addr + (uint64_t)half_cache_len * i]), half_cache_len);

		if (flash_addr + half_cache_len >= AW_NVR_ADDR) {
			AWLOGE("flash addr write err, addr=0x%08X, len=0x%04X",
					flash_addr, half_cache_len);
			goto err_hand;
		}

		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
					firmware_info, half_cache_len + value_head_len);
		if (ret != AW_OK) {
			AWLOGE("send_transfer_cmd_once err");
			goto err_hand;
		}

		flash_addr += half_cache_len;
		seq++;

		if (firmware_info != NULL) {
			free(firmware_info);
			firmware_info = NULL;
		}
	}

	if (cycle_cnt_last_len != 0) {
		firmware_info = (uint8_t *)malloc(cycle_cnt_last_len + value_head_len);
		if (firmware_info == NULL) {
			AWLOGE("devm_kzalloc err");
			goto err_hand;
		}
		//Insufficient word makes up for 0xff
		memset(firmware_info, 1, cycle_cnt_last_len + value_head_len);

		firmware_info[0] = (uint8_t)(seq >> OFFSET_BIT_24);
		firmware_info[1] = (uint8_t)(seq >> OFFSET_BIT_16);
		firmware_info[2] = (uint8_t)(seq >> OFFSET_BIT_8);
		firmware_info[3] = (uint8_t)(seq);
		firmware_info[4] = (uint8_t)(flash_addr >> OFFSET_BIT_24);
		firmware_info[5] = (uint8_t)(flash_addr >> OFFSET_BIT_16);
		firmware_info[6] = (uint8_t)(flash_addr >> OFFSET_BIT_8);
		firmware_info[7] = (uint8_t)(flash_addr);

		for (i = 0; i < value_head_len; i += 4) {
			AWLOGD("last_len = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x",
				cycle_cnt_last_len, firmware_info[i + 0], firmware_info[i + 1],
				firmware_info[i + 2], firmware_info[i + 3]);
		}

		memcpy(firmware_info + value_head_len,
				&(fw_data[start_addr + cycle_cnt * (uint64_t)half_cache_len]),
				cycle_cnt_last_len);

		if (flash_addr + cycle_cnt_last_len >= AW_NVR_ADDR) {
			AWLOGE("flash addr write err, addr=0x%08X, len=0x%04X",
					flash_addr, cycle_cnt_last_len);
			goto err_hand;
		}

		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
					firmware_info, cycle_cnt_last_len + value_head_len);
		if (ret != AW_OK) {
			AWLOGD("send_transfer_cmd_once err");
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

	AWLOGD("enter");

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

	for (i = 0; i < 4; i++) {
		AWLOGD("0x%x 0x%x 0x%x 0x%x",
			transfer_value_w[i * 4 + 0], transfer_value_w[i * 4 + 1],
			transfer_value_w[i * 4 + 2], transfer_value_w[i * 4 + 3]);
	}

	ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_TRANSFER_CMD,
						transfer_value_w, AW_EN_TR_CHECK_VALUE_LEN);
	if (ret != AW_OK) {
		AWLOGD("aw9320x_write_firmware_checksum err");
		return -AW_ERR;
	}
	ret = aw9320x_reg_read_all_val(&r_check_en, WORD_LEN,
		FLASH_ADDR_BOOT, AW_FW_CHECK_EN_ADDR);
	if (ret != AW_OK) {
		AWLOGD("aw9320x_read check_en err");
		return -AW_ERR;
	}
	ret = aw9320x_reg_read_all_val(&r_checksum, WORD_LEN,
		FLASH_ADDR_BOOT, AW_FW_CHECK_CODE_ADDR);
	if (ret != AW_OK) {
		AWLOGD("aw9320x_read check_en err");
		return -AW_ERR;
	}
	w_checksum = AW_GET_32_DATA(p_checksum[0], p_checksum[1], p_checksum[2], p_checksum[3]);
	AWLOGD("r_check_en :0x%08x, r_checksum 0x%08x", r_check_en, r_checksum);
	if ((r_check_en == AW_CHECK_EN_VAL) && (r_checksum == w_checksum)) {
		AWLOGD("Consistent reading and writing");
		return AW_OK;
	} else {
		AWLOGE("err ! r_check_en != AW_CHECK_EN_VAL || r_checksum != w_checksum");
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
		AWLOGE("read AW_BT_VER_INF_VERSION err");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_read(AW_BT_VER_INF_DATE, &bt_date);
	if (ret != AW_OK) {
		AWLOGE("read AW_BT_VER_INF_DATE err");
		return -AW_ERR;
	}

	ret = aw9320x_reg_read_all_val(&bt_checksum, WORD_LEN,
				FLASH_ADDR_BOOT, AW_BT_CHECK_SUM_ADDR);
	if (ret != AW_OK) {
		AWLOGE("read bt_checksum err");
		return -AW_ERR;
	}
	AWLOGD("boot version:0x%08x, date:0x%08x, checksum 0x%08x",
			bt_version, bt_date, bt_checksum);

	fw_checksum = aw9320x_get_bin_checksum(fw_data, fw_len, AW_FW_CHECK_LEN);
	p_fw_check_sum[0] = (uint8_t)(fw_checksum >> 24);
	p_fw_check_sum[1] = (uint8_t)(fw_checksum >> 16);
	p_fw_check_sum[2] = (uint8_t)(fw_checksum >> 8);
	p_fw_check_sum[3] = (uint8_t)(fw_checksum >> 0);

	AWLOGD("firmwarw checksum 0x%08x", fw_checksum);

	return AW_OK;
}

//erase 63 sector ()
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
			AWLOGD("send_UPDATE_START_CMD_cmd err i = %d", i);
			break;
		}
		//AWLOGD("cnt : %d, addr = 0x%x", i, erase_addr);
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
		AWLOGE("send_UPDATE_START_CMD_cmd");
		return -AW_ERR;
	}
	AWLOGD("cnt : %d, addr = 0x%x", 64, erase_addr);

	return AW_OK;
}

static int32_t aw9320x_send_online_cmd(void)
{
	int32_t ret = 0;
	int32_t cnt = 200;
	uint32_t irq_stat = 0;

	ret = aw9320x_i2c_write(AW_BT_HOST2CPU_TRIG, AW_BT_HOST2CPU_TRIG_ONLINE_UPGRADE_CMD);
	if (ret != AW_OK) {
		AWLOGE("write AW_BT_HOST2CPU_TRIG failed");
		return -AW_ERR;
	}

	AW_DELAY(1);

	do {
		ret = aw9320x_i2c_read(REG_IRQSRC, &irq_stat);
		if (ret != AW_OK) {
			AWLOGE("read REG_IRQSRC fail");
			return -AW_ERR;
		}
		if (((irq_stat >> 29) & 0x01) == 1)
			break;
		AW_DELAY(1);
	} while (cnt--);

	if (cnt == -1) {
		AWLOGE("read irqsrc failed!, REG_IRQSRC val: 0x%x", irq_stat);
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

	AWLOGD("enter");

	do {
		//1.Send online upgrade command
		AWLOGD("1.Send online upgrade command");
		ret = aw9320x_send_online_cmd();
		if (ret != AW_OK) {
			AWLOGD("1.Send online upgrade command err");
			update_flag = AW_FALSE;
			break;
		}

		ret = aw9320x_get_fw_and_bt_info(fw_data, fw_len, fw_check_sum);
		if (ret != AW_OK) {
			AWLOGD("aw9320x_get_fw_and_bt_infor");
			update_flag = AW_FALSE;
			break;
		}

		//2.send start cmd
		AWLOGD("2.send start cmd");
		prot_update_fw_flag = SEND_START_CMD;
		ret = aw9320x_send_once_cmd(UPDATE_MODULE, UPDATE_START_CMD,
				P_AW_START_CMD_SEND_VALUE, AW_START_CMD_SEND_VALUE_LEN);
		if (ret != AW_OK) {
			AWLOGD("send_UPDATE_START_CMD_cmd err");
			update_flag = AW_FALSE;
			break;
		}

		//3.a en fw check erase_last_sector"
		AWLOGD("3.a en fw check erase_last_sector");
		ret = aw9320x_flash_erase_last_sector();
		if (ret != AW_OK) {
			AWLOGD("aw9320x_flash_erase_sector err");
			update_flag = AW_FALSE;
			break;
		}
		//3.b en fw check
		AWLOGD("3.b en fw check");
		prot_update_fw_flag = SEND_UPDATE_CHECK_CODE_CMD;
		ret = aw9320x_write_firmware_checksum(fw_check_sum);
		if (ret != AW_OK) {
			AWLOGD("aw9320x_write_firmware_checksum err");
				update_flag = AW_FALSE;
				break;
		}

		//4.send Erase Chip Cmd
		AWLOGD("4.send Erase Chip Cmd");
		ret = aw9320x_flash_erase_sector();
		if (ret != AW_OK) {
			AWLOGD("aw9320x_flash_erase_sector err");
			update_flag = AW_FALSE;
			break;
		}
		//5.Cycle write firmware
		AWLOGD("5 Cycle write firmware");
		prot_update_fw_flag = SEND_UPDATE_FW_CMD;
		ret = aw9320x_cycle_write_firmware(fw_data, fw_len, AW_FLASH_HEAD_ADDR);
		if (ret != AW_OK) {
			AWLOGD("cycle_write_firmware err");
			update_flag = AW_FALSE;
			break;
		}

		//6.send stop
		AWLOGD("6.send stop");
		prot_update_fw_flag = SEND_STOP_CMD;
		ret = aw9320x_send_stop_cmd();
		if (ret != AW_OK) {
			AWLOGD("stop err");
			update_flag = AW_FALSE;
			break;
		} else {
			AWLOGD("aw9320x_send_all_update_cmd ok, update firmware ok!");
		}
	} while (0);

	if (update_flag == AW_FALSE) {
		AWLOGD("Write through protocol failed, start write through register");

		ret = aw9320x_recover_fun(INIT_RECOVER);
		if (ret != AW_OK) {
			AWLOGE("recover_fun err");
			return -AW_ERR;
		}

		ret = aw9320x_soft_reset();
		if (ret != AW_OK) {
			AWLOGE("soft_reset err");
			return -AW_ERR;
		}

		ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_OPEN);
		if (ret != AW_OK) {
			AWLOGE("REG_APB_ACCESS_EN err");
			return -AW_ERR;
		}

		ret = aw9320x_i2c_read(REG_BOOT_LOADER_ACTIVE, &reg_boot_loader_active_val);
		if (ret != AW_OK) {
			AWLOGE("read REG_BOOT_LOADER_ACTIVE err");
			return -AW_ERR;
		}
		if (reg_boot_loader_active_val != 0) {
			ret = aw9320x_i2c_write(REG_BOOT_LOADER_ACTIVE, 0);
				if (ret != AW_OK) {
				AWLOGE("write REG_BOOT_LOADER_ACTIVE err");
				return -AW_ERR;
			}
		}

		ret = aw9320x_i2c_read(REG_UPDATA_DIS, &data_tmp);
		if (ret != AW_OK) {
			AWLOGE("0x4744 read err");
			return -AW_ERR;
		}
		if (((data_tmp >> 24) & 0xff) != 0) {
			ret = aw9320x_i2c_write(REG_UPDATA_DIS, data_tmp & AW_REG_UPDATA_DIS_MASK);
			if (ret != AW_OK) {
				AWLOGE("0x4744 wr err");
				return -AW_ERR;
			}
		}

		ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
		if (ret != AW_OK) {
			AWLOGE("REG_APB_ACCESS_EN wr err");
			return -AW_ERR;
		}
		if (load_fw_mode == AW_DIRECT_LOAD) {
			AWLOGD("direct updata");
			return -AW_ERR;
		}

		return -AW_PROT_UPDATE_ERR;
	}

	AWLOGE("prot update fw ok!!!");

	return AW_OK;
}

static int32_t aw9320x_check_chipid(void)
{
	int32_t ret;
	uint32_t chipid;

	AWLOGD("enter");

	ret = aw9320x_reg_read_all_val(&chipid, WORD_LEN,
			FLASH_ADDR_BOOT, REG_NVR_CHIPID_ADDR);
	if (ret != AW_OK) {
		AWLOGE("read chipid err");
		return -AW_ERR;
	}

	switch (chipid) {
	case AW93203CSR_CHIP_ID:
		AWLOGD("AW93203CSR NVR CHIP ID : 0x%08X", chipid);
		break;
	case AW93205DNR_CHIP_ID:
		AWLOGD("AW93205DNR NVR CHIP ID : 0x%08X", chipid);
		break;
	case AW93208CSR_CHIP_ID:
		AWLOGD("AW93208CSR NVR CHIP ID : 0x%08X", chipid);
		break;
	case AW93208_CHIP_ID:
		AWLOGD("AW93208 CHIP ID : 0x%08x", chipid);
		break;
	default:
		AWLOGD("NVR no chipid, CHIP ID : 0x%08x", chipid);
		return -AW_ERR_CHIPID;
	}

	return AW_OK;
}

//Default: update when version numbers are different
int32_t aw9320x_fw_update(uint8_t load_fw_mode)
{
	int8_t cmp_val = 0;
	int32_t ret = 0;
	uint32_t arr_len = sizeof(fw_para_data) / sizeof(fw_para_data[0]);

	ret = aw9320x_check_sum(fw_para_data, arr_len);
	if (ret != AW_OK) {
		AWLOGD("check_um err!");
		return -AW_ERR;
	}

	struct aw_fw_load_info fw_load_info = {
		.fw_len = AW_GET_32_DATA(fw_para_data[71], fw_para_data[70], fw_para_data[69], fw_para_data[68]),
		.p_fw_data = &fw_para_data[72],
		.app_version = AW_GET_32_DATA(fw_para_data[63], fw_para_data[62], fw_para_data[61], fw_para_data[60]),
		.load_fw_mode = load_fw_mode,
	};

	AWLOGE("fw_len = %d,app_version = 0x%x", fw_load_info.fw_len, fw_load_info.app_version);
	//direct updata_fw
	if (fw_load_info.load_fw_mode == AW_COMPARE_VERSION_LOAD) {
		aw9320x_fw_version_cmp(&cmp_val, fw_load_info.app_version);
		if (cmp_val == AW9320X_VER_EQUAL) {
	 		AWLOGD("the version number of soc and app are equal, no update!");
	 		return AW_OK;
		}
	}

	return aw9320x_send_all_update_cmd(fw_load_info.p_fw_data, fw_load_info.fw_len, load_fw_mode);
}

int32_t aw9320x_checksum_en_judg(void)
{
	int32_t ret = 0;
	uint32_t r_data = 0;

	AWLOGD("enter");

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}
	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG reg err");
		return -AW_ERR;
	}

	aw9320x_reg_read_val(&r_data, AW_FW_CHECK_EN_ADDR);
	AWLOGD("read flash AW_FW_CHECK_EN_ADDR 0x3FF8 = 0x%x", r_data);

	if(r_data == AW_CHECK_EN_VAL) {
		AWLOGD("w9320x_checksum_en ok!");
		return AW_OK;
	} else {
		AWLOGD("w9320x_checksum_en failed!");
		return -AW_ERR;
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_DEFAULT_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}
}

static int32_t aw9320x_rd_dump_flash(struct aw_update_common *update_info,
				const uint8_t *w_bin_offset, uint32_t update_data_len)
{
	int32_t ret = 0;
	uint32_t i = 0;
	uint32_t r_data = 0;
	uint32_t w_data = 0;
	uint32_t read_cnt = update_info->update_data_len;

	AWLOGD("enter");

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}
	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG reg err");
		return -AW_ERR;
	}

	AWLOGE("read_cnt = %d", read_cnt);
	for (i = 0; i < read_cnt; i += WORD_LEN) {
		ret = aw9320x_reg_read_val(&r_data,
					update_info->flash_tr_start_addr + i);
		if (ret != AW_OK) {
			AWLOGE("reg_read_bin err");
			return -AW_ERR;
		}
		w_data = AW_GET_32_DATA(w_bin_offset[i + 0],
					w_bin_offset[i + 1],
					w_bin_offset[i + 2],
					w_bin_offset[i + 3]);
		AWLOGD("i=%d, addr=0x%08x, BIN_DATA=0x%08x, R_DATA=0x%08x",
			i, update_info->flash_tr_start_addr + i, w_data, r_data);
		if (w_data != r_data) {
			AWLOGE("w_data != r_data err!");
		}
	}

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}
	AWLOGD("END");
	return AW_OK;
}

int32_t aw9320x_dump_fw_flash(void)
{
	uint32_t arr_len = sizeof(fw_para_data)/sizeof(unsigned char);
	int32_t ret = 0;
	uint32_t r_data = 0;
	uint32_t check_sum = 0;
	struct aw_update_common *update_info;

	AWLOGD("enter");

	//1.config FMC reg
	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_OPEN_APB_ACCESS_EN);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return -AW_ERR;
	}
	//2.config PMU_CFG reg
	ret = aw9320x_i2c_write(REG_PMU_CFG, REG_ENSET_PMU_CFG);
	if (ret != AW_OK) {
		AWLOGE("config PMU_CFG reg err");
		return -AW_ERR;
	}

	aw9320x_reg_read_val(&r_data, 0x3FFC);
	AWLOGD("read flash 0x3FFC = 0x%x", r_data);

	aw9320x_reg_read_val(&r_data, 0x31b0);
	AWLOGD("read flash 0x31B0 = 0x%x", r_data);

	aw9320x_reg_read_val(&r_data, 0x3ff8);
	AWLOGD("read flash 0x3FF8 = 0x%x", r_data);

	ret = aw9320x_i2c_write(REG_ACCESSEN, REG_ACCESSEN_CLOSE);
	if (ret != AW_OK) {
		AWLOGE("write 0xff20 err");
		return ret;
	}

	ret = aw9320x_check_sum(fw_para_data, arr_len);
	if (ret != AW_OK) {
		AWLOGD("check_um err!");
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
	AWLOGD("update_data_len = %d", fw_update.update_data_len);
	update_info = &fw_update;

	check_sum = aw9320x_get_bin_checksum(update_info->w_bin_offset,
				update_info->update_data_len,
				update_info->check_info->check_len);
	AWLOGD("aw9320x_get_bin_checksum check_sum = 0x%x", check_sum);

	ret = aw9320x_rd_dump_flash(update_info,
					update_info->w_bin_offset,
					update_info->update_data_len);
	if (ret != AW_OK) {
		AWLOGE("reg_read_bin err");
		return -AW_ERR;
	}
	return AW_OK;
}

int32_t aw9320x_dump_bt_flash(void)
{
	struct aw_update_common *update_info;
	uint32_t arr_len = sizeof(bt_para_data) / sizeof(bt_para_data[0]);
	int32_t ret = 0;

	struct check_info bt_check_info = {
		.check_len = AW_BT_CHECK_LEN,
		.flash_check_start_addr = AW_BT_CHECK_START_ADDR,
		.w_check_en_addr = AW_BT_CHECK_EN_ADDR,
		.w_check_code_addr = AW_BT_CHECK_CODE_ADDR,
	};

	AWLOGD("enter");
	ret = aw9320x_check_sum(bt_para_data, arr_len);
	if (ret != AW_OK) {
		AWLOGD("check_um err!");
		return -AW_ERR;
	}

	struct aw_update_common bt_update = {
		.update_flag = BOOT_UPDATE,
		.w_bin_offset = &bt_para_data[72],
		.update_data_len = AW_GET_32_DATA(bt_para_data[71], bt_para_data[70], bt_para_data[69], bt_para_data[68]),
		.flash_tr_start_addr = AW_BT_TR_START_ADDR,
		.check_info = &bt_check_info,
	};

	AWLOGD("update_data_len = %d", bt_update.update_data_len);
	update_info = &bt_update;

	uint32_t check_sum = aw9320x_get_bin_checksum(update_info->w_bin_offset,
						update_info->update_data_len,
						update_info->check_info->check_len);
	AWLOGD("aw9320x_get_bin_checksum check_sum = 0x%x", check_sum);

	ret = aw9320x_rd_dump_flash(update_info,
					update_info->w_bin_offset,
					update_info->update_data_len);
	if (ret != AW_OK) {
		AWLOGE("reg_read_bin err");
		return -AW_ERR;
	}
	return AW_OK;
}

int32_t aw9320x_dump_ram_data(void)
{
	uint32_t reg_val = 0;

	AWLOGD("enter");
	for(int i = 0; i < 0x1BA0; i += 4){
		aw9320x_i2c_read(i, &reg_val);
		AWLOGD("ram addr %04x, R_DATA=0x%08x", i, reg_val);
	}
	return  AW_OK;
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

#ifdef AW_PRINTF_FLASH_RAM_DATA
	aw9320x_dump_fw_flash();
	aw9320x_dump_ram_data();
	aw9320x_dump_bt_flash();
#endif

	return AW_OK;
}

/*****************aw_protocol_transfer end**************************/

static int32_t aw9320x_update_err_handle(void)
{
	int32_t ret = -1;

	ret = aw9320x_update_bt_to_flash();
	if (ret == AW_OK) {
		AWLOGE("update boot to flash ok!!!");
	} else {
		AWLOGE("update_boot_to_flash failed :%d", ret);
		return -AW_ERR;
	}

	ret = aw9320x_update_fw_to_flash();
	if (ret != AW_OK) {
		AWLOGE("update_fw_to_flash failed :%d", ret);
		return -AW_ERR;
	}

	ret = aw9320x_recover_fun(REG_UPDATE_RECOVER);
	if (ret != AW_OK) {
		AWLOGE("recover_fun err");
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

static void aw9320x_button_irq_event(struct cap_event_status *p_irq_stat_data)
{
	uint8_t i = 0;
	uint8_t bit_i = 0;
	uint32_t reg_btnstat0_val = 0;
	uint32_t reg_btnstat1_val = 0;

	aw9320x_i2c_read(REG_BTNSTAT0, &reg_btnstat0_val);
	aw9320x_i2c_read(REG_BTNSTAT1, &reg_btnstat1_val);

	for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		if ((reg_btnstat0_val >> (i + OFFSET_BIT_8)) & 0x01) { //long press leave
			p_irq_stat_data->long_press_leave |= (1 << bit_i);
		} else if ((reg_btnstat0_val >> (i + OFFSET_BIT_0)) & 0x01) { //super perss
			p_irq_stat_data->super_long_press |= (1 << bit_i);
		} else if ((reg_btnstat1_val >> (i + OFFSET_BIT_24)) & 0x01) { //long perss
			p_irq_stat_data->long_press |= (1 << bit_i);
		} else if ((reg_btnstat1_val >> (i + OFFSET_BIT_16)) & 0x01) { //triple click
			p_irq_stat_data->triple_click |= (1 << bit_i);
		} else if ((reg_btnstat1_val >> (i + OFFSET_BIT_8)) & 0x01) { //double click
			p_irq_stat_data->double_click |= (1 << bit_i);
		} else if ((reg_btnstat1_val >> (i + OFFSET_BIT_0)) & 0x01) { //single click
			p_irq_stat_data->single_click |= (1 << bit_i);
		}
		bit_i++;
	}

	aw9320x_i2c_write(REG_CMD, REG_CMD_SEND_CLEND_CMD);
}

static void aw930x_slide_mode_event(struct cap_event_status *p_irq_stat_data)
{
	uint32_t slddata1_val = 0;

	aw9320x_i2c_read(REG_SLDDATA1, &slddata1_val);

	AWLOGD("tws REG_SLDDATA1 = 0x%x", slddata1_val);

	if ((slddata1_val >> REG_SLDDATA1_LONG_PRESS_LEAVE_BIT) & 0x01) { //long press leave
		p_irq_stat_data->long_press_leave |= (1 << SLIDE_STORE_BIT);
	} else if ((slddata1_val >> REG_SLDDATA1_SUPER_PRESS_BIT) & 0x01) { //super press
		p_irq_stat_data->super_long_press |= (1 << SLIDE_STORE_BIT);
	} else if ((slddata1_val >> REG_SLDDATA1_LONG_PRESS_BIT) & 0x01) { //long press leave
		p_irq_stat_data->super_long_press |= (1 << SLIDE_STORE_BIT);
	} else if ((slddata1_val >> REG_SLDDATA1_TREBLE_CLICK_BIT) & 0x01) { //treble click
		p_irq_stat_data->triple_click |= (1 << SLIDE_STORE_BIT);
	} else if ((slddata1_val >> REG_SLDDATA1_DOUBLE_CLICK_BIT) & 0x01) { //double click
		p_irq_stat_data->double_click |= (1 << SLIDE_STORE_BIT);
	} else if ((slddata1_val >> REG_SLDDATA1_TSINGED_CLICK_BIT) & 0x01) { //single click
		p_irq_stat_data->single_click |= (1 << SLIDE_STORE_BIT);
	} else { //slide
		if ((slddata1_val >> REG_SLDDATA1_SLIDE_BIT) & 0x01) { //There are sliding events
			if ((((slddata1_val >> REG_SLDDATA1_NORMDIRECTIONST_BIT) & 0x01) == 0) &&
					(((slddata1_val >> REG_SLDDATA1_NORMSPEEDST_BIT) & 0x01)) == 0) { //Positive direction and slow
				p_irq_stat_data->right_wareds = 0x01;
			} else if ((((slddata1_val >> REG_SLDDATA1_NORMDIRECTIONST_BIT) & 0x01) == 0) &&
					(((slddata1_val >> REG_SLDDATA1_NORMSPEEDST_BIT) & 0x01)) == 1) { //Positive direction and fast
				p_irq_stat_data->right_wareds = 0x10;
			} else if ((((slddata1_val >> REG_SLDDATA1_NORMDIRECTIONST_BIT) & 0x01) == 1) &&
					(((slddata1_val >> REG_SLDDATA1_NORMSPEEDST_BIT) & 0x01)) == 0) { //Negative direction and slow
				p_irq_stat_data->left_wareds = 0x01;
			} else if ((((slddata1_val >> REG_SLDDATA1_NORMDIRECTIONST_BIT) & 0x01) == 1) &&
					(((slddata1_val >> REG_SLDDATA1_NORMSPEEDST_BIT) & 0x01)) == 1) { //Negative direction and fast
				p_irq_stat_data->left_wareds = 0x10;
			}

			if (((slddata1_val >> REG_SLDDATA1_MOVEDIRECTION_BIT) & 0x01) == 0)
				p_irq_stat_data->slide_distance = slddata1_val & 0xff;
			else if (((slddata1_val >> REG_SLDDATA1_MOVEDIRECTION_BIT) & 0x01) == 1)
				p_irq_stat_data->slide_distance = -(slddata1_val & 0xff);
		}
	}
	aw9320x_i2c_write(REG_CMD, REG_CMD_SEND_CLEND_CMD);
}

static void aw9320x_prox_and_touch_irq_event(struct cap_event_status *p_irq_stat_data)
{
	int32_t ret = 0;
	uint32_t curr_status_val = 0;

	ret = aw9320x_i2c_read(REG_STAT0, &curr_status_val);
	if (ret < 0) {
		AWLOGE("i2c IO error");
		return;
	}
	AWLOGD("STAT0 = 0x%x", curr_status_val);

	p_irq_stat_data->prox_stat_th_0 = (uint8_t)(curr_status_val & 0xff);
	p_irq_stat_data->prox_stat_th_1 = (uint8_t)((curr_status_val >> 8) & 0xff);

}

//The last value needs to be maintained
static uint8_t wear = 0;
static void aw9320x_get_irq_stat(struct cap_event_status *p_irq_stat_data, uint32_t *irq_status)
{
	int32_t ret = 0;
	uint8_t flag = AW_FALSE;

	ret = aw9320x_i2c_read(REG_IRQSRC, irq_status);
	if (ret < 0) {
		AWLOGE("i2c IO error");
		return ;
	}
	AWLOGD("IRQSRC = 0x%x", *irq_status);

	if ((*irq_status >> REG_IRQSRC_BUTTON_BIT) & 0x01) {//button
		AWLOGD("button");
		aw9320x_button_irq_event(p_irq_stat_data);
		flag = AW_TRUE;
	}
	if ((*irq_status >> REG_IRQSRC_SLIDE_BIT) & 0x01) {//slide
		AWLOGD("slide");
		aw930x_slide_mode_event(p_irq_stat_data);
		flag = AW_TRUE;
	}
	if ((*irq_status >> REG_IRQSRC_wear_BIT) & 0x01) { //in ear
		AWLOGD("in ear");
		//If there is no out of ear time, keep the previous state
		wear = 1;
		flag = AW_TRUE;
	} else if ((*irq_status >> REG_IRQSRC_OUT_EAR_BIT) & 0x01) { //out ear
		AWLOGD("out ear");
		wear = 2;
		flag = AW_TRUE;
	}
	if (((*irq_status >> REG_IRQSRC_PROX_BIT) & 0x01) || ((*irq_status >> REG_IRQSRC_EXIT_PROX_BIT) & 0x01) ||
		((*irq_status >> REG_IRQSRC_TOUCH_BIT) & 0x01 ) || ((*irq_status >> REG_IRQSRC_EXIT_TOUCH_BIT) & 0x01)) {
		AWLOGD("prox");
		aw9320x_prox_and_touch_irq_event(p_irq_stat_data);
		flag = AW_TRUE;
	}
	if ((*irq_status >> REG_IRQSRC_INIT_BIT) & 0x01) {
		AWLOGD("exception handling");
		aw9320x_para_loaded();
		p_irq_stat_data->irq_trigger = AW_TRUE;
		flag = AW_TRUE;
	}
	if (flag != AW_TRUE) {
		//AWLOGD("No valid interrupt trigger");
		p_irq_stat_data->irq_trigger = AW_FALSE;
	}
}

/**
 * @description: callback of irq, don't do any thing here but set signal.
 */
static void aw9320x_irq_cb(void)
{
#ifdef AW_OS_USED
	if (g_is_need_irq == AW_TRUE)
		g_aw9320x_func->irq_thread_func.set_signal(AW9320X_READ_IRQ_STAT);

#else
	uint32_t p_irq_status = 0;
	struct cap_event_status p_irq_stat_data;

	aw9320x_get_irq_stat(&p_irq_stat_data, &p_irq_status);
#endif
}
#if defined(AW_SPP_USED) && defined(AW_OS_USED)
void cap_event_status_reprot(struct cap_event_status *p_irq_stat_data, uint32_t *irq_status)
{
	uint8_t i = 0;
	uint8_t spp_addr = 0;
	uint32_t diff = 0;
	uint8_t irq_event_report_buf[AW_CAP_IRQ_EVENT_REPORT_LEN] = { 0 };

	irq_event_report_buf[0] = p_irq_stat_data->prox_stat_th_0;
	irq_event_report_buf[1] = 0;
	irq_event_report_buf[2] = (uint8_t)(*irq_status & GET_BITS_7_0);
	irq_event_report_buf[3] = (uint8_t)((*irq_status >> OFFSET_BIT_8) & GET_BITS_7_0);
	irq_event_report_buf[4] = (uint8_t)((*irq_status >> OFFSET_BIT_16) & GET_BITS_7_0);
	irq_event_report_buf[5] = (uint8_t)((*irq_status >> OFFSET_BIT_24) & GET_BITS_7_0);

	for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(REG_DIFF_CH0 + (i * AW_REG_STEP), &diff);
		diff = (int32_t)diff >> AW_REMOVE_DECIMAL_BITS;
		AWLOGD("diff:0x%x   %d", diff, diff);
		spp_addr = AW_CAP_IRQ_CURVEL_INDEX + i * 4;
		irq_event_report_buf[spp_addr + 0] = (uint8_t)(diff & GET_BITS_7_0);
		irq_event_report_buf[spp_addr + 1] = (uint8_t)((diff >> OFFSET_BIT_8) & GET_BITS_7_0);
		irq_event_report_buf[spp_addr + 2] = (uint8_t)((diff >> OFFSET_BIT_16) & GET_BITS_7_0);
		irq_event_report_buf[spp_addr + 3] = (uint8_t)((diff >> OFFSET_BIT_24) & GET_BITS_7_0);
	}
	aw9320x_app_data_send(AW_APP_CMD_IRQ_STATE_INPUT, irq_event_report_buf, sizeof(irq_event_report_buf));
}
#endif

#ifdef AW_OS_USED
static void aw9320x_irq_thread_cb(void)
{
	int32_t ret = 0;
	uint32_t irq_status = 0;
	struct cap_event_status irq_stat_data;

	while (1) {
		ret = 0;
		ret = g_aw9320x_func->irq_thread_func.wait_signal_forever();
		memset(&irq_stat_data, 0, sizeof(struct cap_event_status));
		irq_stat_data.irq_trigger = AW_TRUE;

		if (ret == AW9320X_READ_IRQ_STAT)
			aw9320x_get_irq_stat(&irq_stat_data, &irq_status);

	}
}
#endif

#if defined(AW_SPP_USED) && defined(AW_OS_USED)

#ifndef AW_MUL_CAP_FLAG
//This value is expanded by 10000 times. It needs to be converted to float type except 10000.0
void aw9320x_self_cap_parasitic_data_get(uint32_t *reg_data_cfg)
{
	uint32_t i = 0;
	uint32_t reg_data = 0;
	uint32_t reg_data_cfg_val = 0;
	uint32_t reg_data_cfg_tmp0 = 0;
	uint32_t reg_data_cfg_tmp1 = 0;

	for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(REG_AFECFG3_CH0 + AW_CFG_REG_STEP * i, &reg_data);
		if (((reg_data >> AW_AFECFG3_CVMULTUALMOD) & 0x1) != 0)
			continue;

		aw9320x_i2c_read(REG_AFECFG1_CH0 + AW_CFG_REG_STEP * i, &reg_data_cfg_val);

		if (((reg_data >> AW_AFECFG3_CVOFF2X) & 0x1) == 0) {
			reg_data_cfg_tmp0 = (reg_data_cfg_val & 0xff) * AW_FINE_ADJUST_STEP0;
			reg_data_cfg_tmp1 = ((reg_data_cfg_val >> 8) & 0xff) * AW_COARSE_ADJUST_STEP0;
		} else {
			reg_data_cfg_tmp0 = (reg_data_cfg_val & 0xff) * AW_FINE_ADJUST_STEP1;
			reg_data_cfg_tmp1 = ((reg_data_cfg_val >> 8) & 0xff) * AW_COARSE_ADJUST_STEP1;
		}
		reg_data_cfg[i] = (reg_data_cfg_tmp0 + reg_data_cfg_tmp1);
	}
}
#else
static uint32_t aw_pow2(uint32_t cnt)
{
	uint32_t i = 0;
	uint32_t sum = 1;

	for (i = 0; i < cnt; i++)
		sum *= 2;

	return sum;
}

void aw9320x_mul_cap_parasitic_data_get(uint32_t *parasitic_data)
{
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t reg_data = 0;
	uint32_t reg_data_cfg_val = 0;
	uint32_t off_m = 0;
	uint32_t fine_off_f_temp = 0;
	uint32_t off_f = 0;
	uint32_t off_c = 0;
	int32_t s_off_c = 0;

	for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read(REG_AFECFG3_CH0 + AW_CFG_REG_STEP * i, &reg_data);
		if (((reg_data >> AW_AFECFG3_CVMULTUALMOD) & 0x1) != 1)
			continue;

		if (((reg_data >> AW_AFECFG3_CVOFF2X) & 0x1) == 0) {
			aw9320x_i2c_read(REG_AFECFG1_CH0 + AW_CFG_REG_STEP * i, &reg_data_cfg_val);
			off_m = (reg_data_cfg_val >> 16) & 0xff;
			off_f = reg_data_cfg_val & 0xff;
			fine_off_f_temp = off_f * AW_FINE_ADJUST_STEP0;
			off_c = (reg_data_cfg_val >> 8) & 0xff;

			for (j = 0; j < 8; j++)
				s_off_c += (((1 - 2 * ((off_m >> j) & 0x1)) * ((off_c >> j) & 0x1) * aw_pow2(j)) * AW_COARSE_ADJUST_STEP0);
			parasitic_data[i] = AW_ABS((int32_t)fine_off_f_temp + s_off_c);
		}
	}
}
#endif

static void aw9320x_app_send_curve_dat(void)
{
	AW_U32 i = 0;
	AW_S32 diff[AW9320X_CURVER_LEN] = { 0 };
	AW_S32 app_data[AW9320X_CURVER_LEN] = { 0 };
	AW_S32 base[AW9320X_CURVER_LEN] = { 0 };
	AW_S32 comp[AW9320X_CURVER_LEN] = { 0 };
	AW_S32 spp_offset = 0;
	AW_U32 pos, slddata1_val;
	struct cap_event_status irq_stat_data;
	uint32_t irq_status = 0;
	uint32_t cnt = 0;

	AW_U8 *buf = malloc(AW_SAR_SPP_ONE_PACK_LEN * PACKS_IN_ONE_COMM);
	if (buf == NULL) {
		AWLOGE("malloc apply error!");
		return;
	}
	memset(buf, 0, AW_SAR_SPP_ONE_PACK_LEN * PACKS_IN_ONE_COMM);

	AWLOGE("packs size=%d", AW_SAR_SPP_ONE_PACK_LEN * PACKS_IN_ONE_COMM);

	while (AW_TRUE) {
		memset(&irq_stat_data, 0, sizeof(struct cap_event_status));
		for (i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
			aw9320x_i2c_read(REG_RAW_CH0 + (i * AW_REG_STEP), (uint32_t *)&app_data[i]);
			aw9320x_i2c_read(REG_VALID_CH0 + (i * AW_REG_STEP), (uint32_t *)&comp[i]);
			aw9320x_i2c_read(REG_BASELINE_CH0 + (i * AW_REG_STEP), (uint32_t *)&base[i]);
			aw9320x_i2c_read(REG_DIFF_CH0 + (i * AW_REG_STEP), (uint32_t *)&diff[i]);
		}
		aw9320x_i2c_read(REG_SLDDATA2, &pos);
		aw9320x_i2c_read(REG_SLDDATA1, &slddata1_val);

		for (i = 0; i < AW9320X_CURVER_LEN; i++) {
			app_data[i] >>= 10;
			spp_offset = i * 4 + cnt * AW_SAR_SPP_ONE_PACK_LEN;
			buf[spp_offset] = (AW_U8)(app_data[i] & AW_ONE_BYTE_1);
			buf[spp_offset + 1] = (AW_U8)(app_data[i] >> AW_BIT8 & AW_ONE_BYTE_1);
			buf[spp_offset + 2] = (AW_U8)(app_data[i] >> AW_BIT16 & AW_ONE_BYTE_1);
			buf[spp_offset + 3] = (AW_U8)(app_data[i] >> AW_BIT24 & AW_ONE_BYTE_1);
		}

		for (i = 0; i < AW9320X_CURVER_LEN; i++) {
			spp_offset = AW_CURVE_DATA_LEN + i * 4 + cnt * AW_SAR_SPP_ONE_PACK_LEN;
			comp[i] >>= 10;
			buf[spp_offset] = (AW_U8)(comp[i] & AW_ONE_BYTE_1);
			buf[spp_offset + 1] = (AW_U8)(comp[i] >> AW_BIT8 & AW_ONE_BYTE_1);
			buf[spp_offset + 2] = (AW_U8)(comp[i] >> AW_BIT16 & AW_ONE_BYTE_1);
			buf[spp_offset + 3] = (AW_U8)(comp[i] >> AW_BIT24 & AW_ONE_BYTE_1);
		}

		for (i = 0; i < AW9320X_CURVER_LEN; i++) {
			spp_offset = AW_CURVE_DATA_LEN * 2 + i * 4 + cnt * AW_SAR_SPP_ONE_PACK_LEN;
			base[i] >>= 10;
			buf[spp_offset] = (AW_U8)(base[i] & AW_ONE_BYTE_1);
			buf[spp_offset + 1] = (AW_U8)(base[i] >> AW_BIT8 & AW_ONE_BYTE_1);
			buf[spp_offset + 2] = (AW_U8)(base[i] >> AW_BIT16 & AW_ONE_BYTE_1);
			buf[spp_offset + 3] = (AW_U8)(base[i] >> AW_BIT24 & AW_ONE_BYTE_1);
		}

		for (i = 0; i < AW9320X_CURVER_LEN; i++) {
			spp_offset = AW_CURVE_DATA_LEN * 3 + i * 4 + cnt * AW_SAR_SPP_ONE_PACK_LEN;
			diff[i] >>= 10;
			buf[spp_offset] = (AW_U8)(diff[i] & AW_ONE_BYTE_1);
			buf[spp_offset + 1] = (AW_U8)(diff[i] >> AW_BIT8 & AW_ONE_BYTE_1);
			buf[spp_offset + 2] = (AW_U8)(diff[i] >> AW_BIT16 & AW_ONE_BYTE_1);
			buf[spp_offset + 3] = (AW_U8)(diff[i] >> AW_BIT24 & AW_ONE_BYTE_1);
		}

		for (i = 0; i < VIRTUAL_REG_NUM; i++) {
			spp_offset = AW_CURVE_DATA_LEN * 4 + i * 4 + cnt * AW_SAR_SPP_ONE_PACK_LEN;
			//reserve
			buf[spp_offset] = 0x04;
			buf[spp_offset + 1] = 0x03;
			buf[spp_offset + 2] = 0x02;
			buf[spp_offset + 3] = 0x01;
		}

		aw9320x_get_irq_stat(&irq_stat_data, &irq_status);
		spp_offset = AW_CURVE_DATA_LEN * 4 + VIRTUAL_REG_BUF_LEN + cnt * AW_SAR_SPP_ONE_PACK_LEN;
		buf[spp_offset + 0] = (irq_stat_data.single_click != 0) ? 1 : 0;
		buf[spp_offset + 1] = (irq_stat_data.double_click != 0) ? 1 : 0;
		buf[spp_offset + 2] = (irq_stat_data.triple_click != 0) ? 1 : 0;
		buf[spp_offset + 3] = (irq_stat_data.long_press != 0) ? 1 : 0;
		buf[spp_offset + 4] = (irq_stat_data.super_long_press != 0) ? 1 : 0;
		buf[spp_offset + 5] = irq_stat_data.left_wareds;
		buf[spp_offset + 6] = irq_stat_data.right_wareds;
		buf[spp_offset + 7] = (wear == 1) ? 1 : 2;
		buf[spp_offset + 8] = irq_stat_data.up_wareds;
		buf[spp_offset + 9] = irq_stat_data.down_wareds;

		AWLOGD("buf[%d]=single_click:0x%x", spp_offset + 0, irq_stat_data.single_click);
		AWLOGD("buf[%d]=double_click:0x%x", spp_offset + 1, irq_stat_data.double_click);
		AWLOGD("buf[%d]=triple_click:0x%x", spp_offset + 2, irq_stat_data.triple_click);
		AWLOGD("buf[%d]=long_press:0x%x", spp_offset + 3, irq_stat_data.long_press);
		AWLOGD("buf[%d]=super_long_press:0x%x", spp_offset + 4, irq_stat_data.super_long_press);
		AWLOGD("buf[%d]=left_wareds:0x%x", spp_offset + 5, irq_stat_data.left_wareds);
		AWLOGD("buf[%d]=right_wareds:0x%x", spp_offset + 6, irq_stat_data.right_wareds);
		AWLOGD("buf[%d]=wear:0x%x", spp_offset + 7, buf[spp_offset + 7]);
		AWLOGD("buf[%d]=up_wareds:0x%x", spp_offset + 8, irq_stat_data.up_wareds);
		AWLOGD("buf[%d]=down_wareds:0x%x", spp_offset + 9, irq_stat_data.down_wareds);

		spp_offset = AW_CURVE_DATA_LEN * 4 + VIRTUAL_REG_BUF_LEN +
			cnt * AW_SAR_SPP_ONE_PACK_LEN + AW_SAR_STATUS_LEN;
		*(AW_U32 *)(buf + spp_offset) = pos;
		AWLOGD("buf[%d]=0x%x", spp_offset, buf[spp_offset]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 1, buf[spp_offset + 1]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 2, buf[spp_offset + 2]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 3, buf[spp_offset + 3]);

		spp_offset = AW_CURVE_DATA_LEN * 4 + VIRTUAL_REG_BUF_LEN +
			cnt * AW_SAR_SPP_ONE_PACK_LEN + AW_SAR_STATUS_LEN + AW_POS_DATA_LEN;
		*(AW_U32 *)(buf + spp_offset) = slddata1_val & 0xFF;
		AWLOGD("buf[%d]=0x%x", spp_offset, buf[spp_offset]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 1, buf[spp_offset + 1]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 2, buf[spp_offset + 2]);
		AWLOGD("buf[%d]=0x%x", spp_offset + 3, buf[spp_offset + 3]);

		cnt++;

		if (cnt >= PACKS_IN_ONE_COMM) {
			aw9320x_app_data_send_v1(AW_APP_CMD_GET_CURVE_DATA, buf, AW_SAR_SPP_ONE_PACK_LEN * PACKS_IN_ONE_COMM);
			cnt = 0;
			break;
		}
		AW_DELAY(AW_COMM_CYCLE / PACKS_IN_ONE_COMM);
		//AW_DELAY(1000);
	}

	free(buf);
}


static void aw9320x_work_thread_cb(void)
{
	int32_t ret = 0;

	while (1) {
		ret = g_aw9320x_func->work_thread_func.wait_signal_forever();
		if (ret == AW9320X_SPP_CURVE_RUN)
			aw9320x_app_send_curve_dat();
		g_is_need_irq = AW_TRUE;
	}
}
#endif

void aw9320x_cali_get_offset(AW_U8 aot_flag)
{
	AW_U32 offset[AW_CHANNEL_NUM_MAX];
	AW_U32 reg_afe_cfg1[] = {REG_AFECFG1_CH0, REG_AFECFG1_CH1, REG_AFECFG1_CH2,
		REG_AFECFG1_CH3, REG_AFECFG1_CH4, REG_AFECFG1_CH5,
		REG_AFECFG1_CH6, REG_AFECFG1_CH7,};
	AW_U32 offset_f = 0;
	AW_U32 offset_c = 0;

	//step 2: Waiting 1s for calibration complete flag
	if(aot_flag == 1){
		//step 1: Parasitic capacitance calibration
		aw9320x_aot_set(aot_flag);

	}
	AW_DELAY(500);
	//step 3: Read offset data and restore
	for (AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		aw9320x_i2c_read( reg_afe_cfg1[i], &offset[i]);
		AWLOGD("aw9320x reg = 0x%x  data = 0x%x", reg_afe_cfg1[i], offset[i]);

		offset_c = (offset[i] >> AW_BIT8) & 0xff;
		offset_f = (offset[i] ) & 0xff;

		offset_c = offset_c* AW_COARSE_ADJUST_STEP0;
		offset_f = offset_f * AW_FINE_ADJUST_STEP0;

		AWLOGD("unsigned cap ofst ch%u: %u.%u pf\r\n",
					i,
					(offset_c +  offset_f)/ AW9320XCSR_STEP_LEN_UNSIGNED_CAP_ENLARGE,
					(offset_c +  offset_f) % AW9320XCSR_STEP_LEN_UNSIGNED_CAP_ENLARGE);
	}

}

AW_S32 aw9320x_read_diff(AW_S32 *diff)
{
	AW_S8 ret = -1;

	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		ret = aw9320x_i2c_read(REG_DIFF_CH0 + (i * AW_REG_STEP),
				(AW_U32 *)diff + i);
		if (ret != AW_OK) {
			AWLOGE("read reg[0x%04X] diff failed: %d",
					REG_DIFF_CH0 + (i * AW_REG_STEP), ret);
			return ret;
		} else {
#ifndef AW_DEBUG_PRINTF
			AWLOGD("diff: ch[%d]: %d", i, (*(diff + i) >> 10));
#endif
		}
	}

	return AW_OK;
}

AW_S32 aw9320x_read_base(AW_S32 *base)
{
	AW_S8 ret = -1;

	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		ret = aw9320x_i2c_read(REG_BASELINE_CH0 + (i * AW_REG_STEP),
				(AW_U32 *)base + i);
		if (ret != AW_OK) {
			AWLOGE("read reg[0x%04X] diff failed: %d",
					REG_BASELINE_CH0 + (i * AW_REG_STEP), ret);
			return ret;
		} else {
#ifndef AW_DEBUG_PRINTF
			AWLOGD("base: ch[%d]: %d", i, (*(base + i) >> 10));
#endif
		}
	}

	return AW_OK;
}

AW_S32 aw9320x_read_valid(AW_S32 *valid)
{
	AW_S8 ret = -1;

	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		ret = aw9320x_i2c_read(REG_VALID_CH0 + (i * AW_REG_STEP),
				(AW_U32 *)valid + i);
		if (ret != AW_OK) {
			AWLOGE("read reg[0x%04X] valid failed: %d",
					REG_VALID_CH0 + (i * AW_REG_STEP), ret);
			return ret;
		} else {
#ifndef AW_DEBUG_PRINTF
			AWLOGD("valid: ch[%d]: %d", i, (*(valid + i) >> 10));
#endif
		}
	}

	return AW_OK;
}

AW_S32 aw9320x_read_raw(AW_S32 *raw)
{
	AW_S8 ret = -1;

	for (AW_U32 i = 0; i < AW_CHANNEL_NUM_MAX; i++) {
		ret = aw9320x_i2c_read(REG_RAW_CH0 + (i * AW_REG_STEP),
				(AW_U32 *)raw + i);
		if (ret != AW_OK) {
			AWLOGE("read reg[0x%04X] raw failed: %d",
					REG_RAW_CH0 + (i * AW_REG_STEP), ret);
			return ret;
		} else {
#ifndef AW_DEBUG_PRINTF
			AWLOGD("raw: ch[%d]: %d", i, (*(raw + i) >> 10));
#endif
		}
	}

	return AW_OK;
}

AW_S32 aw932xx_read_ch_data(void){

	AW_S8 ret = -1;
	AW_S32 valid[AW_CHANNEL_NUM_MAX];
	AW_S32 raw[AW_CHANNEL_NUM_MAX];
	AW_S32 diff[AW_CHANNEL_NUM_MAX];
	AW_S32 base[AW_CHANNEL_NUM_MAX];

	ret = aw9320x_read_diff(diff);
	if(ret != AW_OK){
		AWLOGE("read diff error");
	}

	ret = aw9320x_read_base(base);
	if(ret != AW_OK){
		AWLOGE("read base error");
	}

	ret = aw9320x_read_valid(valid);
	if(ret != AW_OK){
		AWLOGE("read valid error");
	}

	ret = aw9320x_read_raw(raw);
	if(ret != AW_OK){
		AWLOGE("read raw error");
	}
#ifdef AW_DEBUG_PRINTF_DATA
	for(AW_U8 i = 0; i < AW_CHANNEL_NUM_MAX; i++){
		AWLOGD("ch = %d, raw = %d, valid = %d, base = %d, diff = %d", i, raw[i] >> 10, valid[i] >> 10, base[i] >> 10, diff[i] >> 10 );
	}
#endif
	return ret;
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

#ifdef AW_OS_USED
	if ((hw_fun->irq_thread_func.set_signal == NULL) ||
		(hw_fun->irq_thread_func.wait_signal_forever == NULL) ||
		(hw_fun->irq_thread_func.create_thread == NULL))
			AWLOGE("err! irq_thread para is NULL");
#endif

#if defined(AW_SPP_USED) && defined(AW_OS_USED)
	if ((hw_fun->spp_func.spp_write == NULL) ||
		(hw_fun->spp_func.spp_init == NULL) ||
		(hw_fun->work_thread_func.create_thread == NULL) ||
		(hw_fun->work_thread_func.set_signal == NULL) ||
		(hw_fun->work_thread_func.wait_signal_forever == NULL)) {
		AWLOGE("err! work_thread_func para is NULL");
		return ret;
	}
#endif

	g_aw9320x_func = hw_fun;
	aw9320x_Global_var_rst_def_val();

	ret = aw9320x_read_chipid();
	switch (ret) {
	case -AW_ERR:
		return ret;
	case -AW_ERR_CHIPID:
		AWLOGE("read chipid failed i2c err, ret=%d, ", ret);
		ret = aw9320x_check_chipid();
		if (ret == AW_OK) {
			AWLOGD("update boot");
			ret = aw9320x_update_bt_to_flash();
			if (ret == AW_OK) {
				AWLOGE("update boot to flash update fw ok!!!");
				ret = aw9320x_soft_reset();
				if (ret != AW_OK) {
					AWLOGE("soft_reset failed :%d", ret);
					return -AW_ERR;
				}
				ret = aw9320x_read_chipid();
				if (ret == AW_OK) {
					AWLOGD("after update boot, read chipid ok!");
					break;
				} else {
					AWLOGE("after update boot, read chipid failed, ret=%d, ", ret);
					return ret;
				}
			} else {
				AWLOGE("update_boot_to_flash failed :%d", ret);
				return -AW_ERR;
			}
		} else {
			AWLOGE("nvr chipid err!");
			return -AW_ERR;
		}
	case AW_OK:
	default:
		break;
	}

	ret = aw9320x_recover_fun(INIT_RECOVER);
	if (ret != AW_OK) {
		AWLOGE("recover_fun err");
		return -AW_ERR;
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

#ifdef AW_UPGRADE_EXCEPTION_RECOVERY
	ret = aw9320x_checksum_en_judg();
	if (ret == -AW_ERR) {
		AWLOGE("aw9320x_checksum_en failed,Firmware abnormal reload");
		load_fw_mode = AW_DIRECT_LOAD;
	}
#endif

	ret = aw9320x_fw_update(load_fw_mode);
	if (ret != AW_OK) {
		ret = aw9320x_update_err_handle();
		if (ret != AW_OK) {
			return -AW_ERR;
		} else {
			goto aw9320x_part_porc_load;
		}
	} else {
		AWLOGE("aw9320x_fw_update ok!");
	}

aw9320x_part_porc_load:
	g_aw9320x_func->irq_init(aw9320x_irq_cb);

#ifdef AW_OS_USED
	//as some platform do not support operate i2c in intn or timer,
	//so this thread is necessary. timer's or intn's callback will send
	//signal to this thread.  opreations about i2c will be done in this thread.
	g_aw9320x_func->irq_thread_func.create_thread(aw9320x_irq_thread_cb);

#ifdef AW_SPP_USED
	g_aw9320x_func->work_thread_func.create_thread(aw9320x_work_thread_cb);
	g_aw9320x_func->spp_func.spp_init(aw9320x_spp_cmd_handler);
#endif
#endif
	ret = aw9320x_para_loaded();
	if (ret != AW_OK) {
		AWLOGE("aw9320x_para_loaded failed :%d", ret);
		return -AW_ERR;
	}

	AWLOGD("aw9320x init ok!");
	return 0;
}

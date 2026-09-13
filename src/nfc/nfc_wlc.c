/*
 * NFC wireless charging (NFC Forum WLC listener) over the ST25DV tag:
 * WLC records, NDEF record encoder, type 5 tag (ST lib_NDEF
 * tagtype5_wrapper.c) and the charging control state machine.
 *
 * Original file name unknown.  Link order: first file of the module
 * (align-8 0xfd28, align-4 0x26c5c..0x27817, align-2 0x7f6f2..0x7fbc5).
 *
 * Upstream origins (the vendor compiled them into this one translation
 * unit: ndefMessageInit is inlined into wlc_write_ndef_message, and IPA facts cross
 * the "files"):
 *   - ST RFAL NDEF library, plain-C original of
 *     referenced_examples/st25_rfal_ndef/src (stm32duino C++ wrapper):
 *       ndef_record.cpp   ndefRecordReset, ndefRecordGetHeaderLength,
 *                         ndefRecordGetLength, ndefRecordSetType/Id/Payload,
 *                         ndefRecordGetPayload, ndefRecordDecode,
 *                         ndefRecordEncodeHeader, ndefRecordEncode (+ static
 *                         ndefRecordEncodePayload, inlined),
 *                         ndefRecordGetPayloadLength, ndefRecordGetPayloadItem
 *       ndef_message.cpp  ndefMessageInit (static here), ndefAllocRecord,
 *                         ndefMessageGetInfo, ndefMessageAppend,
 *                         ndefMessageEncode, ndefMessageDecode (unused)
 *       ndef_types.cpp    ndefTypeToRecord, ndefRecordSetNdefType
 *       ndef_type_wlc.cpp bufTypeRtdWlcCapability/StatusInfo,
 *                         ndefRtdWlcCapability{GetPayloadLength,
 *                         GetPayloadItem,Init,ToRecord},
 *                         ndefRtdWlcStatusInfo{GetPayloadLength,
 *                         GetPayloadItem,Init,ToRecord}
 *     Error codes from st_errno.h (ReturnCode = uint16_t).
 *   - ST25DV lib_NDEF tagtype5_wrapper.c
 *     (referenced_examples/stm32-st25dv-main): NfcType5_* and
 *     BSP_NFCTAG_GetByteSize.
 *   - Zephyr samples/drivers/adc (referenced_examples/adc/src/main.c):
 *     adc_channels, adc_nfc_init, adc_nfc_run.
 *   - Vendor code: the WLCFOD record and WLC message builder
 *     (wlc_write_ndef_message), field supervision and the listener state machine.
 */
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/eeprom.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/printk.h>

#include <g1_log.h>

#include "st25dv.h"
#include "nfc_wlc.h"

/* ------------------------------------------------------------------ */
/* data                                                                */
/* ------------------------------------------------------------------ */

/* ndef_type_wlc.c: RTD WLC type strings.  The vendor dropped the const of the
 * buffer descriptors (they sit in .data at 0x200023c4 / 0x200023bc). */
static const uint8_t ndefRtdTypeWlcCapability[] = "WLCCAP";
static const uint8_t ndefRtdTypeWlcStatusInfo[] = "WLCSTAI";

ndefConstBuffer8 bufTypeRtdWlcCapability = { ndefRtdTypeWlcCapability, sizeof(ndefRtdTypeWlcCapability) - 1U };
ndefConstBuffer8 bufTypeRtdWlcStatusInfo = { ndefRtdTypeWlcStatusInfo, sizeof(ndefRtdTypeWlcStatusInfo) - 1U };
static struct wlc_listener wlc_listener = {
	.state = 1,
};
static uint8_t wlc_info_sent = 1;	/* 0x20003046 */

static struct nfc_charge nfc_charge;
static uint32_t nfc_tick_start;
uint32_t nfc_field_mv;			/* last NFC field voltage (mV * 10) */
static sCCFileInfo CCFileStruct;
static uint32_t nfc_field_tick;
static uint32_t wlcCapabilityItem;	/* 0x200083ec ndef_type_wlc payload items */
static uint32_t wlcStatusInfoItem;	/* 0x200083e8 */
static float wlc_wait_ms;
static uint32_t nfc_charge_tick;
static int wlc_tag_configured;

static uint8_t ndefRecordPoolIndex = 0;	/* ndef_message.c; the record pool itself is unused */
uint8_t nfc_tag_type_ok;			/* ST25DV of the expected type (UID byte 6 is 0x50/0x51) */
static uint8_t nfc_field_on;
static uint8_t wlcCapabilityTemp;	/* 0x20019935 */
static uint8_t wlc_field_present;
static uint8_t nfc_low_field;

/* other modules */
struct GlassesState;
struct GlassesState *get_dashboard_state(void);
void init_box_status(void);
void FUN_000336ec(void);
uint8_t FUN_00033d5c(void);
uint16_t wlc_last_battery;

#define GS_U8(off) (((const uint8_t *)get_dashboard_state())[off])
/* ------------------------------------------------------------------ */
/* ndef_type_wlc.c: payload length / payload item encoders             */
/* ------------------------------------------------------------------ */

#define NDEF_TYPE_RTD_WLC_PAYLOAD_LENGTH			6U

#define NDEF_WLC_CAPABILITY_CONFIG_MODE_REQ_SHIFT		6U
#define NDEF_WLC_CAPABILITY_CONFIG_MODE_REQ_MASK		3U
#define NDEF_WLC_CAPABILITY_CONFIG_WAIT_TIME_RETRY_SHIFT	2U
#define NDEF_WLC_CAPABILITY_CONFIG_WAIT_TIME_RETRY_MASK		0xFU
#define NDEF_WLC_CAPABILITY_CONFIG_NEGO_WAIT_SHIFT		1U
#define NDEF_WLC_CAPABILITY_CONFIG_NEGO_WAIT_MASK		1U
#define NDEF_WLC_CAPABILITY_CONFIG_RD_CONF_SHIFT		0U
#define NDEF_WLC_CAPABILITY_CONFIG_RD_CONF_MASK			1U
#define NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_RFU_SHIFT		5U
#define NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_RFU_MASK		0x7U
#define NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_SHIFT		0U
#define NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_MASK		0x1FU

/*
 * Upstream these are function-local statics ("static uint32_t item",
 * "static uint8_t temp"); they are file-scope here only so that the global
 * symbol map can name them (GCC would call them item.0 / item.2 / temp.1).
 */

static const uint8_t *ndefRtdWlcCapabilityGetPayloadItem(const ndefType *type,
							 ndefConstBuffer *bufItem, bool begin)
{
	const ndefTypeRtdWlcCapability *ndefData;

	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCCAP) ||
	    (bufItem == NULL)) {
		return NULL;
	}

	ndefData = &type->data.wlcCapability;

	if (begin == true) {
		wlcCapabilityItem = 0;
	}

	/* Prepare bufItem->length: Each field is 1 byte, except when complete */
	bufItem->length = sizeof(uint8_t);

	switch (wlcCapabilityItem) {
	case 0: /* WLC Protocol Version */
		bufItem->buffer = &ndefData->wlcProtocolVersion;
		break;
	case 1: { /* WLC Config */
		wlcCapabilityTemp =
			((ndefData->wlcConfigModeReq & NDEF_WLC_CAPABILITY_CONFIG_MODE_REQ_MASK) << NDEF_WLC_CAPABILITY_CONFIG_MODE_REQ_SHIFT)
			| ((ndefData->wlcConfigWaitTimeRetry & NDEF_WLC_CAPABILITY_CONFIG_WAIT_TIME_RETRY_MASK) << NDEF_WLC_CAPABILITY_CONFIG_WAIT_TIME_RETRY_SHIFT)
			| ((ndefData->wlcConfigNegoWait & NDEF_WLC_CAPABILITY_CONFIG_NEGO_WAIT_MASK) << NDEF_WLC_CAPABILITY_CONFIG_NEGO_WAIT_SHIFT)
			| ((ndefData->wlcConfigRdConf & NDEF_WLC_CAPABILITY_CONFIG_RD_CONF_MASK) << NDEF_WLC_CAPABILITY_CONFIG_RD_CONF_SHIFT);

		bufItem->buffer = &wlcCapabilityTemp;
		break;
	}
	case 2: /* Cap Wt Int */
		wlcCapabilityTemp =
			((ndefData->capWtIntRfu & NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_RFU_MASK) << NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_RFU_SHIFT)
			| ((ndefData->capWtInt & NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_MASK) << NDEF_WLC_CAPABILITY_CONFIG_CAP_WT_INT_SHIFT);

		bufItem->buffer = &wlcCapabilityTemp;
		break;
	case 3: /* NDEF Rd Wt */
		bufItem->buffer = &ndefData->ndefRdWt;
		break;
	case 4: /* NDEF Write To Int */
		bufItem->buffer = &ndefData->ndefWriteToInt;
		break;
	case 5: /* NDEF Write Wt Int */
		bufItem->buffer = &ndefData->ndefWriteWtInt;
		break;
	default:
		bufItem->buffer = NULL;
		bufItem->length = 0;
		break;
	}

	/* Move to to next item for next call */
	wlcCapabilityItem++;

	return bufItem->buffer;
}

static const uint8_t *ndefRtdWlcStatusInfoGetPayloadItem(const ndefType *type,
							 ndefConstBuffer *bufItem, bool begin)
{
	const ndefTypeRtdWlcStatusInfo *ndefData;

	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCSTAI) ||
	    (bufItem == NULL)) {
		return NULL;
	}

	ndefData = &type->data.wlcStatusInfo;

	if (begin == true) {
		wlcStatusInfoItem = 0;
	}

	/* Prepare bufItem->length: Each field is 1 byte, except when complete */
	bufItem->length = sizeof(uint8_t);

	switch (wlcStatusInfoItem) {
	case 0: /* Control Byte 1 */
		bufItem->buffer = &ndefData->controlByte1;
		wlcStatusInfoItem++;
		break;
	case 1: /* Battery Level */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_BATTERY_LEVEL_MASK) != 0U) {
			bufItem->buffer = &ndefData->batteryLevel;
			wlcStatusInfoItem = 2;
			break;
		}
		/* fall through */
	case 2: /* Receive Power */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_POWER_MASK) != 0U) {
			bufItem->buffer = &ndefData->receivePower;
			wlcStatusInfoItem = 3;
			break;
		}
		/* fall through */
	case 3: /* Receive Voltage */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_VOLTAGE_MASK) != 0U) {
			bufItem->buffer = &ndefData->receiveVoltage;
			wlcStatusInfoItem = 4;
			break;
		}
		/* fall through */
	case 4: /* Receive Current */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_CURRENT_MASK) != 0U) {
			bufItem->buffer = &ndefData->receiveCurrent;
			wlcStatusInfoItem = 5;
			break;
		}
		/* fall through */
	case 5: /* Battery temperature */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_TEMPERATURE_BATTERY_MASK) != 0U) {
			bufItem->buffer = &ndefData->temperatureBattery;
			wlcStatusInfoItem = 6;
			break;
		}
		/* fall through */
	case 6: /* WLCL temperature */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_TEMPERATURE_WLCL_MASK) != 0U) {
			bufItem->buffer = &ndefData->temperatureWlcl;
			wlcStatusInfoItem = 7;
			break;
		}
		/* fall through */
	case 7: /* RFU */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_RFU_MASK) != 0U) {
			bufItem->buffer = &ndefData->rfu;
			wlcStatusInfoItem = 8;
			break;
		}
		/* fall through */
	case 8: /* Control byte 2 */
		if ((ndefData->controlByte1 & NDEF_WLC_STATUSINFO_CONTROLBYTE1_CONTROL_BYTE_2_MASK) != 0U) {
			bufItem->buffer = &ndefData->controlByte2;
			wlcStatusInfoItem = 9;
			break;
		}
		/* fall through */
	default:
		bufItem->buffer = NULL;
		bufItem->length = 0;
		break;
	}

	return bufItem->buffer;
}


/* ------------------------------------------------------------------ */
/* NFC ADC (field voltage)                                             */
/* ------------------------------------------------------------------ */

/* ADC io-channels of the zephyr,user node (overlay: <&adc 3>, channel@3) */
#define DT_SPEC_AND_COMMA(node_id, prop, idx) ADC_DT_SPEC_GET_BY_IDX(node_id, idx),

static const struct adc_dt_spec adc_channels[] = {
	DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user), io_channels, DT_SPEC_AND_COMMA)
};

/*
 * Zephyr ADC sample style channel loop (one channel).  The loop matters: at fnsplit time the
 * setup path is inside it, so GCC does not split the function into a header and an .part.0
 * (which would reorder the blocks after re-inlining).
 */
int adc_nfc_init(void)
{
	int err;

	for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) {
		err = 0;
		if (adc_is_ready_dt(&adc_channels[i])) {
			err = adc_channel_setup_dt(&adc_channels[i]);
		} else {
			G1_LOG_ERR("ADC controller device %s not ready\n\n", adc_channels[i].dev->name);
		}
		if (err < 0) {
			G1_LOG_ERR("Could not setup channel #%d (%d)\n\n", i, err);
		}
	}

	return 0;
}

uint32_t adc_nfc_run(void)
{
	int err;
	uint16_t buf;
	int32_t val_mv;
	struct adc_sequence sequence = {
		.buffer = &buf,
		/* buffer size in bytes, not number of samples */
		.buffer_size = sizeof(buf),
	};

	(void)adc_sequence_init_dt(&adc_channels[0], &sequence);

	err = adc_read(adc_channels[0].dev, &sequence);
	if (err < 0) {
		G1_LOG_ERR("Could not read (%d)\n\n", err);
		return 0;
	}

	if (adc_channels[0].channel_cfg.differential) {
		val_mv = (int32_t)((int16_t)buf);
	} else {
		val_mv = (int32_t)buf;
	}

	err = adc_raw_to_millivolts_dt(&adc_channels[0], &val_mv);
	/* conversion to mV may not be supported, skip if not */
	if (err < 0) {
		G1_LOG_ERR(" (value in mV not available)\n\n");
		return 0;
	}

	if (val_mv > 0 && val_mv < 1200) {
		return val_mv;
	}

	return 0;
}

/* ------------------------------------------------------------------ */
/* I2C security session                                                */
/* ------------------------------------------------------------------ */

int nfc_i2c_session_open(int enable)
{
	uint8_t session = 0;
	struct st25dv_passwd pwd;

	st25dv_read_i2c_security_session_dyn(global_st25dv_context_ptr, &session);
	if (session == 0) {
		if (enable) {
			pwd.msb = 0;
			pwd.lsb = 0;
			st25dv_present_i2c_password(global_st25dv_context_ptr, &pwd);
		}
	} else if (session == 1 && !enable) {
		/* a wrong password closes the session */
		pwd.msb = 0x12345678;
		pwd.lsb = 0x13245678;
		st25dv_present_i2c_password(global_st25dv_context_ptr, &pwd);
	}

	st25dv_read_i2c_security_session_dyn(global_st25dv_context_ptr, &session);
	return session;
}

uint32_t FUN_00026f3c(void)
{
	return nfc_field_mv;
}

uint32_t nfc_tick_elapsed(void)
{
	return (uint32_t)k_uptime_ticks() - nfc_tick_start;
}

void nfc_tick_reset(void)
{
	nfc_tick_start = k_uptime_ticks();
}

/* ------------------------------------------------------------------ */
/* type 5 tag (lib_NDEF tagtype5_wrapper.c)                            */
/* ------------------------------------------------------------------ */

uint32_t BSP_NFCTAG_GetByteSize(void)
{
	struct st25dv_mem_size mem_size;

	st25dv_read_mem_size(global_st25dv_context_ptr, &mem_size);
	return (mem_size.blk_size + 1) * (mem_size.mem_size + 1);
}

int NfcType5_ReadCCFile(uint8_t *pCCBuffer)
{
	int ret_value;

	/* Read 4 bytes of CC File */
	ret_value = eeprom_st25dv_read(global_st25dv_context_ptr, 0, pCCBuffer, 4);

	/* If extended memory reads the next 4 bytes */
	if (pCCBuffer[2] == NFCT5_EXTENDED_CCFILE) {
		if (ret_value != 0) {
			return NDEF_ERROR;
		}
		ret_value = eeprom_st25dv_read(global_st25dv_context_ptr, 4, pCCBuffer + 4, 4);
	}

	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	return NDEF_OK;
}

int NfcType5_NDEFDetection(void)
{
	uint8_t acc_buffer[8];
	TT5_TLV_t tlv_detect;
	int16_t status;
	uint32_t memory_size;

	CCFileStruct.State = TT5_NO_NDEF;

	/* Read CCFile */
	status = NfcType5_ReadCCFile(acc_buffer);
	if (status != NDEF_OK) {
		return status;
	}

	/* Check Byte 0 is equal to magic number */
	if ((acc_buffer[0] != NFCT5_MAGICNUMBER_E1_CCFILE) &&
	    (acc_buffer[0] != NFCT5_MAGICNUMBER_E2_CCFILE)) {
		return NDEF_ERROR_NOT_FORMATED;
	}
	/* Check Version and Access Condition */
	if ((acc_buffer[1] & 0xFC) != 0x40) {
		return NDEF_ERROR_NOT_FORMATED;
	}

	/* Check if CCFile is on 4 Bytes or 8 Bytes */
	CCFileStruct.MemorySize = acc_buffer[2];
	if (acc_buffer[2] == NFCT5_EXTENDED_CCFILE) {
		CCFileStruct.ExtMemorySize = sys_get_be16(&acc_buffer[6]);
		memory_size = CCFileStruct.ExtMemorySize;
		CCFileStruct.NDEF_offset = 8;
	} else {
		CCFileStruct.ExtMemorySize = 0;
		memory_size = CCFileStruct.MemorySize;
		CCFileStruct.NDEF_offset = 4;
	}

	CCFileStruct.MagicNumber = acc_buffer[0];
	CCFileStruct.Version = acc_buffer[1];
	CCFileStruct.TT5Tag = acc_buffer[3];

	/* Search for position of NDEF TLV in memory and tag status */
	while ((eeprom_st25dv_read(global_st25dv_context_ptr, CCFileStruct.NDEF_offset,
				   &tlv_detect, sizeof(TT5_TLV_t)) == 0) &&
	       (CCFileStruct.NDEF_offset < memory_size)) {
		/* Detect first NDEF Message in memory */
		if (tlv_detect.Type == NFCT5_NDEF_MSG_TLV) {
			if (tlv_detect.Length == 0x00) {
				CCFileStruct.State = TT5_INITIALIZED;
			} else if (CCFileStruct.Version & 0x3) {
				CCFileStruct.State = TT5_READ;
			} else {
				CCFileStruct.State = TT5_READ_WRITE;
			}
			return NDEF_OK;
		}
		/* If Proprietary NDEF jump to end of proprietary message */
		else if (tlv_detect.Type == NFCT5_PROPRIETARY_TLV) {
			if (tlv_detect.Length == NFCT5_3_BYTES_L_TLV) {
				CCFileStruct.NDEF_offset += tlv_detect.Length16;
			} else {
				CCFileStruct.NDEF_offset += tlv_detect.Length;
			}
			continue;
		}
		break;
	}

	return NDEF_ERROR_NOT_FORMATED;
}

int NfcType5_WriteTLV(uint8_t type, uint32_t Length, const uint8_t *pData)
{
	uint8_t TLV_Header[4];
	uint8_t NDEF_end = NFCT5_TERMINATOR_TLV;
	uint8_t TLVHeaderLength;
	uint32_t maxLength;
	uint32_t offset;
	int ret_value;

	maxLength = BSP_NFCTAG_GetByteSize() - CCFileStruct.NDEF_offset - 1 -
		    ((Length >= 0xFF) ? 4 : 2);
	if (Length > maxLength) {
		return NDEF_ERROR_MEMORY_TAG;
	}

	/* Detect NDEF in tag */
	if (NfcType5_NDEFDetection() != NDEF_OK) {
		return NDEF_ERROR;
	}

	TLV_Header[0] = type;
	if (Length >= 0xFF) {
		TLV_Header[1] = NFCT5_3_BYTES_L_TLV;
		*(uint16_t *)&TLV_Header[2] = sys_cpu_to_be16(Length);
		TLVHeaderLength = 4;
	} else {
		TLV_Header[1] = (uint8_t)Length;
		TLVHeaderLength = 2;
	}

	offset = CCFileStruct.NDEF_offset;
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, offset, TLV_Header,
					TLVHeaderLength);
	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	offset += TLVHeaderLength;
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, offset, pData, Length);
	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	offset += Length;
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, offset, &NDEF_end, 1);
	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	return NDEF_OK;
}

int NfcType5_WriteCCFile(const uint8_t *pCCBuffer)
{
	int ret_value;

	/* Write first block of CCFile */
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, 0, pCCBuffer, 4);

	/* If extended memory writes the next 4 bytes */
	if (pCCBuffer[2] == NFCT5_EXTENDED_CCFILE) {
		if (ret_value != 0) {
			return NDEF_ERROR;
		}
		ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, 4, pCCBuffer + 4, 4);
	}

	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	return NDEF_OK;
}

void nfc_configure_gpo(uint32_t gpo_conf)
{
	uint8_t it_time;

	if (st25dv_configure_gpo(global_st25dv_context_ptr, gpo_conf)) {
		return;
	}
	if (st25dv_read_it_pulse(global_st25dv_context_ptr, &it_time)) {
		return;
	}

	it_time = ((gpo_conf & 0x3ff) >> 8) | 0x0c;
	st25dv_write_it_pulse(global_st25dv_context_ptr, it_time);
}

int NfcType5_TT5Init(void)
{
	int ret_value;
	int16_t status;
	uint8_t accbuffer[8];
	uint8_t cdata;

	/* Prepare buffer to update CCFile */
	accbuffer[0] = CCFileStruct.MagicNumber;
	accbuffer[1] = CCFileStruct.Version;
	accbuffer[2] = CCFileStruct.MemorySize;
	accbuffer[3] = CCFileStruct.TT5Tag;
	CCFileStruct.NDEF_offset = 0x04;

	/* If extended memory prepare the length bytes */
	if (CCFileStruct.MemorySize == NFCT5_EXTENDED_CCFILE) {
		sys_put_be16(CCFileStruct.ExtMemorySize, &accbuffer[6]);
		CCFileStruct.NDEF_offset = 0x08;
	}

	/* Update CCFile */
	status = NfcType5_WriteCCFile(accbuffer);
	if (status != NDEF_OK) {
		return status;
	}

	/* Update NDEF TLV for INITIALIZED state */
	/* Update T */
	cdata = NFCT5_NDEF_MSG_TLV;
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, CCFileStruct.NDEF_offset,
					&cdata, 1);
	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	/* Update L */
	cdata = 0x00;
	ret_value = eeprom_st25dv_write(global_st25dv_context_ptr, CCFileStruct.NDEF_offset + 1,
					&cdata, 1);
	if (ret_value != 0) {
		return NDEF_ERROR;
	}

	return NDEF_OK;
}

int nfc_write_ndef(const uint8_t *pData, uint32_t Length)
{
	int status;

	if (NfcType5_WriteNDEF(Length, pData) != NDEF_ERROR) {
		return NDEF_OK;
	}

	/* not formatted: write a fresh CC file (E1 40 40 01) and retry */
	CCFileStruct.MagicNumber = NFCT5_MAGICNUMBER_E1_CCFILE;
	CCFileStruct.Version = 0x40;
	CCFileStruct.MemorySize = 0x40;
	CCFileStruct.TT5Tag = 0x01;
	status = NfcType5_TT5Init();
	NfcType5_WriteNDEF(Length, pData);

	return status;
}

/* ------------------------------------------------------------------ */
/* ndef_type_wlc.c: WLC Capability / Status and Information types      */
/* ------------------------------------------------------------------ */

static uint32_t ndefRtdWlcCapabilityGetPayloadLength(const ndefType *type);
static uint32_t ndefRtdWlcStatusInfoGetPayloadLength(const ndefType *type);

ReturnCode ndefRtdWlcCapabilityToRecord(const ndefType *type, ndefRecord *record)
{
	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCCAP) ||
	    (record == NULL)) {
		return ERR_PARAM;
	}

	(void)ndefRecordReset(record);

	/* String type */
	(void)ndefRecordSetType(record, NDEF_TNF_RTD_WELL_KNOWN_TYPE, &bufTypeRtdWlcCapability);

	if (ndefRecordSetNdefType(record, type) != ERR_NONE) {
		return ERR_PARAM;
	}

	return ERR_NONE;
}

ReturnCode ndefRtdWlcStatusInfoToRecord(const ndefType *type, ndefRecord *record)
{
	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCSTAI) ||
	    (record == NULL)) {
		return ERR_PARAM;
	}

	(void)ndefRecordReset(record);

	/* String type */
	(void)ndefRecordSetType(record, NDEF_TNF_RTD_WELL_KNOWN_TYPE, &bufTypeRtdWlcStatusInfo);

	if (ndefRecordSetNdefType(record, type) != ERR_NONE) {
		return ERR_PARAM;
	}

	return ERR_NONE;
}

__attribute__((noinline)) void wlc_reset_info(struct wlc_listener *wlc)
{
	wlc->cap_info[4] = 9;
	wlc->cap_info[5] = 9;
	wlc->f30[0] = 9;
	wlc->f30[1] = 9;
}

/* ------------------------------------------------------------------ */
/* vendor: WLC listener NDEF message (WLCCAP [+ WLCSTAI] [+ WLCFOD])   */
/* ------------------------------------------------------------------ */

/* ndef_message.c */
#define NDEF_MAX_RECORD 10U

static ndefRecord *ndefAllocRecord(void)
{
	static ndefRecord ndefRecordPool[NDEF_MAX_RECORD];

	if (ndefRecordPoolIndex >= NDEF_MAX_RECORD) {
		return NULL;
	}

	return &ndefRecordPool[ndefRecordPoolIndex++];
}

static ReturnCode ndefMessageInit(ndefMessage *message)
{
	if (message == NULL) {
		return ERR_PARAM;
	}

	message->record = NULL;
	message->info.length = 0;
	message->info.recordCount = 0;

	ndefRecordPoolIndex = 0;

	return ERR_NONE;
}

int wlc_write_ndef_message(const uint8_t *cap_info, const uint8_t *stai_info, const uint8_t *fod_info)
{
	ndefBuffer bufPayload;
	ndefTypeRtdWlcStatusInfo wlcStatusInfo;
	ndefTypeRtdWlcCapability wlcCapability;
	ndefRecord recordCap;
	ndefRecord recordFod;
	ndefRecord recordStai;
	uint8_t buf[32];
	ndefType typeCap;
	ndefType typeStai;
	ndefRecord records[4];
	ReturnCode err;
	int count;
	int i;

	wlcCapability.capWtInt = cap_info[4];
	wlcCapability.ndefRdWt = cap_info[6];
	wlcCapability.ndefWriteToInt = cap_info[7];
	wlcCapability.ndefWriteWtInt = cap_info[8];
	wlcCapability.wlcConfigModeReq = cap_info[0];
	wlcCapability.wlcConfigNegoWait = cap_info[2];
	wlcCapability.wlcConfigRdConf = cap_info[3];
	wlcCapability.wlcConfigWaitTimeRetry = cap_info[1];
	wlcCapability.wlcProtocolVersion = 0x20;
	wlcCapability.capWtIntRfu = cap_info[9];
	err = ndefRtdWlcCapabilityInit(&typeCap, &wlcCapability) |
	      ndefTypeToRecord(&typeCap, &recordCap);
	records[0] = recordCap;

	if (!stai_info[0]) {
		count = 1;
	} else {
		wlcStatusInfo.controlByte1 = stai_info[1];
		wlcStatusInfo.batteryLevel = stai_info[2];
		wlcStatusInfo.receivePower = stai_info[3];
		wlcStatusInfo.receiveVoltage = stai_info[4];
		wlcStatusInfo.receiveCurrent = stai_info[5];
		wlcStatusInfo.temperatureBattery = stai_info[6];
		wlcStatusInfo.temperatureWlcl = stai_info[7];
		wlcStatusInfo.controlByte2 = stai_info[8];
		count = 2;
		err |= ndefRtdWlcStatusInfoInit(&typeStai, &wlcStatusInfo) |
		       ndefTypeToRecord(&typeStai, &recordStai);
		records[1] = recordStai;
	}

	if (fod_info[0]) {
		ndefConstBuffer bufRecord;

		/* raw WLCFOD record (not in the ST library): ME|SR|TNF=1, type "WLCFOD", 2 bytes payload */
		buf[0] = 0x51;
		buf[1] = 0x06;
		buf[2] = 0x02;
		buf[3] = 'W';
		buf[4] = 'L';
		buf[5] = 'C';
		buf[6] = 'F';
		buf[7] = 'O';
		buf[8] = 'D';
		buf[9] = fod_info[1];
		buf[10] = fod_info[2];
		bufRecord.buffer = buf;
		bufRecord.length = 11;
		err = ndefRecordDecode(&bufRecord, &recordFod);
		records[count] = recordFod;
		count++;
	}

	{
		ndefMessage message;

		ndefMessageInit(&message);
		for (i = 0; i < count; i++) {
			err |= ndefMessageAppend(&message, &records[i]);
		}

		bufPayload.buffer = buf;
		bufPayload.length = sizeof(buf);
		err |= ndefMessageEncode(&message, &bufPayload);
	}

	return (err | (uint16_t)nfc_write_ndef(bufPayload.buffer, bufPayload.length)) ? -1 : 0;
}

/* ------------------------------------------------------------------ */
/* align-2 helpers                                                     */
/* ------------------------------------------------------------------ */

static uint32_t ndefRtdWlcCapabilityGetPayloadLength(const ndefType *type)
{
	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCCAP)) {
		return 0;
	}

	return NDEF_TYPE_RTD_WLC_PAYLOAD_LENGTH;
}

static uint32_t ndefRtdWlcStatusInfoGetPayloadLength(const ndefType *type)
{
	uint32_t length;

	if ((type == NULL) || (type->id != NDEF_TYPE_ID_RTD_WLCSTAI)) {
		return 0;
	}

	const ndefTypeRtdWlcStatusInfo *ndefData = &type->data.wlcStatusInfo;

	length = sizeof(uint8_t); /* Control byte 1 */

	/* Count the number of bits set in the Control byte 1 to get the number of following bytes */
	for (uint32_t i = 0; i < 8U; i++) {
		if ((ndefData->controlByte1 & (1U << i)) != 0U) {
			length += sizeof(uint8_t);
		}
	}

	return length;
}

int NfcType5_WriteNDEF(uint16_t Length, const uint8_t *pData)
{
	return NfcType5_WriteTLV(NFCT5_NDEF_MSG_TLV, Length, pData);
}

/* ndef_types.c */
ReturnCode ndefTypeToRecord(const ndefType *type, ndefRecord *record)
{
	if (type == NULL) {
		return ERR_PARAM;
	}

	if (type->typeToRecord != NULL) {
		return type->typeToRecord(type, record);
	}

	return ERR_NOT_IMPLEMENTED;
}

/* ------------------------------------------------------------------ */
/* ndef_record.c                                                       */
/* ------------------------------------------------------------------ */

uint32_t ndefRecordGetHeaderLength(const ndefRecord *record)
{
	uint32_t length;

	if (record == NULL) {
		return 0;
	}

	length = sizeof(uint8_t);	/* header (MB:1 + ME:1 + CF:1 + SR:1 + IL:1 + TNF:3 => 8 bits) */
	length += sizeof(uint8_t);	/* Type length */
	if (ndefHeaderIsSetSR(record)) {
		length += sizeof(uint8_t);	/* Short record */
	} else {
		length += sizeof(uint32_t);	/* Standard record */
	}
	if (ndefHeaderIsSetIL(record)) {
		length += sizeof(uint8_t);	/* Id length */
	}
	length += record->typeLength;	/* Type */
	length += record->idLength;	/* Id */

	return length;
}

uint32_t ndefRecordGetPayloadLength(const ndefRecord *record)
{
	uint32_t payloadLength;

	if (record == NULL) {
		return 0;
	}

	if ((record->ndeftype != NULL) && (record->ndeftype->getPayloadLength != NULL)) {
		payloadLength = record->ndeftype->getPayloadLength(record->ndeftype);
	} else {
		payloadLength = record->bufPayload.length;
	}

	return payloadLength;
}

uint32_t ndefRecordGetLength(const ndefRecord *record)
{
	uint32_t length;

	length = ndefRecordGetHeaderLength(record);	/* Header */
	length += ndefRecordGetPayloadLength(record);	/* Payload */

	return length;
}

ReturnCode ndefRecordSetType(ndefRecord *record, uint8_t tnf, const ndefConstBuffer8 *bufType)
{
	if ((record == NULL) ||
	    (bufType == NULL) || ndefBufferIsInvalid(bufType)) {
		return ERR_PARAM;
	}

	ndefHeaderSetTNF(record, tnf);
	record->typeLength = bufType->length;
	record->type = bufType->buffer;

	return ERR_NONE;
}

ReturnCode ndefRecordSetPayload(ndefRecord *record, const ndefConstBuffer *bufPayload)
{
	if ((record == NULL) ||
	    (bufPayload == NULL) || ndefBufferIsInvalid(bufPayload)) {
		return ERR_PARAM;
	}

	ndefHeaderSetValueSR(record, (bufPayload->length <= NDEF_SHORT_RECORD_LENGTH_MAX) ? 1 : 0);
	record->bufPayload.buffer = bufPayload->buffer;
	record->bufPayload.length = bufPayload->length;

	return ERR_NONE;
}

ReturnCode ndefRecordSetId(ndefRecord *record, const ndefConstBuffer8 *bufId)
{
	if ((record == NULL) ||
	    (bufId == NULL) || ndefBufferIsInvalid(bufId)) {
		return ERR_PARAM;
	}

	if (bufId->buffer != NULL) {
		ndefHeaderSetIL(record);
	} else {
		ndefHeaderClearIL(record);
	}
	record->id = bufId->buffer;
	record->idLength = bufId->length;

	return ERR_NONE;
}

ReturnCode ndefRecordReset(ndefRecord *record)
{
	ndefConstBuffer8 bufEmpty8 = { NULL, 0 };
	ndefConstBuffer bufEmpty = { NULL, 0 };

	if (record == NULL) {
		return ERR_PARAM;
	}

	/* Set the MB and ME bits */
	record->header = ndefHeader(1U, 1U, 0U, 0U, 0U, NDEF_TNF_EMPTY);

	(void)ndefRecordSetType(record, NDEF_TNF_EMPTY, &bufEmpty8);
	(void)ndefRecordSetId(record, &bufEmpty8);

	/* Set the SR bit */
	(void)ndefRecordSetPayload(record, &bufEmpty);

	record->ndeftype = NULL;
	record->next = NULL;

	return ERR_NONE;
}

ReturnCode ndefRecordDecode(const ndefConstBuffer *bufPayload, ndefRecord *record)
{
	uint32_t offset;

	if ((bufPayload == NULL) || (bufPayload->buffer == NULL) || (record == NULL)) {
		return ERR_PARAM;
	}

	if (ndefRecordReset(record) != ERR_NONE) {
		return ERR_INTERNAL;
	}

	/* Get "header" byte */
	offset = 0;
	if ((offset + sizeof(uint8_t)) > bufPayload->length) {
		return ERR_PROTO;
	}
	record->header = bufPayload->buffer[offset];
	offset++;

	/* Get Type length */
	if ((offset + sizeof(uint8_t)) > bufPayload->length) {
		return ERR_PROTO;
	}
	record->typeLength = bufPayload->buffer[offset];
	offset++;

	/* Decode Payload length */
	if (ndefHeaderIsSetSR(record)) {
		/* Short record */
		if ((offset + sizeof(uint8_t)) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->bufPayload.length = bufPayload->buffer[offset]; /* length stored on a single byte for Short Record */
		offset++;
	} else {
		/* Standard record */
		if ((offset + sizeof(uint32_t)) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->bufPayload.length = GETU32(&bufPayload->buffer[offset]);
		offset += sizeof(uint32_t);
	}

	/* Get Id length */
	if (ndefHeaderIsSetIL(record)) {
		if ((offset + sizeof(uint8_t)) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->idLength = bufPayload->buffer[offset];
		offset++;
	} else {
		record->idLength = 0;
	}

	/* Get Type */
	if (record->typeLength > 0U) {
		if ((offset + record->typeLength) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->type = &bufPayload->buffer[offset];
		offset += record->typeLength;
	} else {
		record->type = NULL;
	}

	/* Get Id */
	if (record->idLength > 0U) {
		if ((offset + record->idLength) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->id = &bufPayload->buffer[offset];
		offset += record->idLength;
	} else {
		record->id = NULL;
	}

	/* Get Payload */
	if (record->bufPayload.length > 0U) {
		if ((offset + record->bufPayload.length) > bufPayload->length) {
			return ERR_PROTO;
		}
		record->bufPayload.buffer = &bufPayload->buffer[offset];
	} else {
		record->bufPayload.buffer = NULL;
	}

	record->next = NULL;

	return ERR_NONE;
}

ReturnCode ndefRecordEncodeHeader(const ndefRecord *record, ndefBuffer *bufHeader)
{
	uint32_t offset;
	uint32_t payloadLength;

	if ((record == NULL) || (bufHeader == NULL) || (bufHeader->buffer == NULL)) {
		return ERR_PARAM;
	}

	if (bufHeader->length < NDEF_RECORD_HEADER_LEN) {
		bufHeader->length = NDEF_RECORD_HEADER_LEN;
		return ERR_NOMEM;
	}

	/* Start encoding the record */
	offset = 0;
	bufHeader->buffer[offset] = record->header;
	offset++;

	/* Set Type length */
	bufHeader->buffer[offset] = record->typeLength;
	offset++;

	/* Encode Payload length */
	payloadLength = ndefRecordGetPayloadLength(record);
	if (payloadLength <= NDEF_SHORT_RECORD_LENGTH_MAX) {
		/* Short record */
		bufHeader->buffer[offset] = (uint8_t)payloadLength;
		offset++;
	} else {
		/* Standard record */
		bufHeader->buffer[offset] = (uint8_t)(payloadLength >> 24);
		offset++;
		bufHeader->buffer[offset] = (uint8_t)(payloadLength >> 16);
		offset++;
		bufHeader->buffer[offset] = (uint8_t)(payloadLength >> 8);
		offset++;
		bufHeader->buffer[offset] = (uint8_t)(payloadLength);
		offset++;
	}

	/* Encode Id length */
	if (ndefHeaderIsSetIL(record)) {
		bufHeader->buffer[offset] = record->idLength;
		offset++;
	}

	bufHeader->length = offset;

	return ERR_NONE;
}

/* ndef_types.c */
ReturnCode ndefRecordSetNdefType(ndefRecord *record, const ndefType *type)
{
	uint32_t payloadLength;

	if ((record == NULL) ||
	    (type == NULL) ||
	    (type->id == NDEF_TYPE_ID_NONE) ||
	    (type->id > NDEF_TYPE_ID_COUNT) ||
	    (type->getPayloadLength == NULL) ||
	    (type->getPayloadItem == NULL) ||
	    (type->typeToRecord == NULL)) {
		return ERR_PARAM;
	}

	record->ndeftype = type;

	/* Set Short Record bit accordingly */
	payloadLength = ndefRecordGetPayloadLength(record);
	ndefHeaderSetValueSR(record, (payloadLength <= NDEF_SHORT_RECORD_LENGTH_MAX) ? 1 : 0);

	return ERR_NONE;
}

ReturnCode ndefRecordGetPayload(const ndefRecord *record, ndefConstBuffer *bufPayload)
{
	if ((record == NULL) || (bufPayload == NULL)) {
		return ERR_PARAM;
	}

	bufPayload->buffer = record->bufPayload.buffer;
	bufPayload->length = record->bufPayload.length;

	return ERR_NONE;
}

const uint8_t *ndefRecordGetPayloadItem(const ndefRecord *record, ndefConstBuffer *bufPayloadItem,
					bool begin)
{
	if ((record == NULL) || (bufPayloadItem == NULL)) {
		return NULL;
	}

	bufPayloadItem->buffer = NULL;
	bufPayloadItem->length = 0;

	if ((record->ndeftype != NULL) && (record->ndeftype->getPayloadItem != NULL)) {
		record->ndeftype->getPayloadItem(record->ndeftype, bufPayloadItem, begin);
	} else {
		if (begin == true) {
			(void)ndefRecordGetPayload(record, bufPayloadItem);
		}
	}

	return bufPayloadItem->buffer;
}

static ReturnCode ndefRecordEncodePayload(const ndefRecord *record, ndefBuffer *bufPayload)
{
	uint32_t payloadLength;
	uint32_t offset;
	bool begin;
	ndefConstBuffer bufPayloadItem;

	if (bufPayload == NULL) {
		return ERR_PARAM;
	}

	payloadLength = ndefRecordGetPayloadLength(record);
	if (payloadLength > bufPayload->length) {
		return ERR_NOMEM;
	}

	begin = true;
	offset = 0;
	while (ndefRecordGetPayloadItem(record, &bufPayloadItem, begin) != NULL) {
		begin = false;
		if (bufPayloadItem.length > 0U) {
			ST_MEMCPY(&bufPayload->buffer[offset], bufPayloadItem.buffer, bufPayloadItem.length);
		}
		offset += bufPayloadItem.length;
	}

	bufPayload->length = offset;

	return ERR_NONE;
}

ReturnCode ndefRecordEncode(const ndefRecord *record, ndefBuffer *bufRecord)
{
	ReturnCode err;
	ndefBuffer bufHeader;
	ndefBuffer bufPayload;
	uint32_t offset;

	if ((record == NULL) || (bufRecord == NULL) || (bufRecord->buffer == NULL)) {
		return ERR_PARAM;
	}

	if (bufRecord->length < ndefRecordGetLength(record)) {
		bufRecord->length = ndefRecordGetLength(record);
		return ERR_NOMEM;
	}

	/* Encode header at the beginning of buffer provided */
	bufHeader = *bufRecord; /* Copy ndefBuffer fields */
	err = ndefRecordEncodeHeader(record, &bufHeader);
	if (err != ERR_NONE) {
		return err;
	}

	offset = bufHeader.length;

	/* Set Type */
	if (record->typeLength > 0U) {
		(void)ST_MEMCPY(&bufRecord->buffer[offset], record->type, record->typeLength);
		offset += record->typeLength;
	}

	/* Set Id */
	if (record->idLength > 0U) {
		(void)ST_MEMCPY(&bufRecord->buffer[offset], record->id, record->idLength);
		offset += record->idLength;
	}

	/* Set Payload */
	bufPayload.buffer = &bufRecord->buffer[offset];
	bufPayload.length = bufRecord->length - offset;
	err = ndefRecordEncodePayload(record, &bufPayload);
	if (err != ERR_NONE) {
		return err;
	}

	bufRecord->length = offset + bufPayload.length;

	return ERR_NONE;
}

/* ------------------------------------------------------------------ */
/* ndef_message.c                                                      */
/* ------------------------------------------------------------------ */

ReturnCode ndefMessageGetInfo(const ndefMessage *message, ndefMessageInfo *info)
{
	ndefRecord *record;
	uint32_t length = 0;
	uint32_t recordCount = 0;

	if ((message == NULL) || (info == NULL)) {
		return ERR_PARAM;
	}

	record = message->record;

	while (record != NULL) {
		length += ndefRecordGetLength(record);
		recordCount++;
		record = record->next;
	}

	info->length = length;
	info->recordCount = recordCount;

	return ERR_NONE;
}

ReturnCode ndefMessageEncode(const ndefMessage *message, ndefBuffer *bufPayload)
{
	ReturnCode err;
	ndefMessageInfo info;
	ndefRecord *record;
	uint32_t offset;
	uint32_t remainingLength;

	if ((bufPayload == NULL) || (bufPayload->buffer == NULL)) {
		return ERR_PARAM;
	}

	err = ndefMessageGetInfo(message, &info);
	if ((err != ERR_NONE) || (bufPayload->length < info.length)) {
		bufPayload->length = info.length;
		return ERR_NOMEM;
	}

	/* Get the first record */
	record = ndefMessageGetFirstRecord(message);
	offset = 0;
	remainingLength = bufPayload->length;

	while (record != NULL) {
		ndefBuffer bufRecord;

		bufRecord.buffer = &bufPayload->buffer[offset];
		bufRecord.length = remainingLength;
		err = ndefRecordEncode(record, &bufRecord);
		if (err != ERR_NONE) {
			bufPayload->length = info.length;
			return err;
		}
		offset += bufRecord.length;
		remainingLength -= bufRecord.length;

		record = ndefMessageGetNextRecord(record);
	}

	bufPayload->length = offset;

	return ERR_NONE;
}

ReturnCode ndefMessageAppend(ndefMessage *message, ndefRecord *record)
{
	if ((message == NULL) || (record == NULL)) {
		return ERR_PARAM;
	}

	/* Clear the Message Begin bit */
	ndefHeaderClearMB(record);

	/* Record is appended so it is the last in the list, set the Message End bit */
	ndefHeaderSetME(record);

	record->next = NULL;

	if (message->record == NULL) {
		/* Set the Message Begin bit for the first record only */
		ndefHeaderSetMB(record);

		message->record = record;
	} else {
		ndefRecord *current = message->record;

		/* Go through the list of records */
		while (current->next != NULL) {
			current = current->next;
		}

		/* Clear the Message End bit to the record before the one being appended */
		ndefHeaderClearME(current);

		/* Append to the last record */
		current->next = record;
	}

	message->info.length += ndefRecordGetLength(record);
	message->info.recordCount += 1U;

	return ERR_NONE;
}

/* not called by the firmware (dropped by --gc-sections) */
ReturnCode ndefMessageDecode(const ndefConstBuffer *bufPayload, ndefMessage *message)
{
	ReturnCode err;
	uint32_t offset;

	if ((bufPayload == NULL) || (bufPayload->buffer == NULL)) {
		return ERR_PARAM;
	}

	err = ndefMessageInit(message);
	if (err != ERR_NONE) {
		return err;
	}

	offset = 0;
	while (offset < bufPayload->length) {
		ndefConstBuffer bufRecord;
		ndefRecord *record = ndefAllocRecord();

		if (record == NULL) {
			return ERR_NOMEM;
		}
		bufRecord.buffer = &bufPayload->buffer[offset];
		bufRecord.length = bufPayload->length - offset;
		err = ndefRecordDecode(&bufRecord, record);
		if (err != ERR_NONE) {
			return err;
		}
		offset += ndefRecordGetLength(record);

		err = ndefMessageAppend(message, record);
		if (err != ERR_NONE) {
			return err;
		}
	}

	return ERR_NONE;
}

ReturnCode ndefRtdWlcCapabilityInit(ndefType *type, const ndefTypeRtdWlcCapability *param)
{
	ndefTypeRtdWlcCapability *ndefData;

	if ((type == NULL) || (param == NULL)) {
		return ERR_PARAM;
	}

	type->id = NDEF_TYPE_ID_RTD_WLCCAP;
	type->getPayloadLength = ndefRtdWlcCapabilityGetPayloadLength;
	type->getPayloadItem = ndefRtdWlcCapabilityGetPayloadItem;
	type->typeToRecord = ndefRtdWlcCapabilityToRecord;
	ndefData = &type->data.wlcCapability;

	(void)ST_MEMCPY(ndefData, param, sizeof(ndefTypeRtdWlcCapability));

	return ERR_NONE;
}

ReturnCode ndefRtdWlcStatusInfoInit(ndefType *type, const ndefTypeRtdWlcStatusInfo *param)
{
	ndefTypeRtdWlcStatusInfo *ndefData;

	if ((type == NULL) || (param == NULL)) {
		return ERR_PARAM;
	}

	type->id = NDEF_TYPE_ID_RTD_WLCSTAI;
	type->getPayloadLength = ndefRtdWlcStatusInfoGetPayloadLength;
	type->getPayloadItem = ndefRtdWlcStatusInfoGetPayloadItem;
	type->typeToRecord = ndefRtdWlcStatusInfoToRecord;
	ndefData = &type->data.wlcStatusInfo;

	(void)ST_MEMCPY(ndefData, param, sizeof(ndefTypeRtdWlcStatusInfo));

	return ERR_NONE;
}

uint8_t FUN_000274a0(void)
{
	return nfc_tag_type_ok;
}

/* ------------------------------------------------------------------ */
/* NFC field supervision and WLC listener                             */
/* ------------------------------------------------------------------ */

int nfc_read_field_mv(uint32_t *field_mv)
{
	*field_mv = adc_nfc_run() * 10;
	return 1;
}

int nfc_init(void)
{
	uint8_t uid[8] = {0};
	uint8_t ic_rev = 0;
	uint8_t ic_ref;
	const struct eeprom_driver_api *api;

	global_st25dv_context_ptr = eeprom_st25dv_init();
	if (!global_st25dv_context_ptr || !global_st25dv_context_ptr->config ||
	    !global_st25dv_context_ptr->data || !global_st25dv_context_ptr->api) {
		return 0;
	}

	k_msleep(20);
	api = global_st25dv_context_ptr->api;
	api->size(global_st25dv_context_ptr);

	ST25DV_GetUID(global_st25dv_context_ptr, uid);
	printk("UUID = %02X %02X %02X %02X %02X %02X %02X %02X.\n", uid[0], uid[1], uid[2],
	       uid[3], uid[4], uid[5], uid[6], uid[7]);
	if (uid[5] == 0x50 || uid[5] == 0x51) {
		nfc_tag_type_ok = 1;
	}

	st25dv_read_ic_rev(global_st25dv_context_ptr, &ic_rev);
	printk("REV_IC = %02X.\n", ic_rev);
	st25dv_read_id(global_st25dv_context_ptr, &ic_ref);
	printk("REF_IC = %02X.\n", ic_ref);

	adc_nfc_init();
	init_box_status();

	return 0;
}

void nfc_charge_update_state(struct nfc_charge *chg)
{
	int status = nfc_charge_status();

	if (status == 1) {
		chg->state = 4;
	} else if (status == 0) {
		chg->state = 1;
	} else {
		chg->state = 2;
	}
}

int nfc_charge_status(void)
{
	if (nfc_field_mv <= 5100) {
		return 2;
	}

	return GS_U8(0xfc4) >= 100 ? 1 : 0;
}

void nfc_charge_update(struct nfc_charge *chg, struct wlc_listener *wlc)
{
	chg->state = 3;
	nfc_charge_update_state(chg);

	switch (chg->state) {
	case 1:
		wlc->cap_info[5] = 9;
		wlc->f03 = 0;
		if (chg->field_mv < 500) {
			if (!nfc_low_field) {
				nfc_low_field = 1;
			}
			return;
		}
		nfc_low_field = 0;
		break;
	case 2:
		if ((int64_t)(k_uptime_ticks() - nfc_charge_tick) <= 3000) {
			return;
		}
		if (wlc->state == 10) {
			if (!wlc->active) {
				wlc->cap_info[5] = 6;
			}
			wlc->fod_req = 1;
		}
		wlc->f03 = 1;
		nfc_charge_tick = k_uptime_ticks();
		return;
	case 4:
		if (wlc->state == 10) {
			if (!wlc->active) {
				wlc->cap_info[5] = 6;
			}
			wlc->fod_req = 1;
		}
		if (!wlc->charging) {
			wlc->charging = 1;
		}
		break;
	default:
		break;
	}

	nfc_charge_tick = k_uptime_ticks();
}

void nfc_field_voltage_update(void)
{
	nfc_read_field_mv(&nfc_charge.field_mv);
	nfc_field_mv = nfc_charge.field_mv;
}

uint32_t chargerGetVdcRect(void)
{
	nfc_field_voltage_update();
	return nfc_field_mv;
}

bool nfc_field_detected(void)
{
	nfc_field_voltage_update();
	return nfc_field_mv > 5100;
}

int nfc_field_check(void)
{
	int ret;

	if (nfc_field_detected()) {
		nfc_field_tick = k_uptime_ticks();
		ret = 1;
	} else {
		if ((int32_t)((uint32_t)k_uptime_ticks() - nfc_field_tick) < 0) {
			k_uptime_ticks();
		}
		ret = 0;
	}

	return ret;
}

void wlc_update_field_state(struct wlc_listener *wlc, uint8_t *present)
{
	int on = nfc_field_check();

	*present = on != 0;
	if (!on) {
		if (nfc_field_on) {
			nfc_field_on = 0;
			if (!wlc->charging) {
				wlc->state = 1;
			}
		}
	} else if (!nfc_field_on) {
		nfc_field_on = 1;
	}
}

void nfc_charge_refresh(struct nfc_charge *chg, struct wlc_listener *wlc)
{
	nfc_read_field_mv(&chg->field_mv);
	nfc_field_mv = chg->field_mv;

	wlc->stai_info[4] = (GS_U8(0xfc8) + 200u) >> 8;
	wlc->stai_info[2] = GS_U8(0xfc4);
	wlc->battery = GS_U8(0xfc4);
	(void)get_dashboard_state();
	wlc->charging = 0;

	nfc_charge_update(chg, wlc);
}

int FUN_00027744(void)
{
	uint8_t eh_ctrl = 0;

	FUN_000336ec();

	if (!wlc_tag_configured) {
		if (nfc_i2c_session_open(1) < 0) {
			return 0;
		}
		if (st25dv_read_eh_ctrl_dyn(global_st25dv_context_ptr, &eh_ctrl) == 0) {
			eh_ctrl &= ~BIT(0);
			st25dv_write_eh_ctrl_dyn(global_st25dv_context_ptr, eh_ctrl);
		}
		nfc_configure_gpo(0xff);
		if (nfc_i2c_session_open(0) < 0) {
			return 0;
		}
		wlc_tag_configured = 1;
	}

	if (wlc_listener.state == 1) {
		wlc_listener.active = 1;
		wlc_listener.fod_req = 0;
		wlc_listener.charging = 0;
		wlc_listener.f03 = 0;
		wlc_listener.f04 = 1;
		wlc_listener.f06 = 0;
		wlc_listener.cap_info[0] = 0;
		wlc_listener.cap_info[1] = 0;
		wlc_listener.cap_info[2] = 0;
		wlc_listener.cap_info[3] = 1;
		wlc_listener.cap_info[4] = 9;
		wlc_listener.cap_info[5] = 9;
		wlc_listener.cap_info[6] = 0x1e;
		wlc_listener.cap_info[7] = 3;
		wlc_listener.cap_info[8] = 0xa;
		wlc_listener.cap_info[9] = 0;
		wlc_listener.stai_info[0] = 1;
		wlc_listener.stai_info[1] = 5;
		wlc_listener.stai_info[2] = 0;
		wlc_listener.stai_info[3] = 0;
		wlc_listener.stai_info[4] = 0;
		wlc_listener.stai_info[5] = 0;
		wlc_listener.stai_info[6] = 0;
		wlc_listener.stai_info[7] = 0;
		wlc_listener.stai_info[8] = 0;
		wlc_listener.fod_info[0] = 0;
		wlc_listener.fod_info[1] = 2;
		wlc_listener.fod_info[2] = 0;
		wlc_listener.f25 = 0;
		wlc_listener.f27 = 0;
		wlc_listener.f28 = 0;
		wlc_listener.f2c = 0;
		wlc_listener.f2e[0] = 1;
		wlc_listener.f2e[1] = 1;
		wlc_listener.f30[0] = 0xa;
		wlc_listener.f30[1] = 0xa;
		wlc_listener.f32[0] = 0;
		wlc_listener.f32[1] = 0;
		wlc_listener.battery = 0;
		wlc_listener.f35[0] = 0;
		wlc_listener.f35[1] = 0;
		wlc_listener.f35[2] = 0xf;
		wlc_listener.f38 = 0;
		wlc_listener.f3a = 0;
	}

	nfc_charge_refresh(&nfc_charge, &wlc_listener);
	FUN_00033d5c();
	wlc_listener_process(&wlc_listener);

	return 0;
}

void wlc_listener_process(struct wlc_listener *wlc)
{
	int diff;

	wlc_update_field_state(wlc, &wlc_field_present);
	wlc_field_present = 1;

	switch (wlc->state) {
	case 1:
		wlc_reset_info(wlc);
		/*
		 * The target keeps this (redundant) store after the call; our GCC
		 * drops a plain store (ipa-modref knows wlc_reset_info cannot touch
		 * it).  A volatile access keeps it and gives the target's size.
		 */
		*(volatile uint8_t *)&wlc_field_present = 1;
		wlc->state = 2;
		wlc->charging = 0;
		return;
	case 2:
		k_msleep(50);
		wlc->state = 3;
		return;
	case 3:
		if (wlc->charging) {
			wlc->state = 12;
			return;
		}
		if (!wlc->cap_info[0]) {
			if (wlc_info_sent || wlc->cap_info[4] != wlc->cap_info[5]) {
				goto send;
			}
			diff = wlc->stai_info[2] - wlc_last_battery;
			if (diff < 0) {
				diff = wlc_last_battery - wlc->stai_info[2];
			}
			if (diff > 20) {
				wlc_last_battery = wlc->stai_info[2];
send:
				wlc->cap_info[4] = wlc->cap_info[5];
				wlc_write_ndef_message(wlc->cap_info, wlc->stai_info, wlc->fod_info);
				wlc_info_sent = 0;
			}
			wlc->state = 4;
		}
		if (wlc->fod_req) {
			wlc->fod_req = 0;
		}
		wlc_wait_ms = 150.0f;
		nfc_tick_reset();
		return;
	case 4:
		if (!((float)nfc_tick_elapsed() > wlc_wait_ms)) {
			return;
		}
		if (!wlc->cap_info[0]) {
			wlc->state = 9;
		} else {
			wlc->state = 5;
		}
		return;
	case 5:
	case 6:
	case 7:
	case 9:
		if (!wlc->cap_info[0]) {
			wlc_wait_ms = pow(2.0, wlc->cap_info[4] + 3) - 50.0;
		}
		nfc_tick_reset();
		wlc->state = 10;
		return;
	case 10:
		if (!wlc->fod_req && !((float)nfc_tick_elapsed() >= wlc_wait_ms)) {
			return;
		}
		wlc->state = 11;
		return;
	case 11:
		if (wlc->fod_req) {
			if (wlc->charging) {
				if (!wlc->cap_info[0]) {
					wlc->state = 12;
				}
			} else if (!wlc->cap_info[0]) {
				wlc->state = 2;
			}
		} else if (!wlc->cap_info[0]) {
			wlc->state = 3;
		}
		return;
	case 12:
		wlc->cap_info[0] = 2;
		wlc->cap_info[4] = 0x13;
		wlc_write_ndef_message(wlc->cap_info, wlc->stai_info, wlc->fod_info);
		wlc_info_sent = 1;
		wlc->fod_req = 0;
		nfc_tick_reset();
		wlc->state = 14;
		return;
	case 14:
		nfc_tick_reset();
		return;
	default:
		return;
	}
}

/* old Ghidra name, kept as an alias until the callers in other modules (threads.c) are renamed */
extern __typeof__(chargerGetVdcRect) FUN_00027664 __attribute__((alias("chargerGetVdcRect")));

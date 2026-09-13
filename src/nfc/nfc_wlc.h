/*
 * NFC wireless charging (NFC Forum WLC) listener on the ST25DV:
 * the ST RFAL NDEF library subset (records, messages, WLCCAP/WLCSTAI types;
 * see referenced_examples/st25_rfal_ndef), the type 5 tag wrapper (from ST's
 * lib_NDEF tagtype5_wrapper.c) and the vendor WLCFOD record / listener.
 */
#ifndef G1_NFC_WLC_H_
#define G1_NFC_WLC_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/*
 * ---- NDEF library (ST RFAL NDEF: st_errno.h, ndef_buffer.h, ndef_record.h,
 *      ndef_message.h, ndef_types.h, ndef_type_wlc.h), reduced to what the
 *      firmware uses ----
 */

/* st_errno.h */
typedef uint16_t ReturnCode;

#define ERR_NONE		((ReturnCode)0U)
#define ERR_NOMEM		((ReturnCode)1U)
#define ERR_PARAM		((ReturnCode)7U)
#define ERR_PROTO		((ReturnCode)11U)
#define ERR_INTERNAL		((ReturnCode)12U)
#define ERR_NOT_IMPLEMENTED	((ReturnCode)15U)

/* ndef_buffer.h */
typedef struct {
	const uint8_t *buffer;
	uint32_t length;
} ndefConstBuffer;

typedef struct {
	uint8_t *buffer;
	uint32_t length;
} ndefBuffer;

typedef struct {
	const uint8_t *buffer;
	uint8_t length;
} ndefConstBuffer8;

#define ndefBufferIsInvalid(buf) (((buf)->buffer == NULL) && ((buf)->length != 0U))

/* nfc_utils.h */
#define GETU32(a) (((uint32_t)(a)[0] << 24) | ((uint32_t)(a)[1] << 16) | \
		   ((uint32_t)(a)[2] << 8) | ((uint32_t)(a)[3]))
#define ST_MEMCPY memcpy

/* ndef_record.h */
#define NDEF_RECORD_HEADER_LEN		7U
#define NDEF_SHORT_RECORD_LENGTH_MAX	255U

#define NDEF_TNF_EMPTY			0U
#define NDEF_TNF_RTD_WELL_KNOWN_TYPE	1U
#define NDEF_TNF_MASK			7U

#define ndefHeader(MB, ME, CF, SR, IL, TNF) \
	((((MB) & 1U) << 7U) | (((ME) & 1U) << 6U) | (((CF) & 1U) << 5U) | \
	 (((SR) & 1U) << 4U) | (((IL) & 1U) << 3U) | ((uint8_t)(TNF) & NDEF_TNF_MASK))

#define ndefHeaderSR(record)		(((record)->header & 0x10U) >> 4)
#define ndefHeaderIL(record)		(((record)->header & 0x08U) >> 3)
#define ndefHeaderTNF(record)		((record)->header & NDEF_TNF_MASK)

#define ndefHeaderSetMB(record)		((record)->header |= (1U << 7))
#define ndefHeaderSetME(record)		((record)->header |= (1U << 6))
#define ndefHeaderSetIL(record)		((record)->header |= (1U << 3))
#define ndefHeaderSetTNF(record, value)	((record)->header |= (uint8_t)(value) & NDEF_TNF_MASK)

#define ndefHeaderClearMB(record)	((record)->header &= 0x7FU)
#define ndefHeaderClearME(record)	((record)->header &= 0xBFU)
#define ndefHeaderClearIL(record)	((record)->header &= 0xF7U)

#define ndefHeaderSetValueSR(record, value) \
	do { (record)->header &= 0xEFU; (record)->header |= (((uint8_t)(value)) & 1U) << 4; } while (0)

#define ndefHeaderIsSetSR(record)	(ndefHeaderSR(record) == 1U)
#define ndefHeaderIsSetIL(record)	(ndefHeaderIL(record) == 1U)

typedef struct ndefTypeStruct ndefType;
typedef struct ndefMessageStruct ndefMessage;

/* one NDEF record (0x1c bytes) */
typedef struct ndefRecordStruct {
	uint8_t header;			/* MB:1 ME:1 CF:1 SR:1 IL:1 TNF:3 */
	uint8_t typeLength;
	uint8_t idLength;
	const uint8_t *type;
	const uint8_t *id;
	ndefConstBuffer bufPayload;
	const ndefType *ndeftype;	/* well-known type data (payload generator) */
	struct ndefRecordStruct *next;
} ndefRecord;

/* ndef_message.h */
typedef struct {
	uint32_t length;
	uint32_t recordCount;
} ndefMessageInfo;

struct ndefMessageStruct {
	ndefRecord *record;
	ndefMessageInfo info;
};

#define ndefMessageGetFirstRecord(message)	(((message) == NULL) ? NULL : (message)->record)
#define ndefMessageGetNextRecord(record)	(((record) == NULL) ? NULL : (record)->next)

/* ndef_type_wlc.h */
typedef struct {
	uint8_t wlcProtocolVersion;
	uint8_t wlcConfigModeReq;
	uint8_t wlcConfigWaitTimeRetry;
	uint8_t wlcConfigNegoWait;
	uint8_t wlcConfigRdConf;
	uint8_t capWtIntRfu;
	uint8_t capWtInt;
	uint8_t ndefRdWt;
	uint8_t ndefWriteToInt;
	uint8_t ndefWriteWtInt;
} ndefTypeRtdWlcCapability;

typedef struct {
	uint8_t controlByte1;
	uint8_t batteryLevel;
	uint8_t receivePower;
	uint8_t receiveVoltage;
	uint8_t receiveCurrent;
	uint8_t temperatureBattery;
	uint8_t temperatureWlcl;
	uint8_t rfu;
	uint8_t controlByte2;
} ndefTypeRtdWlcStatusInfo;

/* the Listen Control record is not used, but its 13-byte struct sizes the union */
typedef struct {
	uint8_t statusInfoErrorFlag;
	uint8_t statusInfoBatteryStatus;
	uint8_t statusInfoCnt;
	uint8_t wptConfigWptReq;
	uint8_t wptConfigWptDuration;
	uint8_t wptConfigInfoReq;
	uint8_t powerAdjReq;
	uint8_t batteryLevel;
	uint8_t drvInfoFlag;
	uint8_t drvInfoInt;
	uint8_t holdOffWtInt;
	uint8_t errorInfoError;
	uint8_t errorInfoTemperature;
} ndefTypeRtdWlcListenCtl;

#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_BATTERY_LEVEL_MASK		0x01U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_POWER_MASK		0x02U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_VOLTAGE_MASK		0x04U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_RECEIVE_CURRENT_MASK		0x08U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_TEMPERATURE_BATTERY_MASK	0x10U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_TEMPERATURE_WLCL_MASK		0x20U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_RFU_MASK			0x40U
#define NDEF_WLC_STATUSINFO_CONTROLBYTE1_CONTROL_BYTE_2_MASK		0x80U

/* ndef_types.h */
typedef enum {
	NDEF_TYPE_ID_NONE = 0,
	NDEF_TYPE_ID_FLAT,
	NDEF_TYPE_ID_EMPTY,
	NDEF_TYPE_ID_RTD_DEVICE_INFO,
	NDEF_TYPE_ID_RTD_TEXT,
	NDEF_TYPE_ID_RTD_URI,
	NDEF_TYPE_ID_RTD_AAR,
	NDEF_TYPE_ID_RTD_WLCCAP,
	NDEF_TYPE_ID_RTD_WLCSTAI,
	NDEF_TYPE_ID_RTD_WLCINFO,
	NDEF_TYPE_ID_RTD_WLCCTL,
	NDEF_TYPE_ID_RTD_WPCWLC,
	NDEF_TYPE_ID_RTD_TNEP_SERVICE_PARAMETER,
	NDEF_TYPE_ID_RTD_TNEP_SERVICE_SELECT,
	NDEF_TYPE_ID_RTD_TNEP_STATUS,
	NDEF_TYPE_ID_MEDIA,
	NDEF_TYPE_ID_BLUETOOTH_BREDR,
	NDEF_TYPE_ID_BLUETOOTH_LE,
	NDEF_TYPE_ID_BLUETOOTH_SECURE_BREDR,
	NDEF_TYPE_ID_BLUETOOTH_SECURE_LE,
	NDEF_TYPE_ID_MEDIA_VCARD,
	NDEF_TYPE_ID_MEDIA_WIFI,
	NDEF_TYPE_ID_COUNT
} ndefTypeId;

struct ndefTypeStruct {
	ndefTypeId id;
	uint32_t (*getPayloadLength)(const ndefType *type);
	const uint8_t *(*getPayloadItem)(const ndefType *type, ndefConstBuffer *item, bool begin);
	ReturnCode (*typeToRecord)(const ndefType *type, ndefRecord *record);
	union {
		ndefTypeRtdWlcCapability wlcCapability;
		ndefTypeRtdWlcStatusInfo wlcStatusInfo;
		ndefTypeRtdWlcListenCtl wlcListenCtl;
		uint8_t reserved;
	} data;
};

/* ndef_record.c */
ReturnCode ndefRecordReset(ndefRecord *record);
uint32_t ndefRecordGetHeaderLength(const ndefRecord *record);
uint32_t ndefRecordGetLength(const ndefRecord *record);
ReturnCode ndefRecordSetType(ndefRecord *record, uint8_t tnf, const ndefConstBuffer8 *bufType);
ReturnCode ndefRecordSetId(ndefRecord *record, const ndefConstBuffer8 *bufId);
ReturnCode ndefRecordSetPayload(ndefRecord *record, const ndefConstBuffer *bufPayload);
ReturnCode ndefRecordGetPayload(const ndefRecord *record, ndefConstBuffer *bufPayload);
ReturnCode ndefRecordDecode(const ndefConstBuffer *bufPayload, ndefRecord *record);
ReturnCode ndefRecordEncodeHeader(const ndefRecord *record, ndefBuffer *bufHeader);
ReturnCode ndefRecordEncode(const ndefRecord *record, ndefBuffer *bufRecord);
uint32_t ndefRecordGetPayloadLength(const ndefRecord *record);
const uint8_t *ndefRecordGetPayloadItem(const ndefRecord *record, ndefConstBuffer *bufPayloadItem,
					bool begin);

/* ndef_message.c */
ReturnCode ndefMessageGetInfo(const ndefMessage *message, ndefMessageInfo *info);
ReturnCode ndefMessageAppend(ndefMessage *message, ndefRecord *record);
ReturnCode ndefMessageEncode(const ndefMessage *message, ndefBuffer *bufPayload);

/* ndef_types.c */
ReturnCode ndefTypeToRecord(const ndefType *type, ndefRecord *record);
ReturnCode ndefRecordSetNdefType(ndefRecord *record, const ndefType *type);

/* ndef_type_wlc.c */
ReturnCode ndefRtdWlcCapabilityInit(ndefType *type, const ndefTypeRtdWlcCapability *param);
ReturnCode ndefRtdWlcCapabilityToRecord(const ndefType *type, ndefRecord *record);
ReturnCode ndefRtdWlcStatusInfoInit(ndefType *type, const ndefTypeRtdWlcStatusInfo *param);
ReturnCode ndefRtdWlcStatusInfoToRecord(const ndefType *type, ndefRecord *record);

/* ---- type 5 tag (lib_NDEF tagtype5_wrapper.c) ---- */

#define NDEF_OK			0
#define NDEF_ERROR		(-1)
#define NDEF_ERROR_MEMORY_TAG	(-2)
#define NDEF_ERROR_NOT_FORMATED	(-5)

#define NFCT5_MAGICNUMBER_E1_CCFILE	0xE1
#define NFCT5_MAGICNUMBER_E2_CCFILE	0xE2
#define NFCT5_EXTENDED_CCFILE		0x00
#define NFCT5_NDEF_MSG_TLV		0x03
#define NFCT5_PROPRIETARY_TLV		0xFD
#define NFCT5_TERMINATOR_TLV		0xFE
#define NFCT5_3_BYTES_L_TLV		0xFF

typedef enum {
	TT5_NO_NDEF = 0,
	TT5_INITIALIZED,
	TT5_READ_WRITE,
	TT5_READ,
} TT5_State;

typedef struct {
	uint8_t MagicNumber;
	uint8_t Version;
	uint8_t MemorySize;
	uint8_t TT5Tag;
	uint8_t rsved1;
	uint8_t rsved2;
	uint16_t ExtMemorySize;
	TT5_State State;
	uint8_t pad_09[3];
	uint32_t NDEF_offset;
} sCCFileInfo;

typedef struct {
	uint8_t Type;
	uint8_t Length;
	uint16_t Length16;
} TT5_TLV_t;

uint32_t BSP_NFCTAG_GetByteSize(void);
int NfcType5_ReadCCFile(uint8_t *pCCBuffer);
int NfcType5_NDEFDetection(void);
int NfcType5_WriteTLV(uint8_t type, uint32_t Length, const uint8_t *pData);
int NfcType5_WriteCCFile(const uint8_t *pCCBuffer);
int NfcType5_TT5Init(void);
int NfcType5_WriteNDEF(uint16_t Length, const uint8_t *pData);
int nfc_write_ndef(const uint8_t *pData, uint32_t Length);

/* ---- WLC listener state (0x20002380, 0x3c bytes) ---- */

struct wlc_listener {
	uint8_t active;		/* 0x00 */
	uint8_t fod_req;	/* 0x01 */
	uint8_t charging;	/* 0x02 */
	uint8_t f03;		/* 0x03 */
	uint8_t f04;		/* 0x04 */
	uint8_t state;		/* 0x05: state machine, 1 = (re)initialise */
	uint8_t f06;
	uint8_t cap_info[10];	/* 0x07: [0] != 0 while charging, [4] / [5] at 0x0b / 0x0c */
	uint8_t stai_info[11];	/* 0x11: [0] present, [2] battery (0x13), [4] (0x15) */
	uint8_t fod_info[3];	/* 0x1c */
	uint8_t f1f[6];		/* 0x1f */
	uint8_t f25;
	uint8_t f26;
	uint8_t f27;
	uint32_t f28;		/* 0x28 */
	uint8_t f2c;
	uint8_t f2d;
	uint8_t f2e[2];		/* 0x2e */
	uint8_t f30[2];		/* 0x30 */
	uint8_t f32[2];
	uint8_t battery;	/* 0x34 */
	uint8_t f35[3];
	uint8_t f38;
	uint8_t f39;
	uint8_t f3a;
	uint8_t f3b;
};

/* NFC field / charge supervision (0x2000840c) */
struct nfc_charge {
	uint8_t f00;
	uint8_t f01;
	uint8_t state;		/* 1 = charging, 2 = no field, 3 = updating, 4 = battery full */
	uint8_t f03[5];
	uint32_t field_mv;	/* adc_nfc_run() * 10 */
	uint8_t pad_0c[0xc];
};

int adc_nfc_init(void);
uint32_t adc_nfc_run(void);
int nfc_i2c_session_open(int enable);
uint32_t FUN_00026f3c(void);
void nfc_configure_gpo(uint32_t gpo_conf);
int wlc_write_ndef_message(const uint8_t *cap_info, const uint8_t *stai_info, const uint8_t *fod_info);
uint8_t FUN_000274a0(void);
int nfc_init(void);
int nfc_charge_status(void);
void nfc_field_voltage_update(void);
uint32_t chargerGetVdcRect(void);
_Bool nfc_field_detected(void);
int nfc_field_check(void);
void wlc_update_field_state(struct wlc_listener *wlc, uint8_t *present);
void nfc_charge_refresh(struct nfc_charge *chg, struct wlc_listener *wlc);
int FUN_00027744(void);
void wlc_listener_process(struct wlc_listener *wlc);
uint32_t nfc_tick_elapsed(void);
void nfc_tick_reset(void);
void wlc_reset_info(struct wlc_listener *wlc);
int nfc_read_field_mv(uint32_t *field_mv);
void nfc_charge_update_state(struct nfc_charge *chg);

#endif /* G1_NFC_WLC_H_ */

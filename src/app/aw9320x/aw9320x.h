#ifndef _AW9320X_H_
#define _AW9320X_H_

#include "aw_type.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "aw9320x_reg.h"
#include "aw_cap_config.h"
#ifdef __cplusplus
extern "C" {
#endif

#define AW9320X_I2C_DEV_ADDR	(0x12)
#define AW9320X_READ_IRQ_STAT   (2)

#define AW9320X_I2C_RETRIES     (3)
#define AW_REG_DATA_LEN         (4)
#define AW_REG_ADDR_LEN         (2)
#define AW_TX_BUF_LEN           (AW_REG_DATA_LEN +  AW_REG_ADDR_LEN)

typedef int32_t (*aw9320x_i2c_w_t)(uint8_t *, uint32_t);
typedef int32_t (*aw9320x_i2c_r_t)(uint8_t *, uint8_t, uint8_t *, uint32_t);
typedef void (*aw9320x_irq_init_t)(void(*)(void));
typedef void (*aw9320x_create_thread_t)(void (*)(void));
typedef void (*aw9320x_set_signal_t)(uint32_t);
typedef uint32_t (*aw9320x_wait_signal_forever_t)(void);
typedef void (*aw9320x_delay_t)(uint32_t);

typedef void (*aw9320x_spp_write_t)(uint8_t *buf, uint16_t length);
typedef void (*aw9320x_spp_init_t)(void (*)(uint8_t *, uint16_t));

struct aw9320x_i2c_func {
	aw9320x_i2c_r_t i2c_r;
	aw9320x_i2c_w_t i2c_w;
};

struct aw9320x_spp_func {
	aw9320x_spp_write_t spp_write;
	aw9320x_spp_init_t spp_init;
};

struct aw9320x_thread_func {
	aw9320x_create_thread_t create_thread;
	aw9320x_set_signal_t set_signal;
	aw9320x_wait_signal_forever_t wait_signal_forever;
};


struct aw9320x_func {
	struct aw9320x_i2c_func i2c_func;
	aw9320x_irq_init_t irq_init;
#ifdef AW_OS_USED
	struct aw9320x_thread_func irq_thread_func;
#endif
	aw9320x_delay_t delay;
#if defined(AW_SPP_USED) && defined(AW_OS_USED)
	struct aw9320x_spp_func spp_func;
	struct aw9320x_thread_func work_thread_func;
#endif
};
#define AW_SPP_SEND_BUF_MAX_SIZE		(255)
#define AW_SPP_PACK_END_LEN			(10)
#define AW_SPP_PACK_END_LEN_V1			(11)
/************************************************/

#define AW_PROT_HEAD_MAX_SZIE			(0x40)
#define AW_VCC_MIN_UV				(1700000)
#define AW_VCC_MAX_UV				(3600000)
#define AW9320X_CHIP_MIN_VOLTAGE		(1600000)
#define AW_RETRIES				(5)
#define AW_POWER_ON_DELAY_MS			(25)
#define REG_MCFG_DELAY_MS			(20)

#define AW_IRQ_DELAY_MS				(100)
#define AW_POWER_ON_SYSFS_DELAY_MS		(5000)

#define REG_RSTNALL_VAL				(0x3c)

#define TRANSFER_SEQ_LEN			(4)
#define TRANSFER_DTS_ADDR_LEN			(4)

#define LEN_BYTE_2				(2)
#define LEN_BYTE_4				(4)
#define INIT_OVER_IRQ				(1)
#define INIT_OVER_IRQ_OK			(1)
#define INIT_OVER_IRQ_ERR			(0)
#define SOFT_RST_OK				(1)
#define UPDATE_FRIMWARE_OK			(1)

#define AW9320X_AWRW_OffSET			(20)
#define AW9320X_AWRW_DATA_WIDTH			(5)
#define AW_DATA_OffSET_2			(2)
#define AW_DATA_OffSET_3			(3)
#define AW_CHANNEL_NUM_MAX			(8)
#define AW_CHANNEL_FOR_GPIO			(6)


#define AW_FINE_ADJUST_STEP0			(165)
#define AW_COARSE_ADJUST_STEP0			(9900)

#define AW9320XCSR_STEP_LEN_UNSIGNED_CAP_ENLARGE (10000)

#define AW_FINE_ADJUST_STEP1			(330)
#define AW_COARSE_ADJUST_STEP1			(19800)
#define AW_CFG_REG_STEP				(0x58)
#define AW_PARA_TIMES				(10000.0)

#define AW_I2C_RW_RETRY_TIME_MIN		(2000)
#define AW_I2C_RW_RETRY_TIME_MAX		(3000)

#define AW_FLASH_DEFAULT_VAL			(0xffffffff)

#define AW_PROT_STOP_WAIT_IRQ_CYCLES		(100)
#define AW_REG_UPDATA_DIS_MASK			(0x00ffffff)
#define AW_AFECFG3_CVMULTUALMOD			(11)
#define AW_AFECFG3_CVOFF2X			(10)
#define AW_CH_NUM_MAX				(8)
#define AW_REMOVE_FLOAT_COEF			(1024)

#define AW_SCANCTR_AOTEN_MASK			(~(0xff << 8))
#define AW_SCANCTR_AOTEN_EN			(0xff << 8)

#define AW_REG_MCFG				(0x4444)
#define AW_REG_ACESS_EN				(0xff20)
#define AW_REG_BOOTLOADER_ACTIVER		(0x4748)
#define AW_REG_MCFG				(0x4444)
#define AW_REG_RSTNALL				(0xff18)
#define AW_CPU_HALT				(0x00010000)
#define AW_ACC_PERI				(0x3c00ffff)
#define AWDIS_HARD_BT_MODE			(0x00000000)
#define AW_CPU_RUN				(0x00000000)
#define AW_RSTNALL				(0x0000003c)

#define REG_IRQSRC_BUTTON_BIT			(10)
#define REG_IRQSRC_SLIDE_BIT			(9)
#define REG_IRQSRC_wear_BIT			(8)
#define REG_IRQSRC_OUT_EAR_BIT			(7)
#define REG_IRQSRC_PROX_BIT			(1)
#define REG_IRQSRC_EXIT_PROX_BIT		(2)
#define REG_IRQSRC_TOUCH_BIT			(3)
#define REG_IRQSRC_EXIT_TOUCH_BIT		(4)
#define REG_IRQSRC_INIT_BIT			(0)

#define REG_SLDDATA1_LONG_PRESS_LEAVE_BIT	(29)
#define REG_SLDDATA1_SUPER_PRESS_BIT		(28)
#define REG_SLDDATA1_LONG_PRESS_BIT		(27)
#define REG_SLDDATA1_TREBLE_CLICK_BIT		(26)
#define REG_SLDDATA1_DOUBLE_CLICK_BIT		(25)
#define REG_SLDDATA1_TSINGED_CLICK_BIT		(24)
#define REG_SLDDATA1_SLIDE_BIT			(17)
#define REG_SLDDATA1_NORMDIRECTIONST_BIT	(19)
#define REG_SLDDATA1_NORMSPEEDST_BIT		(18)
#define REG_SLDDATA1_MOVEDIRECTION_BIT		(16)

#define REG_CMD_SEND_CLEND_CMD			(0xc)

/********aw9320x_reg_mode_update start********/

#define AW_CHECK_EN_VAL			(0x20222022)
#define AW_FW_CHECKSUM_EN_ADDR		(0x10003FF8)

#define AW_BT_CHECK_LEN			(0x7f8)
#define AW_BT_CHECK_EN_ADDR		(0x07F8)
#define AW_BT_CHECK_CODE_ADDR		(0x07FC)

#define AW_FW_CHECK_LEN			(0x37f8)
#define AW_FW_CHECK_EN_ADDR		(0x3FF8)
#define AW_FW_CHECK_CODE_ADDR		(0x3FFC)

#define AW_BT_TR_START_ADDR		(0x0000)

#define AW_BT_CHECK_START_ADDR		(0x0000)

#define AW_FW_TR_START_ADDR		(0x2000)

#define AW_FW_CHECK_START_ADDR		(0x0800)

#define SOCTOR_SIZE			(128)
#define AW_CACHE_LEN			(0x1000)

enum AW9320X_UPDATE_MODE {
	BOOT_UPDATE,
	FRIMWARE_UPDATE,
};

struct check_info {
	uint32_t check_len;
	uint32_t flash_check_start_addr;
	uint32_t w_check_en_addr;
	uint32_t w_check_code_addr;
};

struct aw_update_common {
	uint8_t update_flag;
	const uint8_t *w_bin_offset;
	uint32_t update_data_len;
	uint32_t flash_tr_start_addr;
	struct check_info *check_info;
};

/********aw9320x_reg_mode_update END********/

/*****************aw_type start******************/
#define AW_ABS(x) (((x) > 0) ? (x) : (-(x)))

#define AW_GET_32_DATA(w, x, y, z)              ((unsigned int)(((w) << 24) | ((x) << 16) | ((y) << 8) | (z)))
#define AW_GET_16_DATA(a, b) 	                (((uint32_t)(a) << (8)) | ((uint32_t)(b) << (0)))

#define AW_REVERSEBYTERS_U16(value) ((((value) & (0x00FF)) << (8)) | (((value) & (0xFF00)) >> (8)))
#define AW_REVERSEBYTERS_U32(value) ((((value) & (0x000000FF)) << (24)) | ((((value) & (0x0000FF00))) << (8)) | (((value) & (0x00FF0000)) >> (8)) | (((value) & (0xFF000000)) >> (24)))
/*****************aw_type end********************/

/************************************************/
struct aw_fw_load_info{
	uint32_t fw_len;
	const uint8_t *p_fw_data;
	uint32_t app_version;
	uint8_t load_fw_mode;
};

#define PROT_SEND_ADDR	(0x0800)
#define	SEND_ADDR_LEN	(2)

#define AW_PACK_FIXED_SIZE 			(12)
#define AW_ADDR_SIZE 				(2)

//hecksum_en host->slave
#define AW_HEADER_VAL				(0x02)

#define REG_H2C_TRIG_PARSE_CMD			(0x15)

#define AW_WAIT_IRQ_CYCLES				(10)
#define AW_WAIT_ENTER_SLEEP_MODE		(100)
#define AW_WAIT_ENTER_TR_MODE			(100)
#define AW_ACK_ADDR				(0x1800)

#define TRANSFER_SEQ_LEN			(4)
#define TRANSFER_DTS_ADDR_LEN			(4)

#define AW_BT_CHECK_SUM_ADDR			(0x07fc)

#define AW_START_CMD_ACK_STATUS			(2)
#define AW_START_CMD_ACK_ADDR_LEN		(2)

#define P_AW_START_CMD_SEND_VALUE		(NULL)
#define AW_START_CMD_SEND_VALUE_LEN		(0)

#define P_AW_ERASE_CHIP_CMD_SEND_VALUE		(NULL)
#define AW_ERASE_CHIP_CMD_SEND_VALUE_LEN	(0)

#define P_AW_RESTORE_CMD_SEND_VALUE		(NULL)
#define AW_RESTORE_CMD_SEND_VALUE_LEN		(0)

#define AW_EN_TR_CHECK_VALUE_LEN		(16)

#define	AW_FLASH_ERASE_CHIO_CMD_ACK_LEN		(4)
#define AW_FLASH_HEAD_ADDR			(0x10002000)
#define AW_NVR_ADDR					(0x10004000)

#define AW_REG_STEP				(0x58)

#define AW_REG_WST_MODE_SLEEP			(0x03000000)

#define AW_COMPARE_VERSION_LOAD	(0)
#define AW_DIRECT_LOAD			(1)
#define AW9320X_SRAM_ERROR_CODE			(0x1c00)
enum AW9320X_FLASH_ADDR {
	FLASH_ADDR_BOOT,
	FLASH_ADDR_FW,
};

enum AW9320X_CMP_VAL {
	AW9320X_VER_EQUAL,
	AW9320X_VER_NOT_EQUAL,
};

enum AW_MODULE {
	UPDATE_MODULE = 0x01,
	FLASH_MODULE,
	QUERY_MODULE,
};

enum AW_UPDATE_COMMAND {
	UPDATE_START_CMD = 0X01,
	UPDATE_TRANSFER_CMD,
	UPDATE_STOP_CMD,
	UPDATE_RESTORE_FLASHBT_CMD,
};

enum AW_UPDATE_COMMAND_ACK {
	UPDATE_START_CMD_ACK = 0X01,
	UPDATE_RANSFER_CMD_ACK,
	UPDATE_STOP_CMD_ACK,
	UPDATE_RESTORE_FLASHBT_CMD_ACK,
};

enum AW_FLASH_COMMAND {
	FLASH_ERASE_CHIP_CMD = 0X01,
	FLASH_ERASE_SECTOR_CMD,
};

enum AW_FLASH_COMMAND_ACK {
	FLASH_ERASE_CHIP_CMD_ACK = 0X01,
	FLASH_ERASE_SECTOR_CMD_ACK,
};

enum AW_QUERY_COMMAND {
	QUERY_BT_VER_CMD = 0X01,
	QUERY_BT_DATE_CMD,
	QUERY_ERR_CODE_CMD,
	QUERY_PST_CMD,
	QUERY_CACHE_CMD,
};

enum AW_QUERY_COMMAND_ACK {
	QUERY_BT_VER_CMD_ACK = 0X01,
	QUERY_BT_DATE_CMD_ACK,
	QUERY_ERR_CODE_CMD_ACK,
	QUERY_PST_CMD_ACK,
	QUERY_CACHE_CMD_ACK,
};

struct aw_soc_protocol {
	uint16_t header;
	uint16_t size;
	uint32_t checksum;
	uint8_t module;
	uint8_t command;
	uint16_t length;
	uint8_t value[0];
};
/************************************************/

#define AW9320X_OFFSET_MAX						(1000)
#define AW9320X_OFFSET_MIN						(100)
#define AW9320X_CAP_MIN							(-6.5f)
#define AW9320X_CAP_MAX							(6.5f)
#define AW9320X_DIFF_PROX_MIN					(0)
#define AW9320X_DIFF_PROX_MAX					(1000000)

enum aw9320x_err_code {
	AW_OK,
	AW_ERR,
	AW_ERR_IRQ_INIT,
	AW_PROT_UPDATE_ERR,
	AW_ERR_CHIPID,
};

enum aw_i2c_flags {
	I2C_WR,
	I2C_RD,
};

enum AW9320X_CHIP_ID_VALUE {
	AW93203CSR_CHIP_ID = 0x20223203,
	AW93205DNR_CHIP_ID = 0x20223205,
	AW93208CSR_CHIP_ID = 0x20223207,
	AW93208_CHIP_ID    = 0x20226208,
};

enum recover_flag {
	REG_UPDATE_RECOVER,
	INIT_RECOVER,
};

enum AW9320X_OPERAION_MODE {
	AW9320X_ACTIVE_MODE = 1,
	AW9320X_SLEEP_MODE,
	AW9320X_DEEPSLEEP_MODE,
	AW9320X_MODE_ERR,
};

enum AW9320X_UPDATE_FW_MODE {
	AGREEMENT_UPDATE_FW,
	REG_UPDATE_FW,
};

enum AW9320X_HOST_IRQ_STAT {
	IRQ_ENABLE,
	IRQ_DISABLE,
};

struct aw_channels_info {
	uint8_t used;
	uint32_t last_channel_info;
	struct input_dev *input;
	uint8_t name[20];
};

struct aw_awrw_info {
	uint8_t rw_flag;
	uint8_t addr_len;
	uint8_t data_len;
	uint8_t reg_num;
	uint32_t i2c_tranfar_data_len;
	uint8_t *p_i2c_tranfar_data;
};

enum AW_UPDATE_FW_STATE {
	SEND_UPDTAE_CMD,
	SEND_START_CMD,
	SEND_ERASE_SECTOR_CMD,
	SEND_UPDATE_FW_CMD,
	SEND_UPDATE_CHECK_CODE_CMD,
	SEND_RESTORE_CMD,
	SEND_STOP_CMD,
};

enum AW_PROT_UPDATE_FW_DELAY_TIME{
	SEND_UPDTAE_CMD_DELAY_MS = 1,
	SEND_START_CMD_DELAY_MS = 3,
	SEND_ERASE_SECTOR_CMD_DELAY_MS = 6,
	SEND_UPDATE_FW_CMD_DELAY_MS = 100,
	SEND_UPDATE_CHECK_CODE_CMD_DELAY_MS = 1,
	SEND_RESTORE_CMD_DELAY_MS = 27,
	SEND_STOP_CMD_DELAY_MS = 25,
};

enum AW_PROT_RECV_LEN {
	SEND_START_CMD_RECV_LEN = 8,
	SEND_ERASE_CHIP_CMD_RECV_LEN = 4,
	SEND_UPDATE_FW_CMD_RECV_LEN = 8,
	SEND_UPDATE_CHECK_CODE_CMD_RECV_LEN = 4,
	SEND_RESTORE_CMD_RECV_LEN = 4,
};

#define AW_EN                                   (0x01)
#define SLIDE_EN                                (1)
#define LINGER_SLIDER                           (0)
#define SLIDER_REUSED                           (1)
#define NORMAL_SLIDE                            (0)
#define SLIDE_NUM                               (3)
#define PACKS_IN_ONE_COMM			(2)
#define AW9320X_DATA_CLEAR                      (0)
#define AW9320X_CHANNEL_MAX			(5)
#define AW9320X_CPU_WORK_MASK			(1)
#define AW9320X_ALGO_RUN_INTERVAL		(20)
#define AW9320X_ALGO_RUN                        (1)
#define AW9320X_SPP_CURVE_RUN                   (2)
#define AW9320X_READ_IRQ_STAT                   (2)
#define AW9320X_FAR_AWAY_APPORACH_ENABLE        (0x00000006)
#define AW9320X_FAR_AWAY_APPORACH_DISABLE       (0x00000000)
#define AW9320X_POLLING_MAX_TIME                (500)
#define AW_CHIP_CAP                             (3)


#define AW_CAP_IRQ_EVENT_REPORT_LEN				(102)
#define AW_CAP_IRQ_CURVEL_INDEX					(6)
#define AW_REMOVE_DECIMAL_BITS					(10)

#define AW_SAR_REG_LEN						(16) //reg len : 16bits
#define AW_SAR_DATA_LEN						(32) //data len : 32bits
#define AW_CURVE_DATA_LEN					(48) //curve len : 32bits
#define AW_COMM_CYCLE						(90)
#define DATA_MAX_LEN						(512)
#define AW_SPP_REG_MAX_NUM					(10)
#define SAR_REG_DATA_LEN					(4)
#define SAR_APP_CURVE_CNT					(4)
#define AW_SAR_STATUS_LEN					(12)
#define VIRTUAL_REG_NUM						(10) /*single click,double click,trip click,long press,super press,lift,right,wear,up,down,backup1,backup2*/
#define VIRTUAL_REG_BUF_LEN					(VIRTUAL_REG_NUM * SAR_REG_DATA_LEN) //10 word
#define AW_POS_DATA_LEN						4
#define AW_DISTANCE_DATA_LEN				4
#define AW_SAR_SPP_ONE_PACK_LEN					(SAR_APP_CURVE_CNT * AW_CURVE_DATA_LEN + VIRTUAL_REG_BUF_LEN + AW_SAR_STATUS_LEN + AW_POS_DATA_LEN + AW_DISTANCE_DATA_LEN)
#define AW9320X_REDUNDANCY_DATA_LEN				(10)
#define AW9320X_REDUNDANCY_DATA_LEN_V1				(11)

/*The offset address of the data in the app protocol start*/
#define PROTOCOL_RAWDATA_OFFSET					(0)
#define PROTOCOL_VALIDDATA_OFFSET				(48)
#define PROTOCOL_BASELINEDATA_OFFSET				(96)
#define PROTOCOL_DIFFDATA_OFFSET				(144)
#define PROTOCOL_VIRTUAL_OFFSET					(192)
#define PROTOCOL_EVENT_OFFSET					(232)
/*The offset address of the data in the app protocol end*/

#define AW_GET_REG_ACTIVE_VAL					(0x1000000)
#define AW_GET_REG_SLEEP_VAL					(0x3000000)
#define AW_GET_REG_DEEPSLEEP_VAL				(0x0)
#define AW_MAX_SCAN_PERRIOD					(50)

#define AW_FLASH_ERASE_SECTOR_START_ADDR	(0x10002000)
#define AW_SECTOR_SIZE				(128)
#define AW_ERASE_SECTOR_CNT			(64 - 1)
#define AW9320X_CURVER_LEN			(12)

enum aw9320x_bit {
	AW_BIT0,
	AW_BIT1,
	AW_BIT2,
	AW_BIT3,
	AW_BIT7 = 7,
	AW_BIT8 = 8,
	AW_BIT16 = 16,
	AW_BIT24 = 24,
	AW_BIT28 = 28,
	AW_BIT32 = 32,
};

enum {
	AW_APP_CMD_GET_DEVICE_INFO = 0x00,
	AW_APP_CMD_GET_CURVE_DATA = 0x01,
	AW_APP_CMD_READ_REG = 0x02,
	AW_APP_CMD_WRITE_REG = 0x03,
	AW_APP_CMD_GET_ALGO_PARA = 0x04,
	AW_APP_CMD_SET_ALGO_PARA = 0x05,
	AW_APP_CMD_IRQ_STATE_INPUT = 0x06,
	AW_APP_CMD_IRQ_EVENT_INPUT = 0x07,

	AW_APP_CMD_OFFSET_CALI = 0xa0,
	AW_APP_CMD_DIFF_TO_AIR = 0xa1,
	AW_APP_CMD_DIFF_APPROACH = 0xa2,
	AW_APP_CMD_SHORT_CIRCUIT = 0xa3,
	AW_APP_CMD_SET_DIFF_TH = 0xa4,
};

typedef enum {
	APK_VALID_DATA_HEADER = 3,
	APK_VALID_DATA_HEADER_V1 = 4,
	APK_HEADER = 0x3A,
	OFFSET = 0x82,
	NOISE,
	SIGNAL_RAW_0,
	SIGNAL_RAW_1,
	VERIFY_0,
	VERIFY_1,
	DYNAMIC_CALI = 0x8C,
	APK_END0 = 0x0D,
	APK_END1 = 0x0A,
} CALI_FLAG_T;

enum aw9320x_word {
	AW_BIT_0_1_EN = 0x03,
	AW_ONE_BYTE_1 = 0xff,
	AW_BIT_10_EN = 0x00000400,
	AW_BIT_11_EN = 0x00000800,
	AW_BIT_12_EN = 0x00001000,
	AW_HALF_WORD_1 = 0xffff,
	AW_THREE_BYTE_1 = 0xffffff,
	AW_ONE_WORD_1 = 0xffffffff,
};

typedef struct aw_app_prf {
	uint8_t cmd;
	uint8_t dat[DATA_MAX_LEN];
	uint8_t len;
} aw_app_prf_t;

struct aw_bt_and_fw_info {
	uint8_t update_flag;
	uint32_t fw_bin_version;
	uint32_t fw_version;
	uint32_t fw_checksum;

	uint32_t bt_version;
	uint32_t bt_date;
	uint32_t bt_checksum;
	uint32_t bt_bin_version;
};

#define SLIDE_STORE_BIT		(7)
struct cap_event_status {
	uint8_t single_click;
	uint8_t double_click;
	uint8_t triple_click;
	uint8_t long_press;
	uint8_t super_long_press;
	uint8_t left_wareds;
	uint8_t right_wareds;
	uint8_t wear;
	uint8_t up_wareds;
	uint8_t down_wareds;
	uint8_t event_backup1;
	uint8_t event_backup2;

	uint8_t irq_trigger;
	uint8_t long_press_leave;
	uint8_t prox_stat_th_0;
	uint8_t prox_stat_th_1;
	int32_t slide_distance;
};

enum AW93312_EVENT_LIST {
	SINGLE_CLICK = 0,
	DOUBLE_CLICK,
	TRIPLE_CLICK,
	LONG_PRESS,
	SUPER_LONG_PRESS,
	LEFT_WAREDS,
	RIGHT_WAREDS,
	WEAR,
	UP_WAREDS,
	DOWN_WAREDS,
	EVENT_BACKUP1,
	EVENT_BACKUP2,
};


enum aw9320x_irq_porx_position {
	TRIGGER_FAR,
	TRIGGER_TH0,
	TRIGGER_TH1 = 0x03,
};

int32_t aw9320x_init(struct aw9320x_func *hw_fun);
void aw9320x_mode_operation_set(enum AW9320X_OPERAION_MODE mode);
enum AW9320X_OPERAION_MODE aw9320x_mode_operation_get(void);
void aw9320x_aot_set(uint8_t cali_flag);
void aw9320x_diff_get(int32_t *p_diff);
int32_t aw9320x_fw_update(uint8_t load_fw_mode);
#ifndef AW_MUL_CAP_FLAG
void aw9320x_self_cap_parasitic_data_get(uint32_t *reg_data_cfg);
#else
void aw9320x_mul_cap_parasitic_data_get(uint32_t *parasitic_data);
#endif
#ifdef __cplusplus
}
#endif
#endif

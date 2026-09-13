/* Private declarations of proxy_thread.c (panel_display module) */
#ifndef PD_PROXY_THREAD_H_
#define PD_PROXY_THREAD_H_

#include <stdint.h>
#include <zephyr/kernel.h>

struct GlassesState;
struct GlassesState *get_dashboard_state(void);

/* message of the proxy queue (0x18 bytes) */
enum proxy_msg_type {
	PROXY_MSG_RESPONSE_LOAD = 0,      /* send_response_data_to_msgqueue */
	PROXY_MSG_RESPONSE_SEND = 1,      /* send_response_data_to_ble */
	PROXY_MSG_AUDIO_FILE = 2,         /* sendAudioStreamFileToApp */
	PROXY_MSG_AUDIO_INFO = 3,         /* requestAudioInfoToApp */
	PROXY_MSG_POWER = 4,              /* SendPowerInfoToSlave */
	PROXY_MSG_LANGUAGE = 5,           /* SendSystemLanguageInfoToSlave */
	PROXY_MSG_STARTUP_MODE = 6,       /* SendDashBoardStartupModeInfoToSlave */
	PROXY_MSG_DOUBLE_CLICK = 7,       /* SlaveDoubleClickEventInject */
	PROXY_MSG_DOUBLE_TAP = 8,         /* SendDoubleTapCustomizeToSlave */
	PROXY_MSG_LONGPRESS_TAP = 9,      /* SendLongpressTapCustomizeToSlave */
};

#define PROXY_MSG_DATA_MAX 20

struct proxy_msg {
	uint8_t type;
	uint8_t pad;
	uint16_t len;
	uint8_t data[PROXY_MSG_DATA_MAX];
};

/* QuickNote voice block table at ext flash 0x400000 (see audio_stream.c) */
struct proxy_voice_block {
	uint32_t state;              /* 2 = recorded */
	uint32_t start_addr;
	uint32_t end_addr;
	int32_t timestamp;
	uint32_t crc32;
} __packed;

struct proxy_voice_manager {
	uint32_t magic;
	uint32_t reserved;
	struct proxy_voice_block blocks[4];
} __packed;

/* partial dashboard_ts_context */
struct proxy_dashboard_ts {
	uint32_t ts;                 /* 0x00 */
	uint8_t pad_04[0x72 - 4];
	uint8_t f_72;                /* 0x72 */
};

/* partial view of GlassesState */
struct proxy_gs {
	uint8_t is_master;           /* 0x000 1 master, 2 slave */
	uint8_t work_mode;           /* 0x001 1 / 8: busy */
	uint8_t pad_002[0xd5 - 0x002];
	uint8_t dashboard_mode;      /* 0x0d5 */
	uint8_t pad_0d6[0x788 - 0x0d6];
	int (*ble_send)(const uint8_t *data, uint16_t len); /* 0x788 ble_context + 0xc */
	uint8_t pad_78c[0xff0 - 0x78c];
	struct proxy_dashboard_ts *dashboard_ts;            /* 0xff0 */
	uint8_t pad_ff4[0x1044 - 0xff4];
	int (*flash_read)(struct GlassesState *gs, uint32_t addr, void *buf, uint32_t len); /* 0x1044 */
	uint8_t pad_1048[0x1070 - 0x1048];
	uint16_t module_mask;        /* 0x1070 bit 7: BLE connected to the app */
	uint8_t pad_1072[0x1244 - 0x1072];
	uint8_t f_1244;              /* 0x1244 */
	uint8_t f_1245;              /* 0x1245 */
} __aligned(8);
#define PROXY_GS() ((struct proxy_gs *)get_dashboard_state())

/* other modules */
int sync_to_slave(struct GlassesState *state, int cmd, void *data, size_t len);
int display_powerEvent(int on);
int upgradeAppLanguageInfoToFlash(uint8_t lang);
int upgradeDashboardStartupModeInfoToFlash(uint8_t mode);
int upgradeDoubleTapCustomizeToFlash(uint32_t mode);
int upgradeLongpressTapCustomizeToFlash(uint32_t mode);
void FUN_00030db0(int block);
void FUN_00030dc8(void);
void FUN_0004d4f8(int64_t *ts);
extern atomic_t DAT_20008518;

/* this file */
int start_proxy_thread_handler(void *gs);
int send_response_data_to_msgqueue(const void *data, uint32_t len);
int send_response_data_to_ble(void);
int sendAudioStreamFileToApp(uint8_t cmd, uint8_t block);
void proxy_thread_handler(void *p1, void *p2, void *p3);
int requestAudioInfoToApp(uint8_t cmd);
int SendPowerInfoToSlave(uint8_t on);
int SendSystemLanguageInfoToSlave(uint8_t lang);
int SendDashBoardStartupModeInfoToSlave(uint8_t mode);
int SlaveDoubleClickEventInject(void);
int SendDoubleTapCustomizeToSlave(uint8_t mode);
int SendLongpressTapCustomizeToSlave(uint8_t mode);

#endif

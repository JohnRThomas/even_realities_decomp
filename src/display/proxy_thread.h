/* Private declarations of proxy_thread.c (panel_display module) */
#ifndef PD_PROXY_THREAD_H_
#define PD_PROXY_THREAD_H_

#include <stdint.h>
#include <zephyr/kernel.h>
#include <glasses_state.h>

struct GlassesState;

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

/* proxy_thread.c */
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

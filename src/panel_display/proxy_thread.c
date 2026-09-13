/*
 * Proxy thread: queues BLE responses, streams QuickNote audio files to the
 * app and forwards settings / events to the slave arm.
 * Reconstructed from the v1.63 app core.
 */
#include <stdint.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/util.h>

#include "g1_log.h"
#include "proxy_thread.h"

#define FLASH_DEV DEVICE_DT_GET(DT_NODELABEL(mx25r64))

#define VOICE_MANAGER_ADDR  0x400000
#define VOICE_MANAGER_MAGIC 0x5aa5aa5a
#define VOICE_BLOCK_NUM     4
#define AUDIO_CHUNK_SIZE    0xbe
#define AUDIO_PKT_HDR_SIZE  10
#define AUDIO_RETRY_COUNT   3
#define SYNC_RETRY_COUNT    3
#define SYNC_TIMEOUT        5000

#define PROXY_STACK_SIZE 0x800
#define PROXY_PRIORITY   (-12)

K_MSGQ_DEFINE(proxy_msgq, sizeof(struct proxy_msg), 16, 4);

static K_THREAD_STACK_DEFINE(proxy_stack, PROXY_STACK_SIZE);
static struct k_thread proxy_thread;

k_tid_t proxy_tid;                         /* 0x2000aa70 */
static volatile int audio_file_start;          /* 0x2000aa6c */
static volatile int audio_file_end;            /* 0x2000aa68 */
static volatile int audio_pkt_total;           /* 0x2000aa64 */
static volatile int audio_file_size;           /* 0x2000aa60 */
static volatile int audio_pkt_index;           /* 0x2000aa5c */
static volatile int audio_file_sent;           /* 0x2000aa58 */
static uint8_t response_buf[PROXY_MSG_DATA_MAX];    /* 0x2001e1a6 */
static volatile uint8_t response_pending;                    /* 0x2001e1a5 */
static uint8_t audio_file_buf[0xe6];                /* 0x2001e0bf */
static volatile uint8_t audio_block_idx;                     /* 0x2001e0be */
static volatile uint8_t audio_response_packet_buf[0xe6];     /* 0x2001dfd8 */
static volatile uint8_t audio_pkt_seq;                       /* 0x2001dfd7 */
static volatile uint8_t audio_sending;                       /* 0x2001dfd6 */
static volatile uint16_t response_len;                       /* 0x200108f2 */

#define VOICE_MGR ((struct proxy_voice_manager *)audio_file_buf)

int start_proxy_thread_handler(void *gs)
{
	proxy_tid = k_thread_create(&proxy_thread, proxy_stack, PROXY_STACK_SIZE,
				    proxy_thread_handler, gs, NULL, NULL, PROXY_PRIORITY, 0,
				    K_NO_WAIT);
	return proxy_tid == NULL ? -1 : 0;
}

void proxy_thread_handler(void *p1, void *p2, void *p3)
{
	struct proxy_gs *gs = p1;
	struct proxy_msg msg;
	int ret;
	int retry;
	int n;
	uint8_t buf[8];

	memset(&msg, 0, sizeof(msg));
	while (1) {
		if (gs->work_mode == 1 || gs->work_mode == 8) {
			k_sleep(K_MSEC(5000));
			continue;
		}
		if (!(gs->module_mask & BIT(7))) {
			k_sleep(K_MSEC(1000));
		} else {
		memset(&msg, 0, sizeof(msg));
		ret = k_msgq_get(&proxy_msgq, &msg, K_FOREVER);
		if (ret != 0) {
			continue;
		}

		switch (msg.type) {
		case PROXY_MSG_RESPONSE_LOAD:
			memset(response_buf, 0, sizeof(response_buf));
			n = MIN(msg.len, PROXY_MSG_DATA_MAX);
			memcpy(response_buf, msg.data, n);
			response_len = n;
			response_pending = 1;
			break;

		case PROXY_MSG_RESPONSE_SEND:
			if (response_pending) {
				ret = gs->ble_send(response_buf, response_len);
				if (ret < 0) {
					G1_LOG_WRN("Failed to send data over BLE connection: ret = %d \n",
						   ret);
				}
				*(int64_t *)buf = 0;
				FUN_0004d4f8((int64_t *)buf);
				response_pending = 0;
				response_len = 0;
			}
			break;

		case PROXY_MSG_AUDIO_FILE:
			if (msg.data[0] == 0) {
				audio_block_idx = msg.data[1] - 1;
				if (!device_is_ready(FLASH_DEV)) {
					G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
					break;
				}
				memset(audio_file_buf, 0, sizeof(audio_file_buf));
				if (PROXY_GS()->flash_read(get_dashboard_state(), VOICE_MANAGER_ADDR,
							   audio_file_buf, sizeof(audio_file_buf))) {
					G1_LOG_ERR(" form address [%d] read data failed.\n\n",
						   VOICE_MANAGER_ADDR);
					break;
				}
				if (VOICE_MGR->magic == VOICE_MANAGER_MAGIC &&
				    VOICE_MGR->blocks[audio_block_idx].state == 2) {
					/* the block is read through a volatile pointer: its address stays
					 * in a register and start_addr is loaded from it (+4) */
					volatile struct proxy_voice_block *blk = &VOICE_MGR->blocks[audio_block_idx];

					audio_file_start = blk->start_addr;
					audio_file_end = VOICE_MGR->blocks[audio_block_idx].end_addr;
				}
				memset(audio_file_buf, 0, sizeof(audio_file_buf));
				if (PROXY_GS()->flash_read(get_dashboard_state(), audio_file_start,
							   audio_file_buf, AUDIO_CHUNK_SIZE)) {
					G1_LOG_ERR(" form address [%d] read data failed.\n\n",
						   VOICE_MANAGER_ADDR);
					break;
				}
				audio_pkt_total = (audio_file_end - audio_file_start) / AUDIO_CHUNK_SIZE;
				if ((audio_file_end - audio_file_start) % AUDIO_CHUNK_SIZE) {
					audio_pkt_total++;
				}
				audio_file_size = audio_file_end - audio_file_start;
				audio_pkt_seq = 0;
				audio_pkt_index = 0;
				audio_file_sent = 0;
				memset((void *)audio_response_packet_buf, 0, sizeof(audio_response_packet_buf));
				audio_response_packet_buf[0] = 0x1e;
				audio_response_packet_buf[2] = 0;
				audio_response_packet_buf[3] = audio_pkt_seq;
				audio_pkt_seq++;
				audio_response_packet_buf[4] = 2;
				audio_response_packet_buf[5] = audio_pkt_total;
				audio_response_packet_buf[6] = audio_pkt_total >> 8;
				audio_pkt_index++;
				audio_response_packet_buf[7] = audio_pkt_index;
				audio_response_packet_buf[8] = audio_pkt_index >> 8;
				audio_response_packet_buf[9] = audio_block_idx + 1;
				n = MIN(audio_file_size - audio_file_sent, AUDIO_CHUNK_SIZE);
				memcpy((void *)&audio_response_packet_buf[AUDIO_PKT_HDR_SIZE], audio_file_buf, n);
				audio_response_packet_buf[1] = n + AUDIO_PKT_HDR_SIZE;
				retry = AUDIO_RETRY_COUNT;
				for (;;) {
					ret = gs->ble_send((const uint8_t *)audio_response_packet_buf,
							   audio_response_packet_buf[1]);
					if (ret < 0) {
						G1_LOG_WRN("Failed to send data over BLE connection: ret = %d \n",
							   ret);
						if (--retry != 0) {
							G1_LOG_WRN("retry send audio data first packet\n");
						} else {
							G1_LOG_WRN("send audio stream more than retry count,break audio send process....\n");
							goto next;
						}
					} else {
						audio_sending = 1;
						audio_file_sent += n;
						FUN_00030db0(audio_block_idx);
						sendAudioStreamFileToApp(1, 0);
						break;
					}
				}
			} else if (msg.data[0] == 1) {
				if (!audio_sending) {
					FUN_00030dc8();
					break;
				}
				if (audio_file_sent >= audio_file_size) {
					audio_sending = 0;
					audio_pkt_total = 0;
					audio_file_size = 0;
					audio_file_sent = 0;
					audio_pkt_seq = 0;
					audio_pkt_index = 0;
					audio_file_end = 0;
					audio_file_start = 0;
					FUN_00030dc8();
					G1_LOG_ERR("app request over size data ,break,last packet timestamp = %d\n",
						   PROXY_GS()->dashboard_ts->ts);
				} else {
					memset((void *)audio_response_packet_buf, 0, sizeof(audio_response_packet_buf));
					/* the sizes are volatile: each test re-reads them; if neither test holds,
					 * ret keeps the k_msgq_get() result (it stays in r4, n is int like ret) */
					if (audio_file_size - audio_file_sent > AUDIO_CHUNK_SIZE - 1) {
						ret = AUDIO_CHUNK_SIZE;
					} else if (audio_file_size - audio_file_sent <= AUDIO_CHUNK_SIZE - 1) {
						ret = audio_file_size - audio_file_sent;
					}
					n = ret;
					audio_response_packet_buf[0] = 0x1e;
					audio_response_packet_buf[1] = n + AUDIO_PKT_HDR_SIZE;
					audio_response_packet_buf[2] = 0;
					audio_response_packet_buf[3] = audio_pkt_seq;
					audio_pkt_seq++;
					audio_response_packet_buf[4] = 2;
					audio_response_packet_buf[5] = audio_pkt_total;
					audio_response_packet_buf[6] = audio_pkt_total >> 8;
					audio_pkt_index++;
					audio_response_packet_buf[7] = audio_pkt_index;
					audio_response_packet_buf[8] = audio_pkt_index >> 8;
					audio_response_packet_buf[9] = audio_block_idx + 1;
					memset(audio_file_buf, 0, sizeof(audio_file_buf));
					if (PROXY_GS()->flash_read(get_dashboard_state(),
								   audio_file_start + audio_file_sent,
								   audio_file_buf, n)) {
						G1_LOG_ERR(" form address [%d] read data failed.\n\n",
							   VOICE_MANAGER_ADDR);
						audio_sending = 0;
						FUN_00030dc8();
						break;
					}
					memcpy((void *)&audio_response_packet_buf[AUDIO_PKT_HDR_SIZE],
					       audio_file_buf, n);
					retry = AUDIO_RETRY_COUNT;
					for (;;) {
						ret = gs->ble_send((const uint8_t *)audio_response_packet_buf,
								   audio_response_packet_buf[1]);
						if (ret < 0) {
							G1_LOG_WRN("Failed to send data over BLE connection: ret = %d \n",
								   ret);
							if (--retry != 0) {
								G1_LOG_WRN("retry send audio data\n");
							} else {
								G1_LOG_WRN("send audio stream more than retry count,break audio send process....\n");
								audio_sending = 0;
								FUN_00030dc8();
								goto next;
							}
						} else {
							audio_file_sent += n;
							break;
						}
					}
					sendAudioStreamFileToApp(1, 0);
					break;
				}
			}
			break;

		case PROXY_MSG_AUDIO_INFO: {
			uint8_t *p;
			int cnt = 0;

			if (!device_is_ready(FLASH_DEV)) {
				G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
				break;
			}
			memset(audio_file_buf, 0, sizeof(audio_file_buf));
			if (PROXY_GS()->flash_read(get_dashboard_state(), VOICE_MANAGER_ADDR,
						   audio_file_buf, sizeof(audio_file_buf))) {
				G1_LOG_ERR(" form address [%d] read data failed.\n\n", VOICE_MANAGER_ADDR);
				break;
			}
			memset((void *)audio_response_packet_buf, 0, sizeof(audio_response_packet_buf));
			if (msg.data[0] == 0) {
				audio_response_packet_buf[0] = 0x1e;
			} else {
				audio_response_packet_buf[0] = 0x21;
			}
			audio_response_packet_buf[2] = 0;
			audio_response_packet_buf[3] = audio_pkt_seq;
			audio_pkt_seq++;
			audio_response_packet_buf[4] = 1;
			p = (uint8_t *)&audio_response_packet_buf[6];
			for (int i = 0; i < VOICE_BLOCK_NUM; i++) {
				if (VOICE_MGR->blocks[i].state == 2) {
					int32_t v;

					p[0] = i + 1;
					cnt++;
					v = VOICE_MGR->blocks[i].timestamp;
					p[1] = v;
					p[2] = v >> 8;
					p[3] = v >> 16;
					p[4] = v >> 24;
					v = VOICE_MGR->blocks[i].crc32;
					p[5] = v;
					p[6] = v >> 8;
					p[7] = v >> 16;
					p[8] = v >> 24;
					p += 9;
				}
			}
			audio_response_packet_buf[1] = cnt * 9 + 6;
			audio_response_packet_buf[5] = cnt;
			for (int i = 0; i < audio_response_packet_buf[1]; i++) {
				G1_LOG_DBG("audio_response_packet_buf[%d] = %d\n\n", i,
					   audio_response_packet_buf[i]);
			}
			ret = gs->ble_send((const uint8_t *)audio_response_packet_buf, audio_response_packet_buf[1]);
			if (ret < 0) {
				G1_LOG_WRN("Failed to send data over BLE connection: ret = %d \n", ret);
			}
			break;
		}

		case PROXY_MSG_POWER: {
			uint8_t on = msg.data[0];
			buf[0] = 7;
			buf[1] = on;

			for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec quick note start function.\n",
						   i);
				} else {
					display_powerEvent(on);
					k_yield();
					break;
				}
			}
			break;
		}

		case PROXY_MSG_LANGUAGE: {
			uint8_t lang = msg.data[0];
			buf[0] = 8;
			buf[1] = lang;

			for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec quick note start function.\n",
						   i);
				} else {
					upgradeAppLanguageInfoToFlash(lang);
					break;
				}
			}
			break;
		}

		case PROXY_MSG_STARTUP_MODE: {
			uint8_t mode = msg.data[0];
			buf[0] = 9;
			buf[1] = mode;

			for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec quick note start function.\n",
						   i);
				} else {
					upgradeDashboardStartupModeInfoToFlash(mode);
					break;
				}
			}
			break;
		}

		case PROXY_MSG_DOUBLE_CLICK:
			if (PROXY_GS()->f_1244 == 4 && PROXY_GS()->dashboard_mode == 0 &&
			    PROXY_GS()->is_master == 1) {
				buf[0] = 0x0a;
			buf[1] = 1;

				for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
					if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
						G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n",
							   i);
					} else {
						atomic_or(&DAT_20008518, 2);
						PROXY_GS()->f_1245 = 1;
						break;
					}
				}
			}
			if (PROXY_GS()->dashboard_mode == 6 &&
			    (PROXY_GS()->f_1245 || PROXY_GS()->dashboard_ts->f_72) &&
			    PROXY_GS()->is_master == 1) {
				buf[0] = 0x0a;
			buf[1] = 2;

				for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
					if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
						G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec double click startup dashboard function.\n",
							   i);
					} else {
						atomic_or(&DAT_20008518, 2);
						PROXY_GS()->f_1245 = 0;
						PROXY_GS()->dashboard_ts->f_72 = 0;
						break;
					}
				}
			}
			break;

		case PROXY_MSG_DOUBLE_TAP: {
			uint8_t mode = msg.data[0];
			buf[0] = 0x0c;
			buf[1] = mode;

			for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec double_tap_customize\n",
						   i);
				} else {
					upgradeDoubleTapCustomizeToFlash(mode);
					break;
				}
			}
			break;
		}

		case PROXY_MSG_LONGPRESS_TAP: {
			uint8_t mode = msg.data[0];
			buf[0] = 0x0d;
			buf[1] = mode;

			for (int i = 1; i <= SYNC_RETRY_COUNT; i++) {
				if (sync_to_slave(get_dashboard_state(), 6, buf, 2) >= SYNC_TIMEOUT) {
					G1_LOG_WRN("SYNC TO Slave failed %d times,don't exec longpress_tap_customize\n",
						   i);
				} else {
					upgradeLongpressTapCustomizeToFlash(mode);
					break;
				}
			}
			break;
		}

		default:
			G1_LOG_ERR("received unkonwn command,drop it\n");
			break;
		}
		}
next:;
	}
}

int send_response_data_to_msgqueue(const void *data, uint32_t len)
{
	struct proxy_msg msg;

	if (PROXY_GS()->is_master == 2) {
		return 0;
	}
	memset(&msg, 0, sizeof(msg));
	if (len > PROXY_MSG_DATA_MAX) {
		G1_LOG_ERR("send data length more than %d,can't load it,exit ...\n",
			   PROXY_MSG_DATA_MAX);
		return -1;
	}
	if (data) {
		memcpy(msg.data, data, len);
		msg.len = len;
	}
	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT) == 0) {
		return 0;
	}
	printk("message queue send failed %s\r\n", __func__);
	return -1;
}

int send_response_data_to_ble(void)
{
	if (PROXY_GS()->is_master != 2) {
		struct proxy_msg msg = {.type = PROXY_MSG_RESPONSE_SEND};

		if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
			printk("message queue send failed %s\r\n", __func__);
			return -1;
		}
	}
	return 0;
}

int sendAudioStreamFileToApp(uint8_t cmd, uint8_t block)
{
	struct proxy_msg msg = {.type = PROXY_MSG_AUDIO_FILE, .len = 2, .data = {cmd, block}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int requestAudioInfoToApp(uint8_t cmd)
{
	struct proxy_msg msg = {.type = PROXY_MSG_AUDIO_INFO, .len = 1, .data = {cmd}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SendPowerInfoToSlave(uint8_t on)
{
	struct proxy_msg msg = {.type = PROXY_MSG_POWER, .len = 1, .data = {on}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SendSystemLanguageInfoToSlave(uint8_t lang)
{
	struct proxy_msg msg = {.type = PROXY_MSG_LANGUAGE, .len = 1, .data = {lang}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SendDashBoardStartupModeInfoToSlave(uint8_t mode)
{
	struct proxy_msg msg = {.type = PROXY_MSG_STARTUP_MODE, .len = 1, .data = {mode}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SlaveDoubleClickEventInject(void)
{
	struct proxy_msg msg = {.type = PROXY_MSG_DOUBLE_CLICK};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SendDoubleTapCustomizeToSlave(uint8_t mode)
{
	struct proxy_msg msg = {.type = PROXY_MSG_DOUBLE_TAP, .len = 1, .data = {mode}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

int SendLongpressTapCustomizeToSlave(uint8_t mode)
{
	struct proxy_msg msg = {.type = PROXY_MSG_LONGPRESS_TAP, .len = 1, .data = {mode}};

	if (k_msgq_put(&proxy_msgq, &msg, K_NO_WAIT)) {
		printk("message queue send failed %s\r\n", __func__);
		return -1;
	}
	return 0;
}

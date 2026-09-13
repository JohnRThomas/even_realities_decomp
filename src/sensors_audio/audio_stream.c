/*
 * Audio stream recording (QuickNote): LC3 frames from the microphone are
 * queued here and written into one of four 128 KiB voice blocks on the
 * external flash.  A 4 KiB manager sector at 0x400000 describes the blocks.
 * Reconstructed from the v1.63 firmware image.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/atomic.h>

#include "g1_log.h"
#include "sensors_audio.h"

/* other modules */
extern struct k_sem flash_ops_sem;            /* flash storage thread wake-up */
extern uint32_t crc32(uint32_t crc, const uint8_t *data, size_t len);
extern int sync_to_slave(struct GlassesState *gs, int cmd, void *data, size_t len);
extern int display_DelayClose(int ms);
extern int requestAudioInfoToApp(uint8_t type);
extern uint32_t FUN_00080732(void);          /* current time stamp */

#define FLASH_DEV DEVICE_DT_GET(DT_NODELABEL(mx25r64))

#define AUDIO_STREAM_MSG_DATA  200
#define AUDIO_STREAM_MSGQ_LEN  18

#define VOICE_MANAGER_ADDR  0x400000
#define VOICE_SECTOR_SIZE   0x1000
#define VOICE_BLOCK_BASE    0x421000
#define VOICE_BLOCK_SIZE    0x20000
#define VOICE_BLOCK_LAST_SECTOR 0x10000
#define VOICE_BLOCK_NUM     4
#define VOICE_BLOCK_ALL     0xff
#define VOICE_MANAGER_MAGIC 0x5aa5aa5a

enum audio_stream_cmd {
	AUDIO_STREAM_START = 1,
	AUDIO_STREAM_DATA = 2,
	AUDIO_STREAM_STOP = 3,
	AUDIO_STREAM_DELETE = 4,
};

enum voice_block_state {
	VOICE_BLOCK_FREE = 0,
	VOICE_BLOCK_USED = 2,
};

struct audio_stream_msg {
	uint8_t cmd;
	uint8_t reserved;
	int16_t len;		/* signed: ldrsh in the target */
	uint8_t data[AUDIO_STREAM_MSG_DATA];
};

struct voice_block {
	uint32_t state;
	uint32_t start_addr;
	uint32_t end_addr;
	int32_t timestamp;
	uint32_t crc32;
} __packed;

struct voice_manager {
	uint32_t magic;
	uint32_t reserved;
	struct voice_block blocks[VOICE_BLOCK_NUM];
} __packed;

static const struct voice_manager voice_manager_default __aligned(4) = { /* 4-aligned .rodata in the target */
	.magic = VOICE_MANAGER_MAGIC,
};

K_MSGQ_DEFINE(audio_stream_msgq, sizeof(struct audio_stream_msg), AUDIO_STREAM_MSGQ_LEN, 4);

static uint32_t audio_stream_crc;            /* 0x2000859c */
static int audio_cache_offset;               /* 0x20008598 */
static int audio_sector_count;               /* 0x20008594 */
static atomic_t audio_block_in_use;          /* 0x20008590, 1-based, 0 = none */

static uint8_t audio_record_state;           /* 0x2001aa79 */
static uint8_t audio_block_num;              /* 0x2001aa78 */
static uint8_t audio_cache[VOICE_SECTOR_SIZE]; /* 0x20019a78 */

#define VOICE_MGR ((struct voice_manager *)audio_cache)

static int getAudioMessageQueueCacheData(void *msg)
{
	if (k_msgq_get(&audio_stream_msgq, msg, K_NO_WAIT)) {
		G1_LOG_ERR("dequeue_dmic failed\r\n\n");
		return -1;
	}
	return 0;
}

static void delVoiceBlock(uint8_t num)
{
	int ret;

	G1_LOG_INF("received audio delete command\n");
	/* valid: 1..VOICE_BLOCK_NUM, or 0xff = all (two separate checks in the vendor code) */
	if (num > VOICE_BLOCK_NUM && num != 0xff) {
		G1_LOG_ERR("input parameter error...\n");
		return;
	}
	if (num == 0) {
		G1_LOG_ERR("input parameter error...\n");
		return;
	}
	if (!device_is_ready(FLASH_DEV)) {
		G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
		return;
	}
	memset(audio_cache, 0, sizeof(audio_cache));
	ret = get_dashboard_state()->flash_read(get_dashboard_state(), VOICE_MANAGER_ADDR,
						 audio_cache, VOICE_SECTOR_SIZE);
	if (ret) {
		G1_LOG_ERR(" form address [%d] read data failed.\n\n", VOICE_MANAGER_ADDR);
		return;
	}
	ret = get_dashboard_state()->flash_erase(get_dashboard_state(), VOICE_MANAGER_ADDR,
						  VOICE_SECTOR_SIZE);
	if (ret) {
		G1_LOG_INF("Flash erase failed! %d\n\n", ret);
		return;
	}
	VOICE_MGR->magic = VOICE_MANAGER_MAGIC;
	VOICE_MGR->reserved = 0;
	if (num <= VOICE_BLOCK_NUM) {
		VOICE_MGR->blocks[num - 1].state = VOICE_BLOCK_FREE;
		VOICE_MGR->blocks[num - 1].timestamp = 0;
		G1_LOG_INF("success delete voice block num.(%d)\n", num);
	} else {
		memcpy(audio_cache, &voice_manager_default, sizeof(voice_manager_default));
		G1_LOG_INF("success delete all voice block \n");
	}
	ret = get_dashboard_state()->flash_write(get_dashboard_state(), VOICE_MANAGER_ADDR,
						  audio_cache, VOICE_SECTOR_SIZE);
	if (ret) {
		G1_LOG_ERR("Flash write failed! %d\n\n", ret);
		return;
	}
	G1_LOG_INF("audio manager block delete success\n");
}

int clearAudioMessageQueue(void)
{
	struct audio_stream_msg msg;
	int ret = 0;
	int n = k_msgq_num_used_get(&audio_stream_msgq);

	while (n > 0) {
		ret = k_msgq_get(&audio_stream_msgq, &msg, K_NO_WAIT);
		n--;
	}
	return ret;
}

int sendAudioStram2Cache(void *data)
{
	struct audio_stream_msg msg;

	uint32_t used;

	memset(&msg, 0, sizeof(msg));
	used = k_msgq_num_used_get(&audio_stream_msgq);
	if (used == AUDIO_STREAM_MSGQ_LEN) {
		G1_LOG_ERR("enqueue dmic stream num is full, drop it %d\r\n\n", used);
		return -1;
	}
	memcpy(msg.data, data, AUDIO_STREAM_MSG_DATA);
	msg.len = AUDIO_STREAM_MSG_DATA;
	msg.cmd = AUDIO_STREAM_DATA;
	if (k_msgq_put(&audio_stream_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("enqueue_dmic failed\r\n\n");
		return -1;
	}
	k_sem_give(&flash_ops_sem);
	return 0;
}

uint32_t getAudioMessageQueueNum(void)
{
	return audio_stream_msgq.used_msgs;
}

int startAudioStreamRecord(void)
{
	struct audio_stream_msg msg;
	uint8_t exit_quicknote[2];

	memset(&msg, 0, sizeof(msg));
	msg.cmd = AUDIO_STREAM_START;
	if (k_msgq_put(&audio_stream_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("start up audio record failed\r\n\n");
		exit_quicknote[0] = 1;
		exit_quicknote[1] = 0;
		sync_to_slave(get_dashboard_state(), 6, exit_quicknote, sizeof(exit_quicknote));
		display_DelayClose(10000);
		G1_LOG_ERR("because startup auido record failed,exit quicknote ....\n");
		return -1;
	}
	k_sem_give(&flash_ops_sem);
	return 0;
}

int stopAudioStreamRecord(void)
{
	struct audio_stream_msg msg;

	memset(&msg, 0, sizeof(msg));
	msg.cmd = AUDIO_STREAM_STOP;
	if (k_msgq_put(&audio_stream_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("enqueue_dmic failed\r\n\n");
		return -1;
	}
	k_sem_give(&flash_ops_sem);
	return 0;
}

int delAudioStreamRecord(uint8_t num)
{
	struct audio_stream_msg msg;

	G1_LOG_INF("received audio delete command\n");
	memset(&msg, 0, sizeof(msg));
	msg.len = 1;
	msg.cmd = AUDIO_STREAM_DELETE;
	msg.data[0] = num;
	if (k_msgq_put(&audio_stream_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("enqueue_dmic failed\r\n\n");
		return -1;
	}
	k_sem_give(&flash_ops_sem);
	return 0;
}

atomic_val_t setAudioBlockInUse(atomic_val_t num)
{
	return atomic_set(&audio_block_in_use, num);
}

atomic_val_t clearAudioBlockInUse(void)
{
	return atomic_clear(&audio_block_in_use);
}

atomic_val_t getAudioBlockInUse(void)
{
	return atomic_get(&audio_block_in_use);
}

int audioStreamFileManagerHandler(void)
{
	uint8_t exit_quicknote[2];
	int32_t oldest;
	uint8_t sel;
	int addr;
	int copied;
	int ret;
	int i;

	switch (audio_record_state) {
	case 0: {
		struct audio_stream_msg msg;

		if (audio_stream_msgq.used_msgs == 0) {
			return 0;
		}
		if (getAudioMessageQueueCacheData(&msg)) {
			G1_LOG_ERR("get audio message queue data failed!\n");
			return 0;
		}
		if (msg.cmd == AUDIO_STREAM_START) {
			G1_LOG_INF("start audio stream record!\r\n\n");
			if (!device_is_ready(FLASH_DEV)) {
				G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
				return 0;
			}
			memset(audio_cache, 0, sizeof(audio_cache));
			ret = get_dashboard_state()->flash_read(get_dashboard_state(), VOICE_MANAGER_ADDR,
								 audio_cache, VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_ERR(" form address [%d] read data failed.\n\n", VOICE_MANAGER_ADDR);
				return 0;
			}
			if (VOICE_MGR->magic != VOICE_MANAGER_MAGIC) {
				G1_LOG_INF("filesystem need format,try to format,please wait..\n");
				memset(audio_cache, 0, sizeof(audio_cache));
				memcpy(audio_cache, &voice_manager_default, sizeof(voice_manager_default));
				ret = get_dashboard_state()->flash_erase(get_dashboard_state(),
									  VOICE_MANAGER_ADDR, VOICE_SECTOR_SIZE);
				if (ret) {
					G1_LOG_INF("Flash erase failed! %d\n\n", ret);
					return 0;
				}
				ret = get_dashboard_state()->flash_write(get_dashboard_state(),
									  VOICE_MANAGER_ADDR, audio_cache,
									  VOICE_SECTOR_SIZE);
				if (ret) {
					G1_LOG_ERR("Flash write failed! %d\n\n", ret);
					return 0;
				}
				G1_LOG_INF("filesystem format sucess\n");
			}

			oldest = INT32_MAX;
			sel = 0;
			for (i = 0; i < VOICE_BLOCK_NUM; i++) {
				if (VOICE_MGR->blocks[i].state == VOICE_BLOCK_FREE) {
					G1_LOG_INF("find a free voice block(%d)!\r\n\n", i);
					break;
				}
				G1_LOG_INF("voice_block_store_timestamp = %d, voice_stream_block_ts = %d\n",
					   VOICE_MGR->blocks[i].timestamp, oldest);
				if (VOICE_MGR->blocks[i].timestamp < oldest) {
					if (getAudioBlockInUse() != 0) {
						if (getAudioBlockInUse() - 1 != i) {
							oldest = VOICE_MGR->blocks[i].timestamp;
							sel = i;
						}
					} else {
						oldest = VOICE_MGR->blocks[i].timestamp;
						sel = i;
					}
				}
			}
			if (i == VOICE_BLOCK_NUM) {
				G1_LOG_INF("no free voice block,try to use the oldest voice block(%d)!\n", sel);
			} else {
				sel = i;
			}
			audio_block_num = sel;
			G1_LOG_INF("audio manager start check success,will fill up audio stream to Num%d "
				   "block\n", sel);
			audio_cache_offset = 0;
			audio_sector_count = 0;
			memset(audio_cache, 0, sizeof(audio_cache));
			audio_record_state = 1;
			audio_stream_crc = 0;
			return 0;
		} else if (msg.cmd == AUDIO_STREAM_STOP) {
			clearAudioMessageQueue();
		} else if (msg.cmd == AUDIO_STREAM_DELETE) {
			delVoiceBlock(msg.data[0]);
		} else if (msg.cmd == AUDIO_STREAM_DATA) {
			clearAudioMessageQueue();
		}
		return 0;
	}
	case 1: {
		struct audio_stream_msg msg;

		if (audio_stream_msgq.used_msgs == 0) {
			return 0;
		}
		if (getAudioMessageQueueCacheData(&msg)) {
			G1_LOG_ERR("get audio message queue data failed!\n");
			return 0;
		}

		if (msg.cmd == AUDIO_STREAM_START) {
			audio_record_state = 0;
			G1_LOG_ERR("A start command occurred during recording to exit the recording\n");
			return 0;
		} else if (msg.cmd == AUDIO_STREAM_DATA) {
			if (audio_cache_offset + msg.len < VOICE_SECTOR_SIZE) {
				memcpy(&audio_cache[audio_cache_offset], msg.data, msg.len);
				audio_cache_offset += msg.len;
				G1_LOG_INF("copy %d byte into audio cache\n", audio_cache_offset);
				return 0;
			}
			memcpy(&audio_cache[audio_cache_offset], msg.data,
			       VOICE_SECTOR_SIZE - audio_cache_offset);
			G1_LOG_INF("To complete a sector of data, perform flash write operations\n");
			if (!device_is_ready(FLASH_DEV)) {
				G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
				return 0;
			}
			addr = audio_block_num * VOICE_BLOCK_SIZE + VOICE_BLOCK_BASE +
			       audio_sector_count * VOICE_SECTOR_SIZE;
			if (addr > audio_block_num * VOICE_BLOCK_SIZE + VOICE_BLOCK_BASE +
				   VOICE_BLOCK_LAST_SECTOR) {
				G1_LOG_ERR("the number of recording files exceeds the upper limit, system "
					   "automatically stops\n");
				G1_LOG_ERR("Catch touch release is not recognized, start QuickNote exception "
					   "recovery mechanism\n");
				exit_quicknote[0] = 1;
				exit_quicknote[1] = 0;
				sync_to_slave(get_dashboard_state(), 6, exit_quicknote,
					      sizeof(exit_quicknote));
				display_DelayClose(10000);
				goto stop;
			}
			G1_LOG_INF("wirte addr = 0x%08x\n", addr);
			ret = get_dashboard_state()->flash_erase(get_dashboard_state(), addr,
								  VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_INF("Flash erase failed! %d\n\n", ret);
				return 0;
			}
			ret = get_dashboard_state()->flash_write(get_dashboard_state(), addr, audio_cache,
								  VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_ERR("Flash write failed! %d\n\n", ret);
				return 0;
			}
			audio_stream_crc = crc32(audio_stream_crc, audio_cache, VOICE_SECTOR_SIZE);
			audio_sector_count++;
			G1_LOG_INF("wirte 4k voice data to flash,write address = 0x%08x\n", addr);
			copied = VOICE_SECTOR_SIZE - audio_cache_offset;
			audio_cache_offset = 0;
			memset(audio_cache, 0, sizeof(audio_cache));
			G1_LOG_INF("Copy remain %d byte data into cache memory\n", msg.len - copied);
			memcpy(&audio_cache[audio_cache_offset], msg.data + copied, msg.len - copied);
			audio_cache_offset += msg.len - copied;
			return 0;
		} else if (msg.cmd == AUDIO_STREAM_STOP) {
stop:
			G1_LOG_INF("received audio stop command,stop audio write process\n");
			G1_LOG_INF("To complete a sector of data, perform flash write operations\n");
			if (!device_is_ready(FLASH_DEV)) {
				G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
				return 0;
			}
			addr = audio_block_num * VOICE_BLOCK_SIZE + VOICE_BLOCK_BASE +
			       audio_sector_count * VOICE_SECTOR_SIZE;
			G1_LOG_INF("wirte addr = 0x%08x\n", addr);
			ret = get_dashboard_state()->flash_erase(get_dashboard_state(), addr, VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_INF("Flash erase failed! %d\n\n", ret);
				return 0;
			}
			ret = get_dashboard_state()->flash_write(get_dashboard_state(), addr, audio_cache,
								  VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_ERR("Flash write failed! %d\n\n", ret);
				return 0;
			}
			audio_stream_crc = crc32(audio_stream_crc, audio_cache, audio_cache_offset);

			memset(audio_cache, 0, sizeof(audio_cache));
			ret = get_dashboard_state()->flash_read(get_dashboard_state(), VOICE_MANAGER_ADDR,
								 audio_cache, VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_ERR(" form address [%d] read data failed.\n\n", VOICE_MANAGER_ADDR);
				return 0;
			}
			ret = get_dashboard_state()->flash_erase(get_dashboard_state(), VOICE_MANAGER_ADDR,
								  VOICE_SECTOR_SIZE);
			if (ret) {
				G1_LOG_INF("Flash erase failed! %d\n\n", ret);
				return 0;
			}
			VOICE_MGR->magic = VOICE_MANAGER_MAGIC;
			VOICE_MGR->reserved = 0;
			VOICE_MGR->blocks[audio_block_num].state = VOICE_BLOCK_USED;
			VOICE_MGR->blocks[audio_block_num].start_addr = audio_block_num * VOICE_BLOCK_SIZE + VOICE_BLOCK_BASE;
			VOICE_MGR->blocks[audio_block_num].end_addr = audio_block_num * VOICE_BLOCK_SIZE + VOICE_BLOCK_BASE +
				audio_sector_count * VOICE_SECTOR_SIZE + audio_cache_offset;
			VOICE_MGR->blocks[audio_block_num].timestamp = FUN_00080732();
			VOICE_MGR->blocks[audio_block_num].crc32 = audio_stream_crc;
			G1_LOG_INF("upgrade Num.%d voice manager block,total write sector num = %d, total write "
				   "byte = %d ,crc32 = %d\n",
				   audio_block_num, audio_sector_count,
				   audio_cache_offset + audio_sector_count * VOICE_SECTOR_SIZE, audio_stream_crc);

			if (VOICE_MGR->blocks[audio_block_num].start_addr ==
			    VOICE_MGR->blocks[audio_block_num].end_addr) {
				G1_LOG_INF("voice block start addr = voice block end addr\n");
				audio_record_state = 0;
				audio_block_num = 0;
				audio_cache_offset = 0;
				audio_sector_count = 0;
				clearAudioMessageQueue();
				G1_LOG_ERR("The dmic may have a problem. When the size of the recording file is 0, "
					   "data block 0 is terminated\n");
				return 0;
			}
			ret = get_dashboard_state()->flash_write(get_dashboard_state(), VOICE_MANAGER_ADDR,
								  audio_cache, VOICE_SECTOR_SIZE);
			audio_record_state = 0;
			audio_block_num = 0;
			audio_cache_offset = 0;
			audio_sector_count = 0;
			clearAudioMessageQueue();
			requestAudioInfoToApp(1);
			if (ret) {
				G1_LOG_ERR("Flash write failed! %d\n\n", ret);
				return 0;
			}
			G1_LOG_INF("audio manager block upgrade success\n");
			return 0;
		} else if (msg.cmd == AUDIO_STREAM_DELETE) {
			G1_LOG_WRN("A delete command occurred during the recording process. The recording "
				   "was stopped and the deletion action was performed,Delete num = %d\n",
				   msg.data[0]);
			delVoiceBlock(msg.data[0]);
			audio_record_state = 0;
			return 0;
		}
	}
	}
	return 0;
}

/*
 * Sets bit 2 of the display refresh flags and wakes the display task.
 * Declared int by the vendor but returns nothing: that is why the target has
 * bl k_sem_give + pop instead of a sibcall.  Callers use it as void.
 */
int FUN_0008040c(void)
{
	if (!(get_dashboard_state()->refresh_flags & BIT(2))) {
		get_dashboard_state()->refresh_flags |= BIT(2);
		k_sem_give(&get_dashboard_state()->refresh_sem);
	}
}

/* old Ghidra names, kept as aliases until the callers in other modules are renamed */
extern __typeof__(clearAudioMessageQueue) FUN_00030b28 __attribute__((alias("clearAudioMessageQueue")));
extern __typeof__(setAudioBlockInUse) FUN_00030db0 __attribute__((alias("setAudioBlockInUse")));
extern __typeof__(clearAudioBlockInUse) FUN_00030dc8 __attribute__((alias("clearAudioBlockInUse")));

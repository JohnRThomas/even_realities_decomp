/*
 * QuickNote persistence: 4 notes of 0x200 bytes at 0x403000 on the
 * external flash, written by the flash ops thread (QuickNoteStoreHandler).
 * Original file name unknown.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "storage.h"

#define QUICKNOTE_FLASH_ADDR  0x403000
#define QUICKNOTE_MAGIC       0xaa
#define QUICKNOTE_NUM         4
#define QUICKNOTE_QUEUE_DEPTH 20

/*
 * G1_LOG_ERR() with LOG_LEVEL read through a volatile access.  The shipped
 * QuickNoteStoreHandler re-reads LOG_LEVEL for the store range-check error
 * instead of sharing one (hoisted) load with the following log; the code is
 * the same after the post-reload head merge, but the extra reference of the
 * &LOG_LEVEL register decides the register order (index in r7).
 */
#define QUICKNOTE_LOG_ERR_RELOAD(fmt, ...)                                         \
	do {                                                                        \
		if (*(volatile int *)&LOG_LEVEL > 0) {                              \
			if (BLE_DEBUG) {                                            \
				ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);  \
			} else {                                                    \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);      \
			}                                                           \
		}                                                                   \
	} while (0)

enum {
	QUICKNOTE_CMD_STORE = 1,
	QUICKNOTE_CMD_DELETE = 2,
};

struct quicknote_msg {
	uint8_t cmd;
	uint8_t f1;
	uint16_t f2;
	uint8_t index;
	uint8_t f5;
};

/* one note in flash */
struct quicknote_flash {
	uint8_t magic;
	uint8_t title[QUICKNOTE_TITLE_LEN];
	uint8_t text[QUICKNOTE_TEXT_LEN];
	uint8_t pad[0x200 - 1 - QUICKNOTE_TITLE_LEN - QUICKNOTE_TEXT_LEN];
};

K_MSGQ_DEFINE(quicknote_msgq, sizeof(struct quicknote_msg), QUICKNOTE_QUEUE_DEPTH, 4);

static struct quicknote_flash quicknote_cache[QUICKNOTE_NUM];

int clearQuickNoteQueue(void)
{
	struct quicknote_msg msg;
	int ret = 0;
	int n;

	for (n = k_msgq_num_used_get(&quicknote_msgq); n > 0; n--) {
		ret = k_msgq_get(&quicknote_msgq, &msg, K_NO_WAIT);
	}
	return ret;
}

int upgradeQuickNoteDataToFlash(int index)
{
	struct quicknote_msg msg = {
		.cmd = QUICKNOTE_CMD_STORE,
		.f2 = 1,
		.index = index,
	};

	if (k_msgq_put(&quicknote_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("quicknote flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("SEND QUICKNOTE TEXT Store(%d) Command...\n", index);
	k_sem_give(&flash_ops_sem);
	return 0;
}

int deleteQuickNoteData(int index)
{
	struct quicknote_msg msg = {
		.cmd = QUICKNOTE_CMD_DELETE,
		.f2 = 1,
		.index = index,
	};

	if (k_msgq_put(&quicknote_msgq, &msg, K_NO_WAIT)) {
		G1_LOG_ERR("quicknote flash store queue fill failed\r\n\n");
		return -1;
	}
	G1_LOG_INF("SEND QUICKNOTE TEXT delete(%d) Command...\n", index);
	k_sem_give(&flash_ops_sem);
	return 0;
}

int getQuickNoteDataFromFlash(uint32_t index, void *title, int title_len, void *text,
			      int text_len)
{
	if (index >= QUICKNOTE_NUM) {
		G1_LOG_ERR("quicknote upgrade index out of range\n");
		return -1;
	}
	G1_LOG_INF("read quicknote flash data to ram...\r\n\n");
	if (!device_is_ready(FLASH_DEV)) {
		G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
		return -1;
	}
	memset(quicknote_cache, 0, sizeof(quicknote_cache));
	if (get_dashboard_state()->flash_read(get_dashboard_state(), QUICKNOTE_FLASH_ADDR,
					      quicknote_cache, sizeof(quicknote_cache))) {
		G1_LOG_ERR(" form address [%d] read data failed.\n\n", QUICKNOTE_FLASH_ADDR);
		return -1;
	}
	if (quicknote_cache[index].magic != QUICKNOTE_MAGIC) {
		G1_LOG_INF("quicknote data is invaild,don't export to global ram..\n");
		return -1;
	}
	if (title_len > QUICKNOTE_TITLE_LEN) {
		title_len = QUICKNOTE_TITLE_LEN;
	}
	memcpy(title, quicknote_cache[index].title, title_len);
	if (text_len > QUICKNOTE_TEXT_LEN) {
		text_len = QUICKNOTE_TEXT_LEN;
	}
	memcpy(text, quicknote_cache[index].text, text_len);
	G1_LOG_INF("export flash data to global ram...\n");
	return 0;
}

int getQuickNoteQueueNum(void)
{
	return k_msgq_num_used_get(&quicknote_msgq);
}

static int getQuickNoteBKPQueueCacheData(struct quicknote_msg *msg)
{
	int ret;

	ret = k_msgq_get(&quicknote_msgq, msg, K_NO_WAIT);
	if (ret) {
		G1_LOG_ERR("quick note file queue get failed\r\n\n");
	}
	return ret;
}

unsigned int QuickNoteStoreHandler(void)
{
	struct quicknote_msg msg;
	struct quicknote_flash *note;
	uint8_t *title;
	uint8_t *text;
	int changed;
	uint8_t index;
	int ret;

	if (getQuickNoteBKPQueueCacheData(&msg)) {
		G1_LOG_ERR("quick note get queue data failed\n");
		return -1;
	}
	switch (msg.cmd) {
	case QUICKNOTE_CMD_STORE: {
		/*
		 * unsigned like the return type: with no int->unsigned conversion the
		 * erase/write results coalesce with the return value instead of getting
		 * pseudos of their own, which gives the shipped register order.
		 */
		unsigned int ret;

		index = msg.index;
		if (index >= QUICKNOTE_NUM) {
			QUICKNOTE_LOG_ERR_RELOAD("quicknote upgrade index out of range\n");
			return -1;
		}
		G1_LOG_INF("start quicknote text check...\r\n\n");
		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			return -1;
		}
		memset(quicknote_cache, 0, sizeof(quicknote_cache));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), QUICKNOTE_FLASH_ADDR,
						      quicknote_cache, sizeof(quicknote_cache))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n",
				   QUICKNOTE_FLASH_ADDR);
			return -1;
		}
		note = &quicknote_cache[index];
		title = note->title;
		text = note->text;
		if (note->magic != QUICKNOTE_MAGIC) {
			note->magic = QUICKNOTE_MAGIC;
			memset(title, 0, QUICKNOTE_TITLE_LEN);
			memcpy(title, get_dashboard_state()->quicknote->notes[index].title,
			       QUICKNOTE_TITLE_LEN);
			memset(text, 0, QUICKNOTE_TEXT_LEN);
			memcpy(text, get_dashboard_state()->quicknote->notes[index].text,
			       QUICKNOTE_TEXT_LEN);
		} else {
			changed = 0;
			if (memcmp(title, get_dashboard_state()->quicknote->notes[index].title,
				   QUICKNOTE_TITLE_LEN)) {
				memset(title, 0, QUICKNOTE_TITLE_LEN);
				memcpy(title, get_dashboard_state()->quicknote->notes[index].title,
				       QUICKNOTE_TITLE_LEN);
				changed = 1;
			}
			if (memcmp(text, get_dashboard_state()->quicknote->notes[index].text,
				   QUICKNOTE_TEXT_LEN)) {
				memset(text, 0, QUICKNOTE_TEXT_LEN);
				memcpy(text, get_dashboard_state()->quicknote->notes[index].text,
				       QUICKNOTE_TEXT_LEN);
				changed = 1;
			}
			if (changed != 1) {
				goto same;
			}
		}
		FUN_00038b00();
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(),
							 QUICKNOTE_FLASH_ADDR, 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			return ret;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(),
							 QUICKNOTE_FLASH_ADDR, quicknote_cache,
							 sizeof(quicknote_cache));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			return ret;
		}
		G1_LOG_INF("quicknote %d store sucess\n", index);
		return 0;
same:
		G1_LOG_INF("The current quicknote text is stored the same as in flash and does not need to be updated\n");
		return 0;
	}
	case QUICKNOTE_CMD_DELETE:
		index = msg.index;
		if (index >= QUICKNOTE_NUM) {
			G1_LOG_ERR("quicknote upgrade index out of range\n");
			return -1;
		}
		G1_LOG_INF("start quicknote text check...\r\n\n");
		FUN_00038b00();
		if (!device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR(" [%s] device not ready.\n\n", FLASH_DEV->name);
			return -1;
		}
		memset(quicknote_cache, 0, sizeof(quicknote_cache));
		if (get_dashboard_state()->flash_read(get_dashboard_state(), QUICKNOTE_FLASH_ADDR,
						      quicknote_cache, sizeof(quicknote_cache))) {
			G1_LOG_ERR(" form address [%d] read data failed.\n\n",
				   QUICKNOTE_FLASH_ADDR);
			return -1;
		}
		memset(&quicknote_cache[index], 0xff, sizeof(quicknote_cache[index]));
		ret = get_dashboard_state()->flash_erase(get_dashboard_state(),
							 QUICKNOTE_FLASH_ADDR, 0x1000);
		if (ret) {
			G1_LOG_INF("Flash erase failed! %d\n\n", ret);
			return ret;
		}
		ret = get_dashboard_state()->flash_write(get_dashboard_state(),
							 QUICKNOTE_FLASH_ADDR, quicknote_cache,
							 sizeof(quicknote_cache));
		if (ret) {
			G1_LOG_ERR("Flash write failed! %d\n\n", ret);
			return ret;
		}
		G1_LOG_INF("quicknote %d delete sucess\n", index);
		return 0;
	default:
		return 0;
	}
}

/* old Ghidra name, kept as an alias until the callers in other modules are renamed */
extern __typeof__(clearQuickNoteQueue) FUN_00026618 __attribute__((alias("clearQuickNoteQueue")));

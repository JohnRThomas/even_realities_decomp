/*
 * Flash storage threads: the flash ops worker (audio / quick note / setting
 * stores) and the storage commit thread (settings commit, file download
 * into the external flash).
 * Original file name unknown.
 */
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "storage.h"

#define FILE_MSG_LEN     200
#define FILE_MSGQ_DEPTH  30
#define DEMO_IMAGE_ADDR  0x1c0000
#define DEMO_IMAGE_END   0x200000

struct file_msg {
	uint8_t data[FILE_MSG_LEN];
	uint8_t len;
};
static uint8_t file_buf[0x1400];     /* 0x20017d30 */
uint8_t sys_settings_dirty;          /* 0x20017d2f */

struct k_sem flash_ops_sem;          /* 0x200083c4 */
uint32_t LAST_FILE_CRC;              /* 0x200083c0 */
static uint32_t file_addr;           /* 0x200083bc */
static uint32_t file_buf_len;        /* 0x200083b8 */
static uint32_t file_type;           /* 0x200083b4 */
static struct k_msgq file_msgq;      /* 0x20008380 */
static uint32_t crc32_table[256];    /* 0x20007f80 */
static struct k_thread storage_commit_thread_data;

static struct k_thread flash_ops_thread_data;
/* reverse definition order: flash_ops_stack 0x200226e0, storage_commit_stack 0x20022ee0 */
K_THREAD_STACK_DEFINE(storage_commit_stack, 0x1400);
K_THREAD_STACK_DEFINE(flash_ops_stack, 0x800);

static void flash_ops_thread(void *p1, void *p2, void *p3)
{
	int note;

	G1_LOG_INF("flash op thread startup ...\n");
	while (1) {
		k_sem_take(&flash_ops_sem, K_FOREVER);
		while (getAudioMessageQueueNum()) {
			audioStreamFileManagerHandler();
		}
		while ((note = getQuickNoteQueueNum()) != 0) {
			QuickNoteStoreHandler();
		}
		while (getSettingStorageQueueNum()) {
			SettingStoreHandler();
		}
	}
}

int file_init(void)
{
	int ret;

	ret = k_msgq_alloc_init(&file_msgq, sizeof(struct file_msg), FILE_MSGQ_DEPTH);
	if (ret != 0) {
		printk("file init failed\r\n");
	} else {
		printk("file init success\r\n");
	}
	return ret;
}

int enqueue_file(const void *data, size_t len)
{
	struct file_msg msg;
	int ret;

	if (k_msgq_num_used_get(&file_msgq) == FILE_MSGQ_DEPTH) {
		k_msgq_get(&file_msgq, &msg, K_NO_WAIT);
		G1_LOG_ERR("enqueue_file is full\n");
	}
	memcpy(&msg, data, len);
	msg.len = len;
	ret = k_msgq_put(&file_msgq, &msg, K_NO_WAIT);
	if (ret) {
		G1_LOG_ERR("enqueue_file failed\r\n\n");
	}
	return ret;
}

int dequeue_file(struct file_msg *out)
{
	struct file_msg msg;
	int ret;

	ret = k_msgq_get(&file_msgq, &msg, K_NO_WAIT);
	if (ret != 0) {
		printk("dequeue_file failed\r\n");
	} else {
		memcpy(out, &msg, sizeof(msg));
	}
	return ret;
}

void crc32_init(void)
{
	uint32_t i, j, c;

	for (i = 0; i < 256; i++) {
		c = i;
		for (j = 0; j < 8; j++) {
			if (c & 1) {
				c = (c >> 1) ^ 0xedb88320;
			} else {
				c >>= 1;
			}
		}
		crc32_table[i] = c;
	}
}

uint32_t crc32(uint32_t crc, const uint8_t *buf, int len)
{
	const uint8_t *end = buf + len;

	crc = ~crc;
	while (buf != end) {
		crc = crc32_table[(crc ^ *buf++) & 0xff] ^ (crc >> 8);
	}
	return ~crc;
}

void try_to_save_file(struct GlassesState *gs)
{
	struct file_msg msg;
	uint32_t addr;
	uint8_t ab[4];
	uint8_t len;
	bool end = false;

	dequeue_file(&msg);
	len = msg.len;
	if (len <= 20 && msg.data[0] == 0x0d && msg.data[1] == 0x0e) {
		/* end of file */
		end = true;
	} else if (file_addr != 0) {
		memcpy(file_buf + file_buf_len, &msg.data[1], len - 1);
		file_buf_len += len - 1;
	} else {
		ab[3] = msg.data[1];
		ab[2] = msg.data[2];
		ab[1] = msg.data[3];
		ab[0] = msg.data[4];
		memcpy(&addr, ab, 4);
		file_addr = addr;
		LAST_FILE_CRC = crc32(LAST_FILE_CRC, &msg.data[1], 4);
		if (addr == DEMO_IMAGE_ADDR) {
			file_type = addr;
			*get_dashboard_state()->status_ptr = 0x0c;
			if (*get_dashboard_state()->task_state != 0x10) {
				if (gs->status_ptr[7] == 0) {
					gs->status_ptr[7] = 10;
				}
				update_persist_task_status(get_dashboard_state(), 0x10, 2);
			}
		}
		memcpy(file_buf + file_buf_len, &msg.data[5], len - 5);
		file_buf_len += len - 5;
	}
	if (file_type == DEMO_IMAGE_ADDR && file_addr >= DEMO_IMAGE_END) {
		return;
	}
	if (file_buf_len >= 0x1000) {
		write_font(file_addr, file_buf, 0x1000);
		LAST_FILE_CRC = crc32(LAST_FILE_CRC, file_buf, 0x1000);
		G1_LOG_ERR("crc32_value %08X\n", LAST_FILE_CRC);
		file_addr += 0x1000;
		memcpy(file_buf, file_buf + 0x1000, file_buf_len - 0x1000);
		file_buf_len -= 0x1000;
	} else if (end) {
		write_font(file_addr, file_buf, file_buf_len);
		LAST_FILE_CRC = crc32(LAST_FILE_CRC, file_buf, file_buf_len);
		G1_LOG_ERR("crc cal end crc32_value %08X\n", LAST_FILE_CRC);
	}
}

static void storage_commit_thread(void *p1, void *p2, void *p3)
{
	struct GlassesState *gs = p1;
	bool saved;
	int force_sys = 0;
	uint32_t start;

	file_init();
	crc32_init();
	while (1) {
		k_sem_take(&gs->cmd_sem, K_FOREVER);
		saved = false;
		while (k_msgq_num_used_get(&file_msgq)) {
			try_to_save_file(gs);
			saved = true;
		}
		if (gs->storage_cmd == 0x15 || saved) {
			continue;
		}
		switch (gs->storage_cmd) {
		case 1:
			gs->store.write("brightness_level", &gs->brightness_level, 1);
			break;
		case 2:
			gs->store.write("3dof_enable", &gs->dof3_enable, 1);
			break;
		case 3:
			gs->store.write("display_mode", &gs->display_mode, 1);
			break;
		case 7:
			gs->store.write("countdown_ts", gs->countdown_ts, 7);
			break;
		case 6:
			gs->store.write("dashboard_ts", gs->dashboard_ts, 0x75);
			break;
		case 8:
			gs->store.write("user_sched_info", gs->user_sched_info, 0x16a);
			break;
		case 0x0b:
			gs->store.write("wakeup_angle", &gs->wakeup_angle, 1);
			break;
		case 0x16:
			if (file_type == DEMO_IMAGE_ADDR) {
				get_demo_image_source_from_flash();
				if (get_dashboard_state()->is_master == 1) {
					*get_dashboard_state()->status_ptr = 0x0d;
				} else {
					*get_dashboard_state()->status_ptr = 0x0c;
				}
			}
			file_type = 0;
			file_buf_len = 0;
			LAST_FILE_CRC = 0;
			file_addr = 0;
			continue;
		case 0x17:
			FUN_0007ff66(gs, 0);
			change_work_mode(1);
			continue;
		case 0x19:
		case 0x1a:
			force_sys = 1;
			break;
		case 0x3e:
			update_burial_point_to_flash(get_dashboard_state());
			break;
		case 0x11:
			k_sleep(K_SECONDS(10));
			change_work_mode(7);
			/* fallthrough */
		default:
			G1_LOG_INF("ignore.\n");
			break;
		}
		do {
			start = k_uptime_get();
			k_sem_take(&gs->cmd_sem, K_MSEC(5000));
		} while (k_uptime_get() - start < 5000);
		gs->storage_cmd = 0;
		FUN_0007f556(gs, 0);
		if (sys_settings_dirty) {
			sys_settings_dirty = 0;
			save_sys_settings(gs, force_sys);
		}
	}
}

void storage_commit_request(int cmd, uint8_t sys_dirty)
{
	get_dashboard_state()->storage_cmd = cmd;
	if (sys_settings_dirty != sys_dirty && sys_settings_dirty == 0) {
		sys_settings_dirty = sys_dirty;
	}
	k_sem_give(&get_dashboard_state()->cmd_sem);
}

void start_flash_storage_threads(struct GlassesState *gs)
{
	k_sem_init(&flash_ops_sem, 0, 20);
	k_thread_create(&flash_ops_thread_data, flash_ops_stack,
			K_THREAD_STACK_SIZEOF(flash_ops_stack), flash_ops_thread, gs, NULL, NULL,
			K_PRIO_COOP(4), 0, K_NO_WAIT);
	k_thread_create(&storage_commit_thread_data, storage_commit_stack,
			K_THREAD_STACK_SIZEOF(storage_commit_stack), storage_commit_thread, gs,
			NULL, NULL, K_PRIO_COOP(5), 0, K_NO_WAIT);
}

/*
 * Ghost reference experiment (p_periph): the target's libc_nano member order shows that some
 * vendor function, dropped by --gc-sections, referenced fflush() and fseek() (fflush.o, findfp.o
 * and makebuf.o are extracted in the same archive scan as assert.o).  Nothing calls this.
 */
void dump_file_to_stdio(void)
{
	fflush(stdout);
	fseek(stdout, 0, SEEK_SET);
}

/* old Ghidra name, kept as an alias until the callers in other modules are renamed */
extern __typeof__(storage_commit_request) FUN_00025b28 __attribute__((alias("storage_commit_request")));

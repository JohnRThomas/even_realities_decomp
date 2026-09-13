/*
 * Storage module private declarations (settings glue, flash settings,
 * file storage thread, setting / quick-note stores).
 */
#ifndef STORAGE_H_
#define STORAGE_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>

/* Local settings store backend (GLOBAL_STATE->store, filled by sett_init) */
struct local_store {
	int status;                                                  /* 0x0 */
	int (*write)(const char *key, const void *val, size_t len);  /* 0x4 */
	int (*load)(void);                                           /* 0x8 */
	void (*del)(const char *key);                                /* 0xc */
};

/* partial: only the byte used here */
struct dashboard_ts_context {
	uint8_t pad_00[0x5f];
	uint8_t f_5f;                /* 0x5f */
};
struct countdown_ts_context;
struct user_sched_info;

struct pk7 {
	uint32_t a;
	uint16_t b;
	uint8_t c;
} __packed;

struct triple {
	uint32_t v[3];
};

struct u8pair {
	uint8_t a;
	uint8_t b;
};

/* Burial point (usage statistics) block, flash 0x135000 */
struct burial_point {
	uint32_t id;                 /* 0x00 random id */
	uint8_t pad_04[0x10];
	uint8_t version;             /* 0x14 */
	uint8_t f15;                 /* 0x15 */
	uint8_t valid;               /* 0x16 */
	uint8_t data[0x11c - 0x17];
};

/* System (factory) settings, flash 0x130000 */
struct sys_settings {
	uint32_t valid;              /* 0x00 == 1 */
	uint32_t f04;                /* 0x04 gs 0x10b8 */
	uint8_t esb_channel;         /* 0x08 */
	uint32_t f0c;                /* 0x0c gs 0xf68 */
	uint32_t f10;                /* 0x10 gs 0xf98 */
	uint8_t f14;                 /* 0x14 gs 0xed4 */
	char sn[32];                 /* 0x15 */
	char name[32];               /* 0x35 */
	uint8_t esb_master_addr;     /* 0x55 */
	uint8_t esb_slave_addr;      /* 0x56 */
	uint8_t f57;                 /* 0x57 gs 0x10a8 */
	uint8_t f58;                 /* 0x58 gs 0x10a9 */
	uint32_t f5c;                /* 0x5c gs 0x10b4 */
	uint16_t f60;                /* 0x60 gs 0x108a */
	uint16_t f62;                /* 0x62 gs 0x108c */
	uint32_t f64;                /* 0x64 gs 0xfa8 */
	uint32_t f68;                /* 0x68 gs 0xfa4 */
	uint32_t f6c;                /* 0x6c gs 0xfac */
	uint32_t f70;                /* 0x70 gs 0xfb0 */
	uint16_t f74;                /* 0x74 gs 0xeda */
	uint16_t f76;                /* 0x76 gs 0xedc */
	uint16_t f78;                /* 0x78 gs 0xede */
	uint32_t f7c;                /* 0x7c gs 0xfb4 */
	uint32_t f80;                /* 0x80 gs 0xfb8 */
	struct triple f84;           /* 0x84 gs 0x10bc */
	uint32_t f90;                /* 0x90 gs 0x10b0 */
	uint8_t f94;                 /* 0x94 gs 0x10c8 */
	uint8_t f95;                 /* 0x95 gs 0x10d0 */
};
BUILD_ASSERT(sizeof(struct sys_settings) == 0x98);

/* User settings, flash 0x134000 */
struct usr_settings {
	uint8_t display_mode;        /* 0x00 */
	uint8_t brightness_level;    /* 0x01 */
	uint8_t wakeup_angle;        /* 0x02 */
	uint8_t dof3_enable;         /* 0x03 */
	uint32_t f04;                /* 0x04 gs 0xf70 */
	uint8_t f08;                 /* 0x08 gs 0xf9c */
	uint8_t f09;                 /* 0x09 gs 0x1088 */
	uint8_t f0a;                 /* 0x0a gs 0x10d4 */
	uint8_t f0b;                 /* 0x0b gs 0xec0 */
	struct pk7 f0c;              /* 0x0c gs 0x1081 */
	uint8_t f13;                 /* 0x13 gs 0xef9 */
	uint8_t f14;                 /* 0x14 gs 0x10d6 */
	uint8_t f15;                 /* 0x15 gs 0x10d8 */
	uint8_t f16;                 /* 0x16 gs 0x10d9 */
	uint8_t test_mode;           /* 0x17 */
	uint8_t f18;                 /* 0x18 gs 0xec1 */
	uint8_t f19;                 /* 0x19 gs 0x10d7 */
	uint8_t f1a;                 /* 0x1a gs 0x1244 */
	uint32_t f1c;                /* 0x1c gs 0xf6c */
	uint8_t f20;                 /* 0x20 dashboard_ts 0x5f */
	uint16_t f22;                /* 0x22 gs 0xee0 */
	struct u8pair f24;           /* 0x24 gs 0x1246 */
	uint8_t reserved[6];
};
BUILD_ASSERT(sizeof(struct usr_settings) == 0x2c);

#define SYS_SETTINGS_ADDR   0x130000
#define USR_SETTINGS_ADDR   0x134000
#define BURIAL_POINT_ADDR   0x135000

#include "gs_view.h"

struct GlassesState *get_dashboard_state(void);
extern struct GlassesState *GLOBAL_STATE;

#define FLASH_DEV DEVICE_DT_GET(DT_NODELABEL(mx25r64))

/* plain vendor print (no LOG_LEVEL gate) */
#define G1_PRINT(fmt, ...)                                   \
	do {                                                 \
		if (BLE_DEBUG) {                             \
			ble_printk(fmt, ##__VA_ARGS__);      \
		} else {                                     \
			printk(fmt, ##__VA_ARGS__);          \
		}                                            \
	} while (0)

/* other modules */
uint8_t *FUN_00036268(void); /* BLE whitelist buffer */
uint8_t FUN_00033d5c(void);  /* test mode get */
void set_test_mode(uint8_t mode);
uint16_t FUN_000811a0(uint16_t crc, const uint8_t *buf, int len);
int watchdog_feed(void); /* threads/watchdog.c */
void FUN_000806c6(struct countdown_ts_context *ctx);
void FUN_00038b00(void);
void cleanStocksIndex(void);
void cleanNewsIndex(void);
void cleanCalenadrIndex(void);
void delAudioStreamRecord(int idx);
void deinit_ncs_memory(void);
void set_shipmode(int enter);
extern uint8_t DAT_2000304f;
extern uint8_t DAT_20019a5e;

/* local_settings.c */
int local_store_write(const char *key, const void *val, size_t len);
void sett_init(struct local_store *st);

/* flash_settings.c */
extern char SERIAL_NUMBER[32];
extern char glasses_name[32];
int flash_settings_read(uint32_t addr, void *buf, size_t len);
int flash_settings_write_and_verify(uint32_t addr, const void *data, size_t len);
int FUN_0007f556(struct GlassesState *gs, int unused);
int clear_user_settings(struct GlassesState *gs);
int save_sys_settings(struct GlassesState *gs, int force);
int load_sys_setting(struct GlassesState *gs);
int load_usr_setting(struct GlassesState *gs);
int load_burial_point(struct GlassesState *gs);

void FUN_0007ff66(struct GlassesState *gs, int arg);
void change_work_mode(int mode);
void get_demo_image_source_from_flash(void);
void update_persist_task_status(struct GlassesState *gs, int task, int status);
int getAudioMessageQueueNum(void);
void audioStreamFileManagerHandler(void);
int write_font(uint32_t addr, const void *data, size_t len);
int update_burial_point_to_flash(struct GlassesState *gs);

/* file_storage.c */
extern struct k_sem flash_ops_sem;
extern uint32_t LAST_FILE_CRC;
extern uint8_t sys_settings_dirty;

/* QuickNote context behind GLOBAL_STATE->quicknote (partial) */
#define QUICKNOTE_TITLE_LEN 0x29
#define QUICKNOTE_TEXT_LEN  0x119
struct quicknote {
	uint8_t f0;
	uint8_t title[QUICKNOTE_TITLE_LEN];
	uint8_t text[QUICKNOTE_TEXT_LEN];
};
struct quicknote_ctx {
	uint8_t hdr[3];
	struct quicknote notes[4];
};

/* setting_store.c */
struct app_setting {
	uint8_t magic;
	uint8_t language;
	uint8_t startup_mode;
};
extern volatile struct app_setting CURRENT_LANGUAGE;
void storage_commit_request(int cmd, uint8_t sys_dirty);
int upgradeDashboardStartupModeInfoToFlash(uint8_t mode);
int upgradeDoubleTapCustomizeToFlash(uint32_t mode);

/* setting_store.c / quicknote_store.c */
int getSettingStorageQueueNum(void);
int SettingStoreHandler(void);
int getQuickNoteQueueNum(void);
unsigned int QuickNoteStoreHandler(void);
int cleanAppLanguageInfo(void);
int cleanDashBoardStartUpModeInfo(void);
int deleteQuickNoteData(int index);

#endif /* STORAGE_H_ */

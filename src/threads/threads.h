/*
 * "threads" module (dispatch threads, key events, watchdog, master/slave
 * sync, message state) - private types and prototypes.
 * Reconstructed from the G1 v1.63 app core.
 */
#ifndef G1_THREADS_H_
#define G1_THREADS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <g1_date.h>
#include <zephyr/device.h>


/* BLE context (GlassesState + 0x77c), only the fields used here (see src/ble/ble_ancs.h) */
struct ble_context {
	uint8_t pad_000[0x18];
	uint8_t charging;                        /* 0x018 */
	uint8_t pad_019[0x218 - 0x019];
	struct k_sem rx_sem;                     /* 0x218 */
	struct k_sem sem_230;                    /* 0x230 */
	uint8_t receiver_thd_is_running;         /* 0x248 */
	uint8_t pad_249[3];
};

/* Onboarding task context (GlassesState->onboarding) */
struct onboarding_ctx {
	uint8_t active;                          /* 0x00 */
	uint8_t f_01;                            /* 0x01 */
	uint8_t f_02;                            /* 0x02 */
	uint8_t f_03;                            /* 0x03 */
	int64_t ts;                              /* 0x04 */
	uint8_t f_0c;                            /* 0x00c */
	uint8_t f_0d;                            /* 0x00d */
	uint8_t f_0e;                            /* 0x00e */
	uint8_t pad_00f[0x020 - 0x00f];
	uint8_t saved_brightness;                /* 0x20 */
} __packed;

/* GlassesState->dashboard_ts (partial; see src/main.h) */
struct dashboard_ts_context {
	uint32_t ts;                             /* 0x00 */
	uint8_t pad_004[0x066 - 0x004];
	uint8_t f_66;                            /* 0x066 */
	uint8_t pad_067[0x072 - 0x067];
	uint8_t f_72;                            /* 0x72 */
	uint8_t f_73;                            /* 0x73 */
	uint8_t f_74;                            /* 0x74 */
} __packed;

/*
 * Task / feature state blocks behind the GlassesState + 0x1000..0x1034 pointers
 * (0x1000: 0x217 B, 0x1004: 0xf5 B, 0x1008/0x100c: 0x1e8 B, 0x1010: 0x1e9 B, ...).
 */
struct task_blk {
	uint8_t f_00;                            /* 0x00 */
	uint8_t f_01;                            /* 0x01 */
	uint8_t f_02;                            /* 0x02 */
	uint8_t f_03;                            /* 0x03 */
	uint8_t f_04;                            /* 0x04 */
	uint8_t f_05;                            /* 0x05 */
	uint8_t f_06;                            /* 0x06 */
	uint8_t f_07;                            /* 0x07 */
	uint8_t data[0x200 - 8 + 1];             /* 0x08 (0x200: sequence id of the slave task blocks) */
};

/* message slot returned by FUN_00035260 (g_arrMsgContent entry) */
struct msg_content {
	uint8_t pad_00[0x0c];
	uint8_t f_0c;                            /* 0x0c */
	uint8_t pad_0d[3];
	uint8_t f_10;                            /* 0x10 */
};

/* print without the LOG_LEVEL check / "%s(): " prefix */
#define G1_PRINTK(fmt, ...) \
	do { if (BLE_DEBUG) ble_printk(fmt, ##__VA_ARGS__); else printk(fmt, ##__VA_ARGS__); } while (0)

/* GlassesState + 0x1068: current persist task */
struct msg_status {
	uint32_t task;                           /* 0x00 */
	uint8_t status;                          /* 0x04 */
} __packed;

struct fw_ver {
	uint8_t major;
	uint8_t minor;
	uint8_t patch;
};

/* master -> slave ESB packet (GlassesState + 0x6cc, 22 bytes) */
struct esb_pkt {
	uint8_t cmd;                             /* 0x00: cmd | 0x80 */
	struct fw_ver ver;                       /* 0x01 */
	uint8_t battery;                         /* 0x04 */
	uint8_t pad_05[0x0c - 0x05];
	uint8_t mac[6];                          /* 0x0c */
	uint8_t flags;                           /* 0x12 */
	uint8_t data[2];                         /* 0x13 */
	uint8_t seq;                             /* 0x15 */
} __packed;

typedef int (*esb_send_fn)(void *data, int len);

/* quick-note / message sync item (FUN_0003519c) */
struct note_item {
	uint8_t pad_00[8];
	uint32_t id;                             /* 0x08 */
	uint8_t idx;                             /* 0x0c */
	uint8_t state;                           /* 0x0d */
	uint8_t pad_0e[0xda - 0x0e];
	uint8_t data2[0xda];                     /* 0xda */
};

/* GlassesState + 0xb6c */
struct pm_ops {
	void *priv;                              /* 0x00 */
	void (*suspend)(struct pm_ops *ops);     /* 0x04 */
	void (*resume)(struct pm_ops *ops);      /* 0x08 */
};


/* GlassesState + 0xee8: new message / notification display context */
struct message_ctx {
	uint8_t state;                           /* 0x00 */
};

struct pk_u16 {
	uint16_t v;
} __packed;

/* Partial view of the global vendor state behind GLOBAL_STATE */
/* GlassesState + 0xff4 */
struct ff4_ctx {
	uint32_t ts;                             /* 0x00 */
	uint8_t f_04;                            /* 0x04 */
	uint8_t f_05;                            /* 0x05 */
	uint8_t f_06;                            /* 0x06 */
};

/* GlassesState + 0xff8 (0x16a bytes copied from BLE request 8) */
struct ff8_buf {
	uint8_t data[0x164];
	uint32_t ts;                             /* 0x164 */
	uint8_t tail[2];
};

/* BEGIN GlassesState */
struct GlassesState {
	uint8_t is_master;                       /* 0x000 */
	uint8_t work_mode;                       /* 0x001 */
	uint8_t esb_channel;                     /* 0x002 */
	uint8_t pad_003[0x020 - 0x003];
	struct k_sem sem_1;                      /* 0x020 */
	struct k_sem sem_2;                      /* 0x038 */
	struct k_sem screen_on_sem;              /* 0x050 */
	struct k_sem refresh_sem;                 /* 0x068 */
	struct k_sem dashboard_position_sem;     /* 0x080 */
	uint8_t pad_098[0x0b0 - 0x098];
	struct k_sem touch_sem;                  /* 0x0b0 */
	uint8_t pad_0c8[0x0c9 - 0x0c8];
	union {
		uint8_t sync_flags;              /* 0x0c9 */
		struct {
			uint8_t low : 6;
			uint8_t mode : 2;
		} sync_flag_bits;
	};
	uint8_t f_0ca;                            /* 0x0ca */
	uint8_t f_0cb;                           /* 0x0cb */
	uint8_t f_0cc;                           /* 0x0cc */
	uint8_t f_0cd;                           /* 0x0cd */
	uint8_t f_0ce;                           /* 0x0ce */
	uint8_t f_0cf;                           /* 0x0cf */
	uint32_t sync_date;                      /* 0x0d0 */
	union {
		uint8_t sync_cmd;                /* 0x0d4 */
		struct {
			uint8_t cmd : 6;
			uint8_t st : 2;
		} sync_hdr;
	};
	volatile uint8_t dashboard_mode;         /* 0x0d5 */
	uint16_t sync_d6;                        /* 0x0d6 */
	uint16_t sync_d8;                        /* 0x0d8 */
	uint8_t sync_seq;                        /* 0x0da */
	uint8_t f_0db;                           /* 0x0db */
	uint8_t f_0dc;                            /* 0x0dc */
	uint8_t f_0dd;                           /* 0x0dd */
	uint8_t f_0de;                           /* 0x0de */
	struct msg_status sync_status;           /* 0x0df */
	uint8_t f_0e4;                           /* 0x0e4 */
	uint8_t sync_data[4];                    /* 0x0e5 */
	uint8_t f_0e9;                           /* 0x0e9 */
	uint8_t f_0ea;                           /* 0x0ea */
	uint8_t f_0eb;                           /* 0x0eb */
	uint8_t f_0ec;                           /* 0x0ec */
	struct pk_u16 buf_len;                   /* 0x0ed */
	uint8_t buf_0ef[0x5dc];                  /* 0x0ef */
	uint8_t pad_6cb[0x6cc - 0x6cb];
	struct esb_pkt esb_pkt;                  /* 0x6cc */
	uint8_t pad_6e2[0x774 - 0x6e2];
	esb_send_fn esb_send;                    /* 0x774 */
	uint8_t pad_778[0x77c - 0x778];
	struct ble_context ble_context;          /* 0x77c */
	uint8_t pad_9c8[0xae2 - 0x9c8];
	uint8_t f_ae2;                           /* 0xae2 */
	uint8_t f_ae3;                            /* 0xae3 */
	uint32_t f_ae4;                          /* 0xae4 */
	uint8_t pad_ae8[0xaf4 - 0xae8];
	struct k_sem imu_sem;                    /* 0xaf4 */
	uint8_t f_b0c;                           /* 0xb0c */
	uint8_t f_b0d;                            /* 0xb0d */
	uint8_t pad_b0e[0xb6c - 0xb0e];
	struct pm_ops pm;                        /* 0xb6c */
	uint8_t pad_b78[0xb8c - 0xb78];
	void (*set_brightness)(struct pm_ops *ops, uint8_t level); /* 0xb8c */
	uint8_t pad_b90[0xeb4 - 0xb90];
	int f_eb4;                               /* 0xeb4 */
	uint32_t f_eb8;                          /* 0xeb8 */
	uint8_t pad_ebc[0xec0 - 0xebc];
	uint8_t panel_raster_height_offset;      /* 0xec0 */
	uint8_t panel_canvas_distance_gear;      /* 0xec1 */
	uint8_t pad_ec2[0xec4 - 0xec2];
	int panel_ec4;                           /* 0xec4 */
	uint32_t f_ec8;                          /* 0xec8 */
	uint32_t f_ecc;                          /* 0xecc */
	uint8_t pad_ed0[0xed5 - 0xed0];
	uint8_t panel_brightness;                /* 0xed5 */
	uint8_t f_ed6;                           /* 0xed6 */
	uint8_t f_ed7;                           /* 0xed7 */
	uint8_t pad_ed8[0xee8 - 0xed8];
	struct message_ctx msg_ctx;              /* 0xee8 */
	uint8_t pad_ee9[0xeec - 0xee9];
	uint32_t imu_on;                         /* 0xeec */
	uint8_t pad_ef0[0xef8 - 0xef0];
	uint8_t f_ef8;                            /* 0xef8 */
	uint8_t f_ef9;                            /* 0xef9 */
	uint8_t pad_efa[0xf64 - 0xefa];
	uint8_t f_f64;                            /* 0xf64 */
	uint8_t pad_f65[0xf80 - 0xf65];
	void (*msg_notify)(struct message_ctx *ctx, int code); /* 0xf80 */
	uint8_t opt3007_ctx[0x10];               /* 0xf84 */
	uint32_t f_f94;                          /* 0xf94 */
	uint8_t pad_f98[0xf9c - 0xf98];
	uint8_t f_f9c;                           /* 0xf9c */
	uint8_t pad_f9d[0xfc4 - 0xf9d];
	uint8_t battery_info[4];                 /* 0xfc4 */
	uint8_t battery_voltage;                 /* 0xfc8 */
	uint8_t battery_current;                 /* 0xfc9 */
	uint8_t f_fca;                            /* 0xfca */
	uint8_t pad_fcb[0xfcc - 0xfcb];
	int8_t f_fcc;                            /* 0xfcc */
	uint8_t pad_fcd[0xfd0 - 0xfcd];
	uint8_t f_fd0[3];                         /* 0xfd0 */
	struct fw_ver fw_ver;                    /* 0xfd3 */
	uint8_t pad_fd6[0xfde - 0xfd6];
	uint8_t master_mac[6];                    /* 0xfde */
	uint8_t slave_mac[6];                    /* 0xfe4 */
	uint8_t suspend_state;                   /* 0xfea */
	uint8_t f_feb;                           /* 0xfeb */
	uint8_t screen_on;                       /* 0xfec */
	uint8_t f_fed;                           /* 0xfed */
	uint8_t f_fee;                           /* 0xfee */
	uint8_t pad_fef[0xff0 - 0xfef];
	struct dashboard_ts_context *dashboard_ts; /* 0xff0 */
	void *ptr_ff4;                           /* 0xff4 */
	void *ptr_ff8;                           /* 0xff8 */
	uint8_t *task_ffc;                       /* 0xffc */
	struct task_blk *task_1000;              /* 0x1000 */
	struct task_blk *task_1004;              /* 0x1004 */
	struct task_blk *task_1008;              /* 0x1008 */
	struct task_blk *task_100c;              /* 0x100c */
	struct task_blk *task_1010;              /* 0x1010 */
	struct task_blk *task_1014;              /* 0x1014 */
	struct task_blk *task_1018;              /* 0x1018 */
	struct onboarding_ctx *onboarding;       /* 0x101c */
	struct task_blk *task_1020;              /* 0x1020 */
	struct task_blk *task_1024;              /* 0x1024 */
	struct task_blk *task_1028;              /* 0x1028 */
	struct task_blk *task_102c;              /* 0x102c */
	struct task_blk *task_1030;              /* 0x1030 */
	struct task_blk *task_1034;              /* 0x1034 */
	struct task_blk *task_1038;              /* 0x1038 */
	struct task_blk *task_103c;              /* 0x103c */
	void (*fn_1040)(struct k_sem *sem);       /* 0x1040 */
	int (*ext_flash_read)(struct GlassesState *state, uint32_t addr, void *buf, uint32_t len); /* 0x1044 */
	uint8_t pad_1048[0x1060 - 0x1048];
	uint32_t dashboard_cmd;                  /* 0x1060 */
	uint8_t pad_1064[0x1068 - 0x1064];
	struct msg_status *f_1068;               /* 0x1068 */
	uint8_t pad_106c[0x106e - 0x106c];
	uint8_t sync_ack;                        /* 0x106e */
	uint8_t pad_106f[0x1070 - 0x106f];
	uint16_t module_mask;                    /* 0x1070 */
	uint8_t pad_1072[0x1078 - 0x1072];
	int64_t last_sync_ts;                    /* 0x1078 */
	uint8_t f_1080;                          /* 0x1080 */
	uint8_t pad_1081[0x1089 - 0x1081];
	uint8_t force_bind;                      /* 0x1089 */
	uint16_t f_108a;                         /* 0x108a */
	uint16_t f_108c;                         /* 0x108c */
	uint8_t pad_108e[0x1090 - 0x108e];
	int32_t aw_diff;                         /* 0x1090 */
	uint8_t pad_1094[0x10a0 - 0x1094];
	uint8_t f_10a0;                          /* 0x10a0 */
	uint8_t pad_10a1[0x10c8 - 0x10a1];
	uint8_t f_10c8;                          /* 0x10c8 */
	uint8_t pad_10c9[0x10d5 - 0x10c9];
	uint8_t f_10d5;                          /* 0x10d5 */
	uint8_t message_mode;                          /* 0x10d6 */
	uint8_t message_stay_time;                          /* 0x10d7 */
	uint8_t pad_10d8[0x1244 - 0x10d8];
	uint8_t f_1244;                          /* 0x1244 */
	uint8_t f_1245;                          /* 0x1245 */
	uint8_t f_1246;                          /* 0x1246 */
	uint8_t f_1247;                          /* 0x1247 */
} __aligned(8);
BUILD_ASSERT(offsetof(struct GlassesState, is_master) == 0x0);
BUILD_ASSERT(offsetof(struct GlassesState, work_mode) == 0x1);
BUILD_ASSERT(offsetof(struct GlassesState, esb_channel) == 0x2);
BUILD_ASSERT(offsetof(struct GlassesState, screen_on_sem) == 0x50);
BUILD_ASSERT(offsetof(struct GlassesState, sync_flags) == 0xc9);
BUILD_ASSERT(offsetof(struct GlassesState, f_0cc) == 0xcc);
BUILD_ASSERT(offsetof(struct GlassesState, f_0cd) == 0xcd);
BUILD_ASSERT(offsetof(struct GlassesState, f_0ce) == 0xce);
BUILD_ASSERT(offsetof(struct GlassesState, f_0cf) == 0xcf);
BUILD_ASSERT(offsetof(struct GlassesState, sync_date) == 0xd0);
BUILD_ASSERT(offsetof(struct GlassesState, sync_cmd) == 0xd4);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_mode) == 0xd5);
BUILD_ASSERT(offsetof(struct GlassesState, sync_d6) == 0xd6);
BUILD_ASSERT(offsetof(struct GlassesState, sync_d8) == 0xd8);
BUILD_ASSERT(offsetof(struct GlassesState, sync_seq) == 0xda);
BUILD_ASSERT(offsetof(struct GlassesState, f_0db) == 0xdb);
BUILD_ASSERT(offsetof(struct GlassesState, f_0dd) == 0xdd);
BUILD_ASSERT(offsetof(struct GlassesState, f_0e4) == 0xe4);
BUILD_ASSERT(offsetof(struct GlassesState, sync_data) == 0xe5);
BUILD_ASSERT(offsetof(struct GlassesState, f_0e9) == 0xe9);
BUILD_ASSERT(offsetof(struct GlassesState, f_0ea) == 0xea);
BUILD_ASSERT(offsetof(struct GlassesState, f_0eb) == 0xeb);
BUILD_ASSERT(offsetof(struct GlassesState, f_0ec) == 0xec);
BUILD_ASSERT(offsetof(struct GlassesState, buf_0ef) == 0xef);
BUILD_ASSERT(offsetof(struct GlassesState, esb_pkt) == 0x6cc);
BUILD_ASSERT(offsetof(struct GlassesState, esb_send) == 0x774);
BUILD_ASSERT(offsetof(struct GlassesState, ble_context) == 0x77c);
BUILD_ASSERT(offsetof(struct GlassesState, imu_sem) == 0xaf4);
BUILD_ASSERT(offsetof(struct GlassesState, f_b0c) == 0xb0c);
BUILD_ASSERT(offsetof(struct GlassesState, pm) == 0xb6c);
BUILD_ASSERT(offsetof(struct GlassesState, f_eb8) == 0xeb8);
BUILD_ASSERT(offsetof(struct GlassesState, panel_brightness) == 0xed5);
BUILD_ASSERT(offsetof(struct GlassesState, msg_ctx) == 0xee8);
BUILD_ASSERT(offsetof(struct GlassesState, imu_on) == 0xeec);
BUILD_ASSERT(offsetof(struct GlassesState, f_f9c) == 0xf9c);
BUILD_ASSERT(offsetof(struct GlassesState, battery_info) == 0xfc4);
BUILD_ASSERT(offsetof(struct GlassesState, battery_voltage) == 0xfc8);
BUILD_ASSERT(offsetof(struct GlassesState, fw_ver) == 0xfd3);
BUILD_ASSERT(offsetof(struct GlassesState, slave_mac) == 0xfe4);
BUILD_ASSERT(offsetof(struct GlassesState, suspend_state) == 0xfea);
BUILD_ASSERT(offsetof(struct GlassesState, screen_on) == 0xfec);
BUILD_ASSERT(offsetof(struct GlassesState, f_fed) == 0xfed);
BUILD_ASSERT(offsetof(struct GlassesState, f_fee) == 0xfee);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, task_ffc) == 0xffc);
BUILD_ASSERT(offsetof(struct GlassesState, task_1000) == 0x1000);
BUILD_ASSERT(offsetof(struct GlassesState, task_1004) == 0x1004);
BUILD_ASSERT(offsetof(struct GlassesState, task_1008) == 0x1008);
BUILD_ASSERT(offsetof(struct GlassesState, task_100c) == 0x100c);
BUILD_ASSERT(offsetof(struct GlassesState, task_1010) == 0x1010);
BUILD_ASSERT(offsetof(struct GlassesState, task_1014) == 0x1014);
BUILD_ASSERT(offsetof(struct GlassesState, task_1018) == 0x1018);
BUILD_ASSERT(offsetof(struct GlassesState, onboarding) == 0x101c);
BUILD_ASSERT(offsetof(struct GlassesState, task_1020) == 0x1020);
BUILD_ASSERT(offsetof(struct GlassesState, task_1024) == 0x1024);
BUILD_ASSERT(offsetof(struct GlassesState, task_1028) == 0x1028);
BUILD_ASSERT(offsetof(struct GlassesState, task_102c) == 0x102c);
BUILD_ASSERT(offsetof(struct GlassesState, task_1030) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, task_1034) == 0x1034);
BUILD_ASSERT(offsetof(struct GlassesState, f_1068) == 0x1068);
BUILD_ASSERT(offsetof(struct GlassesState, sync_ack) == 0x106e);
BUILD_ASSERT(offsetof(struct GlassesState, module_mask) == 0x1070);
BUILD_ASSERT(offsetof(struct GlassesState, last_sync_ts) == 0x1078);
BUILD_ASSERT(offsetof(struct GlassesState, force_bind) == 0x1089);
BUILD_ASSERT(offsetof(struct GlassesState, f_108a) == 0x108a);
BUILD_ASSERT(offsetof(struct GlassesState, f_108c) == 0x108c);
BUILD_ASSERT(offsetof(struct GlassesState, message_stay_time) == 0x10d7);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_position_sem) == 0x80);
BUILD_ASSERT(offsetof(struct GlassesState, touch_sem) == 0xb0);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_cmd) == 0x1060);
BUILD_ASSERT(offsetof(struct GlassesState, aw_diff) == 0x1090);
BUILD_ASSERT(offsetof(struct GlassesState, f_1244) == 0x1244);
BUILD_ASSERT(offsetof(struct GlassesState, f_1245) == 0x1245);
BUILD_ASSERT(offsetof(struct dashboard_ts_context, f_72) == 0x72);
BUILD_ASSERT(offsetof(struct onboarding_ctx, f_0c) == 0xc);
BUILD_ASSERT(offsetof(struct onboarding_ctx, f_0d) == 0xd);
BUILD_ASSERT(offsetof(struct onboarding_ctx, f_0e) == 0xe);
BUILD_ASSERT(offsetof(struct GlassesState, sem_1) == 0x20);
BUILD_ASSERT(offsetof(struct GlassesState, sem_2) == 0x38);
BUILD_ASSERT(offsetof(struct GlassesState, f_0cb) == 0xcb);
BUILD_ASSERT(offsetof(struct GlassesState, sync_status) == 0xdf);
BUILD_ASSERT(offsetof(struct GlassesState, buf_len) == 0xed);
BUILD_ASSERT(offsetof(struct GlassesState, f_eb4) == 0xeb4);
BUILD_ASSERT(offsetof(struct GlassesState, panel_raster_height_offset) == 0xec0);
BUILD_ASSERT(offsetof(struct GlassesState, panel_canvas_distance_gear) == 0xec1);
BUILD_ASSERT(offsetof(struct GlassesState, panel_ec4) == 0xec4);
BUILD_ASSERT(offsetof(struct GlassesState, f_ec8) == 0xec8);
BUILD_ASSERT(offsetof(struct GlassesState, f_ecc) == 0xecc);
BUILD_ASSERT(offsetof(struct GlassesState, f_ed6) == 0xed6);
BUILD_ASSERT(offsetof(struct GlassesState, f_ed7) == 0xed7);
BUILD_ASSERT(offsetof(struct GlassesState, opt3007_ctx) == 0xf84);
BUILD_ASSERT(offsetof(struct GlassesState, f_f94) == 0xf94);
BUILD_ASSERT(offsetof(struct GlassesState, f_feb) == 0xfeb);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_ff4) == 0xff4);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_ff8) == 0xff8);
BUILD_ASSERT(offsetof(struct GlassesState, task_1038) == 0x1038);
BUILD_ASSERT(offsetof(struct GlassesState, task_103c) == 0x103c);
BUILD_ASSERT(offsetof(struct GlassesState, message_mode) == 0x10d6);
BUILD_ASSERT(offsetof(struct GlassesState, refresh_sem) == 0x68);
BUILD_ASSERT(offsetof(struct GlassesState, f_ae3) == 0xae3);
BUILD_ASSERT(offsetof(struct GlassesState, set_brightness) == 0xb8c);
BUILD_ASSERT(offsetof(struct GlassesState, f_ef8) == 0xef8);
BUILD_ASSERT(offsetof(struct GlassesState, f_ef9) == 0xef9);
BUILD_ASSERT(offsetof(struct GlassesState, f_f64) == 0xf64);
BUILD_ASSERT(offsetof(struct GlassesState, f_fca) == 0xfca);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd0) == 0xfd0);
BUILD_ASSERT(offsetof(struct GlassesState, master_mac) == 0xfde);
BUILD_ASSERT(offsetof(struct GlassesState, fn_1040) == 0x1040);
BUILD_ASSERT(offsetof(struct GlassesState, ext_flash_read) == 0x1044);
BUILD_ASSERT(offsetof(struct dashboard_ts_context, f_66) == 0x66);
BUILD_ASSERT(offsetof(struct GlassesState, f_0ca) == 0xca);
BUILD_ASSERT(offsetof(struct GlassesState, f_0dc) == 0xdc);
BUILD_ASSERT(offsetof(struct GlassesState, f_b0d) == 0xb0d);
BUILD_ASSERT(offsetof(struct GlassesState, msg_notify) == 0xf80);
BUILD_ASSERT(offsetof(struct GlassesState, f_fcc) == 0xfcc);
BUILD_ASSERT(offsetof(struct GlassesState, f_10c8) == 0x10c8);
BUILD_ASSERT(offsetof(struct GlassesState, f_10a0) == 0x10a0);
BUILD_ASSERT(offsetof(struct GlassesState, f_0de) == 0xde);
BUILD_ASSERT(offsetof(struct GlassesState, f_ae2) == 0xae2);
BUILD_ASSERT(offsetof(struct GlassesState, f_ae4) == 0xae4);
BUILD_ASSERT(offsetof(struct GlassesState, f_1080) == 0x1080);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d5) == 0x10d5);
/* END GlassesState */

/* watchdog.c */
extern int wdt_0_channel_id;
int init_watchdog(void);
int watchdog_feed(void);
int watchdog_disable(void);

/* threads.c */
extern uint8_t DAT_2000304f;
extern uint8_t wear_state_event;
extern uint8_t DAT_20019a5e;
extern struct k_sem nfc_msg_sem;
void trigger_key_event(void);
void trigger_nfc_event(void);
int64_t nfc_deadline_set(uint32_t ms);
void update_activity_time(void);
void exit_silent_mode(void);
void enter_silent_mode(void);
void check_sw0_status(void);
void report_event_to_phone(int cmd);
/* old Ghidra names (aliases in threads.c) until the callers in other modules are renamed */
void FUN_00029774(int cmd);
int64_t FUN_0002c6f4(uint32_t ms);
void FUN_0002c8a4(void);
uint8_t get_glasses_ble_status(void);
uint8_t FUN_00028d2c(void); /* old name, alias of get_glasses_ble_status */

/* task_status.c */
int process_for_new_message_come_on(struct GlassesState *state, struct message_ctx *ctx);
int update_persist_task_status(struct GlassesState *state, int task, int status);
int global_system_suspend(struct GlassesState *state);
int global_system_resume(struct GlassesState *state);

extern uint8_t task_status_lock;
int trigger_screen_state_change(const char *who, struct GlassesState *state, uint8_t on);
int FUN_0008027a(void *dev, struct GlassesState *state, uint32_t on);
uint8_t FUN_0002d9e8(struct GlassesState *state, int mode);
int FUN_0002da10(struct GlassesState *state);
int update_temp_task_status(struct GlassesState *state, int task, int status);
int update_persist_task_status_to_idle(struct GlassesState *state);
int update_persist_task_status_to_wait_blow_head(struct GlassesState *state);
bool FUN_0002dd80(int task);
int sync_message_signal_to_slave(uint8_t signal);
bool is_idle(void);
void FUN_00080338(int clear);
void FUN_00080224(struct GlassesState *state, int flag);

/* threads.c (sync) */
extern uint8_t DAT_20019a5b;
int sync_to_slave(struct GlassesState *state, int cmd, void *data, size_t len);
unsigned int sync_to_master(struct GlassesState *state, int cmd, void *data, size_t len);
unsigned int FUN_000294d0(struct GlassesState *state, int cmd, void *data, size_t len); /* old name, alias of sync_to_master */

/* thread entry points (threads.c) */
void init_threads(struct GlassesState *state);

extern uint8_t msg_busy;

void FUN_0007ff16(void);
void FUN_0007ff66(struct GlassesState *state, int notify);
void FUN_000800ca(struct GlassesState *state, int notify);

void FUN_0002df6c(void);
uint32_t FUN_0002df54(int type, uint32_t def);
void check_disp_quicknote(void);

/* other modules */
uint8_t FUN_00033d5c(void);
void display_DelayClose(int ms);
int clear_timeout_message(int arg);
void FUN_000359fc();  /* really (void); task_status.c passes a dead arg */
void FUN_00080806(uint8_t arg);
int FUN_000169b4(void);   /* main.c returns uint8_t; callers here re-extend */
struct note_item *FUN_0003519c(void);
void FUN_00035204(uint8_t idx, int state);
void confirm_message(uint32_t id);
void start_flash_storage_threads(struct GlassesState *state);
void start_proxy_thread_handler(struct GlassesState *state);
void start_display_thread_handler(struct GlassesState *state);
void start_aging_mode_thread(void);
void start_mic_transm_thread(void);
uint8_t FUN_00035310(void);
uint8_t FUN_00035a78(void);
uint8_t FUN_00035acc(void);
uint8_t g_arrMsgContent_count(void);
void FUN_00035abc(int arg);
struct msg_content *FUN_00035260(int idx);
struct GlassesState *get_dashboard_state(void);
struct ble_context *get_ble_context(void);
int enqueue_bt_data(void *data, uint8_t len);
struct bt_conn *FUN_00019cec(void);   /* current connection */
bool FUN_00017f30(void);
bool FUN_0007f3da(void);
void aw93203_init(void);
int fuel_gauge_update(const struct device *dev, int arg);
void FUN_00027744(void);
void FUN_00033e2c(uint8_t v);
void FUN_00030458(void);
void FUN_000344c8(void);
void FUN_00080992(void);
void FUN_00042830(void);
int onboarding_sync_data(uint8_t *data, int len);
void change_work_mode(int mode);
void display_close_screen(int arg);
void FUN_0004b340(void);
void FUN_00080fca(uint8_t mode);
unsigned int FUN_00027664(void);
int is_box_lid_closed(void);
extern uint8_t DAT_2001db40;
extern uint8_t demo_mode;

/* check_work_mode */
extern int DAT_20006bc8;                      /* main.c: ESB signal / package counter */
void check_work_mode(int in_box, int lid_closed, uint8_t report);
int32_t aw9320x_read_chipid(void);
uint8_t is_box_charging(void);
uint8_t FUN_00033754(void);
uint8_t FUN_00033760(void);
void FUN_00081230(void);
void enter_wear_burial_point(void);

/* msg_sync_thread */
extern uint8_t DAT_2001093b;                  /* main.c: new message flag */
uint8_t FUN_00030440(void);

/* product_test_touch_key_thread */
uint8_t FUN_00033e38(void);
uint8_t FUN_00033e20(void);
void FUN_00033e44(void);

/* nfc_related */
enum { BOX_IN_BOX = 0, BOX_LID_CLOSED = 1 };
void set_box_status(uint8_t type, uint8_t status);
int init_nfc_comm(void);
int FUN_00027848(uint8_t *it_status);
int init_serial_comm(void);
int64_t FUN_00033b18(void);

/* low_speed_peripheral_dispatch_thread */
int runtime_info_sync(struct GlassesState *gs);
void FUN_00035270(void);
void FUN_000806e4(struct GlassesState *gs, struct dashboard_ts_context *ts);
bool getEraseDFU(void);
int erase_dfu_flash(void);
void setEraseDFU(bool set);

/* threads.c */
extern atomic_t DAT_20008514;
extern atomic_t DAT_20008518;

/* other modules (display / key threads) */
extern uint8_t CURRENT_LANGUAGE;
extern uint8_t deferred_text_ack_cmd;
extern uint32_t DAT_2000aa78;
void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset);
void set_brightness_to_panel_reg_in_running(uint8_t level);
int upgradeDashboardStartupModeInfoToFlash(uint8_t mode);
int upgradeAppLanguageInfoToFlash(uint8_t language);
int upgradeDoubleTapCustomizeToFlash(uint32_t mode);
int upgradeLongpressTapCustomizeToFlash(uint32_t mode);
int FUN_00038ae4(int idx);
int setStocksIndex(int idx);
int setNewsIndex(int idx);
int setCalenadrIndex(int idx);
int display_inputEvent(uint8_t a, uint8_t b);
int display_MasterSendClose(void);
int display_powerEvent(int on);
void FUN_0003f1bc(int val);
void FUN_00044b24(void);
int thunk_FUN_00045444(void);
void FUN_000359d8(void);
void FUN_0002dd98(void);
uint8_t FUN_0002ddb0(void);
uint8_t FUN_000359cc(void);
uint8_t FUN_00010848(void *opt3007_ctx);
void FUN_00037af4(void *unused, void *cd);
extern int DAT_20006be0;                      /* button.c: AW9320x irq pending */
extern uint8_t DAT_2001c4e8;
typedef enum aw9320x_WEARING { UNKNOWN = 0, IN_EAR = 1, OUT_EAR = 2 } aw9320x_WEARING;
extern aw9320x_WEARING aw9320x_wearing;
struct cap_event_status;
void aw9320x_get_irq_stat();
void aw9320x_diff_get(int32_t *p_diff);
void reset_pmic_on(void);
void reset_pmic_off(void);
void reset_all_usr_data(struct GlassesState *gs, int reboot);
void set_band_for_ESB(uint8_t band);
uint8_t get_pane_mode(void);
uint8_t getNotesIndex(void);
uint8_t getStocksIndex(void);
uint8_t getNewsIndex(void);
uint8_t getCalenadrIndex(void);
void FUN_00035a84(void);
void FUN_00080852(uint8_t val);
int FUN_0002dea8(void);

#endif /* G1_THREADS_H_ */

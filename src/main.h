/*
 * Module-private declarations for src/main.c (partial views of shared
 * vendor structures, reconstructed from the v1.63 app core).
 */
#ifndef G1_MAIN_H_
#define G1_MAIN_H_

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/regulator.h>

struct GlassesState;

/* Copy of the private config struct of drivers/regulator/regulator_npm1300.c */
struct regulator_npm1300_config {
	struct regulator_common_config common;
	const struct device *mfd;
	uint8_t source;
	int32_t retention_uv;
	struct gpio_dt_spec enable_gpios;
	struct gpio_dt_spec retention_gpios;
	struct gpio_dt_spec pwm_gpios;
};

/* Dashboard / clock context (GLOBAL_STATE->dashboard_ts), partial, packed */
struct dashboard_ts_context {
	uint32_t ts;              /* 0x00 */
	uint8_t f_04;             /* 0x04 */
	uint8_t f_05;             /* 0x05 */
	uint64_t f_06;            /* 0x06 */
	uint8_t f_0e[0x25];       /* 0x0e */
	uint8_t f_33[0x2a];       /* 0x33 */
	uint8_t f_5d;             /* 0x5d */
	uint8_t time_disp_mode;   /* 0x5e */
	uint8_t pad_5f[2];
	uint8_t f_61;             /* 0x61 */
	uint8_t f_62;             /* 0x62 */
	uint8_t pad_63;
	uint8_t f_64;             /* 0x64 */
	uint8_t pad_65[0x74 - 0x65];
	uint8_t f_74;             /* 0x74 */
} __packed;

/* Settings backend (GLOBAL_STATE->settings_ctx), partial */
struct settings_ctx {
	void *priv;
	int (*write_cb)(const char *key, const void *value, size_t len);
};

/* first byte of every ESB package */
struct esb_hdr {
	uint8_t cmd : 6;
	uint8_t dir : 2;
};

/* Slave side ESB sync package (21 bytes, sent by the master) */
struct esb_sync_pkt {
	struct esb_hdr hdr;       /* 0x00 */
	volatile uint8_t screen_id; /* 0x01 */
	uint8_t f_02[4];
	uint8_t package_id;       /* 0x06 */
	uint8_t f_07;             /* 0x07 */
	uint8_t f_08;             /* 0x08 */
	uint8_t f_09;             /* 0x09 */
	uint8_t f_0a[6];
	uint8_t flags;            /* 0x10 */
	uint8_t arg[4];           /* 0x11 */
} __packed;

/* Packet from the ESB master (GLOBAL_STATE->esbm_pkt, 22 bytes) */
struct esbm_pkt {
	uint8_t cmd;              /* 0x00 */
	volatile uint8_t f_01[4]; /* 0x01 */
	uint8_t f_05[7];
	uint8_t mac[6];           /* 0x0c */
	uint8_t flags;            /* 0x12 */
	uint8_t subcmd;           /* 0x13 */
	uint8_t value;            /* 0x14 */
	uint8_t seq;              /* 0x15 */
} __packed;

/* IPC endpoint description handed to the IPC service context */
struct ipc_ep_cfg {
	uint8_t id;
	const char *name;
	int (*recv_cb)(struct GlassesState *gs, const uint8_t *data, size_t len);
};

struct ipc_service_context {
	uint8_t priv[0x64];
	int (*register_recv_cb)(struct ipc_ep_cfg *ep);
};

/* spi_interface_t, partial */
struct spi_master_ctx {
	int (*init_cb)(struct spi_master_ctx *ctx);
	uint8_t pad_04[0x10];
	uint32_t is_initialized;  /* 0x14 */
	uint8_t pins[4];          /* 0x18 sck, mosi, miso, cs */
	uint8_t f_1c;             /* 0x1c */
	uint8_t f_1d;             /* 0x1d */
	uint8_t pad_1e[2];
};

/* imu_fusion_context, partial */
struct imu_ctx {
	uint8_t mode;             /* 0x00 */
	uint8_t pad_01[0x1b];
	const struct device *dev; /* 0x1c */
	uint8_t pad_20[0x6c];
	int (*init_cb)(struct imu_ctx *ctx); /* 0x8c */
	uint8_t pad_90[0x0c];
};

struct user_schedule_context {
	uint8_t pad_000[0x164];
	uint32_t f_164;
	uint8_t f_168;
	uint8_t f_169;
};

struct gs_1028 {
	uint32_t f_0;
	uint32_t f_4;
	uint16_t f_8;
};

struct gs_1068 {
	uint32_t state;
	uint8_t f_4;
} __packed;

/* Partial view of the global vendor state behind GLOBAL_STATE (0x1248 bytes) */
struct GlassesState {
	uint8_t is_master;                           /* 0x000 role: 1 master, 2 slave */
	uint8_t work_mode;                           /* 0x001 */
	uint8_t esb_channel;                         /* 0x002 */
	uint8_t esb_master_addr;                     /* 0x003 */
	uint8_t esb_slave_addr;                      /* 0x004 */
	uint8_t pad_005[0x003];
	struct k_sem ipc_sem;                        /* 0x008 sem_0 */
	struct k_sem sem_1;                          /* 0x020 */
	struct k_sem sem_2;                          /* 0x038 */
	struct k_sem sem_3;                          /* 0x050 */
	struct k_sem main_sem;                       /* 0x068 sem_4 */
	struct k_sem dashboard_position_sem;         /* 0x080 */
	struct k_sem sem_7;                          /* 0x098 */
	struct k_sem touch_sem;                      /* 0x0b0 sem_8 */
	uint8_t pad_0c8[0x001];
	struct esb_hdr esb_hdr;                      /* 0x0c9 last accepted command */
	uint8_t esb_arg1;                            /* 0x0ca */
	uint8_t esb_arg2;                            /* 0x0cb */
	uint8_t esb_up_id;                           /* 0x0cc */
	uint8_t esb_down_id;                         /* 0x0cd */
	uint8_t esb_up_recving;                      /* 0x0ce */
	uint8_t esb_down_recving;                    /* 0x0cf */
	uint8_t pad_0d0[0x004];
	struct esb_sync_pkt sync;                    /* 0x0d4 last accepted sync package */
	uint8_t esb_up_seq;                          /* 0x0e9 */
	uint8_t esb_down_seq;                        /* 0x0ea */
	uint8_t esb_dir;                             /* 0x0eb */
	uint8_t esb_screen_id;                       /* 0x0ec */
	uint8_t pad_0ed[0x002];
	uint8_t buf_0ef[0x5dc];                      /* 0x0ef */
	uint8_t pad_6cb[0x001];
	struct esbm_pkt esbm_pkt;                    /* 0x6cc last packet from the master */
	uint8_t pad_6e2[0x002];
	struct ipc_ep_cfg ipc_ep[4];                 /* 0x6e4 */
	struct ipc_service_context ipc_ctx;          /* 0x714 */
	int (*ble_init)(void *ctx);                  /* 0x77c ble_context (first member) */
	uint8_t pad_780[0x374];
	struct k_sem sem_5;                          /* 0xaf4 */
	uint8_t pad_b0c[0x004];
	struct spi_master_ctx spi;                   /* 0xb10 */
	uint8_t pad_b30[0x03c];
	int (*panel_init)(void *ctx);                /* 0xb6c jdb_panel_context (first member) */
	uint8_t pad_b70[0x348];
	int panel_eb8;                               /* 0xeb8 panel+0x34c */
	uint8_t pad_ebc[0x004];
	uint8_t panel_raster_height_offset;          /* 0xec0 panel+0x354 */
	uint8_t panel_canvas_distance_gear;          /* 0xec1 panel+0x355 */
	uint8_t pad_ec2[0x002];
	int panel_ec4;                               /* 0xec4 panel+0x358 */
	uint8_t pad_ec8[0x00c];
	uint8_t f_ed4;                               /* 0xed4 panel+0x368 */
	uint8_t pad_ed5[0x003];
	uint16_t panel_cur;                          /* 0xed8 panel+0x36c */
	uint8_t pad_eda[0x004];
	uint16_t panel_ede;                          /* 0xede panel+0x372 */
	uint8_t pad_ee0[0x008];
	struct imu_ctx imu;                          /* 0xee8 imu_fusion_context */
	int (*opt3007_init)(void *ctx);              /* 0xf84 opt3007_context (first member) */
	uint8_t pad_f88[0x03d];
	uint8_t f_fc5;                               /* 0xfc5 */
	uint8_t pad_fc6[0x00a];
	uint8_t f_fd0;                               /* 0xfd0 */
	uint8_t f_fd1;                               /* 0xfd1 */
	uint8_t f_fd2;                               /* 0xfd2 */
	uint8_t f_fd3;                               /* 0xfd3 */
	uint8_t f_fd4;                               /* 0xfd4 */
	uint8_t f_fd5;                               /* 0xfd5 */
	uint8_t pad_fd6[0x008];
	uint8_t master_mac[6];                       /* 0xfde */
	uint8_t slave_mac[6];                        /* 0xfe4 */
	uint8_t f_fea;                               /* 0xfea */
	uint8_t pad_feb[0x003];
	uint8_t display_mode;                        /* 0xfee */
	uint8_t pad_fef[0x001];
	struct dashboard_ts_context *dashboard_ts;   /* 0xff0 */
	void *countdown_ts;                          /* 0xff4 */
	struct user_schedule_context *user_sched_info; /* 0xff8 */
	void *ptr_ffc;                               /* 0xffc */
	void *ptr_1000;                              /* 0x1000 */
	void *ptr_1004;                              /* 0x1004 */
	void *ptr_1008;                              /* 0x1008 */
	void *ptr_100c;                              /* 0x100c */
	uint8_t *ptr_1010;                           /* 0x1010 */
	uint8_t *ptr_1014;                           /* 0x1014 */
	uint8_t *ptr_1018;                           /* 0x1018 */
	uint8_t *ptr_101c;                           /* 0x101c */
	uint8_t *ptr_1020;                           /* 0x1020 */
	uint16_t *ptr_1024;                          /* 0x1024 */
	struct gs_1028 *ptr_1028;                    /* 0x1028 */
	uint8_t *multi_packet_data_buffer;           /* 0x102c */
	void *ptr_1030;                              /* 0x1030 */
	uint8_t *ptr_1034;                           /* 0x1034 */
	uint8_t *ptr_1038;                           /* 0x1038 */
	uint8_t *ptr_103c;                           /* 0x103c */
	uint8_t pad_1040[0x004];
	uint32_t ext_flash_1044;                     /* 0x1044 */
	uint32_t ext_flash_1048;                     /* 0x1048 */
	uint32_t ext_flash_104c;                     /* 0x104c */
	struct settings_ctx settings_ctx;            /* 0x1050 */
	uint8_t pad_1058[0x008];
	uint32_t dashboard_cmd;                      /* 0x1060 */
	uint8_t pad_1064[0x004];
	struct gs_1068 *glasses_state;               /* 0x1068 */
	uint8_t bt_ready;                            /* 0x106c */
	uint8_t pending;                             /* 0x106d main loop requests */
	uint8_t f_106e;                              /* 0x106e */
	uint8_t pad_106f[0x001];
	uint16_t module_mask;                        /* 0x1070 */
	uint8_t pad_1072[0x00f];
	uint8_t role_buf[7];                         /* 0x1081 */
	uint16_t f_1088;                             /* 0x1088 */
	uint8_t pad_108a[0x006];
	uint32_t aw_diff;                            /* 0x1090 */
	uint8_t pad_1094[0x00d];
	uint8_t ext_flash_ok;                        /* 0x10a1 */
	uint8_t pad_10a2[0x002];
	uint8_t f_10a4;                              /* 0x10a4 */
	uint8_t pad_10a5[0x02f];
	uint8_t f_10d4;                              /* 0x10d4 */
	uint8_t f_10d5;                              /* 0x10d5 */
	uint8_t pad_10d6[0x172];
} __aligned(8);	/* vendor struct is 8-byte aligned (large-offset addressing, r2_gui) */

BUILD_ASSERT(offsetof(struct GlassesState, is_master) == 0x0);
BUILD_ASSERT(offsetof(struct GlassesState, work_mode) == 0x1);
BUILD_ASSERT(offsetof(struct GlassesState, esb_channel) == 0x2);
BUILD_ASSERT(offsetof(struct GlassesState, esb_master_addr) == 0x3);
BUILD_ASSERT(offsetof(struct GlassesState, esb_slave_addr) == 0x4);
BUILD_ASSERT(offsetof(struct GlassesState, ipc_sem) == 0x8);
BUILD_ASSERT(offsetof(struct GlassesState, sem_1) == 0x20);
BUILD_ASSERT(offsetof(struct GlassesState, sem_2) == 0x38);
BUILD_ASSERT(offsetof(struct GlassesState, sem_3) == 0x50);
BUILD_ASSERT(offsetof(struct GlassesState, main_sem) == 0x68);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_position_sem) == 0x80);
BUILD_ASSERT(offsetof(struct GlassesState, sem_7) == 0x98);
BUILD_ASSERT(offsetof(struct GlassesState, touch_sem) == 0xb0);
BUILD_ASSERT(offsetof(struct GlassesState, esb_hdr) == 0xc9);
BUILD_ASSERT(offsetof(struct GlassesState, esb_arg1) == 0xca);
BUILD_ASSERT(offsetof(struct GlassesState, esb_arg2) == 0xcb);
BUILD_ASSERT(offsetof(struct GlassesState, esb_up_id) == 0xcc);
BUILD_ASSERT(offsetof(struct GlassesState, esb_down_id) == 0xcd);
BUILD_ASSERT(offsetof(struct GlassesState, esb_up_recving) == 0xce);
BUILD_ASSERT(offsetof(struct GlassesState, esb_down_recving) == 0xcf);
BUILD_ASSERT(offsetof(struct GlassesState, sync) == 0xd4);
BUILD_ASSERT(offsetof(struct GlassesState, esb_up_seq) == 0xe9);
BUILD_ASSERT(offsetof(struct GlassesState, esb_down_seq) == 0xea);
BUILD_ASSERT(offsetof(struct GlassesState, esb_dir) == 0xeb);
BUILD_ASSERT(offsetof(struct GlassesState, esb_screen_id) == 0xec);
BUILD_ASSERT(offsetof(struct GlassesState, buf_0ef) == 0xef);
BUILD_ASSERT(offsetof(struct GlassesState, esbm_pkt) == 0x6cc);
BUILD_ASSERT(offsetof(struct GlassesState, ipc_ep) == 0x6e4);
BUILD_ASSERT(offsetof(struct GlassesState, ipc_ctx) == 0x714);
BUILD_ASSERT(offsetof(struct GlassesState, ble_init) == 0x77c);
BUILD_ASSERT(offsetof(struct GlassesState, sem_5) == 0xaf4);
BUILD_ASSERT(offsetof(struct GlassesState, spi) == 0xb10);
BUILD_ASSERT(offsetof(struct GlassesState, panel_init) == 0xb6c);
BUILD_ASSERT(offsetof(struct GlassesState, panel_eb8) == 0xeb8);
BUILD_ASSERT(offsetof(struct GlassesState, panel_raster_height_offset) == 0xec0);
BUILD_ASSERT(offsetof(struct GlassesState, panel_canvas_distance_gear) == 0xec1);
BUILD_ASSERT(offsetof(struct GlassesState, panel_ec4) == 0xec4);
BUILD_ASSERT(offsetof(struct GlassesState, f_ed4) == 0xed4);
BUILD_ASSERT(offsetof(struct GlassesState, panel_cur) == 0xed8);
BUILD_ASSERT(offsetof(struct GlassesState, panel_ede) == 0xede);
BUILD_ASSERT(offsetof(struct GlassesState, imu) == 0xee8);
BUILD_ASSERT(offsetof(struct GlassesState, opt3007_init) == 0xf84);
BUILD_ASSERT(offsetof(struct GlassesState, f_fc5) == 0xfc5);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd0) == 0xfd0);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd1) == 0xfd1);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd2) == 0xfd2);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd3) == 0xfd3);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd4) == 0xfd4);
BUILD_ASSERT(offsetof(struct GlassesState, f_fd5) == 0xfd5);
BUILD_ASSERT(offsetof(struct GlassesState, master_mac) == 0xfde);
BUILD_ASSERT(offsetof(struct GlassesState, slave_mac) == 0xfe4);
BUILD_ASSERT(offsetof(struct GlassesState, f_fea) == 0xfea);
BUILD_ASSERT(offsetof(struct GlassesState, display_mode) == 0xfee);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, countdown_ts) == 0xff4);
BUILD_ASSERT(offsetof(struct GlassesState, user_sched_info) == 0xff8);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_ffc) == 0xffc);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1000) == 0x1000);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1004) == 0x1004);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1008) == 0x1008);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_100c) == 0x100c);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1010) == 0x1010);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1014) == 0x1014);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1018) == 0x1018);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_101c) == 0x101c);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1020) == 0x1020);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1024) == 0x1024);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1028) == 0x1028);
BUILD_ASSERT(offsetof(struct GlassesState, multi_packet_data_buffer) == 0x102c);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1030) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1034) == 0x1034);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_1038) == 0x1038);
BUILD_ASSERT(offsetof(struct GlassesState, ptr_103c) == 0x103c);
BUILD_ASSERT(offsetof(struct GlassesState, ext_flash_1044) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, ext_flash_1048) == 0x1048);
BUILD_ASSERT(offsetof(struct GlassesState, ext_flash_104c) == 0x104c);
BUILD_ASSERT(offsetof(struct GlassesState, settings_ctx) == 0x1050);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_cmd) == 0x1060);
BUILD_ASSERT(offsetof(struct GlassesState, glasses_state) == 0x1068);
BUILD_ASSERT(offsetof(struct GlassesState, bt_ready) == 0x106c);
BUILD_ASSERT(offsetof(struct GlassesState, pending) == 0x106d);
BUILD_ASSERT(offsetof(struct GlassesState, f_106e) == 0x106e);
BUILD_ASSERT(offsetof(struct GlassesState, module_mask) == 0x1070);
BUILD_ASSERT(offsetof(struct GlassesState, role_buf) == 0x1081);
BUILD_ASSERT(offsetof(struct GlassesState, f_1088) == 0x1088);
BUILD_ASSERT(offsetof(struct GlassesState, aw_diff) == 0x1090);
BUILD_ASSERT(offsetof(struct GlassesState, ext_flash_ok) == 0x10a1);
BUILD_ASSERT(offsetof(struct GlassesState, f_10a4) == 0x10a4);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d4) == 0x10d4);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d5) == 0x10d5);
BUILD_ASSERT(sizeof(struct GlassesState) == 0x1248);

extern struct GlassesState *GLOBAL_STATE;

/*
 * Memory block at 0x2007fc00, retained across reboots / shared with the
 * bootloader and the network core.
 */
struct ncs_mem {
	uint32_t ts;              /* 0x00 */
	uint8_t f_04;             /* 0x04 */
	uint8_t f_05;             /* 0x05 */
	uint8_t pad_06[2];
	uint64_t f_08;            /* 0x08 */
	uint8_t f_10[0x25];       /* 0x10 */
	uint8_t f_35[0x2a];       /* 0x35 */
	uint8_t f_5f;             /* 0x5f */
	uint8_t f_60;             /* 0x60 */
	uint8_t f_61;             /* 0x61 */
	uint8_t f_62;             /* 0x62 */
	bool erase_dfu;           /* 0x63 */
	uint32_t magic;           /* 0x64 */
	uint8_t f_68;             /* 0x68 */
	uint8_t notes_index;      /* 0x69 */
	uint8_t pad_6a[6];
	uint8_t f_70;             /* 0x70 */
};

/*
 * The block is a linked object (the code addresses it through a literal
 * that GCC cannot fold, e.g. 0x12345678 is not derived from its address),
 * placed at 0x2007fc00 by the linker.
 */
extern struct ncs_mem ncs_mem;
#define NCS_MEM (&ncs_mem)
#define NCS_MEM_MAGIC 0x12345678

#endif /* G1_MAIN_H_ */

/* Partial view of the vendor global state (GLOBAL_STATE), storage module. */
/* Offsets established from the storage code; padding is explicit. */
#ifndef STORAGE_GS_VIEW_H_
#define STORAGE_GS_VIEW_H_

struct GlassesState {
	uint8_t is_master;                             /* 0x000 */
	uint8_t work_mode;                             /* 0x001 */
	uint8_t esb_channel;                           /* 0x002 */
	uint8_t esb_master_addr;                       /* 0x003 */
	uint8_t esb_slave_addr;                        /* 0x004 */
	uint8_t pad_005[0x080 - 0x005];
	struct k_sem cmd_sem;                          /* 0x080 */
	uint8_t pad_098[0xec0 - 0x098];
	uint8_t f_ec0;                                 /* 0xec0 */
	uint8_t f_ec1;                                 /* 0xec1 */
	uint8_t pad_ec2[0xed4 - 0xec2];
	uint8_t f_ed4;                                 /* 0xed4 */
	uint8_t brightness_level;                      /* 0xed5 */
	uint8_t pad_ed6[0xeda - 0xed6];
	uint16_t f_eda;                                /* 0xeda */
	uint16_t f_edc;                                /* 0xedc */
	uint16_t f_ede;                                /* 0xede */
	uint8_t f_ee0;                                 /* 0xee0 */
	uint8_t pad_ee1[0xef8 - 0xee1];
	uint8_t wakeup_angle;                          /* 0xef8 */
	uint8_t f_ef9;                                 /* 0xef9 */
	uint8_t pad_efa[0xf64 - 0xefa];
	uint8_t dof3_enable;                           /* 0xf64 */
	uint8_t pad_f65[0xf68 - 0xf65];
	uint32_t f_f68;                                /* 0xf68 */
	uint32_t f_f6c;                                /* 0xf6c */
	uint32_t f_f70;                                /* 0xf70 */
	uint8_t pad_f74[0xf98 - 0xf74];
	uint32_t f_f98;                                /* 0xf98 */
	uint8_t f_f9c;                                 /* 0xf9c */
	uint8_t pad_f9d[0xfa4 - 0xf9d];
	uint32_t f_fa4;                                /* 0xfa4 */
	uint32_t f_fa8;                                /* 0xfa8 */
	uint32_t f_fac;                                /* 0xfac */
	uint32_t f_fb0;                                /* 0xfb0 */
	uint32_t f_fb4;                                /* 0xfb4 */
	uint32_t f_fb8;                                /* 0xfb8 */
	uint8_t pad_fbc[0xfee - 0xfbc];
	uint8_t display_mode;                          /* 0xfee */
	uint8_t pad_fef[0xff0 - 0xfef];
	struct dashboard_ts_context * dashboard_ts;    /* 0xff0 */
	struct countdown_ts_context * countdown_ts;    /* 0xff4 */
	struct user_sched_info * user_sched_info;      /* 0xff8 */
	uint8_t pad_ffc[0x1010 - 0xffc];
	uint8_t * status_ptr;                          /* 0x1010 */
	uint8_t pad_1014[0x1030 - 0x1014];
	struct quicknote_ctx * quicknote;              /* 0x1030 */
	uint8_t pad_1034[0x1044 - 0x1034];
	int (*flash_read)(struct GlassesState *gs, uint32_t addr, void *buf, size_t len); /* 0x1044 */
	int (*flash_write)(struct GlassesState *gs, uint32_t addr, const void *buf, size_t len); /* 0x1048 */
	int (*flash_erase)(struct GlassesState *gs, uint32_t addr, size_t len); /* 0x104c */
	struct local_store store;                      /* 0x1050 */
	int storage_cmd;                               /* 0x1060 */
	int first_enter_flag;                          /* 0x1064 */
	int * task_state;                              /* 0x1068 */
	uint8_t pad_106c[0x1081 - 0x106c];
	struct pk7 f_1081;                             /* 0x1081 */
	uint8_t f_1088;                                /* 0x1088 */
	uint8_t pad_1089[0x108a - 0x1089];
	uint16_t f_108a;                               /* 0x108a */
	uint16_t f_108c;                               /* 0x108c */
	uint8_t pad_108e[0x10a8 - 0x108e];
	uint8_t f_10a8;                                /* 0x10a8 */
	uint8_t f_10a9;                                /* 0x10a9 */
	uint8_t pad_10aa[0x10b0 - 0x10aa];
	uint32_t f_10b0;                               /* 0x10b0 */
	uint32_t f_10b4;                               /* 0x10b4 */
	uint32_t f_10b8;                               /* 0x10b8 */
	struct triple f_10bc;                          /* 0x10bc */
	uint8_t f_10c8;                                /* 0x10c8 */
	uint8_t pad_10c9[0x10d0 - 0x10c9];
	uint8_t f_10d0;                                /* 0x10d0 */
	uint8_t pad_10d1[0x10d4 - 0x10d1];
	uint8_t f_10d4;                                /* 0x10d4 */
	uint8_t pad_10d5[0x10d6 - 0x10d5];
	uint8_t f_10d6;                                /* 0x10d6 */
	uint8_t f_10d7;                                /* 0x10d7 */
	uint8_t f_10d8;                                /* 0x10d8 */
	uint8_t f_10d9;                                /* 0x10d9 */
	uint8_t pad_10da[0x1128 - 0x10da];
	struct burial_point burial_point;              /* 0x1128 */
	uint8_t f_1244;                                /* 0x1244 */
	uint8_t f_1245;                                /* 0x1245 */
	struct u8pair f_1246;                          /* 0x1246 */
} __aligned(8);

BUILD_ASSERT(offsetof(struct GlassesState, is_master) == 0x0);
BUILD_ASSERT(offsetof(struct GlassesState, work_mode) == 0x1);
BUILD_ASSERT(offsetof(struct GlassesState, esb_channel) == 0x2);
BUILD_ASSERT(offsetof(struct GlassesState, esb_master_addr) == 0x3);
BUILD_ASSERT(offsetof(struct GlassesState, esb_slave_addr) == 0x4);
BUILD_ASSERT(offsetof(struct GlassesState, cmd_sem) == 0x80);
BUILD_ASSERT(offsetof(struct GlassesState, f_ec0) == 0xec0);
BUILD_ASSERT(offsetof(struct GlassesState, f_ec1) == 0xec1);
BUILD_ASSERT(offsetof(struct GlassesState, f_ed4) == 0xed4);
BUILD_ASSERT(offsetof(struct GlassesState, brightness_level) == 0xed5);
BUILD_ASSERT(offsetof(struct GlassesState, f_eda) == 0xeda);
BUILD_ASSERT(offsetof(struct GlassesState, f_edc) == 0xedc);
BUILD_ASSERT(offsetof(struct GlassesState, f_ede) == 0xede);
BUILD_ASSERT(offsetof(struct GlassesState, f_ee0) == 0xee0);
BUILD_ASSERT(offsetof(struct GlassesState, wakeup_angle) == 0xef8);
BUILD_ASSERT(offsetof(struct GlassesState, f_ef9) == 0xef9);
BUILD_ASSERT(offsetof(struct GlassesState, dof3_enable) == 0xf64);
BUILD_ASSERT(offsetof(struct GlassesState, f_f68) == 0xf68);
BUILD_ASSERT(offsetof(struct GlassesState, f_f6c) == 0xf6c);
BUILD_ASSERT(offsetof(struct GlassesState, f_f70) == 0xf70);
BUILD_ASSERT(offsetof(struct GlassesState, f_f98) == 0xf98);
BUILD_ASSERT(offsetof(struct GlassesState, f_f9c) == 0xf9c);
BUILD_ASSERT(offsetof(struct GlassesState, f_fa4) == 0xfa4);
BUILD_ASSERT(offsetof(struct GlassesState, f_fa8) == 0xfa8);
BUILD_ASSERT(offsetof(struct GlassesState, f_fac) == 0xfac);
BUILD_ASSERT(offsetof(struct GlassesState, f_fb0) == 0xfb0);
BUILD_ASSERT(offsetof(struct GlassesState, f_fb4) == 0xfb4);
BUILD_ASSERT(offsetof(struct GlassesState, f_fb8) == 0xfb8);
BUILD_ASSERT(offsetof(struct GlassesState, display_mode) == 0xfee);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, countdown_ts) == 0xff4);
BUILD_ASSERT(offsetof(struct GlassesState, user_sched_info) == 0xff8);
BUILD_ASSERT(offsetof(struct GlassesState, status_ptr) == 0x1010);
BUILD_ASSERT(offsetof(struct GlassesState, quicknote) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, flash_read) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, flash_write) == 0x1048);
BUILD_ASSERT(offsetof(struct GlassesState, flash_erase) == 0x104c);
BUILD_ASSERT(offsetof(struct GlassesState, store) == 0x1050);
BUILD_ASSERT(offsetof(struct GlassesState, storage_cmd) == 0x1060);
BUILD_ASSERT(offsetof(struct GlassesState, first_enter_flag) == 0x1064);
BUILD_ASSERT(offsetof(struct GlassesState, task_state) == 0x1068);
BUILD_ASSERT(offsetof(struct GlassesState, f_1081) == 0x1081);
BUILD_ASSERT(offsetof(struct GlassesState, f_1088) == 0x1088);
BUILD_ASSERT(offsetof(struct GlassesState, f_108a) == 0x108a);
BUILD_ASSERT(offsetof(struct GlassesState, f_108c) == 0x108c);
BUILD_ASSERT(offsetof(struct GlassesState, f_10a8) == 0x10a8);
BUILD_ASSERT(offsetof(struct GlassesState, f_10a9) == 0x10a9);
BUILD_ASSERT(offsetof(struct GlassesState, f_10b0) == 0x10b0);
BUILD_ASSERT(offsetof(struct GlassesState, f_10b4) == 0x10b4);
BUILD_ASSERT(offsetof(struct GlassesState, f_10b8) == 0x10b8);
BUILD_ASSERT(offsetof(struct GlassesState, f_10bc) == 0x10bc);
BUILD_ASSERT(offsetof(struct GlassesState, f_10c8) == 0x10c8);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d0) == 0x10d0);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d4) == 0x10d4);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d6) == 0x10d6);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d7) == 0x10d7);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d8) == 0x10d8);
BUILD_ASSERT(offsetof(struct GlassesState, f_10d9) == 0x10d9);
BUILD_ASSERT(offsetof(struct GlassesState, burial_point) == 0x1128);
BUILD_ASSERT(offsetof(struct GlassesState, f_1244) == 0x1244);
BUILD_ASSERT(offsetof(struct GlassesState, f_1245) == 0x1245);
BUILD_ASSERT(offsetof(struct GlassesState, f_1246) == 0x1246);

#endif

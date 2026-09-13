/*
 * Module-private declarations for the sensors / audio files
 * (ext_flash.c, opt3007.c, power_charger.c, dmic_audio.c, audio_stream.c).
 * Partial views of shared vendor structures, reconstructed from the v1.63
 * app core.
 */
#ifndef G1_SENSORS_AUDIO_H_
#define G1_SENSORS_AUDIO_H_

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>

/* GLOBAL_STATE->opt3007_context (0xf84), 0x20 bytes */
struct opt3007_context {
	int (*init_cb)(struct opt3007_context *ctx);  /* 0x00 */
	uint8_t pad_04[8];
	int (*read_cb)(int arg);                    /* 0x0c */
	int ready;                                    /* 0x10 */
	int f_14;                                     /* 0x14 */
	uint8_t pad_18[4];
	void *owner;                                  /* 0x1c -> GLOBAL_STATE + 0xb50 */
};

/* Partial view of the global vendor state behind GLOBAL_STATE */
struct GlassesState {
	uint8_t is_master;                       /* 0x000 (1 = master / left) */
	uint8_t pad_001[0x068 - 0x001];
	struct k_sem refresh_sem;                /* 0x068 display refresh request */
	uint8_t pad_080[0xb50 - 0x068 - sizeof(struct k_sem)];
	uint8_t f_b50[0xf84 - 0xb50];            /* 0xb50 (opt3007 owner) */
	struct opt3007_context opt3007_context;  /* 0xf84 */
	int lux_fa4;                             /* 0xfa4 */
	int lux_fa8;                             /* 0xfa8 */
	int lux_fac;                             /* 0xfac */
	uint8_t pad_fb0[4];
	int luminance_curve_a0;                  /* 0xfb4 */
	int lux_fb8;                             /* 0xfb8 */
	uint8_t pad_fbc[0xfc4 - 0xfbc];
	uint8_t battery_soc;                     /* 0xfc4 */
	uint8_t pad_fc5;
	uint8_t battery_soc_flag;                /* 0xfc6 */
	uint8_t pad_fc7;
	uint8_t battery_voltage;                 /* 0xfc8 (V * 100 - 200) */
	uint8_t battery_current;                 /* 0xfc9 ((I + 0.128) * 1000) */
	uint8_t battery_temp;                    /* 0xfca */
	uint8_t pad_fcb;
	int8_t battery_current_ma;               /* 0xfcc */
	uint8_t pad_fcd;
	int16_t battery_temp_x100;               /* 0xfce */
	uint8_t pad_fd0[0xfee - 0xfd0];
	uint8_t display_mode;                    /* 0xfee */
	uint8_t pad_fef[0x1044 - 0xfef];
	/* ext flash API, filled by ext_flash_api_init() */
	int (*flash_read)(struct GlassesState *gs, off_t offset, void *data, size_t len);   /* 0x1044 */
	int (*flash_write)(struct GlassesState *gs, off_t offset, const void *data,
			   size_t len);                                                     /* 0x1048 */
	int (*flash_erase)(struct GlassesState *gs, off_t offset, size_t size);             /* 0x104c */
	uint8_t pad_1050[0x106d - 0x1050];
	uint8_t refresh_flags;                   /* 0x106d */
	uint8_t pad_106e[2];
	uint16_t module_mask;                    /* 0x1070 */
	uint8_t pad_1072[0x10a2 - 0x1072];
	uint16_t flash_page_count;               /* 0x10a2 */
	uint8_t f_10a4;                          /* 0x10a4 mic test: record to flash */
} __aligned(8);

BUILD_ASSERT(offsetof(struct GlassesState, opt3007_context) == 0xf84);
BUILD_ASSERT(offsetof(struct GlassesState, luminance_curve_a0) == 0xfb4);
BUILD_ASSERT(offsetof(struct GlassesState, battery_temp_x100) == 0xfce);
BUILD_ASSERT(offsetof(struct GlassesState, display_mode) == 0xfee);
BUILD_ASSERT(offsetof(struct GlassesState, refresh_sem) == 0x68);
BUILD_ASSERT(offsetof(struct GlassesState, flash_read) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, module_mask) == 0x1070);
BUILD_ASSERT(offsetof(struct GlassesState, flash_page_count) == 0x10a2);

struct GlassesState *get_dashboard_state(void);

/* ext_flash.c */
typedef int (*ext_flash_read_t)(struct GlassesState *gs, off_t offset, void *data, size_t len);
typedef int (*ext_flash_write_t)(struct GlassesState *gs, off_t offset, const void *data,
				 size_t len);
typedef int (*ext_flash_erase_t)(struct GlassesState *gs, off_t offset, size_t size);

int ext_flash_api_init(ext_flash_read_t *read, ext_flash_write_t *write, ext_flash_erase_t *erase);

/* opt3007.c */
int opt3007_read(int arg);
int opt3007_chip_init(struct opt3007_context *ctx);
void opt3007_chip_deinit(void);
void register_opt3007_context(struct opt3007_context *ctx);
int opt3007_get_max_lux(void);

/* dmic / audio */
#define DMIC_MSG_SIZE 200
int enqueue_dmic(void *msg);
int sendAudioStram2Cache(void *data);
void app_codec_lc3_test(void *pcm, int len);

#endif /* G1_SENSORS_AUDIO_H_ */

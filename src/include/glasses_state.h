/*
 * Merged definition of the vendor global state (GLOBAL_STATE /
 * get_dashboard_state(), 0x1248 bytes).
 *
 * Built from every partial view of it: the 9 "struct GlassesState" copies,
 * the alias structs (gui_glasses_state, ui_gs, panel_gs, font_gs, proxy_gs,
 * disp_gs, bp_gs, imu_gs), the sub-struct copies reached through pointers
 * into it (get_ble_context(), get_jdb_panel_context(), CONTAINER_OF, ctx
 * parameters, casts of &gs->buf_0ef: trans_info, nav_info, ...), and the
 * raw-offset users (button.c, nfc_wlc.c, ipc_host.c, ui.h NAV_* / UI_PANEL_*);
 * see ai_helpers/gs_views.py --check for the old-name -> new-path table.
 *
 * The nested types are the merged versions of the module views of the same
 * name (ble_context, jbd_panel_context, imu_ctx, ...), so this header cannot be
 * included next to the module headers that still carry their own partial copy.
 *
 * Anonymous unions are only used where the vendor code really reads one
 * location two ways (whole packet vs. single bytes, array vs. named slots).
 */
#ifndef G1_GLASSES_STATE_H_
#define G1_GLASSES_STATE_H_

#include <stdint.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/bluetooth/addr.h>
#include <nrfx_spim.h>
#include "../ahrs/ahrs.h"

struct GlassesState;

/* pointees of the 0xff0..0x103c pointer block, defined by their owners */
struct schedule_notif;

/* ------------------------------------------------------------------ ESB */

/* first byte of every ESB package */
struct esb_hdr {
	uint8_t cmd : 6;
	uint8_t dir : 2;
};

struct msg_status {
	uint32_t task;                           /* 0x00 */
	uint8_t status;                          /* 0x04 */
} __packed;

struct fw_ver {
	uint8_t major;
	uint8_t minor;
	uint8_t patch;
};

/* sync package sent by the master (21 bytes, gs + 0x0d4) */
struct esb_sync_pkt {
	struct esb_hdr hdr;                      /* 0x00 */
	volatile uint8_t screen_id;              /* 0x01 dashboard_mode */
	uint16_t canvas_x;                           /* 0x02 */
	uint16_t canvas_y;                           /* 0x04 */
	uint8_t package_id;                      /* 0x06 */
	uint8_t stay_time_left_s;                            /* 0x07 */
	uint8_t unknown_task_count;                            /* 0x08 */
	uint8_t unread_msg_num;                            /* 0x09 unread message count */
	uint8_t battery_min;                            /* 0x0a */
	struct msg_status status;                /* 0x0b */
	uint8_t flags;                           /* 0x10 */
	uint8_t arg[4];                          /* 0x11 */
} __packed;

/* peer status package (22 bytes, gs + 0x6cc) */
struct esb_pkt {
	uint8_t cmd;                             /* 0x00 cmd | 0x80 */
	union {
		struct {
			struct fw_ver ver;       /* 0x01 */
			uint8_t battery;         /* 0x04 */
		} __packed;
		volatile uint8_t ver_battery_raw[4];        /* 0x01 main.c copies them byte by byte */
	};
	uint8_t f_05[7];                         /* 0x05 */
	uint8_t mac[6];                          /* 0x0c */
	uint8_t flags;                           /* 0x12 */
	union {
		uint8_t data[2];                 /* 0x13 */
		struct {
			uint8_t subcmd;          /* 0x13 */
			uint8_t value;           /* 0x14 */
		};
	};
	uint8_t seq;                             /* 0x15 */
} __packed;

/* reception buffer at gs + 0x0ef, read per page */
struct db_info {
	uint8_t pad_00[4];
	uint8_t weather_icon;                    /* 0x04 0 / 0xff = none */
	int8_t temperature;                      /* 0x05 Celsius */
	uint8_t pad_06;
	uint8_t new_msg_count;                   /* 0x07 */
	uint8_t pad_08[0x5f - 0x08];
	uint8_t date_format;                     /* 0x5f 0 = mm/dd, 1 = dd-mm, else dd/mm */
	uint8_t low_power;                            /* 0x60 1 = show the 0x42 icon */
	uint8_t pad_61[0x65 - 0x61];
	uint8_t display_mode;                    /* 0x65 */
	uint8_t pane_mode;                       /* 0x66 */
	uint8_t calendar_disp_mode;              /* 0x67 */
	uint8_t pad_68;
	uint8_t stocks_disp_mode;                /* 0x69 */
	uint8_t news_disp_mode;                  /* 0x6a */
	uint8_t citywalk_disp_mode;              /* 0x6b */
	uint8_t pad_6c;
	uint16_t citywalk_x;                     /* 0x6d */
	uint16_t citywalk_y;                     /* 0x6f */
	uint8_t citywalk_state;                   /* 0x71 */
	uint8_t pad_72;
	uint8_t dashboard_on;                            /* 0x73 */
} __packed;

/* screen payload buffer at gs + 0x0ef (0x5dc bytes), read per page */
union screen_payload {
	uint8_t buf[0x5dc];
	struct db_info db;                       /* dashboard */
	struct {
		float yaw;
		float pitch;
		float roll;
	} __packed ypr;                          /* gyro template / imu tx */
	struct ui_timer_payload {
		uint32_t seconds;
		uint8_t state;
	} __packed timer;                        /* template timer screen */
	struct {
		uint8_t pad[7];
		uint8_t count;                   /* 0x07 (gs 0x0f6) */
	} __packed new_msg;
	struct {
		uint8_t pad_00;
		uint8_t ui_action;               /* 0x01 page action / step */
		uint8_t show_clock;              /* 0x02 */
		uint8_t ui_status;               /* 0x03 page sub-state (even_ai_v2) */
		uint8_t page_flags;              /* 0x04 bit0: animated icon */
		uint8_t dark_cnt;                /* 0x05 */
		uint8_t pad_06[2];
		char text[1];                    /* 0x08 page text (length unknown) */
		uint8_t pad_09[7];
		char ai_text[1];                 /* 0x10 even_ai_v2 text (length unknown) */
	} __packed gui;                          /* gui pages */
	struct {
		uint8_t longpress_req;
		uint8_t sub_mode;                /* 0x01 */
		uint8_t page;                    /* 0x02 */
		uint8_t status;                  /* 0x03 */
		uint8_t mode;                    /* 0x04 */
		uint8_t scroll_line;                    /* 0x05 */
		uint8_t pad_06[2];
		char text[0x5dc - 8];            /* 0x08 */
	} __packed qn;                           /* quicknote */
	struct {
		uint8_t status;                  /* 0x00 */
		uint8_t sub_status;              /* 0x01 (read under screen_payload_mutex) */
		uint8_t pad_02[2];
		uint8_t percent;                 /* 0x04 */
		uint8_t hide_bar;                /* 0x05 */
		uint8_t page;                    /* 0x06 */
		char text[0x1e0];                /* 0x07 */
		uint16_t text_len;               /* 0x1e7 */
	} __packed ai;                           /* even AI */
	struct {
		uint8_t work_mode;               /* 0x00 */
		uint8_t cmd;                     /* 0x01 */
		uint8_t pad_02[8];
		uint8_t status;                  /* 0x0a */
		uint8_t pad_0b;
		int8_t countdown;                /* 0x0c */
		uint8_t percent;                 /* 0x0d */
		uint16_t dark_lines;             /* 0x0e */
		uint8_t suspend;                 /* 0x10 */
		int32_t suspend_time;            /* 0x11 */
		uint8_t pad_15[2];
		char text[0x200];                /* 0x17 */
	} __packed tp;                           /* teleprompter */
	struct trans_info {
		uint8_t translation_type;        /* 0x00 1-based language index */
		uint8_t original_type;           /* 0x01 */
		uint8_t suspend_en;              /* 0x02 */
		uint8_t mode;                    /* 0x03 */
		uint8_t pad_04[2];
		char text[0x1e0];                /* 0x06 */
	} __packed trans;                        /* translate (written by the BLE handler) */
	struct nav_page {
		uint8_t running;
		uint8_t direction;               /* 0x01 */
		uint8_t pad_02[5];
		uint8_t imu_action_status;       /* 0x07 */
		uint16_t pos_x;                  /* 0x08 position on the panoramic map */
		uint16_t pos_y;                  /* 0x0a */
		uint8_t pad_0c;
		char total_time[0x18];           /* 0x0d */
		char total_distance[0x18];       /* 0x25 */
		char road[0x40];                 /* 0x3d */
		char distance[0x18];             /* 0x7d */
		char speed[0x1c];                /* 0x95 */
		uint32_t map_size;               /* 0xb1 overview map size (0x1210 = raw) */
	} __packed nav;                          /* navigation (struct nav_page) */
	struct {
		uint8_t pad_00[0xae];
		uint8_t status;                  /* 0xae 1 arriving, 2 arrived */
		uint8_t pad_af[6];
		char text[0x5dc - 0xb5];         /* 0xb5 */
	} __packed nav_arrived;                  /* navigation, arrival page */
} __packed;

/* GlassesState->dash_buf: dashboard data received with cmd 0x4e (0x1e9 bytes) */
struct dash_data_buf {
	uint8_t type;                            /* 0x000 */
	uint8_t screen_status;                             /* 0x001 */
	uint16_t char_pos;                            /* 0x002 (big endian in the packet) */
	uint8_t scroll_pct;                             /* 0x004 */
	uint8_t page_count;                             /* 0x005 */
	uint8_t seq;                             /* 0x006 */
	uint8_t data[0x1e0];                     /* 0x007 */
	uint16_t len;                            /* 0x1e7 */
} __packed;

/* GlassesState->evenai_buf (0x1014, cmd 0x54) */
struct evenai_buf {
	uint8_t state;                                   /* 0x00 */
	uint8_t sub;                                     /* 0x01 */
	uint8_t wakeup_arg;                                     /* 0x02 */
	uint8_t action_status;                                     /* 0x03 */
	uint8_t scroll_line;                                     /* 0x04 */
	uint8_t scroll_pct;                                     /* 0x05 */
	int64_t ts;                                      /* 0x06 */
	uint16_t len;                                    /* 0x0e */
	uint8_t data[0x200];                             /* 0x10 */
} __packed;

/* GlassesState->transcribe_buf (0x102c, cmd 0x52 / 0x53, 0x208 bytes) */
struct transcribe_buf {
	bool running;                                    /* 0x000 */
	uint8_t f_1;                                     /* 0x001 */
	uint8_t mode;                                    /* 0x002 */
	uint8_t status;                                     /* 0x003 */
	uint8_t flags;                                   /* 0x004 */
	uint8_t dark_lines;                                     /* 0x005 */
	uint16_t len;                                    /* 0x006 */
	uint8_t data[0x200];                             /* 0x008 */
};

/* GlassesState->quicknote_show_info (0x1034, 0x152 bytes) */
struct quicknote_show_info {
	uint8_t longpress_req;
	uint8_t enable;       /* 0x01 */
	uint8_t started_by_app;          /* 0x02 */
	uint8_t action;       /* 0x03 */
	uint8_t result_code;          /* 0x04 */
	uint8_t scroll_line;          /* 0x05 */
	uint16_t len;         /* 0x06 */
	uint8_t data[0x14a];  /* 0x08 */
};

/* ------------------------------------------------------------------ IPC */

struct ipc_ep_cfg {
	uint8_t id;
	const char *name;
	int (*recv_cb)(struct GlassesState *gs, const uint8_t *data, size_t len);
};

#define IPC_RECEIVER_MAX 22

/* gs + 0x714, filled by ipc_host.c */
struct ipc_service_context {
	uint32_t f_00;                           /* 0x00 */
	int count;                               /* 0x04 */
	struct ipc_ep_cfg *receivers[IPC_RECEIVER_MAX]; /* 0x08 */
	int (*send)(const void *data, size_t len);       /* 0x60 */
	int (*register_recv_cb)(struct ipc_ep_cfg *ep);  /* 0x64 */
};

/* ------------------------------------------------------------------ BLE */

/*
 * One notification (0x1b4 bytes): the ANCS record being received
 * (ble_context.notif) and the entries of g_arrMsgContent (notification.c).
 */
struct notif_msg {
	uint32_t recv_time;                      /* 0x000 */
	uint32_t start_show_time;                /* 0x004 */
	uint32_t uid;                            /* 0x008 (uidTail) */
	uint8_t pos;                             /* 0x00c */
	uint8_t sync_state;                      /* 0x00d master/slave display sync, 0..4 */
	uint8_t busy;                            /* 0x00e */
	uint8_t read : 1;                        /* 0x00f bit 0 */
	uint8_t state : 7;                       /* 0x00f bits 1..7 */
	char app_identifier[32];                 /* 0x010 */
	char display_name[32];                   /* 0x030 */
	char title[32];                          /* 0x050 */
	char subtitle[32];                       /* 0x070 */
	char message[256];                       /* 0x090 */
	char date[32];                           /* 0x190 */
	uint32_t action;                         /* 0x1b0 */
};
BUILD_ASSERT(sizeof(struct notif_msg) == 0x1b4);

/* the master/slave ESB sync sends a notification as two 0xda-byte halves */
#define NOTIF_MSG_HALF 0xda

/* gs + 0x77c. ble_nus.c points rx buffers at ctx + 0x394 / ctx + 0x8d4,
 * which lie outside this struct (gs + 0xb10 / gs + 0x1050). */
struct ble_context {
	int (*init_cb)(struct ble_context *ctx); /* 0x000 */
	uint8_t pad_004[0x00c - 0x004];
	int (*write)(const uint8_t *data, uint16_t len); /* 0x00c */
	uint8_t *tx_buf;                         /* 0x010 (malloc(0x2b8)) */
	uint32_t tx_len;                         /* 0x014 */
	uint8_t charging;                        /* 0x018 */
	uint8_t pad_019[0x034 - 0x019];
	struct notif_msg notif;                  /* 0x034 */
	struct k_sem ancs_get_attr_data_sem;     /* 0x1e8 */
	struct k_sem ancs_get_attr_req_sem;      /* 0x200 */
	struct k_sem rx_sem;                     /* 0x218 */
	struct k_sem tx_sem;                     /* 0x230 */
	uint8_t receiver_thd_is_running;         /* 0x248 */
	uint8_t pad_249[3];
	union {
		uint8_t *rx_bufs[3];             /* 0x24c */
		struct {
			uint8_t *large_buf_0;        /* 0x24c */
			uint8_t *large_buf_1;        /* 0x250 */
			uint8_t *small_buf;      /* 0x254 */
		};
	};
	uint8_t rx_data[0x100];                  /* 0x258 */
	uint32_t rx_len;                         /* 0x358 */
	uint32_t rx_pending;                     /* 0x35c */
	uint32_t small_len;                      /* 0x360 */
	volatile uint8_t restart_adv;            /* 0x364 */
	volatile uint8_t connected;                  /* 0x365 */
	volatile uint8_t send_enabled;           /* 0x366 */
	uint8_t security_pending;                           /* 0x367 */
	uint32_t last_rx_time;                   /* 0x368 */
	uint32_t connected_time;                 /* 0x36c */
	uint8_t pad_370[0x378 - 0x370];
};

/* ------------------------------------------------------------------ SPI / panel */

/* spi_interface_t (gs + 0xb10) */
struct spi_master_ctx {
	int (*init_cb)(struct spi_master_ctx *ctx);  /* 0x00 */
	int (*deinit_cb)(struct spi_master_ctx *ctx); /* 0x04 */
	int (*xfer_cb)(struct spi_master_ctx *ctx, const uint8_t *tx, size_t tx_len,
		       uint8_t *rx, size_t rx_len);  /* 0x08 */
	nrfx_spim_t spim;                        /* 0x0c */
	uint32_t is_initialized;                 /* 0x14 */
	union {
		uint8_t pins[4];                 /* 0x18 */
		struct {
			uint8_t bus;             /* 0x18 3 or 4 */
			uint8_t sck;             /* 0x19 */
			uint8_t mosi;            /* 0x1a */
			uint8_t miso;            /* 0x1b */
		};
	};
	uint8_t ss;                              /* 0x1c */
	uint8_t speed_mhz;                       /* 0x1d */
	volatile uint8_t xfer_done;              /* 0x1e */
	uint8_t pad_1f;
};

struct flash_ops {
	uint32_t f_0;
	void (*fn)(struct flash_ops *ops);
};

#define PANEL_FB_ROWS 200

struct jbd_panel_context;
typedef int (*panel_cb_t)(struct jbd_panel_context *c);

/* gs + 0xb6c */
struct jbd_panel_context {
	panel_cb_t init_cb;                      /* 0x000 */
	panel_cb_t suspend_cb;                   /* 0x004 */
	panel_cb_t resume_cb;                    /* 0x008 */
	panel_cb_t off_cb;                       /* 0x00c */
	panel_cb_t on_cb;                        /* 0x010 */
	int (*default_task)(struct jbd_panel_context *c, int screen_id, void *ctx); /* 0x014 */
	void (*draw_image_cb)(struct jbd_panel_context *c);          /* 0x018 */
	void *(*clear_cb)(struct jbd_panel_context *c);              /* 0x01c */
	int (*set_brightness_cb)(struct jbd_panel_context *c, uint8_t level); /* 0x020 */
	uint8_t *panel_buffer[PANEL_FB_ROWS];    /* 0x024 frame buffer row pointers */
	uint8_t *current_buffer;                 /* 0x344 */
	uint32_t current_row;                    /* 0x348 */
	uint32_t current_column;                 /* 0x34c */
	uint32_t current_buffer_size;            /* 0x350 */
	uint8_t raster_height_offset;            /* 0x354 (gs 0xec0) */
	uint8_t canvas_distance_gear;            /* 0x355 (gs 0xec1) */
	uint8_t pad_356[2];
	uint32_t y_offset;                       /* 0x358 (gs 0xec4) */
	uint32_t init_done;                      /* 0x35c */
	uint32_t f_360;                          /* 0x360 */
	uint8_t pad_364[4];
	uint8_t voltage;                         /* 0x368 (gs 0xed4) */
	uint8_t panel_brightness_level;          /* 0x369 (gs 0xed5) */
	uint8_t last_synced_brightness;                           /* 0x36a */
	uint8_t applied_brightness;                           /* 0x36b */
	union {
		uint16_t brightness_lum[4];      /* 0x36c (gs 0xed8) */
		struct {
			uint16_t brightness_max; /* 0x36c */
			uint16_t lum_base_0;        /* 0x36e */
			uint16_t lum_base_1;        /* 0x370 */
			uint16_t lum_gear;       /* 0x372 (gs 0xede) */
		};
	};
	uint8_t brightness_percent;              /* 0x374 (gs 0xee0) */
	uint8_t pad_375[3];
	struct spi_master_ctx *spi_callbacks;    /* 0x378 */
};

/* ------------------------------------------------------------------ IMU / light */

/* imu_fusion_context (gs + 0xee8) */
struct imu_ctx {
	uint8_t mode;                            /* 0x00 */
	uint8_t pad_01[3];
	uint32_t on;                             /* 0x04 */
	int thr_low;                             /* 0x08 */
	int thr_high;                            /* 0x0c */
	uint8_t level;                           /* 0x10 wakeup angle */
	uint8_t wear;                            /* 0x11 */
	uint8_t pad_12[2];
	uint8_t inited;                          /* 0x14 */
	uint8_t thread_running;                             /* 0x15 */
	uint8_t pad_16[2];
	uint32_t sample_period_ms;                            /* 0x18 */
	const struct device *dev;                /* 0x1c */
	struct sensor_value odr;                 /* 0x20 */
	struct ahrs fusion;                      /* 0x28 */
	uint8_t pad_6c[0x7c - 0x6c];
	uint8_t dof3_enable;                     /* 0x7c */
	uint8_t pad_7d[3];
	int ref;                                 /* 0x80 */
	int base;                                /* 0x84 user horizontal pitch */
	int div;                                 /* 0x88 */
	int (*init_cb)(struct imu_ctx *c);       /* 0x8c */
	int (*deinit_cb)(struct imu_ctx *c);     /* 0x90 */
	int (*get_cb)(struct imu_ctx *c);        /* 0x94 */
	void (*set_cb)(struct imu_ctx *c, uint32_t val); /* 0x98 */
};

/* gs + 0xf84 */
struct opt3007_context {
	int (*init_cb)(struct opt3007_context *ctx); /* 0x00 */
	uint8_t pad_04[8];
	int (*read_cb)(int arg);                 /* 0x0c */
	int ready;                               /* 0x10 */
	uint32_t lux_base_max;                   /* 0x14 (unsigned: production_test.c divides by it) */
	uint8_t auto_brightness;                            /* 0x18 */
	uint8_t pad_19[3];
	void *owner;                             /* 0x1c -> gs + 0xb50 */
};

/* ------------------------------------------------------------------ storage */

/* settings backend (gs + 0x1050) */
struct local_store {
	int status;                                                  /* 0x0 */
	int (*write)(const char *key, const void *val, size_t len);  /* 0x4 */
	int (*load)(void);                                           /* 0x8 */
	void (*del)(const char *key);                                /* 0xc */
};

struct pk7 {
	uint32_t a;
	uint16_t b;
	uint8_t c;
} __packed;

struct triple {
	uint32_t v[3];
};

/* ------------------------------------------------------------------ burial point */

struct bp_day {
	uint16_t year;                           /* 0x0 */
	uint8_t month;                           /* 0x2 */
	uint8_t day;                             /* 0x3 */
	uint32_t sum_time;                       /* 0x4 seconds */
	uint32_t count;                          /* 0x8 */
};

struct bp_session {
	uint8_t active;                          /* 0x00 */
	uint8_t day_index;                       /* 0x01 */
	int64_t start_time;                      /* 0x02 k_uptime_get() */
	uint8_t pad_0a[0x10];
} __packed;

/* persisted statistics record (gs + 0x1128, 0x11c bytes) */
struct bp_context {
	uint32_t id;                             /* 0x00 random id */
	uint32_t wear_sum_time;                  /* 0x04 */
	uint32_t wear_count;                     /* 0x08 */
	uint32_t dashboard_sum_time;             /* 0x0c */
	uint32_t dashboard_count;                /* 0x10 */
	uint8_t version;                         /* 0x14 */
	uint8_t day_index;                       /* 0x15 */
	uint8_t valid;                           /* 0x16 */
	uint8_t pad_17;
	struct bp_day wear_day[7];               /* 0x18 */
	struct bp_day dashboard_day[7];          /* 0x6c */
	uint32_t notification_sum_time;          /* 0xc0 */
	uint32_t notification_count;             /* 0xc4 */
	struct bp_day notification_day[7];       /* 0xc8 */
};

/* ------------------------------------------------------------------ feature blocks */

/* GlassesState->dashboard_ts (0xff0, 0x75 bytes, persisted as the "dashboard_ts" setting) */
struct dashboard_ts_context {
	uint32_t ts;                             /* 0x00 */
	uint8_t weather_icon;                            /* 0x04 */
	uint8_t temperature;                            /* 0x05 */
	uint64_t ms_ts;                          /* 0x06 uptime ms base */
	uint8_t retained_buf_a[0x25];                      /* 0x0e */
	uint8_t retained_buf_b[0x2a];                      /* 0x33 */
	uint8_t temp_unit;                       /* 0x5d 0 = Celsius, else Fahrenheit */
	uint8_t time_disp_mode;                  /* 0x5e 1 = 12h */
	uint8_t date_format;                            /* 0x5f */
	uint8_t low_power;                       /* 0x60 */
	uint8_t retained_a;                            /* 0x61 */
	uint8_t retained_b;                            /* 0x62 */
	uint8_t pad_63;
	uint8_t retained_c;                            /* 0x64 */
	uint8_t disp_mode;                       /* 0x65 dashboard display mode */
	uint8_t area;                            /* 0x66 custom display area */
	uint8_t sched_mode;                      /* 0x67 schedule display mode */
	uint8_t sched_num;                       /* 0x68 schedule record count */
	uint8_t stocks_mode;                     /* 0x69 */
	uint8_t news_mode;                       /* 0x6a */
	uint8_t citywalk_mode;                   /* 0x6b */
	uint8_t citywalk_bg_param;                            /* 0x6c */
	uint16_t arrow_x;                        /* 0x6d citywalk arrow offset */
	uint16_t arrow_y;                        /* 0x6f */
	uint8_t citywalk_state;                  /* 0x71 */
	uint8_t dashboard_hold;                            /* 0x72 */
	uint8_t dashboard_on;                    /* 0x73 */
	uint8_t exit_pending;                            /* 0x74 */
} __packed;

/* GlassesState->countdown_ts (0xff4, 7 bytes, persisted as "countdown_ts") */
struct countdown_ts_context {
	uint32_t seconds;                        /* 0x00 */
	uint8_t state;                            /* 0x04 */
	uint8_t enabled;                         /* 0x05 */
	uint8_t reset;                           /* 0x06 */
} __packed;

/* GlassesState->user_sched_info (0xff8, 0x16a bytes copied from BLE request 8) */
struct user_schedule_context {
	uint8_t data[0x164];                     /* 0x000 */
	uint32_t ts;                             /* 0x164 time stamp from the phone (0 = none) */
	uint8_t f_168;                           /* 0x168 */
	uint8_t f_169;                           /* 0x169 */
};

/* GlassesState->teleprompter (0x1000, 0x217 bytes) */
struct teleprompter_info {
	uint8_t mode;                            /* 0x00 */
	uint8_t ready;                           /* 0x01 */
	int64_t ts;                              /* 0x02 */
	uint8_t action;                          /* 0x0a */
	uint8_t mode_flag;                            /* 0x0b */
	uint8_t countdown_s;                            /* 0x0c */
	uint8_t scroll_pct;                            /* 0x0d */
	uint16_t mark_pos;                       /* 0x0e */
	uint8_t suspend;                         /* 0x10 */
	uint32_t counter;                        /* 0x11 */
	uint16_t len;                            /* 0x15 */
	uint8_t text[0x200];                     /* 0x17 */
} __packed;

/* GlassesState->translate_src / translate_dst (0x1008 / 0x100c, 0x1e8 bytes) */
struct translate_buf {
	uint8_t translation_type;          /* 0x000 */
	uint8_t original_type;          /* 0x001 */
	uint8_t suspend;      /* 0x002 */
	uint8_t screen_status;          /* 0x003 */
	uint16_t char_pos;         /* 0x004 */
	uint8_t data[0x1e0];  /* 0x006 */
	uint16_t len;         /* 0x1e6 */
} __packed;

/* GlassesState->nav (0x1004, 0xf5 bytes) */
struct nav_info {
	uint8_t running;                         /* 0x00 */
	uint8_t direction;                       /* 0x01 */
	uint8_t f_02[4];
	uint8_t updated;                         /* 0x06 phone alive */
	uint8_t imu_action_status;
	uint16_t x;                              /* 0x08 */
	uint16_t y;                              /* 0x0a */
	uint8_t f_0c;
	char time_remaining[0x18];               /* 0x0d */
	char km_remaining[0x18];                 /* 0x25 */
	char road_name[0x40];                    /* 0x3d */
	char remaining_distance[0x18];           /* 0x7d */
	char speed[0x18];                        /* 0x95 */
	uint8_t panoramic;                       /* 0xad */
	uint8_t arrived;                         /* 0xae */
	uint8_t type;                            /* 0xaf */
	uint8_t sync_id;                         /* 0xb0 */
	uint32_t map_size;                       /* 0xb1 */
	char prompt[0x40];                       /* 0xb5 */
} __packed;

/* GlassesState->bitmap_info (0x1018, 0xb bytes) */
struct bitmap_show_info {
	uint8_t enable;                  /* 0x00 */
	uint8_t sync_pending;            /* 0x01 */
	uint8_t mode;                    /* 0x02 */
	int64_t deadline;                /* 0x03 */
} __packed;

/* GlassesState->onboarding (0x101c, 0x21 bytes, cleared by init_onboarding_info) */
struct onboarding_ctx {
	uint8_t active;                          /* 0x00 */
	uint8_t in_progress;                            /* 0x01 */
	uint8_t action;                          /* 0x02 action_cmd */
	uint8_t sub_step;                        /* 0x03 */
	uint64_t ts;                             /* 0x04 k_uptime_get() of the last step change */
	uint8_t sync_arg;                            /* 0x0c */
	uint8_t calib_state_a;                            /* 0x0d */
	uint8_t calib_state_b;                            /* 0x0e */
	uint32_t calib_data_a;                           /* 0x0f */
	uint32_t calib_data_b;                           /* 0x13 */
	uint32_t calib_data_c;                           /* 0x17 */
	char step_str[4];                        /* 0x1b "n/6" */
	uint8_t flags;                           /* 0x1f */
	uint8_t saved_brightness;                /* 0x20 */
} __packed;

/* GlassesState->ts_info (0x1028, 10 bytes): page enter time stamp */
struct prompt_info {
	union {
		struct {
			uint8_t enable;          /* 0x00 */
			uint8_t action_cmd;             /* 0x01 */
			int64_t ts;              /* 0x02 k_uptime_get() when the page was entered */
		} __packed;
		struct {
			uint32_t word_a;
			uint32_t word_b;
			uint16_t half_c;
		} __packed init;                 /* main.c clears the block as three words */
	};
} __packed;

/* GlassesState->quicknote (0x1030, 0x50f bytes) */
struct quicknote_item {
	uint8_t valid;                           /* 0x000 */
	char title[0x29];                        /* 0x001 */
	char text[0x119];                        /* 0x02a */
};

struct quicknote_ctx {
	uint8_t hdr[3];                          /* 0x000 */
	struct quicknote_item notes[4];          /* 0x003 */
};

/* ------------------------------------------------------------------ GlassesState */

struct GlassesState {
	uint8_t is_master;                       /* 0x000 1 master (left), 2 slave */
	uint8_t work_mode;                       /* 0x001 1 / 8: busy / 9 */
	uint8_t esb_channel;                     /* 0x002 */
	uint8_t esb_master_addr;                 /* 0x003 */
	uint8_t esb_slave_addr;                  /* 0x004 */
	uint8_t pad_005[3];
	struct k_sem ipc_sem;                    /* 0x008 */
	struct k_sem sem_1;                      /* 0x020 */
	struct k_sem sem_2;                      /* 0x038 */
	struct k_sem screen_on_sem;              /* 0x050 */
	struct k_sem main_sem;                   /* 0x068 */
	struct k_sem dashboard_position_sem;     /* 0x080 */
	struct k_sem sem_7;                      /* 0x098 */
	struct k_sem touch_sem;                  /* 0x0b0 */

	/* ESB link state */
	uint8_t esb_block;                           /* 0x0c8 */
	struct esb_hdr esb_hdr;                  /* 0x0c9 */
	uint8_t esb_arg1;                        /* 0x0ca */
	uint8_t esb_arg2;                        /* 0x0cb even-AI v2 volume level */
	uint8_t esb_up_id;                       /* 0x0cc */
	uint8_t esb_down_id;                     /* 0x0cd */
	uint8_t esb_up_recving;                  /* 0x0ce */
	uint8_t esb_down_recving;                /* 0x0cf */
	uint32_t date_ts;                        /* 0x0d0 */
	union {
		struct esb_sync_pkt sync;        /* 0x0d4 last sync package */
		struct {
			struct esb_hdr sync_hdr; /* 0x0d4 */
			volatile uint8_t dashboard_mode; /* 0x0d5 (= sync.screen_id) */
			uint16_t sync_canvas_x;        /* 0x0d6 */
			uint16_t sync_canvas_y;        /* 0x0d8 */
			uint8_t sync_seq;        /* 0x0da */
			uint8_t stay_time_left_s;           /* 0x0db */
			uint8_t unknown_task_count;           /* 0x0dc */
			uint8_t unread_msg_num;  /* 0x0dd */
			uint8_t battery_min;           /* 0x0de */
			struct msg_status sync_status; /* 0x0df */
			uint8_t sync_flags;      /* 0x0e4 */
			uint8_t sync_data[4];    /* 0x0e5 */
		} __packed;
	};
	uint8_t esb_up_seq;                      /* 0x0e9 */
	uint8_t esb_down_seq;                    /* 0x0ea */
	uint8_t esb_dir;                         /* 0x0eb */
	uint8_t esb_screen_id;                   /* 0x0ec */
	union {
		struct {
			uint16_t v;
		} __packed buf_len;              /* 0x0ed */
		struct {
			uint8_t tx_cmd;          /* 0x0ed */
			uint8_t tx_arg;          /* 0x0ee */
		};
	};
	union screen_payload ui;                 /* 0x0ef */
	uint8_t pad_6cb;
	struct esb_pkt esb_pkt;                  /* 0x6cc */
	uint8_t pad_6e2[2];

	/* IPC (net core) */
	struct ipc_ep_cfg ipc_ep[4];             /* 0x6e4 */
	struct ipc_service_context ipc_ctx;      /* 0x714 */

	struct ble_context ble_context;          /* 0x77c */
	struct k_sem imu_sem;                    /* 0xaf4 */
	uint8_t imu_busy;                           /* 0xb0c */
	uint8_t schedule_notif_pending;                           /* 0xb0d */
	uint8_t pad_b0e[2];
	struct spi_master_ctx spi;               /* 0xb10 */
	struct flash_ops flash_ops;            /* 0xb30 */
	uint8_t pad_b38[0xb50 - 0xb38];
	uint8_t opt3007_bus_ctx[0xb6c - 0xb50];            /* 0xb50 opt3007 owner area */
	struct jbd_panel_context panel;          /* 0xb6c */
	struct imu_ctx imu;                      /* 0xee8 */
	struct opt3007_context opt3007_context;  /* 0xf84 */

	/* ambient light -> brightness */
	union {
		uint32_t lux_base[3];            /* 0xfa4 */
		struct {
			int lux_base_low;             /* 0xfa4 */
			int lux_base_mid;             /* 0xfa8 */
			int lux_base_high;             /* 0xfac */
		};
	};
	uint32_t lux_base_spare;                          /* 0xfb0 */
	int luminance_curve;                     /* 0xfb4 */
	int luminance_curve_a1;                             /* 0xfb8 */
	float lux_k_min;                         /* 0xfbc */
	float lux_k_max;                         /* 0xfc0 */

	/* battery */
	union {
		uint8_t battery_info[4];         /* 0xfc4 */
		struct {
			uint8_t battery_left;    /* 0xfc4 own soc */
			uint8_t battery_right;   /* 0xfc5 */
			uint8_t battery_soc_flag; /* 0xfc6 */
			uint8_t f_fc7;           /* 0xfc7 */
		};
	};
	uint8_t battery_voltage;                 /* 0xfc8 */
	uint8_t battery_current;                 /* 0xfc9 */
	uint8_t battery_temp;                    /* 0xfca */
	uint8_t pad_fcb;
	int8_t battery_current_ma;               /* 0xfcc */
	uint8_t pad_fcd;
	int16_t battery_temp_x100;               /* 0xfce */

	struct fw_ver master_fw_ver;                /* 0xfd0 */
	struct fw_ver fw_ver;                    /* 0xfd3 */
	uint8_t pad_fd6[0xfde - 0xfd6];
	uint8_t master_mac[6];                   /* 0xfde */
	uint8_t slave_mac[6];                    /* 0xfe4 */
	uint8_t suspend_state;                   /* 0xfea */
	uint8_t panel_on;                        /* 0xfeb */
	uint8_t screen_on;                       /* 0xfec */
	uint8_t imu_event;                           /* 0xfed */
	uint8_t display_mode;                    /* 0xfee */
	uint8_t pad_fef;

	/* per-feature contexts */
	struct dashboard_ts_context *dashboard_ts;   /* 0xff0 */
	struct countdown_ts_context *countdown_ts;   /* 0xff4 */
	struct user_schedule_context *user_sched_info; /* 0xff8 */
	struct schedule_notif *schedule_notif;       /* 0xffc */
	struct teleprompter_info *teleprompter;  /* 0x1000 */
	struct nav_info *nav;                    /* 0x1004 */
	struct translate_buf *translate_src;     /* 0x1008 */
	struct translate_buf *translate_dst;     /* 0x100c */
	struct dash_data_buf *dash_buf;          /* 0x1010 first byte: screen state */
	struct evenai_buf *evenai_buf;           /* 0x1014 first byte: even-AI state */
	struct bitmap_show_info *bitmap_info;    /* 0x1018 */
	struct onboarding_ctx *onboarding;       /* 0x101c */
	uint8_t *raster_height_cfg;                       /* 0x1020 (1 byte) */
	uint8_t *horiz_pitch_cfg;                /* 0x1024 (2 bytes; main.c clears it as one uint16_t) */
	struct prompt_info *ts_info;                 /* 0x1028 */
	struct transcribe_buf *transcribe_buf;   /* 0x102c (0x208 bytes, ble_proto.h) */
	struct quicknote_ctx *quicknote;         /* 0x1030 */
	struct quicknote_show_info *quicknote_show_info; /* 0x1034 */
	uint8_t *esb_up_snapshot;                       /* 0x1038 */
	uint8_t *esb_down_snapshot;                       /* 0x103c */
	void (*switch_to_dfu_cb)(struct k_sem *sem);      /* 0x1040 */
	int (*flash_read)(struct GlassesState *gs, uint32_t addr, void *buf, size_t len);       /* 0x1044 */
	int (*flash_write)(struct GlassesState *gs, uint32_t addr, const void *buf, size_t len);  /* 0x1048 */
	int (*flash_erase)(struct GlassesState *gs, uint32_t addr, size_t len);                   /* 0x104c */
	struct local_store store;                /* 0x1050 */
	int dashboard_cmd;                       /* 0x1060 signed: file_storage.c switch */
	int first_enter_flag;                    /* 0x1064 */
	struct msg_status *task_status;          /* 0x1068 */
	uint8_t bt_state;                        /* 0x106c */
	uint8_t pending;                         /* 0x106d refresh flags */
	uint8_t sync_ack;                        /* 0x106e */
	uint8_t pad_106f;
	uint16_t module_mask;                    /* 0x1070 bit 7: BLE connected to the app */
	uint8_t pad_1072[6];
	int64_t last_sync_ts;                    /* 0x1078 */
	uint8_t phone_is_ios;                    /* 0x1080 */
	union {
		bt_addr_le_t bonded_addr;        /* 0x1081 */
		struct pk7 bonded_addr_raw;      /* 0x1081 (storage copies it in 3 parts) */
	};
	union {
		uint16_t bond_flags;             /* 0x1088 main.c clears both at once */
		struct {
			uint8_t bonded;          /* 0x1088 */
			uint8_t force_bind;      /* 0x1089 */
		};
	};
	uint16_t canvas_x;                       /* 0x108a */
	uint16_t canvas_y;                       /* 0x108c */
	uint8_t pad_108e[2];
	int32_t aw_diff;                         /* 0x1090 touch diff */
	int accel[3];                            /* 0x1094 */
	uint8_t comflag;                         /* 0x10a0 */
	uint8_t ext_flash_ok;                    /* 0x10a1 */
	uint16_t flash_page_count;               /* 0x10a2 */
	uint8_t mic_nocompress;                  /* 0x10a4 */
	uint8_t pad_10a5[3];

	/* charger */
	uint8_t aging_test_count;                     /* 0x10a8 */
	uint8_t aging_start_soc;                     /* 0x10a9 */
	uint8_t pad_10aa[2];
	uint32_t aging_start_uptime_s;                    /* 0x10ac */
	uint32_t aging_elapsed_s;                    /* 0x10b0 */
	uint32_t aging_charge_time_s;                    /* 0x10b4 */
	uint32_t aging_discharge_time_s;                    /* 0x10b8 */
	union {
		uint16_t aging_discharge_step_s[6];         /* 0x10bc */
		struct triple aging_discharge_step_raw;            /* 0x10bc */
	};
	uint8_t aging_touch_count;                     /* 0x10c8 */
	uint8_t pad_10c9[3];
	uint32_t aging_charge_check_count;                    /* 0x10cc */
	uint8_t aging_charge_check_result;                     /* 0x10d0 */
	uint8_t aging_no_charge_count;                     /* 0x10d1 */
	uint8_t pad_10d2[2];
	uint8_t check_mode;                      /* 0x10d4 */
	uint8_t user_data_reset_pending;                          /* 0x10d5 */
	uint8_t message_mode;                    /* 0x10d6 */
	uint8_t message_stay_time;               /* 0x10d7 */
	uint8_t charge_limit_upper;              /* 0x10d8 */
	uint8_t charge_limit_lower;              /* 0x10d9 */

	/* burial point (usage statistics) */
	struct bp_session bp_dashboard;          /* 0x10da */
	struct bp_session bp_wear;               /* 0x10f4 */
	struct bp_session bp_notification;       /* 0x110e */
	struct bp_context bp;                    /* 0x1128 */

	uint8_t double_tap_customize;                          /* 0x1244 */
	uint8_t double_tap_dashboard_on;                          /* 0x1245 */
	union {
		struct u8pair {
			uint8_t a;
			uint8_t b;
		} f_1246_pair;                   /* 0x1246 settings record copies both */
		struct {
			uint8_t longpress_tap_customize;          /* 0x1246 */
			uint8_t head_up_mic_disabled;          /* 0x1247 */
		};
	};
} __aligned(8);

BUILD_ASSERT(sizeof(union screen_payload) == 0x5dc);
BUILD_ASSERT(sizeof(struct esb_sync_pkt) == 0x15);
BUILD_ASSERT(sizeof(struct esb_pkt) == 0x16);
BUILD_ASSERT(sizeof(struct ble_context) == 0x378);
BUILD_ASSERT(sizeof(struct spi_master_ctx) == 0x20);
BUILD_ASSERT(sizeof(struct jbd_panel_context) == 0x37c);
BUILD_ASSERT(sizeof(struct imu_ctx) == 0x9c);
BUILD_ASSERT(sizeof(struct opt3007_context) == 0x20);
BUILD_ASSERT(sizeof(struct bp_session) == 0x1a);
BUILD_ASSERT(sizeof(struct bp_context) == 0x11c);
BUILD_ASSERT(sizeof(struct dashboard_ts_context) == 0x75);
BUILD_ASSERT(sizeof(struct countdown_ts_context) == 7);
BUILD_ASSERT(sizeof(struct user_schedule_context) == 0x16c); /* 0x16a bytes used, 2 bytes tail padding */
BUILD_ASSERT(sizeof(struct teleprompter_info) == 0x217);
BUILD_ASSERT(sizeof(struct nav_info) == 0xf5);
BUILD_ASSERT(sizeof(struct translate_buf) == 0x1e8);
BUILD_ASSERT(sizeof(struct bitmap_show_info) == 0xb);
BUILD_ASSERT(sizeof(struct onboarding_ctx) == 0x21);
BUILD_ASSERT(sizeof(struct prompt_info) == 10);
BUILD_ASSERT(sizeof(struct quicknote_ctx) == 0x50f);

BUILD_ASSERT(offsetof(struct GlassesState, touch_sem) == 0x0b0);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_mode) == 0x0d5);
BUILD_ASSERT(offsetof(struct GlassesState, ui.ai.text_len) == 0x2d6);
BUILD_ASSERT(offsetof(struct GlassesState, ui.tp.text) == 0x106);
BUILD_ASSERT(offsetof(struct GlassesState, ui.nav.map_size) == 0x1a0);
BUILD_ASSERT(offsetof(struct GlassesState, ui.nav_arrived.text) == 0x1a4);
BUILD_ASSERT(sizeof(struct ipc_service_context) == 0x68);
BUILD_ASSERT(offsetof(struct GlassesState, esb_pkt) == 0x6cc);
BUILD_ASSERT(offsetof(struct GlassesState, ipc_ctx) == 0x714);
BUILD_ASSERT(offsetof(struct GlassesState, ble_context) == 0x77c);
BUILD_ASSERT(offsetof(struct GlassesState, spi) == 0xb10);
BUILD_ASSERT(offsetof(struct GlassesState, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct GlassesState, imu) == 0xee8);
BUILD_ASSERT(offsetof(struct GlassesState, battery_info) == 0xfc4);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, flash_read) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, module_mask) == 0x1070);
BUILD_ASSERT(offsetof(struct GlassesState, last_sync_ts) == 0x1078);
BUILD_ASSERT(offsetof(struct GlassesState, bonded_addr) == 0x1081);
BUILD_ASSERT(offsetof(struct GlassesState, bp_dashboard) == 0x10da);
BUILD_ASSERT(offsetof(struct GlassesState, bp) == 0x1128);
BUILD_ASSERT(sizeof(struct GlassesState) == 0x1248);

struct GlassesState *get_dashboard_state(void);

#endif /* G1_GLASSES_STATE_H_ */

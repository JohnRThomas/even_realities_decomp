/*
 * Notification store / app white list / notification UI / dashboard info
 * - module private types and prototypes.
 * Reconstructed from the G1 v1.63 app core.
 */
#ifndef G1_NOTIFY_H_
#define G1_NOTIFY_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <zephyr/kernel.h>

#include "g1_log.h"
#include "g1_date.h"

/*
 * cJSON comes from modules/lib/cjson (CONFIG_CJSON_LIB).  The current
 * prj.conf does not enable it, so fall back to the declarations we use.
 */
#if __has_include(<cJSON.h>)
#include <cJSON.h>
#else
#define cJSON_False  (1 << 0)
#define cJSON_True   (1 << 1)
#define cJSON_NULL   (1 << 2)
#define cJSON_Number (1 << 3)
#define cJSON_String (1 << 4)
#define cJSON_Array  (1 << 5)
#define cJSON_Object (1 << 6)
typedef int cJSON_bool;
typedef struct cJSON {
	struct cJSON *next;
	struct cJSON *prev;
	struct cJSON *child;
	int type;
	char *valuestring;
	int valueint;
	double valuedouble;
	char *string;
} cJSON;
cJSON *cJSON_Parse(const char *value);
char *cJSON_Print(const cJSON *item);
char *cJSON_PrintUnformatted(const cJSON *item);
void cJSON_Delete(cJSON *item);
int cJSON_GetArraySize(const cJSON *array);
cJSON *cJSON_GetArrayItem(const cJSON *array, int index);
cJSON *cJSON_GetObjectItem(const cJSON *const object, const char *const string);
cJSON_bool cJSON_IsArray(const cJSON *const item);
cJSON *cJSON_CreateObject(void);
cJSON *cJSON_CreateArray(void);
cJSON *cJSON_CreateString(const char *string);
cJSON_bool cJSON_AddItemToArray(cJSON *array, cJSON *item);
cJSON_bool cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);
cJSON *cJSON_AddBoolToObject(cJSON *const object, const char *const name, const cJSON_bool boolean);
cJSON *cJSON_AddStringToObject(cJSON *const object, const char *const name, const char *const string);
#endif

/* print without the LOG_LEVEL check / "%s(): " prefix */
#define BLE_PRINTK(fmt, ...)                                                   \
	do {                                                                   \
		if (BLE_DEBUG) {                                               \
			ble_printk(fmt, ##__VA_ARGS__);                        \
		} else {                                                       \
			printk(fmt, ##__VA_ARGS__);                            \
		}                                                              \
	} while (0)

#define MSG_NORMAL_NUM   10   /* g_arrMsgContent[0..9]: shown messages */
#define MSG_TOTAL_NUM    20   /* g_arrMsgContent[10..19]: push queue */

#define PKCS7_PACK_DONE  0xc9

/*
 * One notification (0x1b4 bytes) - same layout as struct ancs_notif_data
 * in ble/ble_ancs.h.
 */
struct notif_msg {
	uint32_t recv_time;                              /* 0x000 */
	uint32_t start_show_time;                        /* 0x004 */
	uint32_t uid;                                    /* 0x008 (uidTail) */
	uint8_t pos;                                     /* 0x00c */
	uint8_t f_0d;                                    /* 0x00d */
	uint8_t f_0e;                                    /* 0x00e */
	uint8_t read : 1;                                /* 0x00f bit 0 */
	uint8_t state : 7;                               /* 0x00f bits 1..7 */
	char app_identifier[32];                         /* 0x010 */
	char display_name[32];                           /* 0x030 */
	char title[32];                                  /* 0x050 */
	char subtitle[32];                               /* 0x070 */
	char message[256];                               /* 0x090 */
	char date[32];                                   /* 0x190 */
	uint32_t action;                                 /* 0x1b0 */
};

/* BLE context embedded in GlassesState at 0x77c (partial, see ble_proto.h) */
struct ble_context {
	void (*start_work_thread)(void);                 /* 0x000 */
	uint8_t pad_004[0x00c - 0x004];
	int (*write)(const uint8_t *data, uint16_t len); /* 0x00c */
	uint8_t *tx_buf;                                 /* 0x010 */
	uint32_t tx_len;                                 /* 0x014 */
};

/* GlassesState->schedule_notif (0xffc) */
struct schedule_notif {
	uint32_t ts;                                     /* 0x00 */
	uint8_t pad_04[4];
	char title[17];                                  /* 0x08 */
	char desc[0x97];                                 /* 0x19 */
} __packed;

/* GlassesState->dashboard_ts, partial (see main.h) */
struct dashboard_ts_context {
	uint32_t ts;                                     /* 0x00 */
	uint8_t f_04;                                    /* 0x04 */
	uint8_t f_05;                                    /* 0x05 */
	uint64_t f_06;                                   /* 0x06 */
	uint8_t pad_0e[0x5e - 0x0e];
	uint8_t time_disp_mode;                          /* 0x5e (12h clock) */
} __packed;

/* JBD panel context (GlassesState + 0xb6c), partial - see gui/gui.h */
struct jbd_panel_context {
	void *cb[6];                                     /* 0x000 */
	void (*draw_cb)(struct jbd_panel_context *ctx);  /* 0x018 */
	void (*clear_cb)(void);                          /* 0x01c */
	void *cb_20;                                     /* 0x020 */
	uint8_t *panel_buffer[200];                      /* 0x024 frame buffer row pointers */
	uint8_t *current_buffer;                         /* 0x344 */
	uint32_t current_row;                            /* 0x348 */
	uint32_t current_column;                         /* 0x34c */
	uint8_t pad_350[0x35c - 0x350];
	uint32_t init_done;                              /* 0x35c */
	uint8_t pad_360[0x37c - 0x360];
	uint8_t imu_state;                               /* 0x37c (GlassesState + 0xee8, imu_fusion_context) */
	uint8_t pad_37d[0x47f - 0x37d];
	uint8_t panel_on;                                /* 0x47f (GlassesState + 0xfeb) */
};

/* screen specific payload sent by the phone (GlassesState + 0xef) */
union ui_payload {
	struct {
		float yaw;
		float pitch;
		float roll;
	} __packed ypr;                                  /* template gyro screen */
	struct ui_timer_payload {
		uint32_t seconds;
		uint8_t state;
	} __packed timer;                                /* template timer screen */
	struct {
		uint8_t pad[7];
		uint8_t count;                           /* 0xf6 */
	} __packed new_msg;
} __packed;

/* Partial view of the global vendor state (struct GlassesState, main.h) */
struct GlassesState {
	uint8_t is_master;                               /* 0x000 */
	uint8_t pad_001[0x0d0 - 0x001];
	uint32_t now;                                    /* 0x0d0 (FUN_00080732) */
	uint8_t pad_0d4;
	uint8_t dashboard_mode;                          /* 0x0d5 */
	uint8_t pad_0d6[0x0dd - 0x0d6];
	uint8_t unread_msg_num;                          /* 0x0dd master_sync_pkg.panel_data_pkg */
	uint8_t pad_0de[0x0ef - 0x0de];
	union ui_payload ui;                             /* 0x0ef */
	uint8_t pad_0fb[0x77c - 0x0fb];
	struct ble_context ble_context;                  /* 0x77c */
	uint8_t pad_794[0xb0d - 0x77c - sizeof(struct ble_context)];
	uint8_t f_b0d;                                   /* 0xb0d */
	uint8_t pad_b0e[0xb6c - 0xb0e];
	struct jbd_panel_context panel;                  /* 0xb6c */
	uint8_t pad_fec[0xff0 - 0xb6c - sizeof(struct jbd_panel_context)];
	struct dashboard_ts_context *dashboard_ts;       /* 0xff0 */
	uint8_t pad_ff4[0xffc - 0xff4];
	struct schedule_notif *schedule_notif;           /* 0xffc */
	uint8_t pad_1000[0x1030 - 0x1000];
	uint8_t *quicknote;                              /* 0x1030 */
	uint8_t pad_1034[0x1044 - 0x1034];
	int (*flash_read)(struct GlassesState *gs, uint32_t addr, void *buf, uint32_t len); /* 0x1044 */
	uint8_t pad_1048[0x1080 - 0x1048];
	uint8_t phone_is_ios;                            /* 0x1080 */
	uint8_t pad_1081[0x108a - 0x1081];
	uint16_t text_x;                                 /* 0x108a */
	uint16_t text_y;                                 /* 0x108c */
	uint8_t pad_108e[0x10d6 - 0x108e];
	uint8_t f_10d6;                                  /* 0x10d6 */
	uint8_t msg_timeout;                             /* 0x10d7 */
};

BUILD_ASSERT(offsetof(struct GlassesState, ui) == 0xef);
BUILD_ASSERT(offsetof(struct GlassesState, panel) == 0xb6c);
BUILD_ASSERT(offsetof(struct GlassesState, dashboard_ts) == 0xff0);
BUILD_ASSERT(offsetof(struct GlassesState, quicknote) == 0x1030);
BUILD_ASSERT(offsetof(struct GlassesState, flash_read) == 0x1044);
BUILD_ASSERT(offsetof(struct GlassesState, text_x) == 0x108a);
BUILD_ASSERT(sizeof(struct notif_msg) == 0x1b4);
BUILD_ASSERT(offsetof(struct GlassesState, unread_msg_num) == 0xdd);
BUILD_ASSERT(offsetof(struct GlassesState, ble_context) == 0x77c);
BUILD_ASSERT(offsetof(struct GlassesState, f_b0d) == 0xb0d);
BUILD_ASSERT(offsetof(struct GlassesState, schedule_notif) == 0xffc);
BUILD_ASSERT(offsetof(struct GlassesState, msg_timeout) == 0x10d7);

struct GlassesState *get_dashboard_state(void);

/* other modules */
void FUN_0002dd98(void);                         /* threads */
uint8_t is_in_box(void);                         /* ui_b (declared bool there; the caller compares with 1) */
void confirm_message(uint32_t uid);
int FUN_00019d14(struct ble_context *ctx, uint8_t *buf, uint32_t len);
int FUN_0007f4c6(struct ble_context *ctx, uint8_t *buf, uint32_t len, uint32_t max);
int parse_receiver_msg_pack_pkcs7(uint8_t *origin_data, const uint8_t *req, uint16_t req_len);

void dump_ancs(const char *tag, struct notif_msg *data);

/* gui (gui/gui.c and friends) */
typedef int (*gui_effect_cb_t)(int arg, const char *str, int font, int x, int y);
extern const uint8_t gui_fade_mask[26][8][320];
int set_frame_buffer(uint8_t **fb);
int gui_screen_clear(void);
int set_showing_notification_on_gui(void);
int clear_showing_notification_on_gui(void);
int hide_icon_notification_on_gui(void);
int gui_bmp_bitmap_draw(int id, int x, int y, int effect, gui_effect_cb_t cb, int no_draw);
int gui_utf_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
		 uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb, int no_draw);
int gui_utf_draw_middle(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			int no_draw);
int gui_utf_draw_truncate(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  int no_draw);
int gui_utf_draw_align_right(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			     uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			     int no_draw);
int gui_utf_Wordwrap_draw(int arg, const char *str, int font, int x0, int y0, int x1, int y1,
			  uint32_t max_lines, uint32_t dark_cnt, int effect, gui_effect_cb_t cb,
			  uint32_t no_draw);
int FUN_000809e2(void);                          /* screen x offset */
int FUN_00080a3a(void);                          /* screen y offset */
const char *get_string(uint8_t string_id);
uint8_t get_current_language(void);
int _clean_fb_data(uint8_t **fb, int val, int x_start, int y_start, int x_end, int y_end);
int _reflash_fb_data_to_lcd(uint32_t row, uint32_t column, int x_start, int y_start,
			    int x_end, int y_end);
int copy_to_frame_buffer(uint8_t **fb, const uint8_t *src, int w_bytes, int h, int x, int y);
uint16_t *FUN_0004b160(const char *utf8, uint16_t *count);
const uint8_t *FUN_0004b2d4(int glyph, int size);
const uint8_t *find_chinese_bitmap_by_unicode(uint32_t code, int w, int h);
int FUN_00080bc0(uint8_t **fb, const uint8_t *bmp, int w, int h, int x, int y);
/* font_ascii.c (panel_display); same prototype in font_bitmap.h. 4th argument unused (callers pass 0) */
const uint8_t *FUN_00080fa2(uint16_t digit, int w, int h, int arg);
void FUN_00080800(uint8_t **fb, void *arg, int a, int b, int c);
/* common_utils.c (panel_display) defines it as (char *buf, float val); same AAPCS registers (r0, s0).
 * The vendor order is (val, buf): the only caller evaluates the float first (vldmia before mov r0). */
int FUN_0004d328(float val, char *buf);
void FUN_0004b30c(int id, int *w, int *h);

/* burial point (statistics) / date helpers */
const char *FUN_0004d2cc(uint32_t ts);           /* weekday name */
void enter_notification_burial_point(void);
void exit_notification_burial_point(void);

extern volatile uint8_t msg_busy;           /* new notification pending */

/* notification.c */
extern struct notif_msg g_arrMsgContent[MSG_TOTAL_NUM];
void send_whilelist_app_info_wrapper(struct notif_msg *msg);
uint8_t count_unread_messages(void);
void clear_timeout_message(int force);
uint8_t push_message(struct notif_msg *msg);
uint8_t pull_message(struct notif_msg **msg);
uint8_t get_cur_show_msg_idx(void);
uint8_t get_msg_show_state(void);
uint8_t parse_message_type(int idx);
void parse_ncs_notification(char *json, struct notif_msg *msg);

/* whitelist.c */
uint8_t is_on_whitelist_by_identifier(const char *app_id);
void load_app_white_list_from_flash(void);

/* ui_notification.c */
void draw_message(uint8_t unread, struct notif_msg *msg);

/* demo_image.c */
void get_demo_image_source(uint32_t idx);

#endif /* G1_NOTIFY_H_ */

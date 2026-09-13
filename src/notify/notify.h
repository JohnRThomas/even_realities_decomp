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
#include <glasses_state.h>

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

#define MSG_NORMAL_NUM   10   /* g_arrMsgContent[0..9]: shown messages */
#define MSG_TOTAL_NUM    20   /* g_arrMsgContent[10..19]: push queue */

#define PKCS7_PACK_DONE  0xc9

/* GlassesState->schedule_notif (0xffc) */
struct schedule_notif {
	uint32_t ts;                                     /* 0x00 */
	uint8_t pad_04[4];
	char title[17];                                  /* 0x08 */
	char desc[0x97];                                 /* 0x19 */
} __packed;

/* notification.c */
extern struct notif_msg g_arrMsgContent[MSG_TOTAL_NUM];
void send_whilelist_app_info_wrapper(struct notif_msg *msg);
int post_notification_cmd_response(struct GlassesState *state, uint8_t *data, volatile uint8_t *src,
				   uint8_t *hdr, uint8_t *arg, uint8_t *out, uint32_t len);
void post_notification_cmd_process(struct ble_context *ctx, uint8_t *req, uint8_t *data);
int get_notification_counts_cmd_response(struct GlassesState *state, uint8_t *out);
void get_notification_counts_cmd_process(struct ble_context *ctx, uint8_t *buf, uint8_t *rsp);
struct notif_msg *get_push_message_copy(void);
struct notif_msg *get_push_message(void);
void set_msg_sync_state(int idx, uint8_t val);
uint8_t get_msg_sync_state(int idx);
struct notif_msg *find_push_message_by_uid(uint32_t uid);
struct notif_msg *get_message_by_index(int idx);
void clear_all_messages(void);
uint8_t count_messages(void);
/* returns uint8_t; dashboard.c was built against an int prototype (its callers
 * re-extend the result) and defines COUNT_UNREAD_INT_PROTOTYPE before including this header */
#ifdef COUNT_UNREAD_INT_PROTOTYPE
int count_unread_messages(void);
#else
uint8_t count_unread_messages(void);
#endif
void clear_timeout_message(int force);
void confirm_message(uint32_t uid);
uint8_t push_message(struct notif_msg *msg);
uint8_t g_arrMsgContent_count(void);
uint8_t pull_message(struct notif_msg **msg);
uint8_t get_cur_show_msg_idx(void);
void set_cur_message_state(void);
void mark_cur_message_read(void);
uint8_t get_msg_show_state(void);
void expire_cur_message(void);
void set_msg_show_state(uint8_t val);
uint8_t cur_message_show_state(void);
bool is_message_showing(void);
uint8_t parse_message_type(int idx);
void app_list_init(void);

/* ncs_notification.c */
void parse_ncs_notification(char *json, struct notif_msg *msg);

/* ui_notification.c */
int panel_related(struct jbd_panel_context *panel, int idx, void *arg);
void draw_message(uint8_t unread, struct notif_msg *msg);
void set_hide_icon_on_exit(void);
void set_particle_pending(void);
int ui_ancs_notificaton_task(struct jbd_panel_context *panel, void *arg, int event);

/* ui_template.c */
void dump_template_gyro_info(void *arg);
int draw_template_gyro_page(struct jbd_panel_context *panel, void *arg);

/* ui_countdown.c */
void countdown_tick(void *unused, struct countdown_ts_context *cd);
int draw_template_countdown_page(struct jbd_panel_context *panel, void *arg);
int draw_template_notification_page(struct jbd_panel_context *panel, void *arg);
void countdown_reset(struct countdown_ts_context *cd);

#endif /* G1_NOTIFY_H_ */

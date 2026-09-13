/* Notification white list (whitelist.c): record layout, limits and functions */
#ifndef G1_WHITELIST_H_
#define G1_WHITELIST_H_

#include <stdint.h>
#include <stddef.h>
#include <zephyr/kernel.h>
#include <glasses_state.h>

#define WHITELIST_FLASH_ADDR    0x131000
#define MAX_WHITE_LIST_APP_NUM  100
#define MAX_WHITE_LIST_BUF_LEN  (sizeof(struct app_whitelist) + 1)

struct app_info {
	char id[40];
	char name[16];
};

struct app_whitelist {
	uint8_t call_enable : 1;
	uint8_t msg_enable : 1;
	uint8_t ios_mail_enable : 1;
	uint8_t calendar_enable : 1;
	uint8_t app_enable : 1;
	uint8_t app_count;
	struct app_info list[MAX_WHITE_LIST_APP_NUM];
};

BUILD_ASSERT(sizeof(struct app_whitelist) == 0x15e2);

/* whitelist.c */
int parse_app_white_list_json(const char *json);
int is_the_same_whitelist_app(const char *json);
uint8_t *get_app_whitelist_info(void); /* BLE whitelist buffer */
uint8_t is_on_whitelist_by_identifier(const char *pkg_name);
void put_whitelist_app_from_app(struct ble_context *ctx, uint8_t *hdr, const uint8_t *data,
				uint16_t len, uint8_t *rsp);
void get_whitelist_app_from_device(struct ble_context *ctx, uint8_t *rsp);
void load_app_white_list_from_flash(void);

#endif /* G1_WHITELIST_H_ */

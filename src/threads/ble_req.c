/*
 * BLE / SPI request handling of the master (master_process_put_req and the
 * static helpers inlined into it: read_fw_pack_from_nor_flash_by_qspi,
 * process_recv_ble_req).  Separate object between watchdog.c and
 * task_status.c: its out-of-line k_sem_give copy (0x80276) is only used here.
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include "g1_log.h"
#include "threads.h"
#include "../ble_proto/ble_cmd.h"

/* other modules */
void FUN_00080852(uint8_t val);
void FUN_0003f1bc(int val);
void FUN_0004d494(uint32_t *total_s, int idx, int restart);
uint8_t FUN_00030440(void);
void FUN_0007f38a(uint32_t uid);
int FUN_00019c80(int enable);
const char *get_serial_number(void);
const char *FUN_00025340(void);
int get_boot_seconds(void);
int uint32_to_little_endian(uint8_t *buf, uint32_t val);
int get_notification_counts_cmd_response(struct GlassesState *state, uint8_t *out);
int post_notification_cmd_response(struct GlassesState *state, uint8_t *data, volatile uint8_t *src,
				   uint8_t *hdr, uint8_t *arg, uint8_t *out, uint32_t len);
int mbedtls_md5(const unsigned char *input, size_t ilen, unsigned char output[16]);
void dump_hex(const char *tag, const uint8_t *data, uint32_t len);

int FUN_0002d8c8(void *dev, struct GlassesState *state, bool on);

uint8_t get_wear_state_event(void);

/* BLE request header as handed over by the SPI/BLE protocol layer */
struct ble_req {
	uint8_t req_type;                        /* 0x00 */
	uint8_t sub;                             /* 0x01 */
	uint8_t pad_02[2];
	union {
		uint8_t data[0x2b4];             /* 0x04 */
		uint32_t word;                   /* 0x04 */
		struct {
			uint32_t w0;             /* 0x04 */
			uint32_t addr;           /* 0x08 */
			uint32_t len;            /* 0x0c */
		} fw;
	};
};

#define BLE_REQ_FW_READ   3
#define BLE_RESP_OK       0xc9
#define BLE_RESP_INVALID  0xca

static inline int read_fw_pack_from_nor_flash_by_qspi(uint32_t addr, uint8_t *buf, uint32_t len)
{
	int ret;

	if (get_dashboard_state()->ext_flash_read == NULL) {
		return -1;
	}
	ret = get_dashboard_state()->ext_flash_read(get_dashboard_state(), addr, buf, len);
	if (ret) {
		G1_LOG_ERR("read flash fail: %d\n\n", ret);
		return ret;
	}
	return len;
}

static inline int process_recv_ble_req(struct ble_req *head, uint8_t *out)
{
	G1_LOG_ERR("tx error req_type head->req_type %d.\n\n", head->req_type);
	memcpy(out, "error", 6);
	return 6;
}

static inline void notify_dashboard(struct GlassesState *state, struct ble_req *head)
{
	state->dashboard_cmd = head->req_type;
	k_sem_give(&state->dashboard_position_sem);
}

static inline int battery_left(struct GlassesState *state)
{
	int l;

	if (state->battery_info[0] == 93) {
		l = state->battery_info[2] ? 95 : 94;
	} else if (state->battery_info[0] == 94) {
		l = state->battery_info[2] ? 97 : 96;
	} else if (state->battery_info[0] == 95) {
		l = 98;
	} else if (state->battery_info[0] == 96) {
		l = 99;
	} else if (state->battery_info[0] > 96) {
		l = 100;
	} else {
		l = state->battery_info[0];
	}
	return l;
}

static inline bool process_fw_read(uint32_t addr, uint32_t total, uint8_t *out)
{
	uint32_t n = total - 0x12;

	if (total - 0x13 > 0x800c || read_fw_pack_from_nor_flash_by_qspi(addr, out + 0x12, n) != n) {
		out[0] = 'n';
		out[1] = 'o';
		return false;
	}
	uint8_t *md5 = out + 2;

	out[0] = 'o';
	out[1] = 'k';
	mbedtls_md5(out + 0x12, n, md5);
	dump_hex("flash_md5", md5, 16);
	return true;
}

int master_process_put_req(struct GlassesState *state, struct ble_req *head, uint8_t *out, uint32_t len)
{
	uint8_t *data = head->data;
	uint8_t req;
	int l, r;
	uint8_t v;

	if (head->sub == BLE_REQ_FW_READ) {
		uint32_t addr = head->fw.addr;
		uint32_t total = head->fw.len;

		if (!process_fw_read(addr, total, out)) {
			return 0;
		}
		return total;
	}

	req = head->req_type;
	if (req >= 0x01 && req <= 0x27) {
		uint8_t arg;
		uint32_t ts;
		int ret;

		switch (req) {
		case BLE_CMD_BRIGHTNESS_SET:
			if (state->panel_brightness != data[0] || state->f_f9c != data[1]) {
				state->set_brightness(&state->pm, data[0]);
				state->f_f9c = data[1];
				notify_dashboard(state, head);
			}
			out[0] = data[0];
			out[1] = data[1];
			out[2] = BLE_RESP_OK;
			ret = 3;
			goto set_done;
		case BLE_CMD_ANTI_SHAKE_SET:
			if (state->f_f64 != data[0]) {
				state->f_f64 = data[0];
				notify_dashboard(state, head);
			}
			break;
		case BLE_CMD_SILENT_MODE_SET:
			v = data[0];
			arg = data[1];
			if (v >= 10 && v <= 12) {
				uint8_t cur = state->f_fee;

				if (v == cur) {
					break;
				}
				if (state->is_master == 1) {
					if (cur != 12) {
						if (v == 12) {
							FUN_00080852(0);
						}
					} else if (v != 12 && arg != 1) {
						FUN_0003f1bc(1);
					}
				} else if (state->is_master == 2 && cur == 12) {
					if (v != 12 && arg != 1) {
						FUN_0003f1bc(1);
					}
				}
				state->f_fee = v;
				notify_dashboard(state, head);
				if (!state->f_b0c && v == 11) {
					state->f_fed = 3;
					k_sem_give(&state->imu_sem);
					ret = 0;
					goto set_done;
				}
				break;
			}
			out[0] = BLE_RESP_INVALID;
			ret = 1;
			goto set_done;
		case BLE_CMD_DEBUG_CONTROL:
			v = data[0];
			arg = data[1];
			if (v == 1) {
				FUN_0002d8c8("debug-ble", state, arg != 0);
			} else if (v == 2) {
				LOG_LEVEL = arg;
				printk("log_level_set=%d", arg);
			} else if (v == 3) {
				state->dashboard_mode = arg;
			}
			memcpy(out, "Good", 5);
			ret = 5;
			goto set_done;
		case BLE_CMD_COUNTDOWN_TIMER:
			ts = head->word;
			((struct ff4_ctx *)state->ptr_ff4)->f_05 = data[4];
			((struct ff4_ctx *)state->ptr_ff4)->ts = ts;
			((struct ff4_ctx *)state->ptr_ff4)->f_06 = 1;
			notify_dashboard(state, head);
			out[0] = BLE_RESP_OK;
			if (((struct ff4_ctx *)state->ptr_ff4)->f_05) {
				update_persist_task_status(state, 2, 2);
			}
			ret = 1;
			goto set_done;
		case BLE_CMD_TELEPROMPTER_INFO:
			memcpy(state->task_1000, data, 0x217);
			if (!data[1]) {
				memset(state->task_1000, 0, 0x217);
			}
			if (data[1]) {
				update_persist_task_status(state, 9, 2);
			}
			ret = 0;
			goto set_done;
		case BLE_CMD_TRANSLATE_SRC_TEXT:
			if (FUN_00030440()) {
				ret = 0;
				goto set_done;
			}
			state->task_1008->data[0x1e5 - 8] = 0;
			if (!state->task_1008->f_06) {
				state->task_1008->f_06 = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->f_1068->task != 11) {
				update_persist_task_status(state, 11, 2);
			}
			ret = 1;
			goto set_done;
		case BLE_CMD_TRANSLATE_DST_TEXT:
			if (FUN_00030440()) {
				ret = 0;
				goto set_done;
			}
			state->task_100c->data[0x1e5 - 8] = 0;
			if (!state->task_100c->f_06) {
				state->task_100c->f_06 = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->f_1068->task != 11) {
				update_persist_task_status(state, 11, 2);
			}
			ret = 1;
			goto set_done;
		case BLE_CMD_HEAD_UP_ACTION_SET:
			memcpy(state->ptr_ff8, data, 0x16a);
			*(uint32_t *)state->dashboard_ts = ((struct ff8_buf *)state->ptr_ff8)->ts;
			FUN_0004d494((uint32_t *)state->dashboard_ts, 0, 1);
			notify_dashboard(state, head);
			break;
		case BLE_CMD_HEAD_UP_ANGLE_SET:
			v = data[0];
			arg = data[1];
			if (state->f_ef8 != v || state->f_ef9 != arg) {
				state->f_ef8 = v;
				state->f_ef9 = arg;
				notify_dashboard(state, head);
			}
			break;
		case BLE_CMD_NOTIFY_EN:
			v = data[0];
			G1_LOG_ERR("BLE_REQ_PUT_NOTIFY_EN enable:%d\n", v);
			FUN_00019c80(v);
			break;
		case 0x11:
			state->dashboard_cmd = 7;
			k_sem_give(&state->dashboard_position_sem);
			ret = 0;
			goto set_done;
		case BLE_CMD_HARDWARE_SET:
			if (data[4] != 2) {
				ret = 0;
				goto set_done;
			}
			G1_LOG_WRN("ble recv raster_config_info:enable is %d, raster_height_gear is %d, canvas_distance_gear is %d\n",
				   data[5], data[6], data[7]);
			if (data[5] == 1) {
				state->dashboard_ts->f_73 = 1;
				state->task_1020->f_00 = 1;
				state->panel_raster_height_offset = data[6];
				state->panel_canvas_distance_gear = data[7];
			} else {
				state->task_1020->f_00 = 0;
				ret = 0;
				goto set_done;
			}
			update_persist_task_status(state, 15, 2);
			ret = 0;
			goto set_done;
		default:
			ret = 0;
			goto set_done;
		}
		out[0] = BLE_RESP_OK;
		ret = 1;
set_done:
		return ret;
	} else if (req >= 0x29 && req <= 0x45) {
		switch (req) {
		case BLE_CMD_SILENT_MODE_GET:
			out[0] = state->f_fee;
			out[1] = get_wear_state_event();
			return 2;
		case BLE_CMD_ANTI_SHAKE_GET:
			out[0] = state->f_f64;
			return 1;
		case BLE_CMD_BRIGHTNESS_GET:
			out[0] = state->panel_brightness;
			out[1] = state->f_f9c;
			return 2;
		case BLE_CMD_DEVICE_INFO_GET:
			l = battery_left(state);
			if (state->battery_info[1] == 93) {
				r = 94;
			} else if (state->battery_info[1] == 94) {
				r = 96;
			} else if (state->battery_info[1] == 95) {
				r = 98;
			} else if (state->battery_info[1] == 96) {
				r = 99;
			} else if (state->battery_info[0] > 96) {
				r = 100;
			} else {
				r = state->battery_info[1];
			}
			out[0] = l;
			out[1] = r;
			out[2] = state->battery_voltage;
			out[3] = state->battery_current;
			out[4] = state->f_fca;
			memcpy(&out[5], state->f_fd0, 14);
			return 0x13;
		case BLE_CMD_MAC_GET:
			memcpy(&out[0], state->master_mac, 6);
			memcpy(&out[6], state->slave_mac, 6);
			return 12;
		case BLE_CMD_HEAD_UP_ANGLE_GET:
			out[0] = state->f_ef8;
			out[1] = state->f_ef9;
			return 2;
		case BLE_CMD_GLASSES_SN_GET:
			memcpy(out, FUN_00025340(), 16);
			return 16;
		case BLE_CMD_DEVICE_SN_GET:
			memcpy(out, get_serial_number(), 16);
			return 16;
		case BLE_CMD_ESB_CHANNEL_GET:
			out[0] = state->esb_channel;
			return 1;
		case BLE_CMD_NOTIF_COUNT_GET:
			return get_notification_counts_cmd_response(state, out);
		case BLE_CMD_TIME_SINCE_BOOT_GET:
			uint32_to_little_endian(out, get_boot_seconds());
			out[4] = !state->f_ae3 && k_sem_count_get(&state->ble_context.sem_230) != 0;
			return 5;
		default:
			return 0;
		}
	} else if (req >= 0x47 && req <= 0x56) {
		switch (req) {
		case BLE_CMD_NOTIFICATION_SEND:
			return post_notification_cmd_response(state, (uint8_t *)head, &state->sync_cmd,
							      (uint8_t *)head, data, out, len);
		case BLE_CMD_SYNC_DISPLAY:
			v = data[0];
			if (v & 2) {
				state->sync_flags = 0x83;
				state->f_0ca = 1;
				uint8_t pkt[0xfc] = {0};

				pkt[0] = 2;
				memcpy(&pkt[1], &state->sync_flags, 11);
				memset(&pkt[12], 0, 21);
				state->esb_send(pkt, sizeof(pkt));
			}
			if (v & 1) {
				state->fn_1040(&state->refresh_sem);
			}
			break;
		case BLE_CMD_TEXT_SET:
			state->task_1010->data[0x1e6 - 8] = 0;
			if (!state->task_1010->f_07) {
				state->task_1010->f_07 = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->f_1068->task != 16) {
				update_persist_task_status(state, 16, 2);
			}
			return 1;
		case BLE_CMD_NOTIFICATION_CLEAR:
			FUN_0007f38a(__builtin_bswap32(head->word));
			break;
		case BLE_CMD_MTU_SET:
			k_sem_give(&get_dashboard_state()->ble_context.sem_230);
			break;
		case BLE_CMD_NOTIF_AUTO_DISPLAY_SET:
			get_dashboard_state()->message_mode = data[0];
			get_dashboard_state()->message_stay_time = data[1];
			req = head->req_type;
			get_dashboard_state()->dashboard_cmd = req;
			k_sem_give(&get_dashboard_state()->dashboard_position_sem);
			out[0] = BLE_RESP_OK;
			out[1] = data[0];
			return 2;
		default:
			return 0;
		}
		out[0] = BLE_RESP_OK;
		return 1;
	}
	return process_recv_ble_req(head, out);
}


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
#include "../ble/ble_cmd.h"
#include "../ble/ble_ancs.h"
#include "../notify/notify.h"
#include "../sensors_audio/sensors_audio.h"
#include "../storage/storage.h"
#include "../ui/ui.h"
#include "../utils/burial_point.h"
#include "../utils/md5.h"

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

static inline __attribute__((always_inline)) int read_fw_pack_from_nor_flash_by_qspi(uint32_t addr, uint8_t *buf, uint32_t len)
{
	int ret;

	if (get_dashboard_state()->flash_read == NULL) {
		return -1;
	}
	ret = get_dashboard_state()->flash_read(get_dashboard_state(), addr, buf, len);
	if (ret) {
		G1_LOG_ERR("read flash fail: %d\n\n", ret);
		return ret;
	}
	return len;
}

static inline __attribute__((always_inline)) int process_recv_ble_req(struct ble_req *head, uint8_t *out)
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

int master_process_put_req(struct GlassesState *state, struct ble_req *head, uint8_t *out, uint32_t len);

/*
 * Not in the image (gc'd).  Reconstructed from the layout: the shipped __func__ order
 * (master_process_put_req, read_fw_pack..., process_recv_ble_req) needs both helpers analysed before
 * master_process_put_req, and their strings stay in master's section, so the caller is expanded after it.
 */
int ble_req_selftest(struct GlassesState *state, struct ble_req *head, uint8_t *out, uint32_t len)
{
	process_recv_ble_req(head, out);
	read_fw_pack_from_nor_flash_by_qspi(0, out, len);
	return master_process_put_req(state, head, out, len);
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
		bool done = false;

		switch (req) {
		case BLE_CMD_BRIGHTNESS_SET:
			if (state->panel.panel_brightness_level != data[0] || state->opt3007_context.auto_brightness != data[1]) {
				state->panel.set_brightness_cb(&state->panel, data[0]);
				state->opt3007_context.auto_brightness = data[1];
				notify_dashboard(state, head);
			}
			out[0] = data[0];
			out[1] = data[1];
			out[2] = BLE_RESP_OK;
			ret = 3;
			done = true;
			break;
		case BLE_CMD_ANTI_SHAKE_SET:
			if (state->imu.dof3_enable != data[0]) {
				state->imu.dof3_enable = data[0];
				notify_dashboard(state, head);
			}
			break;
		case BLE_CMD_SILENT_MODE_SET:
			v = data[0];
			arg = data[1];
			if (v >= 10 && v <= 12) {
				uint8_t cur = state->display_mode;

				if (v == cur) {
					break;
				}
				if (state->is_master == 1) {
					if (cur != 12) {
						if (v == 12) {
							request_not_disturb_bitmap(0);
						}
					} else if (v != 12 && arg != 1) {
						show_not_disturb_bitmap(1);
					}
				} else if (state->is_master == 2 && cur == 12) {
					if (v != 12 && arg != 1) {
						show_not_disturb_bitmap(1);
					}
				}
				state->display_mode = v;
				notify_dashboard(state, head);
				if (!state->imu_busy && v == 11) {
					state->imu_event = 3;
					k_sem_give(&state->imu_sem);
					ret = 0;
					done = true;
					break;
				}
				break;
			}
			out[0] = BLE_RESP_INVALID;
			ret = 1;
			done = true;
			break;
		case BLE_CMD_DEBUG_CONTROL:
			v = data[0];
			arg = data[1];
			if (v == 1) {
				trigger_imu_state_change("debug-ble", state, arg != 0);
			} else if (v == 2) {
				LOG_LEVEL = arg;
				printk("log_level_set=%d", arg);
			} else if (v == 3) {
				state->dashboard_mode = arg;
			}
			memcpy(out, "Good", 5);
			ret = 5;
			done = true;
			break;
		case BLE_CMD_COUNTDOWN_TIMER:
			ts = head->word;
			state->countdown_ts->enabled = data[4];
			state->countdown_ts->seconds = ts;
			state->countdown_ts->reset = 1;
			notify_dashboard(state, head);
			out[0] = BLE_RESP_OK;
			if (state->countdown_ts->enabled) {
				update_persist_task_status(state, 2, 2);
			}
			ret = 1;
			done = true;
			break;
		case BLE_CMD_TELEPROMPTER_INFO:
			memcpy(state->teleprompter, data, 0x217);
			if (!data[1]) {
				memset(state->teleprompter, 0, 0x217);
			}
			if (data[1]) {
				update_persist_task_status(state, 9, 2);
			}
			ret = 0;
			done = true;
			break;
		case BLE_CMD_TRANSLATE_SRC_TEXT:
			if (dmic_get_stop_state()) {
				ret = 0;
				done = true;
				break;
			}
			state->translate_src->data[0x1e5 - 6] = 0;
			if (!state->translate_src->data[0]) {
				state->translate_src->data[0] = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->task_status->task != 11) {
				update_persist_task_status(state, 11, 2);
			}
			ret = 1;
			done = true;
			break;
		case BLE_CMD_TRANSLATE_DST_TEXT:
			if (dmic_get_stop_state()) {
				ret = 0;
				done = true;
				break;
			}
			state->translate_dst->data[0x1e5 - 6] = 0;
			if (!state->translate_dst->data[0]) {
				state->translate_dst->data[0] = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->task_status->task != 11) {
				update_persist_task_status(state, 11, 2);
			}
			ret = 1;
			done = true;
			break;
		case BLE_CMD_HEAD_UP_ACTION_SET:
			memcpy(state->user_sched_info, data, 0x16a);
			*(uint32_t *)state->dashboard_ts = state->user_sched_info->ts;
			accumulate_elapsed_seconds((uint32_t *)state->dashboard_ts, 0, 1);
			notify_dashboard(state, head);
			break;
		case BLE_CMD_HEAD_UP_ANGLE_SET:
			v = data[0];
			arg = data[1];
			if (state->imu.level != v || state->imu.wear != arg) {
				state->imu.level = v;
				state->imu.wear = arg;
				notify_dashboard(state, head);
			}
			break;
		case BLE_CMD_NOTIFY_EN:
			v = data[0];
			G1_LOG_ERR("BLE_REQ_PUT_NOTIFY_EN enable:%d\n", v);
			set_ancs_enable(v);
			break;
		case 0x11:
			state->dashboard_cmd = 7;
			k_sem_give(&state->dashboard_position_sem);
			ret = 0;
			done = true;
			break;
		case BLE_CMD_HARDWARE_SET:
			if (data[4] != 2) {
				ret = 0;
				done = true;
				break;
			}
			G1_LOG_WRN("ble recv raster_config_info:enable is %d, raster_height_gear is %d, canvas_distance_gear is %d\n",
				   data[5], data[6], data[7]);
			if (data[5] == 1) {
				state->dashboard_ts->dashboard_on = 1;
				state->raster_height_cfg[0] = 1;
				state->panel.raster_height_offset = data[6];
				state->panel.canvas_distance_gear = data[7];
			} else {
				state->raster_height_cfg[0] = 0;
				ret = 0;
				done = true;
				break;
			}
			update_persist_task_status(state, 15, 2);
			ret = 0;
			done = true;
			break;
		default:
			ret = 0;
			done = true;
			break;
		}
		if (!done) {
			out[0] = BLE_RESP_OK;
			ret = 1;
		}
		return ret;
	} else if (req >= 0x29 && req <= 0x45) {
		switch (req) {
		case BLE_CMD_SILENT_MODE_GET:
			out[0] = state->display_mode;
			out[1] = get_wear_state_event();
			return 2;
		case BLE_CMD_ANTI_SHAKE_GET:
			out[0] = state->imu.dof3_enable;
			return 1;
		case BLE_CMD_BRIGHTNESS_GET:
			out[0] = state->panel.panel_brightness_level;
			out[1] = state->opt3007_context.auto_brightness;
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
			out[4] = state->battery_temp;
			memcpy(&out[5], &state->master_fw_ver, 14);
			return 0x13;
		case BLE_CMD_MAC_GET:
			memcpy(&out[0], state->master_mac, 6);
			memcpy(&out[6], state->slave_mac, 6);
			return 12;
		case BLE_CMD_HEAD_UP_ANGLE_GET:
			out[0] = state->imu.level;
			out[1] = state->imu.wear;
			return 2;
		case BLE_CMD_DEVICE_SN_GET:
			memcpy(out, get_serial_number(), 16);
			return 16;
		case BLE_CMD_GLASSES_SN_GET:
			memcpy(out, get_glasses_name(), 16);
			return 16;
		case BLE_CMD_ESB_CHANNEL_GET:
			out[0] = state->esb_channel;
			return 1;
		case BLE_CMD_NOTIF_COUNT_GET:
			return get_notification_counts_cmd_response(state, out);
		case BLE_CMD_TIME_SINCE_BOOT_GET:
			uint32_to_little_endian(out, get_boot_seconds());
			out[4] = !state->ble_context.security_pending && k_sem_count_get(&state->ble_context.tx_sem) != 0;
			return 5;
		default:
			return 0;
		}
	} else if (req >= 0x47 && req <= 0x56) {
		switch (req) {
		case BLE_CMD_NOTIFICATION_SEND:
			return post_notification_cmd_response(state, (uint8_t *)head, (volatile uint8_t *)&state->sync,
							      (uint8_t *)head, data, out, len);
		case BLE_CMD_SYNC_DISPLAY:
			v = data[0];
			if (v & 2) {
				*(uint8_t *)&state->esb_hdr = 0x83; /* cmd 3, dir 2: byte write like the vendor */
				state->esb_arg1 = 1;
				uint8_t pkt[0xfc] = {0};

				pkt[0] = 2;
				memcpy(&pkt[1], &state->esb_hdr, 11);
				memset(&pkt[12], 0, 21);
				state->ipc_ctx.send(pkt, sizeof(pkt));
			}
			if (v & 1) {
				state->switch_to_dfu_cb(&state->main_sem);
			}
			break;
		case BLE_CMD_TEXT_SET:
			state->dash_buf->data[0x1e6 - 7] = 0;
			if (!state->dash_buf->data[0]) {
				state->dash_buf->data[0] = 10;
			}
			out[0] = BLE_RESP_OK;
			if (state->task_status->task != 16) {
				update_persist_task_status(state, 16, 2);
			}
			return 1;
		case BLE_CMD_NOTIFICATION_CLEAR:
			ancs_delete_notification(__builtin_bswap32(head->word));
			break;
		case BLE_CMD_MTU_SET:
			k_sem_give(&get_dashboard_state()->ble_context.tx_sem);
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


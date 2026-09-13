/*
 * Even Realities G1 - application core main.
 * Reconstructed from the v1.63 firmware image.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/drivers/mfd/npm1300.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/sys/atomic.h>
#include <hal/nrf_ipc.h>
#include <stdlib.h>

#define MODULE main
#include <caf/events/module_state_event.h>

#include <g1_date.h>
#include <vendor_drivers.h>
#include "g1_log.h"
#include "main.h"
#include "aw9320x/aw9320x.h"
#include "ble/ble_ancs.h"
#include "button/button.h"
#include "dashboard/dashboard.h"
#include "display/proxy_thread.h"
#include "imu/imu_fusion.h"
#include "ipc/ipc_host.h"
#include "nfc/nfc_wlc.h"
#include "notify/notify.h"
#include "panel_display/panel.h"
#include "production_test/production_test.h"
#include "sensors_audio/sensors_audio.h"
#include "spim_spis/spim.h"
#include "storage/storage.h"
#include "threads/threads.h"
#include "ui/ui.h"
#include "utils/burial_point.h"

/* ------------------------------------------------------------------ */
/* globals                                                             */
/* ------------------------------------------------------------------ */
uint8_t runtime_mode;           /* 0x2001095c, settings key "runtime_mode" */
char net_build_time[32];            /* name reported by the net core */
uint8_t slave_msg_key_pending;
static uint8_t timer_count;     /* 0x2001093a */
static uint8_t work_mode_busy;  /* 0x20010939 */
static uint8_t esbm_last_seq;     /* 0x20010938 */
struct GlassesState *GLOBAL_STATE;
int DEVICE_ROLE;
int esb_tx_count;
int esb_tx_fail_count;
int esb_rx_count;

int esb_signal;                 /* cpunet ESB package counters */
static bool first_sync = true;    /* 0x20003002 */
int LOG_LEVEL = 2;
int rtc_sync_timer_running = 1; /* 0x20002308 */

void timeout_handler(struct k_timer *timer);
void periodic_timer_expiry(struct k_timer *timer);

/* 60 s housekeeping timer.  K_TIMER_DEFINE objects are sorted by name
 * (._k_timer.static.*): the target order os_mgmt_reset_timer, this timer,
 * rtc_sync_timer needs a name between "os_mgmt_reset_timer" and
 * "rtc_sync_timer" (the vendor name is unknown). */
K_TIMER_DEFINE(periodic_timer, periodic_timer_expiry, NULL);    /* 0x20003868 */
K_TIMER_DEFINE(rtc_sync_timer, timeout_handler, NULL); /* 0x200038a0 */

/* retained block shared with bootloader / net core, linked at 0x2007fc00 */
struct ncs_mem ncs_mem __attribute__((section(".ncs_mem")));

enum work_module {
	WORK_MODULE_TOUCH = 0x001,
	WORK_MODULE_DMIC = 0x002,
	WORK_MODULE_0008 = 0x008,
	WORK_MODULE_EXT_FLASH = 0x010,
	WORK_MODULE_IMU = 0x020,
	WORK_MODULE_ESB = 0x040,
	WORK_MODULE_BLE = 0x080,
	WORK_MODULE_SYSTEM = 0x100,
	WORK_MODULE_NFC = 0x400,
	WORK_MODULE_SHIPMODE = 0x800,
};

void set_band_for_ESB(uint8_t band);
static int local_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len);
static int local_esbm_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len);
static int local_esbs_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len);
void update_work_module(int enable, int module);

#define RTC_SYNC_WORD (*(volatile uint32_t *)0x20070000)

#define PMIC_LDO1  DEVICE_DT_GET(DT_NODELABEL(pmic_ldo1))
#define PMIC_LDO2  DEVICE_DT_GET(DT_NODELABEL(pmic_ldo2))
#define PMIC_BUCK2 DEVICE_DT_GET(DT_NODELABEL(pmic_buck2))
#define DFU_FLASH  DEVICE_DT_GET(DT_NODELABEL(mx25r64))

#define NPM_MFD(dev) (((const struct regulator_npm1300_config *)(dev)->config)->mfd)

void periodic_timer_expiry(struct k_timer *timer)
{
	if (get_pt_test_mode() == 1) {
		return;
	}
	timer_count++;
	get_burial_point_day_index();
	update_burial_point_day_index();
	if (get_wearing_state() == 1 && !is_in_box()) {
		add_wear_burial_time(60000);
	}
	if (timer_count > 9) {
		timer_count = 0;
		GLOBAL_STATE->dashboard_cmd = 0x3e;
		k_sem_give(&GLOBAL_STATE->dashboard_position_sem);
	}
}

/* 1.66: gs is unused.  GCC then emits the function as a .constprop clone, a late
 * call-graph node whose expansion walk places it after periodic_timer_expiry and
 * pulls local_esbs_ipc_service_recv behind it, as in the image (in 1.63 the
 * k_msleep(500) before sys_reboot, now inside system_reboot_delayed(), did that
 * through k_msleep.isra.0).  As a plain static function it would come out before
 * periodic_timer_expiry; as a public one its __func__ would be the oldest. */
static void switch_to_dfu_mode(struct GlassesState *gs, struct k_sem *sem)
{
	int ret;

	runtime_mode = 1;
	if (k_is_in_isr()) {
		k_sem_give(sem);
		return;
	}
	ret = GLOBAL_STATE->store.write("runtime_mode", &runtime_mode, 1);
	if (ret != 0) {
		G1_LOG(0, "failed to switch to ble mode [%d]\n", ret);
		return;
	}
	G1_LOG(0, "sys reboot because system reset %d, %d\n", 0, runtime_mode);
	system_reboot_delayed();
}

#define ESB_CMD_MASK  0x3f
#define ESB_DIR_MASK  0xc0
#define ESB_DIR_UP    0x80
#define ESB_DIR_DOWN  0x40

/* the vendor main.c is longer: from here on, line numbers follow it (the logs print __LINE__) */
#line 707
static int local_esbs_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	uint8_t buf[22] = {0};
	struct esb_sync_pkt *new_data_pkg = (struct esb_sync_pkt *)buf;
	struct esb_sync_pkt *data_pkg = &gs->sync;
	struct GlassesState *g;
	struct notif_msg *slot;
	uint32_t id;
	uint8_t cmd, dist;

	memcpy(new_data_pkg, &data[11], sizeof(*new_data_pkg));
	if (new_data_pkg->package_id == data_pkg->package_id) {
		G1_LOG(0, "slave recv same package\n");
		return 0;
	}
	if (new_data_pkg->package_id != (uint8_t)(data_pkg->package_id + 1)) {
		G1_LOG(0, "###############loss package new_data_pkg->package_id %d data_pkg->package_id %d\n",
		       new_data_pkg->package_id, data_pkg->package_id);
	}

	cmd = buf[0] & ESB_CMD_MASK;
	if (cmd == 1) {
		if (gs->suspend_state == 1) {
			data_pkg->package_id++;
			G1_LOG(0, "slave recv suspend package\n");
			return 0;
		}
	} else if (cmd == 2) {
		if (gs->suspend_state == 0) {
			data_pkg->package_id++;
			G1_LOG(0, "slave recv resume package\n");
		}
	}
	if (data_pkg->screen_id != new_data_pkg->screen_id && cmd == 8) {
		data_pkg->package_id++;
		G1_LOG(0, "screen id is not same\n");
		return 0;
	}

	if (data_pkg->screen_id == 9 || data_pkg->screen_id == 11 || data_pkg->screen_id == 10) {
		if ((buf[0] & ESB_DIR_MASK) == ESB_DIR_UP) {
			if (gs->esb_up_recving) {
				data_pkg->package_id++;
				G1_LOG(0, "slave recv up recving\n");
				return 0;
			}
		} else if ((buf[0] & ESB_DIR_MASK) == ESB_DIR_DOWN && gs->esb_down_recving) {
			data_pkg->package_id++;
			G1_LOG(0, "slave recv down recving\n");
			return 0;
		}
	} else if (data_pkg->screen_id == 0x10 && gs->esb_up_recving) {
		G1_LOG(0, "slave even ai recv down recving\n");
		data_pkg->package_id++;
		return 0;
	}

	if (new_data_pkg->screen_id != 6 && new_data_pkg->screen_id != 0) {
		gs->esb_up_seq = data[3];
		gs->esb_down_seq = data[4];
		if (cmd == 0) {
			if ((buf[0] & ESB_DIR_MASK) == ESB_DIR_UP ||
			    (new_data_pkg->screen_id == 0x10 && GLOBAL_STATE->dash_buf->type >= 6 &&
			     GLOBAL_STATE->dash_buf->type <= 9)) {
				if (gs->esb_up_id != data[3] && gs->esb_up_snapshot[0x200] != data[3]) {
					data_pkg->package_id++;
					G1_LOG(0, "slave recv wrong up package\n");
					return 0;
				}
			} else if (gs->esb_down_id != data[4] && gs->esb_down_snapshot[0x200] != data[4]) {
				data_pkg->package_id++;
				G1_LOG(0, "slave recv wrong down package\n");
				return 0;
			}
		}
	}

	gs->esb_hdr.cmd = data[0] & ESB_CMD_MASK;
	gs->esb_arg1 = data[1];
	gs->esb_arg2 = data[2];
	set_date(UNALIGNED_GET((const uint32_t *)&data[7]));
	new_data_pkg->screen_id = data_pkg->screen_id;
	*data_pkg = *new_data_pkg;
	gs->imu.mode = new_data_pkg->hdr.dir;
	gs->dashboard_ts->ts = UNALIGNED_GET((const uint32_t *)&data[7]);
	if (gs->user_sched_info->ts) {
		gs->user_sched_info->ts = gs->dashboard_ts->ts;
	}
	gs->esb_dir = new_data_pkg->hdr.dir;
	gs->esb_screen_id = new_data_pkg->screen_id;
	if (new_data_pkg->flags & BIT(2)) {
		clear_all_messages();
		data_pkg->flags &= ~BIT(2);
	}

	switch (new_data_pkg->hdr.cmd) {
	case 8:
		if (data_pkg->screen_id != new_data_pkg->screen_id && cmd == 8) {
			G1_LOG(0, "screen id is not same, exit\n");
			return 0;
		}
		exit_running_task_keep_status(GLOBAL_STATE, 0);
		if (new_data_pkg->arg[0] && GLOBAL_STATE->sync.screen_id == 4) {
			expire_cur_message();
			if (GLOBAL_STATE->sync.unread_msg_num) {
				set_msg_show_state(6);
			} else {
				set_msg_show_state(0);
			}
		}
		if (GLOBAL_STATE->imu.mode == 2) {
			get_dashboard_startup_mode();
		}
		update_persist_task_status_to_idle(GLOBAL_STATE);
		k_sem_give(&GLOBAL_STATE->sem_2);
		break;
	case 10:
		if (GLOBAL_STATE->esb_pkt.flags & BIT(2)) {
			return 0;
		}
		slot = find_push_message_by_uid(UNALIGNED_GET((uint32_t *)new_data_pkg->arg));
		G1_LOG(0, "##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_FIRST slave before\n",
		       __func__, __LINE__);
		if (slot && slot->sync_state == 0) {
			slot->sync_state = 2;
		}
		break;
	case 11:
		/* the master confirmed the end of the notification display */
		if (GLOBAL_STATE->esb_pkt.flags & BIT(2)) {
			return 0;
		}
		id = UNALIGNED_GET((uint32_t *)new_data_pkg->arg);
		slot = find_push_message_by_uid(id);
		G1_LOG(0, "##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_END slave before\n",
		       __func__, __LINE__);
		if (slot && slot->sync_state == 2) {
			slot->sync_state = 4;
			confirm_message(id);
			push_msg_syncing = 0;
		}
		break;
	case 13:
		reset_dash_buf(0);
		g = GLOBAL_STATE;
		g->dash_buf->type = 2;
		if (g->task_status->task != 0x10) {
			update_persist_task_status(g, 0x10, 2);
		}
		break;
	case 14:
		GLOBAL_STATE->dash_buf->type = 4;
		break;
	case 15:
		GLOBAL_STATE->dash_buf->type = 6;
		break;
	case 16:
		g = GLOBAL_STATE;
		g->dash_buf->type = 11;
		g->sync.stay_time_left_s = 8;
		break;
	case 17:
		GLOBAL_STATE->dash_buf->type = 14;
		break;
	case 18:
		GLOBAL_STATE->dash_buf->type = 16;
		break;
	case 12:
		if (new_data_pkg->arg[0] == 11) {
			dist = new_data_pkg->arg[1];
			G1_LOG(1, "slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
			       dist, new_data_pkg->arg[2]);
			if (dist < 10 && new_data_pkg->arg[2] < 9) {
				g = GLOBAL_STATE;
				g->panel.canvas_distance_gear = dist;
				g->panel.raster_height_offset = new_data_pkg->arg[2];
				cal_panel_canvas_coord(&g->panel.y_offset, &g->panel.current_column);
			}
			if (GLOBAL_STATE->dashboard_ts->exit_pending) {
				GLOBAL_STATE->dashboard_ts->exit_pending = 0;
			}
		}
		break;
	default:
		k_sem_give(&gs->sem_1);
		break;
	}

	if (gs->esb_hdr.cmd == 3) {
		if (gs->esb_hdr.dir == 2) {
			if (gs->esb_arg1 == 1) {
				switch_to_dfu_mode(gs, &gs->main_sem);
			}
		}
	}
	return 0;
}

int power_for_panel(void)
{
	const struct regulator_npm1300_config *config;
	int ret;

	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO1), 0x08, 0x00, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set ldsw1.\n");
		return 0;
	}
	G1_LOG(0, "enable ldsw1 1.8v for panel\n");
	k_msleep(1);

	config = PMIC_BUCK2->config;
	if (GLOBAL_STATE->panel.voltage == 1) {
		ret = mfd_npm1300_reg_write(config->mfd, 0x04, 0x0a, 1);
		if (ret < 0) {
			G1_LOG(0, "Could not set buck2 to 1.1v.\n");
			return 0;
		}
		G1_LOG(0, "set buck2 to 1.1v\n");
	} else {
		ret = mfd_npm1300_reg_write(config->mfd, 0x04, 0x0a, 2);
		if (ret < 0) {
			G1_LOG(0, "Could not set buck2 to 1.2v.\n");
			return 0;
		}
		G1_LOG(0, "set buck2 to 1.2v\n");
	}
	ret = mfd_npm1300_reg_update(config->mfd, 0x04, 0x0f, 2, 2);
	if (ret < 0) {
		G1_LOG(0, "Could not enable software control\n");
		return 0;
	}
	ret = mfd_npm1300_reg_write(config->mfd, 0x04, 0x02, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set buck2.\n");
		return 0;
	}
	G1_LOG(0, "enable buck2.\n");
	k_msleep(1);
	panel_gpio_enable();
	k_msleep(15);
	G1_LOG(0, "turn on -2v for panel.\n");
	return 0;
}

int power_for_imu_and_mic(void)
{
	int ret;

	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO2), 0x08, 0x02, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set ldsw2.\n");
		return 0;
	}
	G1_LOG(0, "enable ldsw2 for imu and mic\n");
	return 0;
}

int power_down_panel(void)
{
	int ret;

	k_msleep(2);
	panel_gpio_disable();
	G1_LOG(0, "turn off -2v for panel.\n");
	k_msleep(16);
	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_BUCK2), 0x04, 0x03, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set buck2.\n");
		return 0;
	}
	G1_LOG(0, "disable buck2 1.2v\n");
	k_msleep(5);
	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO1), 0x08, 0x01, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set ldsw1.\n");
		return 0;
	}
	G1_LOG(0, "disable ldsw1 1.8v for panel\n");
	return 0;
}

int power_down_imu_and_mic(void)
{
	int ret;

	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_LDO2), 0x08, 0x03, 1);
	if (ret < 0) {
		G1_LOG(0, "Could not set ldsw2.\n");
		return 0;
	}
	G1_LOG(0, "disable ldsw2 for imu and mic\n");
	return 0;
}

int dump_pmic_state(void)
{
	const struct regulator_npm1300_config *config = PMIC_LDO2->config;
	uint8_t val = 0;

	mfd_npm1300_reg_write(config->mfd, 0x03, 0x10, 0xeb);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x11, 0x01);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x12, 0xad);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x13, 0x01);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x14, 0x3f);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x15, 0x03);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x16, 0x2e);
	mfd_npm1300_reg_write(config->mfd, 0x03, 0x17, 0x02);

	mfd_npm1300_reg_read(config->mfd, 0x03, 0x10, &val);
	printk("0x10 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x11, &val);
	printk("0x11 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x12, &val);
	printk("0x12 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x13, &val);
	printk("0x13 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x14, &val);
	printk("0x14 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x15, &val);
	printk("0x15 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x16, &val);
	printk("0x16 is %x\n", val);
	mfd_npm1300_reg_read(config->mfd, 0x03, 0x17, &val);
	printk("0x17 is %x\n", val);
	return 0;
}

/* IPC message to the network core carrying the runtime info */
struct ipc_runtime_msg {
	uint8_t type;
	uint8_t reserved;
	struct {
		uint8_t role;
		uint8_t mode;
		uint8_t esb_channel;
		uint8_t esb_master_addr;
		uint8_t esb_slave_addr;
	} info;
} __aligned(8);

int runtime_info_sync(struct GlassesState *gs)
{
	struct ipc_runtime_msg msg = {0};
	int ret;

	msg.type = 1;
	msg.info.role = gs->is_master;
	msg.info.mode = gs->work_mode;
	msg.info.esb_channel = gs->esb_channel;
	msg.info.esb_master_addr = gs->esb_master_addr;
	msg.info.esb_slave_addr = gs->esb_slave_addr;
	ret = global_ipc_service_send(&msg, sizeof(msg));
	if (first_sync) {
		first_sync = false;
		G1_LOG(1, "--role:%d --mode:%d, esb_channel %d --ret:%d esb_master_addr %02X esb_slave_addr %02X\n",
		       msg.info.role, msg.info.mode, msg.info.esb_channel, ret,
		       gs->esb_master_addr, gs->esb_slave_addr);
	}
	return ret;
}

enum {
	IPC_MSG_TICK_SYNC = 1,
	IPC_MSG_RUNTIME_INFO = 2,
	IPC_MSG_UPDATE_MACADDR = 3,
	IPC_MSG_SET_MACADDR = 4,
	IPC_MSG_BT_READY = 6,
	IPC_RESP_CPUNET_ESB_PACKAGES = 7,
	IPC_MSG_ESB_STATUS = 0x0d,
};

void timeout_handler(struct k_timer *timer)
{
	uint32_t ticks = sys_clock_tick_get_32();

	if (RTC_SYNC_WORD == 0xa5a5a5a5) {
		G1_LOG(1, "RTC has sync at %lld ms\n", k_uptime_get());
	} else {
		RTC_SYNC_WORD = ticks;
		nrf_ipc_task_trigger(NRF_IPC, NRF_IPC_TASK_SEND_2);
		G1_LOG(1, "IPC send at %d ticks %lld ms\n", ticks, k_uptime_get());
		if (ticks <= 0x28000) {
			return;
		}
	}
	k_timer_stop(timer);
	rtc_sync_timer_running = 0;
}

static int local_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	uint64_t uptime;

	switch (data[0]) {
	case IPC_MSG_TICK_SYNC:
		uptime = k_ticks_to_ms_ceil64(k_uptime_ticks());
		if (k_sem_count_get(&gs->ipc_sem) == 0) {
			k_sem_give(&gs->ipc_sem);
		}
		break;
	case IPC_MSG_RUNTIME_INFO:
		uptime = k_ticks_to_ms_ceil64(k_uptime_ticks());
		G1_LOG(1, "cpunet request send info uptime %lld\n", uptime);
		if (uptime > 10000) {
			G1_LOG(0, "sys reboot because recv cpunet sync package\n");
			system_reboot_delayed();
		}
		runtime_info_sync(gs);
		break;
	case IPC_MSG_UPDATE_MACADDR:
		uptime = k_ticks_to_ms_ceil64(k_uptime_ticks());
		if (GLOBAL_STATE->is_master == true) {
			memcpy(gs->master_mac, &data[1], sizeof(gs->master_mac));
		} else {
			memcpy(gs->slave_mac, &data[1], sizeof(gs->slave_mac));
		}
		G1_LOG(1, "cpunet request update macaddr info uptime %lld bt macaddr esb_master_addr %02X esb_slave_addr %02X \n",
		       uptime, gs->esb_master_addr, gs->esb_slave_addr);
		if (k_sem_count_get(&gs->ipc_sem) == 0) {
			k_sem_give(&gs->ipc_sem);
		}
		break;
	case IPC_MSG_BT_READY:
		if (!gs->bt_state) {
			gs->bt_state = 1;
		}
		G1_LOG(1, "bt_ready\n");
		if (k_sem_count_get(&gs->ipc_sem) == 0) {
			k_sem_give(&gs->ipc_sem);
		}
		strncpy(net_build_time, &data[1], len - 1);
		net_build_time[sizeof(net_build_time) - 1] = 0;
		break;
	case IPC_RESP_CPUNET_ESB_PACKAGES:
		memcpy(&esb_tx_count, &data[1], 4);
		memcpy(&esb_tx_fail_count, &data[5], 4);
		memcpy(&esb_rx_count, &data[9], 4);
		memcpy(&esb_signal, &data[13], 4);
		if (!gs->check_mode) {
			esb_signal = 70;
		}
		G1_LOG(1, "IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n",
		       esb_tx_count, esb_tx_fail_count, esb_rx_count, esb_signal);
		break;
	case IPC_MSG_SET_MACADDR:
		memcpy(gs->master_mac, &data[1], sizeof(gs->master_mac));
		memcpy(gs->slave_mac, &data[7], sizeof(gs->slave_mac));
		break;
	case IPC_MSG_ESB_STATUS:
		gs->sync_ack = data[1];
		break;
	default:
		G1_LOG(1, "sync fail! len: %d, data=%s\n\n", len, data);
		break;
	}
	return 0;
}

int getDeviceRole(void)
{
	return DEVICE_ROLE;
}

uint8_t is_master(void)
{
	return GLOBAL_STATE->is_master;
}

void set_ncs_mem_ts(uint32_t ts)
{
	NCS_MEM->ts = ts;
}

bool getEraseDFU(void)
{
	return NCS_MEM->erase_dfu;
}

void setEraseDFU(bool set)
{
	NCS_MEM->erase_dfu = set;
}

void set_ncs_mem_pt_level(uint8_t val)
{
	NCS_MEM->pt_level = val;
}

void set_ncs_mem_initialized(void)
{
	NCS_MEM->magic = NCS_MEM_MAGIC;
}

int is_ncs_mem_initialized(void)
{
	return NCS_MEM->magic == NCS_MEM_MAGIC ? 0 : -1;
}

void save_dashboard_ts_to_ncs_mem(void)
{
	struct dashboard_ts_context *ts = GLOBAL_STATE->dashboard_ts;

	NCS_MEM->ts = ts->ts;
	NCS_MEM->weather_icon = ts->weather_icon;
	NCS_MEM->temperature = ts->temperature;
	NCS_MEM->ms_ts = ts->ms_ts;
	NCS_MEM->temp_unit = ts->temp_unit;
	NCS_MEM->time_disp_mode = ts->time_disp_mode;
	NCS_MEM->retained_b = ts->retained_b;
	NCS_MEM->retained_a = ts->retained_a;
	memcpy(NCS_MEM->retained_buf_a, ts->retained_buf_a, sizeof(NCS_MEM->retained_buf_a));
	memcpy(NCS_MEM->retained_buf_b, ts->retained_buf_b, sizeof(NCS_MEM->retained_buf_b));
}

void restore_dashboard_ts_from_ncs_mem(void)
{
	struct GlassesState *gs = GLOBAL_STATE;

	gs->dashboard_ts->ts = NCS_MEM->ts + 1;
	gs->dashboard_ts->weather_icon = NCS_MEM->weather_icon;
	gs->dashboard_ts->temperature = NCS_MEM->temperature;
	gs->dashboard_ts->ms_ts = NCS_MEM->ms_ts;
	gs->dashboard_ts->temp_unit = NCS_MEM->temp_unit;
	gs->dashboard_ts->time_disp_mode = NCS_MEM->time_disp_mode;
	gs->dashboard_ts->retained_b = NCS_MEM->retained_b;
	gs->dashboard_ts->retained_a = NCS_MEM->retained_a;
	gs->dashboard_ts->retained_c = NCS_MEM->retained_c;
	if (NCS_MEM->notes_index < 4) {
		notes_index = NCS_MEM->notes_index;
	}
	memcpy(gs->dashboard_ts->retained_buf_a, NCS_MEM->retained_buf_a, sizeof(NCS_MEM->retained_buf_a));
	memcpy(gs->dashboard_ts->retained_buf_b, NCS_MEM->retained_buf_b, sizeof(NCS_MEM->retained_buf_b));
}

void set_ncs_mem_notes_index(uint8_t idx)
{
	NCS_MEM->notes_index = idx;
}

void deinit_ncs_memory(void)
{
	NCS_MEM->ms_ts = 0;
	NCS_MEM->ts = 0;
	NCS_MEM->weather_icon = 0;
	NCS_MEM->temperature = 0;
	NCS_MEM->temp_unit = 0;
	NCS_MEM->time_disp_mode = 0;
	NCS_MEM->retained_a = 0;
	NCS_MEM->retained_b = 0;
	NCS_MEM->retained_c = 0;
	memset(NCS_MEM->retained_buf_a, 0, sizeof(NCS_MEM->retained_buf_a));
	memset(NCS_MEM->retained_buf_b, 0, sizeof(NCS_MEM->retained_buf_a));
	NCS_MEM->magic = 0;
}

struct GlassesState *get_dashboard_state(void)
{
	return GLOBAL_STATE;
}

int erase_dfu_flash(void)
{
	const struct device *flash = DFU_FLASH;

	if (!device_is_ready(flash)) {
		printk(" [%s] device not ready.\n", flash->name);
		return -1;
	}
	flash_erase(flash, 0, 0x130000);
	printk("erase_dfu_flash done.\n");
	return 0;
}

int set_shipmode(int enable)
{
	int ret;

	power_down_panel();
	power_down_imu_and_mic();
	k_msleep(2000);
	ret = mfd_npm1300_reg_write(NPM_MFD(PMIC_BUCK2), 0x0b, 0x02, 1);
	if (ret < 0) {
		printk("Could not set shipmode.\n");
	} else {
		printk("enable for shipmode\n");
	}
	return 0;
}

void set_band_for_ESB(uint8_t band)
{
	uint8_t msg[64] = {0};

	msg[0] = 1;
	msg[1] = band;
	global_ipc_service_send(msg, 4);
}

void imu_module_set_mode(int enable)
{
	int mode = 0;

	if (enable == 1) {
		mode = 1;
	} else if (enable == 2) {
		mode = 2;
	}
	update_imu_mode(&GLOBAL_STATE->imu, mode);
}

/* Ghidra calls this update_imu_mode (clashes with the real one at 0x281dc) */
void update_work_module(int enable, int module)
{
	struct GlassesState *gs = GLOBAL_STATE;

	if (enable) {
		gs->module_mask |= module;
	} else {
		gs->module_mask &= ~module;
	}
	if (!gs->work_mode) {
		return;
	}
	switch (module) {
	case WORK_MODULE_IMU:
		if (gs->is_master == true) {
			imu_module_set_mode(enable);
		} else {
			k_msleep(50);
		}
		break;
	case WORK_MODULE_TOUCH:
		if (enable) {
			touch_power_on();
		} else {
			touch_power_off();
		}
		break;
	case WORK_MODULE_NFC:
		if (enable) {
			nfc_lpd_off();
		} else {
			nfc_lpd_on();
		}
		break;
	case WORK_MODULE_SYSTEM:
		if (get_pt_test_mode() == 0) {
			if (enable) {
				global_system_resume(GLOBAL_STATE);
			} else {
				global_system_suspend(GLOBAL_STATE);
			}
		}
		break;
	case WORK_MODULE_BLE:
		if (enable) {
			bt_start();
		} else {
			stop_ble_advertising();
		}
		break;
	case WORK_MODULE_ESB:
		switch (enable) {
		case 2:
			set_band_for_ESB(0x0a);
			break;
		case 1:
			set_band_for_ESB(0x0b);
			break;
		default:
			set_band_for_ESB(0x0c);
			break;
		}
		break;
	case WORK_MODULE_SHIPMODE:
		if (!enable) {
			set_shipmode(1);
		}
		break;
	}
}

int get_work_mode(void)
{
	return GLOBAL_STATE->work_mode;
}

int change_work_mode(int mode)
{
	int retry = 5000;

	while (work_mode_busy) {
		if (--retry == 0) {
			break;
		}
		k_msleep(1);
	}
	work_mode_busy = 1;
	if (GLOBAL_STATE->work_mode != mode || GLOBAL_STATE->suspend_state == 5) {
		GLOBAL_STATE->work_mode = mode;
		G1_LOG(0, "change_work_mode to %d\n", (uint8_t)mode);

		switch (GLOBAL_STATE->work_mode) {
		case 0:
			update_work_module(1, WORK_MODULE_EXT_FLASH);
			update_work_module(1, WORK_MODULE_SYSTEM);
			update_work_module(1, WORK_MODULE_IMU);
			update_work_module(1, WORK_MODULE_BLE);
			update_work_module(1, WORK_MODULE_ESB);
			update_work_module(1, WORK_MODULE_0008);
			update_work_module(1, WORK_MODULE_DMIC);
			update_work_module(1, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			break;
		case 1:
			update_work_module(1, WORK_MODULE_EXT_FLASH);
			update_work_module(0, WORK_MODULE_SYSTEM);
			update_work_module(0, WORK_MODULE_IMU);
			update_work_module(1, WORK_MODULE_BLE);
			update_work_module(0, WORK_MODULE_ESB);
			update_work_module(0, WORK_MODULE_0008);
			update_work_module(0, WORK_MODULE_DMIC);
			update_work_module(0, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			{
				uint8_t msg[64] = {0};

				msg[0] = 1;
				msg[1] = 8;
				global_ipc_service_send(msg, 4);
			}
			break;
		case 2:
			update_work_module(1, WORK_MODULE_EXT_FLASH);
			update_work_module(1, WORK_MODULE_SYSTEM);
			update_work_module(2, WORK_MODULE_IMU);
			update_work_module(1, WORK_MODULE_BLE);
			update_work_module(1, WORK_MODULE_ESB);
			update_work_module(0, WORK_MODULE_0008);
			update_work_module(1, WORK_MODULE_DMIC);
			update_work_module(1, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			memset(GLOBAL_STATE->ui.buf, 0, sizeof(GLOBAL_STATE->ui.buf));
			break;
		case 3:
			update_work_module(0, WORK_MODULE_SYSTEM);
			update_work_module(0, WORK_MODULE_EXT_FLASH);
			update_work_module(1, WORK_MODULE_IMU);
			update_work_module(1, WORK_MODULE_BLE);
			update_work_module(1, WORK_MODULE_ESB);
			update_work_module(0, WORK_MODULE_0008);
			update_work_module(1, WORK_MODULE_DMIC);
			update_work_module(1, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			break;
		case 4:
		case 5:
		case 6:
			update_work_module(0, WORK_MODULE_EXT_FLASH);
			update_work_module(0, WORK_MODULE_SYSTEM);
			update_work_module(0, WORK_MODULE_IMU);
			update_work_module(1, WORK_MODULE_BLE);
			update_work_module(1, WORK_MODULE_ESB);
			update_work_module(0, WORK_MODULE_0008);
			update_work_module(0, WORK_MODULE_DMIC);
			update_work_module(0, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			break;
		case 8:
			update_work_module(0, WORK_MODULE_SYSTEM);
			update_work_module(0, WORK_MODULE_EXT_FLASH);
			update_work_module(0, WORK_MODULE_IMU);
			update_work_module(0, WORK_MODULE_BLE);
			update_work_module(0, WORK_MODULE_ESB);
			update_work_module(0, WORK_MODULE_0008);
			update_work_module(0, WORK_MODULE_DMIC);
			update_work_module(0, WORK_MODULE_TOUCH);
			update_work_module(0, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			break;
		case 9:
			update_work_module(0, WORK_MODULE_SYSTEM);
			update_work_module(1, WORK_MODULE_EXT_FLASH);
			update_work_module(1, WORK_MODULE_IMU);
			update_work_module(0, WORK_MODULE_BLE);
			update_work_module(0, WORK_MODULE_ESB);
			update_work_module(1, WORK_MODULE_0008);
			update_work_module(1, WORK_MODULE_DMIC);
			update_work_module(1, WORK_MODULE_TOUCH);
			update_work_module(1, WORK_MODULE_NFC);
			update_work_module(1, WORK_MODULE_SHIPMODE);
			break;
		case 7:
			set_shipmode(1);
			break;
		default:
			break;
		}
	}
	work_mode_busy = 0;
	return 0;
}

static int local_esbm_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	const struct notif_msg *src;
	struct notif_msg *slot;
	uint8_t cmd = data[0] & 0x3f;

	if (cmd != 0 && (uint8_t)(cmd - 12) > 1) {
		if (esbm_last_seq == data[0x15]) {
			return 0;
		}
		esbm_last_seq = data[0x15];
		gs->fw_ver.major = gs->esb_pkt.ver_battery_raw[0];
		gs->fw_ver.minor = gs->esb_pkt.ver_battery_raw[1];
		gs->fw_ver.patch = gs->esb_pkt.ver_battery_raw[2];
		gs->battery_right = gs->esb_pkt.ver_battery_raw[3];
		memcpy(gs->slave_mac, gs->esb_pkt.mac, sizeof(gs->slave_mac));
		memcpy((void *)&gs->esb_pkt, data, sizeof(gs->esb_pkt));
		if (data[0x12] & BIT(2)) {
			clear_all_messages();
			gs->esb_pkt.flags &= ~BIT(2);
		}
	}

	switch (((const struct esb_hdr *)data)->cmd) {
	case 4:
		if (GLOBAL_STATE->sync.screen_id == 4) {
			expire_cur_message();
			if (GLOBAL_STATE->sync.unread_msg_num) {
				set_msg_show_state(6);
			} else {
				set_msg_show_state(0);
			}
		}
		atomic_or(&close_app_flags, BIT(1));
		exit_running_task(gs, 1);
		if (gs->imu.mode == 2) {
			get_dashboard_startup_mode();
		}
		update_persist_task_status_to_idle(gs);
		break;
	case 5:
		exit_running_task(gs, 1);
		change_work_mode(7);
		break;
	case 8:
		exit_running_task(gs, 1);
		gs->display_mode = 12;
		gs->dashboard_cmd = 3;
		k_sem_give(&gs->dashboard_position_sem);
		break;
	case 9:
		gs->display_mode = 10;
		gs->dashboard_cmd = 3;
		k_sem_give(&gs->dashboard_position_sem);
		show_not_disturb_bitmap(1);
		break;
	case 6:
		if (gs->esb_pkt.subcmd == 1) {
			gs->quicknote_show_info->longpress_req = 1;
		} else if (gs->esb_pkt.subcmd == 0) {
			gs->quicknote_show_info->longpress_req = 2;
		}
		break;
	case 7:
		SlaveDoubleClickEventInject();
		break;
	case 10:
		slave_msg_key_pending = 1;
		break;
	case 11:
		break;
	case 12:
		if ((GLOBAL_STATE->sync.flags & BIT(2)) || msg_array_busy) {
			break;
		}
		src = (const struct notif_msg *)&data[1];
		slot = get_message_by_index(data[0xd]);
		if (slot && !slot->busy &&
		    (src->uid != slot->uid || src->recv_time != slot->recv_time || slot->sync_state != 1)) {
			memcpy(slot, &data[1], 0xda);
			slot->sync_state = 1;
		}
		break;
	case 13:
		if ((GLOBAL_STATE->sync.flags & BIT(2)) || msg_array_busy) {
			break;
		}
		slot = get_push_message();
		if (slot && !slot->busy && slot->sync_state != 3) {
			memcpy((uint8_t *)slot + NOTIF_MSG_HALF, &data[1], 0xda);
			slot->sync_state = 3;
		}
		break;
	case 14:
		if (gs->esb_pkt.subcmd == 4) {
			GLOBAL_STATE->onboarding->action = gs->esb_pkt.value;
		} else if (gs->esb_pkt.subcmd == 5) {
			request_not_disturb_bitmap(gs->esb_pkt.value);
		}
		break;
	case 15:
		if (GLOBAL_STATE->dash_buf->type == 1) {
			break;
		}
		reset_dash_buf(0);
		GLOBAL_STATE->dash_buf->type = 1;
		break;
	case 16:
		if (GLOBAL_STATE->dash_buf->type == 4) {
			GLOBAL_STATE->dash_buf->type = 5;
		}
		break;
	case 17:
		if (gs->esb_pkt.subcmd == 6) {
			struct GlassesState *g = GLOBAL_STATE;

			if (g->task_status->task == 0x14 && g->evenai_buf->state == 1 &&
			    g->evenai_buf->sub == 4 && g->evenai_buf->action_status == 0x13) {
				G1_LOG(1, "evenai_v2 need to show network_err tip\n");
			} else if (gs->esb_pkt.value < 3) {
				g->evenai_buf->sub = 6;
				g->evenai_buf->action_status = gs->esb_pkt.value;
			}
		}
		break;
	}
	return 0;
}

/* IPC endpoint callback for "cpunet-esbs-ctrl" */
int ipc_ep3_recv_stub(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	return 0;
}

static void role_init(struct GlassesState *s)
{
	switch (DEVICE_ROLE) {
	case 0:
		s->is_master = 1;
		G1_LOG(0, "Master!------\n");
		break;
	case 1:
		s->is_master = 2;
		G1_LOG(0, "Slave!------\n");
		break;
	default:
		G1_LOG(0, "error --hw_id:0x%x\n", DEVICE_ROLE);
		break;
	}
	runtime_info_sync(s);

	switch (s->is_master) {
	case 1:
		s->master_fw_ver.major = 1;
		s->master_fw_ver.minor = 6;
		s->master_fw_ver.patch = 6;
		s->sync.flags |= BIT(2);
		break;
	case 2:
		s->fw_ver.major = 1;
		s->fw_ver.minor = 6;
		s->fw_ver.patch = 6;
		s->esb_pkt.flags |= BIT(2);
		break;
	}
}

static struct GlassesState *init_context(void)
{
	struct GlassesState *s, *gs;

	G1_LOG(1, "[cpuapp] global context init\n\n");

	s = malloc(sizeof(*s));
	memset(s, 0, sizeof(*s));
	memset(s->master_mac, 0xff, sizeof(s->master_mac));
	memset(s->slave_mac, 0xff, sizeof(s->slave_mac));
	GLOBAL_STATE = s;
	s->is_master = 1;

	k_sem_init(&s->ipc_sem, 0, 1);
	k_sem_init(&s->sem_1, 0, 10);
	k_sem_init(&s->sem_2, 0, 1);
	k_sem_init(&s->screen_on_sem, 0, 1);
	k_sem_init(&s->imu_sem, 0, 1);
	k_sem_init(&s->main_sem, 0, 1);
	k_sem_init(&s->dashboard_position_sem, 0, 1);
	k_sem_init(&s->sem_7, 0, 1);
	k_sem_init(&s->touch_sem, 0, 1);

	gs = GLOBAL_STATE;
	gs->work_mode = 0xff;
	gs->module_mask = 0;
	change_work_mode(0);

	s->dashboard_ts = malloc(0x75);
	if (s->dashboard_ts) {
		memset(s->dashboard_ts, 0, 0x75);
	}
	set_date(1704067200); /* 2024-01-01 00:00:00 */

	s->countdown_ts = malloc(7);
	s->task_status = malloc(5);
	if (s->task_status) {
		s->task_status->task = 0;
		s->task_status->status = 0;
	}
	s->teleprompter = malloc(0x217);
	if (s->teleprompter) {
		memset(s->teleprompter, 0, 0x217);
	}
	s->nav = malloc(0xf5);
	s->translate_src = malloc(0x1e8);
	s->translate_dst = malloc(0x1e8);
	s->dash_buf = malloc(0x1e9);
	s->evenai_buf = malloc(0x210);
	if (s->evenai_buf) {
		memset(s->evenai_buf, 0, 0x210);
	}
	s->quicknote = malloc(0x50f);
	if (s->quicknote) {
		memset(s->quicknote, 0, 0x50f);
	}
	s->quicknote_show_info = malloc(0x152);
	if (s->quicknote_show_info) {
		memset(s->quicknote_show_info, 0, 0x152);
	}
	s->esb_up_snapshot = malloc(0x201);
	if (s->esb_up_snapshot) {
		memset(s->esb_up_snapshot, 0, 0x201);
	}
	s->esb_down_snapshot = malloc(0x201);
	if (s->esb_down_snapshot) {
		memset(s->esb_down_snapshot, 0, 0x201);
	}
	s->user_sched_info = malloc(0x16a);
	if (s->user_sched_info) {
		s->user_sched_info->f_168 = 0;
		s->user_sched_info->ts = 0;
	}
	s->schedule_notif = malloc(0xaf);
	s->bitmap_info = malloc(0xb);
	if (s->bitmap_info) {
		memset(s->bitmap_info, 0, 0xb);
	}
	s->onboarding = malloc(0x21);
	init_onboarding_info();
	s->raster_height_cfg = malloc(1);
	if (s->raster_height_cfg) {
		*s->raster_height_cfg = 0;
	}
	s->horiz_pitch_cfg = malloc(2);
	if (s->horiz_pitch_cfg) {
		*(uint16_t *)s->horiz_pitch_cfg = 0; /* vendor clears both bytes at once */
	}
	s->ts_info = malloc(10);
	if (s->ts_info) {
		s->ts_info->init.word_a = 0;
		s->ts_info->init.word_b = 0;
		s->ts_info->init.half_c = 0;
	}
	s->transcribe_buf = malloc(0x208);
	if (s->transcribe_buf) {
		memset(s->transcribe_buf, 0, 0x208);
	}
	memset(&s->bonded_addr, 0xff, sizeof(s->bonded_addr));
	s->bond_flags = 0;

	register_ipc_service_context(&s->ipc_ctx);
	s->ipc_ep[0].id = 1;
	s->ipc_ep[0].name = "cpuapp-hw-id";
	s->ipc_ep[0].recv_cb = local_ipc_service_recv;
	s->ipc_ctx.register_recv_cb(&s->ipc_ep[0]);
	s->ipc_ep[1].id = 6;
	s->ipc_ep[1].name = "cpunet-esbm-cpu-sync";
	s->ipc_ep[1].recv_cb = local_esbm_ipc_service_recv;
	s->ipc_ep[2].id = 4;
	s->ipc_ep[2].name = "cpunet-esbs";
	s->ipc_ep[2].recv_cb = local_esbs_ipc_service_recv;
	s->ipc_ep[3].id = 5;
	s->ipc_ep[3].name = "cpunet-esbs-ctrl";
	s->ipc_ep[3].recv_cb = ipc_ep3_recv_stub;
	s->ipc_ctx.register_recv_cb(&s->ipc_ep[1]);
	s->ipc_ctx.register_recv_cb(&s->ipc_ep[2]);
	s->ipc_ctx.register_recv_cb(&s->ipc_ep[3]);

	s->spi.is_initialized = 0;
	s->spi.pins[0] = 4;
	s->spi.pins[1] = 8;
	s->spi.pins[2] = 9;
	s->spi.pins[3] = 10;
	s->spi.ss = 11;
	s->spi.speed_mhz = 0x20;
	spi_master_register_context(&s->spi);

	DEVICE_ROLE = button_init();
	s->ext_flash_ok = ext_flash_api_init(&s->flash_read, &s->flash_write, &s->flash_erase);
	s->work_mode = 0;
	sett_init(&s->store);
	load_settings_from_flash(s);

	role_init(s);

	k_sem_take(&s->ipc_sem, K_FOREVER);
	if (s->work_mode == 1) {
		return s;
	}

	ble_context_init(&s->ble_context);
	if (s->is_master == 1) {
		burial_point_record_info_init();
		k_timer_start(&periodic_timer, K_SECONDS(60), K_SECONDS(60));
		power_for_imu_and_mic();
		s->imu.dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
		lsm6dso_init(DEVICE_DT_GET(DT_NODELABEL(lsm6dso)));
		register_imu_funsion_context(&s->imu);
		register_opt3007_context(&s->opt3007_context);
	} else if (s->is_master == 2) {
		power_for_imu_and_mic();
		s->imu.dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
		lsm6dso_init(DEVICE_DT_GET(DT_NODELABEL(lsm6dso)));
	}
	register_jdb_panel_context(&s->panel);
	nfc_init();
	init_dashboard_info(GLOBAL_STATE->dashboard_ts);
	getDashboardStartUpModeInfofromFlash();
	getAppLanguageInfofromFlash();
	clearSettingStorageQueue();
	clearQuickNoteQueue();
	s->user_data_reset_pending = 0;
	s->panel.brightness_max = s->panel.lum_gear;
	s->mic_nocompress = 0;
	G1_LOG(1, "exit!\n");
	return s;
}

static void component_init(struct GlassesState *s)
{
	const struct device *regulators = DEVICE_DT_GET(DT_NODELABEL(pmic_regulators));
	const struct device *charger = DEVICE_DT_GET(DT_NODELABEL(pmic_charger));
	int ret;

	G1_LOG(1, "enter\n");
	get_settings_from_flash(s);
	ret = s->ble_context.init_cb(&s->ble_context);
	if (ret) {
		G1_LOG(1, "[ble_context init] fail: 0x%x\n\n", ret);
	}
	if (s->is_master == 1) {
		ret = s->imu.init_cb(&s->imu);
		if (ret) {
			G1_LOG(1, "[imu_context init] fail: 0x%x\n\n", ret);
		}
		ret = s->opt3007_context.init_cb(&s->opt3007_context);
		if (ret) {
			G1_LOG(1, "[opt3007 init] fail: 0x%x\n\n", ret);
		}
	}

	if (!device_is_ready(regulators)) {
		printk("pmic regulator not ready.\n");
		return;
	}
	printk("pmic regulator %s is ready to use.\n", regulators->name);
	if (!device_is_ready(charger)) {
		printk("Charger device not ready.\n");
		return;
	}
	if (fuel_gauge_init(charger) < 0) {
		printk("Could not initialise fuel gauge.\n");
		return;
	}
	if (npm1300_charger_init(charger) < 0) {
		printk("Could not initialise charger.\n");
		return;
	}
	printk("Initialise charger.\n");
	printk("PMIC device ok\n");
	dump_pmic_state();
	if (is_old_board()) {
		printk("Old board, need to restrain Vterm to 4.2V\n");
		change_termination_voltage();
	}
	power_for_panel();
	ret = s->spi.init_cb(&s->spi);
	if (ret) {
		G1_LOG(1, "[spi_master init] fail: 0x%x\n\n", ret);
	}
	ret = s->panel.init_cb(&s->panel);
	if (ret) {
		G1_LOG(1, "[panel_controler init] fail: 0x%x\n\n", ret);
	}
	aw93203_init();
	app_list_init();
	G1_LOG(1, "exit\n");
	s->aw_diff = 0;
	aw9320x_diff_get(&s->aw_diff);
	set_pt_level(NCS_MEM->pt_level);
}

int main(void)
{
	struct GlassesState *s;

	init_boot_seconds();
	module_set_state(MODULE_STATE_READY);
	G1_LOG(0, "Synchronization using %s driver\n", "mbox");
	k_timer_start(&rtc_sync_timer, K_MSEC(50), K_MSEC(50));
	serialization_init();
	G1_LOG(1, "[Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n", 1, 6, 6,
	       G1_GIT_COMMIT, G1_BUILD_TIME);

	s = init_context();
	component_init(s);

	init_threads(s);
	k_msleep(2000);
	enable_charger();

	for (;;) {
		k_sem_take(&s->main_sem, K_FOREVER);
		if (runtime_mode == 1) {
			switch_to_dfu_mode(s, &s->main_sem);
		}
		while (s->pending) {
			if (s->pending & BIT(0)) {
				save_usr_settings(s, 0);
				s->pending &= ~BIT(0);
			} else if (s->pending & BIT(1)) {
				s->display_mode = 11;
				s->pending &= ~BIT(1);
			} else if (s->pending & BIT(2)) {
				dmic_stream_start();
				s->pending &= ~BIT(2);
			} else if (s->pending & BIT(3)) {
				erase_dfu_flash();
				s->pending &= ~BIT(3);
			}
		}
		k_msleep(1);
	}
	return 0;
}

/* empty hooks called around external flash accesses (ext_flash_read/write/erase) */
void ext_flash_power_up(void)
{
}

void ext_flash_power_down(void)
{
}

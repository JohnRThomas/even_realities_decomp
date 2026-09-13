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

#include "g1_log.h"
#include "main.h"

/* ------------------------------------------------------------------ */
/* externals (other modules)                                           */
/* ------------------------------------------------------------------ */
extern uint8_t FUN_00033d5c(void);
extern uint8_t FUN_00081216(void);
extern int update_burial_point_day_index(void);
extern uint8_t get_wearing_state(void);
extern uint8_t is_in_box(void);
extern void FUN_00081258(int64_t ms);
extern int global_ipc_service_send(void *data, size_t len);

extern int bt_start(void);
extern int stop_ble_advertising(void);
extern int global_system_resume(struct GlassesState *gs);
extern int global_system_suspend(struct GlassesState *gs);
extern int update_imu_mode(struct imu_ctx *imu, uint8_t mode);
extern int FUN_00017af8(void);
extern int FUN_00017b04(void);
extern int FUN_00017b10(void);
extern int FUN_00017b1c(void);

extern void FUN_00035270(void);
extern void FUN_00035a84(void);
extern void FUN_00035abc(int val);
extern void FUN_0007ff66(struct GlassesState *gs, int val);
extern uint8_t FUN_000260dc(void);
extern void update_persist_task_status_to_idle(struct GlassesState *gs);
extern int SlaveDoubleClickEventInject(void);
extern void FUN_0003f1bc(int val);
extern struct esb_msg_slot *FUN_00035260(uint8_t id);
extern struct esb_msg_slot *FUN_000351d8(void);
extern void FUN_00080852(uint8_t val);
extern void FUN_00080338(int val);
extern atomic_t DAT_20008514;
extern uint8_t DAT_20019a5c;

extern void FUN_0004d528(void);
extern int serialization_init(void);
extern int set_date(uint32_t ts);
extern void FUN_0004280c(void);
extern int register_ipc_service_context(struct ipc_service_context *ctx);
extern void spi_master_register_context(struct spi_master_ctx *ctx);
extern uint8_t button_init(void);
extern uint8_t ext_flash_api_init(uint32_t *a, uint32_t *b, uint32_t *c);
extern void sett_init(struct settings_ctx *ctx);
extern void FUN_0007f6c8(struct GlassesState *gs);
extern void ble_context_init(void *ble_ctx);
extern void burial_point_record_info_init(void);
extern int lsm6dso_init(const struct device *dev);
extern int register_imu_funsion_context(struct imu_ctx *ctx);
extern void register_opt3007_context(void *ctx);
extern void register_jdb_panel_context(void *ctx);
extern int nfc_init(void);
extern void init_dashboard_info(struct dashboard_ts_context *ts);
extern uint8_t getDashboardStartUpModeInfofromFlash(void);
extern uint8_t getAppLanguageInfofromFlash(void);
extern int FUN_00025bd0(void);
extern int FUN_00026618(void);
extern int get_settings_from_flash(struct GlassesState *gs);
extern int fuel_gauge_init(const struct device *charger);
extern int npm1300_charger_init(const struct device *dev);
extern int is_old_board(void);
extern int change_termination_voltage(void);
extern void aw93203_init(void);
extern void app_list_init(void);
extern int aw9320x_diff_get(uint32_t *diff);
extern uint8_t FUN_00033770(uint8_t val);
extern void init_threads(struct GlassesState *gs);
extern int enable_charger(void);
extern int FUN_0007f556(struct GlassesState *gs, int val);
extern int dmic_stream_start(void);

extern void FUN_000800ca(struct GlassesState *gs, int val);
extern struct esb_msg_slot *FUN_0003522c(uint32_t id);
extern void confirm_message(uint32_t id);
extern int update_persist_task_status(struct GlassesState *gs, uint32_t task, uint32_t status);
extern void cal_panel_canvas_coord(int *horizontal_offset, int *vertical_offset);
extern uint8_t DAT_20019a66;

extern int panel_gpio_enable(void);
extern int panel_gpio_disable(void);

extern uint8_t notes_index;
/* ------------------------------------------------------------------ */
/* globals                                                             */
/* ------------------------------------------------------------------ */
uint8_t runtime_mode;           /* 0x2001095c, settings key "runtime_mode" */
char DAT_2001093c[32];            /* name reported by the net core */
uint8_t DAT_2001093b;
static uint8_t timer_count;     /* 0x2001093a */
static uint8_t work_mode_busy;  /* 0x20010939 */
static uint8_t esbm_last_seq;     /* 0x20010938 */
struct GlassesState *GLOBAL_STATE;
int DEVICE_ROLE;
int DAT_20006bd4;
int DAT_20006bd0;
int DAT_20006bcc;

int DAT_20006bc8;                 /* cpunet ESB package counters */
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
	WORK_MODULE_0001 = 0x001,
	WORK_MODULE_0002 = 0x002,
	WORK_MODULE_0008 = 0x008,
	WORK_MODULE_0010 = 0x010,
	WORK_MODULE_IMU = 0x020,
	WORK_MODULE_ESB = 0x040,
	WORK_MODULE_BLE = 0x080,
	WORK_MODULE_SYSTEM = 0x100,
	WORK_MODULE_0400 = 0x400,
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
	if (FUN_00033d5c() == 1) {
		return;
	}
	timer_count++;
	FUN_00081216();
	update_burial_point_day_index();
	if (get_wearing_state() == 1 && !is_in_box()) {
		FUN_00081258(60000);
	}
	if (timer_count > 9) {
		timer_count = 0;
		GLOBAL_STATE->dashboard_cmd = 0x3e;
		k_sem_give(&GLOBAL_STATE->dashboard_position_sem);
	}
}

static void switch_to_dfu_mode(struct k_sem *sem)
{
	int ret;

	runtime_mode = 1;
	if (k_is_in_isr()) {
		k_sem_give(sem);
		return;
	}
	ret = GLOBAL_STATE->settings_ctx.write_cb("runtime_mode", &runtime_mode, 1);
	if (ret != 0) {
		G1_LOG(0, "failed to switch to ble mode [%d]\n", ret);
		return;
	}
	G1_LOG(0, "sys reboot because system reset %d, %d\n", 0, runtime_mode);
	k_msleep(500);
	sys_reboot(SYS_REBOOT_COLD);
}

/* message slot handed out by the notification/message sync module */
struct esb_msg_slot {
	uint32_t id;              /* 0x00 */
	uint32_t f_04;
	uint32_t f_08;            /* 0x08 */
	uint8_t f_0c;
	uint8_t state;            /* 0x0d */
	uint8_t busy;             /* 0x0e */
	uint8_t data[0xda - 0x0f];
	uint8_t data2[0xda];      /* 0xda */
};

#define ESB_CMD_MASK  0x3f
#define ESB_DIR_MASK  0xc0
#define ESB_DIR_UP    0x80
#define ESB_DIR_DOWN  0x40

static int local_esbs_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	uint8_t buf[22] = {0};
	struct esb_sync_pkt *new_data_pkg = (struct esb_sync_pkt *)buf;
	struct esb_sync_pkt *data_pkg = &gs->sync;
	struct GlassesState *g;
	struct esb_msg_slot *slot;
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
		if (gs->f_fea == 1) {
			data_pkg->package_id++;
			G1_LOG(0, "slave recv suspend package\n");
			return 0;
		}
	} else if (cmd == 2) {
		if (gs->f_fea == 0) {
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
			    (new_data_pkg->screen_id == 0x10 && *GLOBAL_STATE->ptr_1010 >= 6 &&
			     *GLOBAL_STATE->ptr_1010 <= 9)) {
				if (gs->esb_up_id != data[3] && gs->ptr_1038[0x200] != data[3]) {
					data_pkg->package_id++;
					G1_LOG(0, "slave recv wrong up package\n");
					return 0;
				}
			} else if (gs->esb_down_id != data[4] && gs->ptr_103c[0x200] != data[4]) {
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
	if (gs->user_sched_info->f_164) {
		gs->user_sched_info->f_164 = gs->dashboard_ts->ts;
	}
	gs->esb_dir = new_data_pkg->hdr.dir;
	gs->esb_screen_id = new_data_pkg->screen_id;
	if (new_data_pkg->flags & BIT(2)) {
		FUN_00035270();
		data_pkg->flags &= ~BIT(2);
	}

	switch (new_data_pkg->hdr.cmd) {
	case 8:
		if (data_pkg->screen_id != new_data_pkg->screen_id && cmd == 8) {
			G1_LOG(0, "screen id is not same, exit\n");
			return 0;
		}
		FUN_000800ca(GLOBAL_STATE, 0);
		if (new_data_pkg->arg[0] && GLOBAL_STATE->sync.screen_id == 4) {
			FUN_00035a84();
			if (GLOBAL_STATE->sync.f_09) {
				FUN_00035abc(6);
			} else {
				FUN_00035abc(0);
			}
		}
		if (GLOBAL_STATE->imu.mode == 2) {
			FUN_000260dc();
		}
		update_persist_task_status_to_idle(GLOBAL_STATE);
		k_sem_give(&GLOBAL_STATE->sem_2);
		break;
	case 10:
		if (GLOBAL_STATE->esbm_pkt.flags & BIT(2)) {
			return 0;
		}
		slot = FUN_0003522c(UNALIGNED_GET((uint32_t *)new_data_pkg->arg));
		G1_LOG(0, "##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_FIRST slave before\n",
		       __func__, 820);
		if (slot && slot->state == 0) {
			slot->state = 2;
		}
		break;
	case 11:
		if (GLOBAL_STATE->esbm_pkt.flags & BIT(2)) {
			return 0;
		}
		id = UNALIGNED_GET((uint32_t *)new_data_pkg->arg);
		slot = FUN_0003522c(id);
		G1_LOG(0, "##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_END slave before\n",
		       __func__, 833);
		if (slot && slot->state == 2) {
			slot->state = 4;
			confirm_message(id);
			DAT_20019a66 = 0;
		}
		break;
	case 13:
		FUN_00080338(0);
		g = GLOBAL_STATE;
		*g->ptr_1010 = 2;
		if (g->glasses_state->state != 0x10) {
			update_persist_task_status(g, 0x10, 2);
		}
		break;
	case 14:
		*GLOBAL_STATE->ptr_1010 = 4;
		break;
	case 15:
		*GLOBAL_STATE->ptr_1010 = 6;
		break;
	case 16:
		g = GLOBAL_STATE;
		*g->ptr_1010 = 11;
		g->sync.f_07 = 8;
		break;
	case 17:
		*GLOBAL_STATE->ptr_1010 = 14;
		break;
	case 18:
		*GLOBAL_STATE->ptr_1010 = 16;
		break;
	case 12:
		if (new_data_pkg->arg[0] == 11) {
			dist = new_data_pkg->arg[1];
			G1_LOG(1, "slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
			       dist, new_data_pkg->arg[2]);
			if (dist < 10 && new_data_pkg->arg[2] < 9) {
				g = GLOBAL_STATE;
				g->panel_canvas_distance_gear = dist;
				g->panel_raster_height_offset = new_data_pkg->arg[2];
				cal_panel_canvas_coord(&g->panel_ec4, &g->panel_eb8);
			}
			if (GLOBAL_STATE->dashboard_ts->f_74) {
				GLOBAL_STATE->dashboard_ts->f_74 = 0;
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
				switch_to_dfu_mode(&gs->main_sem);
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
	if (GLOBAL_STATE->f_ed4 == 1) {
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
	IPC_MSG_0D = 0x0d,
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
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
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
		if (!gs->bt_ready) {
			gs->bt_ready = 1;
		}
		G1_LOG(1, "bt_ready\n");
		if (k_sem_count_get(&gs->ipc_sem) == 0) {
			k_sem_give(&gs->ipc_sem);
		}
		memcpy(DAT_2001093c, &data[1], len - 1);
		DAT_2001093c[sizeof(DAT_2001093c) - 1] = 0;
		break;
	case IPC_RESP_CPUNET_ESB_PACKAGES:
		memcpy(&DAT_20006bd4, &data[1], 4);
		memcpy(&DAT_20006bd0, &data[5], 4);
		memcpy(&DAT_20006bcc, &data[9], 4);
		memcpy(&DAT_20006bc8, &data[13], 4);
		if (!gs->f_10d4) {
			DAT_20006bc8 = 70;
		}
		G1_LOG(1, "IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n",
		       DAT_20006bd4, DAT_20006bd0, DAT_20006bcc, DAT_20006bc8);
		break;
	case IPC_MSG_SET_MACADDR:
		memcpy(gs->master_mac, &data[1], sizeof(gs->master_mac));
		memcpy(gs->slave_mac, &data[7], sizeof(gs->slave_mac));
		break;
	case IPC_MSG_0D:
		gs->f_106e = data[1];
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

void FUN_00016614(uint32_t ts)
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

void FUN_00016638(uint8_t val)
{
	NCS_MEM->f_70 = val;
}

void set_ncs_mem_initialized(void)
{
	NCS_MEM->magic = NCS_MEM_MAGIC;
}

int is_ncs_mem_initialized(void)
{
	return NCS_MEM->magic == NCS_MEM_MAGIC ? 0 : -1;
}

void FUN_0001666c(void)
{
	struct dashboard_ts_context *ts = GLOBAL_STATE->dashboard_ts;

	NCS_MEM->ts = ts->ts;
	NCS_MEM->f_04 = ts->f_04;
	NCS_MEM->f_05 = ts->f_05;
	NCS_MEM->f_08 = ts->f_06;
	NCS_MEM->f_5f = ts->f_5d;
	NCS_MEM->f_60 = ts->time_disp_mode;
	NCS_MEM->f_62 = ts->f_62;
	NCS_MEM->f_61 = ts->f_61;
	memcpy(NCS_MEM->f_10, ts->f_0e, sizeof(NCS_MEM->f_10));
	memcpy(NCS_MEM->f_35, ts->f_33, sizeof(NCS_MEM->f_35));
}

void FUN_000166f8(void)
{
	struct GlassesState *gs = GLOBAL_STATE;

	gs->dashboard_ts->ts = NCS_MEM->ts + 1;
	gs->dashboard_ts->f_04 = NCS_MEM->f_04;
	gs->dashboard_ts->f_05 = NCS_MEM->f_05;
	gs->dashboard_ts->f_06 = NCS_MEM->f_08;
	gs->dashboard_ts->f_5d = NCS_MEM->f_5f;
	gs->dashboard_ts->time_disp_mode = NCS_MEM->f_60;
	gs->dashboard_ts->f_62 = NCS_MEM->f_62;
	gs->dashboard_ts->f_61 = NCS_MEM->f_61;
	gs->dashboard_ts->f_64 = NCS_MEM->f_68;
	if (NCS_MEM->notes_index < 4) {
		notes_index = NCS_MEM->notes_index;
	}
	memcpy(gs->dashboard_ts->f_0e, NCS_MEM->f_10, sizeof(NCS_MEM->f_10));
	memcpy(gs->dashboard_ts->f_33, NCS_MEM->f_35, sizeof(NCS_MEM->f_35));
}

void FUN_000167cc(uint8_t idx)
{
	NCS_MEM->notes_index = idx;
}

void deinit_ncs_memory(void)
{
	NCS_MEM->f_08 = 0;
	NCS_MEM->ts = 0;
	NCS_MEM->f_04 = 0;
	NCS_MEM->f_05 = 0;
	NCS_MEM->f_5f = 0;
	NCS_MEM->f_60 = 0;
	NCS_MEM->f_61 = 0;
	NCS_MEM->f_62 = 0;
	NCS_MEM->f_68 = 0;
	memset(NCS_MEM->f_10, 0, sizeof(NCS_MEM->f_10));
	memset(NCS_MEM->f_35, 0, sizeof(NCS_MEM->f_10));
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
	case WORK_MODULE_0001:
		if (enable) {
			FUN_00017b10();
		} else {
			FUN_00017b1c();
		}
		break;
	case WORK_MODULE_0400:
		if (enable) {
			FUN_00017b04();
		} else {
			FUN_00017af8();
		}
		break;
	case WORK_MODULE_SYSTEM:
		if (FUN_00033d5c() == 0) {
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

uint8_t FUN_000169b4(void)
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
	if (GLOBAL_STATE->work_mode == mode && GLOBAL_STATE->f_fea != 5) {
		goto out;
	}
	GLOBAL_STATE->work_mode = mode;
	G1_LOG(0, "change_work_mode to %d\n", (uint8_t)mode);

	switch (GLOBAL_STATE->work_mode) {
	case 0:
		update_work_module(1, WORK_MODULE_0010);
		update_work_module(1, WORK_MODULE_SYSTEM);
		update_work_module(1, WORK_MODULE_IMU);
		update_work_module(1, WORK_MODULE_BLE);
		update_work_module(1, WORK_MODULE_ESB);
		update_work_module(1, WORK_MODULE_0008);
		update_work_module(1, WORK_MODULE_0002);
		update_work_module(1, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		break;
	case 1:
		update_work_module(1, WORK_MODULE_0010);
		update_work_module(0, WORK_MODULE_SYSTEM);
		update_work_module(0, WORK_MODULE_IMU);
		update_work_module(1, WORK_MODULE_BLE);
		update_work_module(0, WORK_MODULE_ESB);
		update_work_module(0, WORK_MODULE_0008);
		update_work_module(0, WORK_MODULE_0002);
		update_work_module(0, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		{
			uint8_t msg[64] = {0};

			msg[0] = 1;
			msg[1] = 8;
			global_ipc_service_send(msg, 4);
		}
		break;
	case 2:
		update_work_module(1, WORK_MODULE_0010);
		update_work_module(1, WORK_MODULE_SYSTEM);
		update_work_module(2, WORK_MODULE_IMU);
		update_work_module(1, WORK_MODULE_BLE);
		update_work_module(1, WORK_MODULE_ESB);
		update_work_module(0, WORK_MODULE_0008);
		update_work_module(1, WORK_MODULE_0002);
		update_work_module(1, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		memset(GLOBAL_STATE->buf_0ef, 0, sizeof(GLOBAL_STATE->buf_0ef));
		break;
	case 3:
		update_work_module(0, WORK_MODULE_SYSTEM);
		update_work_module(0, WORK_MODULE_0010);
		update_work_module(1, WORK_MODULE_IMU);
		update_work_module(1, WORK_MODULE_BLE);
		update_work_module(1, WORK_MODULE_ESB);
		update_work_module(0, WORK_MODULE_0008);
		update_work_module(1, WORK_MODULE_0002);
		update_work_module(1, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		break;
	case 4:
	case 5:
	case 6:
		update_work_module(0, WORK_MODULE_0010);
		update_work_module(0, WORK_MODULE_SYSTEM);
		update_work_module(0, WORK_MODULE_IMU);
		update_work_module(1, WORK_MODULE_BLE);
		update_work_module(1, WORK_MODULE_ESB);
		update_work_module(0, WORK_MODULE_0008);
		update_work_module(0, WORK_MODULE_0002);
		update_work_module(0, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		break;
	case 8:
		update_work_module(0, WORK_MODULE_SYSTEM);
		update_work_module(0, WORK_MODULE_0010);
		update_work_module(0, WORK_MODULE_IMU);
		update_work_module(0, WORK_MODULE_BLE);
		update_work_module(0, WORK_MODULE_ESB);
		update_work_module(0, WORK_MODULE_0008);
		update_work_module(0, WORK_MODULE_0002);
		update_work_module(0, WORK_MODULE_0001);
		update_work_module(0, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		break;
	case 9:
		update_work_module(0, WORK_MODULE_SYSTEM);
		update_work_module(1, WORK_MODULE_0010);
		update_work_module(1, WORK_MODULE_IMU);
		update_work_module(0, WORK_MODULE_BLE);
		update_work_module(0, WORK_MODULE_ESB);
		update_work_module(1, WORK_MODULE_0008);
		update_work_module(1, WORK_MODULE_0002);
		update_work_module(1, WORK_MODULE_0001);
		update_work_module(1, WORK_MODULE_0400);
		update_work_module(1, WORK_MODULE_SHIPMODE);
		break;
	case 7:
		set_shipmode(1);
		break;
	default:
		break;
	}
out:
	work_mode_busy = 0;
	return 0;
}

static int local_esbm_ipc_service_recv(struct GlassesState *gs, const uint8_t *data, size_t len)
{
	const struct esb_msg_slot *src;
	struct esb_msg_slot *slot;
	uint8_t cmd = data[0] & 0x3f;

	if (cmd != 0 && (uint8_t)(cmd - 12) > 1) {
		if (esbm_last_seq == data[0x15]) {
			return 0;
		}
		esbm_last_seq = data[0x15];
		gs->f_fd3 = gs->esbm_pkt.f_01[0];
		gs->f_fd4 = gs->esbm_pkt.f_01[1];
		gs->f_fd5 = gs->esbm_pkt.f_01[2];
		gs->f_fc5 = gs->esbm_pkt.f_01[3];
		memcpy(gs->slave_mac, gs->esbm_pkt.mac, sizeof(gs->slave_mac));
		memcpy((void *)&gs->esbm_pkt, data, sizeof(gs->esbm_pkt));
		if (data[0x12] & BIT(2)) {
			FUN_00035270();
			gs->esbm_pkt.flags &= ~BIT(2);
		}
	}

	switch (((const struct esb_hdr *)data)->cmd) {
	case 4:
		if (GLOBAL_STATE->sync.screen_id == 4) {
			FUN_00035a84();
			if (GLOBAL_STATE->sync.f_09) {
				FUN_00035abc(6);
			} else {
				FUN_00035abc(0);
			}
		}
		atomic_or(&DAT_20008514, BIT(1));
		FUN_0007ff66(gs, 1);
		if (gs->imu.mode == 2) {
			FUN_000260dc();
		}
		update_persist_task_status_to_idle(gs);
		break;
	case 5:
		FUN_0007ff66(gs, 1);
		change_work_mode(7);
		break;
	case 8:
		FUN_0007ff66(gs, 1);
		gs->display_mode = 12;
		gs->dashboard_cmd = 3;
		k_sem_give(&gs->dashboard_position_sem);
		break;
	case 9:
		gs->display_mode = 10;
		gs->dashboard_cmd = 3;
		k_sem_give(&gs->dashboard_position_sem);
		FUN_0003f1bc(1);
		break;
	case 6:
		if (gs->esbm_pkt.subcmd == 1) {
			*gs->ptr_1034 = 1;
		} else if (gs->esbm_pkt.subcmd == 0) {
			*gs->ptr_1034 = 2;
		}
		break;
	case 7:
		SlaveDoubleClickEventInject();
		break;
	case 10:
		DAT_2001093b = 1;
		break;
	case 11:
		break;
	case 12:
		if ((GLOBAL_STATE->sync.flags & BIT(2)) || DAT_20019a5c) {
			break;
		}
		src = (const struct esb_msg_slot *)&data[1];
		slot = FUN_00035260(data[0xd]);
		if (slot && !slot->busy &&
		    (src->f_08 != slot->f_08 || src->id != slot->id || slot->state != 1)) {
			memcpy(slot, &data[1], 0xda);
			slot->state = 1;
		}
		break;
	case 13:
		if ((GLOBAL_STATE->sync.flags & BIT(2)) || DAT_20019a5c) {
			break;
		}
		slot = FUN_000351d8();
		if (slot && !slot->busy && slot->state != 3) {
			memcpy(slot->data2, &data[1], 0xda);
			slot->state = 3;
		}
		break;
	case 14:
		if (gs->esbm_pkt.subcmd == 4) {
			GLOBAL_STATE->ptr_101c[2] = gs->esbm_pkt.value;
		} else if (gs->esbm_pkt.subcmd == 5) {
			FUN_00080852(gs->esbm_pkt.value);
		}
		break;
	case 15:
		if (*GLOBAL_STATE->ptr_1010 == 1) {
			break;
		}
		FUN_00080338(0);
		*GLOBAL_STATE->ptr_1010 = 1;
		break;
	case 16:
		if (*GLOBAL_STATE->ptr_1010 == 4) {
			*GLOBAL_STATE->ptr_1010 = 5;
		}
		break;
	case 17:
		if (gs->esbm_pkt.subcmd == 6) {
			struct GlassesState *g = GLOBAL_STATE;

			if (g->glasses_state->state == 0x14 && g->ptr_1014[0] == 1 &&
			    g->ptr_1014[1] == 4 && g->ptr_1014[3] == 0x13) {
				G1_LOG(1, "evenai_v2 need to show network_err tip\n");
			} else if (gs->esbm_pkt.value < 3) {
				g->ptr_1014[1] = 6;
				g->ptr_1014[3] = gs->esbm_pkt.value;
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
		s->f_fd0 = 1;
		s->f_fd1 = 6;
		s->f_fd2 = 3;
		s->sync.flags |= BIT(2);
		break;
	case 2:
		s->f_fd3 = 1;
		s->f_fd4 = 6;
		s->f_fd5 = 3;
		s->esbm_pkt.flags |= BIT(2);
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
	k_sem_init(&s->sem_3, 0, 1);
	k_sem_init(&s->sem_5, 0, 1);
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
	s->glasses_state = malloc(5);
	if (s->glasses_state) {
		s->glasses_state->state = 0;
		s->glasses_state->f_4 = 0;
	}
	s->ptr_1000 = malloc(0x217);
	if (s->ptr_1000) {
		memset(s->ptr_1000, 0, 0x217);
	}
	s->ptr_1004 = malloc(0xf5);
	s->ptr_1008 = malloc(0x1e8);
	s->ptr_100c = malloc(0x1e8);
	s->ptr_1010 = malloc(0x1e9);
	s->ptr_1014 = malloc(0x210);
	if (s->ptr_1014) {
		memset(s->ptr_1014, 0, 0x210);
	}
	s->ptr_1030 = malloc(0x50f);
	if (s->ptr_1030) {
		memset(s->ptr_1030, 0, 0x50f);
	}
	s->ptr_1034 = malloc(0x152);
	if (s->ptr_1034) {
		memset(s->ptr_1034, 0, 0x152);
	}
	s->ptr_1038 = malloc(0x201);
	if (s->ptr_1038) {
		memset(s->ptr_1038, 0, 0x201);
	}
	s->ptr_103c = malloc(0x201);
	if (s->ptr_103c) {
		memset(s->ptr_103c, 0, 0x201);
	}
	s->user_sched_info = malloc(0x16a);
	if (s->user_sched_info) {
		s->user_sched_info->f_168 = 0;
		s->user_sched_info->f_164 = 0;
	}
	s->ptr_ffc = malloc(0xaf);
	s->ptr_1018 = malloc(0xb);
	if (s->ptr_1018) {
		memset(s->ptr_1018, 0, 0xb);
	}
	s->ptr_101c = malloc(0x21);
	FUN_0004280c();
	s->ptr_1020 = malloc(1);
	if (s->ptr_1020) {
		*s->ptr_1020 = 0;
	}
	s->ptr_1024 = malloc(2);
	if (s->ptr_1024) {
		*s->ptr_1024 = 0;
	}
	s->ptr_1028 = malloc(10);
	if (s->ptr_1028) {
		s->ptr_1028->f_0 = 0;
		s->ptr_1028->f_4 = 0;
		s->ptr_1028->f_8 = 0;
	}
	s->multi_packet_data_buffer = malloc(0x208);
	if (s->multi_packet_data_buffer) {
		memset(s->multi_packet_data_buffer, 0, 0x208);
	}
	memset(s->role_buf, 0xff, sizeof(s->role_buf));
	s->f_1088 = 0;

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
	s->spi.f_1c = 11;
	s->spi.f_1d = 0x20;
	spi_master_register_context(&s->spi);

	DEVICE_ROLE = button_init();
	s->ext_flash_ok = ext_flash_api_init(&s->ext_flash_1044, &s->ext_flash_1048, &s->ext_flash_104c);
	s->work_mode = 0;
	sett_init(&s->settings_ctx);
	FUN_0007f6c8(s);

	role_init(s);

	k_sem_take(&s->ipc_sem, K_FOREVER);
	if (s->work_mode == 1) {
		return s;
	}

	ble_context_init(&s->ble_init);
	if (s->is_master == 1) {
		burial_point_record_info_init();
		k_timer_start(&periodic_timer, K_SECONDS(60), K_SECONDS(60));
		power_for_imu_and_mic();
		s->imu.dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
		lsm6dso_init(DEVICE_DT_GET(DT_NODELABEL(lsm6dso)));
		register_imu_funsion_context(&s->imu);
		register_opt3007_context(&s->opt3007_init);
	} else if (s->is_master == 2) {
		power_for_imu_and_mic();
		s->imu.dev = DEVICE_DT_GET(DT_NODELABEL(lsm6dso));
		lsm6dso_init(DEVICE_DT_GET(DT_NODELABEL(lsm6dso)));
	}
	register_jdb_panel_context(&s->panel_init);
	nfc_init();
	init_dashboard_info(GLOBAL_STATE->dashboard_ts);
	getDashboardStartUpModeInfofromFlash();
	getAppLanguageInfofromFlash();
	FUN_00025bd0();
	FUN_00026618();
	s->f_10d5 = 0;
	s->panel_cur = s->panel_ede;
	s->f_10a4 = 0;
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
	ret = s->ble_init(&s->ble_init);
	if (ret) {
		G1_LOG(1, "[ble_context init] fail: 0x%x\n\n", ret);
	}
	if (s->is_master == 1) {
		ret = s->imu.init_cb(&s->imu);
		if (ret) {
			G1_LOG(1, "[imu_context init] fail: 0x%x\n\n", ret);
		}
		ret = s->opt3007_init(&s->opt3007_init);
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
	ret = s->panel_init(&s->panel_init);
	if (ret) {
		G1_LOG(1, "[panel_controler init] fail: 0x%x\n\n", ret);
	}
	aw93203_init();
	app_list_init();
	G1_LOG(1, "exit\n");
	s->aw_diff = 0;
	aw9320x_diff_get(&s->aw_diff);
	FUN_00033770(NCS_MEM->f_70);
}

int main(void)
{
	struct GlassesState *s;

	FUN_0004d528();
	module_set_state(MODULE_STATE_READY);
	G1_LOG(0, "Synchronization using %s driver\n", "mbox");
	k_timer_start(&rtc_sync_timer, K_MSEC(50), K_MSEC(50));
	serialization_init();
	G1_LOG(1, "[Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n", 1, 6, 3,
	       "fcebbab6", "2025-06-28 17:28:42");

	s = init_context();
	component_init(s);

	init_threads(s);
	k_msleep(2000);
	enable_charger();

	for (;;) {
		k_sem_take(&s->main_sem, K_FOREVER);
		if (runtime_mode == 1) {
			switch_to_dfu_mode(&s->main_sem);
		}
		while (s->pending) {
			if (s->pending & BIT(0)) {
				FUN_0007f556(s, 0);
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
void FUN_0007f328(void)
{
}

void FUN_0007f32a(void)
{
}

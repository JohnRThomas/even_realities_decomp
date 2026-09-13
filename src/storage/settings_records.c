/*
 * Settings records on the external mx25r64 QSPI flash: sys settings,
 * user settings, burial point, serial number.  The raw read / write-and-verify
 * helpers are in flash_settings.c.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/random/rand32.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "g1_log.h"
#include "storage.h"
#include "../dashboard/dashboard.h"
#include "../main.h"
#include "../notify/notify.h"
#include "../production_test/production_test.h"
#include "../sensors_audio/sensors_audio.h"
#include "../threads/threads.h"

char SERIAL_NUMBER[32] = "S100demodevice";
char glasses_name[32] = "S100demoglasses";

int save_sys_settings(struct GlassesState *gs, int force)
{
	struct sys_settings s = {0};

	s.valid = 1;
	s.aging_discharge_time_s = gs->aging_discharge_time_s;
	s.esb_channel = gs->esb_channel;
	s.imu_base = gs->imu.ref;
	s.lux_base_max = gs->opt3007_context.lux_base_max;
	s.panel_voltage = gs->panel.voltage;
	memcpy(s.sn, SERIAL_NUMBER, 16);
	memcpy(s.name, glasses_name, 16);
	s.esb_master_addr = gs->esb_master_addr;
	s.esb_slave_addr = gs->esb_slave_addr;
	s.aging_test_count = gs->aging_test_count;
	s.aging_start_soc = gs->aging_start_soc;
	s.aging_charge_time_s = gs->aging_charge_time_s;
	s.canvas_x = gs->canvas_x;
	s.canvas_y = gs->canvas_y;
	s.lux_base[1] = gs->lux_base_low;
	s.lux_base[0] = gs->lux_base_mid;
	s.lux_base[2] = gs->lux_base_high;
	s.lux_base_spare = gs->lux_base_spare;
	s.luminance_curve = gs->luminance_curve;
	s.luminance_curve_a1 = gs->luminance_curve_a1;
	s.lum_base[0] = gs->panel.lum_base_0;
	s.lum_base[1] = gs->panel.lum_base_1;
	s.lum_base[2] = gs->panel.lum_gear;
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move */
	for (size_t k = 0; k < sizeof(s.aging_discharge_step_s); k++) {
		((uint8_t *)&s.aging_discharge_step_s)[k] = ((uint8_t *)&gs->aging_discharge_step_raw)[k];
	}
	s.aging_elapsed_s = gs->aging_elapsed_s;
	s.aging_touch_count = gs->aging_touch_count;
	s.aging_charge_check_result = gs->aging_charge_check_result;
	flash_settings_write_and_verify(SYS_SETTINGS_ADDR, &s, sizeof(s));
	return 0;
}

int load_sys_setting(struct GlassesState *gs)
{
	struct sys_settings s;

	memset(&s, 0, sizeof(s));
	if (flash_settings_read(SYS_SETTINGS_ADDR, &s, sizeof(s))) {
		G1_LOG_WRN("sys_flash_settings_read error!\n");
		return -1;
	}
	G1_LOG_WRN("read sys settings success!\n");
	gs->aging_discharge_time_s = s.aging_discharge_time_s;
	gs->first_enter_flag = s.valid;
	gs->esb_channel = s.esb_channel;
	gs->imu.ref = s.imu_base;
	gs->opt3007_context.lux_base_max = s.lux_base_max;
	gs->panel.voltage = s.panel_voltage;
	if (s.sn[0] != 0xff) {
		memcpy(SERIAL_NUMBER, s.sn, 16);
	}
	if (s.name[0] != 0xff) {
		memcpy(glasses_name, s.name, 16);
	}
	gs->esb_master_addr = s.esb_master_addr;
	gs->esb_slave_addr = s.esb_slave_addr;
	gs->aging_test_count = s.aging_test_count;
	gs->aging_start_soc = s.aging_start_soc;
	gs->aging_charge_time_s = s.aging_charge_time_s;
	gs->canvas_x = s.canvas_x;
	gs->canvas_y = s.canvas_y;
	gs->lux_base_low = s.lux_base[1];
	gs->lux_base_mid = s.lux_base[0];
	gs->lux_base_high = s.lux_base[2];
	gs->lux_base_spare = s.lux_base_spare;
	gs->luminance_curve = s.luminance_curve;
	gs->luminance_curve_a1 = s.luminance_curve_a1;
	gs->panel.lum_base_0 = s.lum_base[0];
	gs->panel.lum_base_1 = s.lum_base[1];
	gs->panel.lum_gear = s.lum_base[2];
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move.  The
	 * destination is indexed from the start of *gs (not &gs->aging_discharge_step_raw), which keeps
	 * the first-boot memset below from sharing its address computation
	 * (see ai_helpers/agent_notes/load_sys_setting.md) */
	for (size_t k = 0; k < sizeof(s.aging_discharge_step_s); k++) {
		((uint8_t *)gs)[offsetof(struct GlassesState, aging_discharge_step_raw) + k] = ((uint8_t *)&s.aging_discharge_step_s)[k];
	}
	gs->aging_elapsed_s = s.aging_elapsed_s;
	gs->aging_touch_count = s.aging_touch_count;
	gs->aging_charge_check_result = s.aging_charge_check_result;
	if (s.valid != 1) {
		G1_LOG_WRN("FIRST BOOT, full default sys value!\n");
		gs->esb_channel = 0xff;
		gs->aging_discharge_time_s = 0;
		gs->opt3007_context.lux_base_max = 80000;
		gs->imu.ref = 0;
		gs->panel.voltage = 0;
		gs->canvas_x = 0x20;
		gs->canvas_y = 0x20;
		gs->aging_test_count = 0;
		gs->aging_start_soc = 0;
		gs->aging_charge_time_s = 0;
		gs->luminance_curve = 128000;
		gs->panel.lum_base_0 = 0x3f;
		gs->panel.lum_base_1 = 0x3f;
		gs->panel.lum_gear = 0x3f;
		gs->lux_base_low = 0;
		gs->lux_base_mid = 0;
		gs->lux_base_high = 0;
		gs->lux_base_spare = 0;
		gs->luminance_curve_a1 = 0;
		memset(&gs->aging_discharge_step_raw, 0, sizeof(gs->aging_discharge_step_raw));
		gs->aging_elapsed_s = 0;
		gs->aging_touch_count = 0;
		gs->aging_charge_check_result = 0;
		save_sys_settings(gs, 0);
	}
	gs->first_enter_flag = 1;
	if (gs->panel.voltage != 1) {
		gs->panel.voltage = 0;
	}
	if ((uint32_t)gs->luminance_curve + 1 <= 1) {
		gs->luminance_curve = 128000;
	}
	if (gs->canvas_x < 22 || gs->canvas_x > 42) {
		gs->canvas_x = 0x20;
	}
	if (gs->canvas_y > 64) {
		gs->canvas_y = 0x20;
	} else if (gs->canvas_y < 4) {
		gs->canvas_y = 4;
	}
	if (gs->panel.lum_gear == 0 || gs->panel.lum_gear > 63) {
		gs->panel.lum_gear = 0x3f;
	}
	if (gs->aging_touch_count == 0xff) {
		gs->aging_touch_count = 0;
	}
	return 0;
}

int save_usr_settings(struct GlassesState *gs, int unused)
{
	struct usr_settings s = {0};

	s.display_mode = gs->display_mode;
	s.wakeup_angle = gs->imu.level;
	s.brightness_level = gs->panel.panel_brightness_level;
	s.dof3_enable = gs->imu.dof3_enable;
	s.imu_div = gs->imu.div;
	s.auto_brightness = gs->opt3007_context.auto_brightness;
	s.bonded = gs->bonded;
	s.check_mode = gs->check_mode;
	s.raster_height_gear = gs->panel.raster_height_offset;
	s.bonded_addr = gs->bonded_addr_raw;
	s.imu_wear = gs->imu.wear;
	s.message_mode = gs->message_mode;
	s.charge_limit_upper = gs->charge_limit_upper;
	s.charge_limit_lower = gs->charge_limit_lower;
	s.test_mode = get_pt_test_mode();
	s.canvas_distance_gear = gs->panel.canvas_distance_gear;
	s.user_horiz_pitch = gs->imu.base;
	s.message_stay_time = gs->message_stay_time;
	s.double_tap_customize = gs->double_tap_customize;
	s.date_format = gs->dashboard_ts->date_format;
	s.brightness_percent = gs->panel.brightness_percent;
	s.longpress_head_up_mic = gs->f_1246_pair;
	flash_settings_write_and_verify(USR_SETTINGS_ADDR, &s, sizeof(s));
	return 0;
}

int clear_user_settings(struct GlassesState *gs)
{
	gs->display_mode = 10;
	gs->panel.panel_brightness_level = 0x15;
	gs->imu.dof3_enable = 1;
	gs->imu.div = 400;
	gs->opt3007_context.auto_brightness = 1;
	gs->check_mode = 1;
	gs->bonded = 0;
	gs->panel.raster_height_offset = 3;
	memset(&gs->bonded_addr_raw, 0xff, sizeof(gs->bonded_addr_raw));
	gs->imu.level = 0x14;
	gs->imu.wear = 1;
	gs->message_mode = 0;
	gs->charge_limit_upper = 0;
	gs->charge_limit_lower = 0;
	set_test_mode(0);
	gs->panel.canvas_distance_gear = 3;
	gs->imu.base = 0;
	gs->message_stay_time = 15;
	gs->double_tap_customize = 0;
	gs->dashboard_ts->date_format = 0;
	gs->panel.brightness_percent = 100;
	gs->f_1246_pair.a = 0;
	gs->f_1246_pair.b = 0;
	save_usr_settings(gs, 0);
	return 0;
}

int load_usr_setting(struct GlassesState *gs)
{
	struct usr_settings s;
	uint8_t test_mode;

	memset(&s, 0, sizeof(s));
	if (flash_settings_read(USR_SETTINGS_ADDR, &s, sizeof(s))) {
		G1_LOG_WRN("usr_flash_settings_read error!\n");
		return -1;
	}
	G1_LOG_WRN("read user settings success!\n");
	gs->display_mode = s.display_mode;
	gs->panel.panel_brightness_level = s.brightness_level;
	gs->imu.level = s.wakeup_angle;
	gs->imu.dof3_enable = s.dof3_enable;
	gs->imu.div = s.imu_div ? s.imu_div : 400;
	gs->opt3007_context.auto_brightness = s.auto_brightness;
	gs->bonded = s.bonded;
	gs->check_mode = s.check_mode;
	gs->panel.raster_height_offset = s.raster_height_gear;
	gs->bonded_addr_raw = s.bonded_addr;
	gs->imu.wear = s.imu_wear;
	gs->message_mode = s.message_mode > 1 ? 0 : s.message_mode;
	gs->message_stay_time = (s.message_stay_time == 0 || s.message_stay_time == 0xff) ? 15 : s.message_stay_time;
	gs->charge_limit_upper = s.charge_limit_upper;
	gs->charge_limit_lower = s.charge_limit_lower;
	test_mode = s.test_mode;
	gs->panel.canvas_distance_gear = s.canvas_distance_gear;
	gs->imu.base = s.user_horiz_pitch;
	gs->double_tap_customize = s.double_tap_customize;
	gs->dashboard_ts->date_format = s.date_format;
	gs->panel.brightness_percent = s.brightness_percent;
	gs->f_1246_pair = s.longpress_head_up_mic;
	if (gs->display_mode == 0xff && gs->imu.dof3_enable == 0xff) {
		clear_user_settings(gs);
	}
	if (gs->panel.raster_height_offset > 8) {
		gs->panel.raster_height_offset = 3;
	}
	if (gs->panel.canvas_distance_gear == 0 || gs->panel.canvas_distance_gear > 9) {
		gs->panel.canvas_distance_gear = 3;
	}
	if (gs->display_mode == 11) {
		gs->display_mode = 10;
		save_usr_settings(gs, 0);
	}
	if (test_mode > 1) {
		test_mode = 0;
	}
	set_test_mode(test_mode);
	if (get_pt_test_mode() == 1) {
		gs->opt3007_context.auto_brightness = 0;
		gs->display_mode = 11;
		gs->panel.panel_brightness_level = 0x15;
		gs->panel.raster_height_offset = 3;
		gs->panel.canvas_distance_gear = 3;
	} else {
		gs->display_mode = 10;
	}
	if (gs->imu.base == 0xffffffff) {
		gs->imu.base = 0;
	}
	if (gs->double_tap_customize > 5) {
		gs->double_tap_customize = 0;
	}
	if (gs->dashboard_ts->date_format > 2) {
		gs->dashboard_ts->date_format = 0;
	}
	if (gs->panel.brightness_percent < 70 || gs->panel.brightness_percent > 100) {
		gs->panel.brightness_percent = 100;
	}
	if (gs->f_1246_pair.a > 1) {
		gs->f_1246_pair.a = 0;
	}
	if (gs->f_1246_pair.b > 1) {
		gs->f_1246_pair.b = 0;
	}
	return 0;
}

int update_burial_point_to_flash(struct GlassesState *gs)
{
	struct bp_context bp;
	int ret;

	memset(&bp, 0, sizeof(bp));
	G1_LOG_WRN("update_burial_point_to_flash!!!\n");
	if (flash_settings_read(BURIAL_POINT_ADDR, &bp, sizeof(bp))) {
		G1_LOG_WRN("burial_point read error!\n");
		return -1;
	}
	ret = memcmp(&bp, &gs->bp, sizeof(bp));
	if (ret == 0) {
		return ret;
	}
	ret = flash_settings_write_and_verify(BURIAL_POINT_ADDR, &gs->bp,
					      sizeof(gs->bp));
	if (ret) {
		G1_LOG_WRN("burial_point flash_settings_write_and_verify error!\n");
		return -1;
	}
	/*
	 * No return statement here in the vendor code (found by the permuter): the
	 * shipped function returns r0, i.e. the 0 from flash_settings_write_and_verify.
	 */
}

int clear_hardware_settings(struct GlassesState *gs)
{
	memset(&gs->bp, 0xff, sizeof(gs->bp));
	flash_settings_write_and_verify(BURIAL_POINT_ADDR, &gs->bp,
					sizeof(gs->bp));
	return 0;
}

int load_burial_point(struct GlassesState *gs)
{
	struct bp_context *bp = &gs->bp;
	uint32_t id;
	int ret;

	ret = flash_settings_read(BURIAL_POINT_ADDR, bp, sizeof(*bp));
	if (ret) {
		G1_LOG_WRN("burial_point read error!\n");
		return -1;
	}
	if ((bp->version == 0xff && bp->day_index == 0xff) || !bp->valid) {
		id = sys_rand32_get();
		memset(bp, 0, sizeof(*bp));
		bp->version = 7;
		bp->id = id;
		bp->valid = 1;
	}
	return ret;
}

void reset_all_usr_data(struct GlassesState *gs, int reboot)
{
	int i;

	cleanNotesIndex();
	cleanStocksIndex();
	cleanNewsIndex();
	cleanCalenadrIndex();
	if (gs->is_master == 1) {
		delAudioStreamRecord(0xff);
		k_msleep(1000);
	}
	for (i = 0; i < 4; i++) {
		deleteQuickNoteData(i);
		k_msleep(200);
	}
	cleanAppLanguageInfo();
	k_msleep(200);
	cleanDashBoardStartUpModeInfo();
	k_msleep(200);
	clear_user_settings(gs);
	clear_hardware_settings(gs);
	k_msleep(500);
	deinit_ncs_memory();
	k_msleep(500);
	bt_unpair(BT_ID_DEFAULT, NULL);
	if (reboot) {
		G1_LOG_ERR("sys reboot because enter ship mode failed\n");
		system_reboot_delayed();
		return;
	}
	k_msleep(1000);
	set_shipmode(1);
	k_msleep(1000);
}

int get_settings_from_flash(struct GlassesState *gs)
{
	gs->store.write("dashboard_ts", gs->dashboard_ts, 0x75);
	gs->store.write("countdown_ts", gs->countdown_ts, 7);
	gs->store.write("brightness_level", &gs->panel.panel_brightness_level, 1);
	gs->store.write("3dof_enable", &gs->imu.dof3_enable, 1);
	gs->store.write("display_mode", &gs->display_mode, 1);
	gs->store.write("wakeup_angle", &gs->imu.level, 1);
	gs->store.write("first_enter_flag", &gs->first_enter_flag, 4);
	return 0;
}

char *get_serial_number(void)
{
	return SERIAL_NUMBER;
}

char *get_glasses_name(void)
{
	return glasses_name;
}

int save_serial_number(const char *sn)
{
	snprintf(SERIAL_NUMBER, 16, "%s", sn);
	return 0;
}

int dump_serial_number(const char *name)
{
	snprintf(glasses_name, 16, "%s", name);
	return 0;
}

int read_sys_settting_from_flash(struct sys_settings *out)
{
	struct sys_settings s;

	memset(&s, 0, sizeof(s));
	if (flash_settings_read(SYS_SETTINGS_ADDR, &s, sizeof(s))) {
		G1_LOG_WRN("sys_flash_settings_read error!\n");
		return -1;
	}
	G1_LOG_WRN("read sys settings success!\n");
	out->valid = s.valid;
	out->aging_discharge_time_s = s.aging_discharge_time_s;
	out->esb_channel = s.esb_channel;
	out->imu_base = s.imu_base;
	out->lux_base_max = s.lux_base_max;
	out->panel_voltage = s.panel_voltage;
	if (s.sn[0] != 0xff) {
		memcpy(out->sn, s.sn, 16);
	}
	if (s.name[0] != 0xff) {
		memcpy(out->name, s.name, 16);
	}
	out->esb_master_addr = s.esb_master_addr;
	out->esb_slave_addr = s.esb_slave_addr;
	out->aging_test_count = s.aging_test_count;
	out->aging_start_soc = s.aging_start_soc;
	out->aging_charge_time_s = s.aging_charge_time_s;
	out->canvas_x = s.canvas_x;
	out->canvas_y = s.canvas_y;
	out->lux_base[1] = s.lux_base[1];
	out->lux_base[0] = s.lux_base[0];
	out->lux_base[2] = s.lux_base[2];
	out->lux_base_spare = s.lux_base_spare;
	out->luminance_curve = s.luminance_curve;
	out->luminance_curve_a1 = s.luminance_curve_a1;
	out->lum_base[0] = s.lum_base[0];
	out->lum_base[1] = s.lum_base[1];
	out->lum_base[2] = s.lum_base[2];
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move */
	for (size_t k = 0; k < sizeof(s.aging_discharge_step_s); k++) {
		((uint8_t *)&out->aging_discharge_step_s)[k] = ((uint8_t *)&s.aging_discharge_step_s)[k];
	}
	out->aging_elapsed_s = s.aging_elapsed_s;
	out->aging_touch_count = s.aging_touch_count;
	out->aging_charge_check_result = s.aging_charge_check_result;
	return 0;
}

int read_usr_settting_from_flash(struct usr_settings *out)
{
	struct usr_settings s;

	memset(&s, 0, sizeof(s));
	if (flash_settings_read(USR_SETTINGS_ADDR, &s, sizeof(s))) {
		G1_LOG_WRN("usr_flash_settings_read error!\n");
		return -1;
	}
	G1_LOG_WRN("read usr settings success!\n");
	out->charge_limit_upper = s.charge_limit_upper;
	out->charge_limit_lower = s.charge_limit_lower;
	out->test_mode = s.test_mode;
	return 0;
}

int load_settings_from_flash(struct GlassesState *gs)
{
	if (load_sys_setting(gs) == 0 && load_usr_setting(gs) == 0 &&
	    load_burial_point(gs) == 0) {
		countdown_reset(get_dashboard_state()->countdown_ts);
	}
	return 0;
}

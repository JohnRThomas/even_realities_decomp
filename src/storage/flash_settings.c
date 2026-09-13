/*
 * Settings records on the external mx25r64 QSPI flash: sys settings,
 * user settings, burial point, serial number.  The raw read / write-and-verify
 * helpers (and the white-list / font writers) are at the end of local_settings.c:
 * the target .rodata shows they belong to that file.
 * Original file name unknown.
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

char SERIAL_NUMBER[32] = "S100demodevice";
char glasses_name[32] = "S100demoglasses";

int save_sys_settings(struct GlassesState *gs, int force)
{
	struct sys_settings s = {0};

	s.valid = 1;
	s.f04 = gs->f_10b8;
	s.esb_channel = gs->esb_channel;
	s.f0c = gs->f_f68;
	s.f10 = gs->f_f98;
	s.f14 = gs->f_ed4;
	memcpy(s.sn, SERIAL_NUMBER, 16);
	memcpy(s.name, glasses_name, 16);
	s.esb_master_addr = gs->esb_master_addr;
	s.esb_slave_addr = gs->esb_slave_addr;
	s.f57 = gs->f_10a8;
	s.f58 = gs->f_10a9;
	s.f5c = gs->f_10b4;
	s.f60 = gs->f_108a;
	s.f62 = gs->f_108c;
	s.f68 = gs->f_fa4;
	s.f64 = gs->f_fa8;
	s.f6c = gs->f_fac;
	s.f70 = gs->f_fb0;
	s.f7c = gs->f_fb4;
	s.f80 = gs->f_fb8;
	s.f74 = gs->f_eda;
	s.f76 = gs->f_edc;
	s.f78 = gs->f_ede;
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move; see ai_helpers/README.md (flash_settings) */
	for (size_t k = 0; k < sizeof(s.f84); k++) {
		((uint8_t *)&s.f84)[k] = ((uint8_t *)&gs->f_10bc)[k];
	}
	s.f90 = gs->f_10b0;
	s.f94 = gs->f_10c8;
	s.f95 = gs->f_10d0;
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
	gs->f_10b8 = s.f04;
	gs->first_enter_flag = s.valid;
	gs->esb_channel = s.esb_channel;
	gs->f_f68 = s.f0c;
	gs->f_f98 = s.f10;
	gs->f_ed4 = s.f14;
	if (s.sn[0] != 0xff) {
		memcpy(SERIAL_NUMBER, s.sn, 16);
	}
	if (s.name[0] != 0xff) {
		memcpy(glasses_name, s.name, 16);
	}
	gs->esb_master_addr = s.esb_master_addr;
	gs->esb_slave_addr = s.esb_slave_addr;
	gs->f_10a8 = s.f57;
	gs->f_10a9 = s.f58;
	gs->f_10b4 = s.f5c;
	gs->f_108a = s.f60;
	gs->f_108c = s.f62;
	gs->f_fa4 = s.f68;
	gs->f_fa8 = s.f64;
	gs->f_fac = s.f6c;
	gs->f_fb0 = s.f70;
	gs->f_fb4 = s.f7c;
	gs->f_fb8 = s.f80;
	gs->f_eda = s.f74;
	gs->f_edc = s.f76;
	gs->f_ede = s.f78;
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move; see ai_helpers/README.md (flash_settings) */
	for (size_t k = 0; k < sizeof(s.f84); k++) {
		((uint8_t *)&gs->f_10bc)[k] = ((uint8_t *)&s.f84)[k];
	}
	gs->f_10b0 = s.f90;
	gs->f_10c8 = s.f94;
	gs->f_10d0 = s.f95;
	if (s.valid != 1) {
		G1_LOG_WRN("FIRST BOOT, full default sys value!\n");
		gs->esb_channel = 0xff;
		gs->f_10b8 = 0;
		gs->f_f98 = 80000;
		gs->f_f68 = 0;
		gs->f_ed4 = 0;
		gs->f_108a = 0x20;
		gs->f_108c = 0x20;
		gs->f_10a8 = 0;
		gs->f_10a9 = 0;
		gs->f_10b4 = 0;
		gs->f_fb4 = 128000;
		gs->f_eda = 0x3f;
		gs->f_edc = 0x3f;
		gs->f_ede = 0x3f;
		gs->f_fa4 = 0;
		gs->f_fa8 = 0;
		gs->f_fac = 0;
		gs->f_fb0 = 0;
		gs->f_fb8 = 0;
		/* integer-typed address: GIMPLE must not CSE this with the copy's
		 * gs + 0x10bc above, so the 0x10bc constant is not kept live across
		 * the calls (see ai_helpers/agent_notes/load_sys_setting.md) */
		memset((void *)((uintptr_t)gs + offsetof(struct GlassesState, f_10bc)), 0,
		       sizeof(gs->f_10bc));
		gs->f_10b0 = 0;
		gs->f_10c8 = 0;
		gs->f_10d0 = 0;
		save_sys_settings(gs, 0);
	}
	gs->first_enter_flag = 1;
	if (gs->f_ed4 != 1) {
		gs->f_ed4 = 0;
	}
	if (gs->f_fb4 + 1 <= 1) {
		gs->f_fb4 = 128000;
	}
	if (gs->f_108a < 22 || gs->f_108a > 42) {
		gs->f_108a = 0x20;
	}
	if (gs->f_108c > 64) {
		gs->f_108c = 0x20;
	} else if (gs->f_108c < 4) {
		gs->f_108c = 4;
	}
	if (gs->f_ede == 0 || gs->f_ede > 63) {
		gs->f_ede = 0x3f;
	}
	if (gs->f_10c8 == 0xff) {
		gs->f_10c8 = 0;
	}
	return 0;
}

int FUN_0007f556(struct GlassesState *gs, int unused)
{
	struct usr_settings s = {0};

	s.display_mode = gs->display_mode;
	s.wakeup_angle = gs->wakeup_angle;
	s.brightness_level = gs->brightness_level;
	s.dof3_enable = gs->dof3_enable;
	s.f04 = gs->f_f70;
	s.f08 = gs->f_f9c;
	s.f09 = gs->f_1088;
	s.f0a = gs->f_10d4;
	s.f0b = gs->f_ec0;
	s.f0c = gs->f_1081;
	s.f13 = gs->f_ef9;
	s.f14 = gs->f_10d6;
	s.f15 = gs->f_10d8;
	s.f16 = gs->f_10d9;
	s.test_mode = FUN_00033d5c();
	s.f18 = gs->f_ec1;
	s.f1c = gs->f_f6c;
	s.f19 = gs->f_10d7;
	s.f1a = gs->f_1244;
	s.f20 = gs->dashboard_ts->f_5f;
	s.f22 = gs->f_ee0;
	s.f24 = gs->f_1246;
	flash_settings_write_and_verify(USR_SETTINGS_ADDR, &s, sizeof(s));
	return 0;
}

int clear_user_settings(struct GlassesState *gs)
{
	gs->display_mode = 10;
	gs->brightness_level = 0x15;
	gs->dof3_enable = 1;
	gs->f_f70 = 400;
	gs->f_f9c = 1;
	gs->f_10d4 = 1;
	gs->f_1088 = 0;
	gs->f_ec0 = 3;
	memset(&gs->f_1081, 0xff, sizeof(gs->f_1081));
	gs->wakeup_angle = 0x14;
	gs->f_ef9 = 1;
	gs->f_10d6 = 0;
	gs->f_10d8 = 0;
	gs->f_10d9 = 0;
	set_test_mode(0);
	gs->f_ec1 = 3;
	gs->f_f6c = 0;
	gs->f_10d7 = 15;
	gs->f_1244 = 0;
	gs->dashboard_ts->f_5f = 0;
	gs->f_ee0 = 100;
	gs->f_1246.a = 0;
	gs->f_1246.b = 0;
	FUN_0007f556(gs, 0);
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
	gs->brightness_level = s.brightness_level;
	gs->wakeup_angle = s.wakeup_angle;
	gs->dof3_enable = s.dof3_enable;
	gs->f_f70 = s.f04 ? s.f04 : 400;
	gs->f_f9c = s.f08;
	gs->f_1088 = s.f09;
	gs->f_10d4 = s.f0a;
	gs->f_ec0 = s.f0b;
	gs->f_1081 = s.f0c;
	gs->f_ef9 = s.f13;
	gs->f_10d6 = s.f14 > 1 ? 0 : s.f14;
	gs->f_10d7 = (s.f19 == 0 || s.f19 == 0xff) ? 15 : s.f19;
	gs->f_10d8 = s.f15;
	gs->f_10d9 = s.f16;
	test_mode = s.test_mode;
	gs->f_ec1 = s.f18;
	gs->f_f6c = s.f1c;
	gs->f_1244 = s.f1a;
	gs->dashboard_ts->f_5f = s.f20;
	gs->f_ee0 = s.f22;
	gs->f_1246 = s.f24;
	if (gs->display_mode == 0xff && gs->dof3_enable == 0xff) {
		clear_user_settings(gs);
	}
	if (gs->f_ec0 > 8) {
		gs->f_ec0 = 3;
	}
	if (gs->f_ec1 == 0 || gs->f_ec1 > 9) {
		gs->f_ec1 = 3;
	}
	if (gs->display_mode == 11) {
		gs->display_mode = 10;
		FUN_0007f556(gs, 0);
	}
	if (test_mode > 1) {
		test_mode = 0;
	}
	set_test_mode(test_mode);
	if (FUN_00033d5c() == 1) {
		gs->f_f9c = 0;
		gs->display_mode = 11;
		gs->brightness_level = 0x15;
		gs->f_ec0 = 3;
		gs->f_ec1 = 3;
	} else {
		gs->display_mode = 10;
	}
	if (gs->f_f6c == 0xffffffff) {
		gs->f_f6c = 0;
	}
	if (gs->f_1244 > 5) {
		gs->f_1244 = 0;
	}
	if (gs->dashboard_ts->f_5f > 2) {
		gs->dashboard_ts->f_5f = 0;
	}
	if (gs->f_ee0 < 70 || gs->f_ee0 > 100) {
		gs->f_ee0 = 100;
	}
	if (gs->f_1246.a > 1) {
		gs->f_1246.a = 0;
	}
	if (gs->f_1246.b > 1) {
		gs->f_1246.b = 0;
	}
	return 0;
}

int update_burial_point_to_flash(struct GlassesState *gs)
{
	struct burial_point bp;
	int ret;

	memset(&bp, 0, sizeof(bp));
	G1_LOG_WRN("update_burial_point_to_flash!!!\n");
	if (flash_settings_read(BURIAL_POINT_ADDR, &bp, sizeof(bp))) {
		G1_LOG_WRN("burial_point read error!\n");
		return -1;
	}
	ret = memcmp(&bp, &gs->burial_point, sizeof(bp));
	if (ret == 0) {
		return ret;
	}
	ret = flash_settings_write_and_verify(BURIAL_POINT_ADDR, &gs->burial_point,
					      sizeof(gs->burial_point));
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
	memset(&gs->burial_point, 0xff, sizeof(gs->burial_point));
	flash_settings_write_and_verify(BURIAL_POINT_ADDR, &gs->burial_point,
					sizeof(gs->burial_point));
	return 0;
}

int load_burial_point(struct GlassesState *gs)
{
	struct burial_point *bp = &gs->burial_point;
	uint32_t id;
	int ret;

	ret = flash_settings_read(BURIAL_POINT_ADDR, bp, sizeof(*bp));
	if (ret) {
		G1_LOG_WRN("burial_point read error!\n");
		return -1;
	}
	if ((bp->version == 0xff && bp->f15 == 0xff) || !bp->valid) {
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

	FUN_00038b00();
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
		k_msleep(500);
		sys_reboot(SYS_REBOOT_COLD);
	}
	k_msleep(1000);
	set_shipmode(1);
	k_msleep(1000);
}

int get_settings_from_flash(struct GlassesState *gs)
{
	gs->store.write("dashboard_ts", gs->dashboard_ts, 0x75);
	gs->store.write("countdown_ts", gs->countdown_ts, 7);
	gs->store.write("brightness_level", &gs->brightness_level, 1);
	gs->store.write("3dof_enable", &gs->dof3_enable, 1);
	gs->store.write("display_mode", &gs->display_mode, 1);
	gs->store.write("wakeup_angle", &gs->wakeup_angle, 1);
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
	out->f04 = s.f04;
	out->esb_channel = s.esb_channel;
	out->f0c = s.f0c;
	out->f10 = s.f10;
	out->f14 = s.f14;
	if (s.sn[0] != 0xff) {
		memcpy(out->sn, s.sn, 16);
	}
	if (s.name[0] != 0xff) {
		memcpy(out->name, s.name, 16);
	}
	out->esb_master_addr = s.esb_master_addr;
	out->esb_slave_addr = s.esb_slave_addr;
	out->f57 = s.f57;
	out->f58 = s.f58;
	out->f5c = s.f5c;
	out->f60 = s.f60;
	out->f62 = s.f62;
	out->f68 = s.f68;
	out->f64 = s.f64;
	out->f6c = s.f6c;
	out->f70 = s.f70;
	out->f7c = s.f7c;
	out->f80 = s.f80;
	out->f74 = s.f74;
	out->f76 = s.f76;
	out->f78 = s.f78;
	/* byte loop (not memcpy): the shipped code schedules this 12-byte copy as a
	 * char-typed block move; see ai_helpers/README.md (flash_settings) */
	for (size_t k = 0; k < sizeof(s.f84); k++) {
		((uint8_t *)&out->f84)[k] = ((uint8_t *)&s.f84)[k];
	}
	out->f90 = s.f90;
	out->f94 = s.f94;
	out->f95 = s.f95;
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
	out->f15 = s.f15;
	out->f16 = s.f16;
	out->test_mode = s.test_mode;
	return 0;
}

int FUN_0007f6c8(struct GlassesState *gs)
{
	if (load_sys_setting(gs) == 0 && load_usr_setting(gs) == 0 &&
	    load_burial_point(gs) == 0) {
		FUN_000806c6(get_dashboard_state()->countdown_ts);
	}
	return 0;
}

/* old Ghidra name, kept as an alias until the callers in other modules are renamed */
extern __typeof__(get_glasses_name) FUN_00025340 __attribute__((alias("get_glasses_name")));

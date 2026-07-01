/*
 * Function: load_sys_setting
 * Entry:    00024bd0
 * Prototype: undefined4 __stdcall load_sys_setting(GlassesState * param_1)
 */


undefined4 load_sys_setting(GlassesState *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 extraout_r2;
  undefined2 uVar4;
  undefined4 extraout_r3;
  char *pcVar5;
  int local_b0;
  undefined4 local_ac;
  undefined1 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_9c;
  char local_9b [16];
  char acStack_8b [16];
  char local_7b [16];
  char acStack_6b [16];
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  char *pcVar6;
  
  memset(&local_b0,0,0x98);
  iVar1 = flash_settings_read(&DAT_00130000,&local_b0,0x98,extraout_r3);
  if (iVar1 != 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sys_flash_settings_read error!\n");
      }
      else {
        ble_printk("%s(): sys_flash_settings_read error!\n","load_sys_setting",extraout_r2,BLE_DEBUG
                  );
      }
    }
    return 0xffffffff;
  }
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): read sys settings success!\n");
    }
    else {
      ble_printk("%s(): read sys settings success!\n","load_sys_setting",extraout_r2,BLE_DEBUG);
    }
  }
  param_1->field1252_0x10b8 = local_ac;
  *(int *)&param_1->first_enter_flag = local_b0;
  param_1->esb_channel = local_a8;
  *(undefined4 *)&(param_1->imu_fusion_context).field_0x80 = local_a4;
  *(undefined4 *)&(param_1->opt3007_context).field_0x14 = local_a0;
  (param_1->jdb_panel_context).field_0x368 = local_9c;
  if (local_9b[0] != -1) {
    pcVar2 = SERIAL_NUMBER;
    pcVar5 = local_9b;
    do {
      pcVar6 = pcVar5 + 4;
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
      pcVar2 = pcVar2 + 4;
      pcVar5 = pcVar6;
    } while (pcVar6 != acStack_8b);
  }
  if (local_7b[0] != -1) {
    puVar3 = &DAT_20003006;
    pcVar2 = local_7b;
    do {
      pcVar5 = pcVar2 + 4;
      *puVar3 = *(undefined4 *)pcVar2;
      puVar3 = puVar3 + 1;
      pcVar2 = pcVar5;
    } while (pcVar5 != acStack_6b);
  }
  param_1->field_0x3 = local_5b;
  param_1->field_0x4 = local_5a;
  param_1->field_0x10a8 = local_59;
  param_1->field_0x10a9 = local_58;
  param_1->field1251_0x10b4 = local_54;
  param_1->field1214_0x108a = local_50;
  param_1->field1215_0x108c = local_4e;
  *(undefined4 *)&param_1->field_0xfa4 = local_48;
  *(undefined4 *)&param_1->field_0xfa8 = local_4c;
  *(undefined4 *)&param_1->field_0xfac = local_44;
  *(undefined4 *)&param_1->field_0xfb0 = local_40;
  *(undefined4 *)&param_1->field_0xfb4 = local_34;
  *(undefined4 *)&param_1->field_0xfb8 = local_30;
  *(undefined2 *)&(param_1->jdb_panel_context).field_0x36e = local_3c;
  *(undefined2 *)&(param_1->jdb_panel_context).field_0x370 = local_3a;
  *(undefined2 *)&(param_1->jdb_panel_context).field_0x372 = local_38;
  param_1->field1253_0x10bc = local_2c;
  param_1->field1254_0x10c0 = uStack_28;
  param_1->field1255_0x10c4 = local_24;
  param_1->field1250_0x10b0 = local_20;
  param_1->field_0x10c8 = local_1c;
  param_1->field_0x10d0 = local_1b;
  if (local_b0 != 1) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): FIRST BOOT, full default sys value!\n");
      }
      else {
        ble_printk("%s(): FIRST BOOT, full default sys value!\n","load_sys_setting",local_b0,
                   BLE_DEBUG);
      }
    }
    param_1->esb_channel = 0xff;
    param_1->field1252_0x10b8 = 0;
    *(undefined4 *)&(param_1->opt3007_context).field_0x14 = 80000;
    *(undefined4 *)&(param_1->imu_fusion_context).field_0x80 = 0;
    (param_1->jdb_panel_context).field_0x368 = 0;
    param_1->field1214_0x108a = 0x20;
    param_1->field1215_0x108c = 0x20;
    *(undefined2 *)&param_1->field_0x10a8 = 0;
    param_1->field1251_0x10b4 = 0;
    *(undefined4 *)&param_1->field_0xfb4 = 0x1f400;
    *(undefined2 *)&(param_1->jdb_panel_context).field_0x36e = 0x3f;
    *(undefined4 *)&(param_1->jdb_panel_context).field_0x370 = 0x3f003f;
    *(undefined4 *)&param_1->field_0xfa4 = 0;
    *(undefined4 *)&param_1->field_0xfa8 = 0;
    *(undefined4 *)&param_1->field_0xfac = 0;
    *(undefined4 *)&param_1->field_0xfb0 = 0;
    *(undefined4 *)&param_1->field_0xfb8 = 0;
    param_1->field1253_0x10bc = 0;
    param_1->field1254_0x10c0 = 0;
    param_1->field1255_0x10c4 = 0;
    param_1->field1250_0x10b0 = 0;
    param_1->field_0x10c8 = 0;
    param_1->field_0x10d0 = 0;
    __save_sys_settings(param_1);
  }
  *(undefined4 *)&param_1->first_enter_flag = 1;
  if ((param_1->jdb_panel_context).field_0x368 != '\x01') {
    (param_1->jdb_panel_context).field_0x368 = 0;
  }
  if (*(int *)&param_1->field_0xfb4 + 1U < 2) {
    *(undefined4 *)&param_1->field_0xfb4 = 0x1f400;
  }
  if (0x14 < (ushort)(param_1->field1214_0x108a - 0x16)) {
    param_1->field1214_0x108a = 0x20;
  }
  if ((ushort)param_1->field1215_0x108c < 0x41) {
    if (3 < (ushort)param_1->field1215_0x108c) goto LAB_00024dfc;
    uVar4 = 4;
  }
  else {
    uVar4 = 0x20;
  }
  param_1->field1215_0x108c = uVar4;
LAB_00024dfc:
  if (0x3e < (ushort)(*(short *)&(param_1->jdb_panel_context).field_0x372 - 1U)) {
    *(undefined2 *)&(param_1->jdb_panel_context).field_0x372 = 0x3f;
  }
  if (param_1->field_0x10c8 == -1) {
    param_1->field_0x10c8 = 0;
  }
  return 0;
}



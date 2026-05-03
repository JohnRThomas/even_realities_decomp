/*
 * Function: load_sys_setting
 * Entry:    00024bd0
 * Prototype: undefined4 __stdcall load_sys_setting(GlassesState * param_1)
 */


undefined4 load_sys_setting(GlassesState *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_r2;
  undefined2 uVar3;
  undefined4 extraout_r3;
  char *pcVar4;
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
  
  memset(&local_b0,0,0x98);
  iVar1 = flash_settings_read(0x130000,&local_b0,0x98,extraout_r3);
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
  param_1->field3705_0x10b8 = local_ac;
  *(int *)&param_1->field_0x1064 = local_b0;
  param_1->field_0x2 = local_a8;
  *(undefined4 *)&(param_1->imu_fusion_context).field_0x80 = local_a4;
  *(undefined4 *)&(param_1->opt3007_context).field_0x14 = local_a0;
  param_1->field_0xed4 = local_9c;
  if (local_9b[0] != -1) {
    puVar2 = &DAT_20003026;
    pcVar5 = local_9b;
    do {
      pcVar4 = pcVar5 + 4;
      *puVar2 = *(undefined4 *)pcVar5;
      puVar2 = puVar2 + 1;
      pcVar5 = pcVar4;
    } while (pcVar4 != acStack_8b);
  }
  if (local_7b[0] != -1) {
    puVar2 = &DAT_20003006;
    pcVar5 = local_7b;
    do {
      pcVar4 = pcVar5 + 4;
      *puVar2 = *(undefined4 *)pcVar5;
      puVar2 = puVar2 + 1;
      pcVar5 = pcVar4;
    } while (pcVar4 != acStack_6b);
  }
  param_1->field_0x3 = local_5b;
  param_1->field_0x4 = local_5a;
  param_1->field_0x10a8 = local_59;
  param_1->field_0x10a9 = local_58;
  param_1->field3704_0x10b4 = local_54;
  param_1->field3667_0x108a = local_50;
  param_1->field3668_0x108c = local_4e;
  *(undefined4 *)&param_1->field_0xfa4 = local_48;
  *(undefined4 *)&param_1->field_0xfa8 = local_4c;
  *(undefined4 *)&param_1->field_0xfac = local_44;
  *(undefined4 *)&param_1->field_0xfb0 = local_40;
  *(undefined4 *)&param_1->field_0xfb4 = local_34;
  *(undefined4 *)&param_1->field_0xfb8 = local_30;
  param_1->field3446_0xeda = local_3c;
  param_1->field3447_0xedc = local_3a;
  param_1->field3448_0xede = local_38;
  param_1->field3706_0x10bc = local_2c;
  param_1->field3707_0x10c0 = uStack_28;
  param_1->field3708_0x10c4 = local_24;
  param_1->field3703_0x10b0 = local_20;
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
    param_1->field_0x2 = 0xff;
    param_1->field3705_0x10b8 = 0;
    *(undefined4 *)&(param_1->opt3007_context).field_0x14 = 80000;
    *(undefined4 *)&(param_1->imu_fusion_context).field_0x80 = 0;
    param_1->field_0xed4 = 0;
    param_1->field3667_0x108a = 0x20;
    param_1->field3668_0x108c = 0x20;
    *(undefined2 *)&param_1->field_0x10a8 = 0;
    param_1->field3704_0x10b4 = 0;
    *(undefined4 *)&param_1->field_0xfb4 = 0x1f400;
    param_1->field3446_0xeda = 0x3f;
    param_1->field3447_0xedc = 0x3f;
    param_1->field3448_0xede = 0x3f;
    *(undefined4 *)&param_1->field_0xfa4 = 0;
    *(undefined4 *)&param_1->field_0xfa8 = 0;
    *(undefined4 *)&param_1->field_0xfac = 0;
    *(undefined4 *)&param_1->field_0xfb0 = 0;
    *(undefined4 *)&param_1->field_0xfb8 = 0;
    param_1->field3706_0x10bc = 0;
    param_1->field3707_0x10c0 = 0;
    param_1->field3708_0x10c4 = 0;
    param_1->field3703_0x10b0 = 0;
    param_1->field_0x10c8 = 0;
    param_1->field_0x10d0 = 0;
    FUN_00024abc(param_1);
  }
  *(undefined4 *)&param_1->field_0x1064 = 1;
  if (param_1->field_0xed4 != '\x01') {
    param_1->field_0xed4 = 0;
  }
  if (*(int *)&param_1->field_0xfb4 + 1U < 2) {
    *(undefined4 *)&param_1->field_0xfb4 = 0x1f400;
  }
  if (0x14 < (ushort)(param_1->field3667_0x108a - 0x16)) {
    param_1->field3667_0x108a = 0x20;
  }
  if ((ushort)param_1->field3668_0x108c < 0x41) {
    if (3 < (ushort)param_1->field3668_0x108c) goto LAB_00024dfc;
    uVar3 = 4;
  }
  else {
    uVar3 = 0x20;
  }
  param_1->field3668_0x108c = uVar3;
LAB_00024dfc:
  if (0x3e < (ushort)(param_1->field3448_0xede - 1)) {
    param_1->field3448_0xede = 0x3f;
  }
  if (param_1->field_0x10c8 == -1) {
    param_1->field_0x10c8 = 0;
  }
  return 0;
}



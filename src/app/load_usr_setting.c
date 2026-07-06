/*
 * Function: load_usr_setting
 * Entry:    00024e5c
 * Prototype: undefined4 __stdcall load_usr_setting(int param_1)
 */


undefined4 load_usr_setting(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  int local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined1 local_31;
  byte local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  byte local_2d;
  undefined1 local_2c;
  char local_2b;
  undefined1 local_2a;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_22;
  undefined2 local_20;
  
  memset(&local_44,0,0x2c);
  iVar2 = flash_settings_read(0x134000,&local_44,0x2c,extraout_r3);
  if (iVar2 == 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): read user settings success!\n","load_usr_setting");
      }
      else {
        ble_printk("%s(): read user settings success!\n");
      }
    }
    *(undefined1 *)(param_1 + 0xfee) = local_44;
    *(undefined1 *)(param_1 + 0xed5) = local_43;
    *(undefined1 *)(param_1 + 0xef8) = local_42;
    *(undefined1 *)(param_1 + 0xf64) = local_41;
    if (local_40 == 0) {
      local_40 = 400;
    }
    *(int *)(param_1 + 0xf70) = local_40;
    *(undefined1 *)(param_1 + 0xf9c) = local_3c;
    *(undefined1 *)(param_1 + 0x1088) = local_3b;
    *(undefined1 *)(param_1 + 0x10d4) = local_3a;
    *(undefined1 *)(param_1 + 0xec0) = local_39;
    *(undefined2 *)(param_1 + 0x1085) = local_34;
    *(undefined1 *)(param_1 + 0x1087) = local_32;
    *(undefined4 *)(param_1 + 0x1081) = local_38;
    *(undefined1 *)(param_1 + 0xef9) = local_31;
    if (1 < local_30) {
      local_30 = 0;
    }
    *(byte *)(param_1 + 0x10d6) = local_30;
    if (0xfd < (byte)(local_2b - 1U)) {
      local_2b = '\x0f';
    }
    *(char *)(param_1 + 0x10d7) = local_2b;
    *(undefined1 *)(param_1 + 0x10d8) = local_2f;
    *(undefined1 *)(param_1 + 0x10d9) = local_2e;
    uVar4 = (uint)local_2d;
    *(undefined1 *)(param_1 + 0xec1) = local_2c;
    *(undefined4 *)(param_1 + 0xf6c) = local_28;
    *(undefined1 *)(param_1 + 0x1244) = local_2a;
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x5f) = local_24;
    *(undefined1 *)(param_1 + 0xee0) = local_22;
    *(undefined2 *)(param_1 + 0x1246) = local_20;
    if ((*(char *)(param_1 + 0xfee) == -1) && (*(char *)(param_1 + 0xf64) == -1)) {
      __clear_user_settings(param_1);
    }
    if (8 < *(byte *)(param_1 + 0xec0)) {
      *(undefined1 *)(param_1 + 0xec0) = 3;
    }
    if (8 < *(byte *)(param_1 + 0xec1) - 1) {
      *(undefined1 *)(param_1 + 0xec1) = 3;
    }
    if (*(char *)(param_1 + 0xfee) == '\v') {
      *(undefined1 *)(param_1 + 0xfee) = 10;
      FUN_0007f556(param_1);
    }
    if (1 < uVar4) {
      uVar4 = 0;
    }
    __set_test_mode(uVar4);
    cVar1 = FUN_00033d5c();
    if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 0xf9c) = 0;
      *(undefined1 *)(param_1 + 0xfee) = 0xb;
      *(undefined1 *)(param_1 + 0xed5) = 0x15;
      *(undefined2 *)(param_1 + 0xec0) = 0x303;
    }
    else {
      *(undefined1 *)(param_1 + 0xfee) = 10;
    }
    if (*(int *)(param_1 + 0xf6c) == -1) {
      *(undefined4 *)(param_1 + 0xf6c) = 0;
    }
    if (5 < *(byte *)(param_1 + 0x1244)) {
      *(undefined1 *)(param_1 + 0x1244) = 0;
    }
    if (2 < *(byte *)(*(int *)(param_1 + 0xff0) + 0x5f)) {
      *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x5f) = 0;
    }
    if (0x1e < *(byte *)(param_1 + 0xee0) - 0x46) {
      *(undefined1 *)(param_1 + 0xee0) = 100;
    }
    if (1 < *(byte *)(param_1 + 0x1246)) {
      *(undefined1 *)(param_1 + 0x1246) = 0;
    }
    uVar3 = 0;
    if (1 < *(byte *)(param_1 + 0x1247)) {
      *(undefined1 *)(param_1 + 0x1247) = 0;
    }
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): usr_flash_settings_read error!\n","load_usr_setting");
      }
      else {
        ble_printk("%s(): usr_flash_settings_read error!\n");
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



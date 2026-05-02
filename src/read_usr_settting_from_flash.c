/*
 * Function: read_usr_settting_from_flash
 * Entry:    000254b8
 * Prototype: undefined4 __stdcall read_usr_settting_from_flash(int param_1)
 */


undefined4 read_usr_settting_from_flash(int param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined1 auStack_3c [21];
  undefined1 local_27;
  undefined2 local_26;
  
  memset(auStack_3c,0,0x2c);
  iVar1 = flash_settings_read(0x134000,auStack_3c,0x2c,extraout_r3);
  if (iVar1 == 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): read usr settings success!\n");
      }
      else {
        ble_printk("%s(): read usr settings success!\n","read_usr_settting_from_flash",extraout_r2,
                   BLE_DEBUG);
      }
    }
    *(undefined1 *)(param_1 + 0x15) = local_27;
    *(undefined2 *)(param_1 + 0x16) = local_26;
    uVar2 = 0;
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): usr_flash_settings_read error!\n");
      }
      else {
        ble_printk("%s(): usr_flash_settings_read error!\n","read_usr_settting_from_flash",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



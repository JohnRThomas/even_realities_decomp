/*
 * Function: update_burial_point_to_flash
 * Entry:    00025084
 * Prototype: undefined4 __stdcall update_burial_point_to_flash(GlassesState * gs_state)
 */


undefined4 update_burial_point_to_flash(GlassesState *gs_state)

{
  int iVar1;
  char *fmt;
  int extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined1 auStack_12c [288];
  
  memset(auStack_12c,0,284);
  iVar1 = LOG_LEVEL;
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): update_burial_point_to_flash!!!\n","update_burial_point_to_flash");
      iVar1 = extraout_r3_00;
    }
    else {
      ble_printk("%s(): update_burial_point_to_flash!!!\n");
      iVar1 = extraout_r3;
    }
  }
  iVar1 = flash_settings_read(0x135000,auStack_12c,284,iVar1);
  if (iVar1 == 0) {
    iVar1 = memcmp(auStack_12c,&gs_state->__burial_point_ctx,0x11c);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = flash_settings_write_and_verify
                      (0x135000,&gs_state->__burial_point_ctx,0x11c,extraout_r3_01);
    if (iVar1 == 0) {
      return 0;
    }
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): burial_point flash_settings_write_and_verify error!\n";
  }
  else {
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): burial_point read error!\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,"update_burial_point_to_flash");
  }
  else {
    ble_printk(fmt);
  }
  return 0xffffffff;
}



/*
 * Function: set_brightness_to_panel_reg
 * Entry:    0004a830
 * Prototype: undefined __stdcall set_brightness_to_panel_reg(uint param_1, uint param_2)
 */


void set_brightness_to_panel_reg(uint param_1,uint param_2)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): set brightness level = %d\n");
    }
    else {
      ble_printk("%s(): set brightness level = %d\n","set_brightness_to_panel_reg",param_1,BLE_DEBUG
                 ,param_1);
    }
  }
  __update_brightness_level_for_jdb_panel
            (param_1,(ushort *)((int)&uStack_c + 2),(char *)((int)&uStack_c + 1));
  FUN_00080ece(6);
  FUN_00080ece(0xa9);
  FUN_00080d5e(uStack_c >> 0x10,extraout_r1,extraout_r2);
  FUN_00080d46(uStack_c >> 8 & 0xff,extraout_r1_00,extraout_r2_00);
  FUN_00080d0a(0x31,4,extraout_r2_01);
  FUN_00080ece(0xa3);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  return;
}



/*
 * Function: set_brightness_to_panel_reg_in_running
 * Entry:    0004aa30
 * Prototype: undefined __stdcall set_brightness_to_panel_reg_in_running(uint param_1, uint param_2)
 */


void set_brightness_to_panel_reg_in_running(uint param_1,uint param_2)

{
  GlassesState *pGVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): set brightness level = %d\n");
    }
    else {
      ble_printk("%s(): set brightness level = %d\n","set_brightness_to_panel_reg_in_running",
                 param_1,BLE_DEBUG);
    }
  }
  pGVar1 = __get_dashboard_state();
  if ((pGVar1->jdb_panel_context).__initialized != 0) {
    __update_brightness_level_for_jdb_panel
              (param_1,(ushort *)((int)&uStack_c + 2),(char *)((int)&uStack_c + 1));
    thunk_FUN_00080ece(6);
    thunk_FUN_00080ece(0xa9);
    FUN_0004aa00(uStack_c >> 0x10,uStack_c >> 8 & 0xff,extraout_r2);
    FUN_00080d0a(0x31,4,extraout_r2_00);
    thunk_FUN_00080ece(0xa3);
    thunk_FUN_00080ece(0x97);
    busy_wait_seconds(1);
    return;
  }
  return;
}



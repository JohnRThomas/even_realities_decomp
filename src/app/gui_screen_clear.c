/*
 * Function: gui_screen_clear
 * Entry:    000452fc
 * Prototype: undefined4 __stdcall gui_screen_clear(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 gui_screen_clear(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  jdb_panel_context *pjVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exec screen clear command....\n");
    }
    else {
      ble_printk("%s(): exec screen clear command....\n","gui_screen_clear",param_3,BLE_DEBUG);
    }
  }
  pjVar1 = get_jdb_panel_context();
  if (pjVar1->__initialized == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n","gui_screen_clear",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00080dbc(0);
    uVar2 = 0;
  }
  return uVar2;
}



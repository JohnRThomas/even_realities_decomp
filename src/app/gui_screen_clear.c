/*
 * Function: gui_screen_clear
 * Entry:    000452fc
 * Prototype: undefined4 __stdcall gui_screen_clear(void)
 */


undefined4 gui_screen_clear(void)

{
  jbd_panel_context *pjVar1;
  undefined4 uVar2;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exec screen clear command....\n","gui_screen_clear");
    }
    else {
      ble_printk("%s(): exec screen clear command....\n");
    }
  }
  pjVar1 = get_jdb_panel_context();
  if (pjVar1->init_done == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->init_done = 0,init failed, can\'t write data!\n","gui_screen_clear");
      }
      else {
        ble_printk("%s(): c->init_done = 0,init failed, can\'t write data!\n");
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



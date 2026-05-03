/*
 * Function: gui_screen_clear
 * Entry:    000452fc
 * Prototype: undefined4 __stdcall gui_screen_clear(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 gui_screen_clear(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
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
  puVar1 = __get_something_from_glasses_state();
  if (*(int *)(puVar1 + 0x35c) == 0) {
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



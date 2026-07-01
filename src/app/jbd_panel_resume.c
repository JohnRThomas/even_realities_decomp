/*
 * Function: jbd_panel_resume
 * Entry:    0004aef0
 * Prototype: undefined4 __stdcall jbd_panel_resume(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 jbd_panel_resume(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint extraout_r1;
  undefined4 extraout_r2;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): release from deep power down\n");
    }
    else {
      ble_printk("%s(): release from deep power down\n","jbd_panel_resume",param_3,BLE_DEBUG);
    }
  }
  panel_init();
  set_brightness_to_panel_reg((uint)*(byte *)(param_1 + 0x369),extraout_r1);
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): resume completed\n");
    }
    else {
      ble_printk("%s(): resume completed\n","jbd_panel_resume",extraout_r2,BLE_DEBUG);
    }
  }
  return 0;
}



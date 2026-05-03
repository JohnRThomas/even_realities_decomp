/*
 * Function: jbd_panel_suspend
 * Entry:    0004aea8
 * Prototype: undefined4 __stdcall jbd_panel_suspend(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 jbd_panel_suspend(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): SPI_DEEP_POWER_DOWN\n");
    }
    else {
      ble_printk("%s(): SPI_DEEP_POWER_DOWN\n","jbd_panel_suspend",param_3,BLE_DEBUG);
    }
  }
  uStack_c = CONCAT13(0xff,(undefined3)uStack_c);
  FUN_00080f80(0xb9,(void *)((int)&uStack_c + 3),1);
  return 0;
}



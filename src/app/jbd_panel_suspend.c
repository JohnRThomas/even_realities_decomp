/*
 * Function: jbd_panel_suspend
 * Entry:    0004aea8
 * Prototype: undefined4 __stdcall jbd_panel_suspend(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 jbd_panel_suspend(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): SPI_DEEP_POWER_DOWN\n","jbd_panel_suspend",param_3,0,param_1,param_2);
    }
    else {
      ble_printk("%s(): SPI_DEEP_POWER_DOWN\n");
    }
  }
  spi_tx_frame(SPI_DEEP_POWER_DOWN,&stack0xfffffff7,1);
  return 0;
}



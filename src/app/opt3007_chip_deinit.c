/*
 * Function: opt3007_chip_deinit
 * Entry:    0002fd3c
 * Prototype: undefined __stdcall opt3007_chip_deinit(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void opt3007_chip_deinit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_2000854c != 0) {
    param_3 = 0;
    *(undefined4 *)(DAT_2000854c + 0x10) = 0;
  }
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): opt3007_chip_deinit done!\n");
    }
    else {
      ble_printk("%s(): opt3007_chip_deinit done!\n","opt3007_chip_deinit",param_3,BLE_DEBUG);
    }
  }
  DAT_20019a6f = 0;
  return;
}



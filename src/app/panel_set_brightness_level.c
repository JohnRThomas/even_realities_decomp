/*
 * Function: panel_set_brightness_level
 * Entry:    0004a6dc
 * Prototype: uint __stdcall panel_set_brightness_level(int param_1, uint param_2)
 */


uint panel_set_brightness_level(int param_1,uint param_2)

{
  if ((*(byte *)(param_1 + 0x369) != param_2) &&
     (*(char *)(param_1 + 0x369) = (char)param_2, 2 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): new: %d\n");
    }
    else {
      ble_printk("%s(): new: %d\n","panel_set_brightness_level",param_2,BLE_DEBUG);
    }
  }
  return param_2;
}



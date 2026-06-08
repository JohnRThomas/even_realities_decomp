/*
 * Function: bt_send_enabled
 * Entry:    00017f3c
 * Prototype: undefined __stdcall bt_send_enabled(int param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void bt_send_enabled(int param_1)

{
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): status:%d\n\n");
    }
    else {
      ble_printk("%s(): status:%d\n\n","bt_send_enabled",param_1,BLE_DEBUG);
    }
  }
  *(bool *)(GLOBAL_STATE._52_4_ + 0x366) = param_1 == 0;
  return;
}



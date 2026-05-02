/*
 * Function: DashboardLockTimerExpiry_callback
 * Entry:    0001a210
 * Prototype: undefined __stdcall DashboardLockTimerExpiry_callback(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void DashboardLockTimerExpiry_callback(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): dashboard lock timeout,release .\n");
    }
    else {
      ble_printk("%s(): dashboard lock timeout,release .\n","DashboardLockTimerExpiry_callback",
                 param_3,BLE_DEBUG);
    }
  }
  DAT_20007f50 = DAT_20007f50 & 0xfffffffd;
  DAT_20007f4c = DAT_20007f4c & 0xfffffffd;
  DAT_20008480 = DAT_20008480 & 0xfffffffd;
  return;
}



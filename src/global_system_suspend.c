/*
 * Function: global_system_suspend
 * Entry:    0002d8f8
 * Prototype: undefined4 __stdcall global_system_suspend(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 global_system_suspend(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_r2;
  
  if ((*(byte *)(param_1 + 0xfea) & 0xfb) == 0) {
    *(undefined1 *)(param_1 + 0xfea) = 2;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): begin.\n");
      }
      else {
        ble_printk("%s(): begin.\n","global_system_suspend",param_3,BLE_DEBUG);
      }
    }
    z_impl_k_sleep((k_timeout_t)0x2667);
    (**(code **)(param_1 + 0xb70))(param_1 + 0xb6c);
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): end.\n");
      }
      else {
        ble_printk("%s(): end.\n","global_system_suspend",extraout_r2,BLE_DEBUG);
      }
    }
    *(undefined1 *)(param_1 + 0xfea) = 1;
  }
  return 0;
}



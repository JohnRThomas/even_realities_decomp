/*
 * Function: global_system_resume
 * Entry:    0002d974
 * Prototype: undefined4 __stdcall global_system_resume(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 global_system_resume(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_r2;
  
  if ((*(byte *)(param_1 + 0xfea) & 0xfb) == 1) {
    *(undefined1 *)(param_1 + 0xfea) = 3;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): begin.\n");
      }
      else {
        ble_printk("%s(): begin.\n","global_system_resume",param_3,BLE_DEBUG);
      }
    }
    (**(code **)(param_1 + 0xb74))(param_1 + 0xb6c);
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): end.\n");
      }
      else {
        ble_printk("%s(): end.\n","global_system_resume",extraout_r2,BLE_DEBUG);
      }
    }
    *(undefined1 *)(param_1 + 0xfea) = 0;
  }
  return 0;
}



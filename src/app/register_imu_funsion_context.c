/*
 * Function: register_imu_funsion_context
 * Entry:    0002832c
 * Prototype: undefined4 __stdcall register_imu_funsion_context(imu_fusion_context * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4
register_imu_funsion_context(imu_fusion_context *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1->init_cb = 0x28089;
  param_1->field141_0x90 = 0x7fdc1;
  param_1->field142_0x94 = 0x7fded;
  param_1->field143_0x98 = 0x7fdb7;
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exit\n\n");
    }
    else {
      ble_printk("%s(): exit\n\n","register_imu_funsion_context",param_3,BLE_DEBUG);
    }
  }
  return 0;
}



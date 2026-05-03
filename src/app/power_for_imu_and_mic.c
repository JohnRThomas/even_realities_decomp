/*
 * Function: power_for_imu_and_mic
 * Entry:    00016020
 * Prototype: undefined4 __stdcall power_for_imu_and_mic(void)
 */


undefined4 power_for_imu_and_mic(void)

{
  nrfx_err_t nVar1;
  char *fmt;
  undefined4 extraout_r2;
  
  nVar1 = nrfx_gpiote_channel_get(0x8b430,&NMI);
  if ((int)nVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Could not set ldsw2.\n";
  }
  else {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): enable ldsw2 for imu and mic\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"power_for_imu_and_mic",extraout_r2,BLE_DEBUG);
  }
  return 0;
}



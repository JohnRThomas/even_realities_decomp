/*
 * Function: power_down_imu_and_mic
 * Entry:    00016154
 * Prototype: undefined4 __stdcall power_down_imu_and_mic(void)
 */


undefined4 power_down_imu_and_mic(void)

{
  int iVar1;
  char *fmt;
  undefined4 extraout_r2;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&NMI,3);
  if (iVar1 < 0) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): Could not set ldsw2.\n";
  }
  else {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): disable ldsw2 for imu and mic\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"power_down_imu_and_mic",extraout_r2,BLE_DEBUG);
  }
  return 0;
}



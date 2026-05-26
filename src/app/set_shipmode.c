/*
 * Function: set_shipmode
 * Entry:    00016868
 * Prototype: undefined4 __stdcall set_shipmode(void)
 */


undefined4 set_shipmode(void)

{
  int iVar1;
  char *fmt;
  
  power_down_panel();
  power_down_imu_and_mic();
  sleep(2000);
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_0000000b,2);
  if (iVar1 < 0) {
    fmt = "Could not set shipmode.\n";
  }
  else {
    fmt = "enable for shipmode\n";
  }
  printk(fmt);
  return 0;
}



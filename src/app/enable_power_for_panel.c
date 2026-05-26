/*
 * Function: ?_enable_power_for_panel
 * Entry:    0002fd9c
 * Prototype: undefined4 __stdcall ?_enable_power_for_panel(void)
 */


undefined4 __enable_power_for_panel(void)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&NMI,0);
  if (iVar1 < 0) {
    printk("Could not set ldsw1.\n");
  }
  else {
    printk("enable ldsw1 1.8v for panel\n");
    opt3007_chip_init((opt3007_context *)0x0,extraout_r1,extraout_r2);
  }
  return 0;
}



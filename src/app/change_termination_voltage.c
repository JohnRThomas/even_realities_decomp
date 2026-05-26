/*
 * Function: ?_change_termination_voltage
 * Entry:    0002ff00
 * Prototype: int __stdcall ?_change_termination_voltage(void)
 */


int __change_termination_voltage(void)

{
  int iVar1;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0xc);
  if (iVar1 < 0) {
    printk("Could not change termination voltage to 4.2V\n");
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



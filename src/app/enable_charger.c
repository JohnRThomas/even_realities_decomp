/*
 * Function: ?_enable_charger
 * Entry:    0002ff30
 * Prototype: undefined4 __stdcall ?_enable_charger(void)
 */


undefined4 __enable_charger(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,4);
  if (iVar1 < 0) {
    printk("Could not enable charger\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



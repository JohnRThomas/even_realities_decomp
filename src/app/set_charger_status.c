/*
 * Function: ?_set_charger_status
 * Entry:    0002ff60
 * Prototype: uint __stdcall ?_set_charger_status(size_t param_1, uint3 param_2)
 */


uint __set_charger_status(size_t param_1,uint3 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_c;
  
  uStack_c = (uint)param_2;
  iVar1 = i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x34,
                            (void *)((int)&uStack_c + 3),param_1);
  if (iVar1 < 0) {
    printk("Could not get charger status\n");
    uVar2 = 0xffffffff;
  }
  else if ((int)(((int)(uint)uStack_c._3_1_ >> 3 | (uint)(uStack_c._3_1_ >> 2)) << 0x1f) < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(uint)(uStack_c._3_1_ >> 4) & 1;
  }
  return uVar2;
}



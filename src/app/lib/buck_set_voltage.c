/*
 * Function: buck_set_voltage
 * Entry:    00087ab0
 * Prototype: undefined __stdcall buck_set_voltage(int param_1, uint param_2, linear_range * param_3, int32_t param_4)
 */


/* exclude_from_export */

void buck_set_voltage(int param_1,uint param_2,linear_range *param_3,int32_t param_4)

{
  int iVar1;
  uint8_t data;
  undefined1 local_12 [6];
  
  iVar1 = linear_range_get_win_index(param_3,param_4,(int32_t)local_12,(uint16_t *)param_4);
  if ((iVar1 != -0x16) &&
     (iVar1 = i2c_write_dt(*(i2c_dt_spec **)(param_1 + 0x1c),&Reset,(param_2 + 4) * 2 & 0xfe),
     -1 < iVar1)) {
    data = (uint8_t)(1 << (param_2 & 0xff));
    mfd_npm1300_reg_update(*(device **)(param_1 + 0x1c),'\x04','\x0f',data,data);
  }
  return;
}



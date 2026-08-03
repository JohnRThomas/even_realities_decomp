/*
 * Function: ST25DV_GetUID
 * Entry:    0007fc9a
 * Prototype: int __stdcall ST25DV_GetUID(st25dv_context * param_1, int param_2)
 */


int ST25DV_GetUID(st25dv_context *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = __eeprom_st25dv_read_sys(param_1,0x18,param_2,8);
    return iVar1;
  }
  return -0x16;
}



/*
 * Function: FUN_0007fcbe
 * Entry:    0007fcbe
 * Prototype: int __stdcall FUN_0007fcbe(st25dv_context * param_1, int param_2)
 */


int FUN_0007fcbe(st25dv_context *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = __eeprom_st25dv_read_sys(param_1,0x17,param_2,1);
    return iVar1;
  }
  return -0x16;
}



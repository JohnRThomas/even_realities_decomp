/*
 * Function: FUN_0007fc50
 * Entry:    0007fc50
 * Prototype: int __stdcall FUN_0007fc50(st25dv_context * param_1, int param_2)
 */


int FUN_0007fc50(st25dv_context *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = __eeprom_st25dv_read_sys(param_1,1,param_2,1);
    return iVar1;
  }
  return -0x16;
}



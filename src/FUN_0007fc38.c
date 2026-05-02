/*
 * Function: FUN_0007fc38
 * Entry:    0007fc38
 * Prototype: undefined __stdcall FUN_0007fc38(int param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0007fc38(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_9;
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  __eeprom_st25dv_write_sys(param_1,0,&local_9,1);
  return;
}



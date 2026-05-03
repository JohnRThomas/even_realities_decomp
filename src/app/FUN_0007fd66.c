/*
 * Function: FUN_0007fd66
 * Entry:    0007fd66
 * Prototype: undefined __stdcall FUN_0007fd66(int param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0007fd66(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_9;
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  __eeprom_st25dv_write(param_1,0x2002,&local_9,1);
  return;
}



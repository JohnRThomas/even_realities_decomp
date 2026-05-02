/*
 * Function: FUN_0007fd5a
 * Entry:    0007fd5a
 * Prototype: undefined __stdcall FUN_0007fd5a(st25dv_context * param_1, undefined4 param_2)
 */


void FUN_0007fd5a(st25dv_context *param_1,undefined4 param_2)

{
  __eeprom_st25dv_read(param_1,0x2002,param_2,1);
  return;
}



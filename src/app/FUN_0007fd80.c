/*
 * Function: FUN_0007fd80
 * Entry:    0007fd80
 * Prototype: undefined __stdcall FUN_0007fd80(st25dv_context * param_1, undefined4 param_2)
 */


void FUN_0007fd80(st25dv_context *param_1,undefined4 param_2)

{
  __eeprom_st25dv_read(param_1,ST25DV_ITSTS_DYN_REG,param_2,1);
  return;
}



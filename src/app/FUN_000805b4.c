/*
 * Function: FUN_000805b4
 * Entry:    000805b4
 * Prototype: undefined __stdcall FUN_000805b4(uint * param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_000805b4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  cJSON_SetValuestring(0x1c04,param_1,param_3);
  *param_1 = (int)*param_1 >> 10;
  return;
}



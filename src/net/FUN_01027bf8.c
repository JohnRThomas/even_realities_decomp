/*
 * Function: FUN_01027bf8
 * Entry:    01027bf8
 * Prototype: undefined4 * __stdcall FUN_01027bf8(undefined4 * param_1, undefined1 param_2)
 */


undefined4 * FUN_01027bf8(undefined4 *param_1,undefined1 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)((int)param_1 + 6) = param_2;
  return param_1;
}



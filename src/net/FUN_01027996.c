/*
 * Function: FUN_01027996
 * Entry:    01027996
 * Prototype: undefined __stdcall FUN_01027996(undefined4 * param_1, undefined2 param_2)
 */


void FUN_01027996(undefined4 *param_1,undefined2 param_2)

{
  *param_1 = 0;
  *(undefined2 *)(param_1 + 1) = param_2;
  return;
}



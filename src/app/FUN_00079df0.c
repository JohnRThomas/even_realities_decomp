/*
 * Function: $_?_FUN_00079df0
 * Entry:    00079df0
 * Prototype: undefined __stdcall $_?_FUN_00079df0(undefined4 * param_1, undefined2 param_2, undefined2 param_3)
 */


void ____FUN_00079df0(undefined4 *param_1,undefined2 param_2,undefined2 param_3)

{
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = param_2;
  param_1[0x19] = 0;
  *(undefined2 *)((int)param_1 + 0xe) = param_3;
  param_1[6] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  memset(param_1 + 0x17,0,8);
  param_1[8] = param_1;
  param_1[9] = 0x8a6e5;
  param_1[10] = 0x8a70b;
  param_1[0xb] = 0x8a743;
  param_1[0xc] = 0x8a767;
  return;
}



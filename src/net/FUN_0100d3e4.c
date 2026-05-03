/*
 * Function: FUN_0100d3e4
 * Entry:    0100d3e4
 * Prototype: undefined __stdcall FUN_0100d3e4(undefined4 * param_1, int param_2)
 */


void FUN_0100d3e4(undefined4 *param_1,int param_2)

{
  *(undefined4 *)(&DAT_21000e22 + param_2 * 6) = *param_1;
  *(undefined2 *)(&DAT_21000e26 + param_2 * 6) = *(undefined2 *)(param_1 + 1);
  return;
}



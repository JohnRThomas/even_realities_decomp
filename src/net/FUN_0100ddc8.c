/*
 * Function: FUN_0100ddc8
 * Entry:    0100ddc8
 * Prototype: undefined __stdcall FUN_0100ddc8(int param_1, int param_2)
 */


void FUN_0100ddc8(int param_1,int param_2)

{
  *(char *)(param_1 + 0x72) = (char)param_2;
  FUN_0101e9e4(param_1,param_2);
  return;
}



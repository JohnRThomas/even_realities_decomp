/*
 * Function: FUN_0102789e
 * Entry:    0102789e
 * Prototype: undefined2 __stdcall FUN_0102789e(int param_1, undefined2 * param_2, int * param_3)
 */


undefined2 FUN_0102789e(int param_1,undefined2 *param_2,int *param_3)

{
  short sVar1;
  
  sVar1 = FUN_01027056(*(byte *)(param_1 + 0x13));
  *param_3 = (int)param_2 + sVar1 + -3;
  return *param_2;
}



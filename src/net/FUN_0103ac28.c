/*
 * Function: FUN_0103ac28
 * Entry:    0103ac28
 * Prototype: int __stdcall FUN_0103ac28(int * param_1)
 */


int FUN_0103ac28(int *param_1)

{
  return ((uint)*(ushort *)((int)param_1 + 6) - (uint)*(ushort *)(param_1 + 1)) -
         (*param_1 - param_1[2]);
}



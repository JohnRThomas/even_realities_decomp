/*
 * Function: FUN_01021e14
 * Entry:    01021e14
 * Prototype: int __stdcall FUN_01021e14(int param_1, int param_2)
 */


int FUN_01021e14(int param_1,int param_2)

{
  return param_1 + (*(ushort *)(&DAT_0103c584 + param_2 * 2) + 1000) / 1000;
}



/*
 * Function: FUN_01021e94
 * Entry:    01021e94
 * Prototype: int __stdcall FUN_01021e94(int param_1, int param_2, int param_3)
 */


int FUN_01021e94(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_010211f0(param_2);
  iVar3 = *(int *)(&DAT_0103c598 + param_3 * 4);
  iVar2 = FUN_010211e0(param_3);
  return iVar2 + 5 + (uint)((param_1 * 1000 + iVar3 + 2999) - iVar1) / 1000;
}



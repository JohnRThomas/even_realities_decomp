/*
 * Function: FUN_01021e54
 * Entry:    01021e54
 * Prototype: int __stdcall FUN_01021e54(int param_1, int param_2, int param_3, int param_4)
 */


int FUN_01021e54(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(&DAT_0103c584 + param_2 * 2);
  iVar3 = *(int *)(&DAT_0103c598 + param_3 * 4);
  iVar2 = FUN_010211e0(param_3);
  return iVar2 + (param_1 * 1000 + iVar3 + (uint)uVar1 + 2999) / 1000 + param_4 + 5;
}



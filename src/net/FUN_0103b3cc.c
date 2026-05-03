/*
 * Function: FUN_0103b3cc
 * Entry:    0103b3cc
 * Prototype: undefined4 __stdcall FUN_0103b3cc(undefined4 param_1, undefined2 param_2, undefined4 param_3, int * param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7)
 */


undefined4
FUN_0103b3cc(undefined4 param_1,undefined2 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  *param_7 = param_1;
  param_7[1] = param_3;
  *(undefined2 *)(param_7 + 2) = param_2;
  uVar1 = *(ushort *)(param_4 + 2);
  uVar3 = (uint)uVar1;
  param_7[3] = param_5;
  *(ushort *)((int)param_7 + 10) = uVar1;
  *(ushort *)(param_7 + 9) = uVar1;
  param_7[4] = param_6;
  iVar4 = *param_4;
  iVar2 = param_4[1];
  iVar5 = iVar4 + uVar3 * 0x10;
  param_7[5] = uVar3;
  param_7[6] = iVar4;
  param_7[7] = iVar5;
  param_7[8] = iVar5 + (uVar3 + 2) * 2 + iVar2 + 1 & -iVar2;
  return 0;
}



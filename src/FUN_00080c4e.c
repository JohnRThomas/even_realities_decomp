/*
 * Function: FUN_00080c4e
 * Entry:    00080c4e
 * Prototype: undefined __stdcall FUN_00080c4e(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
 */


void FUN_00080c4e(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar2 = 0;
  if (199 < param_6) {
    param_6 = 200;
  }
  if (0x27f < param_5) {
    param_5 = 0x280;
  }
  iVar4 = 0;
  for (; iVar2 < param_4; iVar2 = iVar2 + 1) {
    pbVar5 = (byte *)(param_2 + iVar4);
    for (iVar3 = 0; iVar3 < param_3 / 2; iVar3 = iVar3 + 1) {
      iVar1 = *(int *)(param_1 + param_6 * 4 + iVar2 * 4);
      iVar6 = param_5 / 2 + iVar3;
      *(byte *)(iVar1 + iVar6) = *pbVar5 | *(byte *)(iVar1 + iVar6);
      pbVar5 = pbVar5 + 1;
    }
    iVar4 = iVar4 + (param_3 / 2 & ~(param_3 - (param_3 >> 0x1f) >> 0x1f));
  }
  return;
}



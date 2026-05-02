/*
 * Function: FUN_0008043e
 * Entry:    0008043e
 * Prototype: int __stdcall FUN_0008043e(int param_1, uint param_2, uint param_3)
 */


int FUN_0008043e(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = 0;
  iVar5 = 0;
  for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 4) {
    if (uVar4 < param_2) {
      iVar6 = param_1 + iVar3;
      pbVar1 = (byte *)(param_1 + iVar3);
      iVar3 = iVar3 + 4;
      uVar2 = (uint)*(byte *)(iVar6 + 3) | (uint)*pbVar1 << 0x18 |
              (uint)*(byte *)(iVar6 + 1) << 0x10 | (uint)*(byte *)(iVar6 + 2) << 8;
    }
    else {
      uVar2 = 0xffffffff;
    }
    iVar5 = iVar5 + uVar2;
  }
  return -iVar5;
}



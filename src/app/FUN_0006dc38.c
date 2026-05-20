/*
 * Function: FUN_0006dc38
 * Entry:    0006dc38
 * Prototype: undefined __stdcall FUN_0006dc38(longlong * param_1, int param_2, undefined2 * param_3, int param_4)
 */


void FUN_0006dc38(longlong *param_1,int param_2,undefined2 *param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if (0 < param_4) {
    uVar9 = 0;
    uVar8 = 0xffc30000;
    uVar6 = 0;
    while( true ) {
      iVar7 = ((int)uVar9 >> 3) + -10;
      iVar5 = param_2 + iVar7 * 4;
      uVar4 = *(undefined4 *)(param_2 + iVar7 * 4);
      uVar9 = uVar9 + 5;
      iVar5 = (int)(short)*(undefined4 *)(iVar5 + 0x28) * (int)(short)(&DAT_0008f9f0)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x28) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9f0)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x24) * (int)(short)(&DAT_0008f9ec)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x24) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9ec)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x20) * (int)(short)(&DAT_0008f9e8)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x20) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9e8)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x1c) * (int)(short)(&DAT_0008f9e4)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x1c) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9e4)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x18) * (int)(short)(&DAT_0008f9e0)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x18) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9e0)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x14) * (int)(short)(&DAT_0008f9dc)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x14) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9dc)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x10) * (int)(short)(&DAT_0008f9d8)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x10) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9d8)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0xc) * (int)(short)(&DAT_0008f9d4)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0xc) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9d4)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 8) * (int)(short)(&DAT_0008f9d0)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 8) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9d0)[uVar6 * 0xc] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 4) * (int)(short)(&DAT_0008f9cc)[uVar6 * 0xc] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 4) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f9cc)[uVar6 * 0xc] >> 0x10) +
              (int)(short)uVar4 * (int)(short)uVar8 +
              (int)(short)((uint)uVar4 >> 0x10) * (int)(short)((uint)uVar8 >> 0x10);
      lVar2 = (longlong)iVar5 * 0x3ee61bc6;
      lVar3 = lVar2 + *param_1;
      uVar6 = (uint)lVar3 >> 0x1e | (int)((ulonglong)lVar3 >> 0x20) * 4;
      uVar1 = (longlong)iVar5 * -0x7dcc378e + param_1[1];
      *param_1 = (longlong)(int)uVar6 * 0x7dc75ddb +
                 ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
      param_1[1] = (longlong)(int)uVar6 * -0x3dd11141 + lVar2;
      *param_3 = (short)(uVar6 + 0x8000 >> 0x10);
      if (param_4 * 5 <= (int)uVar9) break;
      uVar8 = *(undefined4 *)(&UNK_0008f9c8 + (uVar9 & 7) * 0x30);
      uVar6 = uVar9 & 7;
      param_3 = param_3 + 1;
    }
  }
  return;
}



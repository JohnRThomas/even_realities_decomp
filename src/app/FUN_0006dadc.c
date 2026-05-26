/*
 * Function: FUN_0006dadc
 * Entry:    0006dadc
 * Prototype: undefined __stdcall FUN_0006dadc(longlong * param_1, int param_2, undefined2 * param_3, int param_4)
 */


void FUN_0006dadc(longlong *param_1,int param_2,undefined2 *param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  
  if (0 < param_4) {
    uVar9 = 0;
    puVar8 = &DAT_ffe20000;
    uVar6 = 0;
    while( true ) {
      iVar7 = ((int)uVar9 >> 2) + -0x14;
      iVar5 = param_2 + iVar7 * 4;
      uVar4 = *(undefined4 *)(param_2 + iVar7 * 4);
      uVar9 = uVar9 + 5;
      iVar5 = (int)(short)*(undefined4 *)(iVar5 + 0x50) * (int)(short)(&PTR_0008ff98)[uVar6 * 0x18]
              + (int)(short)((uint)*(undefined4 *)(iVar5 + 0x50) >> 0x10) *
                (int)(short)((uint)(&PTR_0008ff98)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x4c) *
              (int)(short)(&PTR_DAT_0008ff94)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x4c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff94)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x48) *
              (int)(short)(&PTR_DAT_0008ff90)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x48) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff90)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x44) *
              (int)(short)(&PTR_LAB_0000ff38_1_0008ff8c)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x44) >> 0x10) *
              (int)(short)((uint)(&PTR_LAB_0000ff38_1_0008ff8c)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x40) *
              (int)(short)(&PTR_DAT_0008ff88)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x40) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff88)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x3c) *
              (int)(short)(&PTR_DAT_0008ff84)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x3c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff84)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x38) *
              (int)(short)(&PTR_DAT_0008ff80)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x38) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff80)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x34) *
              (int)(short)(&PTR_DAT_0008ff7c)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x34) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff7c)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x30) *
              (int)(short)(&PTR_LAB_0000f726_2_0008ff78)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x30) >> 0x10) *
              (int)(short)((uint)(&PTR_LAB_0000f726_2_0008ff78)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x2c) *
              (int)(short)(&PTR_DAT_0008ff74)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x2c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff74)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x28) *
              (int)(short)(&PTR_DAT_0008ff70)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x28) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff70)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x24) *
              (int)(short)(&PTR_DAT_0008ff6c)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x24) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff6c)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x20) *
              (int)(short)(&PTR_DAT_0008ff68)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x20) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff68)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x1c) *
              (int)(short)(&PTR_DAT_0008ff64)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x1c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff64)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x18) *
              (int)(short)(&PTR_DAT_0008ff60)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x18) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff60)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x14) *
              (int)(short)(&PTR_DAT_0008ff5c)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x14) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff5c)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0x10) *
              (int)(short)(&PTR_DAT_0008ff58)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0x10) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff58)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 0xc) *
              (int)(short)(&PTR_DAT_0008ff54)[uVar6 * 0x18] +
              (int)(short)((uint)*(undefined4 *)(iVar5 + 0xc) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008ff54)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 8) * (int)(short)(&PTR_DAT_0008ff50)[uVar6 * 0x18]
              + (int)(short)((uint)*(undefined4 *)(iVar5 + 8) >> 0x10) *
                (int)(short)((uint)(&PTR_DAT_0008ff50)[uVar6 * 0x18] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar5 + 4) * (int)(short)(&PTR_DAT_0008ff4c)[uVar6 * 0x18]
              + (int)(short)((uint)*(undefined4 *)(iVar5 + 4) >> 0x10) *
                (int)(short)((uint)(&PTR_DAT_0008ff4c)[uVar6 * 0x18] >> 0x10) +
              (int)(short)uVar4 * (int)(short)puVar8 +
              (int)(short)((uint)uVar4 >> 0x10) * (int)(short)((uint)puVar8 >> 0x10);
      lVar2 = (longlong)iVar5 * 0x3ee61bc6;
      lVar3 = lVar2 + *param_1;
      uVar6 = (uint)lVar3 >> 0x1e | (int)((ulonglong)lVar3 >> 0x20) * 4;
      uVar1 = (longlong)iVar5 * -0x7dcc378e + param_1[1];
      *param_1 = (longlong)(int)uVar6 * 0x7dc75ddb +
                 ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
      param_1[1] = (longlong)(int)uVar6 * -0x3dd11141 + lVar2;
      *param_3 = (short)(uVar6 + 0x8000 >> 0x10);
      if (param_4 * 5 <= (int)uVar9) break;
      puVar8 = (&PTR_DAT_0008ff48)[(uVar9 & 3) * 0x18];
      uVar6 = uVar9 & 3;
      param_3 = param_3 + 1;
    }
  }
  return;
}



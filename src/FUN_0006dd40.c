/*
 * Function: FUN_0006dd40
 * Entry:    0006dd40
 * Prototype: undefined __stdcall FUN_0006dd40(longlong * param_1, int param_2, undefined2 * param_3, int param_4)
 */


void FUN_0006dd40(longlong *param_1,int param_2,undefined2 *param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined2 *local_2c;
  
  if (0 < param_4) {
    uVar8 = 0;
    uVar7 = 0xd60000;
    uVar5 = 0;
    local_2c = param_3;
    while( true ) {
      iVar4 = ((int)uVar8 >> 4) + -5;
      uVar6 = *(undefined4 *)(param_2 + iVar4 * 4);
      iVar4 = param_2 + iVar4 * 4;
      uVar8 = uVar8 + 5;
      iVar4 = (int)(short)*(undefined4 *)(iVar4 + 0x14) * (int)(short)(&DAT_0008f85c)[uVar5 * 6] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 0x14) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f85c)[uVar5 * 6] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x10) * (int)(short)(&DAT_0008f858)[uVar5 * 6] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 0x10) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f858)[uVar5 * 6] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0xc) * (int)(short)(&DAT_0008f854)[uVar5 * 6] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 0xc) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f854)[uVar5 * 6] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 8) * (int)(short)(&DAT_0008f850)[uVar5 * 6] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 8) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f850)[uVar5 * 6] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 4) * (int)(short)(&DAT_0008f84c)[uVar5 * 6] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 4) >> 0x10) *
              (int)(short)((uint)(&DAT_0008f84c)[uVar5 * 6] >> 0x10) +
              (int)(short)uVar6 * (int)(short)uVar7 +
              (int)(short)((uint)uVar6 >> 0x10) * (int)(short)((uint)uVar7 >> 0x10);
      lVar2 = (longlong)iVar4 * 0x3ee61bc6;
      lVar3 = lVar2 + *param_1;
      uVar5 = (uint)lVar3 >> 0x1e | (int)((ulonglong)lVar3 >> 0x20) * 4;
      uVar1 = (longlong)iVar4 * -0x7dcc378e + param_1[1];
      *param_1 = (longlong)(int)uVar5 * 0x7dc75ddb +
                 ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
      param_1[1] = (longlong)(int)uVar5 * -0x3dd11141 + lVar2;
      *local_2c = (short)(uVar5 + 0x8000 >> 0x10);
      if (param_4 * 5 <= (int)uVar8) break;
      uVar7 = *(undefined4 *)(&UNK_0008f848 + (uVar8 & 0xf) * 0x18);
      uVar5 = uVar8 & 0xf;
      local_2c = local_2c + 1;
    }
  }
  return;
}



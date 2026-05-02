/*
 * Function: FUN_0006d804
 * Entry:    0006d804
 * Prototype: undefined __stdcall FUN_0006d804(longlong * param_1, int param_2, undefined2 * param_3, int param_4)
 */


void FUN_0006d804(longlong *param_1,int param_2,undefined2 *param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if (0 < param_4) {
    uVar9 = 0;
    uVar5 = 0;
    uVar8 = 0xfff30000;
    while( true ) {
      iVar6 = ((int)uVar9 >> 3) + -0x1e;
      iVar4 = param_2 + iVar6 * 4;
      uVar7 = *(undefined4 *)(param_2 + iVar6 * 4);
      uVar9 = uVar9 + 0xf;
      iVar4 = (int)(short)*(undefined4 *)(iVar4 + 0x78) * (int)(short)(&DAT_00090140)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x78) >> 0x10) *
                (int)(short)((uint)(&DAT_00090140)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x74) * (int)(short)(&DAT_0009013c)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x74) >> 0x10) *
                (int)(short)((uint)(&DAT_0009013c)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x70) * (int)(short)(&DAT_00090138)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x70) >> 0x10) *
                (int)(short)((uint)(&DAT_00090138)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x6c) * (int)(short)(&DAT_00090134)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x6c) >> 0x10) *
                (int)(short)((uint)(&DAT_00090134)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x68) * (int)(short)(&DAT_00090130)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x68) >> 0x10) *
                (int)(short)((uint)(&DAT_00090130)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 100) * (int)(short)(&DAT_0009012c)[uVar5 * 0x20] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 100) >> 0x10) *
              (int)(short)((uint)(&DAT_0009012c)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x60) * (int)(short)(&DAT_00090128)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x60) >> 0x10) *
                (int)(short)((uint)(&DAT_00090128)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x5c) * (int)(short)(&DAT_00090124)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x5c) >> 0x10) *
                (int)(short)((uint)(&DAT_00090124)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x58) * (int)(short)(&DAT_00090120)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x58) >> 0x10) *
                (int)(short)((uint)(&DAT_00090120)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x54) * (int)(short)(&DAT_0009011c)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x54) >> 0x10) *
                (int)(short)((uint)(&DAT_0009011c)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x50) * (int)(short)(&DAT_00090118)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x50) >> 0x10) *
                (int)(short)((uint)(&DAT_00090118)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x4c) * (int)(short)(&DAT_00090114)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x4c) >> 0x10) *
                (int)(short)((uint)(&DAT_00090114)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x48) * (int)(short)(&DAT_00090110)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x48) >> 0x10) *
                (int)(short)((uint)(&DAT_00090110)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x44) * (int)(short)(&DAT_0009010c)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x44) >> 0x10) *
                (int)(short)((uint)(&DAT_0009010c)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x40) * (int)(short)(&DAT_00090108)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x40) >> 0x10) *
                (int)(short)((uint)(&DAT_00090108)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x3c) * (int)(short)(&DAT_00090104)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x3c) >> 0x10) *
                (int)(short)((uint)(&DAT_00090104)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x38) * (int)(short)(&DAT_00090100)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x38) >> 0x10) *
                (int)(short)((uint)(&DAT_00090100)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x34) * (int)(short)(&DAT_000900fc)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x34) >> 0x10) *
                (int)(short)((uint)(&DAT_000900fc)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x30) * (int)(short)(&DAT_000900f8)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x30) >> 0x10) *
                (int)(short)((uint)(&DAT_000900f8)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x2c) * (int)(short)(&DAT_000900f4)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x2c) >> 0x10) *
                (int)(short)((uint)(&DAT_000900f4)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x28) * (int)(short)(&DAT_000900f0)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x28) >> 0x10) *
                (int)(short)((uint)(&DAT_000900f0)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x24) * (int)(short)(&DAT_000900ec)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x24) >> 0x10) *
                (int)(short)((uint)(&DAT_000900ec)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x20) * (int)(short)(&DAT_000900e8)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x20) >> 0x10) *
                (int)(short)((uint)(&DAT_000900e8)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x1c) * (int)(short)(&DAT_000900e4)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x1c) >> 0x10) *
                (int)(short)((uint)(&DAT_000900e4)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x18) * (int)(short)(&DAT_000900e0)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x18) >> 0x10) *
                (int)(short)((uint)(&DAT_000900e0)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x14) * (int)(short)(&DAT_000900dc)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x14) >> 0x10) *
                (int)(short)((uint)(&DAT_000900dc)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0x10) * (int)(short)(&DAT_000900d8)[uVar5 * 0x20]
              + (int)(short)((uint)*(undefined4 *)(iVar4 + 0x10) >> 0x10) *
                (int)(short)((uint)(&DAT_000900d8)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 0xc) * (int)(short)(&DAT_000900d4)[uVar5 * 0x20] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 0xc) >> 0x10) *
              (int)(short)((uint)(&DAT_000900d4)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 8) * (int)(short)(&DAT_000900d0)[uVar5 * 0x20] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 8) >> 0x10) *
              (int)(short)((uint)(&DAT_000900d0)[uVar5 * 0x20] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar4 + 4) * (int)(short)(&DAT_000900cc)[uVar5 * 0x20] +
              (int)(short)((uint)*(undefined4 *)(iVar4 + 4) >> 0x10) *
              (int)(short)((uint)(&DAT_000900cc)[uVar5 * 0x20] >> 0x10) +
              (int)(short)uVar7 * (int)(short)uVar8 +
              (int)(short)((uint)uVar7 >> 0x10) * (int)(short)((uint)uVar8 >> 0x10);
      lVar2 = (longlong)iVar4 * 0x3ee61bc6;
      lVar3 = lVar2 + *param_1;
      uVar5 = (uint)lVar3 >> 0x1e | (int)((ulonglong)lVar3 >> 0x20) * 4;
      uVar1 = (longlong)iVar4 * -0x7dcc378e + param_1[1];
      *param_1 = (longlong)(int)uVar5 * 0x7dc75ddb +
                 ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
      param_1[1] = (longlong)(int)uVar5 * -0x3dd11141 + lVar2;
      *param_3 = (short)(uVar5 + 0x8000 >> 0x10);
      if (param_4 * 0xf <= (int)uVar9) break;
      uVar5 = uVar9 & 7;
      uVar8 = *(undefined4 *)(&UNK_000900c8 + uVar5 * 0x80);
      param_3 = param_3 + 1;
    }
  }
  return;
}



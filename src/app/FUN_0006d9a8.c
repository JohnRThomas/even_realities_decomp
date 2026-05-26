/*
 * Function: FUN_0006d9a8
 * Entry:    0006d9a8
 * Prototype: undefined __stdcall FUN_0006d9a8(longlong * param_1, int param_2, undefined2 * param_3, int param_4)
 */


void FUN_0006d9a8(longlong *param_1,int param_2,undefined2 *param_3,int param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined2 *local_2c;
  
  if (0 < param_4) {
    uVar9 = 0;
    puVar8 = &DAT_ffce0000;
    uVar7 = 0;
    local_2c = param_3;
    while( true ) {
      iVar4 = ((int)uVar9 >> 4) + -0xf;
      iVar6 = param_2 + iVar4 * 4;
      uVar5 = *(undefined4 *)(param_2 + iVar4 * 4);
      uVar9 = uVar9 + 0xf;
      iVar4 = (int)(short)*(undefined4 *)(iVar6 + 0x3c) * (int)(short)(&PTR_0008fb84)[uVar7 * 0x10]
              + (int)(short)((uint)*(undefined4 *)(iVar6 + 0x3c) >> 0x10) *
                (int)(short)((uint)(&PTR_0008fb84)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x38) *
              (int)(short)(&PTR_DAT_0008fb80)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x38) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb80)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x34) *
              (int)(short)(&PTR_DAT_0008fb7c)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x34) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb7c)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x30) *
              (int)(short)(&PTR_DAT_0008fb78)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x30) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb78)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x2c) *
              (int)(short)(&PTR_DAT_0008fb74)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x2c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb74)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x28) *
              (int)(short)(&PTR_DAT_0008fb70)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x28) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb70)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x24) *
              (int)(short)(&PTR_DAT_0008fb6c)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x24) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb6c)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x20) *
              (int)(short)(&PTR_DAT_0008fb68)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x20) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb68)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x1c) *
              (int)(short)(&PTR_DAT_0008fb64)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x1c) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb64)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x18) *
              (int)(short)(&PTR_DAT_0008fb60)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x18) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb60)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x14) *
              (int)(short)(&PTR_DAT_0008fb5c)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x14) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb5c)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0x10) *
              (int)(short)(&PTR_DAT_0008fb58)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0x10) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb58)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 0xc) *
              (int)(short)(&PTR_DAT_0008fb54)[uVar7 * 0x10] +
              (int)(short)((uint)*(undefined4 *)(iVar6 + 0xc) >> 0x10) *
              (int)(short)((uint)(&PTR_DAT_0008fb54)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 8) * (int)(short)(&PTR_DAT_0008fb50)[uVar7 * 0x10]
              + (int)(short)((uint)*(undefined4 *)(iVar6 + 8) >> 0x10) *
                (int)(short)((uint)(&PTR_DAT_0008fb50)[uVar7 * 0x10] >> 0x10) +
              (int)(short)*(undefined4 *)(iVar6 + 4) * (int)(short)(&PTR_DAT_0008fb4c)[uVar7 * 0x10]
              + (int)(short)((uint)*(undefined4 *)(iVar6 + 4) >> 0x10) *
                (int)(short)((uint)(&PTR_DAT_0008fb4c)[uVar7 * 0x10] >> 0x10) +
              (int)(short)uVar5 * (int)(short)puVar8 +
              (int)(short)((uint)uVar5 >> 0x10) * (int)(short)((uint)puVar8 >> 0x10);
      lVar2 = (longlong)iVar4 * 0x3ee61bc6;
      lVar3 = lVar2 + *param_1;
      uVar7 = (uint)lVar3 >> 0x1e | (int)((ulonglong)lVar3 >> 0x20) * 4;
      uVar1 = (longlong)iVar4 * -0x7dcc378e + param_1[1];
      *param_1 = (longlong)(int)uVar7 * 0x7dc75ddb +
                 ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
      param_1[1] = (longlong)(int)uVar7 * -0x3dd11141 + lVar2;
      *local_2c = (short)(uVar7 + 0x8000 >> 0x10);
      if (param_4 * 0xf <= (int)uVar9) break;
      puVar8 = (&PTR_DAT_0008fb48)[(uVar9 & 0xf) * 0x10];
      uVar7 = uVar9 & 0xf;
      local_2c = local_2c + 1;
    }
  }
  return;
}



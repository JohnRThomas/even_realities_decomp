/*
 * Function: FUN_01016e28
 * Entry:    01016e28
 * Prototype: undefined __stdcall FUN_01016e28(void)
 */


void FUN_01016e28(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  DAT_21001038 = 0;
  if (((DAT_21000fe8 != '\0') || (lVar5 = CONCAT44(DAT_21001034,DAT_21001030), DAT_2100100d != '\0')
      ) && (lVar5 = CONCAT44(DAT_21001034,DAT_21001030),
           DAT_21001034 != 0x7fffffff || DAT_21001030 != 0xffffffff)) {
    lVar4 = thunk_FUN_01025834();
    lVar5 = CONCAT44(DAT_21001034,DAT_21001030);
    uVar2 = (uint)((ulonglong)lVar4 >> 0x20);
    if (DAT_21001034 < uVar2 || uVar2 - DAT_21001034 < (uint)(DAT_21001030 <= (uint)lVar4)) {
      uVar1 = FUN_0100cf38();
      uVar2 = (uint)uVar1;
      lVar5 = thunk_FUN_01025834();
      iVar3 = (uint)(uVar2 * 0x20 < uVar2) * -0x200 + (uint)CARRY4(uVar2 * 0x3e00,uVar2);
      lVar5 = lVar5 + CONCAT44((((iVar3 * 0x40 | uVar2 * 0x3e01 >> 0x1a) - iVar3) -
                               (uint)(uVar2 * 0xf8040 < uVar2 * 0x3e01)) +
                               (uint)CARRY4(uVar2 * 999999,uVar2),uVar2 * 1000000);
      DAT_21001030 = (uint)lVar5;
      DAT_21001034 = (uint)((ulonglong)lVar5 >> 0x20);
      if (DAT_2100100d != '\0') {
        FUN_0100d370(1);
        lVar5 = CONCAT44(DAT_21001034,DAT_21001030);
      }
    }
  }
  DAT_21001034 = (uint)((ulonglong)lVar5 >> 0x20);
  DAT_21001030 = (uint)lVar5;
  DAT_21001000 = 2;
  return;
}



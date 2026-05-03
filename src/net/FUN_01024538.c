/*
 * Function: FUN_01024538
 * Entry:    01024538
 * Prototype: uint __stdcall FUN_01024538(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_01024538(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  undefined4 extraout_r3;
  int extraout_r3_00;
  int iVar2;
  undefined4 extraout_r3_01;
  longlong lVar3;
  byte local_1d;
  uint uStack_1c;
  uint local_18;
  int iStack_14;
  
  uVar1 = (uint)DAT_2100173a;
  if (uVar1 != 0x20) {
    uVar1 = DAT_210016f8;
    iVar2 = DAT_210016fc;
    if (DAT_210016fc == -1 && DAT_210016f8 == 0xffffffff) {
      iVar2 = (uint)DAT_2100173a * 0x20;
      lVar3 = FUN_01024c5c(*(uint *)(&DAT_210017c8 + iVar2),*(uint *)(&DAT_210017cc + iVar2));
      uVar1 = (uint)*(ushort *)(&DAT_210017d6 + iVar2) + (uint)(byte)(&DAT_210017d4)[iVar2] + 1;
      lVar3 = lVar3 + CONCAT44((uint)CARRY4((uint)*(ushort *)(&DAT_210017d6 + iVar2),
                                            (uint)(byte)(&DAT_210017d4)[iVar2]) +
                               (uint)CARRY4(uVar1,param_1),uVar1 + param_1);
      uVar1 = FUN_01024d24((uint)lVar3,(uint)((ulonglong)lVar3 >> 0x20),&uStack_1c,(int *)&local_18,
                           (char *)&local_1d);
      DAT_210016f8 = (0xf < local_1d) + local_18;
      DAT_210016fc = iStack_14 + (uint)CARRY4((uint)(0xf < local_1d),local_18);
      if ((DAT_21001727 == 0) ||
         (uVar1 = FUN_010258d0(5,(uint)DAT_21001727,DAT_210016f8), uVar1 != 0)) {
        return uVar1;
      }
      FUN_01025edc(0x70,0xb5b,extraout_r2,extraout_r3);
      uVar1 = extraout_r2_00;
      iVar2 = extraout_r3_00;
    }
    FUN_01025edc(0x70,0xb46,uVar1,iVar2);
    uVar1 = extraout_r2_01;
    param_4 = extraout_r3_01;
  }
  FUN_01025edc(0x70,0xb45,uVar1,param_4);
  uVar1 = Peripherals::RTC0_NS.COUNTER;
  return uVar1;
}



/*
 * Function: FUN_01024500
 * Entry:    01024500
 * Prototype: uint __stdcall FUN_01024500(void)
 */


uint FUN_01024500(void)

{
  uint uVar1;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int extraout_r3_01;
  int iVar2;
  undefined4 extraout_r3_02;
  undefined4 uVar3;
  int unaff_r6;
  longlong lVar4;
  byte bStack_25;
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  
  if (DAT_2100173a != 0x20) {
                    /* WARNING: Could not emulate address calculation at 0x01024520 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])
                      ((&DAT_210017c4)[(uint)DAT_2100173a * 8],4);
    return uVar1;
  }
  FUN_01025edc(0x70,0x8af,0x20,&DAT_210016f0);
  uVar1 = (uint)DAT_2100173a;
  uVar3 = extraout_r3;
  if (uVar1 != 0x20) {
    uVar1 = DAT_210016f8;
    iVar2 = DAT_210016fc;
    if (DAT_210016fc == -1 && DAT_210016f8 == 0xffffffff) {
      iVar2 = (uint)DAT_2100173a * 0x20;
      lVar4 = FUN_01024c5c(*(uint *)(&DAT_210017c8 + iVar2),*(uint *)(&DAT_210017cc + iVar2));
      uVar1 = (uint)*(ushort *)(&DAT_210017d6 + iVar2) + (uint)(byte)(&DAT_210017d4)[iVar2] + 1;
      lVar4 = lVar4 + CONCAT44((uint)CARRY4((uint)*(ushort *)(&DAT_210017d6 + iVar2),
                                            (uint)(byte)(&DAT_210017d4)[iVar2]) +
                               (uint)CARRY4(uVar1,unaff_r6 >> 0x1b),uVar1 + (unaff_r6 >> 0x1b));
      uVar1 = FUN_01024d24((uint)lVar4,(uint)((ulonglong)lVar4 >> 0x20),&uStack_24,(int *)&uStack_20
                           ,(char *)&bStack_25);
      DAT_210016f8 = (0xf < bStack_25) + uStack_20;
      DAT_210016fc = iStack_1c + (uint)CARRY4((uint)(0xf < bStack_25),uStack_20);
      if ((DAT_21001727 == 0) ||
         (uVar1 = FUN_010258d0(5,(uint)DAT_21001727,DAT_210016f8), uVar1 != 0)) {
        return uVar1;
      }
      FUN_01025edc(0x70,0xb5b,extraout_r2,extraout_r3_00);
      uVar1 = extraout_r2_00;
      iVar2 = extraout_r3_01;
    }
    FUN_01025edc(0x70,0xb46,uVar1,iVar2);
    uVar1 = extraout_r2_01;
    uVar3 = extraout_r3_02;
  }
  FUN_01025edc(0x70,0xb45,uVar1,uVar3);
  uVar1 = Peripherals::RTC0_NS.COUNTER;
  return uVar1;
}



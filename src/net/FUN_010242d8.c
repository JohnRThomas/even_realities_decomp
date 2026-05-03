/*
 * Function: FUN_010242d8
 * Entry:    010242d8
 * Prototype: uint __stdcall FUN_010242d8(uint param_1, undefined4 param_2, undefined4 param_3)
 */


uint FUN_010242d8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  uint extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  uint extraout_r2_08;
  uint extraout_r2_09;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  int extraout_r3_08;
  int iVar7;
  undefined4 extraout_r3_09;
  int unaff_r6;
  longlong lVar8;
  longlong lVar9;
  byte bStack_35;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  undefined4 *puStack_28;
  
  lVar8 = CONCAT44(DAT_21001734,param_1);
  lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
  switch(param_1) {
  case 0:
    if (DAT_21001734 == -1 && DAT_21001730 == -1) goto LAB_01024478;
    while( true ) {
      DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
      DAT_21001730 = (int)lVar9;
      if (DAT_2100170e == 0) break;
      bVar1 = FUN_010252d0();
      lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
      if (bVar1 != 0) break;
      FUN_01025edc(0x70,0x850,extraout_r2_02,extraout_r3_02);
LAB_01024478:
      FUN_01024ee4();
      lVar9 = FUN_01025884();
    }
    DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
    DAT_21001730 = (int)lVar9;
    if (DAT_2100173a == 0x20) {
      FUN_01022304();
      lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
    }
    DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
    DAT_21001730 = (int)lVar9;
    DAT_21001727 = 0xff;
    uVar4 = DAT_210016f8;
    if (DAT_210016fc == -1 && DAT_210016f8 == 0xffffffff) {
LAB_01024374:
      DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
      DAT_21001730 = (int)lVar9;
      if (DAT_21001711 == '\x01') {
        FUN_0102561c((DAT_21001700 - 1U) + DAT_21001708,
                     DAT_21001704 + -1 + (uint)(DAT_21001700 != 0) +
                     (uint)CARRY4(DAT_21001700 - 1U,DAT_21001708),uVar4);
        lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
      }
      DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
      DAT_21001730 = (int)lVar9;
                    /* WARNING: Could not recover jumptable at 0x0102439e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])
                        ((&DAT_210017c4)[(uint)DAT_2100173a * 8],1);
      return uVar4;
    }
    uVar5 = FUN_010258d0(5,0,DAT_210016f8);
    lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
    uVar4 = extraout_r2;
    uVar3 = extraout_r3;
    if (uVar5 != 0) goto LAB_01024374;
    break;
  case 1:
    if (DAT_2100173a == 0x20) {
      FUN_01022304();
    }
    DAT_21001726 = 1;
    bVar1 = FUN_010252d0();
    lVar9 = CONCAT44(DAT_21001734,DAT_21001730);
    if (bVar1 != 0) {
      if (DAT_21001734 == -1 && DAT_21001730 == -1) {
        FUN_01024ee4();
        lVar9 = FUN_01025884();
      }
      DAT_21001734 = (int)((ulonglong)lVar9 >> 0x20);
      DAT_21001730 = (int)lVar9;
                    /* WARNING: Could not recover jumptable at 0x010243ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])
                        ((&DAT_210017c4)[(uint)DAT_2100173a * 8],0);
      return uVar4;
    }
    FUN_01025edc(0x70,0x889,extraout_r2_00,extraout_r3_00);
    uVar4 = extraout_r2_04;
    uVar3 = extraout_r3_03;
    break;
  case 2:
    FUN_01024e0c();
    if ((DAT_2100170e == 0) ||
       (bVar1 = FUN_010252d0(), uVar3 = extraout_r2_01, uVar6 = extraout_r3_01, bVar1 != 0)) {
      bVar2 = FUN_01024e64();
      if (bVar2 == 0) {
        return 0;
      }
      DAT_21001719 = 1;
      return (uint)bVar2;
    }
    goto LAB_010244f0;
  case 3:
    *DAT_21001bc4 = 1;
  default:
    return param_1;
  case 5:
    if (DAT_21001738 != '\0') {
      if (DAT_21001734 == -1 && DAT_21001730 == -1) {
        FUN_01024ee4();
        lVar8 = FUN_01025884();
        DAT_21001730 = (int)lVar8;
      }
      DAT_21001734 = (int)((ulonglong)lVar8 >> 0x20);
      DAT_21001738 = 0;
      return (uint)lVar8;
    }
    if (DAT_2100173a == 0x20) {
      FUN_01022304();
      param_3 = extraout_r2_03;
    }
    DAT_210016f8 = 0xffffffff;
    DAT_210016fc = -1;
    uVar3 = 0;
    if (DAT_21001727 != 0) {
      uVar6 = 6;
      uVar3 = (&DAT_210017c4)[(uint)DAT_2100173a * 8];
      goto LAB_0102431c;
    }
    goto LAB_010244e6;
  case 6:
    if (DAT_2100173a == 0x20) {
      FUN_01022304();
    }
    uVar6 = 5;
    uVar3 = (&DAT_210017c4)[(uint)DAT_2100173a * 8];
LAB_0102431c:
                    /* WARNING: Could not recover jumptable at 0x01024326. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])(uVar3,uVar6);
    return uVar4;
  }
  FUN_01025edc(0x70,0x858,uVar4,uVar3);
  param_3 = extraout_r2_05;
  uVar3 = extraout_r3_04;
LAB_010244e6:
  FUN_01025edc(0x70,0x871,param_3,uVar3);
  uVar3 = extraout_r2_06;
  uVar6 = extraout_r3_05;
LAB_010244f0:
  FUN_01025edc(0x70,0x894,uVar3,uVar6);
  if (DAT_2100173a != 0x20) {
                    /* WARNING: Could not emulate address calculation at 0x01024520 */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])
                      ((&DAT_210017c4)[(uint)DAT_2100173a * 8],4);
    return uVar4;
  }
  FUN_01025edc(0x70,0x8af,0x20,&DAT_210016f0);
  puStack_28 = &DAT_210016f0;
  uVar4 = (uint)DAT_2100173a;
  uVar3 = extraout_r3_06;
  if (uVar4 != 0x20) {
    uVar4 = DAT_210016f8;
    iVar7 = DAT_210016fc;
    if (DAT_210016fc == -1 && DAT_210016f8 == 0xffffffff) {
      iVar7 = (uint)DAT_2100173a * 0x20;
      lVar9 = FUN_01024c5c(*(uint *)(&DAT_210017c8 + iVar7),*(uint *)(&DAT_210017cc + iVar7));
      uVar4 = (uint)*(ushort *)(&DAT_210017d6 + iVar7) + (uint)(byte)(&DAT_210017d4)[iVar7] + 1;
      lVar9 = lVar9 + CONCAT44((uint)CARRY4((uint)*(ushort *)(&DAT_210017d6 + iVar7),
                                            (uint)(byte)(&DAT_210017d4)[iVar7]) +
                               (uint)CARRY4(uVar4,unaff_r6 >> 0x1b),uVar4 + (unaff_r6 >> 0x1b));
      uVar4 = FUN_01024d24((uint)lVar9,(uint)((ulonglong)lVar9 >> 0x20),&uStack_34,(int *)&uStack_30
                           ,(char *)&bStack_35);
      DAT_210016f8 = (0xf < bStack_35) + uStack_30;
      DAT_210016fc = iStack_2c + (uint)CARRY4((uint)(0xf < bStack_35),uStack_30);
      if ((DAT_21001727 == 0) ||
         (uVar4 = FUN_010258d0(5,(uint)DAT_21001727,DAT_210016f8), uVar4 != 0)) {
        return uVar4;
      }
      FUN_01025edc(0x70,0xb5b,extraout_r2_07,extraout_r3_07);
      uVar4 = extraout_r2_08;
      iVar7 = extraout_r3_08;
    }
    FUN_01025edc(0x70,0xb46,uVar4,iVar7);
    uVar4 = extraout_r2_09;
    uVar3 = extraout_r3_09;
  }
  FUN_01025edc(0x70,0xb45,uVar4,uVar3);
  uVar4 = Peripherals::RTC0_NS.COUNTER;
  return uVar4;
}



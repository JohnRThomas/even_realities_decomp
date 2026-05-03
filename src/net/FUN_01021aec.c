/*
 * Function: FUN_01021aec
 * Entry:    01021aec
 * Prototype: uint __stdcall FUN_01021aec(uint param_1, undefined4 * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01021aec(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  short *psVar6;
  undefined2 *puVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 uVar9;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  uint extraout_r3_06;
  undefined4 uVar10;
  undefined4 extraout_r3_07;
  uint extraout_r3_08;
  undefined4 extraout_r3_09;
  uint unaff_r5;
  undefined4 *puVar11;
  char unaff_r8;
  char cVar12;
  undefined8 uVar13;
  byte local_35;
  char local_34;
  undefined1 local_33;
  undefined1 local_32;
  TIMER0_NS *local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  
  DAT_21001625 = DAT_21001625 | 2;
  if (param_1 == 0) {
    local_32 = 0;
    local_34 = '\x04';
    uVar3 = FUN_01024688();
    local_33 = 0xff;
    if (1 < uVar3) {
      local_33 = 0;
    }
    uVar13 = FUN_010263b0();
    uVar9 = extraout_r2;
    uVar10 = extraout_r3;
    if ((int)uVar13 == 0) {
      DAT_21001635 = 1;
      FUN_01021200(param_2,(int)((ulonglong)uVar13 >> 0x20),extraout_r2,extraout_r3);
      uVar3 = (uint)DAT_2100160a;
      Peripherals::RADIO_NS.FREQUENCY = (uint)(byte)(&DAT_0103c490)[uVar3];
      Peripherals::RADIO_NS.DATAWHITEIV = uVar3 & 0x7f;
      FUN_01021ed4((uint)param_2,uVar3,(int)DAT_21001609,(undefined2 *)&local_34);
      FUN_01021da8((int)local_34);
      iVar4 = FUN_010220fc();
      uVar8 = extraout_r2_00;
      uVar9 = extraout_r3_00;
      puVar11 = param_2;
      if (iVar4 == 0) {
        DAT_210015f9 = '\x01';
        if ((char)DAT_210015f7 == '\x01') {
          uVar3 = Peripherals::RADIO_NS.SHORTS;
          Peripherals::RADIO_NS.SHORTS = uVar3 | 8;
        }
        puVar5 = &DAT_10624dd3;
        Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0x8000000a;
        unaff_r5 = ((ushort)(&DAT_0103c570)[(int)param_2] + 500) / 1000;
        if ((char)DAT_210015f7 != '\0') goto LAB_01021c84;
        goto LAB_01021bb4;
      }
      goto LAB_01021d7c;
    }
  }
  else {
    cVar12 = '\x02';
    local_32 = 0;
    local_34 = '\x02';
    uVar3 = FUN_01024688();
    local_33 = 0xff;
    if (1 < uVar3) {
      local_33 = 0;
    }
    uVar13 = FUN_010263b0();
    uVar8 = (undefined4)((ulonglong)uVar13 >> 0x20);
    unaff_r5 = (uint)uVar13;
    uVar9 = extraout_r2_03;
    uVar10 = extraout_r3_03;
    unaff_r8 = '\x02';
    if (unaff_r5 == 0) {
      DAT_21001635 = 1;
      puVar5 = (undefined1 *)0x0;
      if (param_1 == 1) goto LAB_01021d3e;
      goto LAB_01021c7e;
    }
  }
  cVar12 = unaff_r8;
  FUN_01009500(0x3e,0xa69,uVar9,uVar10);
  while( true ) {
    DAT_21000034 = 0x28;
    DAT_21000030 = param_1;
    iVar4 = FUN_010220c0();
    puVar11 = param_2;
    if (iVar4 + 1U < 2) break;
    FUN_01009500(0x3e,0x6e9,extraout_r2_07,extraout_r3_07);
    uVar8 = extraout_r1_00;
    uVar9 = extraout_r2_08;
LAB_01021d3e:
    puVar5 = (undefined1 *)FUN_01020968((int)param_2,uVar8,uVar9);
    if ((char)DAT_210015f7 == '\x01') {
      uVar3 = Peripherals::RADIO_NS.SHORTS;
      Peripherals::RADIO_NS.SHORTS = uVar3 | 4;
    }
    unaff_r5 = 0x29;
    Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0x8000000a;
    DAT_210015f9 = cVar12;
LAB_01021c7e:
    if ((char)DAT_210015f7 == '\0') {
LAB_01021bb4:
      DAT_21001625 = DAT_21001625 | 2;
LAB_01021bc0:
      uVar13 = FUN_01020908(puVar5);
      bVar2 = FUN_010242c4((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),extraout_r2_01,
                           extraout_r3_01);
      puVar11 = param_2;
    }
    else {
LAB_01021c84:
      if ((char)DAT_210015f7 != '\x01') goto LAB_01021bc0;
      DAT_21001625 = DAT_21001625 | 4;
      uVar13 = FUN_01020908(puVar5);
      bVar2 = FUN_010242c4((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),extraout_r2_04,
                           extraout_r3_04);
      puVar11 = param_2;
    }
    if (bVar2 != 0) {
      FUN_01020d00();
      return 0;
    }
    local_2c = src/*FUN_010259e8();
    local_33 = param_1 == 0;
    local_30 = &Peripherals::TIMER0_NS;
    local_28 = (&Peripherals::TIMER0_NS.CC_0_)[local_2c];
    local_34 = bVar2;
    if (param_1 != 0) {
      local_24 = 0x28;
      FUN_0102649c((int)&local_34,extraout_r1,0,0x28);
      uVar3 = (uint)DAT_2100160c;
      if (0x95 < uVar3) {
        uVar8 = extraout_r2_05;
        if (param_1 != 1) goto LAB_01021d72;
        DAT_21000034 = 0x29;
        DAT_21000030 = (uint)bVar2;
        iVar4 = FUN_010220cc();
        if (1 < iVar4 + 1U) {
          FUN_01009500(0x3e,0x6f6,extraout_r2_06,extraout_r3_05);
          uVar3 = extraout_r3_06;
          goto LAB_01021ce0;
        }
      }
      break;
    }
    cVar12 = -0x70;
    param_2 = (undefined4 *)(&DAT_0103c490 + (int)puVar11 * 2);
    local_24 = ((ushort)(&DAT_0103c570)[(int)puVar11] + 600) / 1000;
    FUN_0102649c((int)&local_34,extraout_r1,
                 ((ushort)(&DAT_0103c570)[(int)puVar11] + 600) * 0x10624dd3,local_24);
    puVar11 = param_2;
    if (DAT_2100160c < 0x96) break;
  }
  iVar4 = FUN_010263c8();
  if (iVar4 == 0) {
    uVar3 = (uint)local_35;
    if (DAT_210015f9 == '\x01') {
      iVar4 = (uVar3 ^ 4) << 0x1d;
    }
    else {
      if (DAT_210015f9 != '\x02') {
        DAT_21001636 = 0;
        return unaff_r5;
      }
LAB_01021ce0:
      iVar4 = (uVar3 ^ 2) << 0x1e;
    }
    DAT_21001636 = (undefined1)-(iVar4 >> 0x1f);
    if (-(iVar4 >> 0x1f) == 0) {
      return unaff_r5;
    }
    Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
    Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
    Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    return unaff_r5;
  }
  FUN_01009500(0x3e,0xa8b,extraout_r2_02,extraout_r3_02);
  uVar8 = extraout_r2_09;
  uVar3 = extraout_r3_08;
LAB_01021d72:
  FUN_01009500(0x3e,0x6fa,uVar8,uVar3);
  uVar8 = extraout_r2_10;
  uVar9 = extraout_r3_09;
LAB_01021d7c:
  FUN_01009500(0x3e,0x57e,uVar8,uVar9);
  psVar6 = (short *)((int)param_1 >> 0x17);
  DAT_210015f0 = &DAT_210015f0;
  _DAT_210015f4 = puVar11;
  *psVar6 = (short)((int)param_1 >> 0x17);
  piVar1 = _FUN_010220e4;
  puVar7 = (undefined2 *)((int)psVar6 >> ((uint)psVar6 & 0xff));
  *puVar7 = (short)puVar7;
  *piVar1 = (int)psVar6 << 4;
  piVar1[1] = (int)&DAT_210015f0;
  piVar1[2] = (int)piVar1;
  if ((int)piVar1 < 1) {
    Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 0;
    Peripherals::RADIO_NS.TXPOWER = (uint)piVar1 & 0xff;
    return (uint)piVar1 & 0xff;
  }
  Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 1;
  uVar3 = (int)piVar1 - 3U & 0xff;
  Peripherals::RADIO_NS.TXPOWER = uVar3;
  return uVar3;
}



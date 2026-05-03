/*
 * Function: FUN_01021908
 * Entry:    01021908
 * Prototype: undefined4 * __stdcall FUN_01021908(uint param_1, undefined4 * param_2)
 */


/* WARNING: Removing unreachable block (ram,0x01021b0a) */
/* WARNING: Removing unreachable block (ram,0x01021b24) */
/* WARNING: Removing unreachable block (ram,0x01021b26) */
/* WARNING: Removing unreachable block (ram,0x01021b36) */
/* WARNING: Removing unreachable block (ram,0x01021b7c) */
/* WARNING: Removing unreachable block (ram,0x01021b86) */
/* WARNING: Removing unreachable block (ram,0x01021b92) */
/* WARNING: Removing unreachable block (ram,0x01021bda) */
/* WARNING: Removing unreachable block (ram,0x01021bf8) */
/* WARNING: Removing unreachable block (ram,0x01021cc2) */
/* WARNING: Removing unreachable block (ram,0x01021cd6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_01021908(uint param_1,undefined4 *param_2)

{
  bool bVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  int iVar5;
  undefined4 extraout_r2;
  uint uVar6;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar7;
  uint extraout_r2_04;
  undefined4 extraout_r2_05;
  int extraout_r2_06;
  undefined4 extraout_r2_07;
  uint extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  uint uVar8;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar9;
  uint extraout_r3_05;
  undefined4 extraout_r3_06;
  uint extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  undefined4 extraout_r3_12;
  undefined4 extraout_r3_13;
  uint extraout_r3_14;
  undefined4 extraout_r3_15;
  uint unaff_r4;
  RADIO_NS *unaff_r6;
  undefined4 *unaff_r7;
  undefined4 unaff_r8;
  undefined8 uVar10;
  byte bStack_65;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  TIMER0_NS *pTStack_60;
  int iStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 *puStack_4c;
  RADIO_NS *pRStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  byte local_2d;
  char local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  
  uVar8 = (uint)DAT_21001625;
  iVar5 = uVar8 << 0x1f;
  if (iVar5 < 0) {
    if (param_1 == 0) {
      local_2c = '\x04';
    }
    else {
      local_2c = '\x02';
    }
    local_2a = 0;
    uVar8 = FUN_01024688();
    local_2b = 0xff;
    if (1 < uVar8) {
      local_2b = 0;
    }
    uVar10 = FUN_010263b0();
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar7 = extraout_r2;
    uVar9 = extraout_r3;
    unaff_r7 = param_2;
    if ((int)uVar10 != 0) {
LAB_01021aa2:
      FUN_01009500(0x3e,0xa69,uVar7,uVar9);
      iVar5 = extraout_r2_06;
      uVar8 = extraout_r3_05;
      unaff_r4 = param_1;
      goto LAB_01021aac;
    }
    unaff_r8 = 1;
    unaff_r6 = &Peripherals::RADIO_NS;
    DAT_21001625 = DAT_21001625 | 2;
    DAT_21001635 = 1;
    uVar8 = Peripherals::RADIO_NS.SHORTS;
    Peripherals::RADIO_NS.SHORTS = uVar8 | 1;
    if (param_1 != 0) {
      if (param_1 == 1) {
LAB_01021a68:
        FUN_01020968((int)unaff_r7,uVar3,uVar7);
        Peripherals::RADIO_NS.TASKS_RXEN = param_1;
        ram0x210015f8 = CONCAT11(2,DAT_210015f7._1_1_);
        uVar6 = (uint)DAT_2100160c;
        Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = param_1;
        puVar4 = (undefined4 *)Peripherals::TIMER0_NS.CC_3_;
        uVar3 = extraout_r1_00;
        if (0x95 < uVar6) {
          DAT_21000034 = (undefined4 *)((int)puVar4 + 0x29);
          DAT_21000030 = puVar4;
          uVar10 = FUN_010220cc();
          uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
          uVar6 = extraout_r2_04;
          if (1 < (int)uVar10 + 1U) {
            FUN_01009500(0x3e,0x6f6,extraout_r2_04,extraout_r3_03);
            uVar7 = extraout_r2_05;
            uVar9 = extraout_r3_04;
            goto LAB_01021aa2;
          }
        }
LAB_0102198c:
        local_2b = param_1 == 0;
        param_1 = (uint)(byte)local_2b;
        local_2c = '\x02';
        FUN_0102649c((int)&local_2c,uVar3,uVar6,2);
        iVar5 = FUN_010263c8();
        uVar3 = extraout_r2_00;
        uVar7 = extraout_r3_00;
        if (iVar5 == 0) {
          if (DAT_210015f9 == '\x01') {
            iVar5 = (local_2d ^ 4) << 0x1d;
          }
          else {
            if (DAT_210015f9 != '\x02') {
              DAT_21001636 = 0;
              return (undefined4 *)0x0;
            }
            iVar5 = (local_2d ^ 2) << 0x1e;
          }
          DAT_21001636 = (char)-(iVar5 >> 0x1f);
          if (-(iVar5 >> 0x1f) != 0) {
            Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
            Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
            Peripherals::RADIO_NS.TASKS_DISABLE = 1;
          }
          return (undefined4 *)0x0;
        }
        goto LAB_01021ab6;
      }
      uVar6 = (uint)DAT_2100160c;
      Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
      uVar8 = Peripherals::TIMER0_NS.CC_3_;
      if (uVar6 < 0x96) goto LAB_0102198c;
      goto LAB_01021ac0;
    }
    FUN_01021200(param_2,uVar3,extraout_r2,uVar8 | 1);
    uVar8 = (uint)DAT_2100160a;
    unaff_r7 = (undefined4 *)&DAT_0103c490;
    Peripherals::RADIO_NS.FREQUENCY = (uint)(byte)(&DAT_0103c490)[uVar8];
    Peripherals::RADIO_NS.DATAWHITEIV = uVar8 & 0x7f;
    FUN_01021ed4((uint)param_2,uVar8,(int)DAT_21001609,(undefined2 *)&local_2c);
    FUN_01021da8((int)local_2c);
    uVar10 = FUN_010220fc();
    uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar7 = extraout_r2_01;
    uVar9 = extraout_r3_01;
    if ((int)uVar10 == 0) {
      uVar6 = (uint)DAT_2100160c;
      Peripherals::RADIO_NS.TASKS_TXEN = 1;
      ram0x210015f8 = CONCAT11(1,DAT_210015f7._1_1_);
      Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
      puVar4 = (undefined4 *)Peripherals::TIMER0_NS.CC_3_;
      if (0x95 < uVar6) {
        DAT_21000034 = puVar4 + 10;
        DAT_21000030 = puVar4;
        uVar10 = FUN_010220c0();
        uVar3 = (undefined4)((ulonglong)uVar10 >> 0x20);
        uVar6 = extraout_r2_02;
        if (1 < (int)uVar10 + 1U) {
          FUN_01009500(0x3e,0x6e9,extraout_r2_02,extraout_r3_02);
          uVar3 = extraout_r1;
          uVar7 = extraout_r2_03;
          goto LAB_01021a68;
        }
      }
      goto LAB_0102198c;
    }
  }
  else {
LAB_01021aac:
    param_1 = unaff_r4;
    FUN_01009500(0x3e,0x716,iVar5,uVar8);
    uVar3 = extraout_r2_07;
    uVar7 = extraout_r3_06;
LAB_01021ab6:
    FUN_01009500(0x3e,0xa8b,uVar3,uVar7);
    uVar6 = extraout_r2_08;
    uVar8 = extraout_r3_07;
LAB_01021ac0:
    FUN_01009500(0x3e,0x6fa,uVar6,uVar8);
    uVar7 = extraout_r2_09;
    uVar9 = extraout_r3_08;
  }
  FUN_01009500(0x3e,0x57e,uVar7,uVar9);
  psVar2 = (short *)((int)unaff_r6 >> 0x17);
  *psVar2 = (short)((int)unaff_r6 >> 0x17);
  uVar8 = (int)psVar2 >> ((uint)psVar2 & 0xff);
  *(uint *)param_1 = param_1;
  *(undefined4 **)(param_1 + 4) = unaff_r7;
  DAT_210015f0 = (undefined4 *)(((int)uVar8 >> (uVar8 & 0xff)) << 4);
  ram0x210015f8 = &DAT_210015f0;
  puStack_4c = &DAT_210015f0;
  DAT_21001625 = DAT_21001625 | 2;
  uStack_62 = 0;
  uStack_64 = 2;
  _DAT_210015f4 = param_1;
  uStack_50 = param_1;
  pRStack_48 = unaff_r6;
  puStack_44 = unaff_r7;
  uStack_40 = unaff_r8;
  uVar8 = FUN_01024688();
  uStack_63 = 0xff;
  if (1 < uVar8) {
    uStack_63 = 0;
  }
  puVar4 = (undefined4 *)FUN_010263b0();
  if (puVar4 == (undefined4 *)0x0) {
    DAT_21001635 = 1;
    uVar3 = 0;
LAB_01021c7e:
    if ((char)DAT_210015f7 == '\0') {
      DAT_21001625 = DAT_21001625 | 2;
LAB_01021bc0:
      uVar10 = FUN_01020908(uVar3);
      bVar1 = FUN_010242c4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),extraout_r2_10,
                           extraout_r3_09);
    }
    else {
      if ((char)DAT_210015f7 != '\x01') goto LAB_01021bc0;
      DAT_21001625 = DAT_21001625 | 4;
      uVar10 = FUN_01020908(uVar3);
      bVar1 = FUN_010242c4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),extraout_r2_13,
                           extraout_r3_12);
    }
    if (bVar1) {
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      FUN_01020d00();
      return (undefined4 *)0x0;
    }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
    iStack_5c = FUN_010259e8();
    pTStack_60 = &Peripherals::TIMER0_NS;
    uStack_63 = 0;
    uStack_58 = (&Peripherals::TIMER0_NS.CC_0_)[iStack_5c];
    uStack_54 = 0x28;
    uStack_64 = bVar1;
    FUN_0102649c((int)&uStack_64,extraout_r1_01,0,0x28);
    uVar8 = (uint)DAT_2100160c;
    uVar3 = extraout_r2_14;
    if (0x95 < uVar8) goto LAB_01021d72;
  }
  else {
    FUN_01009500(0x3e,0xa69,extraout_r2_12,extraout_r3_11);
                    /* WARNING: Read-only address (ram,0x00000000) is written */
    DAT_21000030 = &DAT_210015f0;
    DAT_21000034 = (undefined4 *)0x28;
    iVar5 = FUN_010220c0();
    if (1 < iVar5 + 1U) {
      FUN_01009500(0x3e,0x6e9,extraout_r2_15,extraout_r3_13);
      uVar3 = FUN_01020968(0,extraout_r1_02,extraout_r2_16);
      ram0x210015f8 = CONCAT11(2,DAT_210015f7._1_1_);
      if ((char)DAT_210015f7 == '\x01') {
        uVar8 = Peripherals::RADIO_NS.SHORTS;
        Peripherals::RADIO_NS.SHORTS = uVar8 | 4;
      }
      puVar4 = (undefined4 *)&UNK_00000029;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0x8000000a;
      goto LAB_01021c7e;
    }
  }
  iVar5 = FUN_010263c8();
  if (iVar5 == 0) {
    if (DAT_210015f9 == '\x01') {
      iVar5 = (bStack_65 ^ 4) << 0x1d;
    }
    else {
      if (DAT_210015f9 != '\x02') {
        DAT_21001636 = 0;
        return puVar4;
      }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      iVar5 = (bStack_65 ^ 2) << 0x1e;
    }
    DAT_21001636 = (undefined1)-(iVar5 >> 0x1f);
    if (-(iVar5 >> 0x1f) == 0) {
      return puVar4;
    }
    Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
    Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
    Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    return puVar4;
  }
  FUN_01009500(0x3e,0xa8b,extraout_r2_11,extraout_r3_10);
  uVar3 = extraout_r2_17;
  uVar8 = extraout_r3_14;
LAB_01021d72:
  FUN_01009500(0x3e,0x6fa,uVar3,uVar8);
  FUN_01009500(0x3e,0x57e,extraout_r2_18,extraout_r3_15);
  puVar4 = _FUN_010220e4;
  DAT_210015f0 = &DAT_210015f0;
  DAT_00000042 = 0x42;
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  _MasterStackPointer = 0;
  _DAT_210015f4 = 0;
  *_FUN_010220e4 = 0x420;
  puVar4[1] = &DAT_210015f0;
  puVar4[2] = puVar4;
  if (0 < (int)puVar4) {
    Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 1;
    puVar4 = (undefined4 *)((int)puVar4 - 3U & 0xff);
    Peripherals::RADIO_NS.TXPOWER = (uint)puVar4;
    return puVar4;
  }
  Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 0;
  Peripherals::RADIO_NS.TXPOWER = (uint)puVar4 & 0xff;
  return (undefined4 *)((uint)puVar4 & 0xff);
}



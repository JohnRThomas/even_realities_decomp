/*
 * Function: FUN_01021200
 * Entry:    01021200
 * Prototype: undefined4 * __stdcall FUN_01021200(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Possible PIC construction at 0x01021836: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0102183a) */
/* WARNING: Removing unreachable block (ram,0x0102183e) */
/* WARNING: Removing unreachable block (ram,0x01021b0a) */
/* WARNING: Removing unreachable block (ram,0x01021b24) */
/* WARNING: Removing unreachable block (ram,0x01021b26) */
/* WARNING: Removing unreachable block (ram,0x01021b36) */
/* WARNING: Removing unreachable block (ram,0x01021b7c) */
/* WARNING: Removing unreachable block (ram,0x01021b86) */
/* WARNING: Removing unreachable block (ram,0x01021b92) */
/* WARNING: Removing unreachable block (ram,0x01021bda) */
/* WARNING: Removing unreachable block (ram,0x01021cc2) */
/* WARNING: Removing unreachable block (ram,0x01021cd6) */
/* WARNING: Removing unreachable block (ram,0x01021bf8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_01021200(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  short *psVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  undefined4 extraout_r1;
  undefined4 *puVar12;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 *extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined *puVar13;
  undefined *extraout_r2_11;
  undefined *extraout_r2_12;
  undefined *extraout_r2_13;
  undefined *extraout_r2_14;
  undefined *extraout_r2_15;
  undefined4 *puVar14;
  undefined *extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined *extraout_r2_18;
  undefined *extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined *extraout_r2_21;
  undefined4 extraout_r2_22;
  undefined4 *extraout_r2_23;
  undefined *extraout_r2_24;
  undefined4 extraout_r2_25;
  undefined4 extraout_r2_26;
  undefined4 extraout_r2_27;
  undefined4 extraout_r2_28;
  uint extraout_r2_29;
  undefined4 extraout_r2_30;
  uint extraout_r2_31;
  undefined4 extraout_r2_32;
  int extraout_r2_33;
  undefined4 extraout_r2_34;
  uint extraout_r2_35;
  undefined4 extraout_r2_36;
  undefined4 extraout_r2_37;
  undefined4 extraout_r2_38;
  undefined4 extraout_r2_39;
  undefined4 extraout_r2_40;
  undefined4 extraout_r2_41;
  undefined4 extraout_r2_42;
  undefined4 extraout_r2_43;
  undefined4 extraout_r2_44;
  undefined4 extraout_r2_45;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar15;
  undefined4 extraout_r3_03;
  uint extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  uint extraout_r3_09;
  uint uVar16;
  undefined1 *puVar17;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  undefined4 extraout_r3_12;
  undefined4 *extraout_r3_13;
  uint extraout_r3_14;
  uint extraout_r3_15;
  undefined4 extraout_r3_16;
  undefined4 extraout_r3_17;
  undefined4 extraout_r3_18;
  undefined4 extraout_r3_19;
  undefined4 extraout_r3_20;
  undefined4 extraout_r3_21;
  undefined4 uVar18;
  uint extraout_r3_22;
  undefined4 extraout_r3_23;
  uint extraout_r3_24;
  undefined4 extraout_r3_25;
  undefined4 extraout_r3_26;
  undefined4 extraout_r3_27;
  undefined4 extraout_r3_28;
  undefined4 extraout_r3_29;
  undefined4 extraout_r3_30;
  uint extraout_r3_31;
  undefined4 extraout_r3_32;
  undefined4 *unaff_r4;
  undefined1 *unaff_r5;
  RADIO_NS *unaff_r6;
  int unaff_r7;
  undefined4 *puVar19;
  undefined4 *unaff_r8;
  undefined *unaff_r9;
  RADIO_NS *unaff_r10;
  undefined4 unaff_r11;
  undefined4 *puVar20;
  undefined4 uVar21;
  undefined8 uVar22;
  undefined4 uStack_8;
  
  DAT_21001608 = (byte)param_1;
  switch(param_1) {
  case (undefined4 *)0x1:
    Peripherals::RADIO_NS.MODE = 3;
    break;
  case (undefined4 *)0x2:
    Peripherals::RADIO_NS.MODE = 4;
    uVar21 = Peripherals::FICR_NS._132_4_;
    Peripherals::RADIO_NS._1416_4_ = uVar21;
    _MasterStackPointer = 0xb83d;
    return param_1;
  default:
    uVar21 = 0x1021261;
    uStack_8 = param_4;
    FUN_01009500(0x3e,0xd35,&DAT_210015f0,(int)param_1 + -1);
    psVar5 = (short *)((int)unaff_r6 >> 0x17);
    puVar11 = (undefined4 *)0x0;
    *psVar5 = (short)((int)unaff_r6 >> 0x17);
    puVar6 = (undefined4 *)((int)psVar5 >> ((uint)psVar5 & 0xff));
    puVar19 = (undefined4 *)(unaff_r7 << 7);
    puVar14 = extraout_r2;
    puVar20 = &uStack_8;
    do {
      puVar20[-1] = uVar21;
      puVar20[-2] = unaff_r11;
      puVar20[-3] = unaff_r10;
      puVar20[-4] = unaff_r9;
      puVar20[-5] = unaff_r8;
      puVar20[-6] = puVar19;
      puVar20[-7] = unaff_r6;
      puVar20[-8] = unaff_r5;
      puVar20[-9] = unaff_r4;
      if (puVar6 == (undefined4 *)0x0) {
        *(undefined1 *)((int)puVar20 + -0x3a) = 0;
        *(undefined1 *)(puVar20 + -0xf) = 4;
        uVar7 = FUN_01024688();
        uVar3 = 0xff;
        if (1 < uVar7) {
          uVar3 = 0;
        }
        *(undefined1 *)((int)puVar20 + -0x3b) = uVar3;
        uVar22 = FUN_010263b0();
        uVar21 = extraout_r2_00;
        uVar15 = extraout_r3;
        if ((int)uVar22 != 0) {
LAB_010214a4:
          FUN_01009500(0x3e,0xa69,uVar21,uVar15);
LAB_010214ae:
          DAT_21000034 = puVar11 + 10;
          DAT_21000030 = puVar11;
          iVar8 = FUN_010220c0();
          if (iVar8 + 1U < 2) {
LAB_0102139a:
            iVar8 = FUN_010263c8();
            uVar21 = extraout_r2_02;
            uVar15 = extraout_r3_01;
            if (iVar8 == 0) {
              uVar7 = (uint)*(byte *)((int)puVar20 + -0x3d);
              if (*(char *)((int)unaff_r4 + 9) == '\x01') {
                iVar8 = (uVar7 ^ 4) << 0x1d;
              }
              else {
                if (*(char *)((int)unaff_r4 + 9) != '\x02') {
                  *(undefined1 *)((int)unaff_r4 + 0x46) = 0;
                  goto LAB_010213ba;
                }
LAB_01021462:
                iVar8 = (uVar7 ^ 2) << 0x1e;
              }
              *(char *)((int)unaff_r4 + 0x46) = (char)-(iVar8 >> 0x1f);
              if (-(iVar8 >> 0x1f) != 0) {
                Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
                Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
                Peripherals::RADIO_NS.TASKS_DISABLE = 1;
              }
LAB_010213ba:
              return (undefined4 *)&DAT_00000001;
            }
          }
          else {
            FUN_01009500(0x3e,0x6e9,extraout_r2_06,extraout_r3_05);
            uVar21 = extraout_r2_07;
            uVar15 = extraout_r3_06;
          }
          FUN_01009500(0x3e,0xa8b,uVar21,uVar15);
          uVar21 = extraout_r2_08;
          uVar15 = extraout_r3_07;
          goto LAB_010214dc;
        }
        unaff_r4 = &DAT_210015f0;
        unaff_r11 = 1;
        unaff_r9 = &DAT_0103c490;
        DAT_21001635 = 1;
        FUN_01021200(puVar14,(int)((ulonglong)uVar22 >> 0x20),extraout_r2_00,extraout_r3);
        uVar7 = (uint)DAT_2100160a;
        unaff_r10 = &Peripherals::RADIO_NS;
        Peripherals::RADIO_NS.FREQUENCY = (uint)(byte)(&DAT_0103c490)[uVar7];
        Peripherals::RADIO_NS.DATAWHITEIV = uVar7 & 0x7f;
        FUN_01021ed4((uint)puVar14,uVar7,(int)DAT_21001609,(undefined2 *)(puVar20 + -0xf));
        FUN_01021da8((int)*(char *)(puVar20 + -0xf));
        iVar8 = FUN_010220fc();
        uVar21 = extraout_r2_01;
        uVar15 = extraout_r3_00;
        if (iVar8 != 0) goto LAB_010214e6;
        DAT_210015f9 = 1;
        uVar21 = 0;
        if ((byte)DAT_210015f7 != '\x01') {
          puVar11 = (undefined4 *)
                    ((int)puVar11 - ((ushort)(&DAT_0103c570)[(int)puVar14] + 500) / 1000);
          unaff_r9 = &DAT_0103c490 + (int)puVar14 * 2;
          if ((byte)DAT_210015f7 == '\0') {
            Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0x80000008;
          }
        }
LAB_0102131e:
        unaff_r4 = &DAT_210015f0;
        Peripherals::TIMER0_NS.CC_0_ = (uint)puVar11;
        Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0x80000008;
        Peripherals::RADIO_NS.INTENSET = 0x10;
        if ((byte)DAT_210015f7 == '\0') {
          DAT_21001625 = DAT_21001625 | 2;
        }
        else if ((byte)DAT_210015f7 == '\x01') {
          DAT_21001625 = DAT_21001625 | 4;
        }
        FUN_01020908(uVar21);
        Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
        puVar19 = (undefined4 *)Peripherals::TIMER0_NS.CC_3_;
        if (puVar11 <= puVar19) {
          Peripherals::TIMER0_NS.CC_0_ = 0;
          Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0;
          FUN_01020d00();
          return (undefined4 *)0x0;
        }
        puVar20[-0xe] = &Peripherals::TIMER0_NS;
        puVar20[-0xc] = puVar11;
        *(undefined1 *)(puVar20 + -0xf) = 0;
        puVar20[-0xd] = 0;
        *(bool *)((int)puVar20 + -0x3b) = puVar6 == (undefined4 *)0x0;
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)&DAT_0103c490;
          iVar8 = (int)puVar14 * 2;
          uVar1 = (&DAT_0103c570)[(int)puVar14];
          uVar7 = (uVar1 + 600) / 1000;
          puVar20[-0xb] = uVar7;
          FUN_0102649c((int)(puVar20 + -0xf),extraout_r1,(uVar1 + 600) * 0x10624dd3,uVar7);
          puVar14 = (undefined4 *)(&DAT_0103c490 + iVar8);
          if (DAT_2100160c < 0x96) goto LAB_0102139a;
          goto LAB_010214ae;
        }
        puVar20[-0xb] = 0x28;
        FUN_0102649c((int)(puVar20 + -0xf),extraout_r1,puVar19,0x28);
        uVar7 = (uint)DAT_2100160c;
        if (uVar7 < 0x96) goto LAB_0102139a;
        uVar21 = extraout_r2_04;
        if (puVar6 == (undefined4 *)&DAT_00000001) {
          DAT_21000034 = (undefined4 *)((int)puVar11 + 0x29);
          DAT_21000030 = puVar11;
          iVar8 = FUN_010220cc();
          if (iVar8 + 1U < 2) goto LAB_0102139a;
          FUN_01009500(0x3e,0x6f6,extraout_r2_05,extraout_r3_03);
          uVar7 = extraout_r3_04;
          goto LAB_01021462;
        }
      }
      else {
        puVar13 = (undefined *)0x2;
        *(undefined1 *)(puVar20 + -0xf) = 2;
        *(undefined1 *)((int)puVar20 + -0x3a) = 0;
        uVar7 = FUN_01024688();
        uVar3 = 0xff;
        if (1 < uVar7) {
          uVar3 = 0;
        }
        *(undefined1 *)((int)puVar20 + -0x3b) = uVar3;
        uVar22 = FUN_010263b0();
        uVar21 = extraout_r2_03;
        uVar15 = extraout_r3_02;
        unaff_r9 = puVar13;
        if ((int)uVar22 != 0) goto LAB_010214a4;
        uVar15 = 1;
        unaff_r4 = &DAT_210015f0;
        DAT_21001635 = 1;
        if (puVar6 == (undefined4 *)&DAT_00000001) {
          uVar21 = FUN_01020968((int)puVar14,(int)((ulonglong)uVar22 >> 0x20),extraout_r2_03);
          DAT_210015f9 = 2;
          unaff_r9 = (undefined *)0x2;
          if (((byte)DAT_210015f7 != '\x01') &&
             (puVar11 = (undefined4 *)((int)puVar11 + -0x29), unaff_r9 = puVar13,
             (byte)DAT_210015f7 == '\0')) {
            Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0x80000008;
          }
          goto LAB_0102131e;
        }
LAB_010214dc:
        FUN_01009500(0x3e,0x7c3,uVar21,uVar15);
        uVar21 = extraout_r2_09;
        uVar15 = extraout_r3_08;
LAB_010214e6:
        FUN_01009500(0x3e,0x57e,uVar21,uVar15);
        uVar21 = extraout_r2_10;
        uVar7 = extraout_r3_09;
      }
      puVar11 = puVar20 + -0xf;
      FUN_01009500(0x3e,0x6fa,uVar21,uVar7);
      *unaff_r4 = unaff_r4;
      unaff_r4[1] = puVar14;
      _DAT_ae79f67f = ((int)puVar6 >> 0x17) << 4;
      *(short *)((int)puVar6 >> 0x17) = (short)((int)puVar6 >> 0x17);
      unaff_r5 = &DAT_ae79f67f;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      _MasterStackPointer = 0;
      _DAT_ae79f687 = &DAT_ae79f67f;
      puVar20[-0x11] = 0x10214fb;
      puVar20[-0x12] = unaff_r9;
      puVar20[-0x13] = puVar11;
      puVar20[-0x14] = puVar14;
      puVar20[-0x15] = puVar6;
      puVar20[-0x16] = &DAT_ae79f67f;
      puVar20[-0x17] = unaff_r4;
      Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
      unaff_r6 = (RADIO_NS *)Peripherals::TIMER0_NS.CC_3_;
      _DAT_ae79f683 = unaff_r4;
      DAT_21001628 = src/*FUN_01025828();
      DAT_2100162c = 0;
      DAT_21001630 = unaff_r6;
      if (0x95 < DAT_2100160c) {
        if (DAT_210015f9 == 1) {
          iVar8 = FUN_010220d8();
          if (1 < iVar8 + 1U) {
            uVar21 = FUN_01009500(0x3e,0x851,extraout_r2_20,extraout_r3_11);
            goto LAB_010218ba;
          }
        }
        else if ((DAT_210015f9 == 2) && (iVar8 = FUN_010220e4(), 1 < iVar8 + 1U)) {
          FUN_01009500(0x3e,0x857,extraout_r2_17,extraout_r3_10);
          goto LAB_01021866;
        }
      }
      Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_START = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
      DAT_21001625 = 0;
      uVar7 = Peripherals::RADIO_NS.SHORTS;
      Peripherals::RADIO_NS.SHORTS = uVar7 & 0xfffffee2;
      if (DAT_210015fc == 0) {
        bVar4 = false;
        if (DAT_210015f9 != 1) goto LAB_01021582;
LAB_01021660:
        uVar7 = Peripherals::RADIO_NS.EVENTS_END;
        unaff_r5 = (undefined1 *)0x0;
        if (uVar7 != 0) {
          unaff_r5 = (undefined1 *)0x8;
          goto LAB_01021596;
        }
LAB_01021588:
        uVar7 = Peripherals::RADIO_NS.EVENTS_DISABLED;
        if (uVar7 != 0) {
          unaff_r5 = (undefined1 *)((uint)unaff_r5 | 0x10);
        }
      }
      else {
        uVar7 = Peripherals::TIMER0_NS.EVENTS_COMPARE_1_;
        bVar4 = uVar7 != 0;
        if (DAT_210015f9 == 1) goto LAB_01021660;
LAB_01021582:
        if (DAT_210015f9 != 2) {
          unaff_r5 = (undefined1 *)0x0;
          goto LAB_01021588;
        }
        uVar7 = Peripherals::RADIO_NS.EVENTS_END;
        uVar16 = Peripherals::RADIO_NS.CRCSTATUS;
        if (uVar7 == 0) {
          puVar17 = (undefined1 *)0x0;
          unaff_r5 = (undefined1 *)0x4;
        }
        else {
          unaff_r5 = (undefined1 *)0x6;
          puVar17 = (undefined1 *)0x2;
        }
        if ((uVar16 & 1) != 0) {
          unaff_r5 = puVar17;
        }
        if (bVar4) {
          puVar17 = (undefined1 *)((uint)unaff_r5 & 0xb | 1);
          unaff_r5 = (undefined1 *)((uint)unaff_r5 | 1);
        }
        if (puVar17 == (undefined1 *)0x0) goto LAB_01021588;
      }
LAB_01021596:
      uVar7 = Peripherals::RADIO_NS.EVENTS_ADDRESS;
      *(bool *)(puVar20 + -0x19) = uVar7 != 0;
      Peripherals::RADIO_NS.EVENTS_READY = 0;
      Peripherals::RADIO_NS.EVENTS_END = 0;
      Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
      Peripherals::RADIO_NS.EVENTS_ADDRESS = 0;
      Peripherals::RADIO_NS.EVENTS_DEVMATCH = 0;
      Peripherals::RADIO_NS.EVENTS_DEVMISS = 0;
      Peripherals::RADIO_NS.EVENTS_PAYLOAD = 0;
      Peripherals::RADIO_NS.EVENTS_PHYEND = 0;
      iVar8 = FUN_010264f0();
      bVar2 = DAT_210015f7._1_1_;
      if (iVar8 != 0) {
        unaff_r5 = (undefined1 *)((uint)unaff_r5 | 0x10);
      }
      Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
      if ((((uint)unaff_r5 & 0x18) == 0x10) && (DAT_210015f9 == 1)) {
        DAT_21001614 = (undefined4 *)Peripherals::TIMER0_NS.CC_2_;
        DAT_21001610 = Peripherals::TIMER0_NS.CC_1_;
        unaff_r5 = (undefined1 *)((uint)unaff_r5 | 0x20);
        if (DAT_21001619 == 2) goto LAB_010216c2;
LAB_01021602:
        uVar7 = (uint)DAT_21001608;
      }
      else {
        DAT_21001614 = (undefined4 *)Peripherals::TIMER0_NS.CC_2_;
        DAT_21001610 = Peripherals::TIMER0_NS.CC_1_;
        if ((DAT_21001619 != 2) && (DAT_210015f9 != 2)) goto LAB_01021602;
LAB_010216c2:
        uVar7 = (uint)DAT_21001608;
        if ((uVar7 == 4) || (uVar7 == 8)) {
          uVar7 = Peripherals::RADIO_NS.PDUSTAT;
          if ((uVar7 & 6) == 0) {
            uVar7 = 8;
          }
          else {
            uVar7 = 4;
          }
        }
      }
      puVar19 = DAT_21001614;
      puVar13 = (undefined *)(uint)DAT_210015f9;
      uVar16 = (uint)DAT_210015f7._1_1_;
      DAT_21001618 = (undefined1)uVar7;
      DAT_21001619 = DAT_210015f9;
      if (uVar16 == 0) {
        _DAT_210015f4 = (undefined4 *)CONCAT13(DAT_210015f7._1_1_,_DAT_210015f4);
        DAT_210015f7._1_1_ = 0;
        DAT_210015f9 = bVar2;
        DAT_210015fc = bVar2;
        uVar21 = 0;
        goto LAB_010216e8;
      }
      if (((uint)unaff_r5 & 0x11) != 0) {
        FUN_01020d00();
        uVar21 = 0;
        puVar13 = extraout_r2_14;
        goto LAB_010216e8;
      }
      bVar2 = (byte)DAT_210015f7;
      unaff_r9 = (undefined *)(uint)(byte)DAT_210015f7;
      DAT_210015f9 = 0;
      _DAT_210015f4 = (undefined4 *)((uint)_DAT_210015f4 & 0xffffff);
      DAT_210015f7._1_1_ = 0;
      puVar6 = (undefined4 *)(uint)(uVar16 != 1);
      uVar9 = (uint)DAT_2100160c;
      uVar21 = 0;
      puVar14 = DAT_21001614;
      if (puVar13 == (undefined *)0x0) goto LAB_010218f4;
      if (uVar16 == 1) {
        if (puVar13 == (undefined *)0x1) {
          iVar8 = FUN_01021e14(uVar9,uVar7);
          puVar11 = (undefined4 *)(iVar8 + (int)puVar19);
          puVar13 = extraout_r2_18;
        }
        else {
          iVar8 = FUN_01021dd8(uVar9,uVar7);
          puVar11 = (undefined4 *)(iVar8 + (int)puVar19);
          puVar13 = extraout_r2_15;
        }
      }
      else if (puVar13 == (undefined *)0x1) {
        iVar8 = FUN_01021df4(uVar9,uVar7);
        puVar11 = (undefined4 *)(iVar8 + (int)puVar19);
        puVar13 = extraout_r2_21;
      }
      else {
        iVar8 = FUN_01021e34(uVar9,uVar7);
        puVar11 = (undefined4 *)(iVar8 + (int)puVar19);
        puVar13 = extraout_r2_11;
      }
      if (unaff_r9 == (undefined *)0x1) {
        unaff_r6 = (RADIO_NS *)&unaff_r6->field_0x3b;
        if (puVar11 < unaff_r6) goto LAB_0102187c;
        _DAT_210015f4 = (undefined4 *)CONCAT13(bVar2,_DAT_210015f4);
      }
      puVar14 = (undefined4 *)(uint)DAT_210015fa;
      uVar21 = 0x102183b;
      unaff_r4 = &DAT_210015f0;
      unaff_r8 = puVar6;
      puVar20 = puVar20 + -0x1a;
    } while( true );
  case (undefined4 *)0x4:
    Peripherals::RADIO_NS.MODE = 6;
    break;
  case (undefined4 *)0x8:
    Peripherals::RADIO_NS.MODE = 5;
  }
  uVar21 = Peripherals::FICR_NS._128_4_;
  Peripherals::RADIO_NS._1416_4_ = uVar21;
  _MasterStackPointer = 0xb83d;
  return param_1;
LAB_0102187c:
  Peripherals::RADIO_NS.TASKS_DISABLE = 1;
  uVar21 = 1;
  puVar11 = puVar6;
LAB_010216e8:
  if (DAT_21001634 != '\0') {
    Peripherals::RADIO_NS._428_4_ = 0;
    DAT_21001634 = '\0';
    uVar7 = Peripherals::RADIO_NS.PCNF0;
    Peripherals::RADIO_NS.PCNF0 = uVar7 & 0xfff0ffff;
    DAT_21001604 = DAT_21001604 & 0xfffffffc;
    Peripherals::RADIO_NS.DFEMODE = DAT_21001604;
    puVar13 = &DAT_00023280;
    Peripherals::RADIO_NS.DFECTRL1 = 0x23280;
  }
  puVar14 = (undefined4 *)((int)unaff_r5 << 0x1f);
  if ((int)puVar14 < 0) {
LAB_010217f6:
    (*DAT_2100163c)();
    unaff_r5 = (undefined1 *)((uint)unaff_r5 & 0x10);
    puVar13 = extraout_r2_13;
    if (unaff_r5 == (undefined1 *)0x0) goto LAB_01021800;
LAB_0102172e:
    (*DAT_21001648)();
    puVar13 = extraout_r2_12;
    if (DAT_210015f9 != 2) goto LAB_01021760;
  }
  else {
    unaff_r6 = (RADIO_NS *)((int)unaff_r5 << 0x1e);
    if ((int)unaff_r6 < 0) {
      uVar7 = Peripherals::RADIO_NS._1104_4_;
      if ((((int)(uVar7 << 7) < 0) &&
          ((((uVar7 & 0xf00) == 0 || (uVar7 & 0xf0) == 0 || ((uVar7 & 0xf) == 0)) &&
           (iVar8 = Peripherals::RADIO_NS._1108_4_, (uVar7 << 8) >> 0x1d < 3)))) && (iVar8 != 0))
      goto LAB_010217f6;
      if (DAT_21001624 < *(byte *)(DAT_21001620 + 1)) {
LAB_010218ba:
        uVar7 = 0;
        unaff_r5 = (undefined1 *)((uint)unaff_r5 & 0xff);
      }
      else {
        uVar7 = (((uint)unaff_r5 ^ 4) << 0x1d) >> 0x1f;
      }
      (*DAT_21001640)(uVar7,uVar21);
      puVar13 = extraout_r2_19;
    }
    else if (((uint)unaff_r5 & 0x28) != 0) {
      (*DAT_21001644)(uVar21,(((uint)unaff_r5 ^ 0x20) << 0x1a) >> 0x1f);
      puVar13 = extraout_r2_16;
    }
    unaff_r5 = (undefined1 *)((uint)unaff_r5 & 0x10);
    if (unaff_r5 != (undefined1 *)0x0) goto LAB_0102172e;
LAB_01021800:
    if (DAT_210015f9 != 2) {
      bVar4 = FUN_010263e0();
      return (undefined4 *)(uint)bVar4;
    }
  }
  uVar7 = (uint)DAT_210015fc;
  if (uVar7 == 0) goto LAB_01021760;
  if (uVar7 == 2) {
LAB_01021866:
    Peripherals::TIMER0_NS.CC_1_ = (uint)((int)DAT_21001614 + (int)DAT_21001600);
LAB_01021758:
    Peripherals::TIMER0_NS.PUBLISH_COMPARE_1_ = 0x8000000b;
LAB_01021760:
    bVar4 = FUN_010263e0();
    puVar19 = (undefined4 *)(uint)bVar4;
    if ((unaff_r5 != (undefined1 *)0x0) &&
       (bVar4 = puVar19 != (undefined4 *)&DAT_00000001, puVar19 = (undefined4 *)0x0, bVar4)) {
      puVar20[-0x19] = 0;
      do {
        puVar20[-0x19] = puVar20[-0x19] + 1;
        if (puVar20[-0x19] == -1) {
          FUN_01009500(0x3e,0xc34,&Peripherals::RADIO_NS,0);
          FUN_01009500(0x3e,0xa52,extraout_r2_22,extraout_r3_12);
          puVar19 = extraout_r2_23;
          puVar6 = extraout_r3_13;
          goto LAB_010218e0;
        }
        uVar7 = Peripherals::RADIO_NS.STATE;
      } while ((uVar7 & 0xf7) == 4);
      puVar19 = (undefined4 *)0x0;
      Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
      _DAT_e000e280 = 0x100;
    }
    return puVar19;
  }
  puVar6 = puVar11;
  if (uVar7 == 1) {
    puVar19 = DAT_21001614;
    puVar6 = DAT_21001600;
    if (DAT_21001614 < DAT_21001600) {
      Peripherals::TIMER0_NS.CC_1_ = (uint)DAT_21001600;
      goto LAB_01021758;
    }
LAB_010218e0:
    FUN_01009500(0x3e,0xc16,puVar19,puVar6);
    puVar13 = extraout_r2_24;
    uVar7 = extraout_r3_14;
    puVar6 = puVar11;
  }
  FUN_01009500(0x3e,0xc15,puVar13,uVar7);
  uVar21 = extraout_r2_25;
  uVar16 = extraout_r3_15;
LAB_010218f4:
  uVar22 = FUN_01009500(0x3e,0x804,uVar21,uVar16);
  puVar12 = (undefined4 *)((ulonglong)uVar22 >> 0x20);
  puVar10 = (undefined2 *)uVar22;
  *puVar10 = (short)uVar22;
  uVar7 = (int)puVar10 >> ((uint)puVar10 & 0xff);
  puVar11 = (undefined4 *)((int)uVar7 >> (uVar7 & 0xff));
  puVar20[-0x1b] = 0x10218ff;
  puVar20[-0x1c] = puVar6;
  puVar20[-0x1d] = puVar14;
  puVar20[-0x1e] = unaff_r6;
  puVar20[-0x1f] = unaff_r5;
  puVar20[-0x20] = &DAT_210015f0;
  uVar7 = (uint)DAT_21001625;
  iVar8 = uVar7 << 0x1f;
  puVar19 = &DAT_210015f0;
  if (iVar8 < 0) {
    if (puVar11 == (undefined4 *)0x0) {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
    *(undefined1 *)((int)puVar20 + -0x92) = 0;
    *(undefined1 *)(puVar20 + -0x25) = uVar3;
    uVar7 = FUN_01024688();
    uVar3 = 0xff;
    if (1 < uVar7) {
      uVar3 = 0;
    }
    *(undefined1 *)((int)puVar20 + -0x93) = uVar3;
    uVar22 = FUN_010263b0();
    uVar21 = (undefined4)((ulonglong)uVar22 >> 0x20);
    uVar15 = extraout_r2_26;
    uVar18 = extraout_r3_16;
    puVar14 = puVar12;
    if ((int)uVar22 != 0) {
LAB_01021aa2:
      FUN_01009500(0x3e,0xa69,uVar15,uVar18);
      iVar8 = extraout_r2_33;
      uVar7 = extraout_r3_22;
      puVar19 = puVar11;
      goto LAB_01021aac;
    }
    puVar6 = (undefined4 *)&DAT_00000001;
    unaff_r6 = &Peripherals::RADIO_NS;
    DAT_21001625 = DAT_21001625 | 2;
    DAT_21001635 = 1;
    uVar7 = Peripherals::RADIO_NS.SHORTS;
    Peripherals::RADIO_NS.SHORTS = uVar7 | 1;
    if (puVar11 != (undefined4 *)0x0) {
      if (puVar11 == (undefined4 *)0x1) {
LAB_01021a68:
        FUN_01020968((int)puVar14,uVar21,uVar15);
        Peripherals::RADIO_NS.TASKS_RXEN = (uint)puVar11;
        DAT_210015f9 = 2;
        uVar16 = (uint)DAT_2100160c;
        Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = (uint)puVar11;
        puVar19 = (undefined4 *)Peripherals::TIMER0_NS.CC_3_;
        uVar21 = extraout_r1_01;
        if (0x95 < uVar16) {
          DAT_21000034 = (undefined4 *)((int)puVar19 + 0x29);
          DAT_21000030 = puVar19;
          uVar22 = FUN_010220cc();
          uVar21 = (undefined4)((ulonglong)uVar22 >> 0x20);
          uVar16 = extraout_r2_31;
          if (1 < (int)uVar22 + 1U) {
            FUN_01009500(0x3e,0x6f6,extraout_r2_31,extraout_r3_20);
            uVar15 = extraout_r2_32;
            uVar18 = extraout_r3_21;
            goto LAB_01021aa2;
          }
        }
LAB_0102198c:
        bVar4 = puVar11 == (undefined4 *)0x0;
        puVar11 = (undefined4 *)(uint)bVar4;
        *(undefined1 *)(puVar20 + -0x25) = 2;
        *(bool *)((int)puVar20 + -0x93) = bVar4;
        FUN_0102649c((int)(puVar20 + -0x25),uVar21,uVar16,2);
        iVar8 = FUN_010263c8();
        uVar21 = extraout_r2_27;
        uVar15 = extraout_r3_17;
        if (iVar8 == 0) {
          if (DAT_210015f9 == 1) {
            iVar8 = (*(byte *)((int)puVar20 + -0x95) ^ 4) << 0x1d;
          }
          else {
            if (DAT_210015f9 != 2) {
              DAT_21001636 = 0;
              return (undefined4 *)0x0;
            }
            iVar8 = (*(byte *)((int)puVar20 + -0x95) ^ 2) << 0x1e;
          }
          DAT_21001636 = (char)-(iVar8 >> 0x1f);
          if (-(iVar8 >> 0x1f) != 0) {
            Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
            Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
            Peripherals::RADIO_NS.TASKS_DISABLE = 1;
          }
          return (undefined4 *)0x0;
        }
        goto LAB_01021ab6;
      }
      uVar16 = (uint)DAT_2100160c;
      Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
      uVar7 = Peripherals::TIMER0_NS.CC_3_;
      if (uVar16 < 0x96) goto LAB_0102198c;
      goto LAB_01021ac0;
    }
    FUN_01021200(puVar12,uVar21,extraout_r2_26,uVar7 | 1);
    uVar7 = (uint)DAT_2100160a;
    puVar14 = (undefined4 *)&DAT_0103c490;
    Peripherals::RADIO_NS.FREQUENCY = (uint)(byte)(&DAT_0103c490)[uVar7];
    Peripherals::RADIO_NS.DATAWHITEIV = uVar7 & 0x7f;
    FUN_01021ed4((uint)puVar12,uVar7,(int)DAT_21001609,(undefined2 *)(puVar20 + -0x25));
    FUN_01021da8((int)*(char *)(puVar20 + -0x25));
    uVar22 = FUN_010220fc();
    uVar21 = (undefined4)((ulonglong)uVar22 >> 0x20);
    uVar15 = extraout_r2_28;
    uVar18 = extraout_r3_18;
    if ((int)uVar22 == 0) {
      uVar16 = (uint)DAT_2100160c;
      Peripherals::RADIO_NS.TASKS_TXEN = 1;
      DAT_210015f9 = 1;
      Peripherals::TIMER0_NS.TASKS_CAPTURE_3_ = 1;
      puVar19 = (undefined4 *)Peripherals::TIMER0_NS.CC_3_;
      if (0x95 < uVar16) {
        DAT_21000034 = puVar19 + 10;
        DAT_21000030 = puVar19;
        uVar22 = FUN_010220c0();
        uVar21 = (undefined4)((ulonglong)uVar22 >> 0x20);
        uVar16 = extraout_r2_29;
        if (1 < (int)uVar22 + 1U) {
          FUN_01009500(0x3e,0x6e9,extraout_r2_29,extraout_r3_19);
          uVar21 = extraout_r1_00;
          uVar15 = extraout_r2_30;
          goto LAB_01021a68;
        }
      }
      goto LAB_0102198c;
    }
  }
  else {
LAB_01021aac:
    puVar11 = puVar19;
    FUN_01009500(0x3e,0x716,iVar8,uVar7);
    uVar21 = extraout_r2_34;
    uVar15 = extraout_r3_23;
LAB_01021ab6:
    FUN_01009500(0x3e,0xa8b,uVar21,uVar15);
    uVar16 = extraout_r2_35;
    uVar7 = extraout_r3_24;
LAB_01021ac0:
    FUN_01009500(0x3e,0x6fa,uVar16,uVar7);
    uVar15 = extraout_r2_36;
    uVar18 = extraout_r3_25;
  }
  FUN_01009500(0x3e,0x57e,uVar15,uVar18);
  psVar5 = (short *)((int)unaff_r6 >> 0x17);
  *psVar5 = (short)((int)unaff_r6 >> 0x17);
  uVar7 = (int)psVar5 >> ((uint)psVar5 & 0xff);
  *puVar11 = puVar11;
  puVar11[1] = puVar14;
  DAT_210015f0 = (undefined4 *)(((int)uVar7 >> (uVar7 & 0xff)) << 4);
  DAT_210015f7._1_1_ = 0xf0;
  DAT_210015f9 = '\x15';
  DAT_210015fa = 0;
  uRam210015fb = 0x21;
  puVar20[-0x27] = 0x1021ad5;
  puVar20[-0x28] = unaff_r10;
  puVar20[-0x29] = unaff_r9;
  puVar20[-0x2a] = puVar6;
  puVar20[-0x2b] = puVar14;
  puVar20[-0x2c] = unaff_r6;
  puVar20[-0x2d] = &DAT_210015f0;
  puVar20[-0x2e] = puVar11;
  DAT_21001625 = DAT_21001625 | 2;
  *(undefined1 *)((int)puVar20 + -0xca) = 0;
  *(undefined1 *)(puVar20 + -0x33) = 2;
  _DAT_210015f4 = puVar11;
  uVar7 = FUN_01024688();
  uVar3 = 0xff;
  if (1 < uVar7) {
    uVar3 = 0;
  }
  *(undefined1 *)((int)puVar20 + -0xcb) = uVar3;
  puVar19 = (undefined4 *)FUN_010263b0();
  if (puVar19 == (undefined4 *)0x0) {
    DAT_21001635 = 1;
    uVar21 = 0;
LAB_01021c7e:
    if ((byte)DAT_210015f7 == '\0') {
      DAT_21001625 = DAT_21001625 | 2;
LAB_01021bc0:
      uVar22 = FUN_01020908(uVar21);
      bVar4 = FUN_010242c4((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),extraout_r2_37,
                           extraout_r3_26);
    }
    else {
      if ((byte)DAT_210015f7 != '\x01') goto LAB_01021bc0;
      DAT_21001625 = DAT_21001625 | 4;
      uVar22 = FUN_01020908(uVar21);
      bVar4 = FUN_010242c4((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),extraout_r2_40,
                           extraout_r3_29);
    }
    if (bVar4) {
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      FUN_01020d00();
      return (undefined4 *)0x0;
    }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
    iVar8 = src/*FUN_010259e8();
    puVar20[-0x31] = iVar8;
    *(undefined1 *)(puVar20 + -0x33) = 0;
    puVar20[-0x32] = &Peripherals::TIMER0_NS;
    *(undefined1 *)((int)puVar20 + -0xcb) = 0;
    puVar20[-0x30] = (&Peripherals::TIMER0_NS.CC_0_)[iVar8];
    puVar20[-0x2f] = 0x28;
    FUN_0102649c((int)(puVar20 + -0x33),extraout_r1_02,0,0x28);
    uVar7 = (uint)DAT_2100160c;
    uVar21 = extraout_r2_41;
    if (0x95 < uVar7) goto LAB_01021d72;
  }
  else {
    FUN_01009500(0x3e,0xa69,extraout_r2_39,extraout_r3_28);
    DAT_21000030 = &DAT_210015f0;
    DAT_21000034 = (undefined4 *)0x28;
    iVar8 = FUN_010220c0();
    if (1 < iVar8 + 1U) {
      FUN_01009500(0x3e,0x6e9,extraout_r2_42,extraout_r3_30);
      uVar21 = FUN_01020968(0,extraout_r1_03,extraout_r2_43);
      if ((byte)DAT_210015f7 == '\x01') {
        uVar7 = Peripherals::RADIO_NS.SHORTS;
        Peripherals::RADIO_NS.SHORTS = uVar7 | 4;
      }
      puVar19 = (undefined4 *)&UNK_00000029;
      Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0x8000000a;
      DAT_210015f9 = '\x02';
      goto LAB_01021c7e;
    }
  }
  iVar8 = FUN_010263c8();
  if (iVar8 == 0) {
    if (DAT_210015f9 == '\x01') {
      iVar8 = (*(byte *)((int)puVar20 + -0xcd) ^ 4) << 0x1d;
    }
    else {
      if (DAT_210015f9 != '\x02') {
        DAT_21001636 = 0;
        return puVar19;
      }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      iVar8 = (*(byte *)((int)puVar20 + -0xcd) ^ 2) << 0x1e;
    }
    DAT_21001636 = (undefined1)-(iVar8 >> 0x1f);
    if (-(iVar8 >> 0x1f) == 0) {
      return puVar19;
    }
    Peripherals::RADIO_NS.SUBSCRIBE_TXEN = 0;
    Peripherals::RADIO_NS.SUBSCRIBE_RXEN = 0;
    Peripherals::RADIO_NS.TASKS_DISABLE = 1;
    return puVar19;
  }
  FUN_01009500(0x3e,0xa8b,extraout_r2_38,extraout_r3_27);
  uVar21 = extraout_r2_44;
  uVar7 = extraout_r3_31;
LAB_01021d72:
  FUN_01009500(0x3e,0x6fa,uVar21,uVar7);
  FUN_01009500(0x3e,0x57e,extraout_r2_45,extraout_r3_32);
  puVar19 = _FUN_010220e4;
  DAT_210015f0 = &DAT_210015f0;
  DAT_00000042 = 0x42;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  _MasterStackPointer = 0;
  _DAT_210015f4 = (undefined4 *)0;
  *_FUN_010220e4 = 0x420;
  puVar19[1] = &DAT_210015f0;
  puVar19[2] = puVar19;
  if (0 < (int)puVar19) {
    Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 1;
    puVar19 = (undefined4 *)((int)puVar19 - 3U & 0xff);
    Peripherals::RADIO_NS.TXPOWER = (uint)puVar19;
    return puVar19;
  }
  Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 0;
  Peripherals::RADIO_NS.TXPOWER = (uint)puVar19 & 0xff;
  return (undefined4 *)((uint)puVar19 & 0xff);
}



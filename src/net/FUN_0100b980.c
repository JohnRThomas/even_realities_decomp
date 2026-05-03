/*
 * Function: FUN_0100b980
 * Entry:    0100b980
 * Prototype: undefined4 __stdcall FUN_0100b980(uint param_1, ushort * param_2, int param_3, int param_4, int param_5)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0100b980(uint param_1,ushort *param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  ushort *puVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  int iVar9;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar10;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  ushort *extraout_r2_06;
  undefined4 extraout_r2_07;
  uint extraout_r2_08;
  undefined4 extraout_r3;
  undefined *puVar11;
  undefined4 extraout_r3_00;
  uint extraout_r3_01;
  int iVar12;
  bool bVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  
  if (((DAT_21000c8c == 0) && (param_4 != 0 && param_3 != 0)) && (param_5 != 0)) {
    DAT_21000c88 = param_5;
    DAT_21000c84 = DAT_21000c8c;
    DAT_21000c85 = DAT_21000c8c;
    DAT_21000d0c = DAT_21000c8c;
    DAT_21000c86 = DAT_21000c8c;
    DAT_21000cf8 = DAT_21000c8c;
    DAT_21000c78 = 0;
    DAT_21000c6c = param_1;
    DAT_21000c70 = param_2;
    DAT_21000c7a = DAT_21000c78;
    DAT_21000c7c = param_3;
    DAT_21000d08 = param_4;
    FUN_01020bd0();
    FUN_0102074c();
    FUN_01020cd4((char)param_2[0x39]);
    FUN_01020f2c(*(uint *)(param_2 + 0x10));
    FUN_01020ce0(*(uint *)(param_2 + 0xc));
    FUN_01020cf4(*(undefined1 *)((int)param_2 + 0xdb));
    if ((DAT_21000c6c & 0xff) == 0) {
      FUN_01026444(3,extraout_r1,extraout_r2,0);
      if (&DAT_00001d4b < *(undefined **)(param_2 + 10)) {
        FUN_01020a70(0x96,extraout_r1_04,*(undefined **)(param_2 + 10),&DAT_00001d4b);
      }
      else {
        FUN_010210e4(1);
        FUN_01020a70(0x4d,extraout_r1_05,extraout_r2_03,extraout_r3_00);
      }
      uVar5 = FUN_01021aec(0,(undefined4 *)(uint)(byte)param_2[0x37]);
    }
    else {
      FUN_01026444(4,extraout_r1,extraout_r2,DAT_21000c6c & 0xff);
      if (&DAT_00001d4b < *(undefined **)(param_2 + 10)) {
        FUN_01020a70(0x96,extraout_r1_00,*(undefined **)(param_2 + 10),&DAT_00001d4b);
      }
      else {
        FUN_010210e4(1);
        FUN_01020a70(0x4d,extraout_r1_01,extraout_r2_00,extraout_r3);
      }
      uVar5 = FUN_01021aec(1,(undefined4 *)(uint)*(byte *)((int)param_2 + 0x6f));
    }
    if (uVar5 == 0) {
      return 0;
    }
    FUN_01020f38(DAT_21000050);
    DAT_21000cc8 = FUN_0100a97c(*param_2,extraout_r1_02,extraout_r2_01);
    DAT_21000d10 = FUN_0100a918(*param_2,extraout_r1_03,extraout_r2_02);
    if (((*(char *)((int)param_2 + 0x7b) == '\0') && (*(uint **)(param_2 + 0x3a) != (uint *)0x0)) &&
       ((uint)param_2[0x5e] == (uint)param_2[0x79])) {
      iVar12 = (uint)param_2[0x5e] + (uint)param_2[0x3c];
      param_2[0x79] = (ushort)iVar12;
      FUN_01023250((uint)(byte)param_2[0x3d],*(uint **)(param_2 + 0x3a),1,iVar12);
    }
    DAT_21000cdc = *(undefined4 *)(param_2 + 0x9e);
    DAT_21000cd0 = *(undefined4 *)(param_2 + 0x98);
    DAT_21000cd4 = *(undefined4 *)(param_2 + 0x9a);
    DAT_21000cd8 = *(undefined4 *)(param_2 + 0x9c);
    DAT_21000ce9 = *(undefined4 *)(param_2 + 0xa0);
    DAT_21000ced = *(undefined4 *)(param_2 + 0xa2);
    iVar12 = 0;
    if ((char)DAT_21000c6c == '\0') {
      if ((1 < *(byte *)((int)DAT_21000c70 + 0xc5) - 0x26) && ((char)DAT_21000c70[99] != '&')) {
LAB_0100bab0:
        uVar5 = (uint)(byte)DAT_21000c70[0x37];
        if (uVar5 == 4) goto LAB_0100bce6;
        goto LAB_0100baba;
      }
      cVar3 = (char)DAT_21000c70[0x18d];
      bVar2 = (byte)DAT_21000c70[0x37];
    }
    else {
      if ((1 < *(byte *)((int)DAT_21000c70 + 0xc5) - 0x26) &&
         (cVar3 = (char)DAT_21000c70[99], cVar3 != '&')) {
        if (*(byte *)((int)DAT_21000c70 + 0xc5) - 0x21 < 2) {
          puVar8 = DAT_21000c70;
          if (cVar3 != '$') goto LAB_0100bd30;
        }
        else if (cVar3 != '$') goto LAB_0100bab0;
        bVar2 = (byte)DAT_21000c70[0xb7] & *(byte *)((int)DAT_21000c70 + 0x67);
        uVar6 = (uint)bVar2;
        uVar5 = (uint)(byte)DAT_21000c70[0x37];
        if ((int)(uVar6 << 0x1d) < 0) goto LAB_0100bce6;
        if ((bVar2 & 1) == 0) {
          if (-1 < (int)(uVar6 << 0x1e)) goto LAB_0100baba;
          if (uVar5 == 4) goto LAB_0100bce6;
          if (uVar5 == 8) goto LAB_0100bce6;
          goto LAB_0100bc04;
        }
        if (uVar5 == 4) goto LAB_0100bce6;
        if (uVar5 != 8) goto LAB_0100bd74;
        goto LAB_0100bce6;
      }
      cVar3 = (char)DAT_21000c70[0x1df];
      bVar2 = (byte)DAT_21000c70[0x37];
    }
    uVar5 = (uint)bVar2;
    if (cVar3 == '\0') goto LAB_0100baba;
    if (uVar5 == 8) goto LAB_0100bce6;
    if (uVar5 == 4) goto LAB_0100bce6;
    if (cVar3 == '\b') goto LAB_0100bce6;
    if (cVar3 == '\x04') goto LAB_0100bce6;
    if ((uVar5 == 1) || (cVar3 == '\x01')) {
      uVar5 = 1;
    }
    else {
      uVar5 = 2;
    }
    do {
      uVar6 = (uint)param_2[0x1e];
LAB_0100bac6:
      uVar6 = FUN_0100dd38(uVar6,uVar5);
      uVar5 = (uint)param_2[0x1c];
      if (uVar6 <= param_2[0x1c]) {
        uVar5 = uVar6;
      }
      DAT_21000cc3 = (undefined1)uVar5;
      uVar4 = FUN_0100f900((int)(param_2 + 0x18),(uint)*(byte *)((int)param_2 + 0x6f));
      uVar5 = (uint)*(byte *)((int)param_2 + 0x6f);
      cVar3 = *(char *)((int)param_2 + 0xcb);
      uVar1 = param_2[0x20];
      if (uVar5 == 8) {
        uVar5 = 4;
      }
      uVar5 = FUN_0100dd38((uint)uVar4,uVar5);
      if (cVar3 == '\0') {
        uVar5 = uVar5 + 4 & 0xffff;
      }
      if (uVar1 <= uVar5) {
        uVar5 = (uint)uVar1;
      }
      uVar6 = uVar5 & 0xff;
      DAT_21000d14 = (undefined1)uVar5;
      cVar3 = FUN_0100fdcc();
      if ((cVar3 != '\0') && (uVar6 < 0x2b)) {
        uVar6 = 0x2b;
      }
      DAT_21000cc2 = (undefined1)uVar6;
      if ((DAT_21000c6c & 0xff) != 0) {
        if (*(char *)((int)param_2 + 0xcb) != '\0') {
          uVar10 = 1;
          DAT_21000ce0 = *(undefined4 *)(param_2 + 0x94);
          DAT_21000ce4 = *(undefined4 *)(param_2 + 0x96);
          puVar11 = (undefined *)(*(byte *)((int)param_2 + 0x6f) - 1);
          DAT_21000ce8 = 1;
          switch(*(byte *)((int)param_2 + 0x6f)) {
          case 1:
            break;
          case 2:
            iVar12 = 1;
            break;
          default:
            goto switchD_0100bb60_caseD_2;
          case 4:
            iVar12 = 3;
            break;
          case 8:
            iVar12 = 2;
          }
          FUN_010205d0(1,0x21000cd0,uVar6,iVar12,0);
        }
        uVar7 = FUN_0100b73c(1);
        uVar10 = extraout_r2_05;
        goto LAB_0100bca6;
      }
      if ((char)param_2[0x65] == '\0') goto LAB_0100bca0;
      DAT_21000ce8 = 1;
      iVar12 = (byte)param_2[0x37] - 1;
      uVar10 = *(undefined4 *)(param_2 + 0x90);
      DAT_21000ce4 = *(undefined4 *)(param_2 + 0x92);
      puVar11 = &DAT_00001d4b;
      if (*(undefined **)(param_2 + 10) < &DAT_00001d4c) {
        uVar5 = 4;
      }
      else {
        uVar5 = 0;
      }
      iVar9 = 0;
      DAT_21000ce0 = uVar10;
      switch(iVar12) {
      case 0:
        goto switchD_0100bb60_caseD_0;
      case 1:
        iVar9 = 1;
        goto switchD_0100bb60_caseD_0;
      default:
switchD_0100bb60_caseD_2:
        DAT_21000ce8 = 1;
        FUN_01009500(6,0x3c5,uVar10,puVar11);
        puVar8 = extraout_r2_06;
LAB_0100bd30:
        uVar6 = (uint)(byte)puVar8[0xb7];
        uVar5 = (uint)(byte)puVar8[0x37];
        if ((int)(uVar6 << 0x1d) < 0) {
LAB_0100bce6:
          uVar5 = 8;
          uVar6 = 0xa90;
          goto LAB_0100bac6;
        }
        if (((byte)puVar8[0xb7] & 1) == 0) {
          if (-1 < (int)(uVar6 << 0x1e)) goto LAB_0100baba;
          if ((uVar5 == 8) || (uVar5 == 4)) goto LAB_0100bce6;
LAB_0100bc04:
          bVar13 = uVar5 != 1;
          uVar5 = 1;
          if (bVar13) {
            uVar5 = 2;
          }
        }
        else {
          if ((uVar5 == 8) || (uVar5 == 4)) goto LAB_0100bce6;
LAB_0100bd74:
          uVar5 = uVar6 & 1;
        }
        break;
      case 3:
        iVar9 = 3;
        goto switchD_0100bb60_caseD_0;
      case 7:
        iVar9 = 2;
switchD_0100bb60_caseD_0:
        FUN_010205d0(uVar5,0x21000cd0,0xfb,iVar9,0);
LAB_0100bca0:
        uVar14 = FUN_0100b498(1);
        uVar7 = (undefined4)uVar14;
        uVar10 = extraout_r2_04;
LAB_0100bca6:
        uVar5 = Peripherals::RADIO_NS.STATE;
        uVar5 = uVar5 & 0xfffffff7;
        if (uVar5 != 3) {
          ram0x21000c50 = 0;
          _DAT_21000c4c = (uint)*(byte *)((int)param_2 + 0xdb);
          DAT_21000c48 = CONCAT22(param_2[0x5e],*param_2);
          return uVar7;
        }
        goto LAB_0100bd82;
      }
    } while( true );
  }
  FUN_01009500(0x27,0x153,param_3,param_4);
  uVar10 = extraout_r2_07;
  uVar5 = extraout_r3_01;
LAB_0100bd82:
  FUN_01009500(0x27,0x208,uVar10,uVar5);
  puVar8 = (ushort *)(extraout_r2_08 >> 0x13);
  *puVar8 = (ushort)(extraout_r2_08 >> 0x13);
  uVar15 = (ulonglong)(uint)((int)puVar8 >> ((uint)puVar8 & 0xff));
  if (DAT_21000c8c != 0) {
    if ((char)DAT_21000c6c != '\0') {
      if (DAT_21000c8c != 2) {
        FUN_01009500(0x27,0x224,extraout_r2_08,(uint)DAT_21000c8c);
        uVar10 = FUN_0100b434();
        return uVar10;
      }
      uVar15 = FUN_01020fcc(*(uint *)(DAT_21000c70 + 0x178));
      goto LAB_0100bdb6;
    }
    if (DAT_21000c8c == 1) goto LAB_0100bdb6;
    FUN_01009500(0x27,0x220,extraout_r2_08,(uint)DAT_21000c8c);
  }
  uVar15 = FUN_0100b434();
LAB_0100bdb6:
  uVar10 = (undefined4)(uVar15 >> 0x20);
  if ((*(char *)((int)DAT_21000c70 + 0x7b) == '\0') &&
     (uVar10 = 0, *(int *)(DAT_21000c70 + 0x3a) != 0)) {
    uVar10 = FUN_01023250((uint)(byte)DAT_21000c70[0x3d],(uint *)0x0,0,DAT_21000c70);
    return uVar10;
  }
                    /* WARNING: Could not recover jumptable at 0x0100bdc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar10 = (*(code *)0x100bd8d)((int)uVar15,uVar10);
  return uVar10;
LAB_0100baba:
  uVar6 = (uint)param_2[0x1e];
  if ((uVar5 & 0xc) != 0) {
    uVar6 = 0xa90;
  }
  goto LAB_0100bac6;
}



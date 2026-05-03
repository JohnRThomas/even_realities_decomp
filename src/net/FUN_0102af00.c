/*
 * Function: FUN_0102af00
 * Entry:    0102af00
 * Prototype: undefined4 __stdcall FUN_0102af00(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0102af00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar8;
  undefined4 extraout_r2_04;
  int extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  int extraout_r2_08;
  int extraout_r2_09;
  int extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  uint uVar9;
  int extraout_r3;
  int extraout_r3_00;
  int iVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 uStack_34;
  
  if (1 < DAT_21000580) {
    FUN_01039ee2((byte *)"net %s\n","2025-06-28 17:32:14",param_3,DAT_21000580);
  }
  FUN_0102b3ec();
  uVar6 = extraout_r1;
  uVar8 = extraout_r2;
  iVar10 = DAT_21000580;
  if (1 < DAT_21000580) {
    FUN_01039ee2((byte *)"global init\n",extraout_r1,extraout_r2,DAT_21000580);
    uVar6 = extraout_r1_00;
    uVar8 = extraout_r2_00;
    iVar10 = extraout_r3;
  }
  piVar3 = FUN_0103bcf0(0xd0,uVar6,uVar8,iVar10);
  FUN_0103bdee((undefined1 *)piVar3,0,0xd0);
  piVar3[0x31] = -1;
  *(undefined2 *)(piVar3 + 0x32) = 0xffff;
  *(undefined4 *)((int)piVar3 + 0xca) = 0xffffffff;
  *(undefined2 *)((int)piVar3 + 0xce) = 0xffff;
  FUN_0103b9e4((int)(piVar3 + 3),0,1);
  FUN_0103b9e4((int)(piVar3 + 9),0,1);
  piVar3[2] = 0xff;
  FUN_0102b474((int)(piVar3 + 0x12),extraout_r1_01,extraout_r2_01);
  *(undefined1 *)(piVar3 + 0xf) = 1;
  piVar3[0x10] = (int)"cpunet-hw-id";
  piVar3[0x11] = (int)&LAB_0102aa78_1;
  (*(code *)piVar3[0x2b])(piVar3 + 0xf);
  if (1 < DAT_21000580) {
    FUN_01039ee2((byte *)"done\n",extraout_r1_02,extraout_r2_02,DAT_21000580);
  }
  iVar10 = 0x14;
  DAT_210045f4 = piVar3;
  do {
    if (*DAT_210045f4 != 0) {
      if (1 < DAT_21000580) {
        FUN_01039ee2((byte *)"role %d mode %d\n",*DAT_210045f4,DAT_210045f4[1],DAT_210045f4);
      }
      iVar10 = *DAT_210045f4;
      piVar3 = DAT_210045f4;
      if (iVar10 != 1) goto LAB_0102b09c;
      FUN_0102b854((undefined1 *)(DAT_210045f4 + 0x31));
      if (DAT_21000580 < 2) goto LAB_0102afd2;
      pcVar4 = "M\n";
      uVar6 = extraout_r1_03;
      uVar8 = extraout_r2_03;
      goto LAB_0102afce;
    }
    FUN_0102ae00();
    uStack_3e = 0;
    uStack_3c = 0;
    local_40 = 0x201;
    local_3a = uStack_3e;
    (*(code *)DAT_210045f4[0x2a])(&local_40);
    if (1 < DAT_21000580) {
      FUN_01039ee2((byte *)"resend\n",extraout_r1_05,extraout_r2_06,DAT_21000580);
    }
    if (*DAT_210045f4 == 0) {
      FUN_01039ddc(300);
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  piVar3 = (int *)FUN_0102d77c();
  iVar10 = extraout_r3_00;
LAB_0102b09c:
  if ((iVar10 == 2) && (FUN_0102b854((undefined1 *)((int)piVar3 + 0xca)), 1 < DAT_21000580)) {
    pcVar4 = "S\n";
    uVar6 = extraout_r1_06;
    uVar8 = extraout_r2_07;
LAB_0102afce:
    FUN_01039ee2((byte *)pcVar4,uVar6,uVar8,DAT_21000580);
  }
LAB_0102afd2:
  iVar10 = 0x14;
  do {
    local_38 = 0;
    uStack_34 = 0;
    local_40 = 0x301;
    if (*DAT_210045f4 == 1) {
      uStack_3e = (undefined2)DAT_210045f4[0x31];
      uStack_3c = (undefined2)((uint)DAT_210045f4[0x31] >> 0x10);
      local_3a = (undefined2)DAT_210045f4[0x32];
    }
    else {
      uStack_3e = (undefined2)*(undefined4 *)((int)DAT_210045f4 + 0xca);
      uStack_3c = (undefined2)((uint)*(undefined4 *)((int)DAT_210045f4 + 0xca) >> 0x10);
      local_3a = *(undefined2 *)((int)DAT_210045f4 + 0xce);
    }
    uVar11 = (*(code *)DAT_210045f4[0x2a])(&local_40,0x10);
    if (1 < DAT_21000580) {
      FUN_01039ee2((byte *)"mac\n",(int)((ulonglong)uVar11 >> 0x20),extraout_r2_04,DAT_21000580);
    }
    if (-1 < (int)uVar11) break;
    FUN_01039ddc(0x32);
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar10 = 0x14;
  do {
    iVar5 = FUN_0102ae00();
    if (iVar5 == 0) break;
    FUN_01039ddc(0x32);
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  DAT_210045c0 = 0;
  if (DAT_210045f4[2] == 0xff) {
    FUN_0103428c(0);
    uVar6 = extraout_r1_04;
    iVar10 = extraout_r2_05;
  }
  else {
    FUN_0103428c(DAT_210045f4[2]);
    iVar10 = DAT_210045f4[2];
    DAT_21004b9e = (undefined1)iVar10;
    uVar6 = extraout_r1_07;
  }
  if ((1 < DAT_21000580) &&
     (FUN_01039ee2((byte *)"addr 0 0x%02X-0x%02X-0x%02X-0x%02X\n",(uint)DAT_21000767,
                   (uint)DAT_21000768,(uint)DAT_21000769), uVar6 = extraout_r1_08,
     iVar10 = extraout_r2_08, 1 < DAT_21000580)) {
    FUN_01039ee2((byte *)"addr 1 0x%02X-0x%02X-0x%02X-0x%02X\n",(uint)DAT_21000763,
                 (uint)DAT_21000764,(uint)DAT_21000765);
    uVar6 = extraout_r1_09;
    iVar10 = extraout_r2_09;
  }
  iVar5 = *DAT_210045f4;
  if ((iVar5 == 1) || (iVar5 == 2)) {
    FUN_0102ba6c(DAT_210045f4 + 0x2c,uVar6,iVar10,iVar5);
    FUN_0102b77c();
    FUN_01039ddc(1000);
    (*(code *)DAT_210045f4[0x2c])();
    iVar5 = *DAT_210045f4;
    iVar10 = extraout_r2_10;
    if (iVar5 == 1) {
      uVar6 = 0;
      goto LAB_0102b11a;
    }
  }
  uVar6 = 1;
LAB_0102b11a:
  uVar7 = FUN_0102bd7c(uVar6,&LAB_0102acc8_1,iVar10,iVar5);
  if ((uVar7 & 0xff) != 0) {
    if (0 < DAT_21000580) {
      FUN_01039ee2((byte *)"esb init failed %d\n",uVar7 & 0xff,extraout_r2_11,DAT_21000580);
    }
    return 0;
  }
  iVar10 = 0x14;
  do {
    local_40 = 0;
    uStack_3e = 0;
    FUN_0103bdee((undefined1 *)&uStack_3c,0,0x1c);
    local_40 = 0x601;
    FUN_0102aa58((char *)&uStack_3e,"2025-06-28 17:32:14");
    uVar11 = (*(code *)DAT_210045f4[0x2a])(&local_40,0x20);
    if (1 < DAT_21000580) {
      FUN_01039ee2((byte *)"bt\n",(int)((ulonglong)uVar11 >> 0x20),extraout_r2_12,DAT_21000580);
    }
    if (-1 < (int)uVar11) break;
    FUN_01039ddc(100);
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_0102ae00();
  iVar10 = 0;
  do {
    iVar5 = FUN_0102bf78();
    uVar12 = CONCAT44(DAT_21001d04,DAT_21001d00);
    if ((iVar5 != 3) && (uVar12 = CONCAT44(DAT_21001d04,DAT_21001d00), DAT_210045f4[1] != 1)) {
      uVar12 = FUN_01038a44();
      DAT_21001d04 = (int)(uVar12 >> 0x20);
      DAT_21001d00 = (undefined4)uVar12;
      lVar1 = (uVar12 & 0xffffffff) * 1000;
      uVar7 = (uint)lVar1;
      uVar9 = DAT_21001d04 * 1000 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffff8000 < uVar7);
      DAT_21001cf8 = uVar7 + 0x7fff >> 0xf | uVar9 * 0x20000;
      DAT_21001cfc = uVar9 >> 0xf;
      if (DAT_21004c9e < 0x33) {
        if (DAT_21004c9e < 0x28) {
          if (DAT_21004c9f < 0x33) {
            iVar10 = 0;
          }
          else {
            iVar10 = 3;
          }
        }
      }
      else if (DAT_21004c9f - 1 < 0x27) {
        iVar10 = iVar10 + 1;
      }
      else {
        iVar10 = 0;
      }
      if (DAT_21001cfc - DAT_21001cec == (uint)(DAT_21001cf8 < DAT_21001ce8) &&
          (uint)(&DAT_0000270f < (undefined *)(DAT_21001cf8 - DAT_21001ce8)) <=
          (DAT_21001cfc - DAT_21001cec) - (uint)(DAT_21001cf8 < DAT_21001ce8)) {
        if (DAT_21004c9f < 0x28) {
          if (0x32 < DAT_21004c9e) {
LAB_0102b2b2:
            if (2 < iVar10) {
              cVar2 = FUN_0102ab94();
              uVar12 = CONCAT44(DAT_21001d04,DAT_21001d00);
              if (cVar2 != '\0') {
                DAT_21001ce8 = DAT_21001cf8;
                DAT_21001cec = DAT_21001cfc;
                DAT_21004c9e = DAT_21004c9f;
                iVar10 = 0;
                uVar12 = CONCAT44(DAT_21001d04,DAT_21001d00);
              }
            }
          }
        }
        else if ((0x32 < DAT_21004c9f) && (DAT_21004c9e < 0x28)) goto LAB_0102b2b2;
      }
      else {
        DAT_21001ce8 = DAT_21001cf8;
        DAT_21001cec = DAT_21001cfc;
        FUN_0102ab94();
        uVar12 = CONCAT44(DAT_21001d04,DAT_21001d00);
      }
    }
    DAT_21001d04 = (int)(uVar12 >> 0x20);
    DAT_21001d00 = (undefined4)uVar12;
    FUN_01039ddc(1000);
  } while( true );
}



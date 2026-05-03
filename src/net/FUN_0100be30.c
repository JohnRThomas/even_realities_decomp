/*
 * Function: FUN_0100be30
 * Entry:    0100be30
 * Prototype: undefined __stdcall FUN_0100be30(int param_1, int * param_2)
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0100be30(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  ushort extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar8;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 extraout_r3;
  uint uVar12;
  byte *extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar13;
  int iVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  char local_49;
  int local_48;
  undefined4 *local_44;
  int iStack_40;
  int iStack_3c;
  int *piStack_38;
  undefined4 *puStack_34;
  ushort uStack_1e;
  int local_1c;
  
  iVar2 = DAT_21000c70;
  iVar14 = DAT_21000c70 + 0xa8;
  if (-1 < param_1 << 0x1e) {
LAB_0100be46:
    if (param_1 << 0x1f < 0) {
      uVar10 = *(uint *)(iVar2 + 0x128);
      *(uint *)(iVar2 + 0x128) = uVar10 + 1;
      *(uint *)(iVar2 + 300) = *(int *)(iVar2 + 300) + (uint)(0xfffffffe < uVar10);
      *(bool *)(iVar2 + 0xc0) = *(char *)(iVar2 + 0xc0) != '\x01';
    }
    return;
  }
  if (DAT_21000c80 != (undefined4 *)0x0) {
    bVar1 = DAT_21000c74[1];
    DAT_21000c74 = (byte *)FUN_01026198(DAT_21000c80,(undefined4 *)DAT_21000c74,DAT_21000d04 + 3);
    FUN_0102794a(DAT_21000d10,&local_1c,&uStack_1e);
    iVar14 = FUN_010278d2(local_1c);
    *param_2 = iVar14;
    FUN_01027732((short *)DAT_21000d10,(ushort)bVar1,'\x01');
    goto LAB_0100be46;
  }
  FUN_01009500(0x27,0x45f,param_1 << 0x1e,0);
  iVar2 = DAT_21000c70;
  uVar5 = extraout_r1_00 >> 0x11;
  puStack_34 = &DAT_21000c48;
  local_49 = '\0';
  local_48 = 0;
  local_44 = (undefined4 *)0x0;
  uVar10 = (uint)DAT_21000c8c;
  iStack_40 = iVar14;
  iStack_3c = param_1;
  piStack_38 = param_2;
  if (DAT_21000c8c != 2) {
    FUN_01009500(0x27,0x4e2,extraout_r2,(uint)DAT_21000c8c);
    uVar9 = extraout_r2_04;
    uVar13 = extraout_r3_02;
LAB_0100c206:
    FUN_01009500(0x27,0x3dd,uVar9,uVar13);
    uVar9 = extraout_r2_05;
    uVar13 = extraout_r3_03;
LAB_0100c210:
    FUN_01009500(0x27,0x3f4,uVar9,uVar13);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar15 = (ulonglong)CONCAT24(DAT_21000c78,uVar5) & 0x40ffffffff;
  uVar9 = extraout_r2;
  if ((DAT_21000c78 & 0x40) == 0) {
    uVar15 = (*DAT_21000c7c)(0x40);
    DAT_21000c78 = DAT_21000c78 | 0x40;
    uVar9 = extraout_r2_00;
  }
  if (uVar5 == 0) {
    if (*(char *)(iVar2 + 0xcb) != '\0') {
      FUN_01020848();
    }
    DAT_21000c78 = DAT_21000c78 | 0x200;
    uVar12 = 0;
    DAT_21000d0c = DAT_21000d0c + 1;
    goto LAB_0100bfd8;
  }
  if (*(char *)(iVar2 + 0xcb) == '\0') {
    uVar7 = (ushort)DAT_21000c74[1];
  }
  else {
    uVar16 = FUN_010207d4((int)uVar15,(int)(uVar15 >> 0x20),uVar9);
    uVar12 = FUN_0102079c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_01);
    uVar7 = (ushort)DAT_21000c74[1];
    if (uVar12 == 0) {
      pbVar11 = DAT_21000c74;
      if (uVar7 == 0) goto LAB_0100bf10;
      if ((uint)*(byte *)(iVar2 + 0xc0) == ((uint)*DAT_21000c74 << 0x1c) >> 0x1f) {
        DAT_21000c86 = 1;
        FUN_0100b434();
        goto LAB_0100c0c0;
      }
      DAT_21000d04 = (ushort)DAT_21000c74[1];
      goto LAB_0100c148;
    }
  }
  DAT_21000d04 = uVar7;
  pbVar11 = DAT_21000c74;
  uVar7 = DAT_21000d04;
  if (DAT_21000d04 == 0) goto LAB_0100bf10;
LAB_0100c148:
  DAT_21000c80 = (undefined4 *)FUN_01027648(DAT_21000d10,DAT_21000d04);
  pbVar11 = DAT_21000c74;
  do {
    iVar14 = DAT_21000c70;
    uVar8 = (uint)*pbVar11;
    DAT_21000c78 = DAT_21000c78 | 0x100;
    uVar12 = uVar5;
    if ((uint)*(byte *)(iVar2 + 0xbf) != (uVar8 << 0x1d) >> 0x1f) {
      if (*(char *)(DAT_21000c70 + 0xbe) != '\0') {
        cVar3 = (char)DAT_21000c6c;
        if (*(char *)(DAT_21000c70 + 0xbe) == '\x02') {
          iVar6 = FUN_010273fe(DAT_21000cc8,&local_48);
          cVar3 = (char)DAT_21000c6c;
          uVar9 = extraout_r2_03;
          uVar13 = extraout_r3_01;
          if (iVar6 == 0) goto LAB_0100c206;
          uVar12 = *(uint *)(iVar14 + 0x120);
          *(uint *)(iVar14 + 0x120) = uVar12 + 1;
          *(uint *)(iVar14 + 0x124) = *(int *)(iVar14 + 0x124) + (uint)(0xfffffffe < uVar12);
        }
        *(undefined1 *)(iVar14 + 0xbe) = 0;
        if ((cVar3 != '\0') && (*(char *)(iVar14 + 0xba) != '\0')) {
          *(undefined1 *)(iVar14 + 0xba) = 0;
          DAT_21000c7a = DAT_21000c7a | 0x10;
          (*DAT_21000c7c)(0x10);
        }
        if (*(char *)(iVar14 + 0xb9) != '\0') {
          *(undefined1 *)(iVar14 + 0xb9) = 0;
          iVar6 = FUN_0100b184();
          uVar9 = extraout_r2_02;
          uVar13 = extraout_r3;
          if (iVar6 == 0) goto LAB_0100c210;
          DAT_21000c7a = DAT_21000c7a | 8;
          (*DAT_21000c7c)(8,0);
          uVar12 = *(uint *)(iVar14 + 0x120);
          *(uint *)(iVar14 + 0x120) = uVar12 + 1;
          *(uint *)(iVar14 + 0x124) = *(int *)(iVar14 + 0x124) + (uint)(0xfffffffe < uVar12);
        }
        *(bool *)(iVar14 + 0xbf) = *(char *)(iVar14 + 0xbf) != '\x01';
        uVar8 = (uint)*DAT_21000c74;
      }
      DAT_21000c78 = DAT_21000c78 | 0x400;
      uVar12 = 0;
    }
    if ((uint)*(byte *)(iVar2 + 0xc0) == (uVar8 << 0x1c) >> 0x1f) {
      cVar3 = FUN_0100fdcc();
      if (((cVar3 == '\0') || (1 < (*DAT_21000c74 & 3) - 1)) || (DAT_21000c74[1] <= DAT_21000d14)) {
        FUN_0100b3a4(&local_49);
      }
      else {
        DAT_21000c85 = DAT_21000c85 | 0x10;
      }
    }
LAB_0100bfd8:
    if (*(char *)(iVar2 + 0xca) == '\0') goto LAB_0100c02e;
    DAT_21000ce8 = (char)DAT_21000c6c == '\0';
    if (*(undefined **)(DAT_21000c70 + 0x14) < &DAT_00001d4c) {
      uVar8 = 4;
    }
    else {
      uVar8 = 0;
    }
    DAT_21000ce0 = *(undefined4 *)(iVar2 + 0x120);
    DAT_21000ce4 = *(undefined4 *)(iVar2 + 0x124);
    switch(*(undefined1 *)(DAT_21000c70 + 0x6e)) {
    case 1:
      goto switchD_0100c010_caseD_1;
    case 2:
      uVar10 = 1;
      goto switchD_0100c010_caseD_8;
    default:
      FUN_01009500(6,0x3c5,DAT_21000ce0,DAT_21000ce4);
      pbVar11 = extraout_r3_00;
      uVar7 = extraout_r1;
LAB_0100bf10:
      DAT_21000d04 = uVar7;
      DAT_21000c80 = (undefined4 *)0x0;
      break;
    case 4:
      uVar10 = 3;
    case 8:
      goto switchD_0100c010_caseD_8;
    }
  } while( true );
switchD_0100c010_caseD_1:
  uVar10 = 0;
switchD_0100c010_caseD_8:
  FUN_010205d0(uVar8,(uint)&DAT_21000cd0,0xfb,uVar10,0);
LAB_0100c02e:
  if (((1 < DAT_21000d0c) || (iVar14 = (*DAT_21000d08)(1), iVar14 == 0)) ||
     ((DAT_21000c85 != 0 || (bVar4 = FUN_0100b6ac(1), bVar4)))) {
    FUN_010211b8();
    bVar4 = true;
  }
  else {
    FUN_0100b498(0);
    bVar4 = false;
  }
  if (local_49 != '\0') {
    FUN_0100be30(2,(int *)&local_44);
  }
  if ((uVar12 != 0) &&
     (((char)DAT_21000c6c == '\0' ||
      ((DAT_21000c4d != 0 || DAT_21000c4f != 0) || *(short *)(iVar2 + 0xbc) != 0)))) {
    DAT_21000c51 = DAT_21000c51 + 1;
  }
  if (uVar5 == 0) {
    DAT_21000c4f = DAT_21000c4f + 1;
  }
  else {
    DAT_21000c4d = DAT_21000c4d + 1;
    DAT_21000d0c = 0;
  }
  FUN_01010d78((char *)&DAT_21000c6c);
  if (local_48 != 0) {
    iVar14 = FUN_010278d2(local_48);
    iVar2 = DAT_21000c70;
    *(undefined1 *)(iVar14 + 9) = 0;
    FUN_0100f788((undefined4 *)(iVar14 + 1),iVar2,8);
  }
  iVar2 = DAT_21000c70;
  if (local_44 != (undefined4 *)0x0) {
                    /* WARNING (jumptable): Read-only address (ram,0x00000008) is written */
    *(undefined1 *)(local_44 + 2) = 0;
    FUN_0100f788(local_44,iVar2,0x10);
  }
  if (bVar4) {
    FUN_0100b434();
                    /* WARNING: Could not recover jumptable at 0x0100c0f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)0x100beb1)();
    return;
  }
LAB_0100c0c0:
                    /* WARNING: Could not recover jumptable at 0x0100c0c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x100beb1)();
  return;
}



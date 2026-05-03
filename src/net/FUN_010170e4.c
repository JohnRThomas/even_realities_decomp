/*
 * Function: FUN_010170e4
 * Entry:    010170e4
 * Prototype: undefined4 __stdcall FUN_010170e4(uint param_1, undefined1 * param_2, undefined4 param_3)
 */


/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_010170e4(uint param_1,undefined1 *param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined *extraout_r1;
  undefined *puVar9;
  undefined *extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  char *pcVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint extraout_r3;
  undefined *extraout_r3_00;
  char cVar13;
  byte bVar14;
  bool bVar15;
  
  cVar13 = DAT_21001012;
  cVar1 = DAT_2100001c;
  uVar7 = param_1;
  switch(param_2) {
  case (undefined1 *)0x0:
    if (DAT_21001012 == '\0') goto switchD_010170f0_caseD_3;
    uVar11 = (uint)DAT_21000fe4;
    if (uVar11 == 2) {
      puVar12 = &DAT_2100001c;
      puVar9 = (undefined *)(int)DAT_2100001c;
      if (puVar9 != (undefined *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)0x0,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,cVar1);
        DAT_21001038 = 1;
        return 0xb;
      }
    }
    else {
      if (uVar11 != 1) {
        if (uVar11 == 3) {
          pcVar10 = *(char **)(param_1 + 4);
          if ((((*pcVar10 == (char)DAT_21000fec) && (pcVar10[1] == DAT_21000fec._1_1_)) &&
              (pcVar10[2] == DAT_21000fec._2_1_)) &&
             (((pcVar10[3] == DAT_21000fec._3_1_ && (pcVar10[4] == (char)DAT_21000ff0)) &&
              ((pcVar10[5] == DAT_21000ff0._1_1_ && (*(char *)(param_1 + 0x11) == DAT_21000feb))))))
          {
            return 0xc;
          }
          if (DAT_21000fe6 == '\x01') {
            return 0xc;
          }
          if ((DAT_2100100b != 8) && (DAT_21001008 == DAT_2100100b)) {
            return 0xc;
          }
          goto switchD_010170f0_caseD_3;
        }
        goto LAB_010174ba;
      }
      puVar12 = &DAT_2100001c;
      puVar9 = (undefined *)(int)DAT_2100001c;
      if (puVar9 != (undefined *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)0x0,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,cVar1);
        return 5;
      }
    }
    break;
  case (undefined1 *)0x1:
    bVar14 = DAT_2100100d ^ 1;
    if ((*(char *)(param_1 + 0x12) == '\x01') &&
       ((*(byte *)(*(int *)(param_1 + 8) + 5) & 0xc0) == 0x40)) {
      bVar15 = true;
    }
    else {
      bVar15 = false;
    }
    bVar2 = DAT_21001008;
    if ((DAT_21000fe4 == 3) && (DAT_21000fdd != '\0')) {
      bVar2 = DAT_2100100b;
    }
    puVar5 = (undefined4 *)FUN_0100d268((uint)bVar2);
    if (puVar5 == (undefined4 *)0x0) {
LAB_01017182:
      bVar4 = false;
      uVar7 = (uint)DAT_21000fd5;
      uVar11 = uVar7;
    }
    else {
      bVar2 = FUN_0100c404((uint)bVar2);
      if (bVar2 != 0) {
        bVar14 = bVar2;
      }
      if (!bVar15) goto LAB_01017182;
      bVar4 = FUN_0100b2ac(puVar5,*(char **)(param_1 + 8));
      uVar7 = (uint)DAT_21000fd5;
      uVar11 = uVar7;
      if (bVar4) {
        uVar11 = uVar7 | 2;
      }
    }
    if (DAT_21000fe4 == 3) {
      pcVar10 = *(char **)(param_1 + 4);
      if (((((*pcVar10 == (char)DAT_21000fec) && (pcVar10[1] == DAT_21000fec._1_1_)) &&
           (pcVar10[2] == DAT_21000fec._2_1_)) &&
          ((pcVar10[3] == DAT_21000fec._3_1_ && (pcVar10[4] == (char)DAT_21000ff0)))) &&
         (pcVar10[5] == DAT_21000ff0._1_1_)) {
        bVar15 = *(char *)(param_1 + 0x11) == DAT_21000feb;
      }
      else {
        bVar15 = false;
      }
      if ((DAT_21001008 != 8) && (DAT_2100100b == DAT_21001008)) {
        bVar15 = true;
      }
      if (bVar4 == false) {
        bVar4 = false;
        if (bVar14 != 0) {
          bVar4 = FUN_0100b23c(uVar7,(byte *)&DAT_21000fd6,(uint)*(byte *)(param_1 + 0x12),
                               *(byte **)(param_1 + 8));
        }
      }
      else {
        bVar4 = true;
      }
      if ((cVar13 != '\0') &&
         (((DAT_21000fe6 == '\x01' || ((DAT_21000fe6 == '\0' && (bVar15)))) && (bVar4 != false)))) {
        return 0xc;
      }
switchD_010170f0_caseD_3:
      FUN_01020d00();
      return 5;
    }
    FUN_01020d00();
    if (cVar13 == '\0') {
      return 5;
    }
    bVar3 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,(uint)*(byte *)(param_1 + 0x12),
                         *(byte **)(param_1 + 8));
    cVar1 = DAT_2100001c;
    uVar7 = (uint)bVar3;
    if ((uVar7 == 0) && (bVar4 == false)) {
      if ((1 < DAT_21000fe5 - 2) || (!bVar15)) {
        return 5;
      }
      puVar12 = &DAT_2100001c;
      puVar9 = (undefined *)(int)DAT_2100001c;
      param_2 = extraout_r1;
      if (puVar9 != (undefined *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)&DAT_00000001,&DAT_21000fd6,0xfe,DAT_21001009,DAT_2100101f,
                     cVar1);
        return 5;
      }
    }
    else {
      param_2 = &DAT_2100001c;
      puVar12 = (undefined1 *)(int)DAT_2100001c;
      puVar9 = extraout_r2;
      if (puVar12 != (undefined1 *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)&DAT_00000001,&DAT_21000fd6,uVar11,DAT_21001009,DAT_2100101f,
                     cVar1);
        return 5;
      }
    }
    break;
  case (undefined1 *)0x2:
    uVar7 = FUN_01020d00();
    cVar1 = DAT_2100001c;
    puVar9 = &DAT_21000f90;
    if (DAT_21001012 == '\0') {
      return 5;
    }
    if (1 < DAT_21000fe4 - 1) {
      return 5;
    }
    puVar12 = &DAT_2100001c;
    param_2 = (undefined1 *)(int)DAT_2100001c;
    if (param_2 != &UNK_0000007f) {
      DAT_2100001c = 0x7f;
      FUN_01019f50(param_1,(short *)&LAB_00000002,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,cVar1
                  );
      return 5;
    }
    break;
  default:
    goto switchD_010170f0_caseD_3;
  case (undefined1 *)0x6:
    if (DAT_21001012 == '\0') goto switchD_010170f0_caseD_3;
    if (DAT_21000fe4 == 2) {
      puVar12 = &DAT_2100001c;
      puVar9 = (undefined *)(int)DAT_2100001c;
      if (puVar9 != (undefined *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)&LAB_00000006,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,
                     cVar1);
        DAT_21001038 = 0;
        return 0xb;
      }
    }
    else {
      if (DAT_21000fe4 != 1) goto switchD_010170f0_caseD_3;
      puVar12 = &DAT_2100001c;
      puVar9 = (undefined *)(int)DAT_2100001c;
      if (puVar9 != (undefined *)0x7f) {
        DAT_2100001c = 0x7f;
        FUN_01019f50(param_1,(short *)&LAB_00000006,&DAT_21000fd6,0xff,DAT_21001009,DAT_2100101f,
                     cVar1);
        return 5;
      }
    }
  }
  FUN_01017028(uVar7,param_2,puVar9,puVar12);
  param_3 = extraout_r2_00;
  uVar11 = extraout_r3;
LAB_010174ba:
  puVar6 = (ushort *)FUN_01009500(0x32,0xed2,param_3,uVar11);
  cVar1 = DAT_2100001c;
  if (DAT_2100001c == '\x7f') {
    FUN_01017028(puVar6,0,0x7f,&DAT_2100001c);
    puVar9 = &DAT_21000f90;
    if (DAT_21001000 < 5) {
      FUN_01009500(0x32,&DAT_0000164b,(uint)DAT_21001000,&DAT_21000f90);
      uVar7 = extraout_r2_02;
      puVar9 = extraout_r3_00;
    }
    else {
      uVar7 = (uint)DAT_21001000;
      if (uVar7 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0101755a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar8 = (**(code **)(*(int *)(DAT_21001054 + 0xc) + (DAT_21001000 + 0x3ffffffb) * 4))
                          (extraout_r2_01 >> 0x1e);
        return uVar8;
      }
    }
    FUN_01009500(0x32,&DAT_0000164c,uVar7,puVar9);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_2100001c = 0x7f;
  if (DAT_21001000 == 5) {
    cVar13 = '\0';
  }
  else if (DAT_21001000 == 8) {
    cVar13 = '\x03';
  }
  else {
    cVar13 = '\x01';
  }
  uVar7 = FUN_0101a2a0(puVar6,0,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009,cVar1,
                       cVar13);
  if (uVar7 == 0) {
    return 0;
  }
  uVar8 = FUN_01019e60();
  return uVar8;
}



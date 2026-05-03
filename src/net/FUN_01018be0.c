/*
 * Function: FUN_01018be0
 * Entry:    01018be0
 * Prototype: undefined4 __stdcall FUN_01018be0(ushort * param_1)
 */


undefined4 FUN_01018be0(ushort *param_1)

{
  byte bVar1;
  bool bVar2;
  undefined *puVar4;
  int iVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar6;
  undefined1 *puVar7;
  uint extraout_r2;
  uint *extraout_r2_00;
  uint *puVar8;
  uint extraout_r2_01;
  undefined1 *puVar9;
  undefined4 uVar10;
  char cVar11;
  undefined1 uVar12;
  char cVar13;
  undefined8 uVar14;
  undefined2 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint uStackY_3c;
  ushort *puStackY_38;
  code *UNRECOVERED_JUMPTABLE_00;
  char local_1b;
  char local_1a;
  byte local_19;
  uint uVar3;
  
  if (DAT_21000fe7 == '\0') goto LAB_01018c06;
  if (DAT_21001012 == '\0') {
    if (DAT_21001013 == '\0') goto LAB_01018c06;
    cVar11 = (char)*param_1;
    if (cVar11 == '\x01') goto LAB_01018c20;
LAB_01018bfc:
    if (cVar11 == '\x02') {
      uVar14 = FUN_01020d00();
      cVar11 = DAT_2100001c;
      if (DAT_21000fe4 == '\x03') {
        return 5;
      }
      if ((*param_1 & 0x1800) != 0x1800) {
        return 5;
      }
      puVar7 = &DAT_2100001c;
      puVar9 = (undefined1 *)(int)DAT_2100001c;
      if (puVar9 != (undefined1 *)0x7f) {
        DAT_2100001c = 0x7f;
        uVar6 = FUN_0101a2a0(param_1,0xff,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009
                             ,cVar11,'\0');
        if (uVar6 == 0) {
          return 5;
        }
        uVar12 = 2;
LAB_01018d4a:
        puVar4 = FUN_01017818(1,*(byte **)(param_1 + 0xc));
        if (puVar4 == (undefined *)0x0) {
          return 5;
        }
        DAT_21001018 = uVar12;
        return 3;
      }
    }
    else {
      if (cVar11 != '\0') {
LAB_01018c06:
        FUN_01020d00();
        return 5;
      }
      uVar14 = FUN_01020d00();
      if (DAT_21000fe4 == '\x03') {
        return 5;
      }
      bVar1 = *(byte *)((int)param_1 + 1);
      if ((bVar1 & 0x10) == 0) {
        uVar6 = 1;
      }
      else {
        uVar6 = 8;
      }
      if ((uVar6 & ~(uint)bVar1) != 0) {
        return 5;
      }
      local_1b = '\0';
      local_1a = '\0';
      local_19 = 0;
      if (*(int *)(param_1 + 4) == 0) {
        uVar6 = 0xff;
      }
      else {
        uVar14 = FUN_01017e58((int)param_1,&local_1a,&local_1b,&local_19);
        uVar6 = (uint)DAT_21000fd5;
        if (local_1b == '\0') {
          bVar2 = FUN_0100b23c(uVar6,(byte *)&DAT_21000fd6,(uint)(byte)param_1[9],
                               *(byte **)(param_1 + 4));
          uVar3 = (uint)bVar2;
          uVar14 = CONCAT44(extraout_r1,uVar3);
          if (uVar3 == 0) {
            if (1 < DAT_21000fe5 - 2) {
              return 5;
            }
            if (local_1a == '\0') {
              return 5;
            }
            if (local_1b != '\0') {
              return 5;
            }
            uVar6 = 0xfe;
            uVar14 = CONCAT44(extraout_r1,uVar3);
          }
        }
        else {
          uVar6 = uVar6 | 2;
        }
      }
      cVar11 = DAT_2100001c;
      puVar7 = &DAT_2100001c;
      puVar9 = (undefined1 *)(int)DAT_2100001c;
      if ((int)((uint)bVar1 << 0x1b) < 0) {
        if (puVar9 != (undefined1 *)0x7f) {
          uVar12 = 0;
          DAT_2100001c = 0x7f;
          uVar6 = FUN_0101a2a0(param_1,uVar6,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,
                               DAT_21001009,cVar11,'\0');
          if (uVar6 == 0) {
            return 5;
          }
          goto LAB_01018d4a;
        }
      }
      else if (puVar9 != (undefined1 *)0x7f) {
        DAT_2100001c = 0x7f;
        cVar13 = '\0';
        if (DAT_21001000 != '\x05') {
          if (DAT_21001000 == '\b') {
            cVar13 = '\x03';
          }
          else {
            cVar13 = '\x01';
          }
        }
        uVar6 = FUN_0101a2a0(param_1,uVar6,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,
                             DAT_21001009,cVar11,cVar13);
        if (uVar6 == 0) {
          return 5;
        }
        FUN_01019e60();
        return 5;
      }
    }
  }
  else {
    cVar11 = (char)*param_1;
    if (cVar11 != '\x01') goto LAB_01018bfc;
LAB_01018c20:
    uVar14 = FUN_01020d00();
    if (DAT_21001049 == 2) {
      if ((*param_1 & 0x1900) != 0x1900) {
        return 5;
      }
    }
    else if ((*param_1 & 0x1800) != 0x1800) {
      return 5;
    }
    if (DAT_21000fe4 == '\x03') {
      if (*(int *)(param_1 + 2) != 0) {
        bVar2 = FUN_0100b23c((uint)DAT_21001020,(byte *)&DAT_21001019,(uint)DAT_21000feb,
                             (byte *)&DAT_21000fec);
        uVar6 = (uint)bVar2;
        uVar14 = CONCAT44(extraout_r1_00,uVar6);
        if (DAT_21000fe6 != '\x01') {
          if (DAT_21000fe6 != '\0') {
            return 5;
          }
          uVar14 = CONCAT44(extraout_r1_00,uVar6);
          if ((uVar6 == 0) &&
             (uVar14 = CONCAT44(extraout_r1_00,uVar6), DAT_21001008 != DAT_2100100b)) {
            return 5;
          }
        }
      }
      if (*(int *)(param_1 + 4) != 0) {
        return 5;
      }
      cVar11 = DAT_2100100e;
      if ((((*(byte *)(*(int *)(param_1 + 0xc) + 2) & 0xe0) == 0) ||
          (cVar11 = DAT_2100100f, (*(byte *)(*(int *)(param_1 + 0xc) + 2) & 0xe0) == 0x40)) &&
         (cVar11 == '\0')) {
        return 5;
      }
    }
    cVar11 = DAT_2100001c;
    puVar9 = &DAT_2100001c;
    puVar7 = (undefined1 *)(int)DAT_2100001c;
    if (puVar7 != (undefined1 *)0x7f) {
      DAT_2100001c = 0x7f;
      uVar6 = FUN_0101a2a0(param_1,0xff,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009,
                           cVar11,'\0');
      if (uVar6 == 0) {
        return 5;
      }
      puVar4 = FUN_01017818(1,*(byte **)(param_1 + 0xc));
      if (puVar4 == (undefined *)0x0) {
        return 5;
      }
      DAT_21001018 = 1;
      return 3;
    }
  }
  FUN_01017028((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),puVar7,puVar9);
  uStackY_3c = (uint)param_1 >> 0x1f;
  UNRECOVERED_JUMPTABLE_00 = (code *)0x1018e7f;
  puStackY_38 = param_1;
  iVar5 = FUN_0100df60();
  puVar7 = (undefined1 *)(*(byte *)(extraout_r2 >> 0x1e) & 0xf);
  DAT_2100001c = (char)iVar5;
  FUN_0101a870((byte *)(extraout_r2 >> 0x1e),(byte *)&local_68);
  if (puVar7 == &LAB_00000006_1) {
    if ((byte)local_68 == 2) {
      local_64 = 0;
      local_60 = 0;
      bVar1 = local_68._1_1_ & 0xfc;
      goto LAB_01018f70;
    }
    uVar6 = (uint)DAT_21001049;
    if ((byte)local_68 == 1) goto LAB_01018fb6;
    bVar1 = local_68._1_1_;
    if ((byte)local_68 != 0) goto LAB_01018f70;
    if ((DAT_21001049 & 0xc) == 0) goto LAB_01018f70;
    if (-1 < (int)((uint)local_68._1_1_ << 0x1b)) goto LAB_01018f70;
    local_64 = 0;
    local_60 = 0;
    bVar1 = local_68._1_1_ & 0xfc;
    goto LAB_01018f70;
  }
  FUN_01017c6c((int)&local_68,(uint)puVar7,0);
  iVar5 = DAT_21001049 - 1;
  puVar8 = extraout_r2_00;
  switch(DAT_21001049) {
  case 1:
    if ((puVar7 == &LAB_00000006) || ((puVar7 < &LAB_00000006_1 && (puVar7 < &LAB_00000002_1)))) {
      uVar10 = FUN_010170e4((uint)&local_68,puVar7,extraout_r2_00);
      goto joined_r0x01018f04;
    }
    break;
  case 2:
    break;
  default:
    do {
      FUN_01009500(0x32,&DAT_000013b3,puVar8,iVar5);
      uVar6 = extraout_r2_01;
LAB_01018fb6:
      local_60 = 0;
      bVar1 = local_68._1_1_ & 0xfd;
      if (uVar6 != 2) {
        local_64 = 0;
        bVar1 = local_68._1_1_ & 0xfc;
      }
LAB_01018f70:
      local_68._1_1_ = bVar1;
      FUN_01017c6c((int)&local_68,7,0);
      iVar5 = DAT_21001049 - 1;
      puVar8 = &switchD_01018f86::switchdataD_01018f8c;
      switch(iVar5) {
      case 0:
      case 3:
      case 7:
        goto switchD_01018f86_caseD_1;
      case 1:
        if ((byte)local_68 != 1) goto switchD_01018ec8_caseD_2;
        goto switchD_01018f86_caseD_1;
      }
    } while( true );
  case 4:
  case 8:
    if (puVar7 == &LAB_00000006_1) {
switchD_01018f86_caseD_1:
      uVar10 = FUN_01018be0(&local_68);
      goto joined_r0x01018f04;
    }
  }
switchD_01018ec8_caseD_2:
  uVar10 = 5;
  FUN_01020d00();
joined_r0x01018f04:
  if (DAT_2100100c == '\0') {
                    /* WARNING: Could not recover jumptable at 0x01018ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar10 = (*UNRECOVERED_JUMPTABLE_00)(uVar10);
    return uVar10;
  }
  FUN_010210b0();
  FUN_010204a8();
  DAT_2100100c = 0;
                    /* WARNING: Could not recover jumptable at 0x01018f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar10 = (*UNRECOVERED_JUMPTABLE_00)(uVar10);
  return uVar10;
}



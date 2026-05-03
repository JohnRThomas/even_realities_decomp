/*
 * Function: FUN_010185d8
 * Entry:    010185d8
 * Prototype: undefined __stdcall FUN_010185d8(void)
 */


/* WARNING: Possible PIC construction at 0x0101889e: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0101889e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010185d8(void)

{
  byte bVar1;
  bool bVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  int extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined *extraout_r3_04;
  ushort *puVar6;
  uint uVar7;
  undefined *puVar8;
  undefined *unaff_r7;
  undefined **ppuVar9;
  undefined *puVar10;
  undefined *puStack_20;
  uint uStack_1c;
  ushort *puStack_18;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_2100104c < 0x60) {
    uVar7 = (uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
  }
  else {
    uVar7 = 0;
  }
  if (DAT_21001004 != 0) {
    puVar3 = (ushort *)FUN_0100ada0();
    bVar1 = FUN_0100adb4();
    uVar4 = FUN_01027648(puVar3,(ushort)bVar1);
    if (uVar4 == 0) {
      FUN_01009500(0x32,0x5db,extraout_r2,extraout_r3);
      *(int *)extraout_r2_00 = extraout_r2_00;
      *(undefined4 *)(extraout_r2_00 + 4) = extraout_r3_00;
      UNRECOVERED_JUMPTABLE = (code *)0x101867d;
      ppuVar9 = &puStack_20;
      puStack_20 = &DAT_21000f90;
      puVar6 = (ushort *)&DAT_21000f90;
      if (DAT_2100104c < 0x60) {
        puVar8 = (undefined *)(uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
      }
      else {
        puVar8 = (undefined *)0x0;
      }
      uStack_1c = uVar7;
      puStack_18 = puVar3;
      if (DAT_21001004 != 0) {
        puVar3 = (ushort *)FUN_0100ada0();
        bVar1 = FUN_0100adb4();
        uVar7 = FUN_01027648(puVar3,(ushort)bVar1);
        if (uVar7 == 0) {
          puVar10 = (undefined *)0x1018775;
          FUN_01009500(0x32,0x5db,extraout_r2_01,extraout_r3_01);
          *(int *)extraout_r2_02 = extraout_r2_02;
          *(undefined4 *)(extraout_r2_02 + 4) = extraout_r3_02;
          while( true ) {
            ppuVar9[-1] = puVar10;
            ppuVar9[-2] = unaff_r7;
            ppuVar9[-3] = puVar8;
            ppuVar9[-4] = (undefined *)puVar6;
            puVar6 = (ushort *)FUN_0100ada0();
            bVar1 = FUN_0100adb4();
            uVar7 = FUN_01027648(puVar6,(ushort)bVar1);
            if (uVar7 != 0) break;
            FUN_01009500(0x32,0x509,extraout_r2_03,extraout_r3_03);
            ppuVar9[-7] = (undefined *)0x1018883;
            ppuVar9[-8] = extraout_r3_04;
            iVar5 = FUN_0100df60();
            DAT_2100001c = (undefined1)iVar5;
            FUN_01020d00();
            puVar10 = ppuVar9[-7];
            ppuVar9 = ppuVar9 + -6;
          }
          FUN_01019df8();
          bVar1 = (&DAT_2100104d)[DAT_21001028];
          DAT_21001049 = bVar1;
          puVar8 = FUN_0101b95c(0);
          if (puVar8 == (undefined *)0x0) {
            puVar8 = (undefined *)0x0;
            if (DAT_2100100c != '\0') {
              ppuVar9[-5] = (undefined *)0x0;
              FUN_010210b0();
              FUN_010204a8();
              puVar8 = ppuVar9[-5];
              DAT_2100100c = (char)puVar8;
            }
            DAT_2100104a = 0;
            DAT_21001000 = 1;
            DAT_2100104c = 0;
            FUN_0101bcf4(puVar8);
            return;
          }
          if (DAT_21001000 == '\x02') {
            if (bVar1 == 1) goto LAB_010187c4;
LAB_01018806:
            DAT_2100100c = FUN_0100d34c(uVar7 + 5);
            if (DAT_2100100c == '\0') goto LAB_010187d2;
            if ((bVar1 & 0xc) == 0) {
              uVar7 = 0x50;
            }
            else {
              uVar7 = 0x55;
            }
          }
          else {
            FUN_01016c30(0,uVar7);
            if (bVar1 != 1) goto LAB_01018806;
LAB_010187c4:
            DAT_2100100c = FUN_0100d34c(uVar7 + 3);
            if (DAT_2100100c == '\0') goto LAB_010187d2;
            uVar7 = 0x40;
          }
          FUN_01020470();
          FUN_01021098(uVar7);
LAB_010187d2:
          if ((DAT_21000fe4 - 2 < 2) && ((&DAT_2100104d)[DAT_21001028] == '\x01')) {
            FUN_010210f0(0,0,1);
          }
          _DAT_21001008 = 0xffff;
          _DAT_21001010 = 0;
          DAT_21001038 = 0;
          DAT_21001000 = 5;
          return;
        }
        FUN_0101766c(0,uVar7);
      }
      FUN_01020fcc(DAT_21001024);
      if (DAT_21000fe4 == 2) {
        if (DAT_21001018 == '\x02') {
LAB_01018730:
          puVar10 = puVar8;
          if ((((uint)puVar8 & 0xc) != 0) && (DAT_21000fea == '\x01')) {
            puVar10 = (undefined *)0x4;
          }
          FUN_010210f0(0,0,(uint)puVar10);
          goto joined_r0x010186d6;
        }
LAB_010186d8:
        if (DAT_21001018 == '\x01') {
          DAT_21001039 = CONCAT11(DAT_21001049 == '\x02',DAT_21001049 == '\x02');
          goto LAB_010186de;
        }
      }
      else {
        if (DAT_21000fe4 != 3) {
joined_r0x010186d6:
          if (DAT_21001018 == '\x02') {
LAB_01018700:
            DAT_21001039 = 0;
            goto LAB_010186de;
          }
          goto LAB_010186d8;
        }
        if (DAT_21001018 == '\x01') goto LAB_01018730;
        if (DAT_21001018 == '\x02') goto LAB_01018700;
      }
      if (DAT_21001018 == '\0') {
        bVar2 = FUN_0101a1cc();
        DAT_21001039 = CONCAT11(DAT_21001039._1_1_,bVar2);
        bVar2 = FUN_01019d60();
        DAT_21001039 = CONCAT11(bVar2,(undefined1)DAT_21001039);
      }
LAB_010186de:
      DAT_21001049 = (byte)puVar8;
      _DAT_21001010 = _DAT_21001010 & 0xffffff00;
      DAT_21001000 = 7;
                    /* WARNING: Could not recover jumptable at 0x010186ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    FUN_0101766c(0,uVar4);
  }
  FUN_01020fcc(DAT_21001024);
  if (DAT_21000fe4 == 2) {
    if (DAT_21001018 != '\x02') goto LAB_01018622;
  }
  else if ((DAT_21000fe4 != 3) || (DAT_21001018 != '\x01')) goto LAB_01018622;
  uVar4 = uVar7;
  if (((uVar7 & 0xc) != 0) && (DAT_21000fea == '\x01')) {
    uVar4 = 4;
  }
  FUN_010210f0(0,0,uVar4);
LAB_01018622:
  DAT_21001049 = (char)uVar7;
  DAT_21001039 = 0x101;
  _DAT_21001010 = _DAT_21001010 & 0xffffff00;
  DAT_21001000 = 8;
  return;
}



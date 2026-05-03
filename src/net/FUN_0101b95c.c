/*
 * Function: FUN_0101b95c
 * Entry:    0101b95c
 * Prototype: undefined * __stdcall FUN_0101b95c(undefined4 param_1)
 */


/* WARNING: Type propagation algorithm not settling */

undefined * FUN_0101b95c(undefined4 param_1)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  undefined4 uVar10;
  byte *pbVar11;
  uint uVar12;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  int extraout_r2_07;
  uint uVar13;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar14;
  undefined *puVar15;
  uint uVar16;
  int iVar17;
  undefined1 *puVar18;
  int iVar19;
  uint uVar20;
  longlong lVar21;
  undefined *local_58;
  undefined *local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined *local_48;
  int local_44;
  undefined4 uStack_3c;
  int iStack_38;
  undefined1 *puStack_34;
  uint uStack_30;
  
  lVar21 = src/*FUN_01025834();
  uVar20 = DAT_210010b8;
  puVar5 = FUN_01019a04();
  uVar13 = (uint)(byte)puVar5[1];
  switch(param_1) {
  case 0:
    if (uVar13 == 8) {
      iVar6 = 0x728;
      break;
    }
    if (uVar13 == 4) {
      iVar6 = 0x140;
LAB_0101b9f4:
      iVar6 = iVar6 + 0x216;
      break;
    }
    if (uVar13 == 2) {
LAB_0101ba18:
      iVar6 = 0x48;
    }
    else {
      switch(uVar13) {
      case 1:
        iVar6 = 0x150;
        break;
      default:
        FUN_01009500(5,0x104,uVar13 - 1,uVar13);
        goto LAB_0101ba18;
      case 4:
      case 8:
        iVar6 = 0xa0;
        if (uVar13 == 4) goto LAB_0101b9f4;
      }
      if (uVar13 != 2) {
        iVar6 = iVar6 + 0xc0;
        break;
      }
    }
    iVar6 = iVar6 + 0xb0;
    break;
  case 1:
  case 2:
  case 5:
  case 6:
    return &DAT_00000001;
  case 3:
    if ((puVar5[1] & 0xc) == 0) {
      iVar6 = 0x35c;
    }
    else {
      iVar6 = 900;
    }
    break;
  case 4:
    iVar6 = 0x1f8;
    break;
  default:
    FUN_01009500(0x21,0x3d9,extraout_r2,uVar13);
    uStack_30 = uVar20;
    puStack_34 = &DAT_210010a0;
    uStack_3c = param_1;
    iStack_38 = (int)lVar21;
    puVar5 = FUN_01019a04();
    bVar3 = puVar5[4];
    if (bVar3 < 0x60) {
      uVar20 = (uint)(byte)(&DAT_0103c214)[bVar3 >> 5];
      if (uVar20 == 8) {
        uVar20 = 4;
        DAT_210010e4 = 0;
      }
    }
    else {
      uVar20 = 0;
    }
    bVar2 = puVar5[3];
    puVar18 = &DAT_10624dd3;
    if ((char)puVar5[2] < '\0') {
      iVar6 = 300;
    }
    else {
      iVar6 = 0x1e;
    }
    if ((char)puVar5[2] < '\0') {
      iVar17 = 300;
    }
    else {
      iVar17 = 0x1e;
    }
    iVar7 = FUN_01020aa8();
    iVar7 = iVar6 * ((uint)bVar2 | (bVar3 & 0x1f) << 8) - iVar7;
    puVar8 = (undefined *)FUN_01020af0();
    if ((puVar5[2] & 0x40) == 0) {
      iVar6 = 500;
    }
    else {
      iVar6 = 0x32;
    }
    uVar4 = src/*FUN_01024ecc();
    bVar3 = FUN_01020a9c();
    iVar9 = FUN_010211f0((uint)bVar3);
    uVar16 = ((iVar7 + iVar17) * ((uint)uVar4 + iVar6) + 999999) / 1000000;
    puVar15 = (undefined *)((iVar7 - (iVar9 + 999U) / 1000) - uVar16);
    puVar5 = puVar15 + -0x59;
    uVar13 = uVar20;
    if (&UNK_00000253 < puVar5) {
      if (DAT_210010a1 != '\0') goto LAB_0101bad6;
      puVar8 = puVar8 + (int)puVar5;
      iVar6 = FUN_010211e0(uVar20);
      iVar7 = *(int *)(&DAT_0103c218 + uVar20 * 4);
      uVar16 = iVar17 + (uint)(&DAT_0000a3a1 + iVar7) / 1000 + 0x60 + uVar16 * 2 + iVar6;
      iVar17 = FUN_010211e0(uVar20);
      uVar13 = FUN_010211f0(uVar20);
      puVar15 = FUN_0101a984(uVar20);
      local_58 = (undefined *)((uint)local_58 & 0xffffff00);
      uVar20 = iVar7 - uVar13;
      puVar18 = (undefined1 *)((ulonglong)uVar20 * 0x10624dd3 >> 0x20);
      local_50 = (undefined *)CONCAT13(1,(undefined3)local_50);
      uVar10 = FUN_0101a8e8();
      local_50 = (undefined *)CONCAT22(local_50._2_2_,(short)uVar10);
      local_48 = puVar8 + DAT_210010b8;
      puVar15 = puVar15 + (((uVar16 + 0x11a) - iVar17) - uVar20 / 1000);
      local_44 = DAT_210010bc + (uint)CARRY4(DAT_210010b8,(uint)puVar8);
      local_54 = puVar15;
      uVar20 = FUN_01024688();
      local_50._0_3_ = CONCAT12((char)uVar20,(undefined2)local_50);
      DAT_210010c0 = local_48;
      DAT_210010c4 = local_44;
      DAT_210010d8 = puVar15;
      DAT_210010e8 = uVar16;
      pbVar11 = FUN_01019a04();
      puVar5 = (undefined *)FUN_010239c8((uint)*pbVar11,(byte *)&local_58);
      if (puVar5 != (undefined *)0x0) goto LAB_0101bad6;
      FUN_01009500(0x21,0x751,extraout_r2_00,extraout_r3);
    }
    iVar6 = FUN_010211e0(uVar13);
    puVar15 = puVar15 + (int)(puVar8 + -0x10);
    iVar19 = *(int *)(&DAT_0103c218 + uVar13 * 4);
    iVar7 = FUN_010211e0(uVar13);
    iVar9 = FUN_010211f0(uVar13);
    puVar8 = FUN_0101a984(uVar13);
    puVar5 = DAT_210010d8;
    if (DAT_210010d8 <
        puVar8 + 0x11a +
        (int)(puVar15 +
             iVar6 + iVar17 + (uint)(ZEXT48(puVar18) * (ulonglong)(iVar19 + 999) >> 0x26) + 0x20 +
                     uVar16 * 2) +
        (-(uint)(ZEXT48(puVar18) * (ulonglong)(uint)(iVar19 - iVar9) >> 0x26) - iVar7)) {
      uVar20 = (int)(puVar8 + 0x11a +
                     (int)(puVar15 +
                          iVar6 + iVar17 + (uint)(ZEXT48(puVar18) * (ulonglong)(iVar19 + 999) >>
                                                 0x26) + 0x20 + uVar16 * 2) +
                    (-(uint)(ZEXT48(puVar18) * (ulonglong)(uint)(iVar19 - iVar9) >> 0x26) - iVar7))
               - (int)DAT_210010d8;
      uVar13 = FUN_01024688();
      uVar12 = FUN_010245ec(uVar13);
      if (uVar20 < 0x76) {
        uVar20 = 0x76;
      }
      if (uVar12 <= uVar20) {
        uVar20 = uVar12;
      }
      uVar10 = extraout_r2_01;
      if ((puVar5 + uVar20 < (undefined *)0x1000000) &&
         (uVar13 = FUN_010246a8(uVar20,uVar13,extraout_r2_01), uVar10 = extraout_r2_02, uVar13 == 0)
         ) {
        DAT_210010d8 = DAT_210010d8 + uVar20;
        DAT_210010e0 = DAT_210010d8 + -0x109;
        FUN_01024538((uint)DAT_210010e0,extraout_r1,0xfffffef7,DAT_210010d8);
        goto LAB_0101bc86;
      }
      puVar5 = (undefined *)FUN_01019a0c(2,1,uVar10);
      if ((DAT_210010b4 == '\0') || (DAT_210010a1 != '\0')) goto LAB_0101bad6;
      pbVar11 = FUN_0101ab8c((byte *)&local_58,0,(uint *)0x0,(uint *)0x0);
      if (pbVar11 == (byte *)0x0) {
        DAT_210010a2 = 1;
        puVar5 = (undefined *)0x0;
        goto LAB_0101bad6;
      }
    }
    else {
LAB_0101bc86:
      local_4c = DAT_210010ce;
      local_54 = (undefined *)CONCAT31(local_54._1_3_,2);
      local_4b = 0;
      local_58 = puVar15 + iVar6 + iVar17 + (uint)(ZEXT48(puVar18) * (ulonglong)(iVar19 + 999) >>
                                                  0x26) + 0x20 + uVar16 * 2;
      local_50 = puVar15;
      iVar6 = FUN_010195ac(&local_58);
      uVar10 = extraout_r2_03;
      uVar14 = extraout_r3_00;
      if (iVar6 != 0) goto LAB_0101bcd6;
      iVar6 = FUN_010195e8();
      if (iVar6 == 0) {
        return (undefined *)0x0;
      }
      FUN_01009500(0x21,0x795,extraout_r2_04,extraout_r3_01);
    }
    pbVar11 = FUN_01019a04();
    puVar5 = (undefined *)FUN_010239c8((uint)*pbVar11,(byte *)&local_58);
    if (puVar5 != (undefined *)0x0) {
LAB_0101bad6:
      if (DAT_210010b4 == '\0') {
        return puVar5;
      }
      FUN_01020e34();
      puVar5 = FUN_01023284();
      DAT_210010b4 = 0;
      DAT_210010b5 = 0;
      return puVar5;
    }
    FUN_01009500(0x21,0x7cb,extraout_r2_05,extraout_r3_02);
    uVar10 = extraout_r2_06;
    uVar14 = extraout_r3_03;
LAB_0101bcd6:
    FUN_01009500(0x21,0x794,uVar10,uVar14);
    *(int *)extraout_r2_07 = extraout_r2_07;
    *(undefined **)(extraout_r2_07 + 4) = puVar15;
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0x83,0x101bcf0);
    (*pcVar1)();
  }
  puVar5 = (undefined *)(((int)lVar21 - uVar20) + iVar6);
  if (puVar5 < DAT_210010d8 + -0x11a) {
    puVar8 = &DAT_00000001;
  }
  else {
    puVar8 = (undefined *)0x0;
    iVar6 = FUN_0101aa18();
    if (iVar6 != 0) {
      return (undefined *)(uint)(puVar5 < DAT_210010d8 + -0x11a);
    }
  }
  return puVar8;
}



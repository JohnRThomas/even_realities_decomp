/*
 * Function: FUN_0101bd4c
 * Entry:    0101bd4c
 * Prototype: undefined * __stdcall FUN_0101bd4c(uint param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Type propagation algorithm not settling */

undefined * FUN_0101bd4c(uint param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 extraout_r2;
  uint uVar9;
  undefined4 extraout_r2_00;
  uint uVar10;
  undefined4 extraout_r2_01;
  uint extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar11;
  int extraout_r2_04;
  undefined4 extraout_r3;
  uint uVar12;
  undefined4 extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar13;
  undefined1 *unaff_r4;
  uint uVar14;
  undefined *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  bool bVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  
  uVar10 = DAT_210010c8;
  iVar18 = DAT_210010bc;
  uVar17 = DAT_210010b8;
  if (param_1 < 2) {
    uVar3 = FUN_01020af0();
    puVar4 = FUN_01019a04();
    uVar10 = DAT_210010c8;
    bVar1 = puVar4[1];
    uVar16 = (uint)bVar1;
    *(ushort *)(DAT_210010c8 + 0x6e) = CONCAT11(bVar1,bVar1);
    uVar5 = DAT_210010c8;
    *(undefined1 *)(uVar10 + 0x70) = 0xff;
    FUN_0100f9a8(uVar5 + 0x30,(uint)((bVar1 & 0xc) != 0));
    uVar5 = FUN_0100dd8c(param_1 & 1,uVar16,extraout_r2,extraout_r3);
    iVar6 = FUN_010211f0(uVar16);
    uVar10 = DAT_210010c8;
    if (param_1 == 1) {
      if (uVar16 == 8) {
        uVar9 = 0xbe8;
      }
      else if (uVar16 == 4) {
        uVar9 = 0x486;
      }
      else if (uVar16 == 2) {
        uVar9 = 0x14c;
      }
      else {
        uVar9 = 0x1f8;
      }
    }
    else {
      uVar9 = 0x1f8;
    }
    uVar14 = uVar5 + uVar3 + uVar17;
    puVar4 = *(undefined **)(DAT_210010c8 + 0x14);
    uVar16 = ((uint)*(ushort *)(&DAT_0103c23c + uVar16 * 2) + iVar6 + 999) / 1000;
    uVar12 = uVar14 - uVar16;
    unaff_r4 = (undefined1 *)(uVar12 + uVar9);
    iVar6 = ((iVar18 + (uint)CARRY4(uVar5,uVar3) + (uint)CARRY4(uVar5 + uVar3,uVar17)) -
            (uint)(uVar14 < uVar16)) + (uint)CARRY4(uVar12,uVar9);
    puVar7 = (undefined4 *)FUN_0101e59c();
    iVar18 = DAT_210010f4;
    uVar17 = DAT_210010f0;
    if (puVar7 == &DAT_210010f0) {
      if (*(char *)(uVar10 + 0x73) != '\0') {
        cVar2 = FUN_0101e6c4();
        uVar5 = extraout_r3_01;
        if (cVar2 == '\0') {
          uVar5 = (uint)*(short *)(uVar10 + 0x2fc);
          *(undefined2 *)(uVar10 + 0x2fc) = 0;
          bVar19 = CARRY4(uVar5,uVar17);
          uVar17 = uVar5 + uVar17;
          iVar18 = iVar18 + ((int)uVar5 >> 0x1f) + (uint)bVar19;
        }
        uVar20 = FUN_0101e610(uVar17,iVar18,(uint)puVar4,uVar5,(uint)unaff_r4,iVar6);
        puVar15 = (undefined *)uVar20;
        goto LAB_0101be66;
      }
      puVar15 = (undefined *)0x0;
      puVar4 = (undefined *)0x0;
      if (DAT_21001118 != (undefined *)0x0) goto LAB_0101be70;
LAB_0101beb8:
      uVar17 = DAT_210010c8;
      uVar21 = FUN_0100deb0((uint)puVar15,*(undefined **)(DAT_210010c8 + 0x14));
      *(int *)(uVar17 + 0x24) = (int)uVar21;
      puVar8 = *(undefined **)(DAT_210010c8 + 0x14);
      uVar10 = DAT_210010c8;
    }
    else {
      uVar20 = FUN_0101e610(*(uint *)(uVar10 + 0x2d8),*(int *)(uVar10 + 0x2dc),(uint)puVar4,
                            &DAT_210010f0,(uint)unaff_r4,iVar6);
      puVar15 = (undefined *)uVar20;
      uVar11 = extraout_r2_00;
      uVar13 = extraout_r3_00;
      if (puVar4 < puVar15) goto LAB_0101bf32;
LAB_0101be66:
      puVar4 = puVar15;
      if (DAT_21001118 <= puVar15) goto LAB_0101beb8;
LAB_0101be70:
      uVar10 = DAT_210010c8;
      puVar8 = *(undefined **)(DAT_210010c8 + 0x14);
      puVar15 = puVar4 + (int)puVar8;
      *(undefined **)(DAT_210010c8 + 0x24) = puVar8;
    }
    puVar4 = (undefined *)FUN_0100de24(5,puVar8);
    uVar17 = DAT_210010c8;
    *(short *)(uVar10 + 0x28) = (short)puVar4;
    uVar10 = (int)puVar15 - *(int *)(uVar17 + 0x24);
    if (uVar10 < *(ushort *)(uVar17 + 0x28)) {
      *(undefined **)(uVar17 + 0x2d8) = puVar15 + (int)unaff_r4;
      *(uint *)(uVar17 + 0x2dc) = iVar6 + (uint)CARRY4((uint)puVar15,(uint)unaff_r4);
      return puVar4;
    }
  }
  else {
    uVar17 = param_1 - 2;
    if (uVar17 < 2) {
      unaff_r4 = &DAT_210010a0;
      DAT_210010cc = 1;
      DAT_210010cd = param_1 == 3;
      *(undefined1 *)(DAT_210010c8 + 0x300) = 0;
      if (DAT_210010a0 == 5) {
        puVar4 = (undefined *)FUN_0101c43c(uVar10,param_2,1,5);
        DAT_210010c8 = 0;
        if (DAT_210010b4 != '\0') {
          FUN_01020e34();
          puVar4 = FUN_01023284();
          DAT_210010b4 = 0;
          DAT_210010b5 = 0;
          return puVar4;
        }
        return puVar4;
      }
      FUN_01009500(0x21,0x866,1,(uint)DAT_210010a0);
      param_3 = extraout_r2_01;
      uVar17 = extraout_r3_02;
    }
    FUN_01009500(0x21,0x8c3,param_3,uVar17);
    uVar10 = extraout_r2_02;
    uVar17 = extraout_r3_03;
  }
  FUN_01009500(0x21,0x854,uVar10,uVar17);
  uVar11 = extraout_r2_03;
  uVar13 = extraout_r3_04;
LAB_0101bf32:
  FUN_01009500(0x21,0x40f,uVar11,uVar13);
  *(int *)extraout_r2_04 = extraout_r2_04;
  *(undefined1 **)(extraout_r2_04 + 4) = unaff_r4;
  return (undefined *)(uint)DAT_210010a0;
}



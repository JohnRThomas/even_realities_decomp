/*
 * Function: FUN_01009258
 * Entry:    01009258
 * Prototype: int __stdcall FUN_01009258(int param_1, int param_2)
 */


int FUN_01009258(int param_1,int param_2)

{
  uint3 uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar5;
  int iVar6;
  byte bVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar8;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint uVar9;
  int *piVar10;
  ushort *puVar11;
  uint uVar12;
  int *piVar13;
  byte bVar14;
  uint uVar15;
  ulonglong uVar16;
  int local_2c;
  undefined4 local_28;
  undefined1 local_24;
  char local_23;
  undefined1 local_22;
  char local_21;
  ushort *puVar4;
  
  uVar9 = param_1 + 7U & 0xfffffff8;
  local_24 = DAT_21000a45;
  local_23 = DAT_21000a46;
  local_2c = (uint)CONCAT12(DAT_21000a32,CONCAT11(DAT_21000a31,DAT_21000a30)) << 8;
  local_22 = DAT_21000a47;
  local_21 = DAT_21000a48;
  local_28._0_2_ = CONCAT11(DAT_21000a34,DAT_21000a33);
  uVar1 = CONCAT12(DAT_21000a3f,(undefined2)local_28);
  local_28 = (uint)uVar1;
  if (DAT_21000a4e != 0) {
    local_28 = CONCAT13(DAT_21000a34,uVar1);
  }
  bVar7 = 0;
  uVar15 = uVar9;
  if (param_2 != 0) {
    uVar15 = 0;
  }
  iVar3 = FUN_0100a0d8(uVar15,(byte *)&local_2c);
  uVar15 = 0;
  bVar14 = DAT_21000a30 + DAT_21000a31;
  for (; bVar7 < bVar14; bVar7 = bVar7 + 1) {
    iVar6 = FUN_01028046((ushort)(byte)DAT_21000a35,(ushort)DAT_21000a35._1_1_,
                         (ushort)DAT_21000a35._2_1_,(ushort)DAT_21000a35._3_1_);
    uVar15 = uVar15 + iVar6;
  }
  piVar10 = (int *)(uVar9 + iVar3 + 3 & 0xfffffffc);
  piVar13 = piVar10;
  if (param_2 != 0) {
    piVar13 = (int *)0x0;
  }
  iVar3 = FUN_0100a6a4(piVar13,bVar14,uVar15);
  iVar3 = (int)piVar10 + iVar3;
  uVar8 = extraout_r2;
  if (DAT_21000a32 != 0) {
    uVar15 = iVar3 + 3U & 0xfffffffc;
    uVar9 = uVar15;
    if (param_2 != 0) {
      uVar9 = 0;
    }
    uVar9 = FUN_0100a9e0(uVar9,DAT_21000a32,DAT_21000a3f + DAT_21000a33,DAT_21000a3a);
    iVar3 = uVar15 + uVar9;
    uVar8 = extraout_r2_00;
  }
  if ((DAT_21000a4f != '\0') && (DAT_21000a39 != 0)) {
    puVar11 = (ushort *)(iVar3 + 3U & 0xfffffffc);
    if (DAT_21000a50 == '\0') {
      bVar7 = 0x25;
    }
    else {
      bVar7 = 0xff;
    }
    puVar4 = puVar11;
    if (param_2 != 0) {
      puVar4 = (ushort *)0x0;
    }
    uVar2 = FUN_0100ad0c(puVar4,DAT_21000a39,bVar7);
    iVar3 = (int)puVar11 + (uint)uVar2;
    uVar8 = extraout_r2_01;
  }
  if ((DAT_21000a3c != 0) &&
     ((uVar9 = (uint)DAT_21000a32, uVar9 != 0 ||
      ((DAT_21000a4f != '\0' && (uVar9 = (uint)DAT_21000a39, uVar9 != 0)))))) {
    uVar12 = iVar3 + 7U & 0xfffffff8;
    uVar15 = uVar12;
    if (param_2 != 0) {
      uVar15 = 0;
    }
    uVar16 = FUN_01010f7c(uVar15,(uint)DAT_21000a3c,uVar8,uVar9);
    iVar3 = uVar12 + (int)uVar16;
  }
  if ((DAT_21000044 != (code *)0x0) && (DAT_21000a34 != 0)) {
    uVar15 = iVar3 + 3U & 0xfffffffc;
    uVar9 = uVar15;
    if (param_2 != 0) {
      uVar9 = 0;
    }
    iVar3 = (*DAT_21000044)(uVar9,DAT_21000a34,DAT_21000a3d);
    iVar3 = uVar15 + iVar3;
  }
  if ((DAT_2100004c != (code *)0x0) && (DAT_21000a3e != '\0')) {
    uVar15 = iVar3 + 3U & 0xfffffffc;
    uVar9 = uVar15;
    if (param_2 != 0) {
      uVar9 = 0;
    }
    iVar3 = (*DAT_2100004c)(uVar9);
    iVar3 = uVar15 + iVar3;
  }
  if ((DAT_21000048 != (code *)0x0) && (DAT_21000a3f != '\0')) {
    uVar15 = iVar3 + 3U & 0xfffffffc;
    uVar9 = uVar15;
    if (param_2 != 0) {
      uVar9 = 0;
    }
    iVar3 = (*DAT_21000048)(uVar9,DAT_21000a3f,(undefined1)DAT_21000a40,DAT_21000a40._1_1_,
                            DAT_21000a42);
    iVar3 = uVar15 + iVar3;
  }
  uVar9 = (uint)DAT_21000a4e;
  if ((uVar9 != 0) && (DAT_21000a34 != 0)) {
    uVar15 = iVar3 + 3U & 0xfffffffc;
    uVar9 = uVar15;
    if (param_2 != 0) {
      uVar9 = 0;
    }
    iVar3 = FUN_0100adc8(uVar9,DAT_21000a34,DAT_21000a44);
    iVar3 = uVar15 + iVar3;
    uVar9 = extraout_r3;
  }
  if (DAT_21000a49 == 0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(iVar3 + 7U & 0xfffffff8);
    piVar10 = piVar13;
    if (param_2 != 0) {
      piVar10 = (int *)0x0;
    }
    iVar3 = FUN_010281e6(piVar10,(ushort)DAT_21000a49,0x10e);
    iVar3 = (int)piVar13 + iVar3;
    uVar9 = extraout_r3_00;
  }
  if (DAT_21000a4a == 0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)(iVar3 + 7U & 0xfffffff8);
    piVar5 = piVar10;
    if (param_2 != 0) {
      piVar5 = (int *)0x0;
    }
    iVar3 = FUN_010281e6(piVar5,(ushort)DAT_21000a4a,0xfb);
    iVar3 = (int)piVar10 + iVar3;
    uVar9 = extraout_r3_01;
  }
  if (param_2 == 0) {
    FUN_01021fac(piVar13,piVar10,0xfb,uVar9);
  }
  if (((byte)DAT_21000a4b == 0) || (DAT_21000a4b._1_1_ == 0)) {
    if (param_2 == 0) {
      FUN_01022020(0);
    }
  }
  else {
    piVar10 = (int *)(iVar3 + 7U & 0xfffffff8);
    piVar13 = piVar10;
    if (param_2 != 0) {
      piVar13 = (int *)0x0;
    }
    iVar3 = FUN_010281e6(piVar13,(ushort)(byte)DAT_21000a4b,0x104);
    uVar9 = (int)piVar10 + iVar3 + 3 & 0xfffffff8U | 4;
    iVar3 = FUN_0100ae64(DAT_21000a4b._1_1_,DAT_21000a46 + DAT_21000a48,uVar9,param_2);
    iVar3 = uVar9 + iVar3;
    if (param_2 == 0) {
      FUN_01022020(piVar10);
      FUN_0102202c((byte)DAT_21000a4b);
    }
  }
  if (DAT_21000a54 != 0) {
    if (param_2 == 0) {
      DAT_21000a54 = iVar3;
    }
    iVar3 = iVar3 + 0x28;
  }
  if (DAT_21000a4d != 0) {
    piVar10 = (int *)(iVar3 + 7U & 0xfffffff8);
    piVar13 = piVar10;
    if (param_2 != 0) {
      piVar13 = (int *)0x0;
    }
    iVar3 = FUN_010281e6(piVar13,(ushort)DAT_21000a4d,10000);
    iVar3 = (int)piVar10 + iVar3;
    if (param_2 == 0) {
      FUN_0102205c(piVar10,10000);
    }
  }
  return iVar3 - param_1;
}



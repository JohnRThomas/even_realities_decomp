/*
 * Function: FUN_01014c0c
 * Entry:    01014c0c
 * Prototype: undefined4 * __stdcall FUN_01014c0c(undefined4 * param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 * FUN_01014c0c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  char cVar12;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar13;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar14;
  undefined4 extraout_r3_04;
  uint unaff_r5;
  byte *apbStack_24 [2];
  
  puVar8 = DAT_21000f6c;
  DAT_21000f74 = DAT_21000f74 | (ushort)param_1;
  if (param_1 == (undefined4 *)&IRQ) {
    puVar8 = FUN_01014698(DAT_21000f6c,4,&DAT_21000f68,param_4);
    return puVar8;
  }
  if (((uint)param_1 & 3) == 3) {
    FUN_01009500(0x31,0xb30,&DAT_21000f68,3);
    uVar6 = unaff_r5 >> 0x1d;
    iVar7 = FUN_0100b104(apbStack_24);
    if (iVar7 == 0) {
      FUN_01009500(0x31,0x832,extraout_r2,extraout_r3);
      uVar13 = extraout_r2_03;
      uVar14 = extraout_r3_02;
      goto LAB_01014f28;
    }
    FUN_01026284((undefined4 *)apbStack_24[0],0,0x32);
    FUN_0100eddc(apbStack_24[0],3);
    bVar2 = *apbStack_24[0];
    *apbStack_24[0] = (byte)(bVar2 & 0xffffffef);
    FUN_0100ee34((uint)apbStack_24[0],uVar6,extraout_r2_00,bVar2 & 0xffffffef);
    iVar7 = extraout_r3_00;
    if (uVar6 < 0x2b) {
      if (uVar6 < 2) goto switchD_01014d28_caseD_3;
      iVar7 = uVar6 - 2;
      switch(uVar6) {
      case 2:
      case 7:
        apbStack_24[0][4] = *(byte *)(DAT_21000f6c + 0x54);
        break;
      default:
        goto switchD_01014d28_caseD_3;
      case 4:
        FUN_0100ef84((int)apbStack_24[0],DAT_21000f6c + 0xc0);
        FUN_0100ef9c((int)apbStack_24[0],DAT_21000f6c + 0x51);
        break;
      case 5:
      case 6:
        break;
      }
    }
    else {
      if (uVar6 == 0xff) {
        FUN_0100ee5c((int)apbStack_24[0],(undefined4 *)DAT_21000f6c[0xee],
                     (uint)*(byte *)((int)DAT_21000f6c + 0x3b7),DAT_21000f6c);
        goto switchD_01014d28_caseD_5;
      }
switchD_01014d28_caseD_3:
      FUN_01009500(0x31,0x8e4,extraout_r2_01,iVar7);
      (*DAT_210001ec)(uVar6,apbStack_24[0],&DAT_21000f68);
    }
switchD_01014d28_caseD_5:
    puVar8 = (undefined4 *)FUN_0100b134();
    uVar13 = extraout_r2_02;
    uVar14 = extraout_r3_01;
    if (puVar8 != (undefined4 *)0x0) {
      return puVar8;
    }
LAB_01014f28:
    FUN_01009500(0x31,0x8e8,uVar13,uVar14);
    puVar8 = DAT_21000f6c;
    cVar1 = *(char *)((int)DAT_21000f6c + 0x3be);
    cVar3 = *(char *)((int)DAT_21000f6c + 0x3bf);
    cVar11 = cVar1;
    if (cVar1 == '\0') {
      cVar11 = *(char *)((int)DAT_21000f6c + 0x6e);
    }
    cVar12 = cVar3;
    if (cVar3 == '\0') {
      cVar12 = *(char *)((int)DAT_21000f6c + 0x6f);
    }
    *(char *)((int)DAT_21000f6c + 0x6f) = cVar12;
    *(char *)((int)puVar8 + 0x6e) = cVar11;
    pcVar4 = DAT_210001f4;
    *(undefined1 *)(puVar8 + 0x1c) = 0xff;
    uVar13 = 0;
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(DAT_21000f6c);
      uVar13 = extraout_r2_04;
    }
    if ((*(char *)(DAT_21000f6c + 0x5b) == '\x01') || (cVar1 != '\0' || cVar3 != '\0')) {
      FUN_01020134(0x21000f68,0,uVar13);
    }
    uVar6 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
    bVar5 = FUN_0100f9f8((int)DAT_21000f6c);
    uVar13 = extraout_r2_05;
    uVar14 = extraout_r3_03;
    if (bVar5) {
      FUN_0100fb00(*(undefined2 *)DAT_21000f6c,(int)(DAT_21000f6c + 0xc),
                   (undefined4 *)((int)DAT_21000f6c + 0x1ce));
      uVar13 = extraout_r2_06;
      uVar14 = extraout_r3_04;
    }
    FUN_01014698(DAT_21000f6c,5,uVar13,uVar14);
    uVar9 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
    if (uVar6 < uVar9) {
      uVar10 = FUN_01024688();
      uVar9 = uVar9 - uVar6;
      if (uVar9 < 0x76) {
        uVar9 = 0x76;
      }
      uVar6 = FUN_010246a8(uVar9,uVar10,extraout_r2_07);
      return (undefined4 *)(uint)(uVar6 == 0);
    }
    return (undefined4 *)&DAT_00000001;
  }
  if (((uint)param_1 & 2) == 0) {
    if (-1 < (int)param_1 << 0x1f) goto LAB_01014c44;
LAB_01014c52:
    DAT_21000f7c = param_2;
    if (*(char *)(param_2 + 3) == '\x06') {
      if (*(char *)((int)DAT_21000f6c + 0xc6) == '\x19') {
        DAT_21000f6c[0x48] = 0;
        puVar8[0x49] = 0;
        *(undefined1 *)((int)puVar8 + 0xca) = 1;
      }
    }
    else if ((*(char *)(param_2 + 3) == '\v') && (*(char *)((int)DAT_21000f6c + 0xc6) == '\x13')) {
      *(undefined1 *)((int)DAT_21000f6c + 0xca) = 0;
      *(undefined1 *)((int)puVar8 + 0x106) = 1;
    }
    if (((uint)param_1 & 2) == 0) goto LAB_01014c44;
    cVar1 = *(char *)(DAT_21000f78 + 3);
    puVar8 = DAT_21000f6c;
  }
  else {
    DAT_21000f78 = param_2;
    if ((int)param_1 << 0x1f < 0) goto LAB_01014c52;
    cVar1 = *(char *)(param_2 + 3);
  }
  DAT_21000f6c = puVar8;
  if (cVar1 == '\x05') {
    if (*(char *)((int)puVar8 + 0xc6) == '\x17') {
      puVar8[0x4a] = 0;
      puVar8[0x4b] = 0;
      *(undefined1 *)((int)puVar8 + 0xcb) = 1;
    }
  }
  else if ((cVar1 == '\v') && (*(char *)((int)puVar8 + 0xc6) == '\x12')) {
    *(undefined1 *)((int)puVar8 + 0xcb) = 0;
  }
LAB_01014c44:
  if ((int)param_1 << 0x1a < 0) {
    DAT_21000f80 = 8;
  }
  return param_1;
}



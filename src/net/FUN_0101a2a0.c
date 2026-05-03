/*
 * Function: FUN_0101a2a0
 * Entry:    0101a2a0
 * Prototype: uint __stdcall FUN_0101a2a0(ushort * param_1, int param_2, undefined4 * param_3, uint param_4, undefined1 param_5, byte param_6, undefined1 param_7, char param_8)
 */


uint FUN_0101a2a0(ushort *param_1,int param_2,undefined4 *param_3,uint param_4,undefined1 param_5,
                 byte param_6,undefined1 param_7,char param_8)

{
  byte bVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar9;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  byte bVar10;
  byte *pbVar11;
  undefined4 extraout_r3;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  int extraout_r3_03;
  undefined4 uVar14;
  uint uVar15;
  ushort uStackY_66;
  int aiStackY_64 [2];
  undefined4 *puStackY_5c;
  ushort *puStackY_58;
  undefined4 uStackY_54;
  uint local_40;
  ushort uStack_2e;
  int local_2c [2];
  
  uVar15 = (uint)(byte)*param_1;
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = (byte)param_4;
  if (param_8 == '\0') {
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    puVar3 = (undefined4 *)FUN_010278d2(local_2c[0]);
    *(undefined1 *)((int)puVar3 + 0x1b) = param_7;
    *(undefined1 *)((int)puVar3 + 0x12) = 1;
    uVar9 = extraout_r2;
    switch(param_4) {
    case 1:
    case 2:
      bVar10 = bVar1;
      break;
    default:
switchD_0101a2f8_caseD_3:
      FUN_01009500(6,0x294,uVar9,param_4 - 1);
      uVar9 = extraout_r2_03;
      uVar12 = extraout_r3_01;
      goto LAB_0101a69a;
    case 4:
    case 8:
      bVar10 = 3;
    }
    *(byte *)((int)puVar3 + 0x1e) = bVar10;
    *(undefined1 *)((int)puVar3 + 0x2d) = param_5;
    local_40 = 0;
    if (*(int *)(param_1 + 10) != 0) {
      puVar2 = (ushort *)FUN_0100ada0();
      FUN_0102794a(puVar2,local_2c,&uStack_2e);
      FUN_010278d2(local_2c[0]);
      local_40 = *param_1 & 0x10ff;
      if ((*param_1 & 0x10ff) != 0) {
        local_40 = 0;
LAB_0101a33a:
        pbVar11 = *(byte **)(param_1 + 10);
        *(byte *)(puVar3 + 8) = pbVar11[1] >> 4;
        *(ushort *)((int)puVar3 + 0x21) = (ushort)*pbVar11 | (pbVar11[1] & 0xf) << 8;
        goto LAB_0101a356;
      }
    }
LAB_0101a372:
    uVar4 = (uint)(byte)*param_1;
  }
  else {
    uVar4 = FUN_0102753e((short *)puVar2);
    if (uVar4 == 1) {
      return 0;
    }
    if ((char)*param_1 == '\x02') {
      local_40 = 0;
    }
    else {
      local_40 = (uint)(byte)param_1[8];
      if (0x672 < DAT_2100109c + local_40) {
        return 0;
      }
      DAT_2100109c = (ushort)(DAT_2100109c + local_40);
    }
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    puVar3 = (undefined4 *)FUN_010278d2(local_2c[0]);
    *(undefined1 *)((int)puVar3 + 0x1b) = param_7;
    *(undefined1 *)((int)puVar3 + 0x12) = 1;
    uVar9 = extraout_r2_01;
    switch(param_4) {
    case 1:
    case 2:
      bVar10 = bVar1;
      break;
    default:
      goto switchD_0101a2f8_caseD_3;
    case 4:
    case 8:
      bVar10 = 3;
    }
    *(byte *)((int)puVar3 + 0x1f) = bVar10;
    *(undefined1 *)((int)puVar3 + 0x2d) = param_5;
    if (*(int *)(param_1 + 10) != 0) {
      puVar2 = (ushort *)FUN_0100ada0();
      FUN_0102794a(puVar2,local_2c,&uStack_2e);
      iVar5 = FUN_010278d2(local_2c[0]);
      if ((param_8 == '\x03') && ((int)((uint)*(byte *)(iVar5 + 0x1c) << 0x1c) < 0))
      goto LAB_0101a372;
      goto LAB_0101a33a;
    }
LAB_0101a356:
    uVar4 = (uint)(byte)*param_1;
    if (((param_8 == '\x01') && (uVar4 == 0)) && (*(int *)(param_1 + 0xe) != 0)) {
      *(undefined2 *)((int)puVar3 + 0x23) = *(undefined2 *)(*(int *)(param_1 + 0xe) + 2);
    }
  }
  uVar6 = ((*(byte *)(puVar3 + 7) & 0xfffffffe) << 0x1e) >> 0x1f;
  if (uVar4 == 2) {
    uVar6 = 1;
  }
  *(byte *)(puVar3 + 7) =
       *(byte *)(puVar3 + 7) & 0xf4 | uVar4 == 1 | (byte)(uVar6 << 1) |
       (byte)((uVar6 & uVar4 == 0) << 3);
  if ((*(int *)(param_1 + 4) != 0) && (param_8 != '\x02')) {
    puVar2 = (ushort *)FUN_0100ada0();
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    iVar5 = FUN_010278d2(local_2c[0]);
    uVar4 = FUN_0101a1f4(iVar5 + 0x12,(int)param_1,uVar4,1,bVar1,param_8);
    if (uVar4 == 0) {
      *(byte *)(puVar3 + 7) = *(byte *)(puVar3 + 7) | 4;
    }
  }
  iVar5 = *(int *)(param_1 + 0xc);
  if ((uVar15 == 0 || param_8 != '\x01') && (iVar5 != 0)) {
    if (*(char *)(iVar5 + 1) == '\0' && (*(byte *)(iVar5 + 2) & 0x1f) == 0) {
      cVar8 = '\x02';
    }
    else {
      cVar8 = '\x01';
    }
    *(byte *)(puVar3 + 7) = *(byte *)(puVar3 + 7) & 0x9f | cVar8 << 5;
  }
  else {
    *(byte *)(puVar3 + 7) = *(byte *)(puVar3 + 7) & 0x9f;
  }
  if ((((param_8 != '\0') || ((param_4 & 0xc) == 0)) ||
      (-1 < (int)((uint)*(byte *)((int)param_1 + 1) << 0x1b))) &&
     (*(undefined1 **)(param_1 + 0x10) != (undefined1 *)0x0)) {
    *(undefined1 *)(puVar3 + 0xb) = **(undefined1 **)(param_1 + 0x10);
  }
  if (*(int *)(param_1 + 2) != 0) {
    puVar2 = (ushort *)FUN_0100ada0();
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    iVar5 = FUN_010278d2(local_2c[0]);
    uVar4 = FUN_0101a1f4(iVar5 + 0x12,(int)param_1,uVar15,0,bVar1,param_8);
    if (uVar4 == 0) {
      if (param_6 == 0xff) {
        *(undefined1 *)((int)puVar3 + 0x13) = *(undefined1 *)((int)param_1 + 0x11);
        puVar13 = *(undefined4 **)(param_1 + 2);
        puVar3[5] = *puVar13;
        *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(puVar13 + 1);
      }
      else {
        iVar5 = FUN_0100d298((uint)param_6,(undefined1 *)((int)puVar3 + 0x13),puVar3 + 5);
        uVar9 = extraout_r2_02;
        uVar12 = extraout_r3_00;
        if (iVar5 == 0) goto LAB_0101a6a4;
        *(byte *)((int)puVar3 + 0x13) = *(byte *)((int)puVar3 + 0x13) | 2;
      }
    }
  }
  if (*(int *)(param_1 + 4) == 0) {
LAB_0101a486:
    if (param_8 == '\0') {
      return 1;
    }
  }
  else if (param_8 != '\x02') {
    puVar2 = (ushort *)FUN_0100ada0();
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    iVar5 = FUN_010278d2(local_2c[0]);
    uVar15 = FUN_0101a1f4(iVar5 + 0x12,(int)param_1,uVar15,1,bVar1,param_8);
    if (uVar15 == 0) {
      if (param_2 - 2U < 2) {
        *(undefined4 *)((int)puVar3 + 0x26) = *param_3;
        *(undefined2 *)((int)puVar3 + 0x2a) = *(undefined2 *)(param_3 + 1);
      }
      else {
        puVar13 = *(undefined4 **)(param_1 + 4);
        *(undefined4 *)((int)puVar3 + 0x26) = *puVar13;
        *(undefined2 *)((int)puVar3 + 0x2a) = *(undefined2 *)(puVar13 + 1);
      }
      *(char *)((int)puVar3 + 0x25) = (char)param_2;
    }
    goto LAB_0101a486;
  }
  cVar8 = DAT_2100109e;
  puVar13 = DAT_21001098;
  if (DAT_21001098 != (undefined4 *)0x0) {
    *(undefined1 *)(DAT_21001098 + 2) = 0;
    FUN_0100f788(puVar13,0x1019a9d,6);
    if (cVar8 != '\0') {
      *(undefined1 *)((int)puVar13 + 0x11) = 0;
      FUN_0100f788((undefined4 *)((int)puVar13 + 9),0x1019a9d,6);
    }
    DAT_21001098 = (undefined4 *)0x0;
  }
  puVar2 = (ushort *)FUN_0100ada0();
  if ((*(byte *)(puVar3 + 7) & 0x60) == 0x20) {
    DAT_2100109e = 0xe5 < local_40;
    DAT_21001098 = puVar3;
  }
  else {
    *(undefined1 *)(puVar3 + 2) = 0;
    FUN_0100f788(puVar3,0x1019a9d,6);
    if (0xe5 < local_40) {
      *(undefined1 *)((int)puVar3 + 0x11) = 0;
      FUN_0100f788((undefined4 *)((int)puVar3 + 9),0x1019a9d,6);
    }
  }
  bVar1 = FUN_0100adb4();
  uVar15 = FUN_01027732((short *)puVar2,(ushort)bVar1,'\x01');
  param_1 = (ushort *)0x0;
  uVar9 = extraout_r2_00;
  uVar12 = extraout_r3;
  if (uVar15 != 0) {
    FUN_0102794a(puVar2,local_2c,&uStack_2e);
    iVar5 = FUN_010278d2(local_2c[0]);
    uVar9 = *(undefined4 *)((int)puVar3 + 0x16);
    uVar12 = *(undefined4 *)((int)puVar3 + 0x1a);
    uVar14 = *(undefined4 *)((int)puVar3 + 0x1e);
    *(undefined4 *)(iVar5 + 0x12) = *(undefined4 *)((int)puVar3 + 0x12);
    *(undefined4 *)(iVar5 + 0x16) = uVar9;
    *(undefined4 *)(iVar5 + 0x1a) = uVar12;
    *(undefined4 *)(iVar5 + 0x1e) = uVar14;
    uVar9 = *(undefined4 *)((int)puVar3 + 0x26);
    uVar12 = *(undefined4 *)((int)puVar3 + 0x2a);
    *(undefined4 *)(iVar5 + 0x22) = *(undefined4 *)((int)puVar3 + 0x22);
    *(undefined4 *)(iVar5 + 0x26) = uVar9;
    *(undefined4 *)(iVar5 + 0x2a) = uVar12;
    return uVar15;
  }
LAB_0101a69a:
  FUN_01009500(0x33,0x212,uVar9,uVar12);
  uVar9 = extraout_r2_04;
  uVar12 = extraout_r3_02;
LAB_0101a6a4:
  FUN_01009500(0x33,0xe6,uVar9,uVar12);
  iVar7 = (extraout_r3_03 >> 1) * 0x10;
  uStackY_54 = 0x101a6ad;
  puStackY_5c = puVar3;
  puStackY_58 = param_1;
  puVar2 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar2,aiStackY_64,&uStackY_66);
  iVar5 = FUN_010278d2(aiStackY_64[0]);
  if (iVar7 == 0) {
    return (uint)((*(ushort *)(extraout_r3_03 >> 1) & 0x10ff) == 0);
  }
  if (iVar7 == 3) {
    return ((uint)*(byte *)(iVar5 + 0x1c) << 0x1c) >> 0x1f;
  }
  return 0;
}



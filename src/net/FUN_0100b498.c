/*
 * Function: FUN_0100b498
 * Entry:    0100b498
 * Prototype: undefined8 __stdcall FUN_0100b498(int param_1)
 */


undefined8 FUN_0100b498(int param_1)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar10;
  undefined4 extraout_r2_03;
  uint extraout_r2_04;
  uint extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  byte local_13;
  ushort local_12;
  
  iVar6 = DAT_21000c70;
  local_13 = 0;
  uVar9 = (uint)*(byte *)(DAT_21000c70 + 0xcb);
  cVar3 = DAT_21000cc2;
  if (uVar9 != 0) {
    cVar3 = DAT_21000cc2 + '\x04';
  }
  if ((cVar3 == -1) && (param_1 == 0)) {
    uVar5 = (uint)*(byte *)(DAT_21000c70 + 0x6e);
    if (*(byte *)(DAT_21000c70 + 0x6f) != uVar5) goto LAB_0100b4ca;
  }
  else {
    uVar5 = (uint)*(byte *)(DAT_21000c70 + 0x6e);
LAB_0100b4ca:
    FUN_01020afc(0xff,uVar5,uVar9);
    uVar9 = extraout_r2;
  }
  uVar5 = (uint)*(byte *)(iVar6 + 0xbe);
  switch(uVar5) {
  case 0:
    local_12 = (ushort)DAT_21000cc3;
    *(ushort *)(iVar6 + 0x54) = local_12;
    cVar3 = FUN_0100b160(&DAT_21000cc4);
    if (cVar3 == '\0') {
      puVar4 = (ushort *)FUN_01027358((int)DAT_21000cc8,&local_12,&local_13);
      if ((puVar4 != (ushort *)0x0) && (*(char *)(iVar6 + 0x105) == '\0')) {
        uVar9 = (uint)local_13;
        uVar10 = extraout_r2_00;
        DAT_21000cc4 = puVar4;
        if (uVar9 == 0) {
          *puVar4 = (ushort)local_13;
          *(byte *)(puVar4 + 1) = local_13;
          FUN_0100eddc((byte *)DAT_21000cc4,1);
          uVar10 = extraout_r2_03;
          uVar9 = extraout_r3_01;
        }
        FUN_0100f0f8((int)DAT_21000cc4,(uint)local_12,uVar10,uVar9);
        puVar4 = DAT_21000cc4;
        break;
      }
      goto switchD_0100b4d8_caseD_1;
    }
    DAT_21000c7a = DAT_21000c7a | 0x80;
    (*DAT_21000c7c)(0x80,DAT_21000cc4);
    puVar4 = DAT_21000cc4;
    *(undefined1 *)(iVar6 + 0xb9) = 1;
    bVar8 = *(byte *)((int)puVar4 + 3);
joined_r0x0100b5ce:
    if (bVar8 == 0x1b) {
      FUN_01020b68((byte *)(iVar6 + 0x10),1);
      puVar4 = DAT_21000cc4;
    }
    break;
  case 1:
switchD_0100b4d8_caseD_1:
    DAT_21000cc4 = (ushort *)&DAT_21000c90;
    puVar4 = (ushort *)&DAT_21000c90;
    break;
  case 2:
    local_12 = *(ushort *)(iVar6 + 0x54);
    DAT_21000cc4 = (ushort *)FUN_01027358((int)DAT_21000cc8,&local_12,&local_13);
    puVar4 = DAT_21000cc4;
    if (DAT_21000cc4 != (ushort *)0x0) break;
    FUN_01009500(0x27,0x2e9,extraout_r2_02,extraout_r3_00);
    goto LAB_0100b606;
  case 3:
    cVar3 = FUN_0100b160(&DAT_21000cc4);
    if (cVar3 != '\0') {
      bVar8 = *(byte *)((int)DAT_21000cc4 + 3);
      puVar4 = DAT_21000cc4;
      goto joined_r0x0100b5ce;
    }
    FUN_01009500(0x27,0x2f2,extraout_r2_01,extraout_r3);
    uVar9 = extraout_r2_04;
    uVar5 = extraout_r3_02;
  default:
    FUN_01009500(0x27,0x2ff,uVar9,uVar5);
    if ((char)DAT_21000c6c == '\0') {
      if (extraout_r2_05 >> 0x12 != 1) {
        return 0;
      }
    }
    else if (extraout_r2_05 >> 0x12 != 0) {
      return 0;
    }
    iVar6 = (uint)(byte)DAT_21000cfc << 0x1b;
    if (iVar6 < 0) {
      if ((char)DAT_21000c6c == '\0') goto LAB_0100b702;
      iVar7 = 0;
LAB_0100b6c2:
      if ((int)((uint)DAT_21000c7a << 0x1e) < 0) {
        return CONCAT44(iVar7,(uint)(*(byte *)((int)DAT_21000cc4 + 3) != 2));
      }
    }
    else {
      iVar7 = ((int)((uint)*DAT_21000d00 << 0x1b) >> 0x1f) + 1;
      if ((DAT_21000c80 == 0) && (DAT_21000d04 != 0)) goto LAB_0100b6f4;
      if ((char)DAT_21000c6c != '\0') goto LAB_0100b6c2;
    }
    iVar6 = 0;
    if (iVar7 != 0) {
LAB_0100b6f4:
      return CONCAT44(iVar7,1);
    }
LAB_0100b702:
    return CONCAT44(iVar6,(uint)(DAT_21000c7a != 0));
  }
  uVar1 = *puVar4;
  bVar8 = (byte)uVar1 & 0xe3 | (*(byte *)(iVar6 + 0xbf) & 1) << 3 |
          (*(byte *)(iVar6 + 0xc0) & 1) << 2;
  *(byte *)puVar4 = bVar8;
  if ((((byte)uVar1 & 3) != 3) || (*(byte *)((int)puVar4 + 3) != 2)) {
    bVar2 = FUN_010275ae(DAT_21000cc8);
    if (bVar2) {
LAB_0100b56e:
      bVar8 = (byte)*DAT_21000cc4 | 0x10;
      puVar4 = DAT_21000cc4;
    }
    else {
      bVar8 = (byte)*DAT_21000cc4;
      puVar4 = DAT_21000cc4;
      if ((bVar8 & 3) != 3) {
        bVar2 = FUN_0100b1b0();
        if (!bVar2) goto LAB_0100b56e;
        bVar8 = (byte)*DAT_21000cc4;
        puVar4 = DAT_21000cc4;
      }
    }
  }
  *(byte *)puVar4 = bVar8;
  if ((*(char *)(iVar6 + 0xca) == '\0') || (*(byte *)((int)puVar4 + 1) == 0)) {
    FUN_01020f64((uint)puVar4);
    FUN_0102074c();
  }
  else {
    FUN_01020f64(DAT_21000ccc);
    DAT_21000ce0 = *(undefined4 *)(iVar6 + 0x120);
    DAT_21000ce4 = *(undefined4 *)(iVar6 + 0x124);
    DAT_21000ce8 = (char)DAT_21000c6c == '\0';
    FUN_01020698(DAT_21000ccc,DAT_21000cc4);
  }
  if (&DAT_00001d4b < *(undefined **)(iVar6 + 0x14)) {
LAB_0100b606:
    FUN_010210f0(0,1,(uint)*(byte *)(iVar6 + 0x6f));
  }
  else {
    FUN_010210f0(1,1,(uint)*(byte *)(iVar6 + 0x6f));
  }
  DAT_21000cf8 = 1;
  DAT_21000cfc = *DAT_21000cc4;
  DAT_21000c8c = 1;
  DAT_21000cfe = (byte)DAT_21000cc4[1];
  return CONCAT44(&DAT_21000cfc,(uint)*DAT_21000cc4);
}



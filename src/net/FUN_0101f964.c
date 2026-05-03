/*
 * Function: FUN_0101f964
 * Entry:    0101f964
 * Prototype: uint __stdcall FUN_0101f964(byte * param_1, byte * param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_0101f964(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  uint uVar9;
  byte *pbStack_28;
  byte *pbStack_24;
  undefined4 uStack_20;
  ushort local_1c;
  undefined2 uStack_1a;
  
  bVar1 = *param_1;
  if (0xef < bVar1) {
    return 0x12;
  }
  uVar2 = *(ushort *)(param_1 + 1);
  _local_1c = CONCAT22((short)((uint)param_4 >> 0x10),uVar2);
  uVar8 = (uint)uVar2;
  uVar9 = uVar8 & 0xff;
  if ((int)(uVar9 << 0x1b) < 0) {
    if ((uVar2 & 0x60) != 0) {
      return 0x12;
    }
    if ((((uVar8 & 7) != 5) && (1 < (uVar8 & 0xf) - 2)) && ((uVar2 & 0xf) != 0)) {
      return 0x12;
    }
  }
  else {
    if ((int)(uVar9 << 0x1a) < 0) {
      if ((uVar2 & 3) != 0) {
        return 0x12;
      }
    }
    else if ((uVar8 & 3) == 3) {
      return 0x12;
    }
    if (((int)(uVar9 << 0x1c) < 0) && ((uVar8 & 0x67) != 1)) {
      return 0x12;
    }
  }
  bVar5 = param_1[1];
  if (-1 < (int)((uint)bVar5 << 0x1c)) {
    if (*(uint3 *)(param_1 + 6) < *(uint3 *)(param_1 + 3)) {
      return 0x12;
    }
    if (*(uint3 *)(param_1 + 3) < 0x20) {
      return 0x12;
    }
  }
  if (6 < param_1[9] - 1) {
    return 0x12;
  }
  if (3 < param_1[10]) {
    return 0x12;
  }
  if (((bVar5 & 4) != 0) || (param_1[10] - 2 < 2)) {
    if (1 < param_1[0xb]) {
      return 0x12;
    }
    if ((bVar5 & 4) != 0) goto LAB_0101f9f0;
  }
  if (3 < param_1[0x12]) {
    return 0x12;
  }
LAB_0101f9f0:
  if ((bVar5 & 0x10) == 0) {
    if ((param_1[0x14] == 2) && ((bVar5 & 0x6f) != 9)) {
      return 0x12;
    }
    if (2 < param_1[0x16] - 1) {
      return 0x12;
    }
    if (0xf < param_1[0x17]) {
      return 0x12;
    }
  }
  else if (param_1[0x14] != 1) {
    return 0x12;
  }
  if (1 < param_1[0x18]) {
    return 0x12;
  }
  pbStack_28 = param_1;
  pbStack_24 = param_2;
  uStack_20 = param_3;
  if ((((bVar5 & 0x10) == 0) &&
      (((uVar8 = FUN_010200d8(), -1 < (int)(uVar8 << 0x1e) &&
        ((param_1[0x14] == 2 || (param_1[0x16] == 2)))) ||
       ((uVar8 = FUN_010200d8(), -1 < (int)(uVar8 << 0x1d) &&
        ((param_1[0x14] == 3 || (param_1[0x16] == 3)))))))) ||
     (((int)((uint)param_1[1] << 0x1f) < 0 && (cVar3 = FUN_0101ff9c(), cVar3 == '\0')))) {
    return 0x11;
  }
  if ((param_1[1] & 0x18) == 8) {
    if (param_1[0x14] != 2) {
      return 0x11;
    }
  }
  else if ((param_1[0x14] != 2) && (param_1[0x1a] != 0)) {
    return 0x11;
  }
  if ((-1 < (int)((uint)param_1[1] << 0x1c)) && (0x4000 < *(uint3 *)(param_1 + 6))) {
    return 0x11;
  }
  puVar6 = (undefined4 *)FUN_0100a518((ushort)bVar1,2);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)FUN_0100a468((ushort)bVar1,2);
    if (puVar6 == (undefined4 *)0x0) {
      return 7;
    }
    FUN_010129e4(puVar6,DAT_21001224);
  }
  else {
    cVar3 = FUN_010149d4((int)puVar6);
    if (cVar3 != '\0') {
      return 0xc;
    }
  }
  iVar7 = FUN_0102a2ea((ushort)bVar1,0);
  if ((iVar7 != 0) && (bVar4 = FUN_0102a338(iVar7 + 0x40), bVar4)) {
    if ((param_1[1] & 0x33) != 0) {
      return 0x12;
    }
    bVar1 = param_1[0x16];
    bVar5 = FUN_01012f00((int)puVar6);
    uVar8 = FUN_01028c64((uint)bVar5,extraout_r1,extraout_r2);
    if (bVar1 != uVar8) {
      return 0xc;
    }
  }
  iVar7 = FUN_01012ea8((int)puVar6);
  *param_2 = (byte)iVar7;
  param_1[0x13] = (byte)iVar7;
  uVar8 = FUN_01012c38(puVar6,param_1);
  if (param_1[0x19] == 0) {
    return uVar8;
  }
  if (uVar8 == 0) {
    FUN_01028384(&pbStack_28,puVar6[0x11],0);
    FUN_01028580(puVar6[0x11],'\x01',0);
    FUN_01028384(&pbStack_28,puVar6[0x11],4);
    FUN_01028580(puVar6[0x11],'\0',0);
    return 0;
  }
  return uVar8;
}



/*
 * Function: FUN_0100fc8c
 * Entry:    0100fc8c
 * Prototype: uint __stdcall FUN_0100fc8c(uint param_1, int param_2)
 */


uint FUN_0100fc8c(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  
  puVar5 = *(undefined **)(param_1 + 0x14);
  bVar1 = *(byte *)(param_1 + 0x6e);
  if (puVar5 < &DAT_00001d4c) {
    iVar8 = 0x4d;
  }
  else {
    iVar8 = 0x96;
  }
  bVar2 = *(byte *)(param_1 + 0x6f);
  uVar4 = (uint)*(ushort *)(param_1 + 0x38);
  if ((bVar1 & 0xc) == 0) {
    if (bVar1 == 1) {
      uVar6 = (uVar4 + 0xe) * 8;
    }
    else {
      if (bVar1 != 2) goto LAB_0100fda6;
      uVar6 = (uVar4 + 0xf) * 4;
    }
    uVar4 = (uint)*(ushort *)(param_1 + 0x4a);
    if ((uint)*(ushort *)(param_1 + 0x4e) <= (uint)*(ushort *)(param_1 + 0x4a)) {
      uVar4 = (uint)*(ushort *)(param_1 + 0x4e);
    }
    if ((uVar6 & 0xffff) <= uVar4) {
      uVar4 = uVar6 & 0xffff;
    }
    puVar5 = (undefined *)(uint)*(ushort *)(param_1 + 0x40);
    if ((bVar2 & 0xc) == 0) goto LAB_0100fccc;
LAB_0100fd28:
    puVar5 = (undefined *)((int)puVar5 * 0x40 + 0x3d0U & 0xffff);
    if ((undefined *)0xa8f < puVar5) {
      puVar5 = (undefined *)0xa90;
    }
    if (DAT_21000ef2 == '\0') {
LAB_0100fcec:
      *(undefined **)(param_1 + 0x34) = puVar5 + iVar8 + param_2 + 6 + uVar4;
      return param_1;
    }
    puVar7 = (undefined *)0xe90;
  }
  else {
    uVar6 = uVar4 * 0x40 + 0x3d0 & 0xffff;
    uVar4 = 0xa90;
    if (uVar6 < 0xa91) {
      uVar4 = uVar6;
    }
    puVar5 = (undefined *)(uint)*(ushort *)(param_1 + 0x40);
    if ((bVar2 & 0xc) != 0) goto LAB_0100fd28;
LAB_0100fccc:
    if (bVar2 == 1) {
      puVar5 = (undefined *)((int)(puVar5 + 0xe) * 8 & 0xffff);
      if ((undefined *)(uint)*(ushort *)(param_1 + 0x42) <= puVar5) {
        puVar5 = (undefined *)(uint)*(ushort *)(param_1 + 0x42);
      }
      if (DAT_21000ef2 == '\0') goto LAB_0100fcec;
      puVar7 = (undefined *)0x1c8;
    }
    else {
      if (bVar2 != 2) goto LAB_0100fda6;
      puVar5 = (undefined *)((int)(puVar5 + 0xf) * 4 & 0xffff);
      if ((undefined *)(uint)*(ushort *)(param_1 + 0x42) <= puVar5) {
        puVar5 = (undefined *)(uint)*(ushort *)(param_1 + 0x42);
      }
      if (DAT_21000ef2 == '\0') goto LAB_0100fcec;
      puVar7 = (undefined *)0xe8;
    }
  }
  if (puVar5 < puVar7) {
    puVar5 = puVar7;
  }
  if ((bVar1 & 0xc) == 0) {
    if (bVar1 == 1) {
      uVar6 = 0x1c8;
    }
    else {
      if (bVar1 != 2) {
LAB_0100fda6:
        puVar3 = (uint *)FUN_01009500(6,0x1e2,uVar4,puVar5);
        if (*puVar3 < 0x9d) {
          return 0;
        }
        return *puVar3 - 0x9c >> 1;
      }
      uVar6 = 0xe8;
    }
  }
  else {
    uVar6 = 0xe90;
  }
  if (uVar4 < uVar6) {
    uVar4 = uVar6;
  }
  *(undefined **)(param_1 + 0x34) = puVar5 + iVar8 + param_2 + 6 + uVar4;
  return param_1;
}



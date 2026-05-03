/*
 * Function: FUN_0100fb68
 * Entry:    0100fb68
 * Prototype: uint __stdcall FUN_0100fb68(int param_1, uint param_2, int param_3)
 */


uint FUN_0100fb68(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  
  bVar1 = *(byte *)(param_1 + 0x6e);
  if (&DAT_00001d4b < *(undefined **)(param_1 + 0x14)) {
    iVar9 = 0x96;
  }
  else {
    iVar9 = 0x4d;
  }
  bVar2 = *(byte *)(param_1 + 0x6f);
  uVar5 = (uint)*(ushort *)(param_1 + 0x38);
  if ((bVar1 & 0xc) != 0) {
    uVar8 = (uint)*(ushort *)(param_1 + 0x40);
    uVar5 = uVar5 * 0x40 + 0x3d0 & 0xffff;
    uVar4 = 0xa90;
    if (uVar5 < 0xa91) {
      uVar4 = uVar5;
    }
    if ((bVar2 & 0xc) == 0) goto LAB_0100fba8;
LAB_0100fc0c:
    uVar5 = uVar8 * 0x40 + 0x3d0 & 0xffff;
    if (0xa8f < uVar5) {
      uVar5 = 0xa90;
    }
    if (DAT_21000ef2 == '\0') goto LAB_0100fbc8;
    uVar8 = 0xe90;
LAB_0100fc2a:
    if (uVar5 < uVar8) {
      uVar5 = uVar8;
    }
    if ((bVar1 & 0xc) == 0) {
      if (bVar1 == 1) {
        uVar8 = 0x1c8;
      }
      else {
        if (bVar1 != 2) goto LAB_0100fc7e;
        uVar8 = 0xe8;
      }
    }
    else {
      uVar8 = 0xe90;
    }
    if (uVar4 < uVar8) {
      uVar4 = uVar8;
    }
LAB_0100fbc8:
    uVar5 = uVar5 + uVar4 + param_3 + 6 + iVar9 * 2;
    if (param_2 < uVar5) {
      uVar5 = 0;
    }
    else {
      uVar5 = param_2 - uVar5;
    }
    return uVar5;
  }
  if (bVar1 == 1) {
    uVar5 = (uVar5 + 0xe) * 8;
LAB_0100fbee:
    uVar5 = uVar5 & 0xffff;
    uVar4 = (uint)*(ushort *)(param_1 + 0x4a);
    if ((uint)*(ushort *)(param_1 + 0x4e) <= (uint)*(ushort *)(param_1 + 0x4a)) {
      uVar4 = (uint)*(ushort *)(param_1 + 0x4e);
    }
    uVar8 = (uint)*(ushort *)(param_1 + 0x40);
    if (uVar5 <= uVar4) {
      uVar4 = uVar5;
    }
    if ((bVar2 & 0xc) != 0) goto LAB_0100fc0c;
LAB_0100fba8:
    if (bVar2 == 1) {
      uVar5 = (uVar8 + 0xe) * 8 & 0xffff;
      if (*(ushort *)(param_1 + 0x42) <= uVar5) {
        uVar5 = (uint)*(ushort *)(param_1 + 0x42);
      }
      if (DAT_21000ef2 == '\0') goto LAB_0100fbc8;
      uVar8 = 0x1c8;
    }
    else {
      if (bVar2 != 2) goto LAB_0100fc7e;
      uVar8 = (uVar8 + 0xf) * 4 & 0xffff;
      uVar5 = (uint)*(ushort *)(param_1 + 0x42);
      if (uVar8 <= *(ushort *)(param_1 + 0x42)) {
        uVar5 = uVar8;
      }
      if (DAT_21000ef2 == '\0') goto LAB_0100fbc8;
      uVar8 = 0xe8;
    }
    goto LAB_0100fc2a;
  }
  if (bVar1 == 2) {
    uVar5 = (uVar5 + 0xf) * 4;
    goto LAB_0100fbee;
  }
LAB_0100fc7e:
  uVar5 = FUN_01009500(6,0x1e2,param_3,uVar5);
  puVar6 = *(undefined **)(uVar5 + 0x14);
  bVar1 = *(byte *)(uVar5 + 0x6e);
  if (puVar6 < &DAT_00001d4c) {
    iVar9 = 0x4d;
  }
  else {
    iVar9 = 0x96;
  }
  bVar2 = *(byte *)(uVar5 + 0x6f);
  uVar4 = (uint)*(ushort *)(uVar5 + 0x38);
  if ((bVar1 & 0xc) == 0) {
    if (bVar1 == 1) {
      uVar8 = (uVar4 + 0xe) * 8;
    }
    else {
      if (bVar1 != 2) goto LAB_0100fda6;
      uVar8 = (uVar4 + 0xf) * 4;
    }
    uVar4 = (uint)*(ushort *)(uVar5 + 0x4a);
    if ((uint)*(ushort *)(uVar5 + 0x4e) <= (uint)*(ushort *)(uVar5 + 0x4a)) {
      uVar4 = (uint)*(ushort *)(uVar5 + 0x4e);
    }
    if ((uVar8 & 0xffff) <= uVar4) {
      uVar4 = uVar8 & 0xffff;
    }
    puVar6 = (undefined *)(uint)*(ushort *)(uVar5 + 0x40);
    if ((bVar2 & 0xc) != 0) goto LAB_0100fd28;
LAB_0100fccc:
    if (bVar2 == 1) {
      puVar6 = (undefined *)((int)(puVar6 + 0xe) * 8 & 0xffff);
      if ((undefined *)(uint)*(ushort *)(uVar5 + 0x42) <= puVar6) {
        puVar6 = (undefined *)(uint)*(ushort *)(uVar5 + 0x42);
      }
      if (DAT_21000ef2 == '\0') {
LAB_0100fcec:
        *(undefined **)(uVar5 + 0x34) = puVar6 + iVar9 + 6 + uVar4;
        return uVar5;
      }
      puVar7 = (undefined *)0x1c8;
    }
    else {
      if (bVar2 != 2) goto LAB_0100fda6;
      puVar6 = (undefined *)((int)(puVar6 + 0xf) * 4 & 0xffff);
      if ((undefined *)(uint)*(ushort *)(uVar5 + 0x42) <= puVar6) {
        puVar6 = (undefined *)(uint)*(ushort *)(uVar5 + 0x42);
      }
      if (DAT_21000ef2 == '\0') goto LAB_0100fcec;
      puVar7 = (undefined *)0xe8;
    }
  }
  else {
    uVar8 = uVar4 * 0x40 + 0x3d0 & 0xffff;
    uVar4 = 0xa90;
    if (uVar8 < 0xa91) {
      uVar4 = uVar8;
    }
    puVar6 = (undefined *)(uint)*(ushort *)(uVar5 + 0x40);
    if ((bVar2 & 0xc) == 0) goto LAB_0100fccc;
LAB_0100fd28:
    puVar6 = (undefined *)((int)puVar6 * 0x40 + 0x3d0U & 0xffff);
    if ((undefined *)0xa8f < puVar6) {
      puVar6 = (undefined *)0xa90;
    }
    if (DAT_21000ef2 == '\0') goto LAB_0100fcec;
    puVar7 = (undefined *)0xe90;
  }
  if (puVar6 < puVar7) {
    puVar6 = puVar7;
  }
  if ((bVar1 & 0xc) == 0) {
    if (bVar1 == 1) {
      uVar8 = 0x1c8;
    }
    else {
      if (bVar1 != 2) {
LAB_0100fda6:
        puVar3 = (uint *)FUN_01009500(6,0x1e2,uVar4,puVar6);
        if (0x9c < *puVar3) {
          return *puVar3 - 0x9c >> 1;
        }
        return 0;
      }
      uVar8 = 0xe8;
    }
  }
  else {
    uVar8 = 0xe90;
  }
  if (uVar4 < uVar8) {
    uVar4 = uVar8;
  }
  *(undefined **)(uVar5 + 0x34) = puVar6 + iVar9 + 6 + uVar4;
  return uVar5;
}



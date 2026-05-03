/*
 * Function: FUN_010297a4
 * Entry:    010297a4
 * Prototype: int __stdcall FUN_010297a4(byte * param_1, undefined4 param_2)
 */


/* WARNING: Type propagation algorithm not settling */

int FUN_010297a4(byte *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  undefined2 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte *pbStack_20;
  undefined4 uStack_1c;
  
  uVar11 = (uint)param_1[1];
  pbStack_20 = param_1;
  uStack_1c = param_2;
  pcVar6 = (char *)FUN_0100a518((ushort)*param_1,2);
  if (pcVar6 == (char *)0x0) {
    return 0x42;
  }
  cVar1 = FUN_01020088();
  if (cVar1 == '\0') {
    uVar10 = (uint)param_1[3];
  }
  else {
    uVar7 = FUN_01012e44((int)pcVar6);
    uVar10 = (uint)param_1[3];
    if (uVar7 <= param_1[3]) {
      uVar10 = uVar7;
    }
    uVar10 = uVar10 & 0xffff;
  }
  if (uVar11 == 4) {
    if (uVar10 != 0) {
      return 0x12;
    }
  }
  else {
    uVar4 = FUN_0102876e(*(int *)(pcVar6 + 0x44));
    uVar7 = uVar4 + uVar10 & 0xffff;
    cVar1 = FUN_01020088();
    if (cVar1 == '\0') {
      if ((param_1[3] != 0) && (uVar8 = FUN_01012e68((int)pcVar6), uVar8 == 0)) {
        return 0x12;
      }
      uVar8 = FUN_01012e44((int)pcVar6);
      if (uVar8 < uVar7) {
        uVar11 = FUN_01012ee8((int)pcVar6);
        if (uVar11 != 0) {
          return 0x12;
        }
        return 7;
      }
    }
    bVar2 = FUN_01020088();
    iVar9 = FUN_01028dc0(pcVar6,uVar7,(uint)bVar2);
    if (iVar9 != 0) {
      return iVar9;
    }
    if ((1 < uVar11 - 3) && (uVar10 == 0)) {
      return 0x12;
    }
  }
  uVar7 = FUN_01012ee8((int)pcVar6);
  if ((param_1[1] != 3) &&
     ((uVar7 != 0 ||
      ((param_1[1] == 4 &&
       ((cVar1 = FUN_010149d4((int)pcVar6), cVar1 == '\0' ||
        (bVar3 = FUN_010287ec(*(int *)(pcVar6 + 0x44)), !bVar3)))))))) {
    return 0x12;
  }
  if ((uVar11 & 0xfd) == 1) {
    uVar7 = FUN_01012ee8((int)pcVar6);
    if (uVar7 == 0) {
      bVar2 = 1;
      if (uVar11 == 1) {
        bVar2 = 2;
      }
    }
    else {
      bVar2 = 0;
    }
    FUN_01028384(&pbStack_20,*(int *)(pcVar6 + 0x44),bVar2);
  }
  else if (uVar11 == 4) {
    FUN_01013168((int)pcVar6);
    return 0;
  }
  bVar3 = FUN_01028498(*(int *)(pcVar6 + 0x44),'\x01',*(undefined4 **)(param_1 + 4),(ushort)uVar10);
  if (bVar3) {
    if (param_1[1] - 2 < 2) {
      uVar5 = FUN_0102876e(*(int *)(pcVar6 + 0x44));
      FUN_01028580(*(int *)(pcVar6 + 0x44),'\x01',uVar5);
    }
    return 0;
  }
  return 7;
}



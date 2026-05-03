/*
 * Function: FUN_010298d0
 * Entry:    010298d0
 * Prototype: int __stdcall FUN_010298d0(byte * param_1, undefined4 param_2)
 */


int FUN_010298d0(byte *param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  short sVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  byte *pbStack_28;
  undefined4 uStack_24;
  
  uVar8 = (uint)param_1[1];
  uVar9 = (ushort)param_1[3];
  pbStack_28 = param_1;
  uStack_24 = param_2;
  pcVar5 = (char *)FUN_0100a518((ushort)*param_1,2);
  if (pcVar5 == (char *)0x0) {
    return 0x42;
  }
  cVar1 = FUN_01020088();
  if ((cVar1 != '\0') && (uVar6 = FUN_01012eb8((int)pcVar5), uVar6 == 0)) {
    uVar9 = 0;
  }
  sVar4 = FUN_0102878a(*(int *)(pcVar5 + 0x44));
  cVar1 = FUN_01020088();
  if (((cVar1 == '\0') && (param_1[3] != 0)) && (uVar6 = FUN_01012eb8((int)pcVar5), uVar6 == 0)) {
    return 0x12;
  }
  bVar2 = FUN_01020088();
  iVar7 = FUN_01028dc0(pcVar5,(uint)(ushort)(sVar4 + uVar9),(uint)bVar2);
  if (iVar7 != 0) {
    return iVar7;
  }
  if (uVar8 == 4) {
    return 0x12;
  }
  if (uVar8 != 3) {
    if (uVar9 == 0) {
      return 0x12;
    }
    cVar1 = FUN_010149d4((int)pcVar5);
    if (cVar1 != '\0') {
      return 0xc;
    }
    if (uVar8 != 1) goto LAB_01029988;
  }
  uVar6 = FUN_01012ee8((int)pcVar5);
  if (uVar6 == 0) {
    if (uVar8 == 1) {
      bVar2 = 6;
    }
    else {
      bVar2 = 5;
    }
  }
  else {
    bVar2 = 4;
  }
  FUN_01028384(&pbStack_28,*(int *)(pcVar5 + 0x44),bVar2);
LAB_01029988:
  bVar3 = FUN_01028498(*(int *)(pcVar5 + 0x44),'\0',*(undefined4 **)(param_1 + 4),uVar9);
  if (!bVar3) {
    return 7;
  }
  if (uVar8 - 2 < 2) {
    FUN_01028580(*(int *)(pcVar5 + 0x44),'\0',sVar4 + uVar9);
    return 0;
  }
  return 0;
}



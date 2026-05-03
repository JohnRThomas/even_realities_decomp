/*
 * Function: FUN_01013414
 * Entry:    01013414
 * Prototype: int __stdcall FUN_01013414(int param_1)
 */


int FUN_01013414(int param_1)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_12;
  undefined1 local_11;
  
  uVar3 = FUN_01012ee8(param_1);
  if (uVar3 == 0) {
    iVar4 = 0x8b;
  }
  else {
    uVar2 = FUN_01012eb0(param_1);
    if ((uVar2 == 0) && (uVar3 = FUN_01012eb8(param_1), uVar3 == 0)) {
      iVar5 = 0x7f;
      iVar4 = 0x75;
    }
    else {
      iVar5 = 0x89;
      iVar4 = 0x7f;
    }
    FUN_01022108();
    FUN_01022114();
    if (local_12 != '\0' || local_11 != '\0') {
      iVar4 = iVar5;
    }
    bVar1 = FUN_01026528();
    if (bVar1) {
      return iVar4 + 0x18;
    }
    bVar1 = FUN_010263e0();
    if (bVar1) {
      iVar4 = iVar4 + 0xf;
    }
  }
  return iVar4;
}



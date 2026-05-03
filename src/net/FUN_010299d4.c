/*
 * Function: FUN_010299d4
 * Entry:    010299d4
 * Prototype: undefined4 __stdcall FUN_010299d4(byte * param_1)
 */


undefined4 FUN_010299d4(byte *param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar3 = FUN_0100a518((ushort)*param_1,2);
  if (iVar3 == 0) {
    uVar4 = 0x42;
  }
  else {
    cVar1 = FUN_010149d4(iVar3);
    if ((cVar1 == '\0') ||
       ((uVar5 = FUN_01012eb8(iVar3), uVar5 == 0 && (uVar2 = FUN_01012eb0(iVar3), uVar2 == 0)))) {
      FUN_01012c24(iVar3,(undefined4 *)(param_1 + 1));
      uVar4 = 0;
    }
    else {
      uVar4 = 0xc;
    }
  }
  return uVar4;
}



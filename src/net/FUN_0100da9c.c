/*
 * Function: FUN_0100da9c
 * Entry:    0100da9c
 * Prototype: bool __stdcall FUN_0100da9c(int param_1)
 */


bool FUN_0100da9c(int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = *(byte *)(param_1 + 4) & 0xffffffe0;
  if ((*(byte *)(param_1 + 4) & 0xe0) != 0) {
    return false;
  }
  pbVar3 = (byte *)(param_1 + -1);
  do {
    pbVar3 = pbVar3 + 1;
    iVar1 = FUN_0100fee8((uint)*pbVar3);
    uVar2 = uVar2 + iVar1 & 0xff;
  } while (pbVar3 != (byte *)(param_1 + 4));
  return 1 < uVar2;
}



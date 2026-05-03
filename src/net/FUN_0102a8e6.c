/*
 * Function: FUN_0102a8e6
 * Entry:    0102a8e6
 * Prototype: undefined4 __stdcall FUN_0102a8e6(uint param_1)
 */


undefined4 FUN_0102a8e6(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_010222c0(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else if ((*(char *)(iVar1 + 0x24) == '\0') && (*(byte *)(iVar1 + 0x26) != 0)) {
    if (*(byte *)(iVar1 + 0x26) - 1 < 2) {
      FUN_0102a534(param_1,iVar1);
    }
    else {
      *(undefined1 *)(iVar1 + 0x24) = 1;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffdd;
  }
  return uVar2;
}



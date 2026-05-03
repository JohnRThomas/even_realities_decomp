/*
 * Function: FUN_01029aec
 * Entry:    01029aec
 * Prototype: undefined1 __stdcall FUN_01029aec(ushort * param_1)
 */


undefined1 FUN_01029aec(ushort *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_0100a518(*param_1,1);
  if (iVar2 == 0) {
    uVar1 = 2;
  }
  else if ((*(char *)(iVar2 + 0x3a0) == '\0') && (*(byte *)(iVar2 + 0xc6) - 0x16 < 2)) {
    *(undefined1 *)(iVar2 + 0x3a0) = 2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc;
  }
  return uVar1;
}



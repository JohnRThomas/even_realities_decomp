/*
 * Function: FUN_0003522c
 * Entry:    0003522c
 * Prototype: undefined4 * __stdcall FUN_0003522c(int param_1)
 */


undefined4 * FUN_0003522c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 10;
  piVar2 = &DAT_2000989c;
  while ((((char)piVar2[2] == '\0' || (*(char *)((int)piVar2 + 6) != '\0')) || (*piVar2 != param_1))
        ) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x6d;
    if (iVar1 == 0x14) {
      return (undefined4 *)0x0;
    }
  }
  return &DAT_2000878c + iVar1 * 0x6d;
}



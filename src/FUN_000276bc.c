/*
 * Function: FUN_000276bc
 * Entry:    000276bc
 * Prototype: undefined __stdcall FUN_000276bc(int param_1, undefined4 param_2)
 */


void FUN_000276bc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00027690();
  *(bool *)param_2 = iVar1 != 0;
  if (iVar1 != 0) {
    if (DAT_20019936 == '\0') {
      DAT_20019936 = '\x01';
    }
  }
  else if ((DAT_20019936 != '\0') && (DAT_20019936 = '\0', *(char *)(param_1 + 2) == '\0')) {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return;
}



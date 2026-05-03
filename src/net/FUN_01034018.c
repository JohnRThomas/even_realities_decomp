/*
 * Function: FUN_01034018
 * Entry:    01034018
 * Prototype: undefined4 __stdcall FUN_01034018(undefined1 * param_1)
 */


undefined4 FUN_01034018(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (DAT_21006458 == '\0') {
    if (DAT_21004a88 == 0) {
      uVar1 = 0xffffffc3;
    }
    else {
      FUN_010333e8(param_1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



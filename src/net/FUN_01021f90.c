/*
 * Function: FUN_01021f90
 * Entry:    01021f90
 * Prototype: undefined __stdcall FUN_01021f90(int param_1, undefined1 * param_2)
 */


void FUN_01021f90(int param_1,undefined1 *param_2)

{
  *param_2 = 0;
  if (*(undefined4 **)(param_1 + 0x58) != (undefined4 *)0x0) {
    FUN_01028294(DAT_21001664,*(undefined4 **)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}



/*
 * Function: FUN_0102924c
 * Entry:    0102924c
 * Prototype: undefined4 __stdcall FUN_0102924c(undefined1 * param_1)
 */


undefined4 FUN_0102924c(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_01028bfe();
  iVar1 = FUN_0100df14(iVar1);
  *param_1 = (char)iVar1;
  iVar1 = FUN_01028bfe();
  iVar1 = FUN_0100df14(iVar1);
  param_1[1] = (char)iVar1;
  return 0;
}



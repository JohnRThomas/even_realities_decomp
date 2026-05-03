/*
 * Function: FUN_0100dfbc
 * Entry:    0100dfbc
 * Prototype: undefined4 __stdcall FUN_0100dfbc(undefined4 * param_1)
 */


undefined4 FUN_0100dfbc(undefined4 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = DAT_21000014;
  if (DAT_21000ea8 == '\0') {
    *param_1 = DAT_21000010;
    *(undefined1 *)(param_1 + 1) = uVar1;
    return 1;
  }
  return 0;
}



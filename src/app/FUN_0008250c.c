/*
 * Function: FUN_0008250c
 * Entry:    0008250c
 * Prototype: undefined1 __stdcall FUN_0008250c(int param_1)
 */


undefined1 FUN_0008250c(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 1) {
    return **(undefined1 **)(param_1 + 0x88);
  }
  return 4;
}



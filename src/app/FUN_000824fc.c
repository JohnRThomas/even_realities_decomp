/*
 * Function: FUN_000824fc
 * Entry:    000824fc
 * Prototype: undefined __stdcall FUN_000824fc(int param_1, undefined1 param_2)
 */


void FUN_000824fc(int param_1,undefined1 param_2)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    **(undefined1 **)(param_1 + 0x88) = param_2;
  }
  return;
}



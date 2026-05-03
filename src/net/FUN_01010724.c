/*
 * Function: FUN_01010724
 * Entry:    01010724
 * Prototype: undefined4 __stdcall FUN_01010724(int param_1)
 */


undefined4 FUN_01010724(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 4) + 0xc6) == '\x13') {
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x14;
    return 0;
  }
  return 2;
}



/*
 * Function: FUN_0101073c
 * Entry:    0101073c
 * Prototype: undefined4 __stdcall FUN_0101073c(int param_1)
 */


undefined4 FUN_0101073c(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 4) + 0xc6) != '\x19') {
    return 2;
  }
  FUN_0100ffb0(param_1);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0x1d;
  return 0;
}



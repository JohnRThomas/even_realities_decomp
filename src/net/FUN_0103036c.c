/*
 * Function: FUN_0103036c
 * Entry:    0103036c
 * Prototype: undefined4 __stdcall FUN_0103036c(int param_1)
 */


undefined4 FUN_0103036c(int param_1)

{
  if (DAT_210047f8 != 0) {
    return 0xffffff88;
  }
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    DAT_210047f8 = param_1;
    return 0;
  }
  return 0xffffffea;
}



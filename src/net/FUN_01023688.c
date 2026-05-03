/*
 * Function: FUN_01023688
 * Entry:    01023688
 * Prototype: undefined4 __stdcall FUN_01023688(uint param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_01023688(uint param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 < 0x20) {
    (&DAT_210017c0)[param_1 * 8] = param_2;
    (&DAT_210017c4)[param_1 * 8] = param_3;
    return 1;
  }
  return 0;
}



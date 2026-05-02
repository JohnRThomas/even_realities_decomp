/*
 * Function: FUN_0007f9c4
 * Entry:    0007f9c4
 * Prototype: undefined4 __stdcall FUN_0007f9c4(int param_1, undefined4 * param_2)
 */


undefined4 FUN_0007f9c4(int param_1,undefined4 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    param_2[1] = *(undefined4 *)(param_1 + 0x10);
    return 0;
  }
  return 7;
}



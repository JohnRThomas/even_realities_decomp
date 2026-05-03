/*
 * Function: FUN_0100b1d4
 * Entry:    0100b1d4
 * Prototype: undefined __stdcall FUN_0100b1d4(int param_1, undefined4 * param_2)
 */


void FUN_0100b1d4(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    DAT_21000c38 = *param_2;
    DAT_21000c34 = 1;
    DAT_21000c3c = *(undefined2 *)(param_2 + 1);
    return;
  }
  if (param_1 != 1) {
    return;
  }
  DAT_21000c3e = 1;
  DAT_21000c40 = *param_2;
  DAT_21000c44 = *(undefined2 *)(param_2 + 1);
  return;
}



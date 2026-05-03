/*
 * Function: FUN_0102601c
 * Entry:    0102601c
 * Prototype: undefined __stdcall FUN_0102601c(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0102601c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (4 < param_1) {
    param_1 = FUN_01025edc(0x69,0x4f,param_3,param_4);
  }
  (&DAT_21001c28)[param_1 * 8] = 0;
  return;
}



/*
 * Function: FUN_0103428c
 * Entry:    0103428c
 * Prototype: undefined4 __stdcall FUN_0103428c(uint param_1)
 */


undefined4 FUN_0103428c(uint param_1)

{
  if (DAT_21006458 != '\0') {
    return 0xfffffff0;
  }
  if (param_1 < 0x65) {
    DAT_21000697 = (char)param_1;
    return 0;
  }
  return 0xffffffea;
}



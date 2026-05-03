/*
 * Function: FUN_0100982c
 * Entry:    0100982c
 * Prototype: undefined __stdcall FUN_0100982c(void)
 */


void FUN_0100982c(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  if (DAT_21000a5c != '\0') {
    FUN_01020050();
    FUN_0102601c((uint)DAT_21000a5e,extraout_r1,extraout_r2,extraout_r3);
  }
  FUN_0100afb0();
  DAT_21000a5c = 0;
  return;
}



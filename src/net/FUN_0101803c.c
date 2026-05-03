/*
 * Function: FUN_0101803c
 * Entry:    0101803c
 * Prototype: undefined __stdcall FUN_0101803c(void)
 */


void FUN_0101803c(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_2100104c = 0;
  DAT_21001000 = 0;
  FUN_01016ec0(0,DAT_21001050);
  FUN_0101bd4c(2,extraout_r1,extraout_r2);
  return;
}



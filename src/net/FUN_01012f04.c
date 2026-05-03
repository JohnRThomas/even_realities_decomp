/*
 * Function: FUN_01012f04
 * Entry:    01012f04
 * Prototype: undefined __stdcall FUN_01012f04(undefined4 param_1)
 */


void FUN_01012f04(undefined4 param_1)

{
  DAT_21000f4c = param_1;
                    /* WARNING: Could not recover jumptable at 0x01012f0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*DAT_21000f48)();
  return;
}



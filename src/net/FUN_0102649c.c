/*
 * Function: FUN_0102649c
 * Entry:    0102649c
 * Prototype: undefined __stdcall FUN_0102649c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0102649c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    FUN_01025edc(0x68,0x153,param_3,param_4);
  }
  if ((DAT_21001c89 != '\x02') && (DAT_21001c89 != '\x03')) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x010264c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_21001c90 + 4))();
  return;
}



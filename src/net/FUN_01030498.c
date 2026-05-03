/*
 * Function: FUN_01030498
 * Entry:    01030498
 * Prototype: undefined4 __stdcall FUN_01030498(int param_1)
 */


undefined4 FUN_01030498(int param_1)

{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x010304a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(DAT_210047f8 + 0x14))();
    return uVar1;
  }
  return 0x12;
}



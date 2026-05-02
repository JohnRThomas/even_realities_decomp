/*
 * Function: FUN_0007f742
 * Entry:    0007f742
 * Prototype: undefined4 __stdcall FUN_0007f742(int param_1)
 */


undefined4 FUN_0007f742(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 7;
  }
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007f748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1 + 0xc))();
    return uVar1;
  }
  return 0xf;
}



/*
 * Function: $_i2c_read_byte
 * Entry:    0007f770
 * Prototype: undefined4 __stdcall $_i2c_read_byte(int param_1)
 */


undefined4 __i2c_read_byte(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x14) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0x14) + 4),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0007f77c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return *(undefined4 *)(param_1 + 0x10);
}



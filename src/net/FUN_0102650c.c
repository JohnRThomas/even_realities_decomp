/*
 * Function: FUN_0102650c
 * Entry:    0102650c
 * Prototype: undefined4 __stdcall FUN_0102650c(void)
 */


undefined4 FUN_0102650c(void)

{
  undefined4 uVar1;
  
  if ((DAT_21001c89 != '\x02') && (DAT_21001c89 != '\x03')) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0102651e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_21001c90 + 0x18))();
  return uVar1;
}



/*
 * Function: FUN_010264f0
 * Entry:    010264f0
 * Prototype: undefined4 __stdcall FUN_010264f0(void)
 */


undefined4 FUN_010264f0(void)

{
  undefined4 uVar1;
  
  if ((DAT_21001c89 != '\x02') && (DAT_21001c89 != '\x03')) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x01026502. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_21001c90 + 0x10))();
  return uVar1;
}



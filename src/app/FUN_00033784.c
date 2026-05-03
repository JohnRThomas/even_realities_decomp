/*
 * Function: FUN_00033784
 * Entry:    00033784
 * Prototype: undefined4 __stdcall FUN_00033784(void)
 */


undefined4 FUN_00033784(void)

{
  undefined4 uVar1;
  
  if ((DAT_2001abc0 == '\x01') && (DAT_2001abc1 != '\x01')) {
    if (DAT_2001abc1 == '\x02') {
      uVar1 = 0x46;
    }
    else {
      uVar1 = 0x55;
    }
    return uVar1;
  }
  return 100;
}



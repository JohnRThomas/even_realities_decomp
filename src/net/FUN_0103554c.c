/*
 * Function: FUN_0103554c
 * Entry:    0103554c
 * Prototype: undefined1 * __stdcall FUN_0103554c(undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined1 * FUN_0103554c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  
  if (param_2 == 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",0x34,param_4);
    FUN_0103a370();
  }
  if (DAT_21004af0 == '\0') {
    FUN_0102f2ec('\x12');
    puVar1 = &DAT_0bad0000;
    DAT_21004af0 = '\x01';
    DAT_21004aec = param_2;
    DAT_21004af4 = param_3;
  }
  else {
    puVar1 = &DAT_0bad000c;
  }
  return puVar1;
}



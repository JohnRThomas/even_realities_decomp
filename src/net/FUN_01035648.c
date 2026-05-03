/*
 * Function: FUN_01035648
 * Entry:    01035648
 * Prototype: undefined __stdcall FUN_01035648(uint param_1)
 */


void FUN_01035648(uint param_1)

{
  int extraout_r3;
  int iVar1;
  
  iVar1 = 1;
  if (DAT_21004af0 != 1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",0x72,
                 (uint)DAT_21004af0);
    param_1 = FUN_0103a370();
    iVar1 = extraout_r3;
  }
  Peripherals::IPC_NS.INTENCLR = iVar1 << (param_1 & 0xff);
  return;
}



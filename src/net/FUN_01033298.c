/*
 * Function: FUN_01033298
 * Entry:    01033298
 * Prototype: undefined __stdcall FUN_01033298(undefined4 param_1, byte param_2)
 */


void FUN_01033298(undefined4 param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r3;
  uint local_c;
  
  FUN_01022120();
  iVar1 = FUN_010220fc();
  uVar2 = 0;
  if (iVar1 != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/nrf/subsys/esb/esb.c",0x242,
                 extraout_r3);
    uVar2 = FUN_0103a370();
  }
  if ('\0' < (char)param_2) {
    uVar2 = 1;
    param_2 = param_2 - 3;
  }
  local_c = (uint)param_2;
  Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = uVar2;
  Peripherals::RADIO_NS.TXPOWER = local_c;
  return;
}



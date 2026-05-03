/*
 * Function: FUN_01020854
 * Entry:    01020854
 * Prototype: undefined __stdcall FUN_01020854(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020854(void)

{
  _DAT_e000e180 = 0x4000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  Peripherals::AAR_NS.ENABLE = 0;
  Peripherals::AAR_NS.ENABLE = 0;
  FUN_0102074c();
  Peripherals::AAR_NS.SUBSCRIBE_START = 0;
  return;
}



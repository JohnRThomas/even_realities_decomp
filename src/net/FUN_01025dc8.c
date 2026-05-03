/*
 * Function: FUN_01025dc8
 * Entry:    01025dc8
 * Prototype: undefined __stdcall FUN_01025dc8(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01025dc8(void)

{
  Peripherals::TEMP_NS.TASKS_STOP = 1;
  Peripherals::TEMP_NS.INTENCLR = 0xffffffff;
  _DAT_e000e180 = 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e280 = 0x10000;
  return;
}



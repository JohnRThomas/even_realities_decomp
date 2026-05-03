/*
 * Function: FUN_01025f68
 * Entry:    01025f68
 * Prototype: uint __stdcall FUN_01025f68(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01025f68(void)

{
  uint uVar1;
  uint uVar2;
  
  _DAT_e000e180 = 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  Peripherals::TEMP_NS.EVENTS_DATARDY = 0;
  _DAT_e000e280 = 0x10000;
  uVar2 = _DAT_e000ed10 & 0x10;
  _DAT_e000ed10 = _DAT_e000ed10 | 0x10;
  Peripherals::TEMP_NS.INTENSET = 1;
  Peripherals::TEMP_NS.TASKS_START = 1;
  while (uVar1 = Peripherals::TEMP_NS.EVENTS_DATARDY, uVar1 == 0) {
    FUN_0102aa1e();
  }
  if (uVar2 == 0) {
    _DAT_e000ed10 = _DAT_e000ed10 & 0xffffffef;
  }
  uVar2 = Peripherals::TEMP_NS.TEMP;
  Peripherals::TEMP_NS.TASKS_STOP = 1;
  Peripherals::TEMP_NS.INTENCLR = 1;
  Peripherals::TEMP_NS.EVENTS_DATARDY = 0;
  _DAT_e000e280 = 0x10000;
  return uVar2;
}



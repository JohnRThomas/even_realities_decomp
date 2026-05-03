/*
 * Function: FUN_0100af60
 * Entry:    0100af60
 * Prototype: undefined __stdcall FUN_0100af60(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0100af60(void)

{
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e180 = 0x4000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e280 = 0x4000;
  return;
}



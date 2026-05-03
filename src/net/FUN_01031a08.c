/*
 * Function: FUN_01031a08
 * Entry:    01031a08
 * Prototype: bool __stdcall FUN_01031a08(uint param_1)
 */


bool FUN_01031a08(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_2100496c;
  uVar2 = 1 << (param_1 & 0xff);
  DAT_2100496c = DAT_2100496c & ~uVar2;
  Peripherals::RTC1_NS.INTENCLR = 0x10000 << (param_1 & 0xff);
  DataMemoryBarrier(0x1f);
  InstructionSynchronizationBarrier(0xf);
  return (uVar2 & uVar1) != 0;
}



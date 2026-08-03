/*
 * Function: compare_int_lock
 * Entry:    00066744
 * Prototype: bool __stdcall compare_int_lock(int32_t chan)
 */


/* exclude_from_export */

bool compare_int_lock(int32_t chan)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_2000bcc0;
  uVar2 = 1 << (chan & 0xffU);
  DAT_2000bcc0 = DAT_2000bcc0 & ~uVar2;
  Peripherals::RTC1_S.INTENCLR = 0x10000 << (chan & 0xffU);
  DataMemoryBarrier(0x1f);
  InstructionSynchronizationBarrier(0xf);
  return (uVar2 & uVar1) != 0;
}



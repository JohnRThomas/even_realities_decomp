/*
 * Function: z_nrf_rtc_timer_read
 * Entry:    000668b8
 * Prototype: uint64_t __stdcall z_nrf_rtc_timer_read(void)
 */


/* exclude_from_export */

uint64_t z_nrf_rtc_timer_read(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  DataMemoryBarrier(0x1f);
  uVar1 = Peripherals::RTC1_S.COUNTER;
  uVar2 = uVar1 + DAT_2000bcc4 * 0x1000000;
  uVar3 = (DAT_2000bcc4 >> 8) + (uint)CARRY4(uVar1,DAT_2000bcc4 * 0x1000000);
  if ((uVar1 < 0x100000) &&
     (uVar3 <= DAT_2000689c && (uint)(DAT_20006898 <= uVar2) <= uVar3 - DAT_2000689c)) {
    bVar4 = 0xfeffffff < uVar2;
    uVar2 = uVar2 + 0x1000000;
    uVar3 = uVar3 + bVar4;
  }
  return CONCAT44(uVar3,uVar2);
}



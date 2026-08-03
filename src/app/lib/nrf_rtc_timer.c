/*
 * Function: nrf_rtc_timer
 * Entry:    00066b04
 * Prototype: uint __stdcall nrf_rtc_timer(void)
 */


/* exclude_from_export_ai */

uint nrf_rtc_timer(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    if (DAT_2000bcbc == 0) {
      return 0xfffffff4;
    }
    uVar1 = 0x1f - LZCOUNT(DAT_2000bcbc);
    uVar3 = DAT_2000bcbc & ~(1 << (uVar1 & 0xff));
    uVar2 = DAT_2000bcbc >> (uVar1 & 0xff);
    DAT_2000bcbc = uVar3;
  } while (-1 < (int)(uVar2 << 0x1f));
  return uVar1;
}



/*
 * Function: compare_int_unlock
 * Entry:    000667cc
 * Prototype: void __stdcall compare_int_unlock(int32_t chan, bool key)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void compare_int_unlock(int32_t chan,bool key)

{
  if (key) {
    DAT_2000bcc0 = DAT_2000bcc0 | 1 << (chan & 0xffU);
    Peripherals::RTC1_S.INTENSET = 0x10000 << (chan & 0xffU);
    if ((int)((DAT_2000bcb8 >> (chan & 0xffU)) << 0x1f) < 0) {
      _DAT_e000e200 = 0x200000;
    }
  }
  return;
}



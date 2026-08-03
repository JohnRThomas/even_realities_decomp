/*
 * Function: event_clear
 * Entry:    0008840e
 * Prototype: void __stdcall event_clear(int32_t chan)
 */


/* exclude_from_export */

void event_clear(int32_t chan)

{
  *(undefined4 *)((int)&Peripherals::RTC1_S.TASKS_START + ((chan + 0x50) * 4 & 0xffffU)) = 0;
  return;
}



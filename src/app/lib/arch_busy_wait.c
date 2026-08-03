/*
 * Function: arch_busy_wait
 * Entry:    00089b34
 * Prototype: void __stdcall arch_busy_wait(uint32_t usec_to_wait)
 */


/* exclude_from_export */

void arch_busy_wait(uint32_t usec_to_wait)

{
  if (usec_to_wait == 0) {
    return;
  }
  if (usec_to_wait != 0) {
    (*(code *)(undefined *)0x8bff0)((DAT_20002bd8 / 1000000) * usec_to_wait);
    return;
  }
  return;
}



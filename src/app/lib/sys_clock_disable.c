/*
 * Function: sys_clock_disable
 * Entry:    00066bfc
 * Prototype: undefined __stdcall sys_clock_disable(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void sys_clock_disable(void)

{
  Peripherals::RTC1_S.TASKS_STOP = 1;
  arch_irq_disable(0x15);
  Peripherals::RTC1_S.INTENCLR = 0xf0003;
  Peripherals::RTC1_S.EVTENCLR = 0xf0003;
  _DAT_e000e280 = 0x200000;
  return;
}



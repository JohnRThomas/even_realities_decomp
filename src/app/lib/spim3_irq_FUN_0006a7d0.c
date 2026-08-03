/*
 * Function: $_spim3_irq_FUN_0006a7d0
 * Entry:    0006a7d0
 * Prototype: undefined __stdcall $_spim3_irq_FUN_0006a7d0(void)
 */


/* exclude_from_export */

void __spim3_irq_FUN_0006a7d0(void)

{
  irq_handler((NRF_SPIM_Type *)&Peripherals::SPIM3_S,&DAT_2000bd6c);
  return;
}



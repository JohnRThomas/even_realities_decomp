/*
 * Function: $_spim4_irq_FUN_0006a7e0
 * Entry:    0006a7e0
 * Prototype: undefined __stdcall $_spim4_irq_FUN_0006a7e0(void)
 */


/* exclude_from_export */

void __spim4_irq_FUN_0006a7e0(void)

{
  irq_handler((NRF_SPIM_Type *)&Peripherals::SPIM4_S,&DAT_2000bd90);
  return;
}



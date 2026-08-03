/*
 * Function: $_spim2_irq_FUN_0006b01c
 * Entry:    0006b01c
 * Prototype: undefined __stdcall $_spim2_irq_FUN_0006b01c(void)
 */


/* exclude_from_export */

void __spim2_irq_FUN_0006b01c(void)

{
  irq_handler((device *)&Peripherals::SPIM2_S);
  return;
}



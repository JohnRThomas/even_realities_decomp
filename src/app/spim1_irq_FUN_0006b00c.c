/*
 * Function: $_spim1_irq_FUN_0006b00c
 * Entry:    0006b00c
 * Prototype: undefined __stdcall $_spim1_irq_FUN_0006b00c(void)
 */


void __spim1_irq_FUN_0006b00c(void)

{
  irq_handler((device *)&Peripherals::SPIM1_S);
  return;
}



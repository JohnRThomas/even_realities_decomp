/*
 * Function: tfm_spim2_irq_init
 * Entry:    00087484
 * Prototype: undefined __stdcall tfm_spim2_irq_init(void)
 */


/* exclude_from_export */

void tfm_spim2_irq_init(void)

{
  z_arm_irq_priority_set(0xb,1,0);
  return;
}



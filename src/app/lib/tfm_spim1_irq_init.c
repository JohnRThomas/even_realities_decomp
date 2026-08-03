/*
 * Function: tfm_spim1_irq_init
 * Entry:    0008747a
 * Prototype: undefined __stdcall tfm_spim1_irq_init(void)
 */


/* exclude_from_export */

void tfm_spim1_irq_init(void)

{
  z_arm_irq_priority_set(9,1,0);
  return;
}



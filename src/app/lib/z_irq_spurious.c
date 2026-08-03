/*
 * Function: z_irq_spurious
 * Entry:    00083f1a
 * Prototype: void __stdcall z_irq_spurious(void * unused)
 */


/* exclude_from_export */

void z_irq_spurious(void *unused)

{
  z_arm_fatal_error(1,(z_arch_esf_t *)0x0);
  return;
}



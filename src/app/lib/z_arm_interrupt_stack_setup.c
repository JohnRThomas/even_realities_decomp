/*
 * Function: z_arm_interrupt_stack_setup
 * Entry:    00053d00
 * Prototype: void __stdcall z_arm_interrupt_stack_setup(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_arm_interrupt_stack_setup(void)

{
  _DAT_e000ed14 = _DAT_e000ed14 | 0x410;
  return;
}



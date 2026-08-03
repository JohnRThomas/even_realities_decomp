/*
 * Function: fatal_error
 * Entry:    00083f12
 * Prototype: undefined __stdcall fatal_error(z_arch_esf_t * param_1)
 */


/* exclude_from_export */

void fatal_error(z_arch_esf_t *param_1)

{
  z_arm_fatal_error(*param_1,param_1);
  return;
}



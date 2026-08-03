/*
 * Function: FUN_00053550
 * Entry:    00053550
 * Prototype: z_arch_esf_t * __stdcall FUN_00053550(void)
 */


/* exclude_from_export */

z_arch_esf_t * FUN_00053550(void)

{
  z_arch_esf_t *pzVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    pzVar1 = (z_arch_esf_t *)getMainStackPointer();
  }
  else {
    pzVar1 = (z_arch_esf_t *)getProcessStackPointer();
  }
  fatal_error(pzVar1);
  return pzVar1;
}



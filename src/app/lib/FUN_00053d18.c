/*
 * Function: FUN_00053d18
 * Entry:    00053d18
 * Prototype: z_arch_esf_t * __stdcall FUN_00053d18(void)
 */


/* exclude_from_export */

z_arch_esf_t * FUN_00053d18(void)

{
  z_arch_esf_t *esf;
  int fault;
  bool *unaff_lr;
  
  esf = (z_arch_esf_t *)getMainStackPointer();
  fault = getProcessStackPointer();
  fault_handle(esf,fault,unaff_lr);
  return esf;
}



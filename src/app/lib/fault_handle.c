/*
 * Function: fault_handle
 * Entry:    00053d20
 * Prototype: uint32_t __stdcall fault_handle(z_arch_esf_t * esf, int fault, bool * recoverable)
 */


/* exclude_from_export */

uint32_t fault_handle(z_arch_esf_t *esf,int fault,bool *recoverable)

{
  bool *unaff_lr;
  
  fault_handle(esf,fault,unaff_lr);
  return (uint32_t)esf;
}



/*
 * Function: k_sem_init
 * Entry:    0007f2d8
 * Prototype: undefined __stdcall k_sem_init(k_sem * param_1, uint param_2)
 */


/* exclude_from_export */

void k_sem_init(k_sem *param_1,uint param_2)

{
  z_impl_k_sem_init(param_1,0,param_2);
  return;
}



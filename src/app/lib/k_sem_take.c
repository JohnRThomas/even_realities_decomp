/*
 * Function: k_sem_take
 * Entry:    00088fea
 * Prototype: int __stdcall k_sem_take(k_sem * sem, k_timeout_t timeout)
 */


/* exclude_from_export */

int k_sem_take(k_sem *sem,k_timeout_t timeout)

{
  int iVar1;
  k_timeout_t timeout_00;
  
  timeout_00.ticks._0_4_ = (undefined4)timeout.ticks;
  timeout_00.ticks._4_4_ = 0xffffffff;
  iVar1 = z_impl_k_sem_take(sem,timeout_00);
  return iVar1;
}



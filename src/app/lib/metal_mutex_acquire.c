/*
 * Function: metal_mutex_acquire
 * Entry:    00089166
 * Prototype: void __stdcall metal_mutex_acquire(metal_mutex_t * mutex)
 */


/* exclude_from_export */

void metal_mutex_acquire(metal_mutex_t *mutex)

{
  undefined4 in_r1;
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  z_impl_k_sem_take((k_sem *)mutex,timeout);
  return;
}



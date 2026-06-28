/*
 * Function: lock_k_mutex_20007f54
 * Entry:    00019cf8
 * Prototype: undefined __stdcall lock_k_mutex_20007f54(undefined4 param_1, undefined4 param_2)
 */


void lock_k_mutex_20007f54(undefined4 param_1,undefined4 param_2)

{
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = param_1;
  timeout.ticks._0_4_ = param_2;
  z_impl_k_mutex_lock(&k_mutex_20007f54,timeout);
  return;
}



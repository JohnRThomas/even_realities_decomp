/*
 * Function: FUN_0007fc18
 * Entry:    0007fc18
 * Prototype: undefined __stdcall FUN_0007fc18(int param_1, undefined4 param_2)
 */


void FUN_0007fc18(int param_1,undefined4 param_2)

{
  k_timeout_t timeout;
  
  if (param_1 != 0) {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = param_2;
    z_impl_k_mutex_lock(*(k_mutex **)(param_1 + 0x10),timeout);
  }
  return;
}



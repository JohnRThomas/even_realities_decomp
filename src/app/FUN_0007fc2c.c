/*
 * Function: FUN_0007fc2c
 * Entry:    0007fc2c
 * Prototype: undefined __stdcall FUN_0007fc2c(int param_1)
 */


void FUN_0007fc2c(int param_1)

{
  if (param_1 != 0) {
    z_impl_k_mutex_unlock(*(k_mutex **)(param_1 + 0x10));
  }
  return;
}



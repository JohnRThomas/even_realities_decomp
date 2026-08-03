/*
 * Function: api_blocking_start
 * Entry:    000639ac
 * Prototype: undefined __stdcall api_blocking_start(int param_1, byte param_2)
 */


/* exclude_from_export */

void api_blocking_start(int param_1,byte param_2)

{
  undefined8 uVar1;
  k_timeout_t timeout;
  k_sem *local_20;
  k_sem *local_1c;
  uint local_18;
  uint uStack_14;
  
  local_18 = 0;
  uStack_14 = 1;
  local_20 = (k_sem *)&local_20;
  local_1c = (k_sem *)&local_20;
  uVar1 = api_start(param_1,param_2,0x8703f,(k_sem *)&local_20);
  timeout.ticks._0_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
  if (-1 < (int)uVar1) {
    timeout.ticks._4_4_ = 0x4000;
    z_impl_k_sem_take((k_sem *)&local_20,timeout);
  }
  return;
}



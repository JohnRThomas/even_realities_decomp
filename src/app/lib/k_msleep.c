/*
 * Function: k_msleep
 * Entry:    0007fef6
 * Prototype: int32_t __stdcall k_msleep(int32_t ms)
 */


/* exclude_from_export_ai */

int32_t k_msleep(int32_t ms)

{
  undefined4 extraout_r0;
  int32_t iVar1;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  
  __aeabi_uldivmod(ms * 0x8000 + 999,ms >> 0x11,1000,0);
  timeout.ticks._4_4_ = extraout_r1;
  timeout.ticks._0_4_ = extraout_r0;
  iVar1 = z_impl_k_sleep(timeout);
  return iVar1;
}



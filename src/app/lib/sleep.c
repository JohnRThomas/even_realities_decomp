/*
 * Function: $_?_sleep
 * Entry:    00087d8c
 * Prototype: uint __stdcall $_?_sleep(uint __seconds)
 */


/* exclude_from_export */

uint ____sleep(uint __seconds)

{
  longlong lVar1;
  undefined4 extraout_r0;
  uint uVar2;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  
  lVar1 = (longlong)(int)(__seconds & ~((int)__seconds >> 0x1f)) * 0x8000 + 999;
  __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000,0);
  timeout.ticks._4_4_ = extraout_r1;
  timeout.ticks._0_4_ = extraout_r0;
  uVar2 = z_impl_k_sleep(timeout);
  return uVar2;
}



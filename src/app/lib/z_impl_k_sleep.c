/*
 * Function: z_impl_k_sleep
 * Entry:    00080314
 * Prototype: uint __stdcall z_impl_k_sleep(int param_1, int param_2)
 */


/* exclude_from_export */

uint z_impl_k_sleep(int param_1,int param_2)

{
  bool bVar1;
  int32_t iVar2;
  char *test;
  char *file;
  uint uVar3;
  int line;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if (uVar3 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/sched.c",
            0x5c1);
    _ASSERT("\t\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (param_2 == -1 && param_1 == -1) {
    k_thread_suspend((k_tid_t)_current.base);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = z_tick_sleep(CONCAT44(param_2,param_1));
    uVar3 = (uint)((longlong)iVar2 * 1000) >> 0xf |
            (int)((ulonglong)((longlong)iVar2 * 1000) >> 0x20) << 0x11;
  }
  return uVar3;
}



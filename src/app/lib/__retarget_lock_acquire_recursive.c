/*
 * Function: __retarget_lock_acquire_recursive
 * Entry:    000543a8
 * Prototype: void __stdcall __retarget_lock_acquire_recursive(_LOCK_T lock)
 */


/* exclude_from_export */

void __retarget_lock_acquire_recursive(_LOCK_T lock)

{
  undefined4 in_r1;
  k_timeout_t timeout;
  
  if (lock == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","lock != ((void *)0)",
            "WEST_TOPDIR/zephyr/lib/libc/newlib/libc-hooks.c",422);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  z_impl_k_mutex_lock((k_mutex *)lock,timeout);
  return;
}



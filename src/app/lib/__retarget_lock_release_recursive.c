/*
 * Function: __retarget_lock_release_recursive
 * Entry:    000543e0
 * Prototype: void __stdcall __retarget_lock_release_recursive(_LOCK_T lock)
 */


/* exclude_from_export */

void __retarget_lock_release_recursive(_LOCK_T lock)

{
  if (lock == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","lock != ((void *)0)",
            "WEST_TOPDIR/zephyr/lib/libc/newlib/libc-hooks.c",450);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  z_impl_k_mutex_unlock((k_mutex *)lock);
  return;
}



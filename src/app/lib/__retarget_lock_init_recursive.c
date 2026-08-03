/*
 * Function: __retarget_lock_init_recursive
 * Entry:    00054348
 * Prototype: void __stdcall __retarget_lock_init_recursive(_LOCK_T * lock)
 */


/* exclude_from_export */

void __retarget_lock_init_recursive(_LOCK_T *lock)

{
  k_mutex *mutex;
  char *test;
  char *file;
  int line;
  
  if (lock == (_LOCK_T *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","lock != ((void *)0)",
            "WEST_TOPDIR/zephyr/lib/libc/newlib/libc-hooks.c",377);
  }
  else {
    mutex = malloc(0x14);
    *lock = (_LOCK_T)mutex;
    if (mutex != (k_mutex *)0x0) {
      z_impl_k_mutex_init(mutex);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","*lock != ((void *)0)",
            "WEST_TOPDIR/zephyr/lib/libc/newlib/libc-hooks.c",385);
    _ASSERT("\trecursive lock allocation failed\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



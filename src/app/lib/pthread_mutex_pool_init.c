/*
 * Function: pthread_mutex_pool_init
 * Entry:    000544dc
 * Prototype: int __stdcall pthread_mutex_pool_init(void)
 */


/* exclude_from_export */

int pthread_mutex_pool_init(void)

{
  int iVar1;
  int iVar2;
  k_mutex *mutex;
  
  iVar2 = 0;
  mutex = (k_mutex *)&DAT_2000b2c8;
  do {
    iVar1 = z_impl_k_mutex_init(mutex);
    if (iVar1 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/mutex.c",328)
      ;
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar2 = iVar2 + 1;
    mutex = mutex + 1;
  } while (iVar2 != 5);
  return 0;
}



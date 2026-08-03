/*
 * Function: pthread_barrier_pool_init
 * Entry:    00054444
 * Prototype: int __stdcall pthread_barrier_pool_init(void)
 */


/* exclude_from_export */

int pthread_barrier_pool_init(void)

{
  int iVar1;
  k_mutex *mutex;
  int iVar2;
  
  iVar2 = 0;
  mutex = (k_mutex *)&DAT_2000b1ec;
  do {
    iVar1 = z_impl_k_mutex_init(mutex);
    if (iVar1 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",
              205);
LAB_00054460:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar1 = k_condvar_init((k_condvar *)(mutex + 1));
    if (iVar1 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",
              207);
      goto LAB_00054460;
    }
    iVar2 = iVar2 + 1;
    mutex = (k_mutex *)&mutex[1].owner_orig_prio;
    if (iVar2 == 5) {
      return 0;
    }
  } while( true );
}



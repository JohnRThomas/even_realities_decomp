/*
 * Function: pthread_cond_pool_init
 * Entry:    0005449c
 * Prototype: int __stdcall pthread_cond_pool_init(void)
 */


/* exclude_from_export */

int pthread_cond_pool_init(void)

{
  int iVar1;
  int iVar2;
  k_condvar *condvar;
  
  iVar2 = 0;
  condvar = (k_condvar *)&DAT_2000b2a0;
  do {
    iVar1 = k_condvar_init(condvar);
    if (iVar1 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/cond.c",200);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar2 = iVar2 + 1;
    condvar = condvar + 1;
  } while (iVar2 != 5);
  return 0;
}



/*
 * Function: abort
 * Entry:    0005442c
 * Prototype: void __stdcall abort(void)
 */


/* exclude_from_export */

void abort(void)

{
  bool bVar1;
  int iVar2;
  k_mutex *mutex;
  int iVar3;
  
  printk("abort()\n");
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
  iVar3 = 0;
  mutex = (k_mutex *)&DAT_2000b1ec;
  do {
    iVar2 = z_impl_k_mutex_init(mutex);
    if (iVar2 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",
              0xcd);
LAB_00054460:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar2 = k_condvar_init((k_condvar *)(mutex + 1));
    if (iVar2 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",
              0xcf);
      goto LAB_00054460;
    }
    iVar3 = iVar3 + 1;
    mutex = (k_mutex *)&mutex[1].owner_orig_prio;
    if (iVar3 == 5) {
      return;
    }
  } while( true );
}



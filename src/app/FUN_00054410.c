/*
 * Function: FUN_00054410
 * Entry:    00054410
 * Prototype: undefined __stdcall FUN_00054410(void)
 */


void FUN_00054410(void)

{
  bool bVar1;
  int iVar2;
  k_mutex *mutex;
  int iVar3;
  
  FUN_0004e37c(2,(int *)"* buffer overflow detected *\n",0x1d);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
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
    if (iVar2 == 0) goto LAB_00054466;
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",0xcd
           );
    while( true ) {
      k_panic();
LAB_00054466:
      iVar2 = k_condvar_init((k_condvar *)(mutex + 1));
      if (iVar2 == 0) break;
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/posix/barrier.c",
              0xcf);
    }
    iVar3 = iVar3 + 1;
    mutex = (k_mutex *)&mutex[1].owner_orig_prio;
  } while (iVar3 != 5);
  return;
}



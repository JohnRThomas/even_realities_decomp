/*
 * Function: z_impl_k_thread_priority_set
 * Entry:    000777fc
 * Prototype: void __stdcall z_impl_k_thread_priority_set(k_tid_t thread, int prio)
 */


/* exclude_from_export */

void z_impl_k_thread_priority_set(k_tid_t thread,int prio)

{
  bool bVar1;
  char *test;
  char *file;
  uint uVar2;
  int line;
  
  if (prio + 0x10U < 0x1f) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1f;
    }
    if (uVar2 == 0) {
      bVar1 = z_set_prio((k_thread *)thread,prio);
      if ((bVar1) && (*(char *)(_current.base + 0xf) == '\0')) {
        z_reschedule_unlocked();
        return;
      }
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/sched.c",
            1342);
    _ASSERT("\t\n",test,file,line);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "((((prio)) == 15 && z_is_idle_thread_entry((((void *)0)))) || (((15 - 1) >= ((-16))) && ((prio)) >= ((-16)) && ((prio)) <= (15 - 1)))"
            ,"WEST_TOPDIR/zephyr/kernel/sched.c",1341);
    _ASSERT("\tinvalid priority (%d); allowed range: %d to %d\n",(char *)prio,&DAT_0000000e,-0x10);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



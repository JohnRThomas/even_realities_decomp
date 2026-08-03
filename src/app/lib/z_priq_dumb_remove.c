/*
 * Function: z_priq_dumb_remove
 * Entry:    00076f84
 * Prototype: void __stdcall z_priq_dumb_remove(sys_dlist_t * pq, k_thread * thread)
 */


/* exclude_from_export */

void z_priq_dumb_remove(sys_dlist_t *pq,k_thread *thread)

{
  dword *pdVar1;
  dword dVar2;
  
  if (thread == (k_thread *)&DAT_20006900) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
            "WEST_TOPDIR/zephyr/kernel/sched.c",1156);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  dVar2 = thread->base;
  pdVar1 = (dword *)thread->callee_saved;
  *pdVar1 = dVar2;
  *(dword **)(dVar2 + 4) = pdVar1;
  thread->base = 0;
  thread->callee_saved = 0;
  return;
}



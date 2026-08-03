/*
 * Function: k_sem_give
 * Entry:    00075b28
 * Prototype: void __stdcall k_sem_give(k_sem * sem)
 */


/* exclude_from_export */

void k_sem_give(k_sem *sem)

{
  bool bVar1;
  k_thread *thread;
  char *file;
  int line;
  uint uVar2;
  k_spinlock_key_t key;
  
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.entry + 3));
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.entry + 3));
    thread = z_unpend_first_thread((_wait_q_t *)sem);
    if (thread == (k_thread *)0x0) {
      uVar2 = sem->count;
      if (sem->limit != uVar2) {
        uVar2 = uVar2 + 1;
      }
      sem->count = uVar2;
      z_handle_obj_poll_events((sys_dlist_t *)&sem->poll_events,2);
    }
    else {
      thread[1].userspace_local_data = (undefined *)0x0;
      z_ready_thread(thread);
    }
    z_reschedule((k_spinlock *)((int)&_current.entry + 3),key);
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.entry + 3),file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



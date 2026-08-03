/*
 * Function: k_thread_suspend
 * Entry:    0007744c
 * Prototype: void __stdcall k_thread_suspend(k_tid_t thread)
 */


/* exclude_from_export */

void k_thread_suspend(k_tid_t thread)

{
  uint uVar1;
  dword dVar2;
  bool bVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar4;
  
  z_abort_timeout((_timeout *)(thread + 0x18));
  uVar4 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar4 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar3 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar3) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    if ((char)thread[0xd] < '\0') {
      thread[0xd] = thread[0xd] & 0x7f;
      z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,(k_thread *)thread);
    }
    dVar2 = _current.base;
    thread[0xd] = thread[0xd] | 0x10;
    update_cache((uint)((k_tid_t)dVar2 == thread));
    bVar3 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar3) {
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      if ((k_tid_t)_current.base != thread) {
        return;
      }
      z_reschedule_unlocked();
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



/*
 * Function: z_unpend1_no_timeout
 * Entry:    000776b4
 * Prototype: k_thread * __stdcall z_unpend1_no_timeout(_wait_q_t * wait_q)
 */


/* exclude_from_export_ai */

k_thread * z_unpend1_no_timeout(_wait_q_t *wait_q)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  k_thread *thread;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    thread = (k_thread *)wait_q->head;
    if ((k_thread *)wait_q == thread) {
      thread = (k_thread *)0x0;
    }
    else if (thread != (k_thread *)0x0) {
      pended_on_thread(thread);
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return thread;
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



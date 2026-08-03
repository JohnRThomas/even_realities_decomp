/*
 * Function: k_thread_start
 * Entry:    00076d20
 * Prototype: void __stdcall k_thread_start(k_tid_t thread)
 */


/* exclude_from_export */

void k_thread_start(k_tid_t thread)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  k_spinlock_key_t key;
  
  key = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    key = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    if ((int)((uint)(byte)thread[0xd] << 0x1d) < 0) {
      thread[0xd] = thread[0xd] & 0xfb;
      ready_thread((k_thread *)thread);
      z_reschedule((k_spinlock *)((int)&_current.stack_obj + 2),key);
      return;
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(key);
      }
      InstructionSynchronizationBarrier(0xf);
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



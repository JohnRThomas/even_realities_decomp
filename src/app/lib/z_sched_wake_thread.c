/*
 * Function: z_sched_wake_thread
 * Entry:    000775f4
 * Prototype: void __stdcall z_sched_wake_thread(k_thread * thread, bool is_timeout)
 */


/* exclude_from_export_ai */

void z_sched_wake_thread(k_thread *thread,bool is_timeout)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  bool bVar4;
  char *file;
  char *file_00;
  byte bVar5;
  int line;
  int line_00;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar6 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar4 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar4) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    cVar1 = *(char *)((int)&thread[1].join_queue + 2);
    puVar3 = thread->join_queue;
    *(undefined1 *)((int)&thread[1].join_queue + 2) = 0;
    if (((cVar1 == '\0') || (!is_timeout)) && (((uint)puVar3 & 0x2800) == 0)) {
      if (thread->init_data != (undefined *)0x0) {
        pended_on_thread(thread);
      }
      bVar5 = *(byte *)((int)&thread->join_queue + 1);
      if (is_timeout) {
        bVar5 = bVar5 & 0xeb;
      }
      else {
        bVar5 = bVar5 & 0xfb;
      }
      *(byte *)((int)&thread->join_queue + 1) = bVar5;
      ready_thread(thread);
    }
    bVar4 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar4) {
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        setBasePriority(uVar6);
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



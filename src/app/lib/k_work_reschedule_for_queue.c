/*
 * Function: k_work_reschedule_for_queue
 * Entry:    000766cc
 * Prototype: int __stdcall k_work_reschedule_for_queue(k_work_q * queue, k_work_delayable * dwork, k_timeout_t delay)
 */


/* exclude_from_export */

int k_work_reschedule_for_queue(k_work_q *queue,k_work_delayable *dwork,k_timeout_t delay)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar4;
  k_work_q *local_1c;
  undefined4 uStack_18;
  
  uStack_18 = (undefined4)delay.ticks;
  local_1c = queue;
  if (dwork == (k_work_delayable *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dwork != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",990);
  }
  else {
    uVar4 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar4 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
      unschedule_locked(dwork);
      if (delay.ticks == 0) {
        iVar3 = submit_to_queue_locked(&dwork->work,&local_1c);
      }
      else {
        (dwork->work).flags = (dwork->work).flags | 8;
        dwork->queue = (undefined *)local_1c;
        z_add_timeout(&dwork->timeout,(_timeout_func_t)0x76055,delay);
        iVar3 = 1;
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return iVar3;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file_00,
              line_00);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file,line)
      ;
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



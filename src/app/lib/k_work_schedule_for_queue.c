/*
 * Function: k_work_schedule_for_queue
 * Entry:    000765d4
 * Prototype: int __stdcall k_work_schedule_for_queue(k_work_q * queue, k_work_delayable * dwork, k_timeout_t delay)
 */


/* exclude_from_export */

int k_work_schedule_for_queue(k_work_q *queue,k_work_delayable *dwork,k_timeout_t delay)

{
  bool bVar1;
  int iVar2;
  char *file;
  char *file_00;
  int line;
  uint uVar3;
  int line_00;
  undefined4 uVar4;
  k_work_q *local_1c;
  undefined4 uStack_18;
  
  uStack_18 = (undefined4)delay.ticks;
  local_1c = queue;
  if (dwork == (k_work_delayable *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dwork != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",954);
  }
  else {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (bVar1) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
      uVar3 = (dwork->work).flags;
      if ((uVar3 & 0xe) == 0) {
        if (delay.ticks == 0) {
          iVar2 = submit_to_queue_locked(&dwork->work,&local_1c);
        }
        else {
          (dwork->work).flags = uVar3 | 8;
          dwork->queue = (undefined *)local_1c;
          z_add_timeout(&dwork->timeout,(_timeout_func_t)0x76055,delay);
          iVar2 = 1;
        }
      }
      else {
        iVar2 = 0;
      }
      bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return iVar2;
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



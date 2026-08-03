/*
 * Function: k_work_cancel_delayable_sync
 * Entry:    00076874
 * Prototype: bool __stdcall k_work_cancel_delayable_sync(k_work_delayable * dwork, k_work_sync * sync)
 */


/* exclude_from_export */

bool k_work_cancel_delayable_sync(k_work_delayable *dwork,k_work_sync *sync)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 extraout_r1;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar5;
  k_timeout_t timeout;
  
  if (dwork == (k_work_delayable *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dwork != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",1041);
  }
  else if (sync == (k_work_sync *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","sync != ((void *)0)","WEST_TOPDIR/zephyr/kernel/work.c"
            ,0x412);
  }
  else {
    bVar2 = k_is_in_isr();
    if (bVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!k_is_in_isr()","WEST_TOPDIR/zephyr/kernel/work.c",
              0x413);
    }
    else {
      uVar5 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar5 = getBasePriority();
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar3 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
      if (bVar3) {
        z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
        bVar3 = ((dwork->work).flags & 0xf) != 0;
        if (bVar3) {
          unschedule_locked(dwork);
          cancel_async_locked(&dwork->work);
          bVar2 = cancel_sync_locked(&dwork->work,(z_work_canceller *)sync);
        }
        bVar4 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
        if (bVar4) {
          bVar4 = (bool)isCurrentModePrivileged();
          if (bVar4) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
          if (bVar2 != false) {
            timeout.ticks._4_4_ = 0xffffffff;
            timeout.ticks._0_4_ = extraout_r1;
            z_impl_k_sem_take((k_sem *)(sync + 2),timeout);
          }
          return bVar3;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
        _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file_00,
                line_00);
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
        _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file,
                line);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



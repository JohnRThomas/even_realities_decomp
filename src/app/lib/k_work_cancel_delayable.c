/*
 * Function: k_work_cancel_delayable
 * Entry:    000767c0
 * Prototype: int __stdcall k_work_cancel_delayable(k_work_delayable * dwork)
 */


/* exclude_from_export */

int k_work_cancel_delayable(k_work_delayable *dwork)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar4;
  
  if (dwork == (k_work_delayable *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dwork != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",1024);
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
      iVar3 = cancel_async_locked(&dwork->work);
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



/*
 * Function: z_impl_k_mutex_lock
 * Entry:    00075660
 * Prototype: int __stdcall z_impl_k_mutex_lock(k_mutex * mutex, k_timeout_t timeout)
 */


/* exclude_from_export */

int z_impl_k_mutex_lock(k_mutex *mutex,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  dword dVar1;
  bool bVar2;
  bool bVar3;
  k_mutex *pkVar4;
  int iVar5;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  int in_r3;
  int line;
  int line_00;
  int line_01;
  int iVar6;
  int extraout_r3;
  int iVar7;
  uint uVar8;
  k_spinlock_key_t kVar9;
  
  iVar5 = (int)((ulonglong)timeout.ticks >> 0x20);
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = getCurrentExceptionNumber();
    uVar8 = uVar8 & 0x1f;
  }
  if (uVar8 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/mutex.c",
            101);
    _ASSERT("\tmutexes cannot be used inside ISRs\n",test,file,line);
    goto LAB_00075686;
  }
  kVar9 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    kVar9 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)&_current.no_wake_on_timeout);
  if (!bVar2) {
LAB_000756a2:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)&_current.no_wake_on_timeout,file_00,line_00);
    goto LAB_00075686;
  }
  z_spin_lock_set_owner((k_spinlock *)&_current.no_wake_on_timeout);
  if (mutex->lock_count == 0) {
    iVar5 = (int)*(char *)(_current.base + 0xe);
LAB_000756f6:
    mutex->lock_count = mutex->lock_count + 1;
    dVar1 = _current.base;
    mutex->owner_orig_prio = iVar5;
    mutex->owner = (undefined *)dVar1;
    bVar2 = z_spin_unlock_valid((k_spinlock *)&_current.no_wake_on_timeout);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(kVar9);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
  }
  else {
    pkVar4 = (k_mutex *)mutex->owner;
    if (pkVar4 == (k_mutex *)_current.base) {
      iVar5 = mutex->owner_orig_prio;
      goto LAB_000756f6;
    }
    if (iVar5 == 0 && in_r3 == 0) {
      bVar2 = z_spin_unlock_valid((k_spinlock *)&_current.no_wake_on_timeout);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(kVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        return -0x10;
      }
    }
    else {
      iVar6 = (int)*(char *)((int)&pkVar4->lock_count + 2);
      iVar7 = (int)*(char *)(_current.base + 0xe);
      if (iVar6 <= *(char *)(_current.base + 0xe)) {
        iVar7 = iVar6;
      }
      if (iVar7 < -0x7f) {
        iVar7 = -0x7f;
      }
      bVar2 = false;
      if (iVar7 < iVar6) {
        bVar2 = adjust_owner_prio(pkVar4,iVar7);
        iVar6 = extraout_r3;
      }
      timeout_00.ticks._4_4_ = iVar5;
      timeout_00.ticks._0_4_ = iVar6;
      iVar5 = z_pend_curr((k_spinlock *)&_current.no_wake_on_timeout,kVar9,&mutex->wait_q,timeout_00
                         );
      if (iVar5 == 0) {
        return 0;
      }
      kVar9 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        kVar9 = getBasePriority();
      }
      bVar3 = (bool)isCurrentModePrivileged();
      if ((bVar3) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x20 < uVar8)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar3 = z_spin_lock_valid((k_spinlock *)&_current.no_wake_on_timeout);
      if (!bVar3) goto LAB_000756a2;
      z_spin_lock_set_owner((k_spinlock *)&_current.no_wake_on_timeout);
      if ((k_mutex *)mutex->owner != (k_mutex *)0x0) {
        pkVar4 = (k_mutex *)(mutex->wait_q).head;
        iVar5 = mutex->owner_orig_prio;
        if ((mutex != pkVar4) && (pkVar4 != (k_mutex *)0x0)) {
          iVar7 = (int)*(char *)((int)&pkVar4->lock_count + 2);
          if (iVar7 <= iVar5) {
            iVar5 = iVar7;
          }
          if (iVar5 < -0x7f) {
            iVar5 = -0x7f;
          }
        }
        bVar3 = adjust_owner_prio((k_mutex *)mutex->owner,iVar5);
        if (bVar3) goto LAB_000757ac;
      }
      if (bVar2 != false) {
LAB_000757ac:
        z_reschedule((k_spinlock *)&_current.no_wake_on_timeout,kVar9);
        return -0xb;
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)&_current.no_wake_on_timeout);
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(kVar9);
        }
        InstructionSynchronizationBarrier(0xf);
        return -0xb;
      }
    }
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
  _ASSERT("\tNot my spinlock %p\n",(char *)&_current.no_wake_on_timeout,file_01,line_01);
LAB_00075686:
                    /* WARNING: Subroutine does not return */
  k_panic();
}



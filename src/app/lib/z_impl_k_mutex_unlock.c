/*
 * Function: z_impl_k_mutex_unlock
 * Entry:    00075800
 * Prototype: int __stdcall z_impl_k_mutex_unlock(k_mutex * mutex)
 */


/* exclude_from_export */

int z_impl_k_mutex_unlock(k_mutex *mutex)

{
  bool bVar1;
  int iVar2;
  k_thread *thread;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  dword dVar3;
  int line_00;
  int line_01;
  k_spinlock_key_t key;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  if (uVar4 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/mutex.c",
            205);
    _ASSERT("\tmutexes cannot be used inside ISRs\n",test,file,line);
    goto LAB_00075820;
  }
  if (mutex->owner == (undefined *)0x0) {
    iVar2 = -0x16;
  }
  else if (mutex->owner == (undefined *)_current.base) {
    dVar3 = mutex->lock_count;
    if (dVar3 == 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","mutex->lock_count > 0U",
              "WEST_TOPDIR/zephyr/kernel/mutex.c",229);
LAB_00075820:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if (dVar3 == 1) {
      key = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        key = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar1 = z_spin_lock_valid((k_spinlock *)&_current.no_wake_on_timeout);
      if (!bVar1) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
        _ASSERT("\tInvalid spinlock %p\n",(char *)&_current.no_wake_on_timeout,file_00,line_00);
        goto LAB_00075820;
      }
      z_spin_lock_set_owner((k_spinlock *)&_current.no_wake_on_timeout);
      adjust_owner_prio((k_mutex *)mutex->owner,mutex->owner_orig_prio);
      thread = z_unpend_first_thread(&mutex->wait_q);
      mutex->owner = (undefined *)thread;
      if (thread == (k_thread *)0x0) {
        mutex->lock_count = 0;
        bVar1 = z_spin_unlock_valid((k_spinlock *)&_current.no_wake_on_timeout);
        if (!bVar1) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                  "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
          _ASSERT("\tNot my spinlock %p\n",(char *)&_current.no_wake_on_timeout,file_01,line_01);
          goto LAB_00075820;
        }
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
      }
      else {
        mutex->owner_orig_prio = (int)*(char *)((int)&thread->join_queue + 2);
        thread[1].userspace_local_data = (undefined *)0x0;
        z_ready_thread(thread);
        z_reschedule((k_spinlock *)&_current.no_wake_on_timeout,key);
      }
    }
    else {
      mutex->lock_count = dVar3 - 1;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



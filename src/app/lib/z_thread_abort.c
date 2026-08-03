/*
 * Function: z_thread_abort
 * Entry:    00053e38
 * Prototype: void __stdcall z_thread_abort(k_thread * thread)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_thread_abort(k_thread *thread)

{
  byte bVar1;
  bool bVar2;
  k_spinlock_key_t key;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  uint uVar3;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  k_thread *thread_00;
  k_spinlock *lock;
  
  if ((k_thread *)_current.base == thread) {
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = getCurrentExceptionNumber();
      uVar3 = uVar3 & 0x1f;
    }
    if (uVar3 != 0) {
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      _DAT_e000ed24 = _DAT_e000ed24 & 0xffff7fff;
    }
  }
  lock = (k_spinlock *)0x0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    lock = (k_spinlock *)getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    if ((int)((uint)*(byte *)&thread->join_queue << 0x1f) < 0) {
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(lock);
        }
        InstructionSynchronizationBarrier(0xf);
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/kernel/sched.c",1751);
        _ASSERT("\taborting essential thread %p\n",(char *)thread,file_01,line_01);
        goto LAB_00077b96;
      }
    }
    else {
      bVar1 = *(byte *)((int)&thread->join_queue + 1);
      if (-1 < (int)((uint)bVar1 << 0x1c)) {
        if ((char)bVar1 < '\0') {
          *(byte *)((int)&thread->join_queue + 1) = bVar1 & 0x5f | 8;
          z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,thread);
        }
        else {
          *(byte *)((int)&thread->join_queue + 1) = bVar1 & 0xdf | 8;
        }
        if (thread->init_data != (undefined *)0x0) {
          pended_on_thread(thread);
        }
        z_abort_timeout((_timeout *)&thread->events);
        while ((thread_00 = *(k_thread **)((int)&thread->paging_stats + 2),
               thread_00 != (k_thread *)((int)&thread->paging_stats + 2) &&
               (thread_00 != (k_thread *)0x0))) {
          pended_on_thread(thread_00);
          z_abort_timeout((_timeout *)&thread_00->events);
          thread_00[1].userspace_local_data = (undefined *)0x0;
          ready_thread(thread_00);
        }
        update_cache(1);
        arch_float_disable(thread);
        if ((k_thread *)_current.base == thread) {
          uVar3 = 0;
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            uVar3 = getCurrentExceptionNumber();
            uVar3 = uVar3 & 0x1f;
          }
          if (uVar3 == 0) {
            bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
            if (bVar2) {
              z_swap(lock,key);
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/kernel/sched.c",1805);
              _ASSERT("\taborted _current back from dead\n",test,file_03,line_03);
            }
            else {
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                      "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",273);
              _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_02,
                      line_02);
            }
            goto LAB_00077b96;
          }
        }
      }
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(lock);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
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
LAB_00077b96:
                    /* WARNING: Subroutine does not return */
  k_panic();
}



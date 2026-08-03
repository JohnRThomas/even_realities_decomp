/*
 * Function: z_set_prio
 * Entry:    00077308
 * Prototype: bool __stdcall z_set_prio(k_thread * thread, int prio)
 */


/* exclude_from_export */

bool z_set_prio(k_thread *thread,int prio)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar8 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar4 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar4) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    bVar1 = *(byte *)((int)&thread->join_queue + 1);
    cVar3 = (char)prio;
    if (((bVar1 & 0x1f) == 0) && (thread->events == 0)) {
      *(byte *)((int)&thread->join_queue + 1) = bVar1 & 0x7f;
      z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,thread);
      *(char *)((int)&thread->join_queue + 2) = cVar3;
      *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) | 0x80;
      if (thread == (k_thread *)&DAT_20006900) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
                "WEST_TOPDIR/zephyr/kernel/sched.c",193);
        goto LAB_00077388;
      }
      puVar7 = (undefined4 *)0x0;
      if ((undefined **)_current.next_event_link != &_current.next_event_link) {
        puVar7 = (undefined4 *)_current.next_event_link;
      }
      for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
        if ((cVar3 != *(char *)((int)puVar7 + 0xe)) && (cVar3 < *(char *)((int)puVar7 + 0xe))) {
          puVar6 = (undefined4 *)puVar7[1];
          thread->base = (dword)puVar7;
          thread->callee_saved = (dword)puVar6;
          *puVar6 = thread;
          puVar7[1] = thread;
          goto LAB_000773e0;
        }
        if ((undefined4 *)_current.events == puVar7) break;
      }
      thread->base = 0x2000be4c;
      thread->callee_saved = _current.events;
      *(k_thread **)_current.events = thread;
      _current.events = (dword)thread;
LAB_000773e0:
      update_cache(1);
      bVar4 = true;
    }
    else {
      bVar4 = false;
      *(char *)((int)&thread->join_queue + 2) = cVar3;
    }
    bVar5 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar5) {
      bVar5 = (bool)isCurrentModePrivileged();
      if (bVar5) {
        setBasePriority(uVar8);
      }
      InstructionSynchronizationBarrier(0xf);
      return bVar4;
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
LAB_00077388:
                    /* WARNING: Subroutine does not return */
  k_panic();
}



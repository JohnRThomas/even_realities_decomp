/*
 * Function: move_thread_to_end_of_prio_q
 * Entry:    00076fc4
 * Prototype: void __stdcall move_thread_to_end_of_prio_q(k_thread * thread)
 */


/* exclude_from_export */

void move_thread_to_end_of_prio_q(k_thread *thread)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)((int)&thread->join_queue + 1) < '\0') {
    *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) & 0x7f;
    z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,thread);
  }
  *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) | 0x80;
  if (thread == (k_thread *)&DAT_20006900) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
            "WEST_TOPDIR/zephyr/kernel/sched.c",193);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  puVar3 = (undefined4 *)_current.next_event_link;
  if ((undefined **)_current.next_event_link == &_current.next_event_link) {
    puVar3 = (undefined4 *)0x0;
  }
  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    cVar1 = *(char *)((int)&thread->join_queue + 2);
    if ((cVar1 != *(char *)((int)puVar3 + 0xe)) && (cVar1 < *(char *)((int)puVar3 + 0xe))) {
      puVar2 = (undefined4 *)puVar3[1];
      thread->base = (dword)puVar3;
      thread->callee_saved = (dword)puVar2;
      *puVar2 = thread;
      puVar3[1] = thread;
      goto LAB_00077038;
    }
    if ((undefined4 *)_current.events == puVar3) break;
  }
  thread->base = 0x2000be4c;
  thread->callee_saved = _current.events;
  *(k_thread **)_current.events = thread;
  _current.events = (dword)thread;
LAB_00077038:
  update_cache((uint)((k_thread *)_current.base == thread));
  return;
}



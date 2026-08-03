/*
 * Function: ready_thread
 * Entry:    00076ae8
 * Prototype: void __stdcall ready_thread(k_thread * thread)
 */


/* exclude_from_export */

void ready_thread(k_thread *thread)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  bVar1 = *(byte *)((int)&thread->join_queue + 1);
  if (((*(char *)((int)&thread->join_queue + 1) < '\0') || ((bVar1 & 0x1f) != 0)) ||
     (thread->events != 0)) {
    return;
  }
  *(byte *)((int)&thread->join_queue + 1) = bVar1 | 0x80;
  if (thread == (k_thread *)&DAT_20006900) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
            "WEST_TOPDIR/zephyr/kernel/sched.c",193);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  puVar4 = (undefined4 *)0x0;
  if ((undefined **)_current.next_event_link != &_current.next_event_link) {
    puVar4 = (undefined4 *)_current.next_event_link;
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    cVar2 = *(char *)((int)&thread->join_queue + 2);
    if ((cVar2 != *(char *)((int)puVar4 + 0xe)) && (cVar2 < *(char *)((int)puVar4 + 0xe))) {
      puVar3 = (undefined4 *)puVar4[1];
      thread->base = (dword)puVar4;
      thread->callee_saved = (dword)puVar3;
      *puVar3 = thread;
      puVar4[1] = thread;
      goto LAB_00076b54;
    }
    if (puVar4 == (undefined4 *)_current.events) break;
  }
  thread->base = 0x2000be4c;
  thread->callee_saved = _current.events;
  *(k_thread **)_current.events = thread;
  _current.events = (dword)thread;
LAB_00076b54:
  update_cache(0);
  return;
}



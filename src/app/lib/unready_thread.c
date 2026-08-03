/*
 * Function: unready_thread
 * Entry:    00077130
 * Prototype: void __stdcall unready_thread(k_thread * thread)
 */


/* exclude_from_export */

void unready_thread(k_thread *thread)

{
  if (*(char *)((int)&thread->join_queue + 1) < '\0') {
    *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) & 0x7f;
    z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,thread);
  }
  update_cache((uint)((k_thread *)_current.base == thread));
  return;
}



/*
 * Function: update_cache
 * Entry:    00076a80
 * Prototype: void __stdcall update_cache(int preempt_ok)
 */


/* exclude_from_export */

void update_cache(int preempt_ok)

{
  char *test;
  char *file;
  int line;
  k_thread *curr;
  
  if (((undefined **)_current.next_event_link == &_current.next_event_link) ||
     (curr = (k_thread *)_current.next_event_link, _current.next_event_link == (undefined *)0x0)) {
    curr = (k_thread *)_current.callee_saved;
  }
  if (preempt_ok == 0) {
    if (_current.base == 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","_kernel.cpus[0].current != ((void *)0)",
              "WEST_TOPDIR/zephyr/kernel/sched.c",143);
      _ASSERT("\t\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((((*(byte *)(_current.base + 0xd) & 0x1f) == 0) && (curr->events == 0)) &&
       (0x7f < *(ushort *)(_current.base + 0xe))) {
      _current.poller = _current.base;
      return;
    }
  }
  if (curr != (k_thread *)_current.base) {
    z_reset_time_slice(curr);
  }
  _current.poller = (dword)curr;
  return;
}



/*
 * Function: pend_locked
 * Entry:    000771e4
 * Prototype: void __stdcall pend_locked(k_thread * thread, _wait_q_t * wait_q, k_timeout_t timeout)
 */


/* exclude_from_export */

void pend_locked(k_thread *thread,_wait_q_t *wait_q,k_timeout_t timeout)

{
  add_to_waitq_locked(thread,wait_q);
  if (timeout.ticks != -1) {
    z_add_timeout((_timeout *)&thread->events,(_timeout_func_t)0x89e11,timeout);
    return;
  }
  return;
}



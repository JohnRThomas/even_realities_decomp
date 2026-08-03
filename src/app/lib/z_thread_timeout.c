/*
 * Function: z_thread_timeout
 * Entry:    00089e10
 * Prototype: void __stdcall z_thread_timeout(_timeout * timeout)
 */


/* exclude_from_export */

void z_thread_timeout(_timeout *timeout)

{
  z_sched_wake_thread((k_thread *)(timeout + -1),true);
  return;
}



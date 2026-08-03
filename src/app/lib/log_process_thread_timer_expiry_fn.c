/*
 * Function: log_process_thread_timer_expiry_fn
 * Entry:    000506b4
 * Prototype: void __stdcall log_process_thread_timer_expiry_fn(k_timer * timer)
 */


/* exclude_from_export_ai */

void log_process_thread_timer_expiry_fn(k_timer *timer)

{
  k_sem_give((k_sem *)&DAT_20003b98);
  return;
}



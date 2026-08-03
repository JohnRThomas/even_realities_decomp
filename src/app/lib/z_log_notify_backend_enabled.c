/*
 * Function: z_log_notify_backend_enabled
 * Entry:    000506ec
 * Prototype: void __stdcall z_log_notify_backend_enabled(void)
 */


/* exclude_from_export */

void z_log_notify_backend_enabled(void)

{
  if (DAT_2001e1bf == '\0') {
    k_sem_give((k_sem *)&DAT_20003b98);
  }
  DAT_2001e1bf = 1;
  return;
}



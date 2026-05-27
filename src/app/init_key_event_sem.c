/*
 * Function: ?_init_key_event_sem
 * Entry:    0002b978
 * Prototype: undefined __stdcall ?_init_key_event_sem(void)
 */


void __init_key_event_sem(void)

{
  int iVar1;
  
  iVar1 = z_impl_k_sem_init(&__key_event_sem,0,5);
  if (iVar1 == 0) {
    IS_SILENT_MODE = 1;
  }
  return;
}



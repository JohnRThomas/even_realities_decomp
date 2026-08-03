/*
 * Function: backend_init
 * Entry:    000822f4
 * Prototype: void __stdcall backend_init(log_backend * backend)
 */


/* exclude_from_export */

void backend_init(log_backend *backend)

{
  int iVar1;
  
  iVar1 = *(int *)((int)&backend[1].api + 3);
  *(undefined4 *)(iVar1 + 0x3b8) = *(undefined4 *)backend->cb;
  z_impl_k_mutex_init((k_mutex *)(iVar1 + 0x1b0));
  atomic_set((atomic_t *)(iVar1 + 0x3bc),0);
  return;
}



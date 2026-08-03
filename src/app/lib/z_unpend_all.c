/*
 * Function: z_unpend_all
 * Entry:    00089e18
 * Prototype: int __stdcall z_unpend_all(_wait_q_t * wait_q)
 */


/* exclude_from_export */

int z_unpend_all(_wait_q_t *wait_q)

{
  int iVar1;
  uint32_t in_r1;
  uint32_t extraout_r1;
  k_thread *thread;
  
  iVar1 = 0;
  while ((thread = (k_thread *)wait_q->head, (k_thread *)wait_q != thread &&
         (thread != (k_thread *)0x0))) {
    z_unpend_thread((k_poll_event *)thread,in_r1);
    z_ready_thread(thread);
    iVar1 = 1;
    in_r1 = extraout_r1;
  }
  return iVar1;
}



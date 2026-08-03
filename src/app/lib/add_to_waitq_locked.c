/*
 * Function: add_to_waitq_locked
 * Entry:    00077168
 * Prototype: void __stdcall add_to_waitq_locked(k_thread * thread, _wait_q_t * wait_q)
 */


/* exclude_from_export */

void add_to_waitq_locked(k_thread *thread,_wait_q_t *wait_q)

{
  char cVar1;
  char cVar2;
  _wait_q_t *p_Var3;
  undefined4 *puVar4;
  
  unready_thread(thread);
  *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) | 2;
  if (wait_q != (_wait_q_t *)0x0) {
    thread->init_data = (undefined *)wait_q;
    if (thread == (k_thread *)&DAT_20006900) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
              "WEST_TOPDIR/zephyr/kernel/sched.c",0xc1);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    p_Var3 = (_wait_q_t *)wait_q->head;
    if (wait_q != p_Var3) {
      for (; p_Var3 != (_wait_q_t *)0x0; p_Var3 = (_wait_q_t *)p_Var3->head) {
        cVar1 = *(char *)((int)&thread->join_queue + 2);
        cVar2 = *(char *)((int)&p_Var3[1].tail + 2);
        if ((cVar1 != cVar2) && (cVar1 < cVar2)) {
          puVar4 = (undefined4 *)p_Var3->tail;
          thread->base = (dword)p_Var3;
          thread->callee_saved = (dword)puVar4;
          *puVar4 = thread;
          p_Var3->tail = (undefined *)thread;
          return;
        }
        if (p_Var3 == (_wait_q_t *)wait_q->tail) break;
      }
    }
    puVar4 = (undefined4 *)wait_q->tail;
    thread->base = (dword)wait_q;
    thread->callee_saved = (dword)puVar4;
    *puVar4 = thread;
    wait_q->tail = (undefined *)thread;
  }
  return;
}



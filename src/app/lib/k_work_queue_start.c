/*
 * Function: k_work_queue_start
 * Entry:    00076390
 * Prototype: void __stdcall k_work_queue_start(k_work_q * queue, k_thread_stack_t * stack, size_t stack_size, int prio, k_work_queue_config * cfg)
 */


/* exclude_from_export */

void k_work_queue_start(k_work_q *queue,k_thread_stack_t *stack,size_t stack_size,int prio,
                       k_work_queue_config *cfg)

{
  k_timeout_t delay;
  dword dVar1;
  undefined4 in_stack_ffffffdc;
  
  if (queue == (k_work_q *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","queue","WEST_TOPDIR/zephyr/kernel/work.c",712);
  }
  else if (stack == (k_thread_stack_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","stack","WEST_TOPDIR/zephyr/kernel/work.c",0x2c9);
  }
  else {
    if ((queue[0xc].thread & 1) == 0) {
      queue[10].flags = 0;
      queue[0xb].thread = 0;
      queue[0xb].pending = &queue[0xb].pending;
      queue[0xb].notifyq = &queue[0xb].pending;
      queue[0xb].drainq = &queue[0xb].drainq;
      queue[0xb].flags = (dword)&queue[0xb].drainq;
      if (cfg == (k_work_queue_config *)0x0) {
        dVar1 = 1;
      }
      else {
        dVar1 = 0x101;
        if ((char)cfg[1] == '\0') {
          dVar1 = 1;
        }
      }
      queue[0xc].thread = dVar1;
      delay.ticks._4_4_ = 0xffffffff;
      delay.ticks._0_4_ = in_stack_ffffffdc;
      z_impl_k_thread_create
                ((k_thread *)queue,stack,stack_size,(k_thread_entry_t *)0x75d59,queue,(void *)0x0,
                 (void *)0x0,prio,0,delay);
      if ((cfg != (k_work_queue_config *)0x0) && ((char *)*cfg != (char *)0x0)) {
        k_thread_name_set((k_tid_t)queue,(char *)*cfg);
      }
      k_thread_start((k_tid_t)queue);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!flag_test(&queue->flags, K_WORK_QUEUE_STARTED_BIT)",
            "WEST_TOPDIR/zephyr/kernel/work.c",0x2ca);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



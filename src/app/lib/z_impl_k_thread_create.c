/*
 * Function: z_impl_k_thread_create
 * Entry:    00075154
 * Prototype: k_tid_t __stdcall z_impl_k_thread_create(k_thread * new_thread, k_thread_stack_t * stack, size_t stack_size, k_thread_entry_t * entry, void * p1, void * p2, void * p3, int prio, uint32_t options, k_timeout_t delay)
 */


/* exclude_from_export */

k_tid_t z_impl_k_thread_create
                  (k_thread *new_thread,k_thread_stack_t *stack,size_t stack_size,
                  k_thread_entry_t *entry,void *p1,void *p2,void *p3,int prio,uint32_t options,
                  k_timeout_t delay)

{
  bool bVar1;
  k_timeout_t timeout;
  char *test;
  char *file;
  int line;
  uint uVar2;
  int in_stack_0000001c;
  
  timeout.ticks._4_4_ = in_stack_0000001c;
  timeout.ticks._0_4_ = delay.ticks._4_4_;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  if (uVar2 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/thread.c"
            ,652);
    _ASSERT("\tThreads may not be created in ISRs\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  z_setup_new_thread(new_thread,stack,stack_size,entry,p1,p2,p3,prio,options,(char *)0x0);
  if (in_stack_0000001c != -1 || delay.ticks._4_4_ != -1) {
    if (in_stack_0000001c == 0 && delay.ticks._4_4_ == 0) {
      k_thread_start((k_tid_t)new_thread);
    }
    else {
      z_add_timeout((_timeout *)&new_thread->events,(_timeout_func_t)0x89e11,timeout);
    }
  }
  return (k_tid_t)new_thread;
}



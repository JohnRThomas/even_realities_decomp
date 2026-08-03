/*
 * Function: k_thread_create
 * Entry:    0007fece
 * Prototype: k_tid_t __stdcall k_thread_create(k_thread * new_thread, k_thread_stack_t * stack, size_t stack_size, k_thread_entry_t * entry, void * p1, void * p2, void * p3, int prio, uint32_t options, k_timeout_t delay)
 */


/* exclude_from_export_ai */

k_tid_t k_thread_create(k_thread *new_thread,k_thread_stack_t *stack,size_t stack_size,
                       k_thread_entry_t *entry,void *p1,void *p2,void *p3,int prio,uint32_t options,
                       k_timeout_t delay)

{
  k_timeout_t delay_00;
  k_tid_t puVar1;
  undefined4 in_stack_ffffffe4;
  
  delay_00.ticks._4_4_ = p3;
  delay_00.ticks._0_4_ = in_stack_ffffffe4;
  puVar1 = z_impl_k_thread_create
                     (new_thread,stack,stack_size,entry,p1,(void *)0x0,(void *)0x0,(int)p2,0,
                      delay_00);
  return puVar1;
}



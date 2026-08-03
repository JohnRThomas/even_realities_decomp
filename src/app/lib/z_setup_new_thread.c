/*
 * Function: z_setup_new_thread
 * Entry:    000750a0
 * Prototype: char * __stdcall z_setup_new_thread(k_thread * new_thread, k_thread_stack_t * stack, size_t stack_size, k_thread_entry_t * entry, void * p1, void * p2, void * p3, int prio, uint32_t options, char * name)
 */


/* exclude_from_export */

char * z_setup_new_thread(k_thread *new_thread,k_thread_stack_t *stack,size_t stack_size,
                         k_thread_entry_t *entry,void *p1,void *p2,void *p3,int prio,
                         uint32_t options,char *name)

{
  dword dVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  char *stack_ptr;
  
  if (prio == 0xf) {
    if (entry != (k_thread_entry_t *)0x75331) {
LAB_00075114:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "((((prio)) == 15 && z_is_idle_thread_entry((entry))) || (((15 - 1) >= ((-16))) && ((prio)) >= ((-16)) && ((prio)) <= (15 - 1)))"
              ,"WEST_TOPDIR/zephyr/kernel/thread.c",538);
      _ASSERT("\tinvalid priority (%d); allowed range: %d to %d\n",(char *)prio,&DAT_0000000e,-0x10)
      ;
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  else if (0x1e < prio + 0x10U) goto LAB_00075114;
  puVar2 = (undefined1 *)((int)&new_thread->paging_stats + 2);
  *(undefined1 **)((int)&new_thread->paging_stats + 2) = puVar2;
  *(undefined1 **)((int)&new_thread->pipe_desc + 2) = puVar2;
  *(char *)&new_thread->join_queue = (char)options;
  uVar3 = stack_size + 7 & 0xfffffff8;
  *(k_thread_stack_t **)((int)&new_thread[1].events + 2) = stack;
  *(uint *)((int)&new_thread[1].event_options + 2) = uVar3;
  *(char *)((int)&new_thread->join_queue + 2) = (char)prio;
  stack_ptr = (char *)((int)stack + uVar3);
  *(undefined1 *)((int)&new_thread->join_queue + 1) = 4;
  new_thread->events = 0;
  new_thread->event_options = 0;
  new_thread->init_data = (undefined *)0x0;
  *(undefined1 *)((int)&new_thread->join_queue + 3) = 0;
  *(undefined4 *)((int)&new_thread[1].entry + 1) = 0;
  arch_new_thread(new_thread,stack,stack_ptr,entry,p1,p2,p3);
  *(undefined4 *)((int)&new_thread->tls + 2) = 0;
  dVar1 = _current.base;
  *(undefined4 *)((int)&new_thread[1].poller + 2) = 0;
  *(undefined1 *)((int)&new_thread[1].join_queue + 2) = 0;
  uVar4 = 0;
  if (dVar1 != 0) {
    uVar4 = *(undefined4 *)(dVar1 + 0x88);
  }
  *(undefined4 *)((int)&new_thread[1].next_thread + 1) = uVar4;
  return stack_ptr;
}



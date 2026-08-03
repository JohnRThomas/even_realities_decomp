/*
 * Function: arch_new_thread
 * Entry:    00053570
 * Prototype: void __stdcall arch_new_thread(k_thread * thread, k_thread_stack_t * stack, char * stack_ptr, k_thread_entry_t * entry, void * p1, void * p2, void * p3)
 */


/* exclude_from_export_ai */

void arch_new_thread(k_thread *thread,k_thread_stack_t *stack,char *stack_ptr,
                    k_thread_entry_t *entry,void *p1,void *p2,void *p3)

{
  *(k_thread_entry_t **)(stack_ptr + -0x20) = entry;
  *(void **)(stack_ptr + -0x1c) = p1;
  *(void **)(stack_ptr + -0x18) = p2;
  *(code **)(stack_ptr + -8) = z_thread_entry;
  *(void **)(stack_ptr + -0x14) = p3;
  stack_ptr[-0xffffffff00000004] = '\0';
  stack_ptr[-0xffffffff00000003] = '\0';
  stack_ptr[-0xffffffff00000002] = '\0';
  stack_ptr[-0xffffffff00000001] = '\x01';
  thread[1].custom_data = (undefined *)0x0;
  *(char **)((int)&thread->resource_pool + 2) = stack_ptr + -0x20;
  thread[2].poller = (dword)&PTR_s_spec_ble_command_hook_0000fd00;
  return;
}



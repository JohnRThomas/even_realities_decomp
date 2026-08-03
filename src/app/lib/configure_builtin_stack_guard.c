/*
 * Function: configure_builtin_stack_guard
 * Entry:    00083f30
 * Prototype: void __stdcall configure_builtin_stack_guard(k_thread * thread)
 */


/* exclude_from_export_ai */

void configure_builtin_stack_guard(k_thread *thread)

{
  setProcStackPointerLimit(*(undefined4 *)((int)&thread[1].events + 2));
  return;
}



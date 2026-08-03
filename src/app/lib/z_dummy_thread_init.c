/*
 * Function: z_dummy_thread_init
 * Entry:    00078be0
 * Prototype: void __stdcall z_dummy_thread_init(k_thread * dummy_thread)
 */


/* exclude_from_export */

void z_dummy_thread_init(k_thread *dummy_thread)

{
  *(undefined **)((int)&dummy_thread[1].next_thread + 1) = &DAT_20003978;
  return;
}



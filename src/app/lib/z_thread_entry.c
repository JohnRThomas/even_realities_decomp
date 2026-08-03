/*
 * Function: z_thread_entry
 * Entry:    00081570
 * Prototype: void __stdcall z_thread_entry(k_thread_entry_t * entry, void * p1, void * p2, void * p3)
 */


/* exclude_from_export */

void z_thread_entry(k_thread_entry_t *entry,void *p1,void *p2,void *p3)

{
  k_thread *thread;
  
  (*entry)(p1,p2,p3);
  thread = (k_thread *)k_current_get();
                    /* WARNING: Subroutine does not return */
  z_thread_abort(thread);
}



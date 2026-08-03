/*
 * Function: z_impl_k_sem_init
 * Entry:    00089ce4
 * Prototype: int __stdcall z_impl_k_sem_init(k_sem * sem, uint initial_count, uint limit)
 */


/* exclude_from_export */

int z_impl_k_sem_init(k_sem *sem,uint initial_count,uint limit)

{
  if ((limit != 0) && (initial_count <= limit)) {
    sem->count = initial_count;
    sem->limit = limit;
    (sem->wait_q).next = sem;
    (sem->wait_q).prev = sem;
    (sem->poll_events).next = &sem->poll_events;
    (sem->poll_events).prev = &sem->poll_events;
    return 0;
  }
  return -0x16;
}



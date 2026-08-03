/*
 * Function: z_impl_k_mutex_init
 * Entry:    00089c72
 * Prototype: int __stdcall z_impl_k_mutex_init(k_mutex * mutex)
 */


/* exclude_from_export */

int z_impl_k_mutex_init(k_mutex *mutex)

{
  (mutex->wait_q).head = (undefined *)mutex;
  (mutex->wait_q).tail = (undefined *)mutex;
  mutex->owner = (undefined *)0x0;
  mutex->lock_count = 0;
  return 0;
}



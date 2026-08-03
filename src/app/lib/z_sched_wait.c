/*
 * Function: z_sched_wait
 * Entry:    00077db8
 * Prototype: int __stdcall z_sched_wait(k_spinlock * lock, k_spinlock_key_t key, _wait_q_t * wait_q, k_timeout_t timeout, void * * data)
 */


/* exclude_from_export */

int z_sched_wait(k_spinlock *lock,k_spinlock_key_t key,_wait_q_t *wait_q,k_timeout_t timeout,
                void **data)

{
  k_timeout_t timeout_00;
  int iVar1;
  undefined4 *in_stack_00000008;
  
  timeout_00.ticks._4_4_ = (int)((ulonglong)timeout.ticks >> 0x20);
  timeout_00.ticks._0_4_ = (undefined4)timeout.ticks;
  iVar1 = z_pend_curr(lock,key,wait_q,timeout_00);
  if (in_stack_00000008 != (undefined4 *)0x0) {
    *in_stack_00000008 = *(undefined4 *)(_current.base + 0x14);
  }
  return iVar1;
}



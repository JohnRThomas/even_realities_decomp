/*
 * Function: notify_queue_locked
 * Entry:    00089d38
 * Prototype: bool __stdcall notify_queue_locked(k_work_q * queue)
 */


/* exclude_from_export */

bool notify_queue_locked(k_work_q *queue)

{
  int iVar1;
  uint8_t *in_r3;
  uint in_stack_00000000;
  
  if (queue != (k_work_q *)0x0) {
    iVar1 = tc_hmac_prng_reseed((TCHmacPrng_t)&queue[0xb].pending,(uint8_t *)0x0,0,in_r3,
                                in_stack_00000000);
    return SUB41(iVar1,0);
  }
  return false;
}



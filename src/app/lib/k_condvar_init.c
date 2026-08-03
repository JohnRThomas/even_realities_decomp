/*
 * Function: k_condvar_init
 * Entry:    00089e38
 * Prototype: int __stdcall k_condvar_init(k_condvar * condvar)
 */


/* exclude_from_export */

int k_condvar_init(k_condvar *condvar)

{
  (condvar->wait_q).head = (undefined *)condvar;
  (condvar->wait_q).tail = (undefined *)condvar;
  return 0;
}



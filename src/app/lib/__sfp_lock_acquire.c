/*
 * Function: __sfp_lock_acquire
 * Entry:    00079e44
 * Prototype: undefined __stdcall __sfp_lock_acquire(void)
 */


/* exclude_from_export */

void __sfp_lock_acquire(void)

{
  __retarget_lock_acquire_recursive((_LOCK_T)&__sfp_recursive_mutex);
  return;
}



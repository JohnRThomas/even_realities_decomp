/*
 * Function: __sfp_lock_release
 * Entry:    00079e50
 * Prototype: undefined __stdcall __sfp_lock_release(void)
 */


/* exclude_from_export */

void __sfp_lock_release(void)

{
  __retarget_lock_release_recursive((_LOCK_T)&__sfp_recursive_mutex);
  return;
}



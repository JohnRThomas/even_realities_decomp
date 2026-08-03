/*
 * Function: __sinit_lock_release
 * Entry:    00079e68
 * Prototype: undefined __stdcall __sinit_lock_release(void)
 */


/* exclude_from_export */

void __sinit_lock_release(void)

{
  __retarget_lock_release_recursive((_LOCK_T)&__sinit_recursive_mutex);
  return;
}



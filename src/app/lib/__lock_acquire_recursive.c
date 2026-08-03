/*
 * Function: __lock_acquire_recursive
 * Entry:    0007b864
 * Prototype: undefined __stdcall __lock_acquire_recursive(void)
 */


/* exclude_from_export */

void __lock_acquire_recursive(void)

{
  __retarget_lock_acquire_recursive(0x20003990);
  return;
}



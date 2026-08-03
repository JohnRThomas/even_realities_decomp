/*
 * Function: __lock_release_recursive
 * Entry:    0007b870
 * Prototype: undefined __stdcall __lock_release_recursive(void)
 */


/* exclude_from_export */

void __lock_release_recursive(void)

{
  __retarget_lock_release_recursive(0x20003990);
  return;
}



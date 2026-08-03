/*
 * Function: __errno
 * Entry:    00074920
 * Prototype: int * __stdcall __errno(void)
 */


/* exclude_from_export */

int * __errno(void)

{
  return (int *)(_current.base + 0x78);
}



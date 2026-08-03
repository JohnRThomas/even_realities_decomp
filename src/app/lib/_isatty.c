/*
 * Function: _isatty
 * Entry:    00083f96
 * Prototype: int __stdcall _isatty(int __fd)
 */


/* exclude_from_export */

int _isatty(int __fd)

{
  return (uint)(__fd < 3);
}



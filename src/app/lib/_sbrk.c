/*
 * Function: _sbrk
 * Entry:    00054320
 * Prototype: void * __stdcall _sbrk(intptr_t __delta)
 */


/* exclude_from_export_ai */

void * _sbrk(intptr_t __delta)

{
  undefined *puVar1;
  
  if (__delta + DAT_2000b1e8 < 0x1800c) {
    puVar1 = &DAT_20057ff4 + DAT_2000b1e8;
    DAT_2000b1e8 = __delta + DAT_2000b1e8;
  }
  else {
    puVar1 = (undefined *)0xffffffff;
  }
  return puVar1;
}



/*
 * Function: __isfinite
 * Entry:    0008a18c
 * Prototype: uint __stdcall __isfinite(void)
 */


/* exclude_from_export_ai */

uint __isfinite(void)

{
  undefined8 in_d0;
  undefined4 uStack_4;
  
  uStack_4 = (uint)((ulonglong)in_d0 >> 0x20);
  return (uStack_4 | 0x80000000) + 0x100000 >> 0x1f;
}



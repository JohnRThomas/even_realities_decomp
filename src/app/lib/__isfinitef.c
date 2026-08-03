/*
 * Function: __isfinitef
 * Entry:    0008a1a2
 * Prototype: bool __stdcall __isfinitef(uint param_1)
 */


/* exclude_from_export_ai */

bool __isfinitef(uint param_1)

{
  return (param_1 & 0x7fffffff) < 0x7f800000;
}



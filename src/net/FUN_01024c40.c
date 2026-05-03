/*
 * Function: FUN_01024c40
 * Entry:    01024c40
 * Prototype: int __stdcall FUN_01024c40(uint param_1)
 */


int FUN_01024c40(uint param_1)

{
  return (param_1 >> 9) * 0x3d09 + ((param_1 & 0x1ff) * 0x3d09 + 0x100 >> 9);
}



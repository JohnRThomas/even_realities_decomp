/*
 * Function: FUN_01034c68
 * Entry:    01034c68
 * Prototype: uint __stdcall FUN_01034c68(uint param_1)
 */


uint FUN_01034c68(uint param_1)

{
  return (param_1 & 0x1f) + (uint)(byte)""[param_1 >> 5] & 0xff;
}



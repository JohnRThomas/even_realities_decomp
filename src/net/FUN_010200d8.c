/*
 * Function: FUN_010200d8
 * Entry:    010200d8
 * Prototype: uint __stdcall FUN_010200d8(void)
 */


uint FUN_010200d8(void)

{
  return ((uint)(DAT_21000020 << 0x17) >> 0x1f) << 1 | ((uint)(DAT_21000020 << 0x14) >> 0x1f) << 2 |
         1;
}



/*
 * Function: _double_byte
 * Entry:    00083680
 * Prototype: uint8_t __stdcall _double_byte(uint8_t a)
 */


/* exclude_from_export */

uint8_t _double_byte(uint8_t a)

{
  return ((char)a >> 7) * -0x1b ^ a << 1;
}



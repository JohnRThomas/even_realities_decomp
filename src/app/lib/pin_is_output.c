/*
 * Function: pin_is_output
 * Entry:    0006873c
 * Prototype: bool __stdcall pin_is_output(uint32_t pin)
 */


/* exclude_from_export */

bool pin_is_output(uint32_t pin)

{
  byte bVar1;
  
  bVar1 = get_pin_idx(pin);
  return SUB41(((uint)*(ushort *)((int)&DAT_20002be0 + (bVar1 + 8) * 2) << 0x1e) >> 0x1f,0);
}



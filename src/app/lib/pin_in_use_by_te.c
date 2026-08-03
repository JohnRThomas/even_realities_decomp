/*
 * Function: pin_in_use_by_te
 * Entry:    00068708
 * Prototype: bool __stdcall pin_in_use_by_te(uint32_t pin)
 */


/* exclude_from_export */

bool pin_in_use_by_te(uint32_t pin)

{
  byte bVar1;
  
  bVar1 = get_pin_idx(pin);
  return SUB41(((uint)*(ushort *)((int)&DAT_20002be0 + (bVar1 + 8) * 2) << 0x1a) >> 0x1f,0);
}



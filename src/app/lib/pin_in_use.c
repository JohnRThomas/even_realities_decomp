/*
 * Function: pin_in_use
 * Entry:    000686f0
 * Prototype: bool __stdcall pin_in_use(uint32_t pin)
 */


/* exclude_from_export */

bool pin_in_use(uint32_t pin)

{
  byte bVar1;
  
  bVar1 = get_pin_idx(pin);
  return (bool)((byte)*(undefined2 *)((int)&DAT_20002be0 + (bVar1 + 8) * 2) & 1);
}



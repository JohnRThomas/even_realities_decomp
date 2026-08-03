/*
 * Function: pin_has_trigger
 * Entry:    00068720
 * Prototype: bool __stdcall pin_has_trigger(uint32_t pin)
 */


/* exclude_from_export */

bool pin_has_trigger(uint32_t pin)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = get_pin_idx(pin);
  uVar1 = *(ushort *)((int)&DAT_20002be0 + (bVar2 + 8) * 2);
  bVar2 = (byte)uVar1 & 0x1c;
  if ((uVar1 & 0x1c) != 0) {
    bVar2 = 1;
  }
  return (bool)bVar2;
}



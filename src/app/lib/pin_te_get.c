/*
 * Function: pin_te_get
 * Entry:    00068754
 * Prototype: uint8_t __stdcall pin_te_get(nrfx_gpiote_pin_t pin)
 */


/* exclude_from_export */

uint8_t pin_te_get(nrfx_gpiote_pin_t pin)

{
  byte bVar1;
  
  bVar1 = get_pin_idx(pin);
  return (uint8_t)((ushort)*(undefined2 *)((int)&DAT_20002be0 + (bVar1 + 8) * 2) >> 0xd);
}



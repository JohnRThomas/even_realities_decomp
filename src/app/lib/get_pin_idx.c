/*
 * Function: get_pin_idx
 * Entry:    000686dc
 * Prototype: uint8_t __stdcall get_pin_idx(nrfx_gpiote_pin_t pin)
 */


/* exclude_from_export */

uint8_t get_pin_idx(nrfx_gpiote_pin_t pin)

{
  return ((byte)pin & 0x1f) + (&DAT_000f4be1)[pin >> 5];
}



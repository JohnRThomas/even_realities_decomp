/*
 * Function: nrf_gpio_pin_present_check
 * Entry:    000888a6
 * Prototype: bool __stdcall nrf_gpio_pin_present_check(uint32_t pin_number)
 */


/* exclude_from_export */

bool nrf_gpio_pin_present_check(uint32_t pin_number)

{
  uint uVar1;
  
  if (pin_number >> 5 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (pin_number >> 5 != 1) {
      return false;
    }
    uVar1 = 0xffff;
  }
  return (bool)((byte)(uVar1 >> (pin_number & 0x1f)) & 1);
}



/*
 * Function: spim_pin_uninit
 * Entry:    0006a3e0
 * Prototype: void __stdcall spim_pin_uninit(uint32_t pin)
 */


/* exclude_from_export */

void spim_pin_uninit(uint32_t pin)

{
  NRF_GPIO_Type *pNVar1;
  uint32_t local_c [2];
  
  if (pin != 0xffffffff) {
    local_c[0] = pin;
    pNVar1 = nrf_gpio_pin_port_decode(local_c);
    pNVar1[local_c[0] + 0x80] = pNVar1[local_c[0] + 0x80] & 0xfffcf0f0 | 2;
  }
  return;
}



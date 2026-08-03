/*
 * Function: nrfy_gpio_pin_clear
 * Entry:    00088aae
 * Prototype: void __stdcall nrfy_gpio_pin_clear(uint32_t pin_number)
 */


/* exclude_from_export */

void nrfy_gpio_pin_clear(uint32_t pin_number)

{
  NRF_GPIO_Type *pNVar1;
  uint local_c [2];
  
  local_c[0] = pin_number;
  pNVar1 = nrf_gpio_pin_port_decode(local_c);
  pNVar1[3] = 1 << (local_c[0] & 0xff);
  return;
}



/*
 * Function: nrfx_twim_bus_recover
 * Entry:    0006b28c
 * Prototype: nrfx_err_t __stdcall nrfx_twim_bus_recover(uint32_t scl_pin, uint32_t sda_pin)
 */


/* exclude_from_export_ai */

nrfx_err_t nrfx_twim_bus_recover(uint32_t scl_pin,uint32_t sda_pin)

{
  NRF_GPIO_Type *pNVar1;
  char cVar2;
  uint32_t local_1c [2];
  
  local_1c[0] = sda_pin;
  nrf_gpio_pin_set(scl_pin);
  nrf_gpio_pin_set(sda_pin);
  local_1c[0] = scl_pin;
  pNVar1 = nrf_gpio_pin_port_decode(local_1c);
  pNVar1[local_1c[0] + 0x80] = pNVar1[local_1c[0] + 0x80] & 0xfffcf0f0 | 0x60d;
  local_1c[0] = sda_pin;
  pNVar1 = nrf_gpio_pin_port_decode(local_1c);
  pNVar1[local_1c[0] + 0x80] = pNVar1[local_1c[0] + 0x80] & 0xfffcf0f0 | 0x60d;
  arch_busy_wait(4);
  cVar2 = '\t';
  do {
    local_1c[0] = sda_pin;
    pNVar1 = nrf_gpio_pin_port_decode(local_1c);
    if ((int)((pNVar1[4] >> (local_1c[0] & 0xff)) << 0x1f) < 0) break;
    local_1c[0] = scl_pin;
    pNVar1 = nrf_gpio_pin_port_decode(local_1c);
    cVar2 = cVar2 + -1;
    pNVar1[3] = 1 << (local_1c[0] & 0xff);
    arch_busy_wait(4);
    nrf_gpio_pin_set(scl_pin);
    arch_busy_wait(4);
  } while (cVar2 != '\0');
  local_1c[0] = sda_pin;
  pNVar1 = nrf_gpio_pin_port_decode(local_1c);
  pNVar1[3] = 1 << (local_1c[0] & 0xff);
  arch_busy_wait(4);
  nrf_gpio_pin_set(sda_pin);
  arch_busy_wait(4);
  local_1c[0] = sda_pin;
  pNVar1 = nrf_gpio_pin_port_decode(local_1c);
  return NRFX_ERROR_INTERNAL - ((byte)(pNVar1[4] >> (local_1c[0] & 0xff)) & 1);
}



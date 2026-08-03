/*
 * Function: pin_init
 * Entry:    0006a118
 * Prototype: void __stdcall pin_init(uint32_t pin, nrf_gpio_pin_dir_t dir, nrf_gpio_pin_pull_t pull, nrf_gpio_pin_drive_t drive, uint32_t initial_state)
 */


/* exclude_from_export */

void pin_init(uint32_t pin,nrf_gpio_pin_dir_t dir,nrf_gpio_pin_pull_t pull,
             nrf_gpio_pin_drive_t drive,uint32_t initial_state)

{
  NRF_GPIO_Type *pNVar1;
  uint32_t local_1c;
  nrf_gpio_pin_pull_t nStack_18;
  
  if (pin != 0xffffffff) {
    nStack_18 = pull;
    if (dir == 1) {
      local_1c = dir;
      if (initial_state == 0) {
        nrfy_gpio_pin_clear(pin);
      }
      else {
        nrfy_gpio_pin_set(pin);
      }
    }
    local_1c = pin;
    pNVar1 = nrf_gpio_pin_port_decode(&local_1c);
    pNVar1[local_1c + 0x80] =
         drive << 8 | pull << 2 | dir | pNVar1[local_1c + 0x80] & 0xfffcf0f0 | dir << 1;
  }
  return;
}



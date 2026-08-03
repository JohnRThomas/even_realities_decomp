/*
 * Function: nrf_gpio_cfg_default
 * Entry:    000889aa
 * Prototype: void __stdcall nrf_gpio_cfg_default(uint32_t pin_number)
 */


/* exclude_from_export */

void nrf_gpio_cfg_default(uint32_t pin_number)

{
  nrf_gpio_pin_input_t in_r2;
  nrf_gpio_pin_pull_t in_r3;
  nrf_gpio_pin_drive_t in_stack_00000000;
  nrf_gpio_pin_sense_t in_stack_00000004;
  
  nrf_gpio_cfg(pin_number,0,in_r2,in_r3,in_stack_00000000,in_stack_00000004);
  return;
}



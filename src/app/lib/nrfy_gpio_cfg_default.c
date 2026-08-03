/*
 * Function: nrfy_gpio_cfg_default
 * Entry:    000693d8
 * Prototype: void __stdcall nrfy_gpio_cfg_default(uint32_t pin_number)
 */


/* exclude_from_export */

void nrfy_gpio_cfg_default(uint32_t pin_number)

{
  int extraout_r0;
  int iVar1;
  nrf_gpio_pin_dir_t in_r1;
  nrf_gpio_pin_input_t in_r2;
  nrf_gpio_pin_pull_t in_r3;
  
  nrf_gpio_cfg((uint32_t)&stack0xfffffff4,in_r1,in_r2,in_r3,pin_number,pin_number);
  iVar1 = extraout_r0 + pin_number * 4;
  *(uint *)(iVar1 + 0x200) = *(uint *)(iVar1 + 0x200) & 0xfffcf0f0 | 2;
  return;
}



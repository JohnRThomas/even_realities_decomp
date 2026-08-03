/*
 * Function: nrfy_gpio_cfg_sense_set
 * Entry:    0008897a
 * Prototype: void __stdcall nrfy_gpio_cfg_sense_set(uint32_t pin_number, nrf_gpio_pin_sense_t sense_config)
 */


/* exclude_from_export */

void nrfy_gpio_cfg_sense_set(uint32_t pin_number,nrf_gpio_pin_sense_t sense_config)

{
  nrf_gpio_reconfigure
            (pin_number,(nrf_gpio_pin_dir_t *)0x0,(nrf_gpio_pin_input_t *)0x0,
             (nrf_gpio_pin_pull_t *)0x0,(nrf_gpio_pin_drive_t *)0x0,
             (nrf_gpio_pin_sense_t *)&stack0xfffffff7);
  return;
}



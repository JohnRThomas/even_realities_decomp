/*
 * Function: nrf_gpio_cfg
 * Entry:    00069914
 * Prototype: void __stdcall nrf_gpio_cfg(uint32_t pin_number, nrf_gpio_pin_dir_t dir, nrf_gpio_pin_input_t input, nrf_gpio_pin_pull_t pull, nrf_gpio_pin_drive_t drive, nrf_gpio_pin_sense_t sense)
 */


/* exclude_from_export */

void nrf_gpio_cfg(uint32_t pin_number,nrf_gpio_pin_dir_t dir,nrf_gpio_pin_input_t input,
                 nrf_gpio_pin_pull_t pull,nrf_gpio_pin_drive_t drive,nrf_gpio_pin_sense_t sense)

{
  P1_S *pPVar1;
  
  if (pin_number >> 5 == 0) {
    if ((int)((0xffffffffU >> (pin_number & 0xff)) << 0x1f) < 0) {
      pPVar1 = (P1_S *)&Peripherals::P0_S;
      goto LAB_00069942;
    }
  }
  else if ((pin_number >> 5 == 1) &&
          (pin_number = pin_number & 0x1f, (int)((0xffffU >> pin_number) << 0x1f) < 0)) {
    pPVar1 = &Peripherals::P1_S;
LAB_00069942:
    (&((P0_S *)pPVar1)->PIN_CNF_0_)[pin_number] =
         (&((P0_S *)pPVar1)->PIN_CNF_0_)[pin_number] & 0xfffcf0f0 | dir << 8 | 2;
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","nrf_gpio_pin_present_check(*p_pin)",
          s_WEST_TOPDIR_modules_hal_nordic_n_000ee9e7,815);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



/*
 * Function: nrf_gpio_pin_port_decode
 * Entry:    0006b230
 * Prototype: NRF_GPIO_Type * __stdcall nrf_gpio_pin_port_decode(uint32_t * p_pin)
 */


/* exclude_from_export_ai */

NRF_GPIO_Type * nrf_gpio_pin_port_decode(uint32_t *p_pin)

{
  P1_S *pPVar1;
  uint32_t uVar2;
  
  uVar2 = *p_pin;
  if (uVar2 >> 5 == 0) {
    if ((int)((0xffffffffU >> (uVar2 & 0xff)) << 0x1f) < 0) {
      pPVar1 = (P1_S *)&Peripherals::P0_S;
      goto LAB_0006b274;
    }
  }
  else if ((uVar2 >> 5 == 1) && (uVar2 = uVar2 & 0x1f, (int)((0xffffU >> uVar2) << 0x1f) < 0)) {
    pPVar1 = &Peripherals::P1_S;
LAB_0006b274:
    *p_pin = uVar2;
    return (NRF_GPIO_Type *)(P0_S *)pPVar1;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","nrf_gpio_pin_present_check(*p_pin)",
          s_WEST_TOPDIR_modules_hal_nordic_n_000ee9e7,0x32f);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



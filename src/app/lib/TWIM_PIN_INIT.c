/*
 * Function: TWIM_PIN_INIT
 * Entry:    0006a7f0
 * Prototype: undefined __stdcall TWIM_PIN_INIT(uint param_1, int param_2, int param_3, int param_4)
 */


/* exclude_from_export */

void TWIM_PIN_INIT(uint param_1,int param_2,int param_3,int param_4)

{
  P1_S *pPVar1;
  
  if (param_1 >> 5 == 0) {
    if ((int)((0xffffffffU >> (param_1 & 0xff)) << 0x1f) < 0) {
      pPVar1 = (P1_S *)&Peripherals::P0_S;
      goto LAB_0006a81e;
    }
  }
  else if ((param_1 >> 5 == 1) &&
          (param_1 = param_1 & 0x1f, (int)((0xffffU >> param_1) << 0x1f) < 0)) {
    pPVar1 = &Peripherals::P1_S;
LAB_0006a81e:
    (&((P0_S *)pPVar1)->PIN_CNF_0_)[param_1] =
         param_4 << 8 | param_3 << 2 | param_2 << 1 |
         (&((P0_S *)pPVar1)->PIN_CNF_0_)[param_1] & 0xfffcf0f0;
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","nrf_gpio_pin_present_check(*p_pin)",
          s_WEST_TOPDIR_modules_hal_nordic_n_000ee9e7,815);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



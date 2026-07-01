/*
 * Function: reset_pmic_on
 * Entry:    00017b28
 * Prototype: undefined __stdcall reset_pmic_on(void)
 */


void reset_pmic_on(void)

{
  gpio_pin_set(&gpio0_dev,0x17,1);
  return;
}



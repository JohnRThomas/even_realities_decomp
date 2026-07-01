/*
 * Function: reset_pmic_off
 * Entry:    00017b34
 * Prototype: undefined __stdcall reset_pmic_off(void)
 */


void reset_pmic_off(void)

{
  gpio_pin_set(&gpio0_dev,0x17,0);
  return;
}



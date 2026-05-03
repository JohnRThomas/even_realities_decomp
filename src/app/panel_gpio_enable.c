/*
 * Function: panel_gpio_enable
 * Entry:    00017aec
 * Prototype: undefined __stdcall panel_gpio_enable(void)
 */


void panel_gpio_enable(void)

{
  gpio_pin_set(&gpio0_dev,0x18,1);
  return;
}



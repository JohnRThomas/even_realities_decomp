/*
 * Function: panel_gpio_disable
 * Entry:    00017ae0
 * Prototype: undefined __stdcall panel_gpio_disable(void)
 */


void panel_gpio_disable(void)

{
  gpio_pin_set(&gpio0_dev,0x18,0);
  return;
}



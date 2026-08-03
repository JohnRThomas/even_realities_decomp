/*
 * Function: gpio_pin_set
 * Entry:    00017868
 * Prototype: int __stdcall gpio_pin_set(device * port, gpio_pin_t pin, int value)
 */


/* exclude_from_export */

int gpio_pin_set(device *port,gpio_pin_t pin,int value)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((1 << pin & *(uint *)port->config) == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
            "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",1615);
    _ASSERT("\tUnsupported pin\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((1 << pin & *(uint *)port->data) != 0) {
    value = value ^ 1;
  }
  if (value == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(port->api + 0x10);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(port->api + 0xc);
  }
                    /* WARNING: Could not recover jumptable at 0x000178ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*UNRECOVERED_JUMPTABLE)();
  return iVar1;
}



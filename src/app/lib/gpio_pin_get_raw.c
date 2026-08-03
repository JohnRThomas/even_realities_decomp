/*
 * Function: gpio_pin_get_raw
 * Entry:    000178c4
 * Prototype: int __stdcall gpio_pin_get_raw(device * port, gpio_pin_t pin)
 */


/* exclude_from_export */

int gpio_pin_get_raw(device *port,gpio_pin_t pin)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  uint uVar2;
  uint local_c;
  
  local_c = (uint)pin;
  uVar2 = 1 << local_c;
  if ((uVar2 & *(uint *)port->config) != 0) {
    iVar1 = (**(code **)(port->api + 4))
                      (port,&local_c,*(uint *)port->config,*(code **)(port->api + 4),port);
    if (iVar1 == 0) {
      if ((uVar2 & local_c) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    return iVar1;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
          "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
          "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",1489);
  _ASSERT("\tUnsupported pin\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



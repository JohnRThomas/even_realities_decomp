/*
 * Function: gpio_pin_get
 * Entry:    00017a80
 * Prototype: int __stdcall gpio_pin_get(device * port, gpio_pin_t pin)
 */


/* exclude_from_export */

int gpio_pin_get(device *port,gpio_pin_t pin)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  uint uVar2;
  uint local_14 [2];
  
  local_14[0] = (uint)pin;
  uVar2 = 1 << ((uint)port & 0xff);
  if (uVar2 != 0) {
    iVar1 = gpio_nrfx_port_get_raw(0x8b310,local_14);
    if (iVar1 == 0) {
      if (((local_14[0] ^ gpio0_data.invert) & uVar2) == 0) {
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
          "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",1526);
  _ASSERT("\tUnsupported pin\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



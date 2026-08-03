/*
 * Function: z_impl_gpio_pin_interrupt_configure
 * Entry:    00017958
 * Prototype: int __stdcall z_impl_gpio_pin_interrupt_configure(device * port, gpio_pin_t pin, gpio_flags_t flags)
 */


/* WARNING: Removing unreachable block (ram,0x000179f8) */
/* WARNING: Removing unreachable block (ram,0x000179fe) */
/* WARNING: Removing unreachable block (ram,0x000179ac) */
/* WARNING: Removing unreachable block (ram,0x000179d0) */
/* WARNING: Removing unreachable block (ram,0x000179f4) */
/* WARNING: Removing unreachable block (ram,0x00017a02) */
/* WARNING: Removing unreachable block (ram,0x000179da) */
/* WARNING: Removing unreachable block (ram,0x000179b6) */
/* WARNING: Removing unreachable block (ram,0x00017972) */
/* exclude_from_export */

int z_impl_gpio_pin_interrupt_configure(device *port,gpio_pin_t pin,gpio_flags_t flags)

{
  char *test;
  char *file;
  int line;
  
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(flags & ((1U << 21) | (1U << 22))) != 0U",
          "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",0x36e);
  _ASSERT("\tMust either enable or disable interrupts\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}



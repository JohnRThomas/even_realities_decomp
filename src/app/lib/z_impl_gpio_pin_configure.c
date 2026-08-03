/*
 * Function: z_impl_gpio_pin_configure
 * Entry:    00065374
 * Prototype: int __stdcall z_impl_gpio_pin_configure(device * port, gpio_pin_t pin, gpio_flags_t flags)
 */


/* exclude_from_export */

int z_impl_gpio_pin_configure(device *port,gpio_pin_t pin,gpio_flags_t flags)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  int line;
  int line_00;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  puVar5 = port->config;
  puVar6 = puVar5 + 0x28;
  do {
    if (*(device **)(puVar5 + 4) != (device *)0x0) {
      bVar2 = z_device_is_ready(*(device **)(puVar5 + 4));
      if (!bVar2) {
        return -0x13;
      }
      uVar7 = (uint)*(ushort *)(puVar5 + 10);
      iVar3 = *(int *)(puVar5 + 4);
      bVar1 = puVar5[8];
      puVar8 = *(undefined4 **)(iVar3 + 8);
      if ((uVar7 & 0x30) == 0x30) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(flags & ((1 << 4) | (1 << 5))) != ((1 << 4) | (1 << 5))",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",970);
        _ASSERT("\tPull Up and Pull Down should not be enabled simultaneously\n",test,file,line);
LAB_000653cc:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((uVar7 & 6) == 4) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(flags & (1 << 1)) != 0 || (flags & (1 << 2)) == 0"
                ,"WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",977);
        goto LAB_000653cc;
      }
      uVar9 = 1 << (uint)bVar1;
      if ((uVar9 & **(uint **)(iVar3 + 4)) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",996);
        _ASSERT("\tUnsupported pin\n",test_00,file_00,line_00);
        goto LAB_000653cc;
      }
      uVar4 = **(uint **)(iVar3 + 0x10);
      if ((int)(uVar7 << 0x1f) < 0) {
        uVar9 = uVar9 | uVar4;
      }
      else {
        uVar9 = uVar4 & ~uVar9;
      }
      **(uint **)(iVar3 + 0x10) = uVar9;
      iVar3 = (*(code *)*puVar8)(iVar3,(uint)bVar1,uVar7 | 0x20000);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    puVar5 = puVar5 + 8;
    if (puVar6 == puVar5) {
      return 0;
    }
  } while( true );
}



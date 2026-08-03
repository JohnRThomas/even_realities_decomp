/*
 * Function: gpio_nrfx_manage_callback
 * Entry:    00066c7c
 * Prototype: int __stdcall gpio_nrfx_manage_callback(device * port, gpio_callback * callback, bool set)
 */


/* exclude_from_export_ai */

int gpio_nrfx_manage_callback(device *port,gpio_callback *callback,bool set)

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
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar5 = (undefined4 *)port->config;
  bVar2 = z_device_is_ready((device *)*puVar5);
  if (bVar2) {
    if ((device *)puVar5[1] == (device *)0x0) {
      return 0;
    }
    bVar2 = z_device_is_ready((device *)puVar5[1]);
    if (bVar2) {
      uVar7 = (uint)*(ushort *)((int)puVar5 + 10);
      iVar3 = puVar5[1];
      bVar1 = *(byte *)(puVar5 + 2);
      puVar5 = *(undefined4 **)(iVar3 + 8);
      if ((uVar7 & 0x30) == 0x30) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(flags & ((1 << 4) | (1 << 5))) != ((1 << 4) | (1 << 5))",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",970);
        _ASSERT("\tPull Up and Pull Down should not be enabled simultaneously\n",test,file,line);
      }
      else if ((uVar7 & 6) == 4) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(flags & (1 << 1)) != 0 || (flags & (1 << 2)) == 0"
                ,"WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",0x3d1);
      }
      else {
        uVar6 = 1 << (uint)bVar1;
        if ((uVar6 & **(uint **)(iVar3 + 4)) != 0) {
          uVar4 = **(uint **)(iVar3 + 0x10);
          if ((int)(uVar7 << 0x1f) < 0) {
            uVar4 = uVar4 | uVar6;
          }
          else {
            uVar4 = uVar4 & ~uVar6;
          }
          **(uint **)(iVar3 + 0x10) = uVar4;
                    /* WARNING: Could not recover jumptable at 0x00066d28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar3 = (*(code *)*puVar5)(iVar3,(uint)bVar1,uVar7 | 0x400);
          return iVar3;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",996);
        _ASSERT("\tUnsupported pin\n",test_00,file_00,line_00);
      }
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  return -0x13;
}



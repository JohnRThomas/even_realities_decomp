/*
 * Function: gpio_fire_callbacks
 * Entry:    00064854
 * Prototype: void __stdcall gpio_fire_callbacks(sys_slist_t * list, device * port, uint32_t pins)
 */


/* exclude_from_export_ai */

void gpio_fire_callbacks(sys_slist_t *list,device *port,uint32_t pins)

{
  undefined4 *puVar1;
  char *test;
  char *file;
  int line;
  undefined4 *puVar2;
  device *pdVar3;
  
  if ((uint)list >> 5 == 0) {
    pdVar3 = &gpio0_dev;
  }
  else {
    if ((uint)list >> 5 != 1) {
      return;
    }
    pdVar3 = &gpio1_dev;
  }
  puVar1 = *(undefined4 **)(pdVar3->data + 4);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    while (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[2] & 1 << ((uint)list & 0x1f)) != 0) {
        if ((code *)puVar1[1] == (code *)0x0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb->handler",
                  "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio/gpio_utils.h",0x5d);
          _ASSERT("\tNo callback handler!\n",test,file,line);
                    /* WARNING: Subroutine does not return */
          k_panic();
        }
        (*(code *)puVar1[1])(pdVar3);
      }
      puVar1 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar2;
      }
    }
  }
  return;
}



/*
 * Function: gpio_manage_callback
 * Entry:    0006466c
 * Prototype: int __stdcall gpio_manage_callback(sys_slist_t * callbacks, gpio_callback * callback, bool set)
 */


/* exclude_from_export */

int gpio_manage_callback(sys_slist_t *callbacks,gpio_callback *callback,bool set)

{
  gpio_callback *pgVar1;
  undefined *puVar2;
  gpio_callback *pgVar3;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  undefined *puVar4;
  int line;
  int line_00;
  
  puVar4 = callbacks[2].head;
  if (callback == (gpio_callback *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","callback",
            "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio/gpio_utils.h",58);
    _ASSERT("\tNo callback!\n",test,file,line);
  }
  else {
    if (callback->handler != (undefined *)0x0) {
      pgVar1 = *(gpio_callback **)(puVar4 + 4);
      if (pgVar1 == (gpio_callback *)0x0) {
LAB_000646ea:
        if (!set) {
          return -0x16;
        }
      }
      else {
        if (pgVar1 == callback) {
          puVar2 = callback->node;
          *(undefined **)(puVar4 + 4) = puVar2;
          if (callback == *(gpio_callback **)(puVar4 + 8)) {
            *(undefined **)(puVar4 + 8) = puVar2;
          }
        }
        else {
          do {
            pgVar3 = pgVar1;
            pgVar1 = (gpio_callback *)pgVar3->node;
            if (pgVar1 == (gpio_callback *)0x0) goto LAB_000646ea;
          } while (callback != pgVar1);
          pgVar3->node = callback->node;
          if (callback == *(gpio_callback **)(puVar4 + 8)) {
            *(gpio_callback **)(puVar4 + 8) = pgVar3;
          }
        }
        callback->node = (undefined *)0x0;
        if (!set) {
          return 0;
        }
      }
      callback->node = *(undefined **)(puVar4 + 4);
      *(gpio_callback **)(puVar4 + 4) = callback;
      if (*(int *)(puVar4 + 8) == 0) {
        *(gpio_callback **)(puVar4 + 8) = callback;
      }
      return 0;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","callback->handler",
            "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio/gpio_utils.h",59);
    _ASSERT("\tNo callback handler!\n",test_00,file_00,line_00);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



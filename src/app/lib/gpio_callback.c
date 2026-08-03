/*
 * Function: gpio_callback
 * Entry:    00087508
 * Prototype: undefined __stdcall gpio_callback(undefined4 param_1, int param_2)
 */


/* exclude_from_export */

void gpio_callback(undefined4 param_1,int param_2)

{
  k_work_submit((k_work *)(param_2 + 0xc));
  return;
}



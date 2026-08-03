/*
 * Function: hw_cc3xx_init
 * Entry:    00088502
 * Prototype: void __stdcall hw_cc3xx_init(init_level level)
 */


/* exclude_from_export_ai */

void hw_cc3xx_init(init_level level)

{
  nrf_cc3xx_platform_abort_init();
  nrf_cc3xx_platform_mutex_init();
  nrf_cc3xx_platform_init();
  return;
}



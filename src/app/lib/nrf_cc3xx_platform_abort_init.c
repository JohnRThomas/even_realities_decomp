/*
 * Function: nrf_cc3xx_platform_abort_init
 * Entry:    00052fa4
 * Prototype: undefined __stdcall nrf_cc3xx_platform_abort_init(void)
 */


/* exclude_from_export */

void nrf_cc3xx_platform_abort_init(void)

{
  nrf_cc3xx_platform_set_abort((nrf_cc3xx_platform_abort_apis_t *)&nrf_cc3xx_apis);
  return;
}



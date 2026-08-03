/*
 * Function: nrf_cc3xx_platform_set_abort
 * Entry:    0007c8a0
 * Prototype: undefined __stdcall nrf_cc3xx_platform_set_abort(nrf_cc3xx_platform_abort_apis_t * param_1)
 */


/* exclude_from_export */

void nrf_cc3xx_platform_set_abort(nrf_cc3xx_platform_abort_apis_t *param_1)

{
  nrf_cc3xx_platform_abort_apis_t_20002f10.abort_handle = param_1->abort_handle;
  nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn = param_1->abort_fn;
  return;
}



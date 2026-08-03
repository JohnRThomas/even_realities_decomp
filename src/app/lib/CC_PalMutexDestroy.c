/*
 * Function: CC_PalMutexDestroy
 * Entry:    0007d698
 * Prototype: undefined4 __stdcall CC_PalMutexDestroy(undefined4 * param_1)
 */


/* exclude_from_export */

undefined4 CC_PalMutexDestroy(undefined4 *param_1)

{
  (*nrf_cc3xx_mutex_free_cb)(*(nrf_cc3xx_platform_mutex_t **)*param_1);
  return 0;
}



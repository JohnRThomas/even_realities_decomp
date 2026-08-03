/*
 * Function: CC_PalMutexCreate
 * Entry:    0007d684
 * Prototype: CCError_t __stdcall CC_PalMutexCreate(CC_PalMutex * pMutexId)
 */


/* exclude_from_export_ai */

CCError_t CC_PalMutexCreate(CC_PalMutex *pMutexId)

{
  (*nrf_cc3xx_mutex_init_cb)(*(nrf_cc3xx_platform_mutex_t **)*pMutexId);
  return 0;
}



/*
 * Function: CC_PalMutexUnlock
 * Entry:    0007d6bc
 * Prototype: CCError_t __stdcall CC_PalMutexUnlock(CC_PalMutex * pMutexId)
 */


/* exclude_from_export */

CCError_t CC_PalMutexUnlock(CC_PalMutex *pMutexId)

{
  (*nrf_cc3xx_mutex_unlock_cb)(*(nrf_cc3xx_platform_mutex_t **)*pMutexId);
  return 0;
}



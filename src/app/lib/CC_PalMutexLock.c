/*
 * Function: CC_PalMutexLock
 * Entry:    0007d6ac
 * Prototype: CCError_t __stdcall CC_PalMutexLock(CC_PalMutex * pMutexId, uint32_t aTimeOut)
 */


/* exclude_from_export */

CCError_t CC_PalMutexLock(CC_PalMutex *pMutexId,uint32_t aTimeOut)

{
  CCError_t CVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0007d6b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = (*nrf_cc3xx_mutex_lock_cb)(*(nrf_cc3xx_platform_mutex_t **)*pMutexId);
  return CVar1;
}



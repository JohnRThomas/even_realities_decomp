/*
 * Function: nrf_cc3xx_platform_mutex_unlock
 * Entry:    0007d7a8
 * Prototype: void __stdcall nrf_cc3xx_platform_mutex_unlock(nrf_cc3xx_platform_mutex_t * mutex)
 */


/* exclude_from_export */

void nrf_cc3xx_platform_mutex_unlock(nrf_cc3xx_platform_mutex_t *mutex)

{
                    /* WARNING: Could not recover jumptable at 0x0007d7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*nrf_cc3xx_mutex_unlock_cb)(mutex);
  return;
}



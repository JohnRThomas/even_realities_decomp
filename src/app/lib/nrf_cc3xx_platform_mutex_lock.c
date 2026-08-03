/*
 * Function: nrf_cc3xx_platform_mutex_lock
 * Entry:    0007d79c
 * Prototype: void __stdcall nrf_cc3xx_platform_mutex_lock(nrf_cc3xx_platform_mutex_t * mutex)
 */


/* exclude_from_export */

void nrf_cc3xx_platform_mutex_lock(nrf_cc3xx_platform_mutex_t *mutex)

{
                    /* WARNING: Could not recover jumptable at 0x0007d7a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*nrf_cc3xx_mutex_lock_cb)(mutex);
  return;
}



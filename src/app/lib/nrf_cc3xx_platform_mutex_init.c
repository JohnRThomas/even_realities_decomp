/*
 * Function: nrf_cc3xx_platform_mutex_init
 * Entry:    0007d790
 * Prototype: void __stdcall nrf_cc3xx_platform_mutex_init(nrf_cc3xx_platform_mutex_t * mutex)
 */


/* exclude_from_export */

void nrf_cc3xx_platform_mutex_init(nrf_cc3xx_platform_mutex_t *mutex)

{
                    /* WARNING: Could not recover jumptable at 0x0007d794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*nrf_cc3xx_mutex_init_cb)(mutex);
  return;
}



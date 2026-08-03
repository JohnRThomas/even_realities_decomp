/*
 * Function: nrf_cc3xx_platform_set_mutexes
 * Entry:    0007ca28
 * Prototype: void __stdcall nrf_cc3xx_platform_set_mutexes(nrf_cc3xx_platform_mutex_apis_t * apis, nrf_cc3xx_platform_mutexes_t * mutexes)
 */


/* exclude_from_export_ai */

void nrf_cc3xx_platform_set_mutexes
               (nrf_cc3xx_platform_mutex_apis_t *apis,nrf_cc3xx_platform_mutexes_t *mutexes)

{
  nrf_cc3xx_mutex_free_cb = apis->mutex_free_fn;
  nrf_cc3xx_mutex_init_cb = apis->mutex_init_fn;
  nrf_cc3xx_mutex_lock_cb = apis->mutex_lock_fn;
  nrf_cc3xx_mutex_unlock_cb = apis->mutex_unlock_fn;
  nrf_cc3xx_platform_sym_mutex = mutexes->sym_mutex;
  nrf_cc3xx_platform_asym_mutex = mutexes->asym_mutex;
  nrf_cc3xx_platform_rng_mutex = mutexes->rng_mutex;
  nrf_cc3xx_platform_reserved_mutex = mutexes->reserved;
  nrf_cc3xx_platform_power_mutex = mutexes->power_mutex;
  if ((DAT_2000d730 & 0x3a000000) != 0) {
    DAT_2000d72c = 0;
    DAT_2000d7d0 = 0;
    DAT_2000d730 = 0xa95c5f2c;
    DAT_2000d7d4 = 0xa95c5f2c;
    (*nrf_cc3xx_mutex_init_cb)(&DAT_2000d72c);
                    /* WARNING: Could not recover jumptable at 0x0007ca84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*nrf_cc3xx_mutex_init_cb)(&DAT_2000d7d0);
    return;
  }
  return;
}



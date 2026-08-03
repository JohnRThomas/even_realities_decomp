/*
 * Function: mutex_free
 * Entry:    0007c954
 * Prototype: void __stdcall mutex_free(mbedtls_threading_mutex_t * p_mutex)
 */


/* exclude_from_export */

void mutex_free(mbedtls_threading_mutex_t *p_mutex)

{
  if (p_mutex == (mbedtls_threading_mutex_t *)0x0) {
    (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)("mutex_free called with NULL parameter");
  }
  if (((p_mutex[1] & 0x3a000000) != 0) && (p_mutex[1] != 0xa95c5f2c)) {
    p_mutex[1] = 0xa95c5f2c;
    *p_mutex = 0;
  }
  return;
}



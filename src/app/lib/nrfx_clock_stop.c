/*
 * Function: nrfx_clock_stop
 * Entry:    000685cc
 * Prototype: void __stdcall nrfx_clock_stop(nrf_clock_domain_t domain)
 */


/* exclude_from_export */

void nrfx_clock_stop(nrf_clock_domain_t domain)

{
  if (!m_clock_cb.module_initialized) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_clock_cb.module_initialized",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",429);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  clock_stop(domain);
  return;
}



/*
 * Function: nrfx_clock_init
 * Entry:    00068438
 * Prototype: nrfx_err_t __stdcall nrfx_clock_init(nrfx_clock_event_handler_t * event_handler)
 */


/* exclude_from_export */

nrfx_err_t nrfx_clock_init(nrfx_clock_event_handler_t *event_handler)

{
  nrfx_err_t nVar1;
  
  if (event_handler == (nrfx_clock_event_handler_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event_handler",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_clock.c",277);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (m_clock_cb.module_initialized) {
    nVar1 = NRFX_ERROR_FORBIDDEN|NRFX_ERROR_INVALID_PARAM;
  }
  else {
    nVar1 = NRFX_SUCCESS;
    m_clock_cb.module_initialized = true;
    m_clock_cb.event_handler = event_handler;
  }
  return nVar1;
}



/*
 * Function: lfclk_stop
 * Entry:    00087038
 * Prototype: undefined __stdcall lfclk_stop(void)
 */


/* exclude_from_export */

void lfclk_stop(void)

{
  nrfx_clock_stop(NRF_CLOCK_DOMAIN_LFCLK);
  return;
}



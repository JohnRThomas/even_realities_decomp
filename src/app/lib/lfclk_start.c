/*
 * Function: lfclk_start
 * Entry:    00087026
 * Prototype: undefined __stdcall lfclk_start(void)
 */


/* exclude_from_export */

void lfclk_start(void)

{
  nrfx_clock_start(NRF_CLOCK_DOMAIN_LFCLK);
  return;
}



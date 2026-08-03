/*
 * Function: hfclkaudio_start
 * Entry:    0008701a
 * Prototype: void __stdcall hfclkaudio_start(nrf_clock_domain_t domain)
 */


/* exclude_from_export */

void hfclkaudio_start(nrf_clock_domain_t domain)

{
  nrfx_clock_start(NRF_CLOCK_DOMAIN_HFCLKAUDIO);
  return;
}



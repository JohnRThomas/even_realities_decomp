/*
 * Function: hfclkaudio_stop
 * Entry:    0008702c
 * Prototype: undefined __stdcall hfclkaudio_stop(void)
 */


/* exclude_from_export */

void hfclkaudio_stop(void)

{
  nrfx_clock_stop(NRF_CLOCK_DOMAIN_HFCLKAUDIO);
  return;
}



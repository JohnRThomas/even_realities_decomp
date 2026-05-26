/*
 * Function: hfclk192m_stop
 * Entry:    00087032
 * Prototype: undefined __stdcall hfclk192m_stop(void)
 */


/* export_from_export */

void hfclk192m_stop(void)

{
  nrfx_clock_stop(NRF_CLOCK_DOMAIN_HFCLK192M);
  return;
}



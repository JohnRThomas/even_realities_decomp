/*
 * Function: hfclk192m_start
 * Entry:    00087020
 * Prototype: undefined __stdcall hfclk192m_start(void)
 */


/* exclude_from_export */

void hfclk192m_start(void)

{
  nrfx_clock_start(NRF_CLOCK_DOMAIN_HFCLK192M);
  return;
}



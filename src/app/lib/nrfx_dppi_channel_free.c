/*
 * Function: nrfx_dppi_channel_free
 * Entry:    000686c0
 * Prototype: nrfx_err_t __stdcall nrfx_dppi_channel_free(uint8_t channel)
 */


/* exclude_from_export */

nrfx_err_t nrfx_dppi_channel_free(uint8_t channel)

{
  nrfx_err_t nVar1;
  
  Peripherals::DPPIC_S.CHENCLR = 1 << (uint)channel;
  nVar1 = nrfx_flag32_free((nrfx_atomic_t *)&DAT_20002bdc,channel);
  return nVar1;
}



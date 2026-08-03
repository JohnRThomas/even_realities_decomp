/*
 * Function: nrfx_gpiote_channel_free
 * Entry:    00068c74
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_channel_free(uint8_t channel)
 */


/* exclude_from_export */

nrfx_err_t nrfx_gpiote_channel_free(uint8_t channel)

{
  nrfx_err_t nVar1;
  
  nVar1 = nrfx_flag32_free((nrfx_atomic_t *)&DAT_20002c50,channel);
  return nVar1;
}



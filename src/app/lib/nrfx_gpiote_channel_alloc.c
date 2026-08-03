/*
 * Function: nrfx_gpiote_channel_alloc
 * Entry:    00068c80
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_channel_alloc(uint8_t * p_channel)
 */


/* exclude_from_export */

nrfx_err_t nrfx_gpiote_channel_alloc(uint8_t *p_channel)

{
  nrfx_err_t nVar1;
  
  nVar1 = nrfx_flag32_alloc((nrfx_atomic_t *)&DAT_20002c50,p_channel);
  return nVar1;
}



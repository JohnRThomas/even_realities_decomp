/*
 * Function: gppi_channel_alloc
 * Entry:    000686b4
 * Prototype: nrfx_err_t __stdcall gppi_channel_alloc(uint8_t * param_1)
 */


/* exclude_from_export */

nrfx_err_t gppi_channel_alloc(uint8_t *param_1)

{
  nrfx_err_t nVar1;
  
  nVar1 = nrfx_flag32_alloc((nrfx_atomic_t *)&DAT_20002bdc,param_1);
  return nVar1;
}



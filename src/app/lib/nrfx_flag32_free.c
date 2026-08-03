/*
 * Function: nrfx_flag32_free
 * Entry:    000681a0
 * Prototype: nrfx_err_t __stdcall nrfx_flag32_free(nrfx_atomic_t * p_mask, uint8_t flag)
 */


/* exclude_from_export */

nrfx_err_t nrfx_flag32_free(nrfx_atomic_t *p_mask,uint8_t flag)

{
  nrfx_err_t nVar1;
  
  if ((int)(((uint)*p_mask >> flag) << 0x1f) < 0) {
    nVar1 = NRFX_ERROR_INVALID_PARAM;
  }
  else {
    do {
    } while (*p_mask != *p_mask);
    *p_mask = 1 << flag | *p_mask;
    nVar1 = NRFX_SUCCESS;
  }
  return nVar1;
}



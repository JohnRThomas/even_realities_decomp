/*
 * Function: nrfx_flag32_alloc
 * Entry:    00068160
 * Prototype: nrfx_err_t __stdcall nrfx_flag32_alloc(nrfx_atomic_t * p_mask, uint8_t * p_flag)
 */


/* exclude_from_export */

nrfx_err_t nrfx_flag32_alloc(nrfx_atomic_t *p_mask,uint8_t *p_flag)

{
  uint uVar1;
  
  do {
    uVar1 = *p_mask;
    if (uVar1 == 0) {
      return NRFX_ERROR_NO_MEM;
    }
  } while (*p_mask != uVar1);
  *p_mask = uVar1 & ~(1 << (0x1fU - LZCOUNT(uVar1) & 0xff));
  *p_flag = (uint8_t)(0x1fU - LZCOUNT(uVar1));
  return NRFX_SUCCESS;
}



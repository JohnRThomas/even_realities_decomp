/*
 * Function: nrfx_gpiote_channel_get
 * Entry:    00068b90
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_channel_get(nrfx_gpiote_pin_t pin, uint8_t * p_channel)
 */


/* exclude_from_export */

nrfx_err_t nrfx_gpiote_channel_get(nrfx_gpiote_pin_t pin,uint8_t *p_channel)

{
  bool bVar1;
  byte bVar2;
  nrfx_err_t nVar3;
  byte *extraout_r1;
  
  if (p_channel == (uint8_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_channel",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_gpiote.c",613);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  bVar1 = pin_in_use_by_te(pin);
  if (bVar1) {
    bVar2 = get_pin_idx(pin);
    nVar3 = NRFX_SUCCESS;
    *extraout_r1 = (byte)((ushort)*(undefined2 *)((int)&DAT_20002be0 + (bVar2 + 8) * 2) >> 0xd);
  }
  else {
    nVar3 = NRFX_ERROR_INVALID_PARAM;
  }
  return nVar3;
}



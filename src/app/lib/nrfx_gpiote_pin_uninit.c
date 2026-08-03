/*
 * Function: nrfx_gpiote_pin_uninit
 * Entry:    00068dc0
 * Prototype: nrfx_err_t __stdcall nrfx_gpiote_pin_uninit(nrfx_gpiote_pin_t pin)
 */


/* exclude_from_export */

nrfx_err_t nrfx_gpiote_pin_uninit(nrfx_gpiote_pin_t pin)

{
  bool bVar1;
  byte bVar2;
  nrfx_err_t nVar3;
  NRF_GPIO_Type *pNVar4;
  nrfx_gpiote_pin_t local_c;
  
  bVar1 = pin_in_use(pin);
  if (bVar1) {
    nrfx_gpiote_trigger_disable(pin);
    bVar1 = pin_in_use_by_te(pin);
    if (bVar1) {
      bVar2 = pin_te_get(pin);
      (&Peripherals::GPIOTE0_S.CONFIG_0_)[(short)(ushort)bVar2] = 0;
      (&Peripherals::GPIOTE0_S.CONFIG_0_)[(short)(ushort)bVar2] = 0;
    }
    release_handler((lv_obj_t *)pin);
    bVar2 = get_pin_idx(pin);
    *(undefined2 *)((int)&DAT_20002be0 + (bVar2 + 8) * 2) = 0;
    local_c = pin;
    pNVar4 = nrf_gpio_pin_port_decode(&local_c);
    pNVar4[local_c + 0x80] = pNVar4[local_c + 0x80] & 0xfffcf0f0 | 2;
    nVar3 = NRFX_SUCCESS;
  }
  else {
    nVar3 = NRFX_ERROR_INVALID_PARAM;
  }
  return nVar3;
}



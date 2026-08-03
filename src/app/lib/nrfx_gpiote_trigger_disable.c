/*
 * Function: nrfx_gpiote_trigger_disable
 * Entry:    00068d74
 * Prototype: void __stdcall nrfx_gpiote_trigger_disable(nrfx_gpiote_pin_t pin)
 */


/* exclude_from_export */

void nrfx_gpiote_trigger_disable(nrfx_gpiote_pin_t pin)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = pin_in_use_by_te(pin);
  if ((bVar1) && (bVar1 = pin_is_output(pin), !bVar1)) {
    bVar2 = pin_te_get(pin);
    Peripherals::GPIOTE0_S.INTENCLR = 1 << bVar2;
    (&Peripherals::GPIOTE0_S.CONFIG_0_)[(short)(ushort)bVar2] =
         (&Peripherals::GPIOTE0_S.CONFIG_0_)[(short)(ushort)bVar2] & 0xfffffffc;
    return;
  }
  nrfy_gpio_cfg_sense_set(pin,0);
  return;
}



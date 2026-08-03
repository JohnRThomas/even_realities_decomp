/*
 * Function: nrfx_pdm_uninit
 * Entry:    00069484
 * Prototype: void __stdcall nrfx_pdm_uninit(void)
 */


/* exclude_from_export */

void nrfx_pdm_uninit(void)

{
  uint32_t pin_number;
  uint32_t pin_number_00;
  
  arch_irq_disable(0x26);
  Peripherals::PDM0_S.ENABLE = 0;
  if (nrfx_pdm_m_cb.skip_gpio_cfg == false) {
    pin_number = Peripherals::PDM0_S._1344_4_;
    pin_number_00 = Peripherals::PDM0_S._1348_4_;
    nrfy_gpio_cfg_default(pin_number);
    nrfy_gpio_cfg_default(pin_number_00);
  }
  nrfx_pdm_m_cb.drv_state = NRFX_DRV_STATE_UNINITIALIZED;
  return;
}



/*
 * Function: $_?_nrf_dppi_channels_disable
 * Entry:    000681e4
 * Prototype: void __stdcall $_?_nrf_dppi_channels_disable(NRF_DPPIC_Type * p_reg, uint32_t mask)
 */


void ____nrf_dppi_channels_disable(NRF_DPPIC_Type *p_reg,uint32_t mask)

{
  Peripherals::DPPIC_S.CHENCLR = (uint)p_reg;
  return;
}



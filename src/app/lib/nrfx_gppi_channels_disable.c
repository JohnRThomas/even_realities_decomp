/*
 * Function: nrfx_gppi_channels_disable
 * Entry:    000681e4
 * Prototype: void __stdcall nrfx_gppi_channels_disable(uint32_t mask)
 */


/* exclude_from_export */

void nrfx_gppi_channels_disable(uint32_t mask)

{
  Peripherals::DPPIC_S.CHENCLR = mask;
  return;
}



/*
 * Function: nrfx_gppi_channels_enable
 * Entry:    000681d8
 * Prototype: void __stdcall nrfx_gppi_channels_enable(uint32_t mask)
 */


/* exclude_from_export */

void nrfx_gppi_channels_enable(uint32_t mask)

{
  Peripherals::DPPIC_S.CHENSET = mask;
  return;
}



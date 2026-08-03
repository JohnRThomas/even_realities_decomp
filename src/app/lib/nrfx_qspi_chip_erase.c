/*
 * Function: nrfx_qspi_chip_erase
 * Entry:    000889bc
 * Prototype: nrfx_err_t __stdcall nrfx_qspi_chip_erase(void)
 */


/* exclude_from_export */

nrfx_err_t nrfx_qspi_chip_erase(void)

{
  nrfx_err_t nVar1;
  
  nVar1 = nrfx_qspi_erase(NRF_QSPI_ERASE_LEN_ALL,0);
  return nVar1;
}



/*
 * Function: _nrfx_qspi_read
 * Entry:    000889b6
 * Prototype: nrfx_err_t __stdcall _nrfx_qspi_read(void * p_rx_buffer, size_t rx_buffer_length, uint32_t src_address)
 */


/* exclude_from_export */

nrfx_err_t _nrfx_qspi_read(void *p_rx_buffer,size_t rx_buffer_length,uint32_t src_address)

{
  nrfx_err_t nVar1;
  
  nVar1 = qspi_xfer(p_rx_buffer,rx_buffer_length,src_address,NRFX_QSPI_STATE_READ);
  return nVar1;
}



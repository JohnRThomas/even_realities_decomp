/*
 * Function: nrfx_qspi_write
 * Entry:    000889b0
 * Prototype: nrfx_err_t __stdcall nrfx_qspi_write(void * param_1, size_t param_2, uint32_t param_3)
 */


/* exclude_from_export */

nrfx_err_t nrfx_qspi_write(void *param_1,size_t param_2,uint32_t param_3)

{
  nrfx_err_t nVar1;
  
  nVar1 = qspi_xfer(param_1,param_2,param_3,NRFX_QSPI_STATE_WRITE);
  return nVar1;
}



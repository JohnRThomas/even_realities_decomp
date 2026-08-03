/*
 * Function: nrfx_qspi_init
 * Entry:    00069c3c
 * Prototype: nrfx_err_t __stdcall nrfx_qspi_init(nrfx_qspi_config_t * p_config, nrfx_qspi_handler_t * handler, void * p_context)
 */


/* exclude_from_export */

nrfx_err_t nrfx_qspi_init(nrfx_qspi_config_t *p_config,nrfx_qspi_handler_t *handler,void *p_context)

{
  nrfx_qspi_state_t nVar1;
  nrfx_err_t nVar2;
  
  nVar1 = qspi_m_cb.state;
  if (p_config == (nrfx_qspi_config_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",411);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (qspi_m_cb.state == NRFX_QSPI_STATE_UNINITIALIZED) {
    qspi_m_cb.handler = handler;
    qspi_m_cb.p_context = p_context;
    nVar2 = qspi_configure(p_config);
    if ((uint)nVar2 == 0xbad0000) {
      qspi_m_cb.state = NRFX_QSPI_STATE_IDLE;
      qspi_m_cb.activated = (bool)nVar1;
      qspi_m_cb.p_buffer_primary = (void *)0x0;
      qspi_m_cb.p_buffer_secondary = (void *)0x0;
    }
  }
  else {
    nVar2 = NRFX_ERROR_INVALID_STATE;
  }
  return nVar2;
}



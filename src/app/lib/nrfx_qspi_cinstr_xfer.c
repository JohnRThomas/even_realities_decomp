/*
 * Function: nrfx_qspi_cinstr_xfer
 * Entry:    00069c9c
 * Prototype: nrfx_err_t __stdcall nrfx_qspi_cinstr_xfer(nrf_qspi_cinstr_conf_t * p_config, void * p_tx_buffer, void * p_rx_buffer)
 */


/* exclude_from_export */

nrfx_err_t
nrfx_qspi_cinstr_xfer(nrf_qspi_cinstr_conf_t *p_config,void *p_tx_buffer,void *p_rx_buffer)

{
  nrfx_err_t nVar1;
  void *p_tx_data;
  void *p_rx_data;
  
  if (qspi_m_cb.state == NRFX_QSPI_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state != NRFX_QSPI_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",477);
LAB_00069cc2:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (qspi_m_cb.state == NRFX_QSPI_STATE_IDLE) {
    if ((qspi_m_cb.activated) || (nVar1 = qspi_activate(true), nVar1 != 0xbad0007)) {
      Peripherals::QSPI_S.INTENCLR = 1;
      qspi_workaround_apply();
      if (p_tx_buffer != (void *)0x0) {
        nrf_qspi_cinstrdata_set
                  ((NRF_QSPI_Type *)(uint)p_config->opaque[1],(nrf_qspi_cinstr_len_t)p_tx_buffer,
                   p_tx_data);
      }
      qspi_m_cb.timeout_signal = false;
      Peripherals::QSPI_S.EVENTS_READY = 0;
      Peripherals::QSPI_S.CINSTRCONF =
           (uint)p_config->opaque[2] << 0xc | (uint)p_config->opaque[1] << 8 |
           (uint)p_config->opaque[0] | (uint)p_config->opaque[3] << 0xd |
           (uint)p_config[1].opaque[0] << 0xe | (uint)p_config[1].opaque[1] << 0xf;
      nVar1 = qspi_ready_wait();
      if (nVar1 != 0xbad0007) {
        Peripherals::QSPI_S.EVENTS_READY = 0;
        if (p_rx_buffer != (void *)0x0) {
          nrf_qspi_cinstrdata_get
                    ((NRF_QSPI_Type *)(uint)p_config->opaque[1],(nrf_qspi_cinstr_len_t)p_rx_buffer,
                     p_rx_data);
        }
        return NRFX_SUCCESS;
      }
      if (p_config[1].opaque[0] == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config->wipwait",
                "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",0x20a);
        goto LAB_00069cc2;
      }
    }
    nVar1 = NRFX_ERROR_TIMEOUT;
  }
  else {
    nVar1 = NRFX_ERROR_BUSY;
  }
  return nVar1;
}



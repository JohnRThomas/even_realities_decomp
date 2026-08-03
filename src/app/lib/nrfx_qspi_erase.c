/*
 * Function: nrfx_qspi_erase
 * Entry:    00069e6c
 * Prototype: nrfx_err_t __stdcall nrfx_qspi_erase(nrf_qspi_erase_len_t length, uint32_t start_address)
 */


/* exclude_from_export */

nrfx_err_t nrfx_qspi_erase(nrf_qspi_erase_len_t length,uint32_t start_address)

{
  nrfx_err_t nVar1;
  
  if (qspi_m_cb.state == NRFX_QSPI_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state != NRFX_QSPI_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",744);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((start_address & 3) == 0) {
    if (qspi_m_cb.handler == (nrfx_qspi_handler_t *)0x0) {
      Peripherals::QSPI_S._1308_4_ = start_address;
      Peripherals::QSPI_S._1312_4_ = (uint)length;
      qspi_m_cb.timeout_signal = false;
      if ((qspi_m_cb.activated) || (nVar1 = qspi_activate(true), nVar1 != 0xbad0007)) {
        Peripherals::QSPI_S.EVENTS_READY = 0;
        Peripherals::QSPI_S.TASKS_ERASESTART = 1;
        nVar1 = qspi_ready_wait();
        return nVar1;
      }
    }
    else if (qspi_m_cb.state == NRFX_QSPI_STATE_IDLE) {
      Peripherals::QSPI_S._1308_4_ = start_address;
      Peripherals::QSPI_S._1312_4_ = (uint)length;
      qspi_m_cb.timeout_signal = false;
      qspi_m_cb.state = NRFX_QSPI_STATE_ERASE;
      Peripherals::QSPI_S.EVENTS_READY = 0;
      Peripherals::QSPI_S.INTENSET = 1;
      if (qspi_m_cb.activated) {
        Peripherals::QSPI_S.TASKS_ERASESTART = 1;
      }
      else {
        qspi_activate(false);
      }
      nVar1 = NRFX_SUCCESS;
    }
    else {
      nVar1 = NRFX_ERROR_BUSY;
    }
  }
  else {
    nVar1 = NRFX_ERROR_INVALID_ADDR;
  }
  return nVar1;
}



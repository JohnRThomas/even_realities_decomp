/*
 * Function: $_qspi_FUN_00069f30
 * Entry:    00069f30
 * Prototype: undefined __stdcall $_qspi_FUN_00069f30(void)
 */


void __qspi_FUN_00069f30(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = Peripherals::QSPI_S.EVENTS_READY;
  if (uVar1 == 0) {
    return;
  }
  Peripherals::QSPI_S.EVENTS_READY = 0;
  if (!qspi_m_cb.activated) {
    if (qspi_m_cb.state == NRFX_QSPI_STATE_READ) {
      Peripherals::QSPI_S.TASKS_READSTART = 1;
      qspi_m_cb.activated = true;
      return;
    }
    if (qspi_m_cb.state != NRFX_QSPI_STATE_ERASE) {
      if (qspi_m_cb.state != NRFX_QSPI_STATE_WRITE) {
        qspi_m_cb.activated = true;
        return;
      }
      Peripherals::QSPI_S.TASKS_WRITESTART = 1;
      qspi_m_cb.activated = true;
      return;
    }
    Peripherals::QSPI_S.TASKS_ERASESTART = 1;
    qspi_m_cb.activated = true;
    return;
  }
  if (qspi_m_cb.state == NRFX_QSPI_STATE_READ) {
    qspi_m_cb.evt_ext.type._0_1_ = NRFX_QSPI_EVENT_READ_DONE;
  }
  else {
    if (qspi_m_cb.state == NRFX_QSPI_STATE_ERASE) {
      qspi_m_cb.evt_ext.type._0_1_ = NRFX_QSPI_EVENT_ERASE_DONE;
      qspi_m_cb.evt_ext.data.xfer.p_buffer = (void *)Peripherals::QSPI_S._1308_4_;
      uVar2 = Peripherals::QSPI_S._1312_4_;
      qspi_m_cb.evt_ext.data.erase.len = (nrf_qspi_erase_len_t)uVar2;
      goto LAB_00069f80;
    }
    if (qspi_m_cb.state != NRFX_QSPI_STATE_WRITE) goto LAB_00069f80;
    qspi_m_cb.evt_ext.type._0_1_ = NRFX_QSPI_EVENT_WRITE_DONE;
  }
  __qspi_FUN_000698ec();
LAB_00069f80:
  if (qspi_m_cb.p_buffer_primary == (void *)0x0) {
    qspi_m_cb.state = NRFX_QSPI_STATE_IDLE;
  }
  if (qspi_m_cb.timeout_signal == false) {
    (*qspi_m_cb.handler)(NRFX_QSPI_EVENT_DONE,qspi_m_cb.p_context);
  }
  qspi_m_cb.evt_ext.type._0_1_ = NRFX_QSPI_EVENT_NONE;
  return;
}



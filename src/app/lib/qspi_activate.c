/*
 * Function: qspi_activate
 * Entry:    00069798
 * Prototype: nrfx_err_t __stdcall qspi_activate(bool wait)
 */


/* exclude_from_export */

nrfx_err_t qspi_activate(bool wait)

{
  nrfx_err_t nVar1;
  
  Peripherals::QSPI_S.ENABLE = 1;
  Peripherals::QSPI_S.EVENTS_READY = 0;
  Peripherals::QSPI_S.TASKS_ACTIVATE = 1;
  if (wait) {
    nVar1 = qspi_ready_wait();
    if ((undefined1 *)(uint)nVar1 != &DAT_0bad0000) {
      return nVar1;
    }
    qspi_m_cb.activated = true;
  }
  return NRFX_SUCCESS;
}



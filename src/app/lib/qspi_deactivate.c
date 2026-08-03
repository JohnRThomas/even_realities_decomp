/*
 * Function: qspi_deactivate
 * Entry:    00069720
 * Prototype: void __stdcall qspi_deactivate(void)
 */


/* exclude_from_export */

void qspi_deactivate(void)

{
  qspi_m_cb.activated = false;
  Peripherals::QSPI_S.INTENCLR = 1;
  Peripherals::QSPI_S.TASKS_DEACTIVATE = 1;
  Peripherals::QSPI_S.ENABLE = 0;
  Peripherals::QSPI_S.EVENTS_READY = 0;
  return;
}



/*
 * Function: qspi_ready_wait
 * Entry:    00069744
 * Prototype: nrfx_err_t __stdcall qspi_ready_wait(void)
 */


/* exclude_from_export */

nrfx_err_t qspi_ready_wait(void)

{
  uint uVar1;
  undefined **ppuVar2;
  
  if (qspi_m_cb.timeout == 0) {
    ppuVar2 = &PTR_arch_isr_direct_footer_1_0000c350;
  }
  else {
    ppuVar2 = (undefined **)((qspi_m_cb.timeout * 1000) / 10);
  }
  while ((uVar1 = Peripherals::QSPI_S.EVENTS_READY, uVar1 == 0 &&
         (qspi_m_cb.timeout_signal == false))) {
    arch_busy_wait(10);
    ppuVar2 = (undefined **)((int)ppuVar2 - 1);
    if (ppuVar2 == (undefined **)0x0) {
      return NRFX_ERROR_TIMEOUT;
    }
  }
  if (qspi_m_cb.timeout_signal != false) {
    return NRFX_ERROR_TIMEOUT;
  }
  return NRFX_SUCCESS;
}



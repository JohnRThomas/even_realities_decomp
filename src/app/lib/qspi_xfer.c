/*
 * Function: qspi_xfer
 * Entry:    000697cc
 * Prototype: nrfx_err_t __stdcall qspi_xfer(void * p_buffer, size_t length, uint32_t address, nrfx_qspi_state_t desired_state)
 */


/* exclude_from_export */

nrfx_err_t qspi_xfer(void *p_buffer,size_t length,uint32_t address,nrfx_qspi_state_t desired_state)

{
  void *pvVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  nrfx_err_t nVar4;
  int iVar5;
  
  if (qspi_m_cb.state == NRFX_QSPI_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state != NRFX_QSPI_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",122);
  }
  else {
    if (p_buffer != (void *)0x0) {
      if ((((uint)p_buffer & 0xe0000000) == 0x20000000) && (((uint)p_buffer & 3) == 0)) {
        if ((qspi_m_cb.state == NRFX_QSPI_STATE_IDLE) ||
           ((qspi_m_cb.state == desired_state && (qspi_m_cb.activated)))) {
          if (desired_state == NRFX_QSPI_STATE_WRITE) {
            Peripherals::QSPI_S._1296_4_ = address;
            Peripherals::QSPI_S._1300_4_ = p_buffer;
            Peripherals::QSPI_S._1304_4_ = length;
          }
          else {
            Peripherals::QSPI_S._1284_4_ = address;
            Peripherals::QSPI_S._1288_4_ = p_buffer;
            Peripherals::QSPI_S._1292_4_ = length;
          }
          qspi_m_cb.timeout_signal = false;
          if (desired_state == NRFX_QSPI_STATE_WRITE) {
            iVar5 = 8;
          }
          else {
            iVar5 = 4;
          }
          if (qspi_m_cb.handler == (nrfx_qspi_handler_t *)0x0) {
            if ((qspi_m_cb.activated) || (nVar4 = qspi_activate(true), nVar4 != 0xbad0007)) {
              Peripherals::QSPI_S.EVENTS_READY = 0;
              *(undefined4 *)((int)&Peripherals::QSPI_S.TASKS_ACTIVATE + iVar5) = 1;
              nVar4 = qspi_ready_wait();
              return nVar4;
            }
          }
          else {
            pvVar1 = p_buffer;
            uVar2 = length;
            uVar3 = address;
            if (qspi_m_cb.p_buffer_primary == (void *)0x0) {
              Peripherals::QSPI_S.EVENTS_READY = 0;
              Peripherals::QSPI_S.INTENSET = 1;
              qspi_m_cb.p_buffer_primary = p_buffer;
              qspi_m_cb.size_primary = length;
              qspi_m_cb.addr_primary = address;
              qspi_m_cb.state = desired_state;
              if (qspi_m_cb.activated) {
                *(undefined4 *)((int)&Peripherals::QSPI_S.TASKS_ACTIVATE + iVar5) = 1;
                pvVar1 = qspi_m_cb.p_buffer_secondary;
                uVar2 = qspi_m_cb.size_secondary;
                uVar3 = qspi_m_cb.addr_secondary;
              }
              else {
                qspi_activate(false);
                pvVar1 = qspi_m_cb.p_buffer_secondary;
                uVar2 = qspi_m_cb.size_secondary;
                uVar3 = qspi_m_cb.addr_secondary;
              }
            }
            qspi_m_cb.addr_secondary = uVar3;
            qspi_m_cb.size_secondary = uVar2;
            qspi_m_cb.p_buffer_secondary = pvVar1;
            nVar4 = NRFX_SUCCESS;
          }
        }
        else {
          nVar4 = NRFX_ERROR_BUSY;
        }
      }
      else {
        nVar4 = NRFX_ERROR_INVALID_ADDR;
      }
      return nVar4;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_buffer != ((void *)0)",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_qspi.c",123);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



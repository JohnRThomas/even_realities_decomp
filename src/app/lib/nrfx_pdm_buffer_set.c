/*
 * Function: nrfx_pdm_buffer_set
 * Entry:    00069518
 * Prototype: nrfx_err_t __stdcall nrfx_pdm_buffer_set(int16_t * buffer, uint16_t buffer_length)
 */


/* exclude_from_export */

nrfx_err_t nrfx_pdm_buffer_set(int16_t *buffer,uint16_t buffer_length)

{
  uint uVar1;
  nrfx_err_t nVar2;
  
  if (nrfx_pdm_m_cb.drv_state == NRFX_DRV_STATE_UNINITIALIZED) {
    nVar2 = NRFX_ERROR_INVALID_STATE;
  }
  else if (nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_STOPPING) {
    nVar2 = NRFX_ERROR_BUSY;
  }
  else if ((buffer == (int16_t *)0x0) || ((int)((uint)buffer_length << 0x10) < 0)) {
    nVar2 = NRFX_ERROR_INVALID_PARAM;
  }
  else {
    arch_irq_disable(0x26);
    if (nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_STARTING) {
      uVar1 = 0;
    }
    else {
      uVar1 = ~(uint)nrfx_pdm_m_cb.active_buffer & 1;
    }
    if (nrfx_pdm_m_cb.buff_address[uVar1] == (int16_t *)0x0) {
      nrfx_pdm_m_cb.buff_length[uVar1] = buffer_length;
      nrfx_pdm_m_cb.buff_address[uVar1] = buffer;
      DAT_50026560 = buffer;
      DAT_50026564 = (uint)buffer_length;
      if (nrfx_pdm_m_cb.drv_state != NRFX_DRV_STATE_POWERED_ON) {
        nrfx_pdm_m_cb.drv_state = NRFX_DRV_STATE_POWERED_ON;
        Peripherals::PDM0_S.ENABLE = 1;
        Peripherals::PDM0_S.TASKS_START = 1;
      }
      nVar2 = NRFX_SUCCESS;
    }
    else {
      nVar2 = NRFX_ERROR_BUSY;
    }
    arch_irq_enable(0x26);
  }
  return nVar2;
}



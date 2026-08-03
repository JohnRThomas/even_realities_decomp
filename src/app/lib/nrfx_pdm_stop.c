/*
 * Function: nrfx_pdm_stop
 * Entry:    000695a8
 * Prototype: nrfx_err_t __stdcall nrfx_pdm_stop(void)
 */


/* exclude_from_export */

nrfx_err_t nrfx_pdm_stop(void)

{
  nrfx_drv_state_t nVar1;
  
  if (nrfx_pdm_m_cb.drv_state == NRFX_DRV_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.drv_state != NRFX_DRV_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_pdm.c",306);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  nVar1 = nrfx_pdm_m_cb.op_state;
  if (nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_RUNNING) {
    nrfx_pdm_m_cb.op_state = NRFX_PDM_STATE_STOPPING;
    Peripherals::PDM0_S.TASKS_STOP = 1;
    nrfx_pdm_m_cb.drv_state = nVar1;
  }
  else {
    if ((nrfx_pdm_m_cb.op_state != NRFX_PDM_STATE_IDLE) &&
       (nrfx_pdm_m_cb.op_state != NRFX_PDM_STATE_STARTING)) {
      return NRFX_ERROR_BUSY;
    }
    Peripherals::PDM0_S.ENABLE = 0;
    nrfx_pdm_m_cb.op_state = NRFX_PDM_STATE_IDLE;
  }
  return NRFX_SUCCESS;
}



/*
 * Function: nrfx_pdm_start
 * Entry:    000694bc
 * Prototype: nrfx_err_t __stdcall nrfx_pdm_start(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

nrfx_err_t nrfx_pdm_start(void)

{
  if (nrfx_pdm_m_cb.drv_state == NRFX_DRV_STATE_UNINITIALIZED) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.drv_state != NRFX_DRV_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_pdm.c",221);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_IDLE) {
    nrfx_pdm_m_cb.op_state = NRFX_PDM_STATE_STARTING;
    nrfx_pdm_m_cb.irq_buff_request = '\x01';
    _DAT_e000e204 = 0x40;
  }
  else if (nrfx_pdm_m_cb.op_state != NRFX_PDM_STATE_RUNNING) {
    return NRFX_ERROR_BUSY;
  }
  return NRFX_SUCCESS;
}



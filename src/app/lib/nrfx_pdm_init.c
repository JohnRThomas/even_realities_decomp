/*
 * Function: nrfx_pdm_init
 * Entry:    00069404
 * Prototype: nrfx_err_t __stdcall nrfx_pdm_init(nrfx_pdm_config_t * p_config, nrfx_pdm_event_handler_t * event_handler)
 */


/* exclude_from_export */

nrfx_err_t nrfx_pdm_init(nrfx_pdm_config_t *p_config,nrfx_pdm_event_handler_t *event_handler)

{
  nrfx_err_t nVar1;
  int16_t *piVar2;
  
  if (p_config == (nrfx_pdm_config_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_pdm.c",120);
  }
  else {
    if (event_handler != (nrfx_pdm_event_handler_t *)0x0) {
      piVar2 = (int16_t *)(uint)nrfx_pdm_m_cb.drv_state;
      if (piVar2 == (int16_t *)0x0) {
        nrfx_pdm_m_cb._18_2_ = ZEXT12(nrfx_pdm_m_cb.drv_state);
        nrfx_pdm_m_cb.op_state = nrfx_pdm_m_cb.drv_state;
        nrfx_pdm_m_cb.skip_gpio_cfg = *(bool *)((int)p_config + 0x15);
        nrfx_pdm_m_cb.event_handler = event_handler;
        nrfx_pdm_m_cb.buff_address[0] = piVar2;
        nrfx_pdm_m_cb.buff_address[1] = piVar2;
        if (((byte)p_config[4] < 0x51) && (*(byte *)((int)p_config + 0x11) < 0x51)) {
          pdm_configure(p_config);
          nVar1 = NRFX_SUCCESS;
          nrfx_pdm_m_cb.drv_state = NRFX_DRV_STATE_INITIALIZED;
        }
        else {
          nVar1 = NRFX_ERROR_INVALID_PARAM;
        }
      }
      else {
        nVar1 = NRFX_ERROR_INVALID_STATE;
      }
      return nVar1;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event_handler",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_pdm.c",0x79);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}



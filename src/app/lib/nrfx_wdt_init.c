/*
 * Function: nrfx_wdt_init
 * Entry:    0006b0a4
 * Prototype: nrfx_err_t __stdcall nrfx_wdt_init(nrfx_wdt_t * p_instance, nrfx_wdt_config_t * p_config, nrfx_wdt_event_handler_t * wdt_event_handler)
 */


/* exclude_from_export_ai */

nrfx_err_t
nrfx_wdt_init(nrfx_wdt_t *p_instance,nrfx_wdt_config_t *p_config,
             nrfx_wdt_event_handler_t *wdt_event_handler)

{
  byte bVar1;
  nrfx_err_t nVar2;
  
  bVar1 = (byte)p_instance[1];
  (&wdt_m_cb)[bVar1].wdt_event_handler = wdt_event_handler;
  if ((&wdt_m_cb.state)[bVar1] == NRFX_DRV_STATE_UNINITIALIZED) {
    (&wdt_m_cb.state)[bVar1] = NRFX_DRV_STATE_INITIALIZED;
    if (p_config != (nrfx_wdt_config_t *)0x0) {
      wdt_configure(p_instance,p_config);
    }
    nVar2 = NRFX_SUCCESS;
  }
  else {
    nVar2 = NRFX_ERROR_INVALID_STATE;
  }
  return nVar2;
}



/*
 * Function: ?_get_dashboard_tx_ctx
 * Entry:    00080724
 * Prototype: dashboard_ts_context * __stdcall ?_get_dashboard_tx_ctx(void)
 */


dashboard_ts_context * __get_dashboard_tx_ctx(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return *(dashboard_ts_context **)pGVar1->dashboard_ts;
}



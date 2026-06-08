/*
 * Function: get_jdb_panel_context
 * Entry:    00080bb4
 * Prototype: jdb_panel_context * __stdcall get_jdb_panel_context(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

jdb_panel_context * get_jdb_panel_context(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return &pGVar1->jdb_panel_context;
}



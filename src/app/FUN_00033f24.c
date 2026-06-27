/*
 * Function: FUN_00033f24
 * Entry:    00033f24
 * Prototype: undefined __stdcall FUN_00033f24(void)
 */


void FUN_00033f24(void)

{
  GlassesState *pGVar1;
  uint extraout_r1;
  
  __enter_silent_mode();
  DAT_2001abc0 = 0;
  DAT_2001abc1 = 0;
  pGVar1 = __get_dashboard_state();
  (pGVar1->jdb_panel_context).field834_0x369 = 0x15;
  pGVar1 = __get_dashboard_state();
  set_brightness_to_panel_reg_in_running
            ((uint)(pGVar1->jdb_panel_context).field834_0x369,extraout_r1);
  return;
}



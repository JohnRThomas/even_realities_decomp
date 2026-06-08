/*
 * Function: ?_exit_silent_mode
 * Entry:    0002acdc
 * Prototype: undefined __stdcall ?_exit_silent_mode(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void __exit_silent_mode(void)

{
  GlassesState *pGVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  
  if (DAT_2001c4e0 != '\0') {
    DAT_2001c4e0 = '\0';
  }
  change_work_mode(2);
  pGVar1 = __get_dashboard_state();
  global_system_resume((int)pGVar1,extraout_r1,extraout_r2);
  pGVar1 = __get_dashboard_state();
  *(undefined1 *)&(pGVar1->jdb_panel_context).field850_0x37c = 2;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xd5 = 3;
  pGVar1 = __get_dashboard_state();
  FUN_00080fca(pGVar1->field_0xd5,extraout_r1_00,extraout_r2_00);
  DAT_20019a59 = 1;
  return;
}



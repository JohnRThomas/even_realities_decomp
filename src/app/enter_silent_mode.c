/*
 * Function: ?_enter_silent_mode
 * Entry:    0002ad28
 * Prototype: undefined __stdcall ?_enter_silent_mode(void)
 */


void __enter_silent_mode(void)

{
  GlassesState *pGVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  
  pGVar1 = __get_dashboard_state();
  *(undefined1 *)&pGVar1->imu_fusion_context = 1;
  display_close_screen(3,extraout_r1);
  pGVar1 = __get_dashboard_state();
  pGVar1->field20_0xc8[0xd] = 0;
  FUN_0004b340();
  pGVar1 = __get_dashboard_state();
  global_system_suspend((int)pGVar1,extraout_r1_00,extraout_r2);
  DAT_20019a59 = 0;
  return;
}



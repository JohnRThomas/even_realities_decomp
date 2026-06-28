/*
 * Function: FUN_00033e44
 * Entry:    00033e44
 * Prototype: undefined __stdcall FUN_00033e44(void)
 */


void FUN_00033e44(void)

{
  GlassesState *pGVar1;
  GlassesState *pGVar2;
  uint extraout_r1;
  undefined8 uVar3;
  
  __exit_silent_mode();
  DAT_2001abc0 = 1;
  DAT_2001abc1 = 1;
  pGVar1 = __get_dashboard_state();
  (pGVar1->jdb_panel_context).panel_brightness_level = 1;
  pGVar1 = __get_dashboard_state();
  set_brightness_to_panel_reg_in_running
            ((uint)(pGVar1->jdb_panel_context).panel_brightness_level,extraout_r1);
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x10a8 = pGVar1->field_0x10a8 + '\x01';
  pGVar1 = __get_dashboard_state();
  pGVar2 = __get_dashboard_state();
  pGVar2->field_0x10a9 = pGVar1->field_0xfc4;
  uVar3 = FUN_00080638();
  pGVar1 = __get_dashboard_state();
  uVar3 = __aeabi_ldivmod((uint)uVar3,(uint)((ulonglong)uVar3 >> 0x20),1000,0);
  *(int *)&pGVar1->field_0x10ac = (int)uVar3;
  pGVar1 = __get_dashboard_state();
  pGVar1->field2802_0x10b4 = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field2803_0x10b8 = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field2804_0x10bc = 0;
  pGVar1->field2805_0x10c0 = 0;
  pGVar1->field2806_0x10c4 = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x10c8 = 0;
  pGVar1 = __get_dashboard_state();
  *(undefined4 *)&pGVar1->field_0x10cc = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x10d0 = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x10d1 = 0;
  pGVar1 = __get_dashboard_state();
  __save_sys_settings(pGVar1);
  return;
}



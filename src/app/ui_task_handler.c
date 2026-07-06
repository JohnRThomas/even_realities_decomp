/*
 * Function: ?_ui_task_handler
 * Entry:    0004c13c
 * Prototype: int __stdcall ?_ui_task_handler(GlassesState * param_1, int param_2, undefined4 param_3, uint param_4)
 */


int __ui_task_handler(GlassesState *param_1,int param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  jbd_panel_context *pjVar2;
  int iVar3;
  int extraout_r3;
  
  cVar1 = FUN_00033d5c();
  if (cVar1 == '\x01') {
    if (param_2 == 3) {
      FUN_00038270(&param_1->jdb_panel_context,param_3,param_4,extraout_r3);
    }
    return 0;
  }
  pjVar2 = &param_1->jdb_panel_context;
  DAT_2000aa78 = param_2;
  switch(param_2) {
  case 4:
    iVar3 = ui_ancs_notificaton_task_0((int)pjVar2,param_3,param_4);
    return iVar3;
  case 5:
    iVar3 = ui_new_message_come_on_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 6:
    iVar3 = __ui_DashBoard_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 7:
    iVar3 = __ui_bitmap_task((int)pjVar2,param_3,param_4);
    return iVar3;
  default:
                    /* WARNING: Could not recover jumptable at 0x0004c230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)(param_1->jdb_panel_context).a_unknown_panel_cb)
                      (pjVar2,param_1->field20_0xc8[0xd],param_1->field20_0xc8 + 0xc);
    return iVar3;
  case 9:
    iVar3 = ui_teleprompter_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 10:
    iVar3 = ui_navigation_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0xb:
    iVar3 = ui_translate_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0xc:
    iVar3 = ui_QuickNote_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0xe:
    iVar3 = ui_onboarding_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0xf:
    iVar3 = ui_raster_height_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0x10:
    iVar3 = ui_even_ai_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0x11:
    iVar3 = ui_set_imu_pitch_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0x12:
    iVar3 = ui_prompt_info_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0x13:
    iVar3 = ui_transcribe_info_task((int)pjVar2,param_3,param_4);
    return iVar3;
  case 0x14:
    iVar3 = ui_even_ai_v2_info_task((int)pjVar2,param_3,param_4);
    return iVar3;
  }
}



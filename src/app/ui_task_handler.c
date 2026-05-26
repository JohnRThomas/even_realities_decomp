/*
 * Function: ?_ui_task_handler
 * Entry:    0004c13c
 * Prototype: int __stdcall ?_ui_task_handler(int param_1, int param_2, char * param_3, uint param_4)
 */


int __ui_task_handler(int param_1,int param_2,char *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int extraout_r3;
  
  cVar1 = FUN_00033d5c();
  if (cVar1 == '\x01') {
    if (param_2 == 3) {
      FUN_00038270(param_1 + 0xb6c,param_3,param_4,extraout_r3);
    }
    return 0;
  }
  iVar2 = param_1 + 0xb6c;
  DAT_2000aa78 = param_2;
  switch(param_2) {
  case 4:
    iVar2 = ui_ancs_notificaton_task_0(iVar2,param_3,param_4);
    return iVar2;
  case 5:
    iVar2 = ui_new_message_come_on_task(iVar2,param_3,param_4);
    return iVar2;
  case 6:
    iVar2 = __ui_DashBoard_task(iVar2,param_3,param_4);
    return iVar2;
  case 7:
    iVar2 = __ui_bitmap_task(iVar2,param_3,param_4);
    return iVar2;
  default:
                    /* WARNING: Could not recover jumptable at 0x0004c230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (**(code **)(param_1 + 0xb80))(iVar2,*(undefined1 *)(param_1 + 0xd5),param_1 + 0xd4);
    return iVar2;
  case 9:
    iVar2 = ui_teleprompter_task(iVar2,param_3,param_4);
    return iVar2;
  case 10:
    iVar2 = ui_navigation_task(iVar2,param_3,param_4);
    return iVar2;
  case 0xb:
    iVar2 = ui_translate_task(iVar2,param_3,param_4);
    return iVar2;
  case 0xc:
    iVar2 = ui_QuickNote_task(iVar2,param_3,param_4);
    return iVar2;
  case 0xe:
    iVar2 = ui_onboarding_task(iVar2,param_3,param_4);
    return iVar2;
  case 0xf:
    iVar2 = ui_raster_height_task(iVar2,param_3,param_4);
    return iVar2;
  case 0x10:
    iVar2 = ui_even_ai_task(iVar2,param_3,param_4);
    return iVar2;
  case 0x11:
    iVar2 = ui_set_imu_pitch_task(iVar2,param_3,param_4);
    return iVar2;
  case 0x12:
    iVar2 = ui_prompt_info_task(iVar2,param_3,param_4);
    return iVar2;
  case 0x13:
    iVar2 = ui_transcribe_info_task(iVar2,param_3,param_4);
    return iVar2;
  case 0x14:
    iVar2 = ui_even_ai_v2_info_task(iVar2,param_3,param_4);
    return iVar2;
  }
}



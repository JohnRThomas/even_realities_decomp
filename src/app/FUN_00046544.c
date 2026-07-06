/*
 * Function: FUN_00046544
 * Entry:    00046544
 * Prototype: undefined __stdcall FUN_00046544(undefined4 param_1, char * param_2, undefined4 param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9)
 */


void FUN_00046544(undefined4 param_1,char *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,uint param_8,uint param_9)

{
  int *piVar1;
  int x_end;
  ushort uVar2;
  int iVar3;
  GlassesState *pGVar4;
  int y_end;
  int y_start;
  uint32_t uVar5;
  int local_4c [10];
  
  x_end = param_6;
  uVar2 = FUN_00080a3a();
  if (uVar2 < 0x21) {
    iVar3 = FUN_000452e4();
    y_start = param_5 + 0x1b;
    y_end = param_7 + 0x1b;
    if (iVar3 << 0x1e < 0) {
      _clean_fb_data(__frame_buffer,0,param_4,y_start,param_6,y_end);
    }
    __clear_showing_notification_on_gui();
    gui_utf_draw(0,param_2,0,param_4,y_start,param_6,y_end,param_8,param_9,0,(undefined *)0x0,0);
    __set_showing_notification_on_gui();
    iVar3 = 0;
    do {
      local_4c[0] = 3;
      local_4c[1] = 6;
      local_4c[2] = 9;
      local_4c[3] = 0xc;
      local_4c[4] = 0xf;
      local_4c[5] = 0x12;
      local_4c[6] = 0x15;
      local_4c[7] = 0x18;
      local_4c[8] = 0x1b;
      pGVar4 = __get_dashboard_state();
      uVar5 = (pGVar4->jdb_panel_context).current_row;
      pGVar4 = __get_dashboard_state();
      piVar1 = local_4c + iVar3;
      iVar3 = iVar3 + 1;
      _reflash_fb_data_to_lcd_ex
                (uVar5,(pGVar4->jdb_panel_context).current_column,param_4,param_5,param_6,param_7,
                 *piVar1);
    } while (iVar3 != 9);
    FUN_00080cba((int)__frame_buffer,param_4,param_5,param_4,y_start,0x1b,param_6 - param_4);
    iVar3 = FUN_000452e4();
    param_6 = y_end;
    if (iVar3 << 0x1e < 0) {
LAB_00046630:
      _clean_fb_data(__frame_buffer,0,param_4,param_7,x_end,param_6);
      return;
    }
  }
  else {
    uVar2 = FUN_00080a3a();
    if (0x20 < uVar2) {
      FUN_00080cba((int)__frame_buffer,param_4,param_5 + -0x1b,param_4,param_5,0x1b,
                   param_6 - param_4);
      iVar3 = FUN_000452e4();
      if (iVar3 << 0x1e < 0) {
        _clean_fb_data(__frame_buffer,0,param_4,param_5,param_6,param_7);
      }
      __clear_showing_notification_on_gui();
      gui_utf_draw(0,param_2,0,param_4,param_5,param_6,param_7,param_8,param_9,0,(undefined *)0x0,0)
      ;
      iVar3 = 0;
      __set_showing_notification_on_gui();
      do {
        local_4c[0] = -0x1b;
        local_4c[1] = 0xffffffeb;
        local_4c[2] = 0xffffffee;
        local_4c[3] = 0xfffffff1;
        local_4c[4] = 0xfffffff4;
        local_4c[5] = 0xfffffff7;
        local_4c[6] = 0xfffffffa;
        local_4c[7] = 0xfffffffd;
        local_4c[8] = 0;
        pGVar4 = __get_dashboard_state();
        uVar5 = (pGVar4->jdb_panel_context).current_row;
        pGVar4 = __get_dashboard_state();
        piVar1 = local_4c + iVar3;
        iVar3 = iVar3 + 1;
        _reflash_fb_data_to_lcd_ex
                  (uVar5,(pGVar4->jdb_panel_context).current_column,param_4,param_5,param_6,param_7,
                   *piVar1);
      } while (iVar3 != 9);
      iVar3 = FUN_000452e4();
      if (iVar3 << 0x1e < 0) {
        param_6 = param_5;
        param_7 = param_5 + -0x1b;
        goto LAB_00046630;
      }
    }
  }
  return;
}



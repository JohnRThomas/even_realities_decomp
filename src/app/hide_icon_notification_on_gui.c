/*
 * Function: ?_hide_icon_notification_on_gui
 * Entry:    00045a0c
 * Prototype: undefined4 __stdcall ?_hide_icon_notification_on_gui(void)
 */


undefined4 __hide_icon_notification_on_gui(void)

{
  byte bVar1;
  byte *pbVar2;
  GlassesState *pGVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint32_t uVar7;
  
  iVar5 = 0;
  do {
    pbVar2 = __frame_buffer;
    uVar6 = 0;
    do {
      iVar4 = 0;
      do {
        bVar1 = *(byte *)(*(int *)(pbVar2 + uVar6 * 4) + iVar4);
        if (bVar1 != 0) {
          *(byte *)(*(int *)(pbVar2 + uVar6 * 4) + iVar4) =
               bVar1 & (&DAT_000ad56b)[iVar4 + (uVar6 % 0x1a) * 0xa00 + iVar5];
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 320);
      uVar6 = uVar6 + 1;
    } while (uVar6 != 199);
    pGVar3 = __get_dashboard_state();
    uVar7 = (pGVar3->jdb_panel_context).current_row;
    pGVar3 = __get_dashboard_state();
    iVar5 = iVar5 + -320;
    _reflash_fb_data_to_lcd(uVar7,(pGVar3->jdb_panel_context).current_column,0,0,640,199);
  } while (iVar5 != -2560);
  gui_screen_clear();
  return 0;
}



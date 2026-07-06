/*
 * Function: FUN_00045968
 * Entry:    00045968
 * Prototype: undefined4 __stdcall FUN_00045968(void)
 */


undefined4 FUN_00045968(void)

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
      } while (iVar4 != 0x140);
      uVar6 = uVar6 + 1;
    } while (uVar6 != 199);
    pGVar3 = __get_dashboard_state();
    uVar7 = (pGVar3->jdb_panel_context).current_row;
    pGVar3 = __get_dashboard_state();
    _reflash_fb_data_to_lcd(uVar7,(pGVar3->jdb_panel_context).current_column,0,0,0x280,199);
    iVar5 = iVar5 + -0x140;
    arch_busy_wait(5000);
  } while (iVar5 != -0xa00);
  gui_screen_clear();
  return 0;
}



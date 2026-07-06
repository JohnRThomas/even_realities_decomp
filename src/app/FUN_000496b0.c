/*
 * Function: FUN_000496b0
 * Entry:    000496b0
 * Prototype: undefined4 __stdcall FUN_000496b0(byte * param_1, int param_2)
 */


undefined4 FUN_000496b0(byte *param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  dashboard_ts_context *pdVar5;
  int iVar6;
  int iVar7;
  GlassesState *pGVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  
  pGVar4 = __get_dashboard_state();
  if (pGVar4->field20_0xc8[0x29] == '\x01') {
    pdVar5 = (dashboard_ts_context *)FUN_00080732();
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    pGVar8 = __get_dashboard_state();
    gui_clock_draw(pdVar5,iVar6,uVar2 + 2,iVar7 + 0x50,uVar3 + 0x1d,3,
                   (char)pGVar8->dashboard_ts->time_disp_mode != '\x01');
    bVar1 = pGVar4->field20_0xc8[0x2b];
    if ((bVar1 & 1) == 0) {
      FUN_00045444();
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _clean_fb_data(param_1,bVar1 & 1,iVar6,uVar2 + 0x3a,iVar7 + 0x14,uVar3 + 0x54);
      pGVar8 = __get_dashboard_state();
      uVar9 = (pGVar8->jdb_panel_context).current_row;
      pGVar8 = __get_dashboard_state();
      uVar10 = (pGVar8->jdb_panel_context).current_column;
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(uVar9,uVar10,iVar6,uVar2 + 0x3a,iVar7 + 0x14,uVar3 + 0x54);
    }
    else {
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(1,iVar6,uVar2 + 0x3a);
    }
  }
  if ((DAT_20004dc0 == '\0') || (param_2 == 1)) {
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    gui_utf_draw_darkword_by_lines
              (0,pGVar4->field20_0xc8 + 0x2f,0,iVar6 + 0x58,(uint)uVar2,iVar7 + 0x240,uVar3 + 0x88,5
               ,pGVar4->field20_0xc8[0x2c],0,(undefined *)0x0,0);
  }
  return 0;
}



/*
 * Function: FUN_0003e10c
 * Entry:    0003e10c
 * Prototype: undefined4 __stdcall FUN_0003e10c(byte * param_1)
 */


undefined4 FUN_0003e10c(byte *param_1)

{
  ushort uVar1;
  int iVar2;
  GlassesState *pGVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_1;
  if (uVar5 < 6) {
    if (DAT_200024f4 != 1) {
      FUN_00045444();
      DAT_200024f4 = 1;
      iVar2 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      FUN_00045460(iVar2,uVar1 + 0x36);
      pGVar3 = __get_dashboard_state();
      iVar2 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
      pGVar3 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar2,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,0,0,0x280,199);
    }
    iVar2 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar4 = uVar1 + 0x36;
    uVar5 = 1;
  }
  else if (uVar5 == 6) {
    if (DAT_200024f4 != 9) {
      FUN_00045444();
      DAT_200024f4 = 9;
      iVar2 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      FUN_00045460(iVar2,uVar1 + 0x36);
      pGVar3 = __get_dashboard_state();
      iVar2 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
      pGVar3 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar2,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,0,0,0x280,199);
    }
    iVar2 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar4 = uVar1 + 0x36;
    uVar5 = 9;
  }
  else {
    if (uVar5 != 7) {
      if (uVar5 < 0xc) {
        if (DAT_200024f4 == 0xff) {
          return 0;
        }
        FUN_00045444();
        DAT_200024f4 = 0xff;
        iVar2 = FUN_000809e2();
        uVar1 = FUN_00080a3a();
        FUN_00045460(iVar2,uVar1 + 0x36);
        pGVar3 = __get_dashboard_state();
        iVar2 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
        pGVar3 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar2,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,0,0,0x280,199);
        return 0;
      }
      if (uVar5 - 0xc < 2) {
        return 0;
      }
      if (uVar5 == 0xf) {
        return 0;
      }
      if ((uVar5 != 0xe) && (uVar5 != 0x10)) {
        return 0;
      }
      if (DAT_200024f4 == 0xff) {
        return 0;
      }
      FUN_00045444();
      DAT_200024f4 = 0xff;
      return 0;
    }
    if (DAT_200024f4 != 4) {
      FUN_00045444();
      DAT_200024f4 = 4;
      iVar2 = FUN_000809e2();
      uVar1 = FUN_00080a3a();
      FUN_00045460(iVar2,uVar1 + 0x36);
      pGVar3 = __get_dashboard_state();
      iVar2 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
      pGVar3 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar2,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,0,0,0x280,199);
    }
    iVar2 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    iVar4 = uVar1 + 0x36;
    uVar5 = 4;
  }
  gui_bmp_dynamic_bitmap_draw(uVar5,iVar2,iVar4);
  return 0;
}



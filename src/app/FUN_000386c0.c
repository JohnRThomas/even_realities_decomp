/*
 * Function: FUN_000386c0
 * Entry:    000386c0
 * Prototype: undefined __stdcall FUN_000386c0(void)
 */


void FUN_000386c0(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  bVar1 = FUN_00028d2c();
  bVar2 = get_current_language();
  if (bVar1) {
    if (DAT_20004b10 != bVar2) {
      DAT_20004b10 = bVar2;
      pGVar5 = __get_dashboard_state();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _clean_fb_data(&(pGVar5->jdb_panel_context).field9_0x24,0,iVar6 + 0x10a,uVar3 + 0x1c,
                     iVar7 + 0x234,uVar4 + 0x88);
      pGVar5 = __get_dashboard_state();
      iVar9 = *(int *)&(pGVar5->jdb_panel_context).field_0x348;
      pGVar5 = __get_dashboard_state();
      iVar10 = *(int *)&(pGVar5->jdb_panel_context).field_0x34c;
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(iVar9,iVar10,iVar6 + 0x10a,uVar3 + 0x1c,iVar7 + 0x234,uVar4 + 0x88);
    }
    pcVar8 = get_string(0x53);
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar7 = iVar7 + 0x234;
    iVar6 = iVar6 + 0x10a;
  }
  else {
    if (DAT_20004b10 != bVar2) {
      DAT_20004b10 = bVar2;
      pGVar5 = __get_dashboard_state();
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _clean_fb_data(&(pGVar5->jdb_panel_context).field9_0x24,0,iVar6 + 0x10a,uVar3 + 0x1c,
                     iVar7 + 0x234,uVar4 + 0x88);
      pGVar5 = __get_dashboard_state();
      iVar9 = *(int *)&(pGVar5->jdb_panel_context).field_0x348;
      pGVar5 = __get_dashboard_state();
      iVar10 = *(int *)&(pGVar5->jdb_panel_context).field_0x34c;
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(iVar9,iVar10,iVar6 + 0x10a,uVar3 + 0x1c,iVar7 + 0x234,uVar4 + 0x88);
    }
    pcVar8 = get_string(0x53);
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar4 = FUN_00080a3a();
    iVar7 = iVar7 + 0x20a;
    iVar6 = iVar6 + 0xe0;
  }
  gui_utf_draw_middle(0,pcVar8,0,iVar6,uVar3 + 0x28,iVar7,uVar4 + 0x5e,2,0,0,(undefined *)0x0,0);
  return;
}



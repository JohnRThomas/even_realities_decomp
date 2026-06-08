/*
 * Function: FUN_000496b0
 * Entry:    000496b0
 * Prototype: undefined4 __stdcall FUN_000496b0(int * param_1, int param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_000496b0(int *param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  GlassesState *pGVar8;
  int iVar9;
  int iVar10;
  
  pGVar4 = __get_dashboard_state();
  if (pGVar4->field_0xf1 == '\x01') {
    uVar5 = FUN_00080732();
    iVar6 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar7 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    pGVar8 = __get_dashboard_state();
    gui_clock_draw(uVar5,iVar6,uVar2 + 2,iVar7 + 0x50,uVar3 + 0x1d,3,
                   pGVar8->glasses_state_struct_0FF0->field_0x5e != '\x01');
    bVar1 = pGVar4->field_0xf3;
    if ((bVar1 & 1) == 0) {
      FUN_00045444();
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _clean_fb_data(param_1,bVar1 & 1,iVar6,uVar2 + 0x3a,iVar7 + 0x14,uVar3 + 0x54);
      pGVar8 = __get_dashboard_state();
      iVar9 = *(int *)&(pGVar8->jdb_panel_context).field_0x348;
      pGVar8 = __get_dashboard_state();
      iVar10 = *(int *)&(pGVar8->jdb_panel_context).field_0x34c;
      iVar6 = FUN_000809e2();
      uVar2 = FUN_00080a3a();
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      _reflash_fb_data_to_lcd(iVar9,iVar10,iVar6,uVar2 + 0x3a,iVar7 + 0x14,uVar3 + 0x54);
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
              (0,&pGVar4->field_0xf7,0,iVar6 + 0x58,(uint)uVar2,iVar7 + 0x240,uVar3 + 0x88,5,
               pGVar4->field_0xf4,0,(undefined *)0x0,0);
  }
  return 0;
}



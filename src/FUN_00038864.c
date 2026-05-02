/*
 * Function: FUN_00038864
 * Entry:    00038864
 * Prototype: undefined __stdcall FUN_00038864(void)
 */


void FUN_00038864(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  
  bVar1 = get_current_language();
  if (DAT_20004b10 != bVar1) {
    DAT_20004b10 = bVar1;
    pGVar4 = __get_dashboard_state();
    iVar5 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    _clean_fb_data((int)&pGVar4->field_0xb90,0,iVar5 + 0xd2,uVar2 + 0x1c,iVar6 + 0x234,uVar3 + 0x88)
    ;
    pGVar4 = __get_dashboard_state();
    iVar8 = *(int *)&pGVar4->field_0xeb4;
    pGVar4 = __get_dashboard_state();
    iVar9 = *(int *)&pGVar4->field_0xeb8;
    iVar5 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    _reflash_fb_data_to_lcd(iVar8,iVar9,iVar5 + 0xd2,uVar2 + 0x1c,iVar6 + 0x234,uVar3 + 0x88);
  }
  pcVar7 = get_string(0x53);
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  iVar6 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  gui_utf_draw_middle(0,pcVar7,0,iVar5 + 0xb8,uVar2 + 0x28,iVar6 + 0x234,uVar3 + 0x5e,2,0,0,
                      (undefined *)0x0,0);
  return;
}



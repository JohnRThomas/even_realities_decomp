/*
 * Function: ?_update_brightness_level_for_jdb_panel
 * Entry:    00080ace
 * Prototype: undefined __stdcall ?_update_brightness_level_for_jdb_panel(uint brightness_level, uint16_t * lum, uint8_t * cur_value)
 */


void __update_brightness_level_for_jdb_panel(uint brightness_level,uint16_t *lum,uint8_t *cur_value)

{
  ushort uVar1;
  byte bVar2;
  ulonglong uVar3;
  GlassesState *pGVar4;
  uint16_t uVar5;
  uint8_t uVar6;
  int iVar7;
  
  if (brightness_level < 6) {
    pGVar4 = __get_dashboard_state();
    uVar3 = ((ulonglong)*(ushort *)&(pGVar4->jdb_panel_context).field831_0x36c << 1) / 9;
    iVar7 = (int)uVar3;
    if ((iVar7 == 0) ||
       (pGVar4 = __get_dashboard_state(), *(ushort *)&(pGVar4->jdb_panel_context).field831_0x36c < 6
       )) {
      pGVar4 = __get_dashboard_state();
      uVar5 = ((short)((brightness_level * 0x6f) / 6) + 1) *
              (*(short *)&(pGVar4->jdb_panel_context).field831_0x36c + 1);
    }
    else {
      pGVar4 = __get_dashboard_state();
      uVar5 = ((short)((int)(brightness_level *
                            ((uint)*(ushort *)&(pGVar4->jdb_panel_context).field831_0x36c - iVar7))
                      / 6) + (short)uVar3) * 0x6f;
    }
    uVar6 = '\0';
  }
  else {
    pGVar4 = __get_dashboard_state();
    uVar6 = (char)brightness_level + 0xfa;
    uVar5 = (*(short *)&(pGVar4->jdb_panel_context).field831_0x36c + 1) * 0x6f;
  }
  *lum = uVar5;
  *cur_value = uVar6;
  pGVar4 = __get_dashboard_state();
  bVar2 = (pGVar4->jdb_panel_context).field_0x374;
  pGVar4 = __get_dashboard_state();
  if (((byte)(pGVar4->jdb_panel_context).field_0x374 < 100) && (0x45 < bVar2)) {
    uVar1 = *lum;
    pGVar4 = __get_dashboard_state();
    *lum = (uint16_t)(((uint)uVar1 * (uint)(byte)(pGVar4->jdb_panel_context).field_0x374) / 100);
  }
  if (*lum == 0) {
    *lum = 1;
  }
  return;
}



/*
 * Function: ?_update_brightness_level_for_jdb_panel
 * Entry:    00080ace
 * Prototype: undefined __stdcall ?_update_brightness_level_for_jdb_panel(uint param_1, ushort * param_2, char * param_3)
 */


void __update_brightness_level_for_jdb_panel(uint param_1,ushort *param_2,char *param_3)

{
  byte bVar1;
  ulonglong uVar2;
  GlassesState *pGVar3;
  ushort uVar4;
  char cVar5;
  int iVar6;
  
  if (param_1 < 6) {
    pGVar3 = __get_dashboard_state();
    uVar2 = ((ulonglong)*(ushort *)&(pGVar3->jdb_panel_context).field_0x36c << 1) / 9;
    iVar6 = (int)uVar2;
    if ((iVar6 == 0) ||
       (pGVar3 = __get_dashboard_state(), *(ushort *)&(pGVar3->jdb_panel_context).field_0x36c < 6))
    {
      pGVar3 = __get_dashboard_state();
      uVar4 = ((short)((param_1 * 0x6f) / 6) + 1) *
              (*(short *)&(pGVar3->jdb_panel_context).field_0x36c + 1);
    }
    else {
      pGVar3 = __get_dashboard_state();
      uVar4 = ((short)((int)(param_1 *
                            ((uint)*(ushort *)&(pGVar3->jdb_panel_context).field_0x36c - iVar6)) / 6
                      ) + (short)uVar2) * 0x6f;
    }
    cVar5 = '\0';
  }
  else {
    pGVar3 = __get_dashboard_state();
    cVar5 = (char)param_1 + -6;
    uVar4 = (*(short *)&(pGVar3->jdb_panel_context).field_0x36c + 1) * 0x6f;
  }
  *param_2 = uVar4;
  *param_3 = cVar5;
  pGVar3 = __get_dashboard_state();
  bVar1 = (pGVar3->jdb_panel_context).field_0x374;
  pGVar3 = __get_dashboard_state();
  if (((byte)(pGVar3->jdb_panel_context).field_0x374 < 100) && (0x45 < bVar1)) {
    uVar4 = *param_2;
    pGVar3 = __get_dashboard_state();
    *param_2 = (ushort)(((uint)uVar4 * (uint)(byte)(pGVar3->jdb_panel_context).field_0x374) / 100);
  }
  if (*param_2 == 0) {
    *param_2 = 1;
  }
  return;
}



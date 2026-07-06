/*
 * Function: FUN_00038270
 * Entry:    00038270
 * Prototype: undefined4 __stdcall FUN_00038270(jbd_panel_context * param_1, undefined4 param_2, int param_3, int param_4)
 */


undefined4 FUN_00038270(jbd_panel_context *param_1,undefined4 param_2,int param_3,int param_4)

{
  GlassesState *pGVar1;
  undefined *puVar2;
  uint uVar3;
  uint32_t uVar4;
  int local_28;
  int local_24;
  
  local_28 = param_3;
  local_24 = param_4;
  if (param_3 == 2) {
    gui_screen_clear();
    INT_200024e8 = -1;
    INT_200024e4 = -1;
    CHAR____200033f7 = -1;
  }
  else if (DAT_2001c4e0 == '\0') {
    pGVar1 = __get_dashboard_state();
    if (((uint)(ushort)pGVar1->field1214_0x108a != INT_200024e8) ||
       (pGVar1 = __get_dashboard_state(), (uint)(ushort)pGVar1->field1215_0x108c != INT_200024e4)) {
      gui_screen_clear();
      uVar3 = 0;
      local_28 = 6;
      local_24 = 5;
      do {
        puVar2 = &DAT_000dbb66;
        switch(uVar3 & 0xff) {
        case 1:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 8;
          goto LAB_00038370;
        case 2:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 8;
          goto LAB_00038390;
        case 3:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x11e;
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 8;
          goto LAB_000383c2;
        case 4:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x11e;
LAB_00038370:
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 0x42;
LAB_000383c2:
          puVar2 = &DAT_000dbb75;
          break;
        case 5:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x11e;
LAB_00038390:
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 0x7b;
          goto LAB_000383c2;
        case 6:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x232;
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 8;
          break;
        case 7:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x232;
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 0x42;
          break;
        case 8:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 0x232;
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 0x7b;
          break;
        default:
          pGVar1 = __get_dashboard_state();
          INT_200024e8 = (ushort)pGVar1->field1214_0x108a + 8;
          pGVar1 = __get_dashboard_state();
          INT_200024e4 = (ushort)pGVar1->field1215_0x108c + 8;
          puVar2 = &DAT_000dbb75;
        }
        __copy_to_frame_buffer
                  ((int)&param_1->__panel_buffer,puVar2,local_28 / 2,local_24,INT_200024e8,
                   INT_200024e4);
        pGVar1 = __get_dashboard_state();
        uVar4 = (pGVar1->jdb_panel_context).current_row;
        pGVar1 = __get_dashboard_state();
        uVar3 = uVar3 + 1;
        _reflash_fb_data_to_lcd
                  (uVar4,(pGVar1->jdb_panel_context).current_column,INT_200024e8,INT_200024e4,
                   local_28 + INT_200024e8,local_24 + INT_200024e4);
      } while (uVar3 != 9);
    }
  }
  else if (CHAR____200033f7 != CHAR____2001c4df) {
    CHAR____200033f7 = CHAR____2001c4df;
    gui_screen_clear();
    INT_200024e8 = 0;
    INT_200024e4 = 0;
    FUN_0004b30c(0,&local_28,&local_24);
    get_demo_image_source((uint)(byte)CHAR____2001c4df);
    pGVar1 = __get_dashboard_state();
    uVar4 = (pGVar1->jdb_panel_context).current_row;
    pGVar1 = __get_dashboard_state();
    _reflash_fb_data_to_lcd
              (uVar4,(pGVar1->jdb_panel_context).current_column,INT_200024e8,INT_200024e4,
               local_28 + INT_200024e8,local_24 + INT_200024e4);
  }
  return 0;
}



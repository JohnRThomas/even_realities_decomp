/*
 * Function: FUN_00038270
 * Entry:    00038270
 * Prototype: undefined4 __stdcall FUN_00038270(int param_1, undefined4 param_2, int param_3, int param_4)
 */


undefined4 FUN_00038270(int param_1,undefined4 param_2,int param_3,int param_4)

{
  GlassesState *pGVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int local_28;
  int local_24;
  
  local_28 = param_3;
  local_24 = param_4;
  if (param_3 == 2) {
    gui_screen_clear(param_1,param_2,2);
    DAT_200024e8 = 0xffffffff;
    DAT_200024e4 = 0xffffffff;
    DAT_200033f7 = 0xff;
  }
  else if (DAT_2001c4e0 == '\0') {
    pGVar1 = __get_dashboard_state();
    pGVar2 = (GlassesState *)&pGVar1->field_0x1000;
    uVar5 = (uint)(ushort)pGVar1->field2765_0x108a;
    uVar3 = extraout_r1;
    if (uVar5 == DAT_200024e8) {
      pGVar2 = __get_dashboard_state();
      uVar5 = (uint)(ushort)pGVar2->field2766_0x108c;
      uVar3 = extraout_r1_00;
      if (uVar5 == DAT_200024e4) {
        return 0;
      }
    }
    gui_screen_clear(pGVar2,uVar3,uVar5);
    uVar5 = 0;
    local_28 = 6;
    local_24 = 5;
    do {
      puVar4 = &DAT_000dbb66;
      switch(uVar5 & 0xff) {
      case 1:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 8;
        goto LAB_00038370;
      case 2:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 8;
        goto LAB_00038390;
      case 3:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x11e;
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 8;
        goto LAB_000383c2;
      case 4:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x11e;
LAB_00038370:
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 0x42;
LAB_000383c2:
        puVar4 = &DAT_000dbb75;
        break;
      case 5:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x11e;
LAB_00038390:
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 0x7b;
        goto LAB_000383c2;
      case 6:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x232;
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 8;
        break;
      case 7:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x232;
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 0x42;
        break;
      case 8:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 0x232;
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 0x7b;
        break;
      default:
        pGVar1 = __get_dashboard_state();
        DAT_200024e8 = (ushort)pGVar1->field2765_0x108a + 8;
        pGVar1 = __get_dashboard_state();
        DAT_200024e4 = (ushort)pGVar1->field2766_0x108c + 8;
        puVar4 = &DAT_000dbb75;
      }
      __copy_to_frame_buffer(param_1 + 0x24,puVar4,local_28 / 2,local_24,DAT_200024e8,DAT_200024e4);
      pGVar1 = __get_dashboard_state();
      iVar6 = *(int *)&(pGVar1->jdb_panel_context).field_0x348;
      pGVar1 = __get_dashboard_state();
      uVar5 = uVar5 + 1;
      _reflash_fb_data_to_lcd
                (iVar6,*(int *)&(pGVar1->jdb_panel_context).field_0x34c,DAT_200024e8,DAT_200024e4,
                 local_28 + DAT_200024e8,local_24 + DAT_200024e4);
    } while (uVar5 != 9);
  }
  else {
    uVar5 = (uint)DAT_200033f7;
    if (uVar5 != DAT_2001c4df) {
      DAT_200033f7 = DAT_2001c4df;
      gui_screen_clear(param_1,uVar5,(uint)DAT_2001c4df);
      DAT_200024e8 = 0;
      DAT_200024e4 = 0;
      FUN_0004b30c(0,&local_28,&local_24);
      get_demo_image_source((uint)DAT_2001c4df);
      pGVar1 = __get_dashboard_state();
      iVar6 = *(int *)&(pGVar1->jdb_panel_context).field_0x348;
      pGVar1 = __get_dashboard_state();
      _reflash_fb_data_to_lcd
                (iVar6,*(int *)&(pGVar1->jdb_panel_context).field_0x34c,DAT_200024e8,DAT_200024e4,
                 local_28 + DAT_200024e8,local_24 + DAT_200024e4);
    }
  }
  return 0;
}



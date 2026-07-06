/*
 * Function: ?_ui_bitmap_task
 * Entry:    0003eeec
 * Prototype: undefined4 __stdcall ?_ui_bitmap_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 __ui_bitmap_task(int param_1,undefined4 param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  GlassesState *pGVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  
  __set_frame_buffer(param_1 + 0x24);
  __set_showing_notification_on_gui();
  if (param_3 == 2) {
    gui_screen_clear();
    pGVar5 = __get_dashboard_state();
    **(undefined1 **)&pGVar5->field_0x1018 = 0;
    DAT_2001c6cb = '\0';
  }
  else if (DAT_2001c6cb == '\0') {
    gui_screen_clear();
    FUN_00045444();
    DAT_2001c6cb = '\x01';
    uVar10 = sys_clock_tick_get();
    pGVar5 = __get_dashboard_state();
    lVar1 = (uVar10 & 0xffffffff) * 1000;
    uVar7 = (int)(uVar10 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    iVar6 = *(int *)&pGVar5->field_0x1018;
    *(uint *)(iVar6 + 3) = (uint)lVar1 >> 0xf | uVar7 * 0x20000;
    cVar2 = DAT_2001c6cc;
    *(uint *)(iVar6 + 7) = uVar7 >> 0xf;
    if (cVar2 == '\x01') {
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(7,iVar6 + 0xd8,uVar3 + 0x3a);
      pcVar8 = get_string(0x27);
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar6 = iVar6 + 0x104;
    }
    else if (cVar2 == '\x02') {
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x49,iVar6,uVar3 + 0x3a,0,0,0);
      pcVar8 = get_string(0x26);
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar6 = iVar6 + 0x58;
    }
    else {
      if (cVar2 != '\0') {
        return 0;
      }
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(6,iVar6 + 200,uVar3 + 0x3a);
      pcVar8 = get_string(0x25);
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar9 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar6 = iVar6 + 0xf4;
    }
    gui_utf_draw(0,pcVar8,0,iVar6,uVar3 + 0x37,iVar9 + 0x240,uVar4 + 0x88,2,0,0,(undefined *)0x0,0);
  }
  else if (DAT_2001c6cb == '\x01') {
    if (DAT_2001c6cc == '\x01') {
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      uVar7 = 7;
      iVar6 = iVar6 + 0xd8;
    }
    else {
      if (DAT_2001c6cc == '\x02') {
        return 0;
      }
      if (DAT_2001c6cc != '\0') {
        pGVar5 = __get_dashboard_state();
        **(undefined1 **)&pGVar5->field_0x1018 = 0;
        return 0;
      }
      iVar6 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      uVar7 = 6;
      iVar6 = iVar6 + 200;
    }
    gui_bmp_dynamic_bitmap_draw(uVar7,iVar6,uVar3 + 0x3a);
  }
  return 0;
}



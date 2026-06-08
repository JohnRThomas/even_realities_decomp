/*
 * Function: ?_ui_bitmap_task
 * Entry:    0003eeec
 * Prototype: undefined4 __stdcall ?_ui_bitmap_task(int param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 __ui_bitmap_task(int param_1,undefined4 param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 uVar5;
  GlassesState *pGVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  ulonglong uVar11;
  
  FUN_000452f0(param_1 + 0x24);
  uVar5 = FUN_0004540c();
  if (param_3 == 2) {
    gui_screen_clear(uVar5,extraout_r1,extraout_r2);
    pGVar6 = __get_dashboard_state();
    **(undefined1 **)&pGVar6->field_0x1018 = 0;
    DAT_2001c6cb = '\0';
  }
  else if (DAT_2001c6cb == '\0') {
    gui_screen_clear(uVar5,extraout_r1,extraout_r2);
    FUN_00045444();
    DAT_2001c6cb = '\x01';
    uVar11 = sys_clock_tick_get();
    pGVar6 = __get_dashboard_state();
    lVar1 = (uVar11 & 0xffffffff) * 1000;
    uVar8 = (int)(uVar11 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    iVar7 = *(int *)&pGVar6->field_0x1018;
    *(uint *)(iVar7 + 3) = (uint)lVar1 >> 0xf | uVar8 * 0x20000;
    cVar2 = DAT_2001c6cc;
    *(uint *)(iVar7 + 7) = uVar8 >> 0xf;
    if (cVar2 == '\x01') {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(7,iVar7 + 0xd8,uVar3 + 0x3a);
      pcVar9 = get_string(0x27);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar7 = iVar7 + 0x104;
    }
    else if (cVar2 == '\x02') {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_bitmap_draw(0x49,iVar7,uVar3 + 0x3a,0,0,0);
      pcVar9 = get_string(0x26);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar7 = iVar7 + 0x58;
    }
    else {
      if (cVar2 != '\0') {
        return 0;
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      gui_bmp_dynamic_bitmap_draw(6,iVar7 + 200,uVar3 + 0x3a);
      pcVar9 = get_string(0x25);
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      iVar10 = FUN_000809e2();
      uVar4 = FUN_00080a3a();
      iVar7 = iVar7 + 0xf4;
    }
    gui_utf_draw(0,pcVar9,0,iVar7,uVar3 + 0x37,iVar10 + 0x240,uVar4 + 0x88,2,0,0,(undefined *)0x0,0)
    ;
  }
  else if (DAT_2001c6cb == '\x01') {
    if (DAT_2001c6cc == '\x01') {
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      uVar8 = 7;
      iVar7 = iVar7 + 0xd8;
    }
    else {
      if (DAT_2001c6cc == '\x02') {
        return 0;
      }
      if (DAT_2001c6cc != '\0') {
        pGVar6 = __get_dashboard_state();
        **(undefined1 **)&pGVar6->field_0x1018 = 0;
        return 0;
      }
      iVar7 = FUN_000809e2();
      uVar3 = FUN_00080a3a();
      uVar8 = 6;
      iVar7 = iVar7 + 200;
    }
    gui_bmp_dynamic_bitmap_draw(uVar8,iVar7,uVar3 + 0x3a);
  }
  return 0;
}



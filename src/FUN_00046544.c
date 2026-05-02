/*
 * Function: FUN_00046544
 * Entry:    00046544
 * Prototype: undefined __stdcall FUN_00046544(undefined4 param_1, char * param_2, undefined4 param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9)
 */


void FUN_00046544(undefined4 param_1,char *param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,uint param_8,uint param_9)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  GlassesState *pGVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4c [10];
  
  iVar2 = param_6;
  uVar3 = FUN_00080a3a();
  if (uVar3 < 0x21) {
    iVar4 = FUN_000452e4();
    iVar7 = param_5 + 0x1b;
    iVar6 = param_7 + 0x1b;
    if (iVar4 << 0x1e < 0) {
      _clean_fb_data(DAT_2000aa14,0,param_4,iVar7,param_6,iVar6);
    }
    FUN_00045428();
    gui_utf_draw(0,param_2,0,param_4,iVar7,param_6,iVar6,param_8,param_9,0,(undefined *)0x0,0);
    FUN_0004540c();
    iVar4 = 0;
    do {
      local_4c[0] = 3;
      local_4c[1] = 6;
      local_4c[2] = 9;
      local_4c[3] = 0xc;
      local_4c[4] = 0xf;
      local_4c[5] = 0x12;
      local_4c[6] = 0x15;
      local_4c[7] = 0x18;
      local_4c[8] = 0x1b;
      pGVar5 = __get_dashboard_state();
      iVar8 = *(int *)&pGVar5->field_0xeb4;
      pGVar5 = __get_dashboard_state();
      piVar1 = local_4c + iVar4;
      iVar4 = iVar4 + 1;
      _reflash_fb_data_to_lcd_ex
                (iVar8,*(int *)&pGVar5->field_0xeb8,param_4,param_5,param_6,param_7,*piVar1);
    } while (iVar4 != 9);
    FUN_00080cba(DAT_2000aa14,param_4,param_5,param_4,iVar7,0x1b,param_6 - param_4);
    iVar4 = FUN_000452e4();
    param_6 = iVar6;
    if (iVar4 << 0x1e < 0) {
LAB_00046630:
      _clean_fb_data(DAT_2000aa14,0,param_4,param_7,iVar2,param_6);
      return;
    }
  }
  else {
    uVar3 = FUN_00080a3a();
    if (0x20 < uVar3) {
      FUN_00080cba(DAT_2000aa14,param_4,param_5 + -0x1b,param_4,param_5,0x1b,param_6 - param_4);
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_4,param_5,param_6,param_7);
      }
      FUN_00045428();
      gui_utf_draw(0,param_2,0,param_4,param_5,param_6,param_7,param_8,param_9,0,(undefined *)0x0,0)
      ;
      iVar4 = 0;
      FUN_0004540c();
      do {
        local_4c[0] = -0x1b;
        local_4c[1] = 0xffffffeb;
        local_4c[2] = 0xffffffee;
        local_4c[3] = 0xfffffff1;
        local_4c[4] = 0xfffffff4;
        local_4c[5] = 0xfffffff7;
        local_4c[6] = 0xfffffffa;
        local_4c[7] = 0xfffffffd;
        local_4c[8] = 0;
        pGVar5 = __get_dashboard_state();
        iVar6 = *(int *)&pGVar5->field_0xeb4;
        pGVar5 = __get_dashboard_state();
        piVar1 = local_4c + iVar4;
        iVar4 = iVar4 + 1;
        _reflash_fb_data_to_lcd_ex
                  (iVar6,*(int *)&pGVar5->field_0xeb8,param_4,param_5,param_6,param_7,*piVar1);
      } while (iVar4 != 9);
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        param_6 = param_5;
        param_7 = param_5 + -0x1b;
        goto LAB_00046630;
      }
    }
  }
  return;
}



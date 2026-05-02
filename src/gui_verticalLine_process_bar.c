/*
 * Function: gui_verticalLine_process_bar
 * Entry:    00045aa8
 * Prototype: undefined4 __stdcall gui_verticalLine_process_bar(uint param_1, int param_2, uint param_3, int param_4, undefined4 param_5, byte param_6)
 */


undefined4
gui_verticalLine_process_bar
          (uint param_1,int param_2,uint param_3,int param_4,undefined4 param_5,byte param_6)

{
  undefined4 uVar1;
  uint uVar2;
  GlassesState *pGVar3;
  int extraout_r1;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined1 uVar7;
  
  if ((param_1 == param_3) && (param_2 <= param_4)) {
    uVar6 = (uint)param_6;
    if ((param_1 & 1) == 0) {
      uVar7 = 0xf0;
    }
    else {
      uVar7 = 0xf;
    }
    if (99 < uVar6) {
      uVar6 = 100;
    }
    uVar2 = FUN_000452e4();
    if ((uVar2 & 2) != 0) {
      _clean_fb_data(DAT_2000aa14,0,param_1 - 6,extraout_r1,param_1 + 6,param_4);
    }
    piVar5 = (int *)(DAT_2000aa14 + param_2 * 4);
    for (iVar4 = 0; iVar4 < param_4 - param_2; iVar4 = iVar4 + 1) {
      *(undefined1 *)(*piVar5 + (int)param_1 / 2) = uVar7;
      piVar5 = piVar5 + 1;
    }
    iVar4 = FUN_000452e4();
    if (iVar4 << 0x1e < 0) {
      pGVar3 = __get_dashboard_state();
      iVar4 = *(int *)&pGVar3->field_0xeb4;
      pGVar3 = __get_dashboard_state();
      _reflash_fb_data_to_lcd
                (iVar4,*(int *)&pGVar3->field_0xeb8,param_1 - 6,param_2,param_3 + 6,param_4);
    }
    uVar1 = 0;
    gui_bmp_bitmap_draw(0x17,param_1 - 4,(int)(uVar6 * ((param_4 - param_2) + -0xd)) / 100 + param_2
                        ,0,0,0);
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): input param error,please check postion content\n");
      }
      else {
        ble_printk("%s(): input param error,please check postion content\n",
                   "gui_verticalLine_process_bar",param_3,BLE_DEBUG);
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



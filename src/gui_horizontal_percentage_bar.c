/*
 * Function: gui_horizontal_percentage_bar
 * Entry:    00045ba4
 * Prototype: undefined4 __stdcall gui_horizontal_percentage_bar(int param_1, int param_2, int param_3, int param_4, byte param_5, byte param_6, byte param_7)
 */


undefined4
gui_horizontal_percentage_bar
          (int param_1,int param_2,int param_3,int param_4,byte param_5,byte param_6,byte param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  GlassesState *pGVar4;
  int extraout_r1;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if ((param_3 < param_1) || (param_4 < param_2)) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): input param error,please check postion content\n");
      }
      else {
        ble_printk("%s(): input param error,please check postion content\n",
                   "gui_horizontal_percentage_bar",param_3,BLE_DEBUG);
      }
    }
    uVar1 = 0xffffffff;
  }
  else {
    uVar6 = (uint)param_5;
    uVar10 = (uint)param_7;
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    if (99 < uVar10) {
      uVar10 = 100;
    }
    iVar12 = param_3 - param_1;
    iVar7 = iVar12 - (uint)param_6 * (uVar6 - 1);
    iVar11 = (int)(iVar7 * uVar10) / 100;
    iVar2 = FUN_000452e4();
    if (iVar2 << 0x1e < 0) {
      _clean_fb_data(DAT_2000aa14,0,param_1,extraout_r1,param_3,param_4);
    }
    bVar9 = 0;
    iVar13 = 0;
    iVar2 = 0;
    iVar8 = DAT_2000aa14 + param_2 * 4;
    for (uVar10 = 0; (int)uVar10 < iVar12; uVar10 = uVar10 + 1) {
      if (iVar7 / (int)uVar6 <= iVar2) {
        iVar13 = iVar13 + 1;
        if (((int)uVar6 <= iVar13) || (uVar10 = uVar10 + param_6, iVar12 < (int)uVar10)) break;
        iVar2 = 0;
      }
      iVar5 = param_1 / 2 + ((int)uVar10 >> 1);
      if (iVar11 == 0) {
        for (iVar3 = 0; iVar3 < param_4 - param_2; iVar3 = iVar3 + 1) {
          if ((uVar10 & 1) == 0) {
            bVar9 = DAT_20003698 & 0xf0;
          }
          else {
            bVar9 = bVar9 | DAT_20003698 & 0xf;
          }
          if ((uVar10 + 1 & 1) == 0) {
            *(byte *)(*(int *)(iVar8 + iVar3 * 4) + iVar5) = bVar9;
          }
        }
      }
      else {
        for (iVar3 = 0; iVar3 < param_4 - param_2; iVar3 = iVar3 + 1) {
          if ((uVar10 & 1) == 0) {
            bVar9 = 0xf0;
          }
          else {
            bVar9 = bVar9 | 0xf;
          }
          if ((uVar10 + 1 & 1) == 0) {
            *(byte *)(*(int *)(iVar8 + iVar3 * 4) + iVar5) = bVar9;
          }
        }
        if (0 < iVar11) {
          iVar11 = iVar11 + -1;
        }
      }
      iVar2 = iVar2 + 1;
    }
    iVar2 = FUN_000452e4();
    if (iVar2 << 0x1e < 0) {
      pGVar4 = __get_dashboard_state();
      iVar2 = *(int *)&pGVar4->field_0xeb4;
      pGVar4 = __get_dashboard_state();
      _reflash_fb_data_to_lcd(iVar2,*(int *)&pGVar4->field_0xeb8,param_1,param_2,param_3,param_4);
    }
    uVar1 = 0;
  }
  return uVar1;
}



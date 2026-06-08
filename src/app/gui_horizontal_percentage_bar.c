/*
 * Function: gui_horizontal_percentage_bar
 * Entry:    00045ba4
 * Prototype: undefined4 __stdcall gui_horizontal_percentage_bar(int param_1, int param_2, int param_3, int param_4, byte param_5, byte param_6, byte param_7)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
gui_horizontal_percentage_bar
          (int param_1,int param_2,int param_3,int param_4,byte param_5,byte param_6,byte param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  GlassesState *pGVar5;
  int y_start;
  int iVar6;
  uint uVar7;
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
    uVar2 = 0xffffffff;
  }
  else {
    uVar7 = (uint)param_5;
    uVar10 = (uint)param_7;
    if (uVar7 == 0) {
      uVar7 = 1;
    }
    if (99 < uVar10) {
      uVar10 = 100;
    }
    iVar12 = param_3 - param_1;
    iVar8 = iVar12 - (uint)param_6 * (uVar7 - 1);
    iVar11 = (int)(iVar8 * uVar10) / 100;
    iVar3 = FUN_000452e4();
    if (iVar3 << 0x1e < 0) {
      _clean_fb_data(__frame_buffer,0,param_1,y_start,param_3,param_4);
    }
    piVar1 = __frame_buffer;
    bVar9 = 0;
    iVar13 = 0;
    iVar3 = 0;
    for (uVar10 = 0; (int)uVar10 < iVar12; uVar10 = uVar10 + 1) {
      if (iVar8 / (int)uVar7 <= iVar3) {
        iVar13 = iVar13 + 1;
        if (((int)uVar7 <= iVar13) || (uVar10 = uVar10 + param_6, iVar12 < (int)uVar10)) break;
        iVar3 = 0;
      }
      iVar6 = param_1 / 2 + ((int)uVar10 >> 1);
      if (iVar11 == 0) {
        for (iVar4 = 0; iVar4 < param_4 - param_2; iVar4 = iVar4 + 1) {
          if ((uVar10 & 1) == 0) {
            bVar9 = DAT_20003698 & 0xf0;
          }
          else {
            bVar9 = bVar9 | DAT_20003698 & 0xf;
          }
          if ((uVar10 + 1 & 1) == 0) {
            *(byte *)(piVar1[param_2 + iVar4] + iVar6) = bVar9;
          }
        }
      }
      else {
        for (iVar4 = 0; iVar4 < param_4 - param_2; iVar4 = iVar4 + 1) {
          if ((uVar10 & 1) == 0) {
            bVar9 = 0xf0;
          }
          else {
            bVar9 = bVar9 | 0xf;
          }
          if ((uVar10 + 1 & 1) == 0) {
            *(byte *)(piVar1[param_2 + iVar4] + iVar6) = bVar9;
          }
        }
        if (0 < iVar11) {
          iVar11 = iVar11 + -1;
        }
      }
      iVar3 = iVar3 + 1;
    }
    iVar3 = FUN_000452e4();
    if (iVar3 << 0x1e < 0) {
      pGVar5 = __get_dashboard_state();
      iVar3 = *(int *)&(pGVar5->jdb_panel_context).field_0x348;
      pGVar5 = __get_dashboard_state();
      _reflash_fb_data_to_lcd
                (iVar3,*(int *)&(pGVar5->jdb_panel_context).field_0x34c,param_1,param_2,param_3,
                 param_4);
    }
    uVar2 = 0;
  }
  return uVar2;
}



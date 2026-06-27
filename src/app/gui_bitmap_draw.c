/*
 * Function: gui_bitmap_draw
 * Entry:    00045d48
 * Prototype: undefined4 __stdcall gui_bitmap_draw(uint param_1, int param_2, int param_3, int param_4, int param_5, byte param_6)
 */


undefined4
gui_bitmap_draw(uint param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)

{
  byte bVar1;
  int *piVar2;
  char *fmt;
  uint uVar3;
  GlassesState *pGVar4;
  byte bVar5;
  int y_start;
  int extraout_r2;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_2c [2];
  
  if (((param_3 < (int)param_1) || (param_4 < param_2)) || (0xf < param_6)) {
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): input param error,please check postion content\n";
  }
  else {
    if ((param_1 & 1) == 0) {
      uVar3 = FUN_000452e4();
      if ((uVar3 & 2) != 0) {
        _clean_fb_data(__frame_buffer,0,param_1 - 2,y_start,extraout_r2 + 2,param_4);
      }
      piVar2 = __frame_buffer;
      uVar3 = (int)(param_3 - param_1) >> 3;
      iVar11 = 0;
      for (iVar8 = 0; iVar8 < param_4 - param_2; iVar8 = iVar8 + 1) {
        pbVar9 = (byte *)(param_5 + iVar11);
        for (iVar6 = 0; iVar6 < (int)uVar3; iVar6 = iVar6 + 1) {
          bVar1 = *pbVar9;
          bVar5 = 0;
          local_2c[0] = 0;
          uVar7 = 0;
          do {
            if (((int)(uint)bVar1 >> (uVar7 & 0xff) & 1U) != 0) {
              if ((int)(uVar7 << 0x1f) < 0) {
                bVar5 = bVar5 | param_6;
              }
              else {
                bVar5 = bVar5 | param_6 << 4;
              }
            }
            uVar10 = uVar7 + 1;
            if ((uVar10 & 1) == 0) {
              *(byte *)((int)local_2c + ((int)uVar7 >> 1)) = bVar5;
              bVar5 = 0;
            }
            uVar7 = uVar10;
          } while (uVar10 != 8);
          *(undefined4 *)(piVar2[param_2 + iVar8] + iVar6 * 4 + (int)param_1 / 2) = local_2c[0];
          pbVar9 = pbVar9 + 1;
        }
        iVar11 = iVar11 + (uVar3 & ~((int)(param_3 - param_1) >> 0x1f));
      }
      iVar8 = FUN_000452e4();
      if (iVar8 << 0x1e < 0) {
        pGVar4 = __get_dashboard_state();
        iVar8 = *(int *)&(pGVar4->jdb_panel_context).field_0x348;
        pGVar4 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar8,*(int *)&(pGVar4->jdb_panel_context).field_0x34c,param_1 - 2,param_2,
                   param_3 + 2,param_4);
        return 0;
      }
      return 0;
    }
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = 
    "%s(): Scenarios where the starting point of x is an even number are not currently supported.\n"
    ;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"gui_bitmap_draw",param_3,BLE_DEBUG);
  }
  return 0xffffffff;
}



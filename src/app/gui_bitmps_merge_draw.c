/*
 * Function: gui_bitmps_merge_draw
 * Entry:    00045eb8
 * Prototype: undefined4 __stdcall gui_bitmps_merge_draw(uint param_1, int param_2, int param_3, int param_4, int param_5, int param_6, byte param_7, byte param_8)
 */


undefined4
gui_bitmps_merge_draw
          (uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6,byte param_7,
          byte param_8)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  char *fmt;
  int iVar5;
  GlassesState *pGVar6;
  int y_start;
  int x_end;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint32_t uVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  byte *local_5c;
  undefined4 local_2c [2];
  
  if (((param_3 < (int)param_1) || (param_4 < param_2)) || (0xf < (param_7 | param_8))) {
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): input param error,please check postion content\n";
  }
  else {
    if ((param_1 & 1) == 0) {
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        _clean_fb_data(__frame_buffer,0,param_1,y_start,x_end,param_4);
      }
      pbVar3 = __frame_buffer;
      iVar12 = 0;
      uVar7 = (int)(param_3 - param_1) >> 3;
      for (iVar5 = 0; iVar5 < param_4 - param_2; iVar5 = iVar5 + 1) {
        pbVar11 = (byte *)(param_6 + iVar12);
        local_5c = (byte *)(param_5 + iVar12);
        for (iVar8 = 0; iVar8 < (int)uVar7; iVar8 = iVar8 + 1) {
          bVar1 = *local_5c;
          bVar2 = *pbVar11;
          bVar4 = 0;
          local_2c[0] = 0;
          uVar9 = 0;
          do {
            if (((int)(uint)bVar1 >> (uVar9 & 0xff) & 1U) != 0) {
              if ((int)(uVar9 << 0x1f) < 0) {
                bVar4 = bVar4 | param_7;
              }
              else {
                bVar4 = bVar4 | param_7 << 4;
              }
            }
            if (((int)(uint)bVar2 >> (uVar9 & 0xff) & 1U) != 0) {
              if ((int)(uVar9 << 0x1f) < 0) {
                bVar4 = bVar4 | param_8;
              }
              else {
                bVar4 = bVar4 | param_8 << 4;
              }
            }
            uVar13 = uVar9 + 1;
            if ((uVar13 & 1) == 0) {
              *(byte *)((int)local_2c + ((int)uVar9 >> 1)) = bVar4;
              bVar4 = 0;
            }
            uVar9 = uVar13;
          } while (uVar13 != 8);
          *(undefined4 *)(*(int *)(pbVar3 + iVar5 * 4 + param_2 * 4) + iVar8 * 4 + (int)param_1 / 2)
               = local_2c[0];
          pbVar11 = pbVar11 + 1;
          local_5c = local_5c + 1;
        }
        iVar12 = iVar12 + (uVar7 & ~((int)(param_3 - param_1) >> 0x1f));
      }
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        pGVar6 = __get_dashboard_state();
        uVar10 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (uVar10,(pGVar6->jdb_panel_context).current_column,param_1,param_2,param_3,param_4
                  );
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
    printk(fmt,"gui_bitmps_merge_draw");
  }
  else {
    ble_printk(fmt);
  }
  return 0xffffffff;
}



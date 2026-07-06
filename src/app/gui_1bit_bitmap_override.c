/*
 * Function: gui_1bit_bitmap_override
 * Entry:    00046058
 * Prototype: undefined4 __stdcall gui_1bit_bitmap_override(uint param_1, int param_2, int param_3, int param_4, int param_5, byte param_6)
 */


undefined4
gui_1bit_bitmap_override(uint param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)

{
  byte bVar1;
  byte *pbVar2;
  char *fmt;
  int iVar3;
  GlassesState *pGVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint32_t uVar11;
  int iVar12;
  byte *pbVar13;
  byte bVar14;
  int local_54;
  byte *local_4c;
  byte local_2c [8];
  
  pbVar2 = __frame_buffer;
  if (((param_3 < (int)param_1) || (param_4 < param_2)) || (0xf < param_6)) {
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): input param error,please check postion content\n";
  }
  else {
    if ((param_1 & 1) == 0) {
      uVar7 = (int)(param_3 - param_1) >> 3;
      iVar12 = 0;
      for (iVar8 = 0; iVar8 < param_4 - param_2; iVar8 = iVar8 + 1) {
        iVar3 = (int)param_1 / 2;
        local_4c = (byte *)(param_5 + iVar12);
        for (local_54 = 0; local_54 < (int)uVar7; local_54 = local_54 + 1) {
          bVar1 = *local_4c;
          bVar14 = 0;
          local_2c[0] = 0;
          local_2c[1] = 0;
          local_2c[2] = 0;
          local_2c[3] = 0;
          uVar5 = 0;
          do {
            if (((int)(uint)bVar1 >> (uVar5 & 0xff) & 1U) != 0) {
              if ((int)(uVar5 << 0x1f) < 0) {
                bVar14 = bVar14 | param_6;
              }
              else {
                bVar14 = param_6 << 4 | bVar14;
              }
            }
            uVar9 = uVar5 + 1;
            if ((uVar9 & 1) == 0) {
              local_2c[(int)uVar5 >> 1] = bVar14;
              bVar14 = 0;
            }
            uVar5 = uVar9;
          } while (uVar9 != 8);
          iVar6 = 0;
          pbVar13 = local_2c;
          do {
            iVar10 = iVar6 + iVar3;
            iVar6 = iVar6 + 1;
            *(byte *)(*(int *)(pbVar2 + iVar8 * 4 + param_2 * 4) + iVar10) =
                 *pbVar13 | *(byte *)(*(int *)(pbVar2 + iVar8 * 4 + param_2 * 4) + iVar10);
            pbVar13 = pbVar13 + 1;
          } while (iVar6 != 4);
          iVar3 = iVar3 + 4;
          local_4c = local_4c + 1;
        }
        iVar12 = iVar12 + (uVar7 & ~((int)(param_3 - param_1) >> 0x1f));
      }
      iVar8 = FUN_000452e4();
      if (iVar8 << 0x1e < 0) {
        pGVar4 = __get_dashboard_state();
        uVar11 = (pGVar4->jdb_panel_context).current_row;
        pGVar4 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (uVar11,(pGVar4->jdb_panel_context).current_column,param_1 - 2,param_2,param_3 + 2
                   ,param_4);
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
    printk(fmt,"gui_1bit_bitmap_override");
  }
  else {
    ble_printk(fmt);
  }
  return 0xffffffff;
}



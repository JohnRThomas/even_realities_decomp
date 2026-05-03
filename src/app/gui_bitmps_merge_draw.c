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
  byte bVar3;
  char *fmt;
  int iVar4;
  GlassesState *pGVar5;
  int extraout_r1;
  int extraout_r2;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
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
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_1,extraout_r1,extraout_r2,param_4);
      }
      iVar11 = 0;
      uVar6 = (int)(param_3 - param_1) >> 3;
      iVar7 = DAT_2000aa14 + param_2 * 4;
      for (iVar4 = 0; iVar4 < param_4 - param_2; iVar4 = iVar4 + 1) {
        pbVar10 = (byte *)(param_6 + iVar11);
        local_5c = (byte *)(param_5 + iVar11);
        for (iVar8 = 0; iVar8 < (int)uVar6; iVar8 = iVar8 + 1) {
          bVar1 = *local_5c;
          bVar2 = *pbVar10;
          bVar3 = 0;
          local_2c[0] = 0;
          uVar9 = 0;
          do {
            if (((int)(uint)bVar1 >> (uVar9 & 0xff) & 1U) != 0) {
              if ((int)(uVar9 << 0x1f) < 0) {
                bVar3 = bVar3 | param_7;
              }
              else {
                bVar3 = bVar3 | param_7 << 4;
              }
            }
            if (((int)(uint)bVar2 >> (uVar9 & 0xff) & 1U) != 0) {
              if ((int)(uVar9 << 0x1f) < 0) {
                bVar3 = bVar3 | param_8;
              }
              else {
                bVar3 = bVar3 | param_8 << 4;
              }
            }
            uVar12 = uVar9 + 1;
            if ((uVar12 & 1) == 0) {
              *(byte *)((int)local_2c + ((int)uVar9 >> 1)) = bVar3;
              bVar3 = 0;
            }
            uVar9 = uVar12;
          } while (uVar12 != 8);
          *(undefined4 *)(*(int *)(iVar7 + iVar4 * 4) + iVar8 * 4 + (int)param_1 / 2) = local_2c[0];
          pbVar10 = pbVar10 + 1;
          local_5c = local_5c + 1;
        }
        iVar11 = iVar11 + (uVar6 & ~((int)(param_3 - param_1) >> 0x1f));
      }
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        pGVar5 = __get_dashboard_state();
        iVar4 = *(int *)&pGVar5->field_0xeb4;
        pGVar5 = __get_dashboard_state();
        _reflash_fb_data_to_lcd(iVar4,*(int *)&pGVar5->field_0xeb8,param_1,param_2,param_3,param_4);
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
    ble_printk(fmt,"gui_bitmps_merge_draw",param_3,BLE_DEBUG);
  }
  return 0xffffffff;
}



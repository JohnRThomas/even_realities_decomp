/*
 * Function: gui_bitmap_draw
 * Entry:    00045d48
 * Prototype: undefined4 __stdcall gui_bitmap_draw(uint param_1, int param_2, int param_3, int param_4, int param_5, byte param_6)
 */


undefined4
gui_bitmap_draw(uint param_1,int param_2,int param_3,int param_4,int param_5,byte param_6)

{
  byte bVar1;
  char *fmt;
  uint uVar2;
  GlassesState *pGVar3;
  byte bVar4;
  int extraout_r1;
  int extraout_r2;
  int iVar5;
  uint uVar6;
  int iVar7;
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
      uVar2 = FUN_000452e4();
      if ((uVar2 & 2) != 0) {
        _clean_fb_data(DAT_2000aa14,0,param_1 - 2,extraout_r1,extraout_r2 + 2,param_4);
      }
      uVar2 = (int)(param_3 - param_1) >> 3;
      iVar7 = DAT_2000aa14 + param_2 * 4;
      iVar11 = 0;
      for (iVar8 = 0; iVar8 < param_4 - param_2; iVar8 = iVar8 + 1) {
        pbVar9 = (byte *)(param_5 + iVar11);
        for (iVar5 = 0; iVar5 < (int)uVar2; iVar5 = iVar5 + 1) {
          bVar1 = *pbVar9;
          bVar4 = 0;
          local_2c[0] = 0;
          uVar6 = 0;
          do {
            if (((int)(uint)bVar1 >> (uVar6 & 0xff) & 1U) != 0) {
              if ((int)(uVar6 << 0x1f) < 0) {
                bVar4 = bVar4 | param_6;
              }
              else {
                bVar4 = bVar4 | param_6 << 4;
              }
            }
            uVar10 = uVar6 + 1;
            if ((uVar10 & 1) == 0) {
              *(byte *)((int)local_2c + ((int)uVar6 >> 1)) = bVar4;
              bVar4 = 0;
            }
            uVar6 = uVar10;
          } while (uVar10 != 8);
          *(undefined4 *)(*(int *)(iVar7 + iVar8 * 4) + iVar5 * 4 + (int)param_1 / 2) = local_2c[0];
          pbVar9 = pbVar9 + 1;
        }
        iVar11 = iVar11 + (uVar2 & ~((int)(param_3 - param_1) >> 0x1f));
      }
      iVar7 = FUN_000452e4();
      if (iVar7 << 0x1e < 0) {
        pGVar3 = __get_dashboard_state();
        iVar7 = *(int *)&pGVar3->field_0xeb4;
        pGVar3 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar7,*(int *)&pGVar3->field_0xeb8,param_1 - 2,param_2,param_3 + 2,param_4);
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



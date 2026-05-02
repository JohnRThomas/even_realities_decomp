/*
 * Function: gui_bmp_bitmap_draw
 * Entry:    000455c0
 * Prototype: undefined4 __stdcall gui_bmp_bitmap_draw(uint param_1, int param_2, int param_3, int param_4, int param_5, uint param_6)
 */


undefined4
gui_bmp_bitmap_draw(uint param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  GlassesState *pGVar3;
  int extraout_r1;
  undefined4 extraout_r2;
  int iVar4;
  int iVar5;
  undefined *local_24;
  uint local_20;
  uint local_1c;
  
  if (((param_4 == 0) && (param_5 == 0)) && (param_6 == 0)) {
    local_20 = param_6;
    local_1c = param_6;
    if (param_1 - 0x16 < 0x72) {
      iVar2 = resource_manger_get(4,param_1,&local_20,&local_1c,&local_24,(undefined1 *)0x0);
      if (iVar2 < 0) {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): can\'t find resource,please check resource name !\n");
          }
          else {
            ble_printk("%s(): can\'t find resource,please check resource name !\n",
                       "gui_bmp_bitmap_draw",extraout_r2,BLE_DEBUG);
          }
        }
        return 0xffffffff;
      }
      uVar1 = FUN_000452e4();
      if ((uVar1 & 2) != 0) {
        _clean_fb_data(DAT_2000aa14,0,param_2,param_3,local_20 + 2 + param_2,local_1c + param_3);
      }
      FUN_00080c02(DAT_2000aa14,local_24,(int)local_20 / 2,local_1c,param_2,param_3);
      iVar2 = FUN_000452e4();
      if (-1 < iVar2 << 0x1e) {
        return 0;
      }
      pGVar3 = __get_dashboard_state();
      iVar5 = *(int *)&pGVar3->field_0xeb4;
      pGVar3 = __get_dashboard_state();
      iVar2 = local_1c + param_3;
      iVar4 = local_20 + 2 + param_2;
    }
    else {
      uVar1 = FUN_000452e4();
      if ((uVar1 & 2) != 0) {
        _clean_fb_data(DAT_2000aa14,0,extraout_r1,param_3,extraout_r1 + 0x18,param_3 + 0x18);
      }
      local_24 = FUN_0004b2d4(param_1 & 0xff,0x120);
      FUN_00080c02(DAT_2000aa14,local_24,0xc,0x18,param_2,param_3);
      iVar2 = FUN_000452e4();
      if (-1 < iVar2 << 0x1e) {
        return 0;
      }
      pGVar3 = __get_dashboard_state();
      iVar5 = *(int *)&pGVar3->field_0xeb4;
      pGVar3 = __get_dashboard_state();
      iVar2 = param_3 + 0x18;
      iVar4 = param_2 + 0x18;
    }
    _reflash_fb_data_to_lcd(iVar5,*(int *)&pGVar3->field_0xeb8,param_2,param_3,iVar4,iVar2);
  }
  return 0;
}



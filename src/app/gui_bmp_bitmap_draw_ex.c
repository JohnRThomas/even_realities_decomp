/*
 * Function: gui_bmp_bitmap_draw_ex
 * Entry:    00045710
 * Prototype: undefined4 __stdcall gui_bmp_bitmap_draw_ex(uint param_1, int param_2, int param_3, void * param_4, byte param_5)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 gui_bmp_bitmap_draw_ex(uint param_1,int param_2,int param_3,void *param_4,byte param_5)

{
  char *fmt;
  int iVar1;
  uint uVar2;
  GlassesState *pGVar3;
  int extraout_r2;
  byte *pbVar4;
  size_t n;
  uint local_24;
  uint local_20;
  void *local_1c;
  
  if (param_5 == 0) {
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): dark light value parampter error,exit!\n";
  }
  else {
    iVar1 = resource_manger_get(4,param_1,&local_24,&local_20,&local_1c,(undefined1 *)0x0);
    if (-1 < iVar1) {
      n = local_20 * ((int)local_24 / 2);
      memcpy(param_4,local_1c,n);
      pbVar4 = (byte *)((int)param_4 + -1);
      while (n - (int)(pbVar4 + (1 - (int)param_4)) != 0 &&
             (int)(pbVar4 + (1 - (int)param_4)) <= (int)n) {
        pbVar4 = pbVar4 + 1;
        if (*pbVar4 != 0) {
          *pbVar4 = *pbVar4 & param_5;
        }
      }
      uVar2 = FUN_000452e4();
      if ((uVar2 & 2) != 0) {
        _clean_fb_data(__frame_buffer,0,param_2,param_3,local_24 + 2 + param_2,local_20 + param_3);
      }
      __copy_to_frame_buffer((int)__frame_buffer,param_4,(int)local_24 / 2,local_20,param_2,param_3)
      ;
      iVar1 = FUN_000452e4();
      if (iVar1 << 0x1e < 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
        pGVar3 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar1,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,param_2,param_3,
                   local_24 + 2 + param_2,local_20 + param_3);
      }
      return 0;
    }
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    fmt = "%s(): can\'t find resource,please check resource name !\n";
    param_3 = extraout_r2;
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"gui_bmp_bitmap_draw_ex",param_3,BLE_DEBUG);
  }
  return 0xffffffff;
}



/*
 * Function: gui_4bit_bitmap_override
 * Entry:    000461d0
 * Prototype: undefined4 __stdcall gui_4bit_bitmap_override(uint param_1, uint param_2, uint param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 gui_4bit_bitmap_override(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r2;
  uint local_1c;
  uint local_18;
  int local_14;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if ((param_2 < 0x281) && (param_3 < 0x1e1)) {
    iVar1 = resource_manger_get(4,param_1,&local_1c,&local_18,&local_14,(undefined1 *)0x0);
    if (-1 < iVar1) {
      FUN_00080c4e(__frame_buffer,local_14,local_1c,local_18,param_2,param_3);
      iVar1 = FUN_000452e4();
      if (iVar1 << 0x1e < 0) {
        pGVar2 = __get_dashboard_state();
        iVar1 = *(int *)&(pGVar2->jdb_panel_context).field_0x348;
        pGVar2 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar1,*(int *)&(pGVar2->jdb_panel_context).field_0x34c,param_2,param_3,
                   local_1c + param_2,local_18 + param_3);
      }
      return 0;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): can\'t find resource,please check resource name !\n");
      }
      else {
        ble_printk("%s(): can\'t find resource,please check resource name !\n",
                   "gui_4bit_bitmap_override",extraout_r2,BLE_DEBUG);
      }
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): gui_4bit_bitmap_override parampter overstep!!! stop draw bitmap !!! x= %d,y= %d\n"
             ,"gui_4bit_bitmap_override",param_2,param_3);
    }
    else {
      ble_printk("%s(): gui_4bit_bitmap_override parampter overstep!!! stop draw bitmap !!! x= %d,y= %d\n"
                 ,"gui_4bit_bitmap_override",param_2,param_3);
    }
  }
  return 0xffffffff;
}



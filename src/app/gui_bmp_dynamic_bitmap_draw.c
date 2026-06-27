/*
 * Function: gui_bmp_dynamic_bitmap_draw
 * Entry:    00045488
 * Prototype: undefined4 __stdcall gui_bmp_dynamic_bitmap_draw(uint param_1, int param_2, int param_3)
 */


undefined4 gui_bmp_dynamic_bitmap_draw(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r2;
  byte in_stack_00000008;
  byte local_2d;
  uint local_2c;
  uint local_28;
  int local_24 [2];
  
  local_2c = 0;
  local_28 = 0;
  local_24[0] = 0;
  iVar1 = resource_manger_get(5,param_1,&local_2c,&local_28,local_24,&local_2d);
  if (iVar1 < 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): can\'t find resource,please check resource name !\n");
      }
      else {
        ble_printk("%s(): can\'t find resource,please check resource name !\n",
                   "gui_bmp_dynamic_bitmap_draw",extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    DAT_200100f0 = (ushort)local_2d;
    uVar3 = FUN_000452e4();
    if ((uVar3 & 2) != 0) {
      _clean_fb_data(__frame_buffer,0,param_2,param_3,local_2c + param_2,local_28 + param_3);
    }
    __copy_to_frame_buffer
              ((int)__frame_buffer,
               (void *)(local_28 * ((int)(local_2c * DAT_200100ee) / 2) + local_24[0]),
               (int)local_2c / 2,local_28,param_2,param_3);
    iVar1 = FUN_000452e4();
    if (iVar1 << 0x1e < 0) {
      pGVar4 = __get_dashboard_state();
      iVar1 = *(int *)&(pGVar4->jdb_panel_context).field_0x348;
      pGVar4 = __get_dashboard_state();
      _reflash_fb_data_to_lcd
                (iVar1,*(int *)&(pGVar4->jdb_panel_context).field_0x34c,param_2,param_3,
                 local_2c + param_2,local_28 + param_3);
    }
    if ((((int)(uint)DAT_200100ee < (int)(DAT_200100f0 - 1)) || (in_stack_00000008 == 0)) ||
       ((int)(uint)DAT_200100ec < (int)(in_stack_00000008 - 1))) {
      DAT_200100ee = DAT_200100ee + 1;
    }
    if ((uint)DAT_200100f0 <= (uint)DAT_200100ee) {
      DAT_200100ee = 0;
      DAT_200100ec = DAT_200100ec + 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



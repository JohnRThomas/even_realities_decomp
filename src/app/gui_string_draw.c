/*
 * Function: gui_string_draw
 * Entry:    00047c8c
 * Prototype: undefined4 __stdcall gui_string_draw(uint param_1, byte * param_2, int param_3, int param_4, int param_5, int param_6, int * param_7)
 */


undefined4
gui_string_draw(uint param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6,
               int *param_7)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  GlassesState *pGVar4;
  char *fmt;
  uint32_t uVar5;
  byte *pbVar6;
  uint local_34;
  uint local_30;
  void *local_2c [2];
  
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = (void *)0x0;
  sVar1 = strlen((char *)param_2);
  iVar2 = FUN_000452e4();
  if (iVar2 << 0x1e < 0) {
    _clean_fb_data(__frame_buffer,0,param_3,param_4,param_5,param_6);
  }
  iVar2 = param_3;
  pbVar6 = param_2;
  do {
    if (param_2 + sVar1 == pbVar6) {
      iVar3 = FUN_000452e4();
      if (iVar3 << 0x1e < 0) {
        pGVar4 = __get_dashboard_state();
        uVar5 = (pGVar4->jdb_panel_context).current_row;
        pGVar4 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (uVar5,(pGVar4->jdb_panel_context).current_column,param_3,param_4,param_5,param_6)
        ;
      }
      if (param_7 != (int *)0x0) {
        *param_7 = iVar2 - param_3;
      }
      return 0;
    }
    if (*param_2 < 0x20) {
      if (0 < LOG_LEVEL) {
        fmt = "%s(): non-ascii characters\n";
LAB_00047d48:
        if (BLE_DEBUG == 0) {
          printk(fmt,"gui_string_draw");
        }
        else {
          ble_printk(fmt);
        }
      }
    }
    else {
      iVar3 = resource_manger_get(param_1,(uint)*pbVar6,&local_34,&local_30,local_2c,
                                  (undefined1 *)0x0);
      if ((local_2c[0] == (void *)0x0) || (iVar3 != 0)) {
        if (1 < LOG_LEVEL) {
          fmt = "%s(): find ascii postion failed\n";
          goto LAB_00047d48;
        }
      }
      else {
        __copy_to_frame_buffer
                  ((int)__frame_buffer,local_2c[0],(int)local_34 / 2,local_30,iVar2,param_4);
        if ((*pbVar6 - 0x20 < 0x5f) && (param_1 == 3)) {
          iVar2 = local_34 + iVar2 + 3;
        }
        else {
          iVar2 = iVar2 + local_34;
          iVar3 = FUN_000462b0((uint)*pbVar6,(uint)pbVar6[1]);
          iVar2 = iVar2 + iVar3;
        }
      }
    }
    pbVar6 = pbVar6 + 1;
  } while( true );
}



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
  GlassesState *pGVar3;
  char *fmt;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int iVar4;
  byte *pbVar5;
  uint local_34;
  uint local_30;
  void *local_2c [2];
  
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = (void *)0x0;
  sVar1 = strlen((char *)param_2);
  iVar2 = FUN_000452e4();
  iVar2 = iVar2 << 0x1e;
  if (iVar2 < 0) {
    _clean_fb_data(__frame_buffer,0,param_3,param_4,param_5,param_6);
    iVar2 = extraout_r2;
  }
  iVar4 = param_3;
  pbVar5 = param_2;
  do {
    if (param_2 + sVar1 == pbVar5) {
      iVar2 = FUN_000452e4();
      if (iVar2 << 0x1e < 0) {
        pGVar3 = __get_dashboard_state();
        iVar2 = *(int *)&(pGVar3->jdb_panel_context).field_0x348;
        pGVar3 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar2,*(int *)&(pGVar3->jdb_panel_context).field_0x34c,param_3,param_4,param_5,
                   param_6);
      }
      if (param_7 != (int *)0x0) {
        *param_7 = iVar4 - param_3;
      }
      return 0;
    }
    if (*param_2 < 0x20) {
      if (0 < LOG_LEVEL) {
        fmt = "%s(): non-ascii characters\n";
LAB_00047d48:
        if (BLE_DEBUG == 0) {
          printk(fmt);
          iVar2 = extraout_r2_04;
        }
        else {
          ble_printk(fmt,"gui_string_draw",iVar2,BLE_DEBUG);
          iVar2 = extraout_r2_01;
        }
      }
    }
    else {
      iVar2 = resource_manger_get(param_1,(uint)*pbVar5,&local_34,&local_30,local_2c,
                                  (undefined1 *)0x0);
      if ((local_2c[0] == (void *)0x0) || (iVar2 != 0)) {
        iVar2 = extraout_r2_00;
        if (1 < LOG_LEVEL) {
          fmt = "%s(): find ascii postion failed\n";
          goto LAB_00047d48;
        }
      }
      else {
        __copy_to_frame_buffer
                  ((int)__frame_buffer,local_2c[0],(int)local_34 / 2,local_30,iVar4,param_4);
        if ((*pbVar5 - 0x20 < 0x5f) && (param_1 == 3)) {
          iVar4 = local_34 + iVar4 + 3;
          iVar2 = extraout_r2_02;
        }
        else {
          iVar4 = iVar4 + local_34;
          iVar2 = FUN_000462b0((uint)*pbVar5,(uint)pbVar5[1]);
          iVar4 = iVar4 + iVar2;
          iVar2 = extraout_r2_03;
        }
      }
    }
    pbVar5 = pbVar5 + 1;
  } while( true );
}



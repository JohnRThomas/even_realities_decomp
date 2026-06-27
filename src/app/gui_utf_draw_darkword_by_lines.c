/*
 * Function: gui_utf_draw_darkword_by_lines
 * Entry:    0004701c
 * Prototype: undefined4 __stdcall gui_utf_draw_darkword_by_lines(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, byte param_9, int param_10, undefined * param_11, int param_12)
 */


undefined4
gui_utf_draw_darkword_by_lines
          (undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
          int param_7,uint param_8,byte param_9,int param_10,undefined *param_11,int param_12)

{
  size_t sVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  GlassesState *pGVar6;
  undefined4 uVar7;
  undefined4 extraout_r2;
  size_t n;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  int local_2f0;
  ushort local_2da;
  void *local_2d8;
  uint local_2d4;
  uint local_2d0;
  byte local_2cc [680];
  
  local_2da = 0;
  local_2d8 = (void *)0x0;
  puVar4 = (ushort *)FUN_0004b160(param_2,&local_2da);
  local_2d4 = 0;
  local_2d0 = 0;
  if (param_10 == 0) {
    if (param_11 != (undefined *)0x0) {
LAB_00047236:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n",
                     "gui_utf_draw_darkword_by_lines",extraout_r2,BLE_DEBUG);
        }
      }
      uVar7 = (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return uVar7;
    }
    if (param_12 == 0) {
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        _clean_fb_data(__frame_buffer,0,param_4,param_5,param_6,param_7);
      }
      uVar10 = 0;
      uVar13 = 0;
      uVar9 = 0;
      uVar11 = 0;
      for (local_2f0 = 0; local_2f0 < (int)(uint)local_2da; local_2f0 = local_2f0 + 1) {
        puVar14 = puVar4 + 1;
        uVar12 = (uint)*puVar4;
        iVar5 = FUN_00080fb2(uVar12);
        if (iVar5 == 0) {
          iVar5 = resource_manger_get(param_3,uVar12,&local_2d4,&local_2d0,&local_2d8,
                                      (undefined1 *)0x0);
          uVar3 = local_2d0;
          uVar2 = local_2d4;
          if (iVar5 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n",
                           "gui_utf_draw_darkword_by_lines",uVar12,BLE_DEBUG);
              }
            }
          }
          else {
            sVar1 = (int)local_2d4 / 2;
            n = local_2d0 * sVar1;
            memcpy(local_2cc,local_2d8,n);
            if ((param_9 != 0) && ((int)uVar10 < (int)(uint)param_9)) {
              pbVar8 = local_2cc;
              for (iVar5 = 0; iVar5 < (int)n; iVar5 = iVar5 + 1) {
                *pbVar8 = *pbVar8 & DAT_20003698;
                pbVar8 = pbVar8 + 1;
              }
            }
            iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar14);
            uVar13 = uVar13 + uVar2 + iVar5;
            if ((uint)(param_6 - param_4) < uVar13) {
              uVar9 = uVar9 + uVar3;
              if (param_3 == 0) {
                uVar9 = uVar9 + 1;
              }
              uVar10 = uVar10 + 1;
              if ((param_8 <= uVar10) || ((uint)(param_7 - param_5) <= uVar9)) break;
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,sVar1,uVar3,param_4,uVar9 + param_5);
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar14);
              uVar11 = local_2d4 + iVar5;
              uVar13 = uVar11;
            }
            else {
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,sVar1,uVar3,uVar11 + param_4,uVar9 + param_5)
              ;
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar14);
              uVar11 = uVar11 + iVar5 + local_2d4;
            }
          }
        }
        else if ((iVar5 == -1) && ((uVar12 == 0xd || (uVar12 == 10)))) {
          if (local_2d0 == 0) {
            if (param_3 == 0) {
              uVar9 = uVar9 + 0x1b;
            }
            else {
              uVar9 = uVar9 + 0x1a;
            }
          }
          else {
            uVar9 = uVar9 + local_2d0;
            if (param_3 == 0) {
              uVar9 = uVar9 + 1;
            }
          }
          uVar10 = uVar10 + 1;
          if ((param_8 <= uVar10) || ((uint)(param_7 - param_5) <= uVar9)) break;
          uVar11 = 0;
          uVar13 = uVar11;
        }
        puVar4 = puVar14;
      }
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        pGVar6 = __get_dashboard_state();
        iVar5 = *(int *)&(pGVar6->jdb_panel_context).field_0x348;
        pGVar6 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar5,*(int *)&(pGVar6->jdb_panel_context).field_0x34c,param_4,param_5,param_6,
                   param_7);
      }
    }
  }
  else if (param_11 != (undefined *)0x0) goto LAB_00047236;
  return 0;
}



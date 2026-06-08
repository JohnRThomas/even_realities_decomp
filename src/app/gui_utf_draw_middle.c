/*
 * Function: gui_utf_draw_middle
 * Entry:    00047280
 * Prototype: undefined4 __stdcall gui_utf_draw_middle(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9, int param_10, undefined * param_11, int param_12)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
gui_utf_draw_middle(undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,
                   int param_6,int param_7,uint param_8,uint param_9,int param_10,
                   undefined *param_11,int param_12)

{
  size_t sVar1;
  bool bVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  GlassesState *pGVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 extraout_r2;
  size_t n;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_2f8;
  uint local_2f4;
  uint local_2ec;
  int local_2e8;
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
LAB_00047538:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n","gui_utf_draw_middle",
                     extraout_r2,BLE_DEBUG);
        }
      }
      uVar8 = (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return uVar8;
    }
    if (param_12 == 0) {
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        _clean_fb_data(__frame_buffer,0,param_4,param_5,param_6,param_7);
      }
      uVar11 = 0;
      bVar2 = true;
      uVar10 = 0;
      local_2f4 = 0;
      local_2f8 = 0;
      local_2e8 = param_4;
      for (local_2ec = 0; (int)local_2ec < (int)(uint)local_2da; local_2ec = local_2ec + 1) {
        if (bVar2) {
          iVar5 = 0;
          uVar13 = local_2ec;
          for (puVar12 = puVar4;
              (((int)uVar13 < (int)(uint)local_2da && (uVar14 = (uint)*puVar12, uVar14 != 0xd)) &&
              (uVar14 != 10)); puVar12 = puVar12 + 1) {
            iVar7 = FUN_00080fb2(uVar14);
            if (iVar7 == 0) {
              iVar7 = resource_manger_get(param_3,uVar14,&local_2d4,&local_2d0,&local_2d8,
                                          (undefined1 *)0x0);
              if (iVar7 < 0) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): can not find 0x%x font resource\n");
                  }
                  else {
                    ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_draw_middle",
                               uVar14,BLE_DEBUG);
                  }
                }
              }
              else {
                iVar7 = FUN_000462b0((uint)*puVar12,(uint)puVar12[1]);
                iVar5 = iVar5 + iVar7 + local_2d4;
              }
            }
            uVar13 = uVar13 + 1;
          }
          local_2e8 = param_4 + ((uint)((param_6 - param_4) - iVar5) >> 1);
        }
        puVar12 = puVar4 + 1;
        uVar13 = (uint)*puVar4;
        iVar5 = FUN_00080fb2(uVar13);
        if (iVar5 == 0) {
          iVar5 = resource_manger_get(param_3,uVar13,&local_2d4,&local_2d0,&local_2d8,
                                      (undefined1 *)0x0);
          uVar3 = local_2d0;
          uVar14 = local_2d4;
          if (iVar5 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_draw_middle",uVar13,
                           BLE_DEBUG);
              }
            }
          }
          else {
            sVar1 = (int)local_2d4 / 2;
            n = local_2d0 * sVar1;
            memcpy(local_2cc,local_2d8,n);
            if (local_2ec < param_9) {
              pbVar9 = local_2cc;
              for (iVar5 = 0; iVar5 < (int)n; iVar5 = iVar5 + 1) {
                *pbVar9 = *pbVar9 & DAT_20003698;
                pbVar9 = pbVar9 + 1;
              }
            }
            iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar12);
            local_2f4 = local_2f4 + iVar5 + uVar14;
            if ((uint)(param_6 - param_4) < local_2f4) {
              uVar10 = uVar10 + uVar3;
              if (param_3 == 0) {
                uVar10 = uVar10 + 1;
              }
              uVar11 = uVar11 + 1;
              if ((param_8 <= uVar11) || ((uint)(param_7 - param_5) <= uVar10)) break;
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,sVar1,uVar3,local_2e8,uVar10 + param_5);
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar12);
              local_2f8 = iVar5 + local_2d4;
              local_2f4 = local_2f8;
            }
            else {
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,sVar1,uVar3,local_2e8 + local_2f8,
                         uVar10 + param_5);
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar12);
              local_2f8 = local_2f8 + iVar5 + local_2d4;
            }
          }
LAB_000473e2:
          bVar2 = false;
        }
        else {
          if ((iVar5 != -1) || ((uVar13 != 0xd && (uVar13 != 10)))) goto LAB_000473e2;
          if (local_2d0 == 0) {
            if (param_3 == 0) {
              uVar10 = uVar10 + 0x1b;
            }
            else {
              uVar10 = uVar10 + 0x1a;
            }
          }
          else {
            uVar10 = uVar10 + local_2d0;
            if (param_3 == 0) {
              uVar10 = uVar10 + 1;
            }
          }
          uVar11 = uVar11 + 1;
          if ((param_8 <= uVar11) || ((uint)(param_7 - param_5) <= uVar10)) break;
          bVar2 = true;
          local_2f8 = 0;
          local_2f4 = 0;
        }
        puVar4 = puVar12;
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
  else if (param_11 != (undefined *)0x0) goto LAB_00047538;
  return 0;
}



/*
 * Function: gui_utf_draw_dark_light_split
 * Entry:    000469b0
 * Prototype: undefined __stdcall gui_utf_draw_dark_light_split(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, ushort param_9, int param_10, undefined * param_11, int param_12)
 */


void gui_utf_draw_dark_light_split
               (undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
               int param_7,uint param_8,ushort param_9,int param_10,undefined *param_11,int param_12
               )

{
  size_t sVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  GlassesState *pGVar6;
  char *fmt;
  size_t n;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint32_t uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int local_2ec;
  ushort local_2da;
  void *local_2d8;
  uint local_2d4;
  uint local_2d0;
  byte local_2cc [680];
  
  uVar7 = (uint)param_9;
  local_2da = 0;
  local_2d8 = (void *)0x0;
  puVar4 = (ushort *)FUN_0004b160(param_2,&local_2da);
  local_2d4 = 0;
  local_2d0 = 0;
  if (param_10 == 0) {
    if (param_11 != (undefined *)0x0) {
LAB_00046c02:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n","gui_utf_draw_dark_light_split");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n");
        }
      }
      (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return;
    }
    if (param_12 == 0) {
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        _clean_fb_data(__frame_buffer,0,param_4,param_5,param_6,param_7);
      }
      uVar12 = 0;
      uVar15 = 0;
      uVar9 = 0;
      uVar14 = 0;
      for (local_2ec = 0; local_2ec < (int)(uint)local_2da; local_2ec = local_2ec + 1) {
        puVar11 = puVar4 + 1;
        uVar13 = (uint)*puVar4;
        iVar5 = FUN_00080fb2(uVar13);
        if (iVar5 == 0) {
          if (uVar13 == uVar7) {
            uVar13 = uVar7;
            if (DAT_2001db46 == '\0') {
              DAT_2001db46 = '\x01';
              if (1 < LOG_LEVEL) {
                fmt = "%s(): dark_light_flag 1 code = 0x%x\n";
LAB_00046a8c:
                if (BLE_DEBUG == 0) {
                  printk(fmt,"gui_utf_draw_dark_light_split",uVar13);
                }
                else {
                  ble_printk(fmt);
                }
              }
            }
            else {
              DAT_2001db46 = '\0';
              if (1 < LOG_LEVEL) {
                fmt = "%s(): dark_light_flag 0 code = 0x%x\n";
                goto LAB_00046a8c;
              }
            }
          }
          else {
            iVar5 = resource_manger_get(param_3,uVar13,&local_2d4,&local_2d0,&local_2d8,
                                        (undefined1 *)0x0);
            uVar3 = local_2d0;
            uVar2 = local_2d4;
            if (iVar5 < 0) {
              if (1 < LOG_LEVEL) {
                fmt = "%s(): can not find 0x%x font resource\n";
                goto LAB_00046a8c;
              }
            }
            else {
              sVar1 = (int)local_2d4 / 2;
              n = local_2d0 * sVar1;
              memcpy(local_2cc,local_2d8,n);
              if (DAT_2001db46 == '\x01') {
                pbVar8 = local_2cc;
                for (iVar5 = 0; iVar5 < (int)n; iVar5 = iVar5 + 1) {
                  *pbVar8 = *pbVar8 & DAT_20003698;
                  pbVar8 = pbVar8 + 1;
                }
              }
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar11);
              uVar15 = uVar15 + uVar2 + iVar5;
              if ((uint)(param_6 - param_4) < uVar15) {
                uVar9 = uVar9 + uVar3;
                if (param_3 == 0) {
                  uVar9 = uVar9 + 1;
                }
                uVar12 = uVar12 + 1;
                if ((param_8 <= uVar12) || ((uint)(param_7 - param_5) <= uVar9)) break;
                __copy_to_frame_buffer
                          ((int)__frame_buffer,local_2cc,sVar1,uVar3,param_4,uVar9 + param_5);
                iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar11);
                uVar14 = iVar5 + local_2d4;
                uVar15 = uVar14;
              }
              else {
                __copy_to_frame_buffer
                          ((int)__frame_buffer,local_2cc,sVar1,uVar3,uVar14 + param_4,
                           uVar9 + param_5);
                iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar11);
                uVar14 = uVar14 + iVar5 + local_2d4;
              }
            }
          }
        }
        else if ((iVar5 == -1) && ((uVar13 == 0xd || (uVar13 == 10)))) {
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
          uVar12 = uVar12 + 1;
          if ((param_8 <= uVar12) || ((uint)(param_7 - param_5) <= uVar9)) break;
          uVar14 = 0;
          uVar15 = uVar14;
        }
        puVar4 = puVar11;
      }
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        pGVar6 = __get_dashboard_state();
        uVar10 = (pGVar6->jdb_panel_context).current_row;
        pGVar6 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (uVar10,(pGVar6->jdb_panel_context).current_column,param_4,param_5,param_6,param_7
                  );
      }
    }
  }
  else if (param_11 != (undefined *)0x0) goto LAB_00046c02;
  DAT_2001db46 = 0;
  return;
}



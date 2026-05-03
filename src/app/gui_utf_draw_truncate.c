/*
 * Function: gui_utf_draw_truncate
 * Entry:    00046c5c
 * Prototype: undefined4 __stdcall gui_utf_draw_truncate(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9, int param_10, undefined * param_11, int param_12)
 */


undefined4
gui_utf_draw_truncate
          (undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
          int param_7,uint param_8,uint param_9,int param_10,undefined *param_11,int param_12)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  GlassesState *pGVar4;
  undefined4 uVar5;
  undefined4 extraout_r2;
  size_t sVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  size_t sVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  uint local_2fc;
  int local_2f8;
  uint local_2f0;
  ushort local_2da;
  void *local_2d8;
  uint local_2d4;
  uint local_2d0;
  byte local_2cc [680];
  
  local_2da = 0;
  local_2d8 = (void *)0x0;
  puVar2 = (ushort *)print_string(param_2,&local_2da);
  local_2d4 = 0;
  local_2d0 = 0;
  if (param_10 == 0) {
    if (param_11 != (undefined *)0x0) {
LAB_00046fda:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n","gui_utf_draw_truncate",
                     extraout_r2,BLE_DEBUG);
        }
      }
      uVar5 = (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return uVar5;
    }
    if (param_12 == 0) {
      iVar3 = FUN_000452e4();
      if (iVar3 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_4,param_5,param_6,param_7);
      }
      uVar14 = 0;
      uVar8 = 0;
      uVar9 = 0;
      local_2fc = 0;
      local_2f0 = 0;
      do {
        if ((int)(uint)local_2da <= (int)local_2fc) goto LAB_00046eac;
        uVar10 = (uint)*puVar2;
        iVar3 = FUN_00080fb2(uVar10);
        if (iVar3 == 0) {
          iVar3 = resource_manger_get(param_3,uVar10,&local_2d4,&local_2d0,&local_2d8,
                                      (undefined1 *)0x0);
          uVar1 = local_2d0;
          uVar12 = local_2d4;
          if (iVar3 < 0) {
LAB_00046d06:
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_draw_truncate",uVar10,
                           BLE_DEBUG);
              }
            }
          }
          else {
            sVar11 = (int)local_2d4 / 2;
            sVar6 = local_2d0 * sVar11;
            memcpy(local_2cc,local_2d8,sVar6);
            if (local_2fc < param_9) {
              pbVar7 = local_2cc;
              for (iVar3 = 0; iVar3 < (int)sVar6; iVar3 = iVar3 + 1) {
                *pbVar7 = *pbVar7 & DAT_20003698;
                pbVar7 = pbVar7 + 1;
              }
            }
            iVar3 = FUN_000462b0((uint)*puVar2,(uint)puVar2[1]);
            local_2f0 = local_2f0 + uVar12 + iVar3;
            if ((uint)(param_6 - param_4) < local_2f0) {
              uVar14 = uVar14 + 1;
              uVar12 = local_2fc;
              puVar13 = puVar2;
              if ((param_8 <= uVar14) || ((uint)(param_7 - param_5) <= uVar8)) {
                while (uVar12 != 0) {
                  if (3 < (param_6 - param_4) - uVar9) goto LAB_00046e2a;
                  uVar10 = (uint)puVar13[-1];
                  iVar3 = resource_manger_get(param_3,uVar10,&local_2d4,&local_2d0,&local_2d8,
                                              (undefined1 *)0x0);
                  uVar12 = uVar12 - 1;
                  if (iVar3 < 0) {
                    if (1 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): truncate can not find [%d]0x%x font resource\n",
                               "gui_utf_draw_truncate",uVar12,uVar10);
                      }
                      else {
                        ble_printk("%s(): truncate can not find [%d]0x%x font resource\n",
                                   "gui_utf_draw_truncate",uVar12,uVar10);
                      }
                    }
                  }
                  else {
                    iVar3 = FUN_000462b0((uint)puVar13[-1],(uint)*puVar13);
                    uVar9 = (uVar9 - local_2d4) - iVar3;
                    _clean_fb_data(DAT_2000aa14,0,param_4 + uVar9,uVar8 + param_5,
                                   local_2d4 + param_4 + uVar9,local_2d0 + uVar8 + param_5);
                  }
                  puVar13 = puVar13 + -1;
                }
                uVar9 = 0;
LAB_00046e2a:
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): end line x0=%d\n");
                  }
                  else {
                    ble_printk("%s(): end line x0=%d\n","gui_utf_draw_truncate",uVar9,BLE_DEBUG);
                  }
                }
                iVar3 = resource_manger_get(param_3,0x2026,&local_2d4,&local_2d0,&local_2d8,
                                            (undefined1 *)0x0);
                uVar12 = local_2d0;
                if (iVar3 < 0) goto LAB_00046d06;
                sVar11 = (int)local_2d4 / 2;
                sVar6 = local_2d0 * sVar11;
                memcpy(local_2cc,local_2d8,sVar6);
                if (local_2fc < param_9) {
                  pbVar7 = local_2cc;
                  for (local_2f8 = 0; sVar6 - local_2f8 != 0 && local_2f8 <= (int)sVar6;
                      local_2f8 = local_2f8 + 1) {
                    *pbVar7 = *pbVar7 & DAT_20003698;
                    pbVar7 = pbVar7 + 1;
                  }
                }
                FUN_00080c02(DAT_2000aa14,local_2cc,sVar11,uVar12,uVar9 + param_4,uVar8 + param_5);
LAB_00046eac:
                iVar3 = FUN_000452e4();
                if (-1 < iVar3 << 0x1e) {
                  return 0;
                }
                pGVar4 = __get_dashboard_state();
                iVar3 = *(int *)&pGVar4->field_0xeb4;
                pGVar4 = __get_dashboard_state();
                _reflash_fb_data_to_lcd
                          (iVar3,*(int *)&pGVar4->field_0xeb8,param_4,param_5,param_6,param_7);
                return 0;
              }
              uVar8 = uVar8 + uVar1;
              if (param_3 == 0) {
                uVar8 = uVar8 + 1;
              }
              FUN_00080c02(DAT_2000aa14,local_2cc,sVar11,uVar1,param_4,uVar8 + param_5);
              iVar3 = FUN_000462b0((uint)*puVar2,(uint)puVar2[1]);
              uVar9 = local_2d4 + iVar3;
              local_2f0 = uVar9;
            }
            else {
              FUN_00080c02(DAT_2000aa14,local_2cc,sVar11,uVar1,uVar9 + param_4,uVar8 + param_5);
              iVar3 = FUN_000462b0((uint)*puVar2,(uint)puVar2[1]);
              uVar9 = uVar9 + iVar3 + local_2d4;
            }
          }
        }
        else if ((iVar3 == -1) && ((uVar10 == 0xd || (uVar10 == 10)))) {
          if (local_2d0 == 0) {
            if (param_3 == 0) {
              uVar8 = uVar8 + 0x1b;
            }
            else {
              uVar8 = uVar8 + 0x1a;
            }
          }
          else {
            uVar8 = uVar8 + local_2d0;
            if (param_3 == 0) {
              uVar8 = uVar8 + 1;
            }
          }
          uVar14 = uVar14 + 1;
          if ((param_8 <= uVar14) || ((uint)(param_7 - param_5) <= uVar8)) goto LAB_00046eac;
          uVar9 = 0;
          local_2f0 = 0;
        }
        puVar2 = puVar2 + 1;
        local_2fc = local_2fc + 1;
      } while( true );
    }
  }
  else if (param_11 != (undefined *)0x0) goto LAB_00046fda;
  return 0;
}



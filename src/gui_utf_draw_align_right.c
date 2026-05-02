/*
 * Function: gui_utf_draw_align_right
 * Entry:    00047584
 * Prototype: undefined4 __stdcall gui_utf_draw_align_right(undefined4 param_1, char * param_2, uint param_3, uint param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9, int param_10, undefined * param_11, int param_12)
 */


undefined4
gui_utf_draw_align_right
          (undefined4 param_1,char *param_2,uint param_3,uint param_4,int param_5,int param_6,
          int param_7,uint param_8,uint param_9,int param_10,undefined *param_11,int param_12)

{
  size_t sVar1;
  bool bVar2;
  ushort *puVar3;
  int iVar4;
  GlassesState *pGVar5;
  undefined4 uVar6;
  undefined4 extraout_r2;
  size_t n;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  uint local_2f8;
  uint local_2f4;
  uint local_2ec;
  uint local_2e8;
  ushort local_2da;
  void *local_2d8;
  uint local_2d4;
  uint local_2d0;
  byte local_2cc [680];
  
  local_2da = 0;
  local_2d8 = (void *)0x0;
  puVar3 = (ushort *)print_string(param_2,&local_2da);
  local_2d4 = 0;
  local_2d0 = 0;
  if (param_10 == 0) {
    if (param_11 != (undefined *)0x0) {
LAB_00047862:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n","gui_utf_draw_align_right",
                     extraout_r2,BLE_DEBUG);
        }
      }
      uVar6 = (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return uVar6;
    }
    if (param_12 == 0) {
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_4,param_5,param_6,param_7);
      }
      uVar9 = 0;
      bVar2 = true;
      uVar8 = 0;
      local_2f4 = 0;
      local_2f8 = 0;
      local_2e8 = param_4;
      for (local_2ec = 0; (int)local_2ec < (int)(uint)local_2da; local_2ec = local_2ec + 1) {
        if (bVar2) {
          uVar10 = 0;
          uVar12 = local_2ec;
          for (puVar11 = puVar3;
              (((int)uVar12 < (int)(uint)local_2da && (uVar13 = (uint)*puVar11, uVar13 != 0xd)) &&
              (uVar13 != 10)); puVar11 = puVar11 + 1) {
            iVar4 = FUN_00080fb2(uVar13);
            if (iVar4 == 0) {
              iVar4 = resource_manger_get(param_3,uVar13,&local_2d4,&local_2d0,&local_2d8,
                                          (undefined1 *)0x0);
              if (iVar4 < 0) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): can not find 0x%x font resource\n");
                  }
                  else {
                    ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_draw_align_right",
                               uVar13,BLE_DEBUG);
                  }
                }
              }
              else {
                uVar10 = uVar10 + local_2d4;
                iVar4 = FUN_000462b0((uint)*puVar11,(uint)puVar11[1]);
                uVar10 = (uVar10 & 0xffff) + iVar4 & 0xffff;
              }
            }
            uVar12 = uVar12 + 1;
          }
          local_2e8 = param_4;
          if (uVar10 <= param_6 - param_4) {
            local_2e8 = param_6 - uVar10;
          }
          local_2e8 = local_2e8 & 0xfffffffe;
        }
        puVar11 = puVar3 + 1;
        uVar12 = (uint)*puVar3;
        iVar4 = FUN_00080fb2(uVar12);
        if (iVar4 == 0) {
          iVar4 = resource_manger_get(param_3,uVar12,&local_2d4,&local_2d0,&local_2d8,
                                      (undefined1 *)0x0);
          uVar13 = local_2d0;
          uVar10 = local_2d4;
          if (iVar4 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_draw_align_right",
                           uVar12,BLE_DEBUG);
              }
            }
          }
          else {
            sVar1 = (int)local_2d4 / 2;
            n = local_2d0 * sVar1;
            memcpy(local_2cc,local_2d8,n);
            if (local_2ec < param_9) {
              pbVar7 = local_2cc;
              for (iVar4 = 0; iVar4 < (int)n; iVar4 = iVar4 + 1) {
                *pbVar7 = *pbVar7 & DAT_20003698;
                pbVar7 = pbVar7 + 1;
              }
            }
            iVar4 = FUN_000462b0((uint)*puVar3,(uint)*puVar11);
            local_2f4 = local_2f4 + iVar4 + uVar10;
            if (param_6 - param_4 < local_2f4) {
              uVar8 = uVar8 + uVar13;
              if (param_3 == 0) {
                uVar8 = uVar8 + 1;
              }
              uVar9 = uVar9 + 1;
              if ((param_8 <= uVar9) || ((uint)(param_7 - param_5) <= uVar8)) break;
              FUN_00080c02(DAT_2000aa14,local_2cc,sVar1,uVar13,local_2e8,uVar8 + param_5);
              iVar4 = FUN_000462b0((uint)*puVar3,(uint)*puVar11);
              local_2f8 = iVar4 + local_2d4;
              local_2f4 = local_2f8;
            }
            else {
              FUN_00080c02(DAT_2000aa14,local_2cc,sVar1,uVar13,local_2e8 + local_2f8,uVar8 + param_5
                          );
              iVar4 = FUN_000462b0((uint)*puVar3,(uint)*puVar11);
              local_2f8 = local_2f8 + iVar4 + local_2d4;
            }
          }
LAB_000476ec:
          bVar2 = false;
        }
        else {
          if ((iVar4 != -1) || ((uVar12 != 0xd && (uVar12 != 10)))) goto LAB_000476ec;
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
          uVar9 = uVar9 + 1;
          if ((param_8 <= uVar9) || ((uint)(param_7 - param_5) <= uVar8)) break;
          bVar2 = true;
          local_2f8 = 0;
          local_2f4 = 0;
        }
        puVar3 = puVar11;
      }
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        pGVar5 = __get_dashboard_state();
        iVar4 = *(int *)&pGVar5->field_0xeb4;
        pGVar5 = __get_dashboard_state();
        _reflash_fb_data_to_lcd(iVar4,*(int *)&pGVar5->field_0xeb8,param_4,param_5,param_6,param_7);
      }
    }
  }
  else if (param_11 != (undefined *)0x0) goto LAB_00047862;
  return 0;
}



/*
 * Function: gui_utf_Wordwrap_draw
 * Entry:    000478a0
 * Prototype: undefined4 __stdcall gui_utf_Wordwrap_draw(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9, int param_10, undefined * param_11, int param_12)
 */


undefined4
gui_utf_Wordwrap_draw
          (undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
          int param_7,uint param_8,uint param_9,int param_10,undefined *param_11,int param_12)

{
  ushort uVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  int iVar4;
  GlassesState *pGVar5;
  ushort *puVar6;
  char *fmt;
  undefined4 uVar7;
  undefined4 extraout_r2;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ushort *puVar17;
  size_t n;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  uint local_318;
  uint local_314;
  ushort local_302;
  void *local_300;
  uint local_2fc;
  uint local_2f8;
  uint local_2f4 [3];
  ushort local_2e8 [6];
  ushort local_2dc [2];
  undefined4 auStack_2d8 [2];
  ushort local_2d0 [2];
  byte local_2cc [680];
  
  local_302 = 0;
  local_300 = (void *)0x0;
  puVar3 = (ushort *)print_string(param_2,&local_302);
  local_2fc = 0;
  local_2f8 = 0;
  if (param_10 == 0) {
    if (param_11 != (undefined *)0x0) {
LAB_00047c4c:
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n","gui_utf_Wordwrap_draw",
                     extraout_r2,BLE_DEBUG);
        }
      }
      uVar7 = (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return uVar7;
    }
    if (param_12 == 0) {
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_4,param_5,param_6,param_7);
      }
      uVar14 = 0;
      uVar15 = 0;
      uVar13 = 0;
      uVar19 = 0;
      uVar10 = param_6 - param_4;
      puVar17 = puVar3;
      for (uVar18 = 0; (int)uVar18 < (int)(uint)local_302; uVar18 = uVar18 + 1) {
        uVar16 = (uint)*puVar17;
        iVar4 = FUN_00080fb2(uVar16);
        if (iVar4 == 0) {
          iVar4 = resource_manger_get(param_3,uVar16,&local_2fc,&local_2f8,&local_300,
                                      (undefined1 *)0x0);
          if (iVar4 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_Wordwrap_draw",uVar16,
                           BLE_DEBUG);
              }
            }
          }
          else {
            n = local_2f8 * ((int)local_2fc / 2);
            memcpy(local_2cc,local_300,n);
            if (uVar18 < param_9) {
              pbVar11 = local_2cc;
              for (iVar4 = 0; n - iVar4 != 0 && iVar4 <= (int)n; iVar4 = iVar4 + 1) {
                *pbVar11 = *pbVar11 & DAT_20003698;
                pbVar11 = pbVar11 + 1;
              }
            }
            bVar20 = false;
            if ((uVar10 >> 1 < uVar15) && (uVar14 < param_8 - 1)) {
              local_2e8[0] = 0x20;
              local_2e8[1] = 0x2c;
              local_2e8[2] = 0x2e;
              local_2e8[3] = 0x3f;
              local_2e8[4] = 0x21;
              iVar4 = 0;
              puVar6 = local_2e8;
LAB_00047a98:
              if (*puVar6 != uVar16) goto code_r0x00047aa0;
              if (uVar16 == 0) goto LAB_000479d4;
              puVar6 = local_2dc;
              puVar2 = &DAT_0008bbee;
              do {
                puVar12 = puVar2;
                puVar8 = puVar6;
                uVar7 = puVar12[1];
                *(undefined4 *)puVar8 = *puVar12;
                *(undefined4 *)(puVar8 + 2) = uVar7;
                puVar6 = puVar8 + 4;
                puVar2 = puVar12 + 2;
              } while (puVar12 + 2 != &DAT_0008bbf6);
              uVar1 = *(ushort *)(puVar12 + 3);
              uVar9 = uVar18 + 1;
              *(undefined **)(puVar8 + 4) = &DAT_000d0021;
              puVar8[6] = uVar1;
              uVar16 = uVar9;
LAB_00047ad2:
              if ((int)uVar16 < (int)(uint)local_302) {
                iVar4 = 0;
                puVar6 = local_2dc;
LAB_00047ae2:
                if (puVar3[uVar16] != *puVar6) goto LAB_00047afc;
                if (puVar3[uVar16] == 0) goto LAB_00047b02;
                if (0x28 < (int)(uVar16 - uVar18)) {
                  if (LOG_LEVEL < 2) goto LAB_000479d4;
                  fmt = "%s(): The word is too long and will not be processed\n";
                  goto LAB_00047b18;
                }
                iVar4 = 0;
                while ((int)uVar9 < (int)uVar16) {
                  puVar6 = puVar3 + uVar9;
                  uVar9 = uVar9 + 1;
                  if (0x25cc < *puVar6) {
                    iVar4 = iVar4 + 1;
                  }
                }
                if (uVar18 == uVar16) {
                  if (1 < LOG_LEVEL) {
                    fmt = "%s(): !!! end_split_character_index == start_split_character_index\n";
LAB_00047b18:
                    if (BLE_DEBUG == 0) {
                      printk(fmt);
                    }
                    else {
                      ble_printk(fmt,"gui_utf_Wordwrap_draw",uVar9,BLE_DEBUG);
                    }
                  }
                }
                else {
                  if ((iVar4 != 0) &&
                     (-1 < (int)((uint)((float)(longlong)iVar4 /
                                        (float)(longlong)(int)(uVar16 - uVar18) < 0.5) << 0x1f)))
                  goto LAB_000479d4;
                  local_2f4[0] = 0;
                  local_2f4[1] = 0;
                  puVar6 = puVar17;
                  local_318 = uVar15;
                  for (local_314 = uVar18; (int)local_314 <= (int)uVar16; local_314 = local_314 + 1)
                  {
                    iVar4 = resource_manger_get(param_3,(uint)*puVar6,local_2f4,local_2f4 + 1,
                                                local_2f4 + 2,(undefined1 *)0x0);
                    if (iVar4 == 0) {
                      iVar4 = FUN_000462b0((uint)*puVar6,(uint)puVar6[1]);
                      local_318 = local_318 + iVar4 + local_2f4[0];
                    }
                    if (uVar10 < local_318) {
                      bVar20 = true;
                      break;
                    }
                    puVar6 = puVar6 + 1;
                  }
                }
              }
            }
LAB_000479d4:
            iVar4 = FUN_000462b0((uint)*puVar17,(uint)puVar17[1]);
            uVar15 = uVar15 + iVar4 + local_2fc;
            if (uVar10 < uVar15) {
              uVar13 = uVar13 + local_2f8;
              if (param_3 == 0) {
                uVar13 = uVar13 + 1;
              }
              uVar14 = uVar14 + 1;
              if ((param_8 <= uVar14) || ((uint)(param_7 - param_5) <= uVar13)) break;
              FUN_00080c02(DAT_2000aa14,local_2cc,(int)local_2fc / 2,local_2f8,param_4,
                           uVar13 + param_5);
              iVar4 = FUN_000462b0((uint)*puVar17,(uint)puVar17[1]);
              uVar15 = iVar4 + local_2fc;
              uVar19 = uVar15;
            }
            else {
              FUN_00080c02(DAT_2000aa14,local_2cc,(int)local_2fc / 2,local_2f8,param_4 + uVar19,
                           uVar13 + param_5);
              iVar4 = FUN_000462b0((uint)*puVar17,(uint)puVar17[1]);
              uVar19 = uVar19 + iVar4 + local_2fc;
            }
LAB_00047a3a:
            if (bVar20) goto LAB_00047a3c;
          }
        }
        else if (iVar4 == -1) {
          if (uVar16 != 10) {
            bVar20 = uVar16 == 0xd;
            goto LAB_00047a3a;
          }
LAB_00047a3c:
          if (local_2f8 == 0) {
            if (param_3 == 0) {
              uVar13 = uVar13 + 0x1b;
            }
            else {
              uVar13 = uVar13 + 0x1a;
            }
          }
          else {
            uVar13 = uVar13 + local_2f8;
            if (param_3 == 0) {
              uVar13 = uVar13 + 1;
            }
          }
          uVar14 = uVar14 + 1;
          if ((param_8 <= uVar14) || ((uint)(param_7 - param_5) <= uVar13)) break;
          uVar15 = 0;
          uVar19 = uVar15;
        }
        puVar17 = puVar17 + 1;
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
  else if (param_11 != (undefined *)0x0) goto LAB_00047c4c;
  return 0;
code_r0x00047aa0:
  iVar4 = iVar4 + 1;
  puVar6 = puVar6 + 1;
  if (iVar4 == 5) goto LAB_000479d4;
  goto LAB_00047a98;
LAB_00047afc:
  iVar4 = iVar4 + 1;
  puVar6 = puVar6 + 1;
  if (iVar4 == 7) goto LAB_00047b02;
  goto LAB_00047ae2;
LAB_00047b02:
  uVar16 = uVar16 + 1;
  goto LAB_00047ad2;
}



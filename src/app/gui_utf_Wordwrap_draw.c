/*
 * Function: gui_utf_Wordwrap_draw
 * Entry:    000478a0
 * Prototype: undefined4 __stdcall gui_utf_Wordwrap_draw(undefined4 param_1, char * param_2, uint param_3, int param_4, int param_5, int param_6, int param_7, uint param_8, uint param_9, int param_10, undefined * param_11, int param_12)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
gui_utf_Wordwrap_draw
          (undefined4 param_1,char *param_2,uint param_3,int param_4,int param_5,int param_6,
          int param_7,uint param_8,uint param_9,int param_10,undefined *param_11,int param_12)

{
  ushort uVar1;
  undefined **ppuVar2;
  ushort *puVar3;
  int iVar4;
  GlassesState *pGVar5;
  ushort *puVar6;
  char *fmt;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 extraout_r2;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  undefined **ppuVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  ushort *puVar18;
  size_t n;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  uint in_fpscr;
  float fVar22;
  float fVar23;
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
  puVar3 = (ushort *)FUN_0004b160(param_2,&local_302);
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
        _clean_fb_data(__frame_buffer,0,param_4,param_5,param_6,param_7);
      }
      uVar15 = 0;
      uVar16 = 0;
      uVar14 = 0;
      uVar20 = 0;
      uVar11 = param_6 - param_4;
      puVar18 = puVar3;
      for (uVar19 = 0; (int)uVar19 < (int)(uint)local_302; uVar19 = uVar19 + 1) {
        uVar17 = (uint)*puVar18;
        iVar4 = FUN_00080fb2(uVar17);
        if (iVar4 == 0) {
          iVar4 = resource_manger_get(param_3,uVar17,&local_2fc,&local_2f8,&local_300,
                                      (undefined1 *)0x0);
          if (iVar4 < 0) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): can not find 0x%x font resource\n");
              }
              else {
                ble_printk("%s(): can not find 0x%x font resource\n","gui_utf_Wordwrap_draw",uVar17,
                           BLE_DEBUG);
              }
            }
          }
          else {
            n = local_2f8 * ((int)local_2fc / 2);
            memcpy(local_2cc,local_300,n);
            if (uVar19 < param_9) {
              pbVar12 = local_2cc;
              for (iVar4 = 0; n - iVar4 != 0 && iVar4 <= (int)n; iVar4 = iVar4 + 1) {
                *pbVar12 = *pbVar12 & DAT_20003698;
                pbVar12 = pbVar12 + 1;
              }
            }
            bVar21 = false;
            if ((uVar11 >> 1 < uVar16) && (uVar15 < param_8 - 1)) {
              local_2e8[0] = 0x20;
              local_2e8[1] = 0x2c;
              local_2e8[2] = 0x2e;
              local_2e8[3] = 0x3f;
              local_2e8[4] = 0x21;
              iVar4 = 0;
              puVar6 = local_2e8;
LAB_00047a98:
              if (*puVar6 != uVar17) goto code_r0x00047aa0;
              if (uVar17 == 0) goto LAB_000479d4;
              puVar6 = local_2dc;
              ppuVar2 = (undefined **)&DAT_0008bbee;
              do {
                ppuVar13 = ppuVar2;
                puVar9 = puVar6;
                puVar8 = ppuVar13[1];
                *(undefined **)puVar9 = *ppuVar13;
                *(undefined **)(puVar9 + 2) = puVar8;
                puVar6 = puVar9 + 4;
                ppuVar2 = ppuVar13 + 2;
              } while (ppuVar13 + 2 != &PTR_DAT_0008bbf6);
              uVar1 = *(ushort *)(ppuVar13 + 3);
              uVar10 = uVar19 + 1;
              *(undefined **)(puVar9 + 4) = &DAT_000d0021;
              puVar9[6] = uVar1;
              uVar17 = uVar10;
LAB_00047ad2:
              if ((int)uVar17 < (int)(uint)local_302) {
                iVar4 = 0;
                puVar6 = local_2dc;
LAB_00047ae2:
                if (puVar3[uVar17] != *puVar6) goto LAB_00047afc;
                if (puVar3[uVar17] == 0) goto LAB_00047b02;
                if (0x28 < (int)(uVar17 - uVar19)) {
                  if (LOG_LEVEL < 2) goto LAB_000479d4;
                  fmt = "%s(): The word is too long and will not be processed\n";
                  goto LAB_00047b18;
                }
                iVar4 = 0;
                while ((int)uVar10 < (int)uVar17) {
                  puVar6 = puVar3 + uVar10;
                  uVar10 = uVar10 + 1;
                  if (0x25cc < *puVar6) {
                    iVar4 = iVar4 + 1;
                  }
                }
                if (uVar19 == uVar17) {
                  if (1 < LOG_LEVEL) {
                    fmt = "%s(): !!! end_split_character_index == start_split_character_index\n";
LAB_00047b18:
                    if (BLE_DEBUG == 0) {
                      printk(fmt);
                    }
                    else {
                      ble_printk(fmt,"gui_utf_Wordwrap_draw",uVar10,BLE_DEBUG);
                    }
                  }
                }
                else {
                  if (iVar4 != 0) {
                    fVar23 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
                    fVar22 = (float)VectorSignedToFloat(uVar17 - uVar19,(byte)(in_fpscr >> 0x16) & 3
                                                       );
                    in_fpscr = in_fpscr & 0xfffffff;
                    if (0.5 <= fVar23 / fVar22) goto LAB_000479d4;
                  }
                  local_2f4[0] = 0;
                  local_2f4[1] = 0;
                  puVar6 = puVar18;
                  local_318 = uVar16;
                  for (local_314 = uVar19; (int)local_314 <= (int)uVar17; local_314 = local_314 + 1)
                  {
                    iVar4 = resource_manger_get(param_3,(uint)*puVar6,local_2f4,local_2f4 + 1,
                                                local_2f4 + 2,(undefined1 *)0x0);
                    if (iVar4 == 0) {
                      iVar4 = FUN_000462b0((uint)*puVar6,(uint)puVar6[1]);
                      local_318 = local_318 + iVar4 + local_2f4[0];
                    }
                    if (uVar11 < local_318) {
                      bVar21 = true;
                      break;
                    }
                    puVar6 = puVar6 + 1;
                  }
                }
              }
            }
LAB_000479d4:
            iVar4 = FUN_000462b0((uint)*puVar18,(uint)puVar18[1]);
            uVar16 = uVar16 + iVar4 + local_2fc;
            if (uVar11 < uVar16) {
              uVar14 = uVar14 + local_2f8;
              if (param_3 == 0) {
                uVar14 = uVar14 + 1;
              }
              uVar15 = uVar15 + 1;
              if ((param_8 <= uVar15) || ((uint)(param_7 - param_5) <= uVar14)) break;
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,(int)local_2fc / 2,local_2f8,param_4,
                         uVar14 + param_5);
              iVar4 = FUN_000462b0((uint)*puVar18,(uint)puVar18[1]);
              uVar16 = iVar4 + local_2fc;
              uVar20 = uVar16;
            }
            else {
              __copy_to_frame_buffer
                        ((int)__frame_buffer,local_2cc,(int)local_2fc / 2,local_2f8,param_4 + uVar20
                         ,uVar14 + param_5);
              iVar4 = FUN_000462b0((uint)*puVar18,(uint)puVar18[1]);
              uVar20 = uVar20 + iVar4 + local_2fc;
            }
LAB_00047a3a:
            if (bVar21) goto LAB_00047a3c;
          }
        }
        else if (iVar4 == -1) {
          if (uVar17 != 10) {
            bVar21 = uVar17 == 0xd;
            goto LAB_00047a3a;
          }
LAB_00047a3c:
          if (local_2f8 == 0) {
            if (param_3 == 0) {
              uVar14 = uVar14 + 0x1b;
            }
            else {
              uVar14 = uVar14 + 0x1a;
            }
          }
          else {
            uVar14 = uVar14 + local_2f8;
            if (param_3 == 0) {
              uVar14 = uVar14 + 1;
            }
          }
          uVar15 = uVar15 + 1;
          if ((param_8 <= uVar15) || ((uint)(param_7 - param_5) <= uVar14)) break;
          uVar16 = 0;
          uVar20 = uVar16;
        }
        puVar18 = puVar18 + 1;
      }
      iVar4 = FUN_000452e4();
      if (iVar4 << 0x1e < 0) {
        pGVar5 = __get_dashboard_state();
        iVar4 = *(int *)&(pGVar5->jdb_panel_context).field_0x348;
        pGVar5 = __get_dashboard_state();
        _reflash_fb_data_to_lcd
                  (iVar4,*(int *)&(pGVar5->jdb_panel_context).field_0x34c,param_4,param_5,param_6,
                   param_7);
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
  uVar17 = uVar17 + 1;
  goto LAB_00047ad2;
}



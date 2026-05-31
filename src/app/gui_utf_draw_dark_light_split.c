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
  undefined4 extraout_r2;
  size_t n;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
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
          printk("%s(): exex process effect callback function\n");
        }
        else {
          ble_printk("%s(): exex process effect callback function\n","gui_utf_draw_dark_light_split"
                     ,extraout_r2,BLE_DEBUG);
        }
      }
      (*(code *)param_11)(0,param_2,param_3,param_4,param_5);
      return;
    }
    if (param_12 == 0) {
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        _clean_fb_data(DAT_2000aa14,0,param_4,param_5,param_6,param_7);
      }
      uVar11 = 0;
      uVar14 = 0;
      uVar9 = 0;
      uVar13 = 0;
      for (local_2ec = 0; local_2ec < (int)(uint)local_2da; local_2ec = local_2ec + 1) {
        puVar10 = puVar4 + 1;
        uVar12 = (uint)*puVar4;
        iVar5 = FUN_00080fb2(uVar12);
        if (iVar5 == 0) {
          if (uVar12 == uVar7) {
            uVar12 = uVar7;
            if (DAT_2001db46 == '\0') {
              DAT_2001db46 = '\x01';
              if (1 < LOG_LEVEL) {
                fmt = "%s(): dark_light_flag 1 code = 0x%x\n";
LAB_00046a8c:
                if (BLE_DEBUG == 0) {
                  printk(fmt);
                }
                else {
                  ble_printk(fmt,"gui_utf_draw_dark_light_split",uVar12,BLE_DEBUG);
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
            iVar5 = resource_manger_get(param_3,uVar12,&local_2d4,&local_2d0,&local_2d8,
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
              iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar10);
              uVar14 = uVar14 + uVar2 + iVar5;
              if ((uint)(param_6 - param_4) < uVar14) {
                uVar9 = uVar9 + uVar3;
                if (param_3 == 0) {
                  uVar9 = uVar9 + 1;
                }
                uVar11 = uVar11 + 1;
                if ((param_8 <= uVar11) || ((uint)(param_7 - param_5) <= uVar9)) break;
                FUN_00080c02(DAT_2000aa14,local_2cc,sVar1,uVar3,param_4,uVar9 + param_5);
                iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar10);
                uVar13 = iVar5 + local_2d4;
                uVar14 = uVar13;
              }
              else {
                FUN_00080c02(DAT_2000aa14,local_2cc,sVar1,uVar3,uVar13 + param_4,uVar9 + param_5);
                iVar5 = FUN_000462b0((uint)*puVar4,(uint)*puVar10);
                uVar13 = uVar13 + iVar5 + local_2d4;
              }
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
          uVar11 = uVar11 + 1;
          if ((param_8 <= uVar11) || ((uint)(param_7 - param_5) <= uVar9)) break;
          uVar13 = 0;
          uVar14 = uVar13;
        }
        puVar4 = puVar10;
      }
      iVar5 = FUN_000452e4();
      if (iVar5 << 0x1e < 0) {
        pGVar6 = __get_dashboard_state();
        iVar5 = *(int *)&pGVar6->field_0xeb4;
        pGVar6 = __get_dashboard_state();
        _reflash_fb_data_to_lcd(iVar5,*(int *)&pGVar6->field_0xeb8,param_4,param_5,param_6,param_7);
      }
    }
  }
  else if (param_11 != (undefined *)0x0) goto LAB_00046c02;
  DAT_2001db46 = 0;
  return;
}



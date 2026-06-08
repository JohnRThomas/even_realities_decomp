/*
 * Function: resource_manger_get
 * Entry:    00047f4c
 * Prototype: undefined4 __stdcall resource_manger_get(uint param_1, uint param_2, uint * param_3, uint * param_4, undefined4 * param_5, undefined1 * param_6)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
resource_manger_get(uint param_1,uint param_2,uint *param_3,uint *param_4,undefined4 *param_5,
                   undefined1 *param_6)

{
  ushort uVar1;
  uint uVar2;
  GlassesState *pGVar3;
  uint uVar4;
  undefined *puVar5;
  char *pcVar6;
  uint *extraout_r2;
  uint *puVar7;
  uint *extraout_r2_00;
  uint *extraout_r2_01;
  uint *extraout_r2_02;
  uint *extraout_r2_03;
  uint *extraout_r2_04;
  uint *extraout_r2_05;
  uint *extraout_r2_06;
  uint *extraout_r2_07;
  uint *extraout_r2_08;
  uint *extraout_r2_09;
  int iVar8;
  code *pcVar9;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = param_1;
  local_24 = param_2;
  switch(param_1) {
  case 0:
    if ((int)param_2 < 0x2714) {
      puVar5 = FUN_00047f00(param_2 & 0xffff,&local_28,&local_24);
      *param_5 = puVar5;
      if (puVar5 != (undefined *)0x0) {
        *param_3 = local_28;
        *param_4 = local_24;
        return 0;
      }
    }
    if (0xff41 < param_2 - 0xa4) goto LAB_0004836a;
    pGVar3 = __get_dashboard_state();
    pcVar9 = *(code **)&pGVar3->field_0x1044;
    pGVar3 = __get_dashboard_state();
    iVar8 = (param_2 - 0xa4) * 4;
    uVar4 = (*pcVar9)(pGVar3,&DAT_00140000 + iVar8,&local_24);
    puVar7 = extraout_r2;
    if (uVar4 == 0) {
      uVar2 = local_24 >> 0x10;
      if (uVar2 == 0xffff) {
        if (param_2 - 0x1100 < 0xfa) {
          local_28 = uVar4;
          local_24 = uVar4;
          pGVar3 = __get_dashboard_state();
          pcVar9 = *(code **)&pGVar3->field_0x1044;
          pGVar3 = __get_dashboard_state();
          iVar8 = (*pcVar9)(pGVar3,iVar8 + 0xa1be90,&local_24);
          puVar7 = extraout_r2_00;
          if (iVar8 != 0) goto LAB_00047fc2;
          uVar1 = local_24._2_2_ << 8 | local_24._2_2_ >> 8;
          local_28 = CONCAT22(uVar1,(ushort)local_24 << 8 | (ushort)local_24 >> 8);
          if (local_24._2_2_ != 0xffff) {
            memset(&DAT_2001dbc9,0,0x138);
            pGVar3 = __get_dashboard_state();
            pcVar9 = *(code **)&pGVar3->field_0x1044;
            pGVar3 = __get_dashboard_state();
            param_2 = (*pcVar9)(pGVar3,&DAT_00a40000 + (uint)uVar1 * 0x138,&DAT_2001dbc9,0x138);
LAB_000480bc:
            if (param_2 == 0) {
              uVar4 = 0x18;
              goto LAB_0004803a;
            }
            goto LAB_00048018;
          }
LAB_00048378:
          if (0x5d < param_2 - 0xff01) {
            if (0x2e < param_2 - 0x2010) goto LAB_0004820e;
            pGVar3 = __get_dashboard_state();
            if (*(int *)&pGVar3->field_0x1044 != 0) {
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = (*pcVar9)(pGVar3,&DAT_00500000 + (param_2 - 0x2010) * 4,&local_24);
              puVar7 = extraout_r2_08;
              goto LAB_000484ba;
            }
            goto LAB_00048508;
          }
          pGVar3 = __get_dashboard_state();
          if (*(int *)&pGVar3->field_0x1044 != 0) {
            pGVar3 = __get_dashboard_state();
            pcVar9 = *(code **)&pGVar3->field_0x1044;
            pGVar3 = __get_dashboard_state();
            iVar8 = (*pcVar9)(pGVar3,param_2 * 4 + 0x9eba14,&local_24);
            puVar7 = extraout_r2_06;
            if (iVar8 != 0) goto LAB_00047fc2;
            uVar1 = local_24._2_2_;
            uVar4 = (uint)local_24._2_2_;
            if (uVar4 != 0xffff) {
              memset(&DAT_2001dbc9,0,0x138);
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              param_2 = (*pcVar9)(pGVar3,&DAT_00a40000 +
                                         ((uVar4 & 0xff) << 8 | (uint)(uVar1 >> 8)) * 0x138,
                                  &DAT_2001dbc9,0x138);
              goto LAB_000480bc;
            }
            if (0x19c < param_2 - 0x3231) goto LAB_00048328;
            goto LAB_0004840a;
          }
LAB_0004850e:
          pGVar3 = __get_dashboard_state();
          if (*(int *)&pGVar3->field_0x1044 != 0) {
            pGVar3 = __get_dashboard_state();
            pcVar9 = *(code **)&pGVar3->field_0x1044;
            pGVar3 = __get_dashboard_state();
            iVar8 = (*pcVar9)(pGVar3,param_2 * 4 + 0x4d58f8,&local_24);
            puVar7 = extraout_r2_09;
            if (iVar8 != 0) goto LAB_00047fc2;
            uVar4 = (local_24._2_2_ & 0xff) << 8 | (uint)(local_24._2_2_ >> 8);
            if (local_24._2_2_ != 0xffff) {
              memset(&DAT_2001dbc9,0,0x138);
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
LAB_00048474:
              param_2 = (*pcVar9)(pGVar3,&DAT_00520000 + uVar4 * 0xd0,&DAT_2001dbc9);
              goto LAB_000484fc;
            }
          }
        }
        else {
          if (param_2 - 0x302e < 2) {
            pGVar3 = __get_dashboard_state();
            if (*(int *)&pGVar3->field_0x1044 != 0) {
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = (*pcVar9)(pGVar3,iVar8 + 0xa145c0,&local_24);
              puVar7 = extraout_r2_02;
              if (iVar8 != 0) goto LAB_00047fc2;
              uVar4 = local_24 >> 0x10;
              if (uVar4 != 0xffff) goto LAB_0004814a;
LAB_0004820e:
              if (0xfd < param_2 - 0x3001) goto LAB_0004836a;
            }
            pGVar3 = __get_dashboard_state();
            if (*(int *)&pGVar3->field_0x1044 == 0) goto LAB_00048508;
            pGVar3 = __get_dashboard_state();
            pcVar9 = *(code **)&pGVar3->field_0x1044;
            pGVar3 = __get_dashboard_state();
            iVar8 = (*pcVar9)(pGVar3,param_2 * 4 + 0x4f40b8,&local_24);
            puVar7 = extraout_r2_01;
LAB_000484ba:
            if (iVar8 != 0) goto LAB_00047fc2;
            uVar1 = local_24._2_2_;
            uVar4 = (uint)local_24._2_2_;
            if (uVar4 == 0xffff) goto LAB_00048508;
            memset(&DAT_2001dbc9,0,0x138);
            pGVar3 = __get_dashboard_state();
            pcVar9 = *(code **)&pGVar3->field_0x1044;
            pGVar3 = __get_dashboard_state();
            param_2 = (*pcVar9)(pGVar3,&DAT_00520000 +
                                       ((uVar4 & 0xff) << 8 | (uint)(uVar1 >> 8)) * 0xd0,
                                &DAT_2001dbc9);
LAB_000484fc:
            if (param_2 == 0) {
              uVar4 = 0x10;
LAB_0004803a:
              *param_3 = uVar4;
              *param_4 = 0x1a;
              *param_5 = &DAT_2001dbc9;
              return 0;
            }
            goto LAB_00048018;
          }
          if (param_2 - 0x3131 < 0x5e) {
            pGVar3 = __get_dashboard_state();
            if (*(int *)&pGVar3->field_0x1044 != 0) {
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = (*pcVar9)(pGVar3,iVar8 + 0xa141bc,&local_24);
              puVar7 = extraout_r2_03;
              if (iVar8 == 0) {
                uVar1 = local_24._2_2_;
                uVar4 = (uint)local_24._2_2_;
                if (uVar4 == 0xffff) goto LAB_0004820e;
                memset(&DAT_2001dbc9,0,0x138);
                pGVar3 = __get_dashboard_state();
                pcVar9 = *(code **)&pGVar3->field_0x1044;
                pGVar3 = __get_dashboard_state();
                param_2 = (*pcVar9)(pGVar3,&DAT_00a40000 +
                                           ((uVar4 & 0xff) << 8 | (uint)(uVar1 >> 8)) * 0x138,
                                    &DAT_2001dbc9,0x138);
                if (param_2 == 0) {
                  *param_3 = 0x18;
                  *param_4 = 0x1a;
                  *param_5 = &DAT_2001dbc9;
                  return 0;
                }
                goto LAB_00048018;
              }
              goto LAB_00047fc2;
            }
LAB_0004836a:
            if (param_2 - 0x3231 < 0x19d) {
LAB_0004840a:
              pGVar3 = __get_dashboard_state();
              if (*(int *)&pGVar3->field_0x1044 == 0) goto LAB_00048508;
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = 0x4f3bf0;
            }
            else {
LAB_000482e6:
              if (0x5177 < param_2 - 0x4e00) goto LAB_00048328;
              pGVar3 = __get_dashboard_state();
              if (*(int *)&pGVar3->field_0x1044 == 0) goto LAB_00048508;
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = 0x4ed328;
            }
LAB_00048434:
            iVar8 = (*pcVar9)(pGVar3,iVar8 + param_2 * 4,&local_24);
            puVar7 = extraout_r2_07;
            if (iVar8 != 0) goto LAB_00047fc2;
            uVar1 = local_24._2_2_;
            uVar4 = (uint)local_24._2_2_;
            if (uVar4 != 0xffff) {
              memset(&DAT_2001dbc9,0,0x138);
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              uVar4 = (uVar4 & 0xff) << 8 | (uint)(uVar1 >> 8);
              goto LAB_00048474;
            }
          }
          else {
            if (param_2 - 0x3200 < 0x80) {
              pGVar3 = __get_dashboard_state();
              if (*(int *)&pGVar3->field_0x1044 != 0) {
                pGVar3 = __get_dashboard_state();
                pcVar9 = *(code **)&pGVar3->field_0x1044;
                pGVar3 = __get_dashboard_state();
                iVar8 = (*pcVar9)(pGVar3,iVar8 + 0xa13ff8,&local_24);
                puVar7 = extraout_r2_04;
                if (iVar8 != 0) goto LAB_00047fc2;
                uVar4 = local_24 >> 0x10;
                if (uVar4 != 0xffff) {
LAB_0004814a:
                  memset(&DAT_2001dbc9,0,0x138);
                  pGVar3 = __get_dashboard_state();
                  pcVar9 = *(code **)&pGVar3->field_0x1044;
                  pGVar3 = __get_dashboard_state();
                  param_2 = (*pcVar9)(pGVar3,&DAT_00a40000 +
                                             ((uVar4 & 0xff) << 8 | uVar4 >> 8) * 0x138,
                                      &DAT_2001dbc9,0x138);
                  goto LAB_000480bc;
                }
              }
              goto LAB_0004836a;
            }
            if (0x2bab < param_2 - 0xac00) goto LAB_00048378;
            pGVar3 = __get_dashboard_state();
            if (*(int *)&pGVar3->field_0x1044 != 0) {
              pGVar3 = __get_dashboard_state();
              pcVar9 = *(code **)&pGVar3->field_0x1044;
              pGVar3 = __get_dashboard_state();
              iVar8 = (*pcVar9)(pGVar3,iVar8 + 0x9f59f8,&local_24);
              puVar7 = extraout_r2_05;
              if (iVar8 != 0) goto LAB_00047fc2;
              uVar4 = local_24 >> 0x10;
              if (uVar4 != 0xffff) goto LAB_0004814a;
              goto LAB_000482e6;
            }
LAB_00048328:
            if (param_2 - 0xe001 < 0xfd) {
              pGVar3 = __get_dashboard_state();
              if (*(int *)&pGVar3->field_0x1044 != 0) {
                pGVar3 = __get_dashboard_state();
                pcVar9 = *(code **)&pGVar3->field_0x1044;
                pGVar3 = __get_dashboard_state();
                iVar8 = 0x4dd104;
                goto LAB_00048434;
              }
            }
            else {
LAB_00048508:
              if (param_2 - 0xff01 < 0x9f) goto LAB_0004850e;
            }
          }
        }
        if (LOG_LEVEL < 3) {
          return 0xffffffff;
        }
        pcVar6 = "%s(): *************** can\'t find resEncode = 0x%02x*****************\n";
      }
      else {
        memset(&DAT_2001dbc9,0,0x138);
        pGVar3 = __get_dashboard_state();
        pcVar9 = *(code **)&pGVar3->field_0x1044;
        pGVar3 = __get_dashboard_state();
        param_2 = (*pcVar9)(pGVar3,uVar2 * 0xea + 0x200000,&DAT_2001dbc9);
        if (param_2 == 0) {
          uVar4 = 0x12;
          goto LAB_0004803a;
        }
LAB_00048018:
        if (LOG_LEVEL < 1) {
          return 0xffffffff;
        }
        pcVar6 = "%s(): read flash fail: %d\n\n";
      }
      if (BLE_DEBUG == 0) {
        printk(pcVar6);
        return 0xffffffff;
      }
      ble_printk(pcVar6,"resource_manger_get",param_2,BLE_DEBUG);
      return 0xffffffff;
    }
LAB_00047fc2:
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    pcVar6 = "%s(): read flash fail\n\n";
    goto LAB_00047fd2;
  case 1:
    puVar5 = FUN_00047e70(param_2 & 0xffff,&local_28,&local_24);
    *param_5 = puVar5;
    if (puVar5 != (undefined *)0x0) {
      *param_3 = local_28;
      *param_4 = local_24;
      return 0;
    }
    break;
  case 2:
    puVar5 = FUN_00047e24(param_2 & 0xffff,&local_28,&local_24);
    *param_5 = puVar5;
    if (puVar5 != (undefined *)0x0) {
      *param_3 = local_28;
      *param_4 = local_24;
      return 0;
    }
    break;
  case 3:
    puVar5 = FUN_00047eb4(param_2 & 0xffff,&local_28,&local_24);
    *param_5 = puVar5;
    *param_3 = local_28;
    *param_4 = local_24;
    return 0;
  case 4:
    if (param_2 - 0x16 < 0x72) {
      switch(param_2) {
      case 0x16:
        *param_5 = &DAT_000cc039;
        *param_3 = 0x18;
        *param_4 = 0x1a;
        return 0;
      case 0x17:
        *param_5 = &DAT_000cbff8;
        *param_3 = 10;
        *param_4 = 0xd;
        return 0;
      case 0x18:
        *param_5 = &DAT_000ccf6d;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x19:
        *param_5 = &DAT_000ccea5;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x1a:
        *param_5 = &DAT_000ccddd;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x1b:
        *param_5 = &DAT_000cbef4;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x1c:
        *param_5 = &DAT_000bfcd9;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x1d:
        *param_5 = &DAT_000bfbef;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x1e:
        *param_5 = &DAT_000bfb05;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x1f:
        *param_5 = &DAT_000bfa1b;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x20:
        *param_5 = &DAT_000bf931;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x21:
        *param_5 = &DAT_000bf847;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x22:
        *param_5 = &DAT_000bf75d;
        *param_3 = 0x12;
        *param_4 = 0x1a;
        return 0;
      case 0x23:
        *param_5 = &DAT_000ce075;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x24:
        *param_5 = &DAT_000cdf71;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x25:
        *param_5 = &DAT_000cde6d;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x26:
        *param_5 = &DAT_000cdd69;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x27:
        *param_5 = &DAT_000cdc65;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x28:
        *param_5 = &DAT_000cdb61;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x29:
        *param_5 = &DAT_000cda5d;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2a:
        *param_5 = &DAT_000cd959;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2b:
        *param_5 = &DAT_000cd855;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2c:
        *param_5 = &DAT_000cd751;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2d:
        *param_5 = &DAT_000cd64d;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2e:
        *param_5 = &DAT_000cd549;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x2f:
        *param_5 = &DAT_000cd445;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x30:
        *param_5 = &DAT_000cd341;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x31:
        *param_5 = &DAT_000cd23d;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x32:
        *param_5 = &DAT_000cd139;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x33:
        *param_5 = &DAT_000cd035;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      default:
        return 0xffffffff;
      case 0x36:
        *param_5 = &DAT_000ccd15;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x37:
        *param_5 = &DAT_000ccc4d;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x38:
        *param_5 = &DAT_000ccb85;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x39:
        *param_5 = &DAT_000ccabd;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x3a:
        *param_5 = &DAT_000cc9f5;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x3b:
        *param_5 = &DAT_000cc8f1;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x3c:
        *param_5 = &DAT_000cc7ed;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x3e:
        *param_5 = &DAT_000cbdf0;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x3f:
        *param_5 = &DAT_000cbd28;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x40:
        *param_5 = &DAT_000cc171;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x41:
        *param_5 = &DAT_000cbab8;
        *param_3 = 0x30;
        *param_4 = 0x1a;
        return 0;
      case 0x42:
        *param_5 = &DAT_000cc6e9;
        *param_3 = 0x14;
        *param_4 = 0x1a;
        return 0;
      case 0x43:
        *param_5 = &DAT_000cc621;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x44:
        *param_5 = &DAT_000cc559;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x45:
        *param_5 = &DAT_000cc491;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x46:
        *param_5 = &DAT_000cc3c9;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x47:
        *param_5 = &DAT_000cc301;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x48:
        *param_5 = &DAT_000cc239;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x49:
        *param_5 = &DAT_000cb358;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4a:
        *param_5 = &DAT_000cb290;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4b:
        *param_5 = &DAT_000cb1c8;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4c:
        *param_5 = &DAT_000cb100;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4d:
        *param_5 = &DAT_000cb038;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4e:
        *param_5 = &DAT_000caf70;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x4f:
        *param_5 = &DAT_000caea8;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x50:
        *param_5 = &DAT_000cade0;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x51:
        *param_5 = &DAT_000cad18;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x52:
        *param_5 = &DAT_000cac50;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x53:
        *param_5 = &DAT_000cab88;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x54:
        *param_5 = &DAT_000caac0;
        *param_3 = 0x14;
        *param_4 = 0x14;
        return 0;
      case 0x55:
        *param_5 = &DAT_000cb926;
        *param_3 = 0x192;
        *param_4 = 2;
        return 0;
      case 0x56:
        *param_5 = &PTR_DAT_000cb7ec;
        *param_3 = 0x13a;
        *param_4 = 2;
        return 0;
      case 0x57:
        *param_5 = &DAT_000cb65a;
        *param_3 = 0x192;
        *param_4 = 2;
        return 0;
      case 0x58:
        *param_5 = &DAT_000cb520;
        *param_3 = 0x13a;
        *param_4 = 2;
        return 0;
      case 0x59:
        *param_5 = &DAT_000cb4a0;
        *param_3 = 2;
        *param_4 = 0x80;
        return 0;
      case 0x5a:
        *param_5 = &DAT_000cb420;
        *param_3 = 2;
        *param_4 = 0x80;
        return 0;
      case 0x5b:
        *param_5 = "\"\"\"\"\"\"\"\"\"\"\"";
        *param_3 = 10;
        *param_4 = 10;
        return 0;
      case 0x5c:
        *param_5 = &DAT_000caa01;
        *param_3 = 10;
        *param_4 = 10;
        return 0;
      case 0x5d:
        *param_5 = "\"\"\"\"\"\"\"\"\"\"";
        *param_3 = 10;
        *param_4 = 10;
        return 0;
      case 0x5e:
        *param_5 = &DAT_000ca99d;
        *param_3 = 10;
        *param_4 = 10;
        return 0;
      case 0x5f:
        *param_5 = &DAT_000caa65;
        *param_3 = 0xe;
        *param_4 = 0xd;
        return 0;
      case 0x61:
        *param_5 = &DAT_000ca4bb;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x62:
        *param_5 = &DAT_000c9fd9;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 99:
        *param_5 = &DAT_000c9af7;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 100:
        *param_5 = &DAT_000c9615;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x65:
        *param_5 = &DAT_000c9133;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x66:
        *param_5 = &DAT_000c8c51;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x67:
        *param_5 = &DAT_000c876f;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x68:
        *param_5 = &DAT_000c828d;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x69:
        *param_5 = &DAT_000c7dab;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6a:
        *param_5 = &DAT_000c78c9;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6b:
        *param_5 = &DAT_000c73e7;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6c:
        *param_5 = &DAT_000c6f05;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6d:
        *param_5 = &DAT_000c6a23;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6e:
        *param_5 = &DAT_000c6541;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x6f:
        *param_5 = &DAT_000c605f;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x70:
        *param_5 = &DAT_000c5b7d;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x71:
        *param_5 = &DAT_000c569b;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x72:
        *param_5 = &DAT_000c51b9;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x73:
        *param_5 = &DAT_000c4cd7;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x74:
        *param_5 = &DAT_000c47f5;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x75:
        *param_5 = &DAT_000c4313;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x76:
        *param_5 = &DAT_000c3e31;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x77:
        *param_5 = &DAT_000c394f;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x78:
        *param_5 = &DAT_000c346d;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x79:
        *param_5 = &DAT_000c2f8b;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7a:
        *param_5 = &DAT_000c2aa9;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7b:
        *param_5 = &DAT_000c25c7;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7c:
        *param_5 = &DAT_000c20e5;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7d:
        *param_5 = &DAT_000c1c03;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7e:
        *param_5 = &DAT_000c1721;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x7f:
        *param_5 = &DAT_000c123f;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x80:
        *param_5 = &DAT_000c0d5d;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x81:
        *param_5 = &DAT_000c087b;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x82:
        *param_5 = &DAT_000c0399;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x83:
        *param_5 = &DAT_000bfeb7;
        *param_3 = 0x32;
        *param_4 = 0x32;
        return 0;
      case 0x85:
        *param_5 = &DAT_000bfea6;
        *param_3 = 0x22;
        *param_4 = 1;
        return 0;
      case 0x86:
        *param_5 = &DAT_000bfe90;
        *param_3 = 0x2c;
        *param_4 = 1;
        return 0;
      case 0x87:
        *param_5 = &DAT_000bfdc3;
        *param_3 = 0x19a;
        *param_4 = 1;
        return 0;
      }
    }
    if (LOG_LEVEL < 2) {
      return 0xffffffff;
    }
    pcVar6 = "%s(): can\'t find resource ,exit .....\n";
    puVar7 = param_3;
LAB_00047fd2:
    if (BLE_DEBUG == 0) {
      printk(pcVar6);
    }
    else {
      ble_printk(pcVar6,"resource_manger_get",puVar7,BLE_DEBUG);
    }
    break;
  case 5:
    switch(param_2) {
    case 1:
      *param_5 = &DAT_000d83e5;
      *param_3 = 0x14;
      *param_4 = 0x1a;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x2d;
      }
      break;
    case 2:
      puVar5 = &DAT_000d72b5;
      goto LAB_00049054;
    case 3:
      puVar5 = &DAT_000d6185;
LAB_00049054:
      *param_5 = puVar5;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x16;
      }
      break;
    case 4:
      *param_5 = &DAT_000d55cd;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0xf;
      }
      break;
    case 5:
      *param_5 = &DAT_000d4ec5;
      *param_3 = 0x14;
      goto LAB_0004908e;
    case 6:
      *param_5 = &DAT_000d46f5;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 10;
      }
      break;
    case 7:
      *param_5 = &DAT_000d3f39;
      *param_3 = 0x16;
LAB_0004908e:
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 9;
      }
      break;
    case 8:
      *param_5 = &DAT_000d24a9;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x22;
      }
      break;
    case 9:
      *param_5 = &DAT_000d15d1;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x13;
      }
      break;
    case 10:
      *param_5 = &DAT_000d0889;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x11;
      }
      break;
    case 0xb:
      *param_5 = &DAT_000cf821;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x15;
      }
      break;
    case 0xc:
      *param_5 = &DAT_000ce179;
      *param_3 = 0x14;
      *param_4 = 0x14;
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0x1d;
      }
      break;
    default:
      goto switchD_00047f5e_default;
    }
    return 0;
  }
switchD_00047f5e_default:
  return 0xffffffff;
}



/*
 * Function: SettingStoreHandler
 * Entry:    000260f4
 * Prototype: uint __stdcall SettingStoreHandler(void)
 */


uint SettingStoreHandler(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *fmt;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 uVar5;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  bool bVar9;
  undefined2 local_24;
  byte local_22;
  undefined1 local_20 [4];
  byte local_1c;
  
  iVar2 = z_impl_k_msgq_get((k_msgq *)&DAT_20003b34,local_20,(k_timeout_t)0x0);
  if (iVar2 == 0) {
    uVar5 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received setting command .\n");
        uVar5 = extraout_r2_03;
      }
      else {
        ble_printk("%s(): received setting command .\n","SettingStoreHandler",extraout_r2,BLE_DEBUG)
        ;
        uVar5 = extraout_r2_02;
      }
    }
    uVar6 = 0;
    switch(local_20[0]) {
    case 1:
      uVar6 = (uint)local_1c;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): start setting  parameter check. language type = %d\n");
          uVar5 = extraout_r2_05;
        }
        else {
          ble_printk("%s(): start setting  parameter check. language type = %d\n",
                     "SettingStoreHandler",uVar6,BLE_DEBUG);
          uVar5 = extraout_r2_04;
        }
      }
      if (uVar6 - 1 < 0x19) {
        if (BYTE_20019131 == uVar6) {
          bVar9 = SBORROW4(LOG_LEVEL,2);
          iVar2 = LOG_LEVEL + -2;
          bVar1 = LOG_LEVEL == 2;
          goto LAB_000261b4;
        }
        bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
        if (bVar1) {
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar8 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            local_24 = CONCAT11(local_1c,0xaa);
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x104c;
            pGVar4 = __get_dashboard_state();
            uVar6 = (*pcVar8)(pGVar4,0x13e000,0x1000);
            if (uVar6 != 0) goto LAB_00026234;
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x1048;
            pGVar4 = __get_dashboard_state();
            uVar6 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
            if (uVar6 != 0) goto LAB_00026264;
            local_24 = 0;
            local_22 = 0;
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x1044;
            pGVar4 = __get_dashboard_state();
            iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
            if (iVar2 == 0) {
              BYTE_20019131 = local_24._1_1_;
              uVar7 = 0;
              if (LOG_LEVEL < 3) {
                return 0;
              }
              uVar6 = (uint)local_24._1_1_;
              pcVar3 = "%s(): language infomation  %d store sucess\n";
              goto LAB_000262b6;
            }
          }
          goto LAB_00026368;
        }
LAB_000261ca:
        if (LOG_LEVEL < 1) break;
LAB_000261d2:
        pcVar3 = "mx25r6435f@0";
        fmt = "%s():  [%s] device not ready.\n\n";
        goto LAB_000261da;
      }
      if (0 < LOG_LEVEL) {
        pcVar3 = "%s(): Setting Task received error language parameters.\n";
        goto LAB_00026146;
      }
      break;
    case 2:
      bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
      if (bVar1) {
        local_24 = 0;
        local_22 = 0;
        pGVar4 = __get_dashboard_state();
        pcVar8 = *(code **)&pGVar4->field_0x1044;
        pGVar4 = __get_dashboard_state();
        iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
        if (iVar2 == 0) {
          local_24 = 0x2aa;
          pGVar4 = __get_dashboard_state();
          pcVar8 = *(code **)&pGVar4->field_0x104c;
          pGVar4 = __get_dashboard_state();
          uVar6 = (*pcVar8)(pGVar4,0x13e000,0x1000);
          if (uVar6 != 0) {
LAB_00026234:
            if (LOG_LEVEL < 3) {
              return uVar6;
            }
            pcVar3 = "%s(): Flash erase failed! %d\n\n";
            uVar7 = uVar6;
LAB_000262b6:
            if (BLE_DEBUG != 0) {
              ble_printk(pcVar3,"SettingStoreHandler",uVar6,BLE_DEBUG);
              return uVar7;
            }
            printk(pcVar3);
            return uVar7;
          }
          pGVar4 = __get_dashboard_state();
          pcVar8 = *(code **)&pGVar4->field_0x1048;
          pGVar4 = __get_dashboard_state();
          uVar6 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
          if (uVar6 != 0) {
LAB_00026264:
            if (LOG_LEVEL < 1) {
              return uVar6;
            }
            pcVar3 = "%s(): Flash write failed! %d\n\n";
            uVar7 = uVar6;
            goto LAB_000262b6;
          }
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar8 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): App language clean success.\n");
              }
              else {
                ble_printk("%s(): App language clean success.\n","SettingStoreHandler",
                           extraout_r2_06,BLE_DEBUG);
              }
            }
            BYTE_20019131 = 2;
            return 0;
          }
        }
        goto LAB_00026368;
      }
LAB_000262cc:
      if (0 < LOG_LEVEL) goto LAB_000261d2;
      break;
    case 3:
      uVar6 = (uint)local_1c;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): start setting  parameter check. startup_mode type = %d\n");
          uVar5 = extraout_r2_08;
        }
        else {
          ble_printk("%s(): start setting  parameter check. startup_mode type = %d\n",
                     "SettingStoreHandler",uVar6,BLE_DEBUG);
          uVar5 = extraout_r2_07;
        }
      }
      if (DAT_20019132 == uVar6) {
        bVar9 = false;
        bVar1 = LOG_LEVEL == 0;
        iVar2 = LOG_LEVEL;
LAB_000261b4:
        if (!bVar1 && iVar2 < 0 == bVar9) {
          pcVar3 = "%s(): Setting Task received same language parameters.drop it ..\n";
          goto LAB_00026146;
        }
      }
      else {
        if (uVar6 < 3) {
          bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
          if (!bVar1) goto LAB_000261ca;
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar8 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            local_22 = local_1c;
            local_24 = CONCAT11(local_24._1_1_,0xaa);
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x104c;
            pGVar4 = __get_dashboard_state();
            uVar6 = (*pcVar8)(pGVar4,0x13e000,0x1000);
            if (uVar6 != 0) goto LAB_00026234;
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x1048;
            pGVar4 = __get_dashboard_state();
            uVar6 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
            if (uVar6 != 0) goto LAB_00026264;
            local_24 = 0;
            local_22 = 0;
            pGVar4 = __get_dashboard_state();
            pcVar8 = *(code **)&pGVar4->field_0x1044;
            pGVar4 = __get_dashboard_state();
            iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
            if (iVar2 == 0) {
              DAT_20019132 = local_22;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): startup mode  infomation  %d store sucess\n");
                }
                else {
                  ble_printk("%s(): startup mode  infomation  %d store sucess\n",
                             "SettingStoreHandler",(uint)local_22,BLE_DEBUG);
                }
              }
              if (DAT_20019132 != 0) {
                return 0;
              }
              pGVar4 = __get_dashboard_state();
              if (pGVar4->field_0x1244 != '\x04') {
                return 0;
              }
              upgradeDoubleTapCustomizeToFlash(0,extraout_r1,extraout_r2_09);
              return 0;
            }
          }
          goto LAB_00026368;
        }
        if (0 < LOG_LEVEL) {
          pcVar3 = "%s(): dashboard startup mode value error,exit...\n";
          goto LAB_00026146;
        }
      }
      break;
    case 4:
      bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
      if (!bVar1) goto LAB_000262cc;
      local_24 = 0;
      local_22 = 0;
      pGVar4 = __get_dashboard_state();
      pcVar8 = *(code **)&pGVar4->field_0x1044;
      pGVar4 = __get_dashboard_state();
      iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
      if (iVar2 == 0) {
        local_22 = 0;
        local_24 = CONCAT11(local_24._1_1_,0xaa);
        pGVar4 = __get_dashboard_state();
        pcVar8 = *(code **)&pGVar4->field_0x104c;
        pGVar4 = __get_dashboard_state();
        uVar6 = (*pcVar8)(pGVar4,0x13e000,0x1000);
        if (uVar6 != 0) goto LAB_00026234;
        pGVar4 = __get_dashboard_state();
        pcVar8 = *(code **)&pGVar4->field_0x1048;
        pGVar4 = __get_dashboard_state();
        uVar6 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
        if (uVar6 != 0) goto LAB_00026264;
        local_24 = 0;
        local_22 = 0;
        pGVar4 = __get_dashboard_state();
        pcVar8 = *(code **)&pGVar4->field_0x1044;
        pGVar4 = __get_dashboard_state();
        iVar2 = (*pcVar8)(pGVar4,0x13e000,&local_24,3);
        if (iVar2 == 0) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): App language clean success.\n");
            }
            else {
              ble_printk("%s(): App language clean success.\n","SettingStoreHandler",extraout_r2_10,
                         BLE_DEBUG);
            }
          }
          DAT_20019132 = 0;
          return 0;
        }
      }
LAB_00026368:
      if (0 < LOG_LEVEL) {
        pcVar3 = (char *)0x13e000;
        fmt = "%s():  form address [%d] read data failed.\n\n";
LAB_000261da:
        if (BLE_DEBUG == 0) {
          printk(fmt);
        }
        else {
          ble_printk(fmt,"SettingStoreHandler",pcVar3,BLE_DEBUG);
        }
      }
      break;
    default:
      goto switchD_0002611c_default;
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): setting storage queue get failed\r\n\n");
      uVar5 = extraout_r2_01;
    }
    else {
      ble_printk("%s(): setting storage queue get failed\r\n\n","getSettingStorageQueueCacheData",
                 extraout_r2,BLE_DEBUG);
      uVar5 = extraout_r2_00;
    }
    if (0 < LOG_LEVEL) {
      pcVar3 = "%s(): setting storage get queue data failed\n";
LAB_00026146:
      if (BLE_DEBUG == 0) {
        printk(pcVar3);
      }
      else {
        ble_printk(pcVar3,"SettingStoreHandler",uVar5,BLE_DEBUG);
      }
    }
  }
  uVar6 = 0xffffffff;
switchD_0002611c_default:
  return uVar6;
}



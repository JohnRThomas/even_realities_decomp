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
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  bool bVar8;
  undefined2 local_24;
  byte local_22;
  undefined1 local_20 [4];
  byte local_1c;
  
  iVar2 = z_impl_k_msgq_get((k_msgq *)&DAT_20003b34,local_20,(k_timeout_t)0x0);
  if (iVar2 == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received setting command .\n","SettingStoreHandler");
      }
      else {
        ble_printk("%s(): received setting command .\n");
      }
    }
    uVar5 = 0;
    switch(local_20[0]) {
    case 1:
      uVar5 = (uint)local_1c;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): start setting  parameter check. language type = %d\n","SettingStoreHandler",
                 uVar5);
        }
        else {
          ble_printk("%s(): start setting  parameter check. language type = %d\n");
        }
      }
      if (uVar5 - 1 < 0x19) {
        if (BYTE_20019131 == uVar5) {
          bVar8 = SBORROW4(LOG_LEVEL,2);
          iVar2 = LOG_LEVEL + -2;
          bVar1 = LOG_LEVEL == 2;
          goto LAB_000261b4;
        }
        bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
        if (bVar1) {
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar7 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            local_24 = CONCAT11(local_1c,0xaa);
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x104c;
            pGVar4 = __get_dashboard_state();
            uVar5 = (*pcVar7)(pGVar4,0x13e000,0x1000);
            if (uVar5 != 0) goto LAB_00026234;
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x1048;
            pGVar4 = __get_dashboard_state();
            uVar5 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
            if (uVar5 != 0) goto LAB_00026264;
            local_24 = 0;
            local_22 = 0;
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x1044;
            pGVar4 = __get_dashboard_state();
            iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
            if (iVar2 == 0) {
              BYTE_20019131 = local_24._1_1_;
              uVar6 = 0;
              if (LOG_LEVEL < 3) {
                return 0;
              }
              uVar5 = (uint)local_24._1_1_;
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
      bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
      if (bVar1) {
        local_24 = 0;
        local_22 = 0;
        pGVar4 = __get_dashboard_state();
        pcVar7 = *(code **)&pGVar4->field_0x1044;
        pGVar4 = __get_dashboard_state();
        iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
        if (iVar2 == 0) {
          local_24 = 0x2aa;
          pGVar4 = __get_dashboard_state();
          pcVar7 = *(code **)&pGVar4->field_0x104c;
          pGVar4 = __get_dashboard_state();
          uVar5 = (*pcVar7)(pGVar4,0x13e000,0x1000);
          if (uVar5 != 0) {
LAB_00026234:
            if (LOG_LEVEL < 3) {
              return uVar5;
            }
            pcVar3 = "%s(): Flash erase failed! %d\n\n";
            uVar6 = uVar5;
LAB_000262b6:
            if (BLE_DEBUG != 0) {
              ble_printk(pcVar3);
              return uVar6;
            }
            printk(pcVar3,"SettingStoreHandler",uVar5);
            return uVar6;
          }
          pGVar4 = __get_dashboard_state();
          pcVar7 = *(code **)&pGVar4->field_0x1048;
          pGVar4 = __get_dashboard_state();
          uVar5 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
          if (uVar5 != 0) {
LAB_00026264:
            if (LOG_LEVEL < 1) {
              return uVar5;
            }
            pcVar3 = "%s(): Flash write failed! %d\n\n";
            uVar6 = uVar5;
            goto LAB_000262b6;
          }
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar7 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): App language clean success.\n","SettingStoreHandler");
              }
              else {
                ble_printk("%s(): App language clean success.\n");
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
      uVar5 = (uint)local_1c;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): start setting  parameter check. startup_mode type = %d\n",
                 "SettingStoreHandler",uVar5);
        }
        else {
          ble_printk("%s(): start setting  parameter check. startup_mode type = %d\n");
        }
      }
      if (DAT_20019132 == uVar5) {
        bVar8 = false;
        bVar1 = LOG_LEVEL == 0;
        iVar2 = LOG_LEVEL;
LAB_000261b4:
        if (!bVar1 && iVar2 < 0 == bVar8) {
          pcVar3 = "%s(): Setting Task received same language parameters.drop it ..\n";
          goto LAB_00026146;
        }
      }
      else {
        if (uVar5 < 3) {
          bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
          if (!bVar1) goto LAB_000261ca;
          local_24 = 0;
          local_22 = 0;
          pGVar4 = __get_dashboard_state();
          pcVar7 = *(code **)&pGVar4->field_0x1044;
          pGVar4 = __get_dashboard_state();
          iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
          if (iVar2 == 0) {
            local_22 = local_1c;
            local_24 = CONCAT11(local_24._1_1_,0xaa);
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x104c;
            pGVar4 = __get_dashboard_state();
            uVar5 = (*pcVar7)(pGVar4,0x13e000,0x1000);
            if (uVar5 != 0) goto LAB_00026234;
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x1048;
            pGVar4 = __get_dashboard_state();
            uVar5 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
            if (uVar5 != 0) goto LAB_00026264;
            local_24 = 0;
            local_22 = 0;
            pGVar4 = __get_dashboard_state();
            pcVar7 = *(code **)&pGVar4->field_0x1044;
            pGVar4 = __get_dashboard_state();
            iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
            if (iVar2 == 0) {
              DAT_20019132 = local_22;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): startup mode  infomation  %d store sucess\n","SettingStoreHandler",
                         (uint)local_22);
                }
                else {
                  ble_printk("%s(): startup mode  infomation  %d store sucess\n");
                }
              }
              if (DAT_20019132 != 0) {
                return 0;
              }
              pGVar4 = __get_dashboard_state();
              if (pGVar4->field_0x1244 != '\x04') {
                return 0;
              }
              upgradeDoubleTapCustomizeToFlash(0);
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
      bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
      if (!bVar1) goto LAB_000262cc;
      local_24 = 0;
      local_22 = 0;
      pGVar4 = __get_dashboard_state();
      pcVar7 = *(code **)&pGVar4->field_0x1044;
      pGVar4 = __get_dashboard_state();
      iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
      if (iVar2 == 0) {
        local_22 = 0;
        local_24 = CONCAT11(local_24._1_1_,0xaa);
        pGVar4 = __get_dashboard_state();
        pcVar7 = *(code **)&pGVar4->field_0x104c;
        pGVar4 = __get_dashboard_state();
        uVar5 = (*pcVar7)(pGVar4,0x13e000,0x1000);
        if (uVar5 != 0) goto LAB_00026234;
        pGVar4 = __get_dashboard_state();
        pcVar7 = *(code **)&pGVar4->field_0x1048;
        pGVar4 = __get_dashboard_state();
        uVar5 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
        if (uVar5 != 0) goto LAB_00026264;
        local_24 = 0;
        local_22 = 0;
        pGVar4 = __get_dashboard_state();
        pcVar7 = *(code **)&pGVar4->field_0x1044;
        pGVar4 = __get_dashboard_state();
        iVar2 = (*pcVar7)(pGVar4,0x13e000,&local_24,3);
        if (iVar2 == 0) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): App language clean success.\n","SettingStoreHandler");
            }
            else {
              ble_printk("%s(): App language clean success.\n");
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
          printk(fmt,"SettingStoreHandler",pcVar3);
        }
        else {
          ble_printk(fmt);
        }
      }
      break;
    default:
      goto switchD_0002611c_default;
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): setting storage queue get failed\r\n\n","getSettingStorageQueueCacheData");
    }
    else {
      ble_printk("%s(): setting storage queue get failed\r\n\n");
    }
    if (0 < LOG_LEVEL) {
      pcVar3 = "%s(): setting storage get queue data failed\n";
LAB_00026146:
      if (BLE_DEBUG == 0) {
        printk(pcVar3,"SettingStoreHandler");
      }
      else {
        ble_printk(pcVar3);
      }
    }
  }
  uVar5 = 0xffffffff;
switchD_0002611c_default:
  return uVar5;
}



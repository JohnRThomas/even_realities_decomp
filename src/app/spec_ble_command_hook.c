/*
 * Function: spec_ble_command_hook
 * Entry:    0000ef28
 * Prototype: undefined4 __stdcall spec_ble_command_hook(void * param_1, size_t param_2)
 */


undefined4 spec_ble_command_hook(void *param_1,size_t param_2)

{
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  size_t sVar8;
  cJSON *pcVar9;
  cJSON *object;
  int iVar10;
  void *pvVar11;
  undefined4 uVar12;
  undefined4 extraout_r1;
  undefined1 uVar13;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  uint extraout_r2_05;
  uint extraout_r2_06;
  uint extraout_r2_07;
  uint extraout_r2_08;
  uint extraout_r2_09;
  uint extraout_r2_10;
  uint extraout_r2_11;
  uint extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  uint extraout_r2_16;
  uint extraout_r2_17;
  uint extraout_r2_18;
  undefined4 extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined4 extraout_r2_21;
  undefined4 extraout_r2_22;
  byte bVar14;
  code *pcVar15;
  char *pcVar16;
  k_timeout_t timeout;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined4 local_5c4;
  int local_5c0;
  undefined1 auStack_5bc [28];
  undefined4 local_5a0;
  undefined1 auStack_59c [124];
  byte local_520;
  undefined1 uStack_51f;
  char cStack_51e;
  undefined1 uStack_51d;
  undefined1 uStack_51c;
  undefined1 local_51b;
  undefined4 local_420;
  char *local_41c;
  char *pcStack_418;
  char *local_414;
  
  pvVar1 = FUN_00018320();
  local_520 = 0;
  uStack_51f = 0;
  cStack_51e = '\0';
  uStack_51d = 0;
  memset(&uStack_51c,0,0xfc);
  memcpy(&local_520,param_1,param_2);
  iVar2 = strcmp((char *)&local_520,"#c");
  if (iVar2 == 0) {
    uVar7 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): test:BLE_REQ_POST_BT_UNPAIR\n\n");
        uVar7 = extraout_r2_01;
      }
      else {
        ble_printk("%s(): test:BLE_REQ_POST_BT_UNPAIR\n\n","spec_ble_command_hook",extraout_r2,
                   BLE_DEBUG);
        uVar7 = extraout_r2_00;
      }
    }
    uVar12 = 1;
    local_520 = 0x47;
    goto LAB_0000ef7e;
  }
  pcVar3 = strstr((char *)&local_520,"#1@");
  if (pcVar3 != (char *)0x0) {
    local_5a0 = 0;
    memset(auStack_59c,0,0x1c);
    local_420 = 0;
    memset(&local_41c,0,0x7c);
    pcVar3 = pcVar3 + 3;
    pcVar6 = pcVar3;
    do {
      pcVar16 = pcVar6;
      pcVar6 = pcVar16 + 1;
    } while (*pcVar16 != '@');
    __memcpy_chk(&local_5a0,pcVar3,(int)pcVar16 - (int)pcVar3,0x20);
    __strcpy_chk((char *)&local_420,pcVar16 + 1,0x80);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(s__s____title__s__message__s_000a1bfc,"spec_ble_command_hook",&local_5a0,&local_420);
      }
      else {
        ble_printk(s__s____title__s__message__s_000a1bfc,"spec_ble_command_hook",&local_5a0,
                   &local_420);
      }
    }
    piVar4 = &local_5a0;
    goto LAB_0000effe;
  }
  pcVar3 = strstr((char *)&local_520,"#2@");
  if (pcVar3 == (char *)0x0) {
    pcVar3 = strstr((char *)&local_520,"#3@");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strstr((char *)&local_520,"#4@");
      if (pcVar3 == (char *)0x0) {
        pcVar6 = strstr((char *)&local_520,"#5@");
        if (pcVar6 != (char *)0x0) {
          local_41c = pcVar3;
          pcStack_418 = pcVar3;
          local_414 = pcVar3;
          local_420 = *(int *)(pcVar6 + 3);
          pcVar3 = (char *)&local_420;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): buf:%s\n\n");
            }
            else {
              ble_printk("%s(): buf:%s\n\n","spec_ble_command_hook",&local_420,BLE_DEBUG);
            }
          }
          do {
            pcVar6 = pcVar3 + 1;
            if (*pcVar3 == '\0') break;
            pcVar3 = pcVar6;
          } while (*pcVar6 != '@');
          local_5c0 = 0;
          memcpy(&local_5c0,&local_420,(int)pcVar3 - (int)&local_420);
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): cmd:%s\n\n");
            }
            else {
              ble_printk("%s(): cmd:%s\n\n","spec_ble_command_hook",&local_5c0,BLE_DEBUG);
            }
          }
          pcVar3 = pcVar3 + 1;
          local_5a0 = 0;
          pcVar6 = pcVar3;
          do {
            pcVar16 = pcVar6;
            pcVar6 = pcVar16 + 1;
          } while (*pcVar16 != '\0');
          memcpy(&local_5a0,pcVar3,(int)pcVar16 - (int)pcVar3);
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): en:%s\n\n");
            }
            else {
              ble_printk("%s(): en:%s\n\n","spec_ble_command_hook",&local_5a0,BLE_DEBUG);
            }
          }
          uVar7 = FUN_0008a1b6(&local_5c0);
          iVar2 = uVar7 * 0x3c + 0xe1a;
          local_520 = 7;
          uStack_51f = (undefined1)iVar2;
          cStack_51e = (char)((uint)iVar2 >> 8);
          uStack_51d = (undefined1)((uint)iVar2 >> 0x10);
          uStack_51c = (undefined1)((uint)iVar2 >> 0x18);
          uVar7 = FUN_0008a1b6(&local_5a0);
          local_51b = (undefined1)uVar7;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): enable: %d, sec:%d\n\n","spec_ble_command_hook",uVar7,iVar2);
              uVar7 = extraout_r2_12;
            }
            else {
              ble_printk("%s(): enable: %d, sec:%d\n\n","spec_ble_command_hook",uVar7,iVar2);
              uVar7 = extraout_r2_11;
            }
          }
          uVar12 = 6;
          goto LAB_0000ef7e;
        }
        pcVar3 = strstr((char *)&local_520,"#cmd@");
        if (pcVar3 != (char *)0x0) {
          pcVar3 = pcVar3 + 5;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): pos=%s, tx_data_len=%d\n\n","spec_ble_command_hook",pcVar3,param_2);
            }
            else {
              ble_printk("%s(): pos=%s, tx_data_len=%d\n\n","spec_ble_command_hook",pcVar3,param_2);
            }
          }
          local_5a0 = 0;
          local_5c4 = 0;
          memset(auStack_59c,0,0x7c);
          FUN_0004d44c("ble",(int)pcVar3,8);
          pcVar6 = pcVar3;
          do {
            pcVar16 = pcVar6;
            pcVar6 = pcVar16 + 1;
          } while (*pcVar16 != '@');
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): 11 len=%d\n");
            }
            else {
              ble_printk("%s(): 11 len=%d\n","spec_ble_command_hook",(int)pcVar16 - (int)pcVar3,
                         BLE_DEBUG);
            }
          }
          memcpy(&local_5c4,pcVar3,(int)pcVar16 - (int)pcVar3);
          uVar7 = FUN_0008a1b6(&local_5c4);
          if (LOG_LEVEL < 3) {
            if (uVar7 == 4) goto LAB_0000f2fc;
            uVar12 = extraout_r2_13;
            if (uVar7 == 9) goto LAB_0000f39a;
          }
          else {
            if (BLE_DEBUG == 0) {
              printk("%s(): cmd=%d\n");
              uVar12 = extraout_r2_15;
            }
            else {
              ble_printk("%s(): cmd=%d\n","spec_ble_command_hook",uVar7,BLE_DEBUG);
              uVar12 = extraout_r2_14;
            }
            if (uVar7 == 4) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk(&DAT_000a1d43);
                }
                else {
                  ble_printk(&DAT_000a1d43,"spec_ble_command_hook",uVar12,BLE_DEBUG);
                }
              }
LAB_0000f2fc:
              local_420 = 0;
              memset(&local_41c,0,0xfc);
              strcpy((char *)&local_420,
                     "{\"whitelist_app\":\"com.apple.MobileSMS:com.tencent.xin:com.tencent.mqq\"}");
              sVar8 = strlen((char *)&local_420);
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                         "spec_ble_command_hook",&local_5c4,&local_5a0,0,sVar8,&local_420);
                }
                else {
                  ble_printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                             "spec_ble_command_hook",&local_5c4,&local_5a0);
                }
              }
              subcontracing_send_data_pkcs7((int)&local_420,sVar8,4,(undefined *)0x7f50d);
              return 0;
            }
            if (uVar7 == 9) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): simulator->BLE_REQ_PUT_TELEPROMPTER_INFO.\n\n");
                }
                else {
                  ble_printk("%s(): simulator->BLE_REQ_PUT_TELEPROMPTER_INFO.\n\n",
                             "spec_ble_command_hook",uVar12,BLE_DEBUG);
                }
              }
LAB_0000f39a:
              pcVar9 = cJSON_CreateObject();
              cJSON_AddNumberToObject(pcVar9,"enable",1.0);
              cJSON_AddStringToObject(pcVar9,"text",&DAT_000a1e3b);
              object = cJSON_CreateObject();
              cJSON_AddItemToObject(object,"teleprompter_info",pcVar9);
              pcVar3 = cJSON_Print(object);
              sVar8 = strlen(pcVar3);
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                         "spec_ble_command_hook",&local_5c4,&local_5a0,0,sVar8,pcVar3);
                }
                else {
                  ble_printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                             "spec_ble_command_hook",&local_5c4,&local_5a0);
                }
              }
              uVar13 = 9;
              goto LAB_0000f3f4;
            }
          }
          if (uVar7 == 10) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): simulator->BLE_REQ_PUT_NAVIGATION_INFO.\n\n");
              }
              else {
                ble_printk("%s(): simulator->BLE_REQ_PUT_NAVIGATION_INFO.\n\n",
                           "spec_ble_command_hook",uVar12,BLE_DEBUG);
              }
            }
            pcVar9 = cJSON_CreateObject();
            cJSON_AddNumberToObject(pcVar9,"enable",1.0);
            cJSON_AddNumberToObject(pcVar9,"direction",2.0);
            cJSON_AddStringToObject(pcVar9,"info",&DAT_000a1f29);
            object = cJSON_CreateObject();
            cJSON_AddItemToObject(object,"navigation_info",pcVar9);
            pcVar3 = cJSON_Print(object);
            sVar8 = strlen(pcVar3);
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                       "spec_ble_command_hook",&local_5c4,&local_5a0,0,sVar8,pcVar3);
              }
              else {
                ble_printk("%s(): cmd_type:%s, value=%s, tx_len=%d, jstr_len=%d, jsonstr=%s\n\n",
                           "spec_ble_command_hook",&local_5c4,&local_5a0);
              }
            }
            uVar13 = 10;
LAB_0000f3f4:
            subcontracing_send_data_pkcs7((int)pcVar3,sVar8,uVar13,(undefined *)0x7f50d);
            cJSON_Delete(object);
            return 0;
          }
          if (uVar7 == 0x58) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(s__s____simulator_SCHEDULE___000a1f6b);
              }
              else {
                ble_printk(s__s____simulator_SCHEDULE___000a1f6b,"spec_ble_command_hook",uVar12,
                           BLE_DEBUG);
              }
            }
            simulator_ancs_calendar_schedule_trigger();
            return 0;
          }
          if (uVar7 == 0x4b) {
            pcVar16 = pcVar16 + 1;
            pcVar3 = pcVar16;
            do {
              pcVar6 = pcVar3;
              pcVar3 = pcVar6 + 1;
            } while (*pcVar6 != '\0');
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): 22 len=%d\n");
              }
              else {
                ble_printk("%s(): 22 len=%d\n","spec_ble_command_hook",(int)pcVar6 - (int)pcVar16,
                           BLE_DEBUG);
              }
            }
            memcpy(&local_5a0,pcVar16,(int)pcVar6 - (int)pcVar16);
            pcVar3 = (char *)&local_5a0;
            do {
              pcVar6 = pcVar3;
              pcVar3 = pcVar6 + 1;
            } while (*pcVar6 != '#');
            __memcpy_chk(&local_5c0,&local_5a0,(int)pcVar6 - (int)&local_5a0,0x20);
            __strcpy_chk((char *)&local_420,pcVar6 + 1,0x80);
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): #cmd_type:%s, title=%s, msg=%s\n\n","spec_ble_command_hook",&local_5c4
                       ,&local_5c0,&local_420);
              }
              else {
                ble_printk("%s(): #cmd_type:%s, title=%s, msg=%s\n\n","spec_ble_command_hook",
                           &local_5c4,&local_5c0);
              }
            }
            piVar4 = &local_5c0;
LAB_0000effe:
            uVar12 = ncs_notification((char *)piVar4,(char *)&local_420,(undefined *)0x7f50d);
            return uVar12;
          }
          local_520 = (byte)uVar7;
          uVar7 = FUN_0008a1b6(&local_5a0);
          uStack_51f = (undefined1)uVar7;
          uVar7 = extraout_r2_16;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): **cmd_type:%s, value=%s, tx_len=%d\n\n","spec_ble_command_hook",
                     &local_5c4,&local_5a0,2);
              uVar7 = extraout_r2_18;
            }
            else {
              ble_printk("%s(): **cmd_type:%s, value=%s, tx_len=%d\n\n","spec_ble_command_hook",
                         &local_5c4,&local_5a0);
              uVar7 = extraout_r2_17;
            }
          }
          uVar12 = 2;
          goto LAB_0000ef7e;
        }
        local_5c0 = strncmp((char *)&local_520,"#a",2);
        if (local_5c0 == 0) {
          printk("\n*****test callback audio data*****\n");
          memset(auStack_5bc,0,0x10);
          local_5c0 = CONCAT31(local_5c0._1_3_,0x6e);
          do {
            uVar17 = (**(code **)((int)pvVar1 + 0xc))(&local_5c0,0x14);
            timeout.ticks._0_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
            if ((int)uVar17 == 0) {
              timeout.ticks._4_4_ = 0xffffffff;
              z_impl_k_sem_take((k_sem *)((int)pvVar1 + 0x230),timeout);
              printk("\n*****start upload audio*****\n");
              pcVar3 = (char *)&local_420;
              local_420 = (int)uVar17;
              memset(&local_41c,0,0x3fc);
              iVar2 = 0;
              pcVar6 = pcVar3;
              do {
                bVar14 = (byte)iVar2;
                iVar2 = iVar2 + 1;
                *pcVar6 = (bVar14 & 0xf) + 0x30;
                pcVar6 = pcVar6 + 1;
              } while (iVar2 != 0x400);
              uVar17 = FUN_0007f436();
              uVar7 = 0;
              iVar2 = 0;
              do {
                local_5a0._0_3_ = CONCAT12((char)iVar2,0xaf1);
                memcpy((void *)((int)&local_5a0 + 3),pcVar3,0x68);
                while (iVar10 = (**(code **)((int)pvVar1 + 0xc))(&local_5a0,0x6b), iVar10 != 0) {
                  uVar7 = uVar7 + 1 & 0xffff;
                  z_impl_k_sleep((k_timeout_t)0x148);
                  if ((*(char *)((int)pvVar1 + 0x365) == '\0') ||
                     (*(char *)((int)pvVar1 + 0x366) == '\0')) {
                    if (LOG_LEVEL < 1) {
                      return 0;
                    }
                    pcVar3 = 
                    "%s(): unable to audio transfer, due to no connected or notification disabled\n"
                    ;
                    uVar12 = extraout_r2_20;
                    goto LAB_0000f660;
                  }
                }
                iVar2 = iVar2 + 1;
                pcVar3 = pcVar3 + 0x68;
                if (iVar2 == 9) {
                  uVar18 = FUN_0007f436();
                  printk("t0 = %d error count = %d \n",(int)uVar18 - (int)uVar17,uVar7);
                  return 0;
                }
              } while( true );
            }
            z_impl_k_sleep((k_timeout_t)0x148);
          } while ((*(char *)((int)pvVar1 + 0x365) != '\0') &&
                  (*(char *)((int)pvVar1 + 0x366) != '\0'));
          if (LOG_LEVEL < 1) {
            return 0;
          }
          pcVar3 = 
          "%s(): unable to change MTU for audio transfer, due to no connected or notification disabled\n"
          ;
          uVar12 = extraout_r2_19;
LAB_0000f660:
          if (BLE_DEBUG != 0) {
            ble_printk(pcVar3,"spec_ble_command_hook",uVar12,BLE_DEBUG);
            return 0;
          }
          printk(pcVar3);
          return 0;
        }
        iVar2 = strncmp((char *)&local_520,"#b",2);
        if (iVar2 == 0) {
          uVar7 = FUN_0008a1b6(&cStack_51e);
          *(char *)((int)pvVar1 + -0x77a) = (char)uVar7;
          printk("\n*****test set esb channel***** %d\n",uVar7 & 0xff);
LAB_0000f6c2:
          *(undefined4 *)((int)pvVar1 + 0x8e4) = 0;
          DAT_20017d2f = 1;
        }
        else {
          iVar2 = strncmp((char *)&local_520,"#d",2);
          if (iVar2 != 0) {
            iVar2 = strncmp((char *)&local_520,"#e",2);
            if (iVar2 == 0) {
              if (cStack_51e != '0') {
                bVar14 = *(byte *)((int)pvVar1 + 0x8f1) | 4;
                goto LAB_0000f756;
              }
              FUN_00030458();
            }
            else {
              iVar2 = strncmp((char *)&local_520,"#f",2);
              if (iVar2 != 0) {
                local_420 = strncmp((char *)&local_520,"#g",2);
                if (local_420 == 0) {
                  memset(&local_41c,0,0xc4);
                  pcVar3 = "TX:%d,fail:%d,RX:%d,Signal:%d";
                  uVar7 = DAT_20006bd4;
                  iVar2 = DAT_20006bd0;
                  iVar10 = DAT_20006bcc;
                  uVar5 = DAT_20006bc8;
LAB_0000f7f8:
                  __sprintf_chk((char *)&local_420,0,200,pcVar3,uVar7,iVar2,iVar10,uVar5);
LAB_0000f9f4:
                  uVar12 = 200;
                  pcVar15 = *(code **)((int)pvVar1 + 0xc);
                  goto LAB_0000f9f8;
                }
                iVar2 = strncmp((char *)&local_520,"#r",2);
                if (iVar2 == 0) {
                  if (0 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): sys reboot because reboot cmd\n");
                    }
                    else {
                      ble_printk("%s(): sys reboot because reboot cmd\n","spec_ble_command_hook",
                                 extraout_r2_21,BLE_DEBUG);
                    }
                  }
                  sleep(500);
                    /* WARNING: Subroutine does not return */
                  sys_reboot(1);
                }
                iVar2 = strncmp((char *)&local_520,"#l",2);
                if (iVar2 == 0) {
                  uVar7 = FUN_0008a1b6(&cStack_51e);
                  BLE_DEBUG = (int)(uVar7 != 1);
                  return 0;
                }
                local_420 = strncmp((char *)&local_520,"#o",2);
                if (local_420 == 0) {
                  memset(&local_41c,0,0x10);
                  uVar7 = DAT_2000848c;
                  *(uint *)((int)pvVar1 + 0x7ec) = DAT_2000848c;
                  __sprintf_chk((char *)&local_420,0,0x14,"base: %d",uVar7);
                  (**(code **)((int)pvVar1 + 0xc))(&local_420,0x14);
                  goto LAB_0000f6c2;
                }
                local_420 = strncmp((char *)&local_520,"#i",2);
                if (local_420 == 0) {
                  pvVar11 = memset(&local_41c,0,0x10);
                  uVar7 = opt3007_get_max_lux(pvVar11,extraout_r1,extraout_r2_22);
                  if (cStack_51e != '\0') {
                    uVar5 = FUN_0008a1b6(&cStack_51e);
                    if (uVar5 < 2) {
                      uVar5 = FUN_0008a1b6(&cStack_51e);
                      *(char *)((int)pvVar1 + 0x820) = (char)uVar5;
                    }
                    else {
                      *(undefined1 *)((int)pvVar1 + 0x820) = 0;
                      uVar5 = FUN_0008a1b6(&cStack_51e);
                      *(char *)((int)pvVar1 + 0x759) = (char)uVar5;
                    }
                  }
                  if (uVar7 == 0xffffffff) {
                    uVar7 = 80000;
                  }
                  __sprintf_chk((char *)&local_420,0,0x14,"base: %d",uVar7);
                  (**(code **)((int)pvVar1 + 0xc))(&local_420,0x14);
                  goto LAB_0000f716;
                }
                local_420 = strncmp((char *)&local_520,"#y",2);
                if (local_420 == 0) {
                  memset(&local_41c,0,0x10);
                  pcVar3 = "level: %d";
                  uVar7 = (uint)*(byte *)((int)pvVar1 + 0x759);
LAB_0000f93c:
                  __sprintf_chk((char *)&local_420,0,0x14,pcVar3,uVar7);
                }
                else {
                  local_420 = strncmp((char *)&local_520,"#u",2);
                  if (local_420 == 0) {
                    memset(&local_41c,0,0x10);
                    uVar7 = FUN_0008a1b6(&cStack_51e);
                    *(char *)((int)pvVar1 + 0x77c) = (char)uVar7;
                    __sprintf_chk((char *)&local_420,0,0x14,"level: %d",uVar7 & 0xff);
                    (**(code **)((int)pvVar1 + 0xc))(&local_420,0x14);
                    *(undefined4 *)((int)pvVar1 + 0x8e4) = 0;
                    goto LAB_0000f6cc;
                  }
                  iVar2 = strncmp((char *)&local_520,"#p",2);
                  if (iVar2 == 0) {
                    local_420 = 0;
                    memset(&local_41c,0,0x10);
                    pcVar3 = "pitch: %d";
                    uVar7 = DAT_2000848c;
                    goto LAB_0000f93c;
                  }
                  local_420 = strncmp((char *)&local_520,"#t",2);
                  if (local_420 == 0) {
                    memset(&local_41c,0,0xc4);
                    __sprintf_chk((char *)&local_420,0,200,
                                  "net build time: %s, app build time %s, ver %d.%d.%d, JBD DeviceID %x\n\r"
                                  ,&DAT_2001093c,"2025-06-28 17:28:42",1,6,3,DAT_2000aa54);
                    goto LAB_0000f9f4;
                  }
                  local_420 = strncmp((char *)&local_520,"#v",2);
                  if (local_420 == 0) {
                    memset(&local_41c,0,0xc4);
                    uVar5 = (uint)*(byte *)((int)pvVar1 + 0x84e);
                    iVar10 = *(byte *)((int)pvVar1 + 0x84d) - 0x80;
                    iVar2 = *(byte *)((int)pvVar1 + 0x84c) + 200;
                    uVar7 = (uint)*(byte *)((int)pvVar1 + 0x848);
                    pcVar3 = "B:%d, V:%d, A:%d, T:%d";
                    goto LAB_0000f7f8;
                  }
                  local_420 = strncmp((char *)&local_520,"#k",2);
                  if (local_420 == 0) {
                    memset(&local_41c,0,0x3c);
                    uVar12 = FUN_00027664();
                    __sprintf_chk((char *)&local_420,0,0x40,"VADC:%d TMR:%d",uVar12,0);
LAB_0000fade:
                    uVar12 = 0x40;
                    pcVar15 = *(code **)((int)pvVar1 + 0xc);
                    goto LAB_0000f9f8;
                  }
                  local_420 = strncmp((char *)&local_520,"#j",2);
                  if (local_420 == 0) {
                    memset(&local_41c,0,0x10);
                    uVar7 = FUN_0008a1b6(&cStack_51e);
                    if (uVar7 == 1) {
                      (**(code **)((int)pvVar1 + 0x394))();
                      (**(code **)((int)pvVar1 + 0x3b8))((int)pvVar1 + 0x3b4);
                      pcVar3 = "init flash";
                    }
                    else {
                      (**(code **)((int)pvVar1 + 0x394))((int)pvVar1 + 0x394);
                      (**(code **)((int)pvVar1 + 0x3b8))((int)pvVar1 + 0x3b4);
                      pcVar3 = "deinit flash";
                    }
                    strcpy((char *)&local_420,pcVar3);
                  }
                  else {
                    local_420 = strncmp((char *)&local_520,"#s",2);
                    if (local_420 != 0) {
                      local_420 = strncmp((char *)&local_520,"#h",2);
                      if (local_420 != 0) {
                        return 0xffffffff;
                      }
                      memset(&local_41c,0,0x3c);
                      uVar7 = FUN_0008a1b6(&cStack_51e);
                      if (uVar7 == 1) {
                        *(undefined4 *)((int)pvVar1 + 0x8e4) = 0x19;
                      }
                      else {
                        if (uVar7 != 2) {
                          __sprintf_chk((char *)&local_420,0,0x40,
                                        "master mac: %02X:%02X:%02X:%02X:%02X:%02X, slave mac: %02X:%02X:%02X:%02X:%02X:%02X"
                                        ,(uint)*(byte *)((int)pvVar1 + 0x862),
                                        (uint)*(byte *)((int)pvVar1 + 0x863),
                                        (uint)*(byte *)((int)pvVar1 + 0x864),
                                        (uint)*(byte *)((int)pvVar1 + 0x865),
                                        (uint)*(byte *)((int)pvVar1 + 0x866),
                                        (uint)*(byte *)((int)pvVar1 + 0x867),
                                        (uint)*(byte *)((int)pvVar1 + 0x868),
                                        (uint)*(byte *)((int)pvVar1 + 0x869),
                                        (uint)*(byte *)((int)pvVar1 + 0x86a),
                                        (uint)*(byte *)((int)pvVar1 + 0x86b),
                                        (uint)*(byte *)((int)pvVar1 + 0x86c),
                                        (uint)*(byte *)((int)pvVar1 + 0x86d));
                          goto LAB_0000fade;
                        }
                        *(undefined4 *)((int)pvVar1 + 0x862) = 0xffffffff;
                        *(undefined2 *)((int)pvVar1 + 0x866) = 0xffff;
                        *(undefined4 *)((int)pvVar1 + 0x868) = 0xffffffff;
                        *(undefined2 *)((int)pvVar1 + 0x86c) = 0xffff;
                        *(undefined4 *)((int)pvVar1 + 0x8e4) = 0x1a;
                      }
                      DAT_20017d2f = 1;
                      k_sem_give((k_sem *)((int)pvVar1 + -0x6fc));
                      goto LAB_0000fade;
                    }
                    memset(&local_41c,0,0x10);
                    if (cStack_51e == '\0') {
                      uVar7 = 7;
                    }
                    else {
                      uVar7 = FUN_0008a1b6(&cStack_51e);
                    }
                    change_work_mode(uVar7);
                  }
                }
                uVar12 = 0x14;
                pcVar15 = *(code **)((int)pvVar1 + 0xc);
LAB_0000f9f8:
                (*pcVar15)(&local_420,uVar12);
                return 0;
              }
              bVar14 = *(byte *)((int)pvVar1 + 0x8f1) | 8;
LAB_0000f756:
              *(byte *)((int)pvVar1 + 0x8f1) = bVar14;
            }
            iVar2 = -0x714;
            goto LAB_0000f748;
          }
          uVar7 = FUN_0008a1b6(&cStack_51e);
          *(char *)((int)pvVar1 + 0x872) = (char)uVar7;
          printk("\n*****display mode***** %d\n",uVar7 & 0xff);
          if (*(char *)((int)pvVar1 + 0x872) == '\v') {
            *(undefined1 *)((int)pvVar1 + 0x76c) = 2;
            change_work_mode(2);
            if (*(char *)((int)pvVar1 + -0x77c) == '\x02') {
              k_sem_give((k_sem *)((int)pvVar1 + -0x75c));
            }
          }
          else {
            *(undefined1 *)((int)pvVar1 + 0x76c) = 1;
            change_work_mode(3);
          }
LAB_0000f716:
          *(undefined4 *)((int)pvVar1 + 0x8e4) = 0;
        }
LAB_0000f6cc:
        iVar2 = -0x6fc;
LAB_0000f748:
        k_sem_give((k_sem *)((int)pvVar1 + iVar2));
        return 0;
      }
      pcVar3 = pcVar3 + 3;
      uVar5 = FUN_0008a1b6(pcVar3);
      uVar7 = extraout_r2_08;
      if (2 < (int)uVar5) {
        if (BLE_DEBUG == 0) {
          printk("%s(): pos:%s, new log_level_set=%d\n\n","spec_ble_command_hook",pcVar3,uVar5);
          uVar7 = extraout_r2_10;
        }
        else {
          ble_printk("%s(): pos:%s, new log_level_set=%d\n\n","spec_ble_command_hook",pcVar3,uVar5);
          uVar7 = extraout_r2_09;
        }
      }
      uStack_51f = 2;
      cStack_51e = (char)uVar5;
    }
    else {
      pcVar3 = pcVar3 + 3;
      uVar5 = FUN_0008a1b6(pcVar3);
      uVar7 = extraout_r2_05;
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): pos:%s, new screen_id=%d\n\n","spec_ble_command_hook",pcVar3,uVar5);
          uVar7 = extraout_r2_07;
        }
        else {
          ble_printk("%s(): pos:%s, new screen_id=%d\n\n","spec_ble_command_hook",pcVar3,uVar5);
          uVar7 = extraout_r2_06;
        }
      }
      uStack_51f = 3;
      cStack_51e = (char)uVar5;
    }
  }
  else {
    pcVar3 = pcVar3 + 3;
    uVar5 = FUN_0008a1b6(pcVar3);
    uVar7 = extraout_r2_02;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(s__s_______pos__s__val__d_000a1c35,"spec_ble_command_hook",pcVar3,uVar5);
        uVar7 = extraout_r2_04;
      }
      else {
        ble_printk(s__s_______pos__s__val__d_000a1c35,"spec_ble_command_hook",pcVar3,uVar5);
        uVar7 = extraout_r2_03;
      }
    }
    uStack_51f = 1;
    cStack_51e = uVar5 != 0;
  }
  local_520 = 5;
  uVar12 = 3;
LAB_0000ef7e:
  FUN_0007f50c(&local_520,uVar12,uVar7);
  return 0;
}



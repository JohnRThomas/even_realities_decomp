/*
 * Function: key_event_thread
 * Entry:    0002b998
 * Prototype: undefined __stdcall key_event_thread(char * param_1)
 */


void key_event_thread(char *param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  GlassesState *pGVar4;
  int iVar5;
  uint extraout_r0;
  uint extraout_r0_00;
  char *pcVar6;
  int iVar7;
  undefined4 extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  uint uVar8;
  uint extraout_r1_03;
  undefined4 extraout_r1_04;
  uint extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 uVar9;
  undefined4 extraout_r1_07;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  uint uVar10;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined1 *puVar11;
  undefined1 uVar12;
  k_timeout_t timeout;
  undefined4 local_24;
  undefined4 extraout_r2;
  
  __init_key_event_sem();
LAB_0002b9a8:
  while ((pGVar4 = __get_dashboard_state(), pGVar4->field_0x1 == 1 ||
         (pGVar4 = __get_dashboard_state(), pGVar4->field_0x1 == 8))) {
    z_impl_k_sleep((k_timeout_t)0x28000);
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1;
  iVar5 = z_impl_k_sem_take(&__key_event_sem,timeout);
  if (iVar5 != 0) goto switchD_0002bbac_default;
  uVar10 = 0;
  uVar8 = extraout_r1_00;
  uVar9 = extraout_r2;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): key event trigger, type %d\n\n");
      uVar10 = extraout_r0_00;
      uVar8 = extraout_r1_02;
      uVar9 = extraout_r2_02;
    }
    else {
      ble_printk("%s(): key event trigger, type %d\n\n","key_event_thread",DAT_200084f8,BLE_DEBUG);
      uVar10 = extraout_r0;
      uVar8 = extraout_r1_01;
      uVar9 = extraout_r2_00;
    }
  }
  if (DAT_200084f8 == 1) goto code_r0x0002ba04;
  switch(DAT_200084f8) {
  case 2:
    if (**(char **)(param_1 + 0x101c) != '\0') {
      iVar5 = 0x19;
      goto LAB_0002ba9e;
    }
    if (param_1[0xd5] != '\a') {
      if (((**(int **)(param_1 + 0x1068) == 0) && (param_1[0xd5] == '\0')) &&
         (param_1[0xfee] != '\f')) {
        if (param_1[0x1244] == '\x04') {
          if (*param_1 == '\x01') {
            local_24._0_2_ = 0x10a;
            iVar5 = 1;
            do {
              uVar10 = sync_to_slave(param_1,6,&local_24,2);
              if ((int)uVar10 < 3000) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): SEND double click event to slave.\n");
                  }
                  else {
                    ble_printk("%s(): SEND double click event to slave.\n","key_event_thread",
                               extraout_r2_05,BLE_DEBUG);
                  }
                }
                DAT_20008518 = DAT_20008518 | 2;
                param_1[0x1245] = '\x01';
                break;
              }
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk(
                        "%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                        );
                }
                else {
                  ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                             ,"key_event_thread",iVar5,BLE_DEBUG);
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 != 4);
          }
          else {
            iVar5 = 1;
            do {
              uVar10 = FUN_000294d0((int)param_1,7,(void *)0x0,0);
              if (uVar10 < 2000) {
                if (0 < LOG_LEVEL) {
                  pcVar6 = "%s(): sync dashborad startup command success,wait for starting\n";
                  uVar9 = extraout_r2_06;
                  goto LAB_0002bce8;
                }
                break;
              }
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): SYNC dashborad startup command to start Slave failed %d times\n");
                }
                else {
                  ble_printk("%s(): SYNC dashborad startup command to start Slave failed %d times\n"
                             ,"key_event_thread",iVar5,BLE_DEBUG);
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 != 4);
          }
        }
        else if (param_1[0x1244] != '\0') {
          FUN_00029774(0x20,uVar8,uVar9);
          cVar1 = 'd';
          do {
            cVar1 = cVar1 + -1;
            k_msleep(0x14);
          } while (cVar1 != '\0');
        }
      }
      else {
        if ((param_1[0xd5] != '\x06') ||
           ((param_1[0x1244] != '\x04' && (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\0')))) {
          cVar1 = 'e';
          while ((1 < (byte)param_1[0xfea] && (cVar1 = cVar1 + -1, cVar1 != '\0'))) {
            k_msleep(10);
            uVar8 = extraout_r1_03;
            uVar9 = extraout_r2_10;
          }
          if ((param_1[0xd5] != '\f') ||
             ((param_1[0xd5] == '\f' && (*(char *)(*(int *)(param_1 + 0x1034) + 3) == '\n')))) {
            FUN_00029774(0,uVar8,uVar9);
            if (*param_1 == '\x01') {
              if (param_1[0xd5] == '\x04') {
                FUN_00035a84();
                pGVar4 = __get_dashboard_state();
                iVar5 = 0;
                if (pGVar4->field_0xdd != '\0') {
                  iVar5 = 6;
                }
                FUN_00035abc(iVar5);
              }
              iVar5 = 1;
              local_24._0_2_ = 1;
              if (param_1[0xd5] == '\x06') {
                if (param_1[0xd5] == '\x06') {
                  sync_to_slave(param_1,8,&local_24,2);
LAB_0002bf02:
                  FUN_0007ff66((int)param_1,0);
                  update_persist_task_status_to_idle((int)param_1,extraout_r1_04);
                }
              }
              else {
                DAT_20008514 = DAT_20008514 | 2;
                do {
                  uVar10 = sync_to_slave(param_1,8,&local_24,2);
                  if ((int)uVar10 < 3000) {
                    if (0 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): SEND double click event to slave.\n");
                      }
                      else {
                        ble_printk("%s(): SEND double click event to slave.\n","key_event_thread",
                                   extraout_r2_07,BLE_DEBUG);
                      }
                    }
                    goto LAB_0002bedc;
                  }
                  if (0 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk(
                            "%s(): SYNC TO Slave failed %d times,don\'t exec double click close app function.\n"
                            );
                    }
                    else {
                      ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double click close app function.\n"
                                 ,"key_event_thread",iVar5,BLE_DEBUG);
                    }
                  }
                  iVar5 = iVar5 + 1;
                } while (iVar5 != 4);
              }
            }
            else if (param_1[0xd5] == '\x06') {
              if (param_1[0xd5] == '\x06') {
                FUN_000294d0((int)param_1,4,(void *)0x0,0);
                pGVar4 = __get_dashboard_state();
                if (pGVar4->field_0xd5 == '\x04') {
                  FUN_00035a84();
                  pGVar4 = __get_dashboard_state();
                  iVar5 = 0;
                  if (pGVar4->field_0xdd != '\0') {
                    iVar5 = 6;
                  }
                  FUN_00035abc(iVar5);
                }
                goto LAB_0002bf02;
              }
            }
            else {
              FUN_000294d0((int)param_1,4,(void *)0x0,0);
              pGVar4 = __get_dashboard_state();
              if (pGVar4->field_0xd5 == '\x04') {
                FUN_00035a84();
                pGVar4 = __get_dashboard_state();
                iVar5 = 0;
                if (pGVar4->field_0xdd != '\0') {
                  iVar5 = 6;
                }
                FUN_00035abc(iVar5);
              }
LAB_0002bedc:
              FUN_0007ff66((int)param_1,0);
            }
            break;
          }
          iVar5 = 1;
          local_24._0_2_ = 1;
          do {
            uVar10 = sync_to_slave(param_1,6,&local_24,2);
            if ((int)uVar10 < 3000) {
              display_DelayClose(10000);
              z_impl_k_yield();
              uVar9 = extraout_r2_14;
              break;
            }
            uVar9 = extraout_r2_11;
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n"
                      );
                uVar9 = extraout_r2_13;
              }
              else {
                ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n"
                           ,"key_event_thread",iVar5,BLE_DEBUG);
                uVar9 = extraout_r2_12;
              }
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 4);
          if (LOG_LEVEL < 2) break;
          pcVar6 = "%s(): Click event does not respond, close Quicknote to prevent exceptions\n";
          goto LAB_0002bafe;
        }
        FUN_00029774(0,uVar8,uVar9);
        if (*param_1 == '\x01') {
          local_24._0_2_ = 0x20a;
          iVar5 = 1;
          do {
            uVar10 = sync_to_slave(param_1,6,&local_24,2);
            if ((int)uVar10 < 3000) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): SEND double click event to slave.\n");
                }
                else {
                  ble_printk("%s(): SEND double click event to slave.\n","key_event_thread",
                             extraout_r2_08,BLE_DEBUG);
                }
              }
              param_1[0x1245] = '\0';
              DAT_20008518 = DAT_20008518 | 2;
              *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x72) = 0;
              break;
            }
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                      );
              }
              else {
                ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec double click startup dashboard function.\n"
                           ,"key_event_thread",iVar5,BLE_DEBUG);
              }
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 4);
        }
        else {
          iVar5 = 1;
          do {
            uVar10 = FUN_000294d0((int)param_1,7,(void *)0x0,0);
            if (uVar10 < 2000) {
              if (0 < LOG_LEVEL) {
                pcVar6 = "%s(): sync dashborad startup command success,close dashboard function\n";
                uVar9 = extraout_r2_09;
                goto LAB_0002bce8;
              }
              break;
            }
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): SYNC dashborad startup command to close dashboard Slave failed %d times\n"
                      );
              }
              else {
                ble_printk("%s(): SYNC dashborad startup command to close dashboard Slave failed %d times\n"
                           ,"key_event_thread",iVar5,BLE_DEBUG);
              }
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 4);
        }
      }
    }
    goto LAB_0002b9a8;
  case 3:
    if ((**(char **)(param_1 + 0x101c) == '\0') &&
       (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) != '\x01')) {
      if (param_1[0xfee] == '\f') {
        FUN_00029774(5,uVar8,uVar9);
        if (*param_1 == '\x01') {
          uVar10 = sync_to_slave(param_1,5,(undefined4 *)0x0,0);
          uVar9 = extraout_r2_15;
          if ((int)uVar10 < 3000) {
LAB_0002c058:
            FUN_0003f1bc();
            uVar9 = extraout_r2_16;
          }
        }
        else {
          uVar10 = FUN_000294d0((int)param_1,9,(void *)0x0,0);
          uVar9 = extraout_r2_17;
          if (uVar10 < 2000) goto LAB_0002c058;
        }
        param_1[0xfee] = '\n';
        if (0 < LOG_LEVEL) {
          pcVar6 = 
          "%s(): #############################exit not disturb################################\n\n";
LAB_0002c072:
          if (BLE_DEBUG == 0) {
            printk(pcVar6);
          }
          else {
            ble_printk(pcVar6,"key_event_thread",uVar9,BLE_DEBUG);
          }
        }
      }
      else {
        FUN_00029774(4,uVar8,uVar9);
        if (*param_1 == '\x01') {
          sync_to_slave(param_1,4,(undefined4 *)0x0,0);
          FUN_0007ff66((int)param_1,0);
        }
        else {
          FUN_000294d0((int)param_1,8,(void *)0x0,0);
        }
        param_1[0xfee] = '\f';
        FUN_0007ff66((int)param_1,1);
        FUN_00080852(0);
        if (0 < LOG_LEVEL) {
          pcVar6 = 
          "%s(): #############################enter not disturb################################\n\n"
          ;
          uVar9 = extraout_r2_18;
          goto LAB_0002c072;
        }
      }
      param_1[0x1060] = '\x03';
      param_1[0x1061] = '\0';
      param_1[0x1062] = '\0';
      param_1[0x1063] = '\0';
      k_sem_give((k_sem *)(param_1 + 0x80));
      break;
    }
    goto LAB_0002b9a8;
  case 4:
    if ((**(char **)(param_1 + 0x101c) != '\0') ||
       (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\x01')) {
      if (0 < LOG_LEVEL) {
        pcVar6 = "%s(): [onboarding/set_lum_coeffic] is running, exit this time\n";
LAB_0002bce8:
        if (BLE_DEBUG == 0) {
          printk(pcVar6);
        }
        else {
          ble_printk(pcVar6,"key_event_thread",uVar9,BLE_DEBUG);
        }
      }
      goto LAB_0002b9a8;
    }
    DAT_20019a63 = 1;
    if (param_1[0xfee] != '\f') {
      bVar3 = __is_idle();
      uVar10 = (uint)bVar3;
      if (((uVar10 != 0) || (param_1[0xd5] == '\x06')) || (param_1[0xd5] == '\x01')) {
        if (*param_1 != '\x02') {
          uVar12 = 1;
          puVar11 = *(undefined1 **)(param_1 + 0x1034);
          uVar8 = extraout_r1_05;
          goto LAB_0002c172;
        }
        bVar3 = FUN_00028d2c();
        iVar5 = *(int *)(param_1 + 0x1014);
        *(undefined1 *)(iVar5 + 1) = 6;
        if (!bVar3) {
          *(undefined1 *)(*(int *)(param_1 + 0x1014) + 3) = 1;
          break;
        }
        iVar7 = 0x17;
        *(undefined1 *)(*(int *)(param_1 + 0x1014) + 3) = 2;
        uVar9 = extraout_r1_06;
LAB_0002c160:
        FUN_00029774(iVar7,uVar9,iVar5);
        break;
      }
    }
    if (1 < LOG_LEVEL) {
      bVar2 = param_1[0xd5];
      if (BLE_DEBUG == 0) {
        bVar3 = __is_idle();
        printk("%s(): longpress task cannot be started because screen_id %d, %d, %d\n",
               "key_event_thread",(uint)bVar2,(uint)bVar3,(uint)(byte)param_1[0xfee]);
      }
      else {
        bVar3 = __is_idle();
        ble_printk("%s(): longpress task cannot be started because screen_id %d, %d, %d\n",
                   "key_event_thread",(uint)bVar2,(uint)bVar3);
      }
    }
    break;
  case 5:
    DAT_20019a63 = 0;
    cVar1 = param_1[0xd5];
    if (*param_1 == '\x02') {
LAB_0002c1ce:
      DAT_20019a63 = 0;
      if (cVar1 == '\x10') {
        if (**(char **)(param_1 + 0x1010) == '\x04') {
          **(char **)(param_1 + 0x1010) = '\x05';
        }
      }
      else if ((((param_1[0xd5] == '\x14') && (bVar3 = FUN_00028d2c(), bVar3)) &&
               (*(char *)(*(int *)(param_1 + 0x1014) + 1) == '\a')) &&
              (*(char *)(*(int *)(param_1 + 0x1014) + 3) == '\x02')) {
        iVar7 = 0x18;
        iVar5 = 7;
        uVar9 = extraout_r1_07;
        goto LAB_0002c160;
      }
    }
    else if (cVar1 == '\f') {
LAB_0002c22c:
      DAT_20019a63 = 0;
      uVar12 = 2;
      puVar11 = *(undefined1 **)(param_1 + 0x1034);
LAB_0002c172:
      *puVar11 = uVar12;
      check_disp_quicknote(uVar10,uVar8);
    }
    break;
  case 6:
    DAT_20019a63 = 0;
    if (*param_1 == '\x02') {
      cVar1 = param_1[0xd5];
      goto LAB_0002c1ce;
    }
    if ((DAT_20019a57 == '\0') && (param_1[0xd5] == '\f')) {
      DAT_20019a57 = '\x01';
      goto LAB_0002c22c;
    }
  }
  goto switchD_0002bbac_default;
code_r0x0002ba04:
  if (*(char *)(*(int *)(param_1 + 0xff0) + 0x72) == '\x01') goto LAB_0002b9a8;
  if (**(char **)(param_1 + 0x101c) != '\0') {
    FUN_00029774(1,uVar8,uVar9);
    cVar1 = *(char *)(*(int *)(param_1 + 0x101c) + 2);
    if (cVar1 == '\x05') {
      pGVar4 = __get_dashboard_state();
      if (*(char *)pGVar4 != '\x02') goto LAB_0002b9a8;
      uVar12 = 0x13;
      uVar9 = extraout_r2_01;
    }
    else {
      if (cVar1 != '\x13') {
        if ((cVar1 == '\x14') && (pGVar4 = __get_dashboard_state(), *(char *)pGVar4 == '\x01')) {
          *(undefined1 *)(*(int *)(param_1 + 0x101c) + 2) = 0x15;
        }
        goto LAB_0002b9a8;
      }
      pGVar4 = __get_dashboard_state();
      if (*(char *)pGVar4 != '\x02') goto LAB_0002b9a8;
      uVar12 = 0x14;
      uVar9 = extraout_r2_03;
    }
    local_24._0_2_ = CONCAT11(local_24._1_1_,uVar12);
    iVar5 = onboarding_sync_data((undefined1 *)&local_24,1,uVar9);
    if (iVar5 == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x101c) + 2) = uVar12;
    }
    goto LAB_0002b9a8;
  }
  if ((**(byte **)(param_1 + 0x1010) - 7 < 5) || (**(char **)(param_1 + 0x1024) != '\0')) {
LAB_0002ba9c:
    iVar5 = 1;
LAB_0002ba9e:
    FUN_00029774(iVar5,uVar8,uVar9);
    goto LAB_0002b9a8;
  }
  uVar10 = (uint)**(byte **)(param_1 + 0x1014);
  if ((uVar10 == 1) && (uVar9 = 1, (*(byte **)(param_1 + 0x1014))[1] == 3)) goto LAB_0002ba9c;
  if (*(char *)(*(int *)(param_1 + 0x1000) + 1) != '\0') {
    FUN_00029774(1,uVar8,uVar10);
  }
  if (*param_1 != '\x01') {
    if (((*param_1 == '\x02') && (uVar10 = FUN_000352f4(), uVar10 != 0)) &&
       (((param_1[0xd5] == '\x06' &&
         (pGVar4 = __get_dashboard_state(), *(char *)&pGVar4->imu_fusion_context == '\x02')) ||
        (param_1[0xd5] == '\x04')))) {
      do {
        iVar5 = FUN_0002dea8();
      } while (iVar5 < 0);
    }
    goto switchD_0002bbac_default;
  }
  if (param_1[0xd5] != '\x06') goto switchD_0002bbac_default;
  cVar1 = __get_pane_mode();
  local_24._0_2_ = 0x102;
  if (cVar1 == '\0') {
    bVar2 = __getNotesIndex();
LAB_0002bad0:
    local_24._0_2_ = CONCAT11(local_24._1_1_ | bVar2 << 4,(undefined1)local_24);
  }
  else {
    if (cVar1 == '\x01') {
      local_24._0_2_ = 0x302;
      bVar2 = getStocksIndex();
      goto LAB_0002bad0;
    }
    if (cVar1 == '\x02') {
      local_24._0_2_ = 0x502;
      bVar2 = getNewsIndex();
      goto LAB_0002bad0;
    }
    if (cVar1 == '\x03') {
      local_24._0_2_ = 0x702;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): master send calendar key single click ,timestamp = %d\n");
        }
        else {
          ble_printk("%s(): master send calendar key single click ,timestamp = %d\n",
                     "key_event_thread",**(undefined4 **)(param_1 + 0xff0),BLE_DEBUG);
        }
      }
      bVar2 = getCalenadrIndex();
      goto LAB_0002bad0;
    }
  }
  uVar10 = sync_to_slave(param_1,6,&local_24,2);
  if ((int)uVar10 < 5000) {
    display_inputEvent(0,1);
    z_impl_k_yield();
  }
  else if (1 < LOG_LEVEL) {
    pcVar6 = "%s(): SYNC TO Slave failed...,don\'t exec key function.\n";
    uVar9 = extraout_r2_04;
LAB_0002bafe:
    if (BLE_DEBUG == 0) {
      printk(pcVar6);
    }
    else {
      ble_printk(pcVar6,"key_event_thread",uVar9,BLE_DEBUG);
    }
  }
switchD_0002bbac_default:
  DAT_200084f8 = 0;
  goto LAB_0002b9a8;
}



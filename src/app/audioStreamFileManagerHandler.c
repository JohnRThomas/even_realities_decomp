/*
 * Function: audioStreamFileManagerHandler
 * Entry:    00030dec
 * Prototype: undefined4 __stdcall audioStreamFileManagerHandler(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 audioStreamFileManagerHandler(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *fmt;
  GlassesState *pGVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 uVar6;
  undefined4 extraout_r2_09;
  uint uVar7;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  int extraout_r3;
  int iVar8;
  int extraout_r3_00;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  size_t n;
  undefined2 local_f8 [2];
  char local_f4 [2];
  short local_f2;
  byte local_f0 [204];
  
  if (DAT_2001aa79 == '\0') {
    if (DAT_20003a54 == 0) {
      return 0;
    }
    iVar10 = getAudioMessageQueueCacheData(local_f4);
    uVar5 = extraout_r2;
    if (iVar10 != 0) goto LAB_00030e16;
    if (local_f4[0] != '\x01') {
      if (local_f4[0] != '\x03') {
        if (local_f4[0] == '\x04') {
          delVoiceBlock((uint)local_f0[0],extraout_r1,extraout_r2,4);
          return 0;
        }
        if (local_f4[0] != '\x02') {
          return 0;
        }
      }
      FUN_00030b28();
      return 0;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): start audio stream record!\r\n\n");
      }
      else {
        ble_printk("%s(): start audio stream record!\r\n\n","audioStreamFileManagerHandler",
                   extraout_r2,BLE_DEBUG);
      }
    }
    bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
    if (bVar1) {
      memset(&DAT_20019a78,0,0x1000);
      pGVar4 = __get_dashboard_state();
      pcVar11 = *(code **)&pGVar4->field_0x1044;
      pGVar4 = __get_dashboard_state();
      iVar10 = (*pcVar11)(pGVar4,0x400000,&DAT_20019a78,0x1000);
      if (iVar10 == 0) {
        if (_DAT_20019a78 == 0x5aa5aa5a) {
LAB_00030f62:
          iVar10 = 0x7fffffff;
          uVar7 = 0;
          uVar9 = 0;
          do {
            if (*(int *)(&DAT_20019a80 + uVar9 * 0x14) == 0) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): find a free voice block(%d)!\r\n\n");
                }
                else {
                  ble_printk("%s(): find a free voice block(%d)!\r\n\n",
                             "audioStreamFileManagerHandler",uVar9,BLE_DEBUG);
                }
              }
              uVar7 = uVar9 & 0xff;
              goto LAB_00030ff4;
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): voice_block_store_timestamp = %d, voice_stream_block_ts = %d\n",
                       "audioStreamFileManagerHandler",*(undefined4 *)(&DAT_20019a8c + uVar9 * 0x14)
                       ,iVar10);
              }
              else {
                ble_printk("%s(): voice_block_store_timestamp = %d, voice_stream_block_ts = %d\n",
                           "audioStreamFileManagerHandler",
                           *(undefined4 *)(&DAT_20019a8c + uVar9 * 0x14),iVar10);
              }
            }
            if ((*(int *)(&DAT_20019a8c + uVar9 * 0x14) < iVar10) &&
               ((iVar8 = FUN_00030de0(), iVar2 = extraout_r2_00, iVar8 == 0 ||
                (iVar8 = FUN_00030de0(), iVar2 = extraout_r2_01, iVar8 - 1U != uVar9)))) {
              iVar10 = *(int *)(iVar2 + 4);
              uVar7 = uVar9 & 0xff;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 != 4);
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): no free voice block,try to use the oldest voice block(%d)!\n");
            }
            else {
              ble_printk("%s(): no free voice block,try to use the oldest voice block(%d)!\n",
                         "audioStreamFileManagerHandler",uVar7,BLE_DEBUG);
            }
          }
LAB_00030ff4:
          DAT_2001aa78 = (byte)uVar7;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): audio manager start check success,will fill up audio stream to Num%d block\n"
                    );
            }
            else {
              ble_printk("%s(): audio manager start check success,will fill up audio stream to Num%d block\n"
                         ,"audioStreamFileManagerHandler",uVar7,BLE_DEBUG);
            }
          }
          DAT_20008598 = (char *)0x0;
          DAT_20008594 = 0;
          memset(&DAT_20019a78,0,0x1000);
          DAT_2000859c = 0;
          DAT_2001aa79 = 1;
          return 0;
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): filesystem need format,try to format,please wait..\n");
          }
          else {
            ble_printk("%s(): filesystem need format,try to format,please wait..\n",
                       "audioStreamFileManagerHandler",0x5aa5aa5a,BLE_DEBUG);
          }
        }
        memset(&DAT_20019a78,0,0x1000);
        memcpy(&DAT_20019a78,&INT_0008d800,0x58);
        pGVar4 = __get_dashboard_state();
        pcVar11 = *(code **)&pGVar4->field_0x104c;
        pGVar4 = __get_dashboard_state();
        pcVar3 = (char *)(*pcVar11)(pGVar4,0x400000,0x1000);
        if (pcVar3 == (char *)0x0) {
          pGVar4 = __get_dashboard_state();
          pcVar11 = *(code **)&pGVar4->field_0x1048;
          pGVar4 = __get_dashboard_state();
          pcVar3 = (char *)(*pcVar11)(pGVar4,0x400000,&DAT_20019a78,0x1000);
          if (pcVar3 == (char *)0x0) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): filesystem format sucess\n");
              }
              else {
                ble_printk("%s(): filesystem format sucess\n","audioStreamFileManagerHandler",0,
                           BLE_DEBUG);
              }
            }
            goto LAB_00030f62;
          }
          goto joined_r0x000312a2;
        }
        goto LAB_00030f08;
      }
LAB_00030ea4:
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar3 = &DAT_00400000;
      fmt = "%s():  form address [%d] read data failed.\n\n";
    }
    else {
LAB_00030e5e:
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar3 = "mx25r6435f@0";
      fmt = "%s():  [%s] device not ready.\n\n";
    }
LAB_0003113e:
    if (BLE_DEBUG == 0) {
      printk(fmt);
    }
    else {
      ble_printk(fmt,"audioStreamFileManagerHandler",pcVar3,BLE_DEBUG);
    }
  }
  else {
    if (DAT_2001aa79 != '\x01') {
      return 0;
    }
    if (DAT_20003a54 == 0) {
      return 0;
    }
    iVar2 = getAudioMessageQueueCacheData(local_f4);
    iVar10 = LOG_LEVEL;
    uVar5 = extraout_r2_02;
    if (iVar2 == 0) {
      if (local_f4[0] != '\x01') {
        if (local_f4[0] == '\x02') {
          pcVar3 = DAT_20008598 + local_f2;
          if (0xfff < (int)pcVar3) {
            memcpy(DAT_20008598 + 0x20019a78,local_f0,0x1000 - (int)DAT_20008598);
            if (2 < iVar10) {
              if (BLE_DEBUG == 0) {
                printk("%s(): To complete a sector of data, perform flash write operations\n");
              }
              else {
                ble_printk("%s(): To complete a sector of data, perform flash write operations\n",
                           "audioStreamFileManagerHandler",extraout_r2_03,BLE_DEBUG);
              }
            }
            bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
            if (!bVar1) goto LAB_00030e5e;
            iVar10 = (uint)DAT_2001aa78 * 0x20000 + 0x421000 + DAT_20008594 * 0x1000;
            if (iVar10 <= (int)((uint)DAT_2001aa78 * 0x20000 + 0x431000)) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): wirte addr = 0x%08x\n");
                }
                else {
                  ble_printk("%s(): wirte addr = 0x%08x\n","audioStreamFileManagerHandler",iVar10,
                             BLE_DEBUG);
                }
              }
              pGVar4 = __get_dashboard_state();
              pcVar11 = *(code **)&pGVar4->field_0x104c;
              pGVar4 = __get_dashboard_state();
              pcVar3 = (char *)(*pcVar11)(pGVar4,iVar10,0x1000);
              if (pcVar3 != (char *)0x0) goto LAB_00030f08;
              pGVar4 = __get_dashboard_state();
              pcVar11 = *(code **)&pGVar4->field_0x1048;
              pGVar4 = __get_dashboard_state();
              pcVar3 = (char *)(*pcVar11)(pGVar4,iVar10,&DAT_20019a78,0x1000);
              if (pcVar3 == (char *)0x0) {
                DAT_2000859c = crc32(DAT_2000859c,&DAT_20019a78,0x1000);
                DAT_20008594 = DAT_20008594 + 1;
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): wirte 4k voice data to flash,write address = 0x%08x\n");
                  }
                  else {
                    ble_printk("%s(): wirte 4k voice data to flash,write address = 0x%08x\n",
                               "audioStreamFileManagerHandler",iVar10,BLE_DEBUG);
                  }
                }
                pcVar3 = DAT_20008598;
                DAT_20008598 = (char *)0x0;
                memset(&DAT_20019a78,0,0x1000);
                iVar10 = -(int)pcVar3 + 0x1000;
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): Copy remain %d byte data into cache memory\n");
                  }
                  else {
                    ble_printk("%s(): Copy remain %d byte data into cache memory\n",
                               "audioStreamFileManagerHandler",local_f2 - iVar10,BLE_DEBUG);
                  }
                }
                n = local_f2 - iVar10;
                iVar10 = (int)DAT_20008598 + n;
                memcpy(&DAT_20019a78 + (int)DAT_20008598,&stack0x00000f10 + -(int)pcVar3,n);
                DAT_20008598 = (char *)iVar10;
                return 0;
              }
              goto joined_r0x000312a2;
            }
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): the number of recording files exceeds the upper limit, system automatically stops\n"
                      );
                uVar5 = extraout_r2_07;
              }
              else {
                ble_printk("%s(): the number of recording files exceeds the upper limit, system automatically stops\n"
                           ,"audioStreamFileManagerHandler",LOG_LEVEL,BLE_DEBUG);
                uVar5 = extraout_r2_04;
              }
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk(
                        "%s(): Catch touch release is not recognized, start QuickNote exception recovery mechanism\n"
                        );
                }
                else {
                  ble_printk("%s(): Catch touch release is not recognized, start QuickNote exception recovery mechanism\n"
                             ,"audioStreamFileManagerHandler",uVar5,BLE_DEBUG);
                }
              }
            }
            local_f8[0] = 1;
            pGVar4 = __get_dashboard_state();
            sync_to_slave((char *)pGVar4,6,(undefined4 *)local_f8,2);
            display_DelayClose(10000);
            uVar5 = extraout_r2_05;
            goto LAB_000311ea;
          }
          memcpy(DAT_20008598 + 0x20019a78,local_f0,(int)local_f2);
          if (iVar10 < 3) {
            DAT_20008598 = pcVar3;
            return 0;
          }
          fmt = "%s(): copy %d byte into audio cache\n";
          DAT_20008598 = pcVar3;
        }
        else {
          if (local_f4[0] != '\x03') {
            if (local_f4[0] != '\x04') {
              return 0;
            }
            uVar5 = extraout_r1_00;
            uVar6 = extraout_r2_02;
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): A delete command occurred during the recording process. The recording was stopped and the deletion action was performed,Delete num = %d\n"
                      );
                uVar5 = extraout_r1_02;
                uVar6 = extraout_r2_12;
                iVar10 = extraout_r3_00;
              }
              else {
                ble_printk("%s(): A delete command occurred during the recording process. The recording was stopped and the deletion action was performed,Delete num = %d\n"
                           ,"audioStreamFileManagerHandler",(uint)local_f0[0],BLE_DEBUG);
                uVar5 = extraout_r1_01;
                uVar6 = extraout_r2_08;
                iVar10 = extraout_r3;
              }
            }
            delVoiceBlock((uint)local_f0[0],uVar5,uVar6,iVar10);
            DAT_2001aa79 = 0;
            return 0;
          }
LAB_000311ea:
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received audio stop command,stop audio write process\n");
              uVar5 = extraout_r2_09;
            }
            else {
              ble_printk("%s(): received audio stop command,stop audio write process\n",
                         "audioStreamFileManagerHandler",uVar5,BLE_DEBUG);
              uVar5 = extraout_r2_06;
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): To complete a sector of data, perform flash write operations\n");
              }
              else {
                ble_printk("%s(): To complete a sector of data, perform flash write operations\n",
                           "audioStreamFileManagerHandler",uVar5,BLE_DEBUG);
              }
            }
          }
          bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
          if (!bVar1) goto LAB_00030e5e;
          iVar10 = (uint)DAT_2001aa78 * 0x20000 + 0x421000 + DAT_20008594 * 0x1000;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): wirte addr = 0x%08x\n");
            }
            else {
              ble_printk("%s(): wirte addr = 0x%08x\n","audioStreamFileManagerHandler",iVar10,
                         BLE_DEBUG);
            }
          }
          pGVar4 = __get_dashboard_state();
          pcVar11 = *(code **)&pGVar4->field_0x104c;
          pGVar4 = __get_dashboard_state();
          pcVar3 = (char *)(*pcVar11)(pGVar4,iVar10,0x1000);
          if (pcVar3 == (char *)0x0) {
            pGVar4 = __get_dashboard_state();
            pcVar11 = *(code **)&pGVar4->field_0x1048;
            pGVar4 = __get_dashboard_state();
            pcVar3 = (char *)(*pcVar11)(pGVar4,iVar10,&DAT_20019a78,0x1000);
            if (pcVar3 != (char *)0x0) {
joined_r0x000312a2:
              if (LOG_LEVEL < 1) {
                return 0;
              }
              fmt = "%s(): Flash write failed! %d\n\n";
              goto LAB_0003113e;
            }
            DAT_2000859c = crc32(DAT_2000859c,&DAT_20019a78,(int)DAT_20008598);
            memset(&DAT_20019a78,0,0x1000);
            pGVar4 = __get_dashboard_state();
            pcVar11 = *(code **)&pGVar4->field_0x1044;
            pGVar4 = __get_dashboard_state();
            iVar10 = (*pcVar11)(pGVar4,0x400000,&DAT_20019a78,0x1000);
            if (iVar10 != 0) goto LAB_00030ea4;
            pGVar4 = __get_dashboard_state();
            pcVar11 = *(code **)&pGVar4->field_0x104c;
            pGVar4 = __get_dashboard_state();
            pcVar3 = (char *)(*pcVar11)(pGVar4,0x400000,0x1000);
            iVar10 = DAT_20008594;
            if (pcVar3 == (char *)0x0) {
              _DAT_20019a78 = 0x5aa5aa5a;
              iVar2 = (uint)DAT_2001aa78 * 0x14;
              iVar8 = (uint)DAT_2001aa78 * 0x20000 + 0x421000;
              *(int *)(&DAT_20019a84 + iVar2) = iVar8;
              DAT_20019a7c = 0;
              DAT_20019a7d = 0;
              DAT_20019a7e = 0;
              DAT_20019a7f = 0;
              *(char **)(&DAT_20019a88 + iVar2) = DAT_20008598 + iVar8 + iVar10 * 0x1000;
              (&DAT_20019a80)[iVar2] = 2;
              (&DAT_20019a81)[iVar2] = 0;
              (&DAT_20019a82)[iVar2] = 0;
              (&DAT_20019a83)[iVar2] = 0;
              uVar5 = FUN_00080732();
              iVar2 = LOG_LEVEL;
              uVar7 = (uint)DAT_2001aa78;
              iVar10 = uVar7 * 0x14;
              *(undefined4 *)(&DAT_20019a8c + iVar10) = uVar5;
              *(uint *)(&DAT_20019a90 + iVar10) = DAT_2000859c;
              if (2 < iVar2) {
                if (BLE_DEBUG == 0) {
                  printk(
                        "%s(): upgrade Num.%d voice manager block,total write sector num = %d, total write byte = %d ,crc32 = %d\n"
                        );
                }
                else {
                  ble_printk("%s(): upgrade Num.%d voice manager block,total write sector num = %d, total write byte = %d ,crc32 = %d\n"
                             ,"audioStreamFileManagerHandler",uVar7,DAT_20008594);
                }
              }
              if (*(int *)(&DAT_20019a84 + (uint)DAT_2001aa78 * 0x14) ==
                  *(int *)(&DAT_20019a88 + (uint)DAT_2001aa78 * 0x14)) {
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): voice block start addr = voice block end addr\n");
                  }
                  else {
                    ble_printk("%s(): voice block start addr = voice block end addr\n",
                               "audioStreamFileManagerHandler",
                               *(int *)(&DAT_20019a84 + (uint)DAT_2001aa78 * 0x14),BLE_DEBUG);
                  }
                }
                DAT_2001aa79 = '\0';
                DAT_2001aa78 = 0;
                DAT_20008598 = (char *)0x0;
                DAT_20008594 = 0;
                FUN_00030b28();
                if (LOG_LEVEL < 1) {
                  return 0;
                }
                pcVar3 = 
                "%s(): The dmic may have a problem. When the size of the recording file is 0, data block 0 is terminated\n"
                ;
                uVar5 = extraout_r2_10;
              }
              else {
                pGVar4 = __get_dashboard_state();
                pcVar11 = *(code **)&pGVar4->field_0x1048;
                pGVar4 = __get_dashboard_state();
                pcVar3 = (char *)(*pcVar11)(pGVar4,0x400000,&DAT_20019a78,0x1000);
                DAT_2001aa79 = '\0';
                DAT_2001aa78 = 0;
                DAT_20008598 = (char *)0x0;
                DAT_20008594 = 0;
                FUN_00030b28();
                requestAudioInfoToApp(1);
                if (pcVar3 != (char *)0x0) goto joined_r0x000312a2;
                if (LOG_LEVEL < 3) {
                  return 0;
                }
                pcVar3 = "%s(): audio manager block upgrade success\n";
                uVar5 = extraout_r2_11;
              }
              goto LAB_00030e26;
            }
          }
LAB_00030f08:
          if (LOG_LEVEL < 3) {
            return 0;
          }
          fmt = "%s(): Flash erase failed! %d\n\n";
        }
        goto LAB_0003113e;
      }
      DAT_2001aa79 = '\0';
      if (LOG_LEVEL < 1) {
        DAT_2001aa79 = 0;
        return 0;
      }
      pcVar3 = "%s(): A start command occurred during recording to exit the recording\n";
    }
    else {
LAB_00030e16:
      if (LOG_LEVEL < 1) {
        return 0;
      }
      pcVar3 = "%s(): get audio message queue data failed!\n";
    }
LAB_00030e26:
    if (BLE_DEBUG == 0) {
      printk(pcVar3);
    }
    else {
      ble_printk(pcVar3,"audioStreamFileManagerHandler",uVar5,BLE_DEBUG);
    }
  }
  return 0;
}



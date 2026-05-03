/*
 * Function: do_pdm_transfer
 * Entry:    00030520
 * Prototype: uint __stdcall do_pdm_transfer(void)
 */


uint do_pdm_transfer(void)

{
  bool bVar1;
  char cVar2;
  void *pvVar3;
  GlassesState *pGVar4;
  int iVar5;
  char *pcVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  char *pcVar7;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar8;
  uint uVar9;
  void *local_64;
  size_t local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined *local_54;
  char *local_50;
  undefined4 uStack_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 auStack_46 [6];
  undefined4 *local_40;
  undefined1 local_2c;
  undefined1 local_2a;
  
  pvVar3 = FUN_00018320();
  pGVar4 = __get_dashboard_state();
  uVar9 = *(ushort *)&pGVar4->field_0x1070 & 2;
  if ((*(ushort *)&pGVar4->field_0x1070 & 2) != 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): DMIC sample\n");
      }
      else {
        ble_printk("%s(): DMIC sample\n","dmic_stream_start",extraout_r2,BLE_DEBUG);
      }
    }
    bVar1 = z_device_is_ready((device *)&DAT_0008b4f0);
    if (bVar1) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): %s is ready\n");
        }
        else {
          ble_printk("%s(): %s is ready\n","dmic_stream_start","pdm@26000",BLE_DEBUG);
        }
      }
      iVar5 = init_dmic_msgq();
      if (iVar5 == 0) {
        local_54 = &DAT_20003918;
        memset(auStack_46,0,0x1e);
        local_50 = " gyroscope full-scale\r\n";
        uStack_4c = 3500000;
        local_48 = 0x28;
        local_47 = 0x3c;
        local_40 = &local_5c;
        local_2a = 1;
        local_2c = 1;
        local_5c = 16000;
        uStack_58 = 0xc800010;
        cVar2 = FUN_00033d5c();
        if ((cVar2 == '\x01') && (uVar9 = erase_audio_buffer(), (int)uVar9 < 0)) {
          if (0 < LOG_LEVEL) {
            pcVar6 = "%s(): Failed to erase_audio_buffer %d\n";
LAB_00030654:
            if (BLE_DEBUG == 0) {
              printk(pcVar6);
            }
            else {
              ble_printk(pcVar6,"dmic_stream_start",uVar9,BLE_DEBUG);
            }
          }
        }
        else {
          uVar9 = dmic_nrfx_pdm_configure((device *)&DAT_0008b4f0,(dmic_cfg *)&local_50);
          if ((int)uVar9 < 0) {
            if (0 < LOG_LEVEL) {
              pcVar6 = "%s(): Failed to configure the driver: %d\n";
              goto LAB_00030654;
            }
          }
          else {
            uVar9 = dmic_nrfx_pdm_trigger((device *)&DAT_0008b4f0,1);
            if (-1 < (int)uVar9) {
              DAT_20019a77 = 0;
              DAT_20003052 = '\0';
              while (DAT_20003052 != '\x01') {
                local_64 = (void *)0x0;
                cVar2 = FUN_00033d5c();
                if (((cVar2 == '\x01') &&
                    (pGVar4 = __get_dashboard_state(), pGVar4->field_0x10a4 == '\x01')) &&
                   (bVar1 = z_device_is_ready((device *)&DAT_0008b3a0), !bVar1)) {
                  if (LOG_LEVEL < 1) goto LAB_000306f2;
                  pcVar7 = "mx25r6435f@0";
                  pcVar6 = "%s():  [%s] device not ready.\n";
LAB_0003070a:
                  if (BLE_DEBUG == 0) {
                    printk(pcVar6);
                    uVar8 = extraout_r2_03;
                  }
                  else {
                    ble_printk(pcVar6,"do_pdm_transfer",pcVar7,BLE_DEBUG);
                    uVar8 = extraout_r2_02;
                  }
                  if (local_64 != (void *)0x0) goto LAB_000306f8;
LAB_00030746:
                  if (0 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): !!!do_pdm_transfer exec failed.\n");
                    }
                    else {
                      ble_printk("%s(): !!!do_pdm_transfer exec failed.\n","dmic_stream_start",uVar8
                                 ,BLE_DEBUG);
                    }
                  }
                  goto LAB_00030666;
                }
                pcVar7 = (char *)dmic_nrfx_pdm_read(0x8b4f0,0,&local_64,&local_60,1000);
                if (pcVar7 != (char *)0x0) {
                  if (0 < LOG_LEVEL) {
                    pcVar6 = "%s(): dmic_read failed %d\n";
                    goto LAB_0003070a;
                  }
LAB_000306f2:
                  if (local_64 != (void *)0x0) {
LAB_000306f8:
                    k_mem_slab_free((k_mem_slab *)&DAT_20003918,local_64);
                    uVar8 = extraout_r2_01;
                    goto LAB_00030746;
                  }
                  goto LAB_00030666;
                }
                cVar2 = FUN_00033d5c();
                if ((cVar2 == '\x01') &&
                   (pGVar4 = __get_dashboard_state(), pGVar4->field_0x10a4 == '\x01')) {
                  if (DAT_20002404 < 0x410000 - local_60) {
                    pcVar7 = (char *)____qspi_nor_write((device *)&DAT_0008b3a0,DAT_20002404,
                                                        local_64,local_60);
                    if (pcVar7 != (char *)0x0) {
                      if (0 < LOG_LEVEL) {
                        pcVar6 = "%s(): Flash write failed! %d\n\n";
                        goto LAB_0003070a;
                      }
                      goto LAB_000306f2;
                    }
                    if (0 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): Flash write to addr 0x%x\n\n");
                      }
                      else {
                        ble_printk("%s(): Flash write to addr 0x%x\n\n","do_pdm_transfer",
                                   DAT_20002404,BLE_DEBUG);
                      }
                    }
                    DAT_20002404 = DAT_20002404 + local_60;
                  }
joined_r0x0003089a:
                  if (local_64 != (void *)0x0) {
                    k_mem_slab_free((k_mem_slab *)&DAT_20003918,local_64);
                  }
                }
                else if (local_64 != (void *)0x0) {
                  app_codec_lc3_test(local_64,local_60);
                  goto joined_r0x0003089a;
                }
                uVar9 = 0;
                if (((DAT_20003052 == '\0') && (cVar2 = FUN_00033d5c(), cVar2 == '\0')) &&
                   (DAT_20008580 != 0)) {
                  if ((*(char *)((int)pvVar3 + 0x248) == '\0') &&
                     (*(int *)((int)pvVar3 + 0x220) == 0)) {
                    DAT_20019a77 = 1;
                    k_sem_give((k_sem *)((int)pvVar3 + 0x218));
                  }
                  else {
                    local_60 = CONCAT13(local_60._3_1_,0xcc00f1);
                    enqueue_bt_data(&local_60,3);
                  }
                }
              }
              goto LAB_0003057c;
            }
            if (0 < LOG_LEVEL) {
              pcVar6 = "%s(): START trigger failed: %d\n";
              goto LAB_00030654;
            }
          }
        }
LAB_00030666:
        uVar9 = 0xffffffff;
        goto LAB_0003057c;
      }
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): %s is not ready\n");
      }
      else {
        ble_printk("%s(): %s is not ready\n","dmic_stream_start","pdm@26000",BLE_DEBUG);
      }
    }
    uVar9 = 1;
  }
LAB_0003057c:
  iVar5 = dmic_nrfx_pdm_trigger((device *)&DAT_0008b4f0,0);
  if (iVar5 < 0) {
    if (LOG_LEVEL < 1) goto LAB_000305a4;
    pcVar6 = "%s(): STOP trigger failed\n";
  }
  else {
    if (LOG_LEVEL < 1) goto LAB_000305a4;
    pcVar6 = "%s(): STOP trigger Success\n";
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar6);
  }
  else {
    ble_printk(pcVar6,"dmic_stream_start",extraout_r2_00,BLE_DEBUG);
  }
LAB_000305a4:
  clean_dmic_msgq();
  DAT_20002404 = 0x400000;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Exiting\n");
    }
    else {
      ble_printk("%s(): Exiting\n","dmic_stream_start",0x400000,BLE_DEBUG);
    }
  }
  return uVar9;
}



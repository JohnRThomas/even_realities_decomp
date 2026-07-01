/*
 * Function: master_process_put_req
 * Entry:    0002d090
 * Prototype: int __stdcall master_process_put_req(char * param_1, byte * param_2, byte * param_3)
 */


int master_process_put_req(char *param_1,byte *param_2,byte *param_3)

{
  char cVar1;
  byte bVar2;
  GlassesState *pGVar3;
  size_t sVar4;
  k_sem *pkVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar9;
  undefined4 *puVar10;
  byte *pbVar12;
  uint uVar13;
  undefined4 extraout_r2;
  byte bVar14;
  uint uVar15;
  int iVar16;
  byte *pbVar17;
  code *pcVar18;
  size_t sVar19;
  size_t ilen;
  undefined4 uVar20;
  char bVar20;
  undefined1 local_11c;
  undefined4 local_11b;
  undefined4 local_117;
  undefined2 local_113;
  char local_111;
  undefined1 auStack_110 [244];
  char *pcVar8;
  undefined4 *puVar11;
  
  pbVar12 = param_2 + 4;
  if (param_2[1] == 3) {
    uVar20 = *(undefined4 *)(param_2 + 8);
    iVar16 = *(int *)(param_2 + 0xc);
    if (iVar16 - 0x13U < 0x800d) {
      pGVar3 = __get_dashboard_state();
      if (*(int *)&pGVar3->field_0x1044 != 0) {
        pGVar3 = __get_dashboard_state();
        ilen = iVar16 - 0x12;
        pcVar18 = *(code **)&pGVar3->field_0x1044;
        pGVar3 = __get_dashboard_state();
        sVar4 = (*pcVar18)(pGVar3,uVar20,param_3 + 0x12,ilen);
        sVar19 = ilen;
        if ((sVar4 != 0) && (sVar19 = sVar4, 0 < (int)LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): read flash fail: %d\n\n");
          }
          else {
            ble_printk("%s(): read flash fail: %d\n\n","read_fw_pack_from_nor_flash_by_qspi",sVar4,
                       BLE_DEBUG);
          }
        }
        if (ilen == sVar19) {
          *param_3 = 0x6f;
          param_3[1] = 0x6b;
          mbedtls_md5(param_3 + 0x12,ilen,param_3 + 2);
          __dump_hex("flash_md5",(int)(param_3 + 2),0x10);
          return iVar16;
        }
      }
    }
    *param_3 = 0x6e;
    param_3[1] = 0x6f;
    return 0;
  }
  uVar13 = (uint)*param_2;
  if (0x26 < (uVar13 - 1 & 0xff)) {
    if (0x1c < (uVar13 - 0x29 & 0xff)) {
      if (0xf < uVar13 - 0x47) {
        if (0 < (int)LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): tx error req_type head->req_type %d.\n\n");
          }
          else {
            ble_printk("%s(): tx error req_type head->req_type %d.\n\n","process_recv_ble_req",
                       uVar13,BLE_DEBUG);
          }
        }
        param_3[0] = 'e';
        param_3[1] = 'r';
        param_3[2] = 'r';
        param_3[3] = 'o';
        param_3[4] = 'r';
        param_3[5] = '\0';
        return 6;
      }
      switch(uVar13) {
      case 0x4a:
        bVar2 = param_2[4];
        if ((int)((uint)bVar2 << 0x1e) < 0) {
          param_1[0xc9] = -0x7d;
          param_1[0xca] = '\x01';
          memset((void *)((int)&local_11b + 3),0,0xf8);
          local_11c = 2;
          local_11b = *(undefined4 *)(param_1 + 0xc9);
          local_117 = *(undefined4 *)(param_1 + 0xcd);
          local_113 = *(undefined2 *)(param_1 + 0xd1);
          local_111 = param_1[0xd3];
          memset(auStack_110,0,0x15);
          (**(code **)(param_1 + 0x774))(&local_11c,0xfc);
        }
        if ((int)((uint)bVar2 << 0x1f) < 0) {
          (**(code **)(param_1 + 0x1040))(param_1 + 0x68);
        }
        break;
      case 0x4b:
        iVar16 = post_notification_cmd_response
                           ((int)param_1,(int)param_2,(int)(param_1 + 0xd4),(int)param_2,
                            (int)pbVar12,(undefined4 *)param_3);
        return iVar16;
      case 0x4c:
        uVar15 = *(uint *)(param_2 + 4);
        FUN_0007f38a(uVar15 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
                     uVar15 >> 0x18,pbVar12,uVar13 - 0x4a);
        break;
      case 0x4d:
        pGVar3 = __get_dashboard_state();
        pkVar5 = &pGVar3->__work_mode_sem;
        goto LAB_0002d24e;
      case 0x4e:
        *(undefined1 *)(*(int *)(param_1 + 0x1010) + 0x1e6) = 0;
        if (*(char *)(*(int *)(param_1 + 0x1010) + 7) == '\0') {
          *(undefined1 *)(*(int *)(param_1 + 0x1010) + 7) = 10;
        }
        *param_3 = 0xc9;
        if (**(int **)(param_1 + 0x1068) == 0x10) {
          return 1;
        }
        uVar13 = 0x10;
        goto LAB_0002d346;
      case 0x4f:
        pGVar3 = __get_dashboard_state();
        pGVar3->field_0x10d6 = param_2[4];
        pGVar3 = __get_dashboard_state();
        pGVar3->field_0x10d7 = param_2[5];
        bVar2 = *param_2;
        pGVar3 = __get_dashboard_state();
        *(uint *)&pGVar3->field_0x1060 = (uint)bVar2;
        pGVar3 = __get_dashboard_state();
        k_sem_give(&pGVar3->sem_6);
        *param_3 = 0xc9;
        bVar2 = param_2[4];
        goto LAB_0002d522;
      default:
        goto switchD_0002d152_caseD_3;
      }
      goto LAB_0002d252;
    }
    switch(uVar13 - 0x29) {
    case 0:
      *param_3 = param_1[0xed5];
      bVar2 = param_1[0xf9c];
      break;
    case 1:
      bVar2 = param_1[0xf64];
      goto LAB_0002d2c8;
    case 2:
      *param_3 = param_1[0xfee];
      bVar2 = FUN_00028ad8();
      break;
    case 3:
      bVar2 = param_1[0xfc4];
      bVar14 = param_1[0xfc5];
      if (bVar2 == 0x5d) {
        if (param_1[0xfc6] == '\0') {
          if (bVar14 == 0x5d) {
            bVar2 = 0x5e;
            bVar14 = bVar2;
            goto LAB_0002d594;
          }
          bVar2 = 0x5e;
          uVar13 = (uint)(byte)(bVar14 + 0xa2);
        }
        else {
          if (bVar14 == 0x5d) {
            bVar2 = 0x5f;
            goto LAB_0002d622;
          }
          bVar2 = 0x5f;
          uVar13 = (uint)(byte)(bVar14 + 0xa2);
        }
      }
      else if (bVar2 == 0x5e) {
        if (param_1[0xfc6] == '\0') {
          if (bVar14 == 0x5d) {
            bVar2 = 0x60;
            bVar14 = 0x5e;
            goto LAB_0002d594;
          }
          bVar2 = 0x60;
          uVar13 = (uint)(byte)(bVar14 + 0xa2);
        }
        else {
          if (bVar14 == 0x5d) {
            bVar2 = 0x61;
            bVar14 = 0x5e;
            goto LAB_0002d594;
          }
          bVar2 = 0x61;
          uVar13 = (uint)(byte)(bVar14 + 0xa2);
        }
      }
      else if (bVar2 == 0x5f) {
        if (bVar14 == 0x5d) {
          bVar2 = 0x62;
          goto LAB_0002d622;
        }
        bVar2 = 0x62;
        uVar13 = (uint)(byte)(bVar14 + 0xa2);
      }
      else if (bVar2 == 0x60) {
        if (bVar14 == 0x5d) {
          bVar2 = 99;
          goto LAB_0002d622;
        }
        bVar2 = 99;
        uVar13 = (uint)(byte)(bVar14 + 0xa2);
      }
      else if (bVar2 < 0x61) {
        if (bVar14 == 0x5d) goto LAB_0002d622;
        uVar13 = (uint)(byte)(bVar14 + 0xa2);
      }
      else {
        if (bVar14 == 0x5d) {
          bVar2 = 100;
LAB_0002d622:
          bVar14 = 0x5e;
          goto LAB_0002d594;
        }
        uVar13 = (uint)(byte)(bVar14 + 0xa2);
        bVar2 = 100;
        bVar14 = 100;
      }
      if (uVar13 < 3) {
        bVar14 = "`bcmaster_process_put_req"[uVar13];
      }
LAB_0002d594:
      *param_3 = bVar2;
      param_3[1] = bVar14;
      param_3[2] = param_1[0xfc8];
      param_3[3] = param_1[0xfc9];
      param_3[4] = param_1[0xfca];
      pcVar8 = param_1 + 0xfd0;
      pbVar12 = param_3 + 5;
      do {
        pcVar6 = pcVar8 + 4;
        pbVar17 = pbVar12 + 4;
        *(undefined4 *)pbVar12 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar6;
        pbVar12 = pbVar17;
      } while (pcVar6 != param_1 + 0xfdc);
      *(undefined2 *)pbVar17 = *(undefined2 *)pcVar6;
      return 0x13;
    case 4:
      *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0xfde);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 0xfe2);
      *(undefined4 *)(param_3 + 6) = *(undefined4 *)(param_1 + 0xfe4);
      *(undefined2 *)(param_3 + 10) = *(undefined2 *)(param_1 + 0xfe8);
      return 0xc;
    default:
      goto switchD_0002d152_caseD_3;
    case 9:
      *param_3 = param_1[0xef8];
      bVar2 = param_1[0xef9];
      break;
    case 10:
      puVar9 = FUN_00025340();
      puVar10 = puVar9;
      do {
        puVar11 = puVar10 + 1;
        *(undefined4 *)param_3 = *puVar10;
        puVar10 = puVar11;
        param_3 = param_3 + 4;
      } while (puVar11 != puVar9 + 4);
      return 0x10;
    case 0xb:
      pcVar6 = get_serial_number();
      pcVar8 = pcVar6;
      do {
        pcVar7 = pcVar8 + 4;
        *(undefined4 *)param_3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar7;
        param_3 = param_3 + 4;
      } while (pcVar7 != pcVar6 + 0x10);
      return 0x10;
    case 0xc:
      bVar2 = param_1[2];
      goto LAB_0002d2c8;
    case 0xd:
      iVar16 = get_notification_counts_cmd_response((int)param_1,param_3,uVar13);
      return iVar16;
    case 0xe:
      iVar16 = get_boot_seconds();
      uint32_to_little_endian(param_3,iVar16,extraout_r2);
      if (param_1[0xae3] == '\0') {
        bVar20 = *(int *)(param_1 + 0x9b4) != 0;
      }
      else {
        bVar20 = 0;
      }
      goto LAB_0002d2ec;
    }
LAB_0002d522:
    param_3[1] = bVar2;
    return 2;
  }
  switch(uVar13 - 1) {
  case 0:
    if ((param_1[0xed5] != param_2[4]) || (param_1[0xf9c] != param_2[5])) {
      (**(code **)(param_1 + 0xb8c))(param_1 + 0xb6c);
      param_1[0xf9c] = param_2[5];
      *(uint *)(param_1 + 0x1060) = (uint)*param_2;
      k_sem_give((k_sem *)(param_1 + 0x80));
    }
    *param_3 = param_2[4];
    param_3[1] = param_2[5];
    param_3[2] = 0xc9;
    return 3;
  case 1:
    if (param_1[0xf64] != param_2[4]) {
      param_1[0xf64] = param_2[4];
      goto LAB_0002d242;
    }
    break;
  case 2:
    bVar2 = param_2[4];
    uVar13 = (uint)bVar2;
    if (2 < uVar13 - 10) {
      bVar2 = 0xca;
      goto LAB_0002d2c8;
    }
    uVar15 = (uint)(byte)param_1[0xfee];
    if (uVar13 != uVar15) {
      if (*param_1 == '\x01') {
        if (uVar15 == 0xc) {
LAB_0002d2b6:
          if ((uVar13 != 0xc) && (param_2[5] != 1)) {
            FUN_0003f1bc();
          }
        }
        else if (uVar13 == 0xc) {
          FUN_00080852(0);
        }
      }
      else if ((*param_1 == '\x02') && (uVar15 == 0xc)) goto LAB_0002d2b6;
      param_1[0xfee] = bVar2;
      *(uint *)(param_1 + 0x1060) = (uint)*param_2;
      k_sem_give((k_sem *)(param_1 + 0x80));
      if ((param_1[0xb0c] == '\0') && (uVar13 == 0xb)) {
        pkVar5 = (k_sem *)(param_1 + 0xaf4);
        param_1[0xfed] = '\x03';
LAB_0002d2a8:
        k_sem_give(pkVar5);
        return 0;
      }
    }
    break;
  default:
    goto switchD_0002d152_caseD_3;
  case 4:
    bVar2 = param_2[4];
    bVar14 = param_2[5];
    if (bVar2 == 1) {
      FUN_0002d8c8("debug-ble",(int)param_1,(uint)(bVar14 != 0));
    }
    else if (bVar2 == 2) {
      LOG_LEVEL = (uint)bVar14;
      printk("log_level_set=%d");
    }
    else if (bVar2 == 3) {
      param_1[0xd5] = bVar14;
    }
    bVar20 = 0;
    param_3[0] = 'G';
    param_3[1] = 0x6f;
    param_3[2] = 0x6f;
    param_3[3] = 'd';
LAB_0002d2ec:
    param_3[4] = bVar20;
    return 5;
  case 6:
    uVar20 = *(undefined4 *)(param_2 + 4);
    *(byte *)(*(int *)(param_1 + 0xff4) + 5) = param_2[8];
    **(undefined4 **)(param_1 + 0xff4) = uVar20;
    *(undefined1 *)(*(int *)(param_1 + 0xff4) + 6) = 1;
    *(uint *)(param_1 + 0x1060) = (uint)*param_2;
    k_sem_give((k_sem *)(param_1 + 0x80));
    *param_3 = 0xc9;
    if (*(char *)(*(int *)(param_1 + 0xff4) + 5) == '\0') {
      return 1;
    }
    uVar13 = 2;
    goto LAB_0002d346;
  case 7:
    memcpy(*(void **)(param_1 + 0xff8),pbVar12,0x16a);
    **(undefined4 **)(param_1 + 0xff0) = *(undefined4 *)(*(int *)(param_1 + 0xff8) + 0x164);
    FUN_0004d494(*(int **)(param_1 + 0xff0),0,1);
LAB_0002d242:
    *(uint *)(param_1 + 0x1060) = (uint)*param_2;
    pkVar5 = (k_sem *)(param_1 + 0x80);
LAB_0002d24e:
    k_sem_give(pkVar5);
    break;
  case 8:
    memcpy(*(void **)(param_1 + 0x1000),pbVar12,0x217);
    if ((param_2[5] == 0) && (memset(*(void **)(param_1 + 0x1000),0,0x217), param_2[5] == 0)) {
      return 0;
    }
    uVar13 = 9;
    goto LAB_0002d364;
  case 10:
    bVar2 = param_2[5];
    if ((param_1[0xef8] != param_2[4]) || (param_1[0xef9] != bVar2)) {
      param_1[0xef8] = param_2[4];
      param_1[0xef9] = bVar2;
      goto LAB_0002d242;
    }
    break;
  case 0xc:
    cVar1 = FUN_00030440();
    if (cVar1 != '\0') {
      return 0;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x1008) + 0x1e5) = 0;
    iVar16 = *(int *)(param_1 + 0x1008);
    goto LAB_0002d396;
  case 0xe:
    cVar1 = FUN_00030440();
    if (cVar1 != '\0') {
      return 0;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x100c) + 0x1e5) = 0;
    iVar16 = *(int *)(param_1 + 0x100c);
LAB_0002d396:
    if (*(char *)(iVar16 + 6) == '\0') {
      *(undefined1 *)(iVar16 + 6) = 10;
    }
    *param_3 = 0xc9;
    if (**(int **)(param_1 + 0x1068) == 0xb) {
      return 1;
    }
    uVar13 = 0xb;
LAB_0002d346:
    update_persist_task_status((int)param_1,uVar13,2);
    return 1;
  case 0x10:
    param_1[0x1060] = '\a';
    param_1[0x1061] = '\0';
    param_1[0x1062] = '\0';
    param_1[0x1063] = '\0';
    pkVar5 = (k_sem *)(param_1 + 0x80);
    goto LAB_0002d2a8;
  case 0x13:
    bVar2 = param_2[4];
    if (0 < (int)LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): BLE_REQ_PUT_NOTIFY_EN enable:%d\n");
      }
      else {
        ble_printk("%s(): BLE_REQ_PUT_NOTIFY_EN enable:%d\n","master_process_put_req",(uint)bVar2,
                   BLE_DEBUG);
      }
    }
    FUN_00019c80((uint)bVar2);
    break;
  case 0x25:
    if (param_2[8] != 2) {
      return 0;
    }
    if (1 < (int)LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): ble recv raster_config_info:enable is %d, raster_height_gear is %d, canvas_distance_gear is %d\n"
              );
      }
      else {
        ble_printk("%s(): ble recv raster_config_info:enable is %d, raster_height_gear is %d, canvas_distance_gear is %d\n"
                   ,"master_process_put_req",(uint)param_2[9],(uint)param_2[10],(uint)param_2[0xb]);
      }
    }
    if (param_2[9] != 1) {
      **(undefined1 **)(param_1 + 0x1020) = 0;
      return 0;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x73) = 1;
    uVar13 = 0xf;
    **(undefined1 **)(param_1 + 0x1020) = 1;
    param_1[0xec0] = param_2[10];
    param_1[0xec1] = param_2[0xb];
LAB_0002d364:
    update_persist_task_status((int)param_1,uVar13,2);
switchD_0002d152_caseD_3:
    return 0;
  }
LAB_0002d252:
  bVar2 = 0xc9;
LAB_0002d2c8:
  *param_3 = bVar2;
  return 1;
}



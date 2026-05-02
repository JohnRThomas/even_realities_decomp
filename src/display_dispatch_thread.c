/*
 * Function: display_dispatch_thread
 * Entry:    0002afb8
 * Prototype: undefined __stdcall display_dispatch_thread(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


void display_dispatch_thread(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  byte bVar4;
  GlassesState *pGVar5;
  GlassesState *pGVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_r0;
  char *pcVar9;
  uint extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 uVar10;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  uint extraout_r1_08;
  uint extraout_r1_09;
  uint extraout_r1_10;
  uint extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  undefined4 extraout_r1_14;
  uint uVar11;
  uint extraout_r1_15;
  undefined4 extraout_r1_16;
  uint extraout_r1_17;
  uint extraout_r1_18;
  uint extraout_r1_19;
  uint extraout_r1_20;
  uint extraout_r1_21;
  uint extraout_r1_22;
  uint extraout_r1_23;
  uint extraout_r1_24;
  uint extraout_r1_25;
  uint extraout_r1_26;
  uint extraout_r1_27;
  uint extraout_r1_28;
  uint extraout_r1_29;
  uint extraout_r1_30;
  uint extraout_r1_31;
  uint extraout_r1_32;
  uint extraout_r1_33;
  uint extraout_r1_34;
  uint extraout_r1_35;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_06;
  uint uVar12;
  uint extraout_r2_07;
  uint extraout_r2_08;
  undefined4 extraout_r2_11;
  uint extraout_r2_12;
  uint extraout_r2_13;
  uint extraout_r2_14;
  uint extraout_r2_15;
  uint extraout_r2_16;
  uint extraout_r2_17;
  uint extraout_r2_18;
  uint extraout_r2_19;
  uint extraout_r2_20;
  uint extraout_r2_21;
  uint extraout_r2_22;
  uint extraout_r2_23;
  uint extraout_r2_24;
  uint extraout_r2_25;
  uint extraout_r2_26;
  uint extraout_r2_27;
  uint extraout_r2_28;
  uint extraout_r2_29;
  uint extraout_r2_30;
  uint extraout_r2_31;
  uint extraout_r2_32;
  uint uVar13;
  byte *pbVar14;
  size_t n;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  k_timeout_t timeout_02;
  k_timeout_t timeout_03;
  k_timeout_t timeout_04;
  k_timeout_t timeout_05;
  longlong lVar20;
  longlong lVar21;
  k_timeout_t timeout_06;
  undefined8 uVar22;
  uint local_34;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enter\n");
    }
    else {
      ble_printk("%s(): enter\n","display_dispatch_thread",param_3,BLE_DEBUG);
    }
  }
  param_1[0xecc] = 0x12;
  param_1[0xecd] = 0;
  param_1[0xece] = 0;
  param_1[0xecf] = 0;
  param_1[0xfec] = 0;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): raster_height_gear:%d, canvas_distance_gear:%d\n","display_dispatch_thread");
    }
    else {
      ble_printk("%s(): raster_height_gear:%d, canvas_distance_gear:%d\n","display_dispatch_thread",
                 (uint)param_1[0xec0],(uint)param_1[0xec1]);
    }
  }
  param_1[0xeb4] = 0;
  param_1[0xeb5] = 0;
  param_1[0xeb6] = 0;
  param_1[0xeb7] = 0;
  pGVar5 = __get_dashboard_state();
  pGVar6 = __get_dashboard_state();
  cal_panel_canvas_coord((int *)&pGVar5->field_0xec4,(int *)&pGVar6->field_0xeb8);
  *(short *)(param_1 + 0xd6) =
       (short)*(undefined4 *)(param_1 + 0xeb4) + *(short *)(param_1 + 0x108a);
  param_1[0xeec] = 0;
  param_1[0xeed] = 0;
  param_1[0xeee] = 0;
  param_1[0xeef] = 0;
  *(short *)(param_1 + 0xd8) =
       (short)*(undefined4 *)(param_1 + 0xeb8) + *(short *)(param_1 + 0x108c);
  param_1[0xfeb] = 1;
  param_1[0xd5] = 0;
  if (param_1[0xfee] == 0xb) {
    change_work_mode(2);
    cVar2 = FUN_00033d5c();
    if (cVar2 == '\x01') {
      __enter_silent_mode();
    }
  }
  n = 0;
  uVar15 = 0;
  iVar19 = 0;
  local_34 = 1;
  pbVar14 = (byte *)0x0;
LAB_0002b07a:
  do {
    pbVar18 = pbVar14;
    if ((param_1[1] == 1) || (pGVar5 = __get_dashboard_state(), pGVar5->field_0x1 == '\b')) {
      uVar7 = 0x28000;
      goto LAB_0002b10e;
    }
    uVar11 = extraout_r1;
    if ((param_1[0xfec] == 0) &&
       (bVar3 = FUN_0002da10((int)param_1), uVar11 = extraout_r1_00, !bVar3)) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): master sync display suspend.\n");
        }
        else {
          ble_printk("%s(): master sync display suspend.\n","display_dispatch_thread",extraout_r2,
                     BLE_DEBUG);
        }
      }
      param_1[0xcb] = param_1[0xed5];
      cVar2 = FUN_000169b4();
      uVar7 = extraout_r1_01;
      uVar10 = extraout_r2_00;
      if (cVar2 != '\x03') {
        sync_to_slave((char *)param_1,1,(undefined4 *)0x0,0);
        change_work_mode(3);
        uVar7 = extraout_r1_02;
        uVar10 = extraout_r2_01;
      }
      if (*param_1 == 2) {
        while (*(int *)(param_1 + 0x40) != 0) {
          timeout.ticks._4_4_ = 0xffffffff;
          timeout.ticks._0_4_ = uVar7;
          z_impl_k_sem_take((k_sem *)(param_1 + 0x38),timeout);
          uVar7 = extraout_r1_03;
          uVar10 = extraout_r2_02;
        }
        while (*(int *)(param_1 + 0x58) != 0) {
          timeout_00.ticks._4_4_ = 0xffffffff;
          timeout_00.ticks._0_4_ = uVar7;
          z_impl_k_sem_take((k_sem *)(param_1 + 0x50),timeout_00);
          uVar7 = extraout_r1_04;
          uVar10 = extraout_r2_03;
        }
      }
      if ((param_1[0xfec] != 0) ||
         (bVar3 = FUN_0002da10((int)param_1), uVar7 = extraout_r1_05, uVar10 = extraout_r2_04, bVar3
         )) {
        while (*(int *)(param_1 + 0x58) != 0) {
          timeout_03.ticks._4_4_ = 0xffffffff;
          timeout_03.ticks._0_4_ = uVar7;
          z_impl_k_sem_take((k_sem *)(param_1 + 0x50),timeout_03);
          uVar7 = extraout_r1_14;
          uVar10 = extraout_r2_10;
        }
      }
      else {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): thread goto sleep.\n");
            uVar7 = extraout_r1_12;
          }
          else {
            ble_printk("%s(): thread goto sleep.\n","display_dispatch_thread",extraout_r2_04,
                       BLE_DEBUG);
            uVar7 = extraout_r1_06;
          }
        }
        DAT_20019a64 = 0;
        timeout_01.ticks._4_4_ = 0xffffffff;
        timeout_01.ticks._0_4_ = uVar7;
        z_impl_k_sem_take((k_sem *)(param_1 + 0x50),timeout_01);
        uVar10 = extraout_r2_05;
        if (*param_1 == 2) {
          uVar7 = extraout_r1_07;
          while (*(int *)(param_1 + 0x40) != 0) {
            timeout_02.ticks._4_4_ = 0xffffffff;
            timeout_02.ticks._0_4_ = uVar7;
            z_impl_k_sem_take((k_sem *)(param_1 + 0x38),timeout_02);
            uVar7 = extraout_r1_13;
            uVar10 = extraout_r2_09;
          }
        }
        iVar19 = 4;
      }
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): thread wakeup!.\n");
          uVar7 = extraout_r2_11;
        }
        else {
          ble_printk("%s(): thread wakeup!.\n","display_dispatch_thread",uVar10,BLE_DEBUG);
          uVar7 = extraout_r2_06;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sync display resume.\n");
          }
          else {
            ble_printk("%s(): sync display resume.\n","display_dispatch_thread",uVar7,BLE_DEBUG);
          }
        }
      }
      param_1[0xcb] = param_1[0xed5];
      change_work_mode(2);
      uVar15 = 1;
      uVar11 = extraout_r1_08;
    }
    uVar12 = (uint)*param_1;
    if (param_1[0xfeb] == 0) goto LAB_0002b38e;
    if ((uVar12 == 1) && (iVar19 = iVar19 + 1, iVar19 == 5)) {
      if ((param_1[0xf9c] == 0) ||
         ((*(int *)(param_1 + 0xf94) == 0 || (*(int *)(param_1 + 0xec8) == 0)))) {
        iVar19 = 4;
      }
      else {
        bVar4 = FUN_00010848(param_1 + 0xf84,uVar11,1);
        uVar11 = extraout_r1_09;
        if (bVar4 == 0xff) {
          iVar19 = 0;
        }
        else {
          bVar1 = param_1[0xed5];
          if (bVar1 < bVar4) {
            cVar2 = '\x01';
LAB_0002b23a:
            param_1[0xed5] = bVar1 + cVar2;
          }
          else if (bVar1 != bVar4) {
            cVar2 = -1;
            goto LAB_0002b23a;
          }
          iVar19 = (uint)(param_1[0xed5] != bVar4) << 2;
        }
      }
      if (param_1[0xed6] != param_1[0xed5]) {
        param_1[0xed6] = param_1[0xed5];
        if ((((param_1[0xd5] == 6) && (*(char *)(*(int *)(param_1 + 0xff0) + 0x66) != '\0')) ||
            (param_1[0xd5] == 10)) || (param_1[0xd5] == 4)) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          if (param_1[0xd5] != 0x14) {
            uVar15 = 1;
          }
        }
      }
    }
    uVar12 = **(uint **)(param_1 + 0x1068);
    *(uint *)(param_1 + 0xdf) = uVar12;
    param_1[0xe3] = (byte)(*(uint **)(param_1 + 0x1068))[1];
    if (*param_1 == 1) {
      param_1[0xe9] = param_1[0xcc];
      param_1[0xea] = param_1[0xcd];
      param_1[0xeb] = param_1[0xee8];
      param_1[0xec] = param_1[0xd5];
LAB_0002b2c2:
      if ((param_1[0xfee] == 0xc) && (param_1[0xd5] != 7)) goto LAB_0002b38e;
      bVar3 = FUN_0002da10((int)param_1);
      if (!bVar3) {
        uVar17 = 0;
        uVar11 = extraout_r1_10;
        uVar12 = extraout_r2_07;
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): no running task, goto next trun\n","display_dispatch_thread",
                       extraout_r2_07,BLE_DEBUG);
            uVar11 = extraout_r1_11;
            uVar12 = extraout_r2_08;
            goto LAB_0002b38e;
          }
          printk("%s(): no running task, goto next trun\n");
          uVar11 = extraout_r1_15;
          uVar12 = extraout_r2_13;
        }
        goto LAB_0002b398;
      }
      timeout_05.ticks._4_4_ = 0xffffffff;
      timeout_05.ticks._0_4_ = extraout_r1_10;
      z_impl_k_mutex_lock(&k_mutex_2000851c,timeout_05);
      uVar13 = (uint)param_1[0xd5];
      switch(param_1[0xd5]) {
      case 2:
        FUN_00037af4(param_1,*(int **)(param_1 + 0xff4));
        n = 7;
        pbVar14 = *(byte **)(param_1 + 0xff4);
        break;
      case 3:
        uVar22 = FUN_0007fea6();
        iVar8 = (int)uVar22;
        if ((DAT_200084dc != 0) && (iVar8 = DAT_200084dc, 9999 < (uint)((int)uVar22 - DAT_200084dc))
           ) {
          DAT_200084d8 = (DAT_200084d8 + 1) % 7;
          iVar8 = 0;
        }
        DAT_200084dc = iVar8;
        iVar8 = DAT_200084d8;
        DAT_200084d4 = DAT_200084d4 + 1;
        param_1[0xe6] = (byte)DAT_200084d4;
        param_1[0xe5] = (byte)iVar8;
        break;
      case 4:
        cVar2 = '3';
        while ((param_1[0xec] != param_1[0xd5] && (cVar2 = cVar2 + -1, cVar2 != '\0'))) {
          k_msleep(10);
        }
        bVar4 = FUN_000359cc();
        pbVar14 = (byte *)FUN_00035260((uint)bVar4);
        iVar8 = FUN_0002ddb0();
        if ((iVar8 == 0) && (pGVar5 = __get_dashboard_state(), pGVar5->field_0xdd == DAT_2001993c))
        {
          if (uVar15 == 0) {
            unlock_mutext_2000851c();
            n = 0x1b4;
            uVar11 = extraout_r1_20;
            uVar12 = extraout_r2_17;
            goto LAB_0002b38e;
          }
        }
        else {
          pGVar5 = __get_dashboard_state();
          DAT_2001993c = pGVar5->field_0xdd;
        }
        n = 0x1b4;
        uVar15 = 1;
        break;
      case 5:
      case 6:
      case 0xf:
        n = 0x75;
        pbVar14 = *(byte **)(param_1 + 0xff0);
        break;
      case 7:
        n = 0xb;
        pbVar14 = *(byte **)(param_1 + 0x1018);
        break;
      case 8:
        n = 0x16a;
        pbVar14 = *(byte **)(param_1 + 0xff8);
        break;
      case 9:
        n = 0x217;
        pbVar14 = *(byte **)(param_1 + 0x1000);
        break;
      case 10:
        bVar4 = param_1[0xee8];
        iVar8 = *(int *)(param_1 + 0x1004);
        if (bVar4 == 2) {
          if ((local_34 != 2) || (*(char *)(iVar8 + 7) != '\x02')) {
LAB_0002b598:
            uVar15 = 1;
            *(byte *)(iVar8 + 7) = bVar4;
          }
        }
        else if ((bVar4 != local_34) || (*(char *)(iVar8 + 7) != '\x01')) {
          bVar4 = 1;
          goto LAB_0002b598;
        }
        n = 0xf5;
        pbVar14 = *(byte **)(param_1 + 0x1004);
        break;
      case 0xb:
        pbVar14 = *(byte **)(param_1 + 0x100c);
        if (pbVar14[3] - 5 < 2) {
          if (((*param_1 != 2) || (param_1[0xcc] == param_1[0xe9])) ||
             (pbVar18 = *(byte **)(param_1 + 0x1038),
             (*(byte **)(param_1 + 0x1038))[0x200] != param_1[0xe9])) {
            pbVar18 = pbVar14;
          }
        }
        else {
          pbVar18 = *(byte **)(param_1 + 0x1008);
          if (1 < pbVar18[3] - 5) {
            if (param_1[0xee8] == 2) {
              if ((local_34 != 2) || (pbVar14[1] == *pbVar14)) goto LAB_0002b63e;
LAB_0002b652:
              if (((*param_1 == 2) && (param_1[0xcc] != param_1[0xe9])) &&
                 (pbVar18 = *(byte **)(param_1 + 0x1038),
                 (*(byte **)(param_1 + 0x1038))[0x200] == param_1[0xe9])) goto LAB_0002b5cc;
              pbVar14 = *(byte **)(param_1 + 0x100c);
            }
            else {
              if (pbVar14[1] == *pbVar14) {
LAB_0002b63e:
                pbVar14[3] = 2;
                goto LAB_0002b652;
              }
              if (param_1[0xee8] != local_34) {
                pbVar18[3] = 4;
              }
              if (((*param_1 == 2) && (param_1[0xcd] != param_1[0xea])) &&
                 (pbVar18 = *(byte **)(param_1 + 0x103c),
                 (*(byte **)(param_1 + 0x103c))[0x200] == param_1[0xea])) goto LAB_0002b5cc;
              pbVar14 = *(byte **)(param_1 + 0x1008);
            }
            n = 0x1e8;
            break;
          }
          if (((*param_1 == 2) && (param_1[0xcd] != param_1[0xea])) &&
             ((*(byte **)(param_1 + 0x103c))[0x200] == param_1[0xea])) {
            pbVar18 = *(byte **)(param_1 + 0x103c);
          }
        }
LAB_0002b5cc:
        n = 0x1e8;
        goto LAB_0002b5d0;
      case 0xc:
        n = 0x152;
        pbVar14 = *(byte **)(param_1 + 0x1034);
        break;
      case 0xe:
        pGVar5 = __get_dashboard_state();
        pGVar5->field_0xed5 = 0x2a;
        n = 0x21;
        pbVar14 = *(byte **)(param_1 + 0x101c);
        break;
      case 0x10:
        pbVar18 = *(byte **)(param_1 + 0x1010);
        if ((0xb < *pbVar18) && ((*pbVar18 & 0xfd) == 0xd)) {
          unlock_mutext_2000851c();
          uVar11 = extraout_r1_22;
          uVar12 = extraout_r2_19;
          goto LAB_0002b38e;
        }
        if (((*param_1 == 2) && (bVar4 = param_1[0xe9], param_1[0xcc] != bVar4)) &&
           (pbVar14 = *(byte **)(param_1 + 0x1038), bVar4 == pbVar14[0x200])) {
          pbVar18[6] = bVar4;
          pbVar18 = pbVar14;
        }
        else {
          pGVar5 = __get_dashboard_state();
          *(undefined1 *)(*(int *)(param_1 + 0x1010) + 6) = pGVar5->field_0xcc;
        }
        if (**(char **)(param_1 + 0x1010) == '\a') {
          (*(char **)(param_1 + 0x1010))[1] = '\x03';
        }
        n = 0x1e9;
        goto LAB_0002b5d0;
      case 0x11:
        n = 2;
        pbVar14 = *(byte **)(param_1 + 0x1024);
        break;
      case 0x12:
        n = 10;
        pbVar14 = *(byte **)(param_1 + 0x1028);
        break;
      case 0x13:
        n = 0x208;
        pbVar14 = *(byte **)(param_1 + 0x102c);
        break;
      case 0x14:
        n = 0x210;
        pbVar14 = *(byte **)(param_1 + 0x1014);
      }
      pbVar18 = pbVar14;
      uVar16 = uVar15;
      if (pbVar14 != (byte *)0x0) {
LAB_0002b5d0:
        iVar8 = memcmp(param_1 + 0xef,pbVar18,n);
        if (((iVar8 != 0) || (uVar15 != 0)) || (param_1[0xd5] != DAT_2000aa78)) {
          memcpy(param_1 + 0xef,pbVar18,n);
          pbVar14 = pbVar18;
          uVar16 = uVar15;
          goto LAB_0002b4a6;
        }
        unlock_mutext_2000851c();
        uVar17 = 0;
        uVar11 = extraout_r1_21;
        uVar12 = extraout_r2_18;
        goto LAB_0002b398;
      }
LAB_0002b4a6:
      memset(param_1 + n + 0xef,0,0x5dc - n);
      *(short *)(param_1 + 0xed) = (short)n;
      unlock_mutext_2000851c();
      if ((param_1[0xfea] == 0) ||
         (uVar11 = extraout_r1_17, uVar12 = extraout_r2_14, uVar15 = uVar16, param_1[0xfea] == 5)) {
        pbVar18 = pbVar14;
        if (*param_1 == 1) {
          if ((uint)param_1[0xcb] != (uint)param_1[0xed5]) {
            set_brightness_to_panel_reg_in_running((uint)param_1[0xed5],extraout_r1_17);
            param_1[0xcb] = param_1[0xed5];
          }
          uVar17 = sync_to_slave((char *)param_1,0,(undefined4 *)0x0,0);
          uVar15 = 1;
          uVar11 = extraout_r1_18;
          uVar12 = extraout_r2_15;
          if (4999 < (int)uVar17) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): sync to slave exceed MAX_WAIT_COUNT, wait_time %d\n");
                uVar11 = extraout_r1_23;
                uVar12 = extraout_r2_20;
              }
              else {
                ble_printk("%s(): sync to slave exceed MAX_WAIT_COUNT, wait_time %d\n",
                           "display_dispatch_thread",uVar17,BLE_DEBUG);
                uVar11 = extraout_r1_19;
                uVar12 = extraout_r2_16;
              }
            }
            goto LAB_0002b38e;
          }
          if ((int)uVar17 < 3000) {
            if ((int)uVar17 < 500) {
              uVar12 = (uint)param_1[0xec];
              if (((uVar12 == param_1[0xd5]) || (param_1[0xd5] < 7)) || (uVar12 < 7))
              goto LAB_0002b840;
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): screen id was changed, g->master_sync_pkg.new_screen_id %d pkg->screen_id %d\n"
                         ,"display_dispatch_thread",uVar12,(uint)param_1[0xd5]);
                  uVar11 = extraout_r1_27;
                  uVar12 = extraout_r2_24;
                }
                else {
                  ble_printk("%s(): screen id was changed, g->master_sync_pkg.new_screen_id %d pkg->screen_id %d\n"
                             ,"display_dispatch_thread",uVar12,(uint)param_1[0xd5]);
                  uVar11 = extraout_r1_26;
                  uVar12 = extraout_r2_23;
                }
              }
              uVar17 = 0x46;
            }
            else if (0 < LOG_LEVEL) {
              pcVar9 = "%s(): sync to slave exceed LOW_WAIT_COUNT, wait_time %d\n";
              goto LAB_0002b7ca;
            }
          }
          else if (0 < LOG_LEVEL) {
            pcVar9 = "%s(): sync to slave exceed CMD_WAIT_COUNT, wait_time %d\n";
LAB_0002b7ca:
            if (BLE_DEBUG == 0) {
              printk(pcVar9);
              uVar11 = extraout_r1_25;
              uVar12 = extraout_r2_22;
            }
            else {
              ble_printk(pcVar9,"display_dispatch_thread",uVar17,BLE_DEBUG);
              uVar11 = extraout_r1_24;
              uVar12 = extraout_r2_21;
            }
          }
        }
        else {
          uVar17 = 0;
LAB_0002b840:
          bVar3 = FUN_0002da10((int)param_1);
          uVar11 = extraout_r1_28;
          if (bVar3) {
            uVar12 = uVar13;
            if (param_1[0xd5] == uVar13) {
              if (param_1[0xfec] != 0) {
                uVar13 = (uint)param_1[0xee8];
                uVar15 = extraout_r1_28;
                uVar11 = (uint)param_1[0xd5];
                uVar12 = uVar13;
                if ((((param_1[0xd5] == 10) &&
                     (uVar11 = local_34, uVar12 = local_34, local_34 != uVar13)) &&
                    (uVar11 = uVar16, uVar12 = uVar13, uVar16 != 1)) &&
                   (uVar12 = local_34, 1 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): imu->attitude changed ....\n");
                    uVar15 = extraout_r1_34;
                    uVar11 = extraout_r2_31;
                  }
                  else {
                    ble_printk("%s(): imu->attitude changed ....\n","display_dispatch_thread",uVar16
                               ,BLE_DEBUG);
                    uVar15 = extraout_r1_31;
                    uVar11 = extraout_r2_28;
                  }
                }
                local_34 = uVar12;
                FUN_00080fca(param_1[0xd5],uVar15,uVar11);
                uVar11 = extraout_r1_32;
                uVar12 = extraout_r2_29;
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): display_reflash_screen %d done\n");
                    uVar11 = extraout_r1_35;
                    uVar12 = extraout_r2_32;
                  }
                  else {
                    ble_printk("%s(): display_reflash_screen %d done\n","display_dispatch_thread",
                               (uint)param_1[0xd5],BLE_DEBUG);
                    uVar11 = extraout_r1_33;
                    uVar12 = extraout_r2_30;
                  }
                }
                if ((param_1[0xec] == 6) || (uVar15 = 0, param_1[0xec] != 0)) {
                  uVar15 = 0;
                }
                goto LAB_0002b398;
              }
              if (0 < LOG_LEVEL) {
                pcVar9 = "%s(): trigger_on_screen is closed\n";
                goto LAB_0002b858;
              }
            }
            else if (0 < LOG_LEVEL) {
              pcVar9 = "%s(): screen is closed\n";
              goto LAB_0002b858;
            }
          }
          else {
            uVar12 = extraout_r2_25;
            if (0 < LOG_LEVEL) {
              pcVar9 = "%s(): task was closed!!!\n";
              uVar13 = extraout_r2_25;
LAB_0002b858:
              if (BLE_DEBUG == 0) {
                printk(pcVar9);
                uVar11 = extraout_r1_30;
                uVar12 = extraout_r2_27;
              }
              else {
                ble_printk(pcVar9,"display_dispatch_thread",uVar13,BLE_DEBUG);
                uVar11 = extraout_r1_29;
                uVar12 = extraout_r2_26;
              }
            }
          }
          uVar15 = 1;
        }
      }
      else {
LAB_0002b38e:
        uVar17 = 0;
        pbVar18 = pbVar14;
      }
LAB_0002b398:
      pbVar14 = pbVar18;
      if (*param_1 == 1) {
        if (DAT_20019a69 == '\x0f') {
          iVar8 = 0xf1;
LAB_0002b3b6:
          FUN_00029774(iVar8,uVar11,uVar12);
        }
        else {
          if (DAT_20019a69 == 'N') {
            iVar8 = 0xf2;
            goto LAB_0002b3b6;
          }
          if (DAT_20019a69 == '\r') {
            iVar8 = 0xf0;
            goto LAB_0002b3b6;
          }
        }
        DAT_20019a69 = '\0';
        if (*param_1 != 1) goto LAB_0002b92a;
        if (0x45 < (int)uVar17) goto LAB_0002b07a;
        lVar20 = (longlong)(int)(0x46 - uVar17) * 0x8000 + 999;
        __aeabi_uldivmod((int)lVar20,(int)((ulonglong)lVar20 >> 0x20),1000,0);
        uVar7 = extraout_r0;
        uVar10 = extraout_r1_16;
      }
      else {
LAB_0002b92a:
        if ((param_1[0xfea] == 0) || (param_1[0xfea] == 5)) goto LAB_0002b07a;
        uVar7 = 0x148;
LAB_0002b10e:
        uVar10 = 0;
      }
      timeout_06.ticks._4_4_ = uVar10;
      timeout_06.ticks._0_4_ = uVar7;
      z_impl_k_sleep(timeout_06);
      pbVar14 = pbVar18;
      goto LAB_0002b07a;
    }
    if ((1 < param_1[0xfea] - 1) && (param_1[0xfea] != 4)) {
      lVar20 = FUN_0007fea6();
      timeout_04.ticks._0_4_ = (undefined4)((ulonglong)lVar20 >> 0x20);
      timeout_04.ticks._4_4_ = 0x4000;
      z_impl_k_sem_take((k_sem *)(param_1 + 0x38),timeout_04);
      lVar21 = FUN_0007fea6();
      iVar8 = (int)((ulonglong)(lVar21 - lVar20) >> 0x20);
      bVar3 = (uint)(lVar21 - lVar20) < 500;
      uVar11 = iVar8 - (uint)bVar3;
      uVar12 = extraout_r2_12;
      if ((int)(uint)bVar3 <= iVar8) goto LAB_0002b38e;
      goto LAB_0002b2c2;
    }
    k_msleep(0x32);
  } while( true );
}



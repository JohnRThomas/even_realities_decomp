/*
 * Function: ble_process_req_dispatch
 * Entry:    000225a8
 * Prototype: undefined4 __stdcall ble_process_req_dispatch(int param_1, byte * param_2, byte * param_3)
 */


undefined4 ble_process_req_dispatch(int param_1,byte *param_2,byte *param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  bool bVar5;
  bt_conn *conn;
  GlassesState *pGVar6;
  char *pcVar7;
  undefined2 uVar8;
  byte bVar9;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined1 uVar10;
  char cVar11;
  byte bVar12;
  undefined1 *puVar13;
  code *pcVar14;
  byte *pbVar15;
  byte bVar16;
  int iVar17;
  uint uVar18;
  undefined4 *d;
  void *pvVar19;
  int iVar20;
  uint8_t *puVar21;
  size_t n;
  undefined4 *puVar22;
  undefined2 *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  k_timeout_t duration;
  longlong lVar27;
  undefined8 uVar28;
  undefined1 local_bc;
  undefined2 uStack_bb;
  byte bStack_b9;
  undefined4 local_b8;
  byte local_b4;
  undefined1 local_b3;
  byte local_a8 [132];
  
  uVar18 = (uint)*param_2;
  if (uVar18 - 1 < 0x27) {
    ble_process_put_req(param_1,param_2,param_3);
    return 0;
  }
  if (uVar18 - 0x29 < 0x1d) {
    ble_process_get_req(param_1,param_2,(undefined4 *)param_3);
    return 0;
  }
  if (0xf < uVar18 - 0x47) {
    if (5 < (uVar18 + 0xf & 0xff)) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): tx error req_type. %d\n");
        }
        else {
          ble_printk("%s(): tx error req_type. %d\n","ble_process_req_dispatch",uVar18,BLE_DEBUG);
        }
      }
      pcVar14 = *(code **)(param_1 + 0xc);
      pcVar7 = "NN";
      uVar8 = 3;
      goto LAB_00022bfc;
    }
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    memset(local_a8 + 4,0,0x11);
    if (uVar18 == 0xf4) {
      FUN_0007f4d2(param_1);
      return 0;
    }
    if (uVar18 == 0xf5) {
      deal_event_to_phone(param_1,(undefined2 *)param_3);
      return 0;
    }
    if (uVar18 == 0xf1) {
      if ((param_3[2] & 0xfd) == 0xc9) {
        return 0;
      }
      if (param_3[2] == 0xcc) {
        send_dmic_msg(param_1);
        return 0;
      }
      if (1 < LOG_LEVEL) {
        uVar18 = 0xf1;
LAB_0002395e:
        if (BLE_DEBUG == 0) {
          printk("%s(): @tx error post req_type: %d\n");
        }
        else {
          ble_printk("%s(): @tx error post req_type: %d\n","ble_process_report_response",uVar18,
                     BLE_DEBUG);
        }
      }
    }
    else if (1 < LOG_LEVEL) goto LAB_0002395e;
    uVar4 = local_a8._0_4_;
    local_a8[1] = 0xca;
    local_a8[3] = SUB41(uVar4,3);
    local_a8[2] = 0x15;
    strcpy((char *)(local_a8 + 2),"error post req.");
    pcVar14 = *(code **)(param_1 + 0xc);
    pcVar7 = (char *)local_a8;
    uVar8 = 0x14;
    goto LAB_00022bfc;
  }
  puVar22 = *(undefined4 **)(param_1 + 0x10);
  _local_bc = 0;
  memset(&local_b8,0,0x10);
  d = puVar22 + 1;
  *puVar22 = *(undefined4 *)param_2;
  *(uint *)(param_1 + 0x14) = *(ushort *)(param_2 + 2) + 4;
  bVar16 = *param_2;
  uVar18 = (uint)bVar16;
  _local_bc = CONCAT31(_uStack_bb,bVar16);
  switch(uVar18) {
  case 0x47:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): *****will unbond current bt connection*****\n\n");
      }
      else {
        ble_printk("%s(): *****will unbond current bt connection*****\n\n","ble_process_post_req",
                   uVar18,BLE_DEBUG);
      }
    }
    _local_bc = CONCAT11(0xc9,local_bc);
    (**(code **)(param_1 + 0xc))(&local_bc);
    iVar20 = bt_unpair('\0',(bt_addr_le_t *)0x0);
    if ((iVar20 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): bt_unpair fail: %d\n\n");
      }
      else {
        ble_printk("%s(): bt_unpair fail: %d\n\n","ble_process_post_req",iVar20,BLE_DEBUG);
      }
    }
    conn = (bt_conn *)FUN_00019cec();
    if (conn == (bt_conn *)0x0) {
      return 0;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): bt_conn_disconnect because recv unpair\n");
      }
      else {
        ble_printk("%s(): bt_conn_disconnect because recv unpair\n","ble_process_post_req",
                   extraout_r2,BLE_DEBUG);
      }
    }
    bt_conn_disconnect(conn,'\x13');
    return 0;
  default:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): @tx error post req_type: %d\n");
      }
      else {
        ble_printk("%s(): @tx error post req_type: %d\n","ble_process_post_req",uVar18,BLE_DEBUG);
      }
    }
    uVar4 = _local_bc;
    _local_bc = CONCAT11(0xca,local_bc);
    bStack_b9 = SUB41(uVar4,3);
    _local_bc = CONCAT12(0x15,_local_bc);
    strcpy((char *)((int)&uStack_bb + 1),"error post req.");
    break;
  case 0x49:
  case 0x4d:
    goto switchD_0002260e_caseD_49;
  case 0x4a:
    **(undefined4 **)(param_1 + 0x10) = *(undefined4 *)param_2;
    memcpy(d,param_3 + 1,*(ushort *)(param_2 + 2) - 1);
    *(uint *)(param_1 + 0x14) = *(ushort *)(param_2 + 2) + 4;
    goto switchD_0002260e_caseD_49;
  case 0x4b:
    post_notification_cmd_process(param_1,param_2,param_3);
    return 0;
  case 0x4c:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ble_process_post_req BLE_REQ_POST_DELETE_NOTIFICATION_MSG\n");
      }
      else {
        ble_printk("%s(): ble_process_post_req BLE_REQ_POST_DELETE_NOTIFICATION_MSG\n",
                   "ble_process_post_req",uVar18,BLE_DEBUG);
      }
    }
    memcpy(d,param_3 + 1,*(ushort *)(param_2 + 2) - 1);
switchD_0002260e_caseD_49:
    FUN_00019d14(param_1,local_a8,8);
    _local_bc = CONCAT11(0xc9,local_bc);
    break;
  case 0x4e:
    if (*(short *)(param_2 + 2) != 0) {
      memset(&DAT_20010995,0,0x204);
      if ((uint)param_3[3] == param_3[2] - 1) {
        uVar10 = 0xc9;
      }
      else {
        pGVar6 = __get_dashboard_state();
        pvVar19 = *(void **)&pGVar6->field_0x1010;
        pGVar6 = __get_dashboard_state();
        FUN_0007f472(pvVar19,0x1e9,pGVar6->field_0xcc,1);
        FUN_0007f41e(param_3[1],1);
        uVar10 = 0xcb;
      }
      _local_bc = CONCAT11(uVar10,local_bc);
      memcpy(&DAT_20010995,param_3 + 9,*(ushort *)(param_2 + 2) - 9);
    }
    if (param_3[3] == 0) {
      pGVar6 = __get_dashboard_state();
      memset((void *)(*(int *)&pGVar6->field_0x1010 + 7),0,0x1e0);
      pGVar6 = __get_dashboard_state();
      iVar20 = *(int *)&pGVar6->field_0x1010;
      *(undefined1 *)(iVar20 + 0x1e7) = 0;
      *(undefined1 *)(iVar20 + 0x1e8) = 0;
      pGVar6 = __get_dashboard_state();
      *(byte *)(*(int *)&pGVar6->field_0x1010 + 1) = param_3[4];
      bVar16 = param_3[5];
      bVar12 = param_3[6];
      pGVar6 = __get_dashboard_state();
      *(ushort *)(*(int *)&pGVar6->field_0x1010 + 2) = (ushort)bVar16 * 0x100 + (ushort)bVar12;
      pGVar6 = __get_dashboard_state();
      *(byte *)(*(int *)&pGVar6->field_0x1010 + 4) = param_3[7];
      pGVar6 = __get_dashboard_state();
      *(byte *)(*(int *)&pGVar6->field_0x1010 + 5) = param_3[8];
    }
    pGVar6 = __get_dashboard_state();
    iVar20 = *(int *)&pGVar6->field_0x1010;
    pGVar6 = __get_dashboard_state();
    memcpy((void *)(*(ushort *)(*(int *)&pGVar6->field_0x1010 + 0x1e7) + 7 + iVar20),&DAT_20010995,
           *(ushort *)(param_2 + 2) - 9);
    pGVar6 = __get_dashboard_state();
    *(short *)(*(int *)&pGVar6->field_0x1010 + 0x1e7) =
         *(short *)(*(int *)&pGVar6->field_0x1010 + 0x1e7) + *(short *)(param_2 + 2) + -9;
    uVar2 = *(ushort *)(param_2 + 2);
    *(ushort *)((int)puVar22 + 2) = uVar2;
    *(uint *)(param_1 + 0x14) = uVar2 + 4;
    if ((uint)param_3[3] == param_3[2] - 1) {
      FUN_00019d14(param_1,local_a8,8);
      if ((param_3[4] & 0xf0) == 0x60) {
        FUN_00030458();
        pGVar6 = __get_dashboard_state();
        **(undefined1 **)&pGVar6->field_0x1010 = 10;
      }
      else {
        if ((param_3[4] & 0xf0) == 0x70) {
          pGVar6 = __get_dashboard_state();
          uVar10 = 0xf;
          puVar13 = *(undefined1 **)&pGVar6->field_0x1010;
LAB_00022876:
          *puVar13 = uVar10;
          pGVar6 = __get_dashboard_state();
          uVar10 = 0;
        }
        else {
          pGVar6 = __get_dashboard_state();
          bVar16 = param_3[4] & 0xf0;
          if (**(char **)&pGVar6->field_0x1010 == '\x06') {
            if (bVar16 == 0x40) goto LAB_000228ce;
          }
          else if (bVar16 != 0x30) {
            if (bVar16 == 0x40) {
LAB_000228ce:
              pGVar6 = __get_dashboard_state();
              **(undefined1 **)&pGVar6->field_0x1010 = 8;
              pGVar6 = __get_dashboard_state();
              pGVar6->field_0xdb = 8;
            }
            else {
              pGVar6 = __get_dashboard_state();
              if (6 < **(byte **)&pGVar6->field_0x1010) {
                if ((param_3[4] & 0xf0) == 0x40) goto LAB_000228ce;
                if ((param_3[4] & 0xf0) == 0x50) {
                  pGVar6 = __get_dashboard_state();
                  uVar10 = 9;
                  puVar13 = *(undefined1 **)&pGVar6->field_0x1010;
                  goto LAB_00022876;
                }
              }
            }
            goto LAB_00022826;
          }
          pGVar6 = __get_dashboard_state();
          **(undefined1 **)&pGVar6->field_0x1010 = 7;
          pGVar6 = __get_dashboard_state();
          uVar10 = 0x10;
        }
        pGVar6->field_0xdb = uVar10;
      }
    }
LAB_00022826:
    _local_bc = CONCAT12(param_3[1],_local_bc);
    _local_bc = CONCAT13(param_3[2],_local_bc);
    local_b8 = CONCAT31(local_b8._1_3_,param_3[3]);
    bVar5 = __is_master();
    bVar16 = param_3[3];
    bVar12 = param_3[2];
    if (bVar5) {
      if ((uint)bVar16 == bVar12 - 1) {
        DAT_20019a69 = 0x4e;
        DAT_20019a67 = bVar16;
        DAT_20019a68 = bVar12;
        FUN_0007f41e(param_3[1],0);
        return 0;
      }
    }
    else if ((uint)bVar16 == bVar12 - 1) {
      FUN_0007f41e(param_3[1],0);
    }
    break;
  case 0x4f:
    **(undefined4 **)(param_1 + 0x10) = *(undefined4 *)param_2;
    memcpy(d,param_3 + 1,*(ushort *)(param_2 + 2) - 1);
    FUN_00019d14(param_1,local_a8,8);
    _local_bc = CONCAT11(local_a8[0],local_bc);
    _local_bc = CONCAT12(local_a8[1],_local_bc);
    _local_bc = CONCAT13(local_a8[2],_local_bc);
    break;
  case 0x50:
    uVar18 = (uint)*(ushort *)(param_2 + 2);
    if (*(ushort *)(param_3 + 1) == uVar18) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received Dashboard lock command.\n");
        }
        else {
          ble_printk("%s(): received Dashboard lock command.\n","ble_process_post_req",uVar18,
                     BLE_DEBUG);
        }
      }
      bVar16 = param_3[4];
      pGVar6 = __get_dashboard_state();
      if (*(char *)pGVar6 == '\x01') {
        if (bVar16 == 1) {
          if ((int)(DAT_20007f50 << 0x1e) < 0) {
            return 0;
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): master exec dashboard lock process.\n");
            }
            else {
              ble_printk("%s(): master exec dashboard lock process.\n","ble_process_post_req",
                         extraout_r2_00,BLE_DEBUG);
            }
          }
          DAT_20007f50 = DAT_20007f50 | 2;
          duration.ticks._0_4_ = DAT_20007f4c & 0xfffffffd;
          duration.ticks._4_4_ = 0x8000;
          DAT_20007f4c = (uint)duration.ticks;
          k_timer_start((k_timer *)&DAT_20003ec8,duration,(k_timeout_t)0x0);
          return 0;
        }
        if (LOG_LEVEL < 1) {
          return 0;
        }
        pcVar7 = "%s(): received error dashboard lock action command.\n";
      }
      else {
        if (LOG_LEVEL < 1) {
          return 0;
        }
        pcVar7 = "%s(): slave received error dashboard lock command! can\'t exec\n";
      }
      if (BLE_DEBUG != 0) {
        ble_printk(pcVar7,"ble_process_post_req",extraout_r2_00,BLE_DEBUG);
        return 0;
      }
      printk(pcVar7);
      return 0;
    }
    if (LOG_LEVEL < 2) {
      return 0;
    }
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
                 "ble_process_post_req",uVar18,(uint)*(ushort *)(param_3 + 1));
      return 0;
    }
    printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
           "ble_process_post_req");
    return 0;
  case 0x51:
    _local_bc = CONCAT11(6,bVar16);
    _local_bc = (uint3)_local_bc;
    _local_bc = CONCAT13(param_3[3],_local_bc);
    local_b8 = CONCAT31(local_b8._1_3_,param_3[4]);
    if ((*(short *)(param_2 + 2) == *(short *)(param_3 + 1)) && (param_3[4] < 3)) {
      if (param_3[5] == 1) {
        pGVar6 = __get_dashboard_state();
        *(undefined1 *)&pGVar6->field_global_state_struct_1028->field0_0x0 = 1;
        pGVar6 = __get_dashboard_state();
        *(byte *)((int)&pGVar6->field_global_state_struct_1028->field0_0x0 + 1) = param_3[4];
        lVar27 = FUN_0007f436();
        pGVar6 = __get_dashboard_state();
        *(longlong *)((int)&pGVar6->field_global_state_struct_1028->field0_0x0 + 2) = lVar27 + 5000;
        pGVar6 = __get_dashboard_state();
        pGVar6->field_0xcd = param_3[3];
        pGVar6 = __get_dashboard_state();
        update_persist_task_status((int)pGVar6,0x12,2);
      }
      else {
        pGVar6 = __get_dashboard_state();
        *(undefined1 *)&pGVar6->field_global_state_struct_1028->field0_0x0 = 0;
      }
      uVar10 = 0xc9;
    }
    else {
      uVar10 = 0xca;
    }
    local_b8._0_2_ = CONCAT11(uVar10,(undefined1)local_b8);
    break;
  case 0x52:
    uVar1 = *(ushort *)(param_3 + 1);
    uVar24 = (uint)uVar1;
    uVar2 = *(ushort *)(param_2 + 2);
    uVar18 = (uint)uVar2;
    bVar12 = param_3[4];
    if ((uVar18 != uVar24) || (3 < bVar12)) {
LAB_000237cc:
      bVar9 = param_3[3];
      goto LAB_000237da;
    }
    FUN_000496a4();
    iVar20 = LOG_LEVEL;
    bVar16 = param_3[4];
    if (bVar16 == 2) {
      local_b8 = *(undefined4 *)(param_3 + 4);
      local_b4 = param_3[8];
      uVar3 = *(ushort *)(param_3 + 5);
      uVar25 = (uint)uVar3;
      local_bc = (byte)*(undefined4 *)param_3;
      _local_bc = CONCAT11(10,local_bc);
      bStack_b9 = (byte)((uint)*(undefined4 *)param_3 >> 0x18);
      _local_bc = (uint3)_local_bc;
      uVar26 = (uint)*(ushort *)(param_3 + 7);
      local_b3 = 0xc9;
      if (uVar25 == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received transcribe packet,total packet = 1\n");
          }
          else {
            ble_printk("%s(): received transcribe packet,total packet = 1\n","ble_process_post_req",
                       (uint)local_b4,BLE_DEBUG);
          }
        }
        pGVar6 = __get_dashboard_state();
        pGVar6->___multi_packet_data_buffer[3] = param_3[9];
        if ((param_3[10] == 1) ||
           (pGVar6 = __get_dashboard_state(), pGVar6->___multi_packet_data_buffer[2] == '\x02')) {
          pGVar6 = __get_dashboard_state();
          puVar21 = pGVar6->___multi_packet_data_buffer;
          bVar16 = puVar21[4] & 0xfe;
        }
        else {
          pGVar6 = __get_dashboard_state();
          puVar21 = pGVar6->___multi_packet_data_buffer;
          bVar16 = puVar21[4] | 1;
        }
        puVar21[4] = bVar16;
        pGVar6 = __get_dashboard_state();
        pGVar6->___multi_packet_data_buffer[5] = param_3[0xb];
        memset(&DAT_20010995,0,0x204);
        pGVar6 = __get_dashboard_state();
        memset(pGVar6->___multi_packet_data_buffer + 8,0,0x200);
        pGVar6 = __get_dashboard_state();
        *(ushort *)(pGVar6->___multi_packet_data_buffer + 6) = uVar1 - 0xc;
        pGVar6 = __get_dashboard_state();
        puVar21 = pGVar6->___multi_packet_data_buffer;
        pGVar6 = __get_dashboard_state();
        puVar21 = puVar21 + 8;
        uVar2 = *(ushort *)(pGVar6->___multi_packet_data_buffer + 6);
        pbVar15 = param_3 + 0xc;
LAB_00022d50:
        memcpy(puVar21,pbVar15,(uint)uVar2);
LAB_000231de:
        FUN_0007f4a4(param_3[3],0,0);
      }
      else if (uVar26 == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Received transcribe multiple packets, currently the first packet of data\n"
                  );
          }
          else {
            ble_printk("%s(): Received transcribe multiple packets, currently the first packet of data\n"
                       ,"ble_process_post_req",(uint)local_b4,BLE_DEBUG);
          }
        }
        DAT_2000e0f2 = 1;
        n = uVar24 - 0xc;
        DAT_2000e0f0 = uVar3;
        memset(&DAT_20010995,0,0x204);
        pbVar15 = param_3 + 0xc;
LAB_00022dbe:
        memcpy(&DAT_20010995,pbVar15,n);
        DAT_2000e0f4 = (ushort)n;
      }
      else if (uVar26 < uVar25) {
        if ((uint)DAT_2000e0f2 != uVar26 - 1) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                     ,"ble_process_post_req",uVar26,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                         ,"ble_process_post_req",uVar26,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          DAT_2000e0f0 = uVar3;
LAB_00022e1c:
          memset(&DAT_20010995,0,0x204);
          goto LAB_000232c2;
        }
        if (0x20c < uVar18 + DAT_2000e0f4) {
joined_r0x00022f36:
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG != 0) {
              iVar17 = uVar18 - 0xc;
              pcVar7 = 
              "%s(): transcribe data is too long, the current data length %d,wait write data length = %d\n"
              ;
              goto LAB_00022e62;
            }
            pcVar7 = 
            "%s(): transcribe data is too long, the current data length %d,wait write data length = %d\n"
            ;
LAB_00022e70:
            local_b3 = 0xc9;
            printk(pcVar7,"ble_process_post_req",(uint)DAT_2000e0f4);
          }
          goto LAB_000232c2;
        }
        memcpy(&DAT_20010995 + DAT_2000e0f4,param_3 + 0xc,uVar18 - 0xc);
        DAT_2000e0f4 = uVar2 + (DAT_2000e0f4 - 0xc);
        if (2 < iVar20) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                  );
          }
          else {
            ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                       ,"ble_process_post_req",uVar26,BLE_DEBUG);
          }
        }
        DAT_2000e0f2 = DAT_2000e0f2 + 1;
      }
      else if (uVar25 == uVar26) {
        puVar23 = &DAT_2000e0f2;
        if (((uint)DAT_2000e0f2 != uVar25 - 1) || (DAT_2000e0f0 != uVar25)) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                     ,"ble_process_post_req",uVar26,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                         ,"ble_process_post_req",uVar26,DAT_2000e0f2 + 1);
            }
          }
LAB_00022f0c:
          DAT_2000e0f0 = uVar3;
          *puVar23 = 0;
          goto LAB_00022e1c;
        }
        uVar18 = uVar24;
        if (0x20c < uVar24 + DAT_2000e0f4) goto joined_r0x00022f36;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                  );
          }
          else {
            ble_printk("%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                       ,"ble_process_post_req",uVar24 + DAT_2000e0f4,BLE_DEBUG);
          }
        }
        pGVar6 = __get_dashboard_state();
        pGVar6->___multi_packet_data_buffer[3] = param_3[9];
        if ((param_3[10] == 1) ||
           (pGVar6 = __get_dashboard_state(), pGVar6->___multi_packet_data_buffer[2] == '\x02')) {
          pGVar6 = __get_dashboard_state();
          puVar21 = pGVar6->___multi_packet_data_buffer;
          bVar16 = puVar21[4] & 0xfe;
        }
        else {
          pGVar6 = __get_dashboard_state();
          puVar21 = pGVar6->___multi_packet_data_buffer;
          bVar16 = puVar21[4] | 1;
        }
        puVar21[4] = bVar16;
        pGVar6 = __get_dashboard_state();
        uVar2 = DAT_2000e0f4;
        pGVar6->___multi_packet_data_buffer[5] = param_3[0xb];
        memcpy(&DAT_20010995 + uVar2,param_3 + 0xc,uVar24 - 0xc);
        DAT_2000e0f4 = uVar1 + (DAT_2000e0f4 - 0xc);
        pGVar6 = __get_dashboard_state();
        memset(pGVar6->___multi_packet_data_buffer + 8,0,0x200);
        pGVar6 = __get_dashboard_state();
        memcpy(pGVar6->___multi_packet_data_buffer + 8,&DAT_20010995,(uint)DAT_2000e0f4);
        pGVar6 = __get_dashboard_state();
        *(ushort *)(pGVar6->___multi_packet_data_buffer + 6) = DAT_2000e0f4;
        FUN_0007f4a4(param_3[3],0,0);
        DAT_2000e0f0 = 0;
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
      }
      goto LAB_00022bf4;
    }
    bVar12 = param_3[3];
    if (bVar16 == 3) {
      _local_bc = CONCAT11(7,local_bc);
      _local_bc = (uint3)_local_bc;
      _local_bc = CONCAT13(bVar12,_local_bc);
      goto LAB_00023070;
    }
    if (bVar16 != 1) goto LAB_0002309e;
    bVar16 = param_3[5];
    uVar18 = (uint)bVar16;
    _local_bc = CONCAT11(7,local_bc);
    _local_bc = (uint3)_local_bc;
    _local_bc = CONCAT13(bVar12,_local_bc);
    local_b8._0_3_ = CONCAT12(bVar16,0xc901);
    if (uVar18 == 0) {
      pGVar6 = __get_dashboard_state();
      pbVar15 = pGVar6->___multi_packet_data_buffer;
LAB_00022b82:
      *pbVar15 = bVar16;
      goto LAB_00022b84;
    }
    if (uVar18 - 1 < 2) {
      pGVar6 = __get_dashboard_state();
      memset(pGVar6->___multi_packet_data_buffer,0,0x208);
      pGVar6 = __get_dashboard_state();
      *pGVar6->___multi_packet_data_buffer = '\x01';
      pGVar6 = __get_dashboard_state();
      pGVar6->___multi_packet_data_buffer[2] = local_b8._2_1_;
      pGVar6 = __get_dashboard_state();
      if (pGVar6->___multi_packet_data_buffer[2] == '\x02') {
        pGVar6 = __get_dashboard_state();
        pGVar6->___multi_packet_data_buffer[4] = '\0';
      }
      else {
        pGVar6 = __get_dashboard_state();
        pGVar6->___multi_packet_data_buffer[4] = 0xff;
      }
      pGVar6 = __get_dashboard_state();
      pGVar6->field_0xcd = param_3[3];
      pGVar6 = __get_dashboard_state();
      update_persist_task_status((int)pGVar6,0x13,2);
    }
    else if (uVar18 == 3) {
      FUN_00030484(1);
      pGVar6 = __get_dashboard_state();
      puVar21 = pGVar6->___multi_packet_data_buffer;
      bVar16 = puVar21[4] & 0xfe;
LAB_00022c5a:
      puVar21[4] = bVar16;
    }
    else if (uVar18 == 4) {
      FUN_00030484(0);
      pGVar6 = __get_dashboard_state();
      if (pGVar6->___multi_packet_data_buffer[2] != '\x02') {
        pGVar6 = __get_dashboard_state();
        puVar21 = pGVar6->___multi_packet_data_buffer;
        bVar16 = puVar21[4] | 1;
        goto LAB_00022c5a;
      }
    }
    goto LAB_00022bf4;
  case 0x53:
    bVar12 = param_3[4];
    if ((*(short *)(param_2 + 2) != *(short *)(param_3 + 1)) || (3 < bVar12)) goto LAB_000237cc;
    FUN_000496a4();
    bVar12 = param_3[4];
    bVar9 = param_3[3];
    if (bVar12 == 3) {
      _local_bc = CONCAT11(7,(char)_local_bc);
      _local_bc = (uint3)_local_bc;
      _local_bc = CONCAT13(bVar9,_local_bc);
LAB_00023070:
      local_b8 = CONCAT22(local_b8._2_2_,0xc903);
      pGVar6 = __get_dashboard_state();
      cVar11 = -0x36 - *pGVar6->___multi_packet_data_buffer;
      goto LAB_00023088;
    }
LAB_00023828:
    bVar16 = (byte)_local_bc;
LAB_000237da:
    _local_bc = CONCAT13(bVar9,(uint3)CONCAT11(6,bVar16));
    local_b8 = CONCAT31(local_b8._1_3_,bVar12);
    goto LAB_000230a6;
  case 0x54:
    uVar2 = *(ushort *)(param_3 + 1);
    uVar18 = (uint)uVar2;
    bVar12 = param_3[4];
    if ((*(ushort *)(param_2 + 2) != uVar18) || (7 < bVar12)) goto LAB_000237cc;
    FUN_00049a24();
    iVar20 = LOG_LEVEL;
    bVar16 = param_3[4];
    if (bVar16 < 5) {
      if (1 < bVar16) {
        local_b8 = *(undefined4 *)(param_3 + 4);
        local_b4 = param_3[8];
        local_bc = (byte)*(undefined4 *)param_3;
        _local_bc = CONCAT11(10,local_bc);
        bStack_b9 = (byte)((uint)*(undefined4 *)param_3 >> 0x18);
        _local_bc = (uint3)_local_bc;
        local_b3 = 0xc9;
        if (bVar16 == 2) {
          iVar17 = 0xb;
        }
        else if (bVar16 == 3) {
          iVar17 = 0xc;
        }
        else {
          iVar17 = 10;
        }
        uVar3 = *(ushort *)(param_3 + 5);
        uVar26 = (uint)uVar3;
        uVar24 = (uint)*(ushort *)(param_3 + 7);
        if (uVar26 != 1) {
          if (uVar24 == 1) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): Received evenai_v2 multiple packets, currently the first packet of data\n"
                      );
              }
              else {
                ble_printk("%s(): Received evenai_v2 multiple packets, currently the first packet of data\n"
                           ,"ble_process_post_req",(uint)local_b4,BLE_DEBUG);
              }
            }
            DAT_2000e0f2 = 1;
            n = uVar18 - iVar17;
            DAT_2000e0f0 = uVar3;
            memset(&DAT_20010995,0,0x204);
            pbVar15 = param_3 + iVar17;
            goto LAB_00022dbe;
          }
          if (uVar24 < uVar26) {
            puVar23 = &DAT_2000e0f4;
            if ((uint)DAT_2000e0f2 != uVar24 - 1) {
              if (1 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                         ,"ble_process_post_req",uVar24,DAT_2000e0f2 + 1);
                }
                else {
                  ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                             ,"ble_process_post_req",uVar24,DAT_2000e0f2 + 1);
                }
              }
              DAT_2000e0f2 = 0;
              goto LAB_00022f0c;
            }
            if (0x200 < (int)((uVar18 + DAT_2000e0f4) - iVar17)) {
joined_r0x00023614:
              if (LOG_LEVEL < 1) goto LAB_000232c2;
              if (BLE_DEBUG == 0) {
                pcVar7 = 
                "%s(): evenai_v2 data is too long, the current data length %d,wait write data length = %d\n"
                ;
                goto LAB_00022e70;
              }
              iVar17 = uVar18 - iVar17;
              pcVar7 = 
              "%s(): evenai_v2 data is too long, the current data length %d,wait write data length = %d\n"
              ;
LAB_00022e62:
              local_b3 = 0xc9;
              ble_printk(pcVar7,"ble_process_post_req",(uint)DAT_2000e0f4,iVar17);
              goto LAB_000232c2;
            }
            memcpy(&DAT_20010995 + DAT_2000e0f4,param_3 + iVar17,uVar18 - iVar17);
            DAT_2000e0f4 = (uVar2 + DAT_2000e0f4) - (short)iVar17;
            if (2 < iVar20) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                      );
              }
              else {
                ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                           ,"ble_process_post_req",uVar24,BLE_DEBUG);
              }
            }
            DAT_2000e0f2 = DAT_2000e0f2 + 1;
          }
          else if (uVar24 == uVar26) {
            if (((uint)DAT_2000e0f2 != uVar24 - 1) || (uVar24 != DAT_2000e0f0)) {
              if (1 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                         ,"ble_process_post_req",uVar24,DAT_2000e0f2 + 1);
                }
                else {
                  ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                             ,"ble_process_post_req",uVar24,DAT_2000e0f2 + 1);
                }
              }
              DAT_2000e0f2 = 0;
              DAT_2000e0f0 = uVar3;
              goto LAB_00022e1c;
            }
            if (0x200 < (int)((uVar18 + DAT_2000e0f4) - iVar17)) goto joined_r0x00023614;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                      );
              }
              else {
                ble_printk("%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                           ,"ble_process_post_req",LOG_LEVEL,BLE_DEBUG);
              }
            }
            pGVar6 = __get_dashboard_state();
            *(byte *)(*(int *)&pGVar6->field_0x1014 + 1) = bVar16;
            pGVar6 = __get_dashboard_state();
            *(byte *)(*(int *)&pGVar6->field_0x1014 + 3) = param_3[9];
            if (bVar16 == 4) {
              pGVar6 = __get_dashboard_state();
              if (*(char *)(*(int *)&pGVar6->field_0x1014 + 3) == '\x01') {
                pGVar6 = __get_dashboard_state();
                pGVar6->glasses_state_struct_0FF0->field_0x72 = 2;
              }
              else {
                pGVar6 = __get_dashboard_state();
                if (*(char *)(*(int *)&pGVar6->field_0x1014 + 3) == '\x13') {
                  pGVar6 = __get_dashboard_state();
                  if (*(int *)pGVar6->___glasses_state != 0x14) {
                    pGVar6 = __get_dashboard_state();
                    if ((pGVar6->field_0xd5 == '\x06') &&
                       (pGVar6 = __get_dashboard_state(),
                       pGVar6->glasses_state_struct_0FF0->field_0x74 == '\0')) {
                      pGVar6 = __get_dashboard_state();
                      pGVar6->glasses_state_struct_0FF0->field_0x74 = 1;
                    }
                    pGVar6 = __get_dashboard_state();
                    **(undefined1 **)&pGVar6->field_0x1014 = 1;
                    pGVar6 = __get_dashboard_state();
                    update_persist_task_status((int)pGVar6,0x14,2);
                  }
                  goto LAB_00023674;
                }
              }
            }
            else {
              pGVar6 = __get_dashboard_state();
              *(byte *)(*(int *)&pGVar6->field_0x1014 + 4) = param_3[10];
              if (bVar16 == 2) {
LAB_00023674:
                uVar28 = FUN_0007f436();
                pGVar6 = __get_dashboard_state();
                *(undefined8 *)(*(int *)&pGVar6->field_0x1014 + 6) = uVar28;
              }
              else {
                pGVar6 = __get_dashboard_state();
                *(byte *)(*(int *)&pGVar6->field_0x1014 + 5) = param_3[0xb];
              }
            }
            memcpy(&DAT_20010995 + DAT_2000e0f4,param_3 + iVar17,uVar18 - iVar17);
            DAT_2000e0f4 = (uVar2 + DAT_2000e0f4) - (short)iVar17;
            if (((bVar16 != 2) ||
                (pGVar6 = __get_dashboard_state(),
                *(char *)(*(int *)&pGVar6->field_0x1014 + 3) != '\x01')) || (param_3[iVar17] != 0))
            {
              pGVar6 = __get_dashboard_state();
              memset((void *)(*(int *)&pGVar6->field_0x1014 + 0x10),0,0x200);
              pGVar6 = __get_dashboard_state();
              memcpy((void *)(*(int *)&pGVar6->field_0x1014 + 0x10),&DAT_20010995,(uint)DAT_2000e0f4
                    );
              pGVar6 = __get_dashboard_state();
              *(ushort *)(*(int *)&pGVar6->field_0x1014 + 0xe) = DAT_2000e0f4;
            }
            FUN_0007f4a4(param_3[3],0,0);
            DAT_2000e0f0 = 0;
            DAT_2000e0f2 = 0;
            DAT_2000e0f4 = 0;
          }
          goto LAB_00022bf4;
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received evenai_v2 packet,total packet = 1\n");
          }
          else {
            ble_printk("%s(): received evenai_v2 packet,total packet = 1\n","ble_process_post_req",
                       (uint)local_b4,BLE_DEBUG);
          }
        }
        iVar20 = uVar18 - iVar17;
        if (iVar20 < 0x201) {
          pGVar6 = __get_dashboard_state();
          pbVar15 = param_3 + iVar17;
          *(byte *)(*(int *)&pGVar6->field_0x1014 + 1) = bVar16;
          pGVar6 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar6->field_0x1014 + 3) = param_3[9];
          if (bVar16 == 4) {
            pGVar6 = __get_dashboard_state();
            if (*(char *)(*(int *)&pGVar6->field_0x1014 + 3) == '\x01') {
              pGVar6 = __get_dashboard_state();
              pGVar6->glasses_state_struct_0FF0->field_0x72 = 2;
            }
            else {
              pGVar6 = __get_dashboard_state();
              if (*(char *)(*(int *)&pGVar6->field_0x1014 + 3) == '\x13') {
                pGVar6 = __get_dashboard_state();
                if (*(int *)pGVar6->___glasses_state != 0x14) {
                  pGVar6 = __get_dashboard_state();
                  if ((pGVar6->field_0xd5 == '\x06') &&
                     (pGVar6 = __get_dashboard_state(),
                     pGVar6->glasses_state_struct_0FF0->field_0x74 == '\0')) {
                    pGVar6 = __get_dashboard_state();
                    pGVar6->glasses_state_struct_0FF0->field_0x74 = 1;
                  }
                  pGVar6 = __get_dashboard_state();
                  **(undefined1 **)&pGVar6->field_0x1014 = 1;
                  pGVar6 = __get_dashboard_state();
                  update_persist_task_status((int)pGVar6,0x14,2);
                }
                uVar28 = FUN_0007f436();
                pGVar6 = __get_dashboard_state();
                *(undefined8 *)(*(int *)&pGVar6->field_0x1014 + 6) = uVar28;
              }
            }
          }
          else {
            pGVar6 = __get_dashboard_state();
            *(byte *)(*(int *)&pGVar6->field_0x1014 + 4) = param_3[10];
            if (bVar16 == 2) {
              uVar28 = FUN_0007f436();
              pGVar6 = __get_dashboard_state();
              *(undefined8 *)(*(int *)&pGVar6->field_0x1014 + 6) = uVar28;
              pGVar6 = __get_dashboard_state();
              if ((*(char *)(*(int *)&pGVar6->field_0x1014 + 3) == '\x01') && (*pbVar15 == 0))
              goto LAB_000231de;
            }
            else {
              pGVar6 = __get_dashboard_state();
              *(byte *)(*(int *)&pGVar6->field_0x1014 + 5) = param_3[0xb];
            }
          }
          memset(&DAT_20010995,0,0x204);
          pGVar6 = __get_dashboard_state();
          memset((void *)(*(int *)&pGVar6->field_0x1014 + 0x10),0,0x200);
          pGVar6 = __get_dashboard_state();
          *(short *)(*(int *)&pGVar6->field_0x1014 + 0xe) = (short)iVar20;
          pGVar6 = __get_dashboard_state();
          iVar20 = *(int *)&pGVar6->field_0x1014;
          pGVar6 = __get_dashboard_state();
          puVar21 = (uint8_t *)(iVar20 + 0x10);
          uVar2 = *(ushort *)(*(int *)&pGVar6->field_0x1014 + 0xe);
          goto LAB_00022d50;
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): evenai_v2 data is too long, the current data length 0,wait write data length = %d\n"
                  );
          }
          else {
            ble_printk("%s(): evenai_v2 data is too long, the current data length 0,wait write data length = %d\n"
                       ,"ble_process_post_req",iVar20,BLE_DEBUG);
          }
        }
LAB_000232c2:
        local_b3 = 0xca;
        goto LAB_00022bf4;
      }
      if (bVar16 == 1) {
        _local_bc = CONCAT11(7,local_bc);
        _local_bc = (uint3)_local_bc;
        bVar16 = param_3[5];
        _local_bc = CONCAT13(param_3[3],_local_bc);
        local_b8._0_3_ = CONCAT12(bVar16,0xc901);
        if (bVar16 == 1) {
          pGVar6 = __get_dashboard_state();
          **(undefined1 **)&pGVar6->field_0x1014 = 1;
          pGVar6 = __get_dashboard_state();
          *(undefined1 *)(*(int *)&pGVar6->field_0x1014 + 1) = 1;
          pGVar6 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar6->field_0x1014 + 2) = param_3[6];
          pGVar6 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar6->field_0x1014 + 3) = param_3[7];
          pGVar6 = __get_dashboard_state();
          memset((void *)(*(int *)&pGVar6->field_0x1014 + 0x10),0,0x200);
        }
        else {
          if (bVar16 == 2) {
            pGVar6 = __get_dashboard_state();
            pbVar15 = *(byte **)&pGVar6->field_0x1014;
            bVar16 = 2;
            goto LAB_00022b82;
          }
          if (bVar16 != 3) {
            bVar5 = __is_master();
            if (bVar5) {
              pGVar6 = __get_dashboard_state();
              **(undefined1 **)&pGVar6->field_0x1014 = 0;
            }
            goto LAB_00022b84;
          }
          pGVar6 = __get_dashboard_state();
          **(undefined1 **)&pGVar6->field_0x1014 = 1;
          pGVar6 = __get_dashboard_state();
          *(undefined1 *)(*(int *)&pGVar6->field_0x1014 + 1) = 0;
        }
        pGVar6 = __get_dashboard_state();
        if (*(int *)pGVar6->___glasses_state != 0x14) {
          pGVar6 = __get_dashboard_state();
          update_persist_task_status((int)pGVar6,0x14,2);
        }
        goto LAB_000231de;
      }
    }
    else if (bVar16 == 5) {
      _local_bc = CONCAT11(7,local_bc);
      _local_bc = (uint3)_local_bc;
      _local_bc = CONCAT13(param_3[3],_local_bc);
      goto LAB_00023136;
    }
    bVar12 = param_3[3];
LAB_0002309e:
    _local_bc = CONCAT13(bVar12,(uint3)CONCAT11(6,local_bc));
    local_b8 = CONCAT31(local_b8._1_3_,bVar16);
LAB_000230a6:
    uVar10 = 0xca;
LAB_000230a8:
    local_b8._0_2_ = CONCAT11(uVar10,(undefined1)local_b8);
    goto LAB_00022bf4;
  case 0x55:
    bVar12 = param_3[4];
    if ((*(short *)(param_3 + 1) != *(short *)(param_2 + 2)) || (7 < bVar12)) goto LAB_000237cc;
    FUN_00049a24();
    bVar12 = param_3[4];
    bVar9 = param_3[3];
    if (bVar12 != 5) goto LAB_00023828;
    _local_bc = CONCAT11(7,(char)_local_bc);
    _local_bc = (uint3)_local_bc;
    _local_bc = CONCAT13(bVar9,_local_bc);
LAB_00023136:
    local_b8 = CONCAT22(local_b8._2_2_,0xc905);
    pGVar6 = __get_dashboard_state();
    if ((**(char **)&pGVar6->field_0x1014 == '\0') ||
       (pGVar6 = __get_dashboard_state(), 1 < **(byte **)&pGVar6->field_0x1014)) {
      cVar11 = -0x36;
    }
    else {
      cVar11 = -0x37;
    }
LAB_00023088:
    local_b8._0_2_ = CONCAT11(cVar11,(undefined1)local_b8);
    bVar16 = param_3[5];
LAB_0002308e:
    local_b8._0_3_ = CONCAT12(bVar16,(undefined2)local_b8);
LAB_00022bf4:
    pcVar14 = *(code **)(param_1 + 0xc);
    pcVar7 = &local_bc;
    uVar8 = uStack_bb;
    goto LAB_00022bfc;
  case 0x56:
    if (*(short *)(param_3 + 1) == *(short *)(param_2 + 2)) {
      FUN_00049a24();
      bVar16 = param_3[5];
      _local_bc = CONCAT11(7,local_bc);
      _local_bc = (uint3)_local_bc;
      _local_bc = CONCAT13(param_3[3],_local_bc);
      if (param_3[4] == 8) {
        local_b8._0_3_ = CONCAT12(bVar16,8);
        if (bVar16 == 0) {
          pGVar6 = __get_dashboard_state();
          if (pGVar6->glasses_state_struct_0FF0->field_0x74 == '\0') {
            pGVar6 = __get_dashboard_state();
            pGVar6->glasses_state_struct_0FF0->field_0x74 = 1;
          }
LAB_00022b84:
          FUN_00030458();
        }
        goto LAB_00022bf4;
      }
      local_b8._0_2_ = CONCAT11(1,param_3[4]);
      goto LAB_0002308e;
    }
    _local_bc = CONCAT11(6,bVar16);
    _local_bc = (uint3)_local_bc;
    _local_bc = CONCAT13(param_3[3],_local_bc);
    local_b8 = CONCAT31(local_b8._1_3_,param_3[4]);
    uVar10 = 1;
    goto LAB_000230a8;
  }
  pcVar14 = *(code **)(param_1 + 0xc);
  pcVar7 = &local_bc;
  uVar8 = 0x14;
LAB_00022bfc:
  (*pcVar14)(pcVar7,uVar8);
  return 0;
}



/*
 * Function: ble_process_put_req
 * Entry:    0001a9b4
 * Prototype: undefined __stdcall ble_process_put_req(int param_1, byte * param_2, byte * param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void ble_process_put_req(int param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  undefined3 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  char cVar10;
  bool bVar11;
  undefined *puVar12;
  void *pvVar13;
  GlassesState *pGVar14;
  k_sem *sem;
  undefined *puVar15;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  uint extraout_r1_12;
  uint extraout_r1_13;
  undefined1 extraout_r2;
  undefined1 extraout_r2_00;
  undefined1 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  char *pcVar16;
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
  uint *puVar17;
  undefined4 extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined4 extraout_r2_19;
  uint *extraout_r2_20;
  uint *extraout_r2_21;
  undefined4 extraout_r2_22;
  undefined4 extraout_r2_23;
  undefined4 uVar18;
  undefined4 extraout_r2_24;
  undefined4 extraout_r2_25;
  undefined4 *puVar19;
  undefined4 extraout_r2_26;
  undefined4 extraout_r2_27;
  undefined4 extraout_r2_28;
  undefined4 extraout_r2_29;
  undefined4 extraout_r2_30;
  undefined4 extraout_r2_31;
  undefined4 extraout_r2_32;
  size_t sVar21;
  undefined4 extraout_r2_33;
  undefined4 extraout_r2_34;
  undefined4 uVar22;
  undefined4 extraout_r2_35;
  undefined4 extraout_r2_36;
  undefined4 extraout_r2_37;
  undefined1 *d;
  undefined *d_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  global_state_struct_0FF0 *pgVar23;
  undefined1 *puVar24;
  int iVar25;
  undefined4 *puVar26;
  byte *pbVar27;
  void *buf;
  void *buf_00;
  void *buf_01;
  uint uVar28;
  int iVar29;
  char *pcVar30;
  undefined4 *puVar31;
  uint currentChunk;
  int iVar32;
  uint chunkCount;
  int iVar33;
  uint uVar34;
  void *buf_02;
  undefined8 uVar35;
  undefined1 *local_15c;
  uint local_158;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined1 local_13c;
  undefined2 uStack_13b;
  byte bStack_139;
  undefined4 local_138;
  byte local_134;
  undefined1 uStack_133;
  undefined1 uStack_132;
  undefined1 uStack_131;
  undefined1 uStack_130;
  undefined1 uStack_12f;
  undefined2 uStack_12e;
  undefined1 uStack_12c;
  undefined1 uStack_12b;
  undefined2 local_12a;
  uint local_128 [65];
  undefined4 *puVar20;
  
  puVar31 = *(undefined4 **)(param_1 + 0x10);
  iVar29 = param_1 + -0x77c;
  _local_13c = 0;
  memset(&local_138,0,0x10);
  uVar22 = _local_13c;
  puVar19 = puVar31 + 1;
  *puVar31 = *(undefined4 *)param_2;
  *(uint *)(param_1 + 0x14) = *(ushort *)(param_2 + 2) + 4;
  bVar2 = *param_2;
  currentChunk = (uint)bVar2;
  _local_13c = CONCAT31(_uStack_13b,bVar2);
  uVar18 = _local_13c;
  stack0xfffffec6 = SUB42(uVar22,2);
  uVar7 = local_138._1_3_;
  uVar8 = local_138._2_2_;
  _local_13c = uVar18;
  switch(currentChunk) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 0xb:
  case 0x14:
    memcpy(puVar19,param_3 + 1,*(ushort *)(param_2 + 2) - 1);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): msg_data:%02x, %02x, %02x, %02x\n");
      }
      else {
        ble_printk("%s(): msg_data:%02x, %02x, %02x, %02x\n","ble_process_put_req",
                   (uint)*(byte *)(puVar31 + 1),(uint)*(byte *)((int)puVar31 + 5));
      }
    }
    FUN_00019d14(param_1,(byte *)local_128,8);
    _local_13c = CONCAT11(0xc9,local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 4:
    put_whitelist_app_from_app(param_1,puVar19,param_3,(uint)param_2[2],(int)&local_13c);
    break;
  case 6:
    uVar3 = *(ushort *)(param_3 + 1);
    uVar34 = (uint)uVar3;
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 != currentChunk) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): dashboard information packet length error,input data length = %d,packet data length = %d\n"
                 ,"ble_process_put_req",currentChunk,uVar34);
        }
        else {
          ble_printk("%s(): dashboard information packet length error,input data length = %d,packet data length = %d\n"
                     ,"ble_process_put_req",currentChunk,uVar34);
        }
      }
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138._0_2_ = CONCAT11(1,param_3[4]);
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
      return;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received sync id = %d\n");
      }
      else {
        ble_printk("%s(): received sync id = %d\n","ble_process_put_req",(uint)param_3[3],BLE_DEBUG)
        ;
      }
    }
    switch(param_3[4]) {
    case 1:
      uVar22 = *(undefined4 *)(param_3 + 9);
      uVar18 = *(undefined4 *)(param_3 + 0xd);
      FUN_0004d4dc(uVar22,uVar18);
      currentChunk = *(uint *)(param_3 + 5);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): origin ms timestamp = %lld,origin second timestamp = %d\n",
                 "ble_process_put_req",uVar22,uVar18,currentChunk);
        }
        else {
          ble_printk("%s(): origin ms timestamp = %lld,origin second timestamp = %d\n",
                     "ble_process_put_req",uVar22,uVar18);
        }
      }
      *(byte *)(*(int *)(param_1 + 0x874) + 4) = param_3[0x11];
      *(byte *)(*(int *)(param_1 + 0x874) + 5) = param_3[0x12];
      **(uint **)(param_1 + 0x874) = currentChunk;
      iVar29 = *(int *)(param_1 + 0x874);
      *(undefined4 *)(iVar29 + 6) = uVar22;
      *(undefined4 *)(iVar29 + 10) = uVar18;
      local_128[0] = 0;
      local_128[1] = 0;
      local_128[2] = 0;
      FUN_0004d1e0(currentChunk,(undefined2 *)local_128);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n");
        }
        else {
          ble_printk("%s(): date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n","ble_process_put_req",
                     currentChunk,local_128[0] & 0xffff);
        }
      }
      FUN_0004d494(*(int **)(param_1 + 0x874),0,1);
      *(byte *)(*(int *)(param_1 + 0x874) + 0x5d) = param_3[0x13];
      *(byte *)(*(int *)(param_1 + 0x874) + 0x5e) = param_3[0x14];
      if (0x15 < uVar34) {
        if (*(byte *)(*(int *)(param_1 + 0x874) + 0x5f) != param_3[0x15]) {
          *(byte *)(*(int *)(param_1 + 0x874) + 0x5f) = param_3[0x15];
          FUN_00025b28(0,0);
        }
      }
      if (2 < LOG_LEVEL) {
        cVar10 = *(char *)(*(int *)(param_1 + 0x874) + 0x5e);
        if (BLE_DEBUG == 0) {
          pcVar30 = "centigrade degree";
          if (cVar10 != '\0') {
            pcVar30 = "Fahrenheit";
          }
          pcVar16 = "24";
          if (cVar10 != '\0') {
            pcVar16 = "12";
          }
          printk("%s(): time display format :%s hours, temperature display format %s \n",
                 "ble_process_put_req",pcVar16,pcVar30);
        }
        else {
          pcVar30 = "Fahrenheit";
          if (cVar10 == '\0') {
            pcVar30 = "centigrade degree";
          }
          pcVar16 = "12";
          if (cVar10 == '\0') {
            pcVar16 = "24";
          }
          ble_printk("%s(): time display format :%s hours, temperature display format %s \n",
                     "ble_process_put_req",pcVar16,pcVar30);
        }
      }
      FUN_0001666c();
      set_ncs_mem_initialized();
      memset((void *)((int)&local_138 + 1),0,0xf);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT31(local_138._1_3_,param_3[4]);
      (**(code **)(param_1 + 0xc))(&local_13c,6);
      break;
    case 2:
      memset((void *)((int)&local_138 + 1),0,0xf);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT31(local_138._1_3_,param_3[4]);
      (**(code **)(param_1 + 0xc))(&local_13c,6);
      break;
    case 3:
      uVar4 = *(ushort *)(param_3 + 5);
      chunkCount = (uint)uVar4;
      currentChunk = (uint)*(ushort *)(param_3 + 7);
      if (chunkCount == 1) {
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x65 = param_3[9];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x66 = param_3[10];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x67 = param_3[0xb];
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                   "ble_process_put_req");
          }
          else {
            ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                       "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                       (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar14 = __get_dashboard_state();
              printk("%s(): schedule display mode = %d\n","ble_process_put_req",
                     (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x67);
            }
            else {
              pGVar14 = __get_dashboard_state();
              ble_printk("%s(): schedule display mode = %d\n","ble_process_put_req",
                         (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x67,
                         pGVar14->glasses_state_struct_0FF0);
            }
          }
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x67 != '\x03') {
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
        currentChunk = (uint)param_3[0xc];
        uVar22 = extraout_r2_05;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): schedule total record num = %d\n");
            uVar22 = extraout_r2_07;
          }
          else {
            ble_printk("%s(): schedule total record num = %d\n","ble_process_put_req",currentChunk,
                       BLE_DEBUG);
            uVar22 = extraout_r2_06;
          }
        }
        pbVar27 = param_3 + 0xd;
        if (currentChunk < 9) {
          memset(&DAT_2001252f,0,0x520);
          local_15c = &DAT_2001252f;
          local_158 = 0;
          while( true ) {
            if (currentChunk == local_158) {
              pGVar14 = __get_dashboard_state();
              if ((byte)pGVar14->glasses_state_struct_0FF0->field_0x68 != local_158) {
                cleanCalenadrIndex();
              }
              pGVar14 = __get_dashboard_state();
              pGVar14->glasses_state_struct_0FF0->field_0x68 = (char)local_158;
              uStack_133 = 0;
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if (*pbVar27 != 1) break;
            if ((0x40 < pbVar27[1]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule title data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule title data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[1],BLE_DEBUG);
              }
            }
            memset(local_15c,0,0xa4);
            sVar21 = (size_t)pbVar27[1];
            puVar24 = local_15c + 1;
            if (0x3f < sVar21) {
              sVar21 = 0x40;
            }
            memcpy(puVar24,pbVar27 + 2,sVar21);
            uVar34 = (uint)pbVar27[1];
            iVar29 = uVar34 + 2;
            if (pbVar27[iVar29] != 2) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): schedule time data struct error, error type = %d\n");
                }
                else {
                  ble_printk("%s(): schedule time data struct error, error type = %d\n",
                             "ble_process_put_req",(uint)pbVar27[iVar29],BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if ((0x20 < pbVar27[uVar34 + 3]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule time data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule time data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[uVar34 + 3],BLE_DEBUG);
              }
            }
            sVar21 = (size_t)pbVar27[uVar34 + 3];
            d = local_15c + 0x42;
            if (0x1f < sVar21) {
              sVar21 = 0x20;
            }
            memcpy(d,pbVar27 + uVar34 + 4,sVar21);
            iVar25 = pbVar27[uVar34 + 3] + 2 + iVar29;
            if (pbVar27[pbVar27[uVar34 + 3] + 2 + iVar29] != 3) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): schedule time data struct error, error type = %d\n");
                }
                else {
                  ble_printk("%s(): schedule time data struct error, error type = %d\n",
                             "ble_process_put_req",(uint)pbVar27[pbVar27[uVar34 + 3] + 2 + iVar29],
                             BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if ((0x40 < pbVar27[iVar25 + 1]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule location data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule location data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[iVar25 + 1],BLE_DEBUG);
              }
            }
            *local_15c = 1;
            sVar21 = (size_t)pbVar27[iVar25 + 1];
            if (0x3f < sVar21) {
              sVar21 = 0x40;
            }
            pvVar13 = memcpy(local_15c + 99,pbVar27 + iVar25 + 2,sVar21);
            pbVar27 = pbVar27 + pbVar27[iVar25 + 1] + 2 + iVar25;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule title : %s , time :%s , location : %s \n",
                       "ble_process_put_req",puVar24,d,pvVar13);
              }
              else {
                ble_printk("%s(): schedule title : %s , time :%s , location : %s \n",
                           "ble_process_put_req",puVar24,d);
              }
            }
            local_158 = local_158 + 1 & 0xff;
            local_15c = local_15c + 0xa4;
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): schedule title data struct error, error type = %d\n");
            }
            else {
              ble_printk("%s(): schedule title data struct error, error type = %d\n",
                         "ble_process_put_req",(uint)*pbVar27,BLE_DEBUG);
            }
          }
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
      }
      else {
        if (currentChunk == 1) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                    );
            }
            else {
              ble_printk("%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                         ,"ble_process_put_req",1,BLE_DEBUG);
            }
          }
          DAT_200100d0 = 0;
          DAT_200100ce = 0;
          DAT_200100cc = 0;
          memset(&DAT_20011ff7,0,0x538);
          memcpy(&DAT_20011ff7,param_3 + 9,uVar34 - 9);
          DAT_200100cc = DAT_200100cc + -9 + uVar3;
          _local_13c = *(undefined4 *)param_3;
          DAT_200100d0 = DAT_200100d0 + 1;
          local_138 = *(uint *)(param_3 + 4);
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          local_134 = param_3[8];
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          DAT_200100ce = uVar4;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
        if (currentChunk < chunkCount) {
          if ((uint)DAT_200100d0 == currentChunk - 1) {
            memcpy(&DAT_20011ff7 + DAT_200100cc,param_3 + 9,uVar34 - 9);
            DAT_200100cc = (DAT_200100cc - 9) + uVar3;
            _local_13c = *(undefined4 *)param_3;
            DAT_200100d0 = DAT_200100d0 + 1;
            uStack_133 = 0;
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if (-1 < iVar29) {
              return;
            }
            if (LOG_LEVEL < 1) {
              return;
            }
            if (BLE_DEBUG != 0) {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
              return;
            }
            printk("%s(): post_to_host failed ret = %d\n");
            return;
          }
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_200100d0 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_200100d0 + 1);
            }
          }
          DAT_200100ce = 0;
          DAT_200100d0 = 0;
          memset(&DAT_20011ff7,0,0x538);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
        if (currentChunk != chunkCount) {
          return;
        }
        if (((uint)DAT_200100d0 != currentChunk - 1) || (DAT_200100ce != currentChunk)) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_200100d0 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_200100d0 + 1);
            }
          }
          DAT_200100ce = 0;
          DAT_200100d0 = 0;
          memset(&DAT_20011ff7,0,0x538);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
        memcpy(&DAT_20011ff7 + DAT_200100cc,param_3 + 9,uVar34 - 9);
        DAT_200100cc = (DAT_200100cc - 9) + uVar3;
        DAT_200100d0 = DAT_200100d0 + 1;
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x65 = DAT_20011ff7;
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x66 = DAT_20011ff8;
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x67 = DAT_20011ff9;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                   "ble_process_put_req");
          }
          else {
            ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                       "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                       (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar14 = __get_dashboard_state();
              printk("%s(): schedule display mode = %d\n","ble_process_put_req",
                     (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x67);
            }
            else {
              pGVar14 = __get_dashboard_state();
              ble_printk("%s(): schedule display mode = %d\n","ble_process_put_req",
                         (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x67,
                         pGVar14->glasses_state_struct_0FF0);
            }
          }
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x67 != '\x03') {
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
        currentChunk = (uint)DAT_20011ffa;
        uVar22 = extraout_r2_08;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): schedule record num = %d\n");
            uVar22 = extraout_r2_10;
          }
          else {
            ble_printk("%s(): schedule record num = %d\n","ble_process_put_req",currentChunk,
                       BLE_DEBUG);
            uVar22 = extraout_r2_09;
          }
        }
        if (currentChunk < 9) {
          memset(&DAT_2001252f,0,0x520);
          puVar12 = &DAT_20012592;
          pbVar27 = &DAT_20011ffb;
          local_15c = (undefined1 *)0x0;
          while( true ) {
            if ((undefined1 *)currentChunk == local_15c) {
              pGVar14 = __get_dashboard_state();
              if ((undefined1 *)(uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x68 !=
                  local_15c) {
                cleanCalenadrIndex();
              }
              pGVar14 = __get_dashboard_state();
              pGVar14->glasses_state_struct_0FF0->field_0x68 = (char)local_15c;
              uStack_133 = 0;
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if (*pbVar27 != 1) break;
            if ((0x41 < pbVar27[1]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule title data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule title data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[1],BLE_DEBUG);
              }
            }
            memset(puVar12 + -99,0,0xa4);
            chunkCount = (uint)pbVar27[1];
            puVar15 = puVar12 + -0x62;
            uVar34 = chunkCount;
            if (0x40 < chunkCount) {
              uVar34 = 0x41;
            }
            iVar29 = chunkCount + 2;
            memcpy(puVar15,pbVar27 + 2,uVar34);
            if (pbVar27[iVar29] != 2) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): schedule time data struct error, error type = %d\n");
                }
                else {
                  ble_printk("%s(): schedule time data struct error, error type = %d\n",
                             "ble_process_put_req",(uint)pbVar27[iVar29],BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if ((0x21 < pbVar27[chunkCount + 3]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule time data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule time data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[chunkCount + 3],BLE_DEBUG);
              }
            }
            d_00 = puVar12 + -0x21;
            uVar28 = (uint)pbVar27[chunkCount + 3];
            uVar34 = uVar28;
            if (0x20 < uVar28) {
              uVar34 = 0x21;
            }
            memcpy(d_00,pbVar27 + chunkCount + 4,uVar34);
            iVar25 = uVar28 + 2 + iVar29;
            if (pbVar27[uVar28 + 2 + iVar29] != 3) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): schedule time data struct error, error type = %d\n");
                }
                else {
                  ble_printk("%s(): schedule time data struct error, error type = %d\n",
                             "ble_process_put_req",(uint)pbVar27[uVar28 + 2 + iVar29],BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if (-1 < iVar29) {
                return;
              }
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): post_to_host failed ret = %d\n");
              return;
            }
            if ((0x41 < pbVar27[iVar25 + 1]) && (1 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule time data format error!!!\n");
              }
              else {
                ble_printk("%s(): schedule time data format error!!!\n","ble_process_put_req",
                           (uint)pbVar27[iVar25 + 1],BLE_DEBUG);
              }
            }
            chunkCount = (uint)pbVar27[iVar25 + 1];
            puVar12[-99] = 1;
            uVar34 = chunkCount;
            if (0x40 < chunkCount) {
              uVar34 = 0x41;
            }
            memcpy(puVar12,pbVar27 + iVar25 + 2,uVar34);
            pbVar27 = pbVar27 + chunkCount + 2 + iVar25;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): schedule title : %s , time :%s , location : %s , schedule_validity :%d\n"
                       ,"ble_process_put_req",puVar15,d_00,puVar12,1);
              }
              else {
                ble_printk("%s(): schedule title : %s , time :%s , location : %s , schedule_validity :%d\n"
                           ,"ble_process_put_req",puVar15,d_00);
              }
            }
            puVar12 = puVar12 + 0xa4;
            local_15c = (undefined1 *)((int)local_15c + 1U & 0xff);
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): schedule title data struct error, error type = %d\n");
            }
            else {
              ble_printk("%s(): schedule title data struct error, error type = %d\n",
                         "ble_process_put_req",(uint)*pbVar27,BLE_DEBUG);
            }
          }
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if (-1 < iVar29) {
            return;
          }
          if (LOG_LEVEL < 1) {
            return;
          }
          if (BLE_DEBUG != 0) {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
            return;
          }
          printk("%s(): post_to_host failed ret = %d\n");
          return;
        }
      }
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): schedule data oversize!!!!\n");
        }
        else {
          ble_printk("%s(): schedule data oversize!!!!\n","ble_process_put_req",uVar22,BLE_DEBUG);
        }
      }
      break;
    case 4:
      uVar4 = *(ushort *)(param_3 + 5);
      chunkCount = (uint)uVar4;
      currentChunk = (uint)*(ushort *)(param_3 + 7);
      if (chunkCount == 1) {
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x65 = param_3[9];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x66 = param_3[10];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x69 = param_3[0xb];
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                   "ble_process_put_req");
          }
          else {
            ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                       "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                       (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar14 = __get_dashboard_state();
              printk("%s(): stocks display mode = %d\n","ble_process_put_req",
                     (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x69);
            }
            else {
              pGVar14 = __get_dashboard_state();
              ble_printk("%s(): stocks display mode = %d\n","ble_process_put_req",
                         (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x69,
                         pGVar14->glasses_state_struct_0FF0);
            }
          }
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x69 == '\x02') {
          currentChunk = (uint)param_3[0xc];
          if (currentChunk < 5) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): current stocks index num = %d\n");
              }
              else {
                ble_printk("%s(): current stocks index num = %d\n","ble_process_put_req",
                           currentChunk,BLE_DEBUG);
              }
            }
            if (param_3[0xd] == 2) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): delete stocks index num = %d\n");
                }
                else {
                  ble_printk("%s(): delete stocks index num = %d\n","ble_process_put_req",
                             currentChunk,BLE_DEBUG);
                }
              }
              memset(&DAT_2000e104 + (currentChunk - 1) * 0x7f2,0,0x7f2);
              cleanStocksIndex();
            }
            else {
              if (param_3[0xe] != 1) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stock code data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stock code data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[0xe],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x20 < param_3[0xf]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks code oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks code oversize !!!\n","ble_process_put_req",1,BLE_DEBUG)
                    ;
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
              iVar25 = currentChunk - 1;
              iVar29 = iVar25 * 0x7f2;
              sVar21 = (size_t)param_3[0xf];
              pvVar13 = (void *)(iVar29 + 0x2000e108);
              if (0x1f < sVar21) {
                sVar21 = 0x20;
              }
              iVar32 = memcmp(pvVar13,param_3 + 0x10,sVar21);
              if (iVar32 != 0) {
                memset(pvVar13,0,0x20);
                cleanStocksIndex();
              }
              sVar21 = (size_t)param_3[0xf];
              if (0x1f < sVar21) {
                sVar21 = 0x20;
              }
              memcpy(pvVar13,param_3 + 0x10,sVar21);
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock code name : %s\n");
                }
                else {
                  ble_printk("%s(): stock code name : %s\n","ble_process_put_req",pvVar13,BLE_DEBUG)
                  ;
                }
              }
              currentChunk = (uint)param_3[0xf];
              iVar32 = currentChunk + 0x10;
              if (param_3[iVar32] != 2) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks company name data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks company name data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[iVar32],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x40 < param_3[currentChunk + 0x11]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks share price oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks share price oversize !!!\n","ble_process_put_req",2,
                               BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar33 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar33 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar33,
                               BLE_DEBUG);
                  }
                }
              }
              sVar21 = (size_t)param_3[currentChunk + 0x11];
              pvVar13 = (void *)(iVar29 + 0x2000e128);
              if (0x3f < sVar21) {
                sVar21 = 0x40;
              }
              iVar33 = memcmp(pvVar13,param_3 + currentChunk + 0x12,sVar21);
              if (iVar33 != 0) {
                memset(pvVar13,0,0x40);
                cleanStocksIndex();
              }
              sVar21 = (size_t)param_3[currentChunk + 0x11];
              if (0x3f < sVar21) {
                sVar21 = 0x40;
              }
              memcpy(pvVar13,param_3 + currentChunk + 0x12,sVar21);
              bVar2 = param_3[currentChunk + 0x11];
              iVar33 = bVar2 + 2 + iVar32;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock company name : %s\n");
                }
                else {
                  ble_printk("%s(): stock company name : %s\n","ble_process_put_req",pvVar13,
                             BLE_DEBUG);
                }
              }
              if (param_3[bVar2 + 2 + iVar32] != 3) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks share price data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks share price data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[bVar2 + 2 + iVar32],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x10 < param_3[iVar33 + 1]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks share price oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks share price oversize !!!\n","ble_process_put_req",
                               (uint)param_3[iVar33 + 1],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar32 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar32 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar32,
                               BLE_DEBUG);
                  }
                }
              }
              pvVar13 = memset((void *)(iVar29 + 0x2000e168),0,0x10);
              sVar21 = (size_t)param_3[iVar33 + 1];
              if (0xf < sVar21) {
                sVar21 = 0x10;
              }
              pvVar13 = memcpy(pvVar13,param_3 + iVar33 + 2,sVar21);
              bVar2 = param_3[iVar33 + 1];
              iVar32 = bVar2 + 2 + iVar33;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock price  : %s\n","ble_process_put_req",pvVar13);
                }
                else {
                  ble_printk("%s(): stock price  : %s\n","ble_process_put_req",pvVar13,extraout_r3);
                }
              }
              if (param_3[bVar2 + 2 + iVar33] != 4) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks price change data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks price change data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[bVar2 + 2 + iVar33],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x10 < param_3[iVar32 + 1]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks price change oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks price change oversize !!!\n","ble_process_put_req",
                               (uint)param_3[iVar32 + 1],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar33 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar33 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar33,
                               BLE_DEBUG);
                  }
                }
              }
              pvVar13 = memset((void *)(iVar29 + 0x2000e178),0,0x10);
              sVar21 = (size_t)param_3[iVar32 + 1];
              if (0xf < sVar21) {
                sVar21 = 0x10;
              }
              pvVar13 = memcpy(pvVar13,param_3 + iVar32 + 2,sVar21);
              bVar2 = param_3[iVar32 + 1];
              iVar33 = bVar2 + 2 + iVar32;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock price change  : %s\n","ble_process_put_req",pvVar13);
                }
                else {
                  ble_printk("%s(): stock price change  : %s\n","ble_process_put_req",pvVar13,
                             extraout_r3_00);
                }
              }
              if (param_3[bVar2 + 2 + iVar32] != 5) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks change rate data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks change rate data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[bVar2 + 2 + iVar32],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x10 < param_3[iVar33 + 1]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks price change oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks price change oversize !!!\n","ble_process_put_req",
                               (uint)param_3[iVar33 + 1],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar32 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar32 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar32,
                               BLE_DEBUG);
                  }
                }
              }
              pvVar13 = memset((void *)(iVar29 + 0x2000e188),0,0x10);
              sVar21 = (size_t)param_3[iVar33 + 1];
              if (0xf < sVar21) {
                sVar21 = 0x10;
              }
              pvVar13 = memcpy(pvVar13,param_3 + iVar33 + 2,sVar21);
              bVar2 = param_3[iVar33 + 1];
              iVar32 = bVar2 + 2 + iVar33;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock change rate : %s\n","ble_process_put_req",pvVar13);
                }
                else {
                  ble_printk("%s(): stock change rate : %s\n","ble_process_put_req",pvVar13,
                             extraout_r3_01);
                }
              }
              iVar5 = LOG_LEVEL;
              if (param_3[bVar2 + 2 + iVar33] != 6) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks change rate data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks change rate data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[bVar2 + 2 + iVar33],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (param_3[iVar32 + 1] != 1) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks change status sformat error !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks change status sformat error !!!\n",
                               "ble_process_put_req",(uint)param_3[iVar32 + 1],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              bVar2 = param_3[iVar32 + 2];
              (&DAT_2000e105)[iVar25 * 0x7f2] = bVar2;
              bVar1 = param_3[iVar32 + 1];
              iVar33 = bVar1 + 2 + iVar32;
              if (2 < iVar5) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stock change status : %d\n");
                }
                else {
                  ble_printk("%s(): stock change status : %d\n","ble_process_put_req",(uint)bVar2,
                             BLE_DEBUG);
                }
              }
              iVar5 = LOG_LEVEL;
              if (param_3[bVar1 + 2 + iVar32] != 7) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks change rate data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stocks change rate data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[bVar1 + 2 + iVar32],BLE_DEBUG);
                  }
                }
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              uVar3 = *(ushort *)(param_3 + iVar33 + 1);
              if (0x75e < uVar3) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stocks image format oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): stocks image format oversize !!!\n","ble_process_put_req",
                               0x75e,BLE_DEBUG);
                  }
                }
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              iVar25 = iVar25 * 0x7f2;
              *(ushort *)(&DAT_2000e106 + iVar25) = uVar3;
              pvVar13 = memset((void *)(iVar29 + 0x2000e198),0,0x75e);
              memcpy(pvVar13,param_3 + iVar33 + 3,(uint)uVar3);
              (&DAT_2000e104)[iVar25] = 1;
              if (2 < iVar5) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): We received %d byte of data from the App\n");
                }
                else {
                  ble_printk("%s(): We received %d byte of data from the App\n",
                             "ble_process_put_req",(uint)*(ushort *)(&DAT_2000e106 + iVar25),
                             BLE_DEBUG);
                }
              }
            }
            uStack_133 = 0;
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
          else {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): stocks data oversize!!!!\n");
              }
              else {
                ble_printk("%s(): stocks data oversize!!!!\n","ble_process_put_req",extraout_r2_11,
                           BLE_DEBUG);
              }
            }
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 1;
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (currentChunk == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                  );
          }
          else {
            ble_printk("%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                       ,"ble_process_put_req",1,BLE_DEBUG);
          }
        }
        DAT_2000e102 = 0;
        DAT_2000e100 = 0;
        DAT_2000e0fe = 0;
        memset(&DAT_200117e5,0,0x812);
        memcpy(&DAT_200117e5,param_3 + 9,uVar34 - 9);
        DAT_2000e0fe = DAT_2000e0fe + -9 + uVar3;
        _local_13c = *(undefined4 *)param_3;
        DAT_2000e102 = DAT_2000e102 + 1;
        local_138 = *(uint *)(param_3 + 4);
        uStack_133 = 0;
        uStack_132 = 0;
        uStack_131 = 0;
        uStack_130 = 0;
        local_134 = param_3[8];
        uStack_12f = 0;
        uStack_12e = 0;
        uStack_12c = 0;
        uStack_12b = 0;
        local_12a = 0;
        DAT_2000e100 = uVar4;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      else if (currentChunk < chunkCount) {
        if ((uint)DAT_2000e102 == currentChunk - 1) {
          memcpy(&DAT_200117e5 + DAT_2000e0fe,param_3 + 9,uVar34 - 9);
          DAT_2000e0fe = (DAT_2000e0fe - 9) + uVar3;
          _local_13c = *(undefined4 *)param_3;
          DAT_2000e102 = DAT_2000e102 + 1;
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req");
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_200100d0 + 1);
            }
          }
          DAT_2000e100 = 0;
          DAT_2000e102 = 0;
          memset(&DAT_200117e5,0,0x812);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (currentChunk == chunkCount) {
        if (((uint)DAT_2000e102 == currentChunk - 1) && (DAT_2000e100 == currentChunk)) {
          memcpy(&DAT_200117e5 + DAT_2000e0fe,param_3 + 9,uVar34 - 9);
          DAT_2000e0fe = (DAT_2000e0fe - 9) + uVar3;
          DAT_2000e102 = DAT_2000e102 + 1;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x65 = DAT_200117e5;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x66 = DAT_200117e6;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x69 = DAT_200117e7;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                     "ble_process_put_req");
            }
            else {
              ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                         "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                         (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                pGVar14 = __get_dashboard_state();
                printk("%s(): stocks display mode = %d\n","ble_process_put_req",
                       (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x69);
              }
              else {
                pGVar14 = __get_dashboard_state();
                ble_printk("%s(): stocks display mode = %d\n","ble_process_put_req",
                           (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x69,
                           pGVar14->glasses_state_struct_0FF0);
              }
            }
          }
          pGVar14 = __get_dashboard_state();
          if (pGVar14->glasses_state_struct_0FF0->field_0x69 == '\x02') {
            currentChunk = (uint)DAT_200117e8;
            if (DAT_200117e8 < 5) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): current stocks index num = %d\n");
                }
                else {
                  ble_printk("%s(): current stocks index num = %d\n","ble_process_put_req",
                             currentChunk,BLE_DEBUG);
                }
              }
              if (DAT_200117e9 == '\x02') {
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): delete stocks index num = %d\n");
                  }
                  else {
                    ble_printk("%s(): delete stocks index num = %d\n","ble_process_put_req",
                               currentChunk,BLE_DEBUG);
                  }
                }
                cleanStocksIndex();
                memset(&DAT_2000e104 + (currentChunk - 1) * 0x7f2,0,0x7f2);
                uStack_133 = 0;
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
              else if (DAT_200117ea == 1) {
                if (0x20 < DAT_200117eb) {
                  if (1 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): stocks code oversize !!!\n");
                    }
                    else {
                      ble_printk("%s(): stocks code oversize !!!\n","ble_process_put_req",1,
                                 BLE_DEBUG);
                    }
                  }
                  uStack_132 = 0;
                  uStack_131 = 0;
                  uStack_130 = 0;
                  uStack_12f = 0;
                  uStack_12e = 0;
                  uStack_12c = 0;
                  uStack_12b = 0;
                  local_12a = 0;
                  _local_13c = *(undefined4 *)param_3;
                  local_138 = *(uint *)(param_3 + 4);
                  local_134 = param_3[8];
                  uStack_133 = 1;
                  iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                  if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): post_to_host failed ret = %d\n");
                    }
                    else {
                      ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29
                                 ,BLE_DEBUG);
                    }
                  }
                }
                iVar25 = currentChunk - 1;
                iVar29 = iVar25 * 0x7f2;
                sVar21 = (size_t)DAT_200117eb;
                pvVar13 = (void *)(iVar29 + 0x2000e108);
                if (0x1f < sVar21) {
                  sVar21 = 0x20;
                }
                iVar32 = memcmp(pvVar13,&DAT_200117ec,sVar21);
                if (iVar32 != 0) {
                  memset(pvVar13,0,0x20);
                  cleanStocksIndex();
                }
                sVar21 = (size_t)DAT_200117eb;
                if (0x1f < sVar21) {
                  sVar21 = 0x20;
                }
                memcpy(pvVar13,&DAT_200117ec,sVar21);
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stock code name : %s\n");
                  }
                  else {
                    ble_printk("%s(): stock code name : %s\n","ble_process_put_req",pvVar13,
                               BLE_DEBUG);
                  }
                }
                currentChunk = (uint)DAT_200117eb;
                if ((byte)(&DAT_200117ec)[currentChunk] == 2) {
                  if (0x40 < (byte)(&DAT_200117ed)[currentChunk]) {
                    if (1 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): stocks share price oversize !!!\n");
                      }
                      else {
                        ble_printk("%s(): stocks share price oversize !!!\n","ble_process_put_req",2
                                   ,BLE_DEBUG);
                      }
                    }
                    uStack_132 = 0;
                    uStack_131 = 0;
                    uStack_130 = 0;
                    uStack_12f = 0;
                    uStack_12e = 0;
                    uStack_12c = 0;
                    uStack_12b = 0;
                    local_12a = 0;
                    _local_13c = *(undefined4 *)param_3;
                    local_138 = *(uint *)(param_3 + 4);
                    local_134 = param_3[8];
                    uStack_133 = 1;
                    iVar32 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                    if ((iVar32 < 0) && (0 < LOG_LEVEL)) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): post_to_host failed ret = %d\n");
                      }
                      else {
                        ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                   iVar32,BLE_DEBUG);
                      }
                    }
                  }
                  sVar21 = (size_t)(byte)(&DAT_200117ed)[currentChunk];
                  pvVar13 = (void *)(iVar29 + 0x2000e128);
                  if (0x3f < sVar21) {
                    sVar21 = 0x40;
                  }
                  iVar32 = memcmp(pvVar13,(void *)(currentChunk + 0x200117ee),sVar21);
                  if (iVar32 != 0) {
                    memset(pvVar13,0,0x40);
                    cleanStocksIndex();
                  }
                  chunkCount = (uint)(byte)(&DAT_200117ed)[currentChunk];
                  uVar34 = chunkCount;
                  if (0x3f < chunkCount) {
                    uVar34 = 0x40;
                  }
                  memcpy(pvVar13,(void *)(currentChunk + 0x200117ee),uVar34);
                  iVar32 = chunkCount + 2 + currentChunk;
                  if (2 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): stock company name : %s\n");
                    }
                    else {
                      ble_printk("%s(): stock company name : %s\n","ble_process_put_req",pvVar13,
                                 BLE_DEBUG);
                    }
                  }
                  currentChunk = (uint)(byte)(&DAT_200117ec)[chunkCount + 2 + currentChunk];
                  if (currentChunk == 3) {
                    currentChunk = (uint)(byte)(&DAT_200117ec)[iVar32 + 1];
                    if (0x10 < currentChunk) {
                      if (1 < LOG_LEVEL) {
                        if (BLE_DEBUG == 0) {
                          printk("%s(): stocks share price oversize !!!\n");
                        }
                        else {
                          ble_printk("%s(): stocks share price oversize !!!\n","ble_process_put_req"
                                     ,currentChunk,BLE_DEBUG);
                        }
                      }
                      uStack_132 = 0;
                      uStack_131 = 0;
                      uStack_130 = 0;
                      uStack_12f = 0;
                      uStack_12e = 0;
                      uStack_12c = 0;
                      uStack_12b = 0;
                      local_12a = 0;
                      _local_13c = *(undefined4 *)param_3;
                      local_138 = *(uint *)(param_3 + 4);
                      local_134 = param_3[8];
                      uStack_133 = 1;
                      iVar33 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                      if ((iVar33 < 0) && (0 < LOG_LEVEL)) {
                        if (BLE_DEBUG == 0) {
                          printk("%s(): post_to_host failed ret = %d\n");
                        }
                        else {
                          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                     iVar33,BLE_DEBUG);
                        }
                      }
                    }
                    pvVar13 = memset((void *)(iVar29 + 0x2000e168),0,0x10);
                    uVar34 = (uint)(byte)(&DAT_200117ec)[iVar32 + 1];
                    currentChunk = uVar34;
                    if (0xf < uVar34) {
                      currentChunk = 0x10;
                    }
                    pvVar13 = memcpy(pvVar13,&DAT_200117ec + iVar32 + 2,currentChunk);
                    iVar33 = uVar34 + 2 + iVar32;
                    if (2 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): stock price  : %s\n","ble_process_put_req",pvVar13);
                      }
                      else {
                        ble_printk("%s(): stock price  : %s\n","ble_process_put_req",pvVar13,
                                   extraout_r3_02);
                      }
                    }
                    currentChunk = (uint)(byte)(&DAT_200117ec)[uVar34 + 2 + iVar32];
                    if (currentChunk == 4) {
                      currentChunk = (uint)(byte)(&DAT_200117ec)[iVar33 + 1];
                      if (0x10 < currentChunk) {
                        if (1 < LOG_LEVEL) {
                          if (BLE_DEBUG == 0) {
                            printk("%s(): stocks price change oversize !!!\n");
                          }
                          else {
                            ble_printk("%s(): stocks price change oversize !!!\n",
                                       "ble_process_put_req",currentChunk,BLE_DEBUG);
                          }
                        }
                        uStack_132 = 0;
                        uStack_131 = 0;
                        uStack_130 = 0;
                        uStack_12f = 0;
                        uStack_12e = 0;
                        uStack_12c = 0;
                        uStack_12b = 0;
                        local_12a = 0;
                        _local_13c = *(undefined4 *)param_3;
                        local_138 = *(uint *)(param_3 + 4);
                        local_134 = param_3[8];
                        uStack_133 = 1;
                        iVar32 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                        if ((iVar32 < 0) && (0 < LOG_LEVEL)) {
                          if (BLE_DEBUG == 0) {
                            printk("%s(): post_to_host failed ret = %d\n");
                          }
                          else {
                            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                       iVar32,BLE_DEBUG);
                          }
                        }
                      }
                      pvVar13 = memset((void *)(iVar29 + 0x2000e178),0,0x10);
                      uVar34 = (uint)(byte)(&DAT_200117ec)[iVar33 + 1];
                      currentChunk = uVar34;
                      if (0xf < uVar34) {
                        currentChunk = 0x10;
                      }
                      pvVar13 = memcpy(pvVar13,&DAT_200117ec + iVar33 + 2,currentChunk);
                      iVar32 = uVar34 + 2 + iVar33;
                      if (2 < LOG_LEVEL) {
                        if (BLE_DEBUG == 0) {
                          printk("%s(): stock price change  : %s\n","ble_process_put_req",pvVar13);
                        }
                        else {
                          ble_printk("%s(): stock price change  : %s\n","ble_process_put_req",
                                     pvVar13,extraout_r3_03);
                        }
                      }
                      currentChunk = (uint)(byte)(&DAT_200117ec)[uVar34 + 2 + iVar33];
                      if (currentChunk == 5) {
                        currentChunk = (uint)(byte)(&DAT_200117ec)[iVar32 + 1];
                        if (0x10 < currentChunk) {
                          if (1 < LOG_LEVEL) {
                            if (BLE_DEBUG == 0) {
                              printk("%s(): stocks price change oversize !!!\n");
                            }
                            else {
                              ble_printk("%s(): stocks price change oversize !!!\n",
                                         "ble_process_put_req",currentChunk,BLE_DEBUG);
                            }
                          }
                          _local_13c = *(undefined4 *)param_3;
                          local_138 = *(uint *)(param_3 + 4);
                          uStack_132 = 0;
                          uStack_131 = 0;
                          uStack_130 = 0;
                          uStack_12f = 0;
                          uStack_12e = 0;
                          uStack_12c = 0;
                          uStack_12b = 0;
                          local_12a = 0;
                          local_134 = param_3[8];
                          uStack_133 = 1;
                          iVar33 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                          if ((iVar33 < 0) && (0 < LOG_LEVEL)) {
                            if (BLE_DEBUG == 0) {
                              printk("%s(): post_to_host failed ret = %d\n");
                            }
                            else {
                              ble_printk("%s(): post_to_host failed ret = %d\n",
                                         "ble_process_put_req",iVar33,BLE_DEBUG);
                            }
                          }
                        }
                        pvVar13 = memset((void *)(iVar29 + 0x2000e188),0,0x10);
                        uVar34 = (uint)(byte)(&DAT_200117ec)[iVar32 + 1];
                        currentChunk = uVar34;
                        if (0xf < uVar34) {
                          currentChunk = 0x10;
                        }
                        pvVar13 = memcpy(pvVar13,&DAT_200117ec + iVar32 + 2,currentChunk);
                        iVar33 = uVar34 + 2 + iVar32;
                        if (2 < LOG_LEVEL) {
                          if (BLE_DEBUG == 0) {
                            printk("%s(): stock change rate : %s\n","ble_process_put_req",pvVar13);
                          }
                          else {
                            ble_printk("%s(): stock change rate : %s\n","ble_process_put_req",
                                       pvVar13,extraout_r3_04);
                          }
                        }
                        iVar5 = LOG_LEVEL;
                        currentChunk = (uint)(byte)(&DAT_200117ec)[uVar34 + 2 + iVar32];
                        if (currentChunk == 6) {
                          currentChunk = (uint)(byte)(&DAT_200117ec)[iVar33 + 1];
                          if (currentChunk == 1) {
                            bVar2 = (&DAT_200117ec)[iVar33 + 2];
                            (&DAT_2000e105)[iVar25 * 0x7f2] = bVar2;
                            if (2 < iVar5) {
                              if (BLE_DEBUG == 0) {
                                printk("%s(): stock change status : %d\n");
                              }
                              else {
                                ble_printk("%s(): stock change status : %d\n","ble_process_put_req",
                                           (uint)bVar2,BLE_DEBUG);
                              }
                            }
                            iVar32 = LOG_LEVEL;
                            currentChunk = (uint)(byte)(&DAT_200117ec)[iVar33 + 3];
                            if (currentChunk == 7) {
                              uVar3 = *(ushort *)(&DAT_200117ec + iVar33 + 4);
                              if (uVar3 < 0x75f) {
                                iVar25 = iVar25 * 0x7f2;
                                *(ushort *)(&DAT_2000e106 + iVar25) = uVar3;
                                pvVar13 = memset((void *)(iVar29 + 0x2000e198),0,0x75e);
                                memcpy(pvVar13,&DAT_200117ec + iVar33 + 6,(uint)uVar3);
                                (&DAT_2000e104)[iVar25] = 1;
                                if (2 < iVar32) {
                                  if (BLE_DEBUG == 0) {
                                    printk("%s(): We received %d byte of data from the App\n");
                                  }
                                  else {
                                    ble_printk("%s(): We received %d byte of data from the App\n",
                                               "ble_process_put_req",
                                               (uint)*(ushort *)(&DAT_2000e106 + iVar25),BLE_DEBUG);
                                  }
                                }
                                _local_13c = *(undefined4 *)param_3;
                                DAT_2000e100 = 0;
                                local_138 = *(uint *)(param_3 + 4);
                                uStack_133 = 0;
                                uStack_132 = 0;
                                uStack_131 = 0;
                                uStack_130 = 0;
                                uStack_12f = 0;
                                uStack_12e = 0;
                                DAT_2000e102 = 0;
                                uStack_12c = 0;
                                uStack_12b = 0;
                                local_12a = 0;
                                local_134 = param_3[8];
                                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                                  if (BLE_DEBUG == 0) {
                                    printk("%s(): post_to_host failed ret = %d\n");
                                  }
                                  else {
                                    ble_printk("%s(): post_to_host failed ret = %d\n",
                                               "ble_process_put_req",iVar29,BLE_DEBUG);
                                  }
                                }
                              }
                              else {
                                if (0 < LOG_LEVEL) {
                                  if (BLE_DEBUG == 0) {
                                    printk("%s(): stocks image format oversize !!!\n");
                                  }
                                  else {
                                    ble_printk("%s(): stocks image format oversize !!!\n",
                                               "ble_process_put_req",0x75e,BLE_DEBUG);
                                  }
                                }
                                _local_13c = *(undefined4 *)param_3;
                                local_138 = *(uint *)(param_3 + 4);
                                uStack_132 = 0;
                                uStack_131 = 0;
                                uStack_130 = 0;
                                uStack_12f = 0;
                                uStack_12e = 0;
                                uStack_12c = 0;
                                uStack_12b = 0;
                                local_12a = 0;
                                local_134 = param_3[8];
                                uStack_133 = 1;
                                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                                  if (BLE_DEBUG == 0) {
                                    printk("%s(): post_to_host failed ret = %d\n");
                                  }
                                  else {
                                    ble_printk("%s(): post_to_host failed ret = %d\n",
                                               "ble_process_put_req",iVar29,BLE_DEBUG);
                                  }
                                }
                              }
                            }
                            else {
                              if (0 < LOG_LEVEL) {
                                if (BLE_DEBUG == 0) {
                                  printk(
                                        "%s(): stocks change rate data struct error, error type = %d\n"
                                        );
                                }
                                else {
                                  ble_printk("%s(): stocks change rate data struct error, error type = %d\n"
                                             ,"ble_process_put_req",currentChunk,BLE_DEBUG);
                                }
                              }
                              _local_13c = *(undefined4 *)param_3;
                              local_138 = *(uint *)(param_3 + 4);
                              uStack_132 = 0;
                              uStack_131 = 0;
                              uStack_130 = 0;
                              uStack_12f = 0;
                              uStack_12e = 0;
                              uStack_12c = 0;
                              uStack_12b = 0;
                              local_12a = 0;
                              local_134 = param_3[8];
                              uStack_133 = 1;
                              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                              if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                                if (BLE_DEBUG == 0) {
                                  printk("%s(): post_to_host failed ret = %d\n");
                                }
                                else {
                                  ble_printk("%s(): post_to_host failed ret = %d\n",
                                             "ble_process_put_req",iVar29,BLE_DEBUG);
                                }
                              }
                            }
                          }
                          else {
                            if (0 < LOG_LEVEL) {
                              if (BLE_DEBUG == 0) {
                                printk("%s(): stocks change status sformat error !!!\n");
                              }
                              else {
                                ble_printk("%s(): stocks change status sformat error !!!\n",
                                           "ble_process_put_req",currentChunk,BLE_DEBUG);
                              }
                            }
                            _local_13c = *(undefined4 *)param_3;
                            local_138 = *(uint *)(param_3 + 4);
                            uStack_132 = 0;
                            uStack_131 = 0;
                            uStack_130 = 0;
                            uStack_12f = 0;
                            uStack_12e = 0;
                            uStack_12c = 0;
                            uStack_12b = 0;
                            local_12a = 0;
                            local_134 = param_3[8];
                            uStack_133 = 1;
                            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                              if (BLE_DEBUG == 0) {
                                printk("%s(): post_to_host failed ret = %d\n");
                              }
                              else {
                                ble_printk("%s(): post_to_host failed ret = %d\n",
                                           "ble_process_put_req",iVar29,BLE_DEBUG);
                              }
                            }
                          }
                        }
                        else {
                          if (0 < LOG_LEVEL) {
                            if (BLE_DEBUG == 0) {
                              printk("%s(): stocks change rate data struct error, error type = %d\n"
                                    );
                            }
                            else {
                              ble_printk("%s(): stocks change rate data struct error, error type = %d\n"
                                         ,"ble_process_put_req",currentChunk,BLE_DEBUG);
                            }
                          }
                          _local_13c = *(undefined4 *)param_3;
                          local_138 = *(uint *)(param_3 + 4);
                          uStack_132 = 0;
                          uStack_131 = 0;
                          uStack_130 = 0;
                          uStack_12f = 0;
                          uStack_12e = 0;
                          uStack_12c = 0;
                          uStack_12b = 0;
                          local_12a = 0;
                          local_134 = param_3[8];
                          uStack_133 = 1;
                          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                            if (BLE_DEBUG == 0) {
                              printk("%s(): post_to_host failed ret = %d\n");
                            }
                            else {
                              ble_printk("%s(): post_to_host failed ret = %d\n",
                                         "ble_process_put_req",iVar29,BLE_DEBUG);
                            }
                          }
                        }
                      }
                      else {
                        if (0 < LOG_LEVEL) {
                          if (BLE_DEBUG == 0) {
                            printk("%s(): stocks change rate data struct error, error type = %d\n");
                          }
                          else {
                            ble_printk("%s(): stocks change rate data struct error, error type = %d\n"
                                       ,"ble_process_put_req",currentChunk,BLE_DEBUG);
                          }
                        }
                        _local_13c = *(undefined4 *)param_3;
                        local_138 = *(uint *)(param_3 + 4);
                        uStack_132 = 0;
                        uStack_131 = 0;
                        uStack_130 = 0;
                        uStack_12f = 0;
                        uStack_12e = 0;
                        uStack_12c = 0;
                        uStack_12b = 0;
                        local_12a = 0;
                        local_134 = param_3[8];
                        uStack_133 = 1;
                        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                          if (BLE_DEBUG == 0) {
                            printk("%s(): post_to_host failed ret = %d\n");
                          }
                          else {
                            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                       iVar29,BLE_DEBUG);
                          }
                        }
                      }
                    }
                    else {
                      if (0 < LOG_LEVEL) {
                        if (BLE_DEBUG == 0) {
                          printk("%s(): stocks price change data struct error, error type = %d\n");
                        }
                        else {
                          ble_printk("%s(): stocks price change data struct error, error type = %d\n"
                                     ,"ble_process_put_req",currentChunk,BLE_DEBUG);
                        }
                      }
                      uStack_132 = 0;
                      uStack_131 = 0;
                      uStack_130 = 0;
                      uStack_12f = 0;
                      uStack_12e = 0;
                      uStack_12c = 0;
                      uStack_12b = 0;
                      local_12a = 0;
                      _local_13c = *(undefined4 *)param_3;
                      local_138 = *(uint *)(param_3 + 4);
                      local_134 = param_3[8];
                      uStack_133 = 1;
                      iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                      if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                        if (BLE_DEBUG == 0) {
                          printk("%s(): post_to_host failed ret = %d\n");
                        }
                        else {
                          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                     iVar29,BLE_DEBUG);
                        }
                      }
                    }
                  }
                  else {
                    if (0 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): stocks share price data struct error, error type = %d\n");
                      }
                      else {
                        ble_printk("%s(): stocks share price data struct error, error type = %d\n",
                                   "ble_process_put_req",currentChunk,BLE_DEBUG);
                      }
                    }
                    uStack_132 = 0;
                    uStack_131 = 0;
                    uStack_130 = 0;
                    uStack_12f = 0;
                    uStack_12e = 0;
                    uStack_12c = 0;
                    uStack_12b = 0;
                    local_12a = 0;
                    _local_13c = *(undefined4 *)param_3;
                    local_138 = *(uint *)(param_3 + 4);
                    local_134 = param_3[8];
                    uStack_133 = 1;
                    iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                    if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): post_to_host failed ret = %d\n");
                      }
                      else {
                        ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                   iVar29,BLE_DEBUG);
                      }
                    }
                  }
                }
                else {
                  if (0 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): stocks company name data struct error, error type = %d\n");
                    }
                    else {
                      ble_printk("%s(): stocks company name data struct error, error type = %d\n",
                                 "ble_process_put_req",(uint)(byte)(&DAT_200117ec)[currentChunk],
                                 BLE_DEBUG);
                    }
                  }
                  uStack_132 = 0;
                  uStack_131 = 0;
                  uStack_130 = 0;
                  uStack_12f = 0;
                  uStack_12e = 0;
                  uStack_12c = 0;
                  uStack_12b = 0;
                  local_12a = 0;
                  _local_13c = *(undefined4 *)param_3;
                  local_138 = *(uint *)(param_3 + 4);
                  local_134 = param_3[8];
                  uStack_133 = 1;
                  iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                  if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): post_to_host failed ret = %d\n");
                    }
                    else {
                      ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29
                                 ,BLE_DEBUG);
                    }
                  }
                }
              }
              else {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stock code data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): stock code data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)DAT_200117ea,BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
            }
            else {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stocks data oversize!!!!\n");
                }
                else {
                  ble_printk("%s(): stocks data oversize!!!!\n","ble_process_put_req",
                             (uint)DAT_200117e8,BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): post_to_host failed ret = %d\n");
                }
                else {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                }
              }
            }
          }
          else {
            uStack_133 = 0;
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_2000e102 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_2000e102 + 1);
            }
          }
          DAT_2000e100 = 0;
          DAT_2000e102 = 0;
          memset(&DAT_200117e5,0,0x812);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      break;
    case 5:
      uVar4 = *(ushort *)(param_3 + 5);
      chunkCount = (uint)uVar4;
      currentChunk = (uint)*(ushort *)(param_3 + 7);
      if (chunkCount == 1) {
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x65 = param_3[9];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x66 = param_3[10];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x6a = param_3[0xb];
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                   "ble_process_put_req");
          }
          else {
            ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                       "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                       (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar14 = __get_dashboard_state();
              printk("%s(): news display mode = %d\n","ble_process_put_req",
                     (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6a);
            }
            else {
              pGVar14 = __get_dashboard_state();
              ble_printk("%s(): news display mode = %d\n","ble_process_put_req",
                         (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6a,
                         pGVar14->glasses_state_struct_0FF0);
            }
          }
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x6a == '\x02') {
          currentChunk = (uint)param_3[0xc];
          if (currentChunk < 5) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): current news index num = %d\n");
              }
              else {
                ble_printk("%s(): current news index num = %d\n","ble_process_put_req",currentChunk,
                           BLE_DEBUG);
              }
            }
            if (param_3[0xd] == 2) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): delete news index num = %d\n");
                }
                else {
                  ble_printk("%s(): delete news index num = %d\n","ble_process_put_req",currentChunk
                             ,BLE_DEBUG);
                }
              }
              memset(&DAT_20011281 + (currentChunk - 1) * 0x159,0,0x159);
              cleanNewsIndex();
            }
            else {
              if (param_3[0xe] != 1) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): news data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): news data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[0xe],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              if (0x40 < param_3[0xf]) {
                if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): news source oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): news source oversize !!!\n","ble_process_put_req",1,BLE_DEBUG)
                    ;
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
              iVar29 = (currentChunk - 1) * 0x159;
              sVar21 = (size_t)param_3[0xf];
              pvVar13 = (void *)(iVar29 + 0x20011282);
              if (0x3f < sVar21) {
                sVar21 = 0x40;
              }
              iVar25 = memcmp(pvVar13,param_3 + 0x10,sVar21);
              if (iVar25 != 0) {
                memset(pvVar13,0,0x40);
                cleanNewsIndex();
              }
              sVar21 = (size_t)param_3[0xf];
              if (0x3f < sVar21) {
                sVar21 = 0x40;
              }
              memcpy(pvVar13,param_3 + 0x10,sVar21);
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): news source : %s\n");
                }
                else {
                  ble_printk("%s(): news source : %s\n","ble_process_put_req",pvVar13,BLE_DEBUG);
                }
              }
              uVar34 = (uint)param_3[0xf];
              if (param_3[uVar34 + 0x10] != 2) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): news change rate data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): news change rate data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)param_3[uVar34 + 0x10],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              chunkCount = (uint)*(ushort *)(param_3 + uVar34 + 0x11);
              if (0x118 < chunkCount) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): news txt format oversize !!!\n");
                  }
                  else {
                    ble_printk("%s(): news txt format oversize !!!\n","ble_process_put_req",
                               (uint)param_3[uVar34 + 0x11],BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if (-1 < iVar29) {
                  return;
                }
                if (LOG_LEVEL < 1) {
                  return;
                }
                if (BLE_DEBUG != 0) {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                  return;
                }
                printk("%s(): post_to_host failed ret = %d\n");
                return;
              }
              pvVar13 = (void *)(iVar29 + 0x200112c2);
              iVar29 = memcmp(pvVar13,param_3 + uVar34 + 0x12,(uint)param_3[uVar34 + 0x11]);
              if (iVar29 != 0) {
                memset(pvVar13,0,0x118);
                cleanNewsIndex();
              }
              memcpy(pvVar13,param_3 + uVar34 + 0x13,chunkCount);
              (&DAT_20011281)[(currentChunk - 1) * 0x159] = 1;
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): We received %d byte of data from the News App\n");
                }
                else {
                  ble_printk("%s(): We received %d byte of data from the News App\n",
                             "ble_process_put_req",chunkCount,BLE_DEBUG);
                }
              }
            }
            uStack_133 = 0;
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
          else {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): news index num  oversize!!!!\n");
              }
              else {
                ble_printk("%s(): news index num  oversize!!!!\n","ble_process_put_req",
                           extraout_r2_12,BLE_DEBUG);
              }
            }
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 1;
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (currentChunk == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                  );
          }
          else {
            ble_printk("%s(): Action ID = 1,Received schedule multiple initialization packets, currently the first packet of data\n"
                       ,"ble_process_put_req",1,BLE_DEBUG);
          }
        }
        DAT_2000e0fc = 0;
        DAT_2000e0fa = 0;
        DAT_2000e0f8 = 0;
        memset(&DAT_20011120,0,0x161);
        memcpy(&DAT_20011120,param_3 + 9,uVar34 - 9);
        DAT_2000e0f8 = DAT_2000e0f8 + -9 + uVar3;
        _local_13c = *(undefined4 *)param_3;
        DAT_2000e0fc = DAT_2000e0fc + 1;
        local_138 = *(uint *)(param_3 + 4);
        uStack_133 = 0;
        uStack_132 = 0;
        uStack_131 = 0;
        uStack_130 = 0;
        local_134 = param_3[8];
        uStack_12f = 0;
        uStack_12e = 0;
        uStack_12c = 0;
        uStack_12b = 0;
        local_12a = 0;
        DAT_2000e0fa = uVar4;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      else if (currentChunk < chunkCount) {
        if ((uint)DAT_2000e0fc == currentChunk - 1) {
          memcpy(&DAT_20011120 + DAT_2000e0f8,param_3 + 9,uVar34 - 9);
          DAT_2000e0f8 = (DAT_2000e0f8 - 9) + uVar3;
          _local_13c = *(undefined4 *)param_3;
          DAT_2000e0fc = DAT_2000e0fc + 1;
          uStack_133 = 0;
          uStack_132 = 0;
          uStack_131 = 0;
          uStack_130 = 0;
          uStack_12f = 0;
          uStack_12e = 0;
          uStack_12c = 0;
          uStack_12b = 0;
          local_12a = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_2000e0fc + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_2000e0fc + 1);
            }
          }
          DAT_2000e0fa = 0;
          DAT_2000e0fc = 0;
          memset(&DAT_20011120,0,0x161);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (chunkCount == currentChunk) {
        if (((uint)DAT_2000e0fc == chunkCount - 1) && (DAT_2000e0fa == chunkCount)) {
          memcpy(&DAT_20011120 + DAT_2000e0f8,param_3 + 9,uVar34 - 9);
          DAT_2000e0f8 = (DAT_2000e0f8 - 9) + uVar3;
          DAT_2000e0fc = DAT_2000e0fc + 1;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x65 = DAT_20011120;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x66 = DAT_20011121;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x6a = DAT_20011122;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                     "ble_process_put_req");
            }
            else {
              ble_printk("%s(): Dashboard display mode :%d  custom display Area value : %d\n",
                         "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                         (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
            }
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                pGVar14 = __get_dashboard_state();
                printk("%s(): news display mode = %d\n","ble_process_put_req",
                       (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6a);
              }
              else {
                pGVar14 = __get_dashboard_state();
                ble_printk("%s(): news display mode = %d\n","ble_process_put_req",
                           (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6a,
                           pGVar14->glasses_state_struct_0FF0);
              }
            }
          }
          pGVar14 = __get_dashboard_state();
          if (pGVar14->glasses_state_struct_0FF0->field_0x6a == '\x02') {
            currentChunk = (uint)DAT_20011123;
            if (DAT_20011123 < 5) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): current news index num = %d\n");
                }
                else {
                  ble_printk("%s(): current news index num = %d\n","ble_process_put_req",
                             currentChunk,BLE_DEBUG);
                }
              }
              if (DAT_20011124 == '\x02') {
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): delete news index num = %d\n");
                  }
                  else {
                    ble_printk("%s(): delete news index num = %d\n","ble_process_put_req",
                               currentChunk,BLE_DEBUG);
                  }
                }
                memset(&DAT_20011281 + (currentChunk - 1) * 0x159,0,0x159);
                uStack_133 = 0;
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
              else if (DAT_20011125 == 1) {
                if (0x40 < DAT_20011126) {
                  if (1 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): news source oversize !!!\n");
                    }
                    else {
                      ble_printk("%s(): news source oversize !!!\n","ble_process_put_req",1,
                                 BLE_DEBUG);
                    }
                  }
                  uStack_132 = 0;
                  uStack_131 = 0;
                  uStack_130 = 0;
                  uStack_12f = 0;
                  uStack_12e = 0;
                  uStack_12c = 0;
                  uStack_12b = 0;
                  local_12a = 0;
                  _local_13c = *(undefined4 *)param_3;
                  local_138 = *(uint *)(param_3 + 4);
                  local_134 = param_3[8];
                  uStack_133 = 1;
                  iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                  if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): post_to_host failed ret = %d\n");
                    }
                    else {
                      ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29
                                 ,BLE_DEBUG);
                    }
                  }
                }
                iVar29 = (currentChunk - 1) * 0x159;
                sVar21 = (size_t)DAT_20011126;
                pvVar13 = (void *)(iVar29 + 0x20011282);
                if (0x3f < sVar21) {
                  sVar21 = 0x40;
                }
                iVar25 = memcmp(pvVar13,&DAT_20011127,sVar21);
                if (iVar25 != 0) {
                  memset(pvVar13,0,0x40);
                  cleanNewsIndex();
                }
                sVar21 = (size_t)DAT_20011126;
                if (0x3f < sVar21) {
                  sVar21 = 0x40;
                }
                memcpy(pvVar13,&DAT_20011127,sVar21);
                if (2 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): stock code name : %s\n");
                  }
                  else {
                    ble_printk("%s(): stock code name : %s\n","ble_process_put_req",pvVar13,
                               BLE_DEBUG);
                  }
                }
                uVar34 = (uint)DAT_20011126;
                if ((byte)(&DAT_20011127)[uVar34] == 2) {
                  chunkCount = (uint)*(ushort *)(&DAT_20011128 + uVar34);
                  if (chunkCount < 0x119) {
                    pvVar13 = (void *)(iVar29 + 0x200112c2);
                    iVar29 = memcmp(pvVar13,(void *)(uVar34 + 0x20011129),
                                    (uint)(byte)(&DAT_20011128)[uVar34]);
                    if (iVar29 != 0) {
                      memset(pvVar13,0,0x118);
                      cleanNewsIndex();
                    }
                    memcpy(pvVar13,(void *)(uVar34 + 0x2001112a),chunkCount);
                    (&DAT_20011281)[(currentChunk - 1) * 0x159] = 1;
                    if (2 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): We received %d byte of data from the News App\n");
                      }
                      else {
                        ble_printk("%s(): We received %d byte of data from the News App\n",
                                   "ble_process_put_req",chunkCount,BLE_DEBUG);
                      }
                    }
                    uStack_133 = 0;
                    uStack_132 = 0;
                    uStack_131 = 0;
                    uStack_130 = 0;
                    DAT_2000e0fa = 0;
                    uStack_12f = 0;
                    uStack_12e = 0;
                    DAT_2000e0fc = 0;
                    uStack_12c = 0;
                    uStack_12b = 0;
                    local_12a = 0;
                    _local_13c = *(undefined4 *)param_3;
                    local_138 = *(uint *)(param_3 + 4);
                    local_134 = param_3[8];
                    iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                    if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): post_to_host failed ret = %d\n");
                      }
                      else {
                        ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                   iVar29,BLE_DEBUG);
                      }
                    }
                  }
                  else {
                    if (0 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): news txt format oversize !!!\n");
                      }
                      else {
                        ble_printk("%s(): news txt format oversize !!!\n","ble_process_put_req",
                                   (uint)(byte)(&DAT_20011128)[uVar34],BLE_DEBUG);
                      }
                    }
                    uStack_132 = 0;
                    uStack_131 = 0;
                    uStack_130 = 0;
                    uStack_12f = 0;
                    uStack_12e = 0;
                    uStack_12c = 0;
                    uStack_12b = 0;
                    local_12a = 0;
                    _local_13c = *(undefined4 *)param_3;
                    local_138 = *(uint *)(param_3 + 4);
                    local_134 = param_3[8];
                    uStack_133 = 1;
                    iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                    if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): post_to_host failed ret = %d\n");
                      }
                      else {
                        ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",
                                   iVar29,BLE_DEBUG);
                      }
                    }
                  }
                }
                else {
                  if (0 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): news change rate data struct error, error type = %d\n");
                    }
                    else {
                      ble_printk("%s(): news change rate data struct error, error type = %d\n",
                                 "ble_process_put_req",(uint)(byte)(&DAT_20011127)[uVar34],BLE_DEBUG
                                );
                    }
                  }
                  uStack_132 = 0;
                  uStack_131 = 0;
                  uStack_130 = 0;
                  uStack_12f = 0;
                  uStack_12e = 0;
                  uStack_12c = 0;
                  uStack_12b = 0;
                  local_12a = 0;
                  _local_13c = *(undefined4 *)param_3;
                  local_138 = *(uint *)(param_3 + 4);
                  local_134 = param_3[8];
                  uStack_133 = 1;
                  iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                  if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): post_to_host failed ret = %d\n");
                    }
                    else {
                      ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29
                                 ,BLE_DEBUG);
                    }
                  }
                }
              }
              else {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): news data struct error, error type = %d\n");
                  }
                  else {
                    ble_printk("%s(): news data struct error, error type = %d\n",
                               "ble_process_put_req",(uint)DAT_20011125,BLE_DEBUG);
                  }
                }
                uStack_132 = 0;
                uStack_131 = 0;
                uStack_130 = 0;
                uStack_12f = 0;
                uStack_12e = 0;
                uStack_12c = 0;
                uStack_12b = 0;
                local_12a = 0;
                _local_13c = *(undefined4 *)param_3;
                local_138 = *(uint *)(param_3 + 4);
                local_134 = param_3[8];
                uStack_133 = 1;
                iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
                if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): post_to_host failed ret = %d\n");
                  }
                  else {
                    ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                               BLE_DEBUG);
                  }
                }
              }
            }
            else {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): stocks data oversize!!!!\n");
                }
                else {
                  ble_printk("%s(): stocks data oversize!!!!\n","ble_process_put_req",
                             (uint)DAT_20011123,BLE_DEBUG);
                }
              }
              uStack_132 = 0;
              uStack_131 = 0;
              uStack_130 = 0;
              uStack_12f = 0;
              uStack_12e = 0;
              uStack_12c = 0;
              uStack_12b = 0;
              local_12a = 0;
              _local_13c = *(undefined4 *)param_3;
              local_138 = *(uint *)(param_3 + 4);
              local_134 = param_3[8];
              uStack_133 = 1;
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): post_to_host failed ret = %d\n");
                }
                else {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                }
              }
            }
          }
          else {
            uStack_133 = 0;
            uStack_132 = 0;
            uStack_131 = 0;
            uStack_130 = 0;
            uStack_12f = 0;
            uStack_12e = 0;
            uStack_12c = 0;
            uStack_12b = 0;
            local_12a = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_2000e0fc + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_2000e0fc + 1);
            }
          }
          DAT_2000e0fa = 0;
          DAT_2000e0fc = 0;
          memset(&DAT_20011120,0,0x161);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      break;
    case 6:
      *(byte *)(*(int *)(param_1 + 0x874) + 0x65) = param_3[5];
      *(byte *)(*(int *)(param_1 + 0x874) + 0x66) = param_3[6];
      if ((*(char *)(*(int *)(param_1 + 0x874) + 0x66) == '\x04') &&
         (cVar10 = *(char *)(*(int *)(param_1 + 0x874) + 0x65), cVar10 != DAT_2001111f)) {
        DAT_2001111f = cVar10;
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x6b = 0;
        DAT_20003005 = '\x01';
        DAT_2001111e = '\0';
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Dashboard display mode :%d custom display Area value : %d\n",
                 "ble_process_put_req");
        }
        else {
          ble_printk("%s(): Dashboard display mode :%d custom display Area value : %d\n",
                     "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                     (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
        }
      }
      FUN_0001666c();
      set_ncs_mem_initialized();
      memset((void *)((int)&local_138 + 1),0,0xf);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT31(local_138._1_3_,param_3[4]);
      (**(code **)(param_1 + 0xc))(&local_13c,6);
      break;
    case 7:
      _local_13c = *(undefined4 *)param_3;
      local_138 = *(uint *)(param_3 + 4);
      uVar4 = *(ushort *)(param_3 + 5);
      chunkCount = (uint)uVar4;
      local_134 = param_3[8];
      currentChunk = (uint)*(ushort *)(param_3 + 7);
      uStack_133 = 0;
      if (chunkCount == 1) {
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x65 = param_3[9];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x66 = param_3[10];
        pGVar14 = __get_dashboard_state();
        pGVar14->glasses_state_struct_0FF0->field_0x6b = param_3[0xb];
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Dashboard display mode :%d custom display Area value : %d\n",
                   "ble_process_put_req");
          }
          else {
            ble_printk("%s(): Dashboard display mode :%d custom display Area value : %d\n",
                       "ble_process_put_req",(uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x65),
                       (uint)*(byte *)(*(int *)(param_1 + 0x874) + 0x66));
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar14 = __get_dashboard_state();
              printk("%s(): CityWalk display mode = %d\n","ble_process_put_req",
                     (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6b);
            }
            else {
              pGVar14 = __get_dashboard_state();
              ble_printk("%s(): CityWalk display mode = %d\n","ble_process_put_req",
                         (uint)(byte)pGVar14->glasses_state_struct_0FF0->field_0x6b,
                         pGVar14->glasses_state_struct_0FF0);
            }
          }
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x66 != '\x04') {
          return;
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x6b == '\x02') {
          return;
        }
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x6b == '\x03') {
          bVar2 = param_3[0xc];
          bVar1 = param_3[0xd];
          pGVar14 = __get_dashboard_state();
          pgVar23 = pGVar14->glasses_state_struct_0FF0;
          pgVar23->field_0x6d = bVar2;
          pgVar23->field_0x6e = bVar1;
          pGVar14 = __get_dashboard_state();
          if ((int)((uint)*(ushort *)&pGVar14->glasses_state_struct_0FF0->field_0x6d << 0x1f) < 0) {
            pGVar14 = __get_dashboard_state();
            *(short *)&pGVar14->glasses_state_struct_0FF0->field_0x6d =
                 *(short *)&pGVar14->glasses_state_struct_0FF0->field_0x6d + -1;
          }
          bVar2 = param_3[0xe];
          bVar1 = param_3[0xf];
          pGVar14 = __get_dashboard_state();
          pgVar23 = pGVar14->glasses_state_struct_0FF0;
          pgVar23->field_0x6f = bVar2;
          pgVar23->field_0x70 = bVar1;
          pGVar14 = __get_dashboard_state();
          if (pGVar14->glasses_state_struct_0FF0->field_0x65 == '\0') {
            pGVar14 = __get_dashboard_state();
            uVar22 = extraout_r2_13;
            if ((0x108 < *(ushort *)&pGVar14->glasses_state_struct_0FF0->field_0x6d) ||
               (pGVar14 = __get_dashboard_state(), uVar22 = extraout_r2_14,
               0x68 < *(ushort *)&pGVar14->glasses_state_struct_0FF0->field_0x6f)) {
LAB_0001e4f0:
              if (LOG_LEVEL < 1) {
                return;
              }
              if (BLE_DEBUG != 0) {
                ble_printk("%s(): citywalk arrow offset too long!\n","ble_process_put_req",uVar22,
                           BLE_DEBUG);
                return;
              }
              printk("%s(): citywalk arrow offset too long!\n");
              return;
            }
            puVar12 = &DAT_20013dfb;
LAB_0001e572:
            memcpy(puVar12,param_3 + 0x10,uVar34 - 0x10);
          }
          else {
            pGVar14 = __get_dashboard_state();
            if (pGVar14->glasses_state_struct_0FF0->field_0x65 == '\x01') {
              pGVar14 = __get_dashboard_state();
              uVar22 = extraout_r2_15;
              if ((0x158 < *(ushort *)&pGVar14->glasses_state_struct_0FF0->field_0x6d) ||
                 (pGVar14 = __get_dashboard_state(), uVar22 = extraout_r2_16,
                 0x68 < *(ushort *)&pGVar14->glasses_state_struct_0FF0->field_0x6f))
              goto LAB_0001e4f0;
              puVar12 = &DAT_2001434b;
              goto LAB_0001e572;
            }
          }
          pGVar14 = __get_dashboard_state();
          if (pGVar14->glasses_state_struct_0FF0->field_0x65 == DAT_2001111f) {
            if (DAT_2001111e == '\x01') {
              DAT_20003005 = '\0';
              pGVar14 = __get_dashboard_state();
              if (pGVar14->glasses_state_struct_0FF0->field_0x71 == '\x02') {
                memcpy(&DAT_200143cb,&DAT_20012a4f,0x197c);
              }
              else {
                pGVar14 = __get_dashboard_state();
                if (pGVar14->glasses_state_struct_0FF0->field_0x65 == '\0') {
                  puVar15 = &DAT_20013dfb;
                  puVar12 = &DAT_20015777;
                }
                else {
                  pGVar14 = __get_dashboard_state();
                  if (pGVar14->glasses_state_struct_0FF0->field_0x65 != '\x01') goto LAB_0001e646;
                  puVar15 = &DAT_2001434b;
                  puVar12 = &DAT_20015cc7;
                }
                memcpy(puVar12,puVar15,uVar34 - 0x10);
              }
LAB_0001e646:
              pGVar14 = __get_dashboard_state();
              pGVar14->glasses_state_struct_0FF0->field_0x71 = 3;
              DAT_2001111d = 1;
            }
          }
          else {
            pGVar14 = __get_dashboard_state();
            DAT_2001111f = pGVar14->glasses_state_struct_0FF0->field_0x65;
            pGVar14 = __get_dashboard_state();
            pGVar14->glasses_state_struct_0FF0->field_0x6b = 0;
            DAT_20003005 = '\x01';
            DAT_2001111e = '\0';
          }
          if (DAT_20003005 == '\x01') {
            pGVar14 = __get_dashboard_state();
            pGVar14->glasses_state_struct_0FF0->field_0x6b = 0;
          }
        }
      }
      else if (currentChunk == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Received citywalk multiple packets, currently the first packet of data\n")
            ;
          }
          else {
            ble_printk("%s(): Received citywalk multiple packets, currently the first packet of data\n"
                       ,"ble_process_put_req",(uint)local_134,BLE_DEBUG);
          }
        }
        if (param_3[10] != 4) {
          return;
        }
        DAT_2000e0f2 = 1;
        DAT_2000e0f0 = uVar4;
        if (param_3[0xb] == 2) {
          DAT_2001111e = '\0';
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x71 = 1;
          memset(&DAT_20012a4f,0,0x197c);
          memcpy(&DAT_20012a4f,param_3 + 9,uVar34 - 9);
          DAT_2000e0f6 = (ushort)(uVar34 - 9);
        }
      }
      else if (currentChunk < chunkCount) {
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x71 == '\x01') {
          DAT_2001111e = '\0';
          if ((uint)DAT_2000e0f2 != currentChunk - 1) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                       ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
              else {
                ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
LAB_0001e766:
            DAT_2000e0f6 = 0;
            DAT_2000e0f2 = 0;
            DAT_2000e0f0 = uVar4;
            memset(&DAT_20012a4f,0,0x197c);
            return;
          }
          if (0x197c < (DAT_2000e0f6 - 9) + uVar34) {
            if (LOG_LEVEL < 1) {
              DAT_2001111e = 0;
              return;
            }
            if (BLE_DEBUG != 0) {
              ble_printk("%s(): citywalk data is too long, the current data length %d,wait write data length = %d\n"
                         ,"ble_process_put_req",(uint)DAT_2000e0f6,uVar34 - 9);
              return;
            }
            printk("%s(): citywalk data is too long, the current data length %d,wait write data length = %d\n"
                   ,"ble_process_put_req",(uint)DAT_2000e0f6);
            return;
          }
          memcpy(&DAT_20012a4f + DAT_2000e0f6,param_3 + 9,uVar34 - 9);
          DAT_2000e0f6 = (DAT_2000e0f6 - 9) + uVar3;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                    );
            }
            else {
              ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                         ,"ble_process_put_req",currentChunk,BLE_DEBUG);
            }
          }
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
        }
      }
      else if (chunkCount == currentChunk) {
        pGVar14 = __get_dashboard_state();
        if (pGVar14->glasses_state_struct_0FF0->field_0x71 == '\x01') {
          if (((uint)DAT_2000e0f2 != chunkCount - 1) || (DAT_2000e0f0 != chunkCount)) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                       ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
              else {
                ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
            DAT_2001111e = '\0';
            goto LAB_0001e766;
          }
          if (0x197c < (DAT_2000e0f6 - 9) + uVar34) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): citywalk data is too long, the current data length %d,wait write data length = %d\n"
                       ,"ble_process_put_req",(uint)DAT_2000e0f6);
              }
              else {
                ble_printk("%s(): citywalk data is too long, the current data length %d,wait write data length = %d\n"
                           ,"ble_process_put_req",(uint)DAT_2000e0f6,uVar34 - 9);
              }
            }
            DAT_2001111e = 0;
            return;
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                    );
            }
            else {
              ble_printk("%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                         ,"ble_process_put_req",LOG_LEVEL,BLE_DEBUG);
            }
          }
          memcpy(&DAT_20012a4f + DAT_2000e0f6,param_3 + 9,uVar34 - 9);
          DAT_2000e0f6 = (DAT_2000e0f6 - 9) + uVar3;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x65 = DAT_20012a4f;
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x66 = DAT_20012a50;
          if (DAT_20003005 == '\x01') {
            pGVar14 = __get_dashboard_state();
            pGVar14->glasses_state_struct_0FF0->field_0x6b = 0;
          }
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x6c = DAT_20012a52;
          DAT_2001111e = '\x01';
          pGVar14 = __get_dashboard_state();
          pGVar14->glasses_state_struct_0FF0->field_0x71 = 2;
          pGVar14 = __get_dashboard_state();
          if (((pGVar14->glasses_state_struct_0FF0->field_0x65 == '\0') && (DAT_2000e0f6 != 0x13ac))
             || ((pGVar14 = __get_dashboard_state(),
                 pGVar14->glasses_state_struct_0FF0->field_0x65 == '\x01' &&
                 (DAT_2000e0f6 != 0x18fc)))) {
            DAT_20003005 = '\x01';
            DAT_2001111e = '\0';
            pGVar14 = __get_dashboard_state();
            pGVar14->glasses_state_struct_0FF0->field_0x71 = 0;
          }
        }
        DAT_2000e0f0 = 0;
        DAT_2000e0f2 = 0;
        DAT_2000e0f6 = 0;
      }
      (**(code **)(param_1 + 0xc))(&local_13c,10);
    }
    break;
  case 7:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): #BLE_REQ_PUT_COUNTDOWN_TIMER:\n");
      }
      else {
        ble_printk("%s(): #BLE_REQ_PUT_COUNTDOWN_TIMER:\n","ble_process_put_req",currentChunk,
                   BLE_DEBUG);
      }
    }
    puVar31[1] = *(undefined4 *)(param_3 + 1);
    *(byte *)(puVar31 + 2) = param_3[5];
    *(undefined2 *)((int)puVar31 + 2) = 5;
    *(undefined4 *)(param_1 + 0x14) = 9;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): countdown expect_ts:%d, enable:%d\n","ble_process_put_req");
      }
      else {
        ble_printk("%s(): countdown expect_ts:%d, enable:%d\n","ble_process_put_req",puVar31[1],
                   (uint)*(byte *)(puVar31 + 2));
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): msg_data: %02x,%02x,%02x,%02x,%02x\n");
        }
        else {
          ble_printk("%s(): msg_data: %02x,%02x,%02x,%02x,%02x\n","ble_process_put_req",
                     (uint)*(byte *)(puVar31 + 1),(uint)*(byte *)((int)puVar31 + 5));
        }
      }
    }
    FUN_00019d14(param_1,(byte *)local_128,8);
    _local_13c = CONCAT11(0xc9,local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 8:
    uVar34 = (uint)*(ushort *)(param_3 + 1);
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 == currentChunk) {
      bVar2 = param_3[4];
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received dashboard details packet\n");
          currentChunk = extraout_r2_04;
        }
        else {
          ble_printk("%s(): received dashboard details packet\n","ble_process_put_req",currentChunk,
                     BLE_DEBUG);
          currentChunk = extraout_r2_03;
        }
      }
      if (bVar2 == 3) {
        if (param_3[5] < 3) {
          bVar11 = __is_master();
          if (bVar11) {
            SendDashBoardStartupModeInfoToSlave(param_3[5]);
          }
          memset(&local_13c,0,0x14);
          memcpy(&local_13c,param_3,uVar34);
          (**(code **)(param_1 + 0xc))(&local_13c,uVar34);
        }
        else if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): dashboard details packet error,invalid data\n");
          }
          else {
            ble_printk("%s(): dashboard details packet error,invalid data\n","ble_process_put_req",
                       currentChunk,BLE_DEBUG);
          }
        }
      }
      else if (bVar2 == 4) {
        memset(&local_13c,0,0x14);
        memcpy(&local_13c,param_3,uVar34);
        uVar9 = FUN_000260dc();
        local_138._0_2_ = CONCAT11(uVar9,(undefined1)local_138);
        (**(code **)(param_1 + 0xc))(&local_13c,uVar34);
      }
    }
    else if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
               "ble_process_put_req",currentChunk,uVar34);
      }
      else {
        ble_printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
                   "ble_process_put_req",currentChunk,uVar34);
      }
    }
    break;
  case 9:
    uVar3 = *(ushort *)(param_3 + 1);
    uVar34 = (uint)uVar3;
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 != currentChunk) {
      if (LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
                   ,"ble_process_put_req",currentChunk,uVar34);
        return;
      }
      printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
             ,"ble_process_put_req",currentChunk,uVar34);
      return;
    }
    puVar24 = (undefined1 *)(uint)param_3[4];
    puVar17 = &switchD_0001eae6::switchdataD_0001eaec;
    switch(puVar24) {
    case (undefined1 *)0x1:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received teleprompter init  packet ....\n");
        }
        else {
          ble_printk("%s(): received teleprompter init  packet ....\n","ble_process_put_req",
                     &switchD_0001eae6::switchdataD_0001eaec,BLE_DEBUG);
        }
      }
      memset(puVar19,0,0x217);
      iVar25 = LOG_LEVEL;
      uVar4 = *(ushort *)(param_3 + 5);
      currentChunk = (uint)uVar4;
      chunkCount = (uint)*(ushort *)(param_3 + 7);
      if (currentChunk == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received teleprompter init packet,total packet = 1\n");
          }
          else {
            ble_printk("%s(): received teleprompter init packet,total packet = 1\n",
                       "ble_process_put_req",extraout_r2_17,BLE_DEBUG);
          }
        }
        bVar2 = param_3[3];
        *(byte *)(param_1 + -0x6af) = bVar2;
        FUN_0007f4a4(bVar2,0,0);
        *(undefined1 *)((int)puVar31 + 0xe) = 1;
        *(undefined1 *)((int)puVar31 + 5) = 1;
        *(byte *)(puVar31 + 1) = param_3[10] & 0xf;
        *(byte *)((int)puVar31 + 0xf) = param_3[10] & 0x80;
        *(byte *)(puVar31 + 4) = param_3[9];
        *(byte *)((int)puVar31 + 0x11) = param_3[0xb];
        *(undefined1 *)((int)puVar31 + 0x12) = 0;
        *(undefined1 *)((int)puVar31 + 0x13) = 0;
        *(undefined1 *)(puVar31 + 5) = 0;
        memcpy((void *)((int)puVar31 + 0x1b),param_3 + 0xc,uVar34 - 0x14);
        *(short *)((int)puVar31 + 0x19) = (short)(uVar34 - 0x14);
        uVar22 = *(undefined4 *)(param_3 + (uVar34 - 4));
        *(uint *)((int)puVar31 + 6) =
             (uint)param_3[uVar34 - 6] << 0x10 | (uint)param_3[uVar34 - 7] << 8 |
             (uint)param_3[uVar34 - 8] | (uint)param_3[uVar34 - 5] << 0x18;
        *(undefined4 *)((int)puVar31 + 10) = uVar22;
        local_148 = 0;
        uStack_144 = 0;
        FUN_0004d4f8((longlong *)&local_148);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                  );
          }
          else {
            ble_printk("%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                       ,"ble_process_put_req",*(undefined4 *)((int)puVar31 + 6),
                       *(undefined4 *)((int)puVar31 + 10));
          }
        }
        uVar3 = *(ushort *)(param_2 + 2);
        *(ushort *)((int)puVar31 + 2) = uVar3;
        *(uint *)(param_1 + 0x14) = uVar3 + 4;
        FUN_00019d14(param_1,(byte *)local_128,8);
        uStack_133 = 0;
        uStack_132 = 0;
        uStack_131 = 0;
        uStack_130 = 0;
        uStack_12f = 0;
        uStack_12e = 0;
        uStack_12c = 0;
        uStack_12b = 0;
        local_12a = 0;
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        bVar11 = __is_master();
        if (bVar11) {
          send_response_data_to_msgqueue(&local_13c,10);
        }
        else {
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (chunkCount == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Action ID = 1,Received multiple initialization packets, currently the first packet of data\n"
                  );
          }
          else {
            ble_printk("%s(): Action ID = 1,Received multiple initialization packets, currently the first packet of data\n"
                       ,"ble_process_put_req",extraout_r2_17,BLE_DEBUG);
          }
        }
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
        DAT_2000e0ee = 0;
        DAT_2000e0f0 = uVar4;
        memset(&DAT_20010f06,0,0x217);
        DAT_20010f10 = 1;
        DAT_20010f07 = '\0';
        DAT_20010f06 = param_3[10] & 0xf;
        DAT_20010f11 = param_3[10] & 0x80;
        DAT_20010f12 = param_3[9];
        DAT_20010f13 = param_3[0xb];
        DAT_20010f14 = 0;
        DAT_20010f15 = 0;
        _DAT_20010f08 = 0;
        _DAT_20010f0c = 0;
        memcpy(&DAT_20010f1d,param_3 + 0xc,uVar34 - 0xc);
        DAT_2000e0ee = (ushort)(uVar34 - 0xc);
        _local_13c = *(undefined4 *)param_3;
        DAT_2000e0f2 = DAT_2000e0f2 + 1;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 0;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      else if (chunkCount < currentChunk) {
        if ((uint)DAT_2000e0f2 == chunkCount - 1) {
          memcpy(&DAT_20010f1d + DAT_2000e0ee,param_3 + 0xc,uVar34 - 0xc);
          DAT_2000e0ee = (DAT_2000e0ee - 0xc) + uVar3;
          if (2 < iVar25) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): ACTION ID = 1,Successfully received the subpackage content, the packet sequence is %d\n"
                    );
            }
            else {
              ble_printk("%s(): ACTION ID = 1,Successfully received the subpackage content, the packet sequence is %d\n"
                         ,"ble_process_put_req",chunkCount,BLE_DEBUG);
            }
          }
          _local_13c = *(undefined4 *)param_3;
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 0;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          DAT_2000e0f0 = uVar4;
          memset(&DAT_20010f06,0,0x217);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (chunkCount == currentChunk) {
        if (((uint)DAT_2000e0f2 == chunkCount - 1) && (DAT_2000e0f0 == chunkCount)) {
          bVar2 = param_3[3];
          *(byte *)(param_1 + -0x6af) = bVar2;
          FUN_0007f4a4(bVar2,0,0);
          memcpy(&DAT_20010f1d + DAT_2000e0ee,param_3 + 0xc,uVar34 - 0x14);
          DAT_2000e0ee = (DAT_2000e0ee - 0x14) + uVar3;
          _DAT_20010f08 =
               (uint)param_3[uVar34 - 6] << 0x10 | (uint)param_3[uVar34 - 7] << 8 |
               (uint)param_3[uVar34 - 8] | (uint)param_3[uVar34 - 5] << 0x18;
          _DAT_20010f0c = *(undefined4 *)(param_3 + (uVar34 - 4));
          local_128[0] = 0;
          local_128[1] = 0;
          DAT_20010f1b = DAT_2000e0ee;
          FUN_0004d4f8((longlong *)local_128);
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                    );
            }
            else {
              ble_printk("%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                         ,"ble_process_put_req",_DAT_20010f08,_DAT_20010f0c);
            }
          }
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
          DAT_20010f07 = '\x01';
          pGVar14 = __get_dashboard_state();
          memcpy(*(void **)&pGVar14->field_0x1000,&DAT_20010f06,0x217);
          uVar22 = extraout_r2_18;
          if (DAT_20010f07 != '\0') {
            update_persist_task_status(iVar29,9,2);
            uVar22 = extraout_r2_19;
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): ACTION ID = 1,Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                    );
            }
            else {
              ble_printk("%s(): ACTION ID = 1,Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                         ,"ble_process_put_req",uVar22,BLE_DEBUG);
            }
          }
          local_138 = *(uint *)(param_3 + 4);
          DAT_2000e0f0 = 0;
          _local_13c = *(undefined4 *)param_3;
          DAT_2000e0f2 = 0;
          local_134 = param_3[8];
          uStack_133 = 0;
          bVar11 = __is_master();
          if (bVar11) {
            send_response_data_to_msgqueue(&local_13c,10);
          }
          else {
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f0 = uVar4;
          memset(&DAT_20010f06,0,0x217);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): A serious packet order error occurred!\n");
          }
          else {
            ble_printk("%s(): A serious packet order error occurred!\n","ble_process_put_req",
                       currentChunk,BLE_DEBUG);
          }
        }
        DAT_2000e0f0 = 0;
        DAT_2000e0f2 = 0;
        memset(&DAT_20010f06,0,0x217);
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 1;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      break;
    case (undefined1 *)0x2:
      *(byte *)(param_1 + -0x6af) = param_3[3];
      FUN_0007f4a4(param_3[3],0,0);
      *(uint *)(param_1 + 0x14) = *(ushort *)((int)puVar31 + 2) + 4;
      *(undefined2 *)(*(int *)(param_1 + 0x884) + 0xe) = *(undefined2 *)(param_3 + 6);
      *(byte *)(*(int *)(param_1 + 0x884) + 0xd) = param_3[5];
      *(undefined1 *)(*(int *)(param_1 + 0x884) + 10) = 2;
      iVar25 = *(int *)(param_1 + 0x884);
      uVar22 = *(undefined4 *)(param_3 + (uVar34 - 4));
      *(uint *)(iVar25 + 2) =
           (uint)param_3[uVar34 - 6] << 0x10 | (uint)param_3[uVar34 - 7] << 8 |
           (uint)param_3[uVar34 - 8] | (uint)param_3[uVar34 - 5] << 0x18;
      iVar29 = LOG_LEVEL;
      *(undefined4 *)(iVar25 + 6) = uVar22;
      if (2 < iVar29) {
        if (BLE_DEBUG == 0) {
          printk("%s(): MARK POSITION = %d\n");
        }
        else {
          ble_printk("%s(): MARK POSITION = %d\n","ble_process_put_req",
                     (uint)*(ushort *)(*(int *)(param_1 + 0x884) + 0xe),BLE_DEBUG);
        }
      }
      memset((void *)((int)&local_138 + 1),0,0xf);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT31(local_138._1_3_,param_3[4]);
      bVar11 = __is_master();
      if (!bVar11) {
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
        if (-1 < iVar29) {
          return;
        }
        if (LOG_LEVEL < 1) {
          return;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
          return;
        }
        printk("%s(): post_to_host failed ret = %d\n");
        return;
      }
      goto LAB_0001f2e6;
    case (undefined1 *)0x3:
    case (undefined1 *)0x7:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received teleprompter text upgrade packet ....\n");
          puVar17 = extraout_r2_21;
        }
        else {
          ble_printk("%s(): received teleprompter text upgrade packet ....\n","ble_process_put_req",
                     &switchD_0001eae6::switchdataD_0001eaec,BLE_DEBUG);
          puVar17 = extraout_r2_20;
        }
      }
      iVar29 = LOG_LEVEL;
      uVar4 = *(ushort *)(param_3 + 5);
      currentChunk = (uint)uVar4;
      chunkCount = (uint)*(ushort *)(param_3 + 7);
      if (currentChunk == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received TEXT UPGRADE Single PACKET ...\n");
          }
          else {
            ble_printk("%s(): received TEXT UPGRADE Single PACKET ...\n","ble_process_put_req",
                       puVar17,BLE_DEBUG);
          }
        }
        bVar2 = param_3[3];
        *(byte *)(param_1 + -0x6af) = bVar2;
        FUN_0007f4a4(bVar2,0,0);
        *(undefined1 *)(*(int *)(param_1 + 0x884) + 10) = 3;
        *(undefined1 *)(*(int *)(param_1 + 0x884) + 1) = 1;
        *(byte *)(*(int *)(param_1 + 0x884) + 0xd) = param_3[9];
        *(undefined2 *)(*(int *)(param_1 + 0x884) + 0xe) = *(undefined2 *)(param_3 + 10);
        memset((void *)(*(int *)(param_1 + 0x884) + 0x17),0,0x200);
        memcpy((void *)(*(int *)(param_1 + 0x884) + 0x17),param_3 + 0xc,uVar34 - 0x14);
        *(short *)(*(int *)(param_1 + 0x884) + 0x15) = (short)(uVar34 - 0x14);
        iVar29 = *(int *)(param_1 + 0x884);
        uVar22 = *(undefined4 *)(param_3 + (uVar34 - 4));
        *(uint *)(iVar29 + 2) =
             (uint)param_3[uVar34 - 6] << 0x10 | (uint)param_3[uVar34 - 7] << 8 |
             (uint)param_3[uVar34 - 8] | (uint)param_3[uVar34 - 5] << 0x18;
        *(undefined4 *)(iVar29 + 6) = uVar22;
        local_128[0] = 0;
        local_128[1] = 0;
        FUN_0004d4f8((longlong *)local_128);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                  );
          }
          else {
            ble_printk("%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                       ,"ble_process_put_req",*(undefined4 *)(*(int *)(param_1 + 0x884) + 2),
                       *(undefined4 *)(*(int *)(param_1 + 0x884) + 6));
          }
        }
        if (puVar24 == &DAT_00000007) {
          DAT_20010f05 = 1;
        }
        uVar3 = *(ushort *)(param_2 + 2);
        *(ushort *)((int)puVar31 + 2) = uVar3;
        *(uint *)(param_1 + 0x14) = uVar3 + 4;
        uStack_133 = 0;
        uStack_132 = 0;
        uStack_131 = 0;
        uStack_130 = 0;
        uStack_12f = 0;
        uStack_12e = 0;
        uStack_12c = 0;
        uStack_12b = 0;
        local_12a = 0;
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        bVar11 = __is_master();
        if (bVar11) {
          send_response_data_to_msgqueue(&local_13c,10);
        }
        else {
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (chunkCount == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): ACTION ID = 3,Received multiple initialization packets, currently the first packet of data\n"
                  );
          }
          else {
            ble_printk("%s(): ACTION ID = 3,Received multiple initialization packets, currently the first packet of data\n"
                       ,"ble_process_put_req",puVar17,BLE_DEBUG);
          }
        }
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
        DAT_2000e0f0 = uVar4;
        memset(&DAT_20010f06,0,0x217);
        memcpy(&DAT_20010f06,param_3 + 0xc,uVar34 - 0xc);
        iVar29 = *(int *)(param_1 + 0x884);
        DAT_2000e0f2 = DAT_2000e0f2 + 1;
        DAT_2000e0f4 = (ushort)(uVar34 - 0xc);
        *(undefined1 *)(iVar29 + 2) = 0;
        *(undefined1 *)(iVar29 + 3) = 0;
        *(undefined1 *)(iVar29 + 4) = 0;
        *(undefined1 *)(iVar29 + 5) = 0;
        *(undefined1 *)(iVar29 + 6) = 0;
        *(undefined1 *)(iVar29 + 7) = 0;
        *(undefined1 *)(iVar29 + 8) = 0;
        *(undefined1 *)(iVar29 + 9) = 0;
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 0;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      else if (chunkCount < currentChunk) {
        if ((uint)DAT_2000e0f2 == chunkCount - 1) {
          memcpy(&DAT_20010f06 + DAT_2000e0f4,param_3 + 0xc,uVar34 - 0xc);
          DAT_2000e0f4 = (DAT_2000e0f4 - 0xc) + uVar3;
          if (2 < iVar29) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): ACTION ID = 3,Successfully received the subpackage content, the packet sequence is %d\n"
                    );
            }
            else {
              ble_printk("%s(): ACTION ID = 3,Successfully received the subpackage content, the packet sequence is %d\n"
                         ,"ble_process_put_req",chunkCount,BLE_DEBUG);
            }
          }
          _local_13c = *(undefined4 *)param_3;
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 0;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f0 = 0;
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          memset(&DAT_20010f06,0,0x217);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else if (chunkCount == currentChunk) {
        if (((uint)DAT_2000e0f2 == chunkCount - 1) && (DAT_2000e0f0 == chunkCount)) {
          bVar2 = param_3[3];
          *(byte *)(param_1 + -0x6af) = bVar2;
          FUN_0007f4a4(bVar2,0,0);
          memcpy(&DAT_20010f06 + DAT_2000e0f4,param_3 + 0xc,uVar34 - 0x14);
          DAT_2000e0f4 = (DAT_2000e0f4 - 0x14) + uVar3;
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
          memset((void *)(*(int *)(param_1 + 0x884) + 0x17),0,0x200);
          memcpy((void *)(*(int *)(param_1 + 0x884) + 0x17),&DAT_20010f06,(uint)DAT_2000e0f4);
          *(ushort *)(*(int *)(param_1 + 0x884) + 0x15) = DAT_2000e0f4;
          *(undefined1 *)(*(int *)(param_1 + 0x884) + 10) = 3;
          *(byte *)(*(int *)(param_1 + 0x884) + 0xd) = param_3[9];
          uVar3 = *(ushort *)(param_3 + 10);
          *(ushort *)(*(int *)(param_1 + 0x884) + 0xe) = uVar3;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): ACTIION ID = 3,Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                    );
            }
            else {
              ble_printk("%s(): ACTIION ID = 3,Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                         ,"ble_process_put_req",(uint)uVar3,BLE_DEBUG);
            }
          }
          iVar29 = *(int *)(param_1 + 0x884);
          uVar22 = *(undefined4 *)(param_3 + (uVar34 - 4));
          *(uint *)(iVar29 + 2) =
               (uint)param_3[uVar34 - 6] << 0x10 | (uint)param_3[uVar34 - 7] << 8 |
               (uint)param_3[uVar34 - 8] | (uint)param_3[uVar34 - 5] << 0x18;
          *(undefined4 *)(iVar29 + 6) = uVar22;
          local_128[0] = 0;
          local_128[1] = 0;
          FUN_0004d4f8((longlong *)local_128);
          uVar9 = extraout_r2;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                    );
              uVar9 = extraout_r2_01;
            }
            else {
              ble_printk("%s(): *******************------ received app send timestamp = %lld,current system timestamp = %lld\n"
                         ,"ble_process_put_req",*(undefined4 *)(*(int *)(param_1 + 0x884) + 2),
                         *(undefined4 *)(*(int *)(param_1 + 0x884) + 6));
              uVar9 = extraout_r2_00;
            }
          }
          local_138 = *(uint *)(param_3 + 4);
          bVar11 = puVar24 == &DAT_00000007;
          if (bVar11) {
            uVar9 = 1;
            puVar24 = &DAT_20010f05;
          }
          _local_13c = *(undefined4 *)param_3;
          if (bVar11) {
            *puVar24 = uVar9;
          }
          DAT_2000e0f0 = 0;
          local_134 = param_3[8];
          DAT_2000e0f2 = 0;
          uStack_133 = 0;
          bVar11 = __is_master();
          if (bVar11) {
            send_response_data_to_msgqueue(&local_13c,10);
          }
          else {
            iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
            if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
              if (BLE_DEBUG == 0) {
                printk("%s(): post_to_host failed ret = %d\n");
              }
              else {
                ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                           BLE_DEBUG);
              }
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          DAT_2000e0f0 = uVar4;
          memset(&DAT_20010f06,0,0x217);
          _local_13c = *(undefined4 *)param_3;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
          if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): post_to_host failed ret = %d\n");
            }
            else {
              ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                         BLE_DEBUG);
            }
          }
        }
      }
      else {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ACTION ID = 3,A serious packet order error occurred!\n");
          }
          else {
            ble_printk("%s(): ACTION ID = 3,A serious packet order error occurred!\n",
                       "ble_process_put_req",currentChunk,BLE_DEBUG);
          }
        }
        DAT_2000e0f0 = 0;
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
        memset(&DAT_20010f06,0,0x217);
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 1;
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
      break;
    case (undefined1 *)0x5:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received teleprompter func exit packet ....\n");
        }
        else {
          ble_printk("%s(): received teleprompter func exit packet ....\n","ble_process_put_req",
                     &switchD_0001eae6::switchdataD_0001eaec,BLE_DEBUG);
        }
      }
      bVar11 = __is_master();
      if (bVar11) {
        bVar2 = param_3[3];
        *(byte *)(param_1 + -0x6af) = bVar2;
        FUN_0007f4a4(bVar2,0,0);
        memset(puVar19,0,0x217);
        *(uint *)(param_1 + 0x14) = *(ushort *)((int)puVar31 + 2) + 4;
        FUN_00019d14(param_1,(byte *)local_128,8);
      }
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4));
      iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
      if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): post_to_host failed ret = %d\n");
        }
        else {
          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
        }
      }
    }
    break;
  case 10:
    uVar3 = *(ushort *)(param_3 + 1);
    uVar34 = (uint)uVar3;
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 != currentChunk) {
      if (LOG_LEVEL < 2) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
                   "ble_process_put_req",currentChunk,uVar34);
        return;
      }
      printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
             "ble_process_put_req",currentChunk,uVar34);
      return;
    }
    switch(param_3[4]) {
    case 0:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received navigation func startup  packet ....\n");
        }
        else {
          ble_printk("%s(): received navigation func startup  packet ....\n","ble_process_put_req",
                     currentChunk,BLE_DEBUG);
        }
      }
      pGVar14 = __get_dashboard_state();
      puVar24 = *(undefined1 **)&pGVar14->field_0x1004;
      *(byte *)(param_1 + -0x6af) = param_3[3];
      memset(puVar24,0,0xf5);
      pGVar14 = __get_dashboard_state();
      memset(*(void **)&pGVar14->field_0x1004,0,0xf5);
      puVar24[0xaf] = 0;
      *puVar24 = 1;
      puVar24[0xb0] = param_3[3];
      DAT_20010dc1 = 0;
      DAT_20010dc0 = 0;
      pGVar14 = __get_dashboard_state();
      update_persist_task_status((int)pGVar14,10,2);
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138._0_2_ = (ushort)param_3[4];
      bVar11 = __is_master();
      if (!bVar11) {
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
        if (-1 < iVar29) {
          return;
        }
        if (LOG_LEVEL < 1) {
          return;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
          return;
        }
        printk("%s(): post_to_host failed ret = %d\n");
        return;
      }
      goto LAB_0001f2e6;
    case 1:
      pGVar14 = __get_dashboard_state();
      iVar29 = *(int *)&pGVar14->field_0x1004;
      pGVar14 = __get_dashboard_state();
      pGVar14->field_0xcd = param_3[3];
      *(byte *)(iVar29 + 1) = param_3[5];
      uVar6 = DAT_2000e0e0;
      uVar3 = *(ushort *)(param_3 + 6);
      currentChunk = (uint)uVar3;
      *(ushort *)(iVar29 + 8) = uVar3;
      uVar4 = *(ushort *)(param_3 + 8);
      chunkCount = (uint)uVar4;
      *(ushort *)(iVar29 + 10) = uVar4;
      if ((currentChunk != uVar6) || (chunkCount != DAT_2000e0de)) {
        DAT_20010dbc = 1;
        DAT_2000e0de = uVar4;
        DAT_2000e0e0 = uVar3;
      }
      if (((0x1e8 < currentChunk) || (0x88 < chunkCount)) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): app send x/y parameter overstep!!! x= %d,y= %d\n","ble_process_put_req");
        }
        else {
          ble_printk("%s(): app send x/y parameter overstep!!! x= %d,y= %d\n","ble_process_put_req",
                     currentChunk,chunkCount);
        }
      }
      pbVar27 = param_3 + 9;
      currentChunk = 0;
      do {
        chunkCount = currentChunk;
        if (uVar34 - 10 <= chunkCount) goto LAB_00020be8;
        pbVar27 = pbVar27 + 1;
        currentChunk = chunkCount + 1;
      } while (*pbVar27 != 0);
      if (0x18 < (int)currentChunk) {
LAB_00020be8:
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): TIME_REMAINNING_STRING_SIZE oversize\n");
          }
          else {
            ble_printk("%s(): TIME_REMAINNING_STRING_SIZE oversize\n","ble_process_put_req",
                       uVar34 - 10,BLE_DEBUG);
          }
        }
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(1,param_3[4]);
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        return;
      }
      pvVar13 = (void *)(iVar29 + 0xd);
      memset(pvVar13,0,0x18);
      memcpy(pvVar13,param_3 + 10,currentChunk);
      iVar32 = chunkCount + 10;
      iVar25 = uVar34 - 1;
      pbVar27 = param_3 + iVar32;
      currentChunk = 0;
      do {
        if ((uint)(iVar25 - iVar32) <= currentChunk) goto LAB_00020c78;
        pbVar27 = pbVar27 + 1;
        currentChunk = currentChunk + 1;
      } while (*pbVar27 != 0);
      if (0x18 < (int)currentChunk) {
LAB_00020c78:
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): KILOMETER_REMAINNING_STRING_SIZE oversize\n");
          }
          else {
            ble_printk("%s(): KILOMETER_REMAINNING_STRING_SIZE oversize\n","ble_process_put_req",
                       iVar25 - iVar32,BLE_DEBUG);
          }
        }
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(1,param_3[4]);
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        return;
      }
      buf = (void *)(iVar29 + 0x25);
      memset(buf,0,0x18);
      memcpy(buf,param_3 + chunkCount + 0xb,currentChunk);
      iVar32 = iVar32 + currentChunk;
      pbVar27 = param_3 + iVar32;
      currentChunk = 0;
      do {
        if ((uint)(iVar25 - iVar32) <= currentChunk) goto LAB_00020d02;
        pbVar27 = pbVar27 + 1;
        currentChunk = currentChunk + 1;
      } while (*pbVar27 != 0);
      if (0x40 < (int)currentChunk) {
LAB_00020d02:
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ROAD_NAME_STRING_SIZE oversize\n");
          }
          else {
            ble_printk("%s(): ROAD_NAME_STRING_SIZE oversize\n","ble_process_put_req",
                       iVar25 - iVar32,BLE_DEBUG);
          }
        }
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(1,param_3[4]);
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        return;
      }
      buf_00 = (void *)(iVar29 + 0x3d);
      memset(buf_00,0,0x40);
      memcpy(buf_00,param_3 + iVar32 + 1,currentChunk);
      iVar32 = iVar32 + currentChunk;
      pbVar27 = param_3 + iVar32;
      currentChunk = 0;
      do {
        if ((uint)(iVar25 - iVar32) <= currentChunk) goto LAB_00020d8e;
        pbVar27 = pbVar27 + 1;
        currentChunk = currentChunk + 1;
      } while (*pbVar27 != 0);
      if (0x18 < (int)currentChunk) {
LAB_00020d8e:
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): REMAINING_DISTANCE_STRING_SIZE oversize\n");
          }
          else {
            ble_printk("%s(): REMAINING_DISTANCE_STRING_SIZE oversize\n","ble_process_put_req",
                       iVar25 - iVar32,BLE_DEBUG);
          }
        }
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(1,param_3[4]);
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        return;
      }
      buf_02 = (void *)(iVar29 + 0x7d);
      memset(buf_02,0,0x18);
      iVar33 = currentChunk + iVar32;
      memcpy(buf_02,param_3 + iVar32 + 1,currentChunk);
      iVar32 = LOG_LEVEL;
      pbVar27 = param_3 + iVar33;
      currentChunk = 0;
      do {
        if ((uint)(iVar25 - iVar33) <= currentChunk) goto LAB_00020e12;
        pbVar27 = pbVar27 + 1;
        currentChunk = currentChunk + 1;
      } while (*pbVar27 != 0);
      if (0x18 < (int)currentChunk) {
LAB_00020e12:
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): CURRENT_SPEED_STRING_SIZE oversize\n");
          }
          else {
            ble_printk("%s(): CURRENT_SPEED_STRING_SIZE oversize\n","ble_process_put_req",
                       extraout_r2_31,BLE_DEBUG);
          }
        }
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(1,param_3[4]);
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        return;
      }
      buf_01 = (void *)(iVar29 + 0x95);
      memset(buf_01,0,0x18);
      memcpy(buf_01,param_3 + iVar33 + 1,currentChunk);
      if (2 < iVar32) {
        if (BLE_DEBUG == 0) {
          printk("%s(): direction = %d,x = %d,y = %d,time_remaining = %s,remainning_kilometers = %s,road_name_info = %s,                            remaining_distance_info= %s,current speed = %s\n"
                 ,"ble_process_put_req",(uint)*(byte *)(iVar29 + 1),(uint)*(ushort *)(iVar29 + 8),
                 (uint)*(ushort *)(iVar29 + 10),pvVar13,buf,buf_00,buf_02,buf_01);
        }
        else {
          ble_printk("%s(): direction = %d,x = %d,y = %d,time_remaining = %s,remainning_kilometers = %s,road_name_info = %s,                            remaining_distance_info= %s,current speed = %s\n"
                     ,"ble_process_put_req",(uint)*(byte *)(iVar29 + 1),
                     (uint)*(ushort *)(iVar29 + 8));
        }
      }
      *(undefined1 *)(iVar29 + 6) = 1;
      *(undefined1 *)(iVar29 + 0xaf) = 1;
      *(byte *)(iVar29 + 0xb0) = param_3[3];
      memset((void *)((int)&local_138 + 1),0,0xf);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT31(local_138._1_3_,param_3[4]);
      DAT_20010dbf = 1;
      bVar11 = __is_master();
      if (!bVar11) {
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
        if (-1 < iVar29) {
          return;
        }
        if (LOG_LEVEL < 1) {
          return;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
          return;
        }
        printk("%s(): post_to_host failed ret = %d\n");
        return;
      }
      goto LAB_0001f2e6;
    case 2:
      chunkCount = (uint)*(ushort *)(param_3 + 7);
      uVar4 = *(ushort *)(param_3 + 5);
      currentChunk = (uint)uVar4;
      if (chunkCount == 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): Received multiple initialization packets, currently the first packet of data,total packet = %d\n"
                  );
          }
          else {
            ble_printk("%s(): Received multiple initialization packets, currently the first packet of data,total packet = %d\n"
                       ,"ble_process_put_req",currentChunk,BLE_DEBUG);
          }
        }
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
        DAT_2000e0f0 = uVar4;
        pGVar14 = __get_dashboard_state();
        iVar29 = *(int *)&pGVar14->field_0x1004;
        DAT_20010dc1 = 0;
        FUN_00019cf8(0xffffffff,0xffffffff);
        memset(&DAT_20016b1f,0,0x1210);
        uVar3 = (ushort)(uVar34 - 9);
        memcpy(&DAT_20016b1f,param_3 + 9,uVar34 - 9);
        FUN_00019d08();
        DAT_2000e0f2 = DAT_2000e0f2 + 1;
        DAT_2000e0f4 = uVar3;
        if (currentChunk == 1) {
          DAT_20010dbe = (undefined1)uVar4;
          *(undefined1 *)(iVar29 + 6) = DAT_20010dbe;
          DAT_20010dc1 = DAT_20010dbe;
          *(undefined1 *)(iVar29 + 0xaf) = 2;
          *(byte *)(iVar29 + 0xb0) = param_3[3];
          *(uint *)(iVar29 + 0xb1) = (uint)DAT_2000e0f4;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Successfully received navigation data .Maps are compressed to only one pack!!!\n"
                    );
            }
            else {
              ble_printk("%s(): Successfully received navigation data .Maps are compressed to only one pack!!!\n"
                         ,"ble_process_put_req",1,BLE_DEBUG);
            }
          }
          DAT_2000e0f0 = 0;
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
        }
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 0;
        (**(code **)(param_1 + 0xc))(&local_13c,10);
      }
      else if (chunkCount < currentChunk) {
        if ((uint)DAT_2000e0f2 == chunkCount - 1) {
          if ((DAT_2000e0f4 - 9) + uVar34 < 0x1210) {
            __get_dashboard_state();
            FUN_00019cf8(0xffffffff,0xffffffff);
            memcpy(&DAT_20016b1f + DAT_2000e0f4,param_3 + 9,uVar34 - 9);
            FUN_00019d08();
            DAT_20010dc1 = 0;
            DAT_2000e0f4 = (DAT_2000e0f4 - 9) + uVar3;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Successfully received the subpackage content, the packet sequence is %d,total size = %d\n"
                       ,"ble_process_put_req",chunkCount,(uint)DAT_2000e0f4);
              }
              else {
                ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d,total size = %d\n"
                           ,"ble_process_put_req",chunkCount,(uint)DAT_2000e0f4);
              }
            }
            DAT_2000e0f2 = DAT_2000e0f2 + 1;
          }
          else if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): overview map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                     ,"ble_process_put_req",(uint)DAT_2000e0f4,(DAT_2000e0f4 - 9) + uVar34);
            }
            else {
              ble_printk("%s(): overview map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                         ,"ble_process_put_req",(uint)DAT_2000e0f4,(DAT_2000e0f4 - 9) + uVar34);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          DAT_2000e0f0 = uVar4;
          FUN_00019cf8(0xffffffff,0xffffffff);
          memset(&DAT_20016b1f,0,0x1210);
          FUN_00019d08();
          __get_dashboard_state();
          _local_13c = *(undefined4 *)param_3;
          DAT_20010dc1 = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          (**(code **)(param_1 + 0xc))(&local_13c,10);
        }
      }
      else if (chunkCount == currentChunk) {
        if (((uint)DAT_2000e0f2 == chunkCount - 1) && (chunkCount == DAT_2000e0f0)) {
          if ((DAT_2000e0f4 - 9) + uVar34 < 0x1211) {
            *(byte *)(param_1 + -0x6af) = param_3[3];
            pGVar14 = __get_dashboard_state();
            iVar29 = *(int *)&pGVar14->field_0x1004;
            FUN_00019cf8(0xffffffff,0xffffffff);
            memcpy(&DAT_20016b1f + DAT_2000e0f4,param_3 + 9,uVar34 - 9);
            FUN_00019d08();
            DAT_2000e0f4 = (DAT_2000e0f4 - 9) + uVar3;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Successfully received the last packet,packet length = %d,total packet size = %d\n"
                       ,"ble_process_put_req",chunkCount,(uint)DAT_2000e0f4);
              }
              else {
                ble_printk("%s(): Successfully received the last packet,packet length = %d,total packet size = %d\n"
                           ,"ble_process_put_req",chunkCount,(uint)DAT_2000e0f4);
              }
            }
            *(undefined1 *)(iVar29 + 6) = 1;
            DAT_20010dc1 = 1;
            DAT_20010dbe = 1;
            *(undefined1 *)(iVar29 + 0xaf) = 2;
            *(byte *)(iVar29 + 0xb0) = param_3[3];
            *(uint *)(iVar29 + 0xb1) = (uint)DAT_2000e0f4;
            local_138 = *(uint *)(param_3 + 4);
            _local_13c = *(undefined4 *)param_3;
            DAT_2000e0f0 = 0;
            local_134 = param_3[8];
            DAT_2000e0f2 = 0;
            DAT_2000e0f4 = 0;
            uStack_133 = 0;
            bVar11 = __is_master();
            if (bVar11) {
              send_response_data_to_msgqueue(&local_13c,10);
            }
            else {
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,10);
              if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): post_to_host failed ret = %d\n");
                }
                else {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                }
              }
            }
          }
          else if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): overview map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                     ,"ble_process_put_req",(uint)DAT_2000e0f4,(DAT_2000e0f4 - 9) + uVar34);
            }
            else {
              ble_printk("%s(): overview map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                         ,"ble_process_put_req",(uint)DAT_2000e0f4,(DAT_2000e0f4 - 9) + uVar34);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
            }
          }
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
          DAT_2000e0f0 = uVar4;
          FUN_00019cf8(0xffffffff,0xffffffff);
          memset(&DAT_20016b1f,0,0x1210);
          FUN_00019d08();
          __get_dashboard_state();
          _local_13c = *(undefined4 *)param_3;
          DAT_20010dc1 = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = param_3[8];
          uStack_133 = 1;
          (**(code **)(param_1 + 0xc))(&local_13c,10);
        }
      }
      else {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                   ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
          }
          else {
            ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                       ,"ble_process_put_req",chunkCount,DAT_2000e0f2 + 1);
          }
        }
        DAT_2000e0f2 = 0;
        DAT_2000e0f4 = 0;
        DAT_2000e0f0 = uVar4;
        FUN_00019cf8(0xffffffff,0xffffffff);
        memset(&DAT_20016b1f,0,0x1210);
        FUN_00019d08();
        _local_13c = *(undefined4 *)param_3;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        uStack_133 = 1;
        (**(code **)(param_1 + 0xc))(&local_13c,10);
      }
      break;
    case 3:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received navigation panoramic map data packet ....\n");
        }
        else {
          ble_printk("%s(): received navigation panoramic map data packet ....\n",
                     "ble_process_put_req",currentChunk,BLE_DEBUG);
        }
      }
      currentChunk = (uint)*(ushort *)(param_3 + 7);
      uVar4 = *(ushort *)(param_3 + 5);
      if (currentChunk == 1) {
        sVar21 = uVar34 - 10;
        DAT_2000e0ea = 0;
        DAT_2000e0ec = 0;
        DAT_2000e0e8 = uVar4;
        pGVar14 = __get_dashboard_state();
        DAT_20010dc0 = 0;
        DAT_2001111d = 0;
        *(byte *)(*(int *)&pGVar14->field_0x1004 + 0xad) = param_3[9];
        memset(&DAT_20012a4f,0,0x40d0);
        memcpy(&DAT_20012a4f,param_3 + 10,sVar21);
        DAT_2000e0ec = (ushort)sVar21;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): Successfully received multiple initialization packets, currently the first packet of data,received data size = %d,total packet len = %d\n"
                   ,"ble_process_put_req",sVar21 & 0xffff,(uint)DAT_2000e0e8);
          }
          else {
            ble_printk("%s(): Successfully received multiple initialization packets, currently the first packet of data,received data size = %d,total packet len = %d\n"
                       ,"ble_process_put_req",sVar21 & 0xffff,(uint)DAT_2000e0e8);
          }
        }
        _local_13c = *(undefined4 *)param_3;
        DAT_2000e0ea = DAT_2000e0ea + 1;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = (byte)*(undefined2 *)(param_3 + 8);
        uStack_133 = (undefined1)((ushort)*(undefined2 *)(param_3 + 8) >> 8);
        uStack_132 = 0;
        (**(code **)(param_1 + 0xc))(&local_13c,0xb);
      }
      else if (currentChunk < uVar4) {
        __get_dashboard_state();
        if ((uint)DAT_2000e0ea == currentChunk - 1) {
          if ((DAT_2000e0ec - 10) + uVar34 < 0x40d0) {
            DAT_20010dc0 = 0;
            memcpy(&DAT_20012a4f + DAT_2000e0ec,param_3 + 10,uVar34 - 10);
            DAT_2000e0ec = (DAT_2000e0ec - 10) + uVar3;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Successfully received the subpackage content, the packet sequence is %d,total received size = %d\n"
                       ,"ble_process_put_req",currentChunk,(uint)DAT_2000e0ec);
              }
              else {
                ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d,total received size = %d\n"
                           ,"ble_process_put_req",currentChunk,(uint)DAT_2000e0ec);
              }
            }
            DAT_2000e0ea = DAT_2000e0ea + 1;
          }
          else if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): Panoramic map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                     ,"ble_process_put_req",(uint)DAT_2000e0ec,(DAT_2000e0ec - 10) + uVar34);
            }
            else {
              ble_printk("%s(): Panoramic map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                         ,"ble_process_put_req",(uint)DAT_2000e0ec,(DAT_2000e0ec - 10) + uVar34);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
            }
          }
          DAT_2000e0ea = 0;
          DAT_2000e0ec = 0;
          DAT_2000e0e8 = uVar4;
          memset(&DAT_20012a4f,0,0x40d0);
          _local_13c = *(undefined4 *)param_3;
          DAT_20010dc0 = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = (byte)*(undefined2 *)(param_3 + 8);
          uStack_133 = (undefined1)((ushort)*(undefined2 *)(param_3 + 8) >> 8);
          uStack_132 = 1;
          (**(code **)(param_1 + 0xc))(&local_13c,0xb);
        }
      }
      else if (currentChunk == uVar4) {
        pGVar14 = __get_dashboard_state();
        uVar6 = DAT_2000e0ec;
        iVar29 = *(int *)&pGVar14->field_0x1004;
        if (((uint)DAT_2000e0ea == currentChunk - 1) && (currentChunk == DAT_2000e0e8)) {
          if ((DAT_2000e0ec - 10) + uVar34 < 0x40d1) {
            *(byte *)(param_1 + -0x6af) = param_3[3];
            memcpy(&DAT_20012a4f + uVar6,param_3 + 10,uVar34 - 10);
            DAT_2000e0ec = (DAT_2000e0ec - 10) + uVar3;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Successfully received panoramic map  last packet,Packet id = %d,total received size = %d\n"
                       ,"ble_process_put_req",currentChunk,(uint)DAT_2000e0ec);
              }
              else {
                ble_printk("%s(): Successfully received panoramic map  last packet,Packet id = %d,total received size = %d\n"
                           ,"ble_process_put_req",currentChunk,(uint)DAT_2000e0ec);
              }
            }
            DAT_20010dc0 = 1;
            DAT_20010dbd = 1;
            *(undefined1 *)(iVar29 + 6) = 1;
            *(undefined1 *)(iVar29 + 0xaf) = 3;
            *(byte *)(iVar29 + 0xb0) = param_3[3];
            local_138 = *(uint *)(param_3 + 4);
            DAT_2000e0e8 = 0;
            _local_13c = *(undefined4 *)param_3;
            DAT_2000e0ea = 0;
            DAT_2000e0ec = 0;
            local_134 = (byte)*(undefined2 *)(param_3 + 8);
            uStack_133 = (undefined1)((ushort)*(undefined2 *)(param_3 + 8) >> 8);
            uStack_132 = 0;
            bVar11 = __is_master();
            if (bVar11) {
              send_response_data_to_msgqueue(&local_13c,0xb);
            }
            else {
              iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,0xb);
              if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): post_to_host failed ret = %d\n");
                }
                else {
                  ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                             BLE_DEBUG);
                }
              }
            }
          }
          else if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): Panoramic map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                     ,"ble_process_put_req",(uint)DAT_2000e0ec,(DAT_2000e0ec - 10) + uVar34);
            }
            else {
              ble_printk("%s(): Panoramic map : The data length of the current packet is too long, the current data length %d,wait write data length = %d\n"
                         ,"ble_process_put_req",(uint)DAT_2000e0ec,(DAT_2000e0ec - 10) + uVar34);
            }
          }
        }
        else {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                     ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
            }
            else {
              ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                         ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
            }
          }
          DAT_2000e0ea = 0;
          DAT_2000e0ec = 0;
          DAT_2000e0e8 = uVar4;
          memset(&DAT_20012a4f,0,0x40d0);
          _local_13c = *(undefined4 *)param_3;
          DAT_20010dc0 = 0;
          local_138 = *(uint *)(param_3 + 4);
          local_134 = (byte)*(undefined2 *)(param_3 + 8);
          uStack_133 = (undefined1)((ushort)*(undefined2 *)(param_3 + 8) >> 8);
          uStack_132 = 1;
          (**(code **)(param_1 + 0xc))(&local_13c,0xb);
        }
      }
      else {
        __get_dashboard_state();
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                   ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
          }
          else {
            ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order =%d\n"
                       ,"ble_process_put_req",currentChunk,DAT_2000e0ea + 1);
          }
        }
        DAT_2000e0ea = 0;
        DAT_2000e0ec = 0;
        DAT_2000e0e8 = uVar4;
        memset(&DAT_20012a4f,0,0x40d0);
        _local_13c = *(undefined4 *)param_3;
        DAT_20010dc0 = 0;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = (byte)*(undefined2 *)(param_3 + 8);
        uStack_133 = (undefined1)((ushort)*(undefined2 *)(param_3 + 8) >> 8);
        uStack_132 = 1;
        (**(code **)(param_1 + 0xc))(&local_13c,0xb);
      }
      break;
    case 4:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received app send sync packet ....\n");
        }
        else {
          ble_printk("%s(): received app send sync packet ....\n","ble_process_put_req",currentChunk
                     ,BLE_DEBUG);
        }
      }
      pGVar14 = __get_dashboard_state();
      pcVar30 = *(char **)&pGVar14->field_0x1004;
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4));
      if (*pcVar30 == '\0') {
        local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4)) & 0xffff00ff;
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): navigation don\'t startup, sync packet return\n");
          }
          else {
            ble_printk("%s(): navigation don\'t startup, sync packet return\n","ble_process_put_req"
                       ,extraout_r2_32,BLE_DEBUG);
          }
        }
      }
      else {
        DAT_20007f48 = DAT_20007f48 + 1;
      }
      (**(code **)(param_1 + 0xc))(&local_13c,6);
      break;
    case 5:
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received navigation func exit packet ....\n");
        }
        else {
          ble_printk("%s(): received navigation func exit packet ....\n","ble_process_put_req",
                     currentChunk,BLE_DEBUG);
        }
      }
      pGVar14 = __get_dashboard_state();
      puVar24 = *(undefined1 **)&pGVar14->field_0x1004;
      *(byte *)(param_1 + -0x6af) = param_3[3];
      memset(puVar24 + 1,0,0xf4);
      *puVar24 = 0;
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138._0_2_ = CONCAT11(1,param_3[4]);
      (**(code **)(param_1 + 0xc))(&local_13c,6);
      break;
    case 6:
      pGVar14 = __get_dashboard_state();
      iVar29 = *(int *)&pGVar14->field_0x1004;
      *(byte *)(param_1 + -0x6af) = param_3[3];
      bVar2 = param_3[5];
      *(undefined1 *)(iVar29 + 6) = 1;
      *(byte *)(iVar29 + 0xae) = bVar2;
      *(undefined1 *)(iVar29 + 0xaf) = 6;
      *(byte *)(iVar29 + 0xb0) = param_3[3];
      memset((void *)((int)&local_138 + 2),0,0xe);
      _local_13c = *(undefined4 *)param_3;
      local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4));
      pvVar13 = memset((void *)(iVar29 + 0xb5),0,0x40);
      sVar21 = uVar34 - 6;
      if (sVar21 < 0x40) {
        pvVar13 = memcpy(pvVar13,param_3 + 6,sVar21);
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received arrived status packet. arrived status = %d ,arrived prompt word = %s\n"
                   ,"ble_process_put_req",(uint)bVar2);
          }
          else {
            ble_printk("%s(): received arrived status packet. arrived status = %d ,arrived prompt word = %s\n"
                       ,"ble_process_put_req",(uint)bVar2,pvVar13);
          }
        }
        uVar9 = 0;
      }
      else {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): app send prompt word oversize,drop it...\n");
          }
          else {
            ble_printk("%s(): app send prompt word oversize,drop it...\n","ble_process_put_req",
                       sVar21,BLE_DEBUG);
          }
        }
        uVar9 = 1;
      }
      local_138._0_2_ = CONCAT11(uVar9,(undefined1)local_138);
      bVar11 = __is_master();
      if (!bVar11) {
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
        if (-1 < iVar29) {
          return;
        }
        if (LOG_LEVEL < 1) {
          return;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
          return;
        }
        printk("%s(): post_to_host failed ret = %d\n");
        return;
      }
LAB_0001f2e6:
      send_response_data_to_msgqueue(&local_13c,6);
    }
    break;
  default:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): @tx error put req_type: %d\n");
      }
      else {
        ble_printk("%s(): @tx error put req_type: %d\n","ble_process_put_req",currentChunk,BLE_DEBUG
                  );
      }
    }
    uVar22 = _local_13c;
    _local_13c = CONCAT11(0xca,local_13c);
    bStack_139 = SUB41(uVar22,3);
    _local_13c = CONCAT12(0x15,_local_13c);
    strcpy((char *)((int)&uStack_13b + 1),"error put req.");
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0xd:
    if (*(short *)(param_2 + 2) != 0) {
      memset(&DAT_20010b99,0,0x158);
      if ((uint)param_3[3] == param_3[2] - 1) {
        uVar9 = 0xc9;
      }
      else {
        FUN_0007f472(*(void **)(param_1 + 0x88c),0x1e8,*(undefined1 *)(param_1 + -0x6af),0);
        FUN_0007f4a4(param_3[1],1,0);
        uVar9 = 0xcb;
      }
      _local_13c = CONCAT11(uVar9,local_13c);
      memcpy(&DAT_20010b99,param_3 + 7,*(ushort *)(param_2 + 2) - 7);
    }
    if (param_3[3] == 0) {
      memset((void *)(*(int *)(param_1 + 0x88c) + 6),0,0x1e0);
      iVar29 = *(int *)(param_1 + 0x88c);
      *(undefined1 *)(iVar29 + 0x1e6) = 0;
      *(undefined1 *)(iVar29 + 0x1e7) = 0;
      *(byte *)(*(int *)(param_1 + 0x88c) + 3) = param_3[4];
      *(ushort *)(*(int *)(param_1 + 0x88c) + 4) = (ushort)param_3[6] + (ushort)param_3[5] * 0x100;
    }
    memcpy((void *)(*(int *)(param_1 + 0x88c) + *(ushort *)(*(int *)(param_1 + 0x88c) + 0x1e6) + 6),
           &DAT_20010b99,*(ushort *)(param_2 + 2) - 7);
    *(short *)(*(int *)(param_1 + 0x88c) + 0x1e6) =
         *(short *)(*(int *)(param_1 + 0x88c) + 0x1e6) + *(short *)(param_2 + 2) + -7;
    uVar3 = *(ushort *)(param_2 + 2);
    *(ushort *)((int)puVar31 + 2) = uVar3;
    *(uint *)(param_1 + 0x14) = uVar3 + 4;
    if ((uint)param_3[3] == param_3[2] - 1) {
      FUN_00019d14(param_1,(byte *)local_128,8);
    }
    _local_13c = CONCAT12(param_3[1],_local_13c);
    _local_13c = CONCAT13(param_3[2],_local_13c);
    local_138 = CONCAT31(local_138._1_3_,param_3[3]);
    bVar11 = __is_master();
    bVar2 = param_3[3];
    bVar1 = param_3[2];
    if (bVar11) {
      if ((uint)bVar2 == bVar1 - 1) {
        DAT_20019a69 = 0xd;
        DAT_20019a67 = bVar2;
        DAT_20019a68 = bVar1;
        FUN_0007f4a4(param_3[1],0,0);
      }
      else {
        (**(code **)(param_1 + 0xc))(&local_13c,0x14);
      }
    }
    else {
      if ((uint)bVar2 == bVar1 - 1) {
        FUN_0007f4a4(param_3[1],0,0);
      }
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    }
    break;
  case 0xe:
    if (param_3[1] == 1) {
      bVar11 = __is_idle();
      if ((((((bVar11) ||
             (pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 9)) ||
            (pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 0x10)) ||
           ((pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 0xb ||
            (pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 0x13)))) ||
          ((pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 0x14 ||
           (pGVar14 = __get_dashboard_state(), *(int *)pGVar14->___glasses_state == 0xc)))) ||
         ((pGVar14 = __get_dashboard_state(), pGVar14->field_0xd5 == '\0' &&
          (pGVar14 = __get_dashboard_state(), pGVar14->field_0xfea == '\0')))) {
        pGVar14 = __get_dashboard_state();
        uVar22 = extraout_r2_33;
        if ((*(int *)pGVar14->___glasses_state == 0x10) &&
           (pGVar14 = __get_dashboard_state(), uVar22 = extraout_r2_34,
           **(char **)&pGVar14->field_0x1010 == '\x02')) {
          pGVar14 = __get_dashboard_state();
          uVar22 = 3;
          **(undefined1 **)&pGVar14->field_0x1010 = 3;
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received open dmic command\n");
          }
          else {
            ble_printk("%s(): received open dmic command\n","ble_process_put_req",uVar22,BLE_DEBUG);
          }
        }
        FUN_0008040c();
        goto LAB_00021e38;
      }
      uVar9 = 0xca;
    }
    else {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received close dmic command\n");
        }
        else {
          ble_printk("%s(): received close dmic command\n","ble_process_put_req",currentChunk,
                     BLE_DEBUG);
        }
      }
      FUN_00030458();
LAB_00021e38:
      uVar9 = 0xc9;
    }
    uVar22 = _local_13c;
    _local_13c = CONCAT11(uVar9,local_13c);
    bStack_139 = SUB41(uVar22,3);
    _local_13c = CONCAT12(param_3[1],_local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0xf:
    if (*(short *)(param_2 + 2) != 0) {
      memset(&DAT_20010b99,0,0x158);
      if ((uint)param_3[3] == param_3[2] - 1) {
        uVar9 = 0xc9;
      }
      else {
        FUN_0007f472(*(void **)(param_1 + 0x890),0x1e8,*(undefined1 *)(param_1 + -0x6b0),1);
        FUN_0007f41e(param_3[1],1);
        uVar9 = 0xcb;
      }
      _local_13c = CONCAT11(uVar9,local_13c);
      memcpy(&DAT_20010b99,param_3 + 7,*(ushort *)(param_2 + 2) - 7);
    }
    if (param_3[3] == 0) {
      memset((void *)(*(int *)(param_1 + 0x890) + 6),0,0x1e0);
      iVar29 = *(int *)(param_1 + 0x890);
      *(undefined1 *)(iVar29 + 0x1e6) = 0;
      *(undefined1 *)(iVar29 + 0x1e7) = 0;
      *(byte *)(*(int *)(param_1 + 0x890) + 3) = param_3[4];
      *(ushort *)(*(int *)(param_1 + 0x890) + 4) = (ushort)param_3[6] + (ushort)param_3[5] * 0x100;
    }
    memcpy((void *)(*(int *)(param_1 + 0x890) + *(ushort *)(*(int *)(param_1 + 0x890) + 0x1e6) + 6),
           &DAT_20010b99,*(ushort *)(param_2 + 2) - 7);
    *(short *)(*(int *)(param_1 + 0x890) + 0x1e6) =
         *(short *)(*(int *)(param_1 + 0x890) + 0x1e6) + *(short *)(param_2 + 2) + -7;
    uVar3 = *(ushort *)(param_2 + 2);
    *(ushort *)((int)puVar31 + 2) = uVar3;
    *(uint *)(param_1 + 0x14) = uVar3 + 4;
    if ((uint)param_3[3] == param_3[2] - 1) {
      FUN_00019d14(param_1,(byte *)local_128,8);
    }
    _local_13c = CONCAT12(param_3[1],_local_13c);
    _local_13c = CONCAT13(param_3[2],_local_13c);
    local_138 = CONCAT31(local_138._1_3_,param_3[3]);
    bVar11 = __is_master();
    bVar2 = param_3[3];
    bVar1 = param_3[2];
    if (bVar11) {
      if ((uint)bVar2 == bVar1 - 1) {
        DAT_20019a69 = 0xf;
        DAT_20019a67 = bVar2;
        DAT_20019a68 = bVar1;
        FUN_0007f41e(param_3[1],0);
      }
      else {
        (**(code **)(param_1 + 0xc))(&local_13c,0x14);
      }
    }
    else {
      if ((uint)bVar2 == bVar1 - 1) {
        FUN_0007f41e(param_3[1],0);
      }
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    }
    break;
  case 0x10:
    _local_13c = CONCAT11(6,bVar2);
    _local_13c = (uint3)_local_13c;
    bVar2 = param_3[4];
    _local_13c = CONCAT13(param_3[3],_local_13c);
    local_138 = CONCAT31(uVar7,bVar2);
    if ((*(short *)(param_2 + 2) == *(short *)(param_3 + 1)) && (bVar2 < 3)) {
      if (bVar2 == 1) {
        pGVar14 = __get_dashboard_state();
        if (*(int *)&pGVar14->field_0xf6c != 0) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): ble clear user horiz pitch\n");
            }
            else {
              ble_printk("%s(): ble clear user horiz pitch\n","ble_process_put_req",extraout_r2_02,
                         BLE_DEBUG);
            }
          }
          pGVar14 = __get_dashboard_state();
          *(undefined4 *)&pGVar14->field_0xf6c = 0;
          pGVar14 = __get_dashboard_state();
          *(undefined4 *)&pGVar14->field_0x1060 = 0;
          pGVar14 = __get_dashboard_state();
          k_sem_give(&pGVar14->sem_6);
        }
      }
      else if (bVar2 == 2) {
        if (param_3[5] == 1) {
          pGVar14 = __get_dashboard_state();
          **(undefined1 **)&pGVar14->field_0x1024 = 1;
          pGVar14 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar14->field_0x1024 + 1) = param_3[6];
          pGVar14 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar14->field_0x1024 + 1) == '\x01') {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): ble set user horiz pitch:%d\n");
              }
              else {
                ble_printk("%s(): ble set user horiz pitch:%d\n","ble_process_put_req",DAT_2000848c,
                           BLE_DEBUG);
              }
            }
            pGVar14 = __get_dashboard_state();
            *(undefined4 *)&pGVar14->field_0xf6c = DAT_2000848c;
            pGVar14 = __get_dashboard_state();
            *(undefined4 *)&pGVar14->field_0x1060 = 0;
            pGVar14 = __get_dashboard_state();
            k_sem_give(&pGVar14->sem_6);
          }
          *(byte *)(param_1 + -0x6af) = param_3[3];
          pGVar14 = __get_dashboard_state();
          update_persist_task_status((int)pGVar14,0x11,2);
        }
        else {
          pGVar14 = __get_dashboard_state();
          **(undefined1 **)&pGVar14->field_0x1024 = 0;
        }
      }
      uVar9 = 0xc9;
    }
    else {
      uVar9 = 0xca;
    }
    local_138._0_2_ = CONCAT11(uVar9,(undefined1)local_138);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0x15:
    BIT_MAP_CHUNK_ID = BIT_MAP_CHUNK_ID + 1;
    if (param_3[1] == BIT_MAP_CHUNK_ID) {
      enqueue_file(param_3 + 1,*(ushort *)(param_2 + 2) - 1 & 0xff);
      *(undefined4 *)(param_1 + 0x8e4) = 0x15;
      k_sem_give((k_sem *)(param_1 + -0x6fc));
    }
    else {
      _local_13c = CONCAT11(BIT_MAP_CHUNK_ID,bVar2);
      bStack_139 = SUB41(uVar22,3);
      _local_13c = CONCAT12(0xca,_local_13c);
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
      BIT_MAP_CHUNK_ID = BIT_MAP_CHUNK_ID - 1;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): wrong package id %d\n");
        }
        else {
          ble_printk("%s(): wrong package id %d\n","ble_process_put_req",(uint)BIT_MAP_CHUNK_ID,
                     BLE_DEBUG);
        }
      }
    }
    uVar35 = FUN_0007f436();
    *(undefined8 *)(param_1 + 0x8fc) = uVar35;
    break;
  case 0x16:
    local_128[0] = CONCAT31(CONCAT12(param_3[1],CONCAT11(param_3[2],param_3[3])),param_3[4]);
    _local_13c = CONCAT11(param_3[1],bVar2);
    if (local_128[0] == LAST_FILE_CRC) {
      uVar9 = 0xc9;
    }
    else {
      uVar9 = 0xca;
    }
    _local_13c = CONCAT12(param_3[2],_local_13c);
    _local_13c = CONCAT13(param_3[3],_local_13c);
    local_138._0_2_ = CONCAT11(uVar9,param_3[4]);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    *(uint *)(param_1 + 0x8e4) = (uint)*param_2;
    k_sem_give((k_sem *)(param_1 + -0x6fc));
    break;
  case 0x17:
    setEraseDFU(true);
    uVar35 = FUN_0007f436();
    *(undefined8 *)(param_1 + 0x8fc) = uVar35;
    *(uint *)(param_1 + 0x8e4) = (uint)*param_2;
    k_sem_give((k_sem *)(param_1 + -0x6fc));
    _local_13c = CONCAT11(0xc9,local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0x18:
    _local_13c = CONCAT11(0xc9,bVar2);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    pGVar14 = __get_dashboard_state();
    if ((pGVar14->field_0xd5 == 0xb) ||
       (pGVar14 = __get_dashboard_state(), pGVar14->field_0xd5 == 0x10)) {
      FUN_000800ca(iVar29,0);
    }
    else {
      pGVar14 = __get_dashboard_state();
      if ((*(char *)pGVar14 == '\x02') &&
         (pGVar14 = __get_dashboard_state(), pGVar14->field_0xd5 == '\x06')) {
        sleep(0x32);
      }
      FUN_0007ff66(iVar29,0);
    }
    break;
  case 0x1c:
    if ((param_3[2] != 0) && (param_3[3] != 0)) {
      **(byte **)(param_1 + 0x88c) = param_3[3];
      *(byte *)(*(int *)(param_1 + 0x88c) + 1) = param_3[2];
      **(byte **)(param_1 + 0x890) = param_3[3];
      *(byte *)(*(int *)(param_1 + 0x890) + 1) = param_3[2];
    }
    bVar2 = param_3[1];
    *(byte *)(*(int *)(param_1 + 0x88c) + 2) = bVar2;
    *(byte *)(*(int *)(param_1 + 0x890) + 2) = bVar2;
    FUN_00030484((uint)param_3[1]);
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): received start/Pause command,origin language type = %d,translate origin language type = %d,Suspend status = %d\n"
              );
      }
      else {
        ble_printk("%s(): received start/Pause command,origin language type = %d,translate origin language type = %d,Suspend status = %d\n"
                   ,"ble_process_put_req",(uint)(*(byte **)(param_1 + 0x890))[1],
                   (uint)**(byte **)(param_1 + 0x890));
      }
    }
    _local_13c = CONCAT11(0xc9,local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0x1e:
    uVar3 = *(ushort *)(param_3 + 1);
    uVar34 = (uint)uVar3;
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 == currentChunk) {
      switch(param_3[4]) {
      case 1:
        bVar11 = __is_master();
        if (((bVar11) && (uVar34 == 6)) && (param_3[5] == 1)) {
          requestAudioInfoToApp(0);
        }
        break;
      case 2:
        bVar11 = __is_master();
        if (bVar11) {
          if (uVar34 == 6) {
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received request voice data commmand\n");
              }
              else {
                ble_printk("%s(): received request voice data commmand\n","ble_process_put_req",
                           extraout_r2_22,BLE_DEBUG);
              }
            }
            sendAudioStreamFileToApp(0,param_3[5]);
          }
          else if (uVar34 == 0xb) {
            currentChunk = (uint)param_3[10];
            if (currentChunk == 0) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): received request voice data next data\n");
                }
                else {
                  ble_printk("%s(): received request voice data next data\n","ble_process_put_req",0
                             ,BLE_DEBUG);
                }
              }
            }
            else if (currentChunk == 0xaa) {
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): APP success received audio data ,delete voice block num %d\n");
                }
                else {
                  ble_printk("%s(): APP success received audio data ,delete voice block num %d\n",
                             "ble_process_put_req",(uint)param_3[9],BLE_DEBUG);
                }
              }
              bVar11 = __is_master();
              if (bVar11) {
                currentChunk = (uint)param_3[9];
                if (currentChunk - 1 < 4) {
                  delAudioStreamRecord(param_3[9],extraout_r1,currentChunk);
                }
                else if (1 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): APP delete voice block num error %d\n");
                  }
                  else {
                    ble_printk("%s(): APP delete voice block num error %d\n","ble_process_put_req",
                               currentChunk,BLE_DEBUG);
                  }
                }
              }
            }
            else if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): app return error response information\n");
              }
              else {
                ble_printk("%s(): app return error response information\n","ble_process_put_req",
                           currentChunk,BLE_DEBUG);
              }
            }
          }
        }
        break;
      case 3:
        uVar4 = *(ushort *)(param_3 + 5);
        chunkCount = (uint)uVar4;
        currentChunk = (uint)*(ushort *)(param_3 + 7);
        if (chunkCount == 1) {
          bVar2 = param_3[9];
          bVar1 = param_3[10];
          iVar33 = (bVar2 & 0xf) - 1;
          iVar32 = iVar33 * 0x143;
          iVar29 = iVar32 + 4;
          memset((void *)(*(int *)(param_1 + 0x8b4) + iVar29),0,0x29);
          iVar25 = iVar32 + 0x2d;
          memset((void *)(*(int *)(param_1 + 0x8b4) + iVar25),0,0x119);
          if (bVar1 == 0) {
            *(undefined1 *)(*(int *)(param_1 + 0x8b4) + iVar32 + 3) = 0;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): received empty quick note data ,delete quick note num.%d\n");
              }
              else {
                ble_printk("%s(): received empty quick note data ,delete quick note num.%d\n",
                           "ble_process_put_req",bVar2 & 0xf,BLE_DEBUG);
              }
            }
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 0;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
            deleteQuickNoteData(iVar33,extraout_r1_00,extraout_r2_23);
          }
          else {
            uVar34 = (uint)param_3[0xb];
            currentChunk = uVar34;
            if (0x28 < uVar34) {
              currentChunk = 0x29;
            }
            memcpy((void *)(*(int *)(param_1 + 0x8b4) + iVar29),param_3 + 0xc,currentChunk);
            currentChunk = (uint)*(ushort *)(param_3 + uVar34 + 0xc);
            sVar21 = 0x119;
            if (currentChunk < 0x11a) {
              sVar21 = currentChunk;
            }
            memcpy((void *)(*(int *)(param_1 + 0x8b4) + iVar25),param_3 + uVar34 + 0xe,sVar21);
            uVar22 = extraout_r1_01;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): title length = %d,text length = %d\n","ble_process_put_req",uVar34,
                       currentChunk);
                uVar22 = extraout_r1_04;
              }
              else {
                ble_printk("%s(): title length = %d,text length = %d\n","ble_process_put_req",uVar34
                           ,currentChunk);
                uVar22 = extraout_r1_02;
              }
            }
            uVar18 = 1;
            *(undefined1 *)(iVar33 * 0x143 + *(int *)(param_1 + 0x8b4) + 3) = 1;
            if (2 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): Quick Note Title = %s,TXET = %s\n","ble_process_put_req");
                uVar22 = extraout_r1_05;
                uVar18 = extraout_r2_25;
              }
              else {
                ble_printk("%s(): Quick Note Title = %s,TXET = %s\n","ble_process_put_req",
                           iVar29 + *(int *)(param_1 + 0x8b4),*(int *)(param_1 + 0x8b4) + iVar25);
                uVar22 = extraout_r1_03;
                uVar18 = extraout_r2_24;
              }
            }
            upgradeQuickNoteDataToFlash(iVar33,uVar22,uVar18);
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 0;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
        }
        else if (currentChunk == 1) {
          memset(&DAT_20010dc3,0,0x119);
          memset(&DAT_20010edc,0,0x29);
          DAT_2000e0e6 = 0;
          DAT_20010dc2 = param_3[9];
          DAT_2000e0e4 = 0;
          DAT_2000e0e2 = uVar4;
          *(undefined1 *)((DAT_20010dc2 - 1) * 0x143 + *(int *)(param_1 + 0x8b4) + 3) = 0;
          if ((DAT_20010dc2 < 5) && (DAT_20010dc2 != 0)) {
            chunkCount = (uint)param_3[0xb];
            currentChunk = chunkCount;
            if (0x28 < chunkCount) {
              currentChunk = 0x29;
            }
            memcpy(&DAT_20010edc,param_3 + 0xc,currentChunk);
            currentChunk = (uVar34 - 0xe) - chunkCount;
            uVar34 = currentChunk & 0xffff;
            sVar21 = 0x119;
            if (uVar34 < 0x11a) {
              sVar21 = uVar34;
            }
            memcpy(&DAT_20010dc3 + DAT_2000e0e6,param_3 + chunkCount + 0xe,sVar21);
            DAT_2000e0e6 = (ushort)currentChunk;
            _local_13c = *(undefined4 *)param_3;
            DAT_2000e0e4 = DAT_2000e0e4 + 1;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 0;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
          else {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): app send parameter error,qucik note num = %d\n","ble_process_put_req",
                       (uint)DAT_20010dc2);
              }
              else {
                ble_printk("%s(): app send parameter error,qucik note num = %d\n",
                           "ble_process_put_req",(uint)DAT_20010dc2,&DAT_20010dc2);
              }
            }
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
        }
        else if (currentChunk < chunkCount) {
          if ((uint)DAT_2000e0e4 == currentChunk - 1) {
            memcpy(&DAT_20010dc3 + DAT_2000e0e6,param_3 + 9,uVar34 - 9);
            _local_13c = *(undefined4 *)param_3;
            DAT_2000e0e6 = (DAT_2000e0e6 - 9) + uVar3;
            local_138 = *(uint *)(param_3 + 4);
            DAT_2000e0e4 = DAT_2000e0e4 + 1;
            local_134 = param_3[8];
            uStack_133 = 0;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
          else {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                       ,"ble_process_put_req");
              }
              else {
                ble_printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
            DAT_2000e0e2 = 0;
            DAT_2000e0e4 = 0;
            DAT_2000e0e6 = 0;
            memset(&DAT_20010dc3,0,0x119);
            memset(&DAT_20010edc,0,0x29);
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
        }
        else if (chunkCount == currentChunk) {
          if (((uint)DAT_2000e0e4 == chunkCount - 1) && (DAT_2000e0e2 == chunkCount)) {
            memcpy(&DAT_20010dc3 + DAT_2000e0e6,param_3 + 9,uVar34 - 9);
            DAT_2000e0e6 = (DAT_2000e0e6 - 9) + uVar3;
            memset((void *)((DAT_20010dc2 - 1) * 0x143 + 4 + *(int *)(param_1 + 0x8b4)),0,0x29);
            puVar19 = &DAT_20010edc;
            puVar31 = (undefined4 *)((DAT_20010dc2 - 1) * 0x143 + *(int *)(param_1 + 0x8b4) + 4);
            do {
              puVar20 = puVar19 + 1;
              puVar26 = puVar31 + 1;
              *puVar31 = *puVar19;
              puVar19 = puVar20;
              puVar31 = puVar26;
            } while (puVar20 != (undefined4 *)0x20010f04);
            *(undefined1 *)puVar26 = uRam20010f04;
            memset((void *)((DAT_20010dc2 - 1) * 0x143 + 0x2d + *(int *)(param_1 + 0x8b4)),0,0x119);
            memcpy((void *)((DAT_20010dc2 - 1) * 0x143 + *(int *)(param_1 + 0x8b4) + 0x2d),
                   &DAT_20010dc3,0x119);
            uVar18 = 1;
            *(undefined1 *)((DAT_20010dc2 - 1) * 0x143 + *(int *)(param_1 + 0x8b4) + 3) = 1;
            uVar22 = extraout_r1_06;
            if (2 < LOG_LEVEL) {
              iVar29 = *(int *)(param_1 + 0x8b4);
              if (BLE_DEBUG == 0) {
                printk("%s(): Quick Note Title =%s,QuickNote TXET =%s\n","ble_process_put_req",
                       (DAT_20010dc2 - 1) * 0x143 + iVar29 + 4,
                       (DAT_20010dc2 - 1) * 0x143 + iVar29 + 0x2d);
                uVar22 = extraout_r1_08;
                uVar18 = extraout_r2_27;
              }
              else {
                ble_printk("%s(): Quick Note Title =%s,QuickNote TXET =%s\n","ble_process_put_req",
                           (DAT_20010dc2 - 1) * 0x143 + iVar29 + 4,
                           (DAT_20010dc2 - 1) * 0x143 + iVar29 + 0x2d);
                uVar22 = extraout_r1_07;
                uVar18 = extraout_r2_26;
              }
            }
            upgradeQuickNoteDataToFlash(DAT_20010dc2 - 1,uVar22,uVar18);
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 0;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
            DAT_2000e0e6 = 0;
            DAT_2000e0e4 = 0;
            DAT_2000e0e2 = 0;
          }
          else {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                       ,"ble_process_put_req");
              }
              else {
                ble_printk("%s(): ACTION ID = 3,There is a packet order error, current packet order = %d, expected packet order =%d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
            memset(&DAT_20010dc3,0,0x119);
            memset(&DAT_20010edc,0,0x29);
            DAT_2000e0e6 = 0;
            DAT_2000e0e4 = 0;
            DAT_2000e0e2 = 0;
            _local_13c = *(undefined4 *)param_3;
            local_138 = *(uint *)(param_3 + 4);
            local_134 = param_3[8];
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,10);
          }
        }
        break;
      case 4:
        currentChunk = (uint)param_3[5];
        if (currentChunk < 5) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): delete audio record num = %d\n");
            }
            else {
              ble_printk("%s(): delete audio record num = %d\n","ble_process_put_req",
                         currentChunk - 1,BLE_DEBUG);
            }
          }
          bVar11 = __is_master();
          if (bVar11) {
            delAudioStreamRecord(param_3[5],extraout_r1_09,extraout_r2_28);
          }
          _local_13c = *(undefined4 *)param_3;
          local_138._0_2_ = (ushort)param_3[4];
          (**(code **)(param_1 + 0xc))(&local_13c,6);
        }
        else {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received delete all quick note audio file command .\n");
            }
            else {
              ble_printk("%s(): received delete all quick note audio file command .\n",
                         "ble_process_put_req",currentChunk,BLE_DEBUG);
            }
          }
          bVar11 = __is_master();
          if (bVar11) {
            delAudioStreamRecord(0xff,extraout_r1_10,extraout_r2_29);
          }
          _local_13c = *(undefined4 *)param_3;
          local_138._0_2_ = (ushort)param_3[4];
          (**(code **)(param_1 + 0xc))(&local_13c,6);
        }
        break;
      case 5:
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received clean audio voice command\n");
          }
          else {
            ble_printk("%s(): received clean audio voice command\n","ble_process_put_req",
                       &switchD_0001fd36::switchdataD_0001fd3c,BLE_DEBUG);
          }
        }
        bVar11 = __is_master();
        if (bVar11) {
          delAudioStreamRecord(0xff,extraout_r1_11,extraout_r2_30);
          _local_13c = *(undefined4 *)param_3;
          local_138._0_2_ = (ushort)param_3[4];
          (**(code **)(param_1 + 0xc))(&local_13c,6);
        }
        break;
      case 7:
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = (ushort)param_3[4];
        FUN_0003d7b4();
        if (param_3[5] == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 1) = 1;
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 2) = 1;
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 3) = 7;
          memset((void *)(*(int *)(param_1 + 0x8b8) + 8),0,0x14a);
          update_persist_task_status(iVar29,0xc,2);
          FUN_0007f4a4(param_3[3],0,0);
        }
        else {
          local_138._0_2_ = CONCAT11(1,(undefined1)local_138);
        }
        (**(code **)(param_1 + 0xc))(&local_13c,6);
        break;
      case 8:
        FUN_0003d7b4();
        iVar29 = LOG_LEVEL;
        local_138 = *(uint *)(param_3 + 4);
        local_134 = param_3[8];
        local_13c = (undefined1)*(undefined4 *)param_3;
        _local_13c = CONCAT11(10,local_13c);
        uVar4 = *(ushort *)(param_3 + 5);
        chunkCount = (uint)uVar4;
        currentChunk = (uint)*(ushort *)(param_3 + 7);
        bStack_139 = (byte)((uint)*(undefined4 *)param_3 >> 0x18);
        _local_13c = (uint3)_local_13c;
        uStack_133 = 0;
        if (chunkCount == 1) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): received quick note packet,total packet = 1\n");
            }
            else {
              ble_printk("%s(): received quick note packet,total packet = 1\n","ble_process_put_req"
                         ,(uint)local_134,BLE_DEBUG);
            }
          }
          uVar34 = uVar34 - 0xb;
          if (0x14a < uVar34) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): quick note data is too long, the current data length 0,wait write data length = %d\n"
                      );
              }
              else {
                ble_printk("%s(): quick note data is too long, the current data length 0,wait write data length = %d\n"
                           ,"ble_process_put_req",uVar34,BLE_DEBUG);
              }
            }
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
            return;
          }
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 3) = 8;
          pGVar14 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar14->field_0x1034 + 4) = param_3[9];
          pGVar14 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar14->field_0x1034 + 5) = param_3[10];
          pGVar14 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar14->field_0x1034 + 4) == '\0') {
            memset(&DAT_20010b99,0,0x158);
            pGVar14 = __get_dashboard_state();
            memset((void *)(*(int *)&pGVar14->field_0x1034 + 8),0,0x14a);
            pGVar14 = __get_dashboard_state();
            *(short *)(*(int *)&pGVar14->field_0x1034 + 6) = (short)uVar34;
            pGVar14 = __get_dashboard_state();
            iVar29 = *(int *)&pGVar14->field_0x1034;
            pGVar14 = __get_dashboard_state();
            memcpy((void *)(iVar29 + 8),param_3 + 0xb,
                   (uint)*(ushort *)(*(int *)&pGVar14->field_0x1034 + 6));
          }
          else {
            display_DelayClose(10000);
          }
          FUN_0007f4a4(param_3[3],0,0);
        }
        else if (currentChunk == 1) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Received quick note multiple packets, currently the first packet of data\n"
                    );
            }
            else {
              ble_printk("%s(): Received quick note multiple packets, currently the first packet of data\n"
                         ,"ble_process_put_req",(uint)local_134,BLE_DEBUG);
            }
          }
          DAT_2000e0f2 = 1;
          DAT_2000e0f0 = uVar4;
          memset(&DAT_20010b99,0,0x158);
          memcpy(&DAT_20010b99,param_3 + 0xb,uVar34 - 0xb);
          DAT_2000e0f4 = (ushort)(uVar34 - 0xb);
        }
        else if (currentChunk < chunkCount) {
          if ((uint)DAT_2000e0f2 != currentChunk - 1) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                       ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
              else {
                ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
            DAT_2000e0f2 = 0;
            DAT_2000e0f4 = 0;
            DAT_2000e0f0 = uVar4;
            memset(&DAT_20010b99,0,0x158);
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
            return;
          }
          if (0x14a < (DAT_2000e0f4 - 0xb) + uVar34) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note data is too long, the current data length %d,wait write data length = %d\n"
                       ,"ble_process_put_req",(uint)DAT_2000e0f4);
              }
              else {
                ble_printk("%s(): quick note data is too long, the current data length %d,wait write data length = %d\n"
                           ,"ble_process_put_req",(uint)DAT_2000e0f4,uVar34 - 0xb);
              }
            }
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
            return;
          }
          memcpy(&DAT_20010b99 + DAT_2000e0f4,param_3 + 0xb,uVar34 - 0xb);
          DAT_2000e0f4 = (DAT_2000e0f4 - 0xb) + uVar3;
          if (2 < iVar29) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                    );
            }
            else {
              ble_printk("%s(): Successfully received the subpackage content, the packet sequence is %d\n"
                         ,"ble_process_put_req",currentChunk,BLE_DEBUG);
            }
          }
          DAT_2000e0f2 = DAT_2000e0f2 + 1;
        }
        else if (currentChunk == chunkCount) {
          if (((uint)DAT_2000e0f2 != currentChunk - 1) || (currentChunk != DAT_2000e0f0)) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                       ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
              else {
                ble_printk("%s(): There is a packet order error, current packet order = %d, expected packet order = %d\n"
                           ,"ble_process_put_req",currentChunk,DAT_2000e0f2 + 1);
              }
            }
            DAT_2000e0f2 = 0;
            DAT_2000e0f0 = uVar4;
            memset(&DAT_20010b99,0,0x158);
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
            return;
          }
          if (0x14a < (DAT_2000e0f4 - 0xb) + uVar34) {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): quick note data is too long, the current data length %d,wait write data length = %d\n"
                       ,"ble_process_put_req",(uint)DAT_2000e0f4);
              }
              else {
                ble_printk("%s(): quick note data is too long, the current data length %d,wait write data length = %d\n"
                           ,"ble_process_put_req",(uint)DAT_2000e0f4,uVar34 - 0xb);
              }
            }
            uStack_133 = 1;
            (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
            return;
          }
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                    );
            }
            else {
              ble_printk("%s(): Successfully assembled multiple packages of data, and updated the complete content to the UI thread for data update.\n"
                         ,"ble_process_put_req",LOG_LEVEL,BLE_DEBUG);
            }
          }
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 3) = 8;
          pGVar14 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar14->field_0x1034 + 4) = param_3[9];
          pGVar14 = __get_dashboard_state();
          *(byte *)(*(int *)&pGVar14->field_0x1034 + 5) = param_3[10];
          pGVar14 = __get_dashboard_state();
          if (*(char *)(*(int *)&pGVar14->field_0x1034 + 4) == '\0') {
            memcpy(&DAT_20010b99 + DAT_2000e0f4,param_3 + 0xb,uVar34 - 0xb);
            DAT_2000e0f4 = uVar3 + (DAT_2000e0f4 - 0xb);
            pGVar14 = __get_dashboard_state();
            memset((void *)(*(int *)&pGVar14->field_0x1034 + 8),0,0x14a);
            pGVar14 = __get_dashboard_state();
            memcpy((void *)(*(int *)&pGVar14->field_0x1034 + 8),&DAT_20010b99,(uint)DAT_2000e0f4);
            pGVar14 = __get_dashboard_state();
            *(ushort *)(*(int *)&pGVar14->field_0x1034 + 6) = DAT_2000e0f4;
          }
          else {
            display_DelayClose(10000);
          }
          FUN_0007f4a4(param_3[3],0,0);
          DAT_2000e0f0 = 0;
          DAT_2000e0f2 = 0;
          DAT_2000e0f4 = 0;
        }
        (**(code **)(param_1 + 0xc))(&local_13c,uStack_13b);
        break;
      case 9:
        FUN_0003d7b4();
        uVar22 = local_138;
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = CONCAT11(*(char *)(*(int *)(param_1 + 0x8b8) + 1) != '\x01',param_3[4]);
        local_138._3_1_ = SUB41(uVar22,3);
        local_138._0_3_ = CONCAT12(param_3[5],(ushort)local_138);
        (**(code **)(param_1 + 0xc))(&local_13c,7);
        break;
      case 10:
        _local_13c = *(undefined4 *)param_3;
        local_138._0_2_ = (ushort)param_3[4];
        if (param_3[5] < 3) {
          FUN_0003d7b4();
          if (*(char *)(param_1 + -0x6a7) != '\f') {
            *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 1) = 1;
            *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 2) = 1;
            pGVar14 = __get_dashboard_state();
            memset((void *)(*(int *)&pGVar14->field_0x1034 + 8),0,0x14a);
            update_persist_task_status(iVar29,0xc,2);
          }
          *(undefined1 *)(*(int *)(param_1 + 0x8b8) + 3) = 10;
          *(byte *)(*(int *)(param_1 + 0x8b8) + 4) = param_3[5];
          FUN_0007f4a4(param_3[3],0,0);
        }
        else {
          local_138._0_2_ = CONCAT11(1,param_3[4]);
        }
        (**(code **)(param_1 + 0xc))(&local_13c,6);
      }
    }
    else if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
               "ble_process_put_req",currentChunk,uVar34);
      }
      else {
        ble_printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
                   "ble_process_put_req",currentChunk,uVar34);
      }
    }
    break;
  case 0x1f:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received onboarding init packet ....\n");
      }
      else {
        ble_printk("%s(): received onboarding init packet ....\n","ble_process_put_req",currentChunk
                   ,BLE_DEBUG);
      }
    }
    currentChunk = onboarding_ble_process
                             (iVar29,(int)param_2,(undefined2 *)param_3,(undefined2 *)&local_13c);
    if (0 < (int)currentChunk) {
      memcpy(puVar19,param_3,(uint)*(ushort *)(param_2 + 2));
      iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,currentChunk & 0xffff);
      if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): onboarding post_to_host failed ret = %d\n");
        }
        else {
          ble_printk("%s(): onboarding post_to_host failed ret = %d\n","ble_process_put_req",iVar29,
                     BLE_DEBUG);
        }
      }
    }
    break;
  case 0x20:
    if (((*(ushort *)(param_2 + 2) < 0x15) && (param_3[1] == 0xd)) && (param_3[2] == 0xe)) {
      enqueue_file(param_3 + 1,*(ushort *)(param_2 + 2) - 1 & 0xff);
      *(undefined4 *)(param_1 + 0x8e4) = 0x20;
      k_sem_give((k_sem *)(param_1 + -0x6fc));
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): recv upgrade font success\n");
        }
        else {
          ble_printk("%s(): recv upgrade font success\n","ble_process_put_req",extraout_r2_35,
                     BLE_DEBUG);
        }
      }
      _local_13c = CONCAT11(0xc9,local_13c);
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    }
    else {
      _local_13c = CONCAT11(0xca,bVar2);
      (**(code **)(param_1 + 0xc))(&local_13c,0x14);
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): recv upgrade font failed\n");
        }
        else {
          ble_printk("%s(): recv upgrade font failed\n","ble_process_put_req",extraout_r2_36,
                     BLE_DEBUG);
        }
      }
    }
    BIT_MAP_CHUNK_ID = 0xff;
    break;
  case 0x22:
    if ((uint)*(ushort *)(param_3 + 1) == (uint)*(ushort *)(param_2 + 2)) {
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): received sync id = %d\n");
        }
        else {
          ble_printk("%s(): received sync id = %d\n","ble_process_put_req",(uint)param_3[3],
                     BLE_DEBUG);
        }
      }
      if (param_3[4] == 1) {
        local_134 = 0;
        uStack_133 = 0;
        uStack_132 = 0;
        uStack_131 = 0;
        uStack_130 = 0;
        uStack_12f = 0;
        uStack_12e = 0;
        uStack_12c = 0;
        uStack_12b = 0;
        local_12a = 0;
        _local_13c = *(undefined4 *)param_3;
        local_138._2_2_ = (undefined2)((uint)*(undefined4 *)(param_3 + 4) >> 0x10);
        local_138._0_1_ = (undefined1)*(undefined4 *)(param_3 + 4);
        local_138._0_2_ = CONCAT11(*(undefined1 *)(param_1 + -0x69f),(undefined1)local_138);
        cVar10 = FUN_00038ac8();
        local_138._0_3_ = CONCAT12(cVar10 + '\x01',(ushort)local_138);
        local_138 = CONCAT13(*(undefined1 *)(*(int *)(param_1 + 0x874) + 0x60),(undefined3)local_138
                            );
        (**(code **)(param_1 + 0xc))(&local_13c,8);
      }
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): dashboard information packet length error,input data length = %d,packet data length = %d\n"
               ,"ble_process_put_req");
      }
      else {
        ble_printk("%s(): dashboard information packet length error,input data length = %d,packet data length = %d\n"
                   ,"ble_process_put_req",(uint)*(ushort *)(param_2 + 2),
                   (uint)*(ushort *)(param_3 + 1));
      }
    }
    break;
  case 0x24:
    uVar34 = (uint)*(ushort *)(param_3 + 1);
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (uVar34 != currentChunk) {
      if (LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
                   ,"ble_process_put_req",currentChunk,uVar34);
        return;
      }
      printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
             ,"ble_process_put_req",currentChunk,uVar34);
      return;
    }
    if (param_3[4] != 6) {
      return;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received teleprompter suspend packet ....\n");
      }
      else {
        ble_printk("%s(): received teleprompter suspend packet ....\n","ble_process_put_req",
                   currentChunk,BLE_DEBUG);
      }
    }
    bVar2 = param_3[3];
    *(byte *)(param_1 + -0x6af) = bVar2;
    FUN_0007f4a4(bVar2,0,0);
    *(bool *)(*(int *)(param_1 + 0x884) + 0x10) = param_3[5] == 1;
    iVar29 = *(int *)(param_1 + 0x884);
    uVar22 = *(undefined4 *)(param_3 + (uVar34 - 8));
    *(uint *)(iVar29 + 2) =
         (uint)param_3[uVar34 - 10] << 0x10 | (uint)param_3[uVar34 - 0xb] << 8 |
         (uint)param_3[uVar34 - 0xc] | (uint)param_3[uVar34 - 9] << 0x18;
    *(undefined4 *)(iVar29 + 6) = uVar22;
    *(uint *)(*(int *)(param_1 + 0x884) + 0x11) =
         (uint)param_3[uVar34 - 2] << 0x10 | (uint)param_3[uVar34 - 3] << 8 |
         (uint)param_3[uVar34 - 4] | (uint)param_3[uVar34 - 1] << 0x18;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): SUSPEND status ,app send counter time = %d\n");
      }
      else {
        ble_printk("%s(): SUSPEND status ,app send counter time = %d\n","ble_process_put_req",
                   *(undefined4 *)(*(int *)(param_1 + 0x884) + 0x11),BLE_DEBUG);
      }
    }
    *(uint *)(param_1 + 0x14) = *(ushort *)((int)puVar31 + 2) + 4;
    memset((void *)((int)&local_138 + 2),0,0xe);
    _local_13c = *(undefined4 *)param_3;
    local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4));
    bVar11 = __is_master();
    if (!bVar11) {
      iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
      if (-1 < iVar29) {
        return;
      }
      if (LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG);
        return;
      }
      printk("%s(): post_to_host failed ret = %d\n");
      return;
    }
    goto LAB_0001f2e6;
  case 0x25:
    currentChunk = (uint)*(ushort *)(param_2 + 2);
    if (*(ushort *)(param_3 + 1) == currentChunk) {
      if (param_3[4] == 4) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received app send sync packet ....\n");
          }
          else {
            ble_printk("%s(): received app send sync packet ....\n","ble_process_put_req",
                       currentChunk,BLE_DEBUG);
          }
        }
        DAT_20007f44 = DAT_20007f44 + 1;
        *(uint *)(param_1 + 0x14) = *(ushort *)((int)puVar31 + 2) + 4;
        memset((void *)((int)&local_138 + 2),0,0xe);
        _local_13c = *(undefined4 *)param_3;
        local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)(param_3 + 4));
        iVar29 = (**(code **)(param_1 + 0xc))(&local_13c,6);
        if ((iVar29 < 0) && (0 < LOG_LEVEL)) {
          if (BLE_DEBUG == 0) {
            printk("%s(): post_to_host failed ret = %d\n");
          }
          else {
            ble_printk("%s(): post_to_host failed ret = %d\n","ble_process_put_req",iVar29,BLE_DEBUG
                      );
          }
        }
      }
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
               ,"ble_process_put_req");
      }
      else {
        ble_printk("%s(): teleprompter packet length error,input data length = %d,packet data length = %d\n"
                   ,"ble_process_put_req",currentChunk,(uint)*(ushort *)(param_3 + 1));
      }
    }
    break;
  case 0x26:
    _local_13c = CONCAT11(6,bVar2);
    bVar2 = param_3[4];
    _local_13c = (uint3)_local_13c;
    _local_13c = CONCAT13(param_3[3],_local_13c);
    local_138 = CONCAT31(uVar7,bVar2);
    if ((*(short *)(param_2 + 2) == *(short *)(param_3 + 1)) && (bVar2 < 9)) {
      currentChunk = 0xc9;
      local_138._0_2_ = CONCAT11(0xc9,bVar2);
      local_138 = CONCAT22(uVar8,(ushort)local_138);
      switch(bVar2) {
      case 1:
        *(undefined1 *)(param_1 + 0x959) = 1;
        break;
      case 2:
        if ((8 < param_3[6]) || (9 < param_3[7])) goto switchD_00022248_default;
        *(byte *)(param_1 + -0x6af) = param_3[3];
        memcpy(puVar19,param_3,(uint)*(ushort *)(param_2 + 2));
        FUN_00019d14(param_1,(byte *)local_128,8);
        break;
      case 3:
        cVar10 = FUN_00033d5c();
        if (cVar10 == '\x01') {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): give mic_transm_sem\n");
            }
            else {
              ble_printk("%s(): give mic_transm_sem\n","ble_process_put_req",extraout_r2_37,
                         BLE_DEBUG);
            }
          }
          sem = (k_sem *)&DAT_200085b4;
LAB_000222dc:
          k_sem_give(sem);
        }
        break;
      case 4:
        bVar2 = param_3[5];
        currentChunk = (uint)bVar2;
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ble set lum gear:%d\n");
          }
          else {
            ble_printk("%s(): ble set lum gear:%d\n","ble_process_put_req",currentChunk,BLE_DEBUG);
          }
        }
        if (0x3f < currentChunk) goto switchD_00022248_default;
        if (*(ushort *)(param_1 + 0x762) != currentChunk) {
          *(ushort *)(param_1 + 0x762) = (ushort)bVar2;
          *(ushort *)(param_1 + 0x75c) = (ushort)bVar2;
          sem = (k_sem *)(param_1 + -0x6fc);
          *(uint *)(param_1 + 0x8e4) = (uint)*param_2;
          DAT_20017d2f = 1;
          goto LAB_000222dc;
        }
        break;
      case 5:
        bVar2 = param_3[5];
        if (5 < bVar2) goto switchD_00022248_default;
        if (*(byte *)(param_1 + 0xac8) != bVar2) {
          SendDoubleTapCustomizeToSlave(bVar2);
        }
        break;
      case 6:
        bVar2 = param_3[5];
        if (bVar2 != 1) {
          if (bVar2 == 2) {
            bVar2 = param_3[6];
            uVar34 = (uint)bVar2;
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): ble set lum coeffic:%d\n");
                currentChunk = extraout_r1_13;
              }
              else {
                ble_printk("%s(): ble set lum coeffic:%d\n","ble_process_put_req",uVar34,BLE_DEBUG);
                currentChunk = extraout_r1_12;
              }
            }
            if ((*(char *)(*(int *)(param_1 + 0x874) + 0x72) == '\x01') && (uVar34 - 0x46 < 0x1f)) {
              if (*(byte *)(param_1 + 0x764) != uVar34) {
                *(byte *)(param_1 + 0x764) = bVar2;
                set_brightness_to_panel_reg_in_running
                          ((uint)*(byte *)(param_1 + 0x759),currentChunk);
                FUN_00025b28(0,0);
              }
              break;
            }
          }
          else if (bVar2 == 0) goto LAB_00022350;
          goto switchD_00022248_default;
        }
LAB_00022350:
        *(byte *)(*(int *)(param_1 + 0x874) + 0x72) = bVar2;
        break;
      case 7:
        bVar2 = param_3[5];
        if (1 < bVar2) goto switchD_00022248_default;
        if (*(byte *)(param_1 + 0xaca) != bVar2) {
          SendLongpressTapCustomizeToSlave(bVar2);
        }
        break;
      case 8:
        *(bool *)(param_1 + 0xacb) = param_3[5] == 1;
        break;
      default:
        goto switchD_00022248_default;
      }
    }
    else {
switchD_00022248_default:
      local_138._0_2_ = CONCAT11(0xca,(undefined1)local_138);
    }
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
    break;
  case 0x27:
    *(byte *)(param_1 + 0x958) = param_3[1];
    *(undefined4 *)(param_1 + 0x8e4) = 0x27;
    k_sem_give((k_sem *)(param_1 + -0x6fc));
    _local_13c = CONCAT11(0xc9,local_13c);
    (**(code **)(param_1 + 0xc))(&local_13c,0x14);
  }
  return;
}



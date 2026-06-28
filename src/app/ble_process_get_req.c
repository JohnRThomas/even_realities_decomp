/*
 * Function: ble_process_get_req
 * Entry:    0001a284
 * Prototype: undefined __stdcall ble_process_get_req(int param_1, byte * param_2, undefined4 * param_3)
 */


void ble_process_get_req(int param_1,byte *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 uVar3;
  bool bVar4;
  undefined4 uVar5;
  char *pcVar6;
  GlassesState *pGVar7;
  undefined4 uVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined4 extraout_r2;
  uint uVar12;
  code *pcVar13;
  byte *pbVar14;
  byte local_288 [240];
  uint local_198;
  uint local_194;
  uint local_190;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  uint local_178;
  uint local_174;
  uint uStack_170;
  uint local_168;
  uint local_164;
  byte local_15c;
  byte bStack_15b;
  byte bStack_15a;
  byte bStack_159;
  byte local_158;
  byte bStack_157;
  undefined1 local_156 [6];
  undefined2 local_150;
  undefined2 local_14e;
  undefined2 local_14c;
  byte local_14a;
  undefined4 local_144;
  undefined2 local_140;
  uint local_13e;
  undefined2 local_13a;
  undefined2 local_138;
  undefined2 local_136;
  byte local_134 [272];
  
  local_15c = 0;
  bStack_15b = 0;
  bStack_15a = 0;
  bStack_159 = 0;
  memset(&local_158,0,0x11);
  **(undefined4 **)(param_1 + 0x10) = *(undefined4 *)param_2;
  *(uint *)(param_1 + 0x14) = (uint)*(ushort *)(param_2 + 2);
  local_15c = *param_2;
  uVar9 = (uint)local_15c;
  switch(uVar9) {
  case 0x29:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    uVar9 = 0x65;
    bStack_15b = 0x65;
    bStack_15a = (byte)local_144;
    bStack_159 = local_144._1_1_;
    if (2 < LOG_LEVEL) {
      pcVar6 = "%s(): BLE_REQ_GET_BRIGHTNESS: 0x%02x,0x%02x,0x%02x,0x%02x,\n";
      bVar2 = local_15c;
      local_194 = (uint)local_144._1_1_;
LAB_0001a336:
      local_198 = local_144 & 0xff;
      if (BLE_DEBUG == 0) {
        printk(pcVar6);
      }
      else {
        ble_printk(pcVar6,"ble_process_get_req",(uint)bVar2,uVar9);
      }
    }
    break;
  case 0x2a:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    uVar12 = 0x68;
    bStack_15b = 0x68;
    bStack_15a = (byte)local_144;
    if (2 < LOG_LEVEL) {
      uVar9 = (uint)local_15c;
      if (BLE_DEBUG != 0) {
        pcVar6 = "%s(): BLE_REQ_GET_ANTI_SHAKE_ENABLE: 0x%02x,0x%02x,\n";
        goto LAB_0001a520;
      }
      pcVar6 = "%s(): BLE_REQ_GET_ANTI_SHAKE_ENABLE: 0x%02x,0x%02x,\n";
LAB_0001a52a:
      printk(pcVar6,"ble_process_get_req");
    }
    break;
  case 0x2b:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    uVar12 = 0x69;
    bStack_15b = 0x69;
    bStack_15a = (byte)local_144;
    bStack_159 = (byte)(local_144 >> 8);
    if (2 < LOG_LEVEL) {
      uVar9 = (uint)local_15c;
      if (BLE_DEBUG == 0) {
        pcVar6 = "%s(): BLE_REQ_GET_DISPLAY_MODE: 0x%02x,0x%02x,\n";
        goto LAB_0001a52a;
      }
      pcVar6 = "%s(): BLE_REQ_GET_DISPLAY_MODE: 0x%02x,0x%02x,\n";
LAB_0001a520:
      ble_printk(pcVar6,"ble_process_get_req",uVar9,uVar12);
    }
    break;
  case 0x2c:
    if (*(char *)((int)param_3 + 1) == '\x01') {
      *(undefined1 *)(param_1 + 0x904) = 0;
    }
    else if (*(char *)((int)param_3 + 1) == '\x02') {
      *(undefined1 *)(param_1 + 0x904) = 1;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        pcVar6 = "IOS";
        if (*(char *)(param_1 + 0x904) == '\0') {
          pcVar6 = "Android";
        }
        printk("%s(): %s mobile phone is connected,raw_data[1] = %d\n","ble_process_get_req",pcVar6)
        ;
      }
      else {
        pcVar6 = "IOS";
        if (*(char *)(param_1 + 0x904) == '\0') {
          pcVar6 = "Android";
        }
        ble_printk("%s(): %s mobile phone is connected,raw_data[1] = %d\n","ble_process_get_req",
                   pcVar6,(uint)*(byte *)((int)param_3 + 1));
      }
    }
    FUN_00019d14(param_1,(byte *)&local_144,0x18);
    local_164 = local_144 >> 0x10 & 0xff;
    bStack_15a = (byte)local_144;
    bStack_159 = (byte)(local_144 >> 8);
    local_158 = (byte)(local_144 >> 0x10);
    bStack_157 = (byte)(local_144 >> 0x18);
    local_168 = (uint)(byte)local_13a;
    local_156._0_2_ = local_140;
    local_156._2_4_ = local_13e;
    bStack_15b = 0x66;
    local_150 = local_13a;
    local_14e = local_138;
    local_14c = local_136;
    uVar9 = local_13e >> 8 & 0xff;
    uVar12 = local_13e >> 0x10 & 0xff;
    local_14a = local_134[0];
    if (2 < LOG_LEVEL) {
      local_198 = local_164;
      local_194 = local_144 >> 0x18;
      local_190 = (uint)(byte)local_140;
      local_18c = (uint)local_140._1_1_;
      local_188 = local_13e & 0xff;
      local_184 = uVar9;
      local_180 = uVar12;
      local_17c = local_13e >> 0x18;
      local_178 = local_168;
      local_174 = (uint)local_136._1_1_;
      uStack_170 = (uint)local_134[0];
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): BLE_REQ_GET_DEVICE_INFO: CHG:0x%02x,0x%02x,0x%02x,0x%02x,0x%02x M_SW_VER:v%d.%d.%d S_SW_VER:v%d.%d.%d BLE_SW_VER:v%d.%d\n"
              );
      }
      else {
        ble_printk("%s(): BLE_REQ_GET_DEVICE_INFO: CHG:0x%02x,0x%02x,0x%02x,0x%02x,0x%02x M_SW_VER:v%d.%d.%d S_SW_VER:v%d.%d.%d BLE_SW_VER:v%d.%d\n"
                   ,"ble_process_get_req",local_144 & 0xff,(uint)bStack_159);
      }
    }
    break;
  case 0x2d:
    FUN_00019d14(param_1,(byte *)&local_144,0xc);
    bStack_15b = 0x67;
    __dump_hex("get_mn_mac",(int)&local_144,0xc);
    local_156._0_2_ = local_140;
    uVar3 = local_156._0_2_;
    local_150 = local_13a;
    bStack_15a = (byte)local_144;
    bStack_159 = (byte)(local_144 >> 8);
    local_158 = (byte)(local_144 >> 0x10);
    bStack_157 = (byte)(local_144 >> 0x18);
    local_156._2_4_ = local_13e;
    if (2 < LOG_LEVEL) {
      local_164 = (uint)bStack_15b;
      local_198 = local_144 & 0xff;
      local_194 = (uint)bStack_159;
      local_17c = local_13e >> 8 & 0xff;
      local_190 = (uint)local_158;
      local_18c = (uint)bStack_157;
      local_156[0] = (byte)local_140;
      local_188 = (uint)local_156[0];
      local_156[1] = (byte)((ushort)local_140 >> 8);
      local_184 = (uint)local_156[1];
      local_180 = local_13e & 0xff;
      local_178 = local_13e >> 0x10 & 0xff;
      local_174 = local_13e >> 0x18;
      local_156._0_2_ = uVar3;
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): BLE_REQ_GET_M_N_S_MAC: 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n"
              );
      }
      else {
        ble_printk("%s(): BLE_REQ_GET_M_N_S_MAC: 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n"
                   ,"ble_process_get_req",(uint)local_15c,local_164);
      }
    }
    break;
  case 0x2e:
    get_whitelist_app_from_device(param_1,(int)&local_15c);
    return;
  default:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): #tx error get req_type: %d\n");
      }
      else {
        ble_printk("%s(): #tx error get req_type: %d\n","ble_process_get_req",uVar9,BLE_DEBUG);
      }
    }
    uVar9 = 0x14;
    bStack_15b = 0xca;
    bStack_15a = 0x14;
    strcpy((char *)&bStack_15a,"error get req.");
    pcVar13 = *(code **)(param_1 + 0xc);
    goto LAB_0001a74a;
  case 0x32:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    bStack_15a = (byte)local_144;
    bStack_15b = 0x6d;
    bStack_159 = local_144._1_1_;
    uVar9 = (uint)local_144._1_1_;
    if (2 < LOG_LEVEL) {
      pcVar6 = "%s(): BLE_REQ_GET_WAKEUP_ANGLE: 0x%02x,0x%02x,0x%02x,0x%02x,\n";
      bVar2 = (byte)local_144;
      local_194 = local_144 >> 0x18;
      local_144 = local_144 >> 0x10;
      goto LAB_0001a336;
    }
    break;
  case 0x33:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    pbVar14 = (byte *)&local_144;
    bStack_15b = 0x33;
    pbVar10 = &bStack_15a;
    do {
      uVar5 = *(undefined4 *)pbVar14;
      uVar8 = *(undefined4 *)(pbVar14 + 4);
      pbVar14 = pbVar14 + 8;
      *(undefined4 *)pbVar10 = uVar5;
      *(undefined4 *)(pbVar10 + 4) = uVar8;
      pbVar10 = pbVar10 + 8;
    } while (pbVar14 != local_134);
    if (2 < LOG_LEVEL) {
      pcVar6 = "%s(): BLE_REQ_GET_GLASSES_SN: %s\n";
      puVar11 = &local_144;
LAB_0001a5e8:
      if (BLE_DEBUG == 0) {
        printk(pcVar6);
      }
      else {
        ble_printk(pcVar6,"ble_process_get_req",puVar11,BLE_DEBUG);
      }
    }
    break;
  case 0x34:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    pbVar14 = (byte *)&local_144;
    bStack_15b = 0x34;
    pbVar10 = &bStack_15a;
    do {
      uVar5 = *(undefined4 *)pbVar14;
      uVar8 = *(undefined4 *)(pbVar14 + 4);
      pbVar14 = pbVar14 + 8;
      *(undefined4 *)pbVar10 = uVar5;
      *(undefined4 *)(pbVar10 + 4) = uVar8;
      pbVar10 = pbVar10 + 8;
    } while (pbVar14 != local_134);
    if (2 < LOG_LEVEL) {
      pcVar6 = "%s(): BLE_REQ_GET_DEVICE_SN: %s\n";
      puVar11 = &local_144;
      goto LAB_0001a5e8;
    }
    break;
  case 0x35:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    bStack_15b = 0xc9;
    puVar11 = (undefined4 *)(local_144 & 0xff);
    bStack_15a = (byte)local_144;
    if (2 < LOG_LEVEL) {
      pcVar6 = "%s(): BLE_REQ_GET_ESB_CHANNEL: %d\n";
      goto LAB_0001a5e8;
    }
    break;
  case 0x36:
    get_notification_counts_cmd_process(param_1,(byte *)&local_144,&local_15c);
    return;
  case 0x37:
    FUN_00019d14(param_1,(byte *)&local_144,1);
    bStack_15b = 0x37;
    bStack_15a = (byte)local_144;
    bStack_159 = (byte)(local_144 >> 8);
    local_158 = (byte)(local_144 >> 0x10);
    bStack_157 = (byte)(local_144 >> 0x18);
    local_156[0] = (byte)local_140;
    break;
  case 0x38:
    bStack_15b = 0xc9;
    bStack_15a = *(byte *)(param_1 + 0x90c);
    puVar11 = (undefined4 *)(uint)bStack_15a;
    if (0 < LOG_LEVEL) {
      pcVar6 = "%s(): globle->enable_ancs %d\n";
      goto LAB_0001a5e8;
    }
    break;
  case 0x39:
    if ((uint)*(ushort *)((int)param_3 + 1) == (uint)*(ushort *)(param_2 + 2)) {
      memset(&bStack_157,0,0x10);
      uVar5 = *param_3;
      local_158 = *(byte *)(param_3 + 1);
      local_15c = (byte)uVar5;
      bStack_15b = (byte)((uint)uVar5 >> 8);
      bStack_15a = (byte)((uint)uVar5 >> 0x10);
      bStack_159 = (byte)((uint)uVar5 >> 0x18);
      bVar4 = __is_idle();
      if (bVar4) {
        bStack_157 = 0;
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): return system status to app,current running app is E_ID_SCREEN_IDLE\n");
          }
          else {
            ble_printk("%s(): return system status to app,current running app is E_ID_SCREEN_IDLE\n"
                       ,"ble_process_get_req",extraout_r2,BLE_DEBUG);
          }
        }
      }
      else {
        bStack_157 = 0;
        if (*(char *)(param_1 + -0x6a7) != '\0') {
          bStack_157 = *(byte *)(param_1 + -0x6a7);
        }
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): return system status to app,current running app is %d\n",
                   "ble_process_get_req",(uint)*(byte *)(param_1 + -0x6a7));
          }
          else {
            ble_printk("%s(): return system status to app,current running app is %d\n",
                       "ble_process_get_req",(uint)*(byte *)(param_1 + -0x6a7),param_1 + -0x77c);
          }
        }
      }
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): get device  information packet length error,input data length = %d,packet data length = %d\n"
                 ,"ble_process_get_req");
        }
        else {
          ble_printk("%s(): get device  information packet length error,input data length = %d,packet data length = %d\n"
                     ,"ble_process_get_req",(uint)*(ushort *)(param_2 + 2),
                     (uint)*(ushort *)((int)param_3 + 1));
        }
      }
      memset(local_156,0,0xf);
      local_158 = *(byte *)(param_3 + 1);
      uVar5 = *param_3;
      local_15c = (byte)uVar5;
      bStack_15b = (byte)((uint)uVar5 >> 8);
      bStack_15a = (byte)((uint)uVar5 >> 0x10);
      bStack_159 = (byte)((uint)uVar5 >> 0x18);
      bStack_157 = 0xff;
    }
    uVar9 = 6;
    pcVar13 = *(code **)(param_1 + 0xc);
    goto LAB_0001a74a;
  case 0x3a:
    bStack_15b = 0xc9;
    bStack_15a = *(byte *)(param_1 + 0x958);
    puVar11 = (undefined4 *)(uint)bStack_15a;
    if (0 < LOG_LEVEL) {
      pcVar6 = "%s(): globle->check_mode %d\n";
      goto LAB_0001a5e8;
    }
    break;
  case 0x3b:
    bStack_15a = *(byte *)(param_1 + 0x744);
    uVar9 = (uint)bStack_15a;
    bStack_15b = 0xc9;
    bStack_159 = *(byte *)(param_1 + 0x745);
    uVar12 = (uint)bStack_159;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        pcVar6 = "%s(): BLE_GET_RASTER_CONFIG:raster_height_gear:%d,canvas_distance_gear:%d\n";
        goto LAB_0001a52a;
      }
      pcVar6 = "%s(): BLE_GET_RASTER_CONFIG:raster_height_gear:%d,canvas_distance_gear:%d\n";
      goto LAB_0001a520;
    }
    break;
  case 0x3c:
    bStack_15a = *(byte *)(param_1 + 0x95a);
    uVar9 = (uint)bStack_15a;
    bStack_15b = 0xc9;
    bStack_159 = *(byte *)(param_1 + 0x95b);
    uVar12 = (uint)bStack_159;
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        pcVar6 = "%s(): globle->message_mode %d globle->message_stay_time %d\n";
        goto LAB_0001a52a;
      }
      pcVar6 = "%s(): globle->message_mode %d globle->message_stay_time %d\n";
      goto LAB_0001a520;
    }
    break;
  case 0x3d:
    uVar9 = (uint)*(ushort *)((int)param_3 + 1);
    uVar12 = (uint)*(ushort *)(param_2 + 2);
    if (uVar9 != uVar12) {
      if (LOG_LEVEL < 2) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
                   "ble_process_get_req",uVar12,uVar9);
        return;
      }
      printk("%s(): packet length error,input data length = %d,packet data length = %d\n",
             "ble_process_get_req",uVar12,uVar9);
      return;
    }
    uVar1 = *(undefined1 *)((int)param_3 + 5);
    memset(&local_15c,0,0x15);
    memcpy(&local_15c,param_3,uVar9);
    bVar4 = __is_master();
    CURRENT_LANGUAGE = uVar1;
    if (bVar4) {
      SendSystemLanguageInfoToSlave(uVar1);
    }
    pcVar13 = *(code **)(param_1 + 0xc);
    goto LAB_0001a74a;
  case 0x3e:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): BLE_GET_BURIAL_POINT_DATA\n\n");
      }
      else {
        ble_printk("%s(): BLE_GET_BURIAL_POINT_DATA\n\n","ble_process_get_req",uVar9,BLE_DEBUG);
      }
    }
    pGVar7 = __get_dashboard_state();
    memcpy(&local_144,&pGVar7->__burial_point_ctx,0x11c);
    local_288[0] = *param_2;
    local_288[1] = 0xc9;
    memcpy(local_288 + 2,&local_144,0x11c);
    (**(code **)(param_1 + 0xc))(local_288,0x11e);
    return;
  case 0x3f:
    bStack_15b = *(byte *)((int)param_3 + 1);
    bStack_15a = 0xc9;
    switch(bStack_15b) {
    case 5:
      bStack_159 = *(byte *)(param_1 + 0xac8);
      break;
    case 6:
      bStack_159 = *(byte *)(param_1 + 0x764);
      break;
    case 7:
      bStack_159 = *(byte *)(param_1 + 0xaca);
      break;
    case 8:
      bStack_159 = *(byte *)(param_1 + 0xacb);
      break;
    default:
      bStack_15a = 0xca;
    }
  }
  uVar9 = 0x14;
  pcVar13 = *(code **)(param_1 + 0xc);
LAB_0001a74a:
  (*pcVar13)(&local_15c,uVar9);
  return;
}



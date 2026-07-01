/*
 * Function: local_esbs_ipc_service_recv
 * Entry:    000158c4
 * Prototype: undefined4 __stdcall local_esbs_ipc_service_recv(int param_1, byte * param_2)
 */


undefined4 local_esbs_ipc_service_recv(int param_1,byte *param_2)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  char *fmt;
  int iVar4;
  undefined4 *puVar5;
  k_sem *sem;
  undefined4 uVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined1 uVar7;
  uint uVar8;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  undefined4 *puVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  byte local_24 [4];
  byte local_20;
  undefined4 local_1f;
  
  local_30 = 0;
  memset(&uStack_2c,0,0x12);
  puVar5 = &local_30;
  pbVar10 = param_2 + 0xb;
  do {
    pbVar13 = pbVar10;
    puVar9 = puVar5;
    uVar6 = *(undefined4 *)(pbVar13 + 4);
    pbVar10 = pbVar13 + 8;
    *puVar9 = *(undefined4 *)pbVar13;
    puVar9[1] = uVar6;
    puVar5 = puVar9 + 2;
  } while (pbVar10 != param_2 + 0x1b);
  puVar9[2] = *(undefined4 *)pbVar10;
  *(byte *)(puVar9 + 3) = pbVar13[0xc];
  uVar8 = (uint)uStack_2c._2_1_;
  uVar11 = (uint)*(byte *)(param_1 + 0xda);
  if (uVar8 == uVar11) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): slave recv same package\n";
    goto LAB_00015918;
  }
  if ((uVar8 != (uVar11 + 1 & 0xff)) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ###############loss package new_data_pkg->package_id %d data_pkg->package_id %d\n"
             ,"local_esbs_ipc_service_recv");
      uVar8 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): ###############loss package new_data_pkg->package_id %d data_pkg->package_id %d\n"
                 ,"local_esbs_ipc_service_recv",uVar8,uVar11);
      uVar8 = extraout_r2;
    }
  }
  uVar3 = local_30;
  uVar11 = local_30 & 0x3f;
  uVar15 = local_30 & 0x3f;
  if (uVar15 == 1) {
    if (*(char *)(param_1 + 0xfea) == '\x01') {
      *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): slave recv suspend package\n";
      goto LAB_00015918;
    }
  }
  else if (uVar15 == 2) {
    if ((*(char *)(param_1 + 0xfea) == '\0') &&
       (*(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01', 0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): slave recv resume package\n");
        uVar8 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): slave recv resume package\n","local_esbs_ipc_service_recv",uVar8,BLE_DEBUG
                  );
        uVar8 = extraout_r2_01;
      }
    }
  }
  else {
    uVar8 = (uint)*(byte *)(param_1 + 0xd5);
    if ((uVar8 != (local_30 >> 8 & 0xff)) && (uVar15 == 8)) {
      *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): screen id is not same\n";
      goto LAB_00015918;
    }
  }
  if (((*(char *)(param_1 + 0xd5) == '\t') || (*(char *)(param_1 + 0xd5) == '\v')) ||
     (*(char *)(param_1 + 0xd5) == '\n')) {
    uVar12 = uVar3 & 0xc0;
    if (uVar12 == 0x80) {
      if (*(char *)(param_1 + 0xce) != '\0') {
        *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
        if (LOG_LEVEL < 1) {
          return 0;
        }
        fmt = "%s(): slave recv up recving\n";
        goto LAB_00015918;
      }
    }
    else if ((uVar12 == 0x40) && (*(char *)(param_1 + 0xcf) != '\0')) {
      *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): slave recv down recving\n";
      goto LAB_00015918;
    }
  }
  else if ((*(char *)(param_1 + 0xd5) == '\x10') && (*(char *)(param_1 + 0xce) != '\0')) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): slave even ai recv down recving\n");
      }
      else {
        ble_printk("%s(): slave even ai recv down recving\n","local_esbs_ipc_service_recv",uVar8,
                   BLE_DEBUG);
      }
    }
    *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
    return 0;
  }
  if ((local_30._1_1_ != '\x06') && (local_30._1_1_ != '\0')) {
    *(byte *)(param_1 + 0xe9) = param_2[3];
    bVar1 = param_2[4];
    *(byte *)(param_1 + 0xea) = bVar1;
    if (uVar11 == 0) {
      if (((uVar3 & 0xc0) == 0x80) ||
         ((local_30._1_1_ == '\x10' && (**(byte **)&GLOBAL_STATE->field_0x1010 - 6 < 4)))) {
        if (((uint)*(byte *)(param_1 + 0xcc) != (uint)param_2[3]) &&
           (uVar8 = (uint)*(byte *)(*(int *)(param_1 + 0x1038) + 0x200), uVar8 != param_2[3])) {
          *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
          if (LOG_LEVEL < 1) {
            return 0;
          }
          fmt = "%s(): slave recv wrong up package\n";
          goto LAB_00015918;
        }
      }
      else if (((uint)*(byte *)(param_1 + 0xcd) != (uint)bVar1) &&
              (uVar8 = (uint)*(byte *)(*(int *)(param_1 + 0x103c) + 0x200), uVar8 != bVar1)) {
        *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
        if (LOG_LEVEL < 1) {
          return 0;
        }
        fmt = "%s(): slave recv wrong down package\n";
        goto LAB_00015918;
      }
    }
  }
  *(byte *)(param_1 + 0xc9) = *(byte *)(param_1 + 0xc9) & 0xc0 | *param_2 & 0x3f;
  *(byte *)(param_1 + 0xca) = param_2[1];
  *(byte *)(param_1 + 0xcb) = param_2[2];
  __set_date(*(undefined4 *)(param_2 + 7));
  uVar7 = *(undefined1 *)(param_1 + 0xd5);
  local_30._0_2_ = CONCAT11(uVar7,(byte)local_30);
  puVar5 = (undefined4 *)(param_1 + 0xd4);
  pbVar10 = (byte *)&local_30;
  do {
    pbVar13 = pbVar10;
    puVar9 = puVar5;
    uVar6 = *(undefined4 *)(pbVar13 + 4);
    pbVar10 = pbVar13 + 8;
    *puVar9 = *(undefined4 *)pbVar13;
    puVar9[1] = uVar6;
    puVar5 = puVar9 + 2;
  } while (pbVar10 != &local_20);
  puVar9[2] = *(undefined4 *)pbVar10;
  *(byte *)(puVar9 + 3) = pbVar13[0xc];
  *(byte *)(param_1 + 0xee8) = (byte)local_30 >> 6;
  **(undefined4 **)(param_1 + 0xff0) = *(undefined4 *)(param_2 + 7);
  if (*(int *)(*(int *)(param_1 + 0xff8) + 0x164) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xff8) + 0x164) = **(undefined4 **)(param_1 + 0xff0);
  }
  *(byte *)(param_1 + 0xeb) = (byte)local_30 >> 6;
  *(undefined1 *)(param_1 + 0xec) = uVar7;
  if ((int)((uint)local_20 << 0x1d) < 0) {
    FUN_00035270();
    *(byte *)(param_1 + 0xe4) = *(byte *)(param_1 + 0xe4) & 0xfb;
  }
  pGVar2 = GLOBAL_STATE;
  switch(local_30 & 0x3f) {
  case 8:
    uVar8 = (uint)*(byte *)(param_1 + 0xd5);
    if ((uVar8 != (local_30 >> 8 & 0xff)) && (uVar15 == 8)) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): screen id is not same, exit\n";
LAB_00015918:
      if (BLE_DEBUG != 0) {
        ble_printk(fmt,"local_esbs_ipc_service_recv",uVar8,BLE_DEBUG);
        return 0;
      }
      printk(fmt);
      return 0;
    }
    FUN_000800ca((int)GLOBAL_STATE,0);
    uVar6 = extraout_r1;
    if (((char)local_1f != '\0') && (GLOBAL_STATE->field20_0xc8[0xd] == '\x04')) {
      FUN_00035a84();
      iVar4 = 0;
      if (GLOBAL_STATE->field20_0xc8[0x15] != '\0') {
        iVar4 = 6;
      }
      FUN_00035abc(iVar4);
      uVar6 = extraout_r1_00;
    }
    if (*(char *)&GLOBAL_STATE->imu_fusion_context == '\x02') {
      FUN_000260dc();
      uVar6 = extraout_r1_01;
    }
    update_persist_task_status_to_idle((int)GLOBAL_STATE,uVar6);
    sem = &GLOBAL_STATE->sem_2;
    goto LAB_00015ca2;
  default:
    sem = (k_sem *)(param_1 + 0x20);
LAB_00015ca2:
    k_sem_give(sem);
    goto LAB_00015ce6;
  case 10:
    if ((int)((uint)(byte)GLOBAL_STATE->field_0x6de << 0x1d) < 0) {
      return 0;
    }
    puVar5 = FUN_0003522c(local_1f);
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_FIRST slave before\n",
               "local_esbs_ipc_service_recv","local_esbs_ipc_service_recv",0x334);
      }
      else {
        ble_printk("%s(): ##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_FIRST slave before\n",
                   "local_esbs_ipc_service_recv","local_esbs_ipc_service_recv",0x334);
      }
    }
    if ((puVar5 != (undefined4 *)0x0) && (*(char *)((int)puVar5 + 0xd) == '\0')) {
      *(undefined1 *)((int)puVar5 + 0xd) = 2;
    }
    goto LAB_00015ce6;
  case 0xb:
    if ((int)((uint)(byte)GLOBAL_STATE->field_0x6de << 0x1d) < 0) {
      return 0;
    }
    puVar5 = FUN_0003522c(local_1f);
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_END slave before\n",
               "local_esbs_ipc_service_recv","local_esbs_ipc_service_recv",0x341);
      }
      else {
        ble_printk("%s(): ##########%s %d SYNC_DISPLAY_CMD_COMFIRM_NOTIFY_END slave before\n",
                   "local_esbs_ipc_service_recv","local_esbs_ipc_service_recv",0x341);
      }
    }
    if ((puVar5 == (undefined4 *)0x0) || (*(char *)((int)puVar5 + 0xd) != '\x02'))
    goto LAB_00015ce6;
    *(undefined1 *)((int)puVar5 + 0xd) = 4;
    confirm_message(local_1f);
    uVar7 = 0;
    puVar14 = &DAT_20019a66;
    break;
  case 0xc:
    if ((char)local_1f == '\v') {
      bVar1 = local_1f._1_1_;
      uVar8 = (uint)local_1f._1_1_;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                 "local_esbs_ipc_service_recv",uVar8);
        }
        else {
          ble_printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                     "local_esbs_ipc_service_recv",uVar8,local_1f >> 0x10 & 0xff);
        }
      }
      pGVar2 = GLOBAL_STATE;
      if ((uVar8 < 10) && (local_1f._2_1_ < 9)) {
        (GLOBAL_STATE->jdb_panel_context).field_0x355 = bVar1;
        (pGVar2->jdb_panel_context).field_0x354 = local_1f._2_1_;
        cal_panel_canvas_coord
                  ((int *)&(pGVar2->jdb_panel_context).field_0x358,
                   (int *)&(pGVar2->jdb_panel_context).field_0x34c);
      }
      if (GLOBAL_STATE->dashboard_ts->field_0x74 != '\0') {
        GLOBAL_STATE->dashboard_ts->field_0x74 = 0;
      }
    }
    goto LAB_00015ce6;
  case 0xd:
    FUN_00080338(0);
    pGVar2 = GLOBAL_STATE;
    **(undefined1 **)&GLOBAL_STATE->field_0x1010 = 2;
    if (*(int *)pGVar2->___glasses_state != 0x10) {
      update_persist_task_status((int)pGVar2,0x10,2);
    }
    goto LAB_00015ce6;
  case 0xe:
    uVar7 = 4;
    puVar14 = *(undefined1 **)&GLOBAL_STATE->field_0x1010;
    break;
  case 0xf:
    uVar7 = 6;
    puVar14 = *(undefined1 **)&GLOBAL_STATE->field_0x1010;
    break;
  case 0x10:
    **(undefined1 **)&GLOBAL_STATE->field_0x1010 = 0xb;
    pGVar2->field20_0xc8[0x13] = 8;
    goto LAB_00015ce6;
  case 0x11:
    uVar7 = 0xe;
    puVar14 = *(undefined1 **)&GLOBAL_STATE->field_0x1010;
    break;
  case 0x12:
    uVar7 = 0x10;
    puVar14 = *(undefined1 **)&GLOBAL_STATE->field_0x1010;
  }
  *puVar14 = uVar7;
LAB_00015ce6:
  if ((((*(byte *)(param_1 + 0xc9) & 0x3f) == 3) && ((*(byte *)(param_1 + 0xc9) & 0xc0) == 0x80)) &&
     (*(char *)(param_1 + 0xca) == '\x01')) {
    switch_to_dfu_mode((k_sem *)(param_1 + 0x68));
  }
  return 0;
}



/*
 * Function: local_esbs_ipc_service_recv
 * Entry:    000158c4
 * Prototype: undefined4 __stdcall local_esbs_ipc_service_recv(int param_1, byte * param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 local_esbs_ipc_service_recv(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  char *fmt;
  int iVar3;
  undefined4 *puVar4;
  k_sem *sem;
  undefined4 uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined1 uVar6;
  uint uVar7;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  undefined4 *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  byte local_24 [4];
  byte local_20;
  undefined4 local_1f;
  
  local_30 = 0;
  memset(&uStack_2c,0,0x12);
  puVar4 = &local_30;
  pbVar9 = param_2 + 0xb;
  do {
    pbVar12 = pbVar9;
    puVar8 = puVar4;
    uVar5 = *(undefined4 *)(pbVar12 + 4);
    pbVar9 = pbVar12 + 8;
    *puVar8 = *(undefined4 *)pbVar12;
    puVar8[1] = uVar5;
    puVar4 = puVar8 + 2;
  } while (pbVar9 != param_2 + 0x1b);
  puVar8[2] = *(undefined4 *)pbVar9;
  *(byte *)(puVar8 + 3) = pbVar12[0xc];
  uVar7 = (uint)uStack_2c._2_1_;
  uVar10 = (uint)*(byte *)(param_1 + 0xda);
  if (uVar7 == uVar10) {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    fmt = "%s(): slave recv same package\n";
    goto LAB_00015918;
  }
  if ((uVar7 != (uVar10 + 1 & 0xff)) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ###############loss package new_data_pkg->package_id %d data_pkg->package_id %d\n"
             ,"local_esbs_ipc_service_recv");
      uVar7 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): ###############loss package new_data_pkg->package_id %d data_pkg->package_id %d\n"
                 ,"local_esbs_ipc_service_recv",uVar7,uVar10);
      uVar7 = extraout_r2;
    }
  }
  uVar2 = local_30;
  uVar10 = local_30 & 0x3f;
  uVar14 = local_30 & 0x3f;
  if (uVar14 == 1) {
    if (*(char *)(param_1 + 0xfea) == '\x01') {
      *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): slave recv suspend package\n";
      goto LAB_00015918;
    }
  }
  else if (uVar14 == 2) {
    if ((*(char *)(param_1 + 0xfea) == '\0') &&
       (*(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01', 0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): slave recv resume package\n");
        uVar7 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): slave recv resume package\n","local_esbs_ipc_service_recv",uVar7,BLE_DEBUG
                  );
        uVar7 = extraout_r2_01;
      }
    }
  }
  else {
    uVar7 = (uint)*(byte *)(param_1 + 0xd5);
    if ((uVar7 != (local_30 >> 8 & 0xff)) && (uVar14 == 8)) {
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
    uVar11 = uVar2 & 0xc0;
    if (uVar11 == 0x80) {
      if (*(char *)(param_1 + 0xce) != '\0') {
        *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
        if (LOG_LEVEL < 1) {
          return 0;
        }
        fmt = "%s(): slave recv up recving\n";
        goto LAB_00015918;
      }
    }
    else if ((uVar11 == 0x40) && (*(char *)(param_1 + 0xcf) != '\0')) {
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
        ble_printk("%s(): slave even ai recv down recving\n","local_esbs_ipc_service_recv",uVar7,
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
    if (uVar10 == 0) {
      if (((uVar2 & 0xc0) == 0x80) ||
         ((local_30._1_1_ == '\x10' && (**(byte **)(GLOBAL_STATE._0_4_ + 0x1010) - 6 < 4)))) {
        if (((uint)*(byte *)(param_1 + 0xcc) != (uint)param_2[3]) &&
           (uVar7 = (uint)*(byte *)(*(int *)(param_1 + 0x1038) + 0x200), uVar7 != param_2[3])) {
          *(char *)(param_1 + 0xda) = *(char *)(param_1 + 0xda) + '\x01';
          if (LOG_LEVEL < 1) {
            return 0;
          }
          fmt = "%s(): slave recv wrong up package\n";
          goto LAB_00015918;
        }
      }
      else if (((uint)*(byte *)(param_1 + 0xcd) != (uint)bVar1) &&
              (uVar7 = (uint)*(byte *)(*(int *)(param_1 + 0x103c) + 0x200), uVar7 != bVar1)) {
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
  uVar6 = *(undefined1 *)(param_1 + 0xd5);
  local_30._0_2_ = CONCAT11(uVar6,(byte)local_30);
  puVar4 = (undefined4 *)(param_1 + 0xd4);
  pbVar9 = (byte *)&local_30;
  do {
    pbVar12 = pbVar9;
    puVar8 = puVar4;
    uVar5 = *(undefined4 *)(pbVar12 + 4);
    pbVar9 = pbVar12 + 8;
    *puVar8 = *(undefined4 *)pbVar12;
    puVar8[1] = uVar5;
    puVar4 = puVar8 + 2;
  } while (pbVar9 != &local_20);
  puVar8[2] = *(undefined4 *)pbVar9;
  *(byte *)(puVar8 + 3) = pbVar12[0xc];
  *(byte *)(param_1 + 0xee8) = (byte)local_30 >> 6;
  **(undefined4 **)(param_1 + 0xff0) = *(undefined4 *)(param_2 + 7);
  if (*(int *)(*(int *)(param_1 + 0xff8) + 0x164) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xff8) + 0x164) = **(undefined4 **)(param_1 + 0xff0);
  }
  *(byte *)(param_1 + 0xeb) = (byte)local_30 >> 6;
  *(undefined1 *)(param_1 + 0xec) = uVar6;
  if ((int)((uint)local_20 << 0x1d) < 0) {
    FUN_00035270();
    *(byte *)(param_1 + 0xe4) = *(byte *)(param_1 + 0xe4) & 0xfb;
  }
  uVar5 = GLOBAL_STATE._0_4_;
  switch(local_30 & 0x3f) {
  case 8:
    uVar7 = (uint)*(byte *)(param_1 + 0xd5);
    if ((uVar7 != (local_30 >> 8 & 0xff)) && (uVar14 == 8)) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      fmt = "%s(): screen id is not same, exit\n";
LAB_00015918:
      if (BLE_DEBUG != 0) {
        ble_printk(fmt,"local_esbs_ipc_service_recv",uVar7,BLE_DEBUG);
        return 0;
      }
      printk(fmt);
      return 0;
    }
    FUN_000800ca(GLOBAL_STATE._0_4_,0);
    uVar5 = extraout_r1;
    if (((char)local_1f != '\0') && (*(char *)(GLOBAL_STATE._0_4_ + 0xd5) == '\x04')) {
      FUN_00035a84();
      iVar3 = 0;
      if (*(char *)(GLOBAL_STATE._0_4_ + 0xdd) != '\0') {
        iVar3 = 6;
      }
      FUN_00035abc(iVar3);
      uVar5 = extraout_r1_00;
    }
    if (*(char *)(GLOBAL_STATE._0_4_ + 0xee8) == '\x02') {
      FUN_000260dc();
      uVar5 = extraout_r1_01;
    }
    update_persist_task_status_to_idle(GLOBAL_STATE._0_4_,uVar5);
    sem = (k_sem *)(GLOBAL_STATE._0_4_ + 0x38);
    goto LAB_00015ca2;
  default:
    sem = (k_sem *)(param_1 + 0x20);
LAB_00015ca2:
    k_sem_give(sem);
    goto LAB_00015ce6;
  case 10:
    if ((int)((uint)*(byte *)(GLOBAL_STATE._0_4_ + 0x6de) << 0x1d) < 0) {
      return 0;
    }
    puVar4 = FUN_0003522c(local_1f);
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
    if ((puVar4 != (undefined4 *)0x0) && (*(char *)((int)puVar4 + 0xd) == '\0')) {
      *(undefined1 *)((int)puVar4 + 0xd) = 2;
    }
    goto LAB_00015ce6;
  case 0xb:
    if ((int)((uint)*(byte *)(GLOBAL_STATE._0_4_ + 0x6de) << 0x1d) < 0) {
      return 0;
    }
    puVar4 = FUN_0003522c(local_1f);
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
    if ((puVar4 == (undefined4 *)0x0) || (*(char *)((int)puVar4 + 0xd) != '\x02'))
    goto LAB_00015ce6;
    *(undefined1 *)((int)puVar4 + 0xd) = 4;
    confirm_message(local_1f);
    uVar6 = 0;
    puVar13 = &DAT_20019a66;
    break;
  case 0xc:
    if ((char)local_1f == '\v') {
      bVar1 = local_1f._1_1_;
      uVar7 = (uint)local_1f._1_1_;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                 "local_esbs_ipc_service_recv",uVar7);
        }
        else {
          ble_printk("%s(): slave rcv canvas_distance_gear:%d,raster_height_gear:%d\n",
                     "local_esbs_ipc_service_recv",uVar7,local_1f >> 0x10 & 0xff);
        }
      }
      uVar5 = GLOBAL_STATE._0_4_;
      if ((uVar7 < 10) && (local_1f._2_1_ < 9)) {
        *(byte *)(GLOBAL_STATE._0_4_ + 0xec1) = bVar1;
        *(byte *)(uVar5 + 0xec0) = local_1f._2_1_;
        cal_panel_canvas_coord((int *)(uVar5 + 0xec4),(int *)(uVar5 + 0xeb8));
      }
      if (*(char *)(*(int *)(GLOBAL_STATE._0_4_ + 0xff0) + 0x74) != '\0') {
        *(undefined1 *)(*(int *)(GLOBAL_STATE._0_4_ + 0xff0) + 0x74) = 0;
      }
    }
    goto LAB_00015ce6;
  case 0xd:
    FUN_00080338(0);
    uVar5 = GLOBAL_STATE._0_4_;
    **(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010) = 2;
    if (**(int **)(uVar5 + 0x1068) != 0x10) {
      update_persist_task_status(uVar5,0x10,2);
    }
    goto LAB_00015ce6;
  case 0xe:
    uVar6 = 4;
    puVar13 = *(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010);
    break;
  case 0xf:
    uVar6 = 6;
    puVar13 = *(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010);
    break;
  case 0x10:
    **(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010) = 0xb;
    *(undefined1 *)(uVar5 + 0xdb) = 8;
    goto LAB_00015ce6;
  case 0x11:
    uVar6 = 0xe;
    puVar13 = *(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010);
    break;
  case 0x12:
    uVar6 = 0x10;
    puVar13 = *(undefined1 **)(GLOBAL_STATE._0_4_ + 0x1010);
  }
  *puVar13 = uVar6;
LAB_00015ce6:
  if ((((*(byte *)(param_1 + 0xc9) & 0x3f) == 3) && ((*(byte *)(param_1 + 0xc9) & 0xc0) == 0x80)) &&
     (*(char *)(param_1 + 0xca) == '\x01')) {
    switch_to_dfu_mode((k_sem *)(param_1 + 0x68));
  }
  return 0;
}



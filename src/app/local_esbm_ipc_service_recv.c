/*
 * Function: local_esbm_ipc_service_recv
 * Entry:    00016c6c
 * Prototype: undefined4 __stdcall local_esbm_ipc_service_recv(int param_1, byte * param_2, undefined4 * param_3)
 */


undefined4 local_esbm_ipc_service_recv(int param_1,byte *param_2,undefined4 *param_3)

{
  int *d;
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  char cVar4;
  undefined4 *extraout_r2;
  char *pcVar5;
  byte *pbVar6;
  int iVar8;
  undefined8 uVar9;
  byte *pbVar7;
  
  uVar9 = CONCAT44(param_2,param_1);
  if (((*param_2 & 0x3f) != 0) && (uVar9 = CONCAT44(param_2,param_1), 1 < (*param_2 & 0x3f) - 0xc))
  {
    if (DAT_20010938 == param_2[0x15]) {
      return 0;
    }
    DAT_20010938 = param_2[0x15];
    *(undefined1 *)(param_1 + 0xfd3) = *(undefined1 *)(param_1 + 0x6cd);
    *(undefined1 *)(param_1 + 0xfd4) = *(undefined1 *)(param_1 + 0x6ce);
    *(undefined1 *)(param_1 + 0xfd5) = *(undefined1 *)(param_1 + 0x6cf);
    *(undefined1 *)(param_1 + 0xfc5) = *(undefined1 *)(param_1 + 0x6d0);
    *(undefined4 *)(param_1 + 0xfe4) = *(undefined4 *)(param_1 + 0x6d8);
    *(undefined2 *)(param_1 + 0xfe8) = *(undefined2 *)(param_1 + 0x6dc);
    puVar2 = (undefined4 *)(param_1 + 0x6cc);
    pbVar7 = param_2;
    do {
      pbVar6 = pbVar7 + 4;
      uVar9 = CONCAT44(param_2 + 0x14,*(undefined4 *)pbVar7);
      param_3 = puVar2 + 1;
      *puVar2 = *(undefined4 *)pbVar7;
      puVar2 = param_3;
      pbVar7 = pbVar6;
    } while (pbVar6 != param_2 + 0x14);
    *(undefined2 *)param_3 = *(undefined2 *)pbVar6;
    if ((int)((uint)param_2[0x12] << 0x1d) < 0) {
      uVar9 = FUN_00035270();
      *(byte *)(param_1 + 0x6de) = *(byte *)(param_1 + 0x6de) & 0xfb;
      param_3 = extraout_r2;
    }
  }
  uVar3 = GLOBAL_STATE._0_4_;
  iVar8 = (*param_2 & 0x3f) - 4;
  switch(iVar8) {
  case 0:
    if (*(char *)(GLOBAL_STATE._0_4_ + 0xd5) == '\x04') {
      FUN_00035a84();
      iVar8 = 0;
      if (*(char *)(GLOBAL_STATE._0_4_ + 0xdd) != '\0') {
        iVar8 = 6;
      }
      FUN_00035abc(iVar8);
    }
    DAT_20008514 = DAT_20008514 | 2;
    FUN_0007ff66(param_1,1);
    uVar3 = extraout_r1;
    if (*(char *)(param_1 + 0xee8) == '\x02') {
      FUN_000260dc();
      uVar3 = extraout_r1_00;
    }
    update_persist_task_status_to_idle(param_1,uVar3);
    break;
  case 1:
    FUN_0007ff66(param_1,1);
    change_work_mode(7);
    break;
  case 2:
    if (*(char *)(param_1 + 0x6df) == '\x01') {
      **(undefined1 **)(param_1 + 0x1034) = 1;
      return 0;
    }
    if (*(char *)(param_1 + 0x6df) != '\0') {
      return 0;
    }
    cVar4 = '\x02';
    pcVar5 = *(char **)(param_1 + 0x1034);
    goto LAB_00016dd2;
  case 3:
    SlaveDoubleClickEventInject((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),param_3,iVar8);
    break;
  case 4:
    FUN_0007ff66(param_1,1);
    *(undefined1 *)(param_1 + 0xfee) = 0xc;
    *(undefined4 *)(param_1 + 0x1060) = 3;
    k_sem_give((k_sem *)(param_1 + 0x80));
    break;
  case 5:
    *(undefined1 *)(param_1 + 0xfee) = 10;
    *(undefined4 *)(param_1 + 0x1060) = 3;
    k_sem_give((k_sem *)(param_1 + 0x80));
    FUN_0003f1bc();
    break;
  case 6:
    pcVar5 = &DAT_2001093b;
    goto LAB_00016dde;
  case 8:
    if ((((*(byte *)(GLOBAL_STATE._0_4_ + 0xe4) & 4) == 0 && DAT_20019a5c == '\0') &&
        (d = FUN_00035260((uint)param_2[0xd]), d != (int *)0x0)) &&
       ((*(char *)((int)d + 0xe) == '\0' &&
        (((*(int *)(param_2 + 9) != d[2] || (*(int *)(param_2 + 1) != *d)) ||
         (*(char *)((int)d + 0xd) != '\x01')))))) {
      pvVar1 = memcpy(d,param_2 + 1,0xda);
      *(undefined1 *)((int)pvVar1 + 0xd) = 1;
    }
    break;
  case 9:
    if ((((*(byte *)(GLOBAL_STATE._0_4_ + 0xe4) & 4) == 0 && DAT_20019a5c == '\0') &&
        (puVar2 = FUN_000351d8(), puVar2 != (undefined4 *)0x0)) &&
       ((*(char *)((int)puVar2 + 0xe) == '\0' && (*(char *)((int)puVar2 + 0xd) != '\x03')))) {
      memcpy((void *)((int)puVar2 + 0xda),param_2 + 1,0xda);
      *(undefined1 *)((int)puVar2 + 0xd) = 3;
    }
    break;
  case 10:
    if (*(char *)(param_1 + 0x6df) == '\x04') {
      *(undefined1 *)(*(int *)(GLOBAL_STATE._0_4_ + 0x101c) + 2) = *(undefined1 *)(param_1 + 0x6e0);
    }
    else if (*(char *)(param_1 + 0x6df) == '\x05') {
      FUN_00080852((uint)*(byte *)(param_1 + 0x6e0));
    }
    break;
  case 0xb:
    if (**(char **)(GLOBAL_STATE._0_4_ + 0x1010) == '\x01') {
      return 0;
    }
    FUN_00080338(0);
    pcVar5 = *(char **)(GLOBAL_STATE._0_4_ + 0x1010);
LAB_00016dde:
    cVar4 = '\x01';
    goto LAB_00016dd2;
  case 0xc:
    pcVar5 = *(char **)(GLOBAL_STATE._0_4_ + 0x1010);
    if (*pcVar5 != '\x04') {
      return 0;
    }
    cVar4 = '\x05';
LAB_00016dd2:
    *pcVar5 = cVar4;
    break;
  case 0xd:
    if (*(char *)(param_1 + 0x6df) == '\x06') {
      if ((((**(int **)(GLOBAL_STATE._0_4_ + 0x1068) == 0x14) &&
           (pcVar5 = *(char **)(GLOBAL_STATE._0_4_ + 0x1014), *pcVar5 == '\x01')) &&
          (pcVar5[1] == '\x04')) && (pcVar5[3] == '\x13')) {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): evenai_v2 need to show network_err tip\n");
          }
          else {
            ble_printk("%s(): evenai_v2 need to show network_err tip\n",
                       "local_esbm_ipc_service_recv",0x13,BLE_DEBUG);
          }
        }
      }
      else if (*(byte *)(param_1 + 0x6e0) < 3) {
        *(undefined1 *)(*(int *)(GLOBAL_STATE._0_4_ + 0x1014) + 1) = 6;
        *(undefined1 *)(*(int *)(uVar3 + 0x1014) + 3) = *(undefined1 *)(param_1 + 0x6e0);
      }
    }
  }
  return 0;
}



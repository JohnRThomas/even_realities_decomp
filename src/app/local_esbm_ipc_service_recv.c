/*
 * Function: local_esbm_ipc_service_recv
 * Entry:    00016c6c
 * Prototype: undefined4 __stdcall local_esbm_ipc_service_recv(int param_1, byte * param_2, undefined4 * param_3)
 */


undefined4 local_esbm_ipc_service_recv(int param_1,byte *param_2,undefined4 *param_3)

{
  GlassesState *pGVar1;
  int *d;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar4;
  char cVar5;
  undefined4 *extraout_r2;
  char *pcVar6;
  byte *pbVar7;
  int iVar9;
  undefined8 uVar10;
  byte *pbVar8;
  
  uVar10 = CONCAT44(param_2,param_1);
  if (((*param_2 & 0x3f) != 0) && (uVar10 = CONCAT44(param_2,param_1), 1 < (*param_2 & 0x3f) - 0xc))
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
    puVar3 = (undefined4 *)(param_1 + 0x6cc);
    pbVar8 = param_2;
    do {
      pbVar7 = pbVar8 + 4;
      uVar10 = CONCAT44(param_2 + 0x14,*(undefined4 *)pbVar8);
      param_3 = puVar3 + 1;
      *puVar3 = *(undefined4 *)pbVar8;
      puVar3 = param_3;
      pbVar8 = pbVar7;
    } while (pbVar7 != param_2 + 0x14);
    *(undefined2 *)param_3 = *(undefined2 *)pbVar7;
    if ((int)((uint)param_2[0x12] << 0x1d) < 0) {
      uVar10 = FUN_00035270();
      *(byte *)(param_1 + 0x6de) = *(byte *)(param_1 + 0x6de) & 0xfb;
      param_3 = extraout_r2;
    }
  }
  pGVar1 = GLOBAL_STATE;
  iVar9 = (*param_2 & 0x3f) - 4;
  switch(iVar9) {
  case 0:
    if (GLOBAL_STATE->field20_0xc8[0xd] == '\x04') {
      FUN_00035a84();
      iVar9 = 0;
      if (GLOBAL_STATE->field20_0xc8[0x15] != '\0') {
        iVar9 = 6;
      }
      FUN_00035abc(iVar9);
    }
    DAT_20008514 = DAT_20008514 | 2;
    FUN_0007ff66(param_1,1);
    uVar4 = extraout_r1;
    if (*(char *)(param_1 + 0xee8) == '\x02') {
      FUN_000260dc();
      uVar4 = extraout_r1_00;
    }
    update_persist_task_status_to_idle(param_1,uVar4);
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
    cVar5 = '\x02';
    pcVar6 = *(char **)(param_1 + 0x1034);
    goto LAB_00016dd2;
  case 3:
    SlaveDoubleClickEventInject((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),param_3,iVar9);
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
    pcVar6 = &DAT_2001093b;
    goto LAB_00016dde;
  case 8:
    if ((((GLOBAL_STATE->field20_0xc8[0x1c] & 4) == 0 && DAT_20019a5c == '\0') &&
        (d = FUN_00035260((uint)param_2[0xd]), d != (int *)0x0)) &&
       ((*(char *)((int)d + 0xe) == '\0' &&
        (((*(int *)(param_2 + 9) != d[2] || (*(int *)(param_2 + 1) != *d)) ||
         (*(char *)((int)d + 0xd) != '\x01')))))) {
      pvVar2 = memcpy(d,param_2 + 1,0xda);
      *(undefined1 *)((int)pvVar2 + 0xd) = 1;
    }
    break;
  case 9:
    if ((((GLOBAL_STATE->field20_0xc8[0x1c] & 4) == 0 && DAT_20019a5c == '\0') &&
        (puVar3 = FUN_000351d8(), puVar3 != (undefined4 *)0x0)) &&
       ((*(char *)((int)puVar3 + 0xe) == '\0' && (*(char *)((int)puVar3 + 0xd) != '\x03')))) {
      memcpy((void *)((int)puVar3 + 0xda),param_2 + 1,0xda);
      *(undefined1 *)((int)puVar3 + 0xd) = 3;
    }
    break;
  case 10:
    if (*(char *)(param_1 + 0x6df) == '\x04') {
      *(undefined1 *)(*(int *)&GLOBAL_STATE->field_0x101c + 2) = *(undefined1 *)(param_1 + 0x6e0);
    }
    else if (*(char *)(param_1 + 0x6df) == '\x05') {
      FUN_00080852((uint)*(byte *)(param_1 + 0x6e0));
    }
    break;
  case 0xb:
    if (**(char **)&GLOBAL_STATE->field_0x1010 == '\x01') {
      return 0;
    }
    FUN_00080338(0);
    pcVar6 = *(char **)&GLOBAL_STATE->field_0x1010;
LAB_00016dde:
    cVar5 = '\x01';
    goto LAB_00016dd2;
  case 0xc:
    pcVar6 = *(char **)&GLOBAL_STATE->field_0x1010;
    if (*pcVar6 != '\x04') {
      return 0;
    }
    cVar5 = '\x05';
LAB_00016dd2:
    *pcVar6 = cVar5;
    break;
  case 0xd:
    if (*(char *)(param_1 + 0x6df) == '\x06') {
      if ((((*(int *)GLOBAL_STATE->___glasses_state == 0x14) &&
           (pcVar6 = *(char **)&GLOBAL_STATE->field_0x1014, *pcVar6 == '\x01')) &&
          (pcVar6[1] == '\x04')) && (pcVar6[3] == '\x13')) {
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
        *(undefined1 *)(*(int *)&GLOBAL_STATE->field_0x1014 + 1) = 6;
        *(undefined1 *)(*(int *)&pGVar1->field_0x1014 + 3) = *(undefined1 *)(param_1 + 0x6e0);
      }
    }
  }
  return 0;
}



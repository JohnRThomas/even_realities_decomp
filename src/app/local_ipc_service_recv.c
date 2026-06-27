/*
 * Function: local_ipc_service_recv
 * Entry:    0001638c
 * Prototype: undefined4 __stdcall local_ipc_service_recv(undefined2 * param_1, undefined1 * param_2, int param_3)
 */


undefined4 local_ipc_service_recv(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  longlong lVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r2_01;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  
  switch(*param_2) {
  case 1:
    sys_clock_tick_get();
    goto LAB_000163c0;
  case 2:
    puVar6 = param_1;
    uVar5 = sys_clock_tick_get();
    lVar1 = (uVar5 & 0xffffffff) * 1000;
    uVar3 = (uint)lVar1;
    uVar4 = (int)(uVar5 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
            (uint)(0xffff8000 < uVar3);
    uVar3 = uVar3 + 0x7fff >> 0xf | uVar4 * 0x20000;
    uVar4 = uVar4 >> 0xf;
    uVar2 = extraout_r2;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): cpunet request send info uptime %lld\n","local_ipc_service_recv",uVar3,uVar4,
               puVar6,param_2,param_3);
        uVar2 = extraout_r2_01;
      }
      else {
        ble_printk("%s(): cpunet request send info uptime %lld\n","local_ipc_service_recv",uVar3,
                   uVar4);
        uVar2 = extraout_r2_00;
      }
    }
    if (uVar4 != 0 || uVar4 < (10000 < uVar3)) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): sys reboot because recv cpunet sync package\n");
        }
        else {
          ble_printk("%s(): sys reboot because recv cpunet sync package\n","local_ipc_service_recv",
                     uVar2,BLE_DEBUG);
        }
      }
      sleep(500);
                    /* WARNING: Subroutine does not return */
      sys_reboot(1);
    }
    runtime_info_sync(param_1);
    break;
  case 3:
    uVar5 = sys_clock_tick_get();
    if (*(char *)GLOBAL_STATE._0_4_ == '\x01') {
      *(undefined4 *)(param_1 + 0x7ef) = *(undefined4 *)(param_2 + 1);
      param_1[0x7f1] = *(undefined2 *)(param_2 + 5);
    }
    else {
      *(undefined4 *)(param_1 + 0x7f2) = *(undefined4 *)(param_2 + 1);
      param_1[0x7f4] = *(undefined2 *)(param_2 + 5);
    }
    if (1 < LOG_LEVEL) {
      lVar1 = (uVar5 & 0xffffffff) * 1000;
      uVar3 = (uint)lVar1;
      uVar4 = (int)(uVar5 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
              (uint)(0xffff8000 < uVar3);
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): cpunet request update macaddr info uptime %lld bt macaddr esb_master_addr %02X esb_slave_addr %02X \n"
              );
      }
      else {
        ble_printk("%s(): cpunet request update macaddr info uptime %lld bt macaddr esb_master_addr %02X esb_slave_addr %02X \n"
                   ,"local_ipc_service_recv",uVar3 + 0x7fff >> 0xf | uVar4 * 0x20000,uVar4 >> 0xf);
      }
    }
LAB_000163c0:
    if (*(int *)(param_1 + 8) == 0) {
      k_sem_give((k_sem *)(param_1 + 4));
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x7ef) = *(undefined4 *)(param_2 + 1);
    param_1[0x7f1] = *(undefined2 *)(param_2 + 5);
    *(undefined4 *)(param_1 + 0x7f2) = *(undefined4 *)(param_2 + 7);
    param_1[0x7f4] = *(undefined2 *)(param_2 + 0xb);
    break;
  default:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sync fail! len: %d, data=%s\n\n","local_ipc_service_recv",param_3,param_2,
               param_1,param_2,param_3);
      }
      else {
        ble_printk("%s(): sync fail! len: %d, data=%s\n\n","local_ipc_service_recv",param_3,param_2)
        ;
      }
    }
    break;
  case 6:
    uVar3 = (uint)*(byte *)(param_1 + 0x836);
    if (uVar3 == 0) {
      uVar3 = 1;
      *(undefined1 *)(param_1 + 0x836) = 1;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): bt_ready\n");
      }
      else {
        ble_printk("%s(): bt_ready\n","local_ipc_service_recv",uVar3,BLE_DEBUG);
      }
    }
    if (*(int *)(param_1 + 8) == 0) {
      k_sem_give((k_sem *)(param_1 + 4));
    }
    __memcpy_chk(&DAT_2001093c,param_2 + 1,param_3 - 1,0x20);
    DAT_2001095b = 0;
    break;
  case 7:
    DAT_20006bd4 = *(undefined4 *)(param_2 + 1);
    DAT_20006bd0 = *(undefined4 *)(param_2 + 5);
    DAT_20006bcc = *(undefined4 *)(param_2 + 9);
    DAT_20006bc8 = *(undefined4 *)(param_2 + 0xd);
    if (*(char *)(param_1 + 0x86a) == '\0') {
      DAT_20006bc8 = 0x46;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n");
      }
      else {
        ble_printk("%s(): IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n","local_ipc_service_recv",
                   DAT_20006bd4,DAT_20006bd0);
      }
    }
    break;
  case 0xd:
    *(undefined1 *)(param_1 + 0x837) = param_2[1];
  }
  return 0;
}



/*
 * Function: local_ipc_service_recv
 * Entry:    0001638c
 * Prototype: undefined4 __stdcall local_ipc_service_recv(undefined2 * param_1, undefined1 * param_2, int param_3)
 */


undefined4 local_ipc_service_recv(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 *puVar5;
  
  switch(*param_2) {
  case 1:
    sys_clock_tick_get();
    goto LAB_000163c0;
  case 2:
    puVar5 = param_1;
    uVar4 = sys_clock_tick_get();
    lVar1 = (uVar4 & 0xffffffff) * 1000;
    uVar2 = (uint)lVar1;
    uVar3 = (int)(uVar4 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
            (uint)(0xffff8000 < uVar2);
    uVar2 = uVar2 + 0x7fff >> 0xf | uVar3 * 0x20000;
    uVar3 = uVar3 >> 0xf;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): cpunet request send info uptime %lld\n","local_ipc_service_recv",uVar2,uVar3,
               puVar5,param_2,param_3);
      }
      else {
        ble_printk("%s(): cpunet request send info uptime %lld\n","local_ipc_service_recv",uVar2,
                   uVar3);
      }
    }
    if (uVar3 != 0 || uVar3 < (10000 < uVar2)) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): sys reboot because recv cpunet sync package\n","local_ipc_service_recv");
        }
        else {
          ble_printk("%s(): sys reboot because recv cpunet sync package\n");
        }
      }
      sleep(500);
                    /* WARNING: Subroutine does not return */
      sys_reboot(1);
    }
    runtime_info_sync(param_1);
    break;
  case 3:
    uVar4 = sys_clock_tick_get();
    if (GLOBAL_STATE->is_master == true) {
      *(undefined4 *)(param_1 + 0x7ef) = *(undefined4 *)(param_2 + 1);
      param_1[0x7f1] = *(undefined2 *)(param_2 + 5);
    }
    else {
      *(undefined4 *)(param_1 + 0x7f2) = *(undefined4 *)(param_2 + 1);
      param_1[0x7f4] = *(undefined2 *)(param_2 + 5);
    }
    if (1 < LOG_LEVEL) {
      lVar1 = (uVar4 & 0xffffffff) * 1000;
      uVar2 = (uint)lVar1;
      uVar3 = (int)(uVar4 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
              (uint)(0xffff8000 < uVar2);
      if (BLE_DEBUG == 0) {
        printk("%s(): cpunet request update macaddr info uptime %lld bt macaddr esb_master_addr %02X esb_slave_addr %02X \n"
               ,"local_ipc_service_recv",uVar2 + 0x7fff >> 0xf | uVar3 * 0x20000,uVar3 >> 0xf,
               (uint)*(byte *)((int)param_1 + 3),(uint)*(byte *)(param_1 + 2),param_3);
      }
      else {
        ble_printk(
                  "%s(): cpunet request update macaddr info uptime %lld bt macaddr esb_master_addr %02X esb_slave_addr %02X \n"
                  );
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
    uVar2 = (uint)*(byte *)(param_1 + 0x836);
    if (uVar2 == 0) {
      uVar2 = 1;
      *(undefined1 *)(param_1 + 0x836) = 1;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): bt_ready\n","local_ipc_service_recv",uVar2,0,param_1,param_2,param_3);
      }
      else {
        ble_printk("%s(): bt_ready\n");
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
        printk("%s(): IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n","local_ipc_service_recv",
               DAT_20006bd4,DAT_20006bd0,DAT_20006bcc,DAT_20006bc8,param_3);
      }
      else {
        ble_printk("%s(): IPC_RESP_CPUNET_ESB_PACKAGES %d %d %d %d\n");
      }
    }
    break;
  case 0xd:
    *(undefined1 *)(param_1 + 0x837) = param_2[1];
  }
  return 0;
}



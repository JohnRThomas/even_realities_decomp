/*
 * Function: ble_work_thread
 * Entry:    00023d68
 * Prototype: undefined __stdcall ble_work_thread(void * param_1, undefined4 param_2, undefined4 param_3)
 */


void ble_work_thread(void *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar5;
  k_timeout_t timeout;
  byte local_124;
  undefined1 auStack_123 [259];
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): start\n\n");
      param_2 = extraout_r1_00;
      param_3 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): start\n\n","ble_work_thread",param_3,BLE_DEBUG);
      param_2 = extraout_r1;
      param_3 = extraout_r2;
    }
  }
  iVar2 = ancs_main(param_1,param_2,param_3);
  __debug_init();
  if ((iVar2 != 0) && (2 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): err:%d\n\n");
    }
    else {
      ble_printk("%s(): err:%d\n\n","ble_work_thread",iVar2,BLE_DEBUG);
    }
  }
  pvVar3 = malloc(0x2b8);
  iVar2 = LOG_LEVEL;
  *(void **)((int)param_1 + 0x10) = pvVar3;
  if (2 < iVar2) {
    if (BLE_DEBUG == 0) {
      printk("%s(): tx_size:%d\n\n");
    }
    else {
      ble_printk("%s(): tx_size:%d\n\n","ble_work_thread",0x2b8,BLE_DEBUG);
    }
  }
  while( true ) {
    while (pGVar4 = __get_dashboard_state(),
          -1 < (int)((uint)*(ushort *)&pGVar4->field_0x1070 << 0x18)) {
      sleep(1000);
    }
    iVar2 = FUN_000182dc(&local_124);
    if (iVar2 == 0) break;
    *(undefined1 *)((int)param_1 + 0x248) = 0;
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1_01;
    z_impl_k_sem_take((k_sem *)((int)param_1 + 0x218),timeout);
    *(undefined1 *)((int)param_1 + 0x248) = 1;
    bVar1 = DAT_20019a77;
    if ((*(int *)((int)param_1 + 0x35c) != 0) || (*(int *)((int)param_1 + 0x358) != 0))
    goto LAB_00023e28;
    if (DAT_20003051 != -1) {
      *(undefined4 *)((int)param_1 + 0x35c) = 1;
      **(undefined1 **)((int)param_1 + 0x254) = 0xf5;
      *(char *)(*(int *)((int)param_1 + 0x254) + 1) = DAT_20003051;
      DAT_20003051 = -1;
      *(undefined1 *)(*(int *)((int)param_1 + 0x254) + 2) = 0xcb;
      *(undefined4 *)((int)param_1 + 0x358) = 0;
      *(undefined4 *)((int)param_1 + 0x360) = 3;
      if (*(byte *)(*(int *)((int)param_1 + 0x254) + 1) - 9 < 2) {
        *(undefined1 *)(*(int *)((int)param_1 + 0x254) + 2) = *(undefined1 *)((int)param_1 + 0x18);
      }
      goto LAB_00023e28;
    }
    uVar5 = (uint)DAT_20019a77;
    if (uVar5 != 0) {
      *(undefined4 *)((int)param_1 + 0x35c) = 1;
      **(undefined1 **)((int)param_1 + 0x254) = 0xf1;
      DAT_20019a77 = 0;
      *(undefined1 *)(*(int *)((int)param_1 + 0x254) + 1) = 0;
      *(undefined1 *)(*(int *)((int)param_1 + 0x254) + 2) = 0xcc;
      *(undefined4 *)((int)param_1 + 0x358) = 0;
      goto LAB_00023e28;
    }
    if (DAT_20007f2c != 0) {
      *(undefined4 *)((int)param_1 + 0x35c) = 1;
      **(undefined1 **)((int)param_1 + 0x254) = 0xf4;
      *(byte *)(*(int *)((int)param_1 + 0x254) + 1) = bVar1;
      *(undefined1 *)(*(int *)((int)param_1 + 0x254) + 2) = 0xcb;
      DAT_20007f2c = uVar5;
      *(undefined4 *)((int)param_1 + 0x358) = 0;
LAB_00023e28:
      if (*(char *)((int)param_1 + 0x364) == '\0') {
        if (*(size_t *)((int)param_1 + 0x358) == 0) {
          FUN_00023d38(*(byte **)((int)param_1 + *(int *)((int)param_1 + 0x35c) * 4 + 0x250),
                       *(size_t *)((int)param_1 + 0x360),0);
        }
        else {
          FUN_00023d38((byte *)((int)param_1 + 600),*(size_t *)((int)param_1 + 0x358),0);
          memset((byte *)((int)param_1 + 600),0,0x100);
        }
        *(undefined4 *)((int)param_1 + 0x358) = 0;
        *(undefined4 *)((int)param_1 + 0x35c) = 0;
      }
      else {
        iVar2 = __stop_ble_advertising();
        if (iVar2 == 0) {
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): charge plug off, call bt_start. \n\n");
            }
            else {
              ble_printk("%s(): charge plug off, call bt_start. \n\n","ble_work_thread",0,BLE_DEBUG)
              ;
            }
          }
          iVar2 = bt_start();
          if (iVar2 != 0) {
            printk("Advertising failed to start (err %d)\n",iVar2);
          }
        }
        else if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): bt_le_adv_stop failed!!! err=%d\n\n");
          }
          else {
            ble_printk("%s(): bt_le_adv_stop failed!!! err=%d\n\n","ble_work_thread",iVar2,BLE_DEBUG
                      );
          }
        }
        *(undefined1 *)((int)param_1 + 0x364) = 0;
      }
    }
  }
  uVar5 = (uint)local_124;
  if (uVar5 < 0x15) {
    memcpy(*(void **)((int)param_1 + 0x254),auStack_123,uVar5);
    *(undefined4 *)((int)param_1 + 0x35c) = 1;
    *(undefined4 *)((int)param_1 + 0x358) = 0;
    *(uint *)((int)param_1 + 0x360) = (uint)local_124;
  }
  else {
    memcpy((void *)((int)param_1 + 600),auStack_123,uVar5);
    *(uint *)((int)param_1 + 0x358) = uVar5;
  }
  goto LAB_00023e28;
}



/*
 * Function: msg_sync_thread
 * Entry:    0002a8d0
 * Prototype: undefined __stdcall msg_sync_thread(int param_1, uint param_2, undefined4 param_3)
 */


void msg_sync_thread(int param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  GlassesState *pGVar2;
  uint uVar3;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  undefined1 uVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  local_1c = param_2;
  uStack_18 = param_3;
  do {
    while ((pGVar2 = __get_dashboard_state(), pGVar2->field_0x1 == '\x01' ||
           (pGVar2 = __get_dashboard_state(), pGVar2->field_0x1 == '\b'))) {
      z_impl_k_sleep((k_timeout_t)0x28000);
    }
    pGVar2 = __get_dashboard_state();
    if (*(char *)pGVar2 == '\x01') {
      pGVar2 = __get_dashboard_state();
      switch(**(undefined1 **)&pGVar2->field_0x1010) {
      case 1:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0xd,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          FUN_00080224(param_1,0);
          FUN_00080338(0);
          cVar1 = FUN_00030440();
          if (cVar1 == '\0') {
            pGVar2 = __get_dashboard_state();
            uVar4 = 3;
            puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
          }
          else {
            pGVar2 = __get_dashboard_state();
            uVar4 = 2;
            puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
          }
          *puVar5 = uVar4;
          pGVar2 = __get_dashboard_state();
          if (*(int *)pGVar2->___glasses_state != 0x10) {
            pGVar2 = __get_dashboard_state();
            update_persist_task_status((int)pGVar2,0x10,2);
          }
        }
        break;
      case 3:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0xe,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          pGVar2 = __get_dashboard_state();
          uVar4 = 4;
          puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
LAB_0002ab02:
          *puVar5 = uVar4;
        }
        break;
      case 5:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0xf,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          FUN_00030458();
          FUN_00029774(0x18,extraout_r1_00,extraout_r2_01);
          pGVar2 = __get_dashboard_state();
          uVar4 = 6;
          puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
          goto LAB_0002ab02;
        }
        break;
      case 10:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0x10,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          pGVar2 = __get_dashboard_state();
          **(undefined1 **)&pGVar2->field_0x1010 = 0xb;
          pGVar2 = __get_dashboard_state();
          pGVar2->field_0xdb = 8;
        }
        break;
      case 0xd:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0x11,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          pGVar2 = __get_dashboard_state();
          uVar4 = 0xe;
          puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
          goto LAB_0002ab02;
        }
        break;
      case 0xf:
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,0x12,(undefined4 *)0x0,0);
        if ((int)uVar3 < 500) {
          pGVar2 = __get_dashboard_state();
          uVar4 = 0x10;
          puVar5 = *(undefined1 **)&pGVar2->field_0x1010;
          goto LAB_0002ab02;
        }
      }
      pGVar2 = __get_dashboard_state();
      if ((*(char *)(*(int *)&pGVar2->field_0x1014 + 1) == '\x06') &&
         (pGVar2 = __get_dashboard_state(), *(byte *)(*(int *)&pGVar2->field_0x1014 + 3) < 3)) {
        local_1c = CONCAT31(local_1c._1_3_,0xe);
        pGVar2 = __get_dashboard_state();
        local_1c._0_2_ =
             CONCAT11(*(undefined1 *)(*(int *)&pGVar2->field_0x1014 + 1),(undefined1)local_1c);
        pGVar2 = __get_dashboard_state();
        local_1c = (uint)CONCAT12(*(undefined1 *)(*(int *)&pGVar2->field_0x1014 + 3),(short)local_1c
                                 );
        pGVar2 = __get_dashboard_state();
        uVar3 = sync_to_slave((char *)pGVar2,6,&local_1c,4);
        if ((int)uVar3 < 500) {
          pGVar2 = __get_dashboard_state();
          FUN_00080224((int)pGVar2,0);
          pGVar2 = __get_dashboard_state();
          if ((((*(int *)pGVar2->___glasses_state == 0x14) &&
               (pGVar2 = __get_dashboard_state(), **(char **)&pGVar2->field_0x1014 == '\x01')) &&
              (pGVar2 = __get_dashboard_state(),
              *(char *)(*(int *)&pGVar2->field_0x1014 + 1) == '\x04')) &&
             (pGVar2 = __get_dashboard_state(),
             *(char *)(*(int *)&pGVar2->field_0x1014 + 3) == '\x13')) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): evenai_v2 need to show network_err tip\n");
              }
              else {
                ble_printk("%s(): evenai_v2 need to show network_err tip\n","msg_sync_thread",
                           extraout_r2,BLE_DEBUG);
              }
            }
            pGVar2 = __get_dashboard_state();
            *(undefined1 *)(pGVar2->___glasses_state + 4) = 2;
          }
          else {
            pGVar2 = __get_dashboard_state();
            if (*(int *)pGVar2->___glasses_state != 0x14) {
              pGVar2 = __get_dashboard_state();
              **(undefined1 **)&pGVar2->field_0x1014 = 1;
              pGVar2 = __get_dashboard_state();
              memset((void *)(*(int *)&pGVar2->field_0x1014 + 0x10),0,0x200);
              pGVar2 = __get_dashboard_state();
              update_persist_task_status((int)pGVar2,0x14,2);
            }
            pGVar2 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar2->field_0x1014 + 1) = 7;
            uVar6 = FUN_0007fea6();
            pGVar2 = __get_dashboard_state();
            *(undefined8 *)(*(int *)&pGVar2->field_0x1014 + 6) = uVar6;
          }
        }
      }
    }
    else {
      pGVar2 = __get_dashboard_state();
      if (**(char **)&pGVar2->field_0x1010 == '\x01') {
        pGVar2 = __get_dashboard_state();
        FUN_000294d0((int)pGVar2,0xf,(void *)0x0,0);
        FUN_00080224(param_1,0);
      }
      else if (**(char **)&pGVar2->field_0x1010 == '\x05') {
        pGVar2 = __get_dashboard_state();
        FUN_000294d0((int)pGVar2,0x10,(void *)0x0,0);
      }
      pGVar2 = __get_dashboard_state();
      if (*(char *)(*(int *)&pGVar2->field_0x1014 + 1) == '\x06') {
        pGVar2 = __get_dashboard_state();
        local_1c = CONCAT31(local_1c._1_3_,*(undefined1 *)(*(int *)&pGVar2->field_0x1014 + 1));
        pGVar2 = __get_dashboard_state();
        local_1c._0_2_ =
             CONCAT11(*(undefined1 *)(*(int *)&pGVar2->field_0x1014 + 3),(undefined1)local_1c);
        pGVar2 = __get_dashboard_state();
        FUN_000294d0((int)pGVar2,0x11,&local_1c,2);
      }
    }
    FUN_00029684();
    pGVar2 = __get_dashboard_state();
    if ((*(char *)pGVar2 == '\x01') && (DAT_2001093b != '\0')) {
      sync_message_signal_to_slave(3,extraout_r1,extraout_r2_00);
      pGVar2 = __get_dashboard_state();
      if ((pGVar2->field_0x10d6 != '\0') &&
         ((uVar3 = FUN_00035310(), uVar3 != 0 &&
          (pGVar2 = __get_dashboard_state(), pGVar2->field_0xd5 != '\x04')))) {
        pGVar2 = __get_dashboard_state();
        update_temp_task_status((int)pGVar2,4,2);
        pGVar2 = __get_dashboard_state();
        trigger_screen_state_change("IMU:wakeup:new-notification",(int)pGVar2,1,extraout_r3);
        FUN_0002dd98();
      }
      DAT_2001093b = '\0';
      __get_msg_show_state();
      FUN_000359d8();
    }
    k_msleep(200);
  } while( true );
}



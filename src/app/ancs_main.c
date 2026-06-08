/*
 * Function: ancs_main
 * Entry:    00019b10
 * Prototype: undefined4 __stdcall ancs_main(void * param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 ancs_main(void *param_1,undefined4 param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  int iVar2;
  char *pcVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  int iVar4;
  int iVar5;
  
  GLOBAL_STATE.sem_8.limit = (uint)param_1;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Starting Apple Notification Center Service client\n\n");
    }
    else {
      ble_printk("%s(): Starting Apple Notification Center Service client\n\n","ancs_main",param_3,
                 BLE_DEBUG);
    }
  }
  iVar5 = 50;
  iVar4 = 5;
  do {
    for (; (pGVar1 = __get_dashboard_state(), pGVar1->field_0x106c == '\0' && (iVar5 != 0));
        iVar5 = iVar5 + -1) {
      sleep(100);
    }
    iVar2 = bt_enable((bt_ready_cb_t)0x0);
    if (iVar2 == 0) break;
    bt_disable();
    printk("BLE init failed (err %d) bt_retry_count %d\n",iVar2,iVar4);
    iVar4 = iVar4 + -1;
    sleep(1000);
  } while (iVar4 != 0);
  bt_foreach_bond('\0',(void *)0x184fd,(void *)0x0);
  settings_load();
  iVar4 = ancs_c_init((int)param_1 + 0x34,extraout_r1,extraout_r2,extraout_r3);
  if (iVar4 == 0) {
    iVar4 = FUN_00019384();
    if (iVar4 == 0) {
      iVar4 = bt_conn_auth_cb_register((bt_conn_auth_cb *)&DAT_20002338);
      if (iVar4 == 0) {
        iVar4 = bt_conn_auth_info_cb_register((bt_conn_auth_info_cb *)&DAT_20002328);
        if (iVar4 == 0) {
          bt_gatt_cb_register((bt_gatt_cb *)&DAT_20002320);
          iVar4 = __init_nus();
          if (iVar4 == 0) {
            iVar4 = bt_start();
            if (iVar4 == 0) {
              start_ancs_work_thread(param_1);
              return 0;
            }
            printk("Advertising %s failed to start (err %d)\n",&DAT_20010975,iVar4);
            goto LAB_00019ba6;
          }
          pcVar3 = "Failed to init nus.\n";
        }
        else {
          pcVar3 = "Failed to register authorization info callbacks.\n";
        }
      }
      else {
        pcVar3 = "Failed to register authorization callbacks\n";
      }
      printk(pcVar3);
      goto LAB_00019ba6;
    }
    pcVar3 = "GATT Service client init failed (err %d)\n";
  }
  else {
    pcVar3 = "ANCS client init failed (err %d)\n";
  }
  printk(pcVar3,iVar4);
LAB_00019ba6:
  printk("ancs or ncs init failure, reboot it\n");
  sleep(1000);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): reboot because ancs start failed\r\n\n");
    }
    else {
      ble_printk("%s(): reboot because ancs start failed\r\n\n","ancs_main",extraout_r2_00,BLE_DEBUG
                );
    }
  }
  sleep(500);
                    /* WARNING: Subroutine does not return */
  sys_reboot(1);
}



/*
 * Function: ancs_security_changed
 * Entry:    000185f4
 * Prototype: undefined __stdcall ancs_security_changed(bt_conn * param_1, undefined4 param_2, int param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void ancs_security_changed(bt_conn *param_1,undefined4 param_2,int param_3)

{
  bt_security_t bVar1;
  char cVar2;
  k_work_delayable *pkVar3;
  GlassesState *pGVar4;
  int iVar5;
  ushort extraout_r1;
  size_t len;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  undefined4 extraout_r2_02;
  char acStack_38 [32];
  
  pkVar3 = k_work_delayable_from_work((k_work *)param_1);
  bt_addr_le_to_str((bt_addr_le_t *)pkVar3,acStack_38,len);
  if (param_3 == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): %s level %u\n\n","ancs_security_changed",acStack_38,param_2);
      }
      else {
        ble_printk("%s(): %s level %u\n\n","ancs_security_changed",acStack_38,param_2);
      }
    }
    bVar1 = bt_conn_get_security(param_1);
    if (1 < bVar1) {
      GLOBAL_STATE.sem_8.count = 0;
      pkVar3 = k_work_delayable_from_work((k_work *)param_1);
      cVar2 = FUN_00033d5c();
      if ((cVar2 == '\0') &&
         (pGVar4 = __get_dashboard_state(), *(char *)((int)&pGVar4->field2792_0x1087 + 1) == '\x01')
         ) {
        pGVar4 = __get_dashboard_state();
        iVar5 = memcmp(pGVar4->field2791_0x1080 + 1,pkVar3,7);
        if (iVar5 == 0) {
          discover_gattp(param_1,extraout_r1,extraout_r2_00);
        }
      }
    }
    *(undefined1 *)(GLOBAL_STATE.sem_8.limit + 0x367) = 0;
    GLOBAL_STATE.sem_2.wait_q.next = (void *)0x0;
  }
  else {
    uVar6 = extraout_r2;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Security failed: %s level %u err %d\n\n","ancs_security_changed",acStack_38,
               param_2,param_3);
        uVar6 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): Security failed: %s level %u err %d\n\n","ancs_security_changed",
                   acStack_38,param_2);
        uVar6 = extraout_r2_01;
      }
    }
    GLOBAL_STATE.sem_2.wait_q.next = (void *)((int)GLOBAL_STATE.sem_2.wait_q.next + 1);
    if (9 < (int)GLOBAL_STATE.sem_2.wait_q.next) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): reboot because Security failed exceed 10 times, so reboot\r\n\n");
        }
        else {
          ble_printk("%s(): reboot because Security failed exceed 10 times, so reboot\r\n\n",
                     "ancs_security_changed",uVar6,BLE_DEBUG);
        }
      }
      sleep(500);
                    /* WARNING: Subroutine does not return */
      sys_reboot(1);
    }
    bt_conn_set_security(param_1,2);
  }
  return;
}



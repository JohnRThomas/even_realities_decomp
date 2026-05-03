/*
 * Function: ancs_connected
 * Entry:    00018720
 * Prototype: undefined __stdcall ancs_connected(bt_conn * param_1, int param_2)
 */


void ancs_connected(bt_conn *param_1,int param_2)

{
  bt_conn_type bVar1;
  byte bVar2;
  char cVar3;
  k_work_delayable *addr;
  GlassesState *pGVar4;
  int iVar5;
  uint uVar6;
  size_t len;
  char acStack_38 [32];
  
  addr = k_work_delayable_from_work((k_work *)param_1);
  bt_addr_le_to_str((bt_addr_le_t *)addr,acStack_38,len);
  bVar1 = param_1->type;
  bVar2 = param_1->role;
  pGVar4 = __get_dashboard_state();
  printk("%s -- type: 0x%x, role:0x%x force_bind %d",acStack_38,(uint)bVar1,(uint)bVar2,
         (uint)(byte)pGVar4->field_0x1089);
  if (param_2 == 0) {
    cVar3 = FUN_00033d5c();
    if ((cVar3 == '\0') && (pGVar4 = __get_dashboard_state(), pGVar4->field_0x1089 == '\0')) {
      pGVar4 = __get_dashboard_state();
      iVar5 = memcmp(pGVar4->field3664_0x1080 + 1,addr,7);
      if (iVar5 != 0) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): disconnect because invalid mac %s -- type: 0x%x, role:0x%x \n\n",
                   "ancs_connected",acStack_38,(uint)param_1->type,(uint)param_1->role);
          }
          else {
            ble_printk("%s(): disconnect because invalid mac %s -- type: 0x%x, role:0x%x \n\n",
                       "ancs_connected",acStack_38,(uint)param_1->type);
          }
        }
        bt_conn_disconnect(param_1,'\x05');
        return;
      }
    }
    bt_conn_le_param_update(param_1,(bt_le_conn_param *)&DAT_20002f80);
    pGVar4 = __get_dashboard_state();
    uVar6 = FUN_0007f370();
    *(uint *)&pGVar4->field_0xae4 = uVar6;
    pGVar4 = __get_dashboard_state();
    uVar6 = FUN_0007f370();
    *(uint *)&pGVar4->field_0xae8 = uVar6;
    uVar6 = GLOBAL_STATE.sem_8.limit;
    *(undefined1 *)(GLOBAL_STATE.sem_8.limit + 0x365) = 1;
    *(undefined1 *)(uVar6 + 0x367) = 1;
    DAT_20007ef4 = param_1;
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): failed (err 0x%02x)\n\n");
    }
    else {
      ble_printk("%s(): failed (err 0x%02x)\n\n","ancs_connected",param_2,BLE_DEBUG);
    }
  }
  return;
}



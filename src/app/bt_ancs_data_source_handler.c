/*
 * Function: bt_ancs_data_source_handler
 * Entry:    00018d40
 * Prototype: undefined __stdcall bt_ancs_data_source_handler(undefined4 param_1, byte * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_ancs_data_source_handler(undefined4 param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  GlassesState *pGVar3;
  byte *pbVar4;
  
  pbVar4 = param_2;
  iVar1 = FUN_00018320();
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): bt_ancs_data_source_handler response->command_id %d\n");
    }
    else {
      ble_printk("%s(): bt_ancs_data_source_handler response->command_id %d\n",
                 "bt_ancs_data_source_handler",(uint)*param_2,BLE_DEBUG,param_1,pbVar4);
    }
  }
  if (*param_2 == 0) {
    if (*(int *)(param_2 + 8) == 0) {
      _DAT_20006c80 = *(undefined4 *)(param_2 + 4);
      _DAT_20006c84 = *(undefined4 *)(param_2 + 8);
      _DAT_20006c88 = *(undefined4 *)(param_2 + 0xc);
      DAT_2001095f = '\x01';
    }
  }
  else if (((*param_2 == 1) && (DAT_2001095f != '\0')) && (_DAT_20006c8c != DAT_2000231c)) {
    uVar2 = FUN_0007f370();
    pGVar3 = __get_dashboard_state();
    if (9999 < uVar2 - *(int *)&pGVar3->field_0xae8) {
      while ((pGVar3 = __get_dashboard_state(), pGVar3->field_0x1 == '\x01' ||
             (pGVar3 = __get_dashboard_state(), pGVar3->field_0x1 == '\b'))) {
        z_impl_k_sleep((k_timeout_t)0x28000);
      }
      pGVar3 = __get_dashboard_state();
      if (((((pGVar3->field20_0xc8[0xd] != '\v') &&
            (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\n')) &&
           ((pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\t' &&
            ((((pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\f' &&
               (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x10')) &&
              (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x14')) &&
             ((pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x0e' &&
              (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x0f')))))))) &&
          (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x11')) &&
         ((pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x12' &&
          (pGVar3 = __get_dashboard_state(), pGVar3->field20_0xc8[0xd] != '\x13')))) {
        DAT_2000231c = _DAT_20006c8c;
        *(uint *)(iVar1 + 0x1e4) = (uint)DAT_20006c90;
        enqueue_ancs((void *)(iVar1 + 0x34));
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): =========================>bt_ancs_get_attr_data_sem %d evt_id %d action %d\n"
                  );
          }
          else {
            ble_printk("%s(): =========================>bt_ancs_get_attr_data_sem %d evt_id %d action %d\n"
                       ,"bt_ancs_data_source_handler",_DAT_20006c8c,(uint)DAT_20006c90,
                       *(undefined4 *)(iVar1 + 0x1e4));
          }
        }
        memset((void *)(iVar1 + 0x34),0,0x1b4);
        k_sem_give((k_sem *)(iVar1 + 0x1e8));
        DAT_2001095f = '\0';
      }
    }
  }
  return;
}



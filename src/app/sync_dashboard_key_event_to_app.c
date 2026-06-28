/*
 * Function: sync_dashboard_key_event_to_app
 * Entry:    0003cd04
 * Prototype: undefined __stdcall sync_dashboard_key_event_to_app(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void sync_dashboard_key_event_to_app
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  pGVar2 = __get_dashboard_state();
  if (*(char *)pGVar2 == '\x02') {
    return;
  }
  local_18 = 0x822;
  local_10 = 0;
  uStack_c = 0;
  local_14 = 2;
  pGVar2 = __get_dashboard_state();
  uVar3 = local_14;
  local_14._3_1_ = SUB41(uVar3,3);
  local_14._0_3_ =
       CONCAT12(PANE_MODE,CONCAT11(pGVar2->dashboard_ts->field_0x65,(undefined1)local_14));
  if (PANE_MODE == 0) {
    bVar1 = __getNotesIndex();
  }
  else if (PANE_MODE == 1) {
    bVar1 = getStocksIndex();
  }
  else {
    if (PANE_MODE != 2) {
      if (PANE_MODE == 3) {
        bVar1 = getCalenadrIndex();
        local_14 = CONCAT13(bVar1 + 1,(undefined3)local_14);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): calendar index = %d\n");
          }
          else {
            ble_printk("%s(): calendar index = %d\n","sync_dashboard_key_event_to_app",
                       (uint)(byte)(bVar1 + 1),BLE_DEBUG);
          }
        }
      }
      goto LAB_0003cd4c;
    }
    bVar1 = getNewsIndex();
  }
  local_14 = CONCAT13(bVar1 + 1,(undefined3)local_14);
LAB_0003cd4c:
  uVar3 = send_response_data_to_msgqueue(&local_18,8);
  send_response_data_to_ble(uVar3,extraout_r1,extraout_r2,extraout_r3);
  return;
}



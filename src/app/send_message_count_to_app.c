/*
 * Function: ?_send_message_count_to_app
 * Entry:    0003cc64
 * Prototype: undefined __stdcall ?_send_message_count_to_app(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void __send_message_count_to_app
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  undefined4 uVar4;
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
  local_18 = 0xa22;
  local_10 = 0;
  uStack_c = 0;
  local_14 = 1;
  uVar3 = FUN_00035310();
  local_14._0_2_ = CONCAT11((char)uVar3,(undefined1)local_14);
  pGVar2 = __get_dashboard_state();
  local_14._0_3_ = CONCAT12(pGVar2->dashboard_ts->field_0x60,(undefined2)local_14);
  pGVar2 = __get_dashboard_state();
  local_14 = CONCAT13(pGVar2->dashboard_ts->field_0x65,(undefined3)local_14);
  pGVar2 = __get_dashboard_state();
  local_10 = CONCAT31(local_10._1_3_,pGVar2->dashboard_ts->field_0x66);
  if (PANE_MODE == '\0') {
    bVar1 = __getNotesIndex();
  }
  else if (PANE_MODE == '\x01') {
    bVar1 = getStocksIndex();
  }
  else if (PANE_MODE == '\x02') {
    bVar1 = getNewsIndex();
  }
  else {
    if (PANE_MODE != '\x03') goto LAB_0003ccd0;
    bVar1 = getCalenadrIndex();
  }
  local_10._0_2_ = CONCAT11(bVar1 + 1,(undefined1)local_10);
LAB_0003ccd0:
  uVar4 = send_response_data_to_msgqueue(&local_18,10);
  send_response_data_to_ble(uVar4,extraout_r1,extraout_r2,extraout_r3);
  return;
}



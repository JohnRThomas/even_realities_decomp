/*
 * Function: FUN_0002df6c
 * Entry:    0002df6c
 * Prototype: undefined __stdcall FUN_0002df6c(void)
 */


void FUN_0002df6c(void)

{
  byte bVar1;
  char cVar2;
  GlassesState *pGVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  
  k_uptime_get();
  if (BLE_DEBUG == 0) {
    bVar1 = FUN_00035a78();
    printk("[csh_debug_msg] set touch key flag get_msg_show_state() %d\n",(uint)bVar1);
  }
  else {
    bVar1 = FUN_00035a78();
    ble_printk("[csh_debug_msg] set touch key flag get_msg_show_state() %d\n",(char *)(uint)bVar1,
               extraout_r2,extraout_r3);
  }
  cVar2 = FUN_00035a78();
  if ((cVar2 == '\x02') || (cVar2 = FUN_00035a78(), cVar2 == '\x04')) {
    __g_arrMsgContent_count();
    pGVar3 = __get_dashboard_state();
    bVar1 = pGVar3->field_0xfee;
    pGVar3 = __get_dashboard_state();
    uVar4 = FUN_0002df54((uint)bVar1,(uint)(byte)pGVar3->field_0x10d7);
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0xdb = (char)uVar4;
  }
  pGVar3 = __get_dashboard_state();
  uVar5 = FUN_00035310();
  pGVar3->field_0xdd = (char)uVar5;
  pGVar3 = __get_dashboard_state();
  if (pGVar3->field_0xdd == '\0') {
    FUN_00035abc(0);
    pGVar3 = __get_dashboard_state();
    if ((pGVar3->field_0xd5 != '\x01') &&
       (pGVar3 = __get_dashboard_state(), *(char *)&pGVar3->imu_fusion_context == '\x02')) {
      pGVar3 = __get_dashboard_state();
      trigger_screen_state_change("IMU:wakeup:dashboard",(int)pGVar3,1,extraout_r3_00);
    }
    pGVar3 = __get_dashboard_state();
    if (*(char *)pGVar3 == '\x01') {
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0xdb = 0;
    }
  }
  else {
    clear_timeout_message(1);
    FUN_000359fc();
    DAT_20019a6c = 1;
  }
  return;
}



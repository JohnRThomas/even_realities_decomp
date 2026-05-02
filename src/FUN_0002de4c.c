/*
 * Function: FUN_0002de4c
 * Entry:    0002de4c
 * Prototype: undefined __stdcall FUN_0002de4c(void)
 */


void FUN_0002de4c(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  GlassesState *pGVar4;
  char *extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  undefined4 extraout_r2_01;
  
  while ((cVar1 = FUN_00035a78(), cVar1 == '\x05' && (bVar2 = FUN_00035acc(), bVar2 == 2))) {
    if (BLE_DEBUG == 0) {
      printk("[csh_debug_msg] check showing msg timeout \n");
      uVar3 = extraout_r1_01;
      uVar5 = extraout_r2_01;
    }
    else {
      ble_printk("[csh_debug_msg] check showing msg timeout \n",extraout_r1,extraout_r2,BLE_DEBUG);
      uVar3 = extraout_r1_00;
      uVar5 = extraout_r2_00;
    }
    uVar3 = sync_message_signal_to_slave(2,uVar3,uVar5);
    if ((int)uVar3 < 3000) {
      __g_arrMsgContent_count();
      pGVar4 = __get_dashboard_state();
      if (pGVar4->field_0xdd == '\0') {
        FUN_00035abc(0);
        return;
      }
      FUN_00035abc(6);
    }
  }
  return;
}



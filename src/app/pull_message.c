/*
 * Function: pull_message
 * Entry:    0003591c
 * Prototype: byte __stdcall pull_message(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


byte pull_message(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GlassesState *pGVar1;
  char *pcVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  if (param_1 == (undefined4 *)0x0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [%s-%d] message is NULL \n\n","pull_message","pull_message",0x3ca,param_4);
      }
      else {
        ble_printk("%s(): [%s-%d] message is NULL \n\n","pull_message","pull_message",0x3ca);
      }
    }
  }
  else {
    pGVar1 = __get_dashboard_state();
    if ((byte)pGVar1->field20_0xc8[0x15] < 0xb) {
      pcVar2 = (char *)(uint)DAT_2001aef9;
      *param_1 = &DAT_2000878c + (int)pcVar2 * 0x6d;
      if (BLE_DEBUG != 0) {
        ble_printk("[csh_debug_msg]g_curShowMsgIdx is %d \n",pcVar2,&BLE_DEBUG,BLE_DEBUG);
        return DAT_2001aef9;
      }
      printk("[csh_debug_msg]g_curShowMsgIdx is %d \n");
      return DAT_2001aef9;
    }
    if (BLE_DEBUG == 0) {
      pGVar1 = __get_dashboard_state();
      printk("exception handle, GLOBAL->master_sync_pkg.panel_data_pkg.unread_msg_num is %d \n",
             (uint)(byte)pGVar1->field20_0xc8[0x15]);
    }
    else {
      pGVar1 = __get_dashboard_state();
      ble_printk("exception handle, GLOBAL->master_sync_pkg.panel_data_pkg.unread_msg_num is %d \n",
                 (char *)(uint)(byte)pGVar1->field20_0xc8[0x15],extraout_r2,extraout_r3);
    }
  }
  return 10;
}



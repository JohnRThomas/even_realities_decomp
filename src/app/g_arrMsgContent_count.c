/*
 * Function: ?_g_arrMsgContent_count
 * Entry:    000358b0
 * Prototype: undefined1 __stdcall ?_g_arrMsgContent_count(void)
 */


undefined1 __g_arrMsgContent_count(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  undefined4 extraout_r2;
  char *pcVar4;
  
  pGVar2 = __get_dashboard_state();
  bVar1 = pGVar2->field20_0xc8[0x15];
  if ((bVar1 != 0) && (pcVar4 = (char *)(bVar1 - 1), (&DAT_20008790)[(int)pcVar4 * 0x6d] != 0)) {
    clear_timeout_message(1);
    if (pcVar4 == (char *)0x0) {
      DAT_2001aef9 = '\0';
    }
    else {
      DAT_2001aef9 = bVar1 - 2;
    }
    if (BLE_DEBUG == 0) {
      printk("[csh_debug_msg]msg_count_dec unread_msg_num is %d \n");
    }
    else {
      ble_printk("[csh_debug_msg]msg_count_dec unread_msg_num is %d \n",pcVar4,extraout_r2,BLE_DEBUG
                );
    }
    pGVar2 = __get_dashboard_state();
    uVar3 = FUN_00035310();
    pGVar2->field20_0xc8[0x15] = (char)uVar3;
  }
  pGVar2 = __get_dashboard_state();
  return pGVar2->field20_0xc8[0x15];
}



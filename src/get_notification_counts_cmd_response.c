/*
 * Function: get_notification_counts_cmd_response
 * Entry:    00035070
 * Prototype: undefined4 __stdcall get_notification_counts_cmd_response(int param_1, byte * param_2, undefined4 param_3)
 */


undefined4 get_notification_counts_cmd_response(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): input param is error !\n");
      }
      else {
        ble_printk("%s(): input param is error !\n","get_notification_counts_cmd_response",param_3,
                   BLE_DEBUG);
      }
    }
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0xdd);
    *param_2 = bVar1;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [csh_debug]unread_msg_num is: %d\n");
      }
      else {
        ble_printk("%s(): [csh_debug]unread_msg_num is: %d\n","get_notification_counts_cmd_response"
                   ,(uint)bVar1,BLE_DEBUG);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



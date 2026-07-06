/*
 * Function: get_notification_counts_cmd_process
 * Entry:    000350d0
 * Prototype: void __stdcall get_notification_counts_cmd_process(int param_1, byte * param_2, uint8_t * param_3)
 */


void get_notification_counts_cmd_process(int param_1,byte *param_2,uint8_t *param_3)

{
  FUN_0007f4c6(param_1,param_2,1);
  param_3[1] = 0xc9;
  param_3[2] = *param_2;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): BLE_REQ_GET_ESB_CHANNEL: %d\n","get_notification_counts_cmd_process");
    }
    else {
      ble_printk("%s(): BLE_REQ_GET_ESB_CHANNEL: %d\n");
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00035108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0xc))(param_3,0x14);
  return;
}



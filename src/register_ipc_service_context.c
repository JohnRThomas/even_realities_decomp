/*
 * Function: register_ipc_service_context
 * Entry:    00027eec
 * Prototype: undefined4 __stdcall register_ipc_service_context(ipc_service_context * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4
register_ipc_service_context(ipc_service_context *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1->ipc_service_send_cb = 0x27d61;
  param_1->ipc_service_recv_cb = 0x27cf5;
  GLOBAL_IPC_SERVICE_CONTEXT = param_1;
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): exit\n\n");
    }
    else {
      ble_printk("%s(): exit\n\n","register_ipc_service_context",param_3,BLE_DEBUG);
    }
  }
  return 0;
}



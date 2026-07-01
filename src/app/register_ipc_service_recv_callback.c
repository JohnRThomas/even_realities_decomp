/*
 * Function: register_ipc_service_recv_callback
 * Entry:    00027cf4
 * Prototype: undefined4 __stdcall register_ipc_service_recv_callback(byte * param_1)
 */


undefined4 register_ipc_service_recv_callback(byte *param_1)

{
  ipc_service_context *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = GLOBAL_IPC_SERVICE_CONTEXT;
  iVar3 = *(int *)&GLOBAL_IPC_SERVICE_CONTEXT->field_0x4;
  if (iVar3 < 0x16) {
    *(byte **)(&GLOBAL_IPC_SERVICE_CONTEXT->field_0x8 + iVar3 * 4) = param_1;
    uVar2 = 0;
    *(int *)&piVar1->field_0x4 = iVar3 + 1;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ipc_service_register(%d,%s) %d,total must < %d\n");
      }
      else {
        ble_printk("%s(): ipc_service_register(%d,%s) %d,total must < %d\n",
                   "register_ipc_service_recv_callback",(uint)*param_1,*(undefined4 *)(param_1 + 4),
                   iVar3,0x16);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



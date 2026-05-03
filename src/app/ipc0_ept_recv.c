/*
 * Function: ipc0_ept_recv
 * Entry:    00027c54
 * Prototype: undefined __stdcall ipc0_ept_recv(byte * param_1, int param_2)
 */


void ipc0_ept_recv(byte *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = 0;
  puVar2 = (undefined4 *)&GLOBAL_IPC_SERVICE_CONTEXT->field_0x4;
  iVar1 = *puVar2;
  while( true ) {
    if (iVar1 <= iVar3) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): NOT MATCH(cmd=%x)! ipc_receiver_index: %d, len:%d, received_data: %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x\n"
                );
        }
        else {
          ble_printk("%s(): NOT MATCH(cmd=%x)! ipc_receiver_index: %d, len:%d, received_data: %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x\n"
                     ,"ipc0_ept_recv",(uint)*param_1,iVar1);
        }
      }
      return;
    }
    puVar2 = puVar2 + 1;
    pbVar4 = (byte *)*puVar2;
    if ((pbVar4 != (byte *)0x0) && ((uint)*pbVar4 == (uint)*param_1)) break;
    iVar3 = iVar3 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00027cd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(pbVar4 + 8))(&GLOBAL_IPC_SERVICE_CONTEXT[-0x12].field_0x3c,param_1 + 1,param_2 + -1);
  return;
}



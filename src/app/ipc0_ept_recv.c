/*
 * Function: ipc0_ept_recv
 * Entry:    00027c54
 * Prototype: undefined __stdcall ipc0_ept_recv(byte * param_1, int param_2)
 */


void ipc0_ept_recv(byte *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = 0;
  uVar1 = (uint)*param_1;
  puVar3 = (undefined4 *)&GLOBAL_IPC_SERVICE_CONTEXT->field_0x4;
  iVar2 = *puVar3;
  while( true ) {
    if (iVar2 <= iVar4) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): NOT MATCH(cmd=%x)! ipc_receiver_index: %d, len:%d, received_data: %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x\n"
                );
        }
        else {
          ble_printk("%s(): NOT MATCH(cmd=%x)! ipc_receiver_index: %d, len:%d, received_data: %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x\n"
                     ,"ipc0_ept_recv",uVar1,iVar2,param_2,uVar1,(uint)param_1[1],(uint)param_1[2],
                     (uint)param_1[3],(uint)param_1[4],(uint)param_1[5],(uint)param_1[6],
                     (uint)param_1[7]);
        }
      }
      return;
    }
    puVar3 = puVar3 + 1;
    pbVar5 = (byte *)*puVar3;
    if ((pbVar5 != (byte *)0x0) && (*pbVar5 == uVar1)) break;
    iVar4 = iVar4 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00027cd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(pbVar5 + 8))(&GLOBAL_IPC_SERVICE_CONTEXT[-0x12].field_0x3c,param_1 + 1,param_2 + -1);
  return;
}



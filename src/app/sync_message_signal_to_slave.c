/*
 * Function: sync_message_signal_to_slave
 * Entry:    0002ddc0
 * Prototype: uint __stdcall sync_message_signal_to_slave(undefined1 param_1, uint param_2, undefined4 param_3)
 */


uint sync_message_signal_to_slave(byte param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  GlassesState *pGVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int iVar5;
  bool bVar6;
  int64_t iVar7;
  int64_t iVar8;
  uint local_1c;
  undefined4 uStack_18;
  
  uVar1 = (uint)param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  iVar7 = k_uptime_get();
  local_1c = CONCAT31((int3)(local_1c >> 8),param_1) & 0xffff00ff;
  pGVar2 = __get_dashboard_state();
  uVar3 = sync_to_slave((char *)pGVar2,7,&local_1c,1);
  pGVar2 = __get_dashboard_state();
  if (pGVar2->field_0x106e == '\x02') {
    pcVar4 = "%s successfully !";
  }
  else {
    pcVar4 = "%s failed !";
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar4);
  }
  else {
    ble_printk(pcVar4,"sync_message_signal_to_slave",extraout_r2,BLE_DEBUG,uVar1);
  }
  iVar8 = k_uptime_get();
  pcVar4 = (char *)((ulonglong)iVar8 >> 0x20);
  iVar5 = (int)((ulonglong)(iVar7 + 3000) >> 0x20);
  bVar6 = (uint)(iVar7 + 3000) < (uint)iVar8;
  if ((int)((iVar5 - (int)pcVar4) - (uint)bVar6) < 0 !=
      (SBORROW4(iVar5,(int)pcVar4) != SBORROW4(iVar5 - (int)pcVar4,(uint)bVar6))) {
    if (BLE_DEBUG == 0) {
      printk("retry sync_to_slave failed !");
    }
    else {
      ble_printk("retry sync_to_slave failed !",pcVar4,extraout_r2_00,BLE_DEBUG);
    }
  }
  return uVar3;
}



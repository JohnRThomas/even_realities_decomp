/*
 * Function: sync_message_signal_to_slave
 * Entry:    0002ddc0
 * Prototype: uint __stdcall sync_message_signal_to_slave(undefined1 param_1, uint param_2, undefined4 param_3)
 */


uint sync_message_signal_to_slave(undefined1 param_1,uint param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  uint uVar2;
  char *fmt;
  int iVar3;
  int iVar4;
  bool bVar5;
  int64_t iVar6;
  int64_t iVar7;
  uint local_1c;
  undefined4 uStack_18;
  
  local_1c = param_2;
  uStack_18 = param_3;
  iVar6 = k_uptime_get();
  local_1c = CONCAT31((int3)(local_1c >> 8),param_1) & 0xffff00ff;
  pGVar1 = __get_dashboard_state();
  uVar2 = sync_to_slave(&pGVar1->is_master,7,&local_1c,1);
  pGVar1 = __get_dashboard_state();
  if (pGVar1->field_0x106e == '\x02') {
    fmt = "%s successfully !";
  }
  else {
    fmt = "%s failed !";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,"sync_message_signal_to_slave");
  }
  else {
    ble_printk(fmt);
  }
  iVar7 = k_uptime_get();
  iVar3 = (int)((ulonglong)iVar7 >> 0x20);
  iVar4 = (int)((ulonglong)(iVar6 + 3000) >> 0x20);
  bVar5 = (uint)(iVar6 + 3000) < (uint)iVar7;
  if ((int)((iVar4 - iVar3) - (uint)bVar5) < 0 !=
      (SBORROW4(iVar4,iVar3) != SBORROW4(iVar4 - iVar3,(uint)bVar5))) {
    if (BLE_DEBUG == 0) {
      printk("retry sync_to_slave failed !");
    }
    else {
      ble_printk("retry sync_to_slave failed !");
    }
  }
  return uVar2;
}



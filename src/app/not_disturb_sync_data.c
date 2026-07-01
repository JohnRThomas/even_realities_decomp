/*
 * Function: not_disturb_sync_data
 * Entry:    0003f104
 * Prototype: undefined4 __stdcall not_disturb_sync_data(undefined1 * param_1, uint param_2, undefined4 param_3)
 */


undefined4 not_disturb_sync_data(undefined1 *param_1,uint param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  uint uVar2;
  char *fmt;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 extraout_r2_00;
  undefined1 *puVar4;
  undefined4 local_14;
  undefined4 uStack_10;
  
  if (param_1 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  puVar4 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  pGVar1 = __get_dashboard_state();
  if (*(char *)pGVar1 != '\x01') {
    local_14 = CONCAT22(local_14._2_2_,5);
    if (param_2 != 0) {
      local_14._0_2_ = CONCAT11(*param_1,5);
    }
    pGVar1 = __get_dashboard_state();
    uVar2 = FUN_000294d0((int)pGVar1,0xe,&local_14,(param_2 != 0) + 1);
    if (uVar2 < 2000) {
      return 0;
    }
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    fmt = "%s(): not_disturb SYNC TO master failed...\n";
    uVar3 = extraout_r2_00;
    goto LAB_0003f156;
  }
  local_14 = 5;
  if (param_2 < 4) {
    if (param_2 != 0) goto LAB_0003f122;
  }
  else {
    param_2 = 3;
LAB_0003f122:
    memcpy((void *)((int)&local_14 + 1),param_1,param_2);
  }
  pGVar1 = __get_dashboard_state();
  uVar2 = sync_to_slave((char *)pGVar1,6,&local_14,param_2 + 1 & 0xff);
  if ((int)uVar2 < 3000) {
    return 0;
  }
  if (LOG_LEVEL < 1) {
    return 0xffffffff;
  }
  fmt = "%s(): not_disturb SYNC TO Slave failed...\n";
  uVar3 = extraout_r2;
LAB_0003f156:
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"not_disturb_sync_data",uVar3,BLE_DEBUG,puVar4);
  }
  return 0xffffffff;
}



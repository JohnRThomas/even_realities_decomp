/*
 * Function: getDashboardStartUpModeInfofromFlash
 * Entry:    00025fe4
 * Prototype: byte __stdcall getDashboardStartUpModeInfofromFlash(undefined4 param_1, uint param_2, undefined4 param_3)
 */


byte getDashboardStartUpModeInfofromFlash(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  byte bVar2;
  GlassesState *pGVar3;
  int iVar4;
  code *pcVar5;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): read setting flash data to ram...\r\n\n");
    }
    else {
      ble_printk("%s(): read setting flash data to ram...\r\n\n",
                 "getDashboardStartUpModeInfofromFlash",param_3,BLE_DEBUG,param_1);
    }
  }
  bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
  if (bVar1) {
    local_14 = local_14 & 0xff000000;
    pGVar3 = __get_dashboard_state();
    pcVar5 = *(code **)&pGVar3->field_0x1044;
    pGVar3 = __get_dashboard_state();
    iVar4 = (*pcVar5)(pGVar3,0x13e000,&local_14,3);
    if (iVar4 == 0) {
      if (((char)local_14 == -0x56) && (local_14._2_1_ != 0xff)) {
        DAT_20019132 = local_14._2_1_;
      }
      else {
        DAT_20019132 = 0;
      }
      bVar2 = DAT_20019132;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): dashboard startup mode = %d\n");
          bVar2 = DAT_20019132;
        }
        else {
          ble_printk("%s(): dashboard startup mode = %d\n","getDashboardStartUpModeInfofromFlash",
                     (uint)DAT_20019132,BLE_DEBUG);
          bVar2 = DAT_20019132;
        }
      }
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s():  form address [%d] read data failed.\n\n");
        }
        else {
          ble_printk("%s():  form address [%d] read data failed.\n\n",
                     "getDashboardStartUpModeInfofromFlash",0x13e000,BLE_DEBUG);
        }
      }
      bVar2 = 0;
    }
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s():  [%s] device not ready.\n\n");
      }
      else {
        ble_printk("%s():  [%s] device not ready.\n\n","getDashboardStartUpModeInfofromFlash",
                   "mx25r6435f@0",BLE_DEBUG,param_1);
      }
    }
    bVar2 = 0xff;
  }
  return bVar2;
}



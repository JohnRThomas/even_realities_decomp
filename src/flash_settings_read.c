/*
 * Function: flash_settings_read
 * Entry:    00024570
 * Prototype: int __stdcall flash_settings_read(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int flash_settings_read(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  while( true ) {
    bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
    if (bVar1) {
      pGVar2 = __get_dashboard_state();
      pcVar4 = *(code **)&pGVar2->field_0x1044;
      pGVar2 = __get_dashboard_state();
      iVar3 = (*pcVar4)(pGVar2,param_1,param_2,param_3,param_4);
      if (iVar3 == 0) {
        return 0;
      }
      printk("Flash read failed! %d\n",iVar3);
    }
    else {
      printk(" [%s] device not ready.\n","mx25r6435f@0");
      iVar3 = -1;
    }
    if (iVar5 == 10) break;
    z_impl_k_sleep((k_timeout_t)0xccd);
    iVar5 = iVar5 + 1;
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): flash read fail, retry again, retry time %d\n");
      }
      else {
        ble_printk("%s(): flash read fail, retry again, retry time %d\n","flash_settings_read",iVar5
                   ,BLE_DEBUG);
      }
    }
  }
  return iVar3;
}



/*
 * Function: getAppLanguageInfofromFlash
 * Entry:    00025f18
 * Prototype: byte __stdcall getAppLanguageInfofromFlash(undefined4 param_1, uint param_2, undefined4 param_3)
 */


byte getAppLanguageInfofromFlash(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  code *pcVar4;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): read setting flash data to ram...\r\n\n");
    }
    else {
      ble_printk("%s(): read setting flash data to ram...\r\n\n","getAppLanguageInfofromFlash",
                 param_3,BLE_DEBUG,param_1);
    }
  }
  bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
  if (bVar1) {
    local_14 = local_14 & 0xff000000;
    pGVar2 = __get_dashboard_state();
    pcVar4 = *(code **)&pGVar2->field_0x1044;
    pGVar2 = __get_dashboard_state();
    iVar3 = (*pcVar4)(pGVar2,0x13e000,&local_14,3);
    if (iVar3 == 0) {
      if ((char)local_14 == -0x56) {
        BYTE_20019131 = local_14._1_1_;
      }
      else {
        local_14._1_1_ = 2;
        BYTE_20019131 = local_14._1_1_;
      }
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s():  form address [%d] read data failed.\n\n");
        }
        else {
          ble_printk("%s():  form address [%d] read data failed.\n\n","getAppLanguageInfofromFlash",
                     0x13e000,BLE_DEBUG);
        }
      }
      local_14._1_1_ = 0;
    }
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s():  [%s] device not ready.\n\n");
      }
      else {
        ble_printk("%s():  [%s] device not ready.\n\n","getAppLanguageInfofromFlash","mx25r6435f@0",
                   BLE_DEBUG,param_1);
      }
    }
    local_14._1_1_ = 0xff;
  }
  return local_14._1_1_;
}



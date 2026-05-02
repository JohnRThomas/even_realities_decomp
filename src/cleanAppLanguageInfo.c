/*
 * Function: cleanAppLanguageInfo
 * Entry:    00025c7c
 * Prototype: undefined4 __stdcall cleanAppLanguageInfo(undefined4 param_1, undefined4 param_2)
 */


undefined4 cleanAppLanguageInfo(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined4 local_10;
  undefined1 uStack_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  uStack_c = 0;
  local_b = 0;
  local_10 = 2;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003b34,&local_10,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): SEND APP Language Command...\n");
      }
      else {
        ble_printk("%s(): SEND APP Language Command...\n","cleanAppLanguageInfo",extraout_r2,
                   BLE_DEBUG);
      }
    }
    k_sem_give((k_sem *)&DAT_200083c4);
    uVar2 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): setting flash store queue fill failed\r\n\n");
      }
      else {
        ble_printk("%s(): setting flash store queue fill failed\r\n\n","cleanAppLanguageInfo",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



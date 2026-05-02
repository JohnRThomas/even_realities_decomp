/*
 * Function: flash_ops_thread
 * Entry:    00025538
 * Prototype: undefined __stdcall flash_ops_thread(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void flash_ops_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  k_timeout_t timeout;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): flash op thread startup ...\n");
      param_2 = extraout_r1_02;
    }
    else {
      ble_printk("%s(): flash op thread startup ...\n","flash_ops_thread",param_3,BLE_DEBUG);
      param_2 = extraout_r1;
    }
  }
  do {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = param_2;
    z_impl_k_sem_take((k_sem *)&DAT_200083c4,timeout);
    while (iVar1 = FUN_00030bf8(), iVar1 != 0) {
      audioStreamFileManagerHandler();
    }
    while (uVar2 = FUN_00026894(), uVar2 != 0) {
      QuickNoteStoreHandler(uVar2,extraout_r1_00,extraout_r2);
    }
    while (iVar1 = FUN_000260e8(), param_2 = extraout_r1_01, iVar1 != 0) {
      SettingStoreHandler();
    }
  } while( true );
}



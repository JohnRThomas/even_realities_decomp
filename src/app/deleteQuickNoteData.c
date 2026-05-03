/*
 * Function: deleteQuickNoteData
 * Entry:    000266c4
 * Prototype: undefined4 __stdcall deleteQuickNoteData(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 deleteQuickNoteData(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  undefined4 local_18;
  uint local_14;
  undefined4 uStack_10;
  
  local_18 = 0x10002;
  local_14 = CONCAT31((int3)((uint)param_2 >> 8),(char)param_1) & 0xffff00ff;
  uStack_10 = param_3;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003b00,&local_18,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): SEND QUICKNOTE TEXT delete(%d) Command...\n");
      }
      else {
        ble_printk("%s(): SEND QUICKNOTE TEXT delete(%d) Command...\n","deleteQuickNoteData",param_1
                   ,BLE_DEBUG);
      }
    }
    k_sem_give((k_sem *)&DAT_200083c4);
    uVar2 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): quicknote flash store queue fill failed\r\n\n");
      }
      else {
        ble_printk("%s(): quicknote flash store queue fill failed\r\n\n","deleteQuickNoteData",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



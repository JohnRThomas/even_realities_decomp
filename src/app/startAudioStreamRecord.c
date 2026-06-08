/*
 * Function: startAudioStreamRecord
 * Entry:    00030c04
 * Prototype: undefined4 __stdcall startAudioStreamRecord(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 startAudioStreamRecord(void)

{
  int iVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined2 local_d8 [2];
  undefined1 local_d4;
  undefined1 auStack_d3 [203];
  
  memset(auStack_d3,0,0xcb);
  local_d4 = 1;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a30,&local_d4,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    k_sem_give((k_sem *)&DAT_200083c4);
    uVar3 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): start up audio record failed\r\n\n");
      }
      else {
        ble_printk("%s(): start up audio record failed\r\n\n","startAudioStreamRecord",extraout_r2,
                   BLE_DEBUG);
      }
    }
    local_d8[0] = 1;
    pGVar2 = __get_dashboard_state();
    sync_to_slave((char *)pGVar2,6,(undefined4 *)local_d8,2);
    display_DelayClose(10000);
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): because startup auido record failed,exit quicknote ....\n");
      }
      else {
        ble_printk("%s(): because startup auido record failed,exit quicknote ....\n",
                   "startAudioStreamRecord",extraout_r2_00,BLE_DEBUG);
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



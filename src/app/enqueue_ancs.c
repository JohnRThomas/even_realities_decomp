/*
 * Function: enqueue_ancs
 * Entry:    00018cac
 * Prototype: int __stdcall enqueue_ancs(void * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int enqueue_ancs(void *param_1)

{
  int iVar1;
  char *extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined1 auStack_1bc [436];
  
  memset(auStack_1bc,0,0x1b4);
  if (GLOBAL_STATE.sem_6.wait_q.next == (void *)0x0) {
    iVar1 = 1;
  }
  else {
    if (GLOBAL_STATE.sem_6.poll_events.prev == &DAT_0000000a) {
      z_impl_k_msgq_get((k_msgq *)&GLOBAL_STATE.sem_4.count,auStack_1bc,(k_timeout_t)0x0);
      if (BLE_DEBUG == 0) {
        printk("enqueue ancs drop package! \n");
      }
      else {
        ble_printk("enqueue ancs drop package! \n",extraout_r1,extraout_r2,BLE_DEBUG);
      }
    }
    memcpy(auStack_1bc,param_1,0x1b4);
    iVar1 = z_impl_k_msgq_put((k_msgq *)&GLOBAL_STATE.sem_4.count,auStack_1bc,(k_timeout_t)0x0);
    if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): en ancs F\n");
      }
      else {
        ble_printk("%s(): en ancs F\n","enqueue_ancs",extraout_r2_00,BLE_DEBUG);
      }
    }
  }
  return iVar1;
}



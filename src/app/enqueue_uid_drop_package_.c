/*
 * Function: enqueue_uid_drop_package_
 * Entry:    00018f9c
 * Prototype: int __stdcall enqueue_uid_drop_package_(undefined4 * param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int enqueue_uid_drop_package_(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  local_18 = 0;
  uStack_14 = 0;
  if (GLOBAL_STATE.sem_2.poll_events.prev == (void *)0x0) {
    iVar1 = 1;
  }
  else {
    uStack_10 = param_3;
    if (GLOBAL_STATE.sem_3.poll_events.next == &DAT_0000000a) {
      z_impl_k_msgq_get((k_msgq *)&GLOBAL_STATE.sem_2.wait_q.prev,&local_18,(k_timeout_t)0x0);
      if (BLE_DEBUG == 0) {
        printk("enqueue uid drop package! \n");
      }
      else {
        ble_printk("enqueue uid drop package! \n",extraout_r1,extraout_r2,BLE_DEBUG);
      }
    }
    local_18 = *param_1;
    uStack_14 = param_1[1];
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): local_data uid %d\n");
      }
      else {
        ble_printk("%s(): local_data uid %d\n","enqueue_uid",local_18,BLE_DEBUG);
      }
    }
    iVar1 = z_impl_k_msgq_put((k_msgq *)&GLOBAL_STATE.sem_2.wait_q.prev,&local_18,(k_timeout_t)0x0);
    if ((iVar1 != 0) && (0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): en uid F\n");
      }
      else {
        ble_printk("%s(): en uid F\n","enqueue_uid",extraout_r2_00,BLE_DEBUG);
      }
    }
  }
  return iVar1;
}



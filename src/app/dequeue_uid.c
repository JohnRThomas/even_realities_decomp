/*
 * Function: dequeue_uid
 * Entry:    000191a4
 * Prototype: int __stdcall dequeue_uid(undefined4 * param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int dequeue_uid(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r2;
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
    iVar1 = z_impl_k_msgq_get((k_msgq *)&GLOBAL_STATE.sem_2.wait_q.prev,&local_18,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      *param_1 = local_18;
      param_1[1] = uStack_14;
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): D uid F\n");
      }
      else {
        ble_printk("%s(): D uid F\n","dequeue_uid",extraout_r2,BLE_DEBUG);
      }
    }
  }
  return iVar1;
}



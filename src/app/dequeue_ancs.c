/*
 * Function: dequeue_ancs
 * Entry:    00018ee8
 * Prototype: int __stdcall dequeue_ancs(void * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int dequeue_ancs(void *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined1 auStack_1c4 [440];
  
  memset(auStack_1c4,0,0x1b4);
  if (GLOBAL_STATE.sem_6.wait_q.next == (void *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = z_impl_k_msgq_get((k_msgq *)&GLOBAL_STATE.sem_4.count,auStack_1c4,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      memcpy(param_1,auStack_1c4,0x1b4);
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): D ancs F\n");
      }
      else {
        ble_printk("%s(): D ancs F\n","dequeue_ancs",extraout_r2,BLE_DEBUG);
      }
    }
  }
  return iVar1;
}



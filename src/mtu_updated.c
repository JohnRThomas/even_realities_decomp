/*
 * Function: mtu_updated
 * Entry:    00018424
 * Prototype: undefined __stdcall mtu_updated(undefined4 param_1, uint param_2)
 */


void mtu_updated(undefined4 param_1,uint param_2)

{
  printk("Updated MTU: TX: %d RX: %d bytes\n");
  if ((99 < param_2) && (k_sem_give((k_sem *)(GLOBAL_STATE.sem_8.limit + 0x230)), param_2 == 0x1f2))
  {
    change_work_mode(1);
    return;
  }
  return;
}



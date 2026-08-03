/*
 * Function: smp_rx_remove_invalid
 * Entry:    00055a0c
 * Prototype: void __stdcall smp_rx_remove_invalid(smp_transport * zst, void * arg)
 */


/* exclude_from_export_ai */

void smp_rx_remove_invalid(smp_transport *zst,void *arg)

{
  k_spinlock_key_t kVar1;
  net_buf *pnVar2;
  int iVar3;
  uint extraout_r1;
  uint extraout_r1_00;
  uint uVar4;
  uint extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_queue kStack_34;
  
  if (*(int *)&zst[2].expected != 0) {
    kVar1 = k_spin_lock((k_spinlock *)zst);
    if ((kVar1 & 5) != 0) {
      k_work_cancel((k_work *)zst);
    }
    k_queue_init(&kStack_34);
    uVar4 = extraout_r1;
    while (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = uVar4,
          pnVar2 = net_buf_get((k_fifo *)&zst->expected,timeout), uVar4 = extraout_r1_00,
          pnVar2 != (net_buf *)0x0) {
      iVar3 = (**(code **)&zst[2].expected)(pnVar2,arg);
      if (iVar3 == 0) {
        smp_free_buf(pnVar2,zst);
        uVar4 = extraout_r1_01;
      }
      else {
        net_buf_put((k_fifo *)&kStack_34,pnVar2);
        uVar4 = extraout_r1_02;
      }
    }
    while (timeout_00.ticks._4_4_ = 0, timeout_00.ticks._0_4_ = uVar4,
          pnVar2 = net_buf_get((k_fifo *)&kStack_34,timeout_00), pnVar2 != (net_buf *)0x0) {
      net_buf_put((k_fifo *)&zst->expected,pnVar2);
      uVar4 = extraout_r1_03;
    }
    if (*(int *)&zst->expected != 0) {
      k_work_submit_to_queue((k_work_q *)&DAT_20005d98,(k_work *)zst);
    }
  }
  return;
}



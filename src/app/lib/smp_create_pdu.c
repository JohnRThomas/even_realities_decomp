/*
 * Function: smp_create_pdu
 * Entry:    00086868
 * Prototype: net_buf * __stdcall smp_create_pdu(bt_smp * smp, uint8_t op, size_t len)
 */


/* exclude_from_export_ai */

net_buf * smp_create_pdu(bt_smp *smp,uint8_t op,size_t len)

{
  bool bVar1;
  net_buf *pnVar2;
  uint8_t *puVar3;
  uint uVar4;
  k_timeout_t timeout;
  
  bVar1 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,4);
  if (bVar1) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0xf0000;
  }
  timeout.ticks._4_4_ = 0;
  timeout.ticks._0_4_ = uVar4;
  pnVar2 = bt_l2cap_create_pdu_timeout((net_buf_pool *)0x0,0,timeout);
  if (pnVar2 == (net_buf *)0x0) {
    atomic_set_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,4);
  }
  else {
    puVar3 = net_buf_add((net_buf *)&(pnVar2->field6_0xc).field0,1);
    *puVar3 = op;
  }
  return pnVar2;
}



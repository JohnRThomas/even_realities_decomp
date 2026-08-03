/*
 * Function: smp_send_pairing_confirm
 * Entry:    00086aa8
 * Prototype: uint8_t __stdcall smp_send_pairing_confirm(bt_smp * smp)
 */


/* exclude_from_export_ai */

uint8_t smp_send_pairing_confirm(bt_smp *smp)

{
  bool bVar1;
  uint8_t uVar2;
  bt_smp *smp_00;
  net_buf *buf;
  uint8_t *enc_data;
  size_t len;
  void *user_data;
  int iVar3;
  dword *target;
  
  target = &smp->SMP_NUM_FLAGS_;
  bVar1 = atomic_test_bit((atomic_t *)target,10);
  if (bVar1) {
    atomic_set_bit((atomic_t *)target,0);
LAB_00086b1a:
    uVar2 = '\0';
  }
  else {
    atomic_set_bit((atomic_t *)smp,4);
    iVar3 = *(int *)&smp[1].dhkey_BT_DH_KEY_LEN_;
    buf = smp_create_pdu(smp_00,'\x03',len);
    if (buf != (net_buf *)0x0) {
      enc_data = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x10);
      iVar3 = smp_c1(smp->tk,smp->prnd,smp->preq,smp->prsp,(bt_addr_le_t *)(iVar3 + 0x97),
                     (bt_addr_le_t *)(iVar3 + 0x9e),enc_data);
      if (iVar3 == 0) {
        smp_send(smp,buf,(bt_conn_tx_cb_t)0x0,user_data);
        atomic_clear_bit((atomic_t *)target,0);
        goto LAB_00086b1a;
      }
      net_buf_unref(buf);
    }
    uVar2 = '\b';
  }
  return uVar2;
}



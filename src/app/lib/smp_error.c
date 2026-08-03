/*
 * Function: smp_error
 * Entry:    00060ed8
 * Prototype: int __stdcall smp_error(bt_smp * smp, uint8_t reason)
 */


/* exclude_from_export_ai */

int smp_error(bt_smp *smp,uint8_t reason)

{
  bool bVar1;
  bool bVar2;
  net_buf *buf;
  uint8_t *puVar3;
  int iVar4;
  size_t extraout_r2;
  size_t len;
  size_t extraout_r2_00;
  atomic_t *target;
  atomic_t *target_00;
  atomic_t *target_01;
  char local_20 [4];
  char *local_1c;
  
  bVar2 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,2);
  bVar1 = false;
  if (bVar2) {
    bVar1 = *(short *)(smp[1].tk + 9) == 0;
  }
  bVar2 = atomic_test_bit(target,3);
  if (((bVar2) || (bVar2 = atomic_test_bit(target_00,1), bVar2)) ||
     (bVar2 = atomic_test_bit(target_01,0xf), len = extraout_r2_00, bVar2)) {
    smp_pairing_complete(smp,reason);
    len = extraout_r2;
  }
  if (bVar1) {
    local_1c = 
    "SMP does not allow a pairing failure at this point. Known issue. Disconnecting instead.";
    local_20[0] = '\x02';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1080,local_20);
    bt_conn_disconnect(*(bt_conn **)&smp[1].dhkey_BT_DH_KEY_LEN_,'\x05');
  }
  else {
    buf = smp_create_pdu(smp,'\x05',len);
    if (buf == (net_buf *)0x0) {
      return -0x69;
    }
    puVar3 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,1);
    *puVar3 = reason;
    iVar4 = bt_l2cap_send_cb(*(bt_conn **)&smp[1].dhkey_BT_DH_KEY_LEN_,6,buf,(bt_conn_tx_cb_t)0x0,
                             (void *)0x0);
    if (iVar4 != 0) {
      net_buf_unref(buf);
    }
  }
  return 0;
}



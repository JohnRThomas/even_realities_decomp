/*
 * Function: bt_smp_start_security
 * Entry:    00060c10
 * Prototype: int __stdcall bt_smp_start_security(bt_conn * conn)
 */


/* exclude_from_export_ai */

int bt_smp_start_security(bt_conn *conn)

{
  bool bVar1;
  uint8_t uVar2;
  bt_smp *smp;
  bt_conn_auth_cb *pbVar3;
  bt_keys *pbVar4;
  int iVar5;
  net_buf *buf;
  uint8_t *puVar6;
  size_t len;
  uint uVar7;
  undefined *puVar8;
  dword *target;
  
  if (conn->role != '\x01') {
    return -22;
  }
  smp = smp_chan_get(conn);
  if (smp == (bt_smp *)0x0) {
    return -0x80;
  }
  target = &smp->SMP_NUM_FLAGS_;
  bVar1 = atomic_test_bit((atomic_t *)target,4);
  if (bVar1) {
    return -5;
  }
  bVar1 = atomic_test_bit((atomic_t *)target,3);
  if ((bVar1) || (bVar1 = atomic_test_bit((atomic_t *)target,1), bVar1)) {
    return -0x10;
  }
  pbVar3 = latch_auth_cb(smp);
  uVar7 = (uint)*(byte *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 10);
  if (uVar7 == 3) {
    uVar2 = get_io_capa();
    if (uVar2 != '\x03') goto LAB_00060d0c;
    if (pbVar3 != (bt_conn_auth_cb *)0x0) {
      puVar8 = pbVar3->passkey_entry;
      goto LAB_00060d08;
    }
  }
  else if (uVar7 < 4) {
    if (uVar7 - 1 < 2) goto LAB_00060d0c;
  }
  else if ((uVar7 == 4) &&
          ((uVar2 = get_io_capa(), uVar2 != '\x03' ||
           ((pbVar3 != (bt_conn_auth_cb *)0x0 && (pbVar3->passkey_entry != (undefined *)0x0)))))) {
    puVar8 = (undefined *)(uint)DAT_2001e2a6;
LAB_00060d08:
    if (puVar8 != (undefined *)0x0) goto LAB_00060d0c;
  }
  bVar1 = atomic_test_bit((atomic_t *)&conn->flags,0xb);
  if (!bVar1) {
    if ((conn->le).keys == (undefined *)0x0) {
      pbVar4 = bt_keys_find(0x20,conn->id,&(conn->le).dst);
      (conn->le).keys = &pbVar4->id;
      if (pbVar4 == (bt_keys *)0x0) {
        pbVar4 = bt_keys_find(BT_KEYS_REMOTE_CSRK,conn->id,&(conn->le).dst);
        (conn->le).keys = &pbVar4->id;
      }
    }
    puVar8 = (conn->le).keys;
    if (((puVar8 != (undefined *)0x0) && ((*(ushort *)(puVar8 + 0xe) & 0x24) != 0)) &&
       ((conn->required_sec_level < 3 ||
        (((int)((uint)(byte)puVar8[0xd] << 0x1f) < 0 &&
         ((conn->required_sec_level == 3 ||
          (((int)((uint)*(ushort *)(puVar8 + 0xe) << 0x1a) < 0 && (puVar8[0xc] == '\x10')))))))))) {
LAB_00060d0c:
      if ((conn->le).keys == (undefined *)0x0) {
        pbVar4 = bt_keys_get_addr(conn->id,&(conn->le).dst);
        (conn->le).keys = &pbVar4->id;
        if (pbVar4 == (bt_keys *)0x0) {
          return -0xc;
        }
      }
      iVar5 = smp_init(smp);
      if ((iVar5 == 0) && (buf = smp_create_pdu(smp,'\v',len), buf != (net_buf *)0x0)) {
        puVar6 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,1);
        uVar2 = get_auth(smp,'\t');
        *puVar6 = uVar2;
        iVar5 = bt_l2cap_send_cb(conn,6,buf,(bt_conn_tx_cb_t)0x0,(void *)0x0);
        if (iVar5 == 0) {
          atomic_set_bit((atomic_t *)target,0xf);
          atomic_set_bit((atomic_t *)smp,1);
          return 0;
        }
        net_buf_unref(buf);
        return iVar5;
      }
      return -0x69;
    }
  }
  return -22;
}



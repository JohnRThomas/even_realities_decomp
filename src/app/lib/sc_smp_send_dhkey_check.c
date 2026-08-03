/*
 * Function: sc_smp_send_dhkey_check
 * Entry:    00060070
 * Prototype: uint8_t __stdcall sc_smp_send_dhkey_check(bt_smp * smp, uint8_t * e)
 */


/* exclude_from_export_ai */

uint8_t sc_smp_send_dhkey_check(bt_smp *smp,uint8_t *e)

{
  byte bVar1;
  net_buf *buf;
  uint8_t *res;
  int iVar2;
  size_t in_r2;
  void *user_data;
  byte z;
  char local_28 [4];
  char *local_24;
  
  bVar1 = smp->method;
  if (bVar1 < 3) {
    z = 0;
    if (bVar1 != 0) {
      z = (byte)(*(uint *)(smp[1].rrnd + 9) >> smp[1].rrnd[0xd]) & 1 | 0x80;
    }
  }
  else {
    if (bVar1 != 3) {
      local_24 = "Unknown pairing method (%u)";
      local_28[0] = '\x03';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,local_28);
      return '\b';
    }
    z = 0;
  }
  buf = smp_create_pdu(smp,'\x03',in_r2);
  if (buf != (net_buf *)0x0) {
    res = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x10);
    iVar2 = bt_crypto_f4(DAT_2000b928,&smp->pkey_BT_PUB_KEY_LEN_,smp->prnd,z,res);
    if (iVar2 == 0) {
      smp_send(smp,buf,(bt_conn_tx_cb_t)0x0,user_data);
      atomic_clear_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0);
      return '\0';
    }
    net_buf_unref(buf);
  }
  return '\b';
}



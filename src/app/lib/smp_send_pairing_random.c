/*
 * Function: smp_send_pairing_random
 * Entry:    000868da
 * Prototype: uint8_t __stdcall smp_send_pairing_random(bt_smp * smp)
 */


/* exclude_from_export_ai */

uint8_t smp_send_pairing_random(bt_smp *smp)

{
  uint8_t uVar1;
  net_buf *buf;
  undefined4 *puVar2;
  size_t in_r2;
  byte *user_data;
  byte *pbVar3;
  
  buf = smp_create_pdu(smp,'\x04',in_r2);
  if (buf == (net_buf *)0x0) {
    uVar1 = '\b';
  }
  else {
    puVar2 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x10);
    pbVar3 = smp->prnd;
    do {
      user_data = pbVar3 + 4;
      *puVar2 = *(undefined4 *)pbVar3;
      puVar2 = puVar2 + 1;
      pbVar3 = user_data;
    } while (user_data != smp->rrnd);
    smp_send(smp,buf,(bt_conn_tx_cb_t)0x0,user_data);
    uVar1 = '\0';
  }
  return uVar1;
}



/*
 * Function: send_pairing_rsp
 * Entry:    000868a6
 * Prototype: uint8_t __stdcall send_pairing_rsp(bt_smp * smp)
 */


/* exclude_from_export_ai */

uint8_t send_pairing_rsp(bt_smp *smp)

{
  ushort uVar1;
  uint8_t uVar2;
  net_buf *buf;
  undefined4 *puVar3;
  size_t in_r2;
  
  buf = smp_create_pdu(smp,'\x02',in_r2);
  if (buf == (net_buf *)0x0) {
    uVar2 = '\b';
  }
  else {
    puVar3 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,6);
    *puVar3 = *(undefined4 *)(smp->prsp + 1);
    uVar1 = *(ushort *)(smp->prsp + 5);
    *(ushort *)(puVar3 + 1) = uVar1;
    smp_send(smp,buf,(bt_conn_tx_cb_t)0x0,(void *)(uint)uVar1);
    uVar2 = '\0';
  }
  return uVar2;
}



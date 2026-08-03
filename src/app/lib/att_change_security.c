/*
 * Function: att_change_security
 * Entry:    0005ca6c
 * Prototype: int __stdcall att_change_security(bt_conn * conn, uint8_t err)
 */


/* exclude_from_export_ai */

int att_change_security(bt_conn *conn,uint8_t err)

{
  byte bVar1;
  bt_conn *conn_00;
  int iVar2;
  bt_security_t sec;
  void *pvVar3;
  undefined *puVar4;
  uint8_t err_00;
  
  puVar4 = conn[1].tx_queue._queue.poll_events.next;
  if ((puVar4 != (undefined *)0x0) && (puVar4 != &DAT_2000b880)) {
    err_00 = *(uint8_t *)(*(int *)(err + 0xc) + 3);
    if (err_00 != '\0') {
      conn_00 = *(bt_conn **)&conn->id;
      if (err_00 == '\x05') {
        bVar1 = conn_00->sec_level;
        if (bVar1 < 2) goto LAB_0005ca92;
        if (bVar1 == 2) {
          sec = 3;
        }
        else {
          if (bVar1 != 3) goto LAB_0005cacc;
          sec = 4;
        }
      }
      else {
        if ((err_00 != '\x0f') || (1 < conn_00->sec_level)) goto LAB_0005cacc;
LAB_0005ca92:
        sec = 2;
      }
      iVar2 = bt_conn_set_security(conn_00,sec);
      if (iVar2 == 0) {
        k_work_cancel_delayable((k_work_delayable *)&conn[1].deferred_work.queue);
        pvVar3 = conn[1].tx_queue._queue.poll_events.next;
        *(byte *)((int)pvVar3 + 0x10) = *(byte *)((int)pvVar3 + 0x10) | 1;
        return 0;
      }
      goto LAB_0005cacc;
    }
  }
  err_00 = '\x0e';
LAB_0005cacc:
  bVar1 = att_handle_rsp((bt_att_chan *)conn,(void *)0x0,0,err_00);
  return (uint)bVar1;
}



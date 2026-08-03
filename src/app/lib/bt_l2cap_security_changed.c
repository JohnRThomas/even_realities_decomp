/*
 * Function: bt_l2cap_security_changed
 * Entry:    000851a2
 * Prototype: void __stdcall bt_l2cap_security_changed(bt_conn * conn, uint8_t hci_status)
 */


/* exclude_from_export */

void bt_l2cap_security_changed(bt_conn *conn,uint8_t hci_status)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  code *pcVar4;
  int *piVar5;
  bt_l2cap_le_chan *ch;
  bt_l2cap_le_chan *pbVar6;
  bt_l2cap_le_chan *pbVar7;
  
  piVar5 = (int *)conn->channels;
  if (piVar5 != (int *)0x0) {
    pbVar6 = (bt_l2cap_le_chan *)0x0;
    if (*piVar5 != 0) {
      pbVar6 = (bt_l2cap_le_chan *)(*piVar5 + -8);
    }
    ch = (bt_l2cap_le_chan *)(piVar5 + -2);
    while( true ) {
      pbVar7 = pbVar6;
      puVar3 = (uint *)((int)&ch->tx_queue + 2);
      uVar2 = *puVar3;
      *puVar3 = uVar2 & 0xfffffffb;
      if (((int)(uVar2 << 0x1d) < 0) &&
         ((hci_status != '\0' || (iVar1 = l2cap_le_conn_req(ch), iVar1 != 0)))) {
        bt_l2cap_chan_remove((bt_conn *)ch->chan,(bt_l2cap_chan *)ch);
        bt_l2cap_chan_del((bt_l2cap_chan *)ch);
      }
      pcVar4 = *(code **)(ch->rx + 8);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(ch,hci_status);
      }
      if (pbVar7 == (bt_l2cap_le_chan *)0x0) break;
      ch = pbVar7;
      pbVar6 = (bt_l2cap_le_chan *)0x0;
      if (*(int *)&pbVar7->pending_rx_mtu != 0) {
        pbVar6 = (bt_l2cap_le_chan *)(*(int *)&pbVar7->pending_rx_mtu + -8);
      }
    }
  }
  return;
}



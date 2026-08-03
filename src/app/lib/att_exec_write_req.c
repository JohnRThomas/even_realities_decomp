/*
 * Function: att_exec_write_req
 * Entry:    0005c22c
 * Prototype: uint8_t __stdcall att_exec_write_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_exec_write_req(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  ushort uVar2;
  uint16_t tid;
  uint8_t uVar3;
  net_buf *buf_00;
  net_buf *pnVar4;
  uint uVar5;
  sys_snode_t *psVar6;
  undefined *puVar7;
  net_buf *pnVar8;
  net_buf *pnVar9;
  net_buf *pnVar10;
  
  uVar3 = '\0';
  uVar1 = *(buf->field6_0xc).field0.data;
  do {
    if (*(int *)(chan->att + 0x28) == 0) {
      if (uVar3 == '\0') {
        pnVar4 = bt_att_create_rsp_pdu(chan,'\x19',0);
        if (pnVar4 == (net_buf *)0x0) {
          return '\x0e';
        }
        bt_att_chan_send_rsp(chan,pnVar4);
      }
      return '\0';
    }
    buf_00 = net_buf_slist_get((sys_slist_t *)(chan->att + 0x28));
    DAT_200029c4 = 0;
    tid = *(uint16_t *)&buf_00->user_data;
    DAT_200029c0 = DAT_200029c8;
    net_buf_add_mem((net_buf *)&DAT_200029c0,(buf_00->field6_0xc).field0.data,
                    (uint)(buf_00->field6_0xc).field0.len);
    puVar7 = chan->att;
    uVar2 = *(ushort *)((int)&buf_00->user_data + 2);
    pnVar4 = *(net_buf **)(puVar7 + 0x28);
    if (pnVar4 != (net_buf *)0x0) {
      pnVar8 = (net_buf *)(pnVar4->node).next;
      pnVar9 = (net_buf *)0x0;
      while (pnVar4 != (net_buf *)0x0) {
        pnVar10 = pnVar4;
        if (*(uint16_t *)&pnVar4->user_data == tid) {
          uVar5 = (uint)*(ushort *)((int)&pnVar4->user_data + 2);
          if (uVar5 == 0) break;
          if ((uVar5 != (uint)uVar2 + (uint)DAT_200029c4) ||
             (uVar5 = (uint)(pnVar4->field6_0xc).field0.len,
             (uint)DAT_200029c6 < DAT_200029c4 + uVar5)) {
            send_err_rsp((bt_l2cap_chan *)chan,0x18,tid);
            return '\0';
          }
          net_buf_add_mem((net_buf *)&DAT_200029c0,(pnVar4->field6_0xc).field0.data,uVar5);
          psVar6 = (pnVar4->node).next;
          if (pnVar9 == (net_buf *)0x0) {
            *(sys_snode_t **)(puVar7 + 0x28) = psVar6;
            if (pnVar4 == *(net_buf **)(puVar7 + 0x2c)) {
              *(sys_snode_t **)(puVar7 + 0x2c) = psVar6;
            }
          }
          else {
            (pnVar9->node).next = psVar6;
            if (pnVar4 == *(net_buf **)(puVar7 + 0x2c)) {
              *(net_buf **)(puVar7 + 0x2c) = pnVar9;
            }
          }
          (pnVar4->node).next = (sys_snode_t *)0x0;
          net_buf_unref(pnVar4);
          pnVar10 = pnVar9;
        }
        pnVar4 = pnVar8;
        pnVar9 = pnVar10;
        if (pnVar8 != (net_buf *)0x0) {
          pnVar8 = (net_buf *)(pnVar8->node).next;
        }
      }
    }
    if (uVar1 == '\x01') {
      uVar3 = att_write_rsp(chan,'\x18','\0',tid,*(uint16_t *)((int)&buf_00->user_data + 2),
                            DAT_200029c0,DAT_200029c4);
      if (uVar3 != '\0') {
        send_err_rsp((bt_l2cap_chan *)chan,0x18,*(uint16_t *)&buf_00->user_data);
      }
    }
    else {
      uVar3 = '\0';
    }
    net_buf_unref(buf_00);
  } while( true );
}



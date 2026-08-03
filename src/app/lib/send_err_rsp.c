/*
 * Function: send_err_rsp
 * Entry:    000859ac
 * Prototype: void __stdcall send_err_rsp(bt_l2cap_chan * chan, uint16_t err, uint16_t tid)
 */


/* exclude_from_export_ai */

void send_err_rsp(bt_l2cap_chan *chan,uint16_t err,uint16_t tid)

{
  net_buf *buf;
  undefined1 *puVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined1 in_r3;
  undefined4 extraout_r3;
  
  if (err == 0) {
    return;
  }
  buf = bt_att_chan_create_pdu((bt_att_chan *)chan,'\x01',4);
  if (buf == (net_buf *)0x0) {
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1040,&stack0xfffffff0,2,0,extraout_r1,extraout_r2,extraout_r3);
    return;
  }
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,4);
  *puVar1 = (char)err;
  *(uint16_t *)(puVar1 + 1) = tid;
  puVar1[3] = in_r3;
  bt_att_chan_send_rsp((bt_att_chan *)chan,buf);
  return;
}


